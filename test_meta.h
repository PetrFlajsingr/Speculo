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
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0xafafa67272652d65u, 0x7d9187d494177363u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xafafa67272652d65u, 0x7d9187d494177363u};
    constexpr static ID TypeID = ::pf::meta::ID{0x9aa85b2fe87e7774u, 0x908962efc4f89fadu};
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
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0x4011408ec41db1du, 0x9fc502ae89044213u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x4011408ec41db1du, 0x9fc502ae89044213u};
    constexpr static ID TypeID = ::pf::meta::ID{0x9aa85b2fe87e7774u, 0x908962efc4f89fadu};
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
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0x9aa85b2fe87e7774u, 0x908962efc4f89fadu}> {
    using Type = pf::SomeEnum;
    constexpr static ID TypeID = ::pf::meta::ID{0x9aa85b2fe87e7774u, 0x908962efc4f89fadu};

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(
            pf::meta::Attribute{"pf::operators",
                                {R"(()()()((())))", R"([[nodiscard]])", R"(1ll)", R"(1.011)", R"([]{}())", R"("yeet")", R"('a')",
                                 R"([][][]:::3214234...[][][][])"}},
            pf::meta::Attribute{"pf::hihi", {R"()"}}, pf::meta::Attribute{"pf::operators2", {R"(1ll)", R"(1.011)", R"("yeet")"}},
            pf::meta::Attribute{"pf::hihi2", {}});

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = ::pf::StringLiteral{"SomeEnum"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::SomeEnum"};

    using UnderlyingType = bool;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
            ::pf::meta::ID{0xafafa67272652d65u, 0x7d9187d494177363u}, ::pf::meta::ID{0x4011408ec41db1du, 0x9fc502ae89044213u});
};

// const
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0xf1ae0dfc5ffc0ab2u, 0x676af8fa3a2dec39u}>
    : ::pf::meta::details::StaticTypeInfo_ConstWrap<::pf::meta::ID{0xf1ae0dfc5ffc0ab2u, 0x676af8fa3a2dec39u},
                                                    ::pf::meta::ID{0x9aa85b2fe87e7774u, 0x908962efc4f89fadu}> {};
// &
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0x870ce4e038c7df85u, 0xc192a883e4f7e4f2u}>
    : ::pf::meta::details::StaticTypeInfo_RefWrap<::pf::meta::ID{0x870ce4e038c7df85u, 0xc192a883e4f7e4f2u},
                                                  ::pf::meta::ID{0x9aa85b2fe87e7774u, 0x908962efc4f89fadu}> {};
// const &
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0xb6c69e20ea91fe01u, 0x39c9aa80daaeb2b9u}>
    : ::pf::meta::details::StaticTypeInfo_RefWrap<::pf::meta::ID{0xb6c69e20ea91fe01u, 0x39c9aa80daaeb2b9u},
                                                  ::pf::meta::ID{0xf1ae0dfc5ffc0ab2u, 0x676af8fa3a2dec39u}> {};
// *
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0xb59a36df8e86c60eu, 0x919300a23ffed989u}>
    : ::pf::meta::details::StaticTypeInfo_PtrWrap<::pf::meta::ID{0xb59a36df8e86c60eu, 0x919300a23ffed989u},
                                                  ::pf::meta::ID{0x9aa85b2fe87e7774u, 0x908962efc4f89fadu}> {};
// const *
template<>
struct ::pf::meta::details::StaticTypeInfo<::pf::meta::ID{0x987fdd869da978bcu, 0xf77e7c7469b2342bu}>
    : ::pf::meta::details::StaticTypeInfo_PtrWrap<::pf::meta::ID{0x987fdd869da978bcu, 0xf77e7c7469b2342bu},
                                                  ::pf::meta::ID{0xf1ae0dfc5ffc0ab2u, 0x676af8fa3a2dec39u}> {};


namespace pf::meta::details {

    template<>
    [[nodiscard]] consteval ID getTypeId<pf::SomeEnum>() {
        return ::pf::meta::ID{0x9aa85b2fe87e7774u, 0x908962efc4f89fadu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum>() {
        return ::pf::meta::ID{0xf1ae0dfc5ffc0ab2u, 0x676af8fa3a2dec39u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::SomeEnum &>() {
        return ::pf::meta::ID{0x870ce4e038c7df85u, 0xc192a883e4f7e4f2u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum &>() {
        return ::pf::meta::ID{0xb6c69e20ea91fe01u, 0x39c9aa80daaeb2b9u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::SomeEnum *>() {
        return ::pf::meta::ID{0xb59a36df8e86c60eu, 0x919300a23ffed989u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum *>() {
        return ::pf::meta::ID{0x987fdd869da978bcu, 0xf77e7c7469b2342bu};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value1>() {
        return ::pf::meta::ID{0xafafa67272652d65u, 0x7d9187d494177363u};
    }


    template<>
    [[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value2>() {
        return ::pf::meta::ID{0x4011408ec41db1du, 0x9fc502ae89044213u};
    }

}// namespace pf::meta::details


#endif//PF_META_TEST_META_H
