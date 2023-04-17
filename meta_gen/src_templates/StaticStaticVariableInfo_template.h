//
// Created by xflajs00 on 27.03.2023.
//

#ifndef PF_META_GEN_STATICSTATICVARIABLEINFO_TEMPLATE_H
#define PF_META_GEN_STATICSTATICVARIABLEINFO_TEMPLATE_H

constexpr auto StaticTypeInfoTemplate_StaticVariable = R"fmt(
/****************************** {full_name} START ******************************/
template<>
struct StaticInfo<{id}> {{
        struct details {{
                {details}
        }};
        constexpr static ID VariableID = {id};
        constexpr static ID TypeID = {type_id};

        constexpr static auto SourceFile = R"path({source_file})path";
        constexpr static std::uint64_t SourceLine = {source_line};
        constexpr static std::uint64_t SourceColumn = {source_column};

        constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>({attributes});

        constexpr static auto StaticInfoObjectType = StaticInfoType::StaticVariable;

        constexpr static bool IsPublic = {is_public};
        constexpr static bool IsProtected = {is_protected};
        constexpr static bool IsPrivate = {is_private};

        constexpr static auto Name = StringLiteral{{"{name}"}};
        constexpr static auto FullName = StringLiteral{{"{full_name}"}};
    }};
)fmt";

#endif //PF_META_GEN_STATICSTATICVARIABLEINFO_TEMPLATE_H
