
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x80520528a8155d85u, 0x699ef4534504b682u}> {
    struct details {
        constexpr static auto ArgArray_12760218949468296714 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_10183209169220410650 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_18230941654585432042 = pf::make_array<std::string_view>();

    };
    constexpr static ID ValueID = pf::meta::details::ID{0x80520528a8155d85u, 0x699ef4534504b682u};
    constexpr static ID TypeID = pf::meta::details::ID{0x5eaa62a329abf123u, 0x354d0b3359cdf306u};
    using Type = pf::SomeEnum;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(pf::meta::Attribute{"pf::test", std::span<const std::string_view>{details::ArgArray_12760218949468296714}}, pf::meta::Attribute{"pf::test2", std::span<const std::string_view>{details::ArgArray_10183209169220410650}}, pf::meta::Attribute{"pf::test3", std::span<const std::string_view>{details::ArgArray_18230941654585432042}});

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"Value1"};
    constexpr static auto FullName = StringLiteral{"pf::SomeEnum::Value1"};

    constexpr static bool UnderlyingValue = false;
    constexpr static pf::SomeEnum Value = pf::SomeEnum::Value1;
};
/****************************** pf::SomeEnum::Value1 END ******************************/

/****************************** pf::SomeEnum::Value2 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa31b48d763f7979au, 0x8c84ee3752e32867u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xa31b48d763f7979au, 0x8c84ee3752e32867u};
    constexpr static ID TypeID = pf::meta::details::ID{0x5eaa62a329abf123u, 0x354d0b3359cdf306u};
    using Type = pf::SomeEnum;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"Value2"};
    constexpr static auto FullName = StringLiteral{"pf::SomeEnum::Value2"};

    constexpr static bool UnderlyingValue = true;
    constexpr static pf::SomeEnum Value = pf::SomeEnum::Value2;
};
/****************************** pf::SomeEnum::Value2 END ******************************/

/****************************** pf::SomeEnum START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x5eaa62a329abf123u, 0x354d0b3359cdf306u}> {
    struct details {
        constexpr static auto ArgArray_8805692778198213553 = pf::make_array<std::string_view>(R"arg(()()()((())))arg", R"arg([[nodiscard]])arg", R"arg(1ll)arg", R"arg(1.011)arg", R"arg([]{}())arg", R"arg("yeet")arg", R"arg('a')arg", R"arg([][][]:::3214234...[][][][])arg");
constexpr static auto ArgArray_10497485221286886480 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_4677983224106550177 = pf::make_array<std::string_view>(R"arg(1ll)arg", R"arg(1.011)arg", R"arg("yeet")arg");
constexpr static auto ArgArray_14086371373015974792 = pf::make_array<std::string_view>();

    };
    using Type = pf::SomeEnum;
    constexpr static ID TypeID = pf::meta::details::ID{0x5eaa62a329abf123u, 0x354d0b3359cdf306u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(pf::meta::Attribute{"pf::operators", std::span<const std::string_view>{details::ArgArray_8805692778198213553}}, pf::meta::Attribute{"pf::hihi", std::span<const std::string_view>{details::ArgArray_10497485221286886480}}, pf::meta::Attribute{"pf::operators2", std::span<const std::string_view>{details::ArgArray_4677983224106550177}}, pf::meta::Attribute{"pf::hihi2", std::span<const std::string_view>{details::ArgArray_14086371373015974792}});

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"SomeEnum"};
    constexpr static auto FullName = pf::StringLiteral{"pf::SomeEnum"};

    using UnderlyingType = bool;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x80520528a8155d85u, 0x699ef4534504b682u}, pf::meta::details::ID{0xa31b48d763f7979au, 0x8c84ee3752e32867u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x1dcb47411842fd4bu, 0xbc13c62f986010f7u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x1dcb47411842fd4bu, 0xbc13c62f986010f7u}, pf::meta::details::ID{0x5eaa62a329abf123u, 0x354d0b3359cdf306u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x16d674458dadfff2u, 0x1a328ea46a47c279u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x16d674458dadfff2u, 0x1a328ea46a47c279u}, pf::meta::details::ID{0x5eaa62a329abf123u, 0x354d0b3359cdf306u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x5156b43da1f90e1bu, 0xd7adf1b3dd6df61eu}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x5156b43da1f90e1bu, 0xd7adf1b3dd6df61eu}, pf::meta::details::ID{0x5eaa62a329abf123u, 0x354d0b3359cdf306u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x601751a2a78a5fa4u, 0x198960ed8ed5d5c9u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x601751a2a78a5fa4u, 0x198960ed8ed5d5c9u}, pf::meta::details::ID{0x5eaa62a329abf123u, 0x354d0b3359cdf306u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x6717ca739daf1261u, 0x612d4d6375c3d62du}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x6717ca739daf1261u, 0x612d4d6375c3d62du}, pf::meta::details::ID{0x5eaa62a329abf123u, 0x354d0b3359cdf306u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x42086fc098fc6bfeu, 0x8703e53117642325u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x42086fc098fc6bfeu, 0x8703e53117642325u}, pf::meta::details::ID{0x5eaa62a329abf123u, 0x354d0b3359cdf306u}> {};

/****************************** pf::SomeEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::SomeEnum START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum>() {
    return pf::meta::details::ID{0x5eaa62a329abf123u, 0x354d0b3359cdf306u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum>() {
    return pf::meta::details::ID{0x1dcb47411842fd4bu, 0xbc13c62f986010f7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum &>() {
    return pf::meta::details::ID{0x16d674458dadfff2u, 0x1a328ea46a47c279u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum &&>() {
    return pf::meta::details::ID{0x5156b43da1f90e1bu, 0xd7adf1b3dd6df61eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum &>() {
    return pf::meta::details::ID{0x601751a2a78a5fa4u, 0x198960ed8ed5d5c9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum *>() {
    return pf::meta::details::ID{0x6717ca739daf1261u, 0x612d4d6375c3d62du};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum *>() {
    return pf::meta::details::ID{0x42086fc098fc6bfeu, 0x8703e53117642325u};
}
/****************************** pf::SomeEnum END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value1 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value1>() {
return pf::meta::details::ID{0x80520528a8155d85u, 0x699ef4534504b682u};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value1 END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value2 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value2>() {
return pf::meta::details::ID{0xa31b48d763f7979au, 0x8c84ee3752e32867u};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value2 END ******************************/
}
/****************************** pf::Test::E::Value1 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x5a44924497a2bf31u, 0x150f6f63589e0b79u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x5a44924497a2bf31u, 0x150f6f63589e0b79u};
    constexpr static ID TypeID = pf::meta::details::ID{0x972c856574ddb8e3u, 0xac918081c83f1806u};
    using Type = pf::Test::E;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 8;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"Value1"};
    constexpr static auto FullName = StringLiteral{"pf::Test::E::Value1"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::Test::E Value = pf::Test::E::Value1;
};
/****************************** pf::Test::E::Value1 END ******************************/

/****************************** pf::Test::E::Value2 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x9fcc696524e80d20u, 0x12435212527640ceu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x9fcc696524e80d20u, 0x12435212527640ceu};
    constexpr static ID TypeID = pf::meta::details::ID{0x972c856574ddb8e3u, 0xac918081c83f1806u};
    using Type = pf::Test::E;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 8;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"Value2"};
    constexpr static auto FullName = StringLiteral{"pf::Test::E::Value2"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::Test::E Value = pf::Test::E::Value2;
};
/****************************** pf::Test::E::Value2 END ******************************/

