
#pragma once

#include "meta/common.h"
#include "test.h"
#include <pf_common/array.h>
#include <pf_common/concepts/ranges.h>
#include <type_traits>

/****************************** pf::SomeEnum::Value1 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xeb2cd4ddeafa176cu, 0xcdb3481198571082u}> {
    struct details {
        constexpr static auto ArgArray_3320056739435534912 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_5549054955532699665 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_14388086737368975987 = pf::make_array<std::string_view>();

    };
    constexpr static ID ValueID = pf::meta::ID{0xeb2cd4ddeafa176cu, 0xcdb3481198571082u};
    constexpr static ID TypeID = pf::meta::ID{0xaf0caf3f0aba7704u, 0xa088b08065d55019u};
    using Type = pf::SomeEnum;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(pf::meta::Attribute{"test", std::span<const std::string_view>{details::ArgArray_3320056739435534912}}, pf::meta::Attribute{"test2", std::span<const std::string_view>{details::ArgArray_5549054955532699665}}, pf::meta::Attribute{"test3", std::span<const std::string_view>{details::ArgArray_14388086737368975987}});

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
/****************************** pf::SomeEnum::Value1 END ******************************/

/****************************** pf::SomeEnum::Value2 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x661598fd74c60228u, 0x21d413c2a6b248efu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x661598fd74c60228u, 0x21d413c2a6b248efu};
    constexpr static ID TypeID = pf::meta::ID{0xaf0caf3f0aba7704u, 0xa088b08065d55019u};
    using Type = pf::SomeEnum;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

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
/****************************** pf::SomeEnum::Value2 END ******************************/

/****************************** pf::SomeEnum START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xaf0caf3f0aba7704u, 0xa088b08065d55019u}> {
    struct details {
        
    };
    using Type = pf::SomeEnum;
    constexpr static ID TypeID = pf::meta::ID{0xaf0caf3f0aba7704u, 0xa088b08065d55019u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"SomeEnum"};
    constexpr static auto FullName = pf::StringLiteral{"pf::SomeEnum"};

    using UnderlyingType = bool;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0xeb2cd4ddeafa176cu, 0xcdb3481198571082u}, pf::meta::ID{0x661598fd74c60228u, 0x21d413c2a6b248efu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x773af70ff4378abbu, 0x8440eda295a55337u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0x773af70ff4378abbu, 0x8440eda295a55337u}, pf::meta::ID{0xaf0caf3f0aba7704u, 0xa088b08065d55019u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xf1a837737673583u, 0x497d14d68497a251u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0xf1a837737673583u, 0x497d14d68497a251u}, pf::meta::ID{0xaf0caf3f0aba7704u, 0xa088b08065d55019u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x84fea49c5af371fu, 0x918c1154d4aeda80u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0x84fea49c5af371fu, 0x918c1154d4aeda80u}, pf::meta::ID{0xaf0caf3f0aba7704u, 0xa088b08065d55019u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xa1b6a891401fbea3u, 0xcb2aa081cfe7cbau}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0xa1b6a891401fbea3u, 0xcb2aa081cfe7cbau}, pf::meta::ID{0xaf0caf3f0aba7704u, 0xa088b08065d55019u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xcb4a2fb8abe31e0u, 0xf8bb3fa105797e52u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0xcb4a2fb8abe31e0u, 0xf8bb3fa105797e52u}, pf::meta::ID{0xaf0caf3f0aba7704u, 0xa088b08065d55019u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xcdedf8d931f8f093u, 0x15fa8c91faaa846fu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0xcdedf8d931f8f093u, 0x15fa8c91faaa846fu}, pf::meta::ID{0xaf0caf3f0aba7704u, 0xa088b08065d55019u}> {};

/****************************** pf::SomeEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::SomeEnum START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum>() {
    return pf::meta::ID{0xaf0caf3f0aba7704u, 0xa088b08065d55019u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum>() {
    return pf::meta::ID{0x773af70ff4378abbu, 0x8440eda295a55337u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum &>() {
    return pf::meta::ID{0xf1a837737673583u, 0x497d14d68497a251u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum &&>() {
    return pf::meta::ID{0x84fea49c5af371fu, 0x918c1154d4aeda80u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum &>() {
    return pf::meta::ID{0xa1b6a891401fbea3u, 0xcb2aa081cfe7cbau};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum *>() {
    return pf::meta::ID{0xcb4a2fb8abe31e0u, 0xf8bb3fa105797e52u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum *>() {
    return pf::meta::ID{0xcdedf8d931f8f093u, 0x15fa8c91faaa846fu};
}
/****************************** pf::SomeEnum END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value1 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value1>() {
return pf::meta::ID{0xeb2cd4ddeafa176cu, 0xcdb3481198571082u};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value1 END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value2 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value2>() {
return pf::meta::ID{0x661598fd74c60228u, 0x21d413c2a6b248efu};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value2 END ******************************/
}
/****************************** pf::Test::E::Value1 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x60e4a887841ff40cu, 0x18e45603f327a8a5u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x60e4a887841ff40cu, 0x18e45603f327a8a5u};
    constexpr static ID TypeID = pf::meta::ID{0xb1cad1167f5c73bfu, 0x1b87ed5825d6f312u};
    using Type = pf::Test::E;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 8;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"Value1"};
    constexpr static auto FullName = StringLiteral{"pf::Test::E::Value1"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::Test::E Value = pf::Test::E::Value1;
};
/****************************** pf::Test::E::Value1 END ******************************/

/****************************** pf::Test::E::Value2 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x6557610b32f1ac5du, 0xff6de01f67dfa4a4u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x6557610b32f1ac5du, 0xff6de01f67dfa4a4u};
    constexpr static ID TypeID = pf::meta::ID{0xb1cad1167f5c73bfu, 0x1b87ed5825d6f312u};
    using Type = pf::Test::E;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 8;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"Value2"};
    constexpr static auto FullName = StringLiteral{"pf::Test::E::Value2"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::Test::E Value = pf::Test::E::Value2;
};
/****************************** pf::Test::E::Value2 END ******************************/

