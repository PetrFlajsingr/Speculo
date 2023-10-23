export module speculo.gen:src_templates;

namespace speculo::gen::templates {

    constexpr auto StaticValueInfo_Enum = R"fmt(
template<>
struct StaticInfo<{value_id}> {{
    {details}
    constexpr static ID ValueID = {value_id};
    constexpr static ID Id = {type_id};
    using Type = {type};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = speculo::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static {underlying_type} UnderlyingValue = {underlying_value};
    constexpr static {type} Value = {value};
}};
)fmt";


    constexpr auto StaticTypeInfo_Enum = R"fmt(
template<>
struct StaticInfo<{type_id}> {{
    {details}
    using Type = {type};
    constexpr static ID Id = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = speculo::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;
    constexpr static bool IsVolatile = false;
    constexpr static bool IsLiteral = true;
    constexpr static bool IsPOD = true;
    constexpr static bool IsStandardLayout = true;
    constexpr static bool IsTriviallyCopyable = true;
    constexpr static bool IsTrivial = true;
    constexpr static bool IsEmpty = false;
    constexpr static bool IsAggregate = false;

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    using UnderlyingType = {underlying_type};
    constexpr static bool IsScoped = {is_scoped};
    constexpr static std::size_t Size = {size};
    constexpr static std::size_t Alignment = {alignment};
    constexpr static RangeOf<Info> auto EnumValues = speculo::make_array<Info>({enum_value_ids});
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
// volatile
template<>
struct StaticInfo<{volatile_type_id}>
    : StaticInfo_VolatileConstPtrWrap<{volatile_type_id}, {type_id}> {{}};
// const volatile
template<>
struct StaticInfo<{volatile_const_type_id}>
    : StaticInfo_VolatileConstWrap<{volatile_const_type_id}, {type_id}> {{}};
// volatile &
template<>
struct StaticInfo<{volatile_lref_type_id}>
    : StaticInfo_VolatileLRefWrap<{volatile_lref_type_id}, {type_id}> {{}};
// volatile &&
template<>
struct StaticInfo<{volatile_rref_type_id}>
    : StaticInfo_VolatileRRefWrap<{volatile_rref_type_id}, {type_id}> {{}};
// volatile const &
template<>
struct StaticInfo<{volatile_const_lref_type_id}>
    : StaticInfo_VolatileConstLRefWrap<{volatile_const_lref_type_id}, {type_id}> {{}};
// volatile *
template<>
struct StaticInfo<{volatile_ptr_type_id}>
    : StaticInfo_VolatilePtrWrap<{volatile_ptr_type_id}, {type_id}> {{}};
// volatile const *
template<>
struct StaticInfo<{volatile_const_ptr_type_id}>
    : StaticInfo_VolatileConstPtrWrap<{volatile_const_ptr_type_id}, {type_id}> {{}};
)fmt";

    constexpr auto StaticTypeInfo_Record = R"fmt(
template<>
struct StaticInfo<{type_id}> {{
    {details}
    using Type = {type};
    constexpr static ID Id = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = speculo::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::RecordType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;
    constexpr static bool IsVolatile = false;
    constexpr static std::size_t Size = {size};
    constexpr static std::size_t Alignment = {alignment};

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static bool IsUnion = {is_union};
    constexpr static bool IsClass = {is_class};
    constexpr static bool IsStruct = {is_struct};
    constexpr static bool IsPolymorphic = {is_poly};
    constexpr static bool IsAbstract = {is_abstract};
    constexpr static bool IsFinal = {is_final};
    constexpr static bool IsLiteral = {is_literal};
    constexpr static bool IsPOD = {is_pod};
    constexpr static bool IsStandardLayout = {is_standard_layout};
    constexpr static bool IsTriviallyCopyable = {is_trivially_copyable};
    constexpr static bool IsTrivial = {is_trivial};
    constexpr static bool IsEmpty = {is_empty};
    constexpr static bool IsAggregate = {is_aggregate};

