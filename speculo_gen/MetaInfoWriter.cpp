//
// Created by xflajs00 on 19.03.2023.
//

#include "MetaInfoWriter.hpp"

#include "Visitor.hpp"
#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include "src_templates/GetConstantID.hpp"
#include "src_templates/GetTypeID.hpp"
#include "src_templates/StaticArgumentInfo.hpp"
#include "src_templates/StaticBaseInfo.hpp"
#include "src_templates/StaticConstructorInfo.hpp"
#include "src_templates/StaticDestructorInfo.hpp"
#include "src_templates/StaticMemberFunctionInfo.hpp"
#include "src_templates/StaticMemberVariableInfo.hpp"
#include "src_templates/StaticStaticFunctionInfo.hpp"
#include "src_templates/StaticStaticVariableInfo.hpp"
#include "src_templates/StaticTypeInfo.hpp"
#include "src_templates/StaticValueInfo.hpp"

#include "algorithms/contains.hpp"
#include "idToString.hpp"
#include "optional_utils.hpp"
#include "speculo/details/array.hpp"

namespace speculo::gen {
    [[nodiscard]] std::string createDetailsStruct(std::string_view contents) {
        if (contents.empty()) { return ""; }
        return fmt::format("struct details {{\n{}}};", contents);
    }

    MetaInfoWriter::MetaInfoWriter(std::ostream &os, std::shared_ptr<IdGenerator> idGen) : idGenerator(std::move(idGen)), ostream(os) {}

    void MetaInfoWriter::write(std::string_view str) { ostream << str; }

    void MetaInfoWriter::write(const TypeInfoVariant &typeInfo) {
        std::visit(Visitor{[&](const EnumTypeInfo &enumInfo) { writeEnumInfo(enumInfo); },
                           [&](const RecordTypeInfo &recordInfo) { writeRecordInfo(recordInfo); },
                           [](auto) { spdlog::error("MetaInfoWriter: unimplemented type"); }},
                   typeInfo);
    }

    void MetaInfoWriter::writeEnumInfo(const EnumTypeInfo &enumInfo) {
        if (ContainsNoSTIAttribute(enumInfo.attributes)) {
            spdlog::trace("MetaInfoWrite: skipping generation for '{}' due to presence of no_sti attribute", enumInfo.fullName);
            return;
        }

        if (enumInfo.sourceLocation.has_value()) { writeEnumInfoSourceLocation(enumInfo); }

        using namespace fmt::literals;
        std::unordered_map<std::string, std::string> valueIds{};
        std::string valueIdsStr{};
        for (auto &[name, info]: enumInfo.values) {
            if (ContainsNoSTIAttribute(info.attributes)) {
                spdlog::trace("MetaInfoWrite: skipping generation for '{}' due to presence of no_sti attribute", info.fullName);
                continue;
            }

            assert(enumInfo.underlyingType != nullptr);
            if (!std::holds_alternative<FundamentalTypeInfo>(*enumInfo.underlyingType)) {
                spdlog::debug("Unexpected code path triggered in MetaInfo writer {0:x}", 0x192B9F71);
            }

            const auto valueIdStr = idToString(info.id);
            valueIds.emplace(info.fullName, valueIdStr);
            valueIdsStr.append(valueIdStr);
            valueIdsStr.append(", ");

            const auto valueStr = std::visit([](auto val) { return fmt::format("{}", val); }, info.value);

            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: info.attributes) {
                if (attr.arguments.empty()) {
                    argsArrayNames.emplace_back("EmptyAttributeArgArray");
                } else {
                    const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                    argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                    detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                }
            }
            const auto attributesStr = StringifyAttributes(info.attributes, argsArrayNames);

            write(fmt::format(R"fmt(// Enumerator {}, location {}:{}:{}
)fmt",
                              info.fullName, info.sourceLocation.filename, info.sourceLocation.line, info.sourceLocation.column));

