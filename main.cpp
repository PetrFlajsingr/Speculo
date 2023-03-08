#include <iostream>

#include "clang/AST/RecursiveASTVisitor.h"
#include <clang/AST/Attr.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <llvm/Support/CommandLine.h>
#include <pf_common/ScopeExit.h>
#include <random>

#include <fmt/core.h>

#include "meta/common.h"

static llvm::cl::opt<std::string> InputSource(llvm::cl::Required, "in-source", llvm::cl::desc("Specify input filename"),
                                              llvm::cl::value_desc("filename"));
static llvm::cl::opt<std::string> OutputHeader("out-header", llvm::cl::desc("Specify header output filename"),
                                               llvm::cl::value_desc("filename"), llvm::cl::init("output.hpp"));
static llvm::cl::opt<std::string> OutputSource("out-source", llvm::cl::desc("Specify source output filename"),
                                               llvm::cl::value_desc("filename"), llvm::cl::init("output.cpp"));
static llvm::cl::opt<bool> IgnoreIncludes("ignore-includes", llvm::cl::desc("Ignore includes while parsing the file"),
                                          llvm::cl::value_desc("bool"), llvm::cl::init(true));

static llvm::cl::list<std::string> CompilerFlags("flag", llvm::cl::desc("Compiler flags"), llvm::cl::value_desc("flags"),
                                                 llvm::cl::ZeroOrMore);

struct Attribute {
    std::string name;
    std::vector<std::string> arguments;
};

struct TypeInfo {
    std::string fullName;
    std::string name;
    struct {
        unsigned int line;
        unsigned int column;
    } sourceLocation;
};

struct EnumTypeInfo : public TypeInfo {
    struct ValueInfo {
        std::variant<bool, std::uint64_t, std::int64_t> value;
        std::vector<Attribute> attributes;
    };

    std::vector<Attribute> attributes;
    std::unordered_map<std::string, ValueInfo> values;
    std::string underlyingType;
};

class AttributeParser {
public:
    struct EnumAttributes {
        std::vector<Attribute> attributes;
        std::unordered_map<std::string, std::vector<Attribute>> valueAttributes;
    };
    [[nodiscard]] EnumAttributes parseEnumAttributes(clang::ASTContext &astContext, const clang::EnumDecl &decl) const {
        EnumAttributes result{};

        auto srcRange = decl.getSourceRange();

        auto enumTypeAttributes = parseEnumTypeAttributes(astContext, srcRange);
        result.attributes = std::move(enumTypeAttributes.attributes);

        srcRange.setBegin(enumTypeAttributes.end);
        result.valueAttributes = parseEnumValueAttributes(astContext, srcRange);

        return result;
    }

private:
    struct EnumTypeAttributeParseResult {
        std::vector<Attribute> attributes;
        clang::SourceLocation end;
    };
    [[nodiscard]] EnumTypeAttributeParseResult parseEnumTypeAttributes(clang::ASTContext &astContext, clang::SourceRange srcRange) const {
        EnumTypeAttributeParseResult result;

        // skipping first raw_identifier, which is just `enum`/`enum class`
        srcRange.setBegin(advanceByTokens(astContext, srcRange.getBegin(), 1));

        bool foundAttributes;
        do {
            foundAttributes = false;
            if (const auto start = findAttributesStart(astContext, srcRange); start.has_value()) {
                if (contains(astContext, clang::SourceRange{srcRange.getBegin(), *start}, clang::tok::TokenKind::raw_identifier)) {
                    // found enum name, thus we're out of enum type's attributes
                    break;
                }
                if (const auto end = findAttributesEnd(astContext, clang::SourceRange{*start, srcRange.getEnd()}); end.has_value()) {
                    std::ranges::copy(parseAttributes(astContext, clang::SourceRange{*start, *end}), std::back_inserter(result.attributes));
                    srcRange.setBegin(*end);
                    foundAttributes = true;
                }
            }
        } while (foundAttributes);
        result.end = srcRange.getBegin();
        return result;
    }
    [[nodiscard]] std::unordered_map<std::string, std::vector<Attribute>> parseEnumValueAttributes(clang::ASTContext &astContext,
                                                                                                   clang::SourceRange srcRange) const {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

        std::unordered_map<std::string, std::vector<Attribute>> result;

        // advance to l_brace
        {
            auto token = clang::Lexer::findNextToken(srcRange.getBegin(), sourceManager, langOpts);
            while (token->getKind() != clang::tok::TokenKind::l_brace) {
                token = clang::Lexer::findNextToken(token->getLocation(), sourceManager, langOpts);
            }
            srcRange.setBegin(token->getLocation());
        }

        while (true) {
            bool foundValue = true;
            auto token = clang::Lexer::findNextToken(srcRange.getBegin(), sourceManager, langOpts);
            while (token->getKind() != clang::tok::TokenKind::raw_identifier) {
                token = clang::Lexer::findNextToken(token->getLocation(), sourceManager, langOpts);
                if (!token.has_value() || token->getKind() == clang::tok::TokenKind::eof) {
                    foundValue = false;
                    break;
                }
            }
            if (!foundValue) { break; }
            srcRange.setBegin(token->getLocation());

            const auto spelling = clang::Lexer::getSpelling(*token, sourceManager, langOpts);
            std::pair<std::string, std::vector<Attribute>> valueAttributes{spelling, {}};

            bool foundAttributes;
            do {
                foundAttributes = false;
                if (const auto start = findAttributesStart(astContext, srcRange); start.has_value()) {
                    if (contains(astContext, clang::SourceRange{srcRange.getBegin(), *start}, clang::tok::TokenKind::comma)) {
                        // found value divider, these attributes belong to a different value
                        break;
                    }
                    if (const auto end = findAttributesEnd(astContext, clang::SourceRange{*start, srcRange.getEnd()}); end.has_value()) {
                        std::ranges::copy(parseAttributes(astContext, clang::SourceRange{*start, *end}),
                                          std::back_inserter(valueAttributes.second));
                        srcRange.setBegin(*end);
                        foundAttributes = true;
                    }
                }
            } while (foundAttributes);
            result.emplace(std::move(valueAttributes));
        }

        return result;
    }

