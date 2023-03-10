
#pragma once

#include "meta/common.h"
#include "test.h"
#include <pf_common/array.h>
#include <pf_common/concepts/ranges.h>
#include <type_traits>

/****************************** pf::SomeEnum::Value1 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x5a83cb927de6196eu, 0x116444cbf2b844b2u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x5a83cb927de6196eu, 0x116444cbf2b844b2u};
    constexpr static ID TypeID = ::pf::meta::ID{0xa0e3e925ad17f2e6u, 0x77ae0b36af17b79eu};
    using Type = pf::SomeEnum;

    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

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
/****************************** pf::SomeEnum::Value1 END ******************************/

/****************************** pf::SomeEnum::Value2 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xfddf004193609211u, 0xd6d8824732285444u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xfddf004193609211u, 0xd6d8824732285444u};
    constexpr static ID TypeID = ::pf::meta::ID{0xa0e3e925ad17f2e6u, 0x77ae0b36af17b79eu};
    using Type = pf::SomeEnum;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa0e3e925ad17f2e6u, 0x77ae0b36af17b79eu}> {
    using Type = pf::SomeEnum;
    constexpr static ID TypeID = ::pf::meta::ID{0xa0e3e925ad17f2e6u, 0x77ae0b36af17b79eu};

    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(pf::meta::Attribute{"pf::operators", {R"(()()()((())))", R"([[nodiscard]])", R"(1ll)", R"(1.011)", R"([]{}())", R"("yeet")", R"('a')", R"([][][]:::3214234...[][][][])"}}, pf::meta::Attribute{"pf::hihi", {}}, pf::meta::Attribute{"pf::operators2", {R"(1ll)", R"(1.011)", R"("yeet")"}}, pf::meta::Attribute{"pf::hihi2", {}});

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0x5a83cb927de6196eu, 0x116444cbf2b844b2u}, ::pf::meta::ID{0xfddf004193609211u, 0xd6d8824732285444u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4f051911be587e11u, 0xa5af4b5c79eedd69u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x4f051911be587e11u, 0xa5af4b5c79eedd69u}, ::pf::meta::ID{0xa0e3e925ad17f2e6u, 0x77ae0b36af17b79eu}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdab4974637aa3a0eu, 0x3a7782de028e8a6cu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xdab4974637aa3a0eu, 0x3a7782de028e8a6cu}, ::pf::meta::ID{0xa0e3e925ad17f2e6u, 0x77ae0b36af17b79eu}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x54c192e983ca704fu, 0x4a347eca896f424eu}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x54c192e983ca704fu, 0x4a347eca896f424eu}, ::pf::meta::ID{0xa0e3e925ad17f2e6u, 0x77ae0b36af17b79eu}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xea54816cd55d69c7u, 0x39583f61d2446151u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xea54816cd55d69c7u, 0x39583f61d2446151u}, ::pf::meta::ID{0x4f051911be587e11u, 0xa5af4b5c79eedd69u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdaffd732c71d8795u, 0xa89975c214da341eu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xdaffd732c71d8795u, 0xa89975c214da341eu}, ::pf::meta::ID{0xa0e3e925ad17f2e6u, 0x77ae0b36af17b79eu}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdfc02b5026afb128u, 0xc9349c46ad04ba6eu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xdfc02b5026afb128u, 0xc9349c46ad04ba6eu}, ::pf::meta::ID{0x4f051911be587e11u, 0xa5af4b5c79eedd69u}> {};

/****************************** pf::SomeEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::SomeEnum START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum>() {
    return ::pf::meta::ID{0xa0e3e925ad17f2e6u, 0x77ae0b36af17b79eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum>() {
    return ::pf::meta::ID{0x4f051911be587e11u, 0xa5af4b5c79eedd69u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum &>() {
    return ::pf::meta::ID{0xdab4974637aa3a0eu, 0x3a7782de028e8a6cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum &&>() {
    return ::pf::meta::ID{0x54c192e983ca704fu, 0x4a347eca896f424eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum &>() {
    return ::pf::meta::ID{0xea54816cd55d69c7u, 0x39583f61d2446151u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum *>() {
    return ::pf::meta::ID{0xdaffd732c71d8795u, 0xa89975c214da341eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum *>() {
    return ::pf::meta::ID{0xdfc02b5026afb128u, 0xc9349c46ad04ba6eu};
}
/****************************** pf::SomeEnum END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value1 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value1>() {
return ::pf::meta::ID{0x5a83cb927de6196eu, 0x116444cbf2b844b2u};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value1 END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value2 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value2>() {
return ::pf::meta::ID{0xfddf004193609211u, 0xd6d8824732285444u};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value2 END ******************************/
}
/****************************** pf::Test::E::Value1 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x48997037b6e4b22au, 0x2f3f785baf772600u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x48997037b6e4b22au, 0x2f3f785baf772600u};
    constexpr static ID TypeID = ::pf::meta::ID{0x9c9750b3aefbe7d1u, 0x3b4487347f12fe06u};
    using Type = pf::Test::E;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xef5b1c53df4f5342u, 0x9cdd9ff31831c68u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xef5b1c53df4f5342u, 0x9cdd9ff31831c68u};
    constexpr static ID TypeID = ::pf::meta::ID{0x9c9750b3aefbe7d1u, 0x3b4487347f12fe06u};
    using Type = pf::Test::E;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9c9750b3aefbe7d1u, 0x3b4487347f12fe06u}> {
    using Type = pf::Test::E;
    constexpr static ID TypeID = ::pf::meta::ID{0x9c9750b3aefbe7d1u, 0x3b4487347f12fe06u};

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

    constexpr static auto Name = ::pf::StringLiteral{"E"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::Test::E"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0x48997037b6e4b22au, 0x2f3f785baf772600u}, ::pf::meta::ID{0xef5b1c53df4f5342u, 0x9cdd9ff31831c68u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd4fa7d5e2ced86d8u, 0xdc5eec2876840a95u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xd4fa7d5e2ced86d8u, 0xdc5eec2876840a95u}, ::pf::meta::ID{0x9c9750b3aefbe7d1u, 0x3b4487347f12fe06u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x42c3748c26e459ebu, 0xee0f9a019a59a486u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x42c3748c26e459ebu, 0xee0f9a019a59a486u}, ::pf::meta::ID{0x9c9750b3aefbe7d1u, 0x3b4487347f12fe06u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4fee0a991deddcddu, 0x81a0b12b0849c420u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x4fee0a991deddcddu, 0x81a0b12b0849c420u}, ::pf::meta::ID{0x9c9750b3aefbe7d1u, 0x3b4487347f12fe06u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x733e86de3438eda5u, 0x9ecbdfc23d2ac7bu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x733e86de3438eda5u, 0x9ecbdfc23d2ac7bu}, ::pf::meta::ID{0xd4fa7d5e2ced86d8u, 0xdc5eec2876840a95u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xae0c535b8d5038cbu, 0x30c97746d17f6bceu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xae0c535b8d5038cbu, 0x30c97746d17f6bceu}, ::pf::meta::ID{0x9c9750b3aefbe7d1u, 0x3b4487347f12fe06u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xaf8fa140090270f5u, 0x9b75755d8742ef32u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xaf8fa140090270f5u, 0x9b75755d8742ef32u}, ::pf::meta::ID{0xd4fa7d5e2ced86d8u, 0xdc5eec2876840a95u}> {};

/****************************** pf::Test::E END ******************************/
namespace pf::meta::details {
/****************************** pf::Test::E START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E>() {
    return ::pf::meta::ID{0x9c9750b3aefbe7d1u, 0x3b4487347f12fe06u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E>() {
    return ::pf::meta::ID{0xd4fa7d5e2ced86d8u, 0xdc5eec2876840a95u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E &>() {
    return ::pf::meta::ID{0x42c3748c26e459ebu, 0xee0f9a019a59a486u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E &&>() {
    return ::pf::meta::ID{0x4fee0a991deddcddu, 0x81a0b12b0849c420u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E &>() {
    return ::pf::meta::ID{0x733e86de3438eda5u, 0x9ecbdfc23d2ac7bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E *>() {
    return ::pf::meta::ID{0xae0c535b8d5038cbu, 0x30c97746d17f6bceu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E *>() {
    return ::pf::meta::ID{0xaf8fa140090270f5u, 0x9b75755d8742ef32u};
}
/****************************** pf::Test::E END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value1 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::Test::E::Value1>() {
return ::pf::meta::ID{0x48997037b6e4b22au, 0x2f3f785baf772600u};
}
/****************************** pf::Test::E::pf::Test::E::Value1 END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value2 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::Test::E::Value2>() {
return ::pf::meta::ID{0xef5b1c53df4f5342u, 0x9cdd9ff31831c68u};
}
/****************************** pf::Test::E::pf::Test::E::Value2 END ******************************/
}
/****************************** pf::EmptyEnum START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7029165083b7b41au, 0xf54698a4ad74ffc7u}> {
    using Type = pf::EmptyEnum;
    constexpr static ID TypeID = ::pf::meta::ID{0x7029165083b7b41au, 0xf54698a4ad74ffc7u};

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

    constexpr static auto Name = ::pf::StringLiteral{"EmptyEnum"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::EmptyEnum"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>();
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa5ba83f85b4ced63u, 0x113f4166e9214eafu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xa5ba83f85b4ced63u, 0x113f4166e9214eafu}, ::pf::meta::ID{0x7029165083b7b41au, 0xf54698a4ad74ffc7u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf4b177b9e391419fu, 0xd38d69fce2bbfa05u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xf4b177b9e391419fu, 0xd38d69fce2bbfa05u}, ::pf::meta::ID{0x7029165083b7b41au, 0xf54698a4ad74ffc7u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xbda59fd068002ac4u, 0xb7985d914f7e38c6u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xbda59fd068002ac4u, 0xb7985d914f7e38c6u}, ::pf::meta::ID{0x7029165083b7b41au, 0xf54698a4ad74ffc7u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf5605e4a0d58fd8eu, 0x9cf04c6fb3756f13u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xf5605e4a0d58fd8eu, 0x9cf04c6fb3756f13u}, ::pf::meta::ID{0xa5ba83f85b4ced63u, 0x113f4166e9214eafu}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x26b16bfe1579a6ebu, 0x866875116bb288ecu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x26b16bfe1579a6ebu, 0x866875116bb288ecu}, ::pf::meta::ID{0x7029165083b7b41au, 0xf54698a4ad74ffc7u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xad0ef2b3f5a42e11u, 0xd9a02b63ac29c237u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xad0ef2b3f5a42e11u, 0xd9a02b63ac29c237u}, ::pf::meta::ID{0xa5ba83f85b4ced63u, 0x113f4166e9214eafu}> {};

/****************************** pf::EmptyEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::EmptyEnum START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum>() {
    return ::pf::meta::ID{0x7029165083b7b41au, 0xf54698a4ad74ffc7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum>() {
    return ::pf::meta::ID{0xa5ba83f85b4ced63u, 0x113f4166e9214eafu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &>() {
    return ::pf::meta::ID{0xf4b177b9e391419fu, 0xd38d69fce2bbfa05u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &&>() {
    return ::pf::meta::ID{0xbda59fd068002ac4u, 0xb7985d914f7e38c6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum &>() {
    return ::pf::meta::ID{0xf5605e4a0d58fd8eu, 0x9cf04c6fb3756f13u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum *>() {
    return ::pf::meta::ID{0x26b16bfe1579a6ebu, 0x866875116bb288ecu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum *>() {
    return ::pf::meta::ID{0xad0ef2b3f5a42e11u, 0xd9a02b63ac29c237u};
}
/****************************** pf::EmptyEnum END ******************************/
}
/****************************** pf::E1::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7b5e8a4b2034f41cu, 0xba12457f24f3ae76u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x7b5e8a4b2034f41cu, 0xba12457f24f3ae76u};
    constexpr static ID TypeID = ::pf::meta::ID{0xfa402f81a8f421a9u, 0xad32f3567d670637u};
    using Type = pf::E1;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x823b342b03e02df0u, 0xce28b706f44134dfu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x823b342b03e02df0u, 0xce28b706f44134dfu};
    constexpr static ID TypeID = ::pf::meta::ID{0xfa402f81a8f421a9u, 0xad32f3567d670637u};
    using Type = pf::E1;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd0afa0dba4d34e53u, 0x6c18c972f19205cdu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xd0afa0dba4d34e53u, 0x6c18c972f19205cdu};
    constexpr static ID TypeID = ::pf::meta::ID{0xfa402f81a8f421a9u, 0xad32f3567d670637u};
    using Type = pf::E1;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x38968cb79ea93945u, 0x7b54bc3993ebbebdu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x38968cb79ea93945u, 0x7b54bc3993ebbebdu};
    constexpr static ID TypeID = ::pf::meta::ID{0xfa402f81a8f421a9u, 0xad32f3567d670637u};
    using Type = pf::E1;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x5a24bc30f8680629u, 0x81f3e35f4a7b6a48u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x5a24bc30f8680629u, 0x81f3e35f4a7b6a48u};
    constexpr static ID TypeID = ::pf::meta::ID{0xfa402f81a8f421a9u, 0xad32f3567d670637u};
    using Type = pf::E1;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xfa402f81a8f421a9u, 0xad32f3567d670637u}> {
    using Type = pf::E1;
    constexpr static ID TypeID = ::pf::meta::ID{0xfa402f81a8f421a9u, 0xad32f3567d670637u};

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

    constexpr static auto Name = ::pf::StringLiteral{"E1"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E1"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0x7b5e8a4b2034f41cu, 0xba12457f24f3ae76u}, ::pf::meta::ID{0x823b342b03e02df0u, 0xce28b706f44134dfu}, ::pf::meta::ID{0xd0afa0dba4d34e53u, 0x6c18c972f19205cdu}, ::pf::meta::ID{0x38968cb79ea93945u, 0x7b54bc3993ebbebdu}, ::pf::meta::ID{0x5a24bc30f8680629u, 0x81f3e35f4a7b6a48u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3481c01525d1547bu, 0xe970513d9d6703a7u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x3481c01525d1547bu, 0xe970513d9d6703a7u}, ::pf::meta::ID{0xfa402f81a8f421a9u, 0xad32f3567d670637u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x13ac124e94bf3106u, 0xdc466dae5e249fc0u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x13ac124e94bf3106u, 0xdc466dae5e249fc0u}, ::pf::meta::ID{0xfa402f81a8f421a9u, 0xad32f3567d670637u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xed12c8d31c52b777u, 0xad77aed29b158bd1u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xed12c8d31c52b777u, 0xad77aed29b158bd1u}, ::pf::meta::ID{0xfa402f81a8f421a9u, 0xad32f3567d670637u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf280192305e71156u, 0x1b1ff1c77b765e7au}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xf280192305e71156u, 0x1b1ff1c77b765e7au}, ::pf::meta::ID{0x3481c01525d1547bu, 0xe970513d9d6703a7u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x35c32a2e5cb80f52u, 0x708605280ab8a03fu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x35c32a2e5cb80f52u, 0x708605280ab8a03fu}, ::pf::meta::ID{0xfa402f81a8f421a9u, 0xad32f3567d670637u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x36b065d7fbe289b0u, 0xa6ffe1ae6f15b007u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x36b065d7fbe289b0u, 0xa6ffe1ae6f15b007u}, ::pf::meta::ID{0x3481c01525d1547bu, 0xe970513d9d6703a7u}> {};

/****************************** pf::E1 END ******************************/
namespace pf::meta::details {
/****************************** pf::E1 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1>() {
    return ::pf::meta::ID{0xfa402f81a8f421a9u, 0xad32f3567d670637u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1>() {
    return ::pf::meta::ID{0x3481c01525d1547bu, 0xe970513d9d6703a7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 &>() {
    return ::pf::meta::ID{0x13ac124e94bf3106u, 0xdc466dae5e249fc0u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 &&>() {
    return ::pf::meta::ID{0xed12c8d31c52b777u, 0xad77aed29b158bd1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1 &>() {
    return ::pf::meta::ID{0xf280192305e71156u, 0x1b1ff1c77b765e7au};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 *>() {
    return ::pf::meta::ID{0x35c32a2e5cb80f52u, 0x708605280ab8a03fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1 *>() {
    return ::pf::meta::ID{0x36b065d7fbe289b0u, 0xa6ffe1ae6f15b007u};
}
/****************************** pf::E1 END ******************************/

/****************************** pf::E1::pf::E1::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::A>() {
return ::pf::meta::ID{0x7b5e8a4b2034f41cu, 0xba12457f24f3ae76u};
}
/****************************** pf::E1::pf::E1::A END ******************************/

/****************************** pf::E1::pf::E1::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::B>() {
return ::pf::meta::ID{0x823b342b03e02df0u, 0xce28b706f44134dfu};
}
/****************************** pf::E1::pf::E1::B END ******************************/

/****************************** pf::E1::pf::E1::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::C>() {
return ::pf::meta::ID{0xd0afa0dba4d34e53u, 0x6c18c972f19205cdu};
}
/****************************** pf::E1::pf::E1::C END ******************************/

/****************************** pf::E1::pf::E1::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::D>() {
return ::pf::meta::ID{0x38968cb79ea93945u, 0x7b54bc3993ebbebdu};
}
/****************************** pf::E1::pf::E1::D END ******************************/

/****************************** pf::E1::pf::E1::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::E>() {
return ::pf::meta::ID{0x5a24bc30f8680629u, 0x81f3e35f4a7b6a48u};
}
/****************************** pf::E1::pf::E1::E END ******************************/
}
/****************************** pf::E2::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xce467a87cdc8034eu, 0x8228924296de36d6u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xce467a87cdc8034eu, 0x8228924296de36d6u};
    constexpr static ID TypeID = ::pf::meta::ID{0x3980372dc67e5a53u, 0x1aacac3261d0666eu};
    using Type = pf::E2;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb8669706c0449e8au, 0xbf31e7327666050au}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xb8669706c0449e8au, 0xbf31e7327666050au};
    constexpr static ID TypeID = ::pf::meta::ID{0x3980372dc67e5a53u, 0x1aacac3261d0666eu};
    using Type = pf::E2;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x875b4bd3fc6959b4u, 0x2060cdc249c62f5bu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x875b4bd3fc6959b4u, 0x2060cdc249c62f5bu};
    constexpr static ID TypeID = ::pf::meta::ID{0x3980372dc67e5a53u, 0x1aacac3261d0666eu};
    using Type = pf::E2;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xbe66526817c6fa8du, 0x7eef5a6b188d6cc5u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xbe66526817c6fa8du, 0x7eef5a6b188d6cc5u};
    constexpr static ID TypeID = ::pf::meta::ID{0x3980372dc67e5a53u, 0x1aacac3261d0666eu};
    using Type = pf::E2;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc9f492589212fee1u, 0xa4e6e1b7024ef5b0u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xc9f492589212fee1u, 0xa4e6e1b7024ef5b0u};
    constexpr static ID TypeID = ::pf::meta::ID{0x3980372dc67e5a53u, 0x1aacac3261d0666eu};
    using Type = pf::E2;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3980372dc67e5a53u, 0x1aacac3261d0666eu}> {
    using Type = pf::E2;
    constexpr static ID TypeID = ::pf::meta::ID{0x3980372dc67e5a53u, 0x1aacac3261d0666eu};

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

    constexpr static auto Name = ::pf::StringLiteral{"E2"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E2"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0xce467a87cdc8034eu, 0x8228924296de36d6u}, ::pf::meta::ID{0xb8669706c0449e8au, 0xbf31e7327666050au}, ::pf::meta::ID{0x875b4bd3fc6959b4u, 0x2060cdc249c62f5bu}, ::pf::meta::ID{0xbe66526817c6fa8du, 0x7eef5a6b188d6cc5u}, ::pf::meta::ID{0xc9f492589212fee1u, 0xa4e6e1b7024ef5b0u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x687070d3928a8007u, 0x618a7ffb2ad3902eu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x687070d3928a8007u, 0x618a7ffb2ad3902eu}, ::pf::meta::ID{0x3980372dc67e5a53u, 0x1aacac3261d0666eu}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x476ec4f50a17ea7u, 0x7155b025c335c73u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x476ec4f50a17ea7u, 0x7155b025c335c73u}, ::pf::meta::ID{0x3980372dc67e5a53u, 0x1aacac3261d0666eu}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3b34964d52dc2ec6u, 0xe9ce8042c8d0edu}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x3b34964d52dc2ec6u, 0xe9ce8042c8d0edu}, ::pf::meta::ID{0x3980372dc67e5a53u, 0x1aacac3261d0666eu}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xbaa83257a4c68f05u, 0x9e20f1dbe4e6426cu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xbaa83257a4c68f05u, 0x9e20f1dbe4e6426cu}, ::pf::meta::ID{0x687070d3928a8007u, 0x618a7ffb2ad3902eu}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x95122c21dd32bfc6u, 0xd14677c2ef53e940u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x95122c21dd32bfc6u, 0xd14677c2ef53e940u}, ::pf::meta::ID{0x3980372dc67e5a53u, 0x1aacac3261d0666eu}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe0a23b9fd2b4d265u, 0xd2fbed7e8de11e1au}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xe0a23b9fd2b4d265u, 0xd2fbed7e8de11e1au}, ::pf::meta::ID{0x687070d3928a8007u, 0x618a7ffb2ad3902eu}> {};

/****************************** pf::E2 END ******************************/
namespace pf::meta::details {
/****************************** pf::E2 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2>() {
    return ::pf::meta::ID{0x3980372dc67e5a53u, 0x1aacac3261d0666eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2>() {
    return ::pf::meta::ID{0x687070d3928a8007u, 0x618a7ffb2ad3902eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 &>() {
    return ::pf::meta::ID{0x476ec4f50a17ea7u, 0x7155b025c335c73u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 &&>() {
    return ::pf::meta::ID{0x3b34964d52dc2ec6u, 0xe9ce8042c8d0edu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2 &>() {
    return ::pf::meta::ID{0xbaa83257a4c68f05u, 0x9e20f1dbe4e6426cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 *>() {
    return ::pf::meta::ID{0x95122c21dd32bfc6u, 0xd14677c2ef53e940u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2 *>() {
    return ::pf::meta::ID{0xe0a23b9fd2b4d265u, 0xd2fbed7e8de11e1au};
}
/****************************** pf::E2 END ******************************/

/****************************** pf::E2::pf::E2::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::A>() {
return ::pf::meta::ID{0xce467a87cdc8034eu, 0x8228924296de36d6u};
}
/****************************** pf::E2::pf::E2::A END ******************************/

/****************************** pf::E2::pf::E2::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::B>() {
return ::pf::meta::ID{0xb8669706c0449e8au, 0xbf31e7327666050au};
}
/****************************** pf::E2::pf::E2::B END ******************************/

/****************************** pf::E2::pf::E2::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::C>() {
return ::pf::meta::ID{0x875b4bd3fc6959b4u, 0x2060cdc249c62f5bu};
}
/****************************** pf::E2::pf::E2::C END ******************************/

/****************************** pf::E2::pf::E2::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::D>() {
return ::pf::meta::ID{0xbe66526817c6fa8du, 0x7eef5a6b188d6cc5u};
}
/****************************** pf::E2::pf::E2::D END ******************************/

/****************************** pf::E2::pf::E2::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::E>() {
return ::pf::meta::ID{0xc9f492589212fee1u, 0xa4e6e1b7024ef5b0u};
}
/****************************** pf::E2::pf::E2::E END ******************************/
}
/****************************** pf::E3::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd032f7c7b5ebc7c0u, 0x99f501ec52e19b08u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xd032f7c7b5ebc7c0u, 0x99f501ec52e19b08u};
    constexpr static ID TypeID = ::pf::meta::ID{0x298fd7ef4e3283cau, 0xc7c0a7fa12d0ffe7u};
    using Type = pf::E3;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xeeb6192b5d7c640cu, 0x198d42aa846bd200u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xeeb6192b5d7c640cu, 0x198d42aa846bd200u};
    constexpr static ID TypeID = ::pf::meta::ID{0x298fd7ef4e3283cau, 0xc7c0a7fa12d0ffe7u};
    using Type = pf::E3;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xffdc4f2f0a94ea1eu, 0x3fef6dea80ac86cfu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xffdc4f2f0a94ea1eu, 0x3fef6dea80ac86cfu};
    constexpr static ID TypeID = ::pf::meta::ID{0x298fd7ef4e3283cau, 0xc7c0a7fa12d0ffe7u};
    using Type = pf::E3;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x58ce94511d566a65u, 0x865a96e5d7ee1c1u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x58ce94511d566a65u, 0x865a96e5d7ee1c1u};
    constexpr static ID TypeID = ::pf::meta::ID{0x298fd7ef4e3283cau, 0xc7c0a7fa12d0ffe7u};
    using Type = pf::E3;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2b6f43c1b5c54dadu, 0xcac33d1f27081723u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x2b6f43c1b5c54dadu, 0xcac33d1f27081723u};
    constexpr static ID TypeID = ::pf::meta::ID{0x298fd7ef4e3283cau, 0xc7c0a7fa12d0ffe7u};
    using Type = pf::E3;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x298fd7ef4e3283cau, 0xc7c0a7fa12d0ffe7u}> {
    using Type = pf::E3;
    constexpr static ID TypeID = ::pf::meta::ID{0x298fd7ef4e3283cau, 0xc7c0a7fa12d0ffe7u};

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

    constexpr static auto Name = ::pf::StringLiteral{"E3"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E3"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0xd032f7c7b5ebc7c0u, 0x99f501ec52e19b08u}, ::pf::meta::ID{0xeeb6192b5d7c640cu, 0x198d42aa846bd200u}, ::pf::meta::ID{0xffdc4f2f0a94ea1eu, 0x3fef6dea80ac86cfu}, ::pf::meta::ID{0x58ce94511d566a65u, 0x865a96e5d7ee1c1u}, ::pf::meta::ID{0x2b6f43c1b5c54dadu, 0xcac33d1f27081723u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf90068b3067a54bau, 0xd836657f2212ded5u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xf90068b3067a54bau, 0xd836657f2212ded5u}, ::pf::meta::ID{0x298fd7ef4e3283cau, 0xc7c0a7fa12d0ffe7u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb70e15f925a973dfu, 0xda68e502626dd560u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xb70e15f925a973dfu, 0xda68e502626dd560u}, ::pf::meta::ID{0x298fd7ef4e3283cau, 0xc7c0a7fa12d0ffe7u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x29d11aa833fcf700u, 0xd1ef95900bc02670u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x29d11aa833fcf700u, 0xd1ef95900bc02670u}, ::pf::meta::ID{0x298fd7ef4e3283cau, 0xc7c0a7fa12d0ffe7u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb8f2bc59d8f0325au, 0xa5042dd7fc672a78u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xb8f2bc59d8f0325au, 0xa5042dd7fc672a78u}, ::pf::meta::ID{0xf90068b3067a54bau, 0xd836657f2212ded5u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1f55f4cf54f4215au, 0x99c89b99f661b0a1u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x1f55f4cf54f4215au, 0x99c89b99f661b0a1u}, ::pf::meta::ID{0x298fd7ef4e3283cau, 0xc7c0a7fa12d0ffe7u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8bb6164431d80779u, 0x8c42050a0cc2cfc6u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x8bb6164431d80779u, 0x8c42050a0cc2cfc6u}, ::pf::meta::ID{0xf90068b3067a54bau, 0xd836657f2212ded5u}> {};

/****************************** pf::E3 END ******************************/
namespace pf::meta::details {
/****************************** pf::E3 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3>() {
    return ::pf::meta::ID{0x298fd7ef4e3283cau, 0xc7c0a7fa12d0ffe7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3>() {
    return ::pf::meta::ID{0xf90068b3067a54bau, 0xd836657f2212ded5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 &>() {
    return ::pf::meta::ID{0xb70e15f925a973dfu, 0xda68e502626dd560u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 &&>() {
    return ::pf::meta::ID{0x29d11aa833fcf700u, 0xd1ef95900bc02670u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3 &>() {
    return ::pf::meta::ID{0xb8f2bc59d8f0325au, 0xa5042dd7fc672a78u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 *>() {
    return ::pf::meta::ID{0x1f55f4cf54f4215au, 0x99c89b99f661b0a1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3 *>() {
    return ::pf::meta::ID{0x8bb6164431d80779u, 0x8c42050a0cc2cfc6u};
}
/****************************** pf::E3 END ******************************/

/****************************** pf::E3::pf::E3::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::A>() {
return ::pf::meta::ID{0xd032f7c7b5ebc7c0u, 0x99f501ec52e19b08u};
}
/****************************** pf::E3::pf::E3::A END ******************************/

/****************************** pf::E3::pf::E3::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::B>() {
return ::pf::meta::ID{0xeeb6192b5d7c640cu, 0x198d42aa846bd200u};
}
/****************************** pf::E3::pf::E3::B END ******************************/

/****************************** pf::E3::pf::E3::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::C>() {
return ::pf::meta::ID{0xffdc4f2f0a94ea1eu, 0x3fef6dea80ac86cfu};
}
/****************************** pf::E3::pf::E3::C END ******************************/

/****************************** pf::E3::pf::E3::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::D>() {
return ::pf::meta::ID{0x58ce94511d566a65u, 0x865a96e5d7ee1c1u};
}
/****************************** pf::E3::pf::E3::D END ******************************/

/****************************** pf::E3::pf::E3::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::E>() {
return ::pf::meta::ID{0x2b6f43c1b5c54dadu, 0xcac33d1f27081723u};
}
/****************************** pf::E3::pf::E3::E END ******************************/
}
/****************************** pf::E4::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd4b60ddac181ef72u, 0x771a520cbac38cd5u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xd4b60ddac181ef72u, 0x771a520cbac38cd5u};
    constexpr static ID TypeID = ::pf::meta::ID{0x80e370b9fd2e9e0fu, 0x2b015866fad0fc17u};
    using Type = pf::E4;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xafa8397d33f84d9eu, 0xaf7f4761e0f36d54u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xafa8397d33f84d9eu, 0xaf7f4761e0f36d54u};
    constexpr static ID TypeID = ::pf::meta::ID{0x80e370b9fd2e9e0fu, 0x2b015866fad0fc17u};
    using Type = pf::E4;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x773c6071adb7f481u, 0x9aea6f5fcf845fdau}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x773c6071adb7f481u, 0x9aea6f5fcf845fdau};
    constexpr static ID TypeID = ::pf::meta::ID{0x80e370b9fd2e9e0fu, 0x2b015866fad0fc17u};
    using Type = pf::E4;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8e95542e71b7d38bu, 0x3664c069104c6f14u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x8e95542e71b7d38bu, 0x3664c069104c6f14u};
    constexpr static ID TypeID = ::pf::meta::ID{0x80e370b9fd2e9e0fu, 0x2b015866fad0fc17u};
    using Type = pf::E4;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd8450f61e2a8ae95u, 0xbed1afc03e680371u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xd8450f61e2a8ae95u, 0xbed1afc03e680371u};
    constexpr static ID TypeID = ::pf::meta::ID{0x80e370b9fd2e9e0fu, 0x2b015866fad0fc17u};
    using Type = pf::E4;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x80e370b9fd2e9e0fu, 0x2b015866fad0fc17u}> {
    using Type = pf::E4;
    constexpr static ID TypeID = ::pf::meta::ID{0x80e370b9fd2e9e0fu, 0x2b015866fad0fc17u};

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

    constexpr static auto Name = ::pf::StringLiteral{"E4"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E4"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0xd4b60ddac181ef72u, 0x771a520cbac38cd5u}, ::pf::meta::ID{0xafa8397d33f84d9eu, 0xaf7f4761e0f36d54u}, ::pf::meta::ID{0x773c6071adb7f481u, 0x9aea6f5fcf845fdau}, ::pf::meta::ID{0x8e95542e71b7d38bu, 0x3664c069104c6f14u}, ::pf::meta::ID{0xd8450f61e2a8ae95u, 0xbed1afc03e680371u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf30bdc1d775234eeu, 0x1c2e2d68b4338a66u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xf30bdc1d775234eeu, 0x1c2e2d68b4338a66u}, ::pf::meta::ID{0x80e370b9fd2e9e0fu, 0x2b015866fad0fc17u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe409d001c531e1e4u, 0xfd21f4c5c64a8eefu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xe409d001c531e1e4u, 0xfd21f4c5c64a8eefu}, ::pf::meta::ID{0x80e370b9fd2e9e0fu, 0x2b015866fad0fc17u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc00ae2d7895f1387u, 0x290b1e12b8aa0030u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xc00ae2d7895f1387u, 0x290b1e12b8aa0030u}, ::pf::meta::ID{0x80e370b9fd2e9e0fu, 0x2b015866fad0fc17u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x86c5d134a6abd76du, 0x340da993754c713bu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x86c5d134a6abd76du, 0x340da993754c713bu}, ::pf::meta::ID{0xf30bdc1d775234eeu, 0x1c2e2d68b4338a66u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa12398ba38e9e201u, 0x32451f86ee8ab635u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xa12398ba38e9e201u, 0x32451f86ee8ab635u}, ::pf::meta::ID{0x80e370b9fd2e9e0fu, 0x2b015866fad0fc17u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc95fa518330edea2u, 0xb3ff58a3e09d0f51u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xc95fa518330edea2u, 0xb3ff58a3e09d0f51u}, ::pf::meta::ID{0xf30bdc1d775234eeu, 0x1c2e2d68b4338a66u}> {};

/****************************** pf::E4 END ******************************/
namespace pf::meta::details {
/****************************** pf::E4 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4>() {
    return ::pf::meta::ID{0x80e370b9fd2e9e0fu, 0x2b015866fad0fc17u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4>() {
    return ::pf::meta::ID{0xf30bdc1d775234eeu, 0x1c2e2d68b4338a66u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 &>() {
    return ::pf::meta::ID{0xe409d001c531e1e4u, 0xfd21f4c5c64a8eefu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 &&>() {
    return ::pf::meta::ID{0xc00ae2d7895f1387u, 0x290b1e12b8aa0030u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4 &>() {
    return ::pf::meta::ID{0x86c5d134a6abd76du, 0x340da993754c713bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 *>() {
    return ::pf::meta::ID{0xa12398ba38e9e201u, 0x32451f86ee8ab635u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4 *>() {
    return ::pf::meta::ID{0xc95fa518330edea2u, 0xb3ff58a3e09d0f51u};
}
/****************************** pf::E4 END ******************************/

/****************************** pf::E4::pf::E4::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::A>() {
return ::pf::meta::ID{0xd4b60ddac181ef72u, 0x771a520cbac38cd5u};
}
/****************************** pf::E4::pf::E4::A END ******************************/

/****************************** pf::E4::pf::E4::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::B>() {
return ::pf::meta::ID{0xafa8397d33f84d9eu, 0xaf7f4761e0f36d54u};
}
/****************************** pf::E4::pf::E4::B END ******************************/

/****************************** pf::E4::pf::E4::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::C>() {
return ::pf::meta::ID{0x773c6071adb7f481u, 0x9aea6f5fcf845fdau};
}
/****************************** pf::E4::pf::E4::C END ******************************/

/****************************** pf::E4::pf::E4::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::D>() {
return ::pf::meta::ID{0x8e95542e71b7d38bu, 0x3664c069104c6f14u};
}
/****************************** pf::E4::pf::E4::D END ******************************/

/****************************** pf::E4::pf::E4::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::E>() {
return ::pf::meta::ID{0xd8450f61e2a8ae95u, 0xbed1afc03e680371u};
}
/****************************** pf::E4::pf::E4::E END ******************************/
}
/****************************** pf::E5::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8a259d1bfdbdcf52u, 0xc04b513b6224722bu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x8a259d1bfdbdcf52u, 0xc04b513b6224722bu};
    constexpr static ID TypeID = ::pf::meta::ID{0x4227561fcfe3e850u, 0xe52b43eaedda729fu};
    using Type = pf::E5;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x48df2b2d3dc2b52eu, 0xdc84c853f5e8feafu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x48df2b2d3dc2b52eu, 0xdc84c853f5e8feafu};
    constexpr static ID TypeID = ::pf::meta::ID{0x4227561fcfe3e850u, 0xe52b43eaedda729fu};
    using Type = pf::E5;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x351a2b9a22ace5du, 0x7dde976fbf964c91u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x351a2b9a22ace5du, 0x7dde976fbf964c91u};
    constexpr static ID TypeID = ::pf::meta::ID{0x4227561fcfe3e850u, 0xe52b43eaedda729fu};
    using Type = pf::E5;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x75de56d4abd73296u, 0x9586ddd10db7d296u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x75de56d4abd73296u, 0x9586ddd10db7d296u};
    constexpr static ID TypeID = ::pf::meta::ID{0x4227561fcfe3e850u, 0xe52b43eaedda729fu};
    using Type = pf::E5;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x407e50bab0eb946du, 0xcff77287b70c63e9u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x407e50bab0eb946du, 0xcff77287b70c63e9u};
    constexpr static ID TypeID = ::pf::meta::ID{0x4227561fcfe3e850u, 0xe52b43eaedda729fu};
    using Type = pf::E5;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4227561fcfe3e850u, 0xe52b43eaedda729fu}> {
    using Type = pf::E5;
    constexpr static ID TypeID = ::pf::meta::ID{0x4227561fcfe3e850u, 0xe52b43eaedda729fu};

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

    constexpr static auto Name = ::pf::StringLiteral{"E5"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E5"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0x8a259d1bfdbdcf52u, 0xc04b513b6224722bu}, ::pf::meta::ID{0x48df2b2d3dc2b52eu, 0xdc84c853f5e8feafu}, ::pf::meta::ID{0x351a2b9a22ace5du, 0x7dde976fbf964c91u}, ::pf::meta::ID{0x75de56d4abd73296u, 0x9586ddd10db7d296u}, ::pf::meta::ID{0x407e50bab0eb946du, 0xcff77287b70c63e9u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa089b95f957c4bf0u, 0x86d2034132f64571u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xa089b95f957c4bf0u, 0x86d2034132f64571u}, ::pf::meta::ID{0x4227561fcfe3e850u, 0xe52b43eaedda729fu}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9519cf02758279bfu, 0xff9cae2d06bf30b6u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x9519cf02758279bfu, 0xff9cae2d06bf30b6u}, ::pf::meta::ID{0x4227561fcfe3e850u, 0xe52b43eaedda729fu}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xbbffad2cc9df962bu, 0x153d7934405d0534u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xbbffad2cc9df962bu, 0x153d7934405d0534u}, ::pf::meta::ID{0x4227561fcfe3e850u, 0xe52b43eaedda729fu}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf0a0c977c060f6a8u, 0x2ec27062c05ab878u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xf0a0c977c060f6a8u, 0x2ec27062c05ab878u}, ::pf::meta::ID{0xa089b95f957c4bf0u, 0x86d2034132f64571u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6c9352913e84f221u, 0xa1c88f23238299b6u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x6c9352913e84f221u, 0xa1c88f23238299b6u}, ::pf::meta::ID{0x4227561fcfe3e850u, 0xe52b43eaedda729fu}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7a20178529adbc91u, 0x5a6db4c96c531089u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x7a20178529adbc91u, 0x5a6db4c96c531089u}, ::pf::meta::ID{0xa089b95f957c4bf0u, 0x86d2034132f64571u}> {};

/****************************** pf::E5 END ******************************/
namespace pf::meta::details {
/****************************** pf::E5 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5>() {
    return ::pf::meta::ID{0x4227561fcfe3e850u, 0xe52b43eaedda729fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5>() {
    return ::pf::meta::ID{0xa089b95f957c4bf0u, 0x86d2034132f64571u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 &>() {
    return ::pf::meta::ID{0x9519cf02758279bfu, 0xff9cae2d06bf30b6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 &&>() {
    return ::pf::meta::ID{0xbbffad2cc9df962bu, 0x153d7934405d0534u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5 &>() {
    return ::pf::meta::ID{0xf0a0c977c060f6a8u, 0x2ec27062c05ab878u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 *>() {
    return ::pf::meta::ID{0x6c9352913e84f221u, 0xa1c88f23238299b6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5 *>() {
    return ::pf::meta::ID{0x7a20178529adbc91u, 0x5a6db4c96c531089u};
}
/****************************** pf::E5 END ******************************/

/****************************** pf::E5::pf::E5::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::A>() {
return ::pf::meta::ID{0x8a259d1bfdbdcf52u, 0xc04b513b6224722bu};
}
/****************************** pf::E5::pf::E5::A END ******************************/

/****************************** pf::E5::pf::E5::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::B>() {
return ::pf::meta::ID{0x48df2b2d3dc2b52eu, 0xdc84c853f5e8feafu};
}
/****************************** pf::E5::pf::E5::B END ******************************/

/****************************** pf::E5::pf::E5::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::C>() {
return ::pf::meta::ID{0x351a2b9a22ace5du, 0x7dde976fbf964c91u};
}
/****************************** pf::E5::pf::E5::C END ******************************/

/****************************** pf::E5::pf::E5::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::D>() {
return ::pf::meta::ID{0x75de56d4abd73296u, 0x9586ddd10db7d296u};
}
/****************************** pf::E5::pf::E5::D END ******************************/

/****************************** pf::E5::pf::E5::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::E>() {
return ::pf::meta::ID{0x407e50bab0eb946du, 0xcff77287b70c63e9u};
}
/****************************** pf::E5::pf::E5::E END ******************************/
}
/****************************** pf::E6::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc4205e56c5d046c3u, 0x3b52fbc61048df77u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xc4205e56c5d046c3u, 0x3b52fbc61048df77u};
    constexpr static ID TypeID = ::pf::meta::ID{0xb2ad7d6af5a827f2u, 0xf0804145007e741bu};
    using Type = pf::E6;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x995335f86ff597cau, 0x235e2b08c7497a74u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x995335f86ff597cau, 0x235e2b08c7497a74u};
    constexpr static ID TypeID = ::pf::meta::ID{0xb2ad7d6af5a827f2u, 0xf0804145007e741bu};
    using Type = pf::E6;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2760985401c8f42eu, 0xa255697ffaa7ddadu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x2760985401c8f42eu, 0xa255697ffaa7ddadu};
    constexpr static ID TypeID = ::pf::meta::ID{0xb2ad7d6af5a827f2u, 0xf0804145007e741bu};
    using Type = pf::E6;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc01e96b6a0d6c4c7u, 0x31bdaf5cbb22b75au}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xc01e96b6a0d6c4c7u, 0x31bdaf5cbb22b75au};
    constexpr static ID TypeID = ::pf::meta::ID{0xb2ad7d6af5a827f2u, 0xf0804145007e741bu};
    using Type = pf::E6;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf937733cccbe2f08u, 0xc0af529b38f158d6u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xf937733cccbe2f08u, 0xc0af529b38f158d6u};
    constexpr static ID TypeID = ::pf::meta::ID{0xb2ad7d6af5a827f2u, 0xf0804145007e741bu};
    using Type = pf::E6;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb2ad7d6af5a827f2u, 0xf0804145007e741bu}> {
    using Type = pf::E6;
    constexpr static ID TypeID = ::pf::meta::ID{0xb2ad7d6af5a827f2u, 0xf0804145007e741bu};

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

    constexpr static auto Name = ::pf::StringLiteral{"E6"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E6"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0xc4205e56c5d046c3u, 0x3b52fbc61048df77u}, ::pf::meta::ID{0x995335f86ff597cau, 0x235e2b08c7497a74u}, ::pf::meta::ID{0x2760985401c8f42eu, 0xa255697ffaa7ddadu}, ::pf::meta::ID{0xc01e96b6a0d6c4c7u, 0x31bdaf5cbb22b75au}, ::pf::meta::ID{0xf937733cccbe2f08u, 0xc0af529b38f158d6u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x82c560c7428ef736u, 0x75c0d828ad76a6fu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x82c560c7428ef736u, 0x75c0d828ad76a6fu}, ::pf::meta::ID{0xb2ad7d6af5a827f2u, 0xf0804145007e741bu}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xbfd98c99dbdf4e0eu, 0x373ed54c2d7e34ceu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xbfd98c99dbdf4e0eu, 0x373ed54c2d7e34ceu}, ::pf::meta::ID{0xb2ad7d6af5a827f2u, 0xf0804145007e741bu}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x57e484888bdabd5fu, 0xeb6da9ba13e798c1u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x57e484888bdabd5fu, 0xeb6da9ba13e798c1u}, ::pf::meta::ID{0xb2ad7d6af5a827f2u, 0xf0804145007e741bu}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd34b5b3aa6e0a84cu, 0x4b25502283bc807au}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xd34b5b3aa6e0a84cu, 0x4b25502283bc807au}, ::pf::meta::ID{0x82c560c7428ef736u, 0x75c0d828ad76a6fu}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd156c5d2d9b749c2u, 0xeaf7dc4eabb15dd3u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xd156c5d2d9b749c2u, 0xeaf7dc4eabb15dd3u}, ::pf::meta::ID{0xb2ad7d6af5a827f2u, 0xf0804145007e741bu}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x699cd72ecfeb50beu, 0xa4d55176fa656adfu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x699cd72ecfeb50beu, 0xa4d55176fa656adfu}, ::pf::meta::ID{0x82c560c7428ef736u, 0x75c0d828ad76a6fu}> {};

/****************************** pf::E6 END ******************************/
namespace pf::meta::details {
/****************************** pf::E6 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6>() {
    return ::pf::meta::ID{0xb2ad7d6af5a827f2u, 0xf0804145007e741bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6>() {
    return ::pf::meta::ID{0x82c560c7428ef736u, 0x75c0d828ad76a6fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 &>() {
    return ::pf::meta::ID{0xbfd98c99dbdf4e0eu, 0x373ed54c2d7e34ceu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 &&>() {
    return ::pf::meta::ID{0x57e484888bdabd5fu, 0xeb6da9ba13e798c1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6 &>() {
    return ::pf::meta::ID{0xd34b5b3aa6e0a84cu, 0x4b25502283bc807au};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 *>() {
    return ::pf::meta::ID{0xd156c5d2d9b749c2u, 0xeaf7dc4eabb15dd3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6 *>() {
    return ::pf::meta::ID{0x699cd72ecfeb50beu, 0xa4d55176fa656adfu};
}
/****************************** pf::E6 END ******************************/

/****************************** pf::E6::pf::E6::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::A>() {
return ::pf::meta::ID{0xc4205e56c5d046c3u, 0x3b52fbc61048df77u};
}
/****************************** pf::E6::pf::E6::A END ******************************/

/****************************** pf::E6::pf::E6::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::B>() {
return ::pf::meta::ID{0x995335f86ff597cau, 0x235e2b08c7497a74u};
}
/****************************** pf::E6::pf::E6::B END ******************************/

/****************************** pf::E6::pf::E6::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::C>() {
return ::pf::meta::ID{0x2760985401c8f42eu, 0xa255697ffaa7ddadu};
}
/****************************** pf::E6::pf::E6::C END ******************************/

/****************************** pf::E6::pf::E6::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::D>() {
return ::pf::meta::ID{0xc01e96b6a0d6c4c7u, 0x31bdaf5cbb22b75au};
}
/****************************** pf::E6::pf::E6::D END ******************************/

/****************************** pf::E6::pf::E6::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::E>() {
return ::pf::meta::ID{0xf937733cccbe2f08u, 0xc0af529b38f158d6u};
}
/****************************** pf::E6::pf::E6::E END ******************************/
}
/****************************** pf::E7::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xcece6af988d24704u, 0x2cfebbc897c299c9u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xcece6af988d24704u, 0x2cfebbc897c299c9u};
    constexpr static ID TypeID = ::pf::meta::ID{0xae3f20e5b50f1b1cu, 0x344783405dd7eb0fu};
    using Type = pf::E7;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xab842ac2267098c7u, 0x84993a1638eaa8a7u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xab842ac2267098c7u, 0x84993a1638eaa8a7u};
    constexpr static ID TypeID = ::pf::meta::ID{0xae3f20e5b50f1b1cu, 0x344783405dd7eb0fu};
    using Type = pf::E7;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xcc816597dd92ae21u, 0xc9513f731f2cd24du}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xcc816597dd92ae21u, 0xc9513f731f2cd24du};
    constexpr static ID TypeID = ::pf::meta::ID{0xae3f20e5b50f1b1cu, 0x344783405dd7eb0fu};
    using Type = pf::E7;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe8b98a59272d062u, 0x9215b677d01a1cc7u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xe8b98a59272d062u, 0x9215b677d01a1cc7u};
    constexpr static ID TypeID = ::pf::meta::ID{0xae3f20e5b50f1b1cu, 0x344783405dd7eb0fu};
    using Type = pf::E7;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1f9df0b7c8da215au, 0x4f0cb48ce55e4871u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x1f9df0b7c8da215au, 0x4f0cb48ce55e4871u};
    constexpr static ID TypeID = ::pf::meta::ID{0xae3f20e5b50f1b1cu, 0x344783405dd7eb0fu};
    using Type = pf::E7;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xae3f20e5b50f1b1cu, 0x344783405dd7eb0fu}> {
    using Type = pf::E7;
    constexpr static ID TypeID = ::pf::meta::ID{0xae3f20e5b50f1b1cu, 0x344783405dd7eb0fu};

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

    constexpr static auto Name = ::pf::StringLiteral{"E7"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E7"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0xcece6af988d24704u, 0x2cfebbc897c299c9u}, ::pf::meta::ID{0xab842ac2267098c7u, 0x84993a1638eaa8a7u}, ::pf::meta::ID{0xcc816597dd92ae21u, 0xc9513f731f2cd24du}, ::pf::meta::ID{0xe8b98a59272d062u, 0x9215b677d01a1cc7u}, ::pf::meta::ID{0x1f9df0b7c8da215au, 0x4f0cb48ce55e4871u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x75520fe01e04be76u, 0xbff7829b479b6ce2u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x75520fe01e04be76u, 0xbff7829b479b6ce2u}, ::pf::meta::ID{0xae3f20e5b50f1b1cu, 0x344783405dd7eb0fu}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x798870233be3a973u, 0xa6852f48d01d60c1u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x798870233be3a973u, 0xa6852f48d01d60c1u}, ::pf::meta::ID{0xae3f20e5b50f1b1cu, 0x344783405dd7eb0fu}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9ebfd10277b2a11bu, 0x71d9fe574b3adb1u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x9ebfd10277b2a11bu, 0x71d9fe574b3adb1u}, ::pf::meta::ID{0xae3f20e5b50f1b1cu, 0x344783405dd7eb0fu}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdf337683f6272404u, 0x36dad74aa7d1162fu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xdf337683f6272404u, 0x36dad74aa7d1162fu}, ::pf::meta::ID{0x75520fe01e04be76u, 0xbff7829b479b6ce2u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xebc2ce870c7c17a9u, 0x663d7a7b68e5b45bu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xebc2ce870c7c17a9u, 0x663d7a7b68e5b45bu}, ::pf::meta::ID{0xae3f20e5b50f1b1cu, 0x344783405dd7eb0fu}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe5c27f050918903du, 0x4419499f8ee5748fu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xe5c27f050918903du, 0x4419499f8ee5748fu}, ::pf::meta::ID{0x75520fe01e04be76u, 0xbff7829b479b6ce2u}> {};

/****************************** pf::E7 END ******************************/
namespace pf::meta::details {
/****************************** pf::E7 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7>() {
    return ::pf::meta::ID{0xae3f20e5b50f1b1cu, 0x344783405dd7eb0fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7>() {
    return ::pf::meta::ID{0x75520fe01e04be76u, 0xbff7829b479b6ce2u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 &>() {
    return ::pf::meta::ID{0x798870233be3a973u, 0xa6852f48d01d60c1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 &&>() {
    return ::pf::meta::ID{0x9ebfd10277b2a11bu, 0x71d9fe574b3adb1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7 &>() {
    return ::pf::meta::ID{0xdf337683f6272404u, 0x36dad74aa7d1162fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 *>() {
    return ::pf::meta::ID{0xebc2ce870c7c17a9u, 0x663d7a7b68e5b45bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7 *>() {
    return ::pf::meta::ID{0xe5c27f050918903du, 0x4419499f8ee5748fu};
}
/****************************** pf::E7 END ******************************/

/****************************** pf::E7::pf::E7::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::A>() {
return ::pf::meta::ID{0xcece6af988d24704u, 0x2cfebbc897c299c9u};
}
/****************************** pf::E7::pf::E7::A END ******************************/

/****************************** pf::E7::pf::E7::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::B>() {
return ::pf::meta::ID{0xab842ac2267098c7u, 0x84993a1638eaa8a7u};
}
/****************************** pf::E7::pf::E7::B END ******************************/

/****************************** pf::E7::pf::E7::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::C>() {
return ::pf::meta::ID{0xcc816597dd92ae21u, 0xc9513f731f2cd24du};
}
/****************************** pf::E7::pf::E7::C END ******************************/

/****************************** pf::E7::pf::E7::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::D>() {
return ::pf::meta::ID{0xe8b98a59272d062u, 0x9215b677d01a1cc7u};
}
/****************************** pf::E7::pf::E7::D END ******************************/

/****************************** pf::E7::pf::E7::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::E>() {
return ::pf::meta::ID{0x1f9df0b7c8da215au, 0x4f0cb48ce55e4871u};
}
/****************************** pf::E7::pf::E7::E END ******************************/
}
/****************************** pf::E8::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xea4a12721374feb0u, 0x4e76e3a6820f7fbfu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xea4a12721374feb0u, 0x4e76e3a6820f7fbfu};
    constexpr static ID TypeID = ::pf::meta::ID{0xed18c7ad00306dfeu, 0x6dfc356bc2a48a71u};
    using Type = pf::E8;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xbe64defa716a62f4u, 0x49f26da8263576ceu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xbe64defa716a62f4u, 0x49f26da8263576ceu};
    constexpr static ID TypeID = ::pf::meta::ID{0xed18c7ad00306dfeu, 0x6dfc356bc2a48a71u};
    using Type = pf::E8;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x30469ae1a668d451u, 0x507ee729b512eebu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x30469ae1a668d451u, 0x507ee729b512eebu};
    constexpr static ID TypeID = ::pf::meta::ID{0xed18c7ad00306dfeu, 0x6dfc356bc2a48a71u};
    using Type = pf::E8;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x578f60f284a7152fu, 0xebfed46dfd0ae5bfu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x578f60f284a7152fu, 0xebfed46dfd0ae5bfu};
    constexpr static ID TypeID = ::pf::meta::ID{0xed18c7ad00306dfeu, 0x6dfc356bc2a48a71u};
    using Type = pf::E8;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdab9ca79427b717fu, 0xcbb06bd7483c7235u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xdab9ca79427b717fu, 0xcbb06bd7483c7235u};
    constexpr static ID TypeID = ::pf::meta::ID{0xed18c7ad00306dfeu, 0x6dfc356bc2a48a71u};
    using Type = pf::E8;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xed18c7ad00306dfeu, 0x6dfc356bc2a48a71u}> {
    using Type = pf::E8;
    constexpr static ID TypeID = ::pf::meta::ID{0xed18c7ad00306dfeu, 0x6dfc356bc2a48a71u};

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

    constexpr static auto Name = ::pf::StringLiteral{"E8"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E8"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0xea4a12721374feb0u, 0x4e76e3a6820f7fbfu}, ::pf::meta::ID{0xbe64defa716a62f4u, 0x49f26da8263576ceu}, ::pf::meta::ID{0x30469ae1a668d451u, 0x507ee729b512eebu}, ::pf::meta::ID{0x578f60f284a7152fu, 0xebfed46dfd0ae5bfu}, ::pf::meta::ID{0xdab9ca79427b717fu, 0xcbb06bd7483c7235u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x62fabb0fe64694b7u, 0xc950a23012437092u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x62fabb0fe64694b7u, 0xc950a23012437092u}, ::pf::meta::ID{0xed18c7ad00306dfeu, 0x6dfc356bc2a48a71u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4a6bcb1286b5b901u, 0xfa9cd1038bd790d7u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x4a6bcb1286b5b901u, 0xfa9cd1038bd790d7u}, ::pf::meta::ID{0xed18c7ad00306dfeu, 0x6dfc356bc2a48a71u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd44bf6a5d5c6f969u, 0xbf57e8bf1db3460u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xd44bf6a5d5c6f969u, 0xbf57e8bf1db3460u}, ::pf::meta::ID{0xed18c7ad00306dfeu, 0x6dfc356bc2a48a71u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x47b3860eb5aa1b16u, 0xafd12a40ee65ee0au}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x47b3860eb5aa1b16u, 0xafd12a40ee65ee0au}, ::pf::meta::ID{0x62fabb0fe64694b7u, 0xc950a23012437092u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xedf7710c7fc7acd3u, 0xf0eed6560f78bf1u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xedf7710c7fc7acd3u, 0xf0eed6560f78bf1u}, ::pf::meta::ID{0xed18c7ad00306dfeu, 0x6dfc356bc2a48a71u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8b9ebca444c62150u, 0x6c6bf3cda25e804fu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x8b9ebca444c62150u, 0x6c6bf3cda25e804fu}, ::pf::meta::ID{0x62fabb0fe64694b7u, 0xc950a23012437092u}> {};

/****************************** pf::E8 END ******************************/
namespace pf::meta::details {
/****************************** pf::E8 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8>() {
    return ::pf::meta::ID{0xed18c7ad00306dfeu, 0x6dfc356bc2a48a71u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8>() {
    return ::pf::meta::ID{0x62fabb0fe64694b7u, 0xc950a23012437092u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 &>() {
    return ::pf::meta::ID{0x4a6bcb1286b5b901u, 0xfa9cd1038bd790d7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 &&>() {
    return ::pf::meta::ID{0xd44bf6a5d5c6f969u, 0xbf57e8bf1db3460u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8 &>() {
    return ::pf::meta::ID{0x47b3860eb5aa1b16u, 0xafd12a40ee65ee0au};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 *>() {
    return ::pf::meta::ID{0xedf7710c7fc7acd3u, 0xf0eed6560f78bf1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8 *>() {
    return ::pf::meta::ID{0x8b9ebca444c62150u, 0x6c6bf3cda25e804fu};
}
/****************************** pf::E8 END ******************************/

/****************************** pf::E8::pf::E8::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::A>() {
return ::pf::meta::ID{0xea4a12721374feb0u, 0x4e76e3a6820f7fbfu};
}
/****************************** pf::E8::pf::E8::A END ******************************/

/****************************** pf::E8::pf::E8::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::B>() {
return ::pf::meta::ID{0xbe64defa716a62f4u, 0x49f26da8263576ceu};
}
/****************************** pf::E8::pf::E8::B END ******************************/

/****************************** pf::E8::pf::E8::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::C>() {
return ::pf::meta::ID{0x30469ae1a668d451u, 0x507ee729b512eebu};
}
/****************************** pf::E8::pf::E8::C END ******************************/

/****************************** pf::E8::pf::E8::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::D>() {
return ::pf::meta::ID{0x578f60f284a7152fu, 0xebfed46dfd0ae5bfu};
}
/****************************** pf::E8::pf::E8::D END ******************************/

/****************************** pf::E8::pf::E8::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::E>() {
return ::pf::meta::ID{0xdab9ca79427b717fu, 0xcbb06bd7483c7235u};
}
/****************************** pf::E8::pf::E8::E END ******************************/
}
/****************************** pf::E9::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x307e97f360df60eu, 0xdc342eefff12e14u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x307e97f360df60eu, 0xdc342eefff12e14u};
    constexpr static ID TypeID = ::pf::meta::ID{0xe158a1e7a746e654u, 0xe16d4b43127c5d02u};
    using Type = pf::E9;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xea362cb32346791bu, 0x3dbe2cd92195545au}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xea362cb32346791bu, 0x3dbe2cd92195545au};
    constexpr static ID TypeID = ::pf::meta::ID{0xe158a1e7a746e654u, 0xe16d4b43127c5d02u};
    using Type = pf::E9;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x970d36347f5c90c4u, 0x7270f4985fdfd434u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x970d36347f5c90c4u, 0x7270f4985fdfd434u};
    constexpr static ID TypeID = ::pf::meta::ID{0xe158a1e7a746e654u, 0xe16d4b43127c5d02u};
    using Type = pf::E9;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa48a5c1a0a11122cu, 0xf63730f77acb7892u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xa48a5c1a0a11122cu, 0xf63730f77acb7892u};
    constexpr static ID TypeID = ::pf::meta::ID{0xe158a1e7a746e654u, 0xe16d4b43127c5d02u};
    using Type = pf::E9;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4dc7a58dd1790acfu, 0x4464d1a11045c240u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x4dc7a58dd1790acfu, 0x4464d1a11045c240u};
    constexpr static ID TypeID = ::pf::meta::ID{0xe158a1e7a746e654u, 0xe16d4b43127c5d02u};
    using Type = pf::E9;

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe158a1e7a746e654u, 0xe16d4b43127c5d02u}> {
    using Type = pf::E9;
    constexpr static ID TypeID = ::pf::meta::ID{0xe158a1e7a746e654u, 0xe16d4b43127c5d02u};

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

    constexpr static auto Name = ::pf::StringLiteral{"E9"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E9"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0x307e97f360df60eu, 0xdc342eefff12e14u}, ::pf::meta::ID{0xea362cb32346791bu, 0x3dbe2cd92195545au}, ::pf::meta::ID{0x970d36347f5c90c4u, 0x7270f4985fdfd434u}, ::pf::meta::ID{0xa48a5c1a0a11122cu, 0xf63730f77acb7892u}, ::pf::meta::ID{0x4dc7a58dd1790acfu, 0x4464d1a11045c240u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8999d6d58bd2fb2au, 0x11b8ae5c95f921acu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x8999d6d58bd2fb2au, 0x11b8ae5c95f921acu}, ::pf::meta::ID{0xe158a1e7a746e654u, 0xe16d4b43127c5d02u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3ab13ded483f38eu, 0xc6aad0486936bc63u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x3ab13ded483f38eu, 0xc6aad0486936bc63u}, ::pf::meta::ID{0xe158a1e7a746e654u, 0xe16d4b43127c5d02u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc9c0e596e43dd2b7u, 0x590a67655620b9b5u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xc9c0e596e43dd2b7u, 0x590a67655620b9b5u}, ::pf::meta::ID{0xe158a1e7a746e654u, 0xe16d4b43127c5d02u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x96072bce78455c86u, 0x71fcd13ac4e6f55au}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x96072bce78455c86u, 0x71fcd13ac4e6f55au}, ::pf::meta::ID{0x8999d6d58bd2fb2au, 0x11b8ae5c95f921acu}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xafd619bb4b6a0834u, 0x92b5ce3a490b77aau}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xafd619bb4b6a0834u, 0x92b5ce3a490b77aau}, ::pf::meta::ID{0xe158a1e7a746e654u, 0xe16d4b43127c5d02u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x72e75e254b1b0a9du, 0xc555ea5ee4722fe2u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x72e75e254b1b0a9du, 0xc555ea5ee4722fe2u}, ::pf::meta::ID{0x8999d6d58bd2fb2au, 0x11b8ae5c95f921acu}> {};

/****************************** pf::E9 END ******************************/
namespace pf::meta::details {
/****************************** pf::E9 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9>() {
    return ::pf::meta::ID{0xe158a1e7a746e654u, 0xe16d4b43127c5d02u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9>() {
    return ::pf::meta::ID{0x8999d6d58bd2fb2au, 0x11b8ae5c95f921acu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 &>() {
    return ::pf::meta::ID{0x3ab13ded483f38eu, 0xc6aad0486936bc63u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 &&>() {
    return ::pf::meta::ID{0xc9c0e596e43dd2b7u, 0x590a67655620b9b5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9 &>() {
    return ::pf::meta::ID{0x96072bce78455c86u, 0x71fcd13ac4e6f55au};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 *>() {
    return ::pf::meta::ID{0xafd619bb4b6a0834u, 0x92b5ce3a490b77aau};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9 *>() {
    return ::pf::meta::ID{0x72e75e254b1b0a9du, 0xc555ea5ee4722fe2u};
}
/****************************** pf::E9 END ******************************/

/****************************** pf::E9::pf::E9::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::A>() {
return ::pf::meta::ID{0x307e97f360df60eu, 0xdc342eefff12e14u};
}
/****************************** pf::E9::pf::E9::A END ******************************/

/****************************** pf::E9::pf::E9::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::B>() {
return ::pf::meta::ID{0xea362cb32346791bu, 0x3dbe2cd92195545au};
}
/****************************** pf::E9::pf::E9::B END ******************************/

/****************************** pf::E9::pf::E9::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::C>() {
return ::pf::meta::ID{0x970d36347f5c90c4u, 0x7270f4985fdfd434u};
}
/****************************** pf::E9::pf::E9::C END ******************************/

/****************************** pf::E9::pf::E9::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::D>() {
return ::pf::meta::ID{0xa48a5c1a0a11122cu, 0xf63730f77acb7892u};
}
/****************************** pf::E9::pf::E9::D END ******************************/

/****************************** pf::E9::pf::E9::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::E>() {
return ::pf::meta::ID{0x4dc7a58dd1790acfu, 0x4464d1a11045c240u};
}
/****************************** pf::E9::pf::E9::E END ******************************/
}
/****************************** pf::E10::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3fb266a0d5452808u, 0x7a21cd8ff673da5u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x3fb266a0d5452808u, 0x7a21cd8ff673da5u};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E10::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E10 Value = pf::E10::A;
};
/****************************** pf::E10::A END ******************************/

