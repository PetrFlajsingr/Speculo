//
// Created by xflajs00 on 08.03.2023.
//

#ifndef PF_META_TEST_META_H
#define PF_META_TEST_META_H

#include "meta/common.h"
#include "test.h"
#include <pf_common/array.h>
#include <pf_common/concepts/ranges.h>
#include <type_traits>


template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0x5eb8ecd5d22d7bc8u, 0xec6880983ea9e813u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x5eb8ecd5d22d7bc8u, 0xec6880983ea9e813u};
    constexpr static ID TypeID = ::pf::meta::ID{0x70dd77dbc4364052u, 0x5eed17950196999eu};
    using Type = pf::SomeEnum;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(
            pf::meta::Attribute{"test", {}}, pf::meta::Attribute{"test2", {}}, pf::meta::Attribute{"test3", {}});

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"Value1"};
    constexpr static auto FullName = StringLiteral{"pf::SomeEnum::Value1"};

    constexpr static bool UnderlyingValue = false;
    constexpr static pf::SomeEnum Value = pf::SomeEnum::Value1;
};


template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0xab87eb82df2d0491u, 0xd26f2541b2859707u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xab87eb82df2d0491u, 0xd26f2541b2859707u};
    constexpr static ID TypeID = ::pf::meta::ID{0x70dd77dbc4364052u, 0x5eed17950196999eu};
    using Type = pf::SomeEnum;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"Value2"};
    constexpr static auto FullName = StringLiteral{"pf::SomeEnum::Value2"};

    constexpr static bool UnderlyingValue = true;
    constexpr static pf::SomeEnum Value = pf::SomeEnum::Value2;
};


template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0x70dd77dbc4364052u, 0x5eed17950196999eu}> {
    using Type = pf::SomeEnum;
    constexpr static ID TypeID = ::pf::meta::ID{0x70dd77dbc4364052u, 0x5eed17950196999eu};

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(
            pf::meta::Attribute{"pf::operators",
                                {R"(()()()((())))", R"([[nodiscard]])", R"(1ll)", R"(1.011)", R"([]{}())", R"("yeet")", R"('a')",
                                 R"([][][]:::3214234...[][][][])"}},
            pf::meta::Attribute{"pf::hihi", {}}, pf::meta::Attribute{"pf::operators2", {R"(1ll)", R"(1.011)", R"("yeet")"}},
            pf::meta::Attribute{"pf::hihi2", {}});

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = ::pf::StringLiteral{"SomeEnum"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::SomeEnum"};

    using UnderlyingType = bool;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
            ::pf::meta::ID{0x5eb8ecd5d22d7bc8u, 0xec6880983ea9e813u}, ::pf::meta::ID{0xab87eb82df2d0491u, 0xd26f2541b2859707u});
};

// const
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0xd1f8c930455cd9bdu, 0xb40a3521561cd6b5u}>
    : ::pf::meta::details::StaticTypeInfo_ConstWrap<::pf::meta::ID{0xd1f8c930455cd9bdu, 0xb40a3521561cd6b5u},
                                                    ::pf::meta::ID{0x70dd77dbc4364052u, 0x5eed17950196999eu}> {};
// &
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0x5106d8b3279debabu, 0x9f52f7e489d84600u}>
    : ::pf::meta::details::StaticTypeInfo_LRefWrap<::pf::meta::ID{0x5106d8b3279debabu, 0x9f52f7e489d84600u},
                                                   ::pf::meta::ID{0x70dd77dbc4364052u, 0x5eed17950196999eu}> {};
// &&
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0x1c97d9a56938fea3u, 0xf6744a6693c99baeu}>
    : ::pf::meta::details::StaticTypeInfo_RRefWrap<::pf::meta::ID{0x1c97d9a56938fea3u, 0xf6744a6693c99baeu},
                                                   ::pf::meta::ID{0x70dd77dbc4364052u, 0x5eed17950196999eu}> {};
// const &
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0x801e36fb9c348467u, 0x25b370e94f4ec616u}>
    : ::pf::meta::details::StaticTypeInfo_LRefWrap<::pf::meta::ID{0x801e36fb9c348467u, 0x25b370e94f4ec616u},
                                                   ::pf::meta::ID{0xd1f8c930455cd9bdu, 0xb40a3521561cd6b5u}> {};
// *
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0xfdce24249c3f678cu, 0x24b81d7616e8c384u}>
    : ::pf::meta::details::StaticTypeInfo_PtrWrap<::pf::meta::ID{0xfdce24249c3f678cu, 0x24b81d7616e8c384u},
                                                  ::pf::meta::ID{0x70dd77dbc4364052u, 0x5eed17950196999eu}> {};
// const *
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0x5ce3e299c752e5c1u, 0x577b764aaaa3d7a2u}>
    : ::pf::meta::details::StaticTypeInfo_PtrWrap<::pf::meta::ID{0x5ce3e299c752e5c1u, 0x577b764aaaa3d7a2u},
                                                  ::pf::meta::ID{0xd1f8c930455cd9bdu, 0xb40a3521561cd6b5u}> {};


namespace pf::meta::details {

    template<>
    [[nodiscard]] consteval ID getTypeId<pf::SomeEnum>() {
        return ::pf::meta::ID{0x70dd77dbc4364052u, 0x5eed17950196999eu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum>() {
        return ::pf::meta::ID{0xd1f8c930455cd9bdu, 0xb40a3521561cd6b5u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::SomeEnum &>() {
        return ::pf::meta::ID{0x5106d8b3279debabu, 0x9f52f7e489d84600u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::SomeEnum &&>() {
        return ::pf::meta::ID{0x1c97d9a56938fea3u, 0xf6744a6693c99baeu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum &>() {
        return ::pf::meta::ID{0x801e36fb9c348467u, 0x25b370e94f4ec616u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::SomeEnum *>() {
        return ::pf::meta::ID{0xfdce24249c3f678cu, 0x24b81d7616e8c384u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum *>() {
        return ::pf::meta::ID{0x5ce3e299c752e5c1u, 0x577b764aaaa3d7a2u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value1>() {
        return ::pf::meta::ID{0x5eb8ecd5d22d7bc8u, 0xec6880983ea9e813u};
    }


    template<>
    [[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value2>() {
        return ::pf::meta::ID{0xab87eb82df2d0491u, 0xd26f2541b2859707u};
    }

}// namespace pf::meta::details


#endif//PF_META_TEST_META_H
