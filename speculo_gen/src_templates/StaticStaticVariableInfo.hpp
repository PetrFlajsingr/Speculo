//
// Created by xflajs00 on 27.03.2023.
//

#pragma once


namespace speculo::gen::templates {
    constexpr auto StaticTypeInfo_StaticVariable = R"fmt(
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID VariableID = {id};
    constexpr static ID Id = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = speculo::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::StaticVariable;

    constexpr static bool IsPublic = {is_public};
    constexpr static bool IsProtected = {is_protected};
    constexpr static bool IsPrivate = {is_private};
    constexpr static bool IsConstexpr = {is_constexpr};
    constexpr static bool IsInline = {is_inline};
    constexpr static bool IsInlineSpecified = {is_inline_specified};

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static {member_type} = &{member};
    }};
)fmt";
}