//
// Created by xflajs00 on 19.03.2023.
//

#include "MetaInfoWriter.h"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include "src_templates/GetConstantID_template.h"
#include "src_templates/GetTypeID_template.h"
#include "src_templates/StaticBaseInfo_template.h"
#include "src_templates/StaticConstructorInfo_template.h"
#include "src_templates/StaticDestructorInfo_template.h"
#include "src_templates/StaticMemberFunctionInfo_template.h"
#include "src_templates/StaticMemberVariableInfo_template.h"
#include "src_templates/StaticStaticFunctionInfo_template.h"
#include "src_templates/StaticStaticVariableInfo_template.h"
#include "src_templates/StaticTypeInfo_template.h"
#include "src_templates/StaticValueInfo_template.h"
#include <pf_common/Visitor.h>

namespace pf::meta_gen {
    [[nodiscard]] std::string idToString(pf::meta::details::ID id) { return fmt::format("ID{{0x{:x}u, 0x{:x}u}}", id.id[0], id.id[1]); }

    MetaInfoWriter::MetaInfoWriter(std::shared_ptr<llvm::raw_ostream> os, std::shared_ptr<IdGenerator> idGen)
        : idGenerator(std::move(idGen)), ostream(std::move(os)) {}

    void MetaInfoWriter::write(std::string_view str) { *ostream << str; }

    void MetaInfoWriter::write(const TypeInfoVariant &typeInfo) {
        std::visit(Visitor{[&](const EnumTypeInfo &enumInfo) { writeEnumInfo(enumInfo); },
                           [&](const RecordTypeInfo &recordInfo) { writeRecordInfo(recordInfo); },
                           [](auto) { spdlog::error("MetaInfoWriter: unimplemented type"); }},
                   typeInfo);
    }

    void MetaInfoWriter::writeEnumInfo(const EnumTypeInfo &enumInfo) {
        using namespace fmt::literals;
        std::unordered_map<std::string, std::string> valueIds{};
        std::string valueIdsStr{};
        for (auto &[name, info]: enumInfo.values) {
            const auto valueIdStr = idToString(info.id);
            valueIds.emplace(info.fullName, valueIdStr);
            valueIdsStr.append(valueIdStr);
            valueIdsStr.append(", ");

            const auto valueStr = std::visit([](auto val) { return fmt::format("{}", val); }, info.value);

            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: info.attributes) {
                const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                argsArrayNames.push_back(argsArrayName);
                detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
            }
            const auto attributesStr = StringifyAttributes(info.attributes, argsArrayNames);

            write(fmt::format(StaticValueInfoTemplate_Enum, "details"_a = detailsContents, "type"_a = enumInfo.fullName,
                              "value_id"_a = idToString(info.id), "source_file"_a = enumInfo.sourceLocation.filename,
                              "source_line"_a = info.sourceLocation.line, "source_column"_a = info.sourceLocation.column,
                              "type_id"_a = idToString(info.id), "attributes"_a = attributesStr, "name"_a = name,
                              "full_name"_a = info.fullName, "underlying_type"_a = enumInfo.underlyingType, "underlying_value"_a = valueStr,
                              "value"_a = info.fullName));
        }
        if (!valueIdsStr.empty()) { valueIdsStr = valueIdsStr.substr(0, valueIdsStr.length() - 2); }

        const auto const_type_id = idToString(idGenerator->generateId("const " + enumInfo.fullName));
        const auto lref_type_id = idToString(idGenerator->generateId(enumInfo.fullName + "&"));
        const auto const_lref_type_id = idToString(idGenerator->generateId("const " + enumInfo.fullName + "&"));
        const auto rref_type_id = idToString(idGenerator->generateId(enumInfo.fullName + "&&"));
        const auto ptr_type_id = idToString(idGenerator->generateId(enumInfo.fullName + "*"));
        const auto const_ptr_type_id = idToString(idGenerator->generateId("const" + enumInfo.fullName + "*"));

        std::vector<std::string> argsArrayNames;
        std::string detailsContents;
        for (const auto &attr: enumInfo.attributes) {
            const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
            argsArrayNames.push_back(argsArrayName);
            detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
        }
        const auto attributesStr = StringifyAttributes(enumInfo.attributes, argsArrayNames);

