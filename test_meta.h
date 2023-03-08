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
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0xcc073f67063f642cu, 0xd756cd448f263e94u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xcc073f67063f642cu, 0xd756cd448f263e94u};
    constexpr static ID TypeID = ::pf::meta::ID{0xd6141ba1b7763609u, 0xdabcaaac9048c16fu};
    using Type = pf::SomeEnum;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(pf::meta::Attribute{"test", {}}, pf::meta::Attribute{"test2", {}}, pf::meta::Attribute{"test3", {}});

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
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0x780c890665069166u, 0x1678f1f66bd4366au}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x780c890665069166u, 0x1678f1f66bd4366au};
    constexpr static ID TypeID = ::pf::meta::ID{0xd6141ba1b7763609u, 0xdabcaaac9048c16fu};
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
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0xd6141ba1b7763609u, 0xdabcaaac9048c16fu}> {
    using Type = pf::SomeEnum;
    constexpr static ID TypeID = ::pf::meta::ID{0xd6141ba1b7763609u, 0xdabcaaac9048c16fu};

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(pf::meta::Attribute{"pf::operators", {R"(()()()((())))", R"([[nodiscard]])", R"(1ll)", R"(1.011)", R"([]{}())", R"("yeet")", R"('a')", R"([][][]:::3214234...[][][][])"}}, pf::meta::Attribute{"pf::hihi", {R"()"}}, pf::meta::Attribute{"pf::operators2", {R"(1ll)", R"(1.011)", R"("yeet")"}}, pf::meta::Attribute{"pf::hihi2", {}});

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0xcc073f67063f642cu, 0xd756cd448f263e94u}, ::pf::meta::ID{0x780c890665069166u, 0x1678f1f66bd4366au});
};

// const
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0x115a2df9fa8f998du, 0xe7dc8dfd5aaae3cau}>
    : ::pf::meta::details::StaticTypeInfo_ConstWrap<::pf::meta::ID{0x115a2df9fa8f998du, 0xe7dc8dfd5aaae3cau}, ::pf::meta::ID{0xd6141ba1b7763609u, 0xdabcaaac9048c16fu}> {};
// &
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0x9fcdde06baefea85u, 0xc114a3d8a63646dfu}>
    : ::pf::meta::details::StaticTypeInfo_LRefWrap<::pf::meta::ID{0x9fcdde06baefea85u, 0xc114a3d8a63646dfu}, ::pf::meta::ID{0xd6141ba1b7763609u, 0xdabcaaac9048c16fu}> {};
// &&
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0xa6cc46b9cdc67d9cu, 0x19ca11972f87a14bu}>
    : ::pf::meta::details::StaticTypeInfo_RRefWrap<::pf::meta::ID{0xa6cc46b9cdc67d9cu, 0x19ca11972f87a14bu}, ::pf::meta::ID{0xd6141ba1b7763609u, 0xdabcaaac9048c16fu}> {};
// const &
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0x8088d105d5ba32f2u, 0xb1d52392137ec11u}>
    : ::pf::meta::details::StaticTypeInfo_LRefWrap<::pf::meta::ID{0x8088d105d5ba32f2u, 0xb1d52392137ec11u}, ::pf::meta::ID{0x115a2df9fa8f998du, 0xe7dc8dfd5aaae3cau}> {};
// *
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0xefbfa073e74cdb6bu, 0xc2fae69f777a1ca3u}>
    : ::pf::meta::details::StaticTypeInfo_PtrWrap<::pf::meta::ID{0xefbfa073e74cdb6bu, 0xc2fae69f777a1ca3u}, ::pf::meta::ID{0xd6141ba1b7763609u, 0xdabcaaac9048c16fu}> {};
// const *
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0x609b663948213b5u, 0x652e38fc0812908bu}>
    : ::pf::meta::details::StaticTypeInfo_PtrWrap<::pf::meta::ID{0x609b663948213b5u, 0x652e38fc0812908bu}, ::pf::meta::ID{0x115a2df9fa8f998du, 0xe7dc8dfd5aaae3cau}> {};


namespace pf::meta::details {

    template<>
    [[nodiscard]] consteval ID getTypeId<pf::SomeEnum>() {
        return ::pf::meta::ID{0xd6141ba1b7763609u, 0xdabcaaac9048c16fu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum>() {
        return ::pf::meta::ID{0x115a2df9fa8f998du, 0xe7dc8dfd5aaae3cau};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::SomeEnum &>() {
        return ::pf::meta::ID{0x9fcdde06baefea85u, 0xc114a3d8a63646dfu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::SomeEnum &&>() {
        return ::pf::meta::ID{0xa6cc46b9cdc67d9cu, 0x19ca11972f87a14bu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum &>() {
        return ::pf::meta::ID{0x8088d105d5ba32f2u, 0xb1d52392137ec11u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::SomeEnum *>() {
        return ::pf::meta::ID{0xefbfa073e74cdb6bu, 0xc2fae69f777a1ca3u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum *>() {
        return ::pf::meta::ID{0x609b663948213b5u, 0x652e38fc0812908bu};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value1>() {
        return ::pf::meta::ID{0xcc073f67063f642cu, 0xd756cd448f263e94u};
    }


    template<>
    [[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value2>() {
        return ::pf::meta::ID{0x780c890665069166u, 0x1678f1f66bd4366au};
    }

}



#endif//PF_META_TEST_META_H