    [[nodiscard]] std::optional<clang::SourceLocation> findAttributesStart(clang::ASTContext &astContext,
                                                                           const clang::SourceRange &srcRange) const {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

        clang::SourceLocation result;

        auto token = clang::Lexer::findNextToken(srcRange.getBegin(), sourceManager, langOpts);
        bool foundLSquare = false;
        for (auto i = token->getLocation(); i != srcRange.getEnd();) {
            if (!token.has_value()) { return std::nullopt; }
            if (foundLSquare && token->getKind() == clang::tok::TokenKind::l_square) {
                return result;
            } else {
                foundLSquare = token->getKind() == clang::tok::TokenKind::l_square;
            }
            if (foundLSquare) { result = token->getLocation(); }

            token = clang::Lexer::findNextToken(i, sourceManager, langOpts);
            i = token->getLocation();
        }
        return std::nullopt;
    }

    [[nodiscard]] std::optional<clang::SourceLocation> findAttributesEnd(clang::ASTContext &astContext,
                                                                         const clang::SourceRange &srcRange) const {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

        auto token = clang::Lexer::findNextToken(srcRange.getBegin(), sourceManager, langOpts);

        bool foundRSquare = false;
        std::size_t parensNestingCnt{};
        for (auto i = token->getLocation(); i != srcRange.getEnd();) {
            if (!token.has_value()) { return std::nullopt; }
            if (token->getKind() == clang::tok::TokenKind::l_paren) {
                ++parensNestingCnt;
            } else if (token->getKind() == clang::tok::TokenKind::r_paren) {
                --parensNestingCnt;
            }
            if (parensNestingCnt == 0) {
                if (foundRSquare && token->getKind() == clang::tok::TokenKind::r_square) {
                    return token->getLocation();
                } else {
                    foundRSquare = token->getKind() == clang::tok::TokenKind::r_square;
                }
            } else {
                foundRSquare = false;
            }

            token = clang::Lexer::findNextToken(i, sourceManager, langOpts);
            i = token->getLocation();
        }
        return std::nullopt;
    }

