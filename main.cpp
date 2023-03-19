#include <iostream>

#include <pf_common/ScopeExit.h>
#include <pf_common/array.h>

#include <fmt/core.h>
#include <spdlog/spdlog.h>
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
#include "meta_gen/AstActions.h"

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
// TODO: deduplicate
[[nodiscard]] std::string idToString(pf::meta::details::ID id) { return fmt::format("ID{{0x{:x}u, 0x{:x}u}}", id.id[0], id.id[1]); }
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
    const auto typeId = idToString(gen.generateTypeId(std::string{fullTypeName}));
    std::string result{fmt::format(prologue, "full_name"_a = fullTypeName)};
    result.append(fmt::format(typeTemplate, "type_id"_a = typeId, "type_name"_a = typeName, "full_type_name"_a = fullTypeName));
    for (const auto &toGen: typesToGenerate) {
        const auto variantTypeName = wrapNameForInfoType(toGen, std::string{fullTypeName});
        const auto variantId = idToString(gen.generateTypeId(variantTypeName));
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
        spdlog::error("Failed to open output file: {}", errorCode.message());
        return 1;
    }
    auto idGenerator = std::make_shared<pf::meta_gen::IdGenerator>();
    pf::meta_gen::ActionFactory factory{outStream, idGenerator};
    if (const auto ret = tool.run(&factory); ret != 0) {
        spdlog::error("ClangTool run failed with code {}", ret);
    }

    outStream->close();

    if (FormatOutput) { format(std::string{OutputHeader}); }

    return 0;
}
