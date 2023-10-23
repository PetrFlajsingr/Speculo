module;

#include <string>
#include <vector>
#include <ranges>
#include <cstdint>

#include <fmt/format.h>

module speculo.gen;
import speculo;
import :meta_code_generator;
import :structs;
import :algorithms;

namespace speculo::gen {

    std::uint64_t MetaSupportCodeGenerator::getPriority() const { return 1; }

    RecordGenerationResult MetaSupportCodeGenerator::generate(RecordTypeInfo &typeInfo) {
        RecordGenerationResult result{};

        std::vector<std::string> friendDeclarations;
        const auto appendFriendDeclaration = [&](speculo::ID id) {
            friendDeclarations.push_back(fmt::format("friend struct ::speculo::details::StaticInfo<::speculo::{}>;", idToString(id)));
        };
        const auto appendNonPublicFriends = [&](const std::ranges::range auto &infoCollection) {
            for (const auto &info: infoCollection) {
                if (info.access != Access::Public) { appendFriendDeclaration(info.id); }
            }
        };
        appendNonPublicFriends(typeInfo.memberFunctions);
        appendNonPublicFriends(typeInfo.staticFunctions);
        appendNonPublicFriends(typeInfo.memberVariables);
        appendNonPublicFriends(typeInfo.staticVariables);
        appendNonPublicFriends(typeInfo.constructors);
        appendNonPublicFriends(typeInfo.baseClasses);
        if (typeInfo.destructor.access != Access::Public) { appendFriendDeclaration(typeInfo.destructor.id); }


        result.typeBodyCode.append(join(friendDeclarations, "\n"));
        return result;
    }

    GenerationResult MetaSupportCodeGenerator::generate(const EnumTypeInfo &typeInfo) { return {}; }

    FilePrologueEpilogue MetaSupportCodeGenerator::getPrologueEpilogue() {
        return {.hppPrologue = R"(#include <speculo/reflect.hpp>
import speculo;
#include <cstddef>
)"};
    }

}// namespace speculo::gen