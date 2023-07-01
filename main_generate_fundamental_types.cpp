#include "format.hpp"
#include "speculo/Info.hpp"
#include "speculo/details/array.hpp"
#include "speculo_gen/IdGenerator.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include <fmt/format.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/raw_ostream.h>
#include <string>
#include <unordered_set>
#include "speculo_gen/idToString.hpp"

static llvm::cl::opt<std::string> Output(llvm::cl::Required, "output", llvm::cl::desc("Specify output path"),
                                         llvm::cl::value_desc("filename"));

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

std::string generateFundamentalStaticTypeInfo(speculo::gen::IdGenerator &gen, std::string_view typeName, std::string_view fullTypeName,
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
    const auto typeId = speculo::gen::idToString(gen.generateId(std::string{fullTypeName}));
    std::string result{fmt::format(prologue, "full_name"_a = fullTypeName)};
    result.append(fmt::format(typeTemplate, "type_id"_a = typeId, "type_name"_a = typeName, "full_type_name"_a = fullTypeName));
    for (const auto &toGen: typesToGenerate) {
        const auto variantTypeName = wrapNameForInfoType(toGen, std::string{fullTypeName});
        const auto variantId = speculo::gen::idToString(gen.generateId(variantTypeName));
        result.append(fmt::format(variantTypeTemplate, "variant_id"_a = variantId, "wrap_struct"_a = wrapStructForInfoType(toGen),
                                  "type_id"_a = typeId, "full_wrap_type_name"_a = variantTypeName));
    }
    result.append(fmt::format(epilogue, "full_name"_a = fullTypeName));

    return result;
}


int main(int argc, char **argv) {
    spdlog::set_level(spdlog::level::debug);
    spdlog::default_logger()->sinks().clear();
    spdlog::default_logger()->sinks().emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    llvm::cl::ParseCommandLineOptions(argc, argv, "speculo generate fundamental type infos");

    speculo::gen::IdGenerator gen{};
    constexpr auto fundamentalTypes = speculo::make_array<std::string_view>(
            "bool", "char", "signed char", "unsigned char", "char8_t", "char16_t", "char32_t", "short", "unsigned short", "int",
            "unsigned int", "long", "unsigned long", "long long", "unsigned long long", "float", "double", "long double");
    std::string output;
    for (const auto fundamentalType: fundamentalTypes) {
        output.append(generateFundamentalStaticTypeInfo(gen, fundamentalType, fundamentalType)).append("\n");
    }
    output.append(generateFundamentalStaticTypeInfo(gen, "void", "void", {InfoType::Ptr, InfoType::ConstPtr})).append("\n");

    output.append(generateFundamentalStaticTypeInfo(gen, "nullptr_t", "std::nullptr_t", {})).append("\n");


    std::error_code errorCode;
    auto outStream = std::make_shared<llvm::raw_fd_ostream>(std::string{Output}, errorCode, llvm::sys::fs::OpenFlags::OF_Text);
    if (errorCode) {
        spdlog::error("Failed to open output file '{}': {}", std::string{Output}, errorCode.message());
        return 0;
    }

    *outStream << R"(#pragma once

#include <speculo/Attribute.hpp>
#include <speculo/Info.hpp>
#include <speculo/details/StaticInfo.hpp>
#include <speculo/details/StringLiteral.hpp>
#include <speculo/details/StaticInfo_Wrappers.hpp>
#include <speculo/details/array.hpp>

namespace speculo::details {

    template<typename T, ID TID, StringLiteral TypeName, StringLiteral FullTypeName = TypeName> requires(std::is_fundamental_v<T>)
    struct FundamentalStaticTypeInfo {
        using Type = T;
        constexpr static ID Id = TID;

        // FIXME: RangeOf msvc failure here
        constexpr static /*RangeOf<speculo::Attribute>*/ auto Attributes = speculo::make_array<speculo::Attribute>();


        constexpr static auto StaticInfoObjectType = StaticInfoType::FundamentalType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;
        constexpr static bool IsVolatile = false;
        constexpr static bool IsLiteral = true;
        constexpr static bool IsPOD = true;
        constexpr static bool IsStandardLayout = true;
        constexpr static bool IsTriviallyCopyable = true;
        constexpr static bool IsTrivial = true;
        constexpr static bool IsEmpty = false;
        constexpr static bool IsAggregate = false;

        constexpr static auto Name = TypeName;
        constexpr static auto FullName = FullTypeName;
    };)";
    *outStream << output;
    *outStream << "}";
    outStream->close();

    format(std::string{Output});

    return 0;
}