            write(fmt::format(templates::StaticValueInfo_Enum, "details"_a = createDetailsStruct(detailsContents),
                              "type"_a = enumInfo.fullName, "value_id"_a = idToString(info.id),
                              "source_file"_a = projectOr(enumInfo.sourceLocation, &SourceLocationInfo::filename, "<unknown>"),
                              "source_line"_a = info.sourceLocation.line, "source_column"_a = info.sourceLocation.column,
                              "type_id"_a = idToString(info.id), "attributes"_a = attributesStr, "name"_a = name,
                              "full_name"_a = info.fullName,
                              "underlying_type"_a = std::visit([](const auto &t) { return t.fullName; }, *enumInfo.underlyingType),
                              "underlying_value"_a = valueStr, "value"_a = info.fullName));
        }
        if (!valueIdsStr.empty()) { valueIdsStr = valueIdsStr.substr(0, valueIdsStr.length() - 2); }

        std::vector<std::string> argsArrayNames;
        std::string detailsContents;
        for (const auto &attr: enumInfo.attributes) {
            if (attr.arguments.empty()) {
                argsArrayNames.emplace_back("EmptyAttributeArgArray");
            } else {
                const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
            }
        }
        const auto attributesStr = StringifyAttributes(enumInfo.attributes, argsArrayNames);

        write(fmt::format(templates::StaticTypeInfo_Enum, "details"_a = createDetailsStruct(detailsContents),
                          "type_id"_a = idToString(enumInfo.id), "type"_a = enumInfo.fullName,
                          "source_file"_a = projectOr(enumInfo.sourceLocation, &SourceLocationInfo::filename, "<unknown>"),
                          "source_line"_a = projectOr(enumInfo.sourceLocation, &SourceLocationInfo::line, 0),
                          "source_column"_a = projectOr(enumInfo.sourceLocation, &SourceLocationInfo::column, 0),
                          "attributes"_a = attributesStr, "name"_a = enumInfo.name, "full_name"_a = enumInfo.fullName,
                          "underlying_type"_a = std::visit([](const auto &t) { return t.fullName; }, *enumInfo.underlyingType),
                          "enum_value_ids"_a = valueIdsStr, "const_type_id"_a = idToString(enumInfo.constId),
                          "lref_type_id"_a = idToString(enumInfo.lrefId), "const_lref_type_id"_a = idToString(enumInfo.constLrefId),
                          "rref_type_id"_a = idToString(enumInfo.rrefId), "ptr_type_id"_a = idToString(enumInfo.ptrId),
                          "const_ptr_type_id"_a = idToString(enumInfo.constPtrId), "volatile_type_id"_a = idToString(enumInfo.volatileId),
                          "volatile_const_type_id"_a = idToString(enumInfo.volatileConstId),
                          "volatile_lref_type_id"_a = idToString(enumInfo.volatileLrefId),
                          "volatile_rref_type_id"_a = idToString(enumInfo.volatileRrefId),
                          "volatile_const_lref_type_id"_a = idToString(enumInfo.volatileConstLrefId),
                          "volatile_ptr_type_id"_a = idToString(enumInfo.volatilePtrId),
                          "volatile_const_ptr_type_id"_a = idToString(enumInfo.volatileConstPtrId), "size"_a = enumInfo.size,
                          "alignment"_a = enumInfo.alignment, "is_scoped"_a = enumInfo.isScoped));

        write(fmt::format(R"fmt(// Enum {} static info getters
)fmt",
                          enumInfo.fullName));

        write(fmt::format(templates::GetTypeID, "full_name"_a = enumInfo.fullName, "type"_a = enumInfo.fullName,
                          "type_id"_a = idToString(enumInfo.id), "const_type_id"_a = idToString(enumInfo.constId),
                          "lref_type_id"_a = idToString(enumInfo.lrefId), "const_lref_type_id"_a = idToString(enumInfo.constLrefId),
                          "rref_type_id"_a = idToString(enumInfo.rrefId), "ptr_type_id"_a = idToString(enumInfo.ptrId),
                          "const_ptr_type_id"_a = idToString(enumInfo.constPtrId), "volatile_type_id"_a = idToString(enumInfo.volatileId),
                          "volatile_const_type_id"_a = idToString(enumInfo.volatileConstId),
                          "volatile_lref_type_id"_a = idToString(enumInfo.volatileLrefId),
                          "volatile_rref_type_id"_a = idToString(enumInfo.volatileRrefId),
                          "volatile_const_lref_type_id"_a = idToString(enumInfo.volatileConstLrefId),
                          "volatile_ptr_type_id"_a = idToString(enumInfo.volatilePtrId),
                          "volatile_const_ptr_type_id"_a = idToString(enumInfo.volatileConstPtrId)));

        write(fmt::format(R"fmt(// Enumerators of {} static info getters
)fmt",
                          enumInfo.fullName));

        for (const auto &[name, id]: valueIds) {
            write(fmt::format(templates::GetConstantID, "full_name"_a = fmt::format("{}::{}", enumInfo.fullName, name), "constant"_a = name,
                              "value_id"_a = id));
        }

        write(fmt::format(R"fmt(//Enum {} **END**
)fmt",
                          enumInfo.fullName));
    }

    void MetaInfoWriter::writeRecordInfo(const RecordTypeInfo &recordInfo) {
        if (ContainsNoSTIAttribute(recordInfo.attributes)) {
            spdlog::trace("MetaInfoWrite: skipping generation for '{}' due to presence of no_sti attribute", recordInfo.fullName);
            return;
        }
        // skipping private and protected nested types
        if (recordInfo.access.has_value() && *recordInfo.access != Access::Public) { return; }
        using namespace fmt::literals;

        const auto idsToStringMakeArray = [](std::ranges::range auto &&range) {
            static_assert(requires(std::ranges::range_value_t<decltype(range)> v) {
                { v.id } -> std::convertible_to<ID>;
            });
            std::string result;
            for (const auto &val: range) {
                result.append(idToString(val.id));
                result.append(", ");
            }
            if (!result.empty()) { result = result.substr(0, result.length() - 2); }
            return result;
        };

        write(fmt::format(R"fmt(// Record {}, location {}:{}:{} )fmt", recordInfo.fullName,
                          projectOr(recordInfo.sourceLocation, &SourceLocationInfo::filename, "<unknown>"),
                          projectOr(recordInfo.sourceLocation, &SourceLocationInfo::line, 0),
                          projectOr(recordInfo.sourceLocation, &SourceLocationInfo::column, 0)));

        {
            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: recordInfo.attributes) {
                if (attr.arguments.empty()) {
                    argsArrayNames.emplace_back("EmptyAttributeArgArray");
                } else {
                    const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                    argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                    detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                }
            }
            const auto attributesStr = StringifyAttributes(recordInfo.attributes, argsArrayNames);

            write(fmt::format(
                    templates::StaticTypeInfo_Record, "type_id"_a = idToString(recordInfo.id), "full_name"_a = recordInfo.fullName,
                    "details"_a = createDetailsStruct(detailsContents), "type"_a = recordInfo.fullName,
                    "source_file"_a = projectOr(recordInfo.sourceLocation, &SourceLocationInfo::filename, "<unknown>"),
                    "source_line"_a = projectOr(recordInfo.sourceLocation, &SourceLocationInfo::line, 0),
                    "source_column"_a = projectOr(recordInfo.sourceLocation, &SourceLocationInfo::column, 0),
                    "attributes"_a = attributesStr, "name"_a = recordInfo.name, "full_name"_a = recordInfo.fullName,
                    "is_union"_a = recordInfo.isUnion, "is_class"_a = recordInfo.isClass, "is_struct"_a = recordInfo.isStruct,
                    "is_poly"_a = recordInfo.isPolymorphic, "is_abstract"_a = recordInfo.isAbstract, "is_final"_a = recordInfo.isFinal,
                    "bases"_a = idsToStringMakeArray(recordInfo.baseClasses), "ctors"_a = idsToStringMakeArray(recordInfo.constructors),
                    "dtor"_a = idToString(recordInfo.destructor.id), "member_fncs"_a = idsToStringMakeArray(recordInfo.memberFunctions),
                    "static_fncs"_a = idsToStringMakeArray(recordInfo.staticFunctions),
                    "member_vars"_a = idsToStringMakeArray(recordInfo.memberVariables),
                    "static_vars"_a = idsToStringMakeArray(recordInfo.staticVariables), "const_type_id"_a = idToString(recordInfo.constId),
                    "lref_type_id"_a = idToString(recordInfo.lrefId), "const_lref_type_id"_a = idToString(recordInfo.constLrefId),
                    "rref_type_id"_a = idToString(recordInfo.rrefId), "ptr_type_id"_a = idToString(recordInfo.ptrId),
                    "const_ptr_type_id"_a = idToString(recordInfo.constPtrId), "volatile_type_id"_a = idToString(recordInfo.volatileId),
                    "volatile_const_type_id"_a = idToString(recordInfo.volatileConstId),
                    "volatile_lref_type_id"_a = idToString(recordInfo.volatileLrefId),
                    "volatile_rref_type_id"_a = idToString(recordInfo.volatileRrefId),
                    "volatile_const_lref_type_id"_a = idToString(recordInfo.volatileConstLrefId),
                    "volatile_ptr_type_id"_a = idToString(recordInfo.volatilePtrId),
                    "volatile_const_ptr_type_id"_a = idToString(recordInfo.volatileConstPtrId), "size"_a = recordInfo.size,
                    "alignment"_a = recordInfo.alignment, "is_literal"_a = recordInfo.isLiteral, "is_pod"_a = recordInfo.isPOD,
                    "is_standard_layout"_a = recordInfo.isStandardLayout, "is_trivially_copyable"_a = recordInfo.isTriviallyCopyable,
                    "is_trivial"_a = recordInfo.isTrivial, "is_empty"_a = recordInfo.isEmpty, "is_aggregate"_a = recordInfo.isAggregate));


            write(fmt::format(R"fmt(// Record {} static info getters
)fmt",
                              recordInfo.fullName));

            write(fmt::format(templates::GetTypeID, "full_name"_a = recordInfo.fullName, "type"_a = recordInfo.fullName,
                              "type_id"_a = idToString(recordInfo.id), "const_type_id"_a = idToString(recordInfo.constId),
                              "lref_type_id"_a = idToString(recordInfo.lrefId), "const_lref_type_id"_a = idToString(recordInfo.constLrefId),
                              "rref_type_id"_a = idToString(recordInfo.rrefId), "ptr_type_id"_a = idToString(recordInfo.ptrId),
                              "const_ptr_type_id"_a = idToString(recordInfo.constPtrId),
                              "volatile_type_id"_a = idToString(recordInfo.volatileId),
                              "volatile_const_type_id"_a = idToString(recordInfo.volatileConstId),
                              "volatile_lref_type_id"_a = idToString(recordInfo.volatileLrefId),
                              "volatile_rref_type_id"_a = idToString(recordInfo.volatileRrefId),
                              "volatile_const_lref_type_id"_a = idToString(recordInfo.volatileConstLrefId),
                              "volatile_ptr_type_id"_a = idToString(recordInfo.volatilePtrId),
                              "volatile_const_ptr_type_id"_a = idToString(recordInfo.volatileConstPtrId)));
        }

        for (const auto &baseInfo: recordInfo.baseClasses) {
            write(fmt::format(R"fmt(// Record {} base class {}
)fmt",
                              recordInfo.fullName, baseInfo.fullName));

            write(fmt::format(templates::StaticTypeInfo_Base, "full_name"_a = baseInfo.fullName, "id"_a = idToString(baseInfo.id),
                              "details"_a = "", "type_id"_a = idToString(idGenerator->generateId(baseInfo.fullName)),
                              "source_file"_a = baseInfo.sourceLocation.filename, "source_line"_a = baseInfo.sourceLocation.line,
                              "source_column"_a = baseInfo.sourceLocation.column, "is_public"_a = baseInfo.access == Access::Public,
                              "is_protected"_a = baseInfo.access == Access::Protected, "is_private"_a = baseInfo.access == Access::Private,
                              "is_virtual"_a = baseInfo.isVirtual, "name"_a = baseInfo.name, "offset"_a = baseInfo.byteOffset,
                              "size"_a = baseInfo.size));
        }
        for (const auto &ctorInfo: recordInfo.constructors) {
            if (ContainsNoSTIAttribute(ctorInfo.attributes)) {
                spdlog::trace("MetaInfoWrite: skipping generation for '{}' due to presence of no_sti attribute", ctorInfo.fullName);
                continue;
            }
            if (!recordInfo.hasSpeculoGeneratedMacro && ctorInfo.access != Access::Public) { continue; }

            for (const auto &argInfo: ctorInfo.arguments) {
                std::vector<std::string> argsArrayNames;
                std::string detailsContents;
                for (const auto &attr: argInfo.attributes) {
                    if (attr.arguments.empty()) {
                        argsArrayNames.emplace_back("EmptyAttributeArgArray");
                    } else {
                        const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                        argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                        detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                    }
                }
                const auto attributesStr = StringifyAttributes(argInfo.attributes, argsArrayNames);

                write(fmt::format(R"fmt(// Record {} constructor {} argument {}
)fmt",
                                  recordInfo.fullName, ctorInfo.fullName, argInfo.fullName));

                write(fmt::format(templates::StaticTypeInfo_Argument, "full_name"_a = argInfo.fullName, "id"_a = idToString(argInfo.id),
                                  "details"_a = createDetailsStruct(detailsContents),
                                  "type_id"_a = idToString(argInfo.type.getID().value_or(ID::Invalid())),
                                  "source_file"_a = argInfo.sourceLocation.filename, "source_line"_a = argInfo.sourceLocation.line,
                                  "source_column"_a = argInfo.sourceLocation.column, "attributes"_a = attributesStr,
                                  "name"_a = argInfo.name));
            }

            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: ctorInfo.attributes) {
                if (attr.arguments.empty()) {
                    argsArrayNames.emplace_back("EmptyAttributeArgArray");
                } else {
                    const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                    argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                    detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                }
            }
            const auto attributesStr = StringifyAttributes(ctorInfo.attributes, argsArrayNames);

            std::string argsWithNames;
            std::string argsWithForward;
            std::size_t cnt{};
            for (const auto &arg: ctorInfo.arguments) {
                if (contains(speculo::make_array<TypeForm>(TypeForm::LRef, TypeForm::ConstLRef), arg.type.form)) {
                    argsWithNames.append(fmt::format("{} arg_{}, ", arg.type.fullName, cnt));
                    argsWithForward.append(fmt::format("arg_{}, ", cnt, cnt));
                } else if (arg.type.form == TypeForm::RRef) {
                    argsWithNames.append(fmt::format("{} arg_{}, ", arg.type.fullName, cnt));
                    argsWithForward.append(fmt::format("std::move(arg_{}), ", cnt, cnt));
                } else {
                    argsWithNames.append(fmt::format("std::same_as<{}> auto &&arg_{}, ", arg.type.fullName, cnt));
                    argsWithForward.append(fmt::format("std::forward<decltype(arg_{})>(arg_{}), ", cnt, cnt));
                }
                ++cnt;
            }
            if (!argsWithNames.empty()) {
                argsWithNames = argsWithNames.substr(0, argsWithNames.size() - 2);
                argsWithForward = argsWithForward.substr(0, argsWithForward.size() - 2);
            }
            std::string ctorModifier;
            if (ctorInfo.isConstexpr) { ctorModifier = "constexpr"; }
            if (ctorInfo.isConsteval) { ctorModifier = "consteval"; }

            std::string lambdaWraps{};

            const auto skipWraps = recordInfo.isAbstract;

            if (!skipWraps) {
                lambdaWraps
                        .append(fmt::format(
                                R"(constexpr static auto CtorWrap = []({args}) {modifier} -> {type} {{ return {type}({args_fwd}); }};)",
                                "args"_a = argsWithNames, "type"_a = recordInfo.fullName, "args_fwd"_a = argsWithForward,
                                "modifier"_a = ctorModifier))
                        .append("\n\t")
                        .append(fmt::format(
                                R"(constexpr static auto NewCtorWrap = []({args}) {modifier} -> {type}* {{ return new {type}({args_fwd}); }};)",
                                "args"_a = argsWithNames, "type"_a = recordInfo.fullName, "args_fwd"_a = argsWithForward,
                                "modifier"_a = ctorModifier))
                        .append("\n\t");
                std::string memArg = "void *mem";
                if (!argsWithNames.empty()) { memArg.append(", "); }
                lambdaWraps.append(fmt::format(
                        R"(constexpr static auto PlacementNewCtorWrap = []({mem_arg}{args}) -> {type}* {{ return new (mem){type}({args_fwd}); }};)",
                        "mem_arg"_a = memArg, "args"_a = argsWithNames, "type"_a = recordInfo.fullName, "args_fwd"_a = argsWithForward));
            }

            write(fmt::format(R"fmt(// Record {} constructor {}
)fmt",
                              recordInfo.fullName, ctorInfo.fullName));

            write(fmt::format(templates::StaticTypeInfo_Constructor, "full_name"_a = ctorInfo.fullName, "id"_a = idToString(ctorInfo.id),
                              "details"_a = createDetailsStruct(detailsContents), "type_id"_a = idToString(recordInfo.id),
                              "source_file"_a = projectOr(ctorInfo.sourceLocation, &SourceLocationInfo::filename, "<unknown>"),
                              "source_line"_a = projectOr(ctorInfo.sourceLocation, &SourceLocationInfo::line, 0),
                              "source_column"_a = projectOr(ctorInfo.sourceLocation, &SourceLocationInfo::column, 0),
                              "attributes"_a = attributesStr, "is_public"_a = ctorInfo.access == Access::Public,
                              "is_protected"_a = ctorInfo.access == Access::Protected, "is_private"_a = ctorInfo.access == Access::Private,
                              "is_explicit"_a = ctorInfo.isExplicit, "is_copy"_a = ctorInfo.isCopy, "is_move"_a = ctorInfo.isMove,
                              "name"_a = recordInfo.name, "is_constexpr"_a = ctorInfo.isConstexpr, "is_consteval"_a = ctorInfo.isConsteval,
                              "arguments"_a = idsToStringMakeArray(ctorInfo.arguments), "ctor_wraps"_a = lambdaWraps,
                              "is_inline"_a = ctorInfo.isInline, "is_inline_specified"_a = ctorInfo.isInlineSpecified,
                              "is_nothrow"_a = ctorInfo.isNothrow));
        }

        {
            const auto &destructor = recordInfo.destructor;

            if (ContainsNoSTIAttribute(destructor.attributes)) {
                spdlog::trace("MetaInfoWrite: skipping generation for '{}' due to presence of no_sti attribute", destructor.fullName);
            } else if (!recordInfo.hasSpeculoGeneratedMacro && destructor.access != Access::Public) {

                std::vector<std::string> argsArrayNames;
                std::string detailsContents;
                for (const auto &attr: destructor.attributes) {
                    if (attr.arguments.empty()) {
                        argsArrayNames.emplace_back("EmptyAttributeArgArray");
                    } else {
                        const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                        argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                        detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                    }
                }
                const auto attributesStr = StringifyAttributes(destructor.attributes, argsArrayNames);


                std::string dtorModifier;
                if (destructor.isConstexpr) { dtorModifier = "constexpr"; }
                if (destructor.isConsteval) { dtorModifier = "consteval"; }
                std::string wrapLambdaStr =
                        fmt::format(R"([]({full_type} &self) {modifier} -> void {{ self.~{type}(); }})",
                                    "full_type"_a = recordInfo.fullName, "type"_a = recordInfo.name, "modifier"_a = dtorModifier);

                write(fmt::format(R"fmt(// Record {} destructor {}
)fmt",
                                  recordInfo.fullName, destructor.fullName));

                write(fmt::format(
                        templates::StaticTypeInfo_Destructor, "full_name"_a = destructor.fullName, "id"_a = idToString(destructor.id),
                        "details"_a = createDetailsStruct(detailsContents), "type_id"_a = idToString(recordInfo.id),
                        "source_file"_a = projectOr(destructor.sourceLocation, &SourceLocationInfo::filename, "<unknown>"),
                        "source_line"_a = projectOr(destructor.sourceLocation, &SourceLocationInfo::line, 0),
                        "source_column"_a = projectOr(destructor.sourceLocation, &SourceLocationInfo::column, 0),
                        "attributes"_a = attributesStr, "is_public"_a = destructor.access == Access::Public,
                        "is_protected"_a = destructor.access == Access::Protected, "is_private"_a = destructor.access == Access::Private,
                        "is_constexpr"_a = destructor.isConstexpr, "is_consteval"_a = destructor.isConsteval,
                        "is_virtual"_a = destructor.isVirtual, "is_pure_virtual"_a = destructor.isPureVirtual,
                        "is_final"_a = destructor.isFinal, "name"_a = fmt::format("~{}", recordInfo.name),
                        "is_inline"_a = destructor.isInline, "is_inline_specified"_a = destructor.isInlineSpecified,
                        "dtor_wrap_lambda"_a = wrapLambdaStr, "is_nothrow"_a = destructor.isNothrow));
            }
        }

        for (const auto &mbrFncInfo: recordInfo.memberFunctions) {
            if (ContainsNoSTIAttribute(mbrFncInfo.attributes)) {
                spdlog::trace("MetaInfoWrite: skipping generation for '{}' due to presence of no_sti attribute", mbrFncInfo.fullName);
                continue;
            }
            if (!recordInfo.hasSpeculoGeneratedMacro && mbrFncInfo.access != Access::Public) { continue; }

            for (const auto &argInfo: mbrFncInfo.arguments) {
                std::vector<std::string> argsArrayNames;
                std::string detailsContents;
                for (const auto &attr: argInfo.attributes) {
                    if (attr.arguments.empty()) {
                        argsArrayNames.emplace_back("EmptyAttributeArgArray");
                    } else {
                        const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                        argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                        detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                    }
                }
                const auto attributesStr = StringifyAttributes(argInfo.attributes, argsArrayNames);

                write(fmt::format(R"fmt(// Record {} member function {} argument {}
)fmt",
                                  recordInfo.fullName, mbrFncInfo.fullName, argInfo.fullName));

                write(fmt::format(templates::StaticTypeInfo_Argument, "full_name"_a = argInfo.fullName, "id"_a = idToString(argInfo.id),
                                  "details"_a = createDetailsStruct(detailsContents),
                                  "type_id"_a = idToString(argInfo.type.getID().value_or(ID::Invalid())),
                                  "source_file"_a = argInfo.sourceLocation.filename, "source_line"_a = argInfo.sourceLocation.line,
                                  "source_column"_a = argInfo.sourceLocation.column, "attributes"_a = attributesStr,
                                  "name"_a = argInfo.name));
            }

            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: mbrFncInfo.attributes) {
                if (attr.arguments.empty()) {
                    argsArrayNames.emplace_back("EmptyAttributeArgArray");
                } else {
                    const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                    argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                    detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                }
            }
            const auto attributesStr = StringifyAttributes(mbrFncInfo.attributes, argsArrayNames);

            std::string arguments;
            for (const auto &a: mbrFncInfo.arguments) { arguments.append(fmt::format("{}, ", a.type.fullName)); }
            if (!arguments.empty()) { arguments = arguments.substr(0, arguments.size() - 2); }

            write(fmt::format(R"fmt(// Record {} member function {}
)fmt",
                              recordInfo.fullName, mbrFncInfo.fullName));

            if (mbrFncInfo.isConsteval) {
                // TODO: deduplicate
                std::string argsWithNames;
                std::string argNames;
                std::size_t cnt{};
                for (const auto &arg: mbrFncInfo.arguments) {
                    argNames.append(fmt::format("arg_{}, ", cnt));
                    argsWithNames.append(fmt::format("{} arg_{}, ", arg.type.fullName, cnt));
                    ++cnt;
                }
                if (!argsWithNames.empty()) {
                    argsWithNames = argsWithNames.substr(0, argsWithNames.size() - 2);
                    argNames = argNames.substr(0, argNames.size() - 2);
                }

                std::string constevalWrapStr;
                if (argsWithNames.empty()) {
                    constevalWrapStr = fmt::format(
                            R"([]({this_type} *self) {modifier} -> {result_type} {{ {return} self->{fnc}(); }})",
                            "this_type"_a = mbrFncInfo.isConst ? fmt::format("const {}", recordInfo.fullName) : recordInfo.fullName,
                            "modifier"_a = "consteval", "result_type"_a = mbrFncInfo.returnType.fullName, "fnc"_a = mbrFncInfo.name,
                            "return"_a = mbrFncInfo.returnType.fullName == "void" ? "" : "return");
                } else {
                    constevalWrapStr = fmt::format(
                            R"([]({this_type} *self, {args}) {modifier} -> {result_type} {{ {return} self->{fnc}({arg_names}); }})",
                            "this_type"_a = mbrFncInfo.isConst ? fmt::format("const {}", recordInfo.fullName) : recordInfo.fullName,
                            "args"_a = argsWithNames, "arg_names"_a = argNames, "modifier"_a = "consteval",
                            "result_type"_a = mbrFncInfo.returnType.fullName, "fnc"_a = mbrFncInfo.name,
                            "return"_a = mbrFncInfo.returnType.fullName == "void" ? "" : "return");
                }
                write(fmt::format(templates::StaticTypeInfo_ConstevalMemberFunction, "full_name"_a = mbrFncInfo.fullName,
                                  "id"_a = idToString(mbrFncInfo.id), "details"_a = createDetailsStruct(detailsContents),
                                  "type_id"_a = idToString(recordInfo.id), "source_file"_a = mbrFncInfo.sourceLocation.filename,
                                  "source_line"_a = mbrFncInfo.sourceLocation.line, "source_column"_a = mbrFncInfo.sourceLocation.column,
                                  "attributes"_a = attributesStr, "is_public"_a = mbrFncInfo.access == Access::Public,
                                  "is_protected"_a = mbrFncInfo.access == Access::Protected,
                                  "is_private"_a = mbrFncInfo.access == Access::Private, "name"_a = mbrFncInfo.name,
                                  "is_constexpr"_a = mbrFncInfo.isConstexpr, "is_consteval"_a = mbrFncInfo.isConsteval,
                                  "is_const"_a = mbrFncInfo.isConst, "is_virtual"_a = mbrFncInfo.isVirtual,
                                  "is_pure_virtual"_a = mbrFncInfo.isPureVirtual, "is_final"_a = mbrFncInfo.isFinal,
                                  "return_type_id"_a = idToString(mbrFncInfo.returnType.getID().value_or(ID::Invalid())),
                                  "arguments"_a = idsToStringMakeArray(mbrFncInfo.arguments), "consteval_wrap"_a = constevalWrapStr,
                                  "member"_a = mbrFncInfo.fullName, "is_inline_specified"_a = mbrFncInfo.isInlineSpecified,
                                  "is_nothrow"_a = mbrFncInfo.isNothrow));
            } else {
                const auto mbrFncType =
                        fmt::format("{return_type}({type}::*MemberPtr)({arguments})", "return_type"_a = mbrFncInfo.returnType.fullName,
                                    "type"_a = recordInfo.fullName, "arguments"_a = arguments);
                write(fmt::format(templates::StaticTypeInfo_MemberFunction, "full_name"_a = mbrFncInfo.fullName,
                                  "id"_a = idToString(mbrFncInfo.id), "details"_a = createDetailsStruct(detailsContents),
                                  "type_id"_a = idToString(recordInfo.id), "source_file"_a = mbrFncInfo.sourceLocation.filename,
                                  "source_line"_a = mbrFncInfo.sourceLocation.line, "source_column"_a = mbrFncInfo.sourceLocation.column,
                                  "attributes"_a = attributesStr, "is_public"_a = mbrFncInfo.access == Access::Public,
                                  "is_protected"_a = mbrFncInfo.access == Access::Protected,
                                  "is_private"_a = mbrFncInfo.access == Access::Private, "name"_a = mbrFncInfo.name,
                                  "is_constexpr"_a = mbrFncInfo.isConstexpr, "is_consteval"_a = mbrFncInfo.isConsteval,
                                  "is_const"_a = mbrFncInfo.isConst, "is_virtual"_a = mbrFncInfo.isVirtual,
                                  "is_pure_virtual"_a = mbrFncInfo.isPureVirtual, "is_final"_a = mbrFncInfo.isFinal,
                                  "return_type_id"_a = idToString(mbrFncInfo.returnType.getID().value_or(ID::Invalid())),
                                  "arguments"_a = idsToStringMakeArray(mbrFncInfo.arguments), "member_type"_a = mbrFncType,
                                  "member"_a = mbrFncInfo.fullName, "is_inline"_a = mbrFncInfo.isInline,
                                  "is_inline_specified"_a = mbrFncInfo.isInlineSpecified,
                                  "const_qualifier"_a = (mbrFncInfo.isConst ? "const" : ""), "is_nothrow"_a = mbrFncInfo.isNothrow));
            }
        }

        for (const auto &mbrVarInfo: recordInfo.memberVariables) {
            if (ContainsNoSTIAttribute(mbrVarInfo.attributes)) {
                spdlog::trace("MetaInfoWrite: skipping generation for '{}' due to presence of no_sti attribute", mbrVarInfo.fullName);
                continue;
            }
            if (!recordInfo.hasSpeculoGeneratedMacro && mbrVarInfo.access != Access::Public) { continue; }

            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: mbrVarInfo.attributes) {
                if (attr.arguments.empty()) {
                    argsArrayNames.emplace_back("EmptyAttributeArgArray");
                } else {
                    const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                    argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                    detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                }
            }
            const auto attributesStr = StringifyAttributes(mbrVarInfo.attributes, argsArrayNames);

            const auto isReference = mbrVarInfo.type.form == TypeForm::ConstLRef || mbrVarInfo.type.form == TypeForm::LRef ||
                                     mbrVarInfo.type.form == TypeForm::RRef;
            if (isReference) { spdlog::debug("{} is a reference member and a pointer to it can not be stored", mbrVarInfo.fullName); }

            const auto mbrVarType = fmt::format("{return_type} {type}::* MemberPtr", "return_type"_a = mbrVarInfo.type.fullName,
                                                "type"_a = recordInfo.fullName);

            std::string bitfieldBlock{};
            std::string memberPtrBlock{};
            if (!isReference) {
                if (mbrVarInfo.isBitfield) {
                    bitfieldBlock = fmt::format(
                            "constexpr static std::size_t BitfieldSize = {};\nconstexpr static std::size_t BitfieldOffset = {};\n",
                            mbrVarInfo.bitfieldSize, mbrVarInfo.bitfieldOffset);
                    bitfieldBlock.append(fmt::format(templates::StaticTypeInfo_BitfieldAccessor, "parent_type"_a = recordInfo.fullName,
                                                     "bitfield_name"_a = mbrVarInfo.name));
                } else {
                    memberPtrBlock = fmt::format("constexpr static {member_type} = &{member};", "member_type"_a = mbrVarType,
                                                 "member"_a = mbrVarInfo.fullName);
                }
            }

            write(fmt::format(R"fmt(// Record {} member variable {}
)fmt",
                              recordInfo.fullName, mbrVarInfo.fullName));


            write(fmt::format(
                    templates::StaticTypeInfo_MemberVariable, "full_name"_a = mbrVarInfo.fullName, "id"_a = idToString(mbrVarInfo.id),
                    "details"_a = createDetailsStruct(detailsContents), "type_id"_a = idToString(recordInfo.id),
                    "source_file"_a = mbrVarInfo.sourceLocation.filename, "source_line"_a = mbrVarInfo.sourceLocation.line,
                    "source_column"_a = mbrVarInfo.sourceLocation.column, "attributes"_a = attributesStr,
                    "is_public"_a = mbrVarInfo.access == Access::Public, "is_protected"_a = mbrVarInfo.access == Access::Protected,
                    "is_private"_a = mbrVarInfo.access == Access::Private, "name"_a = mbrVarInfo.name,
                    "is_mutable"_a = mbrVarInfo.isMutable, "member_ptr_block"_a = memberPtrBlock, "is_bitfield"_a = mbrVarInfo.isBitfield,
                    "bitfield_block"_a = bitfieldBlock, "offset"_a = mbrVarInfo.byteOffset, "size"_a = mbrVarInfo.size));
        }

        for (const auto &statFncInfo: recordInfo.staticFunctions) {
            if (ContainsNoSTIAttribute(statFncInfo.attributes)) {
                spdlog::trace("MetaInfoWrite: skipping generation for '{}' due to presence of no_sti attribute", statFncInfo.fullName);
                continue;
            }
            if (!recordInfo.hasSpeculoGeneratedMacro && statFncInfo.access != Access::Public) { continue; }

            for (const auto &argInfo: statFncInfo.arguments) {
                std::vector<std::string> argsArrayNames;
                std::string detailsContents;
                for (const auto &attr: argInfo.attributes) {
                    if (attr.arguments.empty()) {
                        argsArrayNames.emplace_back("EmptyAttributeArgArray");
                    } else {
                        const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                        argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                        detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                    }
                }
                const auto attributesStr = StringifyAttributes(argInfo.attributes, argsArrayNames);

                write(fmt::format(R"fmt(// Record {} static function {} argument {}
)fmt",
                                  recordInfo.fullName, statFncInfo.fullName, argInfo.fullName));

                write(fmt::format(templates::StaticTypeInfo_Argument, "full_name"_a = argInfo.fullName, "id"_a = idToString(argInfo.id),
                                  "details"_a = createDetailsStruct(detailsContents),
                                  "type_id"_a = idToString(argInfo.type.getID().value_or(ID::Invalid())),
                                  "source_file"_a = argInfo.sourceLocation.filename, "source_line"_a = argInfo.sourceLocation.line,
                                  "source_column"_a = argInfo.sourceLocation.column, "attributes"_a = attributesStr,
                                  "name"_a = argInfo.name));
            }

            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: statFncInfo.attributes) {
                if (attr.arguments.empty()) {
                    argsArrayNames.emplace_back("EmptyAttributeArgArray");
                } else {
                    const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                    argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                    detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                }
            }
            const auto attributesStr = StringifyAttributes(statFncInfo.attributes, argsArrayNames);
            std::string arguments;
            for (const auto &a: statFncInfo.arguments) { arguments.append(fmt::format("{}, ", a.type.fullName)); }
            if (!arguments.empty()) { arguments = arguments.substr(0, arguments.size() - 2); }
            const auto statFncType = fmt::format("{return_type}(*MemberPtr)({arguments})",
                                                 "return_type"_a = statFncInfo.returnType.fullName, "arguments"_a = arguments);

            write(fmt::format(R"fmt(// Record {} static function {}
)fmt",
                              recordInfo.fullName, statFncInfo.fullName));

            if (statFncInfo.isConsteval) {
                // TODO: deduplicate
                std::string argsWithNames;
                std::string argNames;
                std::size_t cnt{};
                for (const auto &arg: statFncInfo.arguments) {
                    argNames.append(fmt::format("arg_{}, ", cnt));
                    argsWithNames.append(fmt::format("{} arg_{}, ", arg.type.fullName, cnt));
                    ++cnt;
                }
                if (!argsWithNames.empty()) {
                    argsWithNames = argsWithNames.substr(0, argsWithNames.size() - 2);
                    argNames = argNames.substr(0, argNames.size() - 2);
                }

                const std::string constevalWrapStr =
                        fmt::format(R"([]({args}) {modifier} -> {result_type} {{ {return} self->{fnc}({arg_names}); }})",
                                    "args"_a = argsWithNames, "arg_names"_a = argNames, "type"_a = recordInfo.fullName,
                                    "modifier"_a = "consteval", "result_type"_a = statFncInfo.returnType.fullName,
                                    "fnc"_a = statFncInfo.name, "return"_a = statFncInfo.returnType.fullName == "void" ? "" : "return");


                write(fmt::format(templates::StaticTypeInfo_ConstevalStaticFunction, "full_name"_a = statFncInfo.fullName,
                                  "id"_a = idToString(statFncInfo.id), "details"_a = createDetailsStruct(detailsContents),
                                  "type_id"_a = idToString(recordInfo.id), "source_file"_a = statFncInfo.sourceLocation.filename,
                                  "source_line"_a = statFncInfo.sourceLocation.line, "source_column"_a = statFncInfo.sourceLocation.column,
                                  "attributes"_a = attributesStr, "is_public"_a = statFncInfo.access == Access::Public,
                                  "is_protected"_a = statFncInfo.access == Access::Protected,
                                  "is_private"_a = statFncInfo.access == Access::Private, "name"_a = statFncInfo.name,
                                  "is_constexpr"_a = statFncInfo.isConstexpr, "is_consteval"_a = statFncInfo.isConsteval,
                                  "return_type_id"_a = idToString(statFncInfo.returnType.getID().value_or(ID::Invalid())),
                                  "arguments"_a = idsToStringMakeArray(statFncInfo.arguments), "member_type"_a = statFncType,
                                  "member"_a = statFncInfo.fullName, "consteval_wrap"_a = constevalWrapStr,
                                  "is_inline_specified"_a = statFncInfo.isInlineSpecified, "is_nothrow"_a = statFncInfo.isNothrow));
            } else {
                write(fmt::format(templates::StaticTypeInfo_StaticFunction, "full_name"_a = statFncInfo.fullName,
                                  "id"_a = idToString(statFncInfo.id), "details"_a = createDetailsStruct(detailsContents),
                                  "type_id"_a = idToString(recordInfo.id), "source_file"_a = statFncInfo.sourceLocation.filename,
                                  "source_line"_a = statFncInfo.sourceLocation.line, "source_column"_a = statFncInfo.sourceLocation.column,
                                  "attributes"_a = attributesStr, "is_public"_a = statFncInfo.access == Access::Public,
                                  "is_protected"_a = statFncInfo.access == Access::Protected,
                                  "is_private"_a = statFncInfo.access == Access::Private, "name"_a = statFncInfo.name,
                                  "is_constexpr"_a = statFncInfo.isConstexpr, "is_consteval"_a = statFncInfo.isConsteval,
                                  "return_type_id"_a = idToString(statFncInfo.returnType.getID().value_or(ID::Invalid())),
                                  "arguments"_a = idsToStringMakeArray(statFncInfo.arguments), "member_type"_a = statFncType,
                                  "member"_a = statFncInfo.fullName, "is_inline"_a = statFncInfo.isInline,
                                  "is_inline_specified"_a = statFncInfo.isInlineSpecified, "is_nothrow"_a = statFncInfo.isNothrow));
            }
        }

        for (const auto &statVarInfo: recordInfo.staticVariables) {
            if (ContainsNoSTIAttribute(statVarInfo.attributes)) {
                spdlog::trace("MetaInfoWrite: skipping generation for '{}' due to presence of no_sti attribute", statVarInfo.fullName);
                continue;
            }
            if (!recordInfo.hasSpeculoGeneratedMacro && statVarInfo.access != Access::Public) { continue; }

            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: statVarInfo.attributes) {
                if (attr.arguments.empty()) {
                    argsArrayNames.emplace_back("EmptyAttributeArgArray");
                } else {
                    const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                    argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                    detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                }
            }
            const auto attributesStr = StringifyAttributes(statVarInfo.attributes, argsArrayNames);
            const auto statVarType = fmt::format("{type}* MemberPtr", "type"_a = statVarInfo.type.fullName);

            write(fmt::format(R"fmt(// Record {} static variable {}
)fmt",
                              recordInfo.fullName, statVarInfo.fullName));

            write(fmt::format(templates::StaticTypeInfo_StaticVariable, "full_name"_a = statVarInfo.fullName,
                              "id"_a = idToString(statVarInfo.id), "details"_a = createDetailsStruct(detailsContents),
                              "type_id"_a = idToString(recordInfo.id), "source_file"_a = statVarInfo.sourceLocation.filename,
                              "source_line"_a = statVarInfo.sourceLocation.line, "source_column"_a = statVarInfo.sourceLocation.column,
                              "attributes"_a = attributesStr, "is_public"_a = statVarInfo.access == Access::Public,
                              "is_protected"_a = statVarInfo.access == Access::Protected, "is_constexpr"_a = statVarInfo.isConstexpr,
                              "is_private"_a = statVarInfo.access == Access::Private, "name"_a = statVarInfo.name,
                              "member_type"_a = statVarType, "member"_a = statVarInfo.fullName, "is_inline"_a = statVarInfo.isInline,
                              "is_inline_specified"_a = statVarInfo.isInlineSpecified));
        }

        write(fmt::format(R"fmt(// Record {} **END**)fmt", recordInfo.fullName));
    }

    std::string MetaInfoWriter::StringifyAttributes(const std::vector<Attribute> &attrs, const std::vector<std::string> &argArrayNames) {
        assert(attrs.size() == argArrayNames.size());
        std::string attributesString{};
        for (auto i = 0ull; i < attrs.size(); ++i) {
            const auto &attr = attrs[i];
            const auto &argArrayName = argArrayNames[i];
            attributesString.append(fmt::format(R"(Attribute{{"{}", "{}", std::span<const std::string_view>{{{}}}}}, )", attr.nnamespace,
                                                attr.name, argArrayName));
        }
        if (!attrs.empty()) { return attributesString.substr(0, attributesString.length() - 2); }
        return attributesString;
    }

    std::string MetaInfoWriter::CreateAttributeArgArray(std::string_view name, const Attribute &attr) {
        std::string attributeArgsStr{};
        attributeArgsStr.append(fmt::format("constexpr static auto {} = speculo::make_array<std::string_view>(", name));
        for (const auto &arg: attr.arguments) { attributeArgsStr.append(fmt::format(R"fmt(R"arg({})arg")fmt", arg)).append(", "); }
        if (!attr.arguments.empty()) { attributeArgsStr = attributeArgsStr.substr(0, attributeArgsStr.length() - 2); }
        attributeArgsStr.append(");");
        return attributeArgsStr;
    }

    void MetaInfoWriter::writeEnumInfoSourceLocation(const EnumTypeInfo &enumInfo) {
        write(fmt::format("// Enum {}, location {}:{}:{} with {} enumerators\n", enumInfo.fullName,
                          projectOr(enumInfo.sourceLocation, &SourceLocationInfo::filename, "<unknown>"),
                          projectOr(enumInfo.sourceLocation, &SourceLocationInfo::line, 0),
                          projectOr(enumInfo.sourceLocation, &SourceLocationInfo::column, 0), enumInfo.values.size()));
    }

}// namespace speculo::gen