/****************************** pf::Test::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xb1cad1167f5c73bfu, 0x1b87ed5825d6f312u}> {
    struct details {
        
    };
    using Type = pf::Test::E;
    constexpr static ID TypeID = pf::meta::ID{0xb1cad1167f5c73bfu, 0x1b87ed5825d6f312u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 8;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E"};
    constexpr static auto FullName = pf::StringLiteral{"pf::Test::E"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0x60e4a887841ff40cu, 0x18e45603f327a8a5u}, pf::meta::ID{0x6557610b32f1ac5du, 0xff6de01f67dfa4a4u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x41a7a41b4bdee1f8u, 0x385d4fdd3897784au}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0x41a7a41b4bdee1f8u, 0x385d4fdd3897784au}, pf::meta::ID{0xb1cad1167f5c73bfu, 0x1b87ed5825d6f312u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x70fd64f0fe456deau, 0x6e922470715d15ffu}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0x70fd64f0fe456deau, 0x6e922470715d15ffu}, pf::meta::ID{0xb1cad1167f5c73bfu, 0x1b87ed5825d6f312u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xc4ed819c81ca329bu, 0x8ce015d611e86c6fu}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0xc4ed819c81ca329bu, 0x8ce015d611e86c6fu}, pf::meta::ID{0xb1cad1167f5c73bfu, 0x1b87ed5825d6f312u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x8932b3b96fd16e45u, 0x8b26ef930e2e2c2du}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0x8932b3b96fd16e45u, 0x8b26ef930e2e2c2du}, pf::meta::ID{0xb1cad1167f5c73bfu, 0x1b87ed5825d6f312u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xa5ac4b67a741c4f0u, 0x2756338dd5b62a3bu}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0xa5ac4b67a741c4f0u, 0x2756338dd5b62a3bu}, pf::meta::ID{0xb1cad1167f5c73bfu, 0x1b87ed5825d6f312u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x58c93b72c08027e8u, 0xa6e69dfd63075cbau}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0x58c93b72c08027e8u, 0xa6e69dfd63075cbau}, pf::meta::ID{0xb1cad1167f5c73bfu, 0x1b87ed5825d6f312u}> {};

/****************************** pf::Test::E END ******************************/
namespace pf::meta::details {
/****************************** pf::Test::E START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E>() {
    return pf::meta::ID{0xb1cad1167f5c73bfu, 0x1b87ed5825d6f312u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E>() {
    return pf::meta::ID{0x41a7a41b4bdee1f8u, 0x385d4fdd3897784au};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E &>() {
    return pf::meta::ID{0x70fd64f0fe456deau, 0x6e922470715d15ffu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E &&>() {
    return pf::meta::ID{0xc4ed819c81ca329bu, 0x8ce015d611e86c6fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E &>() {
    return pf::meta::ID{0x8932b3b96fd16e45u, 0x8b26ef930e2e2c2du};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E *>() {
    return pf::meta::ID{0xa5ac4b67a741c4f0u, 0x2756338dd5b62a3bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E *>() {
    return pf::meta::ID{0x58c93b72c08027e8u, 0xa6e69dfd63075cbau};
}
/****************************** pf::Test::E END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value1 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::Test::E::Value1>() {
return pf::meta::ID{0x60e4a887841ff40cu, 0x18e45603f327a8a5u};
}
/****************************** pf::Test::E::pf::Test::E::Value1 END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value2 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::Test::E::Value2>() {
return pf::meta::ID{0x6557610b32f1ac5du, 0xff6de01f67dfa4a4u};
}
/****************************** pf::Test::E::pf::Test::E::Value2 END ******************************/
}
/****************************** pf::EmptyEnum START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xead764d3b03b944bu, 0x1dcfed01f5bf1cf8u}> {
    struct details {
        
    };
    using Type = pf::EmptyEnum;
    constexpr static ID TypeID = pf::meta::ID{0xead764d3b03b944bu, 0x1dcfed01f5bf1cf8u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 19;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"EmptyEnum"};
    constexpr static auto FullName = pf::StringLiteral{"pf::EmptyEnum"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>();
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7d67c1f07c11a431u, 0x75d4b8c66e1fa093u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0x7d67c1f07c11a431u, 0x75d4b8c66e1fa093u}, pf::meta::ID{0xead764d3b03b944bu, 0x1dcfed01f5bf1cf8u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x6d50bc329ea5dcfdu, 0xc38d7873a5925859u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0x6d50bc329ea5dcfdu, 0xc38d7873a5925859u}, pf::meta::ID{0xead764d3b03b944bu, 0x1dcfed01f5bf1cf8u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x62f9f6f52c58c13eu, 0xade4f5e3dc8a238cu}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0x62f9f6f52c58c13eu, 0xade4f5e3dc8a238cu}, pf::meta::ID{0xead764d3b03b944bu, 0x1dcfed01f5bf1cf8u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xbaf2ae8bfec1f6d0u, 0xe83a943abe095cfeu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0xbaf2ae8bfec1f6d0u, 0xe83a943abe095cfeu}, pf::meta::ID{0xead764d3b03b944bu, 0x1dcfed01f5bf1cf8u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7bd185a2bbf968efu, 0x339f3056737d392u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x7bd185a2bbf968efu, 0x339f3056737d392u}, pf::meta::ID{0xead764d3b03b944bu, 0x1dcfed01f5bf1cf8u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x37a6bd66987bfdb1u, 0xf43a81b2f25d0fb1u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0x37a6bd66987bfdb1u, 0xf43a81b2f25d0fb1u}, pf::meta::ID{0xead764d3b03b944bu, 0x1dcfed01f5bf1cf8u}> {};

/****************************** pf::EmptyEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::EmptyEnum START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum>() {
    return pf::meta::ID{0xead764d3b03b944bu, 0x1dcfed01f5bf1cf8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum>() {
    return pf::meta::ID{0x7d67c1f07c11a431u, 0x75d4b8c66e1fa093u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &>() {
    return pf::meta::ID{0x6d50bc329ea5dcfdu, 0xc38d7873a5925859u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &&>() {
    return pf::meta::ID{0x62f9f6f52c58c13eu, 0xade4f5e3dc8a238cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum &>() {
    return pf::meta::ID{0xbaf2ae8bfec1f6d0u, 0xe83a943abe095cfeu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum *>() {
    return pf::meta::ID{0x7bd185a2bbf968efu, 0x339f3056737d392u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum *>() {
    return pf::meta::ID{0x37a6bd66987bfdb1u, 0xf43a81b2f25d0fb1u};
}
/****************************** pf::EmptyEnum END ******************************/
}
/****************************** pf::E1::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xe6c1e59d7ae3c815u, 0xc115d6dbff5dbd7bu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xe6c1e59d7ae3c815u, 0xc115d6dbff5dbd7bu};
    constexpr static ID TypeID = pf::meta::ID{0x992ca37dcc214245u, 0xef5ec52e1da23ebau};
    using Type = pf::E1;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E1::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E1 Value = pf::E1::A;
};
/****************************** pf::E1::A END ******************************/

/****************************** pf::E1::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xaac851a93cec2a6eu, 0x5345f5d699af80a0u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xaac851a93cec2a6eu, 0x5345f5d699af80a0u};
    constexpr static ID TypeID = pf::meta::ID{0x992ca37dcc214245u, 0xef5ec52e1da23ebau};
    using Type = pf::E1;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E1::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E1 Value = pf::E1::B;
};
/****************************** pf::E1::B END ******************************/

/****************************** pf::E1::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x21efa3d377469cb0u, 0xc108681c95bf933bu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x21efa3d377469cb0u, 0xc108681c95bf933bu};
    constexpr static ID TypeID = pf::meta::ID{0x992ca37dcc214245u, 0xef5ec52e1da23ebau};
    using Type = pf::E1;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E1::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E1 Value = pf::E1::C;
};
/****************************** pf::E1::C END ******************************/

/****************************** pf::E1::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7300029d66b0fdbdu, 0xf22fa48c59638cb2u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x7300029d66b0fdbdu, 0xf22fa48c59638cb2u};
    constexpr static ID TypeID = pf::meta::ID{0x992ca37dcc214245u, 0xef5ec52e1da23ebau};
    using Type = pf::E1;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E1::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E1 Value = pf::E1::D;
};
/****************************** pf::E1::D END ******************************/

/****************************** pf::E1::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x3f68aebb654c773au, 0x4d6e8ff2acd5158u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x3f68aebb654c773au, 0x4d6e8ff2acd5158u};
    constexpr static ID TypeID = pf::meta::ID{0x992ca37dcc214245u, 0xef5ec52e1da23ebau};
    using Type = pf::E1;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E1::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E1 Value = pf::E1::E;
};
/****************************** pf::E1::E END ******************************/

/****************************** pf::E1 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x992ca37dcc214245u, 0xef5ec52e1da23ebau}> {
    struct details {
        
    };
    using Type = pf::E1;
    constexpr static ID TypeID = pf::meta::ID{0x992ca37dcc214245u, 0xef5ec52e1da23ebau};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E1"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E1"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0xe6c1e59d7ae3c815u, 0xc115d6dbff5dbd7bu}, pf::meta::ID{0xaac851a93cec2a6eu, 0x5345f5d699af80a0u}, pf::meta::ID{0x21efa3d377469cb0u, 0xc108681c95bf933bu}, pf::meta::ID{0x7300029d66b0fdbdu, 0xf22fa48c59638cb2u}, pf::meta::ID{0x3f68aebb654c773au, 0x4d6e8ff2acd5158u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xcb199fbc5e77318eu, 0x68787c0d087eae04u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0xcb199fbc5e77318eu, 0x68787c0d087eae04u}, pf::meta::ID{0x992ca37dcc214245u, 0xef5ec52e1da23ebau}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x964ec4bad9f081bu, 0x7cde27bf2385a35au}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0x964ec4bad9f081bu, 0x7cde27bf2385a35au}, pf::meta::ID{0x992ca37dcc214245u, 0xef5ec52e1da23ebau}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x6d93f606573a31d3u, 0xa8b2cda989af93d2u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0x6d93f606573a31d3u, 0xa8b2cda989af93d2u}, pf::meta::ID{0x992ca37dcc214245u, 0xef5ec52e1da23ebau}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x437a774d664c4aeeu, 0xdbc54f949e12a836u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0x437a774d664c4aeeu, 0xdbc54f949e12a836u}, pf::meta::ID{0x992ca37dcc214245u, 0xef5ec52e1da23ebau}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x241c3cd3e3eefa38u, 0xd2c6a29f99911fc7u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x241c3cd3e3eefa38u, 0xd2c6a29f99911fc7u}, pf::meta::ID{0x992ca37dcc214245u, 0xef5ec52e1da23ebau}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xba20b2f25ecb7a9u, 0xc42aa4a6788ba088u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0xba20b2f25ecb7a9u, 0xc42aa4a6788ba088u}, pf::meta::ID{0x992ca37dcc214245u, 0xef5ec52e1da23ebau}> {};

/****************************** pf::E1 END ******************************/
namespace pf::meta::details {
/****************************** pf::E1 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1>() {
    return pf::meta::ID{0x992ca37dcc214245u, 0xef5ec52e1da23ebau};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1>() {
    return pf::meta::ID{0xcb199fbc5e77318eu, 0x68787c0d087eae04u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 &>() {
    return pf::meta::ID{0x964ec4bad9f081bu, 0x7cde27bf2385a35au};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 &&>() {
    return pf::meta::ID{0x6d93f606573a31d3u, 0xa8b2cda989af93d2u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1 &>() {
    return pf::meta::ID{0x437a774d664c4aeeu, 0xdbc54f949e12a836u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 *>() {
    return pf::meta::ID{0x241c3cd3e3eefa38u, 0xd2c6a29f99911fc7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1 *>() {
    return pf::meta::ID{0xba20b2f25ecb7a9u, 0xc42aa4a6788ba088u};
}
/****************************** pf::E1 END ******************************/

/****************************** pf::E1::pf::E1::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::A>() {
return pf::meta::ID{0xe6c1e59d7ae3c815u, 0xc115d6dbff5dbd7bu};
}
/****************************** pf::E1::pf::E1::A END ******************************/

/****************************** pf::E1::pf::E1::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::B>() {
return pf::meta::ID{0xaac851a93cec2a6eu, 0x5345f5d699af80a0u};
}
/****************************** pf::E1::pf::E1::B END ******************************/

/****************************** pf::E1::pf::E1::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::C>() {
return pf::meta::ID{0x21efa3d377469cb0u, 0xc108681c95bf933bu};
}
/****************************** pf::E1::pf::E1::C END ******************************/

/****************************** pf::E1::pf::E1::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::D>() {
return pf::meta::ID{0x7300029d66b0fdbdu, 0xf22fa48c59638cb2u};
}
/****************************** pf::E1::pf::E1::D END ******************************/

/****************************** pf::E1::pf::E1::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::E>() {
return pf::meta::ID{0x3f68aebb654c773au, 0x4d6e8ff2acd5158u};
}
/****************************** pf::E1::pf::E1::E END ******************************/
}
/****************************** pf::E2::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x93cf1454404a39c9u, 0xb9c9eb851649aa95u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x93cf1454404a39c9u, 0xb9c9eb851649aa95u};
    constexpr static ID TypeID = pf::meta::ID{0xd5db64840602b790u, 0x97f805a1c13de606u};
    using Type = pf::E2;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E2::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E2 Value = pf::E2::A;
};
/****************************** pf::E2::A END ******************************/

