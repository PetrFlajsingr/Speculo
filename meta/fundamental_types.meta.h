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

        // FIXME: RangeOf msvc failure here
        constexpr static /*RangeOf<pf::meta::Attribute>*/ auto Attributes = pf::make_array<pf::meta::Attribute>();

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
    struct StaticInfo<ID{0x0u, 0x25u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x25u}, ID{0x0u, 0x1u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x26u}> : StaticInfo_PtrWrap<ID{0x0u, 0x26u}, ID{0x0u, 0x1u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x27u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x27u}, ID{0x0u, 0x1u}> {};
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
    struct StaticInfo<ID{0x0u, 0x31u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x31u}, ID{0x0u, 0x2u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x32u}> : StaticInfo_PtrWrap<ID{0x0u, 0x32u}, ID{0x0u, 0x2u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x33u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x33u}, ID{0x0u, 0x2u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<char>() {
        return ::pf::meta::ID{0x0u, 0x2u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const char>() {
        return ::pf::meta::ID{0x0u, 0x28u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<char &>() {
        return ::pf::meta::ID{0x0u, 0x29u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<char &&>() {
        return ::pf::meta::ID{0x0u, 0x30u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const char &>() {
        return ::pf::meta::ID{0x0u, 0x31u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<char *>() {
        return ::pf::meta::ID{0x0u, 0x32u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const char *>() {
        return ::pf::meta::ID{0x0u, 0x33u};
    }

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
    struct StaticInfo<ID{0x0u, 0x37u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x37u}, ID{0x0u, 0x3u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x38u}> : StaticInfo_PtrWrap<ID{0x0u, 0x38u}, ID{0x0u, 0x3u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x39u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x39u}, ID{0x0u, 0x3u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<signed char>() {
        return ::pf::meta::ID{0x0u, 0x3u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const signed char>() {
        return ::pf::meta::ID{0x0u, 0x34u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<signed char &>() {
        return ::pf::meta::ID{0x0u, 0x35u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<signed char &&>() {
        return ::pf::meta::ID{0x0u, 0x36u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const signed char &>() {
        return ::pf::meta::ID{0x0u, 0x37u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<signed char *>() {
        return ::pf::meta::ID{0x0u, 0x38u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const signed char *>() {
        return ::pf::meta::ID{0x0u, 0x39u};
    }

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
    struct StaticInfo<ID{0x0u, 0x43u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x43u}, ID{0x0u, 0x4u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x44u}> : StaticInfo_PtrWrap<ID{0x0u, 0x44u}, ID{0x0u, 0x4u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x45u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x45u}, ID{0x0u, 0x4u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned char>() {
        return ::pf::meta::ID{0x0u, 0x4u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned char>() {
        return ::pf::meta::ID{0x0u, 0x40u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned char &>() {
        return ::pf::meta::ID{0x0u, 0x41u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned char &&>() {
        return ::pf::meta::ID{0x0u, 0x42u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned char &>() {
        return ::pf::meta::ID{0x0u, 0x43u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned char *>() {
        return ::pf::meta::ID{0x0u, 0x44u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned char *>() {
        return ::pf::meta::ID{0x0u, 0x45u};
    }

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
    struct StaticInfo<ID{0x0u, 0x49u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x49u}, ID{0x0u, 0x5u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x50u}> : StaticInfo_PtrWrap<ID{0x0u, 0x50u}, ID{0x0u, 0x5u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x51u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x51u}, ID{0x0u, 0x5u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<char8_t>() {
        return ::pf::meta::ID{0x0u, 0x5u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const char8_t>() {
        return ::pf::meta::ID{0x0u, 0x46u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<char8_t &>() {
        return ::pf::meta::ID{0x0u, 0x47u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<char8_t &&>() {
        return ::pf::meta::ID{0x0u, 0x48u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const char8_t &>() {
        return ::pf::meta::ID{0x0u, 0x49u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<char8_t *>() {
        return ::pf::meta::ID{0x0u, 0x50u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const char8_t *>() {
        return ::pf::meta::ID{0x0u, 0x51u};
    }


    // char16_t
    template<>
    struct StaticInfo<ID{0x0u, 0x6u}> : FundamentalStaticTypeInfo<char16_t, ID{0x0u, 0x6u}, StringLiteral{"char16_t"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x52u}> : StaticInfo_ConstWrap<ID{0x0u, 0x52u}, ID{0x0u, 0x6u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x53u}> : StaticInfo_LRefWrap<ID{0x0u, 0x53u}, ID{0x0u, 0x6u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x54u}> : StaticInfo_RRefWrap<ID{0x0u, 0x54u}, ID{0x0u, 0x6u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x55u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x55u}, ID{0x0u, 0x6u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x56u}> : StaticInfo_PtrWrap<ID{0x0u, 0x56u}, ID{0x0u, 0x6u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x57u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x57u}, ID{0x0u, 0x6u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<char16_t>() {
        return ::pf::meta::ID{0x0u, 0x6u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const char16_t>() {
        return ::pf::meta::ID{0x0u, 0x52u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<char16_t &>() {
        return ::pf::meta::ID{0x0u, 0x53u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<char16_t &&>() {
        return ::pf::meta::ID{0x0u, 0x54u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const char16_t &>() {
        return ::pf::meta::ID{0x0u, 0x55u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<char16_t *>() {
        return ::pf::meta::ID{0x0u, 0x56u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const char16_t *>() {
        return ::pf::meta::ID{0x0u, 0x57u};
    }

    // char32_t
    template<>
    struct StaticInfo<ID{0x0u, 0x8u}> : FundamentalStaticTypeInfo<char32_t, ID{0x0u, 0x8u}, StringLiteral{"char32_t"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x58u}> : StaticInfo_ConstWrap<ID{0x0u, 0x58u}, ID{0x0u, 0x8u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x59u}> : StaticInfo_LRefWrap<ID{0x0u, 0x59u}, ID{0x0u, 0x8u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x60u}> : StaticInfo_RRefWrap<ID{0x0u, 0x60u}, ID{0x0u, 0x8u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x61u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x61u}, ID{0x0u, 0x8u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x62u}> : StaticInfo_PtrWrap<ID{0x0u, 0x62u}, ID{0x0u, 0x8u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x63u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x63u}, ID{0x0u, 0x8u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<char32_t>() {
        return ::pf::meta::ID{0x0u, 0x8u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const char32_t>() {
        return ::pf::meta::ID{0x0u, 0x58u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<char32_t &>() {
        return ::pf::meta::ID{0x0u, 0x59u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<char32_t &&>() {
        return ::pf::meta::ID{0x0u, 0x60u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const char32_t &>() {
        return ::pf::meta::ID{0x0u, 0x61u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<char32_t *>() {
        return ::pf::meta::ID{0x0u, 0x62u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const char32_t *>() {
        return ::pf::meta::ID{0x0u, 0x63u};
    }

    // short
    template<>
    struct StaticInfo<ID{0x0u, 0x9u}> : FundamentalStaticTypeInfo<short, ID{0x0u, 0x9u}, StringLiteral{"short"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x64u}> : StaticInfo_ConstWrap<ID{0x0u, 0x64u}, ID{0x0u, 0x9u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x65u}> : StaticInfo_LRefWrap<ID{0x0u, 0x65u}, ID{0x0u, 0x9u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x66u}> : StaticInfo_RRefWrap<ID{0x0u, 0x66u}, ID{0x0u, 0x9u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x67u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x67u}, ID{0x0u, 0x9u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x68u}> : StaticInfo_PtrWrap<ID{0x0u, 0x68u}, ID{0x0u, 0x9u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x69u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x69u}, ID{0x0u, 0x9u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<short>() {
        return ::pf::meta::ID{0x0u, 0x9u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const short>() {
        return ::pf::meta::ID{0x0u, 0x64u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<short &>() {
        return ::pf::meta::ID{0x0u, 0x65u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<short &&>() {
        return ::pf::meta::ID{0x0u, 0x66u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const short &>() {
        return ::pf::meta::ID{0x0u, 0x67u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<short *>() {
        return ::pf::meta::ID{0x0u, 0x68u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const short *>() {
        return ::pf::meta::ID{0x0u, 0x69u};
    }

    // unsigned short
    template<>
    struct StaticInfo<ID{0x0u, 0x10u}> : FundamentalStaticTypeInfo<unsigned short, ID{0x0u, 0x10u}, StringLiteral{"unsigned short"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x70u}> : StaticInfo_ConstWrap<ID{0x0u, 0x70u}, ID{0x0u, 0x10u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x71u}> : StaticInfo_LRefWrap<ID{0x0u, 0x71u}, ID{0x0u, 0x10u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x72u}> : StaticInfo_RRefWrap<ID{0x0u, 0x72u}, ID{0x0u, 0x10u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x73u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x73u}, ID{0x0u, 0x10u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x74u}> : StaticInfo_PtrWrap<ID{0x0u, 0x74u}, ID{0x0u, 0x10u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x75u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x75u}, ID{0x0u, 0x10u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned short>() {
        return ::pf::meta::ID{0x0u, 0x10u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned short>() {
        return ::pf::meta::ID{0x0u, 0x70u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned short &>() {
        return ::pf::meta::ID{0x0u, 0x71u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned short &&>() {
        return ::pf::meta::ID{0x0u, 0x72u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned short &>() {
        return ::pf::meta::ID{0x0u, 0x73u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned short *>() {
        return ::pf::meta::ID{0x0u, 0x74u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned short *>() {
        return ::pf::meta::ID{0x0u, 0x75u};
    }

    // int
    template<>
    struct StaticInfo<ID{0x0u, 0x11u}> : FundamentalStaticTypeInfo<int, ID{0x0u, 0x11u}, StringLiteral{"int"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x76u}> : StaticInfo_ConstWrap<ID{0x0u, 0x76u}, ID{0x0u, 0x11u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x77u}> : StaticInfo_LRefWrap<ID{0x0u, 0x77u}, ID{0x0u, 0x11u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x78u}> : StaticInfo_RRefWrap<ID{0x0u, 0x78u}, ID{0x0u, 0x11u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x79u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x79u}, ID{0x0u, 0x11u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x80u}> : StaticInfo_PtrWrap<ID{0x0u, 0x80u}, ID{0x0u, 0x11u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x81u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x81u}, ID{0x0u, 0x11u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<int>() {
        return ::pf::meta::ID{0x0u, 0x11u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const int>() {
        return ::pf::meta::ID{0x0u, 0x76u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<int &>() {
        return ::pf::meta::ID{0x0u, 0x77u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<int &&>() {
        return ::pf::meta::ID{0x0u, 0x78u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const int &>() {
        return ::pf::meta::ID{0x0u, 0x79u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<int *>() {
        return ::pf::meta::ID{0x0u, 0x80u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const int *>() {
        return ::pf::meta::ID{0x0u, 0x81u};
    }

    // unsigned int
    template<>
    struct StaticInfo<ID{0x0u, 0x12u}> : FundamentalStaticTypeInfo<unsigned int, ID{0x0u, 0x12u}, StringLiteral{"unsigned int"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x82u}> : StaticInfo_ConstWrap<ID{0x0u, 0x82u}, ID{0x0u, 0x12u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x83u}> : StaticInfo_LRefWrap<ID{0x0u, 0x83u}, ID{0x0u, 0x12u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x84u}> : StaticInfo_RRefWrap<ID{0x0u, 0x84u}, ID{0x0u, 0x12u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x85u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x85u}, ID{0x0u, 0x12u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x86u}> : StaticInfo_PtrWrap<ID{0x0u, 0x86u}, ID{0x0u, 0x12u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x87u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x87u}, ID{0x0u, 0x12u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned int>() {
        return ::pf::meta::ID{0x0u, 0x12u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned int>() {
        return ::pf::meta::ID{0x0u, 0x82u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned int &>() {
        return ::pf::meta::ID{0x0u, 0x83u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned int &&>() {
        return ::pf::meta::ID{0x0u, 0x84u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned int &>() {
        return ::pf::meta::ID{0x0u, 0x85u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned int *>() {
        return ::pf::meta::ID{0x0u, 0x86u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned int *>() {
        return ::pf::meta::ID{0x0u, 0x87u};
    }

    // long
    template<>
    struct StaticInfo<ID{0x0u, 0x13u}> : FundamentalStaticTypeInfo<long, ID{0x0u, 0x13u}, StringLiteral{"long"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x88u}> : StaticInfo_ConstWrap<ID{0x0u, 0x88u}, ID{0x0u, 0x13u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x89u}> : StaticInfo_LRefWrap<ID{0x0u, 0x89u}, ID{0x0u, 0x13u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x90u}> : StaticInfo_RRefWrap<ID{0x0u, 0x90u}, ID{0x0u, 0x13u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x91u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x91u}, ID{0x0u, 0x13u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x92u}> : StaticInfo_PtrWrap<ID{0x0u, 0x92u}, ID{0x0u, 0x13u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x93u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x93u}, ID{0x0u, 0x13u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<long>() {
        return ::pf::meta::ID{0x0u, 0x13u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const long>() {
        return ::pf::meta::ID{0x0u, 0x88u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<long &>() {
        return ::pf::meta::ID{0x0u, 0x89u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<long &&>() {
        return ::pf::meta::ID{0x0u, 0x90u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const long &>() {
        return ::pf::meta::ID{0x0u, 0x91u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<long *>() {
        return ::pf::meta::ID{0x0u, 0x92u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const long *>() {
        return ::pf::meta::ID{0x0u, 0x93u};
    }

    // unsigned long
    template<>
    struct StaticInfo<ID{0x0u, 0x14u}> : FundamentalStaticTypeInfo<unsigned long, ID{0x0u, 0x14u}, StringLiteral{"unsigned long"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x94u}> : StaticInfo_ConstWrap<ID{0x0u, 0x94u}, ID{0x0u, 0x14u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x95u}> : StaticInfo_LRefWrap<ID{0x0u, 0x95u}, ID{0x0u, 0x14u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x96u}> : StaticInfo_RRefWrap<ID{0x0u, 0x96u}, ID{0x0u, 0x14u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x97u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x97u}, ID{0x0u, 0x14u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x98u}> : StaticInfo_PtrWrap<ID{0x0u, 0x98u}, ID{0x0u, 0x14u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x99u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x99u}, ID{0x0u, 0x14u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned long>() {
        return ::pf::meta::ID{0x0u, 0x14u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned long>() {
        return ::pf::meta::ID{0x0u, 0x94u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned long &>() {
        return ::pf::meta::ID{0x0u, 0x95u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned long &&>() {
        return ::pf::meta::ID{0x0u, 0x96u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned long &>() {
        return ::pf::meta::ID{0x0u, 0x97u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned long *>() {
        return ::pf::meta::ID{0x0u, 0x98u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned long *>() {
        return ::pf::meta::ID{0x0u, 0x99u};
    }

    // long long
    template<>
    struct StaticInfo<ID{0x0u, 0x15u}> : FundamentalStaticTypeInfo<long long, ID{0x0u, 0x15u}, StringLiteral{"long long"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x100u}> : StaticInfo_ConstWrap<ID{0x0u, 0x100u}, ID{0x0u, 0x15u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x101u}> : StaticInfo_LRefWrap<ID{0x0u, 0x101u}, ID{0x0u, 0x15u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x102u}> : StaticInfo_RRefWrap<ID{0x0u, 0x102u}, ID{0x0u, 0x15u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x103u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x103u}, ID{0x0u, 0x15u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x104u}> : StaticInfo_PtrWrap<ID{0x0u, 0x104u}, ID{0x0u, 0x15u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x105u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x105u}, ID{0x0u, 0x15u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<long long>() {
        return ::pf::meta::ID{0x0u, 0x15u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const long long>() {
        return ::pf::meta::ID{0x0u, 0x100u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<long long &>() {
        return ::pf::meta::ID{0x0u, 0x101u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<long long &&>() {
        return ::pf::meta::ID{0x0u, 0x102u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const long long &>() {
        return ::pf::meta::ID{0x0u, 0x103u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<long long *>() {
        return ::pf::meta::ID{0x0u, 0x104u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const long long *>() {
        return ::pf::meta::ID{0x0u, 0x105u};
    }

    // unsigned long long
    template<>
    struct StaticInfo<ID{0x0u, 0x16u}>
        : FundamentalStaticTypeInfo<unsigned long long, ID{0x0u, 0x16u}, StringLiteral{"unsigned long long"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x106u}> : StaticInfo_ConstWrap<ID{0x0u, 0x106u}, ID{0x0u, 0x16u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x107u}> : StaticInfo_LRefWrap<ID{0x0u, 0x107u}, ID{0x0u, 0x16u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x108u}> : StaticInfo_RRefWrap<ID{0x0u, 0x108u}, ID{0x0u, 0x16u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x109u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x109u}, ID{0x0u, 0x16u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x110u}> : StaticInfo_PtrWrap<ID{0x0u, 0x110u}, ID{0x0u, 0x16u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x111u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x111u}, ID{0x0u, 0x16u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned long long>() {
        return ::pf::meta::ID{0x0u, 0x16u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned long long>() {
        return ::pf::meta::ID{0x0u, 0x106u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned long long &>() {
        return ::pf::meta::ID{0x0u, 0x107u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned long long &&>() {
        return ::pf::meta::ID{0x0u, 0x108u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned long long &>() {
        return ::pf::meta::ID{0x0u, 0x109u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned long long *>() {
        return ::pf::meta::ID{0x0u, 0x110u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned long long *>() {
        return ::pf::meta::ID{0x0u, 0x111u};
    }

    // float
    template<>
    struct StaticInfo<ID{0x0u, 0x17u}> : FundamentalStaticTypeInfo<float, ID{0x0u, 0x17u}, StringLiteral{"float"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x112u}> : StaticInfo_ConstWrap<ID{0x0u, 0x112u}, ID{0x0u, 0x17u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x113u}> : StaticInfo_LRefWrap<ID{0x0u, 0x113u}, ID{0x0u, 0x17u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x114u}> : StaticInfo_RRefWrap<ID{0x0u, 0x114u}, ID{0x0u, 0x17u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x115u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x115u}, ID{0x0u, 0x17u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x116u}> : StaticInfo_PtrWrap<ID{0x0u, 0x116u}, ID{0x0u, 0x17u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x117u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x117u}, ID{0x0u, 0x17u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<float>() {
        return ::pf::meta::ID{0x0u, 0x17u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const float>() {
        return ::pf::meta::ID{0x0u, 0x112u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<float &>() {
        return ::pf::meta::ID{0x0u, 0x113u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<float &&>() {
        return ::pf::meta::ID{0x0u, 0x114u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const float &>() {
        return ::pf::meta::ID{0x0u, 0x115u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<float *>() {
        return ::pf::meta::ID{0x0u, 0x116u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const float *>() {
        return ::pf::meta::ID{0x0u, 0x117u};
    }

    // double
    template<>
    struct StaticInfo<ID{0x0u, 0x18u}> : FundamentalStaticTypeInfo<double, ID{0x0u, 0x18u}, StringLiteral{"double"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x118u}> : StaticInfo_ConstWrap<ID{0x0u, 0x118u}, ID{0x0u, 0x18u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x119u}> : StaticInfo_LRefWrap<ID{0x0u, 0x119u}, ID{0x0u, 0x18u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x120u}> : StaticInfo_RRefWrap<ID{0x0u, 0x120u}, ID{0x0u, 0x18u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x121u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x121u}, ID{0x0u, 0x18u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x122u}> : StaticInfo_PtrWrap<ID{0x0u, 0x122u}, ID{0x0u, 0x18u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x123u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x123u}, ID{0x0u, 0x18u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<double>() {
        return ::pf::meta::ID{0x0u, 0x18u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const double>() {
        return ::pf::meta::ID{0x0u, 0x118u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<double &>() {
        return ::pf::meta::ID{0x0u, 0x119u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<double &&>() {
        return ::pf::meta::ID{0x0u, 0x120u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const double &>() {
        return ::pf::meta::ID{0x0u, 0x121u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<double *>() {
        return ::pf::meta::ID{0x0u, 0x122u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const double *>() {
        return ::pf::meta::ID{0x0u, 0x123u};
    }

    // long double
    template<>
    struct StaticInfo<ID{0x0u, 0x19u}> : FundamentalStaticTypeInfo<long double, ID{0x0u, 0x19u}, StringLiteral{"long double"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x124u}> : StaticInfo_ConstWrap<ID{0x0u, 0x124u}, ID{0x0u, 0x19u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x125u}> : StaticInfo_LRefWrap<ID{0x0u, 0x125u}, ID{0x0u, 0x19u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x126u}> : StaticInfo_RRefWrap<ID{0x0u, 0x126u}, ID{0x0u, 0x19u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x127u}> : StaticInfo_ConstLRefWrap<ID{0x0u, 0x127u}, ID{0x0u, 0x19u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x128u}> : StaticInfo_PtrWrap<ID{0x0u, 0x128u}, ID{0x0u, 0x19u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x129u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x129u}, ID{0x0u, 0x19u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<long double>() {
        return ::pf::meta::ID{0x0u, 0x18u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const long double>() {
        return ::pf::meta::ID{0x0u, 0x124u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<long double &>() {
        return ::pf::meta::ID{0x0u, 0x125u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<long double &&>() {
        return ::pf::meta::ID{0x0u, 0x126u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const long double &>() {
        return ::pf::meta::ID{0x0u, 0x127u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<long double *>() {
        return ::pf::meta::ID{0x0u, 0x128u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const long double *>() {
        return ::pf::meta::ID{0x0u, 0x129u};
    }

    // void
    template<>
    struct StaticInfo<ID{0x0u, 0x20u}> : FundamentalStaticTypeInfo<void, ID{0x0u, 0x20u}, StringLiteral{"void"}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x130u}> : StaticInfo_PtrWrap<ID{0x0u, 0x130u}, ID{0x0u, 0x20u}> {};
    template<>
    struct StaticInfo<ID{0x0u, 0x131u}> : StaticInfo_ConstPtrWrap<ID{0x0u, 0x131u}, ID{0x0u, 0x20u}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<void *>() {
        return ::pf::meta::ID{0x0u, 0x130u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const void *>() {
        return ::pf::meta::ID{0x0u, 0x131u};
    }

    // std::nullptr_t
    template<>
    struct StaticInfo<ID{0x0u, 0x21u}>
        : FundamentalStaticTypeInfo<std::nullptr_t, ID{0x0u, 0x21u}, StringLiteral{"nullptr_t"}, StringLiteral{"std::nullptr_t"}> {};
    template<>
    [[nodiscard]] consteval ID getTypeId<std::nullptr_t>() {
        return ::pf::meta::ID{0x0u, 0x21u};
    }


}// namespace pf::meta::details


#endif//PF_META_FUNDAMENTAL_TYPES_META_H
