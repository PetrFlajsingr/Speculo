
#include "MetaSupportCodeGenerator.hpp"
#include "../Visitor.hpp"

#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include <stduuid/uuid.h>

namespace pf::meta_gen {

    [[nodiscard]] std::string idToStringTEMP(pf::meta::details::ID id) { return fmt::format("ID{{0x{:x}u, 0x{:x}u}}", id.id[0], id.id[1]); }


    GenerationResult MetaSupportCodeGenerator::start() {
        GenerationResult result{};
        result.hppCode = R"(#include <meta/macros.hpp>
#include <meta/details/StaticInfo.hpp>
)";
        return result;
    }
    GenerationResult MetaSupportCodeGenerator::end() { return {}; }

    uint64_t MetaSupportCodeGenerator::getPriority() const { return 1; }

    RecordGenerationResult MetaSupportCodeGenerator::generate(const RecordTypeInfo &typeInfo) {
        RecordGenerationResult result{};

        std::string friendDeclarations;
        const auto appendFriend = [&](meta::details::ID id) {
            friendDeclarations.append(
                    fmt::format("friend struct ::pf::meta::details::StaticInfo<::pf::meta::details::{}>;\n", idToStringTEMP(id)));
        };
        for (const auto &m: typeInfo.memberFunctions) {
            if (m.access != Access::Public) { appendFriend(m.id); }
        }
        for (const auto &m: typeInfo.staticFunctions) {
            if (m.access != Access::Public) { appendFriend(m.id); }
        }
        for (const auto &m: typeInfo.memberVariables) {
            if (m.access != Access::Public) { appendFriend(m.id); }
        }
        for (const auto &m: typeInfo.staticVariables) {
            if (m.access != Access::Public) { appendFriend(m.id); }
        }
        for (const auto &m: typeInfo.constructors) {
            if (m.access != Access::Public) { appendFriend(m.id); }
        }
        for (const auto &m: typeInfo.baseClasses) {
            if (m.access != Access::Public) { appendFriend(m.id); }
        }
        if (typeInfo.destructor.access != Access::Public) { appendFriend(typeInfo.destructor.id); }

        result.typeBodyCode.append(friendDeclarations);
        return result;
    }

    GenerationResult MetaSupportCodeGenerator::generate(const EnumTypeInfo &typeInfo) { return {}; }

}// namespace pf::meta_gen