/****************************** pf::Test::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x972c856574ddb8e3u, 0xac918081c83f1806u}> {
    struct details {
        
    };
    using Type = pf::Test::E;
    constexpr static ID TypeID = pf::meta::details::ID{0x972c856574ddb8e3u, 0xac918081c83f1806u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 8;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E"};
    constexpr static auto FullName = pf::StringLiteral{"pf::Test::E"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x5a44924497a2bf31u, 0x150f6f63589e0b79u}, pf::meta::details::ID{0x9fcc696524e80d20u, 0x12435212527640ceu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x72e2edfe08106344u, 0xe4d2327181b6abb0u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x72e2edfe08106344u, 0xe4d2327181b6abb0u}, pf::meta::details::ID{0x972c856574ddb8e3u, 0xac918081c83f1806u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb23a42921aad3b88u, 0x362691ad47b5f9d6u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0xb23a42921aad3b88u, 0x362691ad47b5f9d6u}, pf::meta::details::ID{0x972c856574ddb8e3u, 0xac918081c83f1806u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x238e09416b1b8d3u, 0xa108bcdeede86d23u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x238e09416b1b8d3u, 0xa108bcdeede86d23u}, pf::meta::details::ID{0x972c856574ddb8e3u, 0xac918081c83f1806u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x268d85f5a505d01cu, 0x94c00934d974ba88u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x268d85f5a505d01cu, 0x94c00934d974ba88u}, pf::meta::details::ID{0x972c856574ddb8e3u, 0xac918081c83f1806u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x2f6f4e3df07ff031u, 0x8c6a95fd37e71f6u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x2f6f4e3df07ff031u, 0x8c6a95fd37e71f6u}, pf::meta::details::ID{0x972c856574ddb8e3u, 0xac918081c83f1806u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd53f3d770e79027u, 0xdf3ad821169c9974u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0xd53f3d770e79027u, 0xdf3ad821169c9974u}, pf::meta::details::ID{0x972c856574ddb8e3u, 0xac918081c83f1806u}> {};

/****************************** pf::Test::E END ******************************/
namespace pf::meta::details {
/****************************** pf::Test::E START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E>() {
    return pf::meta::details::ID{0x972c856574ddb8e3u, 0xac918081c83f1806u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E>() {
    return pf::meta::details::ID{0x72e2edfe08106344u, 0xe4d2327181b6abb0u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E &>() {
    return pf::meta::details::ID{0xb23a42921aad3b88u, 0x362691ad47b5f9d6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E &&>() {
    return pf::meta::details::ID{0x238e09416b1b8d3u, 0xa108bcdeede86d23u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E &>() {
    return pf::meta::details::ID{0x268d85f5a505d01cu, 0x94c00934d974ba88u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E *>() {
    return pf::meta::details::ID{0x2f6f4e3df07ff031u, 0x8c6a95fd37e71f6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E *>() {
    return pf::meta::details::ID{0xd53f3d770e79027u, 0xdf3ad821169c9974u};
}
/****************************** pf::Test::E END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value1 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::Test::E::Value1>() {
return pf::meta::details::ID{0x5a44924497a2bf31u, 0x150f6f63589e0b79u};
}
/****************************** pf::Test::E::pf::Test::E::Value1 END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value2 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::Test::E::Value2>() {
return pf::meta::details::ID{0x9fcc696524e80d20u, 0x12435212527640ceu};
}
/****************************** pf::Test::E::pf::Test::E::Value2 END ******************************/
}
/****************************** pf::EmptyEnum START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x7f87276bbc667004u, 0xa27ae12d73b3d8e6u}> {
    struct details {
        
    };
    using Type = pf::EmptyEnum;
    constexpr static ID TypeID = pf::meta::details::ID{0x7f87276bbc667004u, 0xa27ae12d73b3d8e6u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 19;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x67a70414df79a921u, 0xc17f0033db2928bfu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x67a70414df79a921u, 0xc17f0033db2928bfu}, pf::meta::details::ID{0x7f87276bbc667004u, 0xa27ae12d73b3d8e6u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe846a78a7b14d2cbu, 0xb8980f33dba7d121u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0xe846a78a7b14d2cbu, 0xb8980f33dba7d121u}, pf::meta::details::ID{0x7f87276bbc667004u, 0xa27ae12d73b3d8e6u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x7b325dd0b05b3664u, 0x44b0e506be224c3au}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x7b325dd0b05b3664u, 0x44b0e506be224c3au}, pf::meta::details::ID{0x7f87276bbc667004u, 0xa27ae12d73b3d8e6u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x11339b1e98fa7ff9u, 0xc0fa69cda4d9061du}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x11339b1e98fa7ff9u, 0xc0fa69cda4d9061du}, pf::meta::details::ID{0x7f87276bbc667004u, 0xa27ae12d73b3d8e6u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x2d73bbdc0987c0d5u, 0xaa793ccccb34a2ccu}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x2d73bbdc0987c0d5u, 0xaa793ccccb34a2ccu}, pf::meta::details::ID{0x7f87276bbc667004u, 0xa27ae12d73b3d8e6u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb775063eb5248d69u, 0x6a9001af7e7a55eu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0xb775063eb5248d69u, 0x6a9001af7e7a55eu}, pf::meta::details::ID{0x7f87276bbc667004u, 0xa27ae12d73b3d8e6u}> {};

/****************************** pf::EmptyEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::EmptyEnum START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum>() {
    return pf::meta::details::ID{0x7f87276bbc667004u, 0xa27ae12d73b3d8e6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum>() {
    return pf::meta::details::ID{0x67a70414df79a921u, 0xc17f0033db2928bfu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &>() {
    return pf::meta::details::ID{0xe846a78a7b14d2cbu, 0xb8980f33dba7d121u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &&>() {
    return pf::meta::details::ID{0x7b325dd0b05b3664u, 0x44b0e506be224c3au};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum &>() {
    return pf::meta::details::ID{0x11339b1e98fa7ff9u, 0xc0fa69cda4d9061du};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum *>() {
    return pf::meta::details::ID{0x2d73bbdc0987c0d5u, 0xaa793ccccb34a2ccu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum *>() {
    return pf::meta::details::ID{0xb775063eb5248d69u, 0x6a9001af7e7a55eu};
}
/****************************** pf::EmptyEnum END ******************************/
}
/****************************** pf::E1::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x66858656cc992e3u, 0x322682f22a47fc87u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x66858656cc992e3u, 0x322682f22a47fc87u};
    constexpr static ID TypeID = pf::meta::details::ID{0x4759ccddfcb45cd4u, 0x41ef0909e8fbd04au};
    using Type = pf::E1;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E1::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E1 Value = pf::E1::A;
};
/****************************** pf::E1::A END ******************************/

/****************************** pf::E1::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xcb1a82121dfc2baeu, 0x17a4749c0f988a20u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xcb1a82121dfc2baeu, 0x17a4749c0f988a20u};
    constexpr static ID TypeID = pf::meta::details::ID{0x4759ccddfcb45cd4u, 0x41ef0909e8fbd04au};
    using Type = pf::E1;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E1::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E1 Value = pf::E1::B;
};
/****************************** pf::E1::B END ******************************/

/****************************** pf::E1::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xf52602160f593acu, 0x64e88b1231fb14a9u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xf52602160f593acu, 0x64e88b1231fb14a9u};
    constexpr static ID TypeID = pf::meta::details::ID{0x4759ccddfcb45cd4u, 0x41ef0909e8fbd04au};
    using Type = pf::E1;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E1::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E1 Value = pf::E1::C;
};
/****************************** pf::E1::C END ******************************/

/****************************** pf::E1::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xc891cf6d60fcfc53u, 0xb6e05d4964106199u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xc891cf6d60fcfc53u, 0xb6e05d4964106199u};
    constexpr static ID TypeID = pf::meta::details::ID{0x4759ccddfcb45cd4u, 0x41ef0909e8fbd04au};
    using Type = pf::E1;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E1::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E1 Value = pf::E1::D;
};
/****************************** pf::E1::D END ******************************/

/****************************** pf::E1::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x40e19d5ee715b0feu, 0x426dac1ec62e8d5cu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x40e19d5ee715b0feu, 0x426dac1ec62e8d5cu};
    constexpr static ID TypeID = pf::meta::details::ID{0x4759ccddfcb45cd4u, 0x41ef0909e8fbd04au};
    using Type = pf::E1;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E1::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E1 Value = pf::E1::E;
};
/****************************** pf::E1::E END ******************************/

/****************************** pf::E1 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x4759ccddfcb45cd4u, 0x41ef0909e8fbd04au}> {
    struct details {
        
    };
    using Type = pf::E1;
    constexpr static ID TypeID = pf::meta::details::ID{0x4759ccddfcb45cd4u, 0x41ef0909e8fbd04au};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E1"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E1"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x66858656cc992e3u, 0x322682f22a47fc87u}, pf::meta::details::ID{0xcb1a82121dfc2baeu, 0x17a4749c0f988a20u}, pf::meta::details::ID{0xf52602160f593acu, 0x64e88b1231fb14a9u}, pf::meta::details::ID{0xc891cf6d60fcfc53u, 0xb6e05d4964106199u}, pf::meta::details::ID{0x40e19d5ee715b0feu, 0x426dac1ec62e8d5cu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x43dcd84ffc825ba8u, 0xa4f20111e4b6a09au}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x43dcd84ffc825ba8u, 0xa4f20111e4b6a09au}, pf::meta::details::ID{0x4759ccddfcb45cd4u, 0x41ef0909e8fbd04au}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x9c067e0fbe853bafu, 0x5b4cc94775ef7fa9u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x9c067e0fbe853bafu, 0x5b4cc94775ef7fa9u}, pf::meta::details::ID{0x4759ccddfcb45cd4u, 0x41ef0909e8fbd04au}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x2f9b997a4596f8c8u, 0x4541817d91d1eebcu}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x2f9b997a4596f8c8u, 0x4541817d91d1eebcu}, pf::meta::details::ID{0x4759ccddfcb45cd4u, 0x41ef0909e8fbd04au}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x30c2cac9a1a748afu, 0xcfe0ba45c28050e4u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x30c2cac9a1a748afu, 0xcfe0ba45c28050e4u}, pf::meta::details::ID{0x4759ccddfcb45cd4u, 0x41ef0909e8fbd04au}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x3cdb336bdd0fae52u, 0x6ea47b61132f1414u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x3cdb336bdd0fae52u, 0x6ea47b61132f1414u}, pf::meta::details::ID{0x4759ccddfcb45cd4u, 0x41ef0909e8fbd04au}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xf0659ad9b159f4d6u, 0xac7ce8ef6c96d01du}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0xf0659ad9b159f4d6u, 0xac7ce8ef6c96d01du}, pf::meta::details::ID{0x4759ccddfcb45cd4u, 0x41ef0909e8fbd04au}> {};

/****************************** pf::E1 END ******************************/
namespace pf::meta::details {
/****************************** pf::E1 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1>() {
    return pf::meta::details::ID{0x4759ccddfcb45cd4u, 0x41ef0909e8fbd04au};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1>() {
    return pf::meta::details::ID{0x43dcd84ffc825ba8u, 0xa4f20111e4b6a09au};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 &>() {
    return pf::meta::details::ID{0x9c067e0fbe853bafu, 0x5b4cc94775ef7fa9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 &&>() {
    return pf::meta::details::ID{0x2f9b997a4596f8c8u, 0x4541817d91d1eebcu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1 &>() {
    return pf::meta::details::ID{0x30c2cac9a1a748afu, 0xcfe0ba45c28050e4u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 *>() {
    return pf::meta::details::ID{0x3cdb336bdd0fae52u, 0x6ea47b61132f1414u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1 *>() {
    return pf::meta::details::ID{0xf0659ad9b159f4d6u, 0xac7ce8ef6c96d01du};
}
/****************************** pf::E1 END ******************************/

/****************************** pf::E1::pf::E1::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::A>() {
return pf::meta::details::ID{0x66858656cc992e3u, 0x322682f22a47fc87u};
}
/****************************** pf::E1::pf::E1::A END ******************************/

/****************************** pf::E1::pf::E1::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::B>() {
return pf::meta::details::ID{0xcb1a82121dfc2baeu, 0x17a4749c0f988a20u};
}
/****************************** pf::E1::pf::E1::B END ******************************/

/****************************** pf::E1::pf::E1::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::C>() {
return pf::meta::details::ID{0xf52602160f593acu, 0x64e88b1231fb14a9u};
}
/****************************** pf::E1::pf::E1::C END ******************************/

/****************************** pf::E1::pf::E1::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::D>() {
return pf::meta::details::ID{0xc891cf6d60fcfc53u, 0xb6e05d4964106199u};
}
/****************************** pf::E1::pf::E1::D END ******************************/

/****************************** pf::E1::pf::E1::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::E>() {
return pf::meta::details::ID{0x40e19d5ee715b0feu, 0x426dac1ec62e8d5cu};
}
/****************************** pf::E1::pf::E1::E END ******************************/
}
/****************************** pf::E2::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa39949f7e88ef09u, 0xd72d54510672bea7u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xa39949f7e88ef09u, 0xd72d54510672bea7u};
    constexpr static ID TypeID = pf::meta::details::ID{0x5c82089625506292u, 0x4b92c406180130b9u};
    using Type = pf::E2;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E2::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E2 Value = pf::E2::A;
};
/****************************** pf::E2::A END ******************************/