/****************************** pf::E10::B START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xeddfd68136da12bcu, 0xbaa0250d8074729cu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xeddfd68136da12bcu, 0xbaa0250d8074729cu};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E10::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E10 Value = pf::E10::B;
};
/****************************** pf::E10::B END ******************************/

/****************************** pf::E10::C START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xafa561ecb95b57a6u, 0x4ff78dad827beb2u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xafa561ecb95b57a6u, 0x4ff78dad827beb2u};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E10::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E10 Value = pf::E10::C;
};
/****************************** pf::E10::C END ******************************/

/****************************** pf::E10::D START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6169b3c8d6add85u, 0x892572ea7e566282u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x6169b3c8d6add85u, 0x892572ea7e566282u};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E10::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E10 Value = pf::E10::D;
};
/****************************** pf::E10::D END ******************************/

/****************************** pf::E10::E START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3a86b59cd8ec70adu, 0xcddbfa56fed8a5acu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x3a86b59cd8ec70adu, 0xcddbfa56fed8a5acu};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E10::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E10 Value = pf::E10::E;
};
/****************************** pf::E10::E END ******************************/

/****************************** pf::E10::F START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdce31e3196acb4fu, 0xdf08bc35b80d0a50u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xdce31e3196acb4fu, 0xdf08bc35b80d0a50u};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"F"};
    constexpr static auto FullName = StringLiteral{"pf::E10::F"};

    constexpr static int UnderlyingValue = 5;
    constexpr static pf::E10 Value = pf::E10::F;
};
/****************************** pf::E10::F END ******************************/

