//
// Created by xflajs00 on 27.03.2023.
//

#pragma once

constexpr auto StaticTypeInfoTemplate_MemberFunction = R"fmt(
/****************************** {full_name} START ******************************/
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID FunctionID = {id};
    constexpr static ID TypeID = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

    constexpr static bool IsPublic = {is_public};
    constexpr static bool IsProtected = {is_protected};
    constexpr static bool IsPrivate = {is_private};
    constexpr static bool IsConst = {is_const};
    constexpr static bool IsVirtual = {is_virtual};
    constexpr static bool IsPureVirtual = {is_pure_virtual};
    constexpr static auto IsFinal = {is_final};
    constexpr static bool IsConstexpr = {is_constexpr};
    constexpr static bool IsConsteval = {is_consteval};
    constexpr static bool IsInline = {is_inline};
    constexpr static bool IsInlineSpecified = {is_inline_specified};

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static Info ReturnType = {return_type_id};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>({arguments});

    constexpr static {member_type} = &{member};
    }};
)fmt";

constexpr auto StaticTypeInfoTemplate_ConstevalMemberFunction = R"fmt(
/****************************** {full_name} START ******************************/
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID FunctionID = {id};
    constexpr static ID TypeID = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

    constexpr static bool IsPublic = {is_public};
    constexpr static bool IsProtected = {is_protected};
    constexpr static bool IsPrivate = {is_private};
    constexpr static bool IsConst = {is_const};
    constexpr static bool IsVirtual = {is_virtual};
    constexpr static bool IsPureVirtual = {is_pure_virtual};
    constexpr static auto IsFinal = {is_final};
    constexpr static bool IsConstexpr = {is_constexpr};
    constexpr static bool IsConsteval = {is_consteval};
    constexpr static bool IsInline = true;
    constexpr static bool IsInlineSpecified = {is_inline_specified};

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static Info ReturnType = {return_type_id};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>({arguments});

    constexpr static auto ConstevalWrap = {consteval_wrap};
    }};
)fmt";