        write(fmt::format(StaticTypeInfoTemplate_Enum, "details"_a = detailsContents, "type_id"_a = idToString(enumInfo.id),
                          "type"_a = enumInfo.fullName, "source_file"_a = enumInfo.sourceLocation.filename,
                          "source_line"_a = enumInfo.sourceLocation.line, "source_column"_a = enumInfo.sourceLocation.column,
                          "attributes"_a = attributesStr, "name"_a = enumInfo.name, "full_name"_a = enumInfo.fullName,
                          "underlying_type"_a = enumInfo.underlyingType, "enum_value_ids"_a = valueIdsStr,
                          "const_type_id"_a = const_type_id, "lref_type_id"_a = lref_type_id, "const_lref_type_id"_a = const_lref_type_id,
                          "rref_type_id"_a = rref_type_id, "ptr_type_id"_a = ptr_type_id, "const_ptr_type_id"_a = const_ptr_type_id));

        write(fmt::format(GetTypeIDTemplate, "full_name"_a = enumInfo.fullName, "type"_a = enumInfo.fullName,
                          "type_id"_a = idToString(enumInfo.id), "const_type_id"_a = const_type_id, "lref_type_id"_a = lref_type_id,
                          "const_lref_type_id"_a = const_lref_type_id, "rref_type_id"_a = rref_type_id, "ptr_type_id"_a = ptr_type_id,
                          "const_ptr_type_id"_a = const_ptr_type_id));
        for (const auto &[name, id]: valueIds) {
            write(fmt::format(GetConstantIDTemplate, "full_name"_a = fmt::format("{}::{}", enumInfo.fullName, name), "constant"_a = name,
                              "value_id"_a = id));
        }
    }

    void MetaInfoWriter::writeRecordInfo(const RecordTypeInfo &recordInfo) {
        using namespace fmt::literals;

        const auto idsToStringMakeArray = [](std::ranges::range auto &&range) {
            static_assert(requires(std::ranges::range_value_t<decltype(range)> v) {
                { v.id } -> std::convertible_to<meta::details::ID>;
            });
            std::string result;
            for (const auto &val: range) {
                result.append(idToString(val.id));
                result.append(", ");
            }
            if (!result.empty()) { result = result.substr(0, result.length() - 2); }
            return result;
        };


        const auto const_type_id = idToString(idGenerator->generateId("const " + recordInfo.fullName));
        const auto lref_type_id = idToString(idGenerator->generateId(recordInfo.fullName + "&"));
        const auto const_lref_type_id = idToString(idGenerator->generateId("const " + recordInfo.fullName + "&"));
        const auto rref_type_id = idToString(idGenerator->generateId(recordInfo.fullName + "&&"));
        const auto ptr_type_id = idToString(idGenerator->generateId(recordInfo.fullName + "*"));
        const auto const_ptr_type_id = idToString(idGenerator->generateId("const" + recordInfo.fullName + "*"));
        write(fmt::format(StaticTypeInfoTemplate_Record, "type_id"_a = idToString(recordInfo.id), "full_name"_a = recordInfo.fullName,
                          "details"_a = "", "type"_a = recordInfo.fullName, "source_file"_a = recordInfo.sourceLocation.filename,
                          "source_line"_a = recordInfo.sourceLocation.line, "source_column"_a = recordInfo.sourceLocation.column,
                          "attributes"_a = "",// TODO: attributes
                          "name"_a = recordInfo.name, "full_name"_a = recordInfo.fullName, "is_union"_a = recordInfo.isUnion,
                          "is_poly"_a = recordInfo.isPolymorphic, "is_abstract"_a = recordInfo.isAbstract,
                          "is_final"_a = recordInfo.isFinal, "bases"_a = idsToStringMakeArray(recordInfo.baseClasses),
                          "ctors"_a = idsToStringMakeArray(recordInfo.constructors), "dtor"_a = idToString(recordInfo.destructor.id),
                          "member_fncs"_a = idsToStringMakeArray(recordInfo.memberFunctions),
                          "static_fncs"_a = idsToStringMakeArray(recordInfo.staticFunctions),
                          "member_vars"_a = idsToStringMakeArray(recordInfo.memberVariables),
                          "static_vars"_a = idsToStringMakeArray(recordInfo.staticVariables), "const_type_id"_a = const_type_id,
                          "lref_type_id"_a = lref_type_id, "const_lref_type_id"_a = const_lref_type_id, "rref_type_id"_a = rref_type_id,
                          "ptr_type_id"_a = ptr_type_id, "const_ptr_type_id"_a = const_ptr_type_id));

        write(fmt::format(GetTypeIDTemplate, "full_name"_a = recordInfo.fullName, "type"_a = recordInfo.fullName,
                          "type_id"_a = idToString(recordInfo.id), "const_type_id"_a = const_type_id, "lref_type_id"_a = lref_type_id,
                          "const_lref_type_id"_a = const_lref_type_id, "rref_type_id"_a = rref_type_id, "ptr_type_id"_a = ptr_type_id,
                          "const_ptr_type_id"_a = const_ptr_type_id));

        for (const auto &baseInfo: recordInfo.baseClasses) {
            write(fmt::format(StaticTypeInfoTemplate_Base, "full_name"_a = baseInfo.fullName, "id"_a = idToString(baseInfo.id),
                              "details"_a = "", "type_id"_a = idToString(idGenerator->generateId(baseInfo.fullName)),
                              "source_file"_a = baseInfo.sourceLocation.filename, "source_line"_a = baseInfo.sourceLocation.line,
                              "source_column"_a = baseInfo.sourceLocation.column,
                              "attributes"_a = "",// TODO
                              "is_public"_a = baseInfo.access == Access::Public, "is_protected"_a = baseInfo.access == Access::Protected,
                              "is_private"_a = baseInfo.access == Access::Private, "is_virtual"_a = baseInfo.isVirtual,
                              "name"_a = baseInfo.name));
        }
        for (const auto &ctorInfo: recordInfo.constructors) {
            write(fmt::format(StaticTypeInfoTemplate_Constructor, "full_name"_a = ctorInfo.fullName, "id"_a = idToString(ctorInfo.id),
                              "details"_a = "", "type_id"_a = idToString(recordInfo.id), "source_file"_a = ctorInfo.sourceLocation.filename,
                              "source_line"_a = ctorInfo.sourceLocation.line, "source_column"_a = ctorInfo.sourceLocation.column,
                              "attributes"_a = "",// TODO
                              "is_public"_a = ctorInfo.access == Access::Public, "is_protected"_a = ctorInfo.access == Access::Protected,
                              "is_private"_a = ctorInfo.access == Access::Private, "is_explicit"_a = ctorInfo.isExplicit,
                              "is_copy"_a = ctorInfo.isCopy, "is_move"_a = ctorInfo.isMove, "name"_a = recordInfo.name,
                              "is_constexpr"_a = ctorInfo.isConstexpr, "is_consteval"_a = ctorInfo.isConsteval,
                              "arguments"_a = ""// TODO
                              ));
        }
        write(fmt::format(StaticTypeInfoTemplate_Destructor, "full_name"_a = recordInfo.destructor.fullName,
                          "id"_a = idToString(recordInfo.destructor.id), "details"_a = "", "type_id"_a = idToString(recordInfo.id),
                          "source_file"_a = recordInfo.destructor.sourceLocation.filename,
                          "source_line"_a = recordInfo.destructor.sourceLocation.line,
                          "source_column"_a = recordInfo.destructor.sourceLocation.column,
                          "attributes"_a = "",// TODO
                          "is_public"_a = recordInfo.destructor.access == Access::Public,
                          "is_protected"_a = recordInfo.destructor.access == Access::Protected,
                          "is_private"_a = recordInfo.destructor.access == Access::Private,
                          "is_constexpr"_a = recordInfo.destructor.isConstexpr, "is_consteval"_a = recordInfo.destructor.isConsteval,
                          "is_virtual"_a = recordInfo.destructor.isVirtual, "is_pure_virtual"_a = recordInfo.destructor.isPureVirtual,
                          "name"_a = fmt::format("~{}", recordInfo.name)));

        for (const auto &mbrFncInfo: recordInfo.memberFunctions) {
            write(fmt::format(
                    StaticTypeInfoTemplate_MemberFunction, "full_name"_a = mbrFncInfo.fullName, "id"_a = idToString(mbrFncInfo.id),
                    "details"_a = "", "type_id"_a = idToString(recordInfo.id), "source_file"_a = mbrFncInfo.sourceLocation.filename,
                    "source_line"_a = mbrFncInfo.sourceLocation.line, "source_column"_a = mbrFncInfo.sourceLocation.column,
                    "attributes"_a = "",// TODO
                    "is_public"_a = mbrFncInfo.access == Access::Public, "is_protected"_a = mbrFncInfo.access == Access::Protected,
                    "is_private"_a = mbrFncInfo.access == Access::Private, "name"_a = mbrFncInfo.name,
                    "is_constexpr"_a = mbrFncInfo.isConstexpr, "is_consteval"_a = mbrFncInfo.isConsteval, "is_const"_a = mbrFncInfo.isConst,
                    "is_virtual"_a = mbrFncInfo.isVirtual, "is_pure_virtual"_a = mbrFncInfo.isPureVirtual,
                    "return_type_id"_a = idToString(mbrFncInfo.returnTypeId),
                    "arguments"_a = ""// TODO
                    ));
        }

        for (const auto &mbrVarInfo: recordInfo.memberVariables) {
            write(fmt::format(
                    StaticTypeInfoTemplate_MemberVariable, "full_name"_a = mbrVarInfo.fullName, "id"_a = idToString(mbrVarInfo.id),
                    "details"_a = "", "type_id"_a = idToString(recordInfo.id), "source_file"_a = mbrVarInfo.sourceLocation.filename,
                    "source_line"_a = mbrVarInfo.sourceLocation.line, "source_column"_a = mbrVarInfo.sourceLocation.column,
                    "attributes"_a = "",// TODO
                    "is_public"_a = mbrVarInfo.access == Access::Public, "is_protected"_a = mbrVarInfo.access == Access::Protected,
                    "is_private"_a = mbrVarInfo.access == Access::Private, "name"_a = mbrVarInfo.name,
                    "is_mutable"_a = mbrVarInfo.isMutable));
        }

        for (const auto &statFncInfo: recordInfo.staticFunctions) {
            write(fmt::format(
                    StaticTypeInfoTemplate_StaticFunction, "full_name"_a = statFncInfo.fullName, "id"_a = idToString(statFncInfo.id),
                    "details"_a = "", "type_id"_a = idToString(recordInfo.id), "source_file"_a = statFncInfo.sourceLocation.filename,
                    "source_line"_a = statFncInfo.sourceLocation.line, "source_column"_a = statFncInfo.sourceLocation.column,
                    "attributes"_a = "",// TODO
                    "is_public"_a = statFncInfo.access == Access::Public, "is_protected"_a = statFncInfo.access == Access::Protected,
                    "is_private"_a = statFncInfo.access == Access::Private, "name"_a = statFncInfo.name,
                    "is_constexpr"_a = statFncInfo.isConstexpr, "is_consteval"_a = statFncInfo.isConsteval,
                    "return_type_id"_a = idToString(statFncInfo.returnTypeId),
                    "arguments"_a = ""// TODO
                    ));
        }

        for (const auto &statVarInfo: recordInfo.staticVariables) {
            write(fmt::format(
                    StaticTypeInfoTemplate_StaticVariable, "full_name"_a = statVarInfo.fullName, "id"_a = idToString(statVarInfo.id),
                    "details"_a = "", "type_id"_a = idToString(recordInfo.id), "source_file"_a = statVarInfo.sourceLocation.filename,
                    "source_line"_a = statVarInfo.sourceLocation.line, "source_column"_a = statVarInfo.sourceLocation.column,
                    "attributes"_a = "",// TODO
                    "is_public"_a = statVarInfo.access == Access::Public, "is_protected"_a = statVarInfo.access == Access::Protected,
                    "is_private"_a = statVarInfo.access == Access::Private, "name"_a = statVarInfo.name));
        }
    }

    std::string MetaInfoWriter::StringifyAttributes(const std::vector<Attribute> &attrs, const std::vector<std::string> &argArrayNames) {
        assert(attrs.size() == argArrayNames.size());
        std::string attributesString{};
        for (auto i = 0ull; i < attrs.size(); ++i) {
            const auto &attr = attrs[i];
            const auto &argArrayName = argArrayNames[i];
            attributesString.append(
                    fmt::format(R"(Attribute{{"{}", std::span<const std::string_view>{{details::{}}}}}, )", attr.name, argArrayName));
        }
        if (!attrs.empty()) { return attributesString.substr(0, attributesString.length() - 2); }
        return attributesString;
    }

    std::string MetaInfoWriter::CreateAttributeArgArray(std::string_view name, const Attribute &attr) {
        std::string attributeArgsStr{};
        attributeArgsStr.append(fmt::format("constexpr static auto {} = make_array<std::string_view>(", name));
        for (const auto &arg: attr.arguments) { attributeArgsStr.append(fmt::format(R"fmt(R"arg({})arg")fmt", arg)).append(", "); }
        if (!attr.arguments.empty()) { attributeArgsStr = attributeArgsStr.substr(0, attributeArgsStr.length() - 2); }
        attributeArgsStr.append(");");
        return attributeArgsStr;
    }

}// namespace pf::meta_gen