/****************************** pf::E2::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xda8f3b9ee25fad26u, 0xe606fd329aa0c12au}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xda8f3b9ee25fad26u, 0xe606fd329aa0c12au};
    constexpr static ID TypeID = pf::meta::details::ID{0x5c82089625506292u, 0x4b92c406180130b9u};
    using Type = pf::E2;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E2::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E2 Value = pf::E2::B;
};
/****************************** pf::E2::B END ******************************/

/****************************** pf::E2::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe2e5ba1110e8358au, 0xbe9ea798dd7d2570u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xe2e5ba1110e8358au, 0xbe9ea798dd7d2570u};
    constexpr static ID TypeID = pf::meta::details::ID{0x5c82089625506292u, 0x4b92c406180130b9u};
    using Type = pf::E2;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E2::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E2 Value = pf::E2::C;
};
/****************************** pf::E2::C END ******************************/

/****************************** pf::E2::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd26079a2b3ef20d4u, 0xacfb0597d14eea55u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xd26079a2b3ef20d4u, 0xacfb0597d14eea55u};
    constexpr static ID TypeID = pf::meta::details::ID{0x5c82089625506292u, 0x4b92c406180130b9u};
    using Type = pf::E2;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E2::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E2 Value = pf::E2::D;
};
/****************************** pf::E2::D END ******************************/

/****************************** pf::E2::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x40fe31833e2c63c2u, 0x59e4f748814a8dbu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x40fe31833e2c63c2u, 0x59e4f748814a8dbu};
    constexpr static ID TypeID = pf::meta::details::ID{0x5c82089625506292u, 0x4b92c406180130b9u};
    using Type = pf::E2;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E2::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E2 Value = pf::E2::E;
};
/****************************** pf::E2::E END ******************************/

/****************************** pf::E2 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x5c82089625506292u, 0x4b92c406180130b9u}> {
    struct details {
        
    };
    using Type = pf::E2;
    constexpr static ID TypeID = pf::meta::details::ID{0x5c82089625506292u, 0x4b92c406180130b9u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E2"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E2"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0xa39949f7e88ef09u, 0xd72d54510672bea7u}, pf::meta::details::ID{0xda8f3b9ee25fad26u, 0xe606fd329aa0c12au}, pf::meta::details::ID{0xe2e5ba1110e8358au, 0xbe9ea798dd7d2570u}, pf::meta::details::ID{0xd26079a2b3ef20d4u, 0xacfb0597d14eea55u}, pf::meta::details::ID{0x40fe31833e2c63c2u, 0x59e4f748814a8dbu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb6367bc1fd4ee9fu, 0x90a067ab6945ccefu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0xb6367bc1fd4ee9fu, 0x90a067ab6945ccefu}, pf::meta::details::ID{0x5c82089625506292u, 0x4b92c406180130b9u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd39c51aee8072df7u, 0x3c6e7900684486e8u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0xd39c51aee8072df7u, 0x3c6e7900684486e8u}, pf::meta::details::ID{0x5c82089625506292u, 0x4b92c406180130b9u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x4d750e055dee2252u, 0x56c502139f66cc51u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x4d750e055dee2252u, 0x56c502139f66cc51u}, pf::meta::details::ID{0x5c82089625506292u, 0x4b92c406180130b9u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x646d5548232f5b78u, 0x7be0802a2ebd4807u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x646d5548232f5b78u, 0x7be0802a2ebd4807u}, pf::meta::details::ID{0x5c82089625506292u, 0x4b92c406180130b9u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd799dc4f00b57953u, 0x46fea2dc61cfa8b7u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0xd799dc4f00b57953u, 0x46fea2dc61cfa8b7u}, pf::meta::details::ID{0x5c82089625506292u, 0x4b92c406180130b9u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x1b4b368944f41a7u, 0x4b7228c02a4575a6u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x1b4b368944f41a7u, 0x4b7228c02a4575a6u}, pf::meta::details::ID{0x5c82089625506292u, 0x4b92c406180130b9u}> {};

/****************************** pf::E2 END ******************************/
namespace pf::meta::details {
/****************************** pf::E2 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2>() {
    return pf::meta::details::ID{0x5c82089625506292u, 0x4b92c406180130b9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2>() {
    return pf::meta::details::ID{0xb6367bc1fd4ee9fu, 0x90a067ab6945ccefu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 &>() {
    return pf::meta::details::ID{0xd39c51aee8072df7u, 0x3c6e7900684486e8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 &&>() {
    return pf::meta::details::ID{0x4d750e055dee2252u, 0x56c502139f66cc51u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2 &>() {
    return pf::meta::details::ID{0x646d5548232f5b78u, 0x7be0802a2ebd4807u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 *>() {
    return pf::meta::details::ID{0xd799dc4f00b57953u, 0x46fea2dc61cfa8b7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2 *>() {
    return pf::meta::details::ID{0x1b4b368944f41a7u, 0x4b7228c02a4575a6u};
}
/****************************** pf::E2 END ******************************/

/****************************** pf::E2::pf::E2::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::A>() {
return pf::meta::details::ID{0xa39949f7e88ef09u, 0xd72d54510672bea7u};
}
/****************************** pf::E2::pf::E2::A END ******************************/

/****************************** pf::E2::pf::E2::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::B>() {
return pf::meta::details::ID{0xda8f3b9ee25fad26u, 0xe606fd329aa0c12au};
}
/****************************** pf::E2::pf::E2::B END ******************************/

/****************************** pf::E2::pf::E2::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::C>() {
return pf::meta::details::ID{0xe2e5ba1110e8358au, 0xbe9ea798dd7d2570u};
}
/****************************** pf::E2::pf::E2::C END ******************************/

/****************************** pf::E2::pf::E2::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::D>() {
return pf::meta::details::ID{0xd26079a2b3ef20d4u, 0xacfb0597d14eea55u};
}
/****************************** pf::E2::pf::E2::D END ******************************/

/****************************** pf::E2::pf::E2::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::E>() {
return pf::meta::details::ID{0x40fe31833e2c63c2u, 0x59e4f748814a8dbu};
}
/****************************** pf::E2::pf::E2::E END ******************************/
}
/****************************** pf::E3::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xc3138ee3c777e09bu, 0x3e696525aff96effu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xc3138ee3c777e09bu, 0x3e696525aff96effu};
    constexpr static ID TypeID = pf::meta::details::ID{0x2b8b5be364a054fau, 0x76de95a1dfa44bf6u};
    using Type = pf::E3;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E3::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E3 Value = pf::E3::A;
};
/****************************** pf::E3::A END ******************************/