    [[nodiscard]] std::vector<Attribute> parseAttributes(clang::ASTContext &astContext, const clang::SourceRange &srcRange) const {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

        enum class State { Start, None, Using, UsingEnd, Name, Arguments, NestedParens };
        State state = State::Start;

        std::vector<Attribute> result;

        std::string attributeNamespace;
        std::string attributeName;
        std::vector<std::string> attributeParams;
        std::string attributeParam;
        std::size_t nestedParensCnt{};
        for (auto i = srcRange.getBegin(); i != srcRange.getEnd();) {
            auto token = clang::Lexer::findNextToken(i, sourceManager, langOpts);
            if (!token.has_value()) { break; }
            switch (state) {
                case State::Start: {
                    if (token->getKind() == clang::tok::TokenKind::raw_identifier) {
                        const auto spelling = clang::Lexer::getSpelling(*token, sourceManager, langOpts);
                        if (spelling == "using") {
                            state = State::Using;
                        } else {
                            state = State::Name;
                            attributeName = spelling;
                        }
                    }
                } break;
                case State::None: {
                    if (token->getKind() == clang::tok::TokenKind::raw_identifier) {
                        state = State::Name;
                        attributeName = clang::Lexer::getSpelling(*token, sourceManager, langOpts);
                    }
                } break;
                case State::Using: {
                    attributeNamespace = clang::Lexer::getSpelling(*token, sourceManager, langOpts);
                    state = State::UsingEnd;
                } break;
                case State::UsingEnd: {
                    state = State::None;
                } break;
                case State::Name: {
                    if (token->getKind() == clang::tok::TokenKind::coloncolon ||
                        token->getKind() == clang::tok::TokenKind::raw_identifier) {
                        attributeName += clang::Lexer::getSpelling(*token, sourceManager, langOpts);
                        state = State::Name;
                    } else if (token->getKind() == clang::tok::TokenKind::l_paren) {
                        state = State::Arguments;
                    } else {
                        if (!attributeNamespace.empty()) {
                            result.emplace_back(attributeNamespace + "::" + attributeName, attributeParams);
                        } else {
                            result.emplace_back(attributeName, attributeParams);
                        }
                        attributeParams.clear();
                        attributeName.clear();
                        state = State::None;
                    }
                } break;
                case State::Arguments: {
                    if (token->getKind() == clang::tok::TokenKind::l_paren) {
                        nestedParensCnt = 1;
                        attributeParam.append(clang::Lexer::getSpelling(*token, sourceManager, langOpts));
                        state = State::NestedParens;
                    } else if (token->getKind() == clang::tok::TokenKind::r_paren) {
                        attributeParams.emplace_back(attributeParam);
                        if (!attributeNamespace.empty()) {
                            result.emplace_back(attributeNamespace + "::" + attributeName, attributeParams);
                        } else {
                            result.emplace_back(attributeName, attributeParams);
                        }
                        attributeParams.clear();
                        attributeParam.clear();
                        attributeName.clear();
                        state = State::None;
                    } else if (token->getKind() == clang::tok::TokenKind::comma) {
                        attributeParams.emplace_back(attributeParam);
                        attributeParam.clear();
                        state = State::Arguments;
                    } else {
                        attributeParam.append(clang::Lexer::getSpelling(*token, sourceManager, langOpts));
                        state = State::Arguments;
                    }
                } break;
                case State::NestedParens: {
                    if (token->getKind() == clang::tok::TokenKind::l_paren) {
                        ++nestedParensCnt;
                        attributeParam.append(clang::Lexer::getSpelling(*token, sourceManager, langOpts));
                        state = State::NestedParens;
                    } else if (token->getKind() == clang::tok::TokenKind::r_paren) {
                        attributeParam.append(clang::Lexer::getSpelling(*token, sourceManager, langOpts));
                        --nestedParensCnt;
                        if (nestedParensCnt == 0) {
                            state = State::Arguments;
                        } else {
                            state = State::NestedParens;
                        }
                    } else if (token->getKind() == clang::tok::TokenKind::comma) {
                        attributeParams.emplace_back(attributeParam);
                        attributeParam.clear();
                        state = State::Arguments;
                    } else {
                        attributeParam.append(clang::Lexer::getSpelling(*token, sourceManager, langOpts));
                        state = State::NestedParens;
                    }
                } break;
            }


            // std::cout << clang::tok::getTokenName(token->getKind()) << "\t";
            // std::cout << clang::Lexer::getSpelling(*token, sourceManager, langOpts) << std::endl;

            i = token->getLocation();
        }
        // std::cout << std::endl;
        return result;
    }

