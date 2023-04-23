/**
 * @file meta.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include "Info.h"

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
        return MemberFunction<I> || StaticFunction<I>;
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
            result[i] = Impl::MemberVariables[i] - Impl::MemberFunctions.size();
        }
        return result;
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
    // TODO is_declared_class
    // TODO is_declared_struct

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
    // TODO is_bit_field
    template<Info I>
    requires MemberVariable<I>
    [[nodiscard]] consteval bool is_mutable() {
        using Impl = details::StaticInfo<I.implId>;
        return Impl::IsMutable;
    }



}// namespace pf::meta