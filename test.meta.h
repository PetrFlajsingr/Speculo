
#pragma once

#include "meta/common.h"
#include "test.h"
#include <pf_common/array.h>
#include <pf_common/concepts/ranges.h>
#include <type_traits>

/****************************** pf::SomeEnum::Value1 START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb065620ad626f322u, 0xf37ab3b06ac5301bu}> {
  struct details {
    constexpr static auto ArgArray_6772346369269018050 = pf::make_array<std::string_view>();
    constexpr static auto ArgArray_13400616631417924135 = pf::make_array<std::string_view>();
    constexpr static auto ArgArray_10480389512854834784 = pf::make_array<std::string_view>();
  };
  constexpr static ID ValueID = ::pf::meta::ID{0xb065620ad626f322u, 0xf37ab3b06ac5301bu};
  constexpr static ID TypeID = ::pf::meta::ID{0x8533ac155b795052u, 0x4f5d3dc3714063e6u};
  using Type = pf::SomeEnum;

  constexpr static std::uint64_t SourceLine = 5;
  constexpr static std::uint64_t SourceColumn = 5;

  constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(
      pf::meta::Attribute{"test", std::span<const std::string_view>{details::ArgArray_6772346369269018050}},
      pf::meta::Attribute{"test2", std::span<const std::string_view>{details::ArgArray_13400616631417924135}},
      pf::meta::Attribute{"test3", std::span<const std::string_view>{details::ArgArray_10480389512854834784}});

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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb61cf9a727378213u, 0xeb784de671a79eb3u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xb61cf9a727378213u, 0xeb784de671a79eb3u};
  constexpr static ID TypeID = ::pf::meta::ID{0x8533ac155b795052u, 0x4f5d3dc3714063e6u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8533ac155b795052u, 0x4f5d3dc3714063e6u}> {
  struct details {
    constexpr static auto ArgArray_4392463859511184832 = pf::make_array<std::string_view>(
        R"arg(()()()((())))arg", R"arg([[nodiscard]])arg", R"arg(1ll)arg", R"arg(1.011)arg", R"arg([]{}())arg",
        R"arg("yeet")arg", R"arg('a')arg", R"arg([][][]:::3214234...[][][][])arg");
    constexpr static auto ArgArray_13955115632152650718 = pf::make_array<std::string_view>();
    constexpr static auto ArgArray_18412787335921003142 =
        pf::make_array<std::string_view>(R"arg(1ll)arg", R"arg(1.011)arg", R"arg("yeet")arg");
    constexpr static auto ArgArray_15141754762989906299 = pf::make_array<std::string_view>();
  };
  using Type = pf::SomeEnum;
  constexpr static ID TypeID = ::pf::meta::ID{0x8533ac155b795052u, 0x4f5d3dc3714063e6u};

  constexpr static std::uint64_t SourceLine = 5;
  constexpr static std::uint64_t SourceColumn = 5;

  constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(
      pf::meta::Attribute{"pf::operators", std::span<const std::string_view>{details::ArgArray_4392463859511184832}},
      pf::meta::Attribute{"pf::hihi", std::span<const std::string_view>{details::ArgArray_13955115632152650718}},
      pf::meta::Attribute{"pf::operators2", std::span<const std::string_view>{details::ArgArray_18412787335921003142}},
      pf::meta::Attribute{"pf::hihi2", std::span<const std::string_view>{details::ArgArray_15141754762989906299}});

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
      pf::make_array<pf::meta::Info>(::pf::meta::ID{0xb065620ad626f322u, 0xf37ab3b06ac5301bu},
                                     ::pf::meta::ID{0xb61cf9a727378213u, 0xeb784de671a79eb3u});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2df6088f934658du, 0xa1542b9942d32d87u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x2df6088f934658du, 0xa1542b9942d32d87u},
                                                ::pf::meta::ID{0x8533ac155b795052u, 0x4f5d3dc3714063e6u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x19507df307a81613u, 0x29f2fbc9cd36d75du}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x19507df307a81613u, 0x29f2fbc9cd36d75du},
                                               ::pf::meta::ID{0x8533ac155b795052u, 0x4f5d3dc3714063e6u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb45ada50cf987430u, 0x5a65e52002319e98u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xb45ada50cf987430u, 0x5a65e52002319e98u},
                                               ::pf::meta::ID{0x8533ac155b795052u, 0x4f5d3dc3714063e6u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2a5f82ef8857830fu, 0xf57bd45038791ba4u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x2a5f82ef8857830fu, 0xf57bd45038791ba4u},
                                               ::pf::meta::ID{0x2df6088f934658du, 0xa1542b9942d32d87u}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6fdeb33b6a4b9738u, 0x7a7616f24e1b0cb1u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x6fdeb33b6a4b9738u, 0x7a7616f24e1b0cb1u},
                                              ::pf::meta::ID{0x8533ac155b795052u, 0x4f5d3dc3714063e6u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa06f8810b33f68f8u, 0x937f6ef4cc2adae3u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xa06f8810b33f68f8u, 0x937f6ef4cc2adae3u},
                                              ::pf::meta::ID{0x2df6088f934658du, 0xa1542b9942d32d87u}> {};

/****************************** pf::SomeEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::SomeEnum START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::SomeEnum>() {
  return ::pf::meta::ID{0x8533ac155b795052u, 0x4f5d3dc3714063e6u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum>() {
  return ::pf::meta::ID{0x2df6088f934658du, 0xa1542b9942d32d87u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::SomeEnum &>() {
  return ::pf::meta::ID{0x19507df307a81613u, 0x29f2fbc9cd36d75du};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::SomeEnum &&>() {
  return ::pf::meta::ID{0xb45ada50cf987430u, 0x5a65e52002319e98u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum &>() {
  return ::pf::meta::ID{0x2a5f82ef8857830fu, 0xf57bd45038791ba4u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::SomeEnum *>() {
  return ::pf::meta::ID{0x6fdeb33b6a4b9738u, 0x7a7616f24e1b0cb1u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum *>() {
  return ::pf::meta::ID{0xa06f8810b33f68f8u, 0x937f6ef4cc2adae3u};
}
/****************************** pf::SomeEnum END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value1 START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value1>() {
  return ::pf::meta::ID{0xb065620ad626f322u, 0xf37ab3b06ac5301bu};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value1 END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value2 START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value2>() {
  return ::pf::meta::ID{0xb61cf9a727378213u, 0xeb784de671a79eb3u};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value2 END ******************************/
} // namespace pf::meta::details
/****************************** pf::Test::E::Value1 START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x5947ee91880a7734u, 0x323aec5c4dbd0e75u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x5947ee91880a7734u, 0x323aec5c4dbd0e75u};
  constexpr static ID TypeID = ::pf::meta::ID{0x7e0b600ab1eda4feu, 0xae893c21ae5dd635u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x43e02b4cc000fb33u, 0x336878c33914e470u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x43e02b4cc000fb33u, 0x336878c33914e470u};
  constexpr static ID TypeID = ::pf::meta::ID{0x7e0b600ab1eda4feu, 0xae893c21ae5dd635u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7e0b600ab1eda4feu, 0xae893c21ae5dd635u}> {
  struct details {};
  using Type = pf::Test::E;
  constexpr static ID TypeID = ::pf::meta::ID{0x7e0b600ab1eda4feu, 0xae893c21ae5dd635u};

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
      pf::make_array<pf::meta::Info>(::pf::meta::ID{0x5947ee91880a7734u, 0x323aec5c4dbd0e75u},
                                     ::pf::meta::ID{0x43e02b4cc000fb33u, 0x336878c33914e470u});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x165c8e625dacb3d7u, 0x7f733410ff256c5bu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x165c8e625dacb3d7u, 0x7f733410ff256c5bu},
                                                ::pf::meta::ID{0x7e0b600ab1eda4feu, 0xae893c21ae5dd635u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa99dc697fa3d9ba4u, 0x2a4960fdb7431ab7u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xa99dc697fa3d9ba4u, 0x2a4960fdb7431ab7u},
                                               ::pf::meta::ID{0x7e0b600ab1eda4feu, 0xae893c21ae5dd635u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa711a73653436bdu, 0x1b757e4aae1667au}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xa711a73653436bdu, 0x1b757e4aae1667au},
                                               ::pf::meta::ID{0x7e0b600ab1eda4feu, 0xae893c21ae5dd635u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdfc58c52fdba5e33u, 0xba14201238ff2484u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xdfc58c52fdba5e33u, 0xba14201238ff2484u},
                                               ::pf::meta::ID{0x165c8e625dacb3d7u, 0x7f733410ff256c5bu}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x79b09f5ab03dc0b7u, 0x8bd002b94f4dcf91u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x79b09f5ab03dc0b7u, 0x8bd002b94f4dcf91u},
                                              ::pf::meta::ID{0x7e0b600ab1eda4feu, 0xae893c21ae5dd635u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x762565f05c57839bu, 0xc73bfed7d85caf67u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x762565f05c57839bu, 0xc73bfed7d85caf67u},
                                              ::pf::meta::ID{0x165c8e625dacb3d7u, 0x7f733410ff256c5bu}> {};

/****************************** pf::Test::E END ******************************/
namespace pf::meta::details {
/****************************** pf::Test::E START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::Test::E>() {
  return ::pf::meta::ID{0x7e0b600ab1eda4feu, 0xae893c21ae5dd635u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::Test::E>() {
  return ::pf::meta::ID{0x165c8e625dacb3d7u, 0x7f733410ff256c5bu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::Test::E &>() {
  return ::pf::meta::ID{0xa99dc697fa3d9ba4u, 0x2a4960fdb7431ab7u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::Test::E &&>() {
  return ::pf::meta::ID{0xa711a73653436bdu, 0x1b757e4aae1667au};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::Test::E &>() {
  return ::pf::meta::ID{0xdfc58c52fdba5e33u, 0xba14201238ff2484u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::Test::E *>() {
  return ::pf::meta::ID{0x79b09f5ab03dc0b7u, 0x8bd002b94f4dcf91u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::Test::E *>() {
  return ::pf::meta::ID{0x762565f05c57839bu, 0xc73bfed7d85caf67u};
}
/****************************** pf::Test::E END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value1 START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::Test::E::Value1>() {
  return ::pf::meta::ID{0x5947ee91880a7734u, 0x323aec5c4dbd0e75u};
}
/****************************** pf::Test::E::pf::Test::E::Value1 END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value2 START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::Test::E::Value2>() {
  return ::pf::meta::ID{0x43e02b4cc000fb33u, 0x336878c33914e470u};
}
/****************************** pf::Test::E::pf::Test::E::Value2 END ******************************/
} // namespace pf::meta::details
/****************************** pf::EmptyEnum START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8cb83f39269fffdbu, 0x60ae14eed005804bu}> {
  struct details {};
  using Type = pf::EmptyEnum;
  constexpr static ID TypeID = ::pf::meta::ID{0x8cb83f39269fffdbu, 0x60ae14eed005804bu};

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x56614eca503a4c02u, 0x79ac5f7584dac176u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x56614eca503a4c02u, 0x79ac5f7584dac176u},
                                                ::pf::meta::ID{0x8cb83f39269fffdbu, 0x60ae14eed005804bu}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xbe2000329b38dc48u, 0x56421708815789f3u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xbe2000329b38dc48u, 0x56421708815789f3u},
                                               ::pf::meta::ID{0x8cb83f39269fffdbu, 0x60ae14eed005804bu}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1a2637aa09ad07d1u, 0x9211a50f99b5807fu}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x1a2637aa09ad07d1u, 0x9211a50f99b5807fu},
                                               ::pf::meta::ID{0x8cb83f39269fffdbu, 0x60ae14eed005804bu}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6a26a92ebe70afa6u, 0xc4a1fb801e128082u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x6a26a92ebe70afa6u, 0xc4a1fb801e128082u},
                                               ::pf::meta::ID{0x56614eca503a4c02u, 0x79ac5f7584dac176u}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7563afcbf174672au, 0x68cb4d9ad6205423u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x7563afcbf174672au, 0x68cb4d9ad6205423u},
                                              ::pf::meta::ID{0x8cb83f39269fffdbu, 0x60ae14eed005804bu}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2ef7d5b65c40886eu, 0x4a729c60b24816f7u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x2ef7d5b65c40886eu, 0x4a729c60b24816f7u},
                                              ::pf::meta::ID{0x56614eca503a4c02u, 0x79ac5f7584dac176u}> {};

/****************************** pf::EmptyEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::EmptyEnum START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::EmptyEnum>() {
  return ::pf::meta::ID{0x8cb83f39269fffdbu, 0x60ae14eed005804bu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum>() {
  return ::pf::meta::ID{0x56614eca503a4c02u, 0x79ac5f7584dac176u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &>() {
  return ::pf::meta::ID{0xbe2000329b38dc48u, 0x56421708815789f3u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &&>() {
  return ::pf::meta::ID{0x1a2637aa09ad07d1u, 0x9211a50f99b5807fu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum &>() {
  return ::pf::meta::ID{0x6a26a92ebe70afa6u, 0xc4a1fb801e128082u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::EmptyEnum *>() {
  return ::pf::meta::ID{0x7563afcbf174672au, 0x68cb4d9ad6205423u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum *>() {
  return ::pf::meta::ID{0x2ef7d5b65c40886eu, 0x4a729c60b24816f7u};
}
/****************************** pf::EmptyEnum END ******************************/
} // namespace pf::meta::details
/****************************** pf::E1::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa586a0ef8ffd8802u, 0x29d1e1a3e41f1179u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xa586a0ef8ffd8802u, 0x29d1e1a3e41f1179u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe3f38b45ba731c38u, 0x2e6ac9abdaf91fb0u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8e7d9b3afd3c0e73u, 0x9fd9854122a47d6u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x8e7d9b3afd3c0e73u, 0x9fd9854122a47d6u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe3f38b45ba731c38u, 0x2e6ac9abdaf91fb0u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd01d2b9f494cc890u, 0x438ddd259cfc1cb7u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xd01d2b9f494cc890u, 0x438ddd259cfc1cb7u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe3f38b45ba731c38u, 0x2e6ac9abdaf91fb0u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe3cf579b05544bddu, 0xcdc20d9943547cafu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xe3cf579b05544bddu, 0xcdc20d9943547cafu};
  constexpr static ID TypeID = ::pf::meta::ID{0xe3f38b45ba731c38u, 0x2e6ac9abdaf91fb0u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x914601206b2577cau, 0xaa23901c6fc5f89cu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x914601206b2577cau, 0xaa23901c6fc5f89cu};
  constexpr static ID TypeID = ::pf::meta::ID{0xe3f38b45ba731c38u, 0x2e6ac9abdaf91fb0u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe3f38b45ba731c38u, 0x2e6ac9abdaf91fb0u}> {
  struct details {};
  using Type = pf::E1;
  constexpr static ID TypeID = ::pf::meta::ID{0xe3f38b45ba731c38u, 0x2e6ac9abdaf91fb0u};

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
      ::pf::meta::ID{0xa586a0ef8ffd8802u, 0x29d1e1a3e41f1179u}, ::pf::meta::ID{0x8e7d9b3afd3c0e73u, 0x9fd9854122a47d6u},
      ::pf::meta::ID{0xd01d2b9f494cc890u, 0x438ddd259cfc1cb7u},
      ::pf::meta::ID{0xe3cf579b05544bddu, 0xcdc20d9943547cafu},
      ::pf::meta::ID{0x914601206b2577cau, 0xaa23901c6fc5f89cu});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xcd7bf7dad64d40f6u, 0xcad5b614cf7c75cau}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xcd7bf7dad64d40f6u, 0xcad5b614cf7c75cau},
                                                ::pf::meta::ID{0xe3f38b45ba731c38u, 0x2e6ac9abdaf91fb0u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb8b3167ddb3aa138u, 0xa13095aa29f496a5u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xb8b3167ddb3aa138u, 0xa13095aa29f496a5u},
                                               ::pf::meta::ID{0xe3f38b45ba731c38u, 0x2e6ac9abdaf91fb0u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xbdad3fb53d8804u, 0x5e12e06d38642c2du}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xbdad3fb53d8804u, 0x5e12e06d38642c2du},
                                               ::pf::meta::ID{0xe3f38b45ba731c38u, 0x2e6ac9abdaf91fb0u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1ba09fd15e1358ebu, 0x882ab923cb46a008u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x1ba09fd15e1358ebu, 0x882ab923cb46a008u},
                                               ::pf::meta::ID{0xcd7bf7dad64d40f6u, 0xcad5b614cf7c75cau}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8a6bbb0d9f927c49u, 0x108b091037fdf1afu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x8a6bbb0d9f927c49u, 0x108b091037fdf1afu},
                                              ::pf::meta::ID{0xe3f38b45ba731c38u, 0x2e6ac9abdaf91fb0u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa521241c411498cu, 0xadd0cd7b19865b8fu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xa521241c411498cu, 0xadd0cd7b19865b8fu},
                                              ::pf::meta::ID{0xcd7bf7dad64d40f6u, 0xcad5b614cf7c75cau}> {};

/****************************** pf::E1 END ******************************/
namespace pf::meta::details {
/****************************** pf::E1 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E1>() {
  return ::pf::meta::ID{0xe3f38b45ba731c38u, 0x2e6ac9abdaf91fb0u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E1>() {
  return ::pf::meta::ID{0xcd7bf7dad64d40f6u, 0xcad5b614cf7c75cau};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E1 &>() {
  return ::pf::meta::ID{0xb8b3167ddb3aa138u, 0xa13095aa29f496a5u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E1 &&>() {
  return ::pf::meta::ID{0xbdad3fb53d8804u, 0x5e12e06d38642c2du};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E1 &>() {
  return ::pf::meta::ID{0x1ba09fd15e1358ebu, 0x882ab923cb46a008u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E1 *>() {
  return ::pf::meta::ID{0x8a6bbb0d9f927c49u, 0x108b091037fdf1afu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E1 *>() {
  return ::pf::meta::ID{0xa521241c411498cu, 0xadd0cd7b19865b8fu};
}
/****************************** pf::E1 END ******************************/

/****************************** pf::E1::pf::E1::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E1::A>() {
  return ::pf::meta::ID{0xa586a0ef8ffd8802u, 0x29d1e1a3e41f1179u};
}
/****************************** pf::E1::pf::E1::A END ******************************/

/****************************** pf::E1::pf::E1::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E1::B>() {
  return ::pf::meta::ID{0x8e7d9b3afd3c0e73u, 0x9fd9854122a47d6u};
}
/****************************** pf::E1::pf::E1::B END ******************************/

/****************************** pf::E1::pf::E1::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E1::C>() {
  return ::pf::meta::ID{0xd01d2b9f494cc890u, 0x438ddd259cfc1cb7u};
}
/****************************** pf::E1::pf::E1::C END ******************************/

/****************************** pf::E1::pf::E1::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E1::D>() {
  return ::pf::meta::ID{0xe3cf579b05544bddu, 0xcdc20d9943547cafu};
}
/****************************** pf::E1::pf::E1::D END ******************************/

/****************************** pf::E1::pf::E1::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E1::E>() {
  return ::pf::meta::ID{0x914601206b2577cau, 0xaa23901c6fc5f89cu};
}
/****************************** pf::E1::pf::E1::E END ******************************/
} // namespace pf::meta::details
/****************************** pf::E2::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc2a438908601dec4u, 0x839893f1ead55155u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xc2a438908601dec4u, 0x839893f1ead55155u};
  constexpr static ID TypeID = ::pf::meta::ID{0x45488b290586a541u, 0xad16e9a3393535c3u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x502fb6e297fdefbdu, 0xb64c56b4b400e51au}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x502fb6e297fdefbdu, 0xb64c56b4b400e51au};
  constexpr static ID TypeID = ::pf::meta::ID{0x45488b290586a541u, 0xad16e9a3393535c3u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6cbbff58a8a73c98u, 0x9e407440cf307f2cu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x6cbbff58a8a73c98u, 0x9e407440cf307f2cu};
  constexpr static ID TypeID = ::pf::meta::ID{0x45488b290586a541u, 0xad16e9a3393535c3u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa0ccf0fe53586d40u, 0x23e182fbc20cd35bu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xa0ccf0fe53586d40u, 0x23e182fbc20cd35bu};
  constexpr static ID TypeID = ::pf::meta::ID{0x45488b290586a541u, 0xad16e9a3393535c3u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb00851d57d948916u, 0x9e73898e60887b5eu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xb00851d57d948916u, 0x9e73898e60887b5eu};
  constexpr static ID TypeID = ::pf::meta::ID{0x45488b290586a541u, 0xad16e9a3393535c3u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x45488b290586a541u, 0xad16e9a3393535c3u}> {
  struct details {};
  using Type = pf::E2;
  constexpr static ID TypeID = ::pf::meta::ID{0x45488b290586a541u, 0xad16e9a3393535c3u};

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues =
      pf::make_array<pf::meta::Info>(::pf::meta::ID{0xc2a438908601dec4u, 0x839893f1ead55155u},
                                     ::pf::meta::ID{0x502fb6e297fdefbdu, 0xb64c56b4b400e51au},
                                     ::pf::meta::ID{0x6cbbff58a8a73c98u, 0x9e407440cf307f2cu},
                                     ::pf::meta::ID{0xa0ccf0fe53586d40u, 0x23e182fbc20cd35bu},
                                     ::pf::meta::ID{0xb00851d57d948916u, 0x9e73898e60887b5eu});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x48c7c4c437606045u, 0xa0f94ca1b913489u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x48c7c4c437606045u, 0xa0f94ca1b913489u},
                                                ::pf::meta::ID{0x45488b290586a541u, 0xad16e9a3393535c3u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x96bf4ac0562b671u, 0x53e1deb3c3d437e3u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x96bf4ac0562b671u, 0x53e1deb3c3d437e3u},
                                               ::pf::meta::ID{0x45488b290586a541u, 0xad16e9a3393535c3u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7df8b6e71a5b9f4bu, 0xe785de843f0bedfeu}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x7df8b6e71a5b9f4bu, 0xe785de843f0bedfeu},
                                               ::pf::meta::ID{0x45488b290586a541u, 0xad16e9a3393535c3u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x85116306c9b5cbf6u, 0x798fcda8ccc9e259u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x85116306c9b5cbf6u, 0x798fcda8ccc9e259u},
                                               ::pf::meta::ID{0x48c7c4c437606045u, 0xa0f94ca1b913489u}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x737b8eacb882f81u, 0x16108ef3a5a443ceu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x737b8eacb882f81u, 0x16108ef3a5a443ceu},
                                              ::pf::meta::ID{0x45488b290586a541u, 0xad16e9a3393535c3u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xac0c2b98007a1a71u, 0xf7d68dfd177ac5d0u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xac0c2b98007a1a71u, 0xf7d68dfd177ac5d0u},
                                              ::pf::meta::ID{0x48c7c4c437606045u, 0xa0f94ca1b913489u}> {};

/****************************** pf::E2 END ******************************/
namespace pf::meta::details {
/****************************** pf::E2 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E2>() {
  return ::pf::meta::ID{0x45488b290586a541u, 0xad16e9a3393535c3u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E2>() {
  return ::pf::meta::ID{0x48c7c4c437606045u, 0xa0f94ca1b913489u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E2 &>() {
  return ::pf::meta::ID{0x96bf4ac0562b671u, 0x53e1deb3c3d437e3u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E2 &&>() {
  return ::pf::meta::ID{0x7df8b6e71a5b9f4bu, 0xe785de843f0bedfeu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E2 &>() {
  return ::pf::meta::ID{0x85116306c9b5cbf6u, 0x798fcda8ccc9e259u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E2 *>() {
  return ::pf::meta::ID{0x737b8eacb882f81u, 0x16108ef3a5a443ceu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E2 *>() {
  return ::pf::meta::ID{0xac0c2b98007a1a71u, 0xf7d68dfd177ac5d0u};
}
/****************************** pf::E2 END ******************************/

/****************************** pf::E2::pf::E2::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E2::A>() {
  return ::pf::meta::ID{0xc2a438908601dec4u, 0x839893f1ead55155u};
}
/****************************** pf::E2::pf::E2::A END ******************************/

/****************************** pf::E2::pf::E2::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E2::B>() {
  return ::pf::meta::ID{0x502fb6e297fdefbdu, 0xb64c56b4b400e51au};
}
/****************************** pf::E2::pf::E2::B END ******************************/

/****************************** pf::E2::pf::E2::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E2::C>() {
  return ::pf::meta::ID{0x6cbbff58a8a73c98u, 0x9e407440cf307f2cu};
}
/****************************** pf::E2::pf::E2::C END ******************************/

/****************************** pf::E2::pf::E2::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E2::D>() {
  return ::pf::meta::ID{0xa0ccf0fe53586d40u, 0x23e182fbc20cd35bu};
}
/****************************** pf::E2::pf::E2::D END ******************************/

/****************************** pf::E2::pf::E2::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E2::E>() {
  return ::pf::meta::ID{0xb00851d57d948916u, 0x9e73898e60887b5eu};
}
/****************************** pf::E2::pf::E2::E END ******************************/
} // namespace pf::meta::details
/****************************** pf::E3::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x22453c7d6bd2538bu, 0x2203b8b63e51a29fu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x22453c7d6bd2538bu, 0x2203b8b63e51a29fu};
  constexpr static ID TypeID = ::pf::meta::ID{0x90665fe10b544cbfu, 0x9c0bd9ca176010cfu};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb8bb983fca853797u, 0xe99dc1337f7b107au}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xb8bb983fca853797u, 0xe99dc1337f7b107au};
  constexpr static ID TypeID = ::pf::meta::ID{0x90665fe10b544cbfu, 0x9c0bd9ca176010cfu};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb3346d53a9dd86eu, 0x3f5f418a102010c6u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xb3346d53a9dd86eu, 0x3f5f418a102010c6u};
  constexpr static ID TypeID = ::pf::meta::ID{0x90665fe10b544cbfu, 0x9c0bd9ca176010cfu};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x5b0d464c281dab32u, 0x3fe17eb64e5428e7u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x5b0d464c281dab32u, 0x3fe17eb64e5428e7u};
  constexpr static ID TypeID = ::pf::meta::ID{0x90665fe10b544cbfu, 0x9c0bd9ca176010cfu};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x264bed75bb0a1cd4u, 0x62f268ec673a3ae4u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x264bed75bb0a1cd4u, 0x62f268ec673a3ae4u};
  constexpr static ID TypeID = ::pf::meta::ID{0x90665fe10b544cbfu, 0x9c0bd9ca176010cfu};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x90665fe10b544cbfu, 0x9c0bd9ca176010cfu}> {
  struct details {};
  using Type = pf::E3;
  constexpr static ID TypeID = ::pf::meta::ID{0x90665fe10b544cbfu, 0x9c0bd9ca176010cfu};

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
      ::pf::meta::ID{0x22453c7d6bd2538bu, 0x2203b8b63e51a29fu},
      ::pf::meta::ID{0xb8bb983fca853797u, 0xe99dc1337f7b107au}, ::pf::meta::ID{0xb3346d53a9dd86eu, 0x3f5f418a102010c6u},
      ::pf::meta::ID{0x5b0d464c281dab32u, 0x3fe17eb64e5428e7u},
      ::pf::meta::ID{0x264bed75bb0a1cd4u, 0x62f268ec673a3ae4u});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe24aa2d4158ac6b6u, 0x65ca8ad84f3ff642u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xe24aa2d4158ac6b6u, 0x65ca8ad84f3ff642u},
                                                ::pf::meta::ID{0x90665fe10b544cbfu, 0x9c0bd9ca176010cfu}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x88b9b87819b0e8f5u, 0xc8706e3f3d0f4736u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x88b9b87819b0e8f5u, 0xc8706e3f3d0f4736u},
                                               ::pf::meta::ID{0x90665fe10b544cbfu, 0x9c0bd9ca176010cfu}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb98ed5c875041714u, 0x2d7b186ffda37621u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xb98ed5c875041714u, 0x2d7b186ffda37621u},
                                               ::pf::meta::ID{0x90665fe10b544cbfu, 0x9c0bd9ca176010cfu}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4e71fc0416a0ea03u, 0xa8cdb71b65add474u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x4e71fc0416a0ea03u, 0xa8cdb71b65add474u},
                                               ::pf::meta::ID{0xe24aa2d4158ac6b6u, 0x65ca8ad84f3ff642u}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9a46695f78046b01u, 0x9494e87787a81500u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x9a46695f78046b01u, 0x9494e87787a81500u},
                                              ::pf::meta::ID{0x90665fe10b544cbfu, 0x9c0bd9ca176010cfu}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x48014413fca3adaeu, 0x9490e2784e5fe483u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x48014413fca3adaeu, 0x9490e2784e5fe483u},
                                              ::pf::meta::ID{0xe24aa2d4158ac6b6u, 0x65ca8ad84f3ff642u}> {};

/****************************** pf::E3 END ******************************/
namespace pf::meta::details {
/****************************** pf::E3 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E3>() {
  return ::pf::meta::ID{0x90665fe10b544cbfu, 0x9c0bd9ca176010cfu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E3>() {
  return ::pf::meta::ID{0xe24aa2d4158ac6b6u, 0x65ca8ad84f3ff642u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E3 &>() {
  return ::pf::meta::ID{0x88b9b87819b0e8f5u, 0xc8706e3f3d0f4736u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E3 &&>() {
  return ::pf::meta::ID{0xb98ed5c875041714u, 0x2d7b186ffda37621u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E3 &>() {
  return ::pf::meta::ID{0x4e71fc0416a0ea03u, 0xa8cdb71b65add474u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E3 *>() {
  return ::pf::meta::ID{0x9a46695f78046b01u, 0x9494e87787a81500u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E3 *>() {
  return ::pf::meta::ID{0x48014413fca3adaeu, 0x9490e2784e5fe483u};
}
/****************************** pf::E3 END ******************************/

/****************************** pf::E3::pf::E3::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E3::A>() {
  return ::pf::meta::ID{0x22453c7d6bd2538bu, 0x2203b8b63e51a29fu};
}
/****************************** pf::E3::pf::E3::A END ******************************/

/****************************** pf::E3::pf::E3::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E3::B>() {
  return ::pf::meta::ID{0xb8bb983fca853797u, 0xe99dc1337f7b107au};
}
/****************************** pf::E3::pf::E3::B END ******************************/

/****************************** pf::E3::pf::E3::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E3::C>() {
  return ::pf::meta::ID{0xb3346d53a9dd86eu, 0x3f5f418a102010c6u};
}
/****************************** pf::E3::pf::E3::C END ******************************/

/****************************** pf::E3::pf::E3::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E3::D>() {
  return ::pf::meta::ID{0x5b0d464c281dab32u, 0x3fe17eb64e5428e7u};
}
/****************************** pf::E3::pf::E3::D END ******************************/

/****************************** pf::E3::pf::E3::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E3::E>() {
  return ::pf::meta::ID{0x264bed75bb0a1cd4u, 0x62f268ec673a3ae4u};
}
/****************************** pf::E3::pf::E3::E END ******************************/
} // namespace pf::meta::details
/****************************** pf::E4::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2dbbd0e031535bf4u, 0xb137f8008f9c324u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x2dbbd0e031535bf4u, 0xb137f8008f9c324u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe27dc27508c4d21cu, 0x5a38ae426d8a1737u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xaba1b26eb2d1f8a5u, 0x7e34acb41d331466u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xaba1b26eb2d1f8a5u, 0x7e34acb41d331466u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe27dc27508c4d21cu, 0x5a38ae426d8a1737u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf693e18a0d96a2e7u, 0x93ca79b790832f9u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xf693e18a0d96a2e7u, 0x93ca79b790832f9u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe27dc27508c4d21cu, 0x5a38ae426d8a1737u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x99483f1b3ec05a03u, 0xac5e21e3954a02f8u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x99483f1b3ec05a03u, 0xac5e21e3954a02f8u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe27dc27508c4d21cu, 0x5a38ae426d8a1737u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc8d5233559761868u, 0xe7f2e63c9e6f1108u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xc8d5233559761868u, 0xe7f2e63c9e6f1108u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe27dc27508c4d21cu, 0x5a38ae426d8a1737u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe27dc27508c4d21cu, 0x5a38ae426d8a1737u}> {
  struct details {};
  using Type = pf::E4;
  constexpr static ID TypeID = ::pf::meta::ID{0xe27dc27508c4d21cu, 0x5a38ae426d8a1737u};

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
      ::pf::meta::ID{0x2dbbd0e031535bf4u, 0xb137f8008f9c324u}, ::pf::meta::ID{0xaba1b26eb2d1f8a5u, 0x7e34acb41d331466u},
      ::pf::meta::ID{0xf693e18a0d96a2e7u, 0x93ca79b790832f9u}, ::pf::meta::ID{0x99483f1b3ec05a03u, 0xac5e21e3954a02f8u},
      ::pf::meta::ID{0xc8d5233559761868u, 0xe7f2e63c9e6f1108u});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9424bc6b8997c398u, 0x412c8f930ddda39du}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x9424bc6b8997c398u, 0x412c8f930ddda39du},
                                                ::pf::meta::ID{0xe27dc27508c4d21cu, 0x5a38ae426d8a1737u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x5f92792a151d2428u, 0x66f2aa9ac22f4d25u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x5f92792a151d2428u, 0x66f2aa9ac22f4d25u},
                                               ::pf::meta::ID{0xe27dc27508c4d21cu, 0x5a38ae426d8a1737u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x47ae06bd28a898c1u, 0x6064baf5df2b4eb7u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x47ae06bd28a898c1u, 0x6064baf5df2b4eb7u},
                                               ::pf::meta::ID{0xe27dc27508c4d21cu, 0x5a38ae426d8a1737u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xcd1c9a8d66b75bd8u, 0xe2ed8dfc712d9e7eu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xcd1c9a8d66b75bd8u, 0xe2ed8dfc712d9e7eu},
                                               ::pf::meta::ID{0x9424bc6b8997c398u, 0x412c8f930ddda39du}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2b9418a8a9ea7d74u, 0x680be6484e67cceeu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x2b9418a8a9ea7d74u, 0x680be6484e67cceeu},
                                              ::pf::meta::ID{0xe27dc27508c4d21cu, 0x5a38ae426d8a1737u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9e616a9e74946cc2u, 0x2f9b39ebf29fedf1u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x9e616a9e74946cc2u, 0x2f9b39ebf29fedf1u},
                                              ::pf::meta::ID{0x9424bc6b8997c398u, 0x412c8f930ddda39du}> {};

/****************************** pf::E4 END ******************************/
namespace pf::meta::details {
/****************************** pf::E4 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E4>() {
  return ::pf::meta::ID{0xe27dc27508c4d21cu, 0x5a38ae426d8a1737u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E4>() {
  return ::pf::meta::ID{0x9424bc6b8997c398u, 0x412c8f930ddda39du};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E4 &>() {
  return ::pf::meta::ID{0x5f92792a151d2428u, 0x66f2aa9ac22f4d25u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E4 &&>() {
  return ::pf::meta::ID{0x47ae06bd28a898c1u, 0x6064baf5df2b4eb7u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E4 &>() {
  return ::pf::meta::ID{0xcd1c9a8d66b75bd8u, 0xe2ed8dfc712d9e7eu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E4 *>() {
  return ::pf::meta::ID{0x2b9418a8a9ea7d74u, 0x680be6484e67cceeu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E4 *>() {
  return ::pf::meta::ID{0x9e616a9e74946cc2u, 0x2f9b39ebf29fedf1u};
}
/****************************** pf::E4 END ******************************/

/****************************** pf::E4::pf::E4::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E4::A>() {
  return ::pf::meta::ID{0x2dbbd0e031535bf4u, 0xb137f8008f9c324u};
}
/****************************** pf::E4::pf::E4::A END ******************************/

/****************************** pf::E4::pf::E4::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E4::B>() {
  return ::pf::meta::ID{0xaba1b26eb2d1f8a5u, 0x7e34acb41d331466u};
}
/****************************** pf::E4::pf::E4::B END ******************************/

/****************************** pf::E4::pf::E4::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E4::C>() {
  return ::pf::meta::ID{0xf693e18a0d96a2e7u, 0x93ca79b790832f9u};
}
/****************************** pf::E4::pf::E4::C END ******************************/

/****************************** pf::E4::pf::E4::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E4::D>() {
  return ::pf::meta::ID{0x99483f1b3ec05a03u, 0xac5e21e3954a02f8u};
}
/****************************** pf::E4::pf::E4::D END ******************************/

/****************************** pf::E4::pf::E4::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E4::E>() {
  return ::pf::meta::ID{0xc8d5233559761868u, 0xe7f2e63c9e6f1108u};
}
/****************************** pf::E4::pf::E4::E END ******************************/
} // namespace pf::meta::details
/****************************** pf::E5::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4ff42f0e2d55a20fu, 0x7e129b09e8c9fe9u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x4ff42f0e2d55a20fu, 0x7e129b09e8c9fe9u};
  constexpr static ID TypeID = ::pf::meta::ID{0xeb949ac66a028e4eu, 0xf6cd09104670a4f9u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2e9922f788d185bcu, 0x4567884bed95961cu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x2e9922f788d185bcu, 0x4567884bed95961cu};
  constexpr static ID TypeID = ::pf::meta::ID{0xeb949ac66a028e4eu, 0xf6cd09104670a4f9u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1d6bd0a2debe23f5u, 0x456d2ade02690dd9u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x1d6bd0a2debe23f5u, 0x456d2ade02690dd9u};
  constexpr static ID TypeID = ::pf::meta::ID{0xeb949ac66a028e4eu, 0xf6cd09104670a4f9u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xcc2678adef04ef4du, 0x6e2093fcbf07f773u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xcc2678adef04ef4du, 0x6e2093fcbf07f773u};
  constexpr static ID TypeID = ::pf::meta::ID{0xeb949ac66a028e4eu, 0xf6cd09104670a4f9u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4af0c3bb1d91d6bfu, 0x3f84a1f904c0c7ebu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x4af0c3bb1d91d6bfu, 0x3f84a1f904c0c7ebu};
  constexpr static ID TypeID = ::pf::meta::ID{0xeb949ac66a028e4eu, 0xf6cd09104670a4f9u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xeb949ac66a028e4eu, 0xf6cd09104670a4f9u}> {
  struct details {};
  using Type = pf::E5;
  constexpr static ID TypeID = ::pf::meta::ID{0xeb949ac66a028e4eu, 0xf6cd09104670a4f9u};

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
      ::pf::meta::ID{0x4ff42f0e2d55a20fu, 0x7e129b09e8c9fe9u}, ::pf::meta::ID{0x2e9922f788d185bcu, 0x4567884bed95961cu},
      ::pf::meta::ID{0x1d6bd0a2debe23f5u, 0x456d2ade02690dd9u},
      ::pf::meta::ID{0xcc2678adef04ef4du, 0x6e2093fcbf07f773u},
      ::pf::meta::ID{0x4af0c3bb1d91d6bfu, 0x3f84a1f904c0c7ebu});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8c4bb6779c65785u, 0xe19ba860891339du}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x8c4bb6779c65785u, 0xe19ba860891339du},
                                                ::pf::meta::ID{0xeb949ac66a028e4eu, 0xf6cd09104670a4f9u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x15d3ae05ec7603fu, 0xfe90268d0464c9abu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x15d3ae05ec7603fu, 0xfe90268d0464c9abu},
                                               ::pf::meta::ID{0xeb949ac66a028e4eu, 0xf6cd09104670a4f9u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9ca92abac4fdb1fcu, 0x90ea46f7ce1d9389u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x9ca92abac4fdb1fcu, 0x90ea46f7ce1d9389u},
                                               ::pf::meta::ID{0xeb949ac66a028e4eu, 0xf6cd09104670a4f9u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x41ed5bab9e44d859u, 0xe8dad3e6690dc195u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x41ed5bab9e44d859u, 0xe8dad3e6690dc195u},
                                               ::pf::meta::ID{0x8c4bb6779c65785u, 0xe19ba860891339du}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb4bf58e9c79fea04u, 0xe8c8a05abf6571e8u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xb4bf58e9c79fea04u, 0xe8c8a05abf6571e8u},
                                              ::pf::meta::ID{0xeb949ac66a028e4eu, 0xf6cd09104670a4f9u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x52aeeb8b2c8fc478u, 0xbf269ae585f76f53u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x52aeeb8b2c8fc478u, 0xbf269ae585f76f53u},
                                              ::pf::meta::ID{0x8c4bb6779c65785u, 0xe19ba860891339du}> {};

/****************************** pf::E5 END ******************************/
namespace pf::meta::details {
/****************************** pf::E5 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E5>() {
  return ::pf::meta::ID{0xeb949ac66a028e4eu, 0xf6cd09104670a4f9u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E5>() {
  return ::pf::meta::ID{0x8c4bb6779c65785u, 0xe19ba860891339du};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E5 &>() {
  return ::pf::meta::ID{0x15d3ae05ec7603fu, 0xfe90268d0464c9abu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E5 &&>() {
  return ::pf::meta::ID{0x9ca92abac4fdb1fcu, 0x90ea46f7ce1d9389u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E5 &>() {
  return ::pf::meta::ID{0x41ed5bab9e44d859u, 0xe8dad3e6690dc195u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E5 *>() {
  return ::pf::meta::ID{0xb4bf58e9c79fea04u, 0xe8c8a05abf6571e8u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E5 *>() {
  return ::pf::meta::ID{0x52aeeb8b2c8fc478u, 0xbf269ae585f76f53u};
}
/****************************** pf::E5 END ******************************/

/****************************** pf::E5::pf::E5::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E5::A>() {
  return ::pf::meta::ID{0x4ff42f0e2d55a20fu, 0x7e129b09e8c9fe9u};
}
/****************************** pf::E5::pf::E5::A END ******************************/

/****************************** pf::E5::pf::E5::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E5::B>() {
  return ::pf::meta::ID{0x2e9922f788d185bcu, 0x4567884bed95961cu};
}
/****************************** pf::E5::pf::E5::B END ******************************/

/****************************** pf::E5::pf::E5::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E5::C>() {
  return ::pf::meta::ID{0x1d6bd0a2debe23f5u, 0x456d2ade02690dd9u};
}
/****************************** pf::E5::pf::E5::C END ******************************/

/****************************** pf::E5::pf::E5::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E5::D>() {
  return ::pf::meta::ID{0xcc2678adef04ef4du, 0x6e2093fcbf07f773u};
}
/****************************** pf::E5::pf::E5::D END ******************************/

/****************************** pf::E5::pf::E5::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E5::E>() {
  return ::pf::meta::ID{0x4af0c3bb1d91d6bfu, 0x3f84a1f904c0c7ebu};
}
/****************************** pf::E5::pf::E5::E END ******************************/
} // namespace pf::meta::details
/****************************** pf::E6::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x57c6f9eeb2eca3b6u, 0x1bd9a06de801dce8u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x57c6f9eeb2eca3b6u, 0x1bd9a06de801dce8u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe57bce61d421f304u, 0xb200d50ae00528b3u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe45e49ffa7d0f562u, 0x47c3d17b77842dcbu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xe45e49ffa7d0f562u, 0x47c3d17b77842dcbu};
  constexpr static ID TypeID = ::pf::meta::ID{0xe57bce61d421f304u, 0xb200d50ae00528b3u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x584eb68419552788u, 0xf53446be35d0df97u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x584eb68419552788u, 0xf53446be35d0df97u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe57bce61d421f304u, 0xb200d50ae00528b3u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8acb16ad2d68f0dcu, 0x55140b427a1e9a68u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x8acb16ad2d68f0dcu, 0x55140b427a1e9a68u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe57bce61d421f304u, 0xb200d50ae00528b3u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6fa06c0a81924b59u, 0xabac3ff7a1564f20u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x6fa06c0a81924b59u, 0xabac3ff7a1564f20u};
  constexpr static ID TypeID = ::pf::meta::ID{0xe57bce61d421f304u, 0xb200d50ae00528b3u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe57bce61d421f304u, 0xb200d50ae00528b3u}> {
  struct details {};
  using Type = pf::E6;
  constexpr static ID TypeID = ::pf::meta::ID{0xe57bce61d421f304u, 0xb200d50ae00528b3u};

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
      pf::make_array<pf::meta::Info>(::pf::meta::ID{0x57c6f9eeb2eca3b6u, 0x1bd9a06de801dce8u},
                                     ::pf::meta::ID{0xe45e49ffa7d0f562u, 0x47c3d17b77842dcbu},
                                     ::pf::meta::ID{0x584eb68419552788u, 0xf53446be35d0df97u},
                                     ::pf::meta::ID{0x8acb16ad2d68f0dcu, 0x55140b427a1e9a68u},
                                     ::pf::meta::ID{0x6fa06c0a81924b59u, 0xabac3ff7a1564f20u});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4810fc36c734a902u, 0x3070409a694a629du}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x4810fc36c734a902u, 0x3070409a694a629du},
                                                ::pf::meta::ID{0xe57bce61d421f304u, 0xb200d50ae00528b3u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc8df85a11a6f9bc7u, 0xaa8b7329cca49067u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xc8df85a11a6f9bc7u, 0xaa8b7329cca49067u},
                                               ::pf::meta::ID{0xe57bce61d421f304u, 0xb200d50ae00528b3u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8ed681629222ca3eu, 0x930863133f57f6f0u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x8ed681629222ca3eu, 0x930863133f57f6f0u},
                                               ::pf::meta::ID{0xe57bce61d421f304u, 0xb200d50ae00528b3u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8d515e4fa06183a8u, 0x83ebaebb671192f9u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x8d515e4fa06183a8u, 0x83ebaebb671192f9u},
                                               ::pf::meta::ID{0x4810fc36c734a902u, 0x3070409a694a629du}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xcdb7fb64770d3db3u, 0x4590931b3be286dcu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xcdb7fb64770d3db3u, 0x4590931b3be286dcu},
                                              ::pf::meta::ID{0xe57bce61d421f304u, 0xb200d50ae00528b3u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9517fb8f2557d97u, 0x81fd7af972253e5fu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x9517fb8f2557d97u, 0x81fd7af972253e5fu},
                                              ::pf::meta::ID{0x4810fc36c734a902u, 0x3070409a694a629du}> {};

/****************************** pf::E6 END ******************************/
namespace pf::meta::details {
/****************************** pf::E6 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E6>() {
  return ::pf::meta::ID{0xe57bce61d421f304u, 0xb200d50ae00528b3u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E6>() {
  return ::pf::meta::ID{0x4810fc36c734a902u, 0x3070409a694a629du};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E6 &>() {
  return ::pf::meta::ID{0xc8df85a11a6f9bc7u, 0xaa8b7329cca49067u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E6 &&>() {
  return ::pf::meta::ID{0x8ed681629222ca3eu, 0x930863133f57f6f0u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E6 &>() {
  return ::pf::meta::ID{0x8d515e4fa06183a8u, 0x83ebaebb671192f9u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E6 *>() {
  return ::pf::meta::ID{0xcdb7fb64770d3db3u, 0x4590931b3be286dcu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E6 *>() {
  return ::pf::meta::ID{0x9517fb8f2557d97u, 0x81fd7af972253e5fu};
}
/****************************** pf::E6 END ******************************/

/****************************** pf::E6::pf::E6::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E6::A>() {
  return ::pf::meta::ID{0x57c6f9eeb2eca3b6u, 0x1bd9a06de801dce8u};
}
/****************************** pf::E6::pf::E6::A END ******************************/

/****************************** pf::E6::pf::E6::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E6::B>() {
  return ::pf::meta::ID{0xe45e49ffa7d0f562u, 0x47c3d17b77842dcbu};
}
/****************************** pf::E6::pf::E6::B END ******************************/

/****************************** pf::E6::pf::E6::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E6::C>() {
  return ::pf::meta::ID{0x584eb68419552788u, 0xf53446be35d0df97u};
}
/****************************** pf::E6::pf::E6::C END ******************************/

/****************************** pf::E6::pf::E6::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E6::D>() {
  return ::pf::meta::ID{0x8acb16ad2d68f0dcu, 0x55140b427a1e9a68u};
}
/****************************** pf::E6::pf::E6::D END ******************************/

/****************************** pf::E6::pf::E6::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E6::E>() {
  return ::pf::meta::ID{0x6fa06c0a81924b59u, 0xabac3ff7a1564f20u};
}
/****************************** pf::E6::pf::E6::E END ******************************/
} // namespace pf::meta::details
/****************************** pf::E7::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x419bed071cb825f0u, 0x753e99c1f464bdcbu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x419bed071cb825f0u, 0x753e99c1f464bdcbu};
  constexpr static ID TypeID = ::pf::meta::ID{0x26f6cfadf87a9d62u, 0x925584c532b2a15eu};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7810adafdf502c2u, 0xd7226e44d3db8751u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x7810adafdf502c2u, 0xd7226e44d3db8751u};
  constexpr static ID TypeID = ::pf::meta::ID{0x26f6cfadf87a9d62u, 0x925584c532b2a15eu};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6f834318b4c2b511u, 0xe649f91554988f85u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x6f834318b4c2b511u, 0xe649f91554988f85u};
  constexpr static ID TypeID = ::pf::meta::ID{0x26f6cfadf87a9d62u, 0x925584c532b2a15eu};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xfe4e237598e8cd46u, 0x2b7bc256dc3f7080u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xfe4e237598e8cd46u, 0x2b7bc256dc3f7080u};
  constexpr static ID TypeID = ::pf::meta::ID{0x26f6cfadf87a9d62u, 0x925584c532b2a15eu};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9d6d19fa15d21b54u, 0x8c740d67584089eau}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x9d6d19fa15d21b54u, 0x8c740d67584089eau};
  constexpr static ID TypeID = ::pf::meta::ID{0x26f6cfadf87a9d62u, 0x925584c532b2a15eu};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x26f6cfadf87a9d62u, 0x925584c532b2a15eu}> {
  struct details {};
  using Type = pf::E7;
  constexpr static ID TypeID = ::pf::meta::ID{0x26f6cfadf87a9d62u, 0x925584c532b2a15eu};

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
      ::pf::meta::ID{0x419bed071cb825f0u, 0x753e99c1f464bdcbu}, ::pf::meta::ID{0x7810adafdf502c2u, 0xd7226e44d3db8751u},
      ::pf::meta::ID{0x6f834318b4c2b511u, 0xe649f91554988f85u},
      ::pf::meta::ID{0xfe4e237598e8cd46u, 0x2b7bc256dc3f7080u},
      ::pf::meta::ID{0x9d6d19fa15d21b54u, 0x8c740d67584089eau});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x71f830dfee45beb6u, 0x5e1e15df05badaf2u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x71f830dfee45beb6u, 0x5e1e15df05badaf2u},
                                                ::pf::meta::ID{0x26f6cfadf87a9d62u, 0x925584c532b2a15eu}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6d67a0caa11abe17u, 0x7467583d906e4f08u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x6d67a0caa11abe17u, 0x7467583d906e4f08u},
                                               ::pf::meta::ID{0x26f6cfadf87a9d62u, 0x925584c532b2a15eu}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x73d1f18191e2c243u, 0xdb6a3907f65b443fu}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x73d1f18191e2c243u, 0xdb6a3907f65b443fu},
                                               ::pf::meta::ID{0x26f6cfadf87a9d62u, 0x925584c532b2a15eu}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe4a7e9dad22df6d1u, 0x3d0db2c23496472fu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xe4a7e9dad22df6d1u, 0x3d0db2c23496472fu},
                                               ::pf::meta::ID{0x71f830dfee45beb6u, 0x5e1e15df05badaf2u}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x14dc12aece7a0e3cu, 0x74ca6aa0e941e3ceu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x14dc12aece7a0e3cu, 0x74ca6aa0e941e3ceu},
                                              ::pf::meta::ID{0x26f6cfadf87a9d62u, 0x925584c532b2a15eu}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb7e293aab0da1df9u, 0x96e7796ac0a9d4d8u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xb7e293aab0da1df9u, 0x96e7796ac0a9d4d8u},
                                              ::pf::meta::ID{0x71f830dfee45beb6u, 0x5e1e15df05badaf2u}> {};

/****************************** pf::E7 END ******************************/
namespace pf::meta::details {
/****************************** pf::E7 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E7>() {
  return ::pf::meta::ID{0x26f6cfadf87a9d62u, 0x925584c532b2a15eu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E7>() {
  return ::pf::meta::ID{0x71f830dfee45beb6u, 0x5e1e15df05badaf2u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E7 &>() {
  return ::pf::meta::ID{0x6d67a0caa11abe17u, 0x7467583d906e4f08u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E7 &&>() {
  return ::pf::meta::ID{0x73d1f18191e2c243u, 0xdb6a3907f65b443fu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E7 &>() {
  return ::pf::meta::ID{0xe4a7e9dad22df6d1u, 0x3d0db2c23496472fu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E7 *>() {
  return ::pf::meta::ID{0x14dc12aece7a0e3cu, 0x74ca6aa0e941e3ceu};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E7 *>() {
  return ::pf::meta::ID{0xb7e293aab0da1df9u, 0x96e7796ac0a9d4d8u};
}
/****************************** pf::E7 END ******************************/

/****************************** pf::E7::pf::E7::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E7::A>() {
  return ::pf::meta::ID{0x419bed071cb825f0u, 0x753e99c1f464bdcbu};
}
/****************************** pf::E7::pf::E7::A END ******************************/

/****************************** pf::E7::pf::E7::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E7::B>() {
  return ::pf::meta::ID{0x7810adafdf502c2u, 0xd7226e44d3db8751u};
}
/****************************** pf::E7::pf::E7::B END ******************************/

/****************************** pf::E7::pf::E7::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E7::C>() {
  return ::pf::meta::ID{0x6f834318b4c2b511u, 0xe649f91554988f85u};
}
/****************************** pf::E7::pf::E7::C END ******************************/

/****************************** pf::E7::pf::E7::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E7::D>() {
  return ::pf::meta::ID{0xfe4e237598e8cd46u, 0x2b7bc256dc3f7080u};
}
/****************************** pf::E7::pf::E7::D END ******************************/

/****************************** pf::E7::pf::E7::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E7::E>() {
  return ::pf::meta::ID{0x9d6d19fa15d21b54u, 0x8c740d67584089eau};
}
/****************************** pf::E7::pf::E7::E END ******************************/
} // namespace pf::meta::details
/****************************** pf::E8::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4d2960cea846932cu, 0x64cdb5a20527d1au}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x4d2960cea846932cu, 0x64cdb5a20527d1au};
  constexpr static ID TypeID = ::pf::meta::ID{0x22b02ae933d7a465u, 0xfb550e9c8b4fdeau};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdec9bcf69f011ee5u, 0x3706795e5ef3157au}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xdec9bcf69f011ee5u, 0x3706795e5ef3157au};
  constexpr static ID TypeID = ::pf::meta::ID{0x22b02ae933d7a465u, 0xfb550e9c8b4fdeau};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x378feba004748c8fu, 0x5de6c824c051a3f9u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x378feba004748c8fu, 0x5de6c824c051a3f9u};
  constexpr static ID TypeID = ::pf::meta::ID{0x22b02ae933d7a465u, 0xfb550e9c8b4fdeau};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x28ed6a91860efa5u, 0x46e736c2940e802au}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x28ed6a91860efa5u, 0x46e736c2940e802au};
  constexpr static ID TypeID = ::pf::meta::ID{0x22b02ae933d7a465u, 0xfb550e9c8b4fdeau};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xac5f003c9511b6a4u, 0x835359d52c07e8dfu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xac5f003c9511b6a4u, 0x835359d52c07e8dfu};
  constexpr static ID TypeID = ::pf::meta::ID{0x22b02ae933d7a465u, 0xfb550e9c8b4fdeau};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x22b02ae933d7a465u, 0xfb550e9c8b4fdeau}> {
  struct details {};
  using Type = pf::E8;
  constexpr static ID TypeID = ::pf::meta::ID{0x22b02ae933d7a465u, 0xfb550e9c8b4fdeau};

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
      ::pf::meta::ID{0x4d2960cea846932cu, 0x64cdb5a20527d1au}, ::pf::meta::ID{0xdec9bcf69f011ee5u, 0x3706795e5ef3157au},
      ::pf::meta::ID{0x378feba004748c8fu, 0x5de6c824c051a3f9u}, ::pf::meta::ID{0x28ed6a91860efa5u, 0x46e736c2940e802au},
      ::pf::meta::ID{0xac5f003c9511b6a4u, 0x835359d52c07e8dfu});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x76a20be4625bff7fu, 0x8c26c6f10cd25fa3u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x76a20be4625bff7fu, 0x8c26c6f10cd25fa3u},
                                                ::pf::meta::ID{0x22b02ae933d7a465u, 0xfb550e9c8b4fdeau}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7733cb031b705c15u, 0x39d671ca447cb8d0u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x7733cb031b705c15u, 0x39d671ca447cb8d0u},
                                               ::pf::meta::ID{0x22b02ae933d7a465u, 0xfb550e9c8b4fdeau}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa9cff25173ab49c8u, 0x910816f62972b7cau}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xa9cff25173ab49c8u, 0x910816f62972b7cau},
                                               ::pf::meta::ID{0x22b02ae933d7a465u, 0xfb550e9c8b4fdeau}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x24a13fe448061359u, 0x6e6bbda8780eff5eu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x24a13fe448061359u, 0x6e6bbda8780eff5eu},
                                               ::pf::meta::ID{0x76a20be4625bff7fu, 0x8c26c6f10cd25fa3u}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdbcf9fed25f54bbu, 0xfe5c5949745c3709u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xdbcf9fed25f54bbu, 0xfe5c5949745c3709u},
                                              ::pf::meta::ID{0x22b02ae933d7a465u, 0xfb550e9c8b4fdeau}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x858c70d38919db38u, 0xfec0fe534e9547ecu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x858c70d38919db38u, 0xfec0fe534e9547ecu},
                                              ::pf::meta::ID{0x76a20be4625bff7fu, 0x8c26c6f10cd25fa3u}> {};

/****************************** pf::E8 END ******************************/
namespace pf::meta::details {
/****************************** pf::E8 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E8>() {
  return ::pf::meta::ID{0x22b02ae933d7a465u, 0xfb550e9c8b4fdeau};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E8>() {
  return ::pf::meta::ID{0x76a20be4625bff7fu, 0x8c26c6f10cd25fa3u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E8 &>() {
  return ::pf::meta::ID{0x7733cb031b705c15u, 0x39d671ca447cb8d0u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E8 &&>() {
  return ::pf::meta::ID{0xa9cff25173ab49c8u, 0x910816f62972b7cau};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E8 &>() {
  return ::pf::meta::ID{0x24a13fe448061359u, 0x6e6bbda8780eff5eu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E8 *>() {
  return ::pf::meta::ID{0xdbcf9fed25f54bbu, 0xfe5c5949745c3709u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E8 *>() {
  return ::pf::meta::ID{0x858c70d38919db38u, 0xfec0fe534e9547ecu};
}
/****************************** pf::E8 END ******************************/

/****************************** pf::E8::pf::E8::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E8::A>() {
  return ::pf::meta::ID{0x4d2960cea846932cu, 0x64cdb5a20527d1au};
}
/****************************** pf::E8::pf::E8::A END ******************************/

/****************************** pf::E8::pf::E8::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E8::B>() {
  return ::pf::meta::ID{0xdec9bcf69f011ee5u, 0x3706795e5ef3157au};
}
/****************************** pf::E8::pf::E8::B END ******************************/

/****************************** pf::E8::pf::E8::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E8::C>() {
  return ::pf::meta::ID{0x378feba004748c8fu, 0x5de6c824c051a3f9u};
}
/****************************** pf::E8::pf::E8::C END ******************************/

/****************************** pf::E8::pf::E8::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E8::D>() {
  return ::pf::meta::ID{0x28ed6a91860efa5u, 0x46e736c2940e802au};
}
/****************************** pf::E8::pf::E8::D END ******************************/

/****************************** pf::E8::pf::E8::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E8::E>() {
  return ::pf::meta::ID{0xac5f003c9511b6a4u, 0x835359d52c07e8dfu};
}
/****************************** pf::E8::pf::E8::E END ******************************/
} // namespace pf::meta::details
/****************************** pf::E9::A START ******************************/
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xfa6f10d033b6d7d3u, 0xd853fa22cae4c4b1u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0xfa6f10d033b6d7d3u, 0xd853fa22cae4c4b1u};
  constexpr static ID TypeID = ::pf::meta::ID{0x2edca832f52dd20cu, 0x1e76554f57a4b3f8u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x660b1c5cc2c094eau, 0x7c80fbfd2640d154u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x660b1c5cc2c094eau, 0x7c80fbfd2640d154u};
  constexpr static ID TypeID = ::pf::meta::ID{0x2edca832f52dd20cu, 0x1e76554f57a4b3f8u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4d3e10b2dc1477f1u, 0x86d2d78186e0896bu}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x4d3e10b2dc1477f1u, 0x86d2d78186e0896bu};
  constexpr static ID TypeID = ::pf::meta::ID{0x2edca832f52dd20cu, 0x1e76554f57a4b3f8u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4207164816f484e3u, 0xb4341b2ab7ec42f6u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x4207164816f484e3u, 0xb4341b2ab7ec42f6u};
  constexpr static ID TypeID = ::pf::meta::ID{0x2edca832f52dd20cu, 0x1e76554f57a4b3f8u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x16a4736181146c4bu, 0x6878b16674a30527u}> {
  struct details {};
  constexpr static ID ValueID = ::pf::meta::ID{0x16a4736181146c4bu, 0x6878b16674a30527u};
  constexpr static ID TypeID = ::pf::meta::ID{0x2edca832f52dd20cu, 0x1e76554f57a4b3f8u};
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
template <> struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2edca832f52dd20cu, 0x1e76554f57a4b3f8u}> {
  struct details {};
  using Type = pf::E9;
  constexpr static ID TypeID = ::pf::meta::ID{0x2edca832f52dd20cu, 0x1e76554f57a4b3f8u};

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
  constexpr static RangeOf<pf::meta::Info> auto EnumValues =
      pf::make_array<pf::meta::Info>(::pf::meta::ID{0xfa6f10d033b6d7d3u, 0xd853fa22cae4c4b1u},
                                     ::pf::meta::ID{0x660b1c5cc2c094eau, 0x7c80fbfd2640d154u},
                                     ::pf::meta::ID{0x4d3e10b2dc1477f1u, 0x86d2d78186e0896bu},
                                     ::pf::meta::ID{0x4207164816f484e3u, 0xb4341b2ab7ec42f6u},
                                     ::pf::meta::ID{0x16a4736181146c4bu, 0x6878b16674a30527u});
};

