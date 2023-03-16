
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa3e270a698504255u, 0x763f39dc40a5350au}> {
    struct details {
        constexpr static auto ArgArray_13039163206166571093 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_12915281502111787105 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_13044518521110409818 = pf::make_array<std::string_view>();

    };
    constexpr static ID ValueID = pf::meta::details::ID{0xa3e270a698504255u, 0x763f39dc40a5350au};
    constexpr static ID TypeID = pf::meta::details::ID{0x4437fb4875201431u, 0xbc35479b4938e49cu};
    using Type = pf::SomeEnum;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(pf::meta::Attribute{"test", std::span<const std::string_view>{details::ArgArray_13039163206166571093}}, pf::meta::Attribute{"test2", std::span<const std::string_view>{details::ArgArray_12915281502111787105}}, pf::meta::Attribute{"test3", std::span<const std::string_view>{details::ArgArray_13044518521110409818}});

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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xebc82d361d8515adu, 0xf61602c23e92d465u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xebc82d361d8515adu, 0xf61602c23e92d465u};
    constexpr static ID TypeID = pf::meta::details::ID{0x4437fb4875201431u, 0xbc35479b4938e49cu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x4437fb4875201431u, 0xbc35479b4938e49cu}> {
    struct details {
        constexpr static auto ArgArray_14133276753643664164 = pf::make_array<std::string_view>(R"arg(()()()((())))arg", R"arg([[nodiscard]])arg", R"arg(1ll)arg", R"arg(1.011)arg", R"arg([]{}())arg", R"arg("yeet")arg", R"arg('a')arg", R"arg([][][]:::3214234...[][][][])arg");
constexpr static auto ArgArray_2593754460660534590 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_829658461818120075 = pf::make_array<std::string_view>(R"arg(1ll)arg", R"arg(1.011)arg", R"arg("yeet")arg");
constexpr static auto ArgArray_9350624761234779140 = pf::make_array<std::string_view>();

    };
    using Type = pf::SomeEnum;
    constexpr static ID TypeID = pf::meta::details::ID{0x4437fb4875201431u, 0xbc35479b4938e49cu};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(pf::meta::Attribute{"pf::operators", std::span<const std::string_view>{details::ArgArray_14133276753643664164}}, pf::meta::Attribute{"pf::hihi", std::span<const std::string_view>{details::ArgArray_2593754460660534590}}, pf::meta::Attribute{"pf::operators2", std::span<const std::string_view>{details::ArgArray_829658461818120075}}, pf::meta::Attribute{"pf::hihi2", std::span<const std::string_view>{details::ArgArray_9350624761234779140}});

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0xa3e270a698504255u, 0x763f39dc40a5350au}, pf::meta::details::ID{0xebc82d361d8515adu, 0xf61602c23e92d465u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa2e32ff1308d0d09u, 0x9fb1930632ff6cb7u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0xa2e32ff1308d0d09u, 0x9fb1930632ff6cb7u}, pf::meta::details::ID{0x4437fb4875201431u, 0xbc35479b4938e49cu}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xf358ae377838d815u, 0xd7f2597700c1d56au}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0xf358ae377838d815u, 0xd7f2597700c1d56au}, pf::meta::details::ID{0x4437fb4875201431u, 0xbc35479b4938e49cu}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa3e31dfe734008f5u, 0xf4e507b11885b1a6u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0xa3e31dfe734008f5u, 0xf4e507b11885b1a6u}, pf::meta::details::ID{0x4437fb4875201431u, 0xbc35479b4938e49cu}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x2b102f9ea1a133d6u, 0x794eaa601bb327b6u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x2b102f9ea1a133d6u, 0x794eaa601bb327b6u}, pf::meta::details::ID{0x4437fb4875201431u, 0xbc35479b4938e49cu}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd445fd6411d51e65u, 0x3e88e7ebfc9ffe97u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0xd445fd6411d51e65u, 0x3e88e7ebfc9ffe97u}, pf::meta::details::ID{0x4437fb4875201431u, 0xbc35479b4938e49cu}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x1b2bd50c2c02589u, 0x30102b6165831b4du}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x1b2bd50c2c02589u, 0x30102b6165831b4du}, pf::meta::details::ID{0x4437fb4875201431u, 0xbc35479b4938e49cu}> {};

