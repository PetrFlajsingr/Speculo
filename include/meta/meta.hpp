/**
 * @file meta.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include "Info.hpp"
#include "details/RangeOf.hpp"
#include "template_for.hpp"

#include <concepts>
#include <optional>

namespace pf::meta {
    template<Info I>
    concept Enum = details::StaticInfo<I.implId>::StaticInfoObjectType == details::StaticInfoType::EnumType;
    template<Info I>
    concept Enumerator = details::StaticInfo<I.implId>::StaticInfoObjectType == details::StaticInfoType::EnumValue;
    template<Info I>
    concept Record = details::StaticInfo<I.implId>::StaticInfoObjectType == details::StaticInfoType::RecordType;
    template<Info I>
    concept Base = details::StaticInfo<I.implId>::StaticInfoObjectType == details::StaticInfoType::Base;
    template<Info I>
    concept Constructor = details::StaticInfo<I.implId>::StaticInfoObjectType == details::StaticInfoType::Constructor;
    template<Info I>
    concept Destructor = details::StaticInfo<I.implId>::StaticInfoObjectType == details::StaticInfoType::Destructor;
    template<Info I>
    concept MemberFunction = details::StaticInfo<I.implId>::StaticInfoObjectType == details::StaticInfoType::MemberFunction;
    template<Info I>
    concept MemberVariable = details::StaticInfo<I.implId>::StaticInfoObjectType == details::StaticInfoType::MemberVariable;
    template<Info I>
    concept StaticFunction = details::StaticInfo<I.implId>::StaticInfoObjectType == details::StaticInfoType::StaticFunction;
    template<Info I>
    concept StaticVariable = details::StaticInfo<I.implId>::StaticInfoObjectType == details::StaticInfoType::StaticVariable;
    template<Info I>
    concept Argument = details::StaticInfo<I.implId>::StaticInfoObjectType == details::StaticInfoType::Argument;
    template<Info I>
    concept FundamentalType = details::StaticInfo<I.implId>::StaticInfoObjectType == details::StaticInfoType::FundamentalType;
    template<Info I>
    concept Member = MemberFunction<I> || MemberVariable<I> || StaticFunction<I> || StaticVariable<I> || Constructor<I> || Destructor<I>;
    template<Info I>
    concept Type = Enum<I> || Record<I> || FundamentalType<I>;
    template<Info I>
    concept Function = MemberFunction<I> || StaticFunction<I>;
    template<Info I>
    concept Named = Type<I> || Enumerator<I> || Member<I> || Argument<I>;

    template<Info I>
    [[nodiscard]] consteval bool is_invalid() {
        return !I.implId.isValid();
    }
    // is_local
    template<Info I>
    [[nodiscard]] consteval bool is_class_member() {
        // TODO: applies to static as well?
        return MemberFunction<I> || MemberVariable<I>;
    }
    template<Info I>
    [[nodiscard]] consteval bool is_variable() {
        return MemberVariable<I> || StaticVariable<I>;
    }
    // has_static_storage_duration
    // has_thread_local_storage_duration
    // has_automatic_storage_duration
    template<Info I>
    [[nodiscard]] consteval bool is_function() {
        return Function<I>;
    }
    // is_nothrow
    // has_ellipsis
    template<Info I>
        requires Record<I>
    [[nodiscard]] consteval details::RangeOf<Info> auto members_of() {
        using Impl = details::StaticInfo<I.implId>;
        std::array<Info, Impl::MemberFunctions.size() + Impl::MemberVariables.size()> result;
        std::size_t i{};
        for (; i < Impl::MemberFunctions.size(); ++i) { result[i] = Impl::MemberFunctions[i]; }
        for (; i < Impl::MemberFunctions.size() + Impl::MemberVariables.size(); ++i) {
            result[i] = Impl::MemberVariables[i - Impl::MemberFunctions.size()];
        }
        return result;
    }
    template<Info I>
        requires Enum<I>
    [[nodiscard]] consteval details::RangeOf<Info> auto members_of() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::EnumValues;
    }
    template<Info I>
        requires Record<I>
    [[nodiscard]] consteval details::RangeOf<Info> auto bases_of() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::Bases;
    }
    template<Info I>
    [[nodiscard]] consteval bool is_class() {
        if constexpr (Record<I>) {
            return !details::StaticInfo<I.implId>::IsUnion;
        } else {
            return false;
        }
    }
    template<Info I>
    [[nodiscard]] consteval bool is_union() {
        if constexpr (Record<I>) {
            return details::StaticInfo<I.implId>::IsUnion;
        } else {
            return false;
        }
    }
    template<Info I>
        requires Record<I>
    [[nodiscard]] consteval bool has_virtual_destructor() {
        using Impl = details::StaticInfo<I.implId>;
        using DtorImpl = details::StaticInfo<Impl::Destructor>;
        return DtorImpl::IsVirtual;
    }
    template<Info I>
        requires Record<I>
    [[nodiscard]] consteval bool is_declared_class() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsClass;
    }
    template<Info I>
        requires Record<I>
    [[nodiscard]] consteval bool is_declared_struct() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsStruct;
    }

    template<Info I>
    [[nodiscard]] consteval bool is_data_member() {
        return MemberVariable<I> || StaticVariable<I>;
    }
    template<Info I>
    [[nodiscard]] consteval bool is_static_data_member() {
        return StaticVariable<I>;
    }
    template<Info I>
    [[nodiscard]] consteval bool is_nonstatic_data_member() {
        return MemberVariable<I>;
    }
    template<Info I>
        requires MemberVariable<I>
    [[nodiscard]] consteval bool is_bit_field() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsBitfield;
    }
    template<Info I>
        requires MemberVariable<I>
    [[nodiscard]] consteval bool is_mutable() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsMutable;
    }
    template<Info I>
    [[nodiscard]] consteval bool is_member_function() {
        return MemberFunction<I> || StaticFunction<I>;
    }
    template<Info I>
    [[nodiscard]] consteval bool is_static_member_function() {
        return StaticFunction<I>;
    }
    template<Info I>
    [[nodiscard]] consteval bool is_nonstatic_member_function() {
        return MemberFunction<I>;
    }
    // TODO is_normal
    // TODO is_conversion
    // TODO is_override
    // TODO is_override_specified
    // TODO is_deleted
    template<Info I>
        requires MemberFunction<I>
    [[nodiscard]] consteval bool is_virtual() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsVirtual;
    }
    template<Info I>
        requires MemberFunction<I>
    [[nodiscard]] consteval bool is_pure_virtual() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsPureVirtual;
    }
    template<Info I>
    [[nodiscard]] consteval bool is_constructor() {
        return Constructor<I>;
    }
    // TODO is_default_constructor
    template<Info I>
    [[nodiscard]] consteval bool is_copy_constructor() {
        if constexpr (Constructor<I>) {
            using Impl = details::StaticInfo<I.implId>;
            return Impl::IsCopy;
        }
        return false;
    }
    template<Info I>
    [[nodiscard]] consteval bool is_move_constructor() {
        if constexpr (Constructor<I>) {
            using Impl = details::StaticInfo<I.implId>;
            return Impl::IsMove;
        }
        return false;
    }
    // TODO is_copy_assignment_operator
    // TODO is_move_assignment_operator
    // TODO is_copy
    // TODO is_move
    template<Info I>
    [[nodiscard]] consteval bool is_destructor() {
        return Destructor<I>;
    }
    // TODO is_defaulted
    // TODO is_explicit
    // TODO has_access - probably unsupported
    template<Info I>
        requires(Member<I> || Base<I>)
    [[nodiscard]] consteval bool is_public() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsPublic;
    }
    template<Info I>
        requires(Member<I> || Base<I>)
    [[nodiscard]] consteval bool is_protected() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsProtected;
    }
    template<Info I>
        requires(Member<I> || Base<I>)
    [[nodiscard]] consteval bool is_private() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsPrivate;
    }
    // TODO has_default_access
    // TODO has_linkage
    // TODO is_externally_linked
    // TODO is_internally_linked
    // TODO is_extern_specified
    template<Info I>
        requires MemberFunction<I> || Constructor<I> || Destructor<I> || StaticFunction<I> || StaticVariable<I>
    [[nodiscard]] consteval bool is_inline() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsInline;
    }
    template<Info I>
        requires MemberFunction<I> || Constructor<I> || Destructor<I> || StaticFunction<I> || StaticVariable<I>
    [[nodiscard]] consteval bool is_inline_specified() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsInlineSpecified;
    }
    template<Info I>
        requires MemberFunction<I> || Constructor<I> || Destructor<I> || StaticFunction<I> || StaticVariable<I> || MemberVariable<I>
    [[nodiscard]] consteval bool is_constexpr() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsConstexpr;
    }
    template<Info I>
        requires MemberFunction<I> || Constructor<I> || Destructor<I> || StaticFunction<I> || StaticVariable<I> || MemberVariable<I>
    [[nodiscard]] consteval bool is_consteval() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsConsteval;
    }
    template<Info I>
        requires MemberFunction<I> || Destructor<I> || Record<I>
    [[nodiscard]] consteval bool is_final() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsFinal;
    }
    // TODO is_defined - unsupported
    // TODO is_complete - unsupported
    // TODO is_namespace - probably unsupported
    template<Info I>
    [[nodiscard]] consteval bool is_enum() {
        return Enum<I>;
    }
    template<Info I>
    [[nodiscard]] consteval bool is_unscoped_enum() {
        if constexpr (Enum<I>) {
            using Impl = details::StaticInfo<I.implId>;
            return !Impl::IsScoped;
        }
        return false;
    }
    template<Info I>
    [[nodiscard]] consteval bool is_scoped_enum() {
        if constexpr (Enum<I>) {
            using Impl = details::StaticInfo<I.implId>;
            return Impl::IsScoped;
        }
        return false;
    }
    template<Info I>
    [[nodiscard]] consteval bool is_enumerator() {
        return Enumerator<I>;
    }
    // TODO is_template
    // TODO is_class_template
    // TODO is_function_template
    // TODO is_variable_template
    // TODO is_member_function_template
    // TODO is_static_member_function_template
    // TODO is_nonstatic_member_function_template
    // TODO is_constructor_template
    // TODO is_destructor_template
    // TODO is_concept - almost surely unsupported
    // TODO is_specialization
    // TODO is_partial_specialization
    // TODO is_explicit_specialization
    // TODO is_explicit_instantiation
    template<Info I>
    [[nodiscard]] consteval bool is_base_class() {
        return Base<I>;
    }
    template<Info I>
    [[nodiscard]] consteval bool is_direct_base_class() {
        return Base<I>;
    }
    template<Info I>
    [[nodiscard]] consteval bool is_virtual_base_class() {
        if constexpr (Base<I>) {
            using Impl = details::StaticInfo<I.implId>;
            return Impl::IsVirtual;
        }
        return false;
    }
    template<Info I>
    [[nodiscard]] consteval bool is_function_parameter() {
        return Argument<I>;
    }
    // TODO is_template_parameter
    // TODO is_type_template_parameter
    // TODO is_nontype_template_parameter
    // TODO is_template_template_parameter
    // TODO has_default_argument
    template<Info I>
        requires Function<I>
    [[nodiscard]] consteval details::RangeOf<Info> auto is_function_parameter() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::Arguments;
    }
    template<Info I>
    [[nodiscard]] consteval bool is_type() {
        return Type<I>;
    }
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_fundamental_type() {
        return FundamentalType<I>;
    }
    // TODO is_arithmetic_type
    // TODO is_scalar_type
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_object_type() {
        return Record<I>;
    }
    // TODO is_compound_type
    // TODO is_function_type
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_class_type() {
        if constexpr (Record<I>) {
            using Impl = details::StaticInfo<I.implId>;
            return !Impl::IsUnion;
        }
        return false;
    }
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_union_type() {
        if constexpr (Record<I>) {
            using Impl = details::StaticInfo<I.implId>;
            return Impl::IsUnion;
        }
        return false;
    }
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_enum_type() {
        return Enum<I>;
    }
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_unscoped_enum_type() {
        if constexpr (Enum<I>) {
            using Impl = details::StaticInfo<I.implId>;
            return !Impl::IsScoped;
        }
        return false;
    }
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_scoped_enum_type() {
        if constexpr (Enum<I>) {
            using Impl = details::StaticInfo<I.implId>;
            return Impl::IsScoped;
        }
        return false;
    }
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_void_type() {
        using Impl = details::StaticInfo<I.implId>;
        return std::same_as<typename Impl::Type, void>;
    }
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_null_pointer_type() {
        using Impl = details::StaticInfo<I.implId>;
        return std::same_as<typename Impl::Type, std::nullptr_t>;
    }
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_integral_type() {
        using Impl = details::StaticInfo<I.implId>;
        return std::is_integral_v<typename Impl::Type>;
    }
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_floating_point_type() {
        using Impl = details::StaticInfo<I.implId>;
        return std::is_floating_point_v<typename Impl::Type>;
    }
    // TODO is_array_type
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_pointer_type() {
        using Impl = details::StaticInfo<I.implId>;
        return std::is_pointer_v<typename Impl::Type>;
    }
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_reference_type() {
        using Impl = details::StaticInfo<I.implId>;
        return std::is_reference_v<typename Impl::Type>;
    }
    // TODO is_lvalue_reference_type
    // TODO is_rvalue_reference_type
    // TODO is_member_pointer_type
    // TODO is_member_object_pointer_type
    // TODO is_member_function_pointer_type
    // TODO is_incomplete_type - unsupported for sure
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_const_type() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsConst;
    }
    // TODO is_volatile_type
    // TODO is_trivial_type
    // TODO is_trivially_copyable_type
    // TODO is_standard_layout_type
    // TODO is_pod_type
    // TODO is_literal_type
    // TODO is_empty_type
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_polymorphic_type() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsPolymorphic;
    }
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_abstract_type() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsAbstract;
    }
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval bool is_final_type() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsFinal;
    }
    // TODO is_aggregate_type
    // TODO is_signed_type
    // TODO is_unsigned_type
    // TODO has_unique_object_representations
    // TODO size_of
    // TODO byte_size_of
    // TODO bit_size_of
    // TODO byte_offset_of
    // TODO bit_offset_of
    // TODO alignment_of
    // TODO rank
    // TODO extent
    // TODO is_constructible(info, arguments)
    // TODO is_trivially_constructible(info, arguments)
    // TODO is_nothrow_constructible(info, arguments)
    // TODO is_default_constructible_type
    // TODO is_trivially_default_constructible_type
    // TODO is_nothrow_default_constructible_type
    // TODO is_copy_constructible_type
    // TODO is_trivially_copy_constructible_type
    // TODO is_nothrow_copy_constructible_type
    // TODO is_move_constructible_type
    // TODO is_trivially_move_constructible_type
    // TODO is_nothrow_move_constructible_type
    // TODO is_assignable_type
    // TODO is_trivially_assignable_type
    // TODO is_nothrow_assignable_type
    // TODO is_copy_assignable_type
    // TODO is_trivially_copy_assignable_type
    // TODO is_nothrow_copy_assignable_type
    // TODO is_move_assignable_type
    // TODO is_trivially_move_assignable_type
    // TODO is_nothrow_move_assignable_type
    // TODO is_destructible_type
    // TODO is_trivially_destructible_type
    // TODO is_nothrow_destructible_type
    // TODO is_swappable
    // TODO is_nothrow_swappable
    // TODO is_swappable_with
    // TODO is_nothrow_swappable_with
    // captures are not supported
    template<Info I1, Info I2>
    [[nodiscard]] consteval bool is_same() {
        return I1.implId == I2.implId;
    }

    template<Info Base, Info Derived>
        requires Record<Base> && Record<Derived>
    [[nodiscard]] consteval bool is_base_of() {
        using ImplBase = details::StaticInfo<Base.implId>;
        using ImplDerived = details::StaticInfo<Derived.implId>;
        return std::derived_from<typename ImplDerived::Type, typename ImplBase::Type>;
    }
    template<Info From, Info To>
        requires Type<From> && Type<To>
    [[nodiscard]] consteval bool is_convertible() {
        using ImplFrom = details::StaticInfo<From.implId>;
        using ImplTo = details::StaticInfo<To.implId>;
        return std::convertible_to<typename ImplFrom::Type, typename ImplTo::Type>;
    }
    // TODO is_nothrow_convertible
    // TODO is_invocable
    // TODO is_nothrow_invocable
    // TODO is_invocable_r
    // TODO is_nothrow_invocable_r
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval Info remove_const() {
        using Impl = details::StaticInfo<I.implId>;
        return getTypeId<std::remove_const_t<typename Impl::Type>>();
    }
    // TODO remove_volatile
    // TODO remove_cv
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval Info add_const() {
        using Impl = details::StaticInfo<I.implId>;
        return getTypeId<std::add_const_t<typename Impl::Type>>();
    }
    // TODO add_volatile
    // TODO add_cv
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval Info remove_reference() {
        using Impl = details::StaticInfo<I.implId>;
        return getTypeId<std::remove_reference_t<typename Impl::Type>>();
    }
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval Info add_lvalue_reference() {
        using Impl = details::StaticInfo<I.implId>;
        return getTypeId<std::add_lvalue_reference_t<typename Impl::Type>>();
    }
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval Info add_rvalue_reference() {
        using Impl = details::StaticInfo<I.implId>;
        return getTypeId<std::add_rvalue_reference_t<typename Impl::Type>>();
    }
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval Info remove_pointer() {
        using Impl = details::StaticInfo<I.implId>;
        return getTypeId<std::remove_pointer_t<typename Impl::Type>>();
    }
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval Info add_pointer() {
        using Impl = details::StaticInfo<I.implId>;
        return getTypeId<std::add_pointer_t<typename Impl::Type>>();
    }
    // TODO remove_cvref
    template<Info I>
        requires Type<I>
    [[nodiscard]] consteval Info decay() {
        using Impl = details::StaticInfo<I.implId>;
        return getTypeId<std::decay_t<typename Impl::Type>>();
    }
    // TODO make_signed
    // TODO make_unsigned
    template<Info I>
        requires MemberFunction<I>
    consteval Info this_ref_type_of() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::TypeID;
    }
    // TODO common_type
    template<Info I>
        requires Enum<I>
    consteval Info underlying_type_of() {
        using Impl = details::StaticInfo<I.implId>;
        return details::getTypeId<Impl::UnderlyingType>();
    }
    // TODO invoke_result
    template<Info I>
    [[nodiscard]] consteval bool is_named() {
        return Named<I>;
    }
    template<Info I>
        requires Named<I>// TODO: decide which name to actually return here
    [[nodiscard]] consteval std::string_view name_of() {
        using Impl = details::StaticInfo<I.implId>;
        return static_cast<std::string_view>(Impl::Name);
    }
    template<Info I>
        requires Named<I>// TODO: decide which name to actually return here
    [[nodiscard]] consteval std::string_view display_name_of() {
        using Impl = details::StaticInfo<I.implId>;
        return static_cast<std::string_view>(Impl::FullName);
    }
    // expressions not supported


    /**************** EXTENSIONS *******************/
    template<Info I>
    [[nodiscard]] consteval std::span<const Attribute> attributes_of() {
        using impl = details::StaticInfo<I.implId>;
        if constexpr (requires {
                          { impl::Attributes } -> details::RangeOf<Attribute>;
                      }) {
            return std::span<const Attribute>(impl::Attributes);
        } else {
            return std::span<const Attribute>{};
        }
    }
    template<Info I>
        requires(is_bit_field<I>())
    [[nodiscard]] constexpr auto create_bit_field_accessor(auto parentPtr) {
        using impl = details::StaticInfo<I.implId>;
        return impl::CreateBitfieldAccessor(parentPtr);
    }

}// namespace pf::meta