/****************************** pf::E10::G START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc4f57bd8cb375bd2u, 0x70ddb3fb81b90c7du}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xc4f57bd8cb375bd2u, 0x70ddb3fb81b90c7du};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"G"};
    constexpr static auto FullName = StringLiteral{"pf::E10::G"};

    constexpr static int UnderlyingValue = 6;
    constexpr static pf::E10 Value = pf::E10::G;
};
/****************************** pf::E10::G END ******************************/

/****************************** pf::E10::H START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x27db8f84ecc14482u, 0xbd56014f0ab9229bu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x27db8f84ecc14482u, 0xbd56014f0ab9229bu};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"H"};
    constexpr static auto FullName = StringLiteral{"pf::E10::H"};

    constexpr static int UnderlyingValue = 7;
    constexpr static pf::E10 Value = pf::E10::H;
};
/****************************** pf::E10::H END ******************************/

/****************************** pf::E10::I START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb0ab4ce617fd44a0u, 0x8cadf90f23d62572u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xb0ab4ce617fd44a0u, 0x8cadf90f23d62572u};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"I"};
    constexpr static auto FullName = StringLiteral{"pf::E10::I"};

    constexpr static int UnderlyingValue = 8;
    constexpr static pf::E10 Value = pf::E10::I;
};
/****************************** pf::E10::I END ******************************/

