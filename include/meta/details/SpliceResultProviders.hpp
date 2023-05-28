/**
 * @file SpliceResultProviders.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include "Info.hpp"
#include "details/ID.hpp"
#include "details/StaticInfo.hpp"


#define PF_SPLICE_TYPE(I) ::pf::meta::details::StaticInfo<I.implId>::Type

#define PF_SPLICE_VALUE(I)                                                                                                                 \
    []<::pf::meta::Info i>() consteval {                                                                                                   \
        using impl = ::pf::meta::details::StaticInfo<i.implId>;                                                                            \
        return impl::Value;                                                                                                                \
    }.template operator()<I>()

#define PF_SPLICE_MEMBER(I)                                                                                                                \
    []<::pf::meta::Info i>() consteval {                                                                                                   \
        using impl = ::pf::meta::details::StaticInfo<i.implId>;                                                                            \
        return impl::MemberPtr;                                                                                                            \
    }.template operator()<I>()

#define PF_SPLICE_CTOR(I)                                                                                                                  \
    []<::pf::meta::Info i>() consteval {                                                                                                   \
        using impl = ::pf::meta::details::StaticInfo<i.implId>;                                                                            \
        return impl::CtorWrap;                                                                                                             \
    }.template operator()<I>()

namespace pf::meta::details {


    template<pf::meta::Info I>
    consteval pf::meta::details::StaticInfoType getInfoType() {
        return pf::meta::details::StaticInfo<I.implId>::StaticInfoObjectType;
    }

    template<pf::meta::Info I>
    struct SpliceResultProvider {
        static_assert(sizeof(I) == 0, "Not implemented or splice not supported for this meta type");
    };

    template<pf::meta::Info I>
        requires(getInfoType<I.implId>() == pf::meta::details::StaticInfoType::EnumValue)
    struct SpliceResultProvider<I> {
        constexpr static auto Result = PF_SPLICE_VALUE(I);
    };
    template<pf::meta::Info I>
        requires(getInfoType<I.implId>() == pf::meta::details::StaticInfoType::EnumType ||
                 getInfoType<I.implId>() == pf::meta::details::StaticInfoType::FundamentalType ||
                 getInfoType<I.implId>() == pf::meta::details::StaticInfoType::RecordType)
    struct SpliceResultProvider<I> {
        using Result = typename PF_SPLICE_TYPE(I);
    };

    template<pf::meta::Info I>
        requires(getInfoType<I.implId>() == pf::meta::details::StaticInfoType::MemberFunction ||
                 getInfoType<I.implId>() == pf::meta::details::StaticInfoType::MemberVariable ||
                 getInfoType<I.implId>() == pf::meta::details::StaticInfoType::StaticFunction ||
                 getInfoType<I.implId>() == pf::meta::details::StaticInfoType::StaticVariable)
    struct SpliceResultProvider<I> {
        constexpr static auto Result = PF_SPLICE_MEMBER(I);
    };

    template<pf::meta::Info I>
        requires(getInfoType<I.implId>() == pf::meta::details::StaticInfoType::Constructor)
    struct SpliceResultProvider<I> {
        constexpr static auto Result = PF_SPLICE_CTOR(I);
    };


}// namespace pf::meta::details