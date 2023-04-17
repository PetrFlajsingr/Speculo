//
// Created by xflajs00 on 17.03.2023.
//

#ifndef PF_META_GEN_STATICTYPEINFO_TEMPLATE_H
#define PF_META_GEN_STATICTYPEINFO_TEMPLATE_H

namespace pf::meta_gen {

    constexpr auto StaticTypeInfoTemplate_Enum = R"fmt(
/****************************** {full_name} START ******************************/
template<>
struct StaticInfo<{type_id}> {{
    struct details {{
        {details}
    }};
    using Type = {type};
    constexpr static ID TypeID = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    using UnderlyingType = {underlying_type};
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<Info> auto EnumValues = make_array<Info>({enum_value_ids});
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

/****************************** {full_name} END ******************************/
)fmt";

    constexpr auto StaticTypeInfoTemplate_Record = R"fmt(
/****************************** {full_name} START ******************************/
template<>
struct StaticInfo<{type_id}> {{
    {details}
    using Type = {type};
    constexpr static ID TypeID = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::RecordType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static bool IsUnion = {is_union};
    constexpr static bool IsPolymorphic = {is_poly};
    constexpr static bool IsAbstract = {is_abstract};
    constexpr static bool IsFinal = {is_final};
    constexpr static RangeOf<Info> auto Bases = make_array<Info>({bases});
    constexpr static RangeOf<Info> auto Constructors = make_array<Info>({ctors});
    constexpr static Info Destructor = {dtor};
    constexpr static RangeOf<Info> auto MemberFunctions = make_array<Info>({member_fncs});
    constexpr static RangeOf<Info> auto StaticFunctions = make_array<Info>({static_fncs});
    constexpr static RangeOf<Info> auto MemberVariables = make_array<Info>({member_vars});
    constexpr static RangeOf<Info> auto StaticVariables = make_array<Info>({static_vars});
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

/****************************** {full_name} END ******************************/
)fmt";

}// namespace pf::meta_gen

#endif//PF_META_GEN_STATICTYPEINFO_TEMPLATE_H
