
#pragma once

#include "meta/common.h"
#include "test.h"
#include <pf_common/array.h>
#include <pf_common/concepts/ranges.h>
#include <type_traits>

/****************************** pf::SomeEnum::Value1 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf5b738a455c43efbu, 0x654b72e0f1ad99d1u}> {
    struct details {
        constexpr static auto ArgArray_11420738409591974018 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_9967345316246474928 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_717619965737370577 = pf::make_array<std::string_view>();

    };
    constexpr static ID ValueID = ::pf::meta::ID{0xf5b738a455c43efbu, 0x654b72e0f1ad99d1u};
    constexpr static ID TypeID = ::pf::meta::ID{0x37813f6e3f6f3669u, 0xb6156809fffe6167u};
    using Type = pf::SomeEnum;

    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(pf::meta::Attribute{"test", std::span<const std::string_view>{details::ArgArray_11420738409591974018}}, pf::meta::Attribute{"test2", std::span<const std::string_view>{details::ArgArray_9967345316246474928}}, pf::meta::Attribute{"test3", std::span<const std::string_view>{details::ArgArray_717619965737370577}});

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x86bf3d082693b73u, 0x100657d5d81e328u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x86bf3d082693b73u, 0x100657d5d81e328u};
    constexpr static ID TypeID = ::pf::meta::ID{0x37813f6e3f6f3669u, 0xb6156809fffe6167u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x37813f6e3f6f3669u, 0xb6156809fffe6167u}> {
    struct details {
        constexpr static auto ArgArray_14341789414902109013 = pf::make_array<std::string_view>(R"arg(()()()((())))arg", R"arg([[nodiscard]])arg", R"arg(1ll)arg", R"arg(1.011)arg", R"arg([]{}())arg", R"arg("yeet")arg", R"arg('a')arg", R"arg([][][]:::3214234...[][][][])arg");
constexpr static auto ArgArray_4372837323384191028 = pf::make_array<std::string_view>();
constexpr static auto ArgArray_10051646642585065158 = pf::make_array<std::string_view>(R"arg(1ll)arg", R"arg(1.011)arg", R"arg("yeet")arg");
constexpr static auto ArgArray_17805534564702053736 = pf::make_array<std::string_view>();

    };
    using Type = pf::SomeEnum;
    constexpr static ID TypeID = ::pf::meta::ID{0x37813f6e3f6f3669u, 0xb6156809fffe6167u};

    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(pf::meta::Attribute{"pf::operators", std::span<const std::string_view>{details::ArgArray_14341789414902109013}}, pf::meta::Attribute{"pf::hihi", std::span<const std::string_view>{details::ArgArray_4372837323384191028}}, pf::meta::Attribute{"pf::operators2", std::span<const std::string_view>{details::ArgArray_10051646642585065158}}, pf::meta::Attribute{"pf::hihi2", std::span<const std::string_view>{details::ArgArray_17805534564702053736}});

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0xf5b738a455c43efbu, 0x654b72e0f1ad99d1u}, ::pf::meta::ID{0x86bf3d082693b73u, 0x100657d5d81e328u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xafd5d70a0206bff3u, 0x503b23d9d0179634u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xafd5d70a0206bff3u, 0x503b23d9d0179634u}, ::pf::meta::ID{0x37813f6e3f6f3669u, 0xb6156809fffe6167u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x29915634c83fff1fu, 0x4d75c736d100947bu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x29915634c83fff1fu, 0x4d75c736d100947bu}, ::pf::meta::ID{0x37813f6e3f6f3669u, 0xb6156809fffe6167u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe4c587fbad8706cbu, 0x16bb701a625042a8u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xe4c587fbad8706cbu, 0x16bb701a625042a8u}, ::pf::meta::ID{0x37813f6e3f6f3669u, 0xb6156809fffe6167u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x28e2bddee6107836u, 0x545acdae0ff6e528u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x28e2bddee6107836u, 0x545acdae0ff6e528u}, ::pf::meta::ID{0xafd5d70a0206bff3u, 0x503b23d9d0179634u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x28d84c107df9f382u, 0x25656da51eb741dcu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x28d84c107df9f382u, 0x25656da51eb741dcu}, ::pf::meta::ID{0x37813f6e3f6f3669u, 0xb6156809fffe6167u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x56ee732d9d8d4d8cu, 0x4354387219a230e3u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x56ee732d9d8d4d8cu, 0x4354387219a230e3u}, ::pf::meta::ID{0xafd5d70a0206bff3u, 0x503b23d9d0179634u}> {};

/****************************** pf::SomeEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::SomeEnum START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum>() {
    return ::pf::meta::ID{0x37813f6e3f6f3669u, 0xb6156809fffe6167u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum>() {
    return ::pf::meta::ID{0xafd5d70a0206bff3u, 0x503b23d9d0179634u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum &>() {
    return ::pf::meta::ID{0x29915634c83fff1fu, 0x4d75c736d100947bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum &&>() {
    return ::pf::meta::ID{0xe4c587fbad8706cbu, 0x16bb701a625042a8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum &>() {
    return ::pf::meta::ID{0x28e2bddee6107836u, 0x545acdae0ff6e528u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum *>() {
    return ::pf::meta::ID{0x28d84c107df9f382u, 0x25656da51eb741dcu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum *>() {
    return ::pf::meta::ID{0x56ee732d9d8d4d8cu, 0x4354387219a230e3u};
}
/****************************** pf::SomeEnum END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value1 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value1>() {
return ::pf::meta::ID{0xf5b738a455c43efbu, 0x654b72e0f1ad99d1u};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value1 END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value2 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value2>() {
return ::pf::meta::ID{0x86bf3d082693b73u, 0x100657d5d81e328u};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value2 END ******************************/
}
/****************************** pf::Test::E::Value1 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd6337701b945dea2u, 0x156b38b5121a60edu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xd6337701b945dea2u, 0x156b38b5121a60edu};
    constexpr static ID TypeID = ::pf::meta::ID{0x168bf82ef11c5007u, 0x9889fabc3846f984u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x57ef04fcd8308ce6u, 0xb3ab112e16c0aa80u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x57ef04fcd8308ce6u, 0xb3ab112e16c0aa80u};
    constexpr static ID TypeID = ::pf::meta::ID{0x168bf82ef11c5007u, 0x9889fabc3846f984u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x168bf82ef11c5007u, 0x9889fabc3846f984u}> {
    struct details {
        
    };
    using Type = pf::Test::E;
    constexpr static ID TypeID = ::pf::meta::ID{0x168bf82ef11c5007u, 0x9889fabc3846f984u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0xd6337701b945dea2u, 0x156b38b5121a60edu}, ::pf::meta::ID{0x57ef04fcd8308ce6u, 0xb3ab112e16c0aa80u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xad5d9d77988545b8u, 0x335d9f06a77e3f8bu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xad5d9d77988545b8u, 0x335d9f06a77e3f8bu}, ::pf::meta::ID{0x168bf82ef11c5007u, 0x9889fabc3846f984u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf3a97e6eb6db9f8eu, 0x6be1d56fcf0cb5cdu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xf3a97e6eb6db9f8eu, 0x6be1d56fcf0cb5cdu}, ::pf::meta::ID{0x168bf82ef11c5007u, 0x9889fabc3846f984u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9c7f8e2bc3d1808eu, 0xa22dc4adbb3a2a13u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x9c7f8e2bc3d1808eu, 0xa22dc4adbb3a2a13u}, ::pf::meta::ID{0x168bf82ef11c5007u, 0x9889fabc3846f984u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x5ed1fc0dd8e46fbfu, 0x63088ab8da4d97a1u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x5ed1fc0dd8e46fbfu, 0x63088ab8da4d97a1u}, ::pf::meta::ID{0xad5d9d77988545b8u, 0x335d9f06a77e3f8bu}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7a9d9d6aa420cf4u, 0x7fa524a4bd143b02u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x7a9d9d6aa420cf4u, 0x7fa524a4bd143b02u}, ::pf::meta::ID{0x168bf82ef11c5007u, 0x9889fabc3846f984u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8dc060b1d10d9ff0u, 0x8a617392d77e0f42u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x8dc060b1d10d9ff0u, 0x8a617392d77e0f42u}, ::pf::meta::ID{0xad5d9d77988545b8u, 0x335d9f06a77e3f8bu}> {};

/****************************** pf::Test::E END ******************************/
namespace pf::meta::details {
/****************************** pf::Test::E START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E>() {
    return ::pf::meta::ID{0x168bf82ef11c5007u, 0x9889fabc3846f984u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E>() {
    return ::pf::meta::ID{0xad5d9d77988545b8u, 0x335d9f06a77e3f8bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E &>() {
    return ::pf::meta::ID{0xf3a97e6eb6db9f8eu, 0x6be1d56fcf0cb5cdu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E &&>() {
    return ::pf::meta::ID{0x9c7f8e2bc3d1808eu, 0xa22dc4adbb3a2a13u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E &>() {
    return ::pf::meta::ID{0x5ed1fc0dd8e46fbfu, 0x63088ab8da4d97a1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E *>() {
    return ::pf::meta::ID{0x7a9d9d6aa420cf4u, 0x7fa524a4bd143b02u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E *>() {
    return ::pf::meta::ID{0x8dc060b1d10d9ff0u, 0x8a617392d77e0f42u};
}
/****************************** pf::Test::E END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value1 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::Test::E::Value1>() {
return ::pf::meta::ID{0xd6337701b945dea2u, 0x156b38b5121a60edu};
}
/****************************** pf::Test::E::pf::Test::E::Value1 END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value2 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::Test::E::Value2>() {
return ::pf::meta::ID{0x57ef04fcd8308ce6u, 0xb3ab112e16c0aa80u};
}
/****************************** pf::Test::E::pf::Test::E::Value2 END ******************************/
}
/****************************** pf::EmptyEnum START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa5abd40d5125cec4u, 0x794a1a8380db070du}> {
    struct details {
        
    };
    using Type = pf::EmptyEnum;
    constexpr static ID TypeID = ::pf::meta::ID{0xa5abd40d5125cec4u, 0x794a1a8380db070du};

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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdc504df52b84689eu, 0x2649453fd5fceab5u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xdc504df52b84689eu, 0x2649453fd5fceab5u}, ::pf::meta::ID{0xa5abd40d5125cec4u, 0x794a1a8380db070du}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe10486b48e6a096bu, 0xf1d87f4ca3a16048u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xe10486b48e6a096bu, 0xf1d87f4ca3a16048u}, ::pf::meta::ID{0xa5abd40d5125cec4u, 0x794a1a8380db070du}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa6e35fec198f6e12u, 0x2b8f628ea338c665u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xa6e35fec198f6e12u, 0x2b8f628ea338c665u}, ::pf::meta::ID{0xa5abd40d5125cec4u, 0x794a1a8380db070du}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xad42324d72fe5aau, 0x68620eef5b6ba033u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xad42324d72fe5aau, 0x68620eef5b6ba033u}, ::pf::meta::ID{0xdc504df52b84689eu, 0x2649453fd5fceab5u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9f960ddd5d69a5efu, 0x78c2d54006f44f41u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x9f960ddd5d69a5efu, 0x78c2d54006f44f41u}, ::pf::meta::ID{0xa5abd40d5125cec4u, 0x794a1a8380db070du}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1fbe20e3fd8d81e8u, 0x25a555a9095a00ddu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x1fbe20e3fd8d81e8u, 0x25a555a9095a00ddu}, ::pf::meta::ID{0xdc504df52b84689eu, 0x2649453fd5fceab5u}> {};

/****************************** pf::EmptyEnum END ******************************/
namespace pf::meta::details {
/****************************** pf::EmptyEnum START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum>() {
    return ::pf::meta::ID{0xa5abd40d5125cec4u, 0x794a1a8380db070du};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum>() {
    return ::pf::meta::ID{0xdc504df52b84689eu, 0x2649453fd5fceab5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &>() {
    return ::pf::meta::ID{0xe10486b48e6a096bu, 0xf1d87f4ca3a16048u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &&>() {
    return ::pf::meta::ID{0xa6e35fec198f6e12u, 0x2b8f628ea338c665u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum &>() {
    return ::pf::meta::ID{0xad42324d72fe5aau, 0x68620eef5b6ba033u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum *>() {
    return ::pf::meta::ID{0x9f960ddd5d69a5efu, 0x78c2d54006f44f41u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum *>() {
    return ::pf::meta::ID{0x1fbe20e3fd8d81e8u, 0x25a555a9095a00ddu};
}
/****************************** pf::EmptyEnum END ******************************/
}
/****************************** pf::E1::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd26943671c94b7abu, 0x3207a8c440fe615fu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xd26943671c94b7abu, 0x3207a8c440fe615fu};
    constexpr static ID TypeID = ::pf::meta::ID{0x78e165b5d21a4317u, 0xb76b16ec3a085bb5u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8e88aa08afccd579u, 0x506fe7ff8327c1d8u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x8e88aa08afccd579u, 0x506fe7ff8327c1d8u};
    constexpr static ID TypeID = ::pf::meta::ID{0x78e165b5d21a4317u, 0xb76b16ec3a085bb5u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdfe80319234c9072u, 0x9a35996f1bc60966u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xdfe80319234c9072u, 0x9a35996f1bc60966u};
    constexpr static ID TypeID = ::pf::meta::ID{0x78e165b5d21a4317u, 0xb76b16ec3a085bb5u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8769a18532439346u, 0x94427492abff1a70u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x8769a18532439346u, 0x94427492abff1a70u};
    constexpr static ID TypeID = ::pf::meta::ID{0x78e165b5d21a4317u, 0xb76b16ec3a085bb5u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc0bd61e4a2efb81cu, 0xbd35fe43ca3ea689u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xc0bd61e4a2efb81cu, 0xbd35fe43ca3ea689u};
    constexpr static ID TypeID = ::pf::meta::ID{0x78e165b5d21a4317u, 0xb76b16ec3a085bb5u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x78e165b5d21a4317u, 0xb76b16ec3a085bb5u}> {
    struct details {
        
    };
    using Type = pf::E1;
    constexpr static ID TypeID = ::pf::meta::ID{0x78e165b5d21a4317u, 0xb76b16ec3a085bb5u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0xd26943671c94b7abu, 0x3207a8c440fe615fu}, ::pf::meta::ID{0x8e88aa08afccd579u, 0x506fe7ff8327c1d8u}, ::pf::meta::ID{0xdfe80319234c9072u, 0x9a35996f1bc60966u}, ::pf::meta::ID{0x8769a18532439346u, 0x94427492abff1a70u}, ::pf::meta::ID{0xc0bd61e4a2efb81cu, 0xbd35fe43ca3ea689u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb24e0280b16a4f75u, 0x59a25f550bc7c891u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xb24e0280b16a4f75u, 0x59a25f550bc7c891u}, ::pf::meta::ID{0x78e165b5d21a4317u, 0xb76b16ec3a085bb5u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc3602c2c182c8dbu, 0xa6a4a517ffcb90fcu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xc3602c2c182c8dbu, 0xa6a4a517ffcb90fcu}, ::pf::meta::ID{0x78e165b5d21a4317u, 0xb76b16ec3a085bb5u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x95db1ac57cdcd8du, 0xcb4865cc55ab75a9u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x95db1ac57cdcd8du, 0xcb4865cc55ab75a9u}, ::pf::meta::ID{0x78e165b5d21a4317u, 0xb76b16ec3a085bb5u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc00c430feaa48eddu, 0xc4a6fc15ee88d7aeu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xc00c430feaa48eddu, 0xc4a6fc15ee88d7aeu}, ::pf::meta::ID{0xb24e0280b16a4f75u, 0x59a25f550bc7c891u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe176aea9957e33bfu, 0x5fafac0be0fc0b83u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xe176aea9957e33bfu, 0x5fafac0be0fc0b83u}, ::pf::meta::ID{0x78e165b5d21a4317u, 0xb76b16ec3a085bb5u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3102b7250dfdab90u, 0x88b8bffa82849d74u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x3102b7250dfdab90u, 0x88b8bffa82849d74u}, ::pf::meta::ID{0xb24e0280b16a4f75u, 0x59a25f550bc7c891u}> {};

/****************************** pf::E1 END ******************************/
namespace pf::meta::details {
/****************************** pf::E1 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1>() {
    return ::pf::meta::ID{0x78e165b5d21a4317u, 0xb76b16ec3a085bb5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1>() {
    return ::pf::meta::ID{0xb24e0280b16a4f75u, 0x59a25f550bc7c891u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 &>() {
    return ::pf::meta::ID{0xc3602c2c182c8dbu, 0xa6a4a517ffcb90fcu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 &&>() {
    return ::pf::meta::ID{0x95db1ac57cdcd8du, 0xcb4865cc55ab75a9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1 &>() {
    return ::pf::meta::ID{0xc00c430feaa48eddu, 0xc4a6fc15ee88d7aeu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 *>() {
    return ::pf::meta::ID{0xe176aea9957e33bfu, 0x5fafac0be0fc0b83u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1 *>() {
    return ::pf::meta::ID{0x3102b7250dfdab90u, 0x88b8bffa82849d74u};
}
/****************************** pf::E1 END ******************************/

/****************************** pf::E1::pf::E1::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::A>() {
return ::pf::meta::ID{0xd26943671c94b7abu, 0x3207a8c440fe615fu};
}
/****************************** pf::E1::pf::E1::A END ******************************/

/****************************** pf::E1::pf::E1::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::B>() {
return ::pf::meta::ID{0x8e88aa08afccd579u, 0x506fe7ff8327c1d8u};
}
/****************************** pf::E1::pf::E1::B END ******************************/

/****************************** pf::E1::pf::E1::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::C>() {
return ::pf::meta::ID{0xdfe80319234c9072u, 0x9a35996f1bc60966u};
}
/****************************** pf::E1::pf::E1::C END ******************************/

/****************************** pf::E1::pf::E1::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::D>() {
return ::pf::meta::ID{0x8769a18532439346u, 0x94427492abff1a70u};
}
/****************************** pf::E1::pf::E1::D END ******************************/

/****************************** pf::E1::pf::E1::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::E>() {
return ::pf::meta::ID{0xc0bd61e4a2efb81cu, 0xbd35fe43ca3ea689u};
}
/****************************** pf::E1::pf::E1::E END ******************************/
}
/****************************** pf::E2::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc949ab4f8b760bf5u, 0x21ce84aff0f03a93u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xc949ab4f8b760bf5u, 0x21ce84aff0f03a93u};
    constexpr static ID TypeID = ::pf::meta::ID{0x6cf6e48d902a8006u, 0x31c79c9598dd961eu};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x45b45ebce9bc2591u, 0x767ca79055b5bd2u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x45b45ebce9bc2591u, 0x767ca79055b5bd2u};
    constexpr static ID TypeID = ::pf::meta::ID{0x6cf6e48d902a8006u, 0x31c79c9598dd961eu};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x73c4d47b53c296a4u, 0x5b832ccb13b539cu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x73c4d47b53c296a4u, 0x5b832ccb13b539cu};
    constexpr static ID TypeID = ::pf::meta::ID{0x6cf6e48d902a8006u, 0x31c79c9598dd961eu};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe2fb55fc7b749ccau, 0xf80a149c3215b603u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xe2fb55fc7b749ccau, 0xf80a149c3215b603u};
    constexpr static ID TypeID = ::pf::meta::ID{0x6cf6e48d902a8006u, 0x31c79c9598dd961eu};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x481acc1f9852510du, 0xda6010072ae0603cu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x481acc1f9852510du, 0xda6010072ae0603cu};
    constexpr static ID TypeID = ::pf::meta::ID{0x6cf6e48d902a8006u, 0x31c79c9598dd961eu};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6cf6e48d902a8006u, 0x31c79c9598dd961eu}> {
    struct details {
        
    };
    using Type = pf::E2;
    constexpr static ID TypeID = ::pf::meta::ID{0x6cf6e48d902a8006u, 0x31c79c9598dd961eu};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0xc949ab4f8b760bf5u, 0x21ce84aff0f03a93u}, ::pf::meta::ID{0x45b45ebce9bc2591u, 0x767ca79055b5bd2u}, ::pf::meta::ID{0x73c4d47b53c296a4u, 0x5b832ccb13b539cu}, ::pf::meta::ID{0xe2fb55fc7b749ccau, 0xf80a149c3215b603u}, ::pf::meta::ID{0x481acc1f9852510du, 0xda6010072ae0603cu});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9a8e5fed987f347bu, 0x545a7e3d3789252du}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x9a8e5fed987f347bu, 0x545a7e3d3789252du}, ::pf::meta::ID{0x6cf6e48d902a8006u, 0x31c79c9598dd961eu}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xaa44de3afee50babu, 0x7ba5f9e890d9b561u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xaa44de3afee50babu, 0x7ba5f9e890d9b561u}, ::pf::meta::ID{0x6cf6e48d902a8006u, 0x31c79c9598dd961eu}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7feec1209af0e402u, 0x160282be39e09d33u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x7feec1209af0e402u, 0x160282be39e09d33u}, ::pf::meta::ID{0x6cf6e48d902a8006u, 0x31c79c9598dd961eu}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3df25cd0cf621339u, 0x4edcac000bca4f10u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x3df25cd0cf621339u, 0x4edcac000bca4f10u}, ::pf::meta::ID{0x9a8e5fed987f347bu, 0x545a7e3d3789252du}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3fdfa6dba6155841u, 0x7542b6de5ba1c63bu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x3fdfa6dba6155841u, 0x7542b6de5ba1c63bu}, ::pf::meta::ID{0x6cf6e48d902a8006u, 0x31c79c9598dd961eu}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7d00d5f2e5eee155u, 0x366beb10c03e4bb9u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x7d00d5f2e5eee155u, 0x366beb10c03e4bb9u}, ::pf::meta::ID{0x9a8e5fed987f347bu, 0x545a7e3d3789252du}> {};

/****************************** pf::E2 END ******************************/
namespace pf::meta::details {
/****************************** pf::E2 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2>() {
    return ::pf::meta::ID{0x6cf6e48d902a8006u, 0x31c79c9598dd961eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2>() {
    return ::pf::meta::ID{0x9a8e5fed987f347bu, 0x545a7e3d3789252du};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 &>() {
    return ::pf::meta::ID{0xaa44de3afee50babu, 0x7ba5f9e890d9b561u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 &&>() {
    return ::pf::meta::ID{0x7feec1209af0e402u, 0x160282be39e09d33u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2 &>() {
    return ::pf::meta::ID{0x3df25cd0cf621339u, 0x4edcac000bca4f10u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 *>() {
    return ::pf::meta::ID{0x3fdfa6dba6155841u, 0x7542b6de5ba1c63bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2 *>() {
    return ::pf::meta::ID{0x7d00d5f2e5eee155u, 0x366beb10c03e4bb9u};
}
/****************************** pf::E2 END ******************************/

/****************************** pf::E2::pf::E2::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::A>() {
return ::pf::meta::ID{0xc949ab4f8b760bf5u, 0x21ce84aff0f03a93u};
}
/****************************** pf::E2::pf::E2::A END ******************************/

/****************************** pf::E2::pf::E2::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::B>() {
return ::pf::meta::ID{0x45b45ebce9bc2591u, 0x767ca79055b5bd2u};
}
/****************************** pf::E2::pf::E2::B END ******************************/

/****************************** pf::E2::pf::E2::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::C>() {
return ::pf::meta::ID{0x73c4d47b53c296a4u, 0x5b832ccb13b539cu};
}
/****************************** pf::E2::pf::E2::C END ******************************/

/****************************** pf::E2::pf::E2::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::D>() {
return ::pf::meta::ID{0xe2fb55fc7b749ccau, 0xf80a149c3215b603u};
}
/****************************** pf::E2::pf::E2::D END ******************************/

/****************************** pf::E2::pf::E2::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::E>() {
return ::pf::meta::ID{0x481acc1f9852510du, 0xda6010072ae0603cu};
}
/****************************** pf::E2::pf::E2::E END ******************************/
}
/****************************** pf::E3::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa6c823a84cdbf820u, 0xc7e8e5d1bc7b72b5u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xa6c823a84cdbf820u, 0xc7e8e5d1bc7b72b5u};
    constexpr static ID TypeID = ::pf::meta::ID{0xac252f3f747e7ddcu, 0x6c5b093e5be4a440u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6a4c4794594d8546u, 0xa770432f6f3978cdu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x6a4c4794594d8546u, 0xa770432f6f3978cdu};
    constexpr static ID TypeID = ::pf::meta::ID{0xac252f3f747e7ddcu, 0x6c5b093e5be4a440u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8ed6cf10603a5421u, 0xb428c4f20187cdf9u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x8ed6cf10603a5421u, 0xb428c4f20187cdf9u};
    constexpr static ID TypeID = ::pf::meta::ID{0xac252f3f747e7ddcu, 0x6c5b093e5be4a440u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb690a9762b51246fu, 0x13488e13cff8fb6au}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xb690a9762b51246fu, 0x13488e13cff8fb6au};
    constexpr static ID TypeID = ::pf::meta::ID{0xac252f3f747e7ddcu, 0x6c5b093e5be4a440u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x58b1ee0f90071af2u, 0xeace130d7298202bu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x58b1ee0f90071af2u, 0xeace130d7298202bu};
    constexpr static ID TypeID = ::pf::meta::ID{0xac252f3f747e7ddcu, 0x6c5b093e5be4a440u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xac252f3f747e7ddcu, 0x6c5b093e5be4a440u}> {
    struct details {
        
    };
    using Type = pf::E3;
    constexpr static ID TypeID = ::pf::meta::ID{0xac252f3f747e7ddcu, 0x6c5b093e5be4a440u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0xa6c823a84cdbf820u, 0xc7e8e5d1bc7b72b5u}, ::pf::meta::ID{0x6a4c4794594d8546u, 0xa770432f6f3978cdu}, ::pf::meta::ID{0x8ed6cf10603a5421u, 0xb428c4f20187cdf9u}, ::pf::meta::ID{0xb690a9762b51246fu, 0x13488e13cff8fb6au}, ::pf::meta::ID{0x58b1ee0f90071af2u, 0xeace130d7298202bu});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x27e72ea6a5bf8b6u, 0x33669c18689c1581u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x27e72ea6a5bf8b6u, 0x33669c18689c1581u}, ::pf::meta::ID{0xac252f3f747e7ddcu, 0x6c5b093e5be4a440u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa4a53f1bffb84863u, 0x4943d0e115baa868u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xa4a53f1bffb84863u, 0x4943d0e115baa868u}, ::pf::meta::ID{0xac252f3f747e7ddcu, 0x6c5b093e5be4a440u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7815bc302bdcaac2u, 0x7c94d1f46f1a1ad4u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x7815bc302bdcaac2u, 0x7c94d1f46f1a1ad4u}, ::pf::meta::ID{0xac252f3f747e7ddcu, 0x6c5b093e5be4a440u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf90422fcff775359u, 0xba1eccf30bf7f0efu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xf90422fcff775359u, 0xba1eccf30bf7f0efu}, ::pf::meta::ID{0x27e72ea6a5bf8b6u, 0x33669c18689c1581u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xab12efed5ae95b1fu, 0xd061a6dc1ed4385eu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xab12efed5ae95b1fu, 0xd061a6dc1ed4385eu}, ::pf::meta::ID{0xac252f3f747e7ddcu, 0x6c5b093e5be4a440u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1504c20fc366d5a2u, 0xc3e6fe67f153cfa6u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x1504c20fc366d5a2u, 0xc3e6fe67f153cfa6u}, ::pf::meta::ID{0x27e72ea6a5bf8b6u, 0x33669c18689c1581u}> {};

/****************************** pf::E3 END ******************************/
namespace pf::meta::details {
/****************************** pf::E3 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3>() {
    return ::pf::meta::ID{0xac252f3f747e7ddcu, 0x6c5b093e5be4a440u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3>() {
    return ::pf::meta::ID{0x27e72ea6a5bf8b6u, 0x33669c18689c1581u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 &>() {
    return ::pf::meta::ID{0xa4a53f1bffb84863u, 0x4943d0e115baa868u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 &&>() {
    return ::pf::meta::ID{0x7815bc302bdcaac2u, 0x7c94d1f46f1a1ad4u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3 &>() {
    return ::pf::meta::ID{0xf90422fcff775359u, 0xba1eccf30bf7f0efu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 *>() {
    return ::pf::meta::ID{0xab12efed5ae95b1fu, 0xd061a6dc1ed4385eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3 *>() {
    return ::pf::meta::ID{0x1504c20fc366d5a2u, 0xc3e6fe67f153cfa6u};
}
/****************************** pf::E3 END ******************************/

/****************************** pf::E3::pf::E3::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::A>() {
return ::pf::meta::ID{0xa6c823a84cdbf820u, 0xc7e8e5d1bc7b72b5u};
}
/****************************** pf::E3::pf::E3::A END ******************************/

/****************************** pf::E3::pf::E3::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::B>() {
return ::pf::meta::ID{0x6a4c4794594d8546u, 0xa770432f6f3978cdu};
}
/****************************** pf::E3::pf::E3::B END ******************************/

/****************************** pf::E3::pf::E3::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::C>() {
return ::pf::meta::ID{0x8ed6cf10603a5421u, 0xb428c4f20187cdf9u};
}
/****************************** pf::E3::pf::E3::C END ******************************/

/****************************** pf::E3::pf::E3::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::D>() {
return ::pf::meta::ID{0xb690a9762b51246fu, 0x13488e13cff8fb6au};
}
/****************************** pf::E3::pf::E3::D END ******************************/

/****************************** pf::E3::pf::E3::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::E>() {
return ::pf::meta::ID{0x58b1ee0f90071af2u, 0xeace130d7298202bu};
}
/****************************** pf::E3::pf::E3::E END ******************************/
}
/****************************** pf::E4::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x17a2d7e521dcd95bu, 0x7a5033035e9b9839u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x17a2d7e521dcd95bu, 0x7a5033035e9b9839u};
    constexpr static ID TypeID = ::pf::meta::ID{0x4c10e785462a5f4cu, 0xa55ba6eaa905900fu};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc9daee4e65e00b9fu, 0xc64314d47691c917u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xc9daee4e65e00b9fu, 0xc64314d47691c917u};
    constexpr static ID TypeID = ::pf::meta::ID{0x4c10e785462a5f4cu, 0xa55ba6eaa905900fu};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2804b549a76197a3u, 0x543287b0904fb88bu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x2804b549a76197a3u, 0x543287b0904fb88bu};
    constexpr static ID TypeID = ::pf::meta::ID{0x4c10e785462a5f4cu, 0xa55ba6eaa905900fu};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x24cbd7d2d543baf8u, 0x10d41531bcc44f34u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x24cbd7d2d543baf8u, 0x10d41531bcc44f34u};
    constexpr static ID TypeID = ::pf::meta::ID{0x4c10e785462a5f4cu, 0xa55ba6eaa905900fu};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc705cbe4f41dd3dbu, 0xf344794a5eb3365du}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xc705cbe4f41dd3dbu, 0xf344794a5eb3365du};
    constexpr static ID TypeID = ::pf::meta::ID{0x4c10e785462a5f4cu, 0xa55ba6eaa905900fu};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4c10e785462a5f4cu, 0xa55ba6eaa905900fu}> {
    struct details {
        
    };
    using Type = pf::E4;
    constexpr static ID TypeID = ::pf::meta::ID{0x4c10e785462a5f4cu, 0xa55ba6eaa905900fu};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0x17a2d7e521dcd95bu, 0x7a5033035e9b9839u}, ::pf::meta::ID{0xc9daee4e65e00b9fu, 0xc64314d47691c917u}, ::pf::meta::ID{0x2804b549a76197a3u, 0x543287b0904fb88bu}, ::pf::meta::ID{0x24cbd7d2d543baf8u, 0x10d41531bcc44f34u}, ::pf::meta::ID{0xc705cbe4f41dd3dbu, 0xf344794a5eb3365du});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xfaef3bda8789825eu, 0xd7335384ca7c1b6cu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xfaef3bda8789825eu, 0xd7335384ca7c1b6cu}, ::pf::meta::ID{0x4c10e785462a5f4cu, 0xa55ba6eaa905900fu}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x899799705fb04b8u, 0x3e68e91a2b798d2bu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x899799705fb04b8u, 0x3e68e91a2b798d2bu}, ::pf::meta::ID{0x4c10e785462a5f4cu, 0xa55ba6eaa905900fu}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7b0b47cdb2411aefu, 0x2140b9124bf2ce6du}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x7b0b47cdb2411aefu, 0x2140b9124bf2ce6du}, ::pf::meta::ID{0x4c10e785462a5f4cu, 0xa55ba6eaa905900fu}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x721b012933f4e3feu, 0x5f18b62a97a23146u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x721b012933f4e3feu, 0x5f18b62a97a23146u}, ::pf::meta::ID{0xfaef3bda8789825eu, 0xd7335384ca7c1b6cu}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x83817c4bd3d5bafdu, 0xb03d4cff914b9294u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x83817c4bd3d5bafdu, 0xb03d4cff914b9294u}, ::pf::meta::ID{0x4c10e785462a5f4cu, 0xa55ba6eaa905900fu}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x676de3fad5b55b70u, 0xb7886ae8c9dd4bddu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x676de3fad5b55b70u, 0xb7886ae8c9dd4bddu}, ::pf::meta::ID{0xfaef3bda8789825eu, 0xd7335384ca7c1b6cu}> {};

/****************************** pf::E4 END ******************************/
namespace pf::meta::details {
/****************************** pf::E4 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4>() {
    return ::pf::meta::ID{0x4c10e785462a5f4cu, 0xa55ba6eaa905900fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4>() {
    return ::pf::meta::ID{0xfaef3bda8789825eu, 0xd7335384ca7c1b6cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 &>() {
    return ::pf::meta::ID{0x899799705fb04b8u, 0x3e68e91a2b798d2bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 &&>() {
    return ::pf::meta::ID{0x7b0b47cdb2411aefu, 0x2140b9124bf2ce6du};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4 &>() {
    return ::pf::meta::ID{0x721b012933f4e3feu, 0x5f18b62a97a23146u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 *>() {
    return ::pf::meta::ID{0x83817c4bd3d5bafdu, 0xb03d4cff914b9294u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4 *>() {
    return ::pf::meta::ID{0x676de3fad5b55b70u, 0xb7886ae8c9dd4bddu};
}
/****************************** pf::E4 END ******************************/

/****************************** pf::E4::pf::E4::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::A>() {
return ::pf::meta::ID{0x17a2d7e521dcd95bu, 0x7a5033035e9b9839u};
}
/****************************** pf::E4::pf::E4::A END ******************************/

/****************************** pf::E4::pf::E4::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::B>() {
return ::pf::meta::ID{0xc9daee4e65e00b9fu, 0xc64314d47691c917u};
}
/****************************** pf::E4::pf::E4::B END ******************************/

/****************************** pf::E4::pf::E4::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::C>() {
return ::pf::meta::ID{0x2804b549a76197a3u, 0x543287b0904fb88bu};
}
/****************************** pf::E4::pf::E4::C END ******************************/

/****************************** pf::E4::pf::E4::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::D>() {
return ::pf::meta::ID{0x24cbd7d2d543baf8u, 0x10d41531bcc44f34u};
}
/****************************** pf::E4::pf::E4::D END ******************************/

/****************************** pf::E4::pf::E4::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::E>() {
return ::pf::meta::ID{0xc705cbe4f41dd3dbu, 0xf344794a5eb3365du};
}
/****************************** pf::E4::pf::E4::E END ******************************/
}
/****************************** pf::E5::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2d97ecbfda682cedu, 0xbab5a574d879dd63u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x2d97ecbfda682cedu, 0xbab5a574d879dd63u};
    constexpr static ID TypeID = ::pf::meta::ID{0x740b37fad9039de1u, 0x2871a1c13981ea48u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc80db45ecd53c001u, 0x4ce56be6eb0036a3u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xc80db45ecd53c001u, 0x4ce56be6eb0036a3u};
    constexpr static ID TypeID = ::pf::meta::ID{0x740b37fad9039de1u, 0x2871a1c13981ea48u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc5c3115fb9f4eec0u, 0x39faaa25965079f1u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xc5c3115fb9f4eec0u, 0x39faaa25965079f1u};
    constexpr static ID TypeID = ::pf::meta::ID{0x740b37fad9039de1u, 0x2871a1c13981ea48u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x34d12be70e0834eeu, 0xdac4abdc6d32f91cu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x34d12be70e0834eeu, 0xdac4abdc6d32f91cu};
    constexpr static ID TypeID = ::pf::meta::ID{0x740b37fad9039de1u, 0x2871a1c13981ea48u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x40c98daea424863au, 0x5224956f01ec225eu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x40c98daea424863au, 0x5224956f01ec225eu};
    constexpr static ID TypeID = ::pf::meta::ID{0x740b37fad9039de1u, 0x2871a1c13981ea48u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x740b37fad9039de1u, 0x2871a1c13981ea48u}> {
    struct details {
        
    };
    using Type = pf::E5;
    constexpr static ID TypeID = ::pf::meta::ID{0x740b37fad9039de1u, 0x2871a1c13981ea48u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0x2d97ecbfda682cedu, 0xbab5a574d879dd63u}, ::pf::meta::ID{0xc80db45ecd53c001u, 0x4ce56be6eb0036a3u}, ::pf::meta::ID{0xc5c3115fb9f4eec0u, 0x39faaa25965079f1u}, ::pf::meta::ID{0x34d12be70e0834eeu, 0xdac4abdc6d32f91cu}, ::pf::meta::ID{0x40c98daea424863au, 0x5224956f01ec225eu});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x52536ad33d021e8au, 0xcc3f0e23e5777e6fu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x52536ad33d021e8au, 0xcc3f0e23e5777e6fu}, ::pf::meta::ID{0x740b37fad9039de1u, 0x2871a1c13981ea48u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2d2e2234301f3cd4u, 0xe174a5be2c7e9618u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x2d2e2234301f3cd4u, 0xe174a5be2c7e9618u}, ::pf::meta::ID{0x740b37fad9039de1u, 0x2871a1c13981ea48u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xedb3ed1bd57c6787u, 0x996b2b25492ed754u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xedb3ed1bd57c6787u, 0x996b2b25492ed754u}, ::pf::meta::ID{0x740b37fad9039de1u, 0x2871a1c13981ea48u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9956dff600bbeaadu, 0x749e82c2f38ccf10u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x9956dff600bbeaadu, 0x749e82c2f38ccf10u}, ::pf::meta::ID{0x52536ad33d021e8au, 0xcc3f0e23e5777e6fu}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf713e5d9a964889u, 0x100683d9b7c4fb0eu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xf713e5d9a964889u, 0x100683d9b7c4fb0eu}, ::pf::meta::ID{0x740b37fad9039de1u, 0x2871a1c13981ea48u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x907df8459349f7fcu, 0xdf8d5a149610c04fu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x907df8459349f7fcu, 0xdf8d5a149610c04fu}, ::pf::meta::ID{0x52536ad33d021e8au, 0xcc3f0e23e5777e6fu}> {};

/****************************** pf::E5 END ******************************/
namespace pf::meta::details {
/****************************** pf::E5 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5>() {
    return ::pf::meta::ID{0x740b37fad9039de1u, 0x2871a1c13981ea48u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5>() {
    return ::pf::meta::ID{0x52536ad33d021e8au, 0xcc3f0e23e5777e6fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 &>() {
    return ::pf::meta::ID{0x2d2e2234301f3cd4u, 0xe174a5be2c7e9618u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 &&>() {
    return ::pf::meta::ID{0xedb3ed1bd57c6787u, 0x996b2b25492ed754u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5 &>() {
    return ::pf::meta::ID{0x9956dff600bbeaadu, 0x749e82c2f38ccf10u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 *>() {
    return ::pf::meta::ID{0xf713e5d9a964889u, 0x100683d9b7c4fb0eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5 *>() {
    return ::pf::meta::ID{0x907df8459349f7fcu, 0xdf8d5a149610c04fu};
}
/****************************** pf::E5 END ******************************/

/****************************** pf::E5::pf::E5::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::A>() {
return ::pf::meta::ID{0x2d97ecbfda682cedu, 0xbab5a574d879dd63u};
}
/****************************** pf::E5::pf::E5::A END ******************************/

/****************************** pf::E5::pf::E5::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::B>() {
return ::pf::meta::ID{0xc80db45ecd53c001u, 0x4ce56be6eb0036a3u};
}
/****************************** pf::E5::pf::E5::B END ******************************/

/****************************** pf::E5::pf::E5::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::C>() {
return ::pf::meta::ID{0xc5c3115fb9f4eec0u, 0x39faaa25965079f1u};
}
/****************************** pf::E5::pf::E5::C END ******************************/

/****************************** pf::E5::pf::E5::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::D>() {
return ::pf::meta::ID{0x34d12be70e0834eeu, 0xdac4abdc6d32f91cu};
}
/****************************** pf::E5::pf::E5::D END ******************************/

/****************************** pf::E5::pf::E5::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::E>() {
return ::pf::meta::ID{0x40c98daea424863au, 0x5224956f01ec225eu};
}
/****************************** pf::E5::pf::E5::E END ******************************/
}
/****************************** pf::E6::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc8a9001ae03163b8u, 0x55db1d84c1831efbu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xc8a9001ae03163b8u, 0x55db1d84c1831efbu};
    constexpr static ID TypeID = ::pf::meta::ID{0x7cae578324828de7u, 0x716b420cd33ead13u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x383780fc10dc0beu, 0x48e5d0cb88e4286cu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x383780fc10dc0beu, 0x48e5d0cb88e4286cu};
    constexpr static ID TypeID = ::pf::meta::ID{0x7cae578324828de7u, 0x716b420cd33ead13u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2fdd236c4fc28ea0u, 0x5c8d01246be38f84u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x2fdd236c4fc28ea0u, 0x5c8d01246be38f84u};
    constexpr static ID TypeID = ::pf::meta::ID{0x7cae578324828de7u, 0x716b420cd33ead13u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc0af5386f36df8e7u, 0xb17cfc1010228175u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xc0af5386f36df8e7u, 0xb17cfc1010228175u};
    constexpr static ID TypeID = ::pf::meta::ID{0x7cae578324828de7u, 0x716b420cd33ead13u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe06876f5d31829abu, 0x87bda08e86428ad3u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xe06876f5d31829abu, 0x87bda08e86428ad3u};
    constexpr static ID TypeID = ::pf::meta::ID{0x7cae578324828de7u, 0x716b420cd33ead13u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7cae578324828de7u, 0x716b420cd33ead13u}> {
    struct details {
        
    };
    using Type = pf::E6;
    constexpr static ID TypeID = ::pf::meta::ID{0x7cae578324828de7u, 0x716b420cd33ead13u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0xc8a9001ae03163b8u, 0x55db1d84c1831efbu}, ::pf::meta::ID{0x383780fc10dc0beu, 0x48e5d0cb88e4286cu}, ::pf::meta::ID{0x2fdd236c4fc28ea0u, 0x5c8d01246be38f84u}, ::pf::meta::ID{0xc0af5386f36df8e7u, 0xb17cfc1010228175u}, ::pf::meta::ID{0xe06876f5d31829abu, 0x87bda08e86428ad3u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb9343f3de4a86465u, 0xaf5f043028a16d59u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xb9343f3de4a86465u, 0xaf5f043028a16d59u}, ::pf::meta::ID{0x7cae578324828de7u, 0x716b420cd33ead13u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8562907a0e56b08cu, 0x9db28f67a8da39d6u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x8562907a0e56b08cu, 0x9db28f67a8da39d6u}, ::pf::meta::ID{0x7cae578324828de7u, 0x716b420cd33ead13u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x16083bb4b9c47f74u, 0xec117749ec6b73a4u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x16083bb4b9c47f74u, 0xec117749ec6b73a4u}, ::pf::meta::ID{0x7cae578324828de7u, 0x716b420cd33ead13u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x293016d2c809f235u, 0xecf1bc2deb0925c6u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x293016d2c809f235u, 0xecf1bc2deb0925c6u}, ::pf::meta::ID{0xb9343f3de4a86465u, 0xaf5f043028a16d59u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xca0862d650f8733bu, 0x72bb2ca6fb1ae6e7u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xca0862d650f8733bu, 0x72bb2ca6fb1ae6e7u}, ::pf::meta::ID{0x7cae578324828de7u, 0x716b420cd33ead13u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1c3ae76a4625cb62u, 0xf646706538f28b0bu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x1c3ae76a4625cb62u, 0xf646706538f28b0bu}, ::pf::meta::ID{0xb9343f3de4a86465u, 0xaf5f043028a16d59u}> {};

/****************************** pf::E6 END ******************************/
namespace pf::meta::details {
/****************************** pf::E6 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6>() {
    return ::pf::meta::ID{0x7cae578324828de7u, 0x716b420cd33ead13u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6>() {
    return ::pf::meta::ID{0xb9343f3de4a86465u, 0xaf5f043028a16d59u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 &>() {
    return ::pf::meta::ID{0x8562907a0e56b08cu, 0x9db28f67a8da39d6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 &&>() {
    return ::pf::meta::ID{0x16083bb4b9c47f74u, 0xec117749ec6b73a4u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6 &>() {
    return ::pf::meta::ID{0x293016d2c809f235u, 0xecf1bc2deb0925c6u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 *>() {
    return ::pf::meta::ID{0xca0862d650f8733bu, 0x72bb2ca6fb1ae6e7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6 *>() {
    return ::pf::meta::ID{0x1c3ae76a4625cb62u, 0xf646706538f28b0bu};
}
/****************************** pf::E6 END ******************************/

/****************************** pf::E6::pf::E6::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::A>() {
return ::pf::meta::ID{0xc8a9001ae03163b8u, 0x55db1d84c1831efbu};
}
/****************************** pf::E6::pf::E6::A END ******************************/

/****************************** pf::E6::pf::E6::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::B>() {
return ::pf::meta::ID{0x383780fc10dc0beu, 0x48e5d0cb88e4286cu};
}
/****************************** pf::E6::pf::E6::B END ******************************/

/****************************** pf::E6::pf::E6::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::C>() {
return ::pf::meta::ID{0x2fdd236c4fc28ea0u, 0x5c8d01246be38f84u};
}
/****************************** pf::E6::pf::E6::C END ******************************/

/****************************** pf::E6::pf::E6::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::D>() {
return ::pf::meta::ID{0xc0af5386f36df8e7u, 0xb17cfc1010228175u};
}
/****************************** pf::E6::pf::E6::D END ******************************/

/****************************** pf::E6::pf::E6::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::E>() {
return ::pf::meta::ID{0xe06876f5d31829abu, 0x87bda08e86428ad3u};
}
/****************************** pf::E6::pf::E6::E END ******************************/
}
/****************************** pf::E7::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd595e00eac703773u, 0xe889cb8e03922b28u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xd595e00eac703773u, 0xe889cb8e03922b28u};
    constexpr static ID TypeID = ::pf::meta::ID{0xcfb254e979c28088u, 0x6e0816a82bdbcf3du};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x340bee76b4234d65u, 0x2c16d07cc156ba6fu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x340bee76b4234d65u, 0x2c16d07cc156ba6fu};
    constexpr static ID TypeID = ::pf::meta::ID{0xcfb254e979c28088u, 0x6e0816a82bdbcf3du};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xce6d0fccea98b335u, 0x3a79b6992f56777au}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xce6d0fccea98b335u, 0x3a79b6992f56777au};
    constexpr static ID TypeID = ::pf::meta::ID{0xcfb254e979c28088u, 0x6e0816a82bdbcf3du};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xbbef9c0b77affb49u, 0xbcdb7a802ae44d80u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xbbef9c0b77affb49u, 0xbcdb7a802ae44d80u};
    constexpr static ID TypeID = ::pf::meta::ID{0xcfb254e979c28088u, 0x6e0816a82bdbcf3du};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xeb589aa5cc32f30u, 0x4d404bf05c45a385u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xeb589aa5cc32f30u, 0x4d404bf05c45a385u};
    constexpr static ID TypeID = ::pf::meta::ID{0xcfb254e979c28088u, 0x6e0816a82bdbcf3du};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xcfb254e979c28088u, 0x6e0816a82bdbcf3du}> {
    struct details {
        
    };
    using Type = pf::E7;
    constexpr static ID TypeID = ::pf::meta::ID{0xcfb254e979c28088u, 0x6e0816a82bdbcf3du};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0xd595e00eac703773u, 0xe889cb8e03922b28u}, ::pf::meta::ID{0x340bee76b4234d65u, 0x2c16d07cc156ba6fu}, ::pf::meta::ID{0xce6d0fccea98b335u, 0x3a79b6992f56777au}, ::pf::meta::ID{0xbbef9c0b77affb49u, 0xbcdb7a802ae44d80u}, ::pf::meta::ID{0xeb589aa5cc32f30u, 0x4d404bf05c45a385u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc7eb2666efe4356u, 0xa4b86cabe43df68fu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xc7eb2666efe4356u, 0xa4b86cabe43df68fu}, ::pf::meta::ID{0xcfb254e979c28088u, 0x6e0816a82bdbcf3du}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb41d086b08c98dabu, 0x959566bdd4b07238u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xb41d086b08c98dabu, 0x959566bdd4b07238u}, ::pf::meta::ID{0xcfb254e979c28088u, 0x6e0816a82bdbcf3du}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc82f0920e386eff9u, 0x7fdc8e223fb6d14bu}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xc82f0920e386eff9u, 0x7fdc8e223fb6d14bu}, ::pf::meta::ID{0xcfb254e979c28088u, 0x6e0816a82bdbcf3du}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x80d9a701a2d4f1eu, 0x5e22dab26bcbd2c4u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x80d9a701a2d4f1eu, 0x5e22dab26bcbd2c4u}, ::pf::meta::ID{0xc7eb2666efe4356u, 0xa4b86cabe43df68fu}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xba5de894d94f61ddu, 0x68627bde2ef93333u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xba5de894d94f61ddu, 0x68627bde2ef93333u}, ::pf::meta::ID{0xcfb254e979c28088u, 0x6e0816a82bdbcf3du}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x508d20f0196d1125u, 0x958d8db83e18fffeu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x508d20f0196d1125u, 0x958d8db83e18fffeu}, ::pf::meta::ID{0xc7eb2666efe4356u, 0xa4b86cabe43df68fu}> {};

/****************************** pf::E7 END ******************************/
namespace pf::meta::details {
/****************************** pf::E7 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7>() {
    return ::pf::meta::ID{0xcfb254e979c28088u, 0x6e0816a82bdbcf3du};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7>() {
    return ::pf::meta::ID{0xc7eb2666efe4356u, 0xa4b86cabe43df68fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 &>() {
    return ::pf::meta::ID{0xb41d086b08c98dabu, 0x959566bdd4b07238u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 &&>() {
    return ::pf::meta::ID{0xc82f0920e386eff9u, 0x7fdc8e223fb6d14bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7 &>() {
    return ::pf::meta::ID{0x80d9a701a2d4f1eu, 0x5e22dab26bcbd2c4u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 *>() {
    return ::pf::meta::ID{0xba5de894d94f61ddu, 0x68627bde2ef93333u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7 *>() {
    return ::pf::meta::ID{0x508d20f0196d1125u, 0x958d8db83e18fffeu};
}
/****************************** pf::E7 END ******************************/

/****************************** pf::E7::pf::E7::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::A>() {
return ::pf::meta::ID{0xd595e00eac703773u, 0xe889cb8e03922b28u};
}
/****************************** pf::E7::pf::E7::A END ******************************/

/****************************** pf::E7::pf::E7::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::B>() {
return ::pf::meta::ID{0x340bee76b4234d65u, 0x2c16d07cc156ba6fu};
}
/****************************** pf::E7::pf::E7::B END ******************************/

/****************************** pf::E7::pf::E7::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::C>() {
return ::pf::meta::ID{0xce6d0fccea98b335u, 0x3a79b6992f56777au};
}
/****************************** pf::E7::pf::E7::C END ******************************/

/****************************** pf::E7::pf::E7::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::D>() {
return ::pf::meta::ID{0xbbef9c0b77affb49u, 0xbcdb7a802ae44d80u};
}
/****************************** pf::E7::pf::E7::D END ******************************/

/****************************** pf::E7::pf::E7::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::E>() {
return ::pf::meta::ID{0xeb589aa5cc32f30u, 0x4d404bf05c45a385u};
}
/****************************** pf::E7::pf::E7::E END ******************************/
}
/****************************** pf::E8::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xee2d82a9035e7aedu, 0xe1f0964453cba69eu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xee2d82a9035e7aedu, 0xe1f0964453cba69eu};
    constexpr static ID TypeID = ::pf::meta::ID{0xe1169939f4e20392u, 0xded988f7d44858deu};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf0660b1726b19420u, 0x77c503896b390c23u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xf0660b1726b19420u, 0x77c503896b390c23u};
    constexpr static ID TypeID = ::pf::meta::ID{0xe1169939f4e20392u, 0xded988f7d44858deu};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7ef64119a3ae2059u, 0x42eebf13fa79d100u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x7ef64119a3ae2059u, 0x42eebf13fa79d100u};
    constexpr static ID TypeID = ::pf::meta::ID{0xe1169939f4e20392u, 0xded988f7d44858deu};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x716ba4eb14d002dfu, 0x9294f4b1b1876a6eu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x716ba4eb14d002dfu, 0x9294f4b1b1876a6eu};
    constexpr static ID TypeID = ::pf::meta::ID{0xe1169939f4e20392u, 0xded988f7d44858deu};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x89aa93ef58e9ae87u, 0x4f6041cd82b7466eu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x89aa93ef58e9ae87u, 0x4f6041cd82b7466eu};
    constexpr static ID TypeID = ::pf::meta::ID{0xe1169939f4e20392u, 0xded988f7d44858deu};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe1169939f4e20392u, 0xded988f7d44858deu}> {
    struct details {
        
    };
    using Type = pf::E8;
    constexpr static ID TypeID = ::pf::meta::ID{0xe1169939f4e20392u, 0xded988f7d44858deu};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0xee2d82a9035e7aedu, 0xe1f0964453cba69eu}, ::pf::meta::ID{0xf0660b1726b19420u, 0x77c503896b390c23u}, ::pf::meta::ID{0x7ef64119a3ae2059u, 0x42eebf13fa79d100u}, ::pf::meta::ID{0x716ba4eb14d002dfu, 0x9294f4b1b1876a6eu}, ::pf::meta::ID{0x89aa93ef58e9ae87u, 0x4f6041cd82b7466eu});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd375c88e0432beb5u, 0xac5e3fdc52dc6e57u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xd375c88e0432beb5u, 0xac5e3fdc52dc6e57u}, ::pf::meta::ID{0xe1169939f4e20392u, 0xded988f7d44858deu}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9eaf5cb3912bf68u, 0x70d19c432782fb5u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x9eaf5cb3912bf68u, 0x70d19c432782fb5u}, ::pf::meta::ID{0xe1169939f4e20392u, 0xded988f7d44858deu}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd2c0a98a27315fdau, 0x5a0cc351eb1b622bu}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xd2c0a98a27315fdau, 0x5a0cc351eb1b622bu}, ::pf::meta::ID{0xe1169939f4e20392u, 0xded988f7d44858deu}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x15e7a670f6b3449fu, 0xc73b0833b2d19fe8u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x15e7a670f6b3449fu, 0xc73b0833b2d19fe8u}, ::pf::meta::ID{0xd375c88e0432beb5u, 0xac5e3fdc52dc6e57u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x214b09ea8781cfd4u, 0x40b2541bb33cf636u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x214b09ea8781cfd4u, 0x40b2541bb33cf636u}, ::pf::meta::ID{0xe1169939f4e20392u, 0xded988f7d44858deu}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x51274fa04d794c00u, 0x99eb92aa2edc9527u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x51274fa04d794c00u, 0x99eb92aa2edc9527u}, ::pf::meta::ID{0xd375c88e0432beb5u, 0xac5e3fdc52dc6e57u}> {};

/****************************** pf::E8 END ******************************/
namespace pf::meta::details {
/****************************** pf::E8 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8>() {
    return ::pf::meta::ID{0xe1169939f4e20392u, 0xded988f7d44858deu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8>() {
    return ::pf::meta::ID{0xd375c88e0432beb5u, 0xac5e3fdc52dc6e57u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 &>() {
    return ::pf::meta::ID{0x9eaf5cb3912bf68u, 0x70d19c432782fb5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 &&>() {
    return ::pf::meta::ID{0xd2c0a98a27315fdau, 0x5a0cc351eb1b622bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8 &>() {
    return ::pf::meta::ID{0x15e7a670f6b3449fu, 0xc73b0833b2d19fe8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 *>() {
    return ::pf::meta::ID{0x214b09ea8781cfd4u, 0x40b2541bb33cf636u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8 *>() {
    return ::pf::meta::ID{0x51274fa04d794c00u, 0x99eb92aa2edc9527u};
}
/****************************** pf::E8 END ******************************/

/****************************** pf::E8::pf::E8::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::A>() {
return ::pf::meta::ID{0xee2d82a9035e7aedu, 0xe1f0964453cba69eu};
}
/****************************** pf::E8::pf::E8::A END ******************************/

/****************************** pf::E8::pf::E8::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::B>() {
return ::pf::meta::ID{0xf0660b1726b19420u, 0x77c503896b390c23u};
}
/****************************** pf::E8::pf::E8::B END ******************************/

/****************************** pf::E8::pf::E8::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::C>() {
return ::pf::meta::ID{0x7ef64119a3ae2059u, 0x42eebf13fa79d100u};
}
/****************************** pf::E8::pf::E8::C END ******************************/

/****************************** pf::E8::pf::E8::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::D>() {
return ::pf::meta::ID{0x716ba4eb14d002dfu, 0x9294f4b1b1876a6eu};
}
/****************************** pf::E8::pf::E8::D END ******************************/

/****************************** pf::E8::pf::E8::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::E>() {
return ::pf::meta::ID{0x89aa93ef58e9ae87u, 0x4f6041cd82b7466eu};
}
/****************************** pf::E8::pf::E8::E END ******************************/
}
/****************************** pf::E9::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3cadea7ecfcf8630u, 0x2196f8b175285178u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x3cadea7ecfcf8630u, 0x2196f8b175285178u};
    constexpr static ID TypeID = ::pf::meta::ID{0x60eed27ae6f227c0u, 0x38e4af946c318f49u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa65fa7b02a093737u, 0x9efcdf48245a7636u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0xa65fa7b02a093737u, 0x9efcdf48245a7636u};
    constexpr static ID TypeID = ::pf::meta::ID{0x60eed27ae6f227c0u, 0x38e4af946c318f49u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8de3064d55855a27u, 0x106cc0db0054d44cu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x8de3064d55855a27u, 0x106cc0db0054d44cu};
    constexpr static ID TypeID = ::pf::meta::ID{0x60eed27ae6f227c0u, 0x38e4af946c318f49u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7ecd21bb01645f9u, 0x5253b6e4a5ab4421u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x7ecd21bb01645f9u, 0x5253b6e4a5ab4421u};
    constexpr static ID TypeID = ::pf::meta::ID{0x60eed27ae6f227c0u, 0x38e4af946c318f49u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1de80053997e578bu, 0x12b156c373828634u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ::pf::meta::ID{0x1de80053997e578bu, 0x12b156c373828634u};
    constexpr static ID TypeID = ::pf::meta::ID{0x60eed27ae6f227c0u, 0x38e4af946c318f49u};
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
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x60eed27ae6f227c0u, 0x38e4af946c318f49u}> {
    struct details {
        
    };
    using Type = pf::E9;
    constexpr static ID TypeID = ::pf::meta::ID{0x60eed27ae6f227c0u, 0x38e4af946c318f49u};

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
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(::pf::meta::ID{0x3cadea7ecfcf8630u, 0x2196f8b175285178u}, ::pf::meta::ID{0xa65fa7b02a093737u, 0x9efcdf48245a7636u}, ::pf::meta::ID{0x8de3064d55855a27u, 0x106cc0db0054d44cu}, ::pf::meta::ID{0x7ecd21bb01645f9u, 0x5253b6e4a5ab4421u}, ::pf::meta::ID{0x1de80053997e578bu, 0x12b156c373828634u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb6770ca7e00897ebu, 0xf8cf579737b70a06u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xb6770ca7e00897ebu, 0xf8cf579737b70a06u}, ::pf::meta::ID{0x60eed27ae6f227c0u, 0x38e4af946c318f49u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x64e036be899faa5eu, 0xa1facaf03e27c2acu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x64e036be899faa5eu, 0xa1facaf03e27c2acu}, ::pf::meta::ID{0x60eed27ae6f227c0u, 0x38e4af946c318f49u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3812ae2631004722u, 0xd76ef46789686d3du}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x3812ae2631004722u, 0xd76ef46789686d3du}, ::pf::meta::ID{0x60eed27ae6f227c0u, 0x38e4af946c318f49u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6fe8665c6c7869fau, 0x98d13bf505fa2923u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x6fe8665c6c7869fau, 0x98d13bf505fa2923u}, ::pf::meta::ID{0xb6770ca7e00897ebu, 0xf8cf579737b70a06u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf432db60fcdfb834u, 0xbcc286697bf3abadu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xf432db60fcdfb834u, 0xbcc286697bf3abadu}, ::pf::meta::ID{0x60eed27ae6f227c0u, 0x38e4af946c318f49u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x86924857cf7aa615u, 0xd3e661e140f79afu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x86924857cf7aa615u, 0xd3e661e140f79afu}, ::pf::meta::ID{0xb6770ca7e00897ebu, 0xf8cf579737b70a06u}> {};

/****************************** pf::E9 END ******************************/
namespace pf::meta::details {
/****************************** pf::E9 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9>() {
    return ::pf::meta::ID{0x60eed27ae6f227c0u, 0x38e4af946c318f49u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9>() {
    return ::pf::meta::ID{0xb6770ca7e00897ebu, 0xf8cf579737b70a06u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 &>() {
    return ::pf::meta::ID{0x64e036be899faa5eu, 0xa1facaf03e27c2acu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 &&>() {
    return ::pf::meta::ID{0x3812ae2631004722u, 0xd76ef46789686d3du};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9 &>() {
    return ::pf::meta::ID{0x6fe8665c6c7869fau, 0x98d13bf505fa2923u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 *>() {
    return ::pf::meta::ID{0xf432db60fcdfb834u, 0xbcc286697bf3abadu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9 *>() {
    return ::pf::meta::ID{0x86924857cf7aa615u, 0xd3e661e140f79afu};
}
/****************************** pf::E9 END ******************************/

/****************************** pf::E9::pf::E9::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::A>() {
return ::pf::meta::ID{0x3cadea7ecfcf8630u, 0x2196f8b175285178u};
}
/****************************** pf::E9::pf::E9::A END ******************************/

/****************************** pf::E9::pf::E9::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::B>() {
return ::pf::meta::ID{0xa65fa7b02a093737u, 0x9efcdf48245a7636u};
}
/****************************** pf::E9::pf::E9::B END ******************************/

/****************************** pf::E9::pf::E9::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::C>() {
return ::pf::meta::ID{0x8de3064d55855a27u, 0x106cc0db0054d44cu};
}
/****************************** pf::E9::pf::E9::C END ******************************/

/****************************** pf::E9::pf::E9::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::D>() {
return ::pf::meta::ID{0x7ecd21bb01645f9u, 0x5253b6e4a5ab4421u};
}
/****************************** pf::E9::pf::E9::D END ******************************/

/****************************** pf::E9::pf::E9::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::E>() {
return ::pf::meta::ID{0x1de80053997e578bu, 0x12b156c373828634u};
}
/****************************** pf::E9::pf::E9::E END ******************************/
}