/****************************** pf::E10::J START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3e7c0f7c3ab07e89u, 0x998d19b959af0597u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x3e7c0f7c3ab07e89u, 0x998d19b959af0597u};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"J"};
    constexpr static auto FullName = StringLiteral{"pf::E10::J"};

    constexpr static int UnderlyingValue = 9;
    constexpr static pf::E10 Value = pf::E10::J;
};
/****************************** pf::E10::J END ******************************/

/****************************** pf::E10::K START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe2d9b13352288c9bu, 0x86b2ad173bc24d1cu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xe2d9b13352288c9bu, 0x86b2ad173bc24d1cu};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"K"};
    constexpr static auto FullName = StringLiteral{"pf::E10::K"};

    constexpr static int UnderlyingValue = 10;
    constexpr static pf::E10 Value = pf::E10::K;
};
/****************************** pf::E10::K END ******************************/

/****************************** pf::E10::L START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd3f24a7a1509d60au, 0xf84d5e3c463a195fu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xd3f24a7a1509d60au, 0xf84d5e3c463a195fu};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"L"};
    constexpr static auto FullName = StringLiteral{"pf::E10::L"};

    constexpr static int UnderlyingValue = 11;
    constexpr static pf::E10 Value = pf::E10::L;
};
/****************************** pf::E10::L END ******************************/