/****************************** pf::E2::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xf13fd1eb09e45cc0u, 0x821a01feabbe618fu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xf13fd1eb09e45cc0u, 0x821a01feabbe618fu};
    constexpr static ID TypeID = pf::meta::ID{0xd5db64840602b790u, 0x97f805a1c13de606u};
    using Type = pf::E2;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E2::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E2 Value = pf::E2::B;
};
/****************************** pf::E2::B END ******************************/

/****************************** pf::E2::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xfcd7907ff161203eu, 0x6931cbdb7377eebdu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xfcd7907ff161203eu, 0x6931cbdb7377eebdu};
    constexpr static ID TypeID = pf::meta::ID{0xd5db64840602b790u, 0x97f805a1c13de606u};
    using Type = pf::E2;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E2::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E2 Value = pf::E2::C;
};
/****************************** pf::E2::C END ******************************/

/****************************** pf::E2::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x9aa7209c0004d55au, 0xe9f3f9951bf6c067u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x9aa7209c0004d55au, 0xe9f3f9951bf6c067u};
    constexpr static ID TypeID = pf::meta::ID{0xd5db64840602b790u, 0x97f805a1c13de606u};
    using Type = pf::E2;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E2::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E2 Value = pf::E2::D;
};
/****************************** pf::E2::D END ******************************/

/****************************** pf::E2::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x56c7f1f97d5b1582u, 0x1ca65eeabd9f078fu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x56c7f1f97d5b1582u, 0x1ca65eeabd9f078fu};
    constexpr static ID TypeID = pf::meta::ID{0xd5db64840602b790u, 0x97f805a1c13de606u};
    using Type = pf::E2;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E2::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E2 Value = pf::E2::E;
};
/****************************** pf::E2::E END ******************************/

/****************************** pf::E2 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xd5db64840602b790u, 0x97f805a1c13de606u}> {
    struct details {
        
    };
    using Type = pf::E2;
    constexpr static ID TypeID = pf::meta::ID{0xd5db64840602b790u, 0x97f805a1c13de606u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E2"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E2"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0x93cf1454404a39c9u, 0xb9c9eb851649aa95u}, pf::meta::ID{0xf13fd1eb09e45cc0u, 0x821a01feabbe618fu}, pf::meta::ID{0xfcd7907ff161203eu, 0x6931cbdb7377eebdu}, pf::meta::ID{0x9aa7209c0004d55au, 0xe9f3f9951bf6c067u}, pf::meta::ID{0x56c7f1f97d5b1582u, 0x1ca65eeabd9f078fu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xacda7ce4bdb06c00u, 0x8f8626db85c86bb9u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0xacda7ce4bdb06c00u, 0x8f8626db85c86bb9u}, pf::meta::ID{0xd5db64840602b790u, 0x97f805a1c13de606u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x6ed408f97e9e7c70u, 0x13a94a5beb400a62u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0x6ed408f97e9e7c70u, 0x13a94a5beb400a62u}, pf::meta::ID{0xd5db64840602b790u, 0x97f805a1c13de606u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xa3564e240e76b2bu, 0x320d2af1f48a484u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0xa3564e240e76b2bu, 0x320d2af1f48a484u}, pf::meta::ID{0xd5db64840602b790u, 0x97f805a1c13de606u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xc48f3623dec69176u, 0x31857043f52cca4bu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0xc48f3623dec69176u, 0x31857043f52cca4bu}, pf::meta::ID{0xd5db64840602b790u, 0x97f805a1c13de606u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xc34fbc9cec053dd0u, 0x1e71e8f93cb28940u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0xc34fbc9cec053dd0u, 0x1e71e8f93cb28940u}, pf::meta::ID{0xd5db64840602b790u, 0x97f805a1c13de606u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xd7e013f8dc28d578u, 0x6cada5455f288752u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0xd7e013f8dc28d578u, 0x6cada5455f288752u}, pf::meta::ID{0xd5db64840602b790u, 0x97f805a1c13de606u}> {};

/****************************** pf::E2 END ******************************/
namespace pf::meta::details {
/****************************** pf::E2 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2>() {
    return pf::meta::ID{0xd5db64840602b790u, 0x97f805a1c13de606u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2>() {
    return pf::meta::ID{0xacda7ce4bdb06c00u, 0x8f8626db85c86bb9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 &>() {
    return pf::meta::ID{0x6ed408f97e9e7c70u, 0x13a94a5beb400a62u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 &&>() {
    return pf::meta::ID{0xa3564e240e76b2bu, 0x320d2af1f48a484u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2 &>() {
    return pf::meta::ID{0xc48f3623dec69176u, 0x31857043f52cca4bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 *>() {
    return pf::meta::ID{0xc34fbc9cec053dd0u, 0x1e71e8f93cb28940u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2 *>() {
    return pf::meta::ID{0xd7e013f8dc28d578u, 0x6cada5455f288752u};
}
/****************************** pf::E2 END ******************************/

/****************************** pf::E2::pf::E2::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::A>() {
return pf::meta::ID{0x93cf1454404a39c9u, 0xb9c9eb851649aa95u};
}
/****************************** pf::E2::pf::E2::A END ******************************/

/****************************** pf::E2::pf::E2::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::B>() {
return pf::meta::ID{0xf13fd1eb09e45cc0u, 0x821a01feabbe618fu};
}
/****************************** pf::E2::pf::E2::B END ******************************/

/****************************** pf::E2::pf::E2::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::C>() {
return pf::meta::ID{0xfcd7907ff161203eu, 0x6931cbdb7377eebdu};
}
/****************************** pf::E2::pf::E2::C END ******************************/

/****************************** pf::E2::pf::E2::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::D>() {
return pf::meta::ID{0x9aa7209c0004d55au, 0xe9f3f9951bf6c067u};
}
/****************************** pf::E2::pf::E2::D END ******************************/

/****************************** pf::E2::pf::E2::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::E>() {
return pf::meta::ID{0x56c7f1f97d5b1582u, 0x1ca65eeabd9f078fu};
}
/****************************** pf::E2::pf::E2::E END ******************************/
}
/****************************** pf::E3::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x92816d4def4a354eu, 0x7db213e5c1e1cc97u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x92816d4def4a354eu, 0x7db213e5c1e1cc97u};
    constexpr static ID TypeID = pf::meta::ID{0x1a7164dff64f3b1fu, 0x3b812c3ce8cebcc9u};
    using Type = pf::E3;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E3::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E3 Value = pf::E3::A;
};
/****************************** pf::E3::A END ******************************/

/****************************** pf::E3::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7ddc22b9ccf74c8eu, 0x436081628ebcfc9bu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x7ddc22b9ccf74c8eu, 0x436081628ebcfc9bu};
    constexpr static ID TypeID = pf::meta::ID{0x1a7164dff64f3b1fu, 0x3b812c3ce8cebcc9u};
    using Type = pf::E3;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E3::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E3 Value = pf::E3::B;
};
/****************************** pf::E3::B END ******************************/

/****************************** pf::E3::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x4980b097a710fdeau, 0xfc1e00ea2a014182u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x4980b097a710fdeau, 0xfc1e00ea2a014182u};
    constexpr static ID TypeID = pf::meta::ID{0x1a7164dff64f3b1fu, 0x3b812c3ce8cebcc9u};
    using Type = pf::E3;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E3::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E3 Value = pf::E3::C;
};
/****************************** pf::E3::C END ******************************/

