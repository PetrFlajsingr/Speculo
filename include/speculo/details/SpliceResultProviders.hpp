/**
 * @file SpliceResultProviders.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <speculo/ID.hpp>
#include <speculo/Info.hpp>
#include <speculo/details/StaticInfo.hpp>
#include <speculo/details/meta_helpers.hpp>


namespace speculo::details {
    template<Info I>
    using splice_type = typename StaticInfo<I.id>::Type;

    template<Info I>
    consteval auto splice_value() {
        return StaticInfo<I.id>::Value;
    }

    template<Info I>
    consteval auto splice_member() {
        return StaticInfo<I.id>::MemberPtr;
    }

    template<Info I>
    consteval auto splice_ctor() {
        return StaticInfo<I.id>::CtorWrap;
    }

    template<Info I>
    consteval speculo::details::StaticInfoType getInfoType() {
        return speculo::details::StaticInfo<I.id>::StaticInfoObjectType;
    }

    template<Info I>
    struct SpliceResultProvider {
        static_assert(AlwaysFalseV<I>, "Not implemented or splice not supported for this meta type");
    };

    template<Info I>
        requires(getInfoType<I>() == speculo::details::StaticInfoType::EnumValue)
    struct SpliceResultProvider<I> {
        constexpr static auto Result = splice_value<I>();
    };
    template<Info I>
        requires(getInfoType<I>() == speculo::details::StaticInfoType::EnumType ||
                 getInfoType<I>() == speculo::details::StaticInfoType::FundamentalType ||
                 getInfoType<I>() == speculo::details::StaticInfoType::RecordType)
    struct SpliceResultProvider<I> {
        using Result = splice_type<I>;
    };

    template<Info I>
        requires(getInfoType<I>() == speculo::details::StaticInfoType::MemberFunction ||
                 getInfoType<I>() == speculo::details::StaticInfoType::MemberVariable ||
                 getInfoType<I>() == speculo::details::StaticInfoType::StaticFunction ||
                 getInfoType<I>() == speculo::details::StaticInfoType::StaticVariable)
    struct SpliceResultProvider<I> {
        constexpr static auto Result = splice_member<I>();
    };

    template<Info I>
        requires(getInfoType<I>() == speculo::details::StaticInfoType::Constructor)
    struct SpliceResultProvider<I> {
        constexpr static auto Result = splice_ctor<I>();
    };


}// namespace speculo::details