//
// Created by xflajs00 on 19.03.2023.
//

#include "MetaInfoWriter.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include "src_templates/GetConstantID_template.hpp"
#include "src_templates/GetTypeID_template.hpp"
#include "src_templates/StaticArgumentInfo_template.hpp"
#include "src_templates/StaticBaseInfo_template.hpp"
#include "src_templates/StaticConstructorInfo_template.hpp"
#include "src_templates/StaticDestructorInfo_template.hpp"
#include "src_templates/StaticMemberFunctionInfo_template.hpp"
#include "src_templates/StaticMemberVariableInfo_template.hpp"
#include "src_templates/StaticStaticFunctionInfo_template.hpp"
#include "src_templates/StaticStaticVariableInfo_template.hpp"
#include "src_templates/StaticTypeInfo_template.hpp"
#include "src_templates/StaticValueInfo_template.hpp"
#include <pf_common/Visitor.h>

namespace pf::meta_gen {
    [[nodiscard]] std::string idToString(pf::meta::details::ID id) { return fmt::format("ID{{0x{:x}u, 0x{:x}u}}", id.id[0], id.id[1]); }

    [[nodiscard]] std::string createDetailsStruct(std::string_view contents) {
        if (contents.empty()) { return ""; }
        return fmt::format("struct details {{\n{}}};", contents);
    }

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
        if (std::ranges::any_of(enumInfo.attributes, [](const auto &attribute) {
                // skipping STI generation if requested by the user
                return attribute.nnamespace == "pf" && attribute.name == "no_sti";
            })) {
            return;
        }
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
                if (attr.arguments.empty()) {
                    argsArrayNames.push_back("EmptyAttributeArgArray");
                } else {
                    const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                    argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                    detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                }
            }
            const auto attributesStr = StringifyAttributes(info.attributes, argsArrayNames);

            write(fmt::format(StaticValueInfoTemplate_Enum, "details"_a = createDetailsStruct(detailsContents),
                              "type"_a = enumInfo.fullName, "value_id"_a = idToString(info.id),
                              "source_file"_a = enumInfo.sourceLocation.filename, "source_line"_a = info.sourceLocation.line,
                              "source_column"_a = info.sourceLocation.column, "type_id"_a = idToString(info.id),
                              "attributes"_a = attributesStr, "name"_a = name, "full_name"_a = info.fullName,
                              "underlying_type"_a = enumInfo.underlyingType, "underlying_value"_a = valueStr, "value"_a = info.fullName));
        }
        if (!valueIdsStr.empty()) { valueIdsStr = valueIdsStr.substr(0, valueIdsStr.length() - 2); }

        std::vector<std::string> argsArrayNames;
        std::string detailsContents;
        for (const auto &attr: enumInfo.attributes) {
            if (attr.arguments.empty()) {
                argsArrayNames.push_back("EmptyAttributeArgArray");
            } else {
                const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
            }
        }
        const auto attributesStr = StringifyAttributes(enumInfo.attributes, argsArrayNames);

        write(fmt::format(StaticTypeInfoTemplate_Enum, "details"_a = createDetailsStruct(detailsContents),
                          "type_id"_a = idToString(enumInfo.id), "type"_a = enumInfo.fullName,
                          "source_file"_a = enumInfo.sourceLocation.filename, "source_line"_a = enumInfo.sourceLocation.line,
                          "source_column"_a = enumInfo.sourceLocation.column, "attributes"_a = attributesStr, "name"_a = enumInfo.name,
                          "full_name"_a = enumInfo.fullName, "underlying_type"_a = enumInfo.underlyingType,
                          "enum_value_ids"_a = valueIdsStr, "const_type_id"_a = idToString(enumInfo.constId),
                          "lref_type_id"_a = idToString(enumInfo.lrefId), "const_lref_type_id"_a = idToString(enumInfo.constLrefId),
                          "rref_type_id"_a = idToString(enumInfo.rrefId), "ptr_type_id"_a = idToString(enumInfo.ptrId),
                          "const_ptr_type_id"_a = idToString(enumInfo.constPtrId)));

        write(fmt::format(GetTypeIDTemplate, "full_name"_a = enumInfo.fullName, "type"_a = enumInfo.fullName,
                          "type_id"_a = idToString(enumInfo.id), "const_type_id"_a = idToString(enumInfo.constId),
                          "lref_type_id"_a = idToString(enumInfo.lrefId), "const_lref_type_id"_a = idToString(enumInfo.constLrefId),
                          "rref_type_id"_a = idToString(enumInfo.rrefId), "ptr_type_id"_a = idToString(enumInfo.ptrId),
                          "const_ptr_type_id"_a = idToString(enumInfo.constPtrId)));
        for (const auto &[name, id]: valueIds) {
            write(fmt::format(GetConstantIDTemplate, "full_name"_a = fmt::format("{}::{}", enumInfo.fullName, name), "constant"_a = name,
                              "value_id"_a = id));
        }
    }

    void MetaInfoWriter::writeRecordInfo(const RecordTypeInfo &recordInfo) {
        if (std::ranges::any_of(recordInfo.attributes, [](const auto &attribute) {
                // skipping STI generation if requested by the user
                return attribute.nnamespace == "pf" && attribute.name == "no_sti";
            })) {
            return;
        }
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

        {
            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: recordInfo.attributes) {
                if (attr.arguments.empty()) {
                    argsArrayNames.push_back("EmptyAttributeArgArray");
                } else {
                    const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                    argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                    detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                }
            }
            const auto attributesStr = StringifyAttributes(recordInfo.attributes, argsArrayNames);

            write(fmt::format(StaticTypeInfoTemplate_Record, "type_id"_a = idToString(recordInfo.id), "full_name"_a = recordInfo.fullName,
                              "details"_a = createDetailsStruct(detailsContents), "type"_a = recordInfo.fullName,
                              "source_file"_a = recordInfo.sourceLocation.filename, "source_line"_a = recordInfo.sourceLocation.line,
                              "source_column"_a = recordInfo.sourceLocation.column, "attributes"_a = attributesStr,
                              "name"_a = recordInfo.name, "full_name"_a = recordInfo.fullName, "is_union"_a = recordInfo.isUnion,
                              "is_class"_a = recordInfo.isClass, "is_struct"_a = recordInfo.isStruct,
                              "is_poly"_a = recordInfo.isPolymorphic, "is_abstract"_a = recordInfo.isAbstract,
                              "is_final"_a = recordInfo.isFinal, "bases"_a = idsToStringMakeArray(recordInfo.baseClasses),
                              "ctors"_a = idsToStringMakeArray(recordInfo.constructors), "dtor"_a = idToString(recordInfo.destructor.id),
                              "member_fncs"_a = idsToStringMakeArray(recordInfo.memberFunctions),
                              "static_fncs"_a = idsToStringMakeArray(recordInfo.staticFunctions),
                              "member_vars"_a = idsToStringMakeArray(recordInfo.memberVariables),
                              "static_vars"_a = idsToStringMakeArray(recordInfo.staticVariables),
                              "const_type_id"_a = idToString(recordInfo.constId), "lref_type_id"_a = idToString(recordInfo.lrefId),
                              "const_lref_type_id"_a = idToString(recordInfo.constLrefId), "rref_type_id"_a = idToString(recordInfo.rrefId),
                              "ptr_type_id"_a = idToString(recordInfo.ptrId), "const_ptr_type_id"_a = idToString(recordInfo.constPtrId)));

            write(fmt::format(GetTypeIDTemplate, "full_name"_a = recordInfo.fullName, "type"_a = recordInfo.fullName,
                              "type_id"_a = idToString(recordInfo.id), "const_type_id"_a = idToString(recordInfo.constId),
                              "lref_type_id"_a = idToString(recordInfo.lrefId), "const_lref_type_id"_a = idToString(recordInfo.constLrefId),
                              "rref_type_id"_a = idToString(recordInfo.rrefId), "ptr_type_id"_a = idToString(recordInfo.ptrId),
                              "const_ptr_type_id"_a = idToString(recordInfo.constPtrId)));
        }

        for (const auto &baseInfo: recordInfo.baseClasses) {

            write(fmt::format(StaticTypeInfoTemplate_Base, "full_name"_a = baseInfo.fullName, "id"_a = idToString(baseInfo.id),
                              "details"_a = "", "type_id"_a = idToString(idGenerator->generateId(baseInfo.fullName)),
                              "source_file"_a = baseInfo.sourceLocation.filename, "source_line"_a = baseInfo.sourceLocation.line,
                              "source_column"_a = baseInfo.sourceLocation.column, "is_public"_a = baseInfo.access == Access::Public,
                              "is_protected"_a = baseInfo.access == Access::Protected, "is_private"_a = baseInfo.access == Access::Private,
                              "is_virtual"_a = baseInfo.isVirtual, "name"_a = baseInfo.name));
        }
        for (const auto &ctorInfo: recordInfo.constructors) {
            for (const auto &argInfo: ctorInfo.arguments) {
                std::vector<std::string> argsArrayNames;
                std::string detailsContents;
                for (const auto &attr: argInfo.attributes) {
                    if (attr.arguments.empty()) {
                        argsArrayNames.push_back("EmptyAttributeArgArray");
                    } else {
                        const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                        argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                        detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                    }
                }
                const auto attributesStr = StringifyAttributes(argInfo.attributes, argsArrayNames);

                write(fmt::format(StaticTypeInfoTemplate_Argument, "full_name"_a = argInfo.fullName, "id"_a = idToString(argInfo.id),
                                  "details"_a = createDetailsStruct(detailsContents), "type_id"_a = idToString(argInfo.typeId),
                                  "source_file"_a = argInfo.sourceLocation.filename, "source_line"_a = argInfo.sourceLocation.line,
                                  "source_column"_a = argInfo.sourceLocation.column, "attributes"_a = attributesStr,
                                  "name"_a = argInfo.name));
            }

            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: ctorInfo.attributes) {
                if (attr.arguments.empty()) {
                    argsArrayNames.push_back("EmptyAttributeArgArray");
                } else {
                    const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                    argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                    detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                }
            }
            const auto attributesStr = StringifyAttributes(ctorInfo.attributes, argsArrayNames);

            std::string argsWithNames;
            std::string argNames;
            std::size_t cnt{};
            for (const auto &arg: ctorInfo.arguments) {
                argNames.append(fmt::format("arg_{}, ", cnt));
                argsWithNames.append(fmt::format("{} arg_{}, ", arg.typeName, cnt));
                ++cnt;
            }
            if (!argsWithNames.empty()) {
                argsWithNames = argsWithNames.substr(0, argsWithNames.size() - 2);
                argNames = argNames.substr(0, argNames.size() - 2);
            }
            std::string ctorModifier;
            if (ctorInfo.isConstexpr) { ctorModifier = "constexpr"; }
            if (ctorInfo.isConsteval) { ctorModifier = "consteval"; }


            std::string wrapLambdaStr =
                    fmt::format(R"([]({args}) {modifier} -> {type} {{ return {type}({arg_names}); }})", "args"_a = argsWithNames,
                                "type"_a = recordInfo.fullName, "arg_names"_a = argNames, "modifier"_a = ctorModifier);
            std::string newLambdaStr =
                    fmt::format(R"([]({args}) {modifier} -> {type}* {{ return new {type}({arg_names}); }})", "args"_a = argsWithNames,
                                "type"_a = recordInfo.fullName, "arg_names"_a = argNames, "modifier"_a = ctorModifier);

            write(fmt::format(StaticTypeInfoTemplate_Constructor, "full_name"_a = ctorInfo.fullName, "id"_a = idToString(ctorInfo.id),
                              "details"_a = createDetailsStruct(detailsContents), "type_id"_a = idToString(recordInfo.id),
                              "source_file"_a = ctorInfo.sourceLocation.filename, "source_line"_a = ctorInfo.sourceLocation.line,
                              "source_column"_a = ctorInfo.sourceLocation.column, "attributes"_a = attributesStr,
                              "is_public"_a = ctorInfo.access == Access::Public, "is_protected"_a = ctorInfo.access == Access::Protected,
                              "is_private"_a = ctorInfo.access == Access::Private, "is_explicit"_a = ctorInfo.isExplicit,
                              "is_copy"_a = ctorInfo.isCopy, "is_move"_a = ctorInfo.isMove, "name"_a = recordInfo.name,
                              "is_constexpr"_a = ctorInfo.isConstexpr, "is_consteval"_a = ctorInfo.isConsteval,
                              "arguments"_a = idsToStringMakeArray(ctorInfo.arguments), "ctor_wrap_lambda"_a = wrapLambdaStr,
                              "new_wrap_lambda"_a = newLambdaStr));
        }

        {
            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: recordInfo.destructor.attributes) {
                if (attr.arguments.empty()) {
                    argsArrayNames.push_back("EmptyAttributeArgArray");
                } else {
                    const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                    argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                    detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                }
            }
            const auto attributesStr = StringifyAttributes(recordInfo.destructor.attributes, argsArrayNames);

            write(fmt::format(StaticTypeInfoTemplate_Destructor, "full_name"_a = recordInfo.destructor.fullName,
                              "id"_a = idToString(recordInfo.destructor.id), "details"_a = createDetailsStruct(detailsContents),
                              "type_id"_a = idToString(recordInfo.id), "source_file"_a = recordInfo.destructor.sourceLocation.filename,
                              "source_line"_a = recordInfo.destructor.sourceLocation.line,
                              "source_column"_a = recordInfo.destructor.sourceLocation.column, "attributes"_a = attributesStr,
                              "is_public"_a = recordInfo.destructor.access == Access::Public,
                              "is_protected"_a = recordInfo.destructor.access == Access::Protected,
                              "is_private"_a = recordInfo.destructor.access == Access::Private,
                              "is_constexpr"_a = recordInfo.destructor.isConstexpr, "is_consteval"_a = recordInfo.destructor.isConsteval,
                              "is_virtual"_a = recordInfo.destructor.isVirtual, "is_pure_virtual"_a = recordInfo.destructor.isPureVirtual,
                              "is_final"_a = recordInfo.destructor.isFinal, "name"_a = fmt::format("~{}", recordInfo.name)));
        }

        for (const auto &mbrFncInfo: recordInfo.memberFunctions) {
            for (const auto &argInfo: mbrFncInfo.arguments) {
                std::vector<std::string> argsArrayNames;
                std::string detailsContents;
                for (const auto &attr: argInfo.attributes) {
                    if (attr.arguments.empty()) {
                        argsArrayNames.push_back("EmptyAttributeArgArray");
                    } else {
                        const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                        argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                        detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                    }
                }
                const auto attributesStr = StringifyAttributes(argInfo.attributes, argsArrayNames);

                write(fmt::format(StaticTypeInfoTemplate_Argument, "full_name"_a = argInfo.fullName, "id"_a = idToString(argInfo.id),
                                  "details"_a = createDetailsStruct(detailsContents), "type_id"_a = idToString(argInfo.typeId),
                                  "source_file"_a = argInfo.sourceLocation.filename, "source_line"_a = argInfo.sourceLocation.line,
                                  "source_column"_a = argInfo.sourceLocation.column, "attributes"_a = attributesStr,
                                  "name"_a = argInfo.name));
            }

            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: mbrFncInfo.attributes) {
                if (attr.arguments.empty()) {
                    argsArrayNames.push_back("EmptyAttributeArgArray");
                } else {
                    const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                    argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                    detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                }
            }
            const auto attributesStr = StringifyAttributes(mbrFncInfo.attributes, argsArrayNames);

            std::string arguments;
            for (const auto &a: mbrFncInfo.arguments) { arguments.append(fmt::format("{}, ", a.typeName)); }
            if (!arguments.empty()) { arguments = arguments.substr(0, arguments.size() - 2); }

            if (mbrFncInfo.isConsteval) {
                // TODO: deduplicate
                std::string argsWithNames;
                std::string argNames;
                std::size_t cnt{};
                for (const auto &arg: mbrFncInfo.arguments) {
                    argNames.append(fmt::format("arg_{}, ", cnt));
                    argsWithNames.append(fmt::format("{} arg_{}, ", arg.typeName, cnt));
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
                            "modifier"_a = "consteval", "result_type"_a = mbrFncInfo.returnTypeName, "fnc"_a = mbrFncInfo.name,
                            "return"_a = mbrFncInfo.returnTypeName == "void" ? "" : "return");
                } else {
                    constevalWrapStr = fmt::format(
                            R"([]({this_type} *self, {args}) {modifier} -> {result_type} {{ {return} self->{fnc}({arg_names}); }})",
                            "this_type"_a = mbrFncInfo.isConst ? fmt::format("const {}", recordInfo.fullName) : recordInfo.fullName,
                            "args"_a = argsWithNames, "arg_names"_a = argNames, "modifier"_a = "consteval",
                            "result_type"_a = mbrFncInfo.returnTypeName, "fnc"_a = mbrFncInfo.name,
                            "return"_a = mbrFncInfo.returnTypeName == "void" ? "" : "return");
                }
                write(fmt::format(StaticTypeInfoTemplate_ConstevalMemberFunction, "full_name"_a = mbrFncInfo.fullName,
                                  "id"_a = idToString(mbrFncInfo.id), "details"_a = createDetailsStruct(detailsContents),
                                  "type_id"_a = idToString(recordInfo.id), "source_file"_a = mbrFncInfo.sourceLocation.filename,
                                  "source_line"_a = mbrFncInfo.sourceLocation.line, "source_column"_a = mbrFncInfo.sourceLocation.column,
                                  "attributes"_a = attributesStr, "is_public"_a = mbrFncInfo.access == Access::Public,
                                  "is_protected"_a = mbrFncInfo.access == Access::Protected,
                                  "is_private"_a = mbrFncInfo.access == Access::Private, "name"_a = mbrFncInfo.name,
                                  "is_constexpr"_a = mbrFncInfo.isConstexpr, "is_consteval"_a = mbrFncInfo.isConsteval,
                                  "is_const"_a = mbrFncInfo.isConst, "is_virtual"_a = mbrFncInfo.isVirtual,
                                  "is_pure_virtual"_a = mbrFncInfo.isPureVirtual, "is_final"_a = mbrFncInfo.isFinal,
                                  "return_type_id"_a = idToString(mbrFncInfo.returnTypeId),
                                  "arguments"_a = idsToStringMakeArray(mbrFncInfo.arguments), "consteval_wrap"_a = constevalWrapStr,
                                  "member"_a = mbrFncInfo.fullName));
            } else {
                const auto mbrFncType =
                        fmt::format("{return_type}({type}::*MemberPtr)({arguments})", "return_type"_a = mbrFncInfo.returnTypeName,
                                    "type"_a = recordInfo.fullName, "arguments"_a = arguments);
                write(fmt::format(StaticTypeInfoTemplate_MemberFunction, "full_name"_a = mbrFncInfo.fullName,
                                  "id"_a = idToString(mbrFncInfo.id), "details"_a = createDetailsStruct(detailsContents),
                                  "type_id"_a = idToString(recordInfo.id), "source_file"_a = mbrFncInfo.sourceLocation.filename,
                                  "source_line"_a = mbrFncInfo.sourceLocation.line, "source_column"_a = mbrFncInfo.sourceLocation.column,
                                  "attributes"_a = attributesStr, "is_public"_a = mbrFncInfo.access == Access::Public,
                                  "is_protected"_a = mbrFncInfo.access == Access::Protected,
                                  "is_private"_a = mbrFncInfo.access == Access::Private, "name"_a = mbrFncInfo.name,
                                  "is_constexpr"_a = mbrFncInfo.isConstexpr, "is_consteval"_a = mbrFncInfo.isConsteval,
                                  "is_const"_a = mbrFncInfo.isConst, "is_virtual"_a = mbrFncInfo.isVirtual,
                                  "is_pure_virtual"_a = mbrFncInfo.isPureVirtual, "is_final"_a = mbrFncInfo.isFinal,
                                  "return_type_id"_a = idToString(mbrFncInfo.returnTypeId),
                                  "arguments"_a = idsToStringMakeArray(mbrFncInfo.arguments), "member_type"_a = mbrFncType,
                                  "member"_a = mbrFncInfo.fullName));
            }
        }

        for (const auto &mbrVarInfo: recordInfo.memberVariables) {
            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: mbrVarInfo.attributes) {
                if (attr.arguments.empty()) {
                    argsArrayNames.push_back("EmptyAttributeArgArray");
                } else {
                    const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                    argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                    detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                }
            }
            const auto attributesStr = StringifyAttributes(mbrVarInfo.attributes, argsArrayNames);

            const auto mbrVarType =
                    fmt::format("{return_type} {type}::* MemberPtr", "return_type"_a = mbrVarInfo.typeName, "type"_a = recordInfo.fullName);

            write(fmt::format(StaticTypeInfoTemplate_MemberVariable, "full_name"_a = mbrVarInfo.fullName,
                              "id"_a = idToString(mbrVarInfo.id), "details"_a = createDetailsStruct(detailsContents),
                              "type_id"_a = idToString(recordInfo.id), "source_file"_a = mbrVarInfo.sourceLocation.filename,
                              "source_line"_a = mbrVarInfo.sourceLocation.line, "source_column"_a = mbrVarInfo.sourceLocation.column,
                              "attributes"_a = attributesStr, "is_public"_a = mbrVarInfo.access == Access::Public,
                              "is_protected"_a = mbrVarInfo.access == Access::Protected,
                              "is_private"_a = mbrVarInfo.access == Access::Private, "name"_a = mbrVarInfo.name,
                              "is_mutable"_a = mbrVarInfo.isMutable, "member_type"_a = mbrVarType, "member"_a = mbrVarInfo.fullName));
        }

        for (const auto &statFncInfo: recordInfo.staticFunctions) {
            for (const auto &argInfo: statFncInfo.arguments) {
                std::vector<std::string> argsArrayNames;
                std::string detailsContents;
                for (const auto &attr: argInfo.attributes) {
                    if (attr.arguments.empty()) {
                        argsArrayNames.push_back("EmptyAttributeArgArray");
                    } else {
                        const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                        argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                        detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                    }
                }
                const auto attributesStr = StringifyAttributes(argInfo.attributes, argsArrayNames);
                write(fmt::format(StaticTypeInfoTemplate_Argument, "full_name"_a = argInfo.fullName, "id"_a = idToString(argInfo.id),
                                  "details"_a = createDetailsStruct(detailsContents), "type_id"_a = idToString(argInfo.typeId),
                                  "source_file"_a = argInfo.sourceLocation.filename, "source_line"_a = argInfo.sourceLocation.line,
                                  "source_column"_a = argInfo.sourceLocation.column, "attributes"_a = attributesStr,
                                  "name"_a = argInfo.name));
            }

            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: statFncInfo.attributes) {
                if (attr.arguments.empty()) {
                    argsArrayNames.push_back("EmptyAttributeArgArray");
                } else {
                    const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                    argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                    detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                }
            }
            const auto attributesStr = StringifyAttributes(statFncInfo.attributes, argsArrayNames);
            std::string arguments;
            for (const auto &a: statFncInfo.arguments) { arguments.append(fmt::format("{}, ", a.typeName)); }
            if (!arguments.empty()) { arguments = arguments.substr(0, arguments.size() - 2); }
            const auto statFncType = fmt::format("{return_type}(*MemberPtr)({arguments})", "return_type"_a = statFncInfo.returnTypeName,
                                                 "arguments"_a = arguments);

            if (statFncInfo.isConsteval) {
                // TODO: deduplicate
                std::string argsWithNames;
                std::string argNames;
                std::size_t cnt{};
                for (const auto &arg: statFncInfo.arguments) {
                    argNames.append(fmt::format("arg_{}, ", cnt));
                    argsWithNames.append(fmt::format("{} arg_{}, ", arg.typeName, cnt));
                    ++cnt;
                }
                if (!argsWithNames.empty()) {
                    argsWithNames = argsWithNames.substr(0, argsWithNames.size() - 2);
                    argNames = argNames.substr(0, argNames.size() - 2);
                }

                const std::string constevalWrapStr =
                        fmt::format(R"([]({args}) {modifier} -> {result_type} {{ {return} self->{fnc}({arg_names}); }})",
                                    "args"_a = argsWithNames, "arg_names"_a = argNames, "type"_a = recordInfo.fullName,
                                    "modifier"_a = "consteval", "result_type"_a = statFncInfo.returnTypeName, "fnc"_a = statFncInfo.name,
                                    "return"_a = statFncInfo.returnTypeName == "void" ? "" : "return");


                write(fmt::format(StaticTypeInfoTemplate_ConstevalStaticFunction, "full_name"_a = statFncInfo.fullName,
                                  "id"_a = idToString(statFncInfo.id), "details"_a = createDetailsStruct(detailsContents),
                                  "type_id"_a = idToString(recordInfo.id), "source_file"_a = statFncInfo.sourceLocation.filename,
                                  "source_line"_a = statFncInfo.sourceLocation.line, "source_column"_a = statFncInfo.sourceLocation.column,
                                  "attributes"_a = attributesStr, "is_public"_a = statFncInfo.access == Access::Public,
                                  "is_protected"_a = statFncInfo.access == Access::Protected,
                                  "is_private"_a = statFncInfo.access == Access::Private, "name"_a = statFncInfo.name,
                                  "is_constexpr"_a = statFncInfo.isConstexpr, "is_consteval"_a = statFncInfo.isConsteval,
                                  "return_type_id"_a = idToString(statFncInfo.returnTypeId),
                                  "arguments"_a = idsToStringMakeArray(statFncInfo.arguments), "member_type"_a = statFncType,
                                  "member"_a = statFncInfo.fullName, "consteval_wrap"_a = constevalWrapStr));
            } else {
                write(fmt::format(StaticTypeInfoTemplate_StaticFunction, "full_name"_a = statFncInfo.fullName,
                                  "id"_a = idToString(statFncInfo.id), "details"_a = createDetailsStruct(detailsContents),
                                  "type_id"_a = idToString(recordInfo.id), "source_file"_a = statFncInfo.sourceLocation.filename,
                                  "source_line"_a = statFncInfo.sourceLocation.line, "source_column"_a = statFncInfo.sourceLocation.column,
                                  "attributes"_a = attributesStr, "is_public"_a = statFncInfo.access == Access::Public,
                                  "is_protected"_a = statFncInfo.access == Access::Protected,
                                  "is_private"_a = statFncInfo.access == Access::Private, "name"_a = statFncInfo.name,
                                  "is_constexpr"_a = statFncInfo.isConstexpr, "is_consteval"_a = statFncInfo.isConsteval,
                                  "return_type_id"_a = idToString(statFncInfo.returnTypeId),
                                  "arguments"_a = idsToStringMakeArray(statFncInfo.arguments), "member_type"_a = statFncType,
                                  "member"_a = statFncInfo.fullName));
            }
        }

        for (const auto &statVarInfo: recordInfo.staticVariables) {
            std::vector<std::string> argsArrayNames;
            std::string detailsContents;
            for (const auto &attr: statVarInfo.attributes) {
                if (attr.arguments.empty()) {
                    argsArrayNames.push_back("EmptyAttributeArgArray");
                } else {
                    const auto argsArrayName = fmt::format("ArgArray_{}", idGenerator->generateRandomInt());
                    argsArrayNames.push_back(fmt::format("details::{}", argsArrayName));
                    detailsContents.append(CreateAttributeArgArray(argsArrayName, attr)).append("\n");
                }
            }
            const auto attributesStr = StringifyAttributes(statVarInfo.attributes, argsArrayNames);
            const auto statVarType = fmt::format("{type}* MemberPtr", "type"_a = statVarInfo.typeName);

            write(fmt::format(StaticTypeInfoTemplate_StaticVariable, "full_name"_a = statVarInfo.fullName,
                              "id"_a = idToString(statVarInfo.id), "details"_a = createDetailsStruct(detailsContents),
                              "type_id"_a = idToString(recordInfo.id), "source_file"_a = statVarInfo.sourceLocation.filename,
                              "source_line"_a = statVarInfo.sourceLocation.line, "source_column"_a = statVarInfo.sourceLocation.column,
                              "attributes"_a = attributesStr, "is_public"_a = statVarInfo.access == Access::Public,
                              "is_protected"_a = statVarInfo.access == Access::Protected, "is_constexpr"_a = statVarInfo.isConstexpr,
                              "is_private"_a = statVarInfo.access == Access::Private, "name"_a = statVarInfo.name,
                              "member_type"_a = statVarType, "member"_a = statVarInfo.fullName));
        }
    }

    std::string MetaInfoWriter::StringifyAttributes(const std::vector<Attribute> &attrs, const std::vector<std::string> &argArrayNames) {
        assert(attrs.size() == argArrayNames.size());
        std::string attributesString{};
        for (auto i = 0ull; i < attrs.size(); ++i) {
            const auto &attr = attrs[i];
            const auto &argArrayName = argArrayNames[i];
            attributesString.append(
                    fmt::format(R"(Attribute{{"{}", std::span<const std::string_view>{{{}}}}}, )", attr.name, argArrayName));
        }
        if (!attrs.empty()) { return attributesString.substr(0, attributesString.length() - 2); }
        return attributesString;
    }

    std::string MetaInfoWriter::CreateAttributeArgArray(std::string_view name, const Attribute &attr) {
        std::string attributeArgsStr{};
        attributeArgsStr.append(fmt::format("constexpr static auto {} = pf::meta::details::make_array<std::string_view>(", name));
        for (const auto &arg: attr.arguments) { attributeArgsStr.append(fmt::format(R"fmt(R"arg({})arg")fmt", arg)).append(", "); }
        if (!attr.arguments.empty()) { attributeArgsStr = attributeArgsStr.substr(0, attributeArgsStr.length() - 2); }
        attributeArgsStr.append(");");
        return attributeArgsStr;
    }

}// namespace pf::meta_gen