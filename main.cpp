#include <iostream>

#include <pf_common/array.h>

#include "meta/Info.h"
#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include "meta_gen/AttributeParser.h"
#include "meta_gen/IdGenerator.h"
#include "meta_gen/clang_tooling_compilationdatabase_wrap.h"
#include "meta_gen/info_structs.h"

#include "format.h"
#include "meta_gen/AstActions.h"
#include <clang/Tooling/CommonOptionsParser.h>

#include<nlohmann/json.hpp>
#include <fstream>

static llvm::cl::OptionCategory PfMetaGenCategory("pf_meta_gen options");

static llvm::cl::opt<std::string> ConfigArg(llvm::cl::Required, "config", llvm::cl::desc("Specify input config"),
                                            llvm::cl::value_desc("filename"));
static llvm::cl::opt<bool> IgnoreIncludes("ignore-includes", llvm::cl::desc("Ignore includes while parsing the file"),
                                          llvm::cl::value_desc("bool"), llvm::cl::init(true));
static llvm::cl::opt<bool> FormatOutput("format-output", llvm::cl::desc("Reformat outputs"),
                                        llvm::cl::value_desc("bool"),
                                        llvm::cl::init(false));


static llvm::cl::extrahelp CommonHelp(clang::tooling::CommonOptionsParser::HelpMessage);

#include "meta_gen/Config.h"

[[nodiscard]] std::optional<pf::meta_gen::Config> createConfig(const std::filesystem::path &configPath) {
    std::ifstream configFile{configPath};
    if (!configFile.is_open()) {
        spdlog::error("Can't open file '{}'", configPath.string());
        return std::nullopt;
    }
    auto data = nlohmann::json::parse(configFile);
    // TODO: multiple input files
    auto inputFile = std::filesystem::path{std::string{data["header_paths"][0]}};
    auto metaHeader = inputFile;
    metaHeader.replace_extension("meta.hpp");
    auto generatedHeader = inputFile;
    generatedHeader.replace_extension("generated.hpp");
    auto generatedSource = inputFile;
    generatedSource.replace_extension("generated.cpp");

    const auto projectRoot = std::filesystem::path{std::string{data["project_root"]}};
    inputFile = projectRoot / inputFile;
    metaHeader = projectRoot / metaHeader;
    generatedHeader = projectRoot / generatedHeader;
    generatedSource = projectRoot / generatedSource;

    std::vector<std::string> flags{"-xc++", "-Wno-unknown-attributes"};
    for (const auto &flag: data["compiler_flags"]) {
        flags.push_back(flag);
    }
    for (const auto &includePath: data["include_paths"]) {
        flags.push_back(fmt::format("-I{}", std::string{includePath}));
    }
    return pf::meta_gen::Config{.inputSource = inputFile,
            .outputMetaHeader = metaHeader,
            .outputCodegenHeader = generatedHeader,
            .outputCodegenSource = generatedSource,
            .projectRootDir = projectRoot,
            .ignoreIncludes = IgnoreIncludes,
            .formatOutput = FormatOutput,
            .compilerFlags = std::move(flags),
            .inputIncludePath = inputFile.string()};
}

#include <unordered_set>

enum class InfoType {
    Const, Lvalue, ConstLvalue, Rvalue, Ptr, ConstPtr
};

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
            return fullTypeName + " &";
        case InfoType::ConstLvalue:
            return "const " + fullTypeName + " &";
        case InfoType::Rvalue:
            return fullTypeName + " &&";
        case InfoType::Ptr:
            return fullTypeName + " *";
        case InfoType::ConstPtr:
            return "const " + fullTypeName + " *";
    }
    throw "can't happen";
}

// TODO: deduplicate
[[nodiscard]] std::string idToString(pf::meta::details::ID id) {
    return fmt::format("ID{{0x{:x}u, 0x{:x}u}}", id.id[0], id.id[1]);
}

std::string generateFundamentalStaticTypeInfo(pf::meta_gen::IdGenerator &gen, std::string_view typeName,
                                              std::string_view fullTypeName,
                                              std::unordered_set<InfoType> typesToGenerate = {InfoType::Const,
                                                                                              InfoType::Lvalue,
                                                                                              InfoType::ConstLvalue,
                                                                                              InfoType::Rvalue,
                                                                                              InfoType::Ptr,
                                                                                              InfoType::ConstPtr}) {
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
    const auto typeId = idToString(gen.generateId(std::string{fullTypeName}));
    std::string result{fmt::format(prologue, "full_name"_a = fullTypeName)};
    result.append(fmt::format(typeTemplate, "type_id"_a = typeId, "type_name"_a = typeName,
                              "full_type_name"_a = fullTypeName));
    for (const auto &toGen: typesToGenerate) {
        const auto variantTypeName = wrapNameForInfoType(toGen, std::string{fullTypeName});
        const auto variantId = idToString(gen.generateId(variantTypeName));
        result.append(fmt::format(variantTypeTemplate, "variant_id"_a = variantId,
                                  "wrap_struct"_a = wrapStructForInfoType(toGen),
                                  "type_id"_a = typeId, "full_wrap_type_name"_a = variantTypeName));
    }
    result.append(fmt::format(epilogue, "full_name"_a = fullTypeName));

    return result;
}

int main(int argc, const char **argv) {
    spdlog::set_level(spdlog::level::debug);
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

    const auto configOpt = createConfig(std::filesystem::path{std::string{ConfigArg}});
    if (!configOpt.has_value()) {
        return 0;
    }
    const auto config = *configOpt;
    std::vector<std::string> sources{config.inputSource.string()};

    clang::tooling::FixedCompilationDatabase fixedCompilationDatabase{".", config.compilerFlags};
    //std::string err;
    //auto db = clang::tooling::FixedCompilationDatabase::loadFromFile("C:\\Users\\xflajs00\\CLionProjects\\libclang_test\\cmake-build-debug\\compile_commands.json", err);// fixedCompilationDatabase{".", config.compilerFlags};
    //clang::tooling::ClangTool tool{fixedCompilationDatabase, sources};
    clang::tooling::ClangTool tool{fixedCompilationDatabase, sources};


    std::error_code errorCode;
    auto metaOutStream = std::make_shared<llvm::raw_fd_ostream>(config.outputMetaHeader.string(), errorCode,
                                                                llvm::sys::fs::OpenFlags::OF_Text);
    if (errorCode) {
        spdlog::error("Failed to open output file: {}", errorCode.message());
        return 1;
    }
    auto codeGenOutStream =
            std::make_shared<llvm::raw_fd_ostream>(config.outputCodegenHeader.string(), errorCode,
                                                   llvm::sys::fs::OpenFlags::OF_Text);
    if (errorCode) {
        spdlog::error("Failed to open output file: {}", errorCode.message());
        return 1;
    }
    auto idGenerator = std::make_shared<pf::meta_gen::IdGenerator>();
    pf::meta_gen::ActionFactory factory{config, metaOutStream, codeGenOutStream, idGenerator};
    if (const auto ret = tool.run(&factory); ret != 0) { spdlog::error("ClangTool run failed with code {}", ret); }

    metaOutStream->close();
    codeGenOutStream->close();

    if (FormatOutput) { format(std::string{config.outputMetaHeader.string()}); }

    return 0;
}
