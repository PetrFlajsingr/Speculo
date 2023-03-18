#include <iostream>

#include <pf_common/ScopeExit.h>
#include <pf_common/array.h>

#include <fmt/core.h>

#include "meta/Info.h"

#include "meta_gen/AttributeParser.h"
#include "meta_gen/IdGenerator.h"
#include "meta_gen/clang_tooling_compilationdatabase_wrap.h"
#include "meta_gen/info_structs.h"

#include "meta_gen/src_templates/GetConstantID_template.h"
#include "meta_gen/src_templates/GetTypeID_template.h"
#include "meta_gen/src_templates/MetaFilePrologueEpilogue.h"
#include "meta_gen/src_templates/StaticTypeInfo_template.h"
#include "meta_gen/src_templates/StaticValueInfo_template.h"

#include "format.h"

static llvm::cl::opt<std::string> InputSource(llvm::cl::Required, "in-source", llvm::cl::desc("Specify input filename"),
                                              llvm::cl::value_desc("filename"));
static llvm::cl::opt<std::string> OutputHeader("out-header", llvm::cl::desc("Specify header output filename"),
                                               llvm::cl::value_desc("filename"), llvm::cl::init("output.hpp"));
static llvm::cl::opt<std::string> OutputSource("out-source", llvm::cl::desc("Specify source output filename"),
                                               llvm::cl::value_desc("filename"), llvm::cl::init("output.cpp"));
static llvm::cl::opt<bool> IgnoreIncludes("ignore-includes", llvm::cl::desc("Ignore includes while parsing the file"),
                                          llvm::cl::value_desc("bool"), llvm::cl::init(true));
static llvm::cl::opt<bool> FormatOutput("format-output", llvm::cl::desc("Reformat outputs"), llvm::cl::value_desc("bool"),
                                        llvm::cl::init(false));

static llvm::cl::list<std::string> CompilerFlags("flag", llvm::cl::desc("Compiler flags"), llvm::cl::value_desc("flags"),
                                                 llvm::cl::ZeroOrMore);

namespace pf::meta_gen {

    [[nodiscard]] std::string idToString(pf::meta::details::ID id) { return fmt::format("ID{{0x{:x}u, 0x{:x}u}}", id.id[0], id.id[1]); }


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

                if (const auto enumDecl = clang::dyn_cast<clang::EnumDecl>(decl);
                    enumDecl != nullptr && !enumDecl->isInvalidDecl()) {// enum
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
            result.sourceLocation.column = sourceManager.getPresumedColumnNumber(definition->getSourceRange().getBegin());
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
                result.values.emplace(enumerator->getNameAsString(), EnumTypeInfo::ValueInfo{value, {}, {line, column}});
                //std::cout << enumerator->getNameAsString() << std::endl;
            }

            {
                AttributeParser attributeParser{};
                // FIXME
                auto enumAttributes = attributeParser.parseEnumAttributes(astContext, decl);
                result.attributes = std::move(enumAttributes.attributes);

                for (auto [name, attributes]: enumAttributes.valueAttributes) { result.values[name].attributes = std::move(attributes); }
            }
            using namespace fmt::literals;
            IdGenerator gen{};

            const auto stringifyAttributes = [](const std::vector<Attribute> &attrs, const std::vector<std::string> &argArrayNames) {
                // TODO assert size == size
                std::string attributesString{};
                for (auto i = 0ull; i < attrs.size(); ++i) {
                    const auto &attr = attrs[i];
                    const auto &argArrayName = argArrayNames[i];
                    attributesString.append(fmt::format(R"(Attribute{{"{}", std::span<const std::string_view>{{details::{}}}}}, )",
                                                        attr.name, argArrayName));
                }
                if (!attrs.empty()) { return attributesString.substr(0, attributesString.length() - 2); }
                return attributesString;
            };

            const auto createAttributeArgArray = [](std::string_view name, const Attribute &attr) {
                std::string attributeArgsStr{};
                attributeArgsStr.append(fmt::format("constexpr static auto {} = make_array<std::string_view>(", name));
                for (const auto &arg: attr.arguments) { attributeArgsStr.append(fmt::format(R"fmt(R"arg({})arg")fmt", arg)).append(", "); }
                if (!attr.arguments.empty()) { attributeArgsStr = attributeArgsStr.substr(0, attributeArgsStr.length() - 2); }
                attributeArgsStr.append(");");
                return attributeArgsStr;
            };

            const auto typeId = gen.generateTypeId(result.fullName);