    constexpr static RangeOf<Info> auto Bases = speculo::make_array<Info>({bases});
    constexpr static RangeOf<Info> auto Constructors = speculo::make_array<Info>({ctors});
    constexpr static Info Destructor = {dtor};
    constexpr static RangeOf<Info> auto MemberFunctions = speculo::make_array<Info>({member_fncs});
    constexpr static RangeOf<Info> auto StaticFunctions = speculo::make_array<Info>({static_fncs});
    constexpr static RangeOf<Info> auto MemberVariables = speculo::make_array<Info>({member_vars});
    constexpr static RangeOf<Info> auto StaticVariables = speculo::make_array<Info>({static_vars});
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
// volatile
template<>
struct StaticInfo<{volatile_type_id}>
    : StaticInfo_VolatileConstPtrWrap<{volatile_type_id}, {type_id}> {{}};
// const volatile
template<>
struct StaticInfo<{volatile_const_type_id}>
    : StaticInfo_VolatileConstWrap<{volatile_const_type_id}, {type_id}> {{}};
// volatile &
template<>
struct StaticInfo<{volatile_lref_type_id}>
    : StaticInfo_VolatileLRefWrap<{volatile_lref_type_id}, {type_id}> {{}};
// volatile &&
template<>
struct StaticInfo<{volatile_rref_type_id}>
    : StaticInfo_VolatileRRefWrap<{volatile_rref_type_id}, {type_id}> {{}};
// volatile const &
template<>
struct StaticInfo<{volatile_const_lref_type_id}>
    : StaticInfo_VolatileConstLRefWrap<{volatile_const_lref_type_id}, {type_id}> {{}};
// volatile *
template<>
struct StaticInfo<{volatile_ptr_type_id}>
    : StaticInfo_VolatilePtrWrap<{volatile_ptr_type_id}, {type_id}> {{}};
// volatile const *
template<>
struct StaticInfo<{volatile_const_ptr_type_id}>
    : StaticInfo_VolatileConstPtrWrap<{volatile_const_ptr_type_id}, {type_id}> {{}};
)fmt";


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


    constexpr auto StaticTypeInfo_MemberVariable = R"fmt(
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID VariableID = {id};
    constexpr static ID Id = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = speculo::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

