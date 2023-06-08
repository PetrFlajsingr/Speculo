//
// Created by xflajs00 on 15.03.2023.
//

#pragma once

#include <meta/ID.hpp>
#include <meta/details/StaticInfo.hpp>

namespace pf::meta::details {
    // const T
    template<ID I, ID ParentID>
    struct StaticInfo_ConstWrap : details::StaticInfo<ParentID> {
        using Type = const typename details::StaticInfo<ParentID>::Type;
        constexpr static ID TypeID = I;
        constexpr static bool IsConst = true;
        constexpr static auto Name = StringLiteral{"const "} + details::StaticInfo<ParentID>::Name;
        constexpr static auto FullName = StringLiteral{"const "} + details::StaticInfo<ParentID>::FullName;
    };
    // T&
    template<ID I, ID ParentID>
    struct StaticInfo_LRefWrap : details::StaticInfo<ParentID> {
        using Type = typename details::StaticInfo<ParentID>::Type &;
        constexpr static ID TypeID = I;
        constexpr static bool IsLvalueReference = true;
        constexpr static auto Name = details::StaticInfo<ParentID>::Name + StringLiteral{" &"};
        constexpr static auto FullName = details::StaticInfo<ParentID>::FullName + StringLiteral{" &"};
    };
    // const T&
    template<ID I, ID ParentID>
    struct StaticInfo_ConstLRefWrap : details::StaticInfo<ParentID> {
        using Type = const typename details::StaticInfo<ParentID>::Type &;
        constexpr static ID TypeID = I;
        constexpr static bool IsLvalueReference = true;
        constexpr static bool IsConst = true;
        constexpr static auto Name = StringLiteral{"const "} + details::StaticInfo<ParentID>::Name + StringLiteral{" &"};
        constexpr static auto FullName = StringLiteral{"const "} + details::StaticInfo<ParentID>::FullName + StringLiteral{" &"};
    };
    // T &&
    template<ID I, ID ParentID>
    struct StaticInfo_RRefWrap : details::StaticInfo<ParentID> {
        using Type = typename details::StaticInfo<ParentID>::Type &&;
        constexpr static ID TypeID = I;
        constexpr static bool IsRvalueReference = true;
        constexpr static auto Name = details::StaticInfo<ParentID>::Name + StringLiteral{" &&"};
        constexpr static auto FullName = details::StaticInfo<ParentID>::FullName + StringLiteral{" &&"};
    };
    // T *
    template<ID I, ID ParentID>
    struct StaticInfo_PtrWrap : details::StaticInfo<ParentID> {
        using Type = typename details::StaticInfo<ParentID>::Type *;
        constexpr static ID TypeID = I;
        constexpr static bool IsPtr = true;
        constexpr static auto Name = details::StaticInfo<ParentID>::Name + StringLiteral{" *"};
        constexpr static auto FullName = details::StaticInfo<ParentID>::FullName + StringLiteral{" *"};
    };
    // const T *
    template<ID I, ID ParentID>
    struct StaticInfo_ConstPtrWrap : details::StaticInfo<ParentID> {
        using Type = const typename details::StaticInfo<ParentID>::Type *;
        constexpr static ID TypeID = I;
        constexpr static bool IsPtr = true;
        constexpr static bool IsConst = true;
        constexpr static auto Name = StringLiteral{"const "} + details::StaticInfo<ParentID>::Name + StringLiteral{" *"};
        constexpr static auto FullName = StringLiteral{"const "} + details::StaticInfo<ParentID>::FullName + StringLiteral{" *"};
    };
    // volatile T
    template<ID I, ID ParentID>
    struct StaticInfo_VolatileWrap : details::StaticInfo<ParentID> {
        using Type = volatile typename details::StaticInfo<ParentID>::Type;
        constexpr static ID TypeID = I;
        constexpr static bool IsVolatile = true;
        constexpr static auto Name = StringLiteral{"volatile "} + details::StaticInfo<ParentID>::Name;
        constexpr static auto FullName = StringLiteral{"volatile "} + details::StaticInfo<ParentID>::FullName;
    };
    // volatile const T
    template<ID I, ID ParentID>
    struct StaticInfo_VolatileConstWrap : details::StaticInfo<ParentID> {
        using Type = const typename details::StaticInfo<ParentID>::Type;
        constexpr static ID TypeID = I;
        constexpr static bool IsConst = true;
        constexpr static bool IsVolatile = true;
        constexpr static auto Name = StringLiteral{"volatile const "} + details::StaticInfo<ParentID>::Name;
        constexpr static auto FullName = StringLiteral{"volatile const "} + details::StaticInfo<ParentID>::FullName;
    };
    // volatile T&
    template<ID I, ID ParentID>
    struct StaticInfo_VolatileLRefWrap : details::StaticInfo<ParentID> {
        using Type = typename details::StaticInfo<ParentID>::Type &;
        constexpr static ID TypeID = I;
        constexpr static bool IsLvalueReference = true;
        constexpr static bool IsVolatile = true;
        constexpr static auto Name = StringLiteral{"volatile "} + details::StaticInfo<ParentID>::Name + StringLiteral{" &"};
        constexpr static auto FullName = StringLiteral{"volatile "} + details::StaticInfo<ParentID>::FullName + StringLiteral{" &"};
    };
    // volatile const T&
    template<ID I, ID ParentID>
    struct StaticInfo_VolatileConstLRefWrap : details::StaticInfo<ParentID> {
        using Type = const typename details::StaticInfo<ParentID>::Type &;
        constexpr static ID TypeID = I;
        constexpr static bool IsLvalueReference = true;
        constexpr static bool IsConst = true;
        constexpr static bool IsVolatile = true;
        constexpr static auto Name = StringLiteral{"volatile const "} + details::StaticInfo<ParentID>::Name + StringLiteral{" &"};
        constexpr static auto FullName = StringLiteral{"volatile const "} + details::StaticInfo<ParentID>::FullName + StringLiteral{" &"};
    };
    // volatile T &&
    template<ID I, ID ParentID>
    struct StaticInfo_VolatileRRefWrap : details::StaticInfo<ParentID> {
        using Type = typename details::StaticInfo<ParentID>::Type &&;
        constexpr static ID TypeID = I;
        constexpr static bool IsRvalueReference = true;
        constexpr static bool IsVolatile = true;
        constexpr static auto Name = StringLiteral{"volatile "} + details::StaticInfo<ParentID>::Name + StringLiteral{" &&"};
        constexpr static auto FullName = StringLiteral{"volatile "} + details::StaticInfo<ParentID>::FullName + StringLiteral{" &&"};
    };
    // volatile T *
    template<ID I, ID ParentID>
    struct StaticInfo_VolatilePtrWrap : details::StaticInfo<ParentID> {
        using Type = typename details::StaticInfo<ParentID>::Type *;
        constexpr static ID TypeID = I;
        constexpr static bool IsPtr = true;
        constexpr static bool IsVolatile = true;
        constexpr static auto Name = StringLiteral{"volatile "} + details::StaticInfo<ParentID>::Name + StringLiteral{" *"};
        constexpr static auto FullName = StringLiteral{"volatile "} + details::StaticInfo<ParentID>::FullName + StringLiteral{" *"};
    };
    // volatile const T *
    template<ID I, ID ParentID>
    struct StaticInfo_VolatileConstPtrWrap : details::StaticInfo<ParentID> {
        using Type = const typename details::StaticInfo<ParentID>::Type *;
        constexpr static ID TypeID = I;
        constexpr static bool IsPtr = true;
        constexpr static bool IsConst = true;
        constexpr static bool IsVolatile = true;
        constexpr static auto Name = StringLiteral{"volatile const "} + details::StaticInfo<ParentID>::Name + StringLiteral{" *"};
        constexpr static auto FullName = StringLiteral{"volatile const "} + details::StaticInfo<ParentID>::FullName + StringLiteral{" *"};
    };
}// namespace pf::meta::details