/****************************** pf::E3::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x1cc70e3e7881097cu, 0x7c09974f47ee3059u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x1cc70e3e7881097cu, 0x7c09974f47ee3059u};
    constexpr static ID TypeID = pf::meta::ID{0x1a7164dff64f3b1fu, 0x3b812c3ce8cebcc9u};
    using Type = pf::E3;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E3::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E3 Value = pf::E3::D;
};
/****************************** pf::E3::D END ******************************/

/****************************** pf::E3::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x8a4037680307c65u, 0x3fbff4fe1ffca1f0u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x8a4037680307c65u, 0x3fbff4fe1ffca1f0u};
    constexpr static ID TypeID = pf::meta::ID{0x1a7164dff64f3b1fu, 0x3b812c3ce8cebcc9u};
    using Type = pf::E3;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E3::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E3 Value = pf::E3::E;
};
/****************************** pf::E3::E END ******************************/

/****************************** pf::E3 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x1a7164dff64f3b1fu, 0x3b812c3ce8cebcc9u}> {
    struct details {
        
    };
    using Type = pf::E3;
    constexpr static ID TypeID = pf::meta::ID{0x1a7164dff64f3b1fu, 0x3b812c3ce8cebcc9u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E3"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E3"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0x92816d4def4a354eu, 0x7db213e5c1e1cc97u}, pf::meta::ID{0x7ddc22b9ccf74c8eu, 0x436081628ebcfc9bu}, pf::meta::ID{0x4980b097a710fdeau, 0xfc1e00ea2a014182u}, pf::meta::ID{0x1cc70e3e7881097cu, 0x7c09974f47ee3059u}, pf::meta::ID{0x8a4037680307c65u, 0x3fbff4fe1ffca1f0u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xdb2547cc6dca706cu, 0x3c69ceb69cc7ce5du}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0xdb2547cc6dca706cu, 0x3c69ceb69cc7ce5du}, pf::meta::ID{0x1a7164dff64f3b1fu, 0x3b812c3ce8cebcc9u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x37f78eaf7d72310du, 0x645dff9afd04d587u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0x37f78eaf7d72310du, 0x645dff9afd04d587u}, pf::meta::ID{0x1a7164dff64f3b1fu, 0x3b812c3ce8cebcc9u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x46ade20902f80d9du, 0x5c6cc404a0976bb5u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0x46ade20902f80d9du, 0x5c6cc404a0976bb5u}, pf::meta::ID{0x1a7164dff64f3b1fu, 0x3b812c3ce8cebcc9u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x83940483410141c6u, 0x8ed79bfd982166a2u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0x83940483410141c6u, 0x8ed79bfd982166a2u}, pf::meta::ID{0x1a7164dff64f3b1fu, 0x3b812c3ce8cebcc9u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x1cf00966fb43a90eu, 0x4dd51350ee38fdccu}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x1cf00966fb43a90eu, 0x4dd51350ee38fdccu}, pf::meta::ID{0x1a7164dff64f3b1fu, 0x3b812c3ce8cebcc9u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xa0d59c250ab981d4u, 0x9431990f162b06b3u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0xa0d59c250ab981d4u, 0x9431990f162b06b3u}, pf::meta::ID{0x1a7164dff64f3b1fu, 0x3b812c3ce8cebcc9u}> {};

/****************************** pf::E3 END ******************************/
namespace pf::meta::details {
/****************************** pf::E3 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3>() {
    return pf::meta::ID{0x1a7164dff64f3b1fu, 0x3b812c3ce8cebcc9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3>() {
    return pf::meta::ID{0xdb2547cc6dca706cu, 0x3c69ceb69cc7ce5du};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 &>() {
    return pf::meta::ID{0x37f78eaf7d72310du, 0x645dff9afd04d587u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 &&>() {
    return pf::meta::ID{0x46ade20902f80d9du, 0x5c6cc404a0976bb5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3 &>() {
    return pf::meta::ID{0x83940483410141c6u, 0x8ed79bfd982166a2u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 *>() {
    return pf::meta::ID{0x1cf00966fb43a90eu, 0x4dd51350ee38fdccu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3 *>() {
    return pf::meta::ID{0xa0d59c250ab981d4u, 0x9431990f162b06b3u};
}
/****************************** pf::E3 END ******************************/

/****************************** pf::E3::pf::E3::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::A>() {
return pf::meta::ID{0x92816d4def4a354eu, 0x7db213e5c1e1cc97u};
}
/****************************** pf::E3::pf::E3::A END ******************************/

/****************************** pf::E3::pf::E3::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::B>() {
return pf::meta::ID{0x7ddc22b9ccf74c8eu, 0x436081628ebcfc9bu};
}
/****************************** pf::E3::pf::E3::B END ******************************/

/****************************** pf::E3::pf::E3::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::C>() {
return pf::meta::ID{0x4980b097a710fdeau, 0xfc1e00ea2a014182u};
}
/****************************** pf::E3::pf::E3::C END ******************************/

/****************************** pf::E3::pf::E3::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::D>() {
return pf::meta::ID{0x1cc70e3e7881097cu, 0x7c09974f47ee3059u};
}
/****************************** pf::E3::pf::E3::D END ******************************/

/****************************** pf::E3::pf::E3::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::E>() {
return pf::meta::ID{0x8a4037680307c65u, 0x3fbff4fe1ffca1f0u};
}
/****************************** pf::E3::pf::E3::E END ******************************/
}
/****************************** pf::E4::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x6db12038066c3d7cu, 0xab986bba712e9bc1u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x6db12038066c3d7cu, 0xab986bba712e9bc1u};
    constexpr static ID TypeID = pf::meta::ID{0x22b6cf478ce36377u, 0x9cee23ad158b62edu};
    using Type = pf::E4;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E4::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E4 Value = pf::E4::A;
};
/****************************** pf::E4::A END ******************************/

/****************************** pf::E4::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x16e034ba0282b837u, 0xa3588d203ff02013u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x16e034ba0282b837u, 0xa3588d203ff02013u};
    constexpr static ID TypeID = pf::meta::ID{0x22b6cf478ce36377u, 0x9cee23ad158b62edu};
    using Type = pf::E4;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E4::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E4 Value = pf::E4::B;
};
/****************************** pf::E4::B END ******************************/

/****************************** pf::E4::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x45684a466fd07777u, 0xc060073314ad166du}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x45684a466fd07777u, 0xc060073314ad166du};
    constexpr static ID TypeID = pf::meta::ID{0x22b6cf478ce36377u, 0x9cee23ad158b62edu};
    using Type = pf::E4;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E4::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E4 Value = pf::E4::C;
};
/****************************** pf::E4::C END ******************************/

/****************************** pf::E4::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x90d651302bf247a2u, 0xcb9f4e935657fedeu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x90d651302bf247a2u, 0xcb9f4e935657fedeu};
    constexpr static ID TypeID = pf::meta::ID{0x22b6cf478ce36377u, 0x9cee23ad158b62edu};
    using Type = pf::E4;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E4::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E4 Value = pf::E4::D;
};
/****************************** pf::E4::D END ******************************/

/****************************** pf::E4::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x6a5fa612b4d7bdfcu, 0x2a4d923a0d3a4c08u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x6a5fa612b4d7bdfcu, 0x2a4d923a0d3a4c08u};
    constexpr static ID TypeID = pf::meta::ID{0x22b6cf478ce36377u, 0x9cee23ad158b62edu};
    using Type = pf::E4;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E4::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E4 Value = pf::E4::E;
};
/****************************** pf::E4::E END ******************************/

