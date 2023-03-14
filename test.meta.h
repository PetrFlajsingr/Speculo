
#pragma once

#include "meta/common.h"
#include "test.h"
#include <pf_common/array.h>
#include <pf_common/concepts/ranges.h>
#include <type_traits>

/****************************** pf::SomeEnum::Value1 START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x13871a98f707c312u, 0x51fb264a64e1232bu}> {
  struct details {
    constexpr static auto ArgArray_15782916277954205539 = pf::make_array<std::string_view>();
    constexpr static auto ArgArray_10674978854988230634 = pf::make_array<std::string_view>();
    constexpr static auto ArgArray_6689237690803036314 = pf::make_array<std::string_view>();
  };
  constexpr static ID ValueID = ::pf::meta::ID{0x13871a98f707c312u, 0x51fb264a64e1232bu};
  constexpr static ID TypeID = ::pf::meta::ID{0x983044bf61a82f57u, 0x89d685cc09c62312u};
  using Type = pf::SomeEnum;

  constexpr static std::uint64_t SourceLine = 5;
  constexpr static std::uint64_t SourceColumn = 5;

  constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(
      pf::meta::Attribute{"test", std::span<const std::string_view>{details::ArgArray_15782916277954205539}},
      pf::meta::Attribute{"test2", std::span<const std::string_view>{details::ArgArray_10674978854988230634}},
      pf::meta::Attribute{"test3", std::span<const std::string_view>{details::ArgArray_6689237690803036314}});

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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x402d1bf3047e6a3du, 0x1025a9b127a7d838u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x402d1bf3047e6a3du, 0x1025a9b127a7d838u};
  constexpr static ID TypeID = ::pf::meta::ID{0x983044bf61a82f57u, 0x89d685cc09c62312u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x983044bf61a82f57u, 0x89d685cc09c62312u}> {
  struct details {
    constexpr static auto ArgArray_4090133644610312068 = pf::make_array<std::string_view>(
        R"arg(()()()((())))arg", R"arg([[nodiscard]])arg", R"arg(1ll)arg", R"arg(1.011)arg", R"arg([]{}())arg",
        R"arg("yeet")arg", R"arg('a')arg", R"arg([][][]:::3214234...[][][][])arg");
    constexpr static auto ArgArray_15334654197775934216 = pf::make_array<std::string_view>();
    constexpr static auto ArgArray_11138086033957547105 =
        pf::make_array<std::string_view>(R"arg(1ll)arg", R"arg(1.011)arg", R"arg("yeet")arg");
    constexpr static auto ArgArray_14825723476362556651 = pf::make_array<std::string_view>();
  };
  using Type = pf::SomeEnum;
  constexpr static ID TypeID = ::pf::meta::ID{0x983044bf61a82f57u, 0x89d685cc09c62312u};

  constexpr static std::uint64_t SourceLine = 5;
  constexpr static std::uint64_t SourceColumn = 5;

  constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(
      pf::meta::Attribute{"pf::operators", std::span<const std::string_view>{details::ArgArray_4090133644610312068}},
      pf::meta::Attribute{"pf::hihi", std::span<const std::string_view>{details::ArgArray_15334654197775934216}},
      pf::meta::Attribute{"pf::operators2", std::span<const std::string_view>{details::ArgArray_11138086033957547105}},
      pf::meta::Attribute{"pf::hihi2", std::span<const std::string_view>{details::ArgArray_14825723476362556651}});

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues =
      pf::make_array<pf::meta::Info>(::pf::meta::ID{0x13871a98f707c312u, 0x51fb264a64e1232bu},
                                     ::pf::meta::ID{0x402d1bf3047e6a3du, 0x1025a9b127a7d838u});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x748e1ed45718ed5fu, 0x4afb3ec4362d627fu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x748e1ed45718ed5fu, 0x4afb3ec4362d627fu},
                                                ::pf::meta::ID{0x983044bf61a82f57u, 0x89d685cc09c62312u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe9e06f4950735d48u, 0xacd78f438fbb876u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xe9e06f4950735d48u, 0xacd78f438fbb876u},
                                               ::pf::meta::ID{0x983044bf61a82f57u, 0x89d685cc09c62312u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa10a0f5d41e2432cu, 0x709f065c19743172u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xa10a0f5d41e2432cu, 0x709f065c19743172u},
                                               ::pf::meta::ID{0x983044bf61a82f57u, 0x89d685cc09c62312u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xfda59c798254ea76u, 0xca3cb24f13e7e683u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xfda59c798254ea76u, 0xca3cb24f13e7e683u},
                                               ::pf::meta::ID{0x748e1ed45718ed5fu, 0x4afb3ec4362d627fu}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x65d757db6b2a9157u, 0xd151d04445e94a6cu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x65d757db6b2a9157u, 0xd151d04445e94a6cu},
                                              ::pf::meta::ID{0x983044bf61a82f57u, 0x89d685cc09c62312u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa15458461a050d26u, 0x26171aeff275a141u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xa15458461a050d26u, 0x26171aeff275a141u},
                                              ::pf::meta::ID{0x748e1ed45718ed5fu, 0x4afb3ec4362d627fu}> {};

/****************************** pf::SomeEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::SomeEnum START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::SomeEnum>() {
  return ::pf::meta::ID{0x983044bf61a82f57u, 0x89d685cc09c62312u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum>() {
  return ::pf::meta::ID{0x748e1ed45718ed5fu, 0x4afb3ec4362d627fu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::SomeEnum &>() {
  return ::pf::meta::ID{0xe9e06f4950735d48u, 0xacd78f438fbb876u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::SomeEnum &&>() {
  return ::pf::meta::ID{0xa10a0f5d41e2432cu, 0x709f065c19743172u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum &>() {
  return ::pf::meta::ID{0xfda59c798254ea76u, 0xca3cb24f13e7e683u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::SomeEnum *>() {
  return ::pf::meta::ID{0x65d757db6b2a9157u, 0xd151d04445e94a6cu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum *>() {
  return ::pf::meta::ID{0xa15458461a050d26u, 0x26171aeff275a141u};
}
/****************************** pf::SomeEnum END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value1 START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value1>() {
  return ::pf::meta::ID{0x13871a98f707c312u, 0x51fb264a64e1232bu};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value1 END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value2 START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value2>() {
  return ::pf::meta::ID{0x402d1bf3047e6a3du, 0x1025a9b127a7d838u};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value2 END ******************************/
} // namespace pf::meta::details
/****************************** pf::Test::E::Value1 START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa9cee89e3a40b6c4u, 0xe768e0e72a8d05edu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xa9cee89e3a40b6c4u, 0xe768e0e72a8d05edu};
  constexpr static ID TypeID = ::pf::meta::ID{0x8671c4d368d3bd56u, 0x6ddd579a72910c5u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdf11d5454cf55022u, 0xef60ed25ffd694a7u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xdf11d5454cf55022u, 0xef60ed25ffd694a7u};
  constexpr static ID TypeID = ::pf::meta::ID{0x8671c4d368d3bd56u, 0x6ddd579a72910c5u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8671c4d368d3bd56u, 0x6ddd579a72910c5u}> {
  struct details {};
  using Type = pf::Test::E;
  constexpr static ID TypeID = ::pf::meta::ID{0x8671c4d368d3bd56u, 0x6ddd579a72910c5u};

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues =
      pf::make_array<pf::meta::Info>(::pf::meta::ID{0xa9cee89e3a40b6c4u, 0xe768e0e72a8d05edu},
                                     ::pf::meta::ID{0xdf11d5454cf55022u, 0xef60ed25ffd694a7u});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x590647d224b18430u, 0x92357353acef1508u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x590647d224b18430u, 0x92357353acef1508u},
                                                ::pf::meta::ID{0x8671c4d368d3bd56u, 0x6ddd579a72910c5u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8203335ea25348cbu, 0x813cf5f46eab0448u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x8203335ea25348cbu, 0x813cf5f46eab0448u},
                                               ::pf::meta::ID{0x8671c4d368d3bd56u, 0x6ddd579a72910c5u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd2e1809d7bd53b45u, 0x1d4b682cfcedc129u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xd2e1809d7bd53b45u, 0x1d4b682cfcedc129u},
                                               ::pf::meta::ID{0x8671c4d368d3bd56u, 0x6ddd579a72910c5u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdbde4a7245f11c46u, 0x894fea08bde17a09u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xdbde4a7245f11c46u, 0x894fea08bde17a09u},
                                               ::pf::meta::ID{0x590647d224b18430u, 0x92357353acef1508u}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1040c4a9d6967f9du, 0x193e86d6b28035feu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x1040c4a9d6967f9du, 0x193e86d6b28035feu},
                                              ::pf::meta::ID{0x8671c4d368d3bd56u, 0x6ddd579a72910c5u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xcd236e758d6a55f7u, 0x7e3463cde5b6dd72u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xcd236e758d6a55f7u, 0x7e3463cde5b6dd72u},
                                              ::pf::meta::ID{0x590647d224b18430u, 0x92357353acef1508u}> {};

/****************************** pf::Test::E END ******************************/
namespace pf::meta::details {
/****************************** pf::Test::E START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::Test::E>() {
  return ::pf::meta::ID{0x8671c4d368d3bd56u, 0x6ddd579a72910c5u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::Test::E>() {
  return ::pf::meta::ID{0x590647d224b18430u, 0x92357353acef1508u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::Test::E &>() {
  return ::pf::meta::ID{0x8203335ea25348cbu, 0x813cf5f46eab0448u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::Test::E &&>() {
  return ::pf::meta::ID{0xd2e1809d7bd53b45u, 0x1d4b682cfcedc129u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::Test::E &>() {
  return ::pf::meta::ID{0xdbde4a7245f11c46u, 0x894fea08bde17a09u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::Test::E *>() {
  return ::pf::meta::ID{0x1040c4a9d6967f9du, 0x193e86d6b28035feu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::Test::E *>() {
  return ::pf::meta::ID{0xcd236e758d6a55f7u, 0x7e3463cde5b6dd72u};
}
/****************************** pf::Test::E END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value1 START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::Test::E::Value1>() {
  return ::pf::meta::ID{0xa9cee89e3a40b6c4u, 0xe768e0e72a8d05edu};
}
/****************************** pf::Test::E::pf::Test::E::Value1 END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value2 START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::Test::E::Value2>() {
  return ::pf::meta::ID{0xdf11d5454cf55022u, 0xef60ed25ffd694a7u};
}
/****************************** pf::Test::E::pf::Test::E::Value2 END ******************************/
} // namespace pf::meta::details
/****************************** pf::EmptyEnum START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xfaeb48341d2d2fe2u, 0x865787d1f654c6e0u}> {
  struct details {};
  using Type = pf::EmptyEnum;
  constexpr static ID TypeID = ::pf::meta::ID{0xfaeb48341d2d2fe2u, 0x865787d1f654c6e0u};

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
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x64855a2bb08006f3u, 0x610b6ab60aaffa04u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x64855a2bb08006f3u, 0x610b6ab60aaffa04u},
                                                ::pf::meta::ID{0xfaeb48341d2d2fe2u, 0x865787d1f654c6e0u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x14d8b0165b735326u, 0x32596a012c22dc39u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x14d8b0165b735326u, 0x32596a012c22dc39u},
                                               ::pf::meta::ID{0xfaeb48341d2d2fe2u, 0x865787d1f654c6e0u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9c98d3b5e718600bu, 0xae8b301d83f746f4u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x9c98d3b5e718600bu, 0xae8b301d83f746f4u},
                                               ::pf::meta::ID{0xfaeb48341d2d2fe2u, 0x865787d1f654c6e0u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xee9f2a39fd27f50u, 0x33d1d752e10f2675u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xee9f2a39fd27f50u, 0x33d1d752e10f2675u},
                                               ::pf::meta::ID{0x64855a2bb08006f3u, 0x610b6ab60aaffa04u}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x46d6622cb2c6191bu, 0xb4d320cd1258374fu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x46d6622cb2c6191bu, 0xb4d320cd1258374fu},
                                              ::pf::meta::ID{0xfaeb48341d2d2fe2u, 0x865787d1f654c6e0u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xedab92ce0956b290u, 0x833ca855f03f606au}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xedab92ce0956b290u, 0x833ca855f03f606au},
                                              ::pf::meta::ID{0x64855a2bb08006f3u, 0x610b6ab60aaffa04u}> {};

/****************************** pf::EmptyEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::EmptyEnum START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::EmptyEnum>() {
  return ::pf::meta::ID{0xfaeb48341d2d2fe2u, 0x865787d1f654c6e0u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum>() {
  return ::pf::meta::ID{0x64855a2bb08006f3u, 0x610b6ab60aaffa04u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &>() {
  return ::pf::meta::ID{0x14d8b0165b735326u, 0x32596a012c22dc39u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &&>() {
  return ::pf::meta::ID{0x9c98d3b5e718600bu, 0xae8b301d83f746f4u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum &>() {
  return ::pf::meta::ID{0xee9f2a39fd27f50u, 0x33d1d752e10f2675u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::EmptyEnum *>() {
  return ::pf::meta::ID{0x46d6622cb2c6191bu, 0xb4d320cd1258374fu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum *>() {
  return ::pf::meta::ID{0xedab92ce0956b290u, 0x833ca855f03f606au};
}
/****************************** pf::EmptyEnum END ******************************/
} // namespace pf::meta::details
/****************************** pf::E1::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe359498b10031608u, 0x25908ab251b7757cu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xe359498b10031608u, 0x25908ab251b7757cu};
  constexpr static ID TypeID = ::pf::meta::ID{0x1d81d062cf8d0aa2u, 0x390f54d5a9fd22b4u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9384adfa7143e343u, 0x79465c0c96fa3642u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x9384adfa7143e343u, 0x79465c0c96fa3642u};
  constexpr static ID TypeID = ::pf::meta::ID{0x1d81d062cf8d0aa2u, 0x390f54d5a9fd22b4u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf67059a01d62f68fu, 0x6d4353dac47e35deu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xf67059a01d62f68fu, 0x6d4353dac47e35deu};
  constexpr static ID TypeID = ::pf::meta::ID{0x1d81d062cf8d0aa2u, 0x390f54d5a9fd22b4u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x902650e1a5bd478bu, 0x9da798ff2be51d63u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x902650e1a5bd478bu, 0x9da798ff2be51d63u};
  constexpr static ID TypeID = ::pf::meta::ID{0x1d81d062cf8d0aa2u, 0x390f54d5a9fd22b4u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4124f5e3d8921ca5u, 0x789fa6a5135206f8u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x4124f5e3d8921ca5u, 0x789fa6a5135206f8u};
  constexpr static ID TypeID = ::pf::meta::ID{0x1d81d062cf8d0aa2u, 0x390f54d5a9fd22b4u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1d81d062cf8d0aa2u, 0x390f54d5a9fd22b4u}> {
  struct details {};
  using Type = pf::E1;
  constexpr static ID TypeID = ::pf::meta::ID{0x1d81d062cf8d0aa2u, 0x390f54d5a9fd22b4u};

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues =
      pf::make_array<pf::meta::Info>(::pf::meta::ID{0xe359498b10031608u, 0x25908ab251b7757cu},
                                     ::pf::meta::ID{0x9384adfa7143e343u, 0x79465c0c96fa3642u},
                                     ::pf::meta::ID{0xf67059a01d62f68fu, 0x6d4353dac47e35deu},
                                     ::pf::meta::ID{0x902650e1a5bd478bu, 0x9da798ff2be51d63u},
                                     ::pf::meta::ID{0x4124f5e3d8921ca5u, 0x789fa6a5135206f8u});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4976183a9e432b82u, 0x7fcd5a37d4911f0fu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x4976183a9e432b82u, 0x7fcd5a37d4911f0fu},
                                                ::pf::meta::ID{0x1d81d062cf8d0aa2u, 0x390f54d5a9fd22b4u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2c8f967112d5c5f2u, 0x4e12a7502dd008d3u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x2c8f967112d5c5f2u, 0x4e12a7502dd008d3u},
                                               ::pf::meta::ID{0x1d81d062cf8d0aa2u, 0x390f54d5a9fd22b4u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9b1f0e681ef0decbu, 0x8fa25137a3bf4215u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x9b1f0e681ef0decbu, 0x8fa25137a3bf4215u},
                                               ::pf::meta::ID{0x1d81d062cf8d0aa2u, 0x390f54d5a9fd22b4u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x78e005e18b912a3au, 0xa4932971efa493bbu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x78e005e18b912a3au, 0xa4932971efa493bbu},
                                               ::pf::meta::ID{0x4976183a9e432b82u, 0x7fcd5a37d4911f0fu}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x787ecb62b1ef144du, 0x17b96f237e998d9bu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x787ecb62b1ef144du, 0x17b96f237e998d9bu},
                                              ::pf::meta::ID{0x1d81d062cf8d0aa2u, 0x390f54d5a9fd22b4u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd42cb9cda4253cc6u, 0x327f57e656815fbdu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xd42cb9cda4253cc6u, 0x327f57e656815fbdu},
                                              ::pf::meta::ID{0x4976183a9e432b82u, 0x7fcd5a37d4911f0fu}> {};

/****************************** pf::E1 END ******************************/
namespace pf::meta::details {
/****************************** pf::E1 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E1>() {
  return ::pf::meta::ID{0x1d81d062cf8d0aa2u, 0x390f54d5a9fd22b4u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E1>() {
  return ::pf::meta::ID{0x4976183a9e432b82u, 0x7fcd5a37d4911f0fu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E1 &>() {
  return ::pf::meta::ID{0x2c8f967112d5c5f2u, 0x4e12a7502dd008d3u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E1 &&>() {
  return ::pf::meta::ID{0x9b1f0e681ef0decbu, 0x8fa25137a3bf4215u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E1 &>() {
  return ::pf::meta::ID{0x78e005e18b912a3au, 0xa4932971efa493bbu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E1 *>() {
  return ::pf::meta::ID{0x787ecb62b1ef144du, 0x17b96f237e998d9bu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E1 *>() {
  return ::pf::meta::ID{0xd42cb9cda4253cc6u, 0x327f57e656815fbdu};
}
/****************************** pf::E1 END ******************************/

/****************************** pf::E1::pf::E1::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E1::A>() {
  return ::pf::meta::ID{0xe359498b10031608u, 0x25908ab251b7757cu};
}
/****************************** pf::E1::pf::E1::A END ******************************/

/****************************** pf::E1::pf::E1::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E1::B>() {
  return ::pf::meta::ID{0x9384adfa7143e343u, 0x79465c0c96fa3642u};
}
/****************************** pf::E1::pf::E1::B END ******************************/

/****************************** pf::E1::pf::E1::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E1::C>() {
  return ::pf::meta::ID{0xf67059a01d62f68fu, 0x6d4353dac47e35deu};
}
/****************************** pf::E1::pf::E1::C END ******************************/

/****************************** pf::E1::pf::E1::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E1::D>() {
  return ::pf::meta::ID{0x902650e1a5bd478bu, 0x9da798ff2be51d63u};
}
/****************************** pf::E1::pf::E1::D END ******************************/

/****************************** pf::E1::pf::E1::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E1::E>() {
  return ::pf::meta::ID{0x4124f5e3d8921ca5u, 0x789fa6a5135206f8u};
}
/****************************** pf::E1::pf::E1::E END ******************************/
} // namespace pf::meta::details
/****************************** pf::E2::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xbe285762d49d2b5du, 0x7e36a4bd2b95aa6u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xbe285762d49d2b5du, 0x7e36a4bd2b95aa6u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe57b098c9b2a860bu, 0xf843dbfe4a88ffb3u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdd3e5bc96213be59u, 0xa43a43a7a1c17045u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xdd3e5bc96213be59u, 0xa43a43a7a1c17045u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe57b098c9b2a860bu, 0xf843dbfe4a88ffb3u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x63f606d515616e3fu, 0x6e22d88ac578d4afu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x63f606d515616e3fu, 0x6e22d88ac578d4afu};
  constexpr static ID TypeID = ::pf::meta::ID{0xe57b098c9b2a860bu, 0xf843dbfe4a88ffb3u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x268fffa9874c8aafu, 0x892c4b7871958e9cu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x268fffa9874c8aafu, 0x892c4b7871958e9cu};
  constexpr static ID TypeID = ::pf::meta::ID{0xe57b098c9b2a860bu, 0xf843dbfe4a88ffb3u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa28b87327f39e8beu, 0x2bafd6228f41c06u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xa28b87327f39e8beu, 0x2bafd6228f41c06u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe57b098c9b2a860bu, 0xf843dbfe4a88ffb3u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe57b098c9b2a860bu, 0xf843dbfe4a88ffb3u}> {
  struct details {};
  using Type = pf::E2;
  constexpr static ID TypeID = ::pf::meta::ID{0xe57b098c9b2a860bu, 0xf843dbfe4a88ffb3u};

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
      ::pf::meta::ID{0xbe285762d49d2b5du, 0x7e36a4bd2b95aa6u}, ::pf::meta::ID{0xdd3e5bc96213be59u, 0xa43a43a7a1c17045u},
      ::pf::meta::ID{0x63f606d515616e3fu, 0x6e22d88ac578d4afu},
      ::pf::meta::ID{0x268fffa9874c8aafu, 0x892c4b7871958e9cu},
      ::pf::meta::ID{0xa28b87327f39e8beu, 0x2bafd6228f41c06u});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7ab688809a138a80u, 0xfd8f02f85fce864fu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x7ab688809a138a80u, 0xfd8f02f85fce864fu},
                                                ::pf::meta::ID{0xe57b098c9b2a860bu, 0xf843dbfe4a88ffb3u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x5ca7bc319691040bu, 0x3327af0ba68fff2bu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x5ca7bc319691040bu, 0x3327af0ba68fff2bu},
                                               ::pf::meta::ID{0xe57b098c9b2a860bu, 0xf843dbfe4a88ffb3u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa1751a6a563f77cdu, 0xd08c2450d7485ab8u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xa1751a6a563f77cdu, 0xd08c2450d7485ab8u},
                                               ::pf::meta::ID{0xe57b098c9b2a860bu, 0xf843dbfe4a88ffb3u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb259c8f07ef16facu, 0x6c711b31b85d8e60u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xb259c8f07ef16facu, 0x6c711b31b85d8e60u},
                                               ::pf::meta::ID{0x7ab688809a138a80u, 0xfd8f02f85fce864fu}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x41bc8afe8e006fcbu, 0xb08df3b9be18d784u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x41bc8afe8e006fcbu, 0xb08df3b9be18d784u},
                                              ::pf::meta::ID{0xe57b098c9b2a860bu, 0xf843dbfe4a88ffb3u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x61337db3ac0cc411u, 0x4b531816d614bc7bu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x61337db3ac0cc411u, 0x4b531816d614bc7bu},
                                              ::pf::meta::ID{0x7ab688809a138a80u, 0xfd8f02f85fce864fu}> {};

/****************************** pf::E2 END ******************************/
namespace pf::meta::details {
/****************************** pf::E2 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E2>() {
  return ::pf::meta::ID{0xe57b098c9b2a860bu, 0xf843dbfe4a88ffb3u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E2>() {
  return ::pf::meta::ID{0x7ab688809a138a80u, 0xfd8f02f85fce864fu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E2 &>() {
  return ::pf::meta::ID{0x5ca7bc319691040bu, 0x3327af0ba68fff2bu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E2 &&>() {
  return ::pf::meta::ID{0xa1751a6a563f77cdu, 0xd08c2450d7485ab8u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E2 &>() {
  return ::pf::meta::ID{0xb259c8f07ef16facu, 0x6c711b31b85d8e60u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E2 *>() {
  return ::pf::meta::ID{0x41bc8afe8e006fcbu, 0xb08df3b9be18d784u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E2 *>() {
  return ::pf::meta::ID{0x61337db3ac0cc411u, 0x4b531816d614bc7bu};
}
/****************************** pf::E2 END ******************************/

/****************************** pf::E2::pf::E2::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E2::A>() {
  return ::pf::meta::ID{0xbe285762d49d2b5du, 0x7e36a4bd2b95aa6u};
}
/****************************** pf::E2::pf::E2::A END ******************************/

/****************************** pf::E2::pf::E2::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E2::B>() {
  return ::pf::meta::ID{0xdd3e5bc96213be59u, 0xa43a43a7a1c17045u};
}
/****************************** pf::E2::pf::E2::B END ******************************/

/****************************** pf::E2::pf::E2::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E2::C>() {
  return ::pf::meta::ID{0x63f606d515616e3fu, 0x6e22d88ac578d4afu};
}
/****************************** pf::E2::pf::E2::C END ******************************/

/****************************** pf::E2::pf::E2::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E2::D>() {
  return ::pf::meta::ID{0x268fffa9874c8aafu, 0x892c4b7871958e9cu};
}
/****************************** pf::E2::pf::E2::D END ******************************/

/****************************** pf::E2::pf::E2::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E2::E>() {
  return ::pf::meta::ID{0xa28b87327f39e8beu, 0x2bafd6228f41c06u};
}
/****************************** pf::E2::pf::E2::E END ******************************/
} // namespace pf::meta::details
/****************************** pf::E3::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x42652544ba1fd43du, 0xed177c88dfc5516cu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x42652544ba1fd43du, 0xed177c88dfc5516cu};
  constexpr static ID TypeID = ::pf::meta::ID{0xefb7c9e06e8056fbu, 0x6d4be73f7962c247u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa8229a8508753f5u, 0xcbad5afacdeb01c2u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xa8229a8508753f5u, 0xcbad5afacdeb01c2u};
  constexpr static ID TypeID = ::pf::meta::ID{0xefb7c9e06e8056fbu, 0x6d4be73f7962c247u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x37261602e4d5537bu, 0xf76700e449826c0bu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x37261602e4d5537bu, 0xf76700e449826c0bu};
  constexpr static ID TypeID = ::pf::meta::ID{0xefb7c9e06e8056fbu, 0x6d4be73f7962c247u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x240e5fea07718845u, 0x56179f0878a68c18u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x240e5fea07718845u, 0x56179f0878a68c18u};
  constexpr static ID TypeID = ::pf::meta::ID{0xefb7c9e06e8056fbu, 0x6d4be73f7962c247u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x124e96c4ce19b79du, 0x6e333116dfeda2a7u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x124e96c4ce19b79du, 0x6e333116dfeda2a7u};
  constexpr static ID TypeID = ::pf::meta::ID{0xefb7c9e06e8056fbu, 0x6d4be73f7962c247u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xefb7c9e06e8056fbu, 0x6d4be73f7962c247u}> {
  struct details {};
  using Type = pf::E3;
  constexpr static ID TypeID = ::pf::meta::ID{0xefb7c9e06e8056fbu, 0x6d4be73f7962c247u};

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
      ::pf::meta::ID{0x42652544ba1fd43du, 0xed177c88dfc5516cu}, ::pf::meta::ID{0xa8229a8508753f5u, 0xcbad5afacdeb01c2u},
      ::pf::meta::ID{0x37261602e4d5537bu, 0xf76700e449826c0bu},
      ::pf::meta::ID{0x240e5fea07718845u, 0x56179f0878a68c18u},
      ::pf::meta::ID{0x124e96c4ce19b79du, 0x6e333116dfeda2a7u});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xcb0b5dbe8c70c563u, 0x49e3e0c1d27d8540u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xcb0b5dbe8c70c563u, 0x49e3e0c1d27d8540u},
                                                ::pf::meta::ID{0xefb7c9e06e8056fbu, 0x6d4be73f7962c247u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x5a514cff4f22fdd1u, 0xf0af576424d5c3edu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x5a514cff4f22fdd1u, 0xf0af576424d5c3edu},
                                               ::pf::meta::ID{0xefb7c9e06e8056fbu, 0x6d4be73f7962c247u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe1a3e3fc76d9a3ebu, 0x5fc59ef2623660du}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xe1a3e3fc76d9a3ebu, 0x5fc59ef2623660du},
                                               ::pf::meta::ID{0xefb7c9e06e8056fbu, 0x6d4be73f7962c247u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x41cfd6e7d5b970f0u, 0xe1657a20c8a46435u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x41cfd6e7d5b970f0u, 0xe1657a20c8a46435u},
                                               ::pf::meta::ID{0xcb0b5dbe8c70c563u, 0x49e3e0c1d27d8540u}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x77f17316eb34159du, 0x89b8203c41999917u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x77f17316eb34159du, 0x89b8203c41999917u},
                                              ::pf::meta::ID{0xefb7c9e06e8056fbu, 0x6d4be73f7962c247u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xacca19b86722bc49u, 0x9a5ded9302ef2df5u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xacca19b86722bc49u, 0x9a5ded9302ef2df5u},
                                              ::pf::meta::ID{0xcb0b5dbe8c70c563u, 0x49e3e0c1d27d8540u}> {};

/****************************** pf::E3 END ******************************/
namespace pf::meta::details {
/****************************** pf::E3 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E3>() {
  return ::pf::meta::ID{0xefb7c9e06e8056fbu, 0x6d4be73f7962c247u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E3>() {
  return ::pf::meta::ID{0xcb0b5dbe8c70c563u, 0x49e3e0c1d27d8540u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E3 &>() {
  return ::pf::meta::ID{0x5a514cff4f22fdd1u, 0xf0af576424d5c3edu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E3 &&>() {
  return ::pf::meta::ID{0xe1a3e3fc76d9a3ebu, 0x5fc59ef2623660du};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E3 &>() {
  return ::pf::meta::ID{0x41cfd6e7d5b970f0u, 0xe1657a20c8a46435u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E3 *>() {
  return ::pf::meta::ID{0x77f17316eb34159du, 0x89b8203c41999917u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E3 *>() {
  return ::pf::meta::ID{0xacca19b86722bc49u, 0x9a5ded9302ef2df5u};
}
/****************************** pf::E3 END ******************************/

/****************************** pf::E3::pf::E3::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E3::A>() {
  return ::pf::meta::ID{0x42652544ba1fd43du, 0xed177c88dfc5516cu};
}
/****************************** pf::E3::pf::E3::A END ******************************/

/****************************** pf::E3::pf::E3::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E3::B>() {
  return ::pf::meta::ID{0xa8229a8508753f5u, 0xcbad5afacdeb01c2u};
}
/****************************** pf::E3::pf::E3::B END ******************************/

/****************************** pf::E3::pf::E3::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E3::C>() {
  return ::pf::meta::ID{0x37261602e4d5537bu, 0xf76700e449826c0bu};
}
/****************************** pf::E3::pf::E3::C END ******************************/

/****************************** pf::E3::pf::E3::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E3::D>() {
  return ::pf::meta::ID{0x240e5fea07718845u, 0x56179f0878a68c18u};
}
/****************************** pf::E3::pf::E3::D END ******************************/

/****************************** pf::E3::pf::E3::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E3::E>() {
  return ::pf::meta::ID{0x124e96c4ce19b79du, 0x6e333116dfeda2a7u};
}
/****************************** pf::E3::pf::E3::E END ******************************/
} // namespace pf::meta::details
/****************************** pf::E4::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x5718f8cd8bc18546u, 0x8c5af8ccf44cd5f7u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x5718f8cd8bc18546u, 0x8c5af8ccf44cd5f7u};
  constexpr static ID TypeID = ::pf::meta::ID{0x986b1aef26dd2f09u, 0x695928e3143b20e4u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2fd82271aea7967u, 0xe5a9589dc25dc94au}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x2fd82271aea7967u, 0xe5a9589dc25dc94au};
  constexpr static ID TypeID = ::pf::meta::ID{0x986b1aef26dd2f09u, 0x695928e3143b20e4u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdeec9e3420ae0829u, 0xf2561de4375798d0u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xdeec9e3420ae0829u, 0xf2561de4375798d0u};
  constexpr static ID TypeID = ::pf::meta::ID{0x986b1aef26dd2f09u, 0x695928e3143b20e4u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x55b263a7f8096733u, 0x697025127de750d7u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x55b263a7f8096733u, 0x697025127de750d7u};
  constexpr static ID TypeID = ::pf::meta::ID{0x986b1aef26dd2f09u, 0x695928e3143b20e4u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1f25fa6a8118dffeu, 0xc6ab6c848fc47ce2u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x1f25fa6a8118dffeu, 0xc6ab6c848fc47ce2u};
  constexpr static ID TypeID = ::pf::meta::ID{0x986b1aef26dd2f09u, 0x695928e3143b20e4u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x986b1aef26dd2f09u, 0x695928e3143b20e4u}> {
  struct details {};
  using Type = pf::E4;
  constexpr static ID TypeID = ::pf::meta::ID{0x986b1aef26dd2f09u, 0x695928e3143b20e4u};

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
      ::pf::meta::ID{0x5718f8cd8bc18546u, 0x8c5af8ccf44cd5f7u}, ::pf::meta::ID{0x2fd82271aea7967u, 0xe5a9589dc25dc94au},
      ::pf::meta::ID{0xdeec9e3420ae0829u, 0xf2561de4375798d0u},
      ::pf::meta::ID{0x55b263a7f8096733u, 0x697025127de750d7u},
      ::pf::meta::ID{0x1f25fa6a8118dffeu, 0xc6ab6c848fc47ce2u});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc5c00ac9bd6fe6bfu, 0xf01ea3de7a7d66e5u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xc5c00ac9bd6fe6bfu, 0xf01ea3de7a7d66e5u},
                                                ::pf::meta::ID{0x986b1aef26dd2f09u, 0x695928e3143b20e4u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe079c110e7b53022u, 0x289c8157d38bf328u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xe079c110e7b53022u, 0x289c8157d38bf328u},
                                               ::pf::meta::ID{0x986b1aef26dd2f09u, 0x695928e3143b20e4u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf624a68dc0aa5285u, 0x8fb870854f2659f5u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xf624a68dc0aa5285u, 0x8fb870854f2659f5u},
                                               ::pf::meta::ID{0x986b1aef26dd2f09u, 0x695928e3143b20e4u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf9294fef34f058c1u, 0x8048b9407bb92d22u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xf9294fef34f058c1u, 0x8048b9407bb92d22u},
                                               ::pf::meta::ID{0xc5c00ac9bd6fe6bfu, 0xf01ea3de7a7d66e5u}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xbd3efd553f030379u, 0xf2d522bad6b7b550u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xbd3efd553f030379u, 0xf2d522bad6b7b550u},
                                              ::pf::meta::ID{0x986b1aef26dd2f09u, 0x695928e3143b20e4u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x29b221788c2821d5u, 0x3acb4ed1798feb16u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x29b221788c2821d5u, 0x3acb4ed1798feb16u},
                                              ::pf::meta::ID{0xc5c00ac9bd6fe6bfu, 0xf01ea3de7a7d66e5u}> {};

/****************************** pf::E4 END ******************************/
namespace pf::meta::details {
/****************************** pf::E4 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E4>() {
  return ::pf::meta::ID{0x986b1aef26dd2f09u, 0x695928e3143b20e4u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E4>() {
  return ::pf::meta::ID{0xc5c00ac9bd6fe6bfu, 0xf01ea3de7a7d66e5u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E4 &>() {
  return ::pf::meta::ID{0xe079c110e7b53022u, 0x289c8157d38bf328u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E4 &&>() {
  return ::pf::meta::ID{0xf624a68dc0aa5285u, 0x8fb870854f2659f5u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E4 &>() {
  return ::pf::meta::ID{0xf9294fef34f058c1u, 0x8048b9407bb92d22u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E4 *>() {
  return ::pf::meta::ID{0xbd3efd553f030379u, 0xf2d522bad6b7b550u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E4 *>() {
  return ::pf::meta::ID{0x29b221788c2821d5u, 0x3acb4ed1798feb16u};
}
/****************************** pf::E4 END ******************************/

/****************************** pf::E4::pf::E4::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E4::A>() {
  return ::pf::meta::ID{0x5718f8cd8bc18546u, 0x8c5af8ccf44cd5f7u};
}
/****************************** pf::E4::pf::E4::A END ******************************/

/****************************** pf::E4::pf::E4::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E4::B>() {
  return ::pf::meta::ID{0x2fd82271aea7967u, 0xe5a9589dc25dc94au};
}
/****************************** pf::E4::pf::E4::B END ******************************/

/****************************** pf::E4::pf::E4::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E4::C>() {
  return ::pf::meta::ID{0xdeec9e3420ae0829u, 0xf2561de4375798d0u};
}
/****************************** pf::E4::pf::E4::C END ******************************/

/****************************** pf::E4::pf::E4::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E4::D>() {
  return ::pf::meta::ID{0x55b263a7f8096733u, 0x697025127de750d7u};
}
/****************************** pf::E4::pf::E4::D END ******************************/

/****************************** pf::E4::pf::E4::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E4::E>() {
  return ::pf::meta::ID{0x1f25fa6a8118dffeu, 0xc6ab6c848fc47ce2u};
}
/****************************** pf::E4::pf::E4::E END ******************************/
} // namespace pf::meta::details
/****************************** pf::E5::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xec205fe466cae744u, 0x61a5a110c6c20676u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xec205fe466cae744u, 0x61a5a110c6c20676u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe8884b2637200066u, 0xaed9783a1c795e9au};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x64381ef403f0fb29u, 0xe52db4120cbc8a71u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x64381ef403f0fb29u, 0xe52db4120cbc8a71u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe8884b2637200066u, 0xaed9783a1c795e9au};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4ca44bc62e7896b2u, 0xb431e6edbcddca05u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x4ca44bc62e7896b2u, 0xb431e6edbcddca05u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe8884b2637200066u, 0xaed9783a1c795e9au};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4515010db4b2c2aau, 0xf065480c43b85614u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x4515010db4b2c2aau, 0xf065480c43b85614u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe8884b2637200066u, 0xaed9783a1c795e9au};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7d9356222bb85ee8u, 0x62e5aaa059a167fbu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x7d9356222bb85ee8u, 0x62e5aaa059a167fbu};
  constexpr static ID TypeID = ::pf::meta::ID{0xe8884b2637200066u, 0xaed9783a1c795e9au};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe8884b2637200066u, 0xaed9783a1c795e9au}> {
  struct details {};
  using Type = pf::E5;
  constexpr static ID TypeID = ::pf::meta::ID{0xe8884b2637200066u, 0xaed9783a1c795e9au};

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues =
      pf::make_array<pf::meta::Info>(::pf::meta::ID{0xec205fe466cae744u, 0x61a5a110c6c20676u},
                                     ::pf::meta::ID{0x64381ef403f0fb29u, 0xe52db4120cbc8a71u},
                                     ::pf::meta::ID{0x4ca44bc62e7896b2u, 0xb431e6edbcddca05u},
                                     ::pf::meta::ID{0x4515010db4b2c2aau, 0xf065480c43b85614u},
                                     ::pf::meta::ID{0x7d9356222bb85ee8u, 0x62e5aaa059a167fbu});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc9a7d920e3f69be9u, 0x9a818e501041663bu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xc9a7d920e3f69be9u, 0x9a818e501041663bu},
                                                ::pf::meta::ID{0xe8884b2637200066u, 0xaed9783a1c795e9au}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x909d7ab40e7c6786u, 0xfd90d82b47bcb0ddu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x909d7ab40e7c6786u, 0xfd90d82b47bcb0ddu},
                                               ::pf::meta::ID{0xe8884b2637200066u, 0xaed9783a1c795e9au}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd308ed95768e209cu, 0x13c3a8f1203261fdu}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xd308ed95768e209cu, 0x13c3a8f1203261fdu},
                                               ::pf::meta::ID{0xe8884b2637200066u, 0xaed9783a1c795e9au}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x41153e36df235cbfu, 0xcff8a779076f384eu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x41153e36df235cbfu, 0xcff8a779076f384eu},
                                               ::pf::meta::ID{0xc9a7d920e3f69be9u, 0x9a818e501041663bu}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x97666dfc993eaa05u, 0x3d7cd8d545947bd7u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x97666dfc993eaa05u, 0x3d7cd8d545947bd7u},
                                              ::pf::meta::ID{0xe8884b2637200066u, 0xaed9783a1c795e9au}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x23e425948e91e13fu, 0x9d8f1efbe14c1da6u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x23e425948e91e13fu, 0x9d8f1efbe14c1da6u},
                                              ::pf::meta::ID{0xc9a7d920e3f69be9u, 0x9a818e501041663bu}> {};

/****************************** pf::E5 END ******************************/
namespace pf::meta::details {
/****************************** pf::E5 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E5>() {
  return ::pf::meta::ID{0xe8884b2637200066u, 0xaed9783a1c795e9au};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E5>() {
  return ::pf::meta::ID{0xc9a7d920e3f69be9u, 0x9a818e501041663bu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E5 &>() {
  return ::pf::meta::ID{0x909d7ab40e7c6786u, 0xfd90d82b47bcb0ddu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E5 &&>() {
  return ::pf::meta::ID{0xd308ed95768e209cu, 0x13c3a8f1203261fdu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E5 &>() {
  return ::pf::meta::ID{0x41153e36df235cbfu, 0xcff8a779076f384eu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E5 *>() {
  return ::pf::meta::ID{0x97666dfc993eaa05u, 0x3d7cd8d545947bd7u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E5 *>() {
  return ::pf::meta::ID{0x23e425948e91e13fu, 0x9d8f1efbe14c1da6u};
}
/****************************** pf::E5 END ******************************/

/****************************** pf::E5::pf::E5::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E5::A>() {
  return ::pf::meta::ID{0xec205fe466cae744u, 0x61a5a110c6c20676u};
}
/****************************** pf::E5::pf::E5::A END ******************************/

/****************************** pf::E5::pf::E5::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E5::B>() {
  return ::pf::meta::ID{0x64381ef403f0fb29u, 0xe52db4120cbc8a71u};
}
/****************************** pf::E5::pf::E5::B END ******************************/

/****************************** pf::E5::pf::E5::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E5::C>() {
  return ::pf::meta::ID{0x4ca44bc62e7896b2u, 0xb431e6edbcddca05u};
}
/****************************** pf::E5::pf::E5::C END ******************************/

/****************************** pf::E5::pf::E5::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E5::D>() {
  return ::pf::meta::ID{0x4515010db4b2c2aau, 0xf065480c43b85614u};
}
/****************************** pf::E5::pf::E5::D END ******************************/

/****************************** pf::E5::pf::E5::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E5::E>() {
  return ::pf::meta::ID{0x7d9356222bb85ee8u, 0x62e5aaa059a167fbu};
}
/****************************** pf::E5::pf::E5::E END ******************************/
} // namespace pf::meta::details
/****************************** pf::E6::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xfd8bff2531273e18u, 0xa7d09e32bc7fbda9u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xfd8bff2531273e18u, 0xa7d09e32bc7fbda9u};
  constexpr static ID TypeID = ::pf::meta::ID{0x10f3182ae766398eu, 0xbd229b4a45267a90u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x86eb3bf9564efad9u, 0x705183cf9e76e4cdu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x86eb3bf9564efad9u, 0x705183cf9e76e4cdu};
  constexpr static ID TypeID = ::pf::meta::ID{0x10f3182ae766398eu, 0xbd229b4a45267a90u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x79e5feb022a46805u, 0xd723f71d27f3d4ffu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x79e5feb022a46805u, 0xd723f71d27f3d4ffu};
  constexpr static ID TypeID = ::pf::meta::ID{0x10f3182ae766398eu, 0xbd229b4a45267a90u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xbdcd2f78de1d1888u, 0x866780394eb67a1du}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xbdcd2f78de1d1888u, 0x866780394eb67a1du};
  constexpr static ID TypeID = ::pf::meta::ID{0x10f3182ae766398eu, 0xbd229b4a45267a90u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf491a6d348948e0cu, 0x613c5903873da141u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xf491a6d348948e0cu, 0x613c5903873da141u};
  constexpr static ID TypeID = ::pf::meta::ID{0x10f3182ae766398eu, 0xbd229b4a45267a90u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x10f3182ae766398eu, 0xbd229b4a45267a90u}> {
  struct details {};
  using Type = pf::E6;
  constexpr static ID TypeID = ::pf::meta::ID{0x10f3182ae766398eu, 0xbd229b4a45267a90u};

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues =
      pf::make_array<pf::meta::Info>(::pf::meta::ID{0xfd8bff2531273e18u, 0xa7d09e32bc7fbda9u},
                                     ::pf::meta::ID{0x86eb3bf9564efad9u, 0x705183cf9e76e4cdu},
                                     ::pf::meta::ID{0x79e5feb022a46805u, 0xd723f71d27f3d4ffu},
                                     ::pf::meta::ID{0xbdcd2f78de1d1888u, 0x866780394eb67a1du},
                                     ::pf::meta::ID{0xf491a6d348948e0cu, 0x613c5903873da141u});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9d16864456ee4e47u, 0x490cc6261e180809u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x9d16864456ee4e47u, 0x490cc6261e180809u},
                                                ::pf::meta::ID{0x10f3182ae766398eu, 0xbd229b4a45267a90u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x59bce849420b2f0du, 0xfd67e4f369b22b75u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x59bce849420b2f0du, 0xfd67e4f369b22b75u},
                                               ::pf::meta::ID{0x10f3182ae766398eu, 0xbd229b4a45267a90u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa7b4e977ac2d675du, 0x1d99734b8e3ec10eu}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xa7b4e977ac2d675du, 0x1d99734b8e3ec10eu},
                                               ::pf::meta::ID{0x10f3182ae766398eu, 0xbd229b4a45267a90u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe6b06028178d5b09u, 0xec697f84989e2b7cu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xe6b06028178d5b09u, 0xec697f84989e2b7cu},
                                               ::pf::meta::ID{0x9d16864456ee4e47u, 0x490cc6261e180809u}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb016ba3fa00a1cc6u, 0xef1d31e42d684a07u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xb016ba3fa00a1cc6u, 0xef1d31e42d684a07u},
                                              ::pf::meta::ID{0x10f3182ae766398eu, 0xbd229b4a45267a90u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xae437fa61943c1f5u, 0x9c3cca9d0416b0d9u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xae437fa61943c1f5u, 0x9c3cca9d0416b0d9u},
                                              ::pf::meta::ID{0x9d16864456ee4e47u, 0x490cc6261e180809u}> {};

/****************************** pf::E6 END ******************************/
namespace pf::meta::details {
/****************************** pf::E6 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E6>() {
  return ::pf::meta::ID{0x10f3182ae766398eu, 0xbd229b4a45267a90u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E6>() {
  return ::pf::meta::ID{0x9d16864456ee4e47u, 0x490cc6261e180809u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E6 &>() {
  return ::pf::meta::ID{0x59bce849420b2f0du, 0xfd67e4f369b22b75u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E6 &&>() {
  return ::pf::meta::ID{0xa7b4e977ac2d675du, 0x1d99734b8e3ec10eu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E6 &>() {
  return ::pf::meta::ID{0xe6b06028178d5b09u, 0xec697f84989e2b7cu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E6 *>() {
  return ::pf::meta::ID{0xb016ba3fa00a1cc6u, 0xef1d31e42d684a07u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E6 *>() {
  return ::pf::meta::ID{0xae437fa61943c1f5u, 0x9c3cca9d0416b0d9u};
}
/****************************** pf::E6 END ******************************/

/****************************** pf::E6::pf::E6::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E6::A>() {
  return ::pf::meta::ID{0xfd8bff2531273e18u, 0xa7d09e32bc7fbda9u};
}
/****************************** pf::E6::pf::E6::A END ******************************/

/****************************** pf::E6::pf::E6::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E6::B>() {
  return ::pf::meta::ID{0x86eb3bf9564efad9u, 0x705183cf9e76e4cdu};
}
/****************************** pf::E6::pf::E6::B END ******************************/

/****************************** pf::E6::pf::E6::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E6::C>() {
  return ::pf::meta::ID{0x79e5feb022a46805u, 0xd723f71d27f3d4ffu};
}
/****************************** pf::E6::pf::E6::C END ******************************/

/****************************** pf::E6::pf::E6::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E6::D>() {
  return ::pf::meta::ID{0xbdcd2f78de1d1888u, 0x866780394eb67a1du};
}
/****************************** pf::E6::pf::E6::D END ******************************/

/****************************** pf::E6::pf::E6::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E6::E>() {
  return ::pf::meta::ID{0xf491a6d348948e0cu, 0x613c5903873da141u};
}
/****************************** pf::E6::pf::E6::E END ******************************/
} // namespace pf::meta::details
/****************************** pf::E7::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf23c14daa6c2ca26u, 0xd34303eb8d894eebu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xf23c14daa6c2ca26u, 0xd34303eb8d894eebu};
  constexpr static ID TypeID = ::pf::meta::ID{0xf75d883e7e388150u, 0x6792f39301202c04u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2b2536f57c062239u, 0xb5f2c6c46fbb0770u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x2b2536f57c062239u, 0xb5f2c6c46fbb0770u};
  constexpr static ID TypeID = ::pf::meta::ID{0xf75d883e7e388150u, 0x6792f39301202c04u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xaf9f60019b8cea8cu, 0x9eb45a10a05c9245u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xaf9f60019b8cea8cu, 0x9eb45a10a05c9245u};
  constexpr static ID TypeID = ::pf::meta::ID{0xf75d883e7e388150u, 0x6792f39301202c04u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x97a25199b47b1ccau, 0xf9b7368ffcb3f683u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x97a25199b47b1ccau, 0xf9b7368ffcb3f683u};
  constexpr static ID TypeID = ::pf::meta::ID{0xf75d883e7e388150u, 0x6792f39301202c04u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1e2ad453f985a073u, 0xed08ad2a1f05a0cfu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x1e2ad453f985a073u, 0xed08ad2a1f05a0cfu};
  constexpr static ID TypeID = ::pf::meta::ID{0xf75d883e7e388150u, 0x6792f39301202c04u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf75d883e7e388150u, 0x6792f39301202c04u}> {
  struct details {};
  using Type = pf::E7;
  constexpr static ID TypeID = ::pf::meta::ID{0xf75d883e7e388150u, 0x6792f39301202c04u};

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues =
      pf::make_array<pf::meta::Info>(::pf::meta::ID{0xf23c14daa6c2ca26u, 0xd34303eb8d894eebu},
                                     ::pf::meta::ID{0x2b2536f57c062239u, 0xb5f2c6c46fbb0770u},
                                     ::pf::meta::ID{0xaf9f60019b8cea8cu, 0x9eb45a10a05c9245u},
                                     ::pf::meta::ID{0x97a25199b47b1ccau, 0xf9b7368ffcb3f683u},
                                     ::pf::meta::ID{0x1e2ad453f985a073u, 0xed08ad2a1f05a0cfu});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb690b72e2a2b8509u, 0x7b8adcd167c0d0dfu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xb690b72e2a2b8509u, 0x7b8adcd167c0d0dfu},
                                                ::pf::meta::ID{0xf75d883e7e388150u, 0x6792f39301202c04u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3296a79e35820a76u, 0x1667736a16a456e0u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x3296a79e35820a76u, 0x1667736a16a456e0u},
                                               ::pf::meta::ID{0xf75d883e7e388150u, 0x6792f39301202c04u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd41c7f12b3a4afbau, 0x16f75ac2dd39ddcfu}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xd41c7f12b3a4afbau, 0x16f75ac2dd39ddcfu},
                                               ::pf::meta::ID{0xf75d883e7e388150u, 0x6792f39301202c04u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4b4cf58ec0e5456bu, 0x12f78e0154255274u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x4b4cf58ec0e5456bu, 0x12f78e0154255274u},
                                               ::pf::meta::ID{0xb690b72e2a2b8509u, 0x7b8adcd167c0d0dfu}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8af97e54b99e5d88u, 0xcccbc33d58ac8c93u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x8af97e54b99e5d88u, 0xcccbc33d58ac8c93u},
                                              ::pf::meta::ID{0xf75d883e7e388150u, 0x6792f39301202c04u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdc49a46511822e2u, 0x888cf56df2756e10u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xdc49a46511822e2u, 0x888cf56df2756e10u},
                                              ::pf::meta::ID{0xb690b72e2a2b8509u, 0x7b8adcd167c0d0dfu}> {};

/****************************** pf::E7 END ******************************/
namespace pf::meta::details {
/****************************** pf::E7 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E7>() {
  return ::pf::meta::ID{0xf75d883e7e388150u, 0x6792f39301202c04u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E7>() {
  return ::pf::meta::ID{0xb690b72e2a2b8509u, 0x7b8adcd167c0d0dfu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E7 &>() {
  return ::pf::meta::ID{0x3296a79e35820a76u, 0x1667736a16a456e0u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E7 &&>() {
  return ::pf::meta::ID{0xd41c7f12b3a4afbau, 0x16f75ac2dd39ddcfu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E7 &>() {
  return ::pf::meta::ID{0x4b4cf58ec0e5456bu, 0x12f78e0154255274u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E7 *>() {
  return ::pf::meta::ID{0x8af97e54b99e5d88u, 0xcccbc33d58ac8c93u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E7 *>() {
  return ::pf::meta::ID{0xdc49a46511822e2u, 0x888cf56df2756e10u};
}
/****************************** pf::E7 END ******************************/

/****************************** pf::E7::pf::E7::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E7::A>() {
  return ::pf::meta::ID{0xf23c14daa6c2ca26u, 0xd34303eb8d894eebu};
}
/****************************** pf::E7::pf::E7::A END ******************************/

/****************************** pf::E7::pf::E7::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E7::B>() {
  return ::pf::meta::ID{0x2b2536f57c062239u, 0xb5f2c6c46fbb0770u};
}
/****************************** pf::E7::pf::E7::B END ******************************/

/****************************** pf::E7::pf::E7::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E7::C>() {
  return ::pf::meta::ID{0xaf9f60019b8cea8cu, 0x9eb45a10a05c9245u};
}
/****************************** pf::E7::pf::E7::C END ******************************/

/****************************** pf::E7::pf::E7::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E7::D>() {
  return ::pf::meta::ID{0x97a25199b47b1ccau, 0xf9b7368ffcb3f683u};
}
/****************************** pf::E7::pf::E7::D END ******************************/

/****************************** pf::E7::pf::E7::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E7::E>() {
  return ::pf::meta::ID{0x1e2ad453f985a073u, 0xed08ad2a1f05a0cfu};
}
/****************************** pf::E7::pf::E7::E END ******************************/
} // namespace pf::meta::details
/****************************** pf::E8::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe0f246d75be7b449u, 0x16b014ca4a811b87u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xe0f246d75be7b449u, 0x16b014ca4a811b87u};
  constexpr static ID TypeID = ::pf::meta::ID{0x9400ec47056c16a0u, 0x217e5c433c3a2370u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xfdd8ff5bd8a7a300u, 0x8457ee5d2713ba79u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xfdd8ff5bd8a7a300u, 0x8457ee5d2713ba79u};
  constexpr static ID TypeID = ::pf::meta::ID{0x9400ec47056c16a0u, 0x217e5c433c3a2370u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc216e50ba86ec983u, 0x7651fdd97791ace2u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xc216e50ba86ec983u, 0x7651fdd97791ace2u};
  constexpr static ID TypeID = ::pf::meta::ID{0x9400ec47056c16a0u, 0x217e5c433c3a2370u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd526665dceae234du, 0x43d3d1b88366036au}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xd526665dceae234du, 0x43d3d1b88366036au};
  constexpr static ID TypeID = ::pf::meta::ID{0x9400ec47056c16a0u, 0x217e5c433c3a2370u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1f1bda55ac945567u, 0x4a399df9a16e62cdu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x1f1bda55ac945567u, 0x4a399df9a16e62cdu};
  constexpr static ID TypeID = ::pf::meta::ID{0x9400ec47056c16a0u, 0x217e5c433c3a2370u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9400ec47056c16a0u, 0x217e5c433c3a2370u}> {
  struct details {};
  using Type = pf::E8;
  constexpr static ID TypeID = ::pf::meta::ID{0x9400ec47056c16a0u, 0x217e5c433c3a2370u};

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues =
      pf::make_array<pf::meta::Info>(::pf::meta::ID{0xe0f246d75be7b449u, 0x16b014ca4a811b87u},
                                     ::pf::meta::ID{0xfdd8ff5bd8a7a300u, 0x8457ee5d2713ba79u},
                                     ::pf::meta::ID{0xc216e50ba86ec983u, 0x7651fdd97791ace2u},
                                     ::pf::meta::ID{0xd526665dceae234du, 0x43d3d1b88366036au},
                                     ::pf::meta::ID{0x1f1bda55ac945567u, 0x4a399df9a16e62cdu});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1e000bb1a5dcd6a8u, 0x9f92def2f2c4ed18u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x1e000bb1a5dcd6a8u, 0x9f92def2f2c4ed18u},
                                                ::pf::meta::ID{0x9400ec47056c16a0u, 0x217e5c433c3a2370u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3b17242a9d2ae030u, 0x7ebca03e0ad2ae58u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x3b17242a9d2ae030u, 0x7ebca03e0ad2ae58u},
                                               ::pf::meta::ID{0x9400ec47056c16a0u, 0x217e5c433c3a2370u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xcd09faeadd4548c4u, 0x9ee418eb42f3c814u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xcd09faeadd4548c4u, 0x9ee418eb42f3c814u},
                                               ::pf::meta::ID{0x9400ec47056c16a0u, 0x217e5c433c3a2370u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xaa79f9a3b2cfbfdu, 0x89091deee2275c9u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xaa79f9a3b2cfbfdu, 0x89091deee2275c9u},
                                               ::pf::meta::ID{0x1e000bb1a5dcd6a8u, 0x9f92def2f2c4ed18u}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x10ee60d997d2eba4u, 0x4f80e262aeb08cefu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x10ee60d997d2eba4u, 0x4f80e262aeb08cefu},
                                              ::pf::meta::ID{0x9400ec47056c16a0u, 0x217e5c433c3a2370u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x96892e4d2ae2130eu, 0xc66cef2d961643f1u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x96892e4d2ae2130eu, 0xc66cef2d961643f1u},
                                              ::pf::meta::ID{0x1e000bb1a5dcd6a8u, 0x9f92def2f2c4ed18u}> {};

/****************************** pf::E8 END ******************************/
namespace pf::meta::details {
/****************************** pf::E8 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E8>() {
  return ::pf::meta::ID{0x9400ec47056c16a0u, 0x217e5c433c3a2370u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E8>() {
  return ::pf::meta::ID{0x1e000bb1a5dcd6a8u, 0x9f92def2f2c4ed18u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E8 &>() {
  return ::pf::meta::ID{0x3b17242a9d2ae030u, 0x7ebca03e0ad2ae58u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E8 &&>() {
  return ::pf::meta::ID{0xcd09faeadd4548c4u, 0x9ee418eb42f3c814u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E8 &>() {
  return ::pf::meta::ID{0xaa79f9a3b2cfbfdu, 0x89091deee2275c9u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E8 *>() {
  return ::pf::meta::ID{0x10ee60d997d2eba4u, 0x4f80e262aeb08cefu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E8 *>() {
  return ::pf::meta::ID{0x96892e4d2ae2130eu, 0xc66cef2d961643f1u};
}
/****************************** pf::E8 END ******************************/

/****************************** pf::E8::pf::E8::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E8::A>() {
  return ::pf::meta::ID{0xe0f246d75be7b449u, 0x16b014ca4a811b87u};
}
/****************************** pf::E8::pf::E8::A END ******************************/

/****************************** pf::E8::pf::E8::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E8::B>() {
  return ::pf::meta::ID{0xfdd8ff5bd8a7a300u, 0x8457ee5d2713ba79u};
}
/****************************** pf::E8::pf::E8::B END ******************************/

/****************************** pf::E8::pf::E8::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E8::C>() {
  return ::pf::meta::ID{0xc216e50ba86ec983u, 0x7651fdd97791ace2u};
}
/****************************** pf::E8::pf::E8::C END ******************************/

/****************************** pf::E8::pf::E8::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E8::D>() {
  return ::pf::meta::ID{0xd526665dceae234du, 0x43d3d1b88366036au};
}
/****************************** pf::E8::pf::E8::D END ******************************/

/****************************** pf::E8::pf::E8::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E8::E>() {
  return ::pf::meta::ID{0x1f1bda55ac945567u, 0x4a399df9a16e62cdu};
}
/****************************** pf::E8::pf::E8::E END ******************************/
} // namespace pf::meta::details
/****************************** pf::E9::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2eaf8927b5b4b836u, 0x1413482d21c48444u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x2eaf8927b5b4b836u, 0x1413482d21c48444u};
  constexpr static ID TypeID = ::pf::meta::ID{0xba4510029b5d273u, 0xebc5cebeda217021u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6f6da54326ca0b1au, 0x7b0ff8ae76c5d41bu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x6f6da54326ca0b1au, 0x7b0ff8ae76c5d41bu};
  constexpr static ID TypeID = ::pf::meta::ID{0xba4510029b5d273u, 0xebc5cebeda217021u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6eb93863da1dfe98u, 0x67e79ecca1b4a76bu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x6eb93863da1dfe98u, 0x67e79ecca1b4a76bu};
  constexpr static ID TypeID = ::pf::meta::ID{0xba4510029b5d273u, 0xebc5cebeda217021u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc3a4207fdad94bbu, 0xe1166fc46bdbda42u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xc3a4207fdad94bbu, 0xe1166fc46bdbda42u};
  constexpr static ID TypeID = ::pf::meta::ID{0xba4510029b5d273u, 0xebc5cebeda217021u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x18fdccbcc4b4e753u, 0x3c428dcf6b3cda4eu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x18fdccbcc4b4e753u, 0x3c428dcf6b3cda4eu};
  constexpr static ID TypeID = ::pf::meta::ID{0xba4510029b5d273u, 0xebc5cebeda217021u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xba4510029b5d273u, 0xebc5cebeda217021u}> {
  struct details {};
  using Type = pf::E9;
  constexpr static ID TypeID = ::pf::meta::ID{0xba4510029b5d273u, 0xebc5cebeda217021u};

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
      ::pf::meta::ID{0x2eaf8927b5b4b836u, 0x1413482d21c48444u},
      ::pf::meta::ID{0x6f6da54326ca0b1au, 0x7b0ff8ae76c5d41bu},
      ::pf::meta::ID{0x6eb93863da1dfe98u, 0x67e79ecca1b4a76bu}, ::pf::meta::ID{0xc3a4207fdad94bbu, 0xe1166fc46bdbda42u},
      ::pf::meta::ID{0x18fdccbcc4b4e753u, 0x3c428dcf6b3cda4eu});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7249d641ff3dadbcu, 0xddaa765fa02faf82u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x7249d641ff3dadbcu, 0xddaa765fa02faf82u},
                                                ::pf::meta::ID{0xba4510029b5d273u, 0xebc5cebeda217021u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd4ca27b4f7988123u, 0xcf7096a1a63a4c58u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xd4ca27b4f7988123u, 0xcf7096a1a63a4c58u},
                                               ::pf::meta::ID{0xba4510029b5d273u, 0xebc5cebeda217021u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc2cffb1d02d97ed8u, 0x8b8e0ffda59c7d59u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xc2cffb1d02d97ed8u, 0x8b8e0ffda59c7d59u},
                                               ::pf::meta::ID{0xba4510029b5d273u, 0xebc5cebeda217021u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf8544608dcbb5ef0u, 0xefa919563d1e7debu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xf8544608dcbb5ef0u, 0xefa919563d1e7debu},
                                               ::pf::meta::ID{0x7249d641ff3dadbcu, 0xddaa765fa02faf82u}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7d808f95713c1112u, 0xeb2589e2d4aaf629u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x7d808f95713c1112u, 0xeb2589e2d4aaf629u},
                                              ::pf::meta::ID{0xba4510029b5d273u, 0xebc5cebeda217021u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xcf60395eaac2c67au, 0xe18060198d37caeeu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xcf60395eaac2c67au, 0xe18060198d37caeeu},
                                              ::pf::meta::ID{0x7249d641ff3dadbcu, 0xddaa765fa02faf82u}> {};

/****************************** pf::E9 END ******************************/
namespace pf::meta::details {
/****************************** pf::E9 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E9>() {
  return ::pf::meta::ID{0xba4510029b5d273u, 0xebc5cebeda217021u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E9>() {
  return ::pf::meta::ID{0x7249d641ff3dadbcu, 0xddaa765fa02faf82u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E9 &>() {
  return ::pf::meta::ID{0xd4ca27b4f7988123u, 0xcf7096a1a63a4c58u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E9 &&>() {
  return ::pf::meta::ID{0xc2cffb1d02d97ed8u, 0x8b8e0ffda59c7d59u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E9 &>() {
  return ::pf::meta::ID{0xf8544608dcbb5ef0u, 0xefa919563d1e7debu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E9 *>() {
  return ::pf::meta::ID{0x7d808f95713c1112u, 0xeb2589e2d4aaf629u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E9 *>() {
  return ::pf::meta::ID{0xcf60395eaac2c67au, 0xe18060198d37caeeu};
}
/****************************** pf::E9 END ******************************/

/****************************** pf::E9::pf::E9::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E9::A>() {
  return ::pf::meta::ID{0x2eaf8927b5b4b836u, 0x1413482d21c48444u};
}
/****************************** pf::E9::pf::E9::A END ******************************/

/****************************** pf::E9::pf::E9::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E9::B>() {
  return ::pf::meta::ID{0x6f6da54326ca0b1au, 0x7b0ff8ae76c5d41bu};
}
/****************************** pf::E9::pf::E9::B END ******************************/

/****************************** pf::E9::pf::E9::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E9::C>() {
  return ::pf::meta::ID{0x6eb93863da1dfe98u, 0x67e79ecca1b4a76bu};
}
/****************************** pf::E9::pf::E9::C END ******************************/

/****************************** pf::E9::pf::E9::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E9::D>() {
  return ::pf::meta::ID{0xc3a4207fdad94bbu, 0xe1166fc46bdbda42u};
}
/****************************** pf::E9::pf::E9::D END ******************************/

/****************************** pf::E9::pf::E9::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E9::E>() {
  return ::pf::meta::ID{0x18fdccbcc4b4e753u, 0x3c428dcf6b3cda4eu};
}
/****************************** pf::E9::pf::E9::E END ******************************/
} // namespace pf::meta::details