/****************************** pf::SomeEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::SomeEnum START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum>() {
    return pf::meta::details::ID{0x4437fb4875201431u, 0xbc35479b4938e49cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum>() {
    return pf::meta::details::ID{0xa2e32ff1308d0d09u, 0x9fb1930632ff6cb7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum &>() {
    return pf::meta::details::ID{0xf358ae377838d815u, 0xd7f2597700c1d56au};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum &&>() {
    return pf::meta::details::ID{0xa3e31dfe734008f5u, 0xf4e507b11885b1a6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum &>() {
    return pf::meta::details::ID{0x2b102f9ea1a133d6u, 0x794eaa601bb327b6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum *>() {
    return pf::meta::details::ID{0xd445fd6411d51e65u, 0x3e88e7ebfc9ffe97u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum *>() {
    return pf::meta::details::ID{0x1b2bd50c2c02589u, 0x30102b6165831b4du};
}
/****************************** pf::SomeEnum END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value1 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value1>() {
return pf::meta::details::ID{0xa3e270a698504255u, 0x763f39dc40a5350au};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value1 END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value2 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value2>() {
return pf::meta::details::ID{0xebc82d361d8515adu, 0xf61602c23e92d465u};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value2 END ******************************/
}
/****************************** pf::Test::E::Value1 START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x322d43ad6b37b0fcu, 0xa820a7e44cca2337u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x322d43ad6b37b0fcu, 0xa820a7e44cca2337u};
    constexpr static ID TypeID = pf::meta::details::ID{0x3feb44debfd4aa4eu, 0x5293fddc699c818du};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa39cf4cbebee62d5u, 0xc716e841d51e2390u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xa39cf4cbebee62d5u, 0xc716e841d51e2390u};
    constexpr static ID TypeID = pf::meta::details::ID{0x3feb44debfd4aa4eu, 0x5293fddc699c818du};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x3feb44debfd4aa4eu, 0x5293fddc699c818du}> {
    struct details {
        
    };
    using Type = pf::Test::E;
    constexpr static ID TypeID = pf::meta::details::ID{0x3feb44debfd4aa4eu, 0x5293fddc699c818du};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x322d43ad6b37b0fcu, 0xa820a7e44cca2337u}, pf::meta::details::ID{0xa39cf4cbebee62d5u, 0xc716e841d51e2390u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x4b65eb0875541b29u, 0xecff99ec381b3ffdu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x4b65eb0875541b29u, 0xecff99ec381b3ffdu}, pf::meta::details::ID{0x3feb44debfd4aa4eu, 0x5293fddc699c818du}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe6f432956a81d243u, 0x76730593e0aa1f7au}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0xe6f432956a81d243u, 0x76730593e0aa1f7au}, pf::meta::details::ID{0x3feb44debfd4aa4eu, 0x5293fddc699c818du}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x4c0503dbd74e237eu, 0xbbf0c0da3394c009u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x4c0503dbd74e237eu, 0xbbf0c0da3394c009u}, pf::meta::details::ID{0x3feb44debfd4aa4eu, 0x5293fddc699c818du}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xf7b6414b8f70e9fcu, 0xf93b860dc32b50e2u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0xf7b6414b8f70e9fcu, 0xf93b860dc32b50e2u}, pf::meta::details::ID{0x3feb44debfd4aa4eu, 0x5293fddc699c818du}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xfac6e0d44893059u, 0xbe98de96d4273428u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0xfac6e0d44893059u, 0xbe98de96d4273428u}, pf::meta::details::ID{0x3feb44debfd4aa4eu, 0x5293fddc699c818du}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x616e3377a101f071u, 0x6b6abc67cf7c725bu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x616e3377a101f071u, 0x6b6abc67cf7c725bu}, pf::meta::details::ID{0x3feb44debfd4aa4eu, 0x5293fddc699c818du}> {};

/****************************** pf::Test::E END ******************************/
namespace pf::meta::details {
/****************************** pf::Test::E START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E>() {
    return pf::meta::details::ID{0x3feb44debfd4aa4eu, 0x5293fddc699c818du};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E>() {
    return pf::meta::details::ID{0x4b65eb0875541b29u, 0xecff99ec381b3ffdu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E &>() {
    return pf::meta::details::ID{0xe6f432956a81d243u, 0x76730593e0aa1f7au};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E &&>() {
    return pf::meta::details::ID{0x4c0503dbd74e237eu, 0xbbf0c0da3394c009u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E &>() {
    return pf::meta::details::ID{0xf7b6414b8f70e9fcu, 0xf93b860dc32b50e2u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E *>() {
    return pf::meta::details::ID{0xfac6e0d44893059u, 0xbe98de96d4273428u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E *>() {
    return pf::meta::details::ID{0x616e3377a101f071u, 0x6b6abc67cf7c725bu};
}
/****************************** pf::Test::E END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value1 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::Test::E::Value1>() {
return pf::meta::details::ID{0x322d43ad6b37b0fcu, 0xa820a7e44cca2337u};
}
/****************************** pf::Test::E::pf::Test::E::Value1 END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value2 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::Test::E::Value2>() {
return pf::meta::details::ID{0xa39cf4cbebee62d5u, 0xc716e841d51e2390u};
}
/****************************** pf::Test::E::pf::Test::E::Value2 END ******************************/
}
/****************************** pf::EmptyEnum START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xed5e9bec024f3f95u, 0x75b084570a8f1fd1u}> {
    struct details {
        
    };
    using Type = pf::EmptyEnum;
    constexpr static ID TypeID = pf::meta::details::ID{0xed5e9bec024f3f95u, 0x75b084570a8f1fd1u};

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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x86ffbdfa4c92fdbfu, 0xcaff85dd61da6ef3u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x86ffbdfa4c92fdbfu, 0xcaff85dd61da6ef3u}, pf::meta::details::ID{0xed5e9bec024f3f95u, 0x75b084570a8f1fd1u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xde34aa99690b5d2au, 0xd60cef965c6704d5u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0xde34aa99690b5d2au, 0xd60cef965c6704d5u}, pf::meta::details::ID{0xed5e9bec024f3f95u, 0x75b084570a8f1fd1u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x70747d8d6c446cf3u, 0xc0dc0a80464ac458u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x70747d8d6c446cf3u, 0xc0dc0a80464ac458u}, pf::meta::details::ID{0xed5e9bec024f3f95u, 0x75b084570a8f1fd1u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x39933297863ff336u, 0x7b3d12f9e4ecf549u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x39933297863ff336u, 0x7b3d12f9e4ecf549u}, pf::meta::details::ID{0xed5e9bec024f3f95u, 0x75b084570a8f1fd1u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xeb97e7f9be193a3eu, 0x635b2ca27ac7a53du}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0xeb97e7f9be193a3eu, 0x635b2ca27ac7a53du}, pf::meta::details::ID{0xed5e9bec024f3f95u, 0x75b084570a8f1fd1u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xbd9851eced68813bu, 0xd8b88a2a854e3388u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0xbd9851eced68813bu, 0xd8b88a2a854e3388u}, pf::meta::details::ID{0xed5e9bec024f3f95u, 0x75b084570a8f1fd1u}> {};

/****************************** pf::EmptyEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::EmptyEnum START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum>() {
    return pf::meta::details::ID{0xed5e9bec024f3f95u, 0x75b084570a8f1fd1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum>() {
    return pf::meta::details::ID{0x86ffbdfa4c92fdbfu, 0xcaff85dd61da6ef3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &>() {
    return pf::meta::details::ID{0xde34aa99690b5d2au, 0xd60cef965c6704d5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &&>() {
    return pf::meta::details::ID{0x70747d8d6c446cf3u, 0xc0dc0a80464ac458u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum &>() {
    return pf::meta::details::ID{0x39933297863ff336u, 0x7b3d12f9e4ecf549u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum *>() {
    return pf::meta::details::ID{0xeb97e7f9be193a3eu, 0x635b2ca27ac7a53du};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum *>() {
    return pf::meta::details::ID{0xbd9851eced68813bu, 0xd8b88a2a854e3388u};
}
/****************************** pf::EmptyEnum END ******************************/
}
/****************************** pf::E1::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd3a3016e6d3dd405u, 0x2b82bae1d714b380u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xd3a3016e6d3dd405u, 0x2b82bae1d714b380u};
    constexpr static ID TypeID = pf::meta::details::ID{0x30f6ff7b0b11173au, 0x23eaf8ba524fc7dcu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xf14734b784a3057bu, 0x534cdff4dd1dbe76u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xf14734b784a3057bu, 0x534cdff4dd1dbe76u};
    constexpr static ID TypeID = pf::meta::details::ID{0x30f6ff7b0b11173au, 0x23eaf8ba524fc7dcu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd5cbecf93eedf2b3u, 0xf1f3b1a7eae76f60u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xd5cbecf93eedf2b3u, 0xf1f3b1a7eae76f60u};
    constexpr static ID TypeID = pf::meta::details::ID{0x30f6ff7b0b11173au, 0x23eaf8ba524fc7dcu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x85ba14043c16cf1fu, 0xd37c9023da249524u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x85ba14043c16cf1fu, 0xd37c9023da249524u};
    constexpr static ID TypeID = pf::meta::details::ID{0x30f6ff7b0b11173au, 0x23eaf8ba524fc7dcu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x4120ee8df8c12a60u, 0xb0ad7289beb59a93u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x4120ee8df8c12a60u, 0xb0ad7289beb59a93u};
    constexpr static ID TypeID = pf::meta::details::ID{0x30f6ff7b0b11173au, 0x23eaf8ba524fc7dcu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x30f6ff7b0b11173au, 0x23eaf8ba524fc7dcu}> {
    struct details {
        
    };
    using Type = pf::E1;
    constexpr static ID TypeID = pf::meta::details::ID{0x30f6ff7b0b11173au, 0x23eaf8ba524fc7dcu};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0xd3a3016e6d3dd405u, 0x2b82bae1d714b380u}, pf::meta::details::ID{0xf14734b784a3057bu, 0x534cdff4dd1dbe76u}, pf::meta::details::ID{0xd5cbecf93eedf2b3u, 0xf1f3b1a7eae76f60u}, pf::meta::details::ID{0x85ba14043c16cf1fu, 0xd37c9023da249524u}, pf::meta::details::ID{0x4120ee8df8c12a60u, 0xb0ad7289beb59a93u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe287b042f74266f4u, 0x812b88edddc9130u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0xe287b042f74266f4u, 0x812b88edddc9130u}, pf::meta::details::ID{0x30f6ff7b0b11173au, 0x23eaf8ba524fc7dcu}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x4a205afe7f05701du, 0xb87da5fb46b99062u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x4a205afe7f05701du, 0xb87da5fb46b99062u}, pf::meta::details::ID{0x30f6ff7b0b11173au, 0x23eaf8ba524fc7dcu}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x7c48b971aec94c22u, 0xa0a0f4e0f2ed36c8u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x7c48b971aec94c22u, 0xa0a0f4e0f2ed36c8u}, pf::meta::details::ID{0x30f6ff7b0b11173au, 0x23eaf8ba524fc7dcu}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x179571c7271e1cf5u, 0x5038acd95a02ceb8u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x179571c7271e1cf5u, 0x5038acd95a02ceb8u}, pf::meta::details::ID{0x30f6ff7b0b11173au, 0x23eaf8ba524fc7dcu}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x21bfd857b85f7de7u, 0x5f2a2ce04d4bc5d2u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x21bfd857b85f7de7u, 0x5f2a2ce04d4bc5d2u}, pf::meta::details::ID{0x30f6ff7b0b11173au, 0x23eaf8ba524fc7dcu}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xccd08caa832a9901u, 0xbb8e9019acf47d84u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0xccd08caa832a9901u, 0xbb8e9019acf47d84u}, pf::meta::details::ID{0x30f6ff7b0b11173au, 0x23eaf8ba524fc7dcu}> {};

/****************************** pf::E1 END ******************************/
namespace pf::meta::details {
/****************************** pf::E1 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1>() {
    return pf::meta::details::ID{0x30f6ff7b0b11173au, 0x23eaf8ba524fc7dcu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1>() {
    return pf::meta::details::ID{0xe287b042f74266f4u, 0x812b88edddc9130u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 &>() {
    return pf::meta::details::ID{0x4a205afe7f05701du, 0xb87da5fb46b99062u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 &&>() {
    return pf::meta::details::ID{0x7c48b971aec94c22u, 0xa0a0f4e0f2ed36c8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1 &>() {
    return pf::meta::details::ID{0x179571c7271e1cf5u, 0x5038acd95a02ceb8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 *>() {
    return pf::meta::details::ID{0x21bfd857b85f7de7u, 0x5f2a2ce04d4bc5d2u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1 *>() {
    return pf::meta::details::ID{0xccd08caa832a9901u, 0xbb8e9019acf47d84u};
}
/****************************** pf::E1 END ******************************/

/****************************** pf::E1::pf::E1::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::A>() {
return pf::meta::details::ID{0xd3a3016e6d3dd405u, 0x2b82bae1d714b380u};
}
/****************************** pf::E1::pf::E1::A END ******************************/

/****************************** pf::E1::pf::E1::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::B>() {
return pf::meta::details::ID{0xf14734b784a3057bu, 0x534cdff4dd1dbe76u};
}
/****************************** pf::E1::pf::E1::B END ******************************/

/****************************** pf::E1::pf::E1::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::C>() {
return pf::meta::details::ID{0xd5cbecf93eedf2b3u, 0xf1f3b1a7eae76f60u};
}
/****************************** pf::E1::pf::E1::C END ******************************/

/****************************** pf::E1::pf::E1::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::D>() {
return pf::meta::details::ID{0x85ba14043c16cf1fu, 0xd37c9023da249524u};
}
/****************************** pf::E1::pf::E1::D END ******************************/

/****************************** pf::E1::pf::E1::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::E>() {
return pf::meta::details::ID{0x4120ee8df8c12a60u, 0xb0ad7289beb59a93u};
}
/****************************** pf::E1::pf::E1::E END ******************************/
}
/****************************** pf::E2::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xdd1f0dd806b2f806u, 0x9f14f1048efbf3ccu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xdd1f0dd806b2f806u, 0x9f14f1048efbf3ccu};
    constexpr static ID TypeID = pf::meta::details::ID{0xf2cd40cd11ec4eaeu, 0x53a5d4639d22d25bu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x70726ed70ffa7df0u, 0x7d4ab941518abcd9u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x70726ed70ffa7df0u, 0x7d4ab941518abcd9u};
    constexpr static ID TypeID = pf::meta::details::ID{0xf2cd40cd11ec4eaeu, 0x53a5d4639d22d25bu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x26eb252f6f242df6u, 0x1756440d8c728c75u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x26eb252f6f242df6u, 0x1756440d8c728c75u};
    constexpr static ID TypeID = pf::meta::details::ID{0xf2cd40cd11ec4eaeu, 0x53a5d4639d22d25bu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x9ea48db9741aff0bu, 0x47adbf23c68559e6u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x9ea48db9741aff0bu, 0x47adbf23c68559e6u};
    constexpr static ID TypeID = pf::meta::details::ID{0xf2cd40cd11ec4eaeu, 0x53a5d4639d22d25bu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xec325553eee31d1cu, 0x29acf6417cdd97c4u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xec325553eee31d1cu, 0x29acf6417cdd97c4u};
    constexpr static ID TypeID = pf::meta::details::ID{0xf2cd40cd11ec4eaeu, 0x53a5d4639d22d25bu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xf2cd40cd11ec4eaeu, 0x53a5d4639d22d25bu}> {
    struct details {
        
    };
    using Type = pf::E2;
    constexpr static ID TypeID = pf::meta::details::ID{0xf2cd40cd11ec4eaeu, 0x53a5d4639d22d25bu};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0xdd1f0dd806b2f806u, 0x9f14f1048efbf3ccu}, pf::meta::details::ID{0x70726ed70ffa7df0u, 0x7d4ab941518abcd9u}, pf::meta::details::ID{0x26eb252f6f242df6u, 0x1756440d8c728c75u}, pf::meta::details::ID{0x9ea48db9741aff0bu, 0x47adbf23c68559e6u}, pf::meta::details::ID{0xec325553eee31d1cu, 0x29acf6417cdd97c4u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x5e3bc18dec67146eu, 0xd550644d70111ab6u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x5e3bc18dec67146eu, 0xd550644d70111ab6u}, pf::meta::details::ID{0xf2cd40cd11ec4eaeu, 0x53a5d4639d22d25bu}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x41ed6570462a77a8u, 0x677c14de0f540c9au}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x41ed6570462a77a8u, 0x677c14de0f540c9au}, pf::meta::details::ID{0xf2cd40cd11ec4eaeu, 0x53a5d4639d22d25bu}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xf8fefb9645e2235du, 0xd261c3a2fb1ba36du}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0xf8fefb9645e2235du, 0xd261c3a2fb1ba36du}, pf::meta::details::ID{0xf2cd40cd11ec4eaeu, 0x53a5d4639d22d25bu}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd673198fd6504aceu, 0x8e53f2a264395decu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0xd673198fd6504aceu, 0x8e53f2a264395decu}, pf::meta::details::ID{0xf2cd40cd11ec4eaeu, 0x53a5d4639d22d25bu}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x10dfeaed369a7b94u, 0x1c444d47aea2f0edu}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x10dfeaed369a7b94u, 0x1c444d47aea2f0edu}, pf::meta::details::ID{0xf2cd40cd11ec4eaeu, 0x53a5d4639d22d25bu}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xfccacb3ab5ac408bu, 0x948de9ef679e1656u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0xfccacb3ab5ac408bu, 0x948de9ef679e1656u}, pf::meta::details::ID{0xf2cd40cd11ec4eaeu, 0x53a5d4639d22d25bu}> {};

/****************************** pf::E2 END ******************************/
namespace pf::meta::details {
/****************************** pf::E2 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2>() {
    return pf::meta::details::ID{0xf2cd40cd11ec4eaeu, 0x53a5d4639d22d25bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2>() {
    return pf::meta::details::ID{0x5e3bc18dec67146eu, 0xd550644d70111ab6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 &>() {
    return pf::meta::details::ID{0x41ed6570462a77a8u, 0x677c14de0f540c9au};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 &&>() {
    return pf::meta::details::ID{0xf8fefb9645e2235du, 0xd261c3a2fb1ba36du};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2 &>() {
    return pf::meta::details::ID{0xd673198fd6504aceu, 0x8e53f2a264395decu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 *>() {
    return pf::meta::details::ID{0x10dfeaed369a7b94u, 0x1c444d47aea2f0edu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2 *>() {
    return pf::meta::details::ID{0xfccacb3ab5ac408bu, 0x948de9ef679e1656u};
}
/****************************** pf::E2 END ******************************/

/****************************** pf::E2::pf::E2::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::A>() {
return pf::meta::details::ID{0xdd1f0dd806b2f806u, 0x9f14f1048efbf3ccu};
}
/****************************** pf::E2::pf::E2::A END ******************************/

/****************************** pf::E2::pf::E2::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::B>() {
return pf::meta::details::ID{0x70726ed70ffa7df0u, 0x7d4ab941518abcd9u};
}
/****************************** pf::E2::pf::E2::B END ******************************/

/****************************** pf::E2::pf::E2::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::C>() {
return pf::meta::details::ID{0x26eb252f6f242df6u, 0x1756440d8c728c75u};
}
/****************************** pf::E2::pf::E2::C END ******************************/

/****************************** pf::E2::pf::E2::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::D>() {
return pf::meta::details::ID{0x9ea48db9741aff0bu, 0x47adbf23c68559e6u};
}
/****************************** pf::E2::pf::E2::D END ******************************/

/****************************** pf::E2::pf::E2::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::E>() {
return pf::meta::details::ID{0xec325553eee31d1cu, 0x29acf6417cdd97c4u};
}
/****************************** pf::E2::pf::E2::E END ******************************/
}
/****************************** pf::E3::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x10e7ee3bf051a3a6u, 0xb5e18dc9bac0a326u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x10e7ee3bf051a3a6u, 0xb5e18dc9bac0a326u};
    constexpr static ID TypeID = pf::meta::details::ID{0xa312f3e9437dbd05u, 0x5a311280f3022fddu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x9686331f8267e44bu, 0x67819767d71bce02u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x9686331f8267e44bu, 0x67819767d71bce02u};
    constexpr static ID TypeID = pf::meta::details::ID{0xa312f3e9437dbd05u, 0x5a311280f3022fddu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x3f01cda31b0ab7eu, 0x9c711454fb47d523u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x3f01cda31b0ab7eu, 0x9c711454fb47d523u};
    constexpr static ID TypeID = pf::meta::details::ID{0xa312f3e9437dbd05u, 0x5a311280f3022fddu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xc326f932289479c3u, 0xd1a22c07960cbe44u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xc326f932289479c3u, 0xd1a22c07960cbe44u};
    constexpr static ID TypeID = pf::meta::details::ID{0xa312f3e9437dbd05u, 0x5a311280f3022fddu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x33d83839cde160f4u, 0x24fc793449fa4126u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x33d83839cde160f4u, 0x24fc793449fa4126u};
    constexpr static ID TypeID = pf::meta::details::ID{0xa312f3e9437dbd05u, 0x5a311280f3022fddu};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa312f3e9437dbd05u, 0x5a311280f3022fddu}> {
    struct details {
        
    };
    using Type = pf::E3;
    constexpr static ID TypeID = pf::meta::details::ID{0xa312f3e9437dbd05u, 0x5a311280f3022fddu};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x10e7ee3bf051a3a6u, 0xb5e18dc9bac0a326u}, pf::meta::details::ID{0x9686331f8267e44bu, 0x67819767d71bce02u}, pf::meta::details::ID{0x3f01cda31b0ab7eu, 0x9c711454fb47d523u}, pf::meta::details::ID{0xc326f932289479c3u, 0xd1a22c07960cbe44u}, pf::meta::details::ID{0x33d83839cde160f4u, 0x24fc793449fa4126u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x850db9b941d4bc9cu, 0x3522ed58d014a42cu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x850db9b941d4bc9cu, 0x3522ed58d014a42cu}, pf::meta::details::ID{0xa312f3e9437dbd05u, 0x5a311280f3022fddu}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x3b27f8f97ff3fbe1u, 0xeb23176eb2655fd1u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x3b27f8f97ff3fbe1u, 0xeb23176eb2655fd1u}, pf::meta::details::ID{0xa312f3e9437dbd05u, 0x5a311280f3022fddu}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xae00795ab644b7d2u, 0xd77e8f1aaf60cb32u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0xae00795ab644b7d2u, 0xd77e8f1aaf60cb32u}, pf::meta::details::ID{0xa312f3e9437dbd05u, 0x5a311280f3022fddu}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x170a62d9607cb291u, 0x72215c83e795f69fu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x170a62d9607cb291u, 0x72215c83e795f69fu}, pf::meta::details::ID{0xa312f3e9437dbd05u, 0x5a311280f3022fddu}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x9d3ba07992ce55b2u, 0xb952420336d3889au}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x9d3ba07992ce55b2u, 0xb952420336d3889au}, pf::meta::details::ID{0xa312f3e9437dbd05u, 0x5a311280f3022fddu}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x4686ebe46bac8097u, 0x63071c6d6037571cu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x4686ebe46bac8097u, 0x63071c6d6037571cu}, pf::meta::details::ID{0xa312f3e9437dbd05u, 0x5a311280f3022fddu}> {};

/****************************** pf::E3 END ******************************/
namespace pf::meta::details {
/****************************** pf::E3 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3>() {
    return pf::meta::details::ID{0xa312f3e9437dbd05u, 0x5a311280f3022fddu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3>() {
    return pf::meta::details::ID{0x850db9b941d4bc9cu, 0x3522ed58d014a42cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 &>() {
    return pf::meta::details::ID{0x3b27f8f97ff3fbe1u, 0xeb23176eb2655fd1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 &&>() {
    return pf::meta::details::ID{0xae00795ab644b7d2u, 0xd77e8f1aaf60cb32u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3 &>() {
    return pf::meta::details::ID{0x170a62d9607cb291u, 0x72215c83e795f69fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 *>() {
    return pf::meta::details::ID{0x9d3ba07992ce55b2u, 0xb952420336d3889au};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3 *>() {
    return pf::meta::details::ID{0x4686ebe46bac8097u, 0x63071c6d6037571cu};
}
/****************************** pf::E3 END ******************************/

/****************************** pf::E3::pf::E3::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::A>() {
return pf::meta::details::ID{0x10e7ee3bf051a3a6u, 0xb5e18dc9bac0a326u};
}
/****************************** pf::E3::pf::E3::A END ******************************/

/****************************** pf::E3::pf::E3::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::B>() {
return pf::meta::details::ID{0x9686331f8267e44bu, 0x67819767d71bce02u};
}
/****************************** pf::E3::pf::E3::B END ******************************/

/****************************** pf::E3::pf::E3::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::C>() {
return pf::meta::details::ID{0x3f01cda31b0ab7eu, 0x9c711454fb47d523u};
}
/****************************** pf::E3::pf::E3::C END ******************************/

/****************************** pf::E3::pf::E3::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::D>() {
return pf::meta::details::ID{0xc326f932289479c3u, 0xd1a22c07960cbe44u};
}
/****************************** pf::E3::pf::E3::D END ******************************/

/****************************** pf::E3::pf::E3::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::E>() {
return pf::meta::details::ID{0x33d83839cde160f4u, 0x24fc793449fa4126u};
}
/****************************** pf::E3::pf::E3::E END ******************************/
}
/****************************** pf::E4::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xab3cd4a798557326u, 0xa17f756375497af9u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xab3cd4a798557326u, 0xa17f756375497af9u};
    constexpr static ID TypeID = pf::meta::details::ID{0xb217ab9e81be3dfcu, 0x9bd1d0b941be10a5u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x8628c8f05acbdaacu, 0xa14d4f5e604d27afu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x8628c8f05acbdaacu, 0xa14d4f5e604d27afu};
    constexpr static ID TypeID = pf::meta::details::ID{0xb217ab9e81be3dfcu, 0x9bd1d0b941be10a5u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb7843d09a528c55au, 0x532582c7407a0b05u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xb7843d09a528c55au, 0x532582c7407a0b05u};
    constexpr static ID TypeID = pf::meta::details::ID{0xb217ab9e81be3dfcu, 0x9bd1d0b941be10a5u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x838d64a44570377eu, 0x6544602168b60321u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x838d64a44570377eu, 0x6544602168b60321u};
    constexpr static ID TypeID = pf::meta::details::ID{0xb217ab9e81be3dfcu, 0x9bd1d0b941be10a5u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x205dcbe796bb7c2bu, 0x297063d202018985u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x205dcbe796bb7c2bu, 0x297063d202018985u};
    constexpr static ID TypeID = pf::meta::details::ID{0xb217ab9e81be3dfcu, 0x9bd1d0b941be10a5u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb217ab9e81be3dfcu, 0x9bd1d0b941be10a5u}> {
    struct details {
        
    };
    using Type = pf::E4;
    constexpr static ID TypeID = pf::meta::details::ID{0xb217ab9e81be3dfcu, 0x9bd1d0b941be10a5u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0xab3cd4a798557326u, 0xa17f756375497af9u}, pf::meta::details::ID{0x8628c8f05acbdaacu, 0xa14d4f5e604d27afu}, pf::meta::details::ID{0xb7843d09a528c55au, 0x532582c7407a0b05u}, pf::meta::details::ID{0x838d64a44570377eu, 0x6544602168b60321u}, pf::meta::details::ID{0x205dcbe796bb7c2bu, 0x297063d202018985u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x4ddef32bfe3fa8b9u, 0xa3d8362744f44c83u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x4ddef32bfe3fa8b9u, 0xa3d8362744f44c83u}, pf::meta::details::ID{0xb217ab9e81be3dfcu, 0x9bd1d0b941be10a5u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x4139794f37ac73b5u, 0x239c3d7faf294fa0u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x4139794f37ac73b5u, 0x239c3d7faf294fa0u}, pf::meta::details::ID{0xb217ab9e81be3dfcu, 0x9bd1d0b941be10a5u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xded4461e69c9b490u, 0xb7c0f022c3d5c751u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0xded4461e69c9b490u, 0xb7c0f022c3d5c751u}, pf::meta::details::ID{0xb217ab9e81be3dfcu, 0x9bd1d0b941be10a5u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x80f03e12d89ec21fu, 0x62a89a8f365cd6d5u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x80f03e12d89ec21fu, 0x62a89a8f365cd6d5u}, pf::meta::details::ID{0xb217ab9e81be3dfcu, 0x9bd1d0b941be10a5u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb8153837f89dfcfeu, 0x92c5a9d8d9ac56c3u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0xb8153837f89dfcfeu, 0x92c5a9d8d9ac56c3u}, pf::meta::details::ID{0xb217ab9e81be3dfcu, 0x9bd1d0b941be10a5u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xcaef5152c42da5d0u, 0xb4143f231d10a485u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0xcaef5152c42da5d0u, 0xb4143f231d10a485u}, pf::meta::details::ID{0xb217ab9e81be3dfcu, 0x9bd1d0b941be10a5u}> {};

/****************************** pf::E4 END ******************************/
namespace pf::meta::details {
/****************************** pf::E4 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4>() {
    return pf::meta::details::ID{0xb217ab9e81be3dfcu, 0x9bd1d0b941be10a5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4>() {
    return pf::meta::details::ID{0x4ddef32bfe3fa8b9u, 0xa3d8362744f44c83u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 &>() {
    return pf::meta::details::ID{0x4139794f37ac73b5u, 0x239c3d7faf294fa0u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 &&>() {
    return pf::meta::details::ID{0xded4461e69c9b490u, 0xb7c0f022c3d5c751u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4 &>() {
    return pf::meta::details::ID{0x80f03e12d89ec21fu, 0x62a89a8f365cd6d5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 *>() {
    return pf::meta::details::ID{0xb8153837f89dfcfeu, 0x92c5a9d8d9ac56c3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4 *>() {
    return pf::meta::details::ID{0xcaef5152c42da5d0u, 0xb4143f231d10a485u};
}
/****************************** pf::E4 END ******************************/

/****************************** pf::E4::pf::E4::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::A>() {
return pf::meta::details::ID{0xab3cd4a798557326u, 0xa17f756375497af9u};
}
/****************************** pf::E4::pf::E4::A END ******************************/

/****************************** pf::E4::pf::E4::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::B>() {
return pf::meta::details::ID{0x8628c8f05acbdaacu, 0xa14d4f5e604d27afu};
}
/****************************** pf::E4::pf::E4::B END ******************************/

/****************************** pf::E4::pf::E4::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::C>() {
return pf::meta::details::ID{0xb7843d09a528c55au, 0x532582c7407a0b05u};
}
/****************************** pf::E4::pf::E4::C END ******************************/

/****************************** pf::E4::pf::E4::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::D>() {
return pf::meta::details::ID{0x838d64a44570377eu, 0x6544602168b60321u};
}
/****************************** pf::E4::pf::E4::D END ******************************/

/****************************** pf::E4::pf::E4::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::E>() {
return pf::meta::details::ID{0x205dcbe796bb7c2bu, 0x297063d202018985u};
}
/****************************** pf::E4::pf::E4::E END ******************************/
}
/****************************** pf::E5::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x6e0437d020ee0abfu, 0x45f6fb9ba84fda3bu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x6e0437d020ee0abfu, 0x45f6fb9ba84fda3bu};
    constexpr static ID TypeID = pf::meta::details::ID{0x87734c199b0335cdu, 0x963661f00b6d023u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xda9f3c29a6d1266bu, 0x9109b49941d55694u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xda9f3c29a6d1266bu, 0x9109b49941d55694u};
    constexpr static ID TypeID = pf::meta::details::ID{0x87734c199b0335cdu, 0x963661f00b6d023u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xbb6aa1dc3ee43996u, 0x41b22392261e165eu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xbb6aa1dc3ee43996u, 0x41b22392261e165eu};
    constexpr static ID TypeID = pf::meta::details::ID{0x87734c199b0335cdu, 0x963661f00b6d023u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x8bbf0f4d9d5327e5u, 0x7b54ae39514a87bdu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x8bbf0f4d9d5327e5u, 0x7b54ae39514a87bdu};
    constexpr static ID TypeID = pf::meta::details::ID{0x87734c199b0335cdu, 0x963661f00b6d023u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xcefc7f92dc526b66u, 0x88e64400158874b4u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xcefc7f92dc526b66u, 0x88e64400158874b4u};
    constexpr static ID TypeID = pf::meta::details::ID{0x87734c199b0335cdu, 0x963661f00b6d023u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x87734c199b0335cdu, 0x963661f00b6d023u}> {
    struct details {
        
    };
    using Type = pf::E5;
    constexpr static ID TypeID = pf::meta::details::ID{0x87734c199b0335cdu, 0x963661f00b6d023u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x6e0437d020ee0abfu, 0x45f6fb9ba84fda3bu}, pf::meta::details::ID{0xda9f3c29a6d1266bu, 0x9109b49941d55694u}, pf::meta::details::ID{0xbb6aa1dc3ee43996u, 0x41b22392261e165eu}, pf::meta::details::ID{0x8bbf0f4d9d5327e5u, 0x7b54ae39514a87bdu}, pf::meta::details::ID{0xcefc7f92dc526b66u, 0x88e64400158874b4u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x3f8367fcce138d0u, 0x751242577e7637e8u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x3f8367fcce138d0u, 0x751242577e7637e8u}, pf::meta::details::ID{0x87734c199b0335cdu, 0x963661f00b6d023u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xbc13b2a9b4a55064u, 0xe46fb421dfe007eau}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0xbc13b2a9b4a55064u, 0xe46fb421dfe007eau}, pf::meta::details::ID{0x87734c199b0335cdu, 0x963661f00b6d023u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x9041f1e7d412179bu, 0xc07641fee20ba8e5u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x9041f1e7d412179bu, 0xc07641fee20ba8e5u}, pf::meta::details::ID{0x87734c199b0335cdu, 0x963661f00b6d023u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xf4e6838b4b8f6142u, 0x243691791378cb6fu}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0xf4e6838b4b8f6142u, 0x243691791378cb6fu}, pf::meta::details::ID{0x87734c199b0335cdu, 0x963661f00b6d023u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xff29eb31b03c2666u, 0x5e5bee6c79db2f39u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0xff29eb31b03c2666u, 0x5e5bee6c79db2f39u}, pf::meta::details::ID{0x87734c199b0335cdu, 0x963661f00b6d023u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x849c9a6ce60e0f7bu, 0x1a4a78192d074370u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x849c9a6ce60e0f7bu, 0x1a4a78192d074370u}, pf::meta::details::ID{0x87734c199b0335cdu, 0x963661f00b6d023u}> {};

/****************************** pf::E5 END ******************************/
namespace pf::meta::details {
/****************************** pf::E5 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5>() {
    return pf::meta::details::ID{0x87734c199b0335cdu, 0x963661f00b6d023u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5>() {
    return pf::meta::details::ID{0x3f8367fcce138d0u, 0x751242577e7637e8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 &>() {
    return pf::meta::details::ID{0xbc13b2a9b4a55064u, 0xe46fb421dfe007eau};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 &&>() {
    return pf::meta::details::ID{0x9041f1e7d412179bu, 0xc07641fee20ba8e5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5 &>() {
    return pf::meta::details::ID{0xf4e6838b4b8f6142u, 0x243691791378cb6fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 *>() {
    return pf::meta::details::ID{0xff29eb31b03c2666u, 0x5e5bee6c79db2f39u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5 *>() {
    return pf::meta::details::ID{0x849c9a6ce60e0f7bu, 0x1a4a78192d074370u};
}
/****************************** pf::E5 END ******************************/

/****************************** pf::E5::pf::E5::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::A>() {
return pf::meta::details::ID{0x6e0437d020ee0abfu, 0x45f6fb9ba84fda3bu};
}
/****************************** pf::E5::pf::E5::A END ******************************/

/****************************** pf::E5::pf::E5::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::B>() {
return pf::meta::details::ID{0xda9f3c29a6d1266bu, 0x9109b49941d55694u};
}
/****************************** pf::E5::pf::E5::B END ******************************/

/****************************** pf::E5::pf::E5::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::C>() {
return pf::meta::details::ID{0xbb6aa1dc3ee43996u, 0x41b22392261e165eu};
}
/****************************** pf::E5::pf::E5::C END ******************************/

/****************************** pf::E5::pf::E5::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::D>() {
return pf::meta::details::ID{0x8bbf0f4d9d5327e5u, 0x7b54ae39514a87bdu};
}
/****************************** pf::E5::pf::E5::D END ******************************/

/****************************** pf::E5::pf::E5::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::E>() {
return pf::meta::details::ID{0xcefc7f92dc526b66u, 0x88e64400158874b4u};
}
/****************************** pf::E5::pf::E5::E END ******************************/
}
/****************************** pf::E6::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x5433e7ddc95482e2u, 0x94e19592c30809d5u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x5433e7ddc95482e2u, 0x94e19592c30809d5u};
    constexpr static ID TypeID = pf::meta::details::ID{0xff3442476d8efc6u, 0xcd4d776b9bb74db3u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xc27cba81c7891badu, 0x55b75fb9148e09d6u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xc27cba81c7891badu, 0x55b75fb9148e09d6u};
    constexpr static ID TypeID = pf::meta::details::ID{0xff3442476d8efc6u, 0xcd4d776b9bb74db3u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe7f5ef95fa5c5abcu, 0xf81c497e17af5cb3u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xe7f5ef95fa5c5abcu, 0xf81c497e17af5cb3u};
    constexpr static ID TypeID = pf::meta::details::ID{0xff3442476d8efc6u, 0xcd4d776b9bb74db3u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xe47dc80b00efa974u, 0xf3d911f11edbde54u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xe47dc80b00efa974u, 0xf3d911f11edbde54u};
    constexpr static ID TypeID = pf::meta::details::ID{0xff3442476d8efc6u, 0xcd4d776b9bb74db3u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xff2e60fda7a89b87u, 0xe6c8183bedccd7d5u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xff2e60fda7a89b87u, 0xe6c8183bedccd7d5u};
    constexpr static ID TypeID = pf::meta::details::ID{0xff3442476d8efc6u, 0xcd4d776b9bb74db3u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xff3442476d8efc6u, 0xcd4d776b9bb74db3u}> {
    struct details {
        
    };
    using Type = pf::E6;
    constexpr static ID TypeID = pf::meta::details::ID{0xff3442476d8efc6u, 0xcd4d776b9bb74db3u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x5433e7ddc95482e2u, 0x94e19592c30809d5u}, pf::meta::details::ID{0xc27cba81c7891badu, 0x55b75fb9148e09d6u}, pf::meta::details::ID{0xe7f5ef95fa5c5abcu, 0xf81c497e17af5cb3u}, pf::meta::details::ID{0xe47dc80b00efa974u, 0xf3d911f11edbde54u}, pf::meta::details::ID{0xff2e60fda7a89b87u, 0xe6c8183bedccd7d5u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x6725585f029399b9u, 0x8534b00d4b260038u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x6725585f029399b9u, 0x8534b00d4b260038u}, pf::meta::details::ID{0xff3442476d8efc6u, 0xcd4d776b9bb74db3u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x1bfdf607eb91b97bu, 0x619deb9f0115a9a8u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x1bfdf607eb91b97bu, 0x619deb9f0115a9a8u}, pf::meta::details::ID{0xff3442476d8efc6u, 0xcd4d776b9bb74db3u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xd4d6d49bc61e4d42u, 0xca4149e79def0733u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0xd4d6d49bc61e4d42u, 0xca4149e79def0733u}, pf::meta::details::ID{0xff3442476d8efc6u, 0xcd4d776b9bb74db3u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x720fcc5dfa675d56u, 0x5c5858f0cadb6dc7u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x720fcc5dfa675d56u, 0x5c5858f0cadb6dc7u}, pf::meta::details::ID{0xff3442476d8efc6u, 0xcd4d776b9bb74db3u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x82e25a460a31201fu, 0x11dd5732c3b0f3dbu}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x82e25a460a31201fu, 0x11dd5732c3b0f3dbu}, pf::meta::details::ID{0xff3442476d8efc6u, 0xcd4d776b9bb74db3u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xdae1ecdca189d567u, 0x23d4efde3ba41c5bu}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0xdae1ecdca189d567u, 0x23d4efde3ba41c5bu}, pf::meta::details::ID{0xff3442476d8efc6u, 0xcd4d776b9bb74db3u}> {};

/****************************** pf::E6 END ******************************/
namespace pf::meta::details {
/****************************** pf::E6 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6>() {
    return pf::meta::details::ID{0xff3442476d8efc6u, 0xcd4d776b9bb74db3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6>() {
    return pf::meta::details::ID{0x6725585f029399b9u, 0x8534b00d4b260038u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 &>() {
    return pf::meta::details::ID{0x1bfdf607eb91b97bu, 0x619deb9f0115a9a8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 &&>() {
    return pf::meta::details::ID{0xd4d6d49bc61e4d42u, 0xca4149e79def0733u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6 &>() {
    return pf::meta::details::ID{0x720fcc5dfa675d56u, 0x5c5858f0cadb6dc7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 *>() {
    return pf::meta::details::ID{0x82e25a460a31201fu, 0x11dd5732c3b0f3dbu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6 *>() {
    return pf::meta::details::ID{0xdae1ecdca189d567u, 0x23d4efde3ba41c5bu};
}
/****************************** pf::E6 END ******************************/

/****************************** pf::E6::pf::E6::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::A>() {
return pf::meta::details::ID{0x5433e7ddc95482e2u, 0x94e19592c30809d5u};
}
/****************************** pf::E6::pf::E6::A END ******************************/

/****************************** pf::E6::pf::E6::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::B>() {
return pf::meta::details::ID{0xc27cba81c7891badu, 0x55b75fb9148e09d6u};
}
/****************************** pf::E6::pf::E6::B END ******************************/

/****************************** pf::E6::pf::E6::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::C>() {
return pf::meta::details::ID{0xe7f5ef95fa5c5abcu, 0xf81c497e17af5cb3u};
}
/****************************** pf::E6::pf::E6::C END ******************************/

/****************************** pf::E6::pf::E6::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::D>() {
return pf::meta::details::ID{0xe47dc80b00efa974u, 0xf3d911f11edbde54u};
}
/****************************** pf::E6::pf::E6::D END ******************************/

/****************************** pf::E6::pf::E6::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::E>() {
return pf::meta::details::ID{0xff2e60fda7a89b87u, 0xe6c8183bedccd7d5u};
}
/****************************** pf::E6::pf::E6::E END ******************************/
}
/****************************** pf::E7::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xcad8e3bceefddd46u, 0x88aaca05826de1b2u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xcad8e3bceefddd46u, 0x88aaca05826de1b2u};
    constexpr static ID TypeID = pf::meta::details::ID{0xf32178682614e8d4u, 0x87d88d24243c83f2u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x3c55b4de1d9c4239u, 0x28cf4156318ec399u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x3c55b4de1d9c4239u, 0x28cf4156318ec399u};
    constexpr static ID TypeID = pf::meta::details::ID{0xf32178682614e8d4u, 0x87d88d24243c83f2u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x4944eed98f970096u, 0xe9501eede6f5ea33u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x4944eed98f970096u, 0xe9501eede6f5ea33u};
    constexpr static ID TypeID = pf::meta::details::ID{0xf32178682614e8d4u, 0x87d88d24243c83f2u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x857fd666718b8674u, 0xeff48b911e1a2cc1u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x857fd666718b8674u, 0xeff48b911e1a2cc1u};
    constexpr static ID TypeID = pf::meta::details::ID{0xf32178682614e8d4u, 0x87d88d24243c83f2u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x9f67f8665d613de9u, 0x5d3ab3c00f84746eu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x9f67f8665d613de9u, 0x5d3ab3c00f84746eu};
    constexpr static ID TypeID = pf::meta::details::ID{0xf32178682614e8d4u, 0x87d88d24243c83f2u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xf32178682614e8d4u, 0x87d88d24243c83f2u}> {
    struct details {
        
    };
    using Type = pf::E7;
    constexpr static ID TypeID = pf::meta::details::ID{0xf32178682614e8d4u, 0x87d88d24243c83f2u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0xcad8e3bceefddd46u, 0x88aaca05826de1b2u}, pf::meta::details::ID{0x3c55b4de1d9c4239u, 0x28cf4156318ec399u}, pf::meta::details::ID{0x4944eed98f970096u, 0xe9501eede6f5ea33u}, pf::meta::details::ID{0x857fd666718b8674u, 0xeff48b911e1a2cc1u}, pf::meta::details::ID{0x9f67f8665d613de9u, 0x5d3ab3c00f84746eu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x2642f5ca81ee1db5u, 0x91d06995a11fb068u}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x2642f5ca81ee1db5u, 0x91d06995a11fb068u}, pf::meta::details::ID{0xf32178682614e8d4u, 0x87d88d24243c83f2u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x5bf114cb5e9096f1u, 0x905b579ca0e53149u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x5bf114cb5e9096f1u, 0x905b579ca0e53149u}, pf::meta::details::ID{0xf32178682614e8d4u, 0x87d88d24243c83f2u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb391b4440cba6e5du, 0x5e7fe7aaa438a609u}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0xb391b4440cba6e5du, 0x5e7fe7aaa438a609u}, pf::meta::details::ID{0xf32178682614e8d4u, 0x87d88d24243c83f2u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xaa96c9c96308b895u, 0xfb2638a8019e9e46u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0xaa96c9c96308b895u, 0xfb2638a8019e9e46u}, pf::meta::details::ID{0xf32178682614e8d4u, 0x87d88d24243c83f2u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x9405d3a579979e21u, 0x998c7bd1a0e8b36fu}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x9405d3a579979e21u, 0x998c7bd1a0e8b36fu}, pf::meta::details::ID{0xf32178682614e8d4u, 0x87d88d24243c83f2u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x50208ba3a5c127a6u, 0x174eafe96dd03eb3u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x50208ba3a5c127a6u, 0x174eafe96dd03eb3u}, pf::meta::details::ID{0xf32178682614e8d4u, 0x87d88d24243c83f2u}> {};

/****************************** pf::E7 END ******************************/
namespace pf::meta::details {
/****************************** pf::E7 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7>() {
    return pf::meta::details::ID{0xf32178682614e8d4u, 0x87d88d24243c83f2u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7>() {
    return pf::meta::details::ID{0x2642f5ca81ee1db5u, 0x91d06995a11fb068u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 &>() {
    return pf::meta::details::ID{0x5bf114cb5e9096f1u, 0x905b579ca0e53149u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 &&>() {
    return pf::meta::details::ID{0xb391b4440cba6e5du, 0x5e7fe7aaa438a609u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7 &>() {
    return pf::meta::details::ID{0xaa96c9c96308b895u, 0xfb2638a8019e9e46u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 *>() {
    return pf::meta::details::ID{0x9405d3a579979e21u, 0x998c7bd1a0e8b36fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7 *>() {
    return pf::meta::details::ID{0x50208ba3a5c127a6u, 0x174eafe96dd03eb3u};
}
/****************************** pf::E7 END ******************************/

/****************************** pf::E7::pf::E7::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::A>() {
return pf::meta::details::ID{0xcad8e3bceefddd46u, 0x88aaca05826de1b2u};
}
/****************************** pf::E7::pf::E7::A END ******************************/

/****************************** pf::E7::pf::E7::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::B>() {
return pf::meta::details::ID{0x3c55b4de1d9c4239u, 0x28cf4156318ec399u};
}
/****************************** pf::E7::pf::E7::B END ******************************/

/****************************** pf::E7::pf::E7::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::C>() {
return pf::meta::details::ID{0x4944eed98f970096u, 0xe9501eede6f5ea33u};
}
/****************************** pf::E7::pf::E7::C END ******************************/

/****************************** pf::E7::pf::E7::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::D>() {
return pf::meta::details::ID{0x857fd666718b8674u, 0xeff48b911e1a2cc1u};
}
/****************************** pf::E7::pf::E7::D END ******************************/

/****************************** pf::E7::pf::E7::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::E>() {
return pf::meta::details::ID{0x9f67f8665d613de9u, 0x5d3ab3c00f84746eu};
}
/****************************** pf::E7::pf::E7::E END ******************************/
}
/****************************** pf::E8::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x219c7ae56485fa3fu, 0xd27801969272b1ccu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x219c7ae56485fa3fu, 0xd27801969272b1ccu};
    constexpr static ID TypeID = pf::meta::details::ID{0xdbdee0ba22c443dfu, 0x82af4007d2ed9e70u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa544c33f1439638au, 0x84dbc87d17772a64u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xa544c33f1439638au, 0x84dbc87d17772a64u};
    constexpr static ID TypeID = pf::meta::details::ID{0xdbdee0ba22c443dfu, 0x82af4007d2ed9e70u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x8bc4f21381daaca9u, 0xcf30e2f3fd2ffc17u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x8bc4f21381daaca9u, 0xcf30e2f3fd2ffc17u};
    constexpr static ID TypeID = pf::meta::details::ID{0xdbdee0ba22c443dfu, 0x82af4007d2ed9e70u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x9a774a8f957adedfu, 0x3e9d425165ca79b7u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x9a774a8f957adedfu, 0x3e9d425165ca79b7u};
    constexpr static ID TypeID = pf::meta::details::ID{0xdbdee0ba22c443dfu, 0x82af4007d2ed9e70u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x57ff07bbcbc451c0u, 0x67e79b44b9ed6d44u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x57ff07bbcbc451c0u, 0x67e79b44b9ed6d44u};
    constexpr static ID TypeID = pf::meta::details::ID{0xdbdee0ba22c443dfu, 0x82af4007d2ed9e70u};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xdbdee0ba22c443dfu, 0x82af4007d2ed9e70u}> {
    struct details {
        
    };
    using Type = pf::E8;
    constexpr static ID TypeID = pf::meta::details::ID{0xdbdee0ba22c443dfu, 0x82af4007d2ed9e70u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x219c7ae56485fa3fu, 0xd27801969272b1ccu}, pf::meta::details::ID{0xa544c33f1439638au, 0x84dbc87d17772a64u}, pf::meta::details::ID{0x8bc4f21381daaca9u, 0xcf30e2f3fd2ffc17u}, pf::meta::details::ID{0x9a774a8f957adedfu, 0x3e9d425165ca79b7u}, pf::meta::details::ID{0x57ff07bbcbc451c0u, 0x67e79b44b9ed6d44u});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa7a7ffc70f0aae73u, 0xa9f51b362495d65eu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0xa7a7ffc70f0aae73u, 0xa9f51b362495d65eu}, pf::meta::details::ID{0xdbdee0ba22c443dfu, 0x82af4007d2ed9e70u}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x96d787735840c690u, 0x3d64ca5b067ba01cu}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x96d787735840c690u, 0x3d64ca5b067ba01cu}, pf::meta::details::ID{0xdbdee0ba22c443dfu, 0x82af4007d2ed9e70u}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x82cb6a000974cb34u, 0x7ec09267478768efu}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x82cb6a000974cb34u, 0x7ec09267478768efu}, pf::meta::details::ID{0xdbdee0ba22c443dfu, 0x82af4007d2ed9e70u}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xb86b23f24483f0dau, 0x4ffa8fe19ee56ac9u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0xb86b23f24483f0dau, 0x4ffa8fe19ee56ac9u}, pf::meta::details::ID{0xdbdee0ba22c443dfu, 0x82af4007d2ed9e70u}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x1f7135aec786649au, 0xee8fd92f0ab416d6u}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x1f7135aec786649au, 0xee8fd92f0ab416d6u}, pf::meta::details::ID{0xdbdee0ba22c443dfu, 0x82af4007d2ed9e70u}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x54b8e9b923074389u, 0x621b6f8d11f9c19du}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x54b8e9b923074389u, 0x621b6f8d11f9c19du}, pf::meta::details::ID{0xdbdee0ba22c443dfu, 0x82af4007d2ed9e70u}> {};

/****************************** pf::E8 END ******************************/
namespace pf::meta::details {
/****************************** pf::E8 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8>() {
    return pf::meta::details::ID{0xdbdee0ba22c443dfu, 0x82af4007d2ed9e70u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8>() {
    return pf::meta::details::ID{0xa7a7ffc70f0aae73u, 0xa9f51b362495d65eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 &>() {
    return pf::meta::details::ID{0x96d787735840c690u, 0x3d64ca5b067ba01cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 &&>() {
    return pf::meta::details::ID{0x82cb6a000974cb34u, 0x7ec09267478768efu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8 &>() {
    return pf::meta::details::ID{0xb86b23f24483f0dau, 0x4ffa8fe19ee56ac9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 *>() {
    return pf::meta::details::ID{0x1f7135aec786649au, 0xee8fd92f0ab416d6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8 *>() {
    return pf::meta::details::ID{0x54b8e9b923074389u, 0x621b6f8d11f9c19du};
}
/****************************** pf::E8 END ******************************/

/****************************** pf::E8::pf::E8::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::A>() {
return pf::meta::details::ID{0x219c7ae56485fa3fu, 0xd27801969272b1ccu};
}
/****************************** pf::E8::pf::E8::A END ******************************/

/****************************** pf::E8::pf::E8::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::B>() {
return pf::meta::details::ID{0xa544c33f1439638au, 0x84dbc87d17772a64u};
}
/****************************** pf::E8::pf::E8::B END ******************************/

/****************************** pf::E8::pf::E8::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::C>() {
return pf::meta::details::ID{0x8bc4f21381daaca9u, 0xcf30e2f3fd2ffc17u};
}
/****************************** pf::E8::pf::E8::C END ******************************/

/****************************** pf::E8::pf::E8::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::D>() {
return pf::meta::details::ID{0x9a774a8f957adedfu, 0x3e9d425165ca79b7u};
}
/****************************** pf::E8::pf::E8::D END ******************************/

/****************************** pf::E8::pf::E8::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::E>() {
return pf::meta::details::ID{0x57ff07bbcbc451c0u, 0x67e79b44b9ed6d44u};
}
/****************************** pf::E8::pf::E8::E END ******************************/
}
/****************************** pf::E9::A START ******************************/
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x463a4f5803311c17u, 0x8f0f16451bbd569au}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x463a4f5803311c17u, 0x8f0f16451bbd569au};
    constexpr static ID TypeID = pf::meta::details::ID{0x1031967066fed842u, 0x237c338d62ea552du};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xa4c926c6a088c010u, 0xcff2f3b27c1c6171u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xa4c926c6a088c010u, 0xcff2f3b27c1c6171u};
    constexpr static ID TypeID = pf::meta::details::ID{0x1031967066fed842u, 0x237c338d62ea552du};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x6bf1d64e5c8304f6u, 0x7ca46cd581446f60u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x6bf1d64e5c8304f6u, 0x7ca46cd581446f60u};
    constexpr static ID TypeID = pf::meta::details::ID{0x1031967066fed842u, 0x237c338d62ea552du};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x430f10923887cf7u, 0xfebfdd839f431170u}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0x430f10923887cf7u, 0xfebfdd839f431170u};
    constexpr static ID TypeID = pf::meta::details::ID{0x1031967066fed842u, 0x237c338d62ea552du};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0xec0202cfbbb089dau, 0xb64f605c0dbf974bu}> {
    struct details {
        
    };
    constexpr static ID ValueID = pf::meta::details::ID{0xec0202cfbbb089dau, 0xb64f605c0dbf974bu};
    constexpr static ID TypeID = pf::meta::details::ID{0x1031967066fed842u, 0x237c338d62ea552du};
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
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x1031967066fed842u, 0x237c338d62ea552du}> {
    struct details {
        
    };
    using Type = pf::E9;
    constexpr static ID TypeID = pf::meta::details::ID{0x1031967066fed842u, 0x237c338d62ea552du};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(pf::meta::details::ID{0x463a4f5803311c17u, 0x8f0f16451bbd569au}, pf::meta::details::ID{0xa4c926c6a088c010u, 0xcff2f3b27c1c6171u}, pf::meta::details::ID{0x6bf1d64e5c8304f6u, 0x7ca46cd581446f60u}, pf::meta::details::ID{0x430f10923887cf7u, 0xfebfdd839f431170u}, pf::meta::details::ID{0xec0202cfbbb089dau, 0xb64f605c0dbf974bu});
};

