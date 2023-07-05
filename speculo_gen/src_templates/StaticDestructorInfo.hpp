//
// Created by xflajs00 on 27.03.2023.
//

#pragma once


namespace speculo::gen::templates {
    constexpr auto StaticTypeInfo_Destructor = R"fmt(
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID DestructorID = {id};
    constexpr static ID Id = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = speculo::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::Destructor;

    constexpr static bool IsPublic = {is_public};
    constexpr static bool IsProtected = {is_protected};
    constexpr static bool IsPrivate = {is_private};
    constexpr static auto IsConstexpr = {is_constexpr};
    constexpr static auto IsConsteval = {is_consteval};
    constexpr static auto IsVirtual = {is_virtual};
    constexpr static auto IsPureVirtual = {is_pure_virtual};
    constexpr static auto IsFinal = {is_final};
    constexpr static bool IsInline = {is_inline};
    constexpr static bool IsInlineSpecified = {is_inline_specified};
    constexpr static bool IsNothrow = {is_nothrow};

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static auto DtorWrap = {dtor_wrap_lambda};
    }};
)fmt";
}