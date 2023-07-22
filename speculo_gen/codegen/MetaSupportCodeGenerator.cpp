
#include "MetaSupportCodeGenerator.hpp"
#include "../algorithms/join.hpp"
#include "../idToString.hpp"

#include <fmt/format.h>

namespace speculo::gen {

    uint64_t MetaSupportCodeGenerator::getPriority() const { return 1; }

    RecordGenerationResult MetaSupportCodeGenerator::generate(RecordTypeInfo &typeInfo) {
        RecordGenerationResult result{};

        std::vector<std::string> friendDeclarations;
        const auto appendFriendDeclaration = [&](speculo::ID id) {
            friendDeclarations.emplace_back(fmt::format("friend struct ::speculo::details::StaticInfo<::speculo::{}>;", idToString(id)));
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
        return {.hppPrologue = R"(#include <speculo/macros.hpp>
#include <speculo/details/StaticInfo.hpp>
)"};
    }

}// namespace speculo::gen