// const
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x2942eaa80590eb9bu, 0x44444991b256c0bu}>
    : pf::meta::details::StaticInfo_ConstWrap<pf::meta::details::ID{0x2942eaa80590eb9bu, 0x44444991b256c0bu}, pf::meta::details::ID{0x1031967066fed842u, 0x237c338d62ea552du}> {};
// &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x4e47558ff2c15b27u, 0x27bcf9732a820a19u}>
    : pf::meta::details::StaticInfo_LRefWrap<pf::meta::details::ID{0x4e47558ff2c15b27u, 0x27bcf9732a820a19u}, pf::meta::details::ID{0x1031967066fed842u, 0x237c338d62ea552du}> {};
// &&
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x91adc83977b1b165u, 0x8ac0cfeaeb4dd44fu}>
    : pf::meta::details::StaticInfo_RRefWrap<pf::meta::details::ID{0x91adc83977b1b165u, 0x8ac0cfeaeb4dd44fu}, pf::meta::details::ID{0x1031967066fed842u, 0x237c338d62ea552du}> {};
// const &
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x30c5e5ea4df9e573u, 0x65b6fd9919c89358u}>
    : pf::meta::details::StaticInfo_ConstLRefWrap<pf::meta::details::ID{0x30c5e5ea4df9e573u, 0x65b6fd9919c89358u}, pf::meta::details::ID{0x1031967066fed842u, 0x237c338d62ea552du}> {};