/****************************** pf::E4 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x22b6cf478ce36377u, 0x9cee23ad158b62edu}> {
    struct details {
        
    };
    using Type = pf::E4;
    constexpr static ID TypeID = pf::meta::ID{0x22b6cf478ce36377u, 0x9cee23ad158b62edu};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E4"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E4"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0x6db12038066c3d7cu, 0xab986bba712e9bc1u}, pf::meta::ID{0x16e034ba0282b837u, 0xa3588d203ff02013u}, pf::meta::ID{0x45684a466fd07777u, 0xc060073314ad166du}, pf::meta::ID{0x90d651302bf247a2u, 0xcb9f4e935657fedeu}, pf::meta::ID{0x6a5fa612b4d7bdfcu, 0x2a4d923a0d3a4c08u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7f103c352f4bdfb5u, 0xa95647bb0af1b6deu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0x7f103c352f4bdfb5u, 0xa95647bb0af1b6deu}, pf::meta::ID{0x22b6cf478ce36377u, 0x9cee23ad158b62edu}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xb53aa66462b0a44bu, 0x81727f92365850d9u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0xb53aa66462b0a44bu, 0x81727f92365850d9u}, pf::meta::ID{0x22b6cf478ce36377u, 0x9cee23ad158b62edu}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xe58ef8a0c7679c85u, 0xe37226e8a8892ff0u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0xe58ef8a0c7679c85u, 0xe37226e8a8892ff0u}, pf::meta::ID{0x22b6cf478ce36377u, 0x9cee23ad158b62edu}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x4b310f632ee267e8u, 0xbf2eb7d0b588b762u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0x4b310f632ee267e8u, 0xbf2eb7d0b588b762u}, pf::meta::ID{0x22b6cf478ce36377u, 0x9cee23ad158b62edu}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x8ef5fc97b5787dcdu, 0xc026392512327475u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x8ef5fc97b5787dcdu, 0xc026392512327475u}, pf::meta::ID{0x22b6cf478ce36377u, 0x9cee23ad158b62edu}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7635ad93a47f35e3u, 0xc586d257af3e13c5u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0x7635ad93a47f35e3u, 0xc586d257af3e13c5u}, pf::meta::ID{0x22b6cf478ce36377u, 0x9cee23ad158b62edu}> {};

/****************************** pf::E4 END ******************************/
namespace pf::meta::details {
/****************************** pf::E4 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4>() {
    return pf::meta::ID{0x22b6cf478ce36377u, 0x9cee23ad158b62edu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4>() {
    return pf::meta::ID{0x7f103c352f4bdfb5u, 0xa95647bb0af1b6deu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 &>() {
    return pf::meta::ID{0xb53aa66462b0a44bu, 0x81727f92365850d9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 &&>() {
    return pf::meta::ID{0xe58ef8a0c7679c85u, 0xe37226e8a8892ff0u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4 &>() {
    return pf::meta::ID{0x4b310f632ee267e8u, 0xbf2eb7d0b588b762u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 *>() {
    return pf::meta::ID{0x8ef5fc97b5787dcdu, 0xc026392512327475u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4 *>() {
    return pf::meta::ID{0x7635ad93a47f35e3u, 0xc586d257af3e13c5u};
}
/****************************** pf::E4 END ******************************/

/****************************** pf::E4::pf::E4::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::A>() {
return pf::meta::ID{0x6db12038066c3d7cu, 0xab986bba712e9bc1u};
}
/****************************** pf::E4::pf::E4::A END ******************************/

/****************************** pf::E4::pf::E4::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::B>() {
return pf::meta::ID{0x16e034ba0282b837u, 0xa3588d203ff02013u};
}
/****************************** pf::E4::pf::E4::B END ******************************/

/****************************** pf::E4::pf::E4::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::C>() {
return pf::meta::ID{0x45684a466fd07777u, 0xc060073314ad166du};
}
/****************************** pf::E4::pf::E4::C END ******************************/

/****************************** pf::E4::pf::E4::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::D>() {
return pf::meta::ID{0x90d651302bf247a2u, 0xcb9f4e935657fedeu};
}
/****************************** pf::E4::pf::E4::D END ******************************/

/****************************** pf::E4::pf::E4::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::E>() {
return pf::meta::ID{0x6a5fa612b4d7bdfcu, 0x2a4d923a0d3a4c08u};
}
/****************************** pf::E4::pf::E4::E END ******************************/
}
/****************************** pf::E5::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xe96af662c2992cb6u, 0xb36656593411665u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xe96af662c2992cb6u, 0xb36656593411665u};
    constexpr static ID TypeID = pf::meta::ID{0xb001d6e8a84a859fu, 0x6badb7d240649a72u};
    using Type = pf::E5;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E5::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E5 Value = pf::E5::A;
};
/****************************** pf::E5::A END ******************************/

/****************************** pf::E5::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x70872f502369f61bu, 0x466160b350239077u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x70872f502369f61bu, 0x466160b350239077u};
    constexpr static ID TypeID = pf::meta::ID{0xb001d6e8a84a859fu, 0x6badb7d240649a72u};
    using Type = pf::E5;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E5::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E5 Value = pf::E5::B;
};
/****************************** pf::E5::B END ******************************/

/****************************** pf::E5::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x24263b0708fced6fu, 0x14b8a297fd94d289u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x24263b0708fced6fu, 0x14b8a297fd94d289u};
    constexpr static ID TypeID = pf::meta::ID{0xb001d6e8a84a859fu, 0x6badb7d240649a72u};
    using Type = pf::E5;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E5::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E5 Value = pf::E5::C;
};
/****************************** pf::E5::C END ******************************/

/****************************** pf::E5::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x5b401dd1b21d118u, 0x11b54cb4356c7e18u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x5b401dd1b21d118u, 0x11b54cb4356c7e18u};
    constexpr static ID TypeID = pf::meta::ID{0xb001d6e8a84a859fu, 0x6badb7d240649a72u};
    using Type = pf::E5;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E5::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E5 Value = pf::E5::D;
};
/****************************** pf::E5::D END ******************************/

/****************************** pf::E5::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x58a5f86745b0a512u, 0x8b423877b7292b68u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x58a5f86745b0a512u, 0x8b423877b7292b68u};
    constexpr static ID TypeID = pf::meta::ID{0xb001d6e8a84a859fu, 0x6badb7d240649a72u};
    using Type = pf::E5;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E5::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E5 Value = pf::E5::E;
};
/****************************** pf::E5::E END ******************************/

/****************************** pf::E5 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xb001d6e8a84a859fu, 0x6badb7d240649a72u}> {
    struct details {
        
    };
    using Type = pf::E5;
    constexpr static ID TypeID = pf::meta::ID{0xb001d6e8a84a859fu, 0x6badb7d240649a72u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E5"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E5"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0xe96af662c2992cb6u, 0xb36656593411665u}, pf::meta::ID{0x70872f502369f61bu, 0x466160b350239077u}, pf::meta::ID{0x24263b0708fced6fu, 0x14b8a297fd94d289u}, pf::meta::ID{0x5b401dd1b21d118u, 0x11b54cb4356c7e18u}, pf::meta::ID{0x58a5f86745b0a512u, 0x8b423877b7292b68u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x459f702e4bf697c4u, 0x5f5eeb6b911905cfu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0x459f702e4bf697c4u, 0x5f5eeb6b911905cfu}, pf::meta::ID{0xb001d6e8a84a859fu, 0x6badb7d240649a72u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x32b7aebf60e3d893u, 0xba49976f70747d76u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0x32b7aebf60e3d893u, 0xba49976f70747d76u}, pf::meta::ID{0xb001d6e8a84a859fu, 0x6badb7d240649a72u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xea5b11cbd9ab18fu, 0x351df33a0849d2e1u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0xea5b11cbd9ab18fu, 0x351df33a0849d2e1u}, pf::meta::ID{0xb001d6e8a84a859fu, 0x6badb7d240649a72u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7a99d6e4b3bd0f94u, 0xade6b0f07e263601u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0x7a99d6e4b3bd0f94u, 0xade6b0f07e263601u}, pf::meta::ID{0xb001d6e8a84a859fu, 0x6badb7d240649a72u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x136c05110bba6f49u, 0x961933e00a71bd23u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x136c05110bba6f49u, 0x961933e00a71bd23u}, pf::meta::ID{0xb001d6e8a84a859fu, 0x6badb7d240649a72u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xc13482fc48f80cbdu, 0xf26fd7ecb89da5ebu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0xc13482fc48f80cbdu, 0xf26fd7ecb89da5ebu}, pf::meta::ID{0xb001d6e8a84a859fu, 0x6badb7d240649a72u}> {};

/****************************** pf::E5 END ******************************/
namespace pf::meta::details {
/****************************** pf::E5 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5>() {
    return pf::meta::ID{0xb001d6e8a84a859fu, 0x6badb7d240649a72u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5>() {
    return pf::meta::ID{0x459f702e4bf697c4u, 0x5f5eeb6b911905cfu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 &>() {
    return pf::meta::ID{0x32b7aebf60e3d893u, 0xba49976f70747d76u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 &&>() {
    return pf::meta::ID{0xea5b11cbd9ab18fu, 0x351df33a0849d2e1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5 &>() {
    return pf::meta::ID{0x7a99d6e4b3bd0f94u, 0xade6b0f07e263601u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 *>() {
    return pf::meta::ID{0x136c05110bba6f49u, 0x961933e00a71bd23u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5 *>() {
    return pf::meta::ID{0xc13482fc48f80cbdu, 0xf26fd7ecb89da5ebu};
}
/****************************** pf::E5 END ******************************/

/****************************** pf::E5::pf::E5::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::A>() {
return pf::meta::ID{0xe96af662c2992cb6u, 0xb36656593411665u};
}
/****************************** pf::E5::pf::E5::A END ******************************/

/****************************** pf::E5::pf::E5::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::B>() {
return pf::meta::ID{0x70872f502369f61bu, 0x466160b350239077u};
}
/****************************** pf::E5::pf::E5::B END ******************************/

/****************************** pf::E5::pf::E5::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::C>() {
return pf::meta::ID{0x24263b0708fced6fu, 0x14b8a297fd94d289u};
}
/****************************** pf::E5::pf::E5::C END ******************************/

/****************************** pf::E5::pf::E5::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::D>() {
return pf::meta::ID{0x5b401dd1b21d118u, 0x11b54cb4356c7e18u};
}
/****************************** pf::E5::pf::E5::D END ******************************/

/****************************** pf::E5::pf::E5::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::E>() {
return pf::meta::ID{0x58a5f86745b0a512u, 0x8b423877b7292b68u};
}
/****************************** pf::E5::pf::E5::E END ******************************/
}
/****************************** pf::E6::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x9c50bd6fd12dfdb7u, 0xff4ed390c03b355au}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x9c50bd6fd12dfdb7u, 0xff4ed390c03b355au};
    constexpr static ID TypeID = pf::meta::ID{0xd2b696856b56de7bu, 0x1f83e4644d7d28bu};
    using Type = pf::E6;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E6::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E6 Value = pf::E6::A;
};
/****************************** pf::E6::A END ******************************/

