/**
 * @file SpliceResultProviders.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <meta/ID.hpp>
#include <meta/Info.hpp>
#include <meta/details/StaticInfo.hpp>
#include <meta/details/meta_helpers.hpp>


#define PF_SPLICE_TYPE(I) ::pf::meta::details::StaticInfo<I.id>::Type

#define PF_SPLICE_VALUE(I)                                                                                                                 \
    []<::pf::meta::Info i>() consteval {                                                                                                   \
        using impl = ::pf::meta::details::StaticInfo<i.id>;                                                                            \
        return impl::Value;                                                                                                                \
    }.template operator()<I>()

#define PF_SPLICE_MEMBER(I)                                                                                                                \
    []<::pf::meta::Info i>() consteval {                                                                                                   \
        using impl = ::pf::meta::details::StaticInfo<i.id>;                                                                            \
        return impl::MemberPtr;                                                                                                            \
    }.template operator()<I>()

#define PF_SPLICE_CTOR(I)                                                                                                                  \
    []<::pf::meta::Info i>() consteval {                                                                                                   \
        using impl = ::pf::meta::details::StaticInfo<i.id>;                                                                            \
        return impl::CtorWrap;                                                                                                             \
    }.template operator()<I>()

namespace pf::meta::details {


    template<pf::meta::Info I>
    consteval pf::meta::details::StaticInfoType getInfoType() {
        return pf::meta::details::StaticInfo<I.id>::StaticInfoObjectType;
    }

    template<pf::meta::Info I>
    struct SpliceResultProvider {
        static_assert(AlwaysFalseV<I>, "Not implemented or splice not supported for this meta type");
    };

    template<pf::meta::Info I>
        requires(getInfoType<I.id>() == pf::meta::details::StaticInfoType::EnumValue)
    struct SpliceResultProvider<I> {
        constexpr static auto Result = PF_SPLICE_VALUE(I);
    };
    template<pf::meta::Info I>
        requires(getInfoType<I.id>() == pf::meta::details::StaticInfoType::EnumType ||
                 getInfoType<I.id>() == pf::meta::details::StaticInfoType::FundamentalType ||
                 getInfoType<I.id>() == pf::meta::details::StaticInfoType::RecordType)
    struct SpliceResultProvider<I> {
        using Result = typename PF_SPLICE_TYPE(I);
    };

    template<pf::meta::Info I>
        requires(getInfoType<I.id>() == pf::meta::details::StaticInfoType::MemberFunction ||
                 getInfoType<I.id>() == pf::meta::details::StaticInfoType::MemberVariable ||
                 getInfoType<I.id>() == pf::meta::details::StaticInfoType::StaticFunction ||
                 getInfoType<I.id>() == pf::meta::details::StaticInfoType::StaticVariable)
    struct SpliceResultProvider<I> {
        constexpr static auto Result = PF_SPLICE_MEMBER(I);
    };

    template<pf::meta::Info I>
        requires(getInfoType<I.id>() == pf::meta::details::StaticInfoType::Constructor)
    struct SpliceResultProvider<I> {
        constexpr static auto Result = PF_SPLICE_CTOR(I);
    };


}// namespace pf::meta::details