// *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x1b69c06caece391u, 0xa6badc3137c3efau}>
    : pf::meta::details::StaticInfo_PtrWrap<pf::meta::details::ID{0x1b69c06caece391u, 0xa6badc3137c3efau}, pf::meta::details::ID{0x1031967066fed842u, 0x237c338d62ea552du}> {};
// const *
template<>
struct pf::meta::details::StaticInfo<pf::meta::details::ID{0x5c29f9cce64924a5u, 0xed0c4eef8a82a379u}>
    : pf::meta::details::StaticInfo_ConstPtrWrap<pf::meta::details::ID{0x5c29f9cce64924a5u, 0xed0c4eef8a82a379u}, pf::meta::details::ID{0x1031967066fed842u, 0x237c338d62ea552du}> {};

/****************************** pf::E9 END ******************************/
namespace pf::meta::details {
/****************************** pf::E9 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9>() {
    return pf::meta::details::ID{0x1031967066fed842u, 0x237c338d62ea552du};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9>() {
    return pf::meta::details::ID{0x2942eaa80590eb9bu, 0x44444991b256c0bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 &>() {
    return pf::meta::details::ID{0x4e47558ff2c15b27u, 0x27bcf9732a820a19u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 &&>() {
    return pf::meta::details::ID{0x91adc83977b1b165u, 0x8ac0cfeaeb4dd44fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9 &>() {
    return pf::meta::details::ID{0x30c5e5ea4df9e573u, 0x65b6fd9919c89358u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 *>() {
    return pf::meta::details::ID{0x1b69c06caece391u, 0xa6badc3137c3efau};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9 *>() {
    return pf::meta::details::ID{0x5c29f9cce64924a5u, 0xed0c4eef8a82a379u};
}
/****************************** pf::E9 END ******************************/

/****************************** pf::E9::pf::E9::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::A>() {
return pf::meta::details::ID{0x463a4f5803311c17u, 0x8f0f16451bbd569au};
}
/****************************** pf::E9::pf::E9::A END ******************************/

/****************************** pf::E9::pf::E9::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::B>() {
return pf::meta::details::ID{0xa4c926c6a088c010u, 0xcff2f3b27c1c6171u};
}
/****************************** pf::E9::pf::E9::B END ******************************/

/****************************** pf::E9::pf::E9::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::C>() {
return pf::meta::details::ID{0x6bf1d64e5c8304f6u, 0x7ca46cd581446f60u};
}
/****************************** pf::E9::pf::E9::C END ******************************/

/****************************** pf::E9::pf::E9::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::D>() {
return pf::meta::details::ID{0x430f10923887cf7u, 0xfebfdd839f431170u};
}
/****************************** pf::E9::pf::E9::D END ******************************/

/****************************** pf::E9::pf::E9::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::E>() {
return pf::meta::details::ID{0xec0202cfbbb089dau, 0xb64f605c0dbf974bu};
}
/****************************** pf::E9::pf::E9::E END ******************************/
}