/****************************** pf::E3::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x5a118ba910eb7215u, 0x75704caa8bad0c11u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x5a118ba910eb7215u, 0x75704caa8bad0c11u};
    constexpr static ID TypeID = pf::meta::details::ID{0x2b8b5be364a054fau, 0x76de95a1dfa44bf6u};
    using Type = pf::E3;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E3::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E3 Value = pf::E3::B;
};
/****************************** pf::E3::B END ******************************/

/****************************** pf::E3::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x59e145e33113a0f3u, 0x1ef8456acf315840u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x59e145e33113a0f3u, 0x1ef8456acf315840u};
    constexpr static ID TypeID = pf::meta::details::ID{0x2b8b5be364a054fau, 0x76de95a1dfa44bf6u};
    using Type = pf::E3;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E3::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E3 Value = pf::E3::C;
};
/****************************** pf::E3::C END ******************************/

/****************************** pf::E3::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe1d319c8e6dc66ccu, 0x341d63b5ef64880cu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xe1d319c8e6dc66ccu, 0x341d63b5ef64880cu};
    constexpr static ID TypeID = pf::meta::details::ID{0x2b8b5be364a054fau, 0x76de95a1dfa44bf6u};
    using Type = pf::E3;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E3::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E3 Value = pf::E3::D;
};
/****************************** pf::E3::D END ******************************/

/****************************** pf::E3::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xf5cecc1f2764bdb8u, 0x61dfb51d85cabfbeu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xf5cecc1f2764bdb8u, 0x61dfb51d85cabfbeu};
    constexpr static ID TypeID = pf::meta::details::ID{0x2b8b5be364a054fau, 0x76de95a1dfa44bf6u};
    using Type = pf::E3;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E3::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E3 Value = pf::E3::E;
};
/****************************** pf::E3::E END ******************************/

/****************************** pf::E3 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x2b8b5be364a054fau, 0x76de95a1dfa44bf6u}> {
    struct details {
        
    };
    using Type = pf::E3;
    constexpr static ID TypeID = pf::meta::details::ID{0x2b8b5be364a054fau, 0x76de95a1dfa44bf6u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E3"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E3"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0xc3138ee3c777e09bu, 0x3e696525aff96effu}, pf::meta::details::ID{0x5a118ba910eb7215u, 0x75704caa8bad0c11u}, pf::meta::details::ID{0x59e145e33113a0f3u, 0x1ef8456acf315840u}, pf::meta::details::ID{0xe1d319c8e6dc66ccu, 0x341d63b5ef64880cu}, pf::meta::details::ID{0xf5cecc1f2764bdb8u, 0x61dfb51d85cabfbeu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x5ad9c27fe3e99e89u, 0x26e24fbced4c6c29u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x5ad9c27fe3e99e89u, 0x26e24fbced4c6c29u}, pf::meta::details::ID{0x2b8b5be364a054fau, 0x76de95a1dfa44bf6u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd42d9df3dece519fu, 0x6cbc70e6e2378bbdu}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0xd42d9df3dece519fu, 0x6cbc70e6e2378bbdu}, pf::meta::details::ID{0x2b8b5be364a054fau, 0x76de95a1dfa44bf6u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa491d90f73c8f739u, 0xa142eff68353527du}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0xa491d90f73c8f739u, 0xa142eff68353527du}, pf::meta::details::ID{0x2b8b5be364a054fau, 0x76de95a1dfa44bf6u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x203c6eda29e93051u, 0xf7f1e3bd4382b716u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x203c6eda29e93051u, 0xf7f1e3bd4382b716u}, pf::meta::details::ID{0x2b8b5be364a054fau, 0x76de95a1dfa44bf6u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb3ff86c2cb576f72u, 0xbea48a68b7013223u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0xb3ff86c2cb576f72u, 0xbea48a68b7013223u}, pf::meta::details::ID{0x2b8b5be364a054fau, 0x76de95a1dfa44bf6u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x8580bf328ee98966u, 0xf3497cdf1ec9de0eu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x8580bf328ee98966u, 0xf3497cdf1ec9de0eu}, pf::meta::details::ID{0x2b8b5be364a054fau, 0x76de95a1dfa44bf6u}> {};

/****************************** pf::E3 END ******************************/
namespace pf::meta::details {
/****************************** pf::E3 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3>() {
    return pf::meta::details::ID{0x2b8b5be364a054fau, 0x76de95a1dfa44bf6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3>() {
    return pf::meta::details::ID{0x5ad9c27fe3e99e89u, 0x26e24fbced4c6c29u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 &>() {
    return pf::meta::details::ID{0xd42d9df3dece519fu, 0x6cbc70e6e2378bbdu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 &&>() {
    return pf::meta::details::ID{0xa491d90f73c8f739u, 0xa142eff68353527du};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3 &>() {
    return pf::meta::details::ID{0x203c6eda29e93051u, 0xf7f1e3bd4382b716u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 *>() {
    return pf::meta::details::ID{0xb3ff86c2cb576f72u, 0xbea48a68b7013223u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3 *>() {
    return pf::meta::details::ID{0x8580bf328ee98966u, 0xf3497cdf1ec9de0eu};
}
/****************************** pf::E3 END ******************************/

/****************************** pf::E3::pf::E3::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::A>() {
return pf::meta::details::ID{0xc3138ee3c777e09bu, 0x3e696525aff96effu};
}
/****************************** pf::E3::pf::E3::A END ******************************/

/****************************** pf::E3::pf::E3::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::B>() {
return pf::meta::details::ID{0x5a118ba910eb7215u, 0x75704caa8bad0c11u};
}
/****************************** pf::E3::pf::E3::B END ******************************/

/****************************** pf::E3::pf::E3::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::C>() {
return pf::meta::details::ID{0x59e145e33113a0f3u, 0x1ef8456acf315840u};
}
/****************************** pf::E3::pf::E3::C END ******************************/

/****************************** pf::E3::pf::E3::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::D>() {
return pf::meta::details::ID{0xe1d319c8e6dc66ccu, 0x341d63b5ef64880cu};
}
/****************************** pf::E3::pf::E3::D END ******************************/

/****************************** pf::E3::pf::E3::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::E>() {
return pf::meta::details::ID{0xf5cecc1f2764bdb8u, 0x61dfb51d85cabfbeu};
}
/****************************** pf::E3::pf::E3::E END ******************************/
}
/****************************** pf::E4::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd2d24a6289f86939u, 0xcc3c75ff83ed5729u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xd2d24a6289f86939u, 0xcc3c75ff83ed5729u};
    constexpr static ID TypeID = pf::meta::details::ID{0x31f0da812dcdeba2u, 0xc502a1fca20b7ee1u};
    using Type = pf::E4;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E4::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E4 Value = pf::E4::A;
};
/****************************** pf::E4::A END ******************************/

/****************************** pf::E4::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x143c6617a2dc835au, 0x69dfae844f56006du}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x143c6617a2dc835au, 0x69dfae844f56006du};
    constexpr static ID TypeID = pf::meta::details::ID{0x31f0da812dcdeba2u, 0xc502a1fca20b7ee1u};
    using Type = pf::E4;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E4::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E4 Value = pf::E4::B;
};
/****************************** pf::E4::B END ******************************/

/****************************** pf::E4::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb7deadecef8855b3u, 0x939af7c052e890cau}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xb7deadecef8855b3u, 0x939af7c052e890cau};
    constexpr static ID TypeID = pf::meta::details::ID{0x31f0da812dcdeba2u, 0xc502a1fca20b7ee1u};
    using Type = pf::E4;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E4::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E4 Value = pf::E4::C;
};
/****************************** pf::E4::C END ******************************/

/****************************** pf::E4::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x28b568b9496eafccu, 0x9944591472df0e32u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x28b568b9496eafccu, 0x9944591472df0e32u};
    constexpr static ID TypeID = pf::meta::details::ID{0x31f0da812dcdeba2u, 0xc502a1fca20b7ee1u};
    using Type = pf::E4;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E4::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E4 Value = pf::E4::D;
};
/****************************** pf::E4::D END ******************************/

/****************************** pf::E4::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x886f8776ef559ec8u, 0x8d6c3318edf3d2e5u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x886f8776ef559ec8u, 0x8d6c3318edf3d2e5u};
    constexpr static ID TypeID = pf::meta::details::ID{0x31f0da812dcdeba2u, 0xc502a1fca20b7ee1u};
    using Type = pf::E4;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E4::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E4 Value = pf::E4::E;
};
/****************************** pf::E4::E END ******************************/