    [[nodiscard]] bool contains(clang::ASTContext &astContext, const clang::SourceRange &range, clang::tok::TokenKind kind) const {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

        auto token = clang::Lexer::findNextToken(range.getBegin(), sourceManager, langOpts);
        for (auto i = token->getLocation(); i != range.getEnd();) {
            if (!token.has_value()) { return false; }
            if (token->getKind() == kind) { return true; }
            token = clang::Lexer::findNextToken(i, sourceManager, langOpts);
            i = token->getLocation();
        }
        return false;
    }
    [[nodiscard]] clang::SourceLocation advanceByTokens(clang::ASTContext &astContext, const clang::SourceLocation &loc,
                                                        std::size_t count) const {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        auto token = clang::Lexer::findNextToken(loc, sourceManager, langOpts);
        for (std::size_t i = 0; i < count - 1; ++i) { token = clang::Lexer::findNextToken(token->getLocation(), sourceManager, langOpts); }
        return token->getLocation();
    }

    [[nodiscard]] std::optional<clang::Token> getToken(clang::ASTContext &astContext, const clang::SourceLocation &loc) const {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        return clang::Lexer::findNextToken(loc, sourceManager, langOpts);
    }
};


class TypeIdGenerator {
public:
    TypeIdGenerator() {
        std::random_device rd{};
        std::seed_seq ss{rd(), rd(), rd()};
        gen = std::mt19937_64{ss};
    }
    [[nodiscard]] pf::meta::ID generateTypeId() {
        const auto w1 = dis(gen);
        const auto w2 = dis(gen);
        return pf::meta::ID{w1, w2};
    }

private:
    std::mt19937_64 gen;
    std::uniform_int_distribution<std::uint64_t> dis;
};

[[nodiscard]] std::string idToString(pf::meta::ID id) { return fmt::format("::pf::meta::ID{{0x{:x}u, 0x{:x}u}}", id.id[0], id.id[1]); }

constexpr auto StaticEnumTypeInfoTemplate = R"fmt(
template<>
struct ::pf::meta::details::StaticTypeInfo<{type_id}> {{
    using Type = {type};
    constexpr static ID TypeID = {type_id};

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>({attributes});

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = ::pf::StringLiteral{{"{name}"}};
    constexpr static auto FullName = ::pf::StringLiteral{{"{full_name}"}};

    using UnderlyingType = {underlying_type};
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>({enum_value_ids});
}};

// const
template<>
struct ::pf::meta::details::StaticTypeInfo<{const_type_id}>
    : ::pf::meta::details::StaticTypeInfo_ConstWrap<{const_type_id}, {type_id}> {{}};
// &
template<>
struct ::pf::meta::details::StaticTypeInfo<{ref_type_id}>
    : ::pf::meta::details::StaticTypeInfo_RefWrap<{ref_type_id}, {type_id}> {{}};
// const &
template<>
struct ::pf::meta::details::StaticTypeInfo<{const_ref_type_id}>
    : ::pf::meta::details::StaticTypeInfo_RefWrap<{const_ref_type_id}, {const_type_id}> {{}};
// *
template<>
struct ::pf::meta::details::StaticTypeInfo<{ptr_type_id}>
    : ::pf::meta::details::StaticTypeInfo_PtrWrap<{ptr_type_id}, {type_id}> {{}};
