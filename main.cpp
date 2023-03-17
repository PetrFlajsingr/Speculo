#include <iostream>

#include <clang/Frontend/FrontendActions.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <llvm/Support/CommandLine.h>
#include <pf_common/ScopeExit.h>
#include <pf_common/array.h>
#include <pf_common/concepts/ranges.h>

#include <fmt/core.h>

#include "meta/Info.h"

#include "meta_gen/AttributeParser.h"
#include "meta_gen/info_structs.h"
#include "meta_gen/TypeIdGenerator.h"

#include "format.h"

static llvm::cl::opt<std::string> InputSource(llvm::cl::Required, "in-source", llvm::cl::desc("Specify input filename"),
                                              llvm::cl::value_desc("filename"));
static llvm::cl::opt<std::string> OutputHeader("out-header", llvm::cl::desc("Specify header output filename"),
                                               llvm::cl::value_desc("filename"), llvm::cl::init("output.hpp"));
static llvm::cl::opt<std::string> OutputSource("out-source", llvm::cl::desc("Specify source output filename"),
                                               llvm::cl::value_desc("filename"), llvm::cl::init("output.cpp"));
static llvm::cl::opt<bool> IgnoreIncludes("ignore-includes", llvm::cl::desc("Ignore includes while parsing the file"),
                                          llvm::cl::value_desc("bool"), llvm::cl::init(true));
static llvm::cl::opt<bool> FormatOutput("format-output", llvm::cl::desc("Reformat outputs"),
                                        llvm::cl::value_desc("bool"),
                                        llvm::cl::init(false));

static llvm::cl::list<std::string> CompilerFlags("flag", llvm::cl::desc("Compiler flags"),
                                                 llvm::cl::value_desc("flags"),
                                                 llvm::cl::ZeroOrMore);

namespace pf::meta_gen {

    [[nodiscard]] std::string idToString(pf::meta::details::ID id) {
        return fmt::format("pf::meta::details::ID{{0x{:x}u, 0x{:x}u}}", id.id[0], id.id[1]);
    }

    constexpr auto StaticEnumTypeInfoTemplate = R"fmt(
/****************************** {full_name} START ******************************/
template<>
struct pf::meta::details::StaticInfo<{type_id}> {{
    struct details {{
        {details}
    }};
    using Type = {type};
    constexpr static ID TypeID = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>({attributes});

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{{"{name}"}};
    constexpr static auto FullName = pf::StringLiteral{{"{full_name}"}};

    using UnderlyingType = {underlying_type};
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>({enum_value_ids});
}};

// const
template<>
struct pf::meta::details::StaticInfo<{const_type_id}>
    : pf::meta::details::StaticInfo_ConstWrap<{const_type_id}, {type_id}> {{}};
// &
template<>
struct pf::meta::details::StaticInfo<{lref_type_id}>
    : pf::meta::details::StaticInfo_LRefWrap<{lref_type_id}, {type_id}> {{}};
// &&
template<>
struct pf::meta::details::StaticInfo<{rref_type_id}>
    : pf::meta::details::StaticInfo_RRefWrap<{rref_type_id}, {type_id}> {{}};
// const &
template<>
struct pf::meta::details::StaticInfo<{const_lref_type_id}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<{const_lref_type_id}, {type_id}> {{}};
// *
template<>
struct pf::meta::details::StaticInfo<{ptr_type_id}>
    : pf::meta::details::StaticInfo_PtrWrap<{ptr_type_id}, {type_id}> {{}};
// const *
template<>
struct pf::meta::details::StaticInfo<{const_ptr_type_id}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<{const_ptr_type_id}, {type_id}> {{}};

/****************************** {full_name} END ******************************/
)fmt";
    constexpr auto GetTypeIDTemplate = R"fmt(