/****************************** pf::E4 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x31f0da812dcdeba2u, 0xc502a1fca20b7ee1u}> {
    struct details {
        
    };
    using Type = pf::E4;
    constexpr static ID TypeID = pf::meta::details::ID{0x31f0da812dcdeba2u, 0xc502a1fca20b7ee1u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E4"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E4"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0xd2d24a6289f86939u, 0xcc3c75ff83ed5729u}, pf::meta::details::ID{0x143c6617a2dc835au, 0x69dfae844f56006du}, pf::meta::details::ID{0xb7deadecef8855b3u, 0x939af7c052e890cau}, pf::meta::details::ID{0x28b568b9496eafccu, 0x9944591472df0e32u}, pf::meta::details::ID{0x886f8776ef559ec8u, 0x8d6c3318edf3d2e5u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xcec7dc7c7cad2ba4u, 0x4f648963ee9f0dd9u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0xcec7dc7c7cad2ba4u, 0x4f648963ee9f0dd9u}, pf::meta::details::ID{0x31f0da812dcdeba2u, 0xc502a1fca20b7ee1u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x6c89e4413dd89439u, 0x788b977c2f23ac47u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x6c89e4413dd89439u, 0x788b977c2f23ac47u}, pf::meta::details::ID{0x31f0da812dcdeba2u, 0xc502a1fca20b7ee1u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x398342d05811db3fu, 0x9a89145cb541dc34u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x398342d05811db3fu, 0x9a89145cb541dc34u}, pf::meta::details::ID{0x31f0da812dcdeba2u, 0xc502a1fca20b7ee1u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x6928c7de59e5e274u, 0x1efa4650a449e530u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x6928c7de59e5e274u, 0x1efa4650a449e530u}, pf::meta::details::ID{0x31f0da812dcdeba2u, 0xc502a1fca20b7ee1u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe72d2cfcf6daf9d7u, 0x3c08e9fc71378b35u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0xe72d2cfcf6daf9d7u, 0x3c08e9fc71378b35u}, pf::meta::details::ID{0x31f0da812dcdeba2u, 0xc502a1fca20b7ee1u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x8b912e81052fcf05u, 0x3ce13acf191ae50eu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x8b912e81052fcf05u, 0x3ce13acf191ae50eu}, pf::meta::details::ID{0x31f0da812dcdeba2u, 0xc502a1fca20b7ee1u}> {};

/****************************** pf::E4 END ******************************/
namespace pf::meta::details {
/****************************** pf::E4 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4>() {
    return pf::meta::details::ID{0x31f0da812dcdeba2u, 0xc502a1fca20b7ee1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4>() {
    return pf::meta::details::ID{0xcec7dc7c7cad2ba4u, 0x4f648963ee9f0dd9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 &>() {
    return pf::meta::details::ID{0x6c89e4413dd89439u, 0x788b977c2f23ac47u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 &&>() {
    return pf::meta::details::ID{0x398342d05811db3fu, 0x9a89145cb541dc34u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4 &>() {
    return pf::meta::details::ID{0x6928c7de59e5e274u, 0x1efa4650a449e530u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 *>() {
    return pf::meta::details::ID{0xe72d2cfcf6daf9d7u, 0x3c08e9fc71378b35u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4 *>() {
    return pf::meta::details::ID{0x8b912e81052fcf05u, 0x3ce13acf191ae50eu};
}
/****************************** pf::E4 END ******************************/

/****************************** pf::E4::pf::E4::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::A>() {
return pf::meta::details::ID{0xd2d24a6289f86939u, 0xcc3c75ff83ed5729u};
}
/****************************** pf::E4::pf::E4::A END ******************************/

/****************************** pf::E4::pf::E4::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::B>() {
return pf::meta::details::ID{0x143c6617a2dc835au, 0x69dfae844f56006du};
}
/****************************** pf::E4::pf::E4::B END ******************************/

/****************************** pf::E4::pf::E4::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::C>() {
return pf::meta::details::ID{0xb7deadecef8855b3u, 0x939af7c052e890cau};
}
/****************************** pf::E4::pf::E4::C END ******************************/

/****************************** pf::E4::pf::E4::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::D>() {
return pf::meta::details::ID{0x28b568b9496eafccu, 0x9944591472df0e32u};
}
/****************************** pf::E4::pf::E4::D END ******************************/

/****************************** pf::E4::pf::E4::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::E>() {
return pf::meta::details::ID{0x886f8776ef559ec8u, 0x8d6c3318edf3d2e5u};
}
/****************************** pf::E4::pf::E4::E END ******************************/
}
/****************************** pf::E5::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb1a4c8a0006408fu, 0x53eb7ed70b0a41cbu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xb1a4c8a0006408fu, 0x53eb7ed70b0a41cbu};
    constexpr static ID TypeID = pf::meta::details::ID{0xe9711ba0469f831bu, 0x296af6ad49616953u};
    using Type = pf::E5;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E5::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E5 Value = pf::E5::A;
};
/****************************** pf::E5::A END ******************************/

/****************************** pf::E5::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x4c927be9bec7d293u, 0x37722b1b7795d4b5u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x4c927be9bec7d293u, 0x37722b1b7795d4b5u};
    constexpr static ID TypeID = pf::meta::details::ID{0xe9711ba0469f831bu, 0x296af6ad49616953u};
    using Type = pf::E5;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E5::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E5 Value = pf::E5::B;
};
/****************************** pf::E5::B END ******************************/

/****************************** pf::E5::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x80a11d18d1ede9cfu, 0x1ecce12938d2de30u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x80a11d18d1ede9cfu, 0x1ecce12938d2de30u};
    constexpr static ID TypeID = pf::meta::details::ID{0xe9711ba0469f831bu, 0x296af6ad49616953u};
    using Type = pf::E5;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E5::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E5 Value = pf::E5::C;
};
/****************************** pf::E5::C END ******************************/

/****************************** pf::E5::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd74a272271ddaf8fu, 0x421c8fd13a18c161u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xd74a272271ddaf8fu, 0x421c8fd13a18c161u};
    constexpr static ID TypeID = pf::meta::details::ID{0xe9711ba0469f831bu, 0x296af6ad49616953u};
    using Type = pf::E5;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E5::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E5 Value = pf::E5::D;
};
/****************************** pf::E5::D END ******************************/

/****************************** pf::E5::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x8f8d3481631ef585u, 0x9ec5ce24ae9c5030u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x8f8d3481631ef585u, 0x9ec5ce24ae9c5030u};
    constexpr static ID TypeID = pf::meta::details::ID{0xe9711ba0469f831bu, 0x296af6ad49616953u};
    using Type = pf::E5;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E5::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E5 Value = pf::E5::E;
};
/****************************** pf::E5::E END ******************************/

/****************************** pf::E5 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe9711ba0469f831bu, 0x296af6ad49616953u}> {
    struct details {
        
    };
    using Type = pf::E5;
    constexpr static ID TypeID = pf::meta::details::ID{0xe9711ba0469f831bu, 0x296af6ad49616953u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E5"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E5"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0xb1a4c8a0006408fu, 0x53eb7ed70b0a41cbu}, pf::meta::details::ID{0x4c927be9bec7d293u, 0x37722b1b7795d4b5u}, pf::meta::details::ID{0x80a11d18d1ede9cfu, 0x1ecce12938d2de30u}, pf::meta::details::ID{0xd74a272271ddaf8fu, 0x421c8fd13a18c161u}, pf::meta::details::ID{0x8f8d3481631ef585u, 0x9ec5ce24ae9c5030u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x20c6c869555a4b90u, 0x9cae7d831c97acffu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x20c6c869555a4b90u, 0x9cae7d831c97acffu}, pf::meta::details::ID{0xe9711ba0469f831bu, 0x296af6ad49616953u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa1ccbdab2ec03b53u, 0x165a8bb81a4f3768u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0xa1ccbdab2ec03b53u, 0x165a8bb81a4f3768u}, pf::meta::details::ID{0xe9711ba0469f831bu, 0x296af6ad49616953u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa75f9a98f9f456adu, 0x23829320051bcb99u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0xa75f9a98f9f456adu, 0x23829320051bcb99u}, pf::meta::details::ID{0xe9711ba0469f831bu, 0x296af6ad49616953u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x3811ee99109d847bu, 0x636880ae39496b8cu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x3811ee99109d847bu, 0x636880ae39496b8cu}, pf::meta::details::ID{0xe9711ba0469f831bu, 0x296af6ad49616953u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x1f7080b8562af1c1u, 0xab419c9f864a0f87u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x1f7080b8562af1c1u, 0xab419c9f864a0f87u}, pf::meta::details::ID{0xe9711ba0469f831bu, 0x296af6ad49616953u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xaf8aa101bf8d0043u, 0x5d2c2ab0166cc1bdu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0xaf8aa101bf8d0043u, 0x5d2c2ab0166cc1bdu}, pf::meta::details::ID{0xe9711ba0469f831bu, 0x296af6ad49616953u}> {};

/****************************** pf::E5 END ******************************/
namespace pf::meta::details {
/****************************** pf::E5 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5>() {
    return pf::meta::details::ID{0xe9711ba0469f831bu, 0x296af6ad49616953u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5>() {
    return pf::meta::details::ID{0x20c6c869555a4b90u, 0x9cae7d831c97acffu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 &>() {
    return pf::meta::details::ID{0xa1ccbdab2ec03b53u, 0x165a8bb81a4f3768u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 &&>() {
    return pf::meta::details::ID{0xa75f9a98f9f456adu, 0x23829320051bcb99u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5 &>() {
    return pf::meta::details::ID{0x3811ee99109d847bu, 0x636880ae39496b8cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 *>() {
    return pf::meta::details::ID{0x1f7080b8562af1c1u, 0xab419c9f864a0f87u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5 *>() {
    return pf::meta::details::ID{0xaf8aa101bf8d0043u, 0x5d2c2ab0166cc1bdu};
}
/****************************** pf::E5 END ******************************/

/****************************** pf::E5::pf::E5::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::A>() {
return pf::meta::details::ID{0xb1a4c8a0006408fu, 0x53eb7ed70b0a41cbu};
}
/****************************** pf::E5::pf::E5::A END ******************************/

/****************************** pf::E5::pf::E5::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::B>() {
return pf::meta::details::ID{0x4c927be9bec7d293u, 0x37722b1b7795d4b5u};
}
/****************************** pf::E5::pf::E5::B END ******************************/

/****************************** pf::E5::pf::E5::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::C>() {
return pf::meta::details::ID{0x80a11d18d1ede9cfu, 0x1ecce12938d2de30u};
}
/****************************** pf::E5::pf::E5::C END ******************************/

/****************************** pf::E5::pf::E5::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::D>() {
return pf::meta::details::ID{0xd74a272271ddaf8fu, 0x421c8fd13a18c161u};
}
/****************************** pf::E5::pf::E5::D END ******************************/

/****************************** pf::E5::pf::E5::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::E>() {
return pf::meta::details::ID{0x8f8d3481631ef585u, 0x9ec5ce24ae9c5030u};
}
/****************************** pf::E5::pf::E5::E END ******************************/
}
/****************************** pf::E6::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x84d2729c72383a7bu, 0x1e0512d471b5c07eu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x84d2729c72383a7bu, 0x1e0512d471b5c07eu};
    constexpr static ID TypeID = pf::meta::details::ID{0x5ca19b4d7a1d0940u, 0x69280d1c63170c87u};
    using Type = pf::E6;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E6::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E6 Value = pf::E6::A;
};
/****************************** pf::E6::A END ******************************/