// const *
template<>
struct ::pf::meta::details::StaticTypeInfo<{const_ptr_type_id}>
    : ::pf::meta::details::StaticTypeInfo_PtrWrap<{const_ptr_type_id}, {const_type_id}> {{}};

)fmt";
constexpr auto GetTypeIDTemplate = R"fmt(
template<>
[[nodiscard]] consteval ID getTypeId<{type}>() {{
    return {type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<const {type}>() {{
    return {const_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<{type} &>() {{
    return {ref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<const {type} &>() {{
    return {const_ref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<{type} *>() {{
    return {ptr_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<const {type} *>() {{
    return {const_ptr_type_id};
}}
)fmt";
constexpr auto GetConstantIDTemplate = R"fmt(
template<>
[[nodiscard]] consteval ID getConstantId<{constant}>() {{
return {value_id};
}}
)fmt";
constexpr auto StaticEnumValueInfoTemplate = R"fmt(
template<>
struct ::pf::meta::details::StaticTypeInfo<{value_id}> {{
    constexpr static ID ValueID = {value_id};
    constexpr static ID TypeID = {type_id};
    using Type = {type};

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>({attributes});

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static {underlying_type} UnderlyingValue = {underlying_value};
    constexpr static {type} Value = {value};
}};
)fmt";

class ASTConsumer : public clang::ASTConsumer {
public:
    void HandleTranslationUnit(clang::ASTContext &context) override {
        auto tuCtx = context.getTranslationUnitDecl();
        Walk(context, *tuCtx);
    }

    void Walk(clang::ASTContext &astContext, const clang::DeclContext &context) {
        for (auto it = context.decls_begin(); it != context.decls_end(); ++it) {
            const clang::Decl *decl = *it;
            if (decl->isInvalidDecl()) { continue; }
            auto &sourceManager = astContext.getSourceManager();
            if (static_cast<bool>(IgnoreIncludes) && !sourceManager.isInMainFile(decl->getLocation())) { continue; }


            const auto declContext = clang::dyn_cast<clang::DeclContext>(decl);
            if (declContext) { Walk(astContext, *declContext); }
            const auto enumDecl = clang::dyn_cast<clang::EnumDecl>(decl);
            if (enumDecl) { ParseEnum(astContext, *enumDecl); }
        }
    }

    std::optional<EnumTypeInfo> ParseEnum(clang::ASTContext &astContext, const clang::EnumDecl &decl) {
        //std::cout << decl.getNameAsString() << std::endl;

        const auto definition = decl.getDefinition();
        if (definition == nullptr) { return std::nullopt; }

        EnumTypeInfo result{};
        result.fullName = definition->getQualifiedNameAsString();
        result.name = definition->getNameAsString();

        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        auto printingPolicy = clang::PrintingPolicy{langOpts};


        result.sourceLocation.line = sourceManager.getPresumedLineNumber(definition->getSourceRange().getBegin());
        result.sourceLocation.column = sourceManager.getPresumedColumnNumber(definition->getSourceRange().getBegin());


        // auto namespaceCtx = definition->getEnclosingNamespaceContext();
        // while (namespaceCtx != nullptr) {
        //     result.namespaces.emplace_back(namespaceCtx->get);
        //     auto &namedDecl = clang::dyn_cast<clang::NamedDecl>(decl);
        //     if (namedDecl) { ParseEnum(astContext, *namedDecl); }
        //     namespaceCtx = namespaceCtx->getEnclosingNamespaceContext();
        // }
        result.underlyingType = definition->getIntegerType().getAsString(printingPolicy);

        for (const auto &enumerator: definition->enumerators()) {
            std::variant<bool, std::uint64_t, std::int64_t> value;
            if (definition->getIntegerType()->isBooleanType()) {
                value = enumerator->getInitVal().getBoolValue();
            } else if (definition->getIntegerType()->isSignedIntegerType()) {
                value = enumerator->getInitVal().getSExtValue();
            } else if (definition->getIntegerType()->isUnsignedIntegerType()) {
                value = enumerator->getInitVal().getExtValue();
            } else {
                std::abort();// TODO: invalid type
            }
            result.values.emplace(enumerator->getNameAsString(), EnumTypeInfo::ValueInfo{value, {}});
            //std::cout << enumerator->getNameAsString() << std::endl;
        }

        {
            AttributeParser attributeParser{};
            auto enumAttributes = attributeParser.parseEnumAttributes(astContext, decl);
            result.attributes = std::move(enumAttributes.attributes);

            for (auto [name, attributes]: enumAttributes.valueAttributes) { result.values[name].attributes = std::move(attributes); }
        }
        using namespace fmt::literals;
        TypeIdGenerator gen{};

        const auto stringifyAttributes = [](const std::vector<Attribute> &attrs) {
            std::string result{};
            for (const auto &attr: attrs) {
                result.append("pf::meta::Attribute{");
                result.append(fmt::format(R"("{}")", attr.name));
                result.append(", {");
                for (const auto &arg: attr.arguments) { result.append(fmt::format("R\"({})\"", arg)).append(", "); }
                if (!attr.arguments.empty()) { result = result.substr(0, result.length() - 2); }
                result.append("}");
                result.append("}, ");
            }
            if (!attrs.empty()) { result = result.substr(0, result.length() - 2); }
            return result;
        };

        const auto typeId = gen.generateTypeId();


        std::unordered_map<std::string, std::string> valueIds{};
        std::string valueIdsStr{};
        for (const auto &[name, info]: result.values) {
            const auto valueId = gen.generateTypeId();
            const auto valueIdStr = idToString(valueId);
            const auto fullName = fmt::format("{}::{}", result.fullName, name);
            valueIds.emplace(fullName, valueIdStr);
            valueIdsStr.append(valueIdStr);
            valueIdsStr.append(", ");

            const auto valueStr = std::visit([](auto val) { return fmt::format("{}", val); }, info.value);

            std::cout << fmt::format(StaticEnumValueInfoTemplate, "type"_a = result.fullName, "value_id"_a = idToString(valueId),
                                     "type_id"_a = idToString(typeId), "attributes"_a = stringifyAttributes(info.attributes),
                                     "name"_a = name, "full_name"_a = fullName, "underlying_type"_a = result.underlyingType,
                                     "underlying_value"_a = valueStr, "value"_a = fullName)
                      << std::endl;
        }
        if (!valueIdsStr.empty()) { valueIdsStr = valueIdsStr.substr(0, valueIdsStr.length() - 2); }

        const auto const_type_id = idToString(gen.generateTypeId());
        const auto ref_type_id = idToString(gen.generateTypeId());
        const auto const_ref_type_id = idToString(gen.generateTypeId());
        const auto ptr_type_id = idToString(gen.generateTypeId());
        const auto const_ptr_type_id = idToString(gen.generateTypeId());

        std::cout << fmt::format(StaticEnumTypeInfoTemplate, "type_id"_a = idToString(typeId), "type"_a = result.fullName,
                                 "attributes"_a = stringifyAttributes(result.attributes), "name"_a = result.name,
                                 "full_name"_a = result.fullName, "underlying_type"_a = result.underlyingType,
                                 "enum_value_ids"_a = valueIdsStr, "const_type_id"_a = const_type_id, "ref_type_id"_a = ref_type_id,
                                 "const_ref_type_id"_a = const_ref_type_id, "ptr_type_id"_a = ptr_type_id,
                                 "const_ptr_type_id"_a = const_ptr_type_id)
                  << std::endl;

        std::cout << "namespace pf::meta::details {" << std::endl;
        std::cout << fmt::format(GetTypeIDTemplate, "type"_a = result.fullName, "type_id"_a = idToString(typeId),
                                 "const_type_id"_a = const_type_id, "ref_type_id"_a = ref_type_id,
                                 "const_ref_type_id"_a = const_ref_type_id, "ptr_type_id"_a = ptr_type_id,
                                 "const_ptr_type_id"_a = const_ptr_type_id);
        for (const auto &[name, id]: valueIds) {
            std::cout << fmt::format(GetConstantIDTemplate, "constant"_a = name, "value_id"_a = id);
            std::cout << std::endl;
        }
        std::cout << "}" << std::endl;

        return result;
    }
};

// Action
class ASTAction : public clang::ASTFrontendAction {
public:
    std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &Compiler, llvm::StringRef InFile) override {
        return std::make_unique<ASTConsumer>();
    };
};

// Factory
class ActionFactory : public clang::tooling::FrontendActionFactory {
public:
    std::unique_ptr<clang::FrontendAction> create() override { return std::make_unique<ASTAction>(); }
};

int main(int argc, const char **argv) {
    llvm::cl::ParseCommandLineOptions(argc, argv, "Test");
    auto sources = std::vector{std::string{InputSource}};


    clang::tooling::FixedCompilationDatabase fixedCompilationDatabase{".", CompilerFlags};
    clang::tooling::ClangTool tool{fixedCompilationDatabase, sources};

    ActionFactory factory{};
    tool.run(&factory);

    return 0;
}