/****************************** {full_name} START ******************************/
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
    return {lref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<{type} &&>() {{
    return {rref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<const {type} &>() {{
    return {const_lref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<{type} *>() {{
    return {ptr_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<const {type} *>() {{
    return {const_ptr_type_id};
}}
/****************************** {full_name} END ******************************/
)fmt";
    constexpr auto GetConstantIDTemplate = R"fmt(
/****************************** {full_name} START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<{constant}>() {{
return {value_id};
}}
/****************************** {full_name} END ******************************/
)fmt";
    constexpr auto StaticEnumValueInfoTemplate = R"fmt(
/****************************** {full_name} START ******************************/
template<>
struct pf::meta::details::StaticInfo<{value_id}> {{
    struct details {{
        {details}
    }};
    constexpr static ID ValueID = {value_id};
    constexpr static ID TypeID = {type_id};
    using Type = {type};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

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
/****************************** {full_name} END ******************************/
)fmt";

    constexpr auto MetaFilePrologue = R"fmt(
#pragma once

#include "test.h" // FIXME: include file from tool input
#include <pf_common/array.h>
#include <pf_common/concepts/ranges.h>
#include <type_traits>
#include "meta/details/StaticInfo.h"
#include "meta/details/StaticInfo_Wrappers.h"
#include "meta/details/ID.h"
#include "meta/Attribute.h"
#include "meta/Info.h"
)fmt";
    constexpr auto MetaFileEpilogue = R"fmt(

)fmt";

    class ASTConsumer : public clang::ASTConsumer {
    public:
        explicit ASTConsumer(std::shared_ptr<llvm::raw_fd_ostream> oStream) : outStream{std::move(oStream)} {}

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

                if (const auto enumDecl = clang::dyn_cast<clang::EnumDecl>(decl); enumDecl != nullptr &&
                                                                                  !enumDecl->isInvalidDecl()) {// enum
                    ParseEnum(astContext, *enumDecl);
                } else if (const auto recordDecl = clang::dyn_cast<clang::RecordDecl>(decl);
                        recordDecl != nullptr && !recordDecl->isInvalidDecl()) {// struct union class
                    // ParseRecord(astContext, *recordDecl);
                }


                const auto declContext = clang::dyn_cast<clang::DeclContext>(decl);
                if (declContext) { Walk(astContext, *declContext); }
            }
        }

        std::optional<EnumTypeInfo> ParseEnum(clang::ASTContext &astContext, const clang::EnumDecl &decl) {
            //std::cout << decl.getNameAsString() << std::endl;

            const auto definition = decl.getDefinition();
            if (definition != &decl) { return std::nullopt; }

            EnumTypeInfo result{};
            result.fullName = definition->getQualifiedNameAsString();
            result.name = definition->getNameAsString();

            auto &sourceManager = astContext.getSourceManager();
            auto &langOpts = astContext.getLangOpts();
            auto printingPolicy = clang::PrintingPolicy{langOpts};


            result.sourceLocation.line = sourceManager.getPresumedLineNumber(definition->getSourceRange().getBegin());
            result.sourceLocation.column = sourceManager.getPresumedColumnNumber(
                    definition->getSourceRange().getBegin());
            result.sourceLocation.filename = sourceManager.getFilename(definition->getSourceRange().getBegin());


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
                }
                const auto line = sourceManager.getPresumedLineNumber(enumerator->getSourceRange().getBegin());
                const auto column = sourceManager.getPresumedColumnNumber(enumerator->getSourceRange().getBegin());
                result.values.emplace(enumerator->getNameAsString(),
                                      EnumTypeInfo::ValueInfo{value, {}, {line, column}});
                //std::cout << enumerator->getNameAsString() << std::endl;
            }

            {
                AttributeParser attributeParser{};
                // FIXME
                auto enumAttributes = attributeParser.parseEnumAttributes(astContext, decl);
                result.attributes = std::move(enumAttributes.attributes);

                for (auto [name, attributes]: enumAttributes.valueAttributes) {
                    result.values[name].attributes = std::move(attributes);
                }
            }
            using namespace fmt::literals;
            TypeIdGenerator gen{};

            const auto stringifyAttributes = [](const std::vector<Attribute> &attrs,
                                                const std::vector<std::string> &argArrayNames) {
                // TODO assert size == size
                std::string result{};
                for (auto i = 0ull; i < attrs.size(); ++i) {
                    const auto &attr = attrs[i];
                    const auto &argArrayName = argArrayNames[i];
                    result.append(fmt::format(
                            R"(pf::meta::Attribute{{"{}", std::span<const std::string_view>{{details::{}}}}}, )",
                            attr.name,
                            argArrayName));
                }
                if (!attrs.empty()) { result = result.substr(0, result.length() - 2); }
                return result;
            };

            const auto createAttributeArgArray = [](std::string_view name, const Attribute &attr) {
                std::string result{};
                result.append(fmt::format("constexpr static auto {} = pf::make_array<std::string_view>(", name));
                for (const auto &arg: attr.arguments) {
                    result.append(fmt::format(R"fmt(R"arg({})arg")fmt", arg)).append(", ");
                }
                if (!attr.arguments.empty()) { result = result.substr(0, result.length() - 2); }
                result.append(");");
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

                std::vector<std::string> argsArrayNames;
                std::string detailsContents;
                for (const auto &attr: info.attributes) {
                    const auto argsArrayName = fmt::format("ArgArray_{}", gen.generateRandomInt());
                    argsArrayNames.push_back(argsArrayName);
                    detailsContents.append(createAttributeArgArray(argsArrayName, attr)).append("\n");
                }
                const auto attributesStr = stringifyAttributes(info.attributes, argsArrayNames);

                *outStream << fmt::format(StaticEnumValueInfoTemplate, "details"_a = detailsContents,
                                          "type"_a = result.fullName,
                                          "value_id"_a = idToString(valueId),
                                          "source_file"_a = result.sourceLocation.filename,
                                          "source_line"_a = result.sourceLocation.line,
                                          "source_column"_a = result.sourceLocation.column,
                                          "type_id"_a = idToString(typeId), "attributes"_a = attributesStr,
                                          "name"_a = name,
                                          "full_name"_a = fullName, "underlying_type"_a = result.underlyingType,
                                          "underlying_value"_a = valueStr, "value"_a = fullName);
            }
            if (!valueIdsStr.empty()) { valueIdsStr = valueIdsStr.substr(0, valueIdsStr.length() - 2); }

            const auto const_type_id = idToString(gen.generateTypeId());
            const auto lref_type_id = idToString(gen.generateTypeId());
            const auto const_lref_type_id = idToString(gen.generateTypeId());
            const auto rref_type_id = idToString(gen.generateTypeId());
            const auto ptr_type_id = idToString(gen.generateTypeId());
            const auto const_ptr_type_id = idToString(gen.generateTypeId());

            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: result.attributes) {
                const auto argsArrayName = fmt::format("ArgArray_{}", gen.generateRandomInt());
                argsArrayNames.push_back(argsArrayName);
                detailsContents.append(createAttributeArgArray(argsArrayName, attr)).append("\n");
            }
            const auto attributesStr = stringifyAttributes(result.attributes, argsArrayNames);

            *outStream << fmt::format(
                    StaticEnumTypeInfoTemplate, "details"_a = detailsContents, "type_id"_a = idToString(typeId),
                    "type"_a = result.fullName,
                    "source_file"_a = result.sourceLocation.filename, "source_line"_a = result.sourceLocation.line,
                    "source_column"_a = result.sourceLocation.column, "attributes"_a = attributesStr,
                    "name"_a = result.name,
                    "full_name"_a = result.fullName, "underlying_type"_a = result.underlyingType,
                    "enum_value_ids"_a = valueIdsStr,
                    "const_type_id"_a = const_type_id, "lref_type_id"_a = lref_type_id,
                    "const_lref_type_id"_a = const_lref_type_id,
                    "rref_type_id"_a = rref_type_id, "ptr_type_id"_a = ptr_type_id,
                    "const_ptr_type_id"_a = const_ptr_type_id);

            *outStream << "namespace pf::meta::details {";
            *outStream << fmt::format(GetTypeIDTemplate, "full_name"_a = result.fullName, "type"_a = result.fullName,
                                      "type_id"_a = idToString(typeId), "const_type_id"_a = const_type_id,
                                      "lref_type_id"_a = lref_type_id,
                                      "const_lref_type_id"_a = const_lref_type_id, "rref_type_id"_a = rref_type_id,
                                      "ptr_type_id"_a = ptr_type_id, "const_ptr_type_id"_a = const_ptr_type_id);
            for (const auto &[name, id]: valueIds) {
                *outStream
                        << fmt::format(GetConstantIDTemplate,
                                       "full_name"_a = fmt::format("{}::{}", result.fullName, name),
                                       "constant"_a = name, "value_id"_a = id);
            }
            *outStream << "}";

            return result;
        }

        std::shared_ptr<llvm::raw_fd_ostream> outStream;
    };

// Action
    class ASTAction : public clang::ASTFrontendAction {
    public:
        explicit ASTAction(std::shared_ptr<llvm::raw_fd_ostream> oStream) : outStream{std::move(oStream)} {}

        std::unique_ptr<clang::ASTConsumer>
        CreateASTConsumer(clang::CompilerInstance &Compiler, llvm::StringRef InFile) override {
            return std::make_unique<ASTConsumer>(outStream);
        };

    private:
        std::shared_ptr<llvm::raw_fd_ostream> outStream;
    };

// Factory
    class ActionFactory : public clang::tooling::FrontendActionFactory {
    public:
        explicit ActionFactory(std::shared_ptr<llvm::raw_fd_ostream> oStream) : outStream{std::move(oStream)} {}

        std::unique_ptr<clang::FrontendAction> create() override { return std::make_unique<ASTAction>(outStream); }

    private:
        std::shared_ptr<llvm::raw_fd_ostream> outStream;
    };
}

int main(int argc, const char **argv) {
    llvm::cl::ParseCommandLineOptions(argc, argv, "Test");
    auto sources = std::vector{std::string{InputSource}};


    clang::tooling::FixedCompilationDatabase fixedCompilationDatabase{".", CompilerFlags};
    clang::tooling::ClangTool tool{fixedCompilationDatabase, sources};

    std::error_code errorCode;
    auto outStream = std::make_shared<llvm::raw_fd_ostream>(std::string{OutputHeader}, errorCode,
                                                            llvm::sys::fs::OpenFlags::OF_Text);
    if (errorCode) {
        llvm::errs() << "Failed to open output file: " << errorCode.message();
        return 1;
    }
    *outStream << pf::meta_gen::MetaFilePrologue;
    pf::meta_gen::ActionFactory factory{outStream};
    tool.run(&factory);
    *outStream << pf::meta_gen::MetaFileEpilogue;

    outStream->close();

    if (FormatOutput) { format(std::string{OutputHeader}); }

    return 0;
}