/****************************** pf::E10::M START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2d7eb288437c1497u, 0xa8f7671c279f71c1u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x2d7eb288437c1497u, 0xa8f7671c279f71c1u};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"M"};
    constexpr static auto FullName = StringLiteral{"pf::E10::M"};

    constexpr static int UnderlyingValue = 12;
    constexpr static pf::E10 Value = pf::E10::M;
};
/****************************** pf::E10::M END ******************************/

/****************************** pf::E10::N START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdd1d336dfdd87f81u, 0x89ff52cf7a9aab71u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xdd1d336dfdd87f81u, 0x89ff52cf7a9aab71u};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"N"};
    constexpr static auto FullName = StringLiteral{"pf::E10::N"};

    constexpr static int UnderlyingValue = 13;
    constexpr static pf::E10 Value = pf::E10::N;
};
/****************************** pf::E10::N END ******************************/

/****************************** pf::E10::O START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x70e8653ba8489133u, 0x44193c3c84aaa47bu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x70e8653ba8489133u, 0x44193c3c84aaa47bu};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"O"};
    constexpr static auto FullName = StringLiteral{"pf::E10::O"};

    constexpr static int UnderlyingValue = 14;
    constexpr static pf::E10 Value = pf::E10::O;
};
/****************************** pf::E10::O END ******************************/

