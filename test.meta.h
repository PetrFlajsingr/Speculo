
#pragma once

#include "meta/common.h"
#include "test.h"
#include <pf_common/array.h>
#include <pf_common/concepts/ranges.h>
#include <type_traits>

/****************************** pf::SomeEnum::Value1 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xfe8402588de925e7u, 0x4826ff24708315d4u}> {
    struct details {
        constexpr static auto ArgArray_10077978449667725865 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_3731169918163496404 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_12788202552857538376 = pf::make_array<std::string_view>();

    };
    constexpr static ID ValueID = pf::meta::ID{0xfe8402588de925e7u, 0x4826ff24708315d4u};
    constexpr static ID TypeID = pf::meta::ID{0xe02e66953b250098u, 0x7240c98366dad1f8u};
    using Type = pf::SomeEnum;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(pf::meta::Attribute{"test", std::span<const std::string_view>{details::ArgArray_10077978449667725865}}, pf::meta::Attribute{"test2", std::span<const std::string_view>{details::ArgArray_3731169918163496404}}, pf::meta::Attribute{"test3", std::span<const std::string_view>{details::ArgArray_12788202552857538376}});

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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x8515c6824cb80b96u, 0xcd9ee8ec8bd01c64u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x8515c6824cb80b96u, 0xcd9ee8ec8bd01c64u};
    constexpr static ID TypeID = pf::meta::ID{0xe02e66953b250098u, 0x7240c98366dad1f8u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0xe02e66953b250098u, 0x7240c98366dad1f8u}> {
    struct details {
        constexpr static auto ArgArray_2157388251370780934 = pf::make_array<std::string_view>(R"arg(()()()((())))arg", R"arg([[nodiscard]])arg", R"arg(1ll)arg", R"arg(1.011)arg", R"arg([]{}())arg", R"arg("yeet")arg", R"arg('a')arg", R"arg([][][]:::3214234...[][][][])arg");
constexpr static auto ArgArray_11228414200172369882 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_17620884152746328671 = pf::make_array<std::string_view>(R"arg(1ll)arg", R"arg(1.011)arg", R"arg("yeet")arg");
constexpr static auto ArgArray_1948293540628358545 = pf::make_array<std::string_view>();

    };
    using Type = pf::SomeEnum;
    constexpr static ID TypeID = pf::meta::ID{0xe02e66953b250098u, 0x7240c98366dad1f8u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(pf::meta::Attribute{"pf::operators", std::span<const std::string_view>{details::ArgArray_2157388251370780934}}, pf::meta::Attribute{"pf::hihi", std::span<const std::string_view>{details::ArgArray_11228414200172369882}}, pf::meta::Attribute{"pf::operators2", std::span<const std::string_view>{details::ArgArray_17620884152746328671}}, pf::meta::Attribute{"pf::hihi2", std::span<const std::string_view>{details::ArgArray_1948293540628358545}});

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0xfe8402588de925e7u, 0x4826ff24708315d4u}, pf::meta::ID{0x8515c6824cb80b96u, 0xcd9ee8ec8bd01c64u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xcd9c3b8481b76c00u, 0x629173af4622b829u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0xcd9c3b8481b76c00u, 0x629173af4622b829u}, pf::meta::ID{0xe02e66953b250098u, 0x7240c98366dad1f8u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xd3b78b1f72ac3e7au, 0x103362367d20d741u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0xd3b78b1f72ac3e7au, 0x103362367d20d741u}, pf::meta::ID{0xe02e66953b250098u, 0x7240c98366dad1f8u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xe0e30a5faa69055cu, 0xad568af37ef000au}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0xe0e30a5faa69055cu, 0xad568af37ef000au}, pf::meta::ID{0xe02e66953b250098u, 0x7240c98366dad1f8u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x28a88fc3d07a2a47u, 0x71ea5c91a516f7a9u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0x28a88fc3d07a2a47u, 0x71ea5c91a516f7a9u}, pf::meta::ID{0xe02e66953b250098u, 0x7240c98366dad1f8u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x8119cce83b8a2088u, 0xffb4b2c185271e28u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x8119cce83b8a2088u, 0xffb4b2c185271e28u}, pf::meta::ID{0xe02e66953b250098u, 0x7240c98366dad1f8u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x3daea3630470c3eu, 0x946a24e3b013c400u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0x3daea3630470c3eu, 0x946a24e3b013c400u}, pf::meta::ID{0xe02e66953b250098u, 0x7240c98366dad1f8u}> {};

/****************************** pf::SomeEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::SomeEnum START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum>() {
    return pf::meta::ID{0xe02e66953b250098u, 0x7240c98366dad1f8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum>() {
    return pf::meta::ID{0xcd9c3b8481b76c00u, 0x629173af4622b829u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum &>() {
    return pf::meta::ID{0xd3b78b1f72ac3e7au, 0x103362367d20d741u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum &&>() {
    return pf::meta::ID{0xe0e30a5faa69055cu, 0xad568af37ef000au};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum &>() {
    return pf::meta::ID{0x28a88fc3d07a2a47u, 0x71ea5c91a516f7a9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum *>() {
    return pf::meta::ID{0x8119cce83b8a2088u, 0xffb4b2c185271e28u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum *>() {
    return pf::meta::ID{0x3daea3630470c3eu, 0x946a24e3b013c400u};
}
/****************************** pf::SomeEnum END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value1 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value1>() {
return pf::meta::ID{0xfe8402588de925e7u, 0x4826ff24708315d4u};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value1 END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value2 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value2>() {
return pf::meta::ID{0x8515c6824cb80b96u, 0xcd9ee8ec8bd01c64u};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value2 END ******************************/
}
/****************************** pf::Test::E::Value1 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xb0d9a104d76b6890u, 0x47f91d34b153f3a4u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xb0d9a104d76b6890u, 0x47f91d34b153f3a4u};
    constexpr static ID TypeID = pf::meta::ID{0x277afc1c61de5941u, 0x37cc16193ffb1d35u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0xfce661865e690d54u, 0x50d7cb1b0ec68b1eu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xfce661865e690d54u, 0x50d7cb1b0ec68b1eu};
    constexpr static ID TypeID = pf::meta::ID{0x277afc1c61de5941u, 0x37cc16193ffb1d35u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x277afc1c61de5941u, 0x37cc16193ffb1d35u}> {
    struct details {
        
    };
    using Type = pf::Test::E;
    constexpr static ID TypeID = pf::meta::ID{0x277afc1c61de5941u, 0x37cc16193ffb1d35u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0xb0d9a104d76b6890u, 0x47f91d34b153f3a4u}, pf::meta::ID{0xfce661865e690d54u, 0x50d7cb1b0ec68b1eu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xd8a18195e5d6c9ddu, 0xe572b4d0af883c41u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0xd8a18195e5d6c9ddu, 0xe572b4d0af883c41u}, pf::meta::ID{0x277afc1c61de5941u, 0x37cc16193ffb1d35u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xc0ad9af477cdb7b6u, 0x99b19945d9a745a8u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0xc0ad9af477cdb7b6u, 0x99b19945d9a745a8u}, pf::meta::ID{0x277afc1c61de5941u, 0x37cc16193ffb1d35u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xb54ef2a9aa0584b6u, 0x2a375c1e7ed7d5b4u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0xb54ef2a9aa0584b6u, 0x2a375c1e7ed7d5b4u}, pf::meta::ID{0x277afc1c61de5941u, 0x37cc16193ffb1d35u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x1cdda050d68e8108u, 0x329e14141d6b2aa8u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0x1cdda050d68e8108u, 0x329e14141d6b2aa8u}, pf::meta::ID{0x277afc1c61de5941u, 0x37cc16193ffb1d35u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xfc28fc8c342fffccu, 0xe0e16c19a732ecf9u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0xfc28fc8c342fffccu, 0xe0e16c19a732ecf9u}, pf::meta::ID{0x277afc1c61de5941u, 0x37cc16193ffb1d35u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x1e45ccc675f845c1u, 0x531158bda7e543a1u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0x1e45ccc675f845c1u, 0x531158bda7e543a1u}, pf::meta::ID{0x277afc1c61de5941u, 0x37cc16193ffb1d35u}> {};

/****************************** pf::Test::E END ******************************/
namespace pf::meta::details {
/****************************** pf::Test::E START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E>() {
    return pf::meta::ID{0x277afc1c61de5941u, 0x37cc16193ffb1d35u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E>() {
    return pf::meta::ID{0xd8a18195e5d6c9ddu, 0xe572b4d0af883c41u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E &>() {
    return pf::meta::ID{0xc0ad9af477cdb7b6u, 0x99b19945d9a745a8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E &&>() {
    return pf::meta::ID{0xb54ef2a9aa0584b6u, 0x2a375c1e7ed7d5b4u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E &>() {
    return pf::meta::ID{0x1cdda050d68e8108u, 0x329e14141d6b2aa8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E *>() {
    return pf::meta::ID{0xfc28fc8c342fffccu, 0xe0e16c19a732ecf9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E *>() {
    return pf::meta::ID{0x1e45ccc675f845c1u, 0x531158bda7e543a1u};
}
/****************************** pf::Test::E END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value1 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::Test::E::Value1>() {
return pf::meta::ID{0xb0d9a104d76b6890u, 0x47f91d34b153f3a4u};
}
/****************************** pf::Test::E::pf::Test::E::Value1 END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value2 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::Test::E::Value2>() {
return pf::meta::ID{0xfce661865e690d54u, 0x50d7cb1b0ec68b1eu};
}
/****************************** pf::Test::E::pf::Test::E::Value2 END ******************************/
}
/****************************** pf::EmptyEnum START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x59b3ba7ee7eb568du, 0x863f80c9df5f2168u}> {
    struct details {
        
    };
    using Type = pf::EmptyEnum;
    constexpr static ID TypeID = pf::meta::ID{0x59b3ba7ee7eb568du, 0x863f80c9df5f2168u};

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
struct pf::meta::details::StaticInfo<pf::meta::ID{0xd2c6d21e5f76b316u, 0xc6d664c8e6a36de3u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0xd2c6d21e5f76b316u, 0xc6d664c8e6a36de3u}, pf::meta::ID{0x59b3ba7ee7eb568du, 0x863f80c9df5f2168u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x737ae2d5474581e5u, 0xca8fa0f919d31904u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0x737ae2d5474581e5u, 0xca8fa0f919d31904u}, pf::meta::ID{0x59b3ba7ee7eb568du, 0x863f80c9df5f2168u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x9dd4a1fae0e57f8cu, 0xfd3d972dc87a950du}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0x9dd4a1fae0e57f8cu, 0xfd3d972dc87a950du}, pf::meta::ID{0x59b3ba7ee7eb568du, 0x863f80c9df5f2168u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x75150f41d4ff5ac8u, 0x53d09c44c3a2c8acu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0x75150f41d4ff5ac8u, 0x53d09c44c3a2c8acu}, pf::meta::ID{0x59b3ba7ee7eb568du, 0x863f80c9df5f2168u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xec5e507c2831a50fu, 0xd63d606959f28b4u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0xec5e507c2831a50fu, 0xd63d606959f28b4u}, pf::meta::ID{0x59b3ba7ee7eb568du, 0x863f80c9df5f2168u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x219f6c388b7878c8u, 0xd4e9265625b86e72u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0x219f6c388b7878c8u, 0xd4e9265625b86e72u}, pf::meta::ID{0x59b3ba7ee7eb568du, 0x863f80c9df5f2168u}> {};

/****************************** pf::EmptyEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::EmptyEnum START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum>() {
    return pf::meta::ID{0x59b3ba7ee7eb568du, 0x863f80c9df5f2168u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum>() {
    return pf::meta::ID{0xd2c6d21e5f76b316u, 0xc6d664c8e6a36de3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &>() {
    return pf::meta::ID{0x737ae2d5474581e5u, 0xca8fa0f919d31904u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &&>() {
    return pf::meta::ID{0x9dd4a1fae0e57f8cu, 0xfd3d972dc87a950du};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum &>() {
    return pf::meta::ID{0x75150f41d4ff5ac8u, 0x53d09c44c3a2c8acu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum *>() {
    return pf::meta::ID{0xec5e507c2831a50fu, 0xd63d606959f28b4u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum *>() {
    return pf::meta::ID{0x219f6c388b7878c8u, 0xd4e9265625b86e72u};
}
/****************************** pf::EmptyEnum END ******************************/
}
/****************************** pf::E1::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xe7ea4baaa1715262u, 0xb95eb4ee38c08a21u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xe7ea4baaa1715262u, 0xb95eb4ee38c08a21u};
    constexpr static ID TypeID = pf::meta::ID{0x35bd42e5b76b5448u, 0x93add7dd4a812b3bu};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x449125f8c496d042u, 0xe10b4c02125300bcu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x449125f8c496d042u, 0xe10b4c02125300bcu};
    constexpr static ID TypeID = pf::meta::ID{0x35bd42e5b76b5448u, 0x93add7dd4a812b3bu};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x25370cdc80337cd3u, 0x71992c8bd0c25bcu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x25370cdc80337cd3u, 0x71992c8bd0c25bcu};
    constexpr static ID TypeID = pf::meta::ID{0x35bd42e5b76b5448u, 0x93add7dd4a812b3bu};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x4a9b407ebfe45f85u, 0x57d7596964f4a7bbu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x4a9b407ebfe45f85u, 0x57d7596964f4a7bbu};
    constexpr static ID TypeID = pf::meta::ID{0x35bd42e5b76b5448u, 0x93add7dd4a812b3bu};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7cd91313655b24a0u, 0xce4e283aca458b4bu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x7cd91313655b24a0u, 0xce4e283aca458b4bu};
    constexpr static ID TypeID = pf::meta::ID{0x35bd42e5b76b5448u, 0x93add7dd4a812b3bu};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x35bd42e5b76b5448u, 0x93add7dd4a812b3bu}> {
    struct details {
        
    };
    using Type = pf::E1;
    constexpr static ID TypeID = pf::meta::ID{0x35bd42e5b76b5448u, 0x93add7dd4a812b3bu};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0xe7ea4baaa1715262u, 0xb95eb4ee38c08a21u}, pf::meta::ID{0x449125f8c496d042u, 0xe10b4c02125300bcu}, pf::meta::ID{0x25370cdc80337cd3u, 0x71992c8bd0c25bcu}, pf::meta::ID{0x4a9b407ebfe45f85u, 0x57d7596964f4a7bbu}, pf::meta::ID{0x7cd91313655b24a0u, 0xce4e283aca458b4bu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x854a9677c166c74au, 0x55d14f38f49e241bu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0x854a9677c166c74au, 0x55d14f38f49e241bu}, pf::meta::ID{0x35bd42e5b76b5448u, 0x93add7dd4a812b3bu}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xfec4ee233631277bu, 0x48cda06aef84a902u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0xfec4ee233631277bu, 0x48cda06aef84a902u}, pf::meta::ID{0x35bd42e5b76b5448u, 0x93add7dd4a812b3bu}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x361e91ef49e063c8u, 0xe41219f233101847u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0x361e91ef49e063c8u, 0xe41219f233101847u}, pf::meta::ID{0x35bd42e5b76b5448u, 0x93add7dd4a812b3bu}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x51f30a0c38043b5au, 0xf47f3e6175541336u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0x51f30a0c38043b5au, 0xf47f3e6175541336u}, pf::meta::ID{0x35bd42e5b76b5448u, 0x93add7dd4a812b3bu}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x45e45ff1a276bdbau, 0xc302ac1a832e59ebu}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x45e45ff1a276bdbau, 0xc302ac1a832e59ebu}, pf::meta::ID{0x35bd42e5b76b5448u, 0x93add7dd4a812b3bu}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7dc9ba9a32f3ed07u, 0xd4a6558c43d777f3u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0x7dc9ba9a32f3ed07u, 0xd4a6558c43d777f3u}, pf::meta::ID{0x35bd42e5b76b5448u, 0x93add7dd4a812b3bu}> {};

/****************************** pf::E1 END ******************************/
namespace pf::meta::details {
/****************************** pf::E1 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1>() {
    return pf::meta::ID{0x35bd42e5b76b5448u, 0x93add7dd4a812b3bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1>() {
    return pf::meta::ID{0x854a9677c166c74au, 0x55d14f38f49e241bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 &>() {
    return pf::meta::ID{0xfec4ee233631277bu, 0x48cda06aef84a902u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 &&>() {
    return pf::meta::ID{0x361e91ef49e063c8u, 0xe41219f233101847u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1 &>() {
    return pf::meta::ID{0x51f30a0c38043b5au, 0xf47f3e6175541336u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 *>() {
    return pf::meta::ID{0x45e45ff1a276bdbau, 0xc302ac1a832e59ebu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1 *>() {
    return pf::meta::ID{0x7dc9ba9a32f3ed07u, 0xd4a6558c43d777f3u};
}
/****************************** pf::E1 END ******************************/

/****************************** pf::E1::pf::E1::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::A>() {
return pf::meta::ID{0xe7ea4baaa1715262u, 0xb95eb4ee38c08a21u};
}
/****************************** pf::E1::pf::E1::A END ******************************/

/****************************** pf::E1::pf::E1::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::B>() {
return pf::meta::ID{0x449125f8c496d042u, 0xe10b4c02125300bcu};
}
/****************************** pf::E1::pf::E1::B END ******************************/

/****************************** pf::E1::pf::E1::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::C>() {
return pf::meta::ID{0x25370cdc80337cd3u, 0x71992c8bd0c25bcu};
}
/****************************** pf::E1::pf::E1::C END ******************************/

/****************************** pf::E1::pf::E1::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::D>() {
return pf::meta::ID{0x4a9b407ebfe45f85u, 0x57d7596964f4a7bbu};
}
/****************************** pf::E1::pf::E1::D END ******************************/

/****************************** pf::E1::pf::E1::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::E>() {
return pf::meta::ID{0x7cd91313655b24a0u, 0xce4e283aca458b4bu};
}
/****************************** pf::E1::pf::E1::E END ******************************/
}
/****************************** pf::E2::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x3327f1cff3e583b9u, 0x864ce142d82ae359u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x3327f1cff3e583b9u, 0x864ce142d82ae359u};
    constexpr static ID TypeID = pf::meta::ID{0x128ae9bcfd69bd76u, 0xb28a1d50aa3bf000u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x94b0f30c61594f93u, 0x8e5f1ca92190faa0u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x94b0f30c61594f93u, 0x8e5f1ca92190faa0u};
    constexpr static ID TypeID = pf::meta::ID{0x128ae9bcfd69bd76u, 0xb28a1d50aa3bf000u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x355a21f5105a2715u, 0xcee3676319abad91u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x355a21f5105a2715u, 0xcee3676319abad91u};
    constexpr static ID TypeID = pf::meta::ID{0x128ae9bcfd69bd76u, 0xb28a1d50aa3bf000u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x102f642a9fa0574au, 0xcb985f40f9770857u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x102f642a9fa0574au, 0xcb985f40f9770857u};
    constexpr static ID TypeID = pf::meta::ID{0x128ae9bcfd69bd76u, 0xb28a1d50aa3bf000u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x1e02a19d5c0db998u, 0x6b9276407a1f75c2u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x1e02a19d5c0db998u, 0x6b9276407a1f75c2u};
    constexpr static ID TypeID = pf::meta::ID{0x128ae9bcfd69bd76u, 0xb28a1d50aa3bf000u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x128ae9bcfd69bd76u, 0xb28a1d50aa3bf000u}> {
    struct details {
        
    };
    using Type = pf::E2;
    constexpr static ID TypeID = pf::meta::ID{0x128ae9bcfd69bd76u, 0xb28a1d50aa3bf000u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0x3327f1cff3e583b9u, 0x864ce142d82ae359u}, pf::meta::ID{0x94b0f30c61594f93u, 0x8e5f1ca92190faa0u}, pf::meta::ID{0x355a21f5105a2715u, 0xcee3676319abad91u}, pf::meta::ID{0x102f642a9fa0574au, 0xcb985f40f9770857u}, pf::meta::ID{0x1e02a19d5c0db998u, 0x6b9276407a1f75c2u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7f8d0a2bf2bb6823u, 0xdb547bc976136b80u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0x7f8d0a2bf2bb6823u, 0xdb547bc976136b80u}, pf::meta::ID{0x128ae9bcfd69bd76u, 0xb28a1d50aa3bf000u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x4d4756ca6f0c296du, 0xe402384bc44c0bf1u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0x4d4756ca6f0c296du, 0xe402384bc44c0bf1u}, pf::meta::ID{0x128ae9bcfd69bd76u, 0xb28a1d50aa3bf000u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x3cc078afe318341cu, 0xb814ba430e503a65u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0x3cc078afe318341cu, 0xb814ba430e503a65u}, pf::meta::ID{0x128ae9bcfd69bd76u, 0xb28a1d50aa3bf000u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x9c5dbc43e2cbd316u, 0xc170258bf600c021u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0x9c5dbc43e2cbd316u, 0xc170258bf600c021u}, pf::meta::ID{0x128ae9bcfd69bd76u, 0xb28a1d50aa3bf000u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x5da0b054b03025deu, 0x36bf75aa716720dcu}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x5da0b054b03025deu, 0x36bf75aa716720dcu}, pf::meta::ID{0x128ae9bcfd69bd76u, 0xb28a1d50aa3bf000u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x3e346b4554d76a67u, 0xb609f8eeff0819e8u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0x3e346b4554d76a67u, 0xb609f8eeff0819e8u}, pf::meta::ID{0x128ae9bcfd69bd76u, 0xb28a1d50aa3bf000u}> {};

/****************************** pf::E2 END ******************************/
namespace pf::meta::details {
/****************************** pf::E2 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2>() {
    return pf::meta::ID{0x128ae9bcfd69bd76u, 0xb28a1d50aa3bf000u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2>() {
    return pf::meta::ID{0x7f8d0a2bf2bb6823u, 0xdb547bc976136b80u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 &>() {
    return pf::meta::ID{0x4d4756ca6f0c296du, 0xe402384bc44c0bf1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 &&>() {
    return pf::meta::ID{0x3cc078afe318341cu, 0xb814ba430e503a65u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2 &>() {
    return pf::meta::ID{0x9c5dbc43e2cbd316u, 0xc170258bf600c021u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 *>() {
    return pf::meta::ID{0x5da0b054b03025deu, 0x36bf75aa716720dcu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2 *>() {
    return pf::meta::ID{0x3e346b4554d76a67u, 0xb609f8eeff0819e8u};
}
/****************************** pf::E2 END ******************************/

/****************************** pf::E2::pf::E2::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::A>() {
return pf::meta::ID{0x3327f1cff3e583b9u, 0x864ce142d82ae359u};
}
/****************************** pf::E2::pf::E2::A END ******************************/

/****************************** pf::E2::pf::E2::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::B>() {
return pf::meta::ID{0x94b0f30c61594f93u, 0x8e5f1ca92190faa0u};
}
/****************************** pf::E2::pf::E2::B END ******************************/

/****************************** pf::E2::pf::E2::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::C>() {
return pf::meta::ID{0x355a21f5105a2715u, 0xcee3676319abad91u};
}
/****************************** pf::E2::pf::E2::C END ******************************/

/****************************** pf::E2::pf::E2::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::D>() {
return pf::meta::ID{0x102f642a9fa0574au, 0xcb985f40f9770857u};
}
/****************************** pf::E2::pf::E2::D END ******************************/

/****************************** pf::E2::pf::E2::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::E>() {
return pf::meta::ID{0x1e02a19d5c0db998u, 0x6b9276407a1f75c2u};
}
/****************************** pf::E2::pf::E2::E END ******************************/
}
/****************************** pf::E3::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xcd125d31c04066fu, 0x9b43efa65330d2a6u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xcd125d31c04066fu, 0x9b43efa65330d2a6u};
    constexpr static ID TypeID = pf::meta::ID{0x690842604e5f93e0u, 0xf5e6f07327ebb8a5u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x1272d86aaf64532cu, 0xe9f2a3d2cadb0b8fu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x1272d86aaf64532cu, 0xe9f2a3d2cadb0b8fu};
    constexpr static ID TypeID = pf::meta::ID{0x690842604e5f93e0u, 0xf5e6f07327ebb8a5u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x27fc328664b48100u, 0xbb8975850ffdf35bu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x27fc328664b48100u, 0xbb8975850ffdf35bu};
    constexpr static ID TypeID = pf::meta::ID{0x690842604e5f93e0u, 0xf5e6f07327ebb8a5u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0xbdcd877f370e533u, 0x142f2e30069a33a2u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xbdcd877f370e533u, 0x142f2e30069a33a2u};
    constexpr static ID TypeID = pf::meta::ID{0x690842604e5f93e0u, 0xf5e6f07327ebb8a5u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x767aa8f6a1443cbfu, 0xdcf65b15a8c94660u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x767aa8f6a1443cbfu, 0xdcf65b15a8c94660u};
    constexpr static ID TypeID = pf::meta::ID{0x690842604e5f93e0u, 0xf5e6f07327ebb8a5u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x690842604e5f93e0u, 0xf5e6f07327ebb8a5u}> {
    struct details {
        
    };
    using Type = pf::E3;
    constexpr static ID TypeID = pf::meta::ID{0x690842604e5f93e0u, 0xf5e6f07327ebb8a5u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0xcd125d31c04066fu, 0x9b43efa65330d2a6u}, pf::meta::ID{0x1272d86aaf64532cu, 0xe9f2a3d2cadb0b8fu}, pf::meta::ID{0x27fc328664b48100u, 0xbb8975850ffdf35bu}, pf::meta::ID{0xbdcd877f370e533u, 0x142f2e30069a33a2u}, pf::meta::ID{0x767aa8f6a1443cbfu, 0xdcf65b15a8c94660u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x58d2bcf4abcc1fe0u, 0xd0f0f90010488a12u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0x58d2bcf4abcc1fe0u, 0xd0f0f90010488a12u}, pf::meta::ID{0x690842604e5f93e0u, 0xf5e6f07327ebb8a5u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xd84064f05f785329u, 0x867261c52dfd748fu}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0xd84064f05f785329u, 0x867261c52dfd748fu}, pf::meta::ID{0x690842604e5f93e0u, 0xf5e6f07327ebb8a5u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xb729206b6df4f0e9u, 0x5a14b5c5ad082ca0u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0xb729206b6df4f0e9u, 0x5a14b5c5ad082ca0u}, pf::meta::ID{0x690842604e5f93e0u, 0xf5e6f07327ebb8a5u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x55c46bea824237eeu, 0xa96f2c3297741a3fu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0x55c46bea824237eeu, 0xa96f2c3297741a3fu}, pf::meta::ID{0x690842604e5f93e0u, 0xf5e6f07327ebb8a5u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x4334a64d41da7201u, 0x1a57be128d2f4451u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x4334a64d41da7201u, 0x1a57be128d2f4451u}, pf::meta::ID{0x690842604e5f93e0u, 0xf5e6f07327ebb8a5u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xa8a4e7a5619eb592u, 0xeb3a93bde3e8ea2cu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0xa8a4e7a5619eb592u, 0xeb3a93bde3e8ea2cu}, pf::meta::ID{0x690842604e5f93e0u, 0xf5e6f07327ebb8a5u}> {};

/****************************** pf::E3 END ******************************/
namespace pf::meta::details {
/****************************** pf::E3 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3>() {
    return pf::meta::ID{0x690842604e5f93e0u, 0xf5e6f07327ebb8a5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3>() {
    return pf::meta::ID{0x58d2bcf4abcc1fe0u, 0xd0f0f90010488a12u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 &>() {
    return pf::meta::ID{0xd84064f05f785329u, 0x867261c52dfd748fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 &&>() {
    return pf::meta::ID{0xb729206b6df4f0e9u, 0x5a14b5c5ad082ca0u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3 &>() {
    return pf::meta::ID{0x55c46bea824237eeu, 0xa96f2c3297741a3fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 *>() {
    return pf::meta::ID{0x4334a64d41da7201u, 0x1a57be128d2f4451u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3 *>() {
    return pf::meta::ID{0xa8a4e7a5619eb592u, 0xeb3a93bde3e8ea2cu};
}
/****************************** pf::E3 END ******************************/

/****************************** pf::E3::pf::E3::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::A>() {
return pf::meta::ID{0xcd125d31c04066fu, 0x9b43efa65330d2a6u};
}
/****************************** pf::E3::pf::E3::A END ******************************/

/****************************** pf::E3::pf::E3::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::B>() {
return pf::meta::ID{0x1272d86aaf64532cu, 0xe9f2a3d2cadb0b8fu};
}
/****************************** pf::E3::pf::E3::B END ******************************/

/****************************** pf::E3::pf::E3::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::C>() {
return pf::meta::ID{0x27fc328664b48100u, 0xbb8975850ffdf35bu};
}
/****************************** pf::E3::pf::E3::C END ******************************/

/****************************** pf::E3::pf::E3::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::D>() {
return pf::meta::ID{0xbdcd877f370e533u, 0x142f2e30069a33a2u};
}
/****************************** pf::E3::pf::E3::D END ******************************/

/****************************** pf::E3::pf::E3::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::E>() {
return pf::meta::ID{0x767aa8f6a1443cbfu, 0xdcf65b15a8c94660u};
}
/****************************** pf::E3::pf::E3::E END ******************************/
}
/****************************** pf::E4::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x3dea5a4a2f1eab6fu, 0x2595cc957869c9d4u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x3dea5a4a2f1eab6fu, 0x2595cc957869c9d4u};
    constexpr static ID TypeID = pf::meta::ID{0x6ab1b840684ce0fdu, 0x20a347d128c86992u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x5d330b31f16af274u, 0x47d6342c2120874fu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x5d330b31f16af274u, 0x47d6342c2120874fu};
    constexpr static ID TypeID = pf::meta::ID{0x6ab1b840684ce0fdu, 0x20a347d128c86992u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x882e7b967af4eec4u, 0x808230facef57616u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x882e7b967af4eec4u, 0x808230facef57616u};
    constexpr static ID TypeID = pf::meta::ID{0x6ab1b840684ce0fdu, 0x20a347d128c86992u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x329167c6cdfe1389u, 0xd883e6b226ad9371u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x329167c6cdfe1389u, 0xd883e6b226ad9371u};
    constexpr static ID TypeID = pf::meta::ID{0x6ab1b840684ce0fdu, 0x20a347d128c86992u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0xbe301daa6ab2b45eu, 0xd8ae2adf993c5deu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xbe301daa6ab2b45eu, 0xd8ae2adf993c5deu};
    constexpr static ID TypeID = pf::meta::ID{0x6ab1b840684ce0fdu, 0x20a347d128c86992u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x6ab1b840684ce0fdu, 0x20a347d128c86992u}> {
    struct details {
        
    };
    using Type = pf::E4;
    constexpr static ID TypeID = pf::meta::ID{0x6ab1b840684ce0fdu, 0x20a347d128c86992u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0x3dea5a4a2f1eab6fu, 0x2595cc957869c9d4u}, pf::meta::ID{0x5d330b31f16af274u, 0x47d6342c2120874fu}, pf::meta::ID{0x882e7b967af4eec4u, 0x808230facef57616u}, pf::meta::ID{0x329167c6cdfe1389u, 0xd883e6b226ad9371u}, pf::meta::ID{0xbe301daa6ab2b45eu, 0xd8ae2adf993c5deu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x61b4cd332aec456cu, 0xc6eb3e689737ca63u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0x61b4cd332aec456cu, 0xc6eb3e689737ca63u}, pf::meta::ID{0x6ab1b840684ce0fdu, 0x20a347d128c86992u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x321cfe72880ffec4u, 0x68dafa6b523e6b1cu}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0x321cfe72880ffec4u, 0x68dafa6b523e6b1cu}, pf::meta::ID{0x6ab1b840684ce0fdu, 0x20a347d128c86992u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x3238701cdeacd58eu, 0x55a9a4105939a4bbu}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0x3238701cdeacd58eu, 0x55a9a4105939a4bbu}, pf::meta::ID{0x6ab1b840684ce0fdu, 0x20a347d128c86992u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xcb53d600bb9ecd1eu, 0xea67faf394d773e2u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0xcb53d600bb9ecd1eu, 0xea67faf394d773e2u}, pf::meta::ID{0x6ab1b840684ce0fdu, 0x20a347d128c86992u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x4e5a7582147715b9u, 0x826fa48aa5da888cu}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x4e5a7582147715b9u, 0x826fa48aa5da888cu}, pf::meta::ID{0x6ab1b840684ce0fdu, 0x20a347d128c86992u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x9be8d43d42c34352u, 0x9dc09fcd9b2f5e1u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0x9be8d43d42c34352u, 0x9dc09fcd9b2f5e1u}, pf::meta::ID{0x6ab1b840684ce0fdu, 0x20a347d128c86992u}> {};

/****************************** pf::E4 END ******************************/
namespace pf::meta::details {
/****************************** pf::E4 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4>() {
    return pf::meta::ID{0x6ab1b840684ce0fdu, 0x20a347d128c86992u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4>() {
    return pf::meta::ID{0x61b4cd332aec456cu, 0xc6eb3e689737ca63u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 &>() {
    return pf::meta::ID{0x321cfe72880ffec4u, 0x68dafa6b523e6b1cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 &&>() {
    return pf::meta::ID{0x3238701cdeacd58eu, 0x55a9a4105939a4bbu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4 &>() {
    return pf::meta::ID{0xcb53d600bb9ecd1eu, 0xea67faf394d773e2u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 *>() {
    return pf::meta::ID{0x4e5a7582147715b9u, 0x826fa48aa5da888cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4 *>() {
    return pf::meta::ID{0x9be8d43d42c34352u, 0x9dc09fcd9b2f5e1u};
}
/****************************** pf::E4 END ******************************/

/****************************** pf::E4::pf::E4::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::A>() {
return pf::meta::ID{0x3dea5a4a2f1eab6fu, 0x2595cc957869c9d4u};
}
/****************************** pf::E4::pf::E4::A END ******************************/

/****************************** pf::E4::pf::E4::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::B>() {
return pf::meta::ID{0x5d330b31f16af274u, 0x47d6342c2120874fu};
}
/****************************** pf::E4::pf::E4::B END ******************************/

/****************************** pf::E4::pf::E4::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::C>() {
return pf::meta::ID{0x882e7b967af4eec4u, 0x808230facef57616u};
}
/****************************** pf::E4::pf::E4::C END ******************************/

/****************************** pf::E4::pf::E4::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::D>() {
return pf::meta::ID{0x329167c6cdfe1389u, 0xd883e6b226ad9371u};
}
/****************************** pf::E4::pf::E4::D END ******************************/

/****************************** pf::E4::pf::E4::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::E>() {
return pf::meta::ID{0xbe301daa6ab2b45eu, 0xd8ae2adf993c5deu};
}
/****************************** pf::E4::pf::E4::E END ******************************/
}
/****************************** pf::E5::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x5b050a06a1681042u, 0xf81b777997222c8eu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x5b050a06a1681042u, 0xf81b777997222c8eu};
    constexpr static ID TypeID = pf::meta::ID{0xa380db69cf8725d0u, 0xe1222444e994bbe9u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x97bb98696a4bb944u, 0x895fa468cb1989f0u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x97bb98696a4bb944u, 0x895fa468cb1989f0u};
    constexpr static ID TypeID = pf::meta::ID{0xa380db69cf8725d0u, 0xe1222444e994bbe9u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x25e88baed59efa22u, 0x883185920f9eb4f3u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x25e88baed59efa22u, 0x883185920f9eb4f3u};
    constexpr static ID TypeID = pf::meta::ID{0xa380db69cf8725d0u, 0xe1222444e994bbe9u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x3cadd132867370f1u, 0x5cf782cd023500acu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x3cadd132867370f1u, 0x5cf782cd023500acu};
    constexpr static ID TypeID = pf::meta::ID{0xa380db69cf8725d0u, 0xe1222444e994bbe9u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x6d69096d104d4e82u, 0xb3daa6b29dccd63cu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x6d69096d104d4e82u, 0xb3daa6b29dccd63cu};
    constexpr static ID TypeID = pf::meta::ID{0xa380db69cf8725d0u, 0xe1222444e994bbe9u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0xa380db69cf8725d0u, 0xe1222444e994bbe9u}> {
    struct details {
        
    };
    using Type = pf::E5;
    constexpr static ID TypeID = pf::meta::ID{0xa380db69cf8725d0u, 0xe1222444e994bbe9u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0x5b050a06a1681042u, 0xf81b777997222c8eu}, pf::meta::ID{0x97bb98696a4bb944u, 0x895fa468cb1989f0u}, pf::meta::ID{0x25e88baed59efa22u, 0x883185920f9eb4f3u}, pf::meta::ID{0x3cadd132867370f1u, 0x5cf782cd023500acu}, pf::meta::ID{0x6d69096d104d4e82u, 0xb3daa6b29dccd63cu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x117ac81f4740d3f2u, 0xd5a807d66f2e1e78u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0x117ac81f4740d3f2u, 0xd5a807d66f2e1e78u}, pf::meta::ID{0xa380db69cf8725d0u, 0xe1222444e994bbe9u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x6369928dd9bd49f0u, 0x768eea13756ff219u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0x6369928dd9bd49f0u, 0x768eea13756ff219u}, pf::meta::ID{0xa380db69cf8725d0u, 0xe1222444e994bbe9u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xcb3476a666d25aa4u, 0x968ba818d646c5e0u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0xcb3476a666d25aa4u, 0x968ba818d646c5e0u}, pf::meta::ID{0xa380db69cf8725d0u, 0xe1222444e994bbe9u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xbec0226544216bc3u, 0xcb2b7de22d6f3cecu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0xbec0226544216bc3u, 0xcb2b7de22d6f3cecu}, pf::meta::ID{0xa380db69cf8725d0u, 0xe1222444e994bbe9u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x8a9805efe20b94e4u, 0x54f04650bf0af891u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x8a9805efe20b94e4u, 0x54f04650bf0af891u}, pf::meta::ID{0xa380db69cf8725d0u, 0xe1222444e994bbe9u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x99fa6526d6377375u, 0x7786f76462138e65u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0x99fa6526d6377375u, 0x7786f76462138e65u}, pf::meta::ID{0xa380db69cf8725d0u, 0xe1222444e994bbe9u}> {};

/****************************** pf::E5 END ******************************/
namespace pf::meta::details {
/****************************** pf::E5 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5>() {
    return pf::meta::ID{0xa380db69cf8725d0u, 0xe1222444e994bbe9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5>() {
    return pf::meta::ID{0x117ac81f4740d3f2u, 0xd5a807d66f2e1e78u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 &>() {
    return pf::meta::ID{0x6369928dd9bd49f0u, 0x768eea13756ff219u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 &&>() {
    return pf::meta::ID{0xcb3476a666d25aa4u, 0x968ba818d646c5e0u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5 &>() {
    return pf::meta::ID{0xbec0226544216bc3u, 0xcb2b7de22d6f3cecu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 *>() {
    return pf::meta::ID{0x8a9805efe20b94e4u, 0x54f04650bf0af891u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5 *>() {
    return pf::meta::ID{0x99fa6526d6377375u, 0x7786f76462138e65u};
}
/****************************** pf::E5 END ******************************/

/****************************** pf::E5::pf::E5::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::A>() {
return pf::meta::ID{0x5b050a06a1681042u, 0xf81b777997222c8eu};
}
/****************************** pf::E5::pf::E5::A END ******************************/

/****************************** pf::E5::pf::E5::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::B>() {
return pf::meta::ID{0x97bb98696a4bb944u, 0x895fa468cb1989f0u};
}
/****************************** pf::E5::pf::E5::B END ******************************/

/****************************** pf::E5::pf::E5::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::C>() {
return pf::meta::ID{0x25e88baed59efa22u, 0x883185920f9eb4f3u};
}
/****************************** pf::E5::pf::E5::C END ******************************/

/****************************** pf::E5::pf::E5::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::D>() {
return pf::meta::ID{0x3cadd132867370f1u, 0x5cf782cd023500acu};
}
/****************************** pf::E5::pf::E5::D END ******************************/

/****************************** pf::E5::pf::E5::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::E>() {
return pf::meta::ID{0x6d69096d104d4e82u, 0xb3daa6b29dccd63cu};
}
/****************************** pf::E5::pf::E5::E END ******************************/
}
/****************************** pf::E6::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x35d4db8340e280bau, 0xe6d2149eb673101fu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x35d4db8340e280bau, 0xe6d2149eb673101fu};
    constexpr static ID TypeID = pf::meta::ID{0x4ee2bae06e9b5c2eu, 0xc89fad22e6b93831u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x6337e719731d6687u, 0x9de7f9804016f810u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x6337e719731d6687u, 0x9de7f9804016f810u};
    constexpr static ID TypeID = pf::meta::ID{0x4ee2bae06e9b5c2eu, 0xc89fad22e6b93831u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x26d143de9fa561a1u, 0x596ca5823f7cc67fu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x26d143de9fa561a1u, 0x596ca5823f7cc67fu};
    constexpr static ID TypeID = pf::meta::ID{0x4ee2bae06e9b5c2eu, 0xc89fad22e6b93831u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x2c101a8b1d8e9f4du, 0x8ee7b9d391de4c6fu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x2c101a8b1d8e9f4du, 0x8ee7b9d391de4c6fu};
    constexpr static ID TypeID = pf::meta::ID{0x4ee2bae06e9b5c2eu, 0xc89fad22e6b93831u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0xc4e851a0f54ec7c9u, 0x852305975654b1bdu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xc4e851a0f54ec7c9u, 0x852305975654b1bdu};
    constexpr static ID TypeID = pf::meta::ID{0x4ee2bae06e9b5c2eu, 0xc89fad22e6b93831u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x4ee2bae06e9b5c2eu, 0xc89fad22e6b93831u}> {
    struct details {
        
    };
    using Type = pf::E6;
    constexpr static ID TypeID = pf::meta::ID{0x4ee2bae06e9b5c2eu, 0xc89fad22e6b93831u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0x35d4db8340e280bau, 0xe6d2149eb673101fu}, pf::meta::ID{0x6337e719731d6687u, 0x9de7f9804016f810u}, pf::meta::ID{0x26d143de9fa561a1u, 0x596ca5823f7cc67fu}, pf::meta::ID{0x2c101a8b1d8e9f4du, 0x8ee7b9d391de4c6fu}, pf::meta::ID{0xc4e851a0f54ec7c9u, 0x852305975654b1bdu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xe19dc613621efa6au, 0x12006605ca2949ccu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0xe19dc613621efa6au, 0x12006605ca2949ccu}, pf::meta::ID{0x4ee2bae06e9b5c2eu, 0xc89fad22e6b93831u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x2d1eefb7028d4b82u, 0xe2525714fe036344u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0x2d1eefb7028d4b82u, 0xe2525714fe036344u}, pf::meta::ID{0x4ee2bae06e9b5c2eu, 0xc89fad22e6b93831u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x5b3986ad243d0fbu, 0x7d335537a74d01f5u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0x5b3986ad243d0fbu, 0x7d335537a74d01f5u}, pf::meta::ID{0x4ee2bae06e9b5c2eu, 0xc89fad22e6b93831u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x20924f8ae6cb97a6u, 0x549fd2d637e89319u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0x20924f8ae6cb97a6u, 0x549fd2d637e89319u}, pf::meta::ID{0x4ee2bae06e9b5c2eu, 0xc89fad22e6b93831u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x194d7e7a3434bf08u, 0x4a83a536683f508du}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x194d7e7a3434bf08u, 0x4a83a536683f508du}, pf::meta::ID{0x4ee2bae06e9b5c2eu, 0xc89fad22e6b93831u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x5741dadf747c730u, 0x5dc880f0da37915u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0x5741dadf747c730u, 0x5dc880f0da37915u}, pf::meta::ID{0x4ee2bae06e9b5c2eu, 0xc89fad22e6b93831u}> {};

/****************************** pf::E6 END ******************************/
namespace pf::meta::details {
/****************************** pf::E6 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6>() {
    return pf::meta::ID{0x4ee2bae06e9b5c2eu, 0xc89fad22e6b93831u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6>() {
    return pf::meta::ID{0xe19dc613621efa6au, 0x12006605ca2949ccu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 &>() {
    return pf::meta::ID{0x2d1eefb7028d4b82u, 0xe2525714fe036344u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 &&>() {
    return pf::meta::ID{0x5b3986ad243d0fbu, 0x7d335537a74d01f5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6 &>() {
    return pf::meta::ID{0x20924f8ae6cb97a6u, 0x549fd2d637e89319u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 *>() {
    return pf::meta::ID{0x194d7e7a3434bf08u, 0x4a83a536683f508du};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6 *>() {
    return pf::meta::ID{0x5741dadf747c730u, 0x5dc880f0da37915u};
}
/****************************** pf::E6 END ******************************/

/****************************** pf::E6::pf::E6::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::A>() {
return pf::meta::ID{0x35d4db8340e280bau, 0xe6d2149eb673101fu};
}
/****************************** pf::E6::pf::E6::A END ******************************/

/****************************** pf::E6::pf::E6::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::B>() {
return pf::meta::ID{0x6337e719731d6687u, 0x9de7f9804016f810u};
}
/****************************** pf::E6::pf::E6::B END ******************************/

/****************************** pf::E6::pf::E6::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::C>() {
return pf::meta::ID{0x26d143de9fa561a1u, 0x596ca5823f7cc67fu};
}
/****************************** pf::E6::pf::E6::C END ******************************/

/****************************** pf::E6::pf::E6::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::D>() {
return pf::meta::ID{0x2c101a8b1d8e9f4du, 0x8ee7b9d391de4c6fu};
}
/****************************** pf::E6::pf::E6::D END ******************************/

/****************************** pf::E6::pf::E6::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::E>() {
return pf::meta::ID{0xc4e851a0f54ec7c9u, 0x852305975654b1bdu};
}
/****************************** pf::E6::pf::E6::E END ******************************/
}
/****************************** pf::E7::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x5988a38a9e0e3c8u, 0x4a6f24d6a8f0207au}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x5988a38a9e0e3c8u, 0x4a6f24d6a8f0207au};
    constexpr static ID TypeID = pf::meta::ID{0xa23b6c2d83f09f0fu, 0x12902bd79bf413eeu};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x73f9a3032b92f3ddu, 0x6d8e9f8eddcff253u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x73f9a3032b92f3ddu, 0x6d8e9f8eddcff253u};
    constexpr static ID TypeID = pf::meta::ID{0xa23b6c2d83f09f0fu, 0x12902bd79bf413eeu};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x589985450ca41eddu, 0x7291781d431d7efbu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x589985450ca41eddu, 0x7291781d431d7efbu};
    constexpr static ID TypeID = pf::meta::ID{0xa23b6c2d83f09f0fu, 0x12902bd79bf413eeu};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0xb81cdf455b6cc66eu, 0xf8e6746c7eeda332u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xb81cdf455b6cc66eu, 0xf8e6746c7eeda332u};
    constexpr static ID TypeID = pf::meta::ID{0xa23b6c2d83f09f0fu, 0x12902bd79bf413eeu};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7412f980d47b9ab1u, 0x3685557ea1b8a2d5u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x7412f980d47b9ab1u, 0x3685557ea1b8a2d5u};
    constexpr static ID TypeID = pf::meta::ID{0xa23b6c2d83f09f0fu, 0x12902bd79bf413eeu};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0xa23b6c2d83f09f0fu, 0x12902bd79bf413eeu}> {
    struct details {
        
    };
    using Type = pf::E7;
    constexpr static ID TypeID = pf::meta::ID{0xa23b6c2d83f09f0fu, 0x12902bd79bf413eeu};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0x5988a38a9e0e3c8u, 0x4a6f24d6a8f0207au}, pf::meta::ID{0x73f9a3032b92f3ddu, 0x6d8e9f8eddcff253u}, pf::meta::ID{0x589985450ca41eddu, 0x7291781d431d7efbu}, pf::meta::ID{0xb81cdf455b6cc66eu, 0xf8e6746c7eeda332u}, pf::meta::ID{0x7412f980d47b9ab1u, 0x3685557ea1b8a2d5u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xb24f3638ea60c2au, 0xbed0469b943d6cb0u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0xb24f3638ea60c2au, 0xbed0469b943d6cb0u}, pf::meta::ID{0xa23b6c2d83f09f0fu, 0x12902bd79bf413eeu}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xe572c370a04b950u, 0x977704a9828d5070u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0xe572c370a04b950u, 0x977704a9828d5070u}, pf::meta::ID{0xa23b6c2d83f09f0fu, 0x12902bd79bf413eeu}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x46961039e54b847au, 0xc34c43d6022067bfu}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0x46961039e54b847au, 0xc34c43d6022067bfu}, pf::meta::ID{0xa23b6c2d83f09f0fu, 0x12902bd79bf413eeu}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xcd0234a7c38a667du, 0x508a31d9cfa6b821u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0xcd0234a7c38a667du, 0x508a31d9cfa6b821u}, pf::meta::ID{0xa23b6c2d83f09f0fu, 0x12902bd79bf413eeu}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x490a34eaa49d2e8bu, 0x39d185be4e6358au}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x490a34eaa49d2e8bu, 0x39d185be4e6358au}, pf::meta::ID{0xa23b6c2d83f09f0fu, 0x12902bd79bf413eeu}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x9b2d7d9d1a9fae26u, 0x4094c09e91dc0547u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0x9b2d7d9d1a9fae26u, 0x4094c09e91dc0547u}, pf::meta::ID{0xa23b6c2d83f09f0fu, 0x12902bd79bf413eeu}> {};

/****************************** pf::E7 END ******************************/
namespace pf::meta::details {
/****************************** pf::E7 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7>() {
    return pf::meta::ID{0xa23b6c2d83f09f0fu, 0x12902bd79bf413eeu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7>() {
    return pf::meta::ID{0xb24f3638ea60c2au, 0xbed0469b943d6cb0u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 &>() {
    return pf::meta::ID{0xe572c370a04b950u, 0x977704a9828d5070u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 &&>() {
    return pf::meta::ID{0x46961039e54b847au, 0xc34c43d6022067bfu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7 &>() {
    return pf::meta::ID{0xcd0234a7c38a667du, 0x508a31d9cfa6b821u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 *>() {
    return pf::meta::ID{0x490a34eaa49d2e8bu, 0x39d185be4e6358au};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7 *>() {
    return pf::meta::ID{0x9b2d7d9d1a9fae26u, 0x4094c09e91dc0547u};
}
/****************************** pf::E7 END ******************************/

/****************************** pf::E7::pf::E7::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::A>() {
return pf::meta::ID{0x5988a38a9e0e3c8u, 0x4a6f24d6a8f0207au};
}
/****************************** pf::E7::pf::E7::A END ******************************/

/****************************** pf::E7::pf::E7::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::B>() {
return pf::meta::ID{0x73f9a3032b92f3ddu, 0x6d8e9f8eddcff253u};
}
/****************************** pf::E7::pf::E7::B END ******************************/

/****************************** pf::E7::pf::E7::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::C>() {
return pf::meta::ID{0x589985450ca41eddu, 0x7291781d431d7efbu};
}
/****************************** pf::E7::pf::E7::C END ******************************/

/****************************** pf::E7::pf::E7::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::D>() {
return pf::meta::ID{0xb81cdf455b6cc66eu, 0xf8e6746c7eeda332u};
}
/****************************** pf::E7::pf::E7::D END ******************************/

/****************************** pf::E7::pf::E7::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::E>() {
return pf::meta::ID{0x7412f980d47b9ab1u, 0x3685557ea1b8a2d5u};
}
/****************************** pf::E7::pf::E7::E END ******************************/
}
/****************************** pf::E8::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xba3aedb582bb65acu, 0x9911628e1ee03ca7u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xba3aedb582bb65acu, 0x9911628e1ee03ca7u};
    constexpr static ID TypeID = pf::meta::ID{0x8878d2b99e1bda02u, 0x92495ea412152df6u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x9ebbfeed29ae1919u, 0x27c611f2624314bbu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x9ebbfeed29ae1919u, 0x27c611f2624314bbu};
    constexpr static ID TypeID = pf::meta::ID{0x8878d2b99e1bda02u, 0x92495ea412152df6u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x876f2012865b04d3u, 0x6114a92879b5fa8cu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x876f2012865b04d3u, 0x6114a92879b5fa8cu};
    constexpr static ID TypeID = pf::meta::ID{0x8878d2b99e1bda02u, 0x92495ea412152df6u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0xef669b685a5dc628u, 0xc009761612746c41u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xef669b685a5dc628u, 0xc009761612746c41u};
    constexpr static ID TypeID = pf::meta::ID{0x8878d2b99e1bda02u, 0x92495ea412152df6u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x244a246736f6934eu, 0xbe818d0464443817u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x244a246736f6934eu, 0xbe818d0464443817u};
    constexpr static ID TypeID = pf::meta::ID{0x8878d2b99e1bda02u, 0x92495ea412152df6u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x8878d2b99e1bda02u, 0x92495ea412152df6u}> {
    struct details {
        
    };
    using Type = pf::E8;
    constexpr static ID TypeID = pf::meta::ID{0x8878d2b99e1bda02u, 0x92495ea412152df6u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0xba3aedb582bb65acu, 0x9911628e1ee03ca7u}, pf::meta::ID{0x9ebbfeed29ae1919u, 0x27c611f2624314bbu}, pf::meta::ID{0x876f2012865b04d3u, 0x6114a92879b5fa8cu}, pf::meta::ID{0xef669b685a5dc628u, 0xc009761612746c41u}, pf::meta::ID{0x244a246736f6934eu, 0xbe818d0464443817u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x1d0c5306fef24145u, 0x834344e951270f78u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0x1d0c5306fef24145u, 0x834344e951270f78u}, pf::meta::ID{0x8878d2b99e1bda02u, 0x92495ea412152df6u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xb758b420fe6a485du, 0xa5569bcf4dcaa2beu}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0xb758b420fe6a485du, 0xa5569bcf4dcaa2beu}, pf::meta::ID{0x8878d2b99e1bda02u, 0x92495ea412152df6u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x6915dd75d1cbe975u, 0x44583a315be566f4u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0x6915dd75d1cbe975u, 0x44583a315be566f4u}, pf::meta::ID{0x8878d2b99e1bda02u, 0x92495ea412152df6u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xe14c0d96d88eae5au, 0xaf6d691137b30ac6u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0xe14c0d96d88eae5au, 0xaf6d691137b30ac6u}, pf::meta::ID{0x8878d2b99e1bda02u, 0x92495ea412152df6u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x30b3d391adccfffcu, 0xd0ac967baeedbd6cu}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x30b3d391adccfffcu, 0xd0ac967baeedbd6cu}, pf::meta::ID{0x8878d2b99e1bda02u, 0x92495ea412152df6u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xfa8ff636c3bb111du, 0x4fbed1402dd04cb7u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0xfa8ff636c3bb111du, 0x4fbed1402dd04cb7u}, pf::meta::ID{0x8878d2b99e1bda02u, 0x92495ea412152df6u}> {};

/****************************** pf::E8 END ******************************/
namespace pf::meta::details {
/****************************** pf::E8 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8>() {
    return pf::meta::ID{0x8878d2b99e1bda02u, 0x92495ea412152df6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8>() {
    return pf::meta::ID{0x1d0c5306fef24145u, 0x834344e951270f78u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 &>() {
    return pf::meta::ID{0xb758b420fe6a485du, 0xa5569bcf4dcaa2beu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 &&>() {
    return pf::meta::ID{0x6915dd75d1cbe975u, 0x44583a315be566f4u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8 &>() {
    return pf::meta::ID{0xe14c0d96d88eae5au, 0xaf6d691137b30ac6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 *>() {
    return pf::meta::ID{0x30b3d391adccfffcu, 0xd0ac967baeedbd6cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8 *>() {
    return pf::meta::ID{0xfa8ff636c3bb111du, 0x4fbed1402dd04cb7u};
}
/****************************** pf::E8 END ******************************/

/****************************** pf::E8::pf::E8::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::A>() {
return pf::meta::ID{0xba3aedb582bb65acu, 0x9911628e1ee03ca7u};
}
/****************************** pf::E8::pf::E8::A END ******************************/

/****************************** pf::E8::pf::E8::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::B>() {
return pf::meta::ID{0x9ebbfeed29ae1919u, 0x27c611f2624314bbu};
}
/****************************** pf::E8::pf::E8::B END ******************************/

/****************************** pf::E8::pf::E8::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::C>() {
return pf::meta::ID{0x876f2012865b04d3u, 0x6114a92879b5fa8cu};
}
/****************************** pf::E8::pf::E8::C END ******************************/

/****************************** pf::E8::pf::E8::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::D>() {
return pf::meta::ID{0xef669b685a5dc628u, 0xc009761612746c41u};
}
/****************************** pf::E8::pf::E8::D END ******************************/

/****************************** pf::E8::pf::E8::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::E>() {
return pf::meta::ID{0x244a246736f6934eu, 0xbe818d0464443817u};
}
/****************************** pf::E8::pf::E8::E END ******************************/
}
/****************************** pf::E9::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x1abacbdbb94158d7u, 0xadb075242567d7ceu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x1abacbdbb94158d7u, 0xadb075242567d7ceu};
    constexpr static ID TypeID = pf::meta::ID{0x60015226426621fdu, 0x3bd7759dc0871238u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x4dd13ced5fcba7c0u, 0x6ac18171531dca58u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x4dd13ced5fcba7c0u, 0x6ac18171531dca58u};
    constexpr static ID TypeID = pf::meta::ID{0x60015226426621fdu, 0x3bd7759dc0871238u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0xf0cb2ad9b2ba3eafu, 0x8c0438c6a3b2224au}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0xf0cb2ad9b2ba3eafu, 0x8c0438c6a3b2224au};
    constexpr static ID TypeID = pf::meta::ID{0x60015226426621fdu, 0x3bd7759dc0871238u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x6edb5a7278114469u, 0x96244b1cb6d8ab32u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x6edb5a7278114469u, 0x96244b1cb6d8ab32u};
    constexpr static ID TypeID = pf::meta::ID{0x60015226426621fdu, 0x3bd7759dc0871238u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x5ea97eb215a38676u, 0x2a8c0e2a41df1faeu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::ID{0x5ea97eb215a38676u, 0x2a8c0e2a41df1faeu};
    constexpr static ID TypeID = pf::meta::ID{0x60015226426621fdu, 0x3bd7759dc0871238u};
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
struct pf::meta::details::StaticInfo<pf::meta::ID{0x60015226426621fdu, 0x3bd7759dc0871238u}> {
    struct details {
        
    };
    using Type = pf::E9;
    constexpr static ID TypeID = pf::meta::ID{0x60015226426621fdu, 0x3bd7759dc0871238u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::ID{0x1abacbdbb94158d7u, 0xadb075242567d7ceu}, pf::meta::ID{0x4dd13ced5fcba7c0u, 0x6ac18171531dca58u}, pf::meta::ID{0xf0cb2ad9b2ba3eafu, 0x8c0438c6a3b2224au}, pf::meta::ID{0x6edb5a7278114469u, 0x96244b1cb6d8ab32u}, pf::meta::ID{0x5ea97eb215a38676u, 0x2a8c0e2a41df1faeu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x7d8034c85bdf718du, 0x107f202d6b18dd5eu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::ID{0x7d8034c85bdf718du, 0x107f202d6b18dd5eu}, pf::meta::ID{0x60015226426621fdu, 0x3bd7759dc0871238u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xad66f364cb6dba84u, 0x33590ee5a535165du}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::ID{0xad66f364cb6dba84u, 0x33590ee5a535165du}, pf::meta::ID{0x60015226426621fdu, 0x3bd7759dc0871238u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0xdbbbf9b1e0af7085u, 0x21a719bccc93ce63u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::ID{0xdbbbf9b1e0af7085u, 0x21a719bccc93ce63u}, pf::meta::ID{0x60015226426621fdu, 0x3bd7759dc0871238u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x4dadf84cda0f55eu, 0x334b25198c74073bu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::ID{0x4dadf84cda0f55eu, 0x334b25198c74073bu}, pf::meta::ID{0x60015226426621fdu, 0x3bd7759dc0871238u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x92e6afed7008ca6au, 0xbf9cd68478edf355u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::ID{0x92e6afed7008ca6au, 0xbf9cd68478edf355u}, pf::meta::ID{0x60015226426621fdu, 0x3bd7759dc0871238u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::ID{0x1faa7a2c02ce6f5fu, 0xd7245c8bbeda8cefu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::ID{0x1faa7a2c02ce6f5fu, 0xd7245c8bbeda8cefu}, pf::meta::ID{0x60015226426621fdu, 0x3bd7759dc0871238u}> {};

/****************************** pf::E9 END ******************************/
namespace pf::meta::details {
/****************************** pf::E9 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9>() {
    return pf::meta::ID{0x60015226426621fdu, 0x3bd7759dc0871238u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9>() {
    return pf::meta::ID{0x7d8034c85bdf718du, 0x107f202d6b18dd5eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 &>() {
    return pf::meta::ID{0xad66f364cb6dba84u, 0x33590ee5a535165du};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 &&>() {
    return pf::meta::ID{0xdbbbf9b1e0af7085u, 0x21a719bccc93ce63u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9 &>() {
    return pf::meta::ID{0x4dadf84cda0f55eu, 0x334b25198c74073bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 *>() {
    return pf::meta::ID{0x92e6afed7008ca6au, 0xbf9cd68478edf355u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9 *>() {
    return pf::meta::ID{0x1faa7a2c02ce6f5fu, 0xd7245c8bbeda8cefu};
}
/****************************** pf::E9 END ******************************/

/****************************** pf::E9::pf::E9::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::A>() {
return pf::meta::ID{0x1abacbdbb94158d7u, 0xadb075242567d7ceu};
}
/****************************** pf::E9::pf::E9::A END ******************************/

/****************************** pf::E9::pf::E9::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::B>() {
return pf::meta::ID{0x4dd13ced5fcba7c0u, 0x6ac18171531dca58u};
}
/****************************** pf::E9::pf::E9::B END ******************************/

/****************************** pf::E9::pf::E9::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::C>() {
return pf::meta::ID{0xf0cb2ad9b2ba3eafu, 0x8c0438c6a3b2224au};
}
/****************************** pf::E9::pf::E9::C END ******************************/

/****************************** pf::E9::pf::E9::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::D>() {
return pf::meta::ID{0x6edb5a7278114469u, 0x96244b1cb6d8ab32u};
}
/****************************** pf::E9::pf::E9::D END ******************************/

/****************************** pf::E9::pf::E9::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::E>() {
return pf::meta::ID{0x5ea97eb215a38676u, 0x2a8c0e2a41df1faeu};
}
/****************************** pf::E9::pf::E9::E END ******************************/
}

