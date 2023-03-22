//
// Created by xflajs00 on 19.03.2023.
//

#include "MetaInfoWriter.h"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include "src_templates/GetConstantID_template.h"
#include "src_templates/GetTypeID_template.h"
#include "src_templates/StaticTypeInfo_template.h"
#include "src_templates/StaticValueInfo_template.h"
#include <pf_common/Visitor.h>

namespace pf::meta_gen {
    [[nodiscard]] std::string idToString(pf::meta::details::ID id) {
        return fmt::format("ID{{0x{:x}u, 0x{:x}u}}", id.id[0], id.id[1]);
    }

    MetaInfoWriter::MetaInfoWriter(std::shared_ptr<llvm::raw_ostream> os, std::shared_ptr<IdGenerator> idGen)
            : idGenerator(std::move(idGen)), ostream(std::move(os)) {}

    void MetaInfoWriter::write(std::string_view str) { *ostream << str; }

    void MetaInfoWriter::write(const TypeInfoVariant &typeInfo) {
        std::visit(Visitor{
                           [&](const EnumTypeInfo &enumInfo) { writeEnumInfo(enumInfo); },
                           [&](const RecordTypeInfo recordInfo) { writeRecordInfo(recordInfo); },
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
                              "source_line"_a = info.sourceLocation.line,
                              "source_column"_a = info.sourceLocation.column,
                              "type_id"_a = idToString(info.id), "attributes"_a = attributesStr, "name"_a = name,
                              "full_name"_a = info.fullName, "underlying_type"_a = enumInfo.underlyingType,
                              "underlying_value"_a = valueStr,
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

        write(fmt::format(StaticTypeInfoTemplate_Enum, "details"_a = detailsContents,
                          "type_id"_a = idToString(enumInfo.id),
                          "type"_a = enumInfo.fullName, "source_file"_a = enumInfo.sourceLocation.filename,
                          "source_line"_a = enumInfo.sourceLocation.line,
                          "source_column"_a = enumInfo.sourceLocation.column,
                          "attributes"_a = attributesStr, "name"_a = enumInfo.name, "full_name"_a = enumInfo.fullName,
                          "underlying_type"_a = enumInfo.underlyingType, "enum_value_ids"_a = valueIdsStr,
                          "const_type_id"_a = const_type_id, "lref_type_id"_a = lref_type_id,
                          "const_lref_type_id"_a = const_lref_type_id,
                          "rref_type_id"_a = rref_type_id, "ptr_type_id"_a = ptr_type_id,
                          "const_ptr_type_id"_a = const_ptr_type_id));

        write(fmt::format(GetTypeIDTemplate, "full_name"_a = enumInfo.fullName, "type"_a = enumInfo.fullName,
                          "type_id"_a = idToString(enumInfo.id), "const_type_id"_a = const_type_id,
                          "lref_type_id"_a = lref_type_id,
                          "const_lref_type_id"_a = const_lref_type_id, "rref_type_id"_a = rref_type_id,
                          "ptr_type_id"_a = ptr_type_id,
                          "const_ptr_type_id"_a = const_ptr_type_id));
        for (const auto &[name, id]: valueIds) {
            write(fmt::format(GetConstantIDTemplate, "full_name"_a = fmt::format("{}::{}", enumInfo.fullName, name),
                              "constant"_a = name,
                              "value_id"_a = id));
        }
    }

    void MetaInfoWriter::writeRecordInfo(const RecordTypeInfo &recordInfo) {
        write(recordInfo.fullName);
        write("\n base classes:\n");
        for (const auto &b : recordInfo.baseClasses) {
            write(b.fullName);
            write("\n");
        }
        write("constructors:\n");
        for (const auto &b : recordInfo.constructors) {
            write(b.fullName);
            write("\n");
        }
        write("memberFunctions:\n");
        for (const auto &b : recordInfo.memberFunctions) {
            write(b.fullName);
            write("\n");
        }
        write("memberVariables:\n");
        for (const auto &b : recordInfo.memberVariables) {
            write(b.fullName);
            write("\n");
        }
        write("staticFunctions:\n");
        for (const auto &b : recordInfo.staticFunctions) {
            write(b.fullName);
            write("\n");
        }
        write("staticVariables:\n");
        for (const auto &b : recordInfo.staticVariables) {
            write(b.fullName);
            write("\n");
        }
        write("// _________________________");
    }

    std::string MetaInfoWriter::StringifyAttributes(const std::vector<Attribute> &attrs,
                                                    const std::vector<std::string> &argArrayNames) {
        assert(attrs.size() == argArrayNames.size());
        std::string attributesString{};
        for (auto i = 0ull; i < attrs.size(); ++i) {
            const auto &attr = attrs[i];
            const auto &argArrayName = argArrayNames[i];
            attributesString.append(
                    fmt::format(R"(Attribute{{"{}", std::span<const std::string_view>{{details::{}}}}}, )", attr.name,
                                argArrayName));
        }
        if (!attrs.empty()) { return attributesString.substr(0, attributesString.length() - 2); }
        return attributesString;
    }

    std::string MetaInfoWriter::CreateAttributeArgArray(std::string_view name, const Attribute &attr) {
        std::string attributeArgsStr{};
        attributeArgsStr.append(fmt::format("constexpr static auto {} = make_array<std::string_view>(", name));
        for (const auto &arg: attr.arguments) {
            attributeArgsStr.append(fmt::format(R"fmt(R"arg({})arg")fmt", arg)).append(", ");
        }
        if (!attr.arguments.empty()) { attributeArgsStr = attributeArgsStr.substr(0, attributeArgsStr.length() - 2); }
        attributeArgsStr.append(");");
        return attributeArgsStr;
    }

}// namespace pf::meta_gen