/****************************** pf::E10::P START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x597747a39c26bcecu, 0xed0667c2a5e3aedcu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x597747a39c26bcecu, 0xed0667c2a5e3aedcu};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"P"};
    constexpr static auto FullName = StringLiteral{"pf::E10::P"};

    constexpr static int UnderlyingValue = 15;
    constexpr static pf::E10 Value = pf::E10::P;
};
/****************************** pf::E10::P END ******************************/

/****************************** pf::E10::Q START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6f6a5a043a5e90e1u, 0xb73395cb51245ca3u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x6f6a5a043a5e90e1u, 0xb73395cb51245ca3u};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"Q"};
    constexpr static auto FullName = StringLiteral{"pf::E10::Q"};

    constexpr static int UnderlyingValue = 16;
    constexpr static pf::E10 Value = pf::E10::Q;
};
/****************************** pf::E10::Q END ******************************/

/****************************** pf::E10::R START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe84689523cb05ddbu, 0x5bceb3393e2493bfu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xe84689523cb05ddbu, 0x5bceb3393e2493bfu};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"R"};
    constexpr static auto FullName = StringLiteral{"pf::E10::R"};

    constexpr static int UnderlyingValue = 17;
    constexpr static pf::E10 Value = pf::E10::R;
};
/****************************** pf::E10::R END ******************************/

