//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

namespace pf::meta_gen {

    constexpr auto StaticTypeInfoTemplate_Enum = R"fmt(
template<>
struct StaticInfo<{type_id}> {{
    {details}
    using Type = {type};
    constexpr static ID TypeID = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    using UnderlyingType = {underlying_type};
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<Info> auto EnumValues = pf::meta::details::make_array<Info>({enum_value_ids});
}};

// const
template<>
struct StaticInfo<{const_type_id}>
    : StaticInfo_ConstWrap<{const_type_id}, {type_id}> {{}};
// &
template<>
struct StaticInfo<{lref_type_id}>
    : StaticInfo_LRefWrap<{lref_type_id}, {type_id}> {{}};
// &&
template<>
struct StaticInfo<{rref_type_id}>
    : StaticInfo_RRefWrap<{rref_type_id}, {type_id}> {{}};
// const &
template<>
struct StaticInfo<{const_lref_type_id}>
    : StaticInfo_ConstLRefWrap<{const_lref_type_id}, {type_id}> {{}};
// *
template<>
struct StaticInfo<{ptr_type_id}>
    : StaticInfo_PtrWrap<{ptr_type_id}, {type_id}> {{}};
// const *
template<>
struct StaticInfo<{const_ptr_type_id}>
    : StaticInfo_ConstPtrWrap<{const_ptr_type_id}, {type_id}> {{}};
)fmt";

    constexpr auto StaticTypeInfoTemplate_Record = R"fmt(
template<>
struct StaticInfo<{type_id}> {{
    {details}
    using Type = {type};
    constexpr static ID TypeID = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::RecordType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static bool IsUnion = {is_union};
    constexpr static bool IsClass = {is_class};
    constexpr static bool IsStruct = {is_struct};
    constexpr static bool IsPolymorphic = {is_poly};
    constexpr static bool IsAbstract = {is_abstract};
    constexpr static bool IsFinal = {is_final};
    constexpr static RangeOf<Info> auto Bases = pf::meta::details::make_array<Info>({bases});
    constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>({ctors});
    constexpr static Info Destructor = {dtor};
    constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>({member_fncs});
    constexpr static RangeOf<Info> auto StaticFunctions = pf::meta::details::make_array<Info>({static_fncs});
    constexpr static RangeOf<Info> auto MemberVariables = pf::meta::details::make_array<Info>({member_vars});
    constexpr static RangeOf<Info> auto StaticVariables = pf::meta::details::make_array<Info>({static_vars});
}};

// const
template<>
struct StaticInfo<{const_type_id}>
    : StaticInfo_ConstWrap<{const_type_id}, {type_id}> {{}};
// &
template<>
struct StaticInfo<{lref_type_id}>
    : StaticInfo_LRefWrap<{lref_type_id}, {type_id}> {{}};
// &&
template<>
struct StaticInfo<{rref_type_id}>
    : StaticInfo_RRefWrap<{rref_type_id}, {type_id}> {{}};
// const &
template<>
struct StaticInfo<{const_lref_type_id}>
    : StaticInfo_ConstLRefWrap<{const_lref_type_id}, {type_id}> {{}};
// *
template<>
struct StaticInfo<{ptr_type_id}>
    : StaticInfo_PtrWrap<{ptr_type_id}, {type_id}> {{}};
// const *
template<>
struct StaticInfo<{const_ptr_type_id}>
    : StaticInfo_ConstPtrWrap<{const_ptr_type_id}, {type_id}> {{}};
)fmt";

}// namespace pf::meta_gen
