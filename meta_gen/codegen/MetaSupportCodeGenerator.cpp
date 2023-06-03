
#include "MetaSupportCodeGenerator.hpp"
#include "../Visitor.hpp"

#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include <stduuid/uuid.h>

namespace pf::meta_gen {

    [[nodiscard]] std::string idToStringTEMP(pf::meta::details::ID id) { return fmt::format("ID{{0x{:x}u, 0x{:x}u}}", id.id[0], id.id[1]); }


    void MetaSupportCodeGenerator::start() {
        writeToHpp(fmt::format(R"(#include <meta/macros.hpp>
#include <meta/details/StaticInfo.hpp>
#undef PF_META_GENERATED_FILE_ID
#define PF_META_GENERATED_FILE_ID {}
)",
                               getHeaderUuid()));
    }

    void MetaSupportCodeGenerator::handle(const meta_gen::TypeInfoVariant &typeInfo) {
        using namespace fmt::literals;
        constexpr auto friendMacroTemplate = R"(#define PF_META_GENERATED_{line}_{file_id} {body})";


        std::visit(Visitor{[&](const EnumTypeInfo &enumInfo) {},
                           [&](const RecordTypeInfo &recordInfo) {
                               // no need to write friends because macro is not in use
                               if (!recordInfo.hasPfMetaGeneratedMacro) { return; }
                               std::string macroBody;
                               std::size_t generatedMacroLineOffset{};
                               if (const auto pos = recordInfo.originalCode.find("PF_META_GENERATED()"); pos != std::string::npos) {
                                   for (auto i = 0; i < pos; ++i) {
                                       if (recordInfo.originalCode[i] == '\n') { ++generatedMacroLineOffset; }
                                   }
                               }
                               generatedMacroLineOffset += recordInfo.sourceLocation.line;

                               const auto appendFriend = [&](meta::details::ID id) {
                                   macroBody.append(fmt::format("friend struct ::pf::meta::details::StaticInfo<::pf::meta::details::{}>;",
                                                                idToStringTEMP(id)));
                               };
                               for (const auto &m: recordInfo.memberFunctions) {
                                   if (m.access != Access::Public) { appendFriend(m.id); }
                               }
                               for (const auto &m: recordInfo.staticFunctions) {
                                   if (m.access != Access::Public) { appendFriend(m.id); }
                               }
                               for (const auto &m: recordInfo.memberVariables) {
                                   if (m.access != Access::Public) { appendFriend(m.id); }
                               }
                               for (const auto &m: recordInfo.staticVariables) {
                                   if (m.access != Access::Public) { appendFriend(m.id); }
                               }
                               for (const auto &m: recordInfo.constructors) {
                                   if (m.access != Access::Public) { appendFriend(m.id); }
                               }
                               for (const auto &m: recordInfo.baseClasses) {
                                   if (m.access != Access::Public) { appendFriend(m.id); }
                               }
                               if (recordInfo.destructor.access != Access::Public) { appendFriend(recordInfo.destructor.id); }

                               writeToHpp(fmt::format(friendMacroTemplate, "line"_a = generatedMacroLineOffset,
                                                      "file_id"_a = getHeaderUuid(), "body"_a = macroBody));
                               writeToHpp("\n");
                           },
                           [](auto) { spdlog::error("MetaSupportCodeGenerator: unimplemented type"); }},
                   typeInfo);
    }

    void MetaSupportCodeGenerator::end() {}

    uint64_t MetaSupportCodeGenerator::getPriority() const { return 1; }

}// namespace pf::meta_gen