/****************************** pf::E10::S START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb4bb8a8989d1f3f8u, 0xe4a28553b7e64753u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xb4bb8a8989d1f3f8u, 0xe4a28553b7e64753u};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"S"};
    constexpr static auto FullName = StringLiteral{"pf::E10::S"};

    constexpr static int UnderlyingValue = 18;
    constexpr static pf::E10 Value = pf::E10::S;
};
/****************************** pf::E10::S END ******************************/

/****************************** pf::E10::T START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x32ba434ab7d8b8c4u, 0xcbb1d29e265fbb1eu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x32ba434ab7d8b8c4u, 0xcbb1d29e265fbb1eu};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"T"};
    constexpr static auto FullName = StringLiteral{"pf::E10::T"};

    constexpr static int UnderlyingValue = 19;
    constexpr static pf::E10 Value = pf::E10::T;
};
/****************************** pf::E10::T END ******************************/

/****************************** pf::E10::U START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa3c9eefbef4f7f5cu, 0x59059c9b8cec100fu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xa3c9eefbef4f7f5cu, 0x59059c9b8cec100fu};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"U"};
    constexpr static auto FullName = StringLiteral{"pf::E10::U"};

    constexpr static int UnderlyingValue = 20;
    constexpr static pf::E10 Value = pf::E10::U;
};
/****************************** pf::E10::U END ******************************/

/****************************** pf::E10::V START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xea8ec2d0bc2b7d9eu, 0xd89c628b55dd2532u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xea8ec2d0bc2b7d9eu, 0xd89c628b55dd2532u};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"V"};
    constexpr static auto FullName = StringLiteral{"pf::E10::V"};

    constexpr static int UnderlyingValue = 21;
    constexpr static pf::E10 Value = pf::E10::V;
};
/****************************** pf::E10::V END ******************************/

/****************************** pf::E10::W START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x83847fab4a80ecc2u, 0x655c6e5ca53d6e97u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x83847fab4a80ecc2u, 0x655c6e5ca53d6e97u};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"W"};
    constexpr static auto FullName = StringLiteral{"pf::E10::W"};

    constexpr static int UnderlyingValue = 22;
    constexpr static pf::E10 Value = pf::E10::W;
};
/****************************** pf::E10::W END ******************************/

/****************************** pf::E10::Y START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1cd8ef458e1748dau, 0xf64172f94ab5241eu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x1cd8ef458e1748dau, 0xf64172f94ab5241eu};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"Y"};
    constexpr static auto FullName = StringLiteral{"pf::E10::Y"};

    constexpr static int UnderlyingValue = 23;
    constexpr static pf::E10 Value = pf::E10::Y;
};
/****************************** pf::E10::Y END ******************************/

/****************************** pf::E10::Z START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x96cab93844da7b88u, 0x434a1df60018afcdu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x96cab93844da7b88u, 0x434a1df60018afcdu};
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
    using Type = pf::E10;

    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"Z"};
    constexpr static auto FullName = StringLiteral{"pf::E10::Z"};

    constexpr static int UnderlyingValue = 24;
    constexpr static pf::E10 Value = pf::E10::Z;
};
/****************************** pf::E10::Z END ******************************/

