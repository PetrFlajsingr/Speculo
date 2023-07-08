//
// Created by xflajs00 on 27.03.2023.
//

#pragma once


namespace speculo::gen::templates {
    constexpr auto StaticTypeInfo_StaticFunction = R"fmt(
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID FunctionID = {id};
    constexpr static ID Id = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = speculo::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::StaticFunction;

    constexpr static bool IsPublic = {is_public};
    constexpr static bool IsProtected = {is_protected};
    constexpr static bool IsPrivate = {is_private};
    constexpr static bool IsConstexpr = {is_constexpr};
    constexpr static bool IsConsteval = {is_consteval};
    constexpr static bool IsInline = {is_inline};
    constexpr static bool IsInlineSpecified = {is_inline_specified};
    constexpr static bool IsNothrow = {is_nothrow};

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static Info ReturnType = {return_type_id};
    constexpr static RangeOf<Info> auto Arguments = speculo::make_array<Info>({arguments});

    constexpr static {member_type} = &{member};
    }};
)fmt";
    constexpr auto StaticTypeInfo_ConstevalStaticFunction = R"fmt(
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID FunctionID = {id};
    constexpr static ID Id = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = speculo::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::StaticFunction;

    constexpr static bool IsPublic = {is_public};
    constexpr static bool IsProtected = {is_protected};
    constexpr static bool IsPrivate = {is_private};
    constexpr static bool IsConstexpr = {is_constexpr};
    constexpr static bool IsConsteval = {is_consteval};
    constexpr static bool IsInline = true;
    constexpr static bool IsInlineSpecified = {is_inline_specified};
    constexpr static bool IsNothrow = {is_nothrow};

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static Info ReturnType = {return_type_id};
    constexpr static RangeOf<Info> auto Arguments = speculo::make_array<Info>({arguments});

    constexpr static auto ConstevalWrap = {consteval_wrap};
    }};
)fmt";
}// namespace speculo::gen::templates