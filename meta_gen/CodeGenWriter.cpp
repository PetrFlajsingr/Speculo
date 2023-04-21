
#include "CodeGenWriter.hpp"

#include <fmt/format.h>
#include <pf_common/Visitor.h>
#include <spdlog/spdlog.h>

#include <stduuid/uuid.h>

namespace pf::meta_gen {

    [[nodiscard]] std::string idToStringTEMP(pf::meta::details::ID id) { return fmt::format("ID{{0x{:x}u, 0x{:x}u}}", id.id[0], id.id[1]); }

    void CodeGenWriter::start(std::string_view fileName) {
        uuids::uuid_name_generator uuidGenerator{uuids::uuid::from_string("471F3823-2574-4bfd-b411-99ed177d3e43").value()};
        const auto fileUUID = uuidGenerator(fileName);
        fileUUIDstr = to_string(fileUUID);
        std::ranges::replace(fileUUIDstr, '-', '_');
        write("#include <meta/macros.h>\n");
        write("#include <meta/details/StaticInfo.h>\n");
        write(fmt::format(R"(#undef PF_META_GENERATED_FILE_ID
#define PF_META_GENERATED_FILE_ID {}
)",
                          fileUUIDstr));
    }

    void CodeGenWriter::generate(const meta_gen::TypeInfoVariant &typeInfo) {
        using namespace fmt::literals;
        constexpr auto friendMacroTemplate = R"(#define PF_META_GENERATED_{line}_{file_id} {body})";


        std::visit(Visitor{[&](const EnumTypeInfo &enumInfo) {},
                           [&](const RecordTypeInfo &recordInfo) {
                               std::string macroBody;
                               std::size_t generatedMacroLineOffset{};
                               if (const auto pos = recordInfo.originalCode.find("PF_META_GENERATED"); pos != std::string::npos) {
                                   for (auto i = 0; i < pos; ++i) {
                                       if (recordInfo.originalCode[i] == '\n') {
                                           ++generatedMacroLineOffset;
                                       }
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

                               write(fmt::format(friendMacroTemplate, "line"_a = generatedMacroLineOffset, "file_id"_a = fileUUIDstr, "body"_a = macroBody));
                               write("\n");
                           },
                           [](auto) { spdlog::error("CodeGenWriter: unimplemented type"); }},
                   typeInfo);
    }
    void CodeGenWriter::write(std::string_view str) { *ostream << str; }

    void CodeGenWriter::end() {}

}// namespace pf::meta_gen