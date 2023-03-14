//
// Created by xflajs00 on 14.03.2023.
//

#ifndef PF_META_FUNDAMENTAL_TYPES_META_H
#define PF_META_FUNDAMENTAL_TYPES_META_H

#include "common.h"
#include <pf_common/concepts/ranges.h>

namespace pf::meta::details {
    template<typename T, ID TID, StringLiteral TypeName, StringLiteral FullTypeName = TypeName>
        requires(std::is_fundamental_v<T>)
    struct FundamentalStaticTypeInfo {
        using Type = T;
        constexpr static ID TypeID = TID;

        constexpr static RangeOf<Attribute> auto Attributes = std::span<Attribute>{};

        constexpr static bool IsEnum = false;
        constexpr static bool IsEnumValue = false;
        constexpr static bool IsRecord = false;
        constexpr static bool IsUnion = false;
        constexpr static bool IsPrimitiveType = true;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = TypeName;
        constexpr static auto FullName = FullTypeName;
    };
    // bool
    template<>
    struct StaticInfo<ID{0x0u, 0x1u}> : FundamentalStaticTypeInfo<bool, ID{0x0u, 0x1u}, StringLiteral{"bool"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x22u}> : StaticInfo_ConstWrap<ID{0x0u, 0x22u}, ID{0x0u, 0x1u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x23u}> : StaticInfo_LRefWrap<ID{0x0u, 0x23u}, ID{0x0u, 0x1u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x24u}> : StaticInfo_RRefWrap<ID{0x0u, 0x24u}, ID{0x0u, 0x1u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x25u}> : StaticInfo_LRefWrap<ID{0x0u, 0x25u}, ID{0x0u, 0x22u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x26u}> : StaticInfo_PtrWrap<ID{0x0u, 0x26u}, ID{0x0u, 0x1u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x27u}> : StaticInfo_PtrWrap<ID{0x0u, 0x27u}, ID{0x0u, 0x22u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<bool>() {
        return ::pf::meta::ID{0x0u, 0x1u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const bool>() {
        return ::pf::meta::ID{0x0u, 0x22u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<bool &>() {
        return ::pf::meta::ID{0x0u, 0x23u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<bool &&>() {
        return ::pf::meta::ID{0x0u, 0x24u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const bool &>() {
        return ::pf::meta::ID{0x0u, 0x25u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<bool *>() {
        return ::pf::meta::ID{0x0u, 0x26u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const bool *>() {
        return ::pf::meta::ID{0x0u, 0x27u};
    }

    // char
    template<>
    struct StaticInfo<ID{0x0u, 0x2u}> : FundamentalStaticTypeInfo<char, ID{0x0u, 0x2u}, StringLiteral{"char"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x28u}> : StaticInfo_ConstWrap<ID{0x0u, 0x28u}, ID{0x0u, 0x2u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x29u}> : StaticInfo_LRefWrap<ID{0x0u, 0x29u}, ID{0x0u, 0x2u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x30u}> : StaticInfo_RRefWrap<ID{0x0u, 0x30u}, ID{0x0u, 0x2u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x31u}> : StaticInfo_LRefWrap<ID{0x0u, 0x31u}, ID{0x0u, 0x28u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x32u}> : StaticInfo_PtrWrap<ID{0x0u, 0x32u}, ID{0x0u, 0x2u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x33u}> : StaticInfo_PtrWrap<ID{0x0u, 0x33u}, ID{0x0u, 0x28u}> {};

    // signed char
    template<>
    struct StaticInfo<ID{0x0u, 0x3u}> : FundamentalStaticTypeInfo<signed char, ID{0x0u, 0x3u}, StringLiteral{"signed char"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x34u}> : StaticInfo_ConstWrap<ID{0x0u, 0x34u}, ID{0x0u, 0x3u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x35u}> : StaticInfo_LRefWrap<ID{0x0u, 0x35u}, ID{0x0u, 0x3u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x36u}> : StaticInfo_RRefWrap<ID{0x0u, 0x36u}, ID{0x0u, 0x3u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x37u}> : StaticInfo_LRefWrap<ID{0x0u, 0x37u}, ID{0x0u, 0x34u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x38u}> : StaticInfo_PtrWrap<ID{0x0u, 0x38u}, ID{0x0u, 0x3u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x39u}> : StaticInfo_PtrWrap<ID{0x0u, 0x39u}, ID{0x0u, 0x34u}> {};

    // unsigned char
    template<>
    struct StaticInfo<ID{0x0u, 0x4u}> : FundamentalStaticTypeInfo<unsigned char, ID{0x0u, 0x4u}, StringLiteral{"unsigned char"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x40u}> : StaticInfo_ConstWrap<ID{0x0u, 0x40u}, ID{0x0u, 0x4u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x41u}> : StaticInfo_LRefWrap<ID{0x0u, 0x41u}, ID{0x0u, 0x4u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x42u}> : StaticInfo_RRefWrap<ID{0x0u, 0x42u}, ID{0x0u, 0x4u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x43u}> : StaticInfo_LRefWrap<ID{0x0u, 0x43u}, ID{0x0u, 0x40u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x44u}> : StaticInfo_PtrWrap<ID{0x0u, 0x44u}, ID{0x0u, 0x4u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x45u}> : StaticInfo_PtrWrap<ID{0x0u, 0x45u}, ID{0x0u, 0x40u}> {};

    // char8_t
    template<>
    struct StaticInfo<ID{0x0u, 0x5u}> : FundamentalStaticTypeInfo<char8_t, ID{0x0u, 0x5u}, StringLiteral{"char8_t"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x46u}> : StaticInfo_ConstWrap<ID{0x0u, 0x46u}, ID{0x0u, 0x5u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x47u}> : StaticInfo_LRefWrap<ID{0x0u, 0x47u}, ID{0x0u, 0x5u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x48u}> : StaticInfo_RRefWrap<ID{0x0u, 0x48u}, ID{0x0u, 0x5u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x49u}> : StaticInfo_LRefWrap<ID{0x0u, 0x49u}, ID{0x0u, 0x46u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x50u}> : StaticInfo_PtrWrap<ID{0x0u, 0x50u}, ID{0x0u, 0x5u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x51u}> : StaticInfo_PtrWrap<ID{0x0u, 0x51u}, ID{0x0u, 0x46u}> {};


    template<>
    struct StaticInfo<ID{0x0u, 0x6u}> : FundamentalStaticTypeInfo<char16_t, ID{0x0u, 0x6u}, StringLiteral{"char16_t"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x7u}> : FundamentalStaticTypeInfo<char16_t, ID{0x0u, 0x7u}, StringLiteral{"char16_t"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x8u}> : FundamentalStaticTypeInfo<char32_t, ID{0x0u, 0x8u}, StringLiteral{"char32_t"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x9u}> : FundamentalStaticTypeInfo<short, ID{0x0u, 0x9u}, StringLiteral{"short"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x10u}> : FundamentalStaticTypeInfo<unsigned short, ID{0x0u, 0x10u}, StringLiteral{"unsigned short"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x11u}> : FundamentalStaticTypeInfo<int, ID{0x0u, 0x11u}, StringLiteral{"int"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x12u}> : FundamentalStaticTypeInfo<unsigned int, ID{0x0u, 0x12u}, StringLiteral{"unsigned int"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x13u}> : FundamentalStaticTypeInfo<long, ID{0x0u, 0x13u}, StringLiteral{"long"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x14u}> : FundamentalStaticTypeInfo<unsigned long, ID{0x0u, 0x14u}, StringLiteral{"unsigned long"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x15u}> : FundamentalStaticTypeInfo<long long, ID{0x0u, 0x15u}, StringLiteral{"long long"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x16u}>
        : FundamentalStaticTypeInfo<unsigned long long, ID{0x0u, 0x16u}, StringLiteral{"unsigned long long"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x17u}> : FundamentalStaticTypeInfo<float, ID{0x0u, 0x17u}, StringLiteral{"float"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x18u}> : FundamentalStaticTypeInfo<double, ID{0x0u, 0x18u}, StringLiteral{"double"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x19u}> : FundamentalStaticTypeInfo<long double, ID{0x0u, 0x19u}, StringLiteral{"long double"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x20u}> : FundamentalStaticTypeInfo<void, ID{0x0u, 0x20u}, StringLiteral{"void"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x21u}>
        : FundamentalStaticTypeInfo<std::nullptr_t, ID{0x0u, 0x21u}, StringLiteral{"nullptr_t"}, StringLiteral{"std::nullptr_t"}> {};

}// namespace pf::meta::details


#endif//PF_META_FUNDAMENTAL_TYPES_META_H