/****************************** pf::E6::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x74a2ac095b6eb70du, 0x78de62cfa5837eb3u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x74a2ac095b6eb70du, 0x78de62cfa5837eb3u};
    constexpr static ID TypeID = pf::meta::details::ID{0x5ca19b4d7a1d0940u, 0x69280d1c63170c87u};
    using Type = pf::E6;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E6::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E6 Value = pf::E6::B;
};
/****************************** pf::E6::B END ******************************/

/****************************** pf::E6::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x640d7747e9715603u, 0x74789b00b5c0560du}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x640d7747e9715603u, 0x74789b00b5c0560du};
    constexpr static ID TypeID = pf::meta::details::ID{0x5ca19b4d7a1d0940u, 0x69280d1c63170c87u};
    using Type = pf::E6;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E6::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E6 Value = pf::E6::C;
};
/****************************** pf::E6::C END ******************************/

/****************************** pf::E6::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd6139f438b9ed17cu, 0xa1e3a6c9bb295aa4u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xd6139f438b9ed17cu, 0xa1e3a6c9bb295aa4u};
    constexpr static ID TypeID = pf::meta::details::ID{0x5ca19b4d7a1d0940u, 0x69280d1c63170c87u};
    using Type = pf::E6;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E6::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E6 Value = pf::E6::D;
};
/****************************** pf::E6::D END ******************************/

/****************************** pf::E6::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x1ac4155e6ae35778u, 0xea911771779e8e59u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x1ac4155e6ae35778u, 0xea911771779e8e59u};
    constexpr static ID TypeID = pf::meta::details::ID{0x5ca19b4d7a1d0940u, 0x69280d1c63170c87u};
    using Type = pf::E6;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E6::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E6 Value = pf::E6::E;
};
/****************************** pf::E6::E END ******************************/

/****************************** pf::E6 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x5ca19b4d7a1d0940u, 0x69280d1c63170c87u}> {
    struct details {
        
    };
    using Type = pf::E6;
    constexpr static ID TypeID = pf::meta::details::ID{0x5ca19b4d7a1d0940u, 0x69280d1c63170c87u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E6"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E6"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x84d2729c72383a7bu, 0x1e0512d471b5c07eu}, pf::meta::details::ID{0x74a2ac095b6eb70du, 0x78de62cfa5837eb3u}, pf::meta::details::ID{0x640d7747e9715603u, 0x74789b00b5c0560du}, pf::meta::details::ID{0xd6139f438b9ed17cu, 0xa1e3a6c9bb295aa4u}, pf::meta::details::ID{0x1ac4155e6ae35778u, 0xea911771779e8e59u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x999229d92f77bfebu, 0x1a2366b3abd4b2b1u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x999229d92f77bfebu, 0x1a2366b3abd4b2b1u}, pf::meta::details::ID{0x5ca19b4d7a1d0940u, 0x69280d1c63170c87u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x6a8234a8ceabdd59u, 0x6413c6c93a2b91c2u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x6a8234a8ceabdd59u, 0x6413c6c93a2b91c2u}, pf::meta::details::ID{0x5ca19b4d7a1d0940u, 0x69280d1c63170c87u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd0856376d6ed3ecbu, 0x28f03a823510e192u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0xd0856376d6ed3ecbu, 0x28f03a823510e192u}, pf::meta::details::ID{0x5ca19b4d7a1d0940u, 0x69280d1c63170c87u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x76de597fef6f9231u, 0x2b133516a6c4fc18u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x76de597fef6f9231u, 0x2b133516a6c4fc18u}, pf::meta::details::ID{0x5ca19b4d7a1d0940u, 0x69280d1c63170c87u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xc41177d38c4d9131u, 0xd77d33c9d958a4bau}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0xc41177d38c4d9131u, 0xd77d33c9d958a4bau}, pf::meta::details::ID{0x5ca19b4d7a1d0940u, 0x69280d1c63170c87u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x6b00b54766b3cb6eu, 0x42bbd9cb66182649u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x6b00b54766b3cb6eu, 0x42bbd9cb66182649u}, pf::meta::details::ID{0x5ca19b4d7a1d0940u, 0x69280d1c63170c87u}> {};

/****************************** pf::E6 END ******************************/
namespace pf::meta::details {
/****************************** pf::E6 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6>() {
    return pf::meta::details::ID{0x5ca19b4d7a1d0940u, 0x69280d1c63170c87u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6>() {
    return pf::meta::details::ID{0x999229d92f77bfebu, 0x1a2366b3abd4b2b1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 &>() {
    return pf::meta::details::ID{0x6a8234a8ceabdd59u, 0x6413c6c93a2b91c2u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 &&>() {
    return pf::meta::details::ID{0xd0856376d6ed3ecbu, 0x28f03a823510e192u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6 &>() {
    return pf::meta::details::ID{0x76de597fef6f9231u, 0x2b133516a6c4fc18u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 *>() {
    return pf::meta::details::ID{0xc41177d38c4d9131u, 0xd77d33c9d958a4bau};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6 *>() {
    return pf::meta::details::ID{0x6b00b54766b3cb6eu, 0x42bbd9cb66182649u};
}
/****************************** pf::E6 END ******************************/

/****************************** pf::E6::pf::E6::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::A>() {
return pf::meta::details::ID{0x84d2729c72383a7bu, 0x1e0512d471b5c07eu};
}
/****************************** pf::E6::pf::E6::A END ******************************/

/****************************** pf::E6::pf::E6::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::B>() {
return pf::meta::details::ID{0x74a2ac095b6eb70du, 0x78de62cfa5837eb3u};
}
/****************************** pf::E6::pf::E6::B END ******************************/

/****************************** pf::E6::pf::E6::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::C>() {
return pf::meta::details::ID{0x640d7747e9715603u, 0x74789b00b5c0560du};
}
/****************************** pf::E6::pf::E6::C END ******************************/

/****************************** pf::E6::pf::E6::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::D>() {
return pf::meta::details::ID{0xd6139f438b9ed17cu, 0xa1e3a6c9bb295aa4u};
}
/****************************** pf::E6::pf::E6::D END ******************************/

/****************************** pf::E6::pf::E6::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::E>() {
return pf::meta::details::ID{0x1ac4155e6ae35778u, 0xea911771779e8e59u};
}
/****************************** pf::E6::pf::E6::E END ******************************/
}
/****************************** pf::E7::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x35f26a0fb8a77d7fu, 0x90c06946d7fd1801u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x35f26a0fb8a77d7fu, 0x90c06946d7fd1801u};
    constexpr static ID TypeID = pf::meta::details::ID{0xc03f776a8eb7aff4u, 0x6a89078ddf872174u};
    using Type = pf::E7;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E7::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E7 Value = pf::E7::A;
};
/****************************** pf::E7::A END ******************************/

/****************************** pf::E7::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe6fafb75004c5758u, 0x3e51166fda700447u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xe6fafb75004c5758u, 0x3e51166fda700447u};
    constexpr static ID TypeID = pf::meta::details::ID{0xc03f776a8eb7aff4u, 0x6a89078ddf872174u};
    using Type = pf::E7;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E7::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E7 Value = pf::E7::B;
};
/****************************** pf::E7::B END ******************************/

/****************************** pf::E7::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x8bff9a51e7e3420u, 0x1fad3009c39e6560u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x8bff9a51e7e3420u, 0x1fad3009c39e6560u};
    constexpr static ID TypeID = pf::meta::details::ID{0xc03f776a8eb7aff4u, 0x6a89078ddf872174u};
    using Type = pf::E7;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E7::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E7 Value = pf::E7::C;
};
/****************************** pf::E7::C END ******************************/

/****************************** pf::E7::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x845727c2d17baa90u, 0xb9fbc2956677a59u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x845727c2d17baa90u, 0xb9fbc2956677a59u};
    constexpr static ID TypeID = pf::meta::details::ID{0xc03f776a8eb7aff4u, 0x6a89078ddf872174u};
    using Type = pf::E7;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E7::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E7 Value = pf::E7::D;
};
/****************************** pf::E7::D END ******************************/

