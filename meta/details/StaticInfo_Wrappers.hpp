//
// Created by xflajs00 on 15.03.2023.
//

#ifndef PF_META_DETAILS_STATICINFO_WRAPPERS_H
#define PF_META_DETAILS_STATICINFO_WRAPPERS_H

#include "ID.hpp"
#include "StaticInfo.hpp"

namespace pf::meta::details {
    template<ID I, ID ParentID>
    struct StaticInfo_ConstWrap : details::StaticInfo<ParentID> {
        using Type = const typename details::StaticInfo<ParentID>::Type;
        constexpr static ID TypeID = I;
        constexpr static bool IsConst = true;
        constexpr static auto Name = StringLiteral{"const "} + details::StaticInfo<ParentID>::Name;
        constexpr static auto FullName = StringLiteral{"const "} + details::StaticInfo<ParentID>::FullName;
    };
    template<ID I, ID ParentID>
    struct StaticInfo_LRefWrap : details::StaticInfo<ParentID> {
        using Type = typename details::StaticInfo<ParentID>::Type &;
        constexpr static ID TypeID = I;
        constexpr static bool IsLvalueReference = true;
        constexpr static auto Name = details::StaticInfo<ParentID>::Name + StringLiteral{" &"};
        constexpr static auto FullName = details::StaticInfo<ParentID>::FullName + StringLiteral{" &"};
    };
    template<ID I, ID ParentID>
    struct StaticInfo_ConstLRefWrap : details::StaticInfo<ParentID> {
        using Type = const typename details::StaticInfo<ParentID>::Type &;
        constexpr static ID TypeID = I;
        constexpr static bool IsLvalueReference = true;
        constexpr static bool IsConst = true;
        constexpr static auto Name = StringLiteral{"const "} + details::StaticInfo<ParentID>::Name + StringLiteral{" &"};
        constexpr static auto FullName = StringLiteral{"const "} + details::StaticInfo<ParentID>::FullName + StringLiteral{" &"};
    };
    template<ID I, ID ParentID>
    struct StaticInfo_RRefWrap : details::StaticInfo<ParentID> {
        using Type = typename details::StaticInfo<ParentID>::Type &&;
        constexpr static ID TypeID = I;
        constexpr static bool IsRvalueReference = true;
        constexpr static auto Name = details::StaticInfo<ParentID>::Name + StringLiteral{" &&"};
        constexpr static auto FullName = details::StaticInfo<ParentID>::FullName + StringLiteral{" &&"};
    };
    template<ID I, ID ParentID>
    struct StaticInfo_PtrWrap : details::StaticInfo<ParentID> {
        using Type = typename details::StaticInfo<ParentID>::Type *;
        constexpr static ID TypeID = I;
        constexpr static bool IsPtr = true;
        constexpr static auto Name = details::StaticInfo<ParentID>::Name + StringLiteral{" *"};
        constexpr static auto FullName = details::StaticInfo<ParentID>::FullName + StringLiteral{" *"};
    };
    template<ID I, ID ParentID>
    struct StaticInfo_ConstPtrWrap : details::StaticInfo<ParentID> {
        using Type = const typename details::StaticInfo<ParentID>::Type *;
        constexpr static ID TypeID = I;
        constexpr static bool IsPtr = true;
        constexpr static bool IsConst = true;
        constexpr static auto Name = StringLiteral{"const "} + details::StaticInfo<ParentID>::Name + StringLiteral{" *"};
        constexpr static auto FullName = StringLiteral{"const "} + details::StaticInfo<ParentID>::FullName + StringLiteral{" *"};
    };
}// namespace pf::meta::details

#endif//PF_META_DETAILS_STATICINFO_WRAPPERS_H