/****************************** pf::E10 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u}> {
    using Type = pf::E10;
    constexpr static ID TypeID = ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};

    constexpr static std::uint64_t SourceLine = 30;
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

    constexpr static auto Name = ::pf::StringLiteral{"E10"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E10"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0x3fb266a0d5452808u, 0x7a21cd8ff673da5u}, ::pf::meta::ID{0xeddfd68136da12bcu, 0xbaa0250d8074729cu}, ::pf::meta::ID{0xafa561ecb95b57a6u, 0x4ff78dad827beb2u}, ::pf::meta::ID{0x6169b3c8d6add85u, 0x892572ea7e566282u}, ::pf::meta::ID{0x3a86b59cd8ec70adu, 0xcddbfa56fed8a5acu}, ::pf::meta::ID{0xdce31e3196acb4fu, 0xdf08bc35b80d0a50u}, ::pf::meta::ID{0xc4f57bd8cb375bd2u, 0x70ddb3fb81b90c7du}, ::pf::meta::ID{0x27db8f84ecc14482u, 0xbd56014f0ab9229bu}, ::pf::meta::ID{0xb0ab4ce617fd44a0u, 0x8cadf90f23d62572u}, ::pf::meta::ID{0x3e7c0f7c3ab07e89u, 0x998d19b959af0597u}, ::pf::meta::ID{0xe2d9b13352288c9bu, 0x86b2ad173bc24d1cu}, ::pf::meta::ID{0xd3f24a7a1509d60au, 0xf84d5e3c463a195fu}, ::pf::meta::ID{0x2d7eb288437c1497u, 0xa8f7671c279f71c1u}, ::pf::meta::ID{0xdd1d336dfdd87f81u, 0x89ff52cf7a9aab71u}, ::pf::meta::ID{0x70e8653ba8489133u, 0x44193c3c84aaa47bu}, ::pf::meta::ID{0x597747a39c26bcecu, 0xed0667c2a5e3aedcu}, ::pf::meta::ID{0x6f6a5a043a5e90e1u, 0xb73395cb51245ca3u}, ::pf::meta::ID{0xe84689523cb05ddbu, 0x5bceb3393e2493bfu}, ::pf::meta::ID{0xb4bb8a8989d1f3f8u, 0xe4a28553b7e64753u}, ::pf::meta::ID{0x32ba434ab7d8b8c4u, 0xcbb1d29e265fbb1eu}, ::pf::meta::ID{0xa3c9eefbef4f7f5cu, 0x59059c9b8cec100fu}, ::pf::meta::ID{0xea8ec2d0bc2b7d9eu, 0xd89c628b55dd2532u}, ::pf::meta::ID{0x83847fab4a80ecc2u, 0x655c6e5ca53d6e97u}, ::pf::meta::ID{0x1cd8ef458e1748dau, 0xf64172f94ab5241eu}, ::pf::meta::ID{0x96cab93844da7b88u, 0x434a1df60018afcdu});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc7b750cba6775b3bu, 0x4bfac7681cb17bbeu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xc7b750cba6775b3bu, 0x4bfac7681cb17bbeu}, ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa17d9576aad4f9ffu, 0xcedccf81869f031du}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xa17d9576aad4f9ffu, 0xcedccf81869f031du}, ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xaa804a45179b050fu, 0x660d18e35c322389u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xaa804a45179b050fu, 0x660d18e35c322389u}, ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xca4359cc27bb22cdu, 0x464bf2c95021145u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xca4359cc27bb22cdu, 0x464bf2c95021145u}, ::pf::meta::ID{0xc7b750cba6775b3bu, 0x4bfac7681cb17bbeu}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8a1537dd4ef5dd2au, 0x5c2b3c99b581a6d5u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x8a1537dd4ef5dd2au, 0x5c2b3c99b581a6d5u}, ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8af82d7e46f1a661u, 0x75f0453ce489c3e4u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x8af82d7e46f1a661u, 0x75f0453ce489c3e4u}, ::pf::meta::ID{0xc7b750cba6775b3bu, 0x4bfac7681cb17bbeu}> {};

/****************************** pf::E10 END ******************************/
namespace pf::meta::details {
/****************************** pf::E10 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E10>() {
    return ::pf::meta::ID{0xed359fa9f4aff6d6u, 0x8734f1554236a577u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E10>() {
    return ::pf::meta::ID{0xc7b750cba6775b3bu, 0x4bfac7681cb17bbeu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E10 &>() {
    return ::pf::meta::ID{0xa17d9576aad4f9ffu, 0xcedccf81869f031du};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E10 &&>() {
    return ::pf::meta::ID{0xaa804a45179b050fu, 0x660d18e35c322389u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E10 &>() {
    return ::pf::meta::ID{0xca4359cc27bb22cdu, 0x464bf2c95021145u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E10 *>() {
    return ::pf::meta::ID{0x8a1537dd4ef5dd2au, 0x5c2b3c99b581a6d5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E10 *>() {
    return ::pf::meta::ID{0x8af82d7e46f1a661u, 0x75f0453ce489c3e4u};
}
/****************************** pf::E10 END ******************************/

/****************************** pf::E10::pf::E10::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::A>() {
return ::pf::meta::ID{0x3fb266a0d5452808u, 0x7a21cd8ff673da5u};
}
/****************************** pf::E10::pf::E10::A END ******************************/

/****************************** pf::E10::pf::E10::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::B>() {
return ::pf::meta::ID{0xeddfd68136da12bcu, 0xbaa0250d8074729cu};
}
/****************************** pf::E10::pf::E10::B END ******************************/

/****************************** pf::E10::pf::E10::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::C>() {
return ::pf::meta::ID{0xafa561ecb95b57a6u, 0x4ff78dad827beb2u};
}
/****************************** pf::E10::pf::E10::C END ******************************/

/****************************** pf::E10::pf::E10::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::D>() {
return ::pf::meta::ID{0x6169b3c8d6add85u, 0x892572ea7e566282u};
}
/****************************** pf::E10::pf::E10::D END ******************************/

/****************************** pf::E10::pf::E10::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::E>() {
return ::pf::meta::ID{0x3a86b59cd8ec70adu, 0xcddbfa56fed8a5acu};
}
/****************************** pf::E10::pf::E10::E END ******************************/

/****************************** pf::E10::pf::E10::F START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::F>() {
return ::pf::meta::ID{0xdce31e3196acb4fu, 0xdf08bc35b80d0a50u};
}
/****************************** pf::E10::pf::E10::F END ******************************/

/****************************** pf::E10::pf::E10::G START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::G>() {
return ::pf::meta::ID{0xc4f57bd8cb375bd2u, 0x70ddb3fb81b90c7du};
}
/****************************** pf::E10::pf::E10::G END ******************************/

/****************************** pf::E10::pf::E10::H START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::H>() {
return ::pf::meta::ID{0x27db8f84ecc14482u, 0xbd56014f0ab9229bu};
}
/****************************** pf::E10::pf::E10::H END ******************************/

/****************************** pf::E10::pf::E10::I START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::I>() {
return ::pf::meta::ID{0xb0ab4ce617fd44a0u, 0x8cadf90f23d62572u};
}
/****************************** pf::E10::pf::E10::I END ******************************/

/****************************** pf::E10::pf::E10::J START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::J>() {
return ::pf::meta::ID{0x3e7c0f7c3ab07e89u, 0x998d19b959af0597u};
}
/****************************** pf::E10::pf::E10::J END ******************************/

/****************************** pf::E10::pf::E10::K START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::K>() {
return ::pf::meta::ID{0xe2d9b13352288c9bu, 0x86b2ad173bc24d1cu};
}
/****************************** pf::E10::pf::E10::K END ******************************/

/****************************** pf::E10::pf::E10::L START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::L>() {
return ::pf::meta::ID{0xd3f24a7a1509d60au, 0xf84d5e3c463a195fu};
}
/****************************** pf::E10::pf::E10::L END ******************************/

/****************************** pf::E10::pf::E10::M START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::M>() {
return ::pf::meta::ID{0x2d7eb288437c1497u, 0xa8f7671c279f71c1u};
}
/****************************** pf::E10::pf::E10::M END ******************************/

/****************************** pf::E10::pf::E10::N START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::N>() {
return ::pf::meta::ID{0xdd1d336dfdd87f81u, 0x89ff52cf7a9aab71u};
}
/****************************** pf::E10::pf::E10::N END ******************************/

/****************************** pf::E10::pf::E10::O START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::O>() {
return ::pf::meta::ID{0x70e8653ba8489133u, 0x44193c3c84aaa47bu};
}
/****************************** pf::E10::pf::E10::O END ******************************/

/****************************** pf::E10::pf::E10::P START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::P>() {
return ::pf::meta::ID{0x597747a39c26bcecu, 0xed0667c2a5e3aedcu};
}
/****************************** pf::E10::pf::E10::P END ******************************/

/****************************** pf::E10::pf::E10::Q START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::Q>() {
return ::pf::meta::ID{0x6f6a5a043a5e90e1u, 0xb73395cb51245ca3u};
}
/****************************** pf::E10::pf::E10::Q END ******************************/

/****************************** pf::E10::pf::E10::R START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::R>() {
return ::pf::meta::ID{0xe84689523cb05ddbu, 0x5bceb3393e2493bfu};
}
/****************************** pf::E10::pf::E10::R END ******************************/

/****************************** pf::E10::pf::E10::S START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::S>() {
return ::pf::meta::ID{0xb4bb8a8989d1f3f8u, 0xe4a28553b7e64753u};
}
/****************************** pf::E10::pf::E10::S END ******************************/

/****************************** pf::E10::pf::E10::T START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::T>() {
return ::pf::meta::ID{0x32ba434ab7d8b8c4u, 0xcbb1d29e265fbb1eu};
}
/****************************** pf::E10::pf::E10::T END ******************************/

/****************************** pf::E10::pf::E10::U START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::U>() {
return ::pf::meta::ID{0xa3c9eefbef4f7f5cu, 0x59059c9b8cec100fu};
}
/****************************** pf::E10::pf::E10::U END ******************************/

/****************************** pf::E10::pf::E10::V START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::V>() {
return ::pf::meta::ID{0xea8ec2d0bc2b7d9eu, 0xd89c628b55dd2532u};
}
/****************************** pf::E10::pf::E10::V END ******************************/

/****************************** pf::E10::pf::E10::W START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::W>() {
return ::pf::meta::ID{0x83847fab4a80ecc2u, 0x655c6e5ca53d6e97u};
}
/****************************** pf::E10::pf::E10::W END ******************************/

/****************************** pf::E10::pf::E10::Y START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::Y>() {
return ::pf::meta::ID{0x1cd8ef458e1748dau, 0xf64172f94ab5241eu};
}
/****************************** pf::E10::pf::E10::Y END ******************************/

/****************************** pf::E10::pf::E10::Z START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E10::Z>() {
return ::pf::meta::ID{0x96cab93844da7b88u, 0x434a1df60018afcdu};
}
/****************************** pf::E10::pf::E10::Z END ******************************/
}