/****************************** pf::E7::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x668825810c8778beu, 0x4444b75821b4a13u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x668825810c8778beu, 0x4444b75821b4a13u};
    constexpr static ID TypeID = pf::meta::details::ID{0xc03f776a8eb7aff4u, 0x6a89078ddf872174u};
    using Type = pf::E7;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E7::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E7 Value = pf::E7::E;
};
/****************************** pf::E7::E END ******************************/

/****************************** pf::E7 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xc03f776a8eb7aff4u, 0x6a89078ddf872174u}> {
    struct details {
        
    };
    using Type = pf::E7;
    constexpr static ID TypeID = pf::meta::details::ID{0xc03f776a8eb7aff4u, 0x6a89078ddf872174u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E7"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E7"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x35f26a0fb8a77d7fu, 0x90c06946d7fd1801u}, pf::meta::details::ID{0xe6fafb75004c5758u, 0x3e51166fda700447u}, pf::meta::details::ID{0x8bff9a51e7e3420u, 0x1fad3009c39e6560u}, pf::meta::details::ID{0x845727c2d17baa90u, 0xb9fbc2956677a59u}, pf::meta::details::ID{0x668825810c8778beu, 0x4444b75821b4a13u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x897bcc3928f1df4bu, 0x47247c525c9df1f4u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x897bcc3928f1df4bu, 0x47247c525c9df1f4u}, pf::meta::details::ID{0xc03f776a8eb7aff4u, 0x6a89078ddf872174u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x3b6e5f72a0a5cce9u, 0x6ef6c9a7e0e033ffu}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x3b6e5f72a0a5cce9u, 0x6ef6c9a7e0e033ffu}, pf::meta::details::ID{0xc03f776a8eb7aff4u, 0x6a89078ddf872174u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xda3c081939ddcc02u, 0xdda5472f97312296u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0xda3c081939ddcc02u, 0xdda5472f97312296u}, pf::meta::details::ID{0xc03f776a8eb7aff4u, 0x6a89078ddf872174u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x1c10d6dc7c813a5eu, 0x35076cdeb4b13f03u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x1c10d6dc7c813a5eu, 0x35076cdeb4b13f03u}, pf::meta::details::ID{0xc03f776a8eb7aff4u, 0x6a89078ddf872174u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x9505054f3300f438u, 0x4dca16f6dc4cd573u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x9505054f3300f438u, 0x4dca16f6dc4cd573u}, pf::meta::details::ID{0xc03f776a8eb7aff4u, 0x6a89078ddf872174u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x96e67d1ebe377b4fu, 0xdc77a44ecdd0d275u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x96e67d1ebe377b4fu, 0xdc77a44ecdd0d275u}, pf::meta::details::ID{0xc03f776a8eb7aff4u, 0x6a89078ddf872174u}> {};

/****************************** pf::E7 END ******************************/
namespace pf::meta::details {
/****************************** pf::E7 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7>() {
    return pf::meta::details::ID{0xc03f776a8eb7aff4u, 0x6a89078ddf872174u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7>() {
    return pf::meta::details::ID{0x897bcc3928f1df4bu, 0x47247c525c9df1f4u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 &>() {
    return pf::meta::details::ID{0x3b6e5f72a0a5cce9u, 0x6ef6c9a7e0e033ffu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 &&>() {
    return pf::meta::details::ID{0xda3c081939ddcc02u, 0xdda5472f97312296u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7 &>() {
    return pf::meta::details::ID{0x1c10d6dc7c813a5eu, 0x35076cdeb4b13f03u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 *>() {
    return pf::meta::details::ID{0x9505054f3300f438u, 0x4dca16f6dc4cd573u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7 *>() {
    return pf::meta::details::ID{0x96e67d1ebe377b4fu, 0xdc77a44ecdd0d275u};
}
/****************************** pf::E7 END ******************************/

/****************************** pf::E7::pf::E7::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::A>() {
return pf::meta::details::ID{0x35f26a0fb8a77d7fu, 0x90c06946d7fd1801u};
}
/****************************** pf::E7::pf::E7::A END ******************************/

/****************************** pf::E7::pf::E7::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::B>() {
return pf::meta::details::ID{0xe6fafb75004c5758u, 0x3e51166fda700447u};
}
/****************************** pf::E7::pf::E7::B END ******************************/

/****************************** pf::E7::pf::E7::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::C>() {
return pf::meta::details::ID{0x8bff9a51e7e3420u, 0x1fad3009c39e6560u};
}
/****************************** pf::E7::pf::E7::C END ******************************/

/****************************** pf::E7::pf::E7::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::D>() {
return pf::meta::details::ID{0x845727c2d17baa90u, 0xb9fbc2956677a59u};
}
/****************************** pf::E7::pf::E7::D END ******************************/

/****************************** pf::E7::pf::E7::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::E>() {
return pf::meta::details::ID{0x668825810c8778beu, 0x4444b75821b4a13u};
}
/****************************** pf::E7::pf::E7::E END ******************************/
}
/****************************** pf::E8::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd85568b85b42aa26u, 0x9a1bd510b7d8826bu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xd85568b85b42aa26u, 0x9a1bd510b7d8826bu};
    constexpr static ID TypeID = pf::meta::details::ID{0xbfe98b6248533d99u, 0x1898a2a66a0647f6u};
    using Type = pf::E8;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E8::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E8 Value = pf::E8::A;
};
/****************************** pf::E8::A END ******************************/

/****************************** pf::E8::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x3aba260676fc0468u, 0x1f9570c080489653u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x3aba260676fc0468u, 0x1f9570c080489653u};
    constexpr static ID TypeID = pf::meta::details::ID{0xbfe98b6248533d99u, 0x1898a2a66a0647f6u};
    using Type = pf::E8;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E8::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E8 Value = pf::E8::B;
};
/****************************** pf::E8::B END ******************************/

/****************************** pf::E8::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xbae487f082a6435bu, 0x5253fb4769d0d1a3u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xbae487f082a6435bu, 0x5253fb4769d0d1a3u};
    constexpr static ID TypeID = pf::meta::details::ID{0xbfe98b6248533d99u, 0x1898a2a66a0647f6u};
    using Type = pf::E8;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E8::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E8 Value = pf::E8::C;
};
/****************************** pf::E8::C END ******************************/

/****************************** pf::E8::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x3f3dfa2dcddcd416u, 0xa0d312604add58c3u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x3f3dfa2dcddcd416u, 0xa0d312604add58c3u};
    constexpr static ID TypeID = pf::meta::details::ID{0xbfe98b6248533d99u, 0x1898a2a66a0647f6u};
    using Type = pf::E8;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E8::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E8 Value = pf::E8::D;
};
/****************************** pf::E8::D END ******************************/

/****************************** pf::E8::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x97bb92f37a6e92d6u, 0x5588876b674dd9dau}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x97bb92f37a6e92d6u, 0x5588876b674dd9dau};
    constexpr static ID TypeID = pf::meta::details::ID{0xbfe98b6248533d99u, 0x1898a2a66a0647f6u};
    using Type = pf::E8;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E8::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E8 Value = pf::E8::E;
};
/****************************** pf::E8::E END ******************************/