/****************************** pf::E6::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7918dc0d4a28bfb4u, 0xf3f88acf79e06248u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x7918dc0d4a28bfb4u, 0xf3f88acf79e06248u};
    constexpr static ID TypeID = pf::meta::ID{0xd2b696856b56de7bu, 0x1f83e4644d7d28bu};
    using Type = pf::E6;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E6::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E6 Value = pf::E6::B;
};
/****************************** pf::E6::B END ******************************/

/****************************** pf::E6::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xed37bc6fef75a473u, 0xac4e33994208db25u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xed37bc6fef75a473u, 0xac4e33994208db25u};
    constexpr static ID TypeID = pf::meta::ID{0xd2b696856b56de7bu, 0x1f83e4644d7d28bu};
    using Type = pf::E6;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E6::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E6 Value = pf::E6::C;
};
/****************************** pf::E6::C END ******************************/

/****************************** pf::E6::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xa6174ce2723cf32bu, 0x2a77d5892a2bbfe2u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xa6174ce2723cf32bu, 0x2a77d5892a2bbfe2u};
    constexpr static ID TypeID = pf::meta::ID{0xd2b696856b56de7bu, 0x1f83e4644d7d28bu};
    using Type = pf::E6;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E6::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E6 Value = pf::E6::D;
};
/****************************** pf::E6::D END ******************************/

/****************************** pf::E6::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xec479cc0488270cu, 0xea0b310543798daau}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xec479cc0488270cu, 0xea0b310543798daau};
    constexpr static ID TypeID = pf::meta::ID{0xd2b696856b56de7bu, 0x1f83e4644d7d28bu};
    using Type = pf::E6;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E6::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E6 Value = pf::E6::E;
};
/****************************** pf::E6::E END ******************************/

/****************************** pf::E6 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xd2b696856b56de7bu, 0x1f83e4644d7d28bu}> {
    struct details {
        
    };
    using Type = pf::E6;
    constexpr static ID TypeID = pf::meta::ID{0xd2b696856b56de7bu, 0x1f83e4644d7d28bu};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E6"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E6"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0x9c50bd6fd12dfdb7u, 0xff4ed390c03b355au}, pf::meta::ID{0x7918dc0d4a28bfb4u, 0xf3f88acf79e06248u}, pf::meta::ID{0xed37bc6fef75a473u, 0xac4e33994208db25u}, pf::meta::ID{0xa6174ce2723cf32bu, 0x2a77d5892a2bbfe2u}, pf::meta::ID{0xec479cc0488270cu, 0xea0b310543798daau});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xcef09d9c3ea2bbfcu, 0xd345e754e25cbd12u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0xcef09d9c3ea2bbfcu, 0xd345e754e25cbd12u}, pf::meta::ID{0xd2b696856b56de7bu, 0x1f83e4644d7d28bu}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xb3ee85bbd4937bfau, 0xcb00fc320b00e8f7u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0xb3ee85bbd4937bfau, 0xcb00fc320b00e8f7u}, pf::meta::ID{0xd2b696856b56de7bu, 0x1f83e4644d7d28bu}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x3e6c82cf2df7a144u, 0x89438ef915b1e477u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0x3e6c82cf2df7a144u, 0x89438ef915b1e477u}, pf::meta::ID{0xd2b696856b56de7bu, 0x1f83e4644d7d28bu}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x6a80c3c87f69c8e0u, 0x37b2051f0179a291u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0x6a80c3c87f69c8e0u, 0x37b2051f0179a291u}, pf::meta::ID{0xd2b696856b56de7bu, 0x1f83e4644d7d28bu}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x55718f40cebdf097u, 0x1b63990d68cdc11u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x55718f40cebdf097u, 0x1b63990d68cdc11u}, pf::meta::ID{0xd2b696856b56de7bu, 0x1f83e4644d7d28bu}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7db0bb5230d65401u, 0x50302ba5e2919f22u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0x7db0bb5230d65401u, 0x50302ba5e2919f22u}, pf::meta::ID{0xd2b696856b56de7bu, 0x1f83e4644d7d28bu}> {};

/****************************** pf::E6 END ******************************/
namespace pf::meta::details {
/****************************** pf::E6 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6>() {
    return pf::meta::ID{0xd2b696856b56de7bu, 0x1f83e4644d7d28bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6>() {
    return pf::meta::ID{0xcef09d9c3ea2bbfcu, 0xd345e754e25cbd12u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 &>() {
    return pf::meta::ID{0xb3ee85bbd4937bfau, 0xcb00fc320b00e8f7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 &&>() {
    return pf::meta::ID{0x3e6c82cf2df7a144u, 0x89438ef915b1e477u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6 &>() {
    return pf::meta::ID{0x6a80c3c87f69c8e0u, 0x37b2051f0179a291u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 *>() {
    return pf::meta::ID{0x55718f40cebdf097u, 0x1b63990d68cdc11u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6 *>() {
    return pf::meta::ID{0x7db0bb5230d65401u, 0x50302ba5e2919f22u};
}
/****************************** pf::E6 END ******************************/

/****************************** pf::E6::pf::E6::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::A>() {
return pf::meta::ID{0x9c50bd6fd12dfdb7u, 0xff4ed390c03b355au};
}
/****************************** pf::E6::pf::E6::A END ******************************/

/****************************** pf::E6::pf::E6::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::B>() {
return pf::meta::ID{0x7918dc0d4a28bfb4u, 0xf3f88acf79e06248u};
}
/****************************** pf::E6::pf::E6::B END ******************************/

/****************************** pf::E6::pf::E6::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::C>() {
return pf::meta::ID{0xed37bc6fef75a473u, 0xac4e33994208db25u};
}
/****************************** pf::E6::pf::E6::C END ******************************/

/****************************** pf::E6::pf::E6::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::D>() {
return pf::meta::ID{0xa6174ce2723cf32bu, 0x2a77d5892a2bbfe2u};
}
/****************************** pf::E6::pf::E6::D END ******************************/

/****************************** pf::E6::pf::E6::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::E>() {
return pf::meta::ID{0xec479cc0488270cu, 0xea0b310543798daau};
}
/****************************** pf::E6::pf::E6::E END ******************************/
}
/****************************** pf::E7::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xc91b9228b7d86eu, 0xd87c0b1f91b9e5dcu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xc91b9228b7d86eu, 0xd87c0b1f91b9e5dcu};
    constexpr static ID TypeID = pf::meta::ID{0xcb12ff137ed9fccfu, 0x84c0549abea88e48u};
    using Type = pf::E7;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E7::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E7 Value = pf::E7::A;
};
/****************************** pf::E7::A END ******************************/

/****************************** pf::E7::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x1fa0f94c4683c577u, 0x2f95e083c9bbaf58u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x1fa0f94c4683c577u, 0x2f95e083c9bbaf58u};
    constexpr static ID TypeID = pf::meta::ID{0xcb12ff137ed9fccfu, 0x84c0549abea88e48u};
    using Type = pf::E7;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E7::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E7 Value = pf::E7::B;
};
/****************************** pf::E7::B END ******************************/

/****************************** pf::E7::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xce20ee2fda1040c1u, 0xd851652936bea594u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xce20ee2fda1040c1u, 0xd851652936bea594u};
    constexpr static ID TypeID = pf::meta::ID{0xcb12ff137ed9fccfu, 0x84c0549abea88e48u};
    using Type = pf::E7;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E7::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E7 Value = pf::E7::C;
};
/****************************** pf::E7::C END ******************************/

/****************************** pf::E7::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x4f8f35869562736cu, 0x2402639b2118b346u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x4f8f35869562736cu, 0x2402639b2118b346u};
    constexpr static ID TypeID = pf::meta::ID{0xcb12ff137ed9fccfu, 0x84c0549abea88e48u};
    using Type = pf::E7;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E7::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E7 Value = pf::E7::D;
};
/****************************** pf::E7::D END ******************************/

