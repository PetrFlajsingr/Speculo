
#include "CodeGenWriter.hpp"

#include <fmt/format.h>
#include <pf_common/Visitor.h>
#include <spdlog/spdlog.h>

namespace pf::meta_gen {

    [[nodiscard]] std::string idToStringTEMP(pf::meta::details::ID id) { return fmt::format("ID{{0x{:x}u, 0x{:x}u}}", id.id[0], id.id[1]); }

    void CodeGenWriter::generate(const meta_gen::TypeInfoVariant &typeInfo) {
        using namespace fmt::literals;
        constexpr auto friendMacroTemplate = R"(#define PF_META_GENERATED_{type_name} {body})";

        std::visit(Visitor{[&](const EnumTypeInfo &enumInfo) {},
                           [&](const RecordTypeInfo &recordInfo) {
                               std::string macroBody;
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

                               write(fmt::format(friendMacroTemplate, "type_name"_a = recordInfo.name, "body"_a = macroBody));
                               write("\n");
                           },
                           [](auto) { spdlog::error("CodeGenWriter: unimplemented type"); }},
                   typeInfo);
    }

    void CodeGenWriter::write(std::string_view str) { *ostream << str; }

}// namespace pf::meta_gen