            std::unordered_map<std::string, std::string> valueIds{};
            std::string valueIdsStr{};
            for (const auto &[name, info]: result.values) {
                const auto fullName = fmt::format("{}::{}", result.fullName, name);
                const auto valueId = gen.generateTypeId(fullName);
                const auto valueIdStr = idToString(valueId);
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

                *outStream << fmt::format(StaticValueInfoTemplate_Enum, "details"_a = detailsContents, "type"_a = result.fullName,
                                          "value_id"_a = idToString(valueId), "source_file"_a = result.sourceLocation.filename,
                                          "source_line"_a = result.sourceLocation.line, "source_column"_a = result.sourceLocation.column,
                                          "type_id"_a = idToString(typeId), "attributes"_a = attributesStr, "name"_a = name,
                                          "full_name"_a = fullName, "underlying_type"_a = result.underlyingType,
                                          "underlying_value"_a = valueStr, "value"_a = fullName);
            }
            if (!valueIdsStr.empty()) { valueIdsStr = valueIdsStr.substr(0, valueIdsStr.length() - 2); }

            const auto const_type_id = idToString(gen.generateTypeId("const " + result.fullName));
            const auto lref_type_id = idToString(gen.generateTypeId(result.fullName + "&"));
            const auto const_lref_type_id = idToString(gen.generateTypeId("const " + result.fullName + "&"));
            const auto rref_type_id = idToString(gen.generateTypeId(result.fullName + "&&"));
            const auto ptr_type_id = idToString(gen.generateTypeId(result.fullName + "*"));
            const auto const_ptr_type_id = idToString(gen.generateTypeId("const" + result.fullName + "*"));

            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: result.attributes) {
                const auto argsArrayName = fmt::format("ArgArray_{}", gen.generateRandomInt());
                argsArrayNames.push_back(argsArrayName);
                detailsContents.append(createAttributeArgArray(argsArrayName, attr)).append("\n");
            }
            const auto attributesStr = stringifyAttributes(result.attributes, argsArrayNames);

            *outStream << fmt::format(StaticTypeInfoTemplate_Enum, "details"_a = detailsContents, "type_id"_a = idToString(typeId),
                                      "type"_a = result.fullName, "source_file"_a = result.sourceLocation.filename,
                                      "source_line"_a = result.sourceLocation.line, "source_column"_a = result.sourceLocation.column,
                                      "attributes"_a = attributesStr, "name"_a = result.name, "full_name"_a = result.fullName,
                                      "underlying_type"_a = result.underlyingType, "enum_value_ids"_a = valueIdsStr,
                                      "const_type_id"_a = const_type_id, "lref_type_id"_a = lref_type_id,
                                      "const_lref_type_id"_a = const_lref_type_id, "rref_type_id"_a = rref_type_id,
                                      "ptr_type_id"_a = ptr_type_id, "const_ptr_type_id"_a = const_ptr_type_id);

            *outStream << fmt::format(GetTypeIDTemplate, "full_name"_a = result.fullName, "type"_a = result.fullName,
                                      "type_id"_a = idToString(typeId), "const_type_id"_a = const_type_id, "lref_type_id"_a = lref_type_id,
                                      "const_lref_type_id"_a = const_lref_type_id, "rref_type_id"_a = rref_type_id,
                                      "ptr_type_id"_a = ptr_type_id, "const_ptr_type_id"_a = const_ptr_type_id);
            for (const auto &[name, id]: valueIds) {
                *outStream << fmt::format(GetConstantIDTemplate, "full_name"_a = fmt::format("{}::{}", result.fullName, name),
                                          "constant"_a = name, "value_id"_a = id);
            }

            return result;
        }

        std::shared_ptr<llvm::raw_fd_ostream> outStream;
    };

    // Action
    class ASTAction : public clang::ASTFrontendAction {
    public:
        explicit ASTAction(std::shared_ptr<llvm::raw_fd_ostream> oStream) : outStream{std::move(oStream)} {}

        std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &Compiler, llvm::StringRef InFile) override {
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
}// namespace pf::meta_gen

#include <unordered_set>

enum class InfoType { Const, Lvalue, ConstLvalue, Rvalue, Ptr, ConstPtr };

[[nodiscard]] constexpr std::string wrapStructForInfoType(InfoType infoType) {
    switch (infoType) {
        case InfoType::Const:
            return "StaticInfo_ConstWrap";
        case InfoType::Lvalue:
            return "StaticInfo_LRefWrap";
        case InfoType::ConstLvalue:
            return "StaticInfo_ConstLRefWrap";
        case InfoType::Rvalue:
            return "StaticInfo_RRefWrap";
        case InfoType::Ptr:
            return "StaticInfo_PtrWrap";
        case InfoType::ConstPtr:
            return "StaticInfo_ConstPtrWrap";
    }
    throw "can't happen";
}

[[nodiscard]] constexpr std::string wrapNameForInfoType(InfoType infoType, const std::string &fullTypeName) {
    switch (infoType) {
        case InfoType::Const:
            return "const " + fullTypeName;
        case InfoType::Lvalue:
            return fullTypeName + "&";
        case InfoType::ConstLvalue:
            return "const " + fullTypeName + "&";
        case InfoType::Rvalue:
            return fullTypeName + "&&";
        case InfoType::Ptr:
            return fullTypeName + "*";
        case InfoType::ConstPtr:
            return "const " + fullTypeName + "*";
    }
    throw "can't happen";
}

std::string generateFundamentalStaticTypeInfo(pf::meta_gen::IdGenerator &gen, std::string_view typeName, std::string_view fullTypeName,
                                              std::unordered_set<InfoType> typesToGenerate = {InfoType::Const, InfoType::Lvalue,
                                                                                              InfoType::ConstLvalue, InfoType::Rvalue,
                                                                                              InfoType::Ptr, InfoType::ConstPtr}) {
    using namespace fmt::literals;
    constexpr auto prologue = R"fmt(
/****************************** {full_name} START ******************************/
)fmt";
    constexpr auto epilogue = R"fmt(
/****************************** {full_name} END ******************************/
)fmt";
    constexpr auto typeTemplate = R"fmt(
template<>
struct StaticInfo<{type_id}> : FundamentalStaticTypeInfo<{full_type_name}, {type_id}, StringLiteral{{"{type_name}"}}, StringLiteral{{"{full_type_name}"}}> {{}};
template<>
[[nodiscard]] consteval ID getTypeId<{full_type_name}>() {{
    return {type_id};
}}
)fmt";
    constexpr auto variantTypeTemplate = R"fmt(
template<>
struct StaticInfo<{variant_id}> : {wrap_struct}<{variant_id}, {type_id}> {{}};
template<>
[[nodiscard]] consteval ID getTypeId<{full_wrap_type_name}>() {{
    return {variant_id};
}}
)fmt";
    const auto typeId = pf::meta_gen::idToString(gen.generateTypeId(std::string{fullTypeName}));
    std::string result{fmt::format(prologue, "full_name"_a = fullTypeName)};
    result.append(fmt::format(typeTemplate, "type_id"_a = typeId, "type_name"_a = typeName, "full_type_name"_a = fullTypeName));
    for (const auto &toGen: typesToGenerate) {
        const auto variantTypeName = wrapNameForInfoType(toGen, std::string{fullTypeName});
        const auto variantId = pf::meta_gen::idToString(gen.generateTypeId(variantTypeName));
        result.append(fmt::format(variantTypeTemplate, "variant_id"_a = variantId, "wrap_struct"_a = wrapStructForInfoType(toGen),
                                  "type_id"_a = typeId, "full_wrap_type_name"_a = variantTypeName));
    }
    result.append(fmt::format(epilogue, "full_name"_a = fullTypeName));

    return result;
}

int main(int argc, const char **argv) {
    llvm::cl::ParseCommandLineOptions(argc, argv, "Test");

   /*
    // TODO: create a separate exe for this
    pf::meta_gen::TypeIdGenerator gen{};
    constexpr auto fundamentalTypes = pf::make_array<std::string_view>(
            "bool", "char", "signed char", "unsigned char", "char8_t", "char16_t", "char32_t", "short", "unsigned short", "int",
            "unsigned int", "long", "unsigned long", "long long", "unsigned long long", "float", "double", "long double");
    std::string output;
    for (const auto fundamentalType: fundamentalTypes) {
        output.append(generateFundamentalStaticTypeInfo(gen, fundamentalType, fundamentalType)).append("\n");
    }
    output.append(generateFundamentalStaticTypeInfo(gen, "void", "void", {InfoType::Ptr, InfoType::ConstPtr})).append("\n");

    output.append(generateFundamentalStaticTypeInfo(gen, "nullptr_t", "std::nullptr_t", {})).append("\n");


    std::error_code errorCode;
    auto outStream =
            std::make_shared<llvm::raw_fd_ostream>(std::string{OutputHeader} + "_ungabunga", errorCode, llvm::sys::fs::OpenFlags::OF_Text);

    *outStream << output;

    return 0;*/
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