/****************************** pf::E7::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x4699643ea09900b3u, 0xa0313199e1aba8fdu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x4699643ea09900b3u, 0xa0313199e1aba8fdu};
    constexpr static ID TypeID = pf::meta::ID{0xcb12ff137ed9fccfu, 0x84c0549abea88e48u};
    using Type = pf::E7;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E7::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E7 Value = pf::E7::E;
};
/****************************** pf::E7::E END ******************************/

/****************************** pf::E7 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xcb12ff137ed9fccfu, 0x84c0549abea88e48u}> {
    struct details {
        
    };
    using Type = pf::E7;
    constexpr static ID TypeID = pf::meta::ID{0xcb12ff137ed9fccfu, 0x84c0549abea88e48u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E7"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E7"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0xc91b9228b7d86eu, 0xd87c0b1f91b9e5dcu}, pf::meta::ID{0x1fa0f94c4683c577u, 0x2f95e083c9bbaf58u}, pf::meta::ID{0xce20ee2fda1040c1u, 0xd851652936bea594u}, pf::meta::ID{0x4f8f35869562736cu, 0x2402639b2118b346u}, pf::meta::ID{0x4699643ea09900b3u, 0xa0313199e1aba8fdu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x8b2cdf1a2f90942u, 0xe6b0e2d8777ae245u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0x8b2cdf1a2f90942u, 0xe6b0e2d8777ae245u}, pf::meta::ID{0xcb12ff137ed9fccfu, 0x84c0549abea88e48u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xd4060bde56cf48c4u, 0x71c0259b852ec99fu}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0xd4060bde56cf48c4u, 0x71c0259b852ec99fu}, pf::meta::ID{0xcb12ff137ed9fccfu, 0x84c0549abea88e48u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x3683e77356b3299du, 0xea4ea04d66bc25dbu}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0x3683e77356b3299du, 0xea4ea04d66bc25dbu}, pf::meta::ID{0xcb12ff137ed9fccfu, 0x84c0549abea88e48u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7f17ce45907063dfu, 0x34e5800365b6e342u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0x7f17ce45907063dfu, 0x34e5800365b6e342u}, pf::meta::ID{0xcb12ff137ed9fccfu, 0x84c0549abea88e48u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xfbbe8b3739b87583u, 0x5c25c3f2681df059u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0xfbbe8b3739b87583u, 0x5c25c3f2681df059u}, pf::meta::ID{0xcb12ff137ed9fccfu, 0x84c0549abea88e48u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xf2866a8fb8ddba79u, 0xb88dc102a56afbc5u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0xf2866a8fb8ddba79u, 0xb88dc102a56afbc5u}, pf::meta::ID{0xcb12ff137ed9fccfu, 0x84c0549abea88e48u}> {};

/****************************** pf::E7 END ******************************/
namespace pf::meta::details {
/****************************** pf::E7 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7>() {
    return pf::meta::ID{0xcb12ff137ed9fccfu, 0x84c0549abea88e48u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7>() {
    return pf::meta::ID{0x8b2cdf1a2f90942u, 0xe6b0e2d8777ae245u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 &>() {
    return pf::meta::ID{0xd4060bde56cf48c4u, 0x71c0259b852ec99fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 &&>() {
    return pf::meta::ID{0x3683e77356b3299du, 0xea4ea04d66bc25dbu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7 &>() {
    return pf::meta::ID{0x7f17ce45907063dfu, 0x34e5800365b6e342u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 *>() {
    return pf::meta::ID{0xfbbe8b3739b87583u, 0x5c25c3f2681df059u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7 *>() {
    return pf::meta::ID{0xf2866a8fb8ddba79u, 0xb88dc102a56afbc5u};
}
/****************************** pf::E7 END ******************************/

/****************************** pf::E7::pf::E7::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::A>() {
return pf::meta::ID{0xc91b9228b7d86eu, 0xd87c0b1f91b9e5dcu};
}
/****************************** pf::E7::pf::E7::A END ******************************/

/****************************** pf::E7::pf::E7::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::B>() {
return pf::meta::ID{0x1fa0f94c4683c577u, 0x2f95e083c9bbaf58u};
}
/****************************** pf::E7::pf::E7::B END ******************************/

/****************************** pf::E7::pf::E7::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::C>() {
return pf::meta::ID{0xce20ee2fda1040c1u, 0xd851652936bea594u};
}
/****************************** pf::E7::pf::E7::C END ******************************/

/****************************** pf::E7::pf::E7::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::D>() {
return pf::meta::ID{0x4f8f35869562736cu, 0x2402639b2118b346u};
}
/****************************** pf::E7::pf::E7::D END ******************************/

/****************************** pf::E7::pf::E7::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::E>() {
return pf::meta::ID{0x4699643ea09900b3u, 0xa0313199e1aba8fdu};
}
/****************************** pf::E7::pf::E7::E END ******************************/
}
/****************************** pf::E8::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xc76c3fdfe6f999d0u, 0x80b5bb50f07cbca3u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xc76c3fdfe6f999d0u, 0x80b5bb50f07cbca3u};
    constexpr static ID TypeID = pf::meta::ID{0xe50761fdd7fe81f1u, 0xce7830ad459cafb2u};
    using Type = pf::E8;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E8::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E8 Value = pf::E8::A;
};
/****************************** pf::E8::A END ******************************/

/****************************** pf::E8::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x1cb1356cf96c450fu, 0x382768c8e2acc983u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x1cb1356cf96c450fu, 0x382768c8e2acc983u};
    constexpr static ID TypeID = pf::meta::ID{0xe50761fdd7fe81f1u, 0xce7830ad459cafb2u};
    using Type = pf::E8;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E8::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E8 Value = pf::E8::B;
};
/****************************** pf::E8::B END ******************************/

/****************************** pf::E8::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x9e497dc9b59c37b1u, 0xd62aac6d2075cd7u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x9e497dc9b59c37b1u, 0xd62aac6d2075cd7u};
    constexpr static ID TypeID = pf::meta::ID{0xe50761fdd7fe81f1u, 0xce7830ad459cafb2u};
    using Type = pf::E8;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E8::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E8 Value = pf::E8::C;
};
/****************************** pf::E8::C END ******************************/

/****************************** pf::E8::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xbf57aa422c260257u, 0xb425d4342d593066u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xbf57aa422c260257u, 0xb425d4342d593066u};
    constexpr static ID TypeID = pf::meta::ID{0xe50761fdd7fe81f1u, 0xce7830ad459cafb2u};
    using Type = pf::E8;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E8::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E8 Value = pf::E8::D;
};
/****************************** pf::E8::D END ******************************/

/****************************** pf::E8::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x98c53443a03dce21u, 0xcf54ce8748013fa1u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x98c53443a03dce21u, 0xcf54ce8748013fa1u};
    constexpr static ID TypeID = pf::meta::ID{0xe50761fdd7fe81f1u, 0xce7830ad459cafb2u};
    using Type = pf::E8;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E8::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E8 Value = pf::E8::E;
};
/****************************** pf::E8::E END ******************************/