    constexpr static bool IsPublic = {is_public};
    constexpr static bool IsProtected = {is_protected};
    constexpr static bool IsPrivate = {is_private};
    constexpr static bool IsMutable = {is_mutable};
    constexpr static bool IsBitfield = {is_bitfield};
    constexpr static std::size_t Offset = {offset};
    constexpr static std::size_t Size = {size};
    {bitfield_block}

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    {member_ptr_block}
    }};
)fmt";


    constexpr auto StaticTypeInfo_BitfieldAccessor = R"fmt(
    template<bool IsConst>
    struct BitfieldAccessor {{
        using Parent = std::conditional_t<IsConst, const {parent_type}, {parent_type}>;
        constexpr explicit BitfieldAccessor(Parent *p) : parent{{p}} {{}}
        constexpr auto &operator=(int rhs) requires (!IsConst) {{
            parent->{bitfield_name} = rhs;
            return *this;
        }}
        constexpr explicit(false) operator int() const {{
            return parent->{bitfield_name};
        }}
    private:
        Parent *parent;
    }};

    constexpr static BitfieldAccessor<false> CreateBitfieldAccessor({parent_type} *self) {{
        return BitfieldAccessor<false>{{self}};
    }}
    constexpr static BitfieldAccessor<true> CreateBitfieldAccessor(const {parent_type} *self) {{
        return BitfieldAccessor<true>{{self}};
    }}
)fmt";


    constexpr auto StaticTypeInfo_MemberFunction = R"fmt(
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID FunctionID = {id};
    constexpr static ID Id = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = speculo::make_array<Attribute>({attributes});

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
    constexpr static bool IsNothrow = {is_nothrow};

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static Info ReturnType = {return_type_id};
    constexpr static RangeOf<Info> auto Arguments = speculo::make_array<Info>({arguments});

    constexpr static {member_type} {const_qualifier} = &{member};
    }};
)fmt";

    constexpr auto StaticTypeInfo_ConstevalMemberFunction = R"fmt(
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID FunctionID = {id};
    constexpr static ID Id = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = speculo::make_array<Attribute>({attributes});

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
    constexpr static bool IsNothrow = {is_nothrow};

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static Info ReturnType = {return_type_id};
    constexpr static RangeOf<Info> auto Arguments = speculo::make_array<Info>({arguments});

    constexpr static auto ConstevalWrap = {consteval_wrap};
    }};
)fmt";


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


    constexpr auto StaticTypeInfo_Constructor = R"fmt(
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID ConstructorID = {id};
    constexpr static ID Id = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = speculo::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

    constexpr static bool IsPublic = {is_public};
    constexpr static bool IsProtected = {is_protected};
    constexpr static bool IsPrivate = {is_private};
    constexpr static bool IsExplicit = {is_explicit};
    constexpr static bool IsCopy = {is_copy};
    constexpr static bool IsMove = {is_move};
    constexpr static bool IsConstexpr = {is_constexpr};
    constexpr static bool IsConsteval = {is_consteval};
    constexpr static bool IsInline = {is_inline};
    constexpr static bool IsInlineSpecified = {is_inline_specified};
    constexpr static bool IsNothrow = {is_nothrow};

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static RangeOf<Info> auto Arguments = speculo::make_array<Info>({arguments});

    {ctor_wraps}
    }};
)fmt";


    constexpr auto StaticTypeInfo_Base = R"fmt(
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID BaseID = {id};
    constexpr static ID Id = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static auto StaticInfoObjectType = StaticInfoType::Base;

    constexpr static bool IsPublic = {is_public};
    constexpr static bool IsProtected = {is_protected};
    constexpr static bool IsPrivate = {is_private};
    constexpr static auto IsVirtual = {is_virtual};
    constexpr static std::size_t Offset = {offset};
    constexpr static std::size_t Size = {size};

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};
    }};
)fmt";


    constexpr auto StaticTypeInfo_Argument = R"fmt(
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID ArgumentID = {id};
    constexpr static ID Id = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = speculo::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};
    }};
)fmt";


    constexpr auto GetConstantID = R"fmt(
template<>
[[nodiscard]] consteval ID getConstantId<{constant}>() {{
return {value_id};
}}
)fmt";


    constexpr auto GetTypeID = R"fmt(
template<>
[[nodiscard]] consteval ID getTypeId<{type}>() {{
    return {type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<const {type}>() {{
    return {const_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<{type} &>() {{
    return {lref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<{type} &&>() {{
    return {rref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<const {type} &>() {{
    return {const_lref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<{type} *>() {{
    return {ptr_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<const {type} *>() {{
    return {const_ptr_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<volatile {type}>() {{
    return {volatile_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<volatile const {type}>() {{
    return {volatile_const_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<volatile {type} &>() {{
    return {volatile_lref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<volatile {type} &&>() {{
    return {volatile_rref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<volatile const {type} &>() {{
    return {volatile_const_lref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<volatile {type} *>() {{
    return {volatile_ptr_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<volatile const {type} *>() {{
    return {volatile_const_ptr_type_id};
}}
)fmt";


    constexpr auto MetaFilePrologue = R"fmt(
#pragma once

#include "{relative_include_path}"
import speculo;
#include <cstdint>
#include <cstddef>
#include <string_view>
#include <span>
#include <array>

namespace speculo::details {{
)fmt";
    constexpr auto MetaFileEpilogue = R"fmt(
}
)fmt";

}