// const
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x50e8cad4c59d9f0bu, 0xf9296b9719a86ecbu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x50e8cad4c59d9f0bu, 0xf9296b9719a86ecbu},
                                                ::pf::meta::ID{0x2edca832f52dd20cu, 0x1e76554f57a4b3f8u}> {};
// &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x73f004c4499413f6u, 0x95a835d24b633faeu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x73f004c4499413f6u, 0x95a835d24b633faeu},
                                               ::pf::meta::ID{0x2edca832f52dd20cu, 0x1e76554f57a4b3f8u}> {};
// &&
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8c65a2e3f57b30ccu, 0x413e31a1df046918u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x8c65a2e3f57b30ccu, 0x413e31a1df046918u},
                                               ::pf::meta::ID{0x2edca832f52dd20cu, 0x1e76554f57a4b3f8u}> {};
// const &
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3fc1b05c82f447f2u, 0x6a1b68b747246ae6u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x3fc1b05c82f447f2u, 0x6a1b68b747246ae6u},
                                               ::pf::meta::ID{0x50e8cad4c59d9f0bu, 0xf9296b9719a86ecbu}> {};
// *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb8da3535f82f4865u, 0x93dce1671982f824u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xb8da3535f82f4865u, 0x93dce1671982f824u},
                                              ::pf::meta::ID{0x2edca832f52dd20cu, 0x1e76554f57a4b3f8u}> {};