/****************************** pf::E8 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xe50761fdd7fe81f1u, 0xce7830ad459cafb2u}> {
    struct details {
        
    };
    using Type = pf::E8;
    constexpr static ID TypeID = pf::meta::ID{0xe50761fdd7fe81f1u, 0xce7830ad459cafb2u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E8"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E8"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0xc76c3fdfe6f999d0u, 0x80b5bb50f07cbca3u}, pf::meta::ID{0x1cb1356cf96c450fu, 0x382768c8e2acc983u}, pf::meta::ID{0x9e497dc9b59c37b1u, 0xd62aac6d2075cd7u}, pf::meta::ID{0xbf57aa422c260257u, 0xb425d4342d593066u}, pf::meta::ID{0x98c53443a03dce21u, 0xcf54ce8748013fa1u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x2cf9edc2d07fed0fu, 0xd7867070cbc86eaau}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0x2cf9edc2d07fed0fu, 0xd7867070cbc86eaau}, pf::meta::ID{0xe50761fdd7fe81f1u, 0xce7830ad459cafb2u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7d49117917351685u, 0x66141bb4529dbabdu}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0x7d49117917351685u, 0x66141bb4529dbabdu}, pf::meta::ID{0xe50761fdd7fe81f1u, 0xce7830ad459cafb2u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7ae9eb33dde25adau, 0x5aa612ba1ef54d5au}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0x7ae9eb33dde25adau, 0x5aa612ba1ef54d5au}, pf::meta::ID{0xe50761fdd7fe81f1u, 0xce7830ad459cafb2u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xfc277fd2e2808c5du, 0xbffac22699f9539u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0xfc277fd2e2808c5du, 0xbffac22699f9539u}, pf::meta::ID{0xe50761fdd7fe81f1u, 0xce7830ad459cafb2u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xb46430b3d8d4cdafu, 0x533c5f7a161717adu}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0xb46430b3d8d4cdafu, 0x533c5f7a161717adu}, pf::meta::ID{0xe50761fdd7fe81f1u, 0xce7830ad459cafb2u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x3262e19f6e4ca967u, 0x2ffaa5c9bdcc4bc2u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0x3262e19f6e4ca967u, 0x2ffaa5c9bdcc4bc2u}, pf::meta::ID{0xe50761fdd7fe81f1u, 0xce7830ad459cafb2u}> {};

/****************************** pf::E8 END ******************************/
namespace pf::meta::details {
/****************************** pf::E8 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8>() {
    return pf::meta::ID{0xe50761fdd7fe81f1u, 0xce7830ad459cafb2u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8>() {
    return pf::meta::ID{0x2cf9edc2d07fed0fu, 0xd7867070cbc86eaau};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 &>() {
    return pf::meta::ID{0x7d49117917351685u, 0x66141bb4529dbabdu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 &&>() {
    return pf::meta::ID{0x7ae9eb33dde25adau, 0x5aa612ba1ef54d5au};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8 &>() {
    return pf::meta::ID{0xfc277fd2e2808c5du, 0xbffac22699f9539u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 *>() {
    return pf::meta::ID{0xb46430b3d8d4cdafu, 0x533c5f7a161717adu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8 *>() {
    return pf::meta::ID{0x3262e19f6e4ca967u, 0x2ffaa5c9bdcc4bc2u};
}
/****************************** pf::E8 END ******************************/

/****************************** pf::E8::pf::E8::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::A>() {
return pf::meta::ID{0xc76c3fdfe6f999d0u, 0x80b5bb50f07cbca3u};
}
/****************************** pf::E8::pf::E8::A END ******************************/

/****************************** pf::E8::pf::E8::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::B>() {
return pf::meta::ID{0x1cb1356cf96c450fu, 0x382768c8e2acc983u};
}
/****************************** pf::E8::pf::E8::B END ******************************/

/****************************** pf::E8::pf::E8::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::C>() {
return pf::meta::ID{0x9e497dc9b59c37b1u, 0xd62aac6d2075cd7u};
}
/****************************** pf::E8::pf::E8::C END ******************************/

/****************************** pf::E8::pf::E8::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::D>() {
return pf::meta::ID{0xbf57aa422c260257u, 0xb425d4342d593066u};
}
/****************************** pf::E8::pf::E8::D END ******************************/

/****************************** pf::E8::pf::E8::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::E>() {
return pf::meta::ID{0x98c53443a03dce21u, 0xcf54ce8748013fa1u};
}
/****************************** pf::E8::pf::E8::E END ******************************/
}
/****************************** pf::E9::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x15a5f014e315a604u, 0xe330c03274b174ddu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x15a5f014e315a604u, 0xe330c03274b174ddu};
    constexpr static ID TypeID = pf::meta::ID{0x1ea6071632e92109u, 0xf1216368c0c1e97du};
    using Type = pf::E9;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E9::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E9 Value = pf::E9::A;
};
/****************************** pf::E9::A END ******************************/

/****************************** pf::E9::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xda545b100b60e77cu, 0x211bf495dcd479b1u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xda545b100b60e77cu, 0x211bf495dcd479b1u};
    constexpr static ID TypeID = pf::meta::ID{0x1ea6071632e92109u, 0xf1216368c0c1e97du};
    using Type = pf::E9;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E9::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E9 Value = pf::E9::B;
};
/****************************** pf::E9::B END ******************************/

/****************************** pf::E9::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x17e9ac81f90a242du, 0x84192826169f7a9cu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x17e9ac81f90a242du, 0x84192826169f7a9cu};
    constexpr static ID TypeID = pf::meta::ID{0x1ea6071632e92109u, 0xf1216368c0c1e97du};
    using Type = pf::E9;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E9::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E9 Value = pf::E9::C;
};
/****************************** pf::E9::C END ******************************/

/****************************** pf::E9::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xe2e5ad35ce680904u, 0x61431b0ff9ef90d5u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xe2e5ad35ce680904u, 0x61431b0ff9ef90d5u};
    constexpr static ID TypeID = pf::meta::ID{0x1ea6071632e92109u, 0xf1216368c0c1e97du};
    using Type = pf::E9;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E9::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E9 Value = pf::E9::D;
};
/****************************** pf::E9::D END ******************************/

/****************************** pf::E9::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xb44b32cd4092ac15u, 0x1d99843ec8e24996u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xb44b32cd4092ac15u, 0x1d99843ec8e24996u};
    constexpr static ID TypeID = pf::meta::ID{0x1ea6071632e92109u, 0xf1216368c0c1e97du};
    using Type = pf::E9;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E9::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E9 Value = pf::E9::E;
};
/****************************** pf::E9::E END ******************************/

/****************************** pf::E9 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x1ea6071632e92109u, 0xf1216368c0c1e97du}> {
    struct details {
        
    };
    using Type = pf::E9;
    constexpr static ID TypeID = pf::meta::ID{0x1ea6071632e92109u, 0xf1216368c0c1e97du};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E9"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E9"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0x15a5f014e315a604u, 0xe330c03274b174ddu}, pf::meta::ID{0xda545b100b60e77cu, 0x211bf495dcd479b1u}, pf::meta::ID{0x17e9ac81f90a242du, 0x84192826169f7a9cu}, pf::meta::ID{0xe2e5ad35ce680904u, 0x61431b0ff9ef90d5u}, pf::meta::ID{0xb44b32cd4092ac15u, 0x1d99843ec8e24996u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xa938f18172bf7ea3u, 0xfb845c93846f1f9bu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0xa938f18172bf7ea3u, 0xfb845c93846f1f9bu}, pf::meta::ID{0x1ea6071632e92109u, 0xf1216368c0c1e97du}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xd78687c7480eac5cu, 0xdb4309f3e69acfcdu}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0xd78687c7480eac5cu, 0xdb4309f3e69acfcdu}, pf::meta::ID{0x1ea6071632e92109u, 0xf1216368c0c1e97du}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x4c1dc82bec37ab68u, 0x8f24663b99aa394u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0x4c1dc82bec37ab68u, 0x8f24663b99aa394u}, pf::meta::ID{0x1ea6071632e92109u, 0xf1216368c0c1e97du}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xe91749e947724802u, 0x4e95ac8a7adef16bu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0xe91749e947724802u, 0x4e95ac8a7adef16bu}, pf::meta::ID{0x1ea6071632e92109u, 0xf1216368c0c1e97du}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x1f985614e709634cu, 0x18eb845ba732d444u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x1f985614e709634cu, 0x18eb845ba732d444u}, pf::meta::ID{0x1ea6071632e92109u, 0xf1216368c0c1e97du}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7e06ae81b3e3b1b6u, 0xc80114b45f1a92feu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0x7e06ae81b3e3b1b6u, 0xc80114b45f1a92feu}, pf::meta::ID{0x1ea6071632e92109u, 0xf1216368c0c1e97du}> {};

/****************************** pf::E9 END ******************************/
namespace pf::meta::details {
/****************************** pf::E9 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9>() {
    return pf::meta::ID{0x1ea6071632e92109u, 0xf1216368c0c1e97du};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9>() {
    return pf::meta::ID{0xa938f18172bf7ea3u, 0xfb845c93846f1f9bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 &>() {
    return pf::meta::ID{0xd78687c7480eac5cu, 0xdb4309f3e69acfcdu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 &&>() {
    return pf::meta::ID{0x4c1dc82bec37ab68u, 0x8f24663b99aa394u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9 &>() {
    return pf::meta::ID{0xe91749e947724802u, 0x4e95ac8a7adef16bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 *>() {
    return pf::meta::ID{0x1f985614e709634cu, 0x18eb845ba732d444u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9 *>() {
    return pf::meta::ID{0x7e06ae81b3e3b1b6u, 0xc80114b45f1a92feu};
}
/****************************** pf::E9 END ******************************/

/****************************** pf::E9::pf::E9::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::A>() {
return pf::meta::ID{0x15a5f014e315a604u, 0xe330c03274b174ddu};
}
/****************************** pf::E9::pf::E9::A END ******************************/

/****************************** pf::E9::pf::E9::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::B>() {
return pf::meta::ID{0xda545b100b60e77cu, 0x211bf495dcd479b1u};
}
/****************************** pf::E9::pf::E9::B END ******************************/

/****************************** pf::E9::pf::E9::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::C>() {
return pf::meta::ID{0x17e9ac81f90a242du, 0x84192826169f7a9cu};
}
/****************************** pf::E9::pf::E9::C END ******************************/

/****************************** pf::E9::pf::E9::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::D>() {
return pf::meta::ID{0xe2e5ad35ce680904u, 0x61431b0ff9ef90d5u};
}
/****************************** pf::E9::pf::E9::D END ******************************/

/****************************** pf::E9::pf::E9::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::E>() {
return pf::meta::ID{0xb44b32cd4092ac15u, 0x1d99843ec8e24996u};
}
/****************************** pf::E9::pf::E9::E END ******************************/
}

