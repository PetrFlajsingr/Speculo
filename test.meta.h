
#pragma once

#include "test.h" // FIXME: include file from tool input
#include <pf_common/array.h>
#include <pf_common/concepts/ranges.h>
#include <type_traits>
#include "meta/details/StaticInfo.h"
#include "meta/details/StaticInfo_Wrappers.h"
#include "meta/details/ID.h"
#include "meta/Attribute.h"
#include "meta/Info.h"

/****************************** pf::SomeEnum::Value1 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa8a39f8d5c0c7fb4u, 0x3836af5c2d49e8a1u}> {
    struct details {
        constexpr static auto ArgArray_14272884268912331910 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_17830640958501193878 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_18350870136209208577 = pf::make_array<std::string_view>();

    };
    constexpr static ID ValueID = pf::meta::details::ID{0xa8a39f8d5c0c7fb4u, 0x3836af5c2d49e8a1u};
    constexpr static ID TypeID = pf::meta::details::ID{0x95e8e6083c96ed3cu, 0x87d09429d4a60b29u};
    using Type = pf::SomeEnum;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(pf::meta::Attribute{"test", std::span<const std::string_view>{details::ArgArray_14272884268912331910}}, pf::meta::Attribute{"test2", std::span<const std::string_view>{details::ArgArray_17830640958501193878}}, pf::meta::Attribute{"test3", std::span<const std::string_view>{details::ArgArray_18350870136209208577}});

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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe391e67dbe6f84acu, 0xd6bf4c26f37b2e6cu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xe391e67dbe6f84acu, 0xd6bf4c26f37b2e6cu};
    constexpr static ID TypeID = pf::meta::details::ID{0x95e8e6083c96ed3cu, 0x87d09429d4a60b29u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x95e8e6083c96ed3cu, 0x87d09429d4a60b29u}> {
    struct details {
        constexpr static auto ArgArray_12199429309247918723 = pf::make_array<std::string_view>(R"arg(()()()((())))arg", R"arg([[nodiscard]])arg", R"arg(1ll)arg", R"arg(1.011)arg", R"arg([]{}())arg", R"arg("yeet")arg", R"arg('a')arg", R"arg([][][]:::3214234...[][][][])arg");
constexpr static auto ArgArray_15158093310135656793 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_14339933373192633136 = pf::make_array<std::string_view>(R"arg(1ll)arg", R"arg(1.011)arg", R"arg("yeet")arg");
constexpr static auto ArgArray_13305354245767424541 = pf::make_array<std::string_view>();

    };
    using Type = pf::SomeEnum;
    constexpr static ID TypeID = pf::meta::details::ID{0x95e8e6083c96ed3cu, 0x87d09429d4a60b29u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(pf::meta::Attribute{"pf::operators", std::span<const std::string_view>{details::ArgArray_12199429309247918723}}, pf::meta::Attribute{"pf::hihi", std::span<const std::string_view>{details::ArgArray_15158093310135656793}}, pf::meta::Attribute{"pf::operators2", std::span<const std::string_view>{details::ArgArray_14339933373192633136}}, pf::meta::Attribute{"pf::hihi2", std::span<const std::string_view>{details::ArgArray_13305354245767424541}});

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0xa8a39f8d5c0c7fb4u, 0x3836af5c2d49e8a1u}, pf::meta::details::ID{0xe391e67dbe6f84acu, 0xd6bf4c26f37b2e6cu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x74df13179c8fe08au, 0x8a4a2608102c07bu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x74df13179c8fe08au, 0x8a4a2608102c07bu}, pf::meta::details::ID{0x95e8e6083c96ed3cu, 0x87d09429d4a60b29u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x10de80d1e0c31563u, 0x8967f3a6dd84eb9du}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x10de80d1e0c31563u, 0x8967f3a6dd84eb9du}, pf::meta::details::ID{0x95e8e6083c96ed3cu, 0x87d09429d4a60b29u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x8a3285dac403a44u, 0xe66ea0dfcf0ade79u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x8a3285dac403a44u, 0xe66ea0dfcf0ade79u}, pf::meta::details::ID{0x95e8e6083c96ed3cu, 0x87d09429d4a60b29u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x34b1bee36c4c1ebau, 0x404c989cfaade4c2u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x34b1bee36c4c1ebau, 0x404c989cfaade4c2u}, pf::meta::details::ID{0x95e8e6083c96ed3cu, 0x87d09429d4a60b29u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb3b6dbefa65af832u, 0xe379fd2635633dc3u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0xb3b6dbefa65af832u, 0xe379fd2635633dc3u}, pf::meta::details::ID{0x95e8e6083c96ed3cu, 0x87d09429d4a60b29u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa115cecf0c26ed72u, 0xe3d4486696898da8u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0xa115cecf0c26ed72u, 0xe3d4486696898da8u}, pf::meta::details::ID{0x95e8e6083c96ed3cu, 0x87d09429d4a60b29u}> {};

/****************************** pf::SomeEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::SomeEnum START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum>() {
    return pf::meta::details::ID{0x95e8e6083c96ed3cu, 0x87d09429d4a60b29u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum>() {
    return pf::meta::details::ID{0x74df13179c8fe08au, 0x8a4a2608102c07bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum &>() {
    return pf::meta::details::ID{0x10de80d1e0c31563u, 0x8967f3a6dd84eb9du};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum &&>() {
    return pf::meta::details::ID{0x8a3285dac403a44u, 0xe66ea0dfcf0ade79u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum &>() {
    return pf::meta::details::ID{0x34b1bee36c4c1ebau, 0x404c989cfaade4c2u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum *>() {
    return pf::meta::details::ID{0xb3b6dbefa65af832u, 0xe379fd2635633dc3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum *>() {
    return pf::meta::details::ID{0xa115cecf0c26ed72u, 0xe3d4486696898da8u};
}
/****************************** pf::SomeEnum END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value1 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value1>() {
return pf::meta::details::ID{0xa8a39f8d5c0c7fb4u, 0x3836af5c2d49e8a1u};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value1 END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value2 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value2>() {
return pf::meta::details::ID{0xe391e67dbe6f84acu, 0xd6bf4c26f37b2e6cu};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value2 END ******************************/
}
/****************************** pf::Test::E::Value1 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xc3e856f9053656ebu, 0xb934fbefd19b2099u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xc3e856f9053656ebu, 0xb934fbefd19b2099u};
    constexpr static ID TypeID = pf::meta::details::ID{0xc00af76f0f20c2b8u, 0x2b281533fef7a87cu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xeb0027c4bb1a6562u, 0xe144ee7a2946dec8u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xeb0027c4bb1a6562u, 0xe144ee7a2946dec8u};
    constexpr static ID TypeID = pf::meta::details::ID{0xc00af76f0f20c2b8u, 0x2b281533fef7a87cu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xc00af76f0f20c2b8u, 0x2b281533fef7a87cu}> {
    struct details {
        
    };
    using Type = pf::Test::E;
    constexpr static ID TypeID = pf::meta::details::ID{0xc00af76f0f20c2b8u, 0x2b281533fef7a87cu};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0xc3e856f9053656ebu, 0xb934fbefd19b2099u}, pf::meta::details::ID{0xeb0027c4bb1a6562u, 0xe144ee7a2946dec8u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x5232fbcb68611da3u, 0x4a377125b6b139eeu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x5232fbcb68611da3u, 0x4a377125b6b139eeu}, pf::meta::details::ID{0xc00af76f0f20c2b8u, 0x2b281533fef7a87cu}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x40d593916f9a5fd4u, 0x89cefcbf1524a44bu}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x40d593916f9a5fd4u, 0x89cefcbf1524a44bu}, pf::meta::details::ID{0xc00af76f0f20c2b8u, 0x2b281533fef7a87cu}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x13ed78aa3474a99du, 0xd1a5d4b3ad3fd593u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x13ed78aa3474a99du, 0xd1a5d4b3ad3fd593u}, pf::meta::details::ID{0xc00af76f0f20c2b8u, 0x2b281533fef7a87cu}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x406624b81209034fu, 0xb79dd174704862dbu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x406624b81209034fu, 0xb79dd174704862dbu}, pf::meta::details::ID{0xc00af76f0f20c2b8u, 0x2b281533fef7a87cu}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x35cb55fc4c96469eu, 0xc02f55e716b4d84du}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x35cb55fc4c96469eu, 0xc02f55e716b4d84du}, pf::meta::details::ID{0xc00af76f0f20c2b8u, 0x2b281533fef7a87cu}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x52ea878196666faeu, 0x2ad95ad33b15ca19u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x52ea878196666faeu, 0x2ad95ad33b15ca19u}, pf::meta::details::ID{0xc00af76f0f20c2b8u, 0x2b281533fef7a87cu}> {};

/****************************** pf::Test::E END ******************************/
namespace pf::meta::details {
/****************************** pf::Test::E START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E>() {
    return pf::meta::details::ID{0xc00af76f0f20c2b8u, 0x2b281533fef7a87cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E>() {
    return pf::meta::details::ID{0x5232fbcb68611da3u, 0x4a377125b6b139eeu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E &>() {
    return pf::meta::details::ID{0x40d593916f9a5fd4u, 0x89cefcbf1524a44bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E &&>() {
    return pf::meta::details::ID{0x13ed78aa3474a99du, 0xd1a5d4b3ad3fd593u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E &>() {
    return pf::meta::details::ID{0x406624b81209034fu, 0xb79dd174704862dbu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E *>() {
    return pf::meta::details::ID{0x35cb55fc4c96469eu, 0xc02f55e716b4d84du};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E *>() {
    return pf::meta::details::ID{0x52ea878196666faeu, 0x2ad95ad33b15ca19u};
}
/****************************** pf::Test::E END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value1 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::Test::E::Value1>() {
return pf::meta::details::ID{0xc3e856f9053656ebu, 0xb934fbefd19b2099u};
}
/****************************** pf::Test::E::pf::Test::E::Value1 END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value2 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::Test::E::Value2>() {
return pf::meta::details::ID{0xeb0027c4bb1a6562u, 0xe144ee7a2946dec8u};
}
/****************************** pf::Test::E::pf::Test::E::Value2 END ******************************/
}
/****************************** pf::EmptyEnum START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe40dad7cdffa0e84u, 0x32d74abe5fd3900du}> {
    struct details {
        
    };
    using Type = pf::EmptyEnum;
    constexpr static ID TypeID = pf::meta::details::ID{0xe40dad7cdffa0e84u, 0x32d74abe5fd3900du};

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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x21b0e1cb0036147eu, 0xa9c99384cdefb9f3u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x21b0e1cb0036147eu, 0xa9c99384cdefb9f3u}, pf::meta::details::ID{0xe40dad7cdffa0e84u, 0x32d74abe5fd3900du}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xcd2f538bda615bu, 0x66b3447f86239487u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0xcd2f538bda615bu, 0x66b3447f86239487u}, pf::meta::details::ID{0xe40dad7cdffa0e84u, 0x32d74abe5fd3900du}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x16760df527b838d8u, 0xcb44e3f79e8882b9u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x16760df527b838d8u, 0xcb44e3f79e8882b9u}, pf::meta::details::ID{0xe40dad7cdffa0e84u, 0x32d74abe5fd3900du}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x44e09abceb12cfb2u, 0xffb815944f0b2e8eu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x44e09abceb12cfb2u, 0xffb815944f0b2e8eu}, pf::meta::details::ID{0xe40dad7cdffa0e84u, 0x32d74abe5fd3900du}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x49bccf0b7cbb0b84u, 0xab183b9d67d2a474u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x49bccf0b7cbb0b84u, 0xab183b9d67d2a474u}, pf::meta::details::ID{0xe40dad7cdffa0e84u, 0x32d74abe5fd3900du}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x581a50a23aa656c4u, 0xf2247591bb5571adu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x581a50a23aa656c4u, 0xf2247591bb5571adu}, pf::meta::details::ID{0xe40dad7cdffa0e84u, 0x32d74abe5fd3900du}> {};

/****************************** pf::EmptyEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::EmptyEnum START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum>() {
    return pf::meta::details::ID{0xe40dad7cdffa0e84u, 0x32d74abe5fd3900du};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum>() {
    return pf::meta::details::ID{0x21b0e1cb0036147eu, 0xa9c99384cdefb9f3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &>() {
    return pf::meta::details::ID{0xcd2f538bda615bu, 0x66b3447f86239487u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &&>() {
    return pf::meta::details::ID{0x16760df527b838d8u, 0xcb44e3f79e8882b9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum &>() {
    return pf::meta::details::ID{0x44e09abceb12cfb2u, 0xffb815944f0b2e8eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum *>() {
    return pf::meta::details::ID{0x49bccf0b7cbb0b84u, 0xab183b9d67d2a474u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum *>() {
    return pf::meta::details::ID{0x581a50a23aa656c4u, 0xf2247591bb5571adu};
}
/****************************** pf::EmptyEnum END ******************************/
}
/****************************** pf::E1::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x134efe9169125c06u, 0x997ec750051caa66u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x134efe9169125c06u, 0x997ec750051caa66u};
    constexpr static ID TypeID = pf::meta::details::ID{0x88bff6945420769eu, 0x108c618d729babcdu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x9a4c0132747520e2u, 0xf5ca64a99bfc27b8u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x9a4c0132747520e2u, 0xf5ca64a99bfc27b8u};
    constexpr static ID TypeID = pf::meta::details::ID{0x88bff6945420769eu, 0x108c618d729babcdu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xdc3eb5e5b942e8a0u, 0xf9f76d3f656b5425u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xdc3eb5e5b942e8a0u, 0xf9f76d3f656b5425u};
    constexpr static ID TypeID = pf::meta::details::ID{0x88bff6945420769eu, 0x108c618d729babcdu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x7255f0f2ef35054au, 0xf02959f7202a6abfu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x7255f0f2ef35054au, 0xf02959f7202a6abfu};
    constexpr static ID TypeID = pf::meta::details::ID{0x88bff6945420769eu, 0x108c618d729babcdu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x8b93facce536861au, 0x773d656550d39e44u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x8b93facce536861au, 0x773d656550d39e44u};
    constexpr static ID TypeID = pf::meta::details::ID{0x88bff6945420769eu, 0x108c618d729babcdu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x88bff6945420769eu, 0x108c618d729babcdu}> {
    struct details {
        
    };
    using Type = pf::E1;
    constexpr static ID TypeID = pf::meta::details::ID{0x88bff6945420769eu, 0x108c618d729babcdu};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x134efe9169125c06u, 0x997ec750051caa66u}, pf::meta::details::ID{0x9a4c0132747520e2u, 0xf5ca64a99bfc27b8u}, pf::meta::details::ID{0xdc3eb5e5b942e8a0u, 0xf9f76d3f656b5425u}, pf::meta::details::ID{0x7255f0f2ef35054au, 0xf02959f7202a6abfu}, pf::meta::details::ID{0x8b93facce536861au, 0x773d656550d39e44u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x613fa42ab83e9dccu, 0x59bc4686924122fu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x613fa42ab83e9dccu, 0x59bc4686924122fu}, pf::meta::details::ID{0x88bff6945420769eu, 0x108c618d729babcdu}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x46c6439bb298cccbu, 0xc35de7c9e1963c23u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x46c6439bb298cccbu, 0xc35de7c9e1963c23u}, pf::meta::details::ID{0x88bff6945420769eu, 0x108c618d729babcdu}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xf2a254e0321fa16du, 0x33385e3f6cb77fc7u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0xf2a254e0321fa16du, 0x33385e3f6cb77fc7u}, pf::meta::details::ID{0x88bff6945420769eu, 0x108c618d729babcdu}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x25faa31afd3db416u, 0xcce5e029b7f2263du}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x25faa31afd3db416u, 0xcce5e029b7f2263du}, pf::meta::details::ID{0x88bff6945420769eu, 0x108c618d729babcdu}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xdee3d0dc174dd8d4u, 0xdafb52c3452a858u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0xdee3d0dc174dd8d4u, 0xdafb52c3452a858u}, pf::meta::details::ID{0x88bff6945420769eu, 0x108c618d729babcdu}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa1a8b8ca5bd197c9u, 0xf0b9ecbbdd203d5fu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0xa1a8b8ca5bd197c9u, 0xf0b9ecbbdd203d5fu}, pf::meta::details::ID{0x88bff6945420769eu, 0x108c618d729babcdu}> {};

/****************************** pf::E1 END ******************************/
namespace pf::meta::details {
/****************************** pf::E1 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1>() {
    return pf::meta::details::ID{0x88bff6945420769eu, 0x108c618d729babcdu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1>() {
    return pf::meta::details::ID{0x613fa42ab83e9dccu, 0x59bc4686924122fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 &>() {
    return pf::meta::details::ID{0x46c6439bb298cccbu, 0xc35de7c9e1963c23u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 &&>() {
    return pf::meta::details::ID{0xf2a254e0321fa16du, 0x33385e3f6cb77fc7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1 &>() {
    return pf::meta::details::ID{0x25faa31afd3db416u, 0xcce5e029b7f2263du};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 *>() {
    return pf::meta::details::ID{0xdee3d0dc174dd8d4u, 0xdafb52c3452a858u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1 *>() {
    return pf::meta::details::ID{0xa1a8b8ca5bd197c9u, 0xf0b9ecbbdd203d5fu};
}
/****************************** pf::E1 END ******************************/

/****************************** pf::E1::pf::E1::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::A>() {
return pf::meta::details::ID{0x134efe9169125c06u, 0x997ec750051caa66u};
}
/****************************** pf::E1::pf::E1::A END ******************************/

/****************************** pf::E1::pf::E1::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::B>() {
return pf::meta::details::ID{0x9a4c0132747520e2u, 0xf5ca64a99bfc27b8u};
}
/****************************** pf::E1::pf::E1::B END ******************************/

/****************************** pf::E1::pf::E1::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::C>() {
return pf::meta::details::ID{0xdc3eb5e5b942e8a0u, 0xf9f76d3f656b5425u};
}
/****************************** pf::E1::pf::E1::C END ******************************/

/****************************** pf::E1::pf::E1::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::D>() {
return pf::meta::details::ID{0x7255f0f2ef35054au, 0xf02959f7202a6abfu};
}
/****************************** pf::E1::pf::E1::D END ******************************/

/****************************** pf::E1::pf::E1::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::E>() {
return pf::meta::details::ID{0x8b93facce536861au, 0x773d656550d39e44u};
}
/****************************** pf::E1::pf::E1::E END ******************************/
}
/****************************** pf::E2::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x8d438f0a5a284dbau, 0x88a0f56194c4d334u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x8d438f0a5a284dbau, 0x88a0f56194c4d334u};
    constexpr static ID TypeID = pf::meta::details::ID{0x68666fdc1ab26766u, 0x8c69abfe75b7bc83u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x9d539a9aad7acceau, 0x500bdc392a945d67u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x9d539a9aad7acceau, 0x500bdc392a945d67u};
    constexpr static ID TypeID = pf::meta::details::ID{0x68666fdc1ab26766u, 0x8c69abfe75b7bc83u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd1fecc31bbfaa781u, 0xfdf28b65cc607baeu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xd1fecc31bbfaa781u, 0xfdf28b65cc607baeu};
    constexpr static ID TypeID = pf::meta::details::ID{0x68666fdc1ab26766u, 0x8c69abfe75b7bc83u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x304bfaddd81e4cc6u, 0x8ada44074366bcu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x304bfaddd81e4cc6u, 0x8ada44074366bcu};
    constexpr static ID TypeID = pf::meta::details::ID{0x68666fdc1ab26766u, 0x8c69abfe75b7bc83u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x85b0018f9e9af6fcu, 0xd57e6beefb9f9af6u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x85b0018f9e9af6fcu, 0xd57e6beefb9f9af6u};
    constexpr static ID TypeID = pf::meta::details::ID{0x68666fdc1ab26766u, 0x8c69abfe75b7bc83u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x68666fdc1ab26766u, 0x8c69abfe75b7bc83u}> {
    struct details {
        
    };
    using Type = pf::E2;
    constexpr static ID TypeID = pf::meta::details::ID{0x68666fdc1ab26766u, 0x8c69abfe75b7bc83u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x8d438f0a5a284dbau, 0x88a0f56194c4d334u}, pf::meta::details::ID{0x9d539a9aad7acceau, 0x500bdc392a945d67u}, pf::meta::details::ID{0xd1fecc31bbfaa781u, 0xfdf28b65cc607baeu}, pf::meta::details::ID{0x304bfaddd81e4cc6u, 0x8ada44074366bcu}, pf::meta::details::ID{0x85b0018f9e9af6fcu, 0xd57e6beefb9f9af6u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xf9a25c1079e961ceu, 0x7d8292029d73fea1u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0xf9a25c1079e961ceu, 0x7d8292029d73fea1u}, pf::meta::details::ID{0x68666fdc1ab26766u, 0x8c69abfe75b7bc83u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xbf3fb4715c20138u, 0xe8e2da49dea02c8au}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0xbf3fb4715c20138u, 0xe8e2da49dea02c8au}, pf::meta::details::ID{0x68666fdc1ab26766u, 0x8c69abfe75b7bc83u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe86305b4e07e3ff0u, 0x41264df417e63f05u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0xe86305b4e07e3ff0u, 0x41264df417e63f05u}, pf::meta::details::ID{0x68666fdc1ab26766u, 0x8c69abfe75b7bc83u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x2731931283143f71u, 0xdcbc8b5179ce9c4fu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x2731931283143f71u, 0xdcbc8b5179ce9c4fu}, pf::meta::details::ID{0x68666fdc1ab26766u, 0x8c69abfe75b7bc83u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x7912fdb5a3a28448u, 0x78ae1be9aa558e78u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x7912fdb5a3a28448u, 0x78ae1be9aa558e78u}, pf::meta::details::ID{0x68666fdc1ab26766u, 0x8c69abfe75b7bc83u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x31645e5200f8c971u, 0x63a6e38a5868188u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x31645e5200f8c971u, 0x63a6e38a5868188u}, pf::meta::details::ID{0x68666fdc1ab26766u, 0x8c69abfe75b7bc83u}> {};

/****************************** pf::E2 END ******************************/
namespace pf::meta::details {
/****************************** pf::E2 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2>() {
    return pf::meta::details::ID{0x68666fdc1ab26766u, 0x8c69abfe75b7bc83u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2>() {
    return pf::meta::details::ID{0xf9a25c1079e961ceu, 0x7d8292029d73fea1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 &>() {
    return pf::meta::details::ID{0xbf3fb4715c20138u, 0xe8e2da49dea02c8au};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 &&>() {
    return pf::meta::details::ID{0xe86305b4e07e3ff0u, 0x41264df417e63f05u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2 &>() {
    return pf::meta::details::ID{0x2731931283143f71u, 0xdcbc8b5179ce9c4fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 *>() {
    return pf::meta::details::ID{0x7912fdb5a3a28448u, 0x78ae1be9aa558e78u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2 *>() {
    return pf::meta::details::ID{0x31645e5200f8c971u, 0x63a6e38a5868188u};
}
/****************************** pf::E2 END ******************************/

/****************************** pf::E2::pf::E2::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::A>() {
return pf::meta::details::ID{0x8d438f0a5a284dbau, 0x88a0f56194c4d334u};
}
/****************************** pf::E2::pf::E2::A END ******************************/

/****************************** pf::E2::pf::E2::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::B>() {
return pf::meta::details::ID{0x9d539a9aad7acceau, 0x500bdc392a945d67u};
}
/****************************** pf::E2::pf::E2::B END ******************************/

/****************************** pf::E2::pf::E2::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::C>() {
return pf::meta::details::ID{0xd1fecc31bbfaa781u, 0xfdf28b65cc607baeu};
}
/****************************** pf::E2::pf::E2::C END ******************************/

/****************************** pf::E2::pf::E2::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::D>() {
return pf::meta::details::ID{0x304bfaddd81e4cc6u, 0x8ada44074366bcu};
}
/****************************** pf::E2::pf::E2::D END ******************************/

/****************************** pf::E2::pf::E2::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::E>() {
return pf::meta::details::ID{0x85b0018f9e9af6fcu, 0xd57e6beefb9f9af6u};
}
/****************************** pf::E2::pf::E2::E END ******************************/
}
/****************************** pf::E3::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x191f824e563b04f4u, 0xbfa482a4847d6aacu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x191f824e563b04f4u, 0xbfa482a4847d6aacu};
    constexpr static ID TypeID = pf::meta::details::ID{0xc87d6155b93d15f5u, 0x14113d9e0633d793u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xfb8bebd2757e9612u, 0xeef03a77b493684bu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xfb8bebd2757e9612u, 0xeef03a77b493684bu};
    constexpr static ID TypeID = pf::meta::details::ID{0xc87d6155b93d15f5u, 0x14113d9e0633d793u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xce7b47d962ed89du, 0xc51a9f40477d2c91u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xce7b47d962ed89du, 0xc51a9f40477d2c91u};
    constexpr static ID TypeID = pf::meta::details::ID{0xc87d6155b93d15f5u, 0x14113d9e0633d793u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x692a152b28c4b51au, 0x90595b957bcb49b2u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x692a152b28c4b51au, 0x90595b957bcb49b2u};
    constexpr static ID TypeID = pf::meta::details::ID{0xc87d6155b93d15f5u, 0x14113d9e0633d793u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x380dd38ab2095680u, 0xe059e2bbeb1d7e55u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x380dd38ab2095680u, 0xe059e2bbeb1d7e55u};
    constexpr static ID TypeID = pf::meta::details::ID{0xc87d6155b93d15f5u, 0x14113d9e0633d793u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xc87d6155b93d15f5u, 0x14113d9e0633d793u}> {
    struct details {
        
    };
    using Type = pf::E3;
    constexpr static ID TypeID = pf::meta::details::ID{0xc87d6155b93d15f5u, 0x14113d9e0633d793u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x191f824e563b04f4u, 0xbfa482a4847d6aacu}, pf::meta::details::ID{0xfb8bebd2757e9612u, 0xeef03a77b493684bu}, pf::meta::details::ID{0xce7b47d962ed89du, 0xc51a9f40477d2c91u}, pf::meta::details::ID{0x692a152b28c4b51au, 0x90595b957bcb49b2u}, pf::meta::details::ID{0x380dd38ab2095680u, 0xe059e2bbeb1d7e55u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xf43ae8e46a6997a6u, 0x2f07425c5c0ab9ceu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0xf43ae8e46a6997a6u, 0x2f07425c5c0ab9ceu}, pf::meta::details::ID{0xc87d6155b93d15f5u, 0x14113d9e0633d793u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x8eb8043a60efe509u, 0xb7f311f3921067f3u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x8eb8043a60efe509u, 0xb7f311f3921067f3u}, pf::meta::details::ID{0xc87d6155b93d15f5u, 0x14113d9e0633d793u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x896c5085b5979706u, 0xe4081389b7adb061u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x896c5085b5979706u, 0xe4081389b7adb061u}, pf::meta::details::ID{0xc87d6155b93d15f5u, 0x14113d9e0633d793u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x6d5a8d5ebcec41a6u, 0x2c832e7e15dd4bc7u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x6d5a8d5ebcec41a6u, 0x2c832e7e15dd4bc7u}, pf::meta::details::ID{0xc87d6155b93d15f5u, 0x14113d9e0633d793u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x8906247fc10fcb80u, 0x39581a2f65657bdcu}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x8906247fc10fcb80u, 0x39581a2f65657bdcu}, pf::meta::details::ID{0xc87d6155b93d15f5u, 0x14113d9e0633d793u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x2fbe7c4cdea21e26u, 0x2f59e9125cd7fa05u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x2fbe7c4cdea21e26u, 0x2f59e9125cd7fa05u}, pf::meta::details::ID{0xc87d6155b93d15f5u, 0x14113d9e0633d793u}> {};

/****************************** pf::E3 END ******************************/
namespace pf::meta::details {
/****************************** pf::E3 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3>() {
    return pf::meta::details::ID{0xc87d6155b93d15f5u, 0x14113d9e0633d793u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3>() {
    return pf::meta::details::ID{0xf43ae8e46a6997a6u, 0x2f07425c5c0ab9ceu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 &>() {
    return pf::meta::details::ID{0x8eb8043a60efe509u, 0xb7f311f3921067f3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 &&>() {
    return pf::meta::details::ID{0x896c5085b5979706u, 0xe4081389b7adb061u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3 &>() {
    return pf::meta::details::ID{0x6d5a8d5ebcec41a6u, 0x2c832e7e15dd4bc7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 *>() {
    return pf::meta::details::ID{0x8906247fc10fcb80u, 0x39581a2f65657bdcu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3 *>() {
    return pf::meta::details::ID{0x2fbe7c4cdea21e26u, 0x2f59e9125cd7fa05u};
}
/****************************** pf::E3 END ******************************/

/****************************** pf::E3::pf::E3::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::A>() {
return pf::meta::details::ID{0x191f824e563b04f4u, 0xbfa482a4847d6aacu};
}
/****************************** pf::E3::pf::E3::A END ******************************/

/****************************** pf::E3::pf::E3::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::B>() {
return pf::meta::details::ID{0xfb8bebd2757e9612u, 0xeef03a77b493684bu};
}
/****************************** pf::E3::pf::E3::B END ******************************/

/****************************** pf::E3::pf::E3::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::C>() {
return pf::meta::details::ID{0xce7b47d962ed89du, 0xc51a9f40477d2c91u};
}
/****************************** pf::E3::pf::E3::C END ******************************/

/****************************** pf::E3::pf::E3::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::D>() {
return pf::meta::details::ID{0x692a152b28c4b51au, 0x90595b957bcb49b2u};
}
/****************************** pf::E3::pf::E3::D END ******************************/

/****************************** pf::E3::pf::E3::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::E>() {
return pf::meta::details::ID{0x380dd38ab2095680u, 0xe059e2bbeb1d7e55u};
}
/****************************** pf::E3::pf::E3::E END ******************************/
}
/****************************** pf::E4::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe184780e955c5a68u, 0x10664e88ebb2464au}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xe184780e955c5a68u, 0x10664e88ebb2464au};
    constexpr static ID TypeID = pf::meta::details::ID{0xe58f3c300bb91f8cu, 0xbaff5de49fc34ac6u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb132e674826cf87u, 0x4c2227f777f6888eu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xb132e674826cf87u, 0x4c2227f777f6888eu};
    constexpr static ID TypeID = pf::meta::details::ID{0xe58f3c300bb91f8cu, 0xbaff5de49fc34ac6u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x26debfc81a795263u, 0x8b18fa20e0124f13u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x26debfc81a795263u, 0x8b18fa20e0124f13u};
    constexpr static ID TypeID = pf::meta::details::ID{0xe58f3c300bb91f8cu, 0xbaff5de49fc34ac6u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x984ea90082b04b02u, 0x573803c5af3f6b75u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x984ea90082b04b02u, 0x573803c5af3f6b75u};
    constexpr static ID TypeID = pf::meta::details::ID{0xe58f3c300bb91f8cu, 0xbaff5de49fc34ac6u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x68c2db8cce9ef348u, 0xd522efa392d109du}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x68c2db8cce9ef348u, 0xd522efa392d109du};
    constexpr static ID TypeID = pf::meta::details::ID{0xe58f3c300bb91f8cu, 0xbaff5de49fc34ac6u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe58f3c300bb91f8cu, 0xbaff5de49fc34ac6u}> {
    struct details {
        
    };
    using Type = pf::E4;
    constexpr static ID TypeID = pf::meta::details::ID{0xe58f3c300bb91f8cu, 0xbaff5de49fc34ac6u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0xe184780e955c5a68u, 0x10664e88ebb2464au}, pf::meta::details::ID{0xb132e674826cf87u, 0x4c2227f777f6888eu}, pf::meta::details::ID{0x26debfc81a795263u, 0x8b18fa20e0124f13u}, pf::meta::details::ID{0x984ea90082b04b02u, 0x573803c5af3f6b75u}, pf::meta::details::ID{0x68c2db8cce9ef348u, 0xd522efa392d109du});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xae79e315968558d0u, 0xe5765e3b074b0debu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0xae79e315968558d0u, 0xe5765e3b074b0debu}, pf::meta::details::ID{0xe58f3c300bb91f8cu, 0xbaff5de49fc34ac6u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x98ec0e27d02db330u, 0xdd5f071efb5fa223u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x98ec0e27d02db330u, 0xdd5f071efb5fa223u}, pf::meta::details::ID{0xe58f3c300bb91f8cu, 0xbaff5de49fc34ac6u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x9c0e6cae8b6c7a96u, 0xbe51fb3624b07fafu}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x9c0e6cae8b6c7a96u, 0xbe51fb3624b07fafu}, pf::meta::details::ID{0xe58f3c300bb91f8cu, 0xbaff5de49fc34ac6u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x6eb20fc42275bb2eu, 0x9693d7a8ec71d434u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x6eb20fc42275bb2eu, 0x9693d7a8ec71d434u}, pf::meta::details::ID{0xe58f3c300bb91f8cu, 0xbaff5de49fc34ac6u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x7ab7d4ab94f0fd97u, 0xd31036a2a99b3fbdu}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x7ab7d4ab94f0fd97u, 0xd31036a2a99b3fbdu}, pf::meta::details::ID{0xe58f3c300bb91f8cu, 0xbaff5de49fc34ac6u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x1f8856b2b158ccd2u, 0x59ae992a0d56ddd9u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x1f8856b2b158ccd2u, 0x59ae992a0d56ddd9u}, pf::meta::details::ID{0xe58f3c300bb91f8cu, 0xbaff5de49fc34ac6u}> {};

/****************************** pf::E4 END ******************************/
namespace pf::meta::details {
/****************************** pf::E4 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4>() {
    return pf::meta::details::ID{0xe58f3c300bb91f8cu, 0xbaff5de49fc34ac6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4>() {
    return pf::meta::details::ID{0xae79e315968558d0u, 0xe5765e3b074b0debu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 &>() {
    return pf::meta::details::ID{0x98ec0e27d02db330u, 0xdd5f071efb5fa223u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 &&>() {
    return pf::meta::details::ID{0x9c0e6cae8b6c7a96u, 0xbe51fb3624b07fafu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4 &>() {
    return pf::meta::details::ID{0x6eb20fc42275bb2eu, 0x9693d7a8ec71d434u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 *>() {
    return pf::meta::details::ID{0x7ab7d4ab94f0fd97u, 0xd31036a2a99b3fbdu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4 *>() {
    return pf::meta::details::ID{0x1f8856b2b158ccd2u, 0x59ae992a0d56ddd9u};
}
/****************************** pf::E4 END ******************************/

/****************************** pf::E4::pf::E4::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::A>() {
return pf::meta::details::ID{0xe184780e955c5a68u, 0x10664e88ebb2464au};
}
/****************************** pf::E4::pf::E4::A END ******************************/

/****************************** pf::E4::pf::E4::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::B>() {
return pf::meta::details::ID{0xb132e674826cf87u, 0x4c2227f777f6888eu};
}
/****************************** pf::E4::pf::E4::B END ******************************/

/****************************** pf::E4::pf::E4::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::C>() {
return pf::meta::details::ID{0x26debfc81a795263u, 0x8b18fa20e0124f13u};
}
/****************************** pf::E4::pf::E4::C END ******************************/

/****************************** pf::E4::pf::E4::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::D>() {
return pf::meta::details::ID{0x984ea90082b04b02u, 0x573803c5af3f6b75u};
}
/****************************** pf::E4::pf::E4::D END ******************************/

/****************************** pf::E4::pf::E4::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::E>() {
return pf::meta::details::ID{0x68c2db8cce9ef348u, 0xd522efa392d109du};
}
/****************************** pf::E4::pf::E4::E END ******************************/
}
/****************************** pf::E5::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x616b8ad449ed4483u, 0xd1c8a4e1aab48581u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x616b8ad449ed4483u, 0xd1c8a4e1aab48581u};
    constexpr static ID TypeID = pf::meta::details::ID{0x7d2131ef489c5089u, 0xd1523f0d45536884u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x2d67c0993d449889u, 0x2ca925dab7fff796u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x2d67c0993d449889u, 0x2ca925dab7fff796u};
    constexpr static ID TypeID = pf::meta::details::ID{0x7d2131ef489c5089u, 0xd1523f0d45536884u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x65ffaade57047d3au, 0x468cc217f85f1a01u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x65ffaade57047d3au, 0x468cc217f85f1a01u};
    constexpr static ID TypeID = pf::meta::details::ID{0x7d2131ef489c5089u, 0xd1523f0d45536884u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x4cd177a95c39f7d7u, 0xdab4b167b8974003u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x4cd177a95c39f7d7u, 0xdab4b167b8974003u};
    constexpr static ID TypeID = pf::meta::details::ID{0x7d2131ef489c5089u, 0xd1523f0d45536884u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x66239075a9d0f86fu, 0x3efc590e5b19fbf0u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x66239075a9d0f86fu, 0x3efc590e5b19fbf0u};
    constexpr static ID TypeID = pf::meta::details::ID{0x7d2131ef489c5089u, 0xd1523f0d45536884u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x7d2131ef489c5089u, 0xd1523f0d45536884u}> {
    struct details {
        
    };
    using Type = pf::E5;
    constexpr static ID TypeID = pf::meta::details::ID{0x7d2131ef489c5089u, 0xd1523f0d45536884u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x616b8ad449ed4483u, 0xd1c8a4e1aab48581u}, pf::meta::details::ID{0x2d67c0993d449889u, 0x2ca925dab7fff796u}, pf::meta::details::ID{0x65ffaade57047d3au, 0x468cc217f85f1a01u}, pf::meta::details::ID{0x4cd177a95c39f7d7u, 0xdab4b167b8974003u}, pf::meta::details::ID{0x66239075a9d0f86fu, 0x3efc590e5b19fbf0u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x34c8fcb46eed58au, 0x6a5b8e045342d2f7u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x34c8fcb46eed58au, 0x6a5b8e045342d2f7u}, pf::meta::details::ID{0x7d2131ef489c5089u, 0xd1523f0d45536884u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x2e6b547589c29c5du, 0xf1c3c341288f76dbu}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x2e6b547589c29c5du, 0xf1c3c341288f76dbu}, pf::meta::details::ID{0x7d2131ef489c5089u, 0xd1523f0d45536884u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x21a452eef0f4d555u, 0x4daba0a126bf650u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x21a452eef0f4d555u, 0x4daba0a126bf650u}, pf::meta::details::ID{0x7d2131ef489c5089u, 0xd1523f0d45536884u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x2312501d2e7e4302u, 0xf4f509fa465a22d4u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x2312501d2e7e4302u, 0xf4f509fa465a22d4u}, pf::meta::details::ID{0x7d2131ef489c5089u, 0xd1523f0d45536884u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x64a1f8d7e3bba210u, 0x14ba9a3150742ef1u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x64a1f8d7e3bba210u, 0x14ba9a3150742ef1u}, pf::meta::details::ID{0x7d2131ef489c5089u, 0xd1523f0d45536884u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x72d79f4bcb82021au, 0xe29f93bf09b209a2u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x72d79f4bcb82021au, 0xe29f93bf09b209a2u}, pf::meta::details::ID{0x7d2131ef489c5089u, 0xd1523f0d45536884u}> {};

/****************************** pf::E5 END ******************************/
namespace pf::meta::details {
/****************************** pf::E5 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5>() {
    return pf::meta::details::ID{0x7d2131ef489c5089u, 0xd1523f0d45536884u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5>() {
    return pf::meta::details::ID{0x34c8fcb46eed58au, 0x6a5b8e045342d2f7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 &>() {
    return pf::meta::details::ID{0x2e6b547589c29c5du, 0xf1c3c341288f76dbu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 &&>() {
    return pf::meta::details::ID{0x21a452eef0f4d555u, 0x4daba0a126bf650u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5 &>() {
    return pf::meta::details::ID{0x2312501d2e7e4302u, 0xf4f509fa465a22d4u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 *>() {
    return pf::meta::details::ID{0x64a1f8d7e3bba210u, 0x14ba9a3150742ef1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5 *>() {
    return pf::meta::details::ID{0x72d79f4bcb82021au, 0xe29f93bf09b209a2u};
}
/****************************** pf::E5 END ******************************/

/****************************** pf::E5::pf::E5::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::A>() {
return pf::meta::details::ID{0x616b8ad449ed4483u, 0xd1c8a4e1aab48581u};
}
/****************************** pf::E5::pf::E5::A END ******************************/

/****************************** pf::E5::pf::E5::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::B>() {
return pf::meta::details::ID{0x2d67c0993d449889u, 0x2ca925dab7fff796u};
}
/****************************** pf::E5::pf::E5::B END ******************************/

/****************************** pf::E5::pf::E5::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::C>() {
return pf::meta::details::ID{0x65ffaade57047d3au, 0x468cc217f85f1a01u};
}
/****************************** pf::E5::pf::E5::C END ******************************/

/****************************** pf::E5::pf::E5::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::D>() {
return pf::meta::details::ID{0x4cd177a95c39f7d7u, 0xdab4b167b8974003u};
}
/****************************** pf::E5::pf::E5::D END ******************************/

/****************************** pf::E5::pf::E5::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::E>() {
return pf::meta::details::ID{0x66239075a9d0f86fu, 0x3efc590e5b19fbf0u};
}
/****************************** pf::E5::pf::E5::E END ******************************/
}
/****************************** pf::E6::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xc2f6ead0931f0ab5u, 0xc284ea2c07192894u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xc2f6ead0931f0ab5u, 0xc284ea2c07192894u};
    constexpr static ID TypeID = pf::meta::details::ID{0xdaa3c40a9e1a1bb0u, 0xd31bc918996aaf61u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd5087f79d534e622u, 0xc2415ade94b8fcf8u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xd5087f79d534e622u, 0xc2415ade94b8fcf8u};
    constexpr static ID TypeID = pf::meta::details::ID{0xdaa3c40a9e1a1bb0u, 0xd31bc918996aaf61u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x4a10526a696450e2u, 0x7d984f68712a2d21u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x4a10526a696450e2u, 0x7d984f68712a2d21u};
    constexpr static ID TypeID = pf::meta::details::ID{0xdaa3c40a9e1a1bb0u, 0xd31bc918996aaf61u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd36eecd999a24288u, 0xbae09e7df88034beu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xd36eecd999a24288u, 0xbae09e7df88034beu};
    constexpr static ID TypeID = pf::meta::details::ID{0xdaa3c40a9e1a1bb0u, 0xd31bc918996aaf61u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x18fb2de1ed14e5f8u, 0x8a85b1f52c69806au}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x18fb2de1ed14e5f8u, 0x8a85b1f52c69806au};
    constexpr static ID TypeID = pf::meta::details::ID{0xdaa3c40a9e1a1bb0u, 0xd31bc918996aaf61u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xdaa3c40a9e1a1bb0u, 0xd31bc918996aaf61u}> {
    struct details {
        
    };
    using Type = pf::E6;
    constexpr static ID TypeID = pf::meta::details::ID{0xdaa3c40a9e1a1bb0u, 0xd31bc918996aaf61u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0xc2f6ead0931f0ab5u, 0xc284ea2c07192894u}, pf::meta::details::ID{0xd5087f79d534e622u, 0xc2415ade94b8fcf8u}, pf::meta::details::ID{0x4a10526a696450e2u, 0x7d984f68712a2d21u}, pf::meta::details::ID{0xd36eecd999a24288u, 0xbae09e7df88034beu}, pf::meta::details::ID{0x18fb2de1ed14e5f8u, 0x8a85b1f52c69806au});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x2e2dddbda9e518e4u, 0xb694345ef9192429u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x2e2dddbda9e518e4u, 0xb694345ef9192429u}, pf::meta::details::ID{0xdaa3c40a9e1a1bb0u, 0xd31bc918996aaf61u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x982dfe4003b10b7u, 0x3bd79b71338e65d1u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x982dfe4003b10b7u, 0x3bd79b71338e65d1u}, pf::meta::details::ID{0xdaa3c40a9e1a1bb0u, 0xd31bc918996aaf61u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb5b49140f725da61u, 0x9c3803f7971d01a5u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0xb5b49140f725da61u, 0x9c3803f7971d01a5u}, pf::meta::details::ID{0xdaa3c40a9e1a1bb0u, 0xd31bc918996aaf61u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x9cfc357d93ab11fdu, 0xedb7d46954ff7ed7u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x9cfc357d93ab11fdu, 0xedb7d46954ff7ed7u}, pf::meta::details::ID{0xdaa3c40a9e1a1bb0u, 0xd31bc918996aaf61u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x3b7b1007d893c430u, 0x9ce1ed3c73e0cbdbu}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x3b7b1007d893c430u, 0x9ce1ed3c73e0cbdbu}, pf::meta::details::ID{0xdaa3c40a9e1a1bb0u, 0xd31bc918996aaf61u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd8acd67e891a87d9u, 0xf92a2e4c375849ddu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0xd8acd67e891a87d9u, 0xf92a2e4c375849ddu}, pf::meta::details::ID{0xdaa3c40a9e1a1bb0u, 0xd31bc918996aaf61u}> {};

/****************************** pf::E6 END ******************************/
namespace pf::meta::details {
/****************************** pf::E6 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6>() {
    return pf::meta::details::ID{0xdaa3c40a9e1a1bb0u, 0xd31bc918996aaf61u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6>() {
    return pf::meta::details::ID{0x2e2dddbda9e518e4u, 0xb694345ef9192429u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 &>() {
    return pf::meta::details::ID{0x982dfe4003b10b7u, 0x3bd79b71338e65d1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 &&>() {
    return pf::meta::details::ID{0xb5b49140f725da61u, 0x9c3803f7971d01a5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6 &>() {
    return pf::meta::details::ID{0x9cfc357d93ab11fdu, 0xedb7d46954ff7ed7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 *>() {
    return pf::meta::details::ID{0x3b7b1007d893c430u, 0x9ce1ed3c73e0cbdbu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6 *>() {
    return pf::meta::details::ID{0xd8acd67e891a87d9u, 0xf92a2e4c375849ddu};
}
/****************************** pf::E6 END ******************************/

/****************************** pf::E6::pf::E6::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::A>() {
return pf::meta::details::ID{0xc2f6ead0931f0ab5u, 0xc284ea2c07192894u};
}
/****************************** pf::E6::pf::E6::A END ******************************/

/****************************** pf::E6::pf::E6::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::B>() {
return pf::meta::details::ID{0xd5087f79d534e622u, 0xc2415ade94b8fcf8u};
}
/****************************** pf::E6::pf::E6::B END ******************************/

/****************************** pf::E6::pf::E6::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::C>() {
return pf::meta::details::ID{0x4a10526a696450e2u, 0x7d984f68712a2d21u};
}
/****************************** pf::E6::pf::E6::C END ******************************/

/****************************** pf::E6::pf::E6::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::D>() {
return pf::meta::details::ID{0xd36eecd999a24288u, 0xbae09e7df88034beu};
}
/****************************** pf::E6::pf::E6::D END ******************************/

/****************************** pf::E6::pf::E6::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::E>() {
return pf::meta::details::ID{0x18fb2de1ed14e5f8u, 0x8a85b1f52c69806au};
}
/****************************** pf::E6::pf::E6::E END ******************************/
}
/****************************** pf::E7::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x845b9643a367012au, 0x5d54a842eb599259u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x845b9643a367012au, 0x5d54a842eb599259u};
    constexpr static ID TypeID = pf::meta::details::ID{0xda6f10e7b705b195u, 0x7682023f045af688u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xc5cf0ef75f7c58afu, 0x455e8b7816fd6819u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xc5cf0ef75f7c58afu, 0x455e8b7816fd6819u};
    constexpr static ID TypeID = pf::meta::details::ID{0xda6f10e7b705b195u, 0x7682023f045af688u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe6599213adb4a24cu, 0xf9797995d88a4ae9u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xe6599213adb4a24cu, 0xf9797995d88a4ae9u};
    constexpr static ID TypeID = pf::meta::details::ID{0xda6f10e7b705b195u, 0x7682023f045af688u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb69f4ab8203e1cb4u, 0x8011048a0d304094u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xb69f4ab8203e1cb4u, 0x8011048a0d304094u};
    constexpr static ID TypeID = pf::meta::details::ID{0xda6f10e7b705b195u, 0x7682023f045af688u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x7c3dfa946fa07adau, 0xeb4542b0c0626813u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x7c3dfa946fa07adau, 0xeb4542b0c0626813u};
    constexpr static ID TypeID = pf::meta::details::ID{0xda6f10e7b705b195u, 0x7682023f045af688u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xda6f10e7b705b195u, 0x7682023f045af688u}> {
    struct details {
        
    };
    using Type = pf::E7;
    constexpr static ID TypeID = pf::meta::details::ID{0xda6f10e7b705b195u, 0x7682023f045af688u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x845b9643a367012au, 0x5d54a842eb599259u}, pf::meta::details::ID{0xc5cf0ef75f7c58afu, 0x455e8b7816fd6819u}, pf::meta::details::ID{0xe6599213adb4a24cu, 0xf9797995d88a4ae9u}, pf::meta::details::ID{0xb69f4ab8203e1cb4u, 0x8011048a0d304094u}, pf::meta::details::ID{0x7c3dfa946fa07adau, 0xeb4542b0c0626813u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xabb5d954cde95be9u, 0x8ad5f37be85553d4u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0xabb5d954cde95be9u, 0x8ad5f37be85553d4u}, pf::meta::details::ID{0xda6f10e7b705b195u, 0x7682023f045af688u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x485e8156235912eeu, 0x9078a4a2a3c016c9u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x485e8156235912eeu, 0x9078a4a2a3c016c9u}, pf::meta::details::ID{0xda6f10e7b705b195u, 0x7682023f045af688u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xbd59ccaf040b337cu, 0xf3dfc9624c138fd0u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0xbd59ccaf040b337cu, 0xf3dfc9624c138fd0u}, pf::meta::details::ID{0xda6f10e7b705b195u, 0x7682023f045af688u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xc711eb8505ffcc68u, 0x52bae3f701cf2efu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0xc711eb8505ffcc68u, 0x52bae3f701cf2efu}, pf::meta::details::ID{0xda6f10e7b705b195u, 0x7682023f045af688u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x1919ca9cf59373cu, 0x52afc5d0f6903effu}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x1919ca9cf59373cu, 0x52afc5d0f6903effu}, pf::meta::details::ID{0xda6f10e7b705b195u, 0x7682023f045af688u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x2139f66e93c134ddu, 0xae2bcc32cc56a6a7u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x2139f66e93c134ddu, 0xae2bcc32cc56a6a7u}, pf::meta::details::ID{0xda6f10e7b705b195u, 0x7682023f045af688u}> {};

/****************************** pf::E7 END ******************************/
namespace pf::meta::details {
/****************************** pf::E7 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7>() {
    return pf::meta::details::ID{0xda6f10e7b705b195u, 0x7682023f045af688u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7>() {
    return pf::meta::details::ID{0xabb5d954cde95be9u, 0x8ad5f37be85553d4u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 &>() {
    return pf::meta::details::ID{0x485e8156235912eeu, 0x9078a4a2a3c016c9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 &&>() {
    return pf::meta::details::ID{0xbd59ccaf040b337cu, 0xf3dfc9624c138fd0u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7 &>() {
    return pf::meta::details::ID{0xc711eb8505ffcc68u, 0x52bae3f701cf2efu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 *>() {
    return pf::meta::details::ID{0x1919ca9cf59373cu, 0x52afc5d0f6903effu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7 *>() {
    return pf::meta::details::ID{0x2139f66e93c134ddu, 0xae2bcc32cc56a6a7u};
}
/****************************** pf::E7 END ******************************/

/****************************** pf::E7::pf::E7::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::A>() {
return pf::meta::details::ID{0x845b9643a367012au, 0x5d54a842eb599259u};
}
/****************************** pf::E7::pf::E7::A END ******************************/

/****************************** pf::E7::pf::E7::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::B>() {
return pf::meta::details::ID{0xc5cf0ef75f7c58afu, 0x455e8b7816fd6819u};
}
/****************************** pf::E7::pf::E7::B END ******************************/

/****************************** pf::E7::pf::E7::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::C>() {
return pf::meta::details::ID{0xe6599213adb4a24cu, 0xf9797995d88a4ae9u};
}
/****************************** pf::E7::pf::E7::C END ******************************/

/****************************** pf::E7::pf::E7::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::D>() {
return pf::meta::details::ID{0xb69f4ab8203e1cb4u, 0x8011048a0d304094u};
}
/****************************** pf::E7::pf::E7::D END ******************************/

/****************************** pf::E7::pf::E7::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::E>() {
return pf::meta::details::ID{0x7c3dfa946fa07adau, 0xeb4542b0c0626813u};
}
/****************************** pf::E7::pf::E7::E END ******************************/
}
/****************************** pf::E8::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x7ba52aff7c345ec1u, 0x251edd0fab193d6cu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x7ba52aff7c345ec1u, 0x251edd0fab193d6cu};
    constexpr static ID TypeID = pf::meta::details::ID{0x36355f64157a5d6eu, 0xe6e8fc69b0e47a1eu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x13995ee2ac23d489u, 0x8d8b0c2f3eff59dfu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x13995ee2ac23d489u, 0x8d8b0c2f3eff59dfu};
    constexpr static ID TypeID = pf::meta::details::ID{0x36355f64157a5d6eu, 0xe6e8fc69b0e47a1eu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa1f80a4f7383cbc9u, 0x421d6cc5411aedf0u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xa1f80a4f7383cbc9u, 0x421d6cc5411aedf0u};
    constexpr static ID TypeID = pf::meta::details::ID{0x36355f64157a5d6eu, 0xe6e8fc69b0e47a1eu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xfe1de4f82a9754dcu, 0x531a4e158df7a822u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xfe1de4f82a9754dcu, 0x531a4e158df7a822u};
    constexpr static ID TypeID = pf::meta::details::ID{0x36355f64157a5d6eu, 0xe6e8fc69b0e47a1eu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x42728d3173fc934fu, 0x4689886a8d4cebeau}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x42728d3173fc934fu, 0x4689886a8d4cebeau};
    constexpr static ID TypeID = pf::meta::details::ID{0x36355f64157a5d6eu, 0xe6e8fc69b0e47a1eu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x36355f64157a5d6eu, 0xe6e8fc69b0e47a1eu}> {
    struct details {
        
    };
    using Type = pf::E8;
    constexpr static ID TypeID = pf::meta::details::ID{0x36355f64157a5d6eu, 0xe6e8fc69b0e47a1eu};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x7ba52aff7c345ec1u, 0x251edd0fab193d6cu}, pf::meta::details::ID{0x13995ee2ac23d489u, 0x8d8b0c2f3eff59dfu}, pf::meta::details::ID{0xa1f80a4f7383cbc9u, 0x421d6cc5411aedf0u}, pf::meta::details::ID{0xfe1de4f82a9754dcu, 0x531a4e158df7a822u}, pf::meta::details::ID{0x42728d3173fc934fu, 0x4689886a8d4cebeau});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xc347ac3898a6d96bu, 0x74cbd4a34b4b38c6u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0xc347ac3898a6d96bu, 0x74cbd4a34b4b38c6u}, pf::meta::details::ID{0x36355f64157a5d6eu, 0xe6e8fc69b0e47a1eu}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x913ac76f188f2e31u, 0x7acb05388629897cu}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x913ac76f188f2e31u, 0x7acb05388629897cu}, pf::meta::details::ID{0x36355f64157a5d6eu, 0xe6e8fc69b0e47a1eu}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x6e6779157788a95au, 0x276823d0534dfe3u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x6e6779157788a95au, 0x276823d0534dfe3u}, pf::meta::details::ID{0x36355f64157a5d6eu, 0xe6e8fc69b0e47a1eu}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x1e9bd3bfc9ce3c2bu, 0x3ddf0b28afe80afdu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x1e9bd3bfc9ce3c2bu, 0x3ddf0b28afe80afdu}, pf::meta::details::ID{0x36355f64157a5d6eu, 0xe6e8fc69b0e47a1eu}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xc7235d3bc9606fa0u, 0x643a26f181d51137u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0xc7235d3bc9606fa0u, 0x643a26f181d51137u}, pf::meta::details::ID{0x36355f64157a5d6eu, 0xe6e8fc69b0e47a1eu}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x51d7de84db588257u, 0x4708722b69297f0eu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x51d7de84db588257u, 0x4708722b69297f0eu}, pf::meta::details::ID{0x36355f64157a5d6eu, 0xe6e8fc69b0e47a1eu}> {};

/****************************** pf::E8 END ******************************/
namespace pf::meta::details {
/****************************** pf::E8 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8>() {
    return pf::meta::details::ID{0x36355f64157a5d6eu, 0xe6e8fc69b0e47a1eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8>() {
    return pf::meta::details::ID{0xc347ac3898a6d96bu, 0x74cbd4a34b4b38c6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 &>() {
    return pf::meta::details::ID{0x913ac76f188f2e31u, 0x7acb05388629897cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 &&>() {
    return pf::meta::details::ID{0x6e6779157788a95au, 0x276823d0534dfe3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8 &>() {
    return pf::meta::details::ID{0x1e9bd3bfc9ce3c2bu, 0x3ddf0b28afe80afdu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 *>() {
    return pf::meta::details::ID{0xc7235d3bc9606fa0u, 0x643a26f181d51137u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8 *>() {
    return pf::meta::details::ID{0x51d7de84db588257u, 0x4708722b69297f0eu};
}
/****************************** pf::E8 END ******************************/

/****************************** pf::E8::pf::E8::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::A>() {
return pf::meta::details::ID{0x7ba52aff7c345ec1u, 0x251edd0fab193d6cu};
}
/****************************** pf::E8::pf::E8::A END ******************************/

/****************************** pf::E8::pf::E8::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::B>() {
return pf::meta::details::ID{0x13995ee2ac23d489u, 0x8d8b0c2f3eff59dfu};
}
/****************************** pf::E8::pf::E8::B END ******************************/

/****************************** pf::E8::pf::E8::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::C>() {
return pf::meta::details::ID{0xa1f80a4f7383cbc9u, 0x421d6cc5411aedf0u};
}
/****************************** pf::E8::pf::E8::C END ******************************/

/****************************** pf::E8::pf::E8::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::D>() {
return pf::meta::details::ID{0xfe1de4f82a9754dcu, 0x531a4e158df7a822u};
}
/****************************** pf::E8::pf::E8::D END ******************************/

/****************************** pf::E8::pf::E8::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::E>() {
return pf::meta::details::ID{0x42728d3173fc934fu, 0x4689886a8d4cebeau};
}
/****************************** pf::E8::pf::E8::E END ******************************/
}
/****************************** pf::E9::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd79a42ff3af45a6u, 0xddbc08d8219e6125u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xd79a42ff3af45a6u, 0xddbc08d8219e6125u};
    constexpr static ID TypeID = pf::meta::details::ID{0x96960c2a5d1fb439u, 0x2801c86fe5ef55acu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xfad0e83a80d50410u, 0x4ac62bd735378dc2u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xfad0e83a80d50410u, 0x4ac62bd735378dc2u};
    constexpr static ID TypeID = pf::meta::details::ID{0x96960c2a5d1fb439u, 0x2801c86fe5ef55acu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x428d7bc0da76ff6eu, 0xbeed99264f4a9e22u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x428d7bc0da76ff6eu, 0xbeed99264f4a9e22u};
    constexpr static ID TypeID = pf::meta::details::ID{0x96960c2a5d1fb439u, 0x2801c86fe5ef55acu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x1d993127f6b1b389u, 0x84329239c724a68fu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x1d993127f6b1b389u, 0x84329239c724a68fu};
    constexpr static ID TypeID = pf::meta::details::ID{0x96960c2a5d1fb439u, 0x2801c86fe5ef55acu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x676d679818dec894u, 0x3ea79605285f158bu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x676d679818dec894u, 0x3ea79605285f158bu};
    constexpr static ID TypeID = pf::meta::details::ID{0x96960c2a5d1fb439u, 0x2801c86fe5ef55acu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x96960c2a5d1fb439u, 0x2801c86fe5ef55acu}> {
    struct details {
        
    };
    using Type = pf::E9;
    constexpr static ID TypeID = pf::meta::details::ID{0x96960c2a5d1fb439u, 0x2801c86fe5ef55acu};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0xd79a42ff3af45a6u, 0xddbc08d8219e6125u}, pf::meta::details::ID{0xfad0e83a80d50410u, 0x4ac62bd735378dc2u}, pf::meta::details::ID{0x428d7bc0da76ff6eu, 0xbeed99264f4a9e22u}, pf::meta::details::ID{0x1d993127f6b1b389u, 0x84329239c724a68fu}, pf::meta::details::ID{0x676d679818dec894u, 0x3ea79605285f158bu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x6f6c607dedfd9997u, 0x36c645af3ec7d5f9u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x6f6c607dedfd9997u, 0x36c645af3ec7d5f9u}, pf::meta::details::ID{0x96960c2a5d1fb439u, 0x2801c86fe5ef55acu}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x16f7d76f1e1cf68bu, 0x77f5801aa0aa9216u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x16f7d76f1e1cf68bu, 0x77f5801aa0aa9216u}, pf::meta::details::ID{0x96960c2a5d1fb439u, 0x2801c86fe5ef55acu}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x21a91cc2b531a31fu, 0x5b5eac7ab650cad2u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x21a91cc2b531a31fu, 0x5b5eac7ab650cad2u}, pf::meta::details::ID{0x96960c2a5d1fb439u, 0x2801c86fe5ef55acu}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd2e084814307bb07u, 0x9f63d6cae7f7a426u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0xd2e084814307bb07u, 0x9f63d6cae7f7a426u}, pf::meta::details::ID{0x96960c2a5d1fb439u, 0x2801c86fe5ef55acu}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x6b0d038ae6c3130fu, 0x22dca073923dbf8au}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x6b0d038ae6c3130fu, 0x22dca073923dbf8au}, pf::meta::details::ID{0x96960c2a5d1fb439u, 0x2801c86fe5ef55acu}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x911b826ca32390b1u, 0x32e387e3b8f77c9du}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x911b826ca32390b1u, 0x32e387e3b8f77c9du}, pf::meta::details::ID{0x96960c2a5d1fb439u, 0x2801c86fe5ef55acu}> {};

/****************************** pf::E9 END ******************************/
namespace pf::meta::details {
/****************************** pf::E9 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9>() {
    return pf::meta::details::ID{0x96960c2a5d1fb439u, 0x2801c86fe5ef55acu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9>() {
    return pf::meta::details::ID{0x6f6c607dedfd9997u, 0x36c645af3ec7d5f9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 &>() {
    return pf::meta::details::ID{0x16f7d76f1e1cf68bu, 0x77f5801aa0aa9216u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 &&>() {
    return pf::meta::details::ID{0x21a91cc2b531a31fu, 0x5b5eac7ab650cad2u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9 &>() {
    return pf::meta::details::ID{0xd2e084814307bb07u, 0x9f63d6cae7f7a426u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 *>() {
    return pf::meta::details::ID{0x6b0d038ae6c3130fu, 0x22dca073923dbf8au};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9 *>() {
    return pf::meta::details::ID{0x911b826ca32390b1u, 0x32e387e3b8f77c9du};
}
/****************************** pf::E9 END ******************************/

/****************************** pf::E9::pf::E9::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::A>() {
return pf::meta::details::ID{0xd79a42ff3af45a6u, 0xddbc08d8219e6125u};
}
/****************************** pf::E9::pf::E9::A END ******************************/

/****************************** pf::E9::pf::E9::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::B>() {
return pf::meta::details::ID{0xfad0e83a80d50410u, 0x4ac62bd735378dc2u};
}
/****************************** pf::E9::pf::E9::B END ******************************/

/****************************** pf::E9::pf::E9::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::C>() {
return pf::meta::details::ID{0x428d7bc0da76ff6eu, 0xbeed99264f4a9e22u};
}
/****************************** pf::E9::pf::E9::C END ******************************/

/****************************** pf::E9::pf::E9::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::D>() {
return pf::meta::details::ID{0x1d993127f6b1b389u, 0x84329239c724a68fu};
}
/****************************** pf::E9::pf::E9::D END ******************************/

/****************************** pf::E9::pf::E9::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::E>() {
return pf::meta::details::ID{0x676d679818dec894u, 0x3ea79605285f158bu};
}
/****************************** pf::E9::pf::E9::E END ******************************/
}