/****************************** pf::E8 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xbfe98b6248533d99u, 0x1898a2a66a0647f6u}> {
    struct details {
        
    };
    using Type = pf::E8;
    constexpr static ID TypeID = pf::meta::details::ID{0xbfe98b6248533d99u, 0x1898a2a66a0647f6u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E8"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E8"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0xd85568b85b42aa26u, 0x9a1bd510b7d8826bu}, pf::meta::details::ID{0x3aba260676fc0468u, 0x1f9570c080489653u}, pf::meta::details::ID{0xbae487f082a6435bu, 0x5253fb4769d0d1a3u}, pf::meta::details::ID{0x3f3dfa2dcddcd416u, 0xa0d312604add58c3u}, pf::meta::details::ID{0x97bb92f37a6e92d6u, 0x5588876b674dd9dau});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x6a2098d3cb829065u, 0xcba17438fb765883u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x6a2098d3cb829065u, 0xcba17438fb765883u}, pf::meta::details::ID{0xbfe98b6248533d99u, 0x1898a2a66a0647f6u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x5789e8f6a862cb33u, 0x5973c443946031e8u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x5789e8f6a862cb33u, 0x5973c443946031e8u}, pf::meta::details::ID{0xbfe98b6248533d99u, 0x1898a2a66a0647f6u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x5c8957a9dad5f419u, 0xff020e2301c9c621u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x5c8957a9dad5f419u, 0xff020e2301c9c621u}, pf::meta::details::ID{0xbfe98b6248533d99u, 0x1898a2a66a0647f6u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x188b79384fb54be3u, 0x26da528fc72c2dbdu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x188b79384fb54be3u, 0x26da528fc72c2dbdu}, pf::meta::details::ID{0xbfe98b6248533d99u, 0x1898a2a66a0647f6u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe55e2b83d22b5702u, 0x5c1f168d29410e63u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0xe55e2b83d22b5702u, 0x5c1f168d29410e63u}, pf::meta::details::ID{0xbfe98b6248533d99u, 0x1898a2a66a0647f6u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x76d41415ccc97680u, 0x2e211eecbc15a11eu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x76d41415ccc97680u, 0x2e211eecbc15a11eu}, pf::meta::details::ID{0xbfe98b6248533d99u, 0x1898a2a66a0647f6u}> {};

/****************************** pf::E8 END ******************************/
namespace pf::meta::details {
/****************************** pf::E8 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8>() {
    return pf::meta::details::ID{0xbfe98b6248533d99u, 0x1898a2a66a0647f6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8>() {
    return pf::meta::details::ID{0x6a2098d3cb829065u, 0xcba17438fb765883u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 &>() {
    return pf::meta::details::ID{0x5789e8f6a862cb33u, 0x5973c443946031e8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 &&>() {
    return pf::meta::details::ID{0x5c8957a9dad5f419u, 0xff020e2301c9c621u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8 &>() {
    return pf::meta::details::ID{0x188b79384fb54be3u, 0x26da528fc72c2dbdu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 *>() {
    return pf::meta::details::ID{0xe55e2b83d22b5702u, 0x5c1f168d29410e63u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8 *>() {
    return pf::meta::details::ID{0x76d41415ccc97680u, 0x2e211eecbc15a11eu};
}
/****************************** pf::E8 END ******************************/

/****************************** pf::E8::pf::E8::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::A>() {
return pf::meta::details::ID{0xd85568b85b42aa26u, 0x9a1bd510b7d8826bu};
}
/****************************** pf::E8::pf::E8::A END ******************************/

/****************************** pf::E8::pf::E8::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::B>() {
return pf::meta::details::ID{0x3aba260676fc0468u, 0x1f9570c080489653u};
}
/****************************** pf::E8::pf::E8::B END ******************************/

/****************************** pf::E8::pf::E8::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::C>() {
return pf::meta::details::ID{0xbae487f082a6435bu, 0x5253fb4769d0d1a3u};
}
/****************************** pf::E8::pf::E8::C END ******************************/

/****************************** pf::E8::pf::E8::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::D>() {
return pf::meta::details::ID{0x3f3dfa2dcddcd416u, 0xa0d312604add58c3u};
}
/****************************** pf::E8::pf::E8::D END ******************************/

/****************************** pf::E8::pf::E8::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::E>() {
return pf::meta::details::ID{0x97bb92f37a6e92d6u, 0x5588876b674dd9dau};
}
/****************************** pf::E8::pf::E8::E END ******************************/
}
/****************************** pf::E9::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x7d43d098fce86830u, 0x366ed26acbe04a96u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x7d43d098fce86830u, 0x366ed26acbe04a96u};
    constexpr static ID TypeID = pf::meta::details::ID{0x259c22d14f8966e7u, 0x4853f738a73d159u};
    using Type = pf::E9;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E9::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E9 Value = pf::E9::A;
};
/****************************** pf::E9::A END ******************************/

/****************************** pf::E9::B START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xfc03172143ea2106u, 0xd6f08cf0413d435du}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xfc03172143ea2106u, 0xd6f08cf0413d435du};
    constexpr static ID TypeID = pf::meta::details::ID{0x259c22d14f8966e7u, 0x4853f738a73d159u};
    using Type = pf::E9;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E9::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E9 Value = pf::E9::B;
};
/****************************** pf::E9::B END ******************************/

/****************************** pf::E9::C START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x9b18a6b96275dbaeu, 0xecdfe196f9b5f6f1u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x9b18a6b96275dbaeu, 0xecdfe196f9b5f6f1u};
    constexpr static ID TypeID = pf::meta::details::ID{0x259c22d14f8966e7u, 0x4853f738a73d159u};
    using Type = pf::E9;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E9::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E9 Value = pf::E9::C;
};
/****************************** pf::E9::C END ******************************/

/****************************** pf::E9::D START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x408b158fde64f4a0u, 0xe4d9ef9577b494e3u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x408b158fde64f4a0u, 0xe4d9ef9577b494e3u};
    constexpr static ID TypeID = pf::meta::details::ID{0x259c22d14f8966e7u, 0x4853f738a73d159u};
    using Type = pf::E9;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E9::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E9 Value = pf::E9::D;
};
/****************************** pf::E9::D END ******************************/

/****************************** pf::E9::E START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb6a9099422aaf642u, 0x38de42b9789984c6u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xb6a9099422aaf642u, 0x38de42b9789984c6u};
    constexpr static ID TypeID = pf::meta::details::ID{0x259c22d14f8966e7u, 0x4853f738a73d159u};
    using Type = pf::E9;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E9::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E9 Value = pf::E9::E;
};
/****************************** pf::E9::E END ******************************/

/****************************** pf::E9 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x259c22d14f8966e7u, 0x4853f738a73d159u}> {
    struct details {
        
    };
    using Type = pf::E9;
    constexpr static ID TypeID = pf::meta::details::ID{0x259c22d14f8966e7u, 0x4853f738a73d159u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = pf::StringLiteral{"E9"};
    constexpr static auto FullName = pf::StringLiteral{"pf::E9"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x7d43d098fce86830u, 0x366ed26acbe04a96u}, pf::meta::details::ID{0xfc03172143ea2106u, 0xd6f08cf0413d435du}, pf::meta::details::ID{0x9b18a6b96275dbaeu, 0xecdfe196f9b5f6f1u}, pf::meta::details::ID{0x408b158fde64f4a0u, 0xe4d9ef9577b494e3u}, pf::meta::details::ID{0xb6a9099422aaf642u, 0x38de42b9789984c6u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xc8e2d78176d4bfe4u, 0x85db6ecbf063b4e0u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0xc8e2d78176d4bfe4u, 0x85db6ecbf063b4e0u}, pf::meta::details::ID{0x259c22d14f8966e7u, 0x4853f738a73d159u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xbac814497fd7e464u, 0x5e7c0a8f471441f5u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0xbac814497fd7e464u, 0x5e7c0a8f471441f5u}, pf::meta::details::ID{0x259c22d14f8966e7u, 0x4853f738a73d159u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb50d45685115b0bdu, 0xf17b999ce488b556u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0xb50d45685115b0bdu, 0xf17b999ce488b556u}, pf::meta::details::ID{0x259c22d14f8966e7u, 0x4853f738a73d159u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x2042efa449d7d0b5u, 0x126f0201a0f91bu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x2042efa449d7d0b5u, 0x126f0201a0f91bu}, pf::meta::details::ID{0x259c22d14f8966e7u, 0x4853f738a73d159u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd847c5cb09cf3fd4u, 0x2dcf5276e88a0f4fu}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0xd847c5cb09cf3fd4u, 0x2dcf5276e88a0f4fu}, pf::meta::details::ID{0x259c22d14f8966e7u, 0x4853f738a73d159u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x379c5f44f8398c05u, 0xa7ad3667fccf8328u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x379c5f44f8398c05u, 0xa7ad3667fccf8328u}, pf::meta::details::ID{0x259c22d14f8966e7u, 0x4853f738a73d159u}> {};

/****************************** pf::E9 END ******************************/
namespace pf::meta::details {
/****************************** pf::E9 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9>() {
    return pf::meta::details::ID{0x259c22d14f8966e7u, 0x4853f738a73d159u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9>() {
    return pf::meta::details::ID{0xc8e2d78176d4bfe4u, 0x85db6ecbf063b4e0u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 &>() {
    return pf::meta::details::ID{0xbac814497fd7e464u, 0x5e7c0a8f471441f5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 &&>() {
    return pf::meta::details::ID{0xb50d45685115b0bdu, 0xf17b999ce488b556u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9 &>() {
    return pf::meta::details::ID{0x2042efa449d7d0b5u, 0x126f0201a0f91bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 *>() {
    return pf::meta::details::ID{0xd847c5cb09cf3fd4u, 0x2dcf5276e88a0f4fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9 *>() {
    return pf::meta::details::ID{0x379c5f44f8398c05u, 0xa7ad3667fccf8328u};
}
/****************************** pf::E9 END ******************************/

/****************************** pf::E9::pf::E9::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::A>() {
return pf::meta::details::ID{0x7d43d098fce86830u, 0x366ed26acbe04a96u};
}
/****************************** pf::E9::pf::E9::A END ******************************/

/****************************** pf::E9::pf::E9::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::B>() {
return pf::meta::details::ID{0xfc03172143ea2106u, 0xd6f08cf0413d435du};
}
/****************************** pf::E9::pf::E9::B END ******************************/

/****************************** pf::E9::pf::E9::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::C>() {
return pf::meta::details::ID{0x9b18a6b96275dbaeu, 0xecdfe196f9b5f6f1u};
}
/****************************** pf::E9::pf::E9::C END ******************************/

/****************************** pf::E9::pf::E9::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::D>() {
return pf::meta::details::ID{0x408b158fde64f4a0u, 0xe4d9ef9577b494e3u};
}
/****************************** pf::E9::pf::E9::D END ******************************/

/****************************** pf::E9::pf::E9::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::E>() {
return pf::meta::details::ID{0xb6a9099422aaf642u, 0x38de42b9789984c6u};
}
/****************************** pf::E9::pf::E9::E END ******************************/
}