// const *
template <>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xda7e4749495066f0u, 0x76b5ddd6b7ff6fadu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xda7e4749495066f0u, 0x76b5ddd6b7ff6fadu},
                                              ::pf::meta::ID{0x50e8cad4c59d9f0bu, 0xf9296b9719a86ecbu}> {};

/****************************** pf::E9 END ******************************/
namespace pf::meta::details {
/****************************** pf::E9 START ******************************/
template <> [[nodiscard]] consteval ID getTypeId<pf::E9>() {
  return ::pf::meta::ID{0x2edca832f52dd20cu, 0x1e76554f57a4b3f8u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E9>() {
  return ::pf::meta::ID{0x50e8cad4c59d9f0bu, 0xf9296b9719a86ecbu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E9 &>() {
  return ::pf::meta::ID{0x73f004c4499413f6u, 0x95a835d24b633faeu};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E9 &&>() {
  return ::pf::meta::ID{0x8c65a2e3f57b30ccu, 0x413e31a1df046918u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E9 &>() {
  return ::pf::meta::ID{0x3fc1b05c82f447f2u, 0x6a1b68b747246ae6u};
}
template <> [[nodiscard]] consteval ID getTypeId<pf::E9 *>() {
  return ::pf::meta::ID{0xb8da3535f82f4865u, 0x93dce1671982f824u};
}
template <> [[nodiscard]] consteval ID getTypeId<const pf::E9 *>() {
  return ::pf::meta::ID{0xda7e4749495066f0u, 0x76b5ddd6b7ff6fadu};
}
/****************************** pf::E9 END ******************************/

/****************************** pf::E9::pf::E9::A START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E9::A>() {
  return ::pf::meta::ID{0xfa6f10d033b6d7d3u, 0xd853fa22cae4c4b1u};
}
/****************************** pf::E9::pf::E9::A END ******************************/

/****************************** pf::E9::pf::E9::B START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E9::B>() {
  return ::pf::meta::ID{0x660b1c5cc2c094eau, 0x7c80fbfd2640d154u};
}
/****************************** pf::E9::pf::E9::B END ******************************/

/****************************** pf::E9::pf::E9::C START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E9::C>() {
  return ::pf::meta::ID{0x4d3e10b2dc1477f1u, 0x86d2d78186e0896bu};
}
/****************************** pf::E9::pf::E9::C END ******************************/

/****************************** pf::E9::pf::E9::D START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E9::D>() {
  return ::pf::meta::ID{0x4207164816f484e3u, 0xb4341b2ab7ec42f6u};
}
/****************************** pf::E9::pf::E9::D END ******************************/

/****************************** pf::E9::pf::E9::E START ******************************/
template <> [[nodiscard]] consteval ID getConstantId<pf::E9::E>() {
  return ::pf::meta::ID{0x16a4736181146c4bu, 0x6878b16674a30527u};
}
/****************************** pf::E9::pf::E9::E END ******************************/
} // namespace pf::meta::details
