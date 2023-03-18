
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

namespace pf::meta::details {

/****************************** pf::SomeEnum::Value1 START ******************************/
template<>
struct StaticInfo<ID{0xc0597f7732016649u, 0xed19a615bd3023bau}> {
    struct details {
        constexpr static auto ArgArray_4371875128473051321 = make_array<std::string_view>();
constexpr static auto ArgArray_4491124210048082010 = make_array<std::string_view>();
constexpr static auto ArgArray_15097458155946262550 = make_array<std::string_view>();

    };
    constexpr static ID ValueID = ID{0xc0597f7732016649u, 0xed19a615bd3023bau};
    constexpr static ID TypeID = ID{0xc0597f7732016649u, 0xed19a615bd3023bau};
    using Type = pf::SomeEnum;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 6;
    constexpr static std::uint64_t SourceColumn = 92;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>(Attribute{"pf::test", std::span<const std::string_view>{details::ArgArray_4371875128473051321}}, Attribute{"pf::test2", std::span<const std::string_view>{details::ArgArray_4491124210048082010}}, Attribute{"pf::test3", std::span<const std::string_view>{details::ArgArray_15097458155946262550}});

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"Value1"};
    constexpr static auto FullName = StringLiteral{"pf::SomeEnum::Value1"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::SomeEnum Value = pf::SomeEnum::Value1;
};
/****************************** pf::SomeEnum::Value1 END ******************************/

/****************************** pf::SomeEnum::Value2 START ******************************/
template<>
struct StaticInfo<ID{0x445d2037590be14au, 0xd949752de2aa1786u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x445d2037590be14au, 0xd949752de2aa1786u};
    constexpr static ID TypeID = ID{0x445d2037590be14au, 0xd949752de2aa1786u};
    using Type = pf::SomeEnum;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 6;
    constexpr static std::uint64_t SourceColumn = 138;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"Value2"};
    constexpr static auto FullName = StringLiteral{"pf::SomeEnum::Value2"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::SomeEnum Value = pf::SomeEnum::Value2;
};
/****************************** pf::SomeEnum::Value2 END ******************************/

/****************************** pf::SomeEnum START ******************************/
template<>
struct StaticInfo<ID{0x2b53af1c1cf57f8au, 0xe97917064d8b3696u}> {
    struct details {
        constexpr static auto ArgArray_9675262143886934025 = make_array<std::string_view>(R"arg(()()()((())))arg", R"arg([[nodiscard]])arg", R"arg(1ll)arg", R"arg(1.011)arg", R"arg([]{}())arg", R"arg("yeet")arg", R"arg('a')arg", R"arg([][][]:::3214234...[][][][])arg");
constexpr static auto ArgArray_7373583208148062503 = make_array<std::string_view>();
constexpr static auto ArgArray_14879294174180100374 = make_array<std::string_view>(R"arg(1ll)arg", R"arg(1.011)arg", R"arg("yeet")arg");
constexpr static auto ArgArray_15702518898743246785 = make_array<std::string_view>();

    };
    using Type = pf::SomeEnum;
    constexpr static ID TypeID = ID{0x2b53af1c1cf57f8au, 0xe97917064d8b3696u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>(Attribute{"pf::operators", std::span<const std::string_view>{details::ArgArray_9675262143886934025}}, Attribute{"pf::hihi", std::span<const std::string_view>{details::ArgArray_7373583208148062503}}, Attribute{"pf::operators2", std::span<const std::string_view>{details::ArgArray_14879294174180100374}}, Attribute{"pf::hihi2", std::span<const std::string_view>{details::ArgArray_15702518898743246785}});

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"SomeEnum"};
    constexpr static auto FullName = StringLiteral{"pf::SomeEnum"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<Info> auto EnumValues = make_array<Info>(ID{0xc0597f7732016649u, 0xed19a615bd3023bau}, ID{0x445d2037590be14au, 0xd949752de2aa1786u});
};

// const
template<>
struct StaticInfo<ID{0xd758cfe3010d305cu, 0x75e0fa159fe801a3u}>
    : StaticInfo_ConstWrap<ID{0xd758cfe3010d305cu, 0x75e0fa159fe801a3u}, ID{0x2b53af1c1cf57f8au, 0xe97917064d8b3696u}> {};
// &
template<>
struct StaticInfo<ID{0xf85570c403801102u, 0xbe855f5bedc2039cu}>
    : StaticInfo_LRefWrap<ID{0xf85570c403801102u, 0xbe855f5bedc2039cu}, ID{0x2b53af1c1cf57f8au, 0xe97917064d8b3696u}> {};
// &&
template<>
struct StaticInfo<ID{0xcc552cc1c3b15455u, 0x87dd60be50b83d90u}>
    : StaticInfo_RRefWrap<ID{0xcc552cc1c3b15455u, 0x87dd60be50b83d90u}, ID{0x2b53af1c1cf57f8au, 0xe97917064d8b3696u}> {};
// const &
template<>
struct StaticInfo<ID{0x805563dfab2a0258u, 0x4d0f473bf7bb31a3u}>
    : StaticInfo_ConstLRefWrap<ID{0x805563dfab2a0258u, 0x4d0f473bf7bb31a3u}, ID{0x2b53af1c1cf57f8au, 0xe97917064d8b3696u}> {};
// *
template<>
struct StaticInfo<ID{0xce5b68659bbf2b7fu, 0xe2d2311a2a351592u}>
    : StaticInfo_PtrWrap<ID{0xce5b68659bbf2b7fu, 0xe2d2311a2a351592u}, ID{0x2b53af1c1cf57f8au, 0xe97917064d8b3696u}> {};
// const *
template<>
struct StaticInfo<ID{0x73525563b8d6fe62u, 0xf3c1f4889958b6beu}>
    : StaticInfo_ConstPtrWrap<ID{0x73525563b8d6fe62u, 0xf3c1f4889958b6beu}, ID{0x2b53af1c1cf57f8au, 0xe97917064d8b3696u}> {};

/****************************** pf::SomeEnum END ******************************/

/****************************** pf::SomeEnum START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum>() {
    return ID{0x2b53af1c1cf57f8au, 0xe97917064d8b3696u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum>() {
    return ID{0xd758cfe3010d305cu, 0x75e0fa159fe801a3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum &>() {
    return ID{0xf85570c403801102u, 0xbe855f5bedc2039cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum &&>() {
    return ID{0xcc552cc1c3b15455u, 0x87dd60be50b83d90u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum &>() {
    return ID{0x805563dfab2a0258u, 0x4d0f473bf7bb31a3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::SomeEnum *>() {
    return ID{0xce5b68659bbf2b7fu, 0xe2d2311a2a351592u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::SomeEnum *>() {
    return ID{0x73525563b8d6fe62u, 0xf3c1f4889958b6beu};
}
/****************************** pf::SomeEnum END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value1 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value1>() {
return ID{0xc0597f7732016649u, 0xed19a615bd3023bau};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value1 END ******************************/

/****************************** pf::SomeEnum::pf::SomeEnum::Value2 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value2>() {
return ID{0x445d2037590be14au, 0xd949752de2aa1786u};
}
/****************************** pf::SomeEnum::pf::SomeEnum::Value2 END ******************************/

/****************************** pf::Test::E::Value1 START ******************************/
template<>
struct StaticInfo<ID{0xf95af1e2a6c2c3d2u, 0xe4dc739d8155b99au}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xf95af1e2a6c2c3d2u, 0xe4dc739d8155b99au};
    constexpr static ID TypeID = ID{0xf95af1e2a6c2c3d2u, 0xe4dc739d8155b99au};
    using Type = pf::Test::E;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 8;
    constexpr static std::uint64_t SourceColumn = 30;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"Value1"};
    constexpr static auto FullName = StringLiteral{"pf::Test::E::Value1"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::Test::E Value = pf::Test::E::Value1;
};
/****************************** pf::Test::E::Value1 END ******************************/

/****************************** pf::Test::E::Value2 START ******************************/
template<>
struct StaticInfo<ID{0x4c5823d476eb71d7u, 0x934d6de97e7b44b3u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x4c5823d476eb71d7u, 0x934d6de97e7b44b3u};
    constexpr static ID TypeID = ID{0x4c5823d476eb71d7u, 0x934d6de97e7b44b3u};
    using Type = pf::Test::E;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 8;
    constexpr static std::uint64_t SourceColumn = 38;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"Value2"};
    constexpr static auto FullName = StringLiteral{"pf::Test::E::Value2"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::Test::E Value = pf::Test::E::Value2;
};
/****************************** pf::Test::E::Value2 END ******************************/

/****************************** pf::Test::E START ******************************/
template<>
struct StaticInfo<ID{0xb35c649feb784432u, 0xa4d5a0126de63c87u}> {
    struct details {
        
    };
    using Type = pf::Test::E;
    constexpr static ID TypeID = ID{0xb35c649feb784432u, 0xa4d5a0126de63c87u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 8;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::Test::E"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<Info> auto EnumValues = make_array<Info>(ID{0xf95af1e2a6c2c3d2u, 0xe4dc739d8155b99au}, ID{0x4c5823d476eb71d7u, 0x934d6de97e7b44b3u});
};

// const
template<>
struct StaticInfo<ID{0x50554d39c2a37dd1u, 0x6684282c53771b0u}>
    : StaticInfo_ConstWrap<ID{0x50554d39c2a37dd1u, 0x6684282c53771b0u}, ID{0xb35c649feb784432u, 0xa4d5a0126de63c87u}> {};
// &
template<>
struct StaticInfo<ID{0x19500b73a7b16d63u, 0x8f6578c110140b95u}>
    : StaticInfo_LRefWrap<ID{0x19500b73a7b16d63u, 0x8f6578c110140b95u}, ID{0xb35c649feb784432u, 0xa4d5a0126de63c87u}> {};
// &&
template<>
struct StaticInfo<ID{0xc253911d6d879fbeu, 0xe219fa8d512d9ea3u}>
    : StaticInfo_RRefWrap<ID{0xc253911d6d879fbeu, 0xe219fa8d512d9ea3u}, ID{0xb35c649feb784432u, 0xa4d5a0126de63c87u}> {};
// const &
template<>
struct StaticInfo<ID{0x465c7cf5a8df701bu, 0xe7bde4e395c32e89u}>
    : StaticInfo_ConstLRefWrap<ID{0x465c7cf5a8df701bu, 0xe7bde4e395c32e89u}, ID{0xb35c649feb784432u, 0xa4d5a0126de63c87u}> {};
// *
template<>
struct StaticInfo<ID{0xbe58448fbac65e65u, 0xeed38b0a42b96bbau}>
    : StaticInfo_PtrWrap<ID{0xbe58448fbac65e65u, 0xeed38b0a42b96bbau}, ID{0xb35c649feb784432u, 0xa4d5a0126de63c87u}> {};
// const *
template<>
struct StaticInfo<ID{0xc05fcc8062828513u, 0x856b7d9cd14eb096u}>
    : StaticInfo_ConstPtrWrap<ID{0xc05fcc8062828513u, 0x856b7d9cd14eb096u}, ID{0xb35c649feb784432u, 0xa4d5a0126de63c87u}> {};

/****************************** pf::Test::E END ******************************/

/****************************** pf::Test::E START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E>() {
    return ID{0xb35c649feb784432u, 0xa4d5a0126de63c87u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E>() {
    return ID{0x50554d39c2a37dd1u, 0x6684282c53771b0u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E &>() {
    return ID{0x19500b73a7b16d63u, 0x8f6578c110140b95u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E &&>() {
    return ID{0xc253911d6d879fbeu, 0xe219fa8d512d9ea3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E &>() {
    return ID{0x465c7cf5a8df701bu, 0xe7bde4e395c32e89u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::Test::E *>() {
    return ID{0xbe58448fbac65e65u, 0xeed38b0a42b96bbau};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::Test::E *>() {
    return ID{0xc05fcc8062828513u, 0x856b7d9cd14eb096u};
}
/****************************** pf::Test::E END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value1 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::Test::E::Value1>() {
return ID{0xf95af1e2a6c2c3d2u, 0xe4dc739d8155b99au};
}
/****************************** pf::Test::E::pf::Test::E::Value1 END ******************************/

/****************************** pf::Test::E::pf::Test::E::Value2 START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::Test::E::Value2>() {
return ID{0x4c5823d476eb71d7u, 0x934d6de97e7b44b3u};
}
/****************************** pf::Test::E::pf::Test::E::Value2 END ******************************/

/****************************** pf::EmptyEnum START ******************************/
template<>
struct StaticInfo<ID{0xbc515bce03872d28u, 0x7300b5983a3fffbfu}> {
    struct details {
        
    };
    using Type = pf::EmptyEnum;
    constexpr static ID TypeID = ID{0xbc515bce03872d28u, 0x7300b5983a3fffbfu};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 19;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"EmptyEnum"};
    constexpr static auto FullName = StringLiteral{"pf::EmptyEnum"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<Info> auto EnumValues = make_array<Info>();
};

// const
template<>
struct StaticInfo<ID{0xdb50ac114169223bu, 0xc38336650f7df787u}>
    : StaticInfo_ConstWrap<ID{0xdb50ac114169223bu, 0xc38336650f7df787u}, ID{0xbc515bce03872d28u, 0x7300b5983a3fffbfu}> {};
// &
template<>
struct StaticInfo<ID{0xfa5b248f62dfcc39u, 0xc0f0749f111ce3a1u}>
    : StaticInfo_LRefWrap<ID{0xfa5b248f62dfcc39u, 0xc0f0749f111ce3a1u}, ID{0xbc515bce03872d28u, 0x7300b5983a3fffbfu}> {};
// &&
template<>
struct StaticInfo<ID{0x2d5fc20029e9634cu, 0xc39c3daf3820ca8fu}>
    : StaticInfo_RRefWrap<ID{0x2d5fc20029e9634cu, 0xc39c3daf3820ca8fu}, ID{0xbc515bce03872d28u, 0x7300b5983a3fffbfu}> {};
// const &
template<>
struct StaticInfo<ID{0x5c516f151dfea4d8u, 0xf53a0045173726a1u}>
    : StaticInfo_ConstLRefWrap<ID{0x5c516f151dfea4d8u, 0xf53a0045173726a1u}, ID{0xbc515bce03872d28u, 0x7300b5983a3fffbfu}> {};
// *
template<>
struct StaticInfo<ID{0xaf5f7b902faa6420u, 0x55fadd2a7f33c1bfu}>
    : StaticInfo_PtrWrap<ID{0xaf5f7b902faa6420u, 0x55fadd2a7f33c1bfu}, ID{0xbc515bce03872d28u, 0x7300b5983a3fffbfu}> {};
// const *
template<>
struct StaticInfo<ID{0x3b513062f8f08877u, 0xfa7d5d913457abaeu}>
    : StaticInfo_ConstPtrWrap<ID{0x3b513062f8f08877u, 0xfa7d5d913457abaeu}, ID{0xbc515bce03872d28u, 0x7300b5983a3fffbfu}> {};

/****************************** pf::EmptyEnum END ******************************/

/****************************** pf::EmptyEnum START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum>() {
    return ID{0xbc515bce03872d28u, 0x7300b5983a3fffbfu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum>() {
    return ID{0xdb50ac114169223bu, 0xc38336650f7df787u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &>() {
    return ID{0xfa5b248f62dfcc39u, 0xc0f0749f111ce3a1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &&>() {
    return ID{0x2d5fc20029e9634cu, 0xc39c3daf3820ca8fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum &>() {
    return ID{0x5c516f151dfea4d8u, 0xf53a0045173726a1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::EmptyEnum *>() {
    return ID{0xaf5f7b902faa6420u, 0x55fadd2a7f33c1bfu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum *>() {
    return ID{0x3b513062f8f08877u, 0xfa7d5d913457abaeu};
}
/****************************** pf::EmptyEnum END ******************************/

/****************************** pf::E1::A START ******************************/
template<>
struct StaticInfo<ID{0x9d50aa4fa46bdfa4u, 0xc862ecf7d777b2afu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x9d50aa4fa46bdfa4u, 0xc862ecf7d777b2afu};
    constexpr static ID TypeID = ID{0x9d50aa4fa46bdfa4u, 0xc862ecf7d777b2afu};
    using Type = pf::E1;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 21;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E1::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E1 Value = pf::E1::A;
};
/****************************** pf::E1::A END ******************************/

/****************************** pf::E1::B START ******************************/
template<>
struct StaticInfo<ID{0x595dcd37a6727fe4u, 0x74ef46b2ac478587u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x595dcd37a6727fe4u, 0x74ef46b2ac478587u};
    constexpr static ID TypeID = ID{0x595dcd37a6727fe4u, 0x74ef46b2ac478587u};
    using Type = pf::E1;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 24;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E1::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E1 Value = pf::E1::B;
};
/****************************** pf::E1::B END ******************************/

/****************************** pf::E1::C START ******************************/
template<>
struct StaticInfo<ID{0x205bf6051910e295u, 0x5ae8dcf71bfbdcb6u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x205bf6051910e295u, 0x5ae8dcf71bfbdcb6u};
    constexpr static ID TypeID = ID{0x205bf6051910e295u, 0x5ae8dcf71bfbdcb6u};
    using Type = pf::E1;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 27;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E1::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E1 Value = pf::E1::C;
};
/****************************** pf::E1::C END ******************************/

/****************************** pf::E1::D START ******************************/
template<>
struct StaticInfo<ID{0x64539613f69a90ccu, 0xf19e907dde2d15b4u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x64539613f69a90ccu, 0xf19e907dde2d15b4u};
    constexpr static ID TypeID = ID{0x64539613f69a90ccu, 0xf19e907dde2d15b4u};
    using Type = pf::E1;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 30;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E1::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E1 Value = pf::E1::D;
};
/****************************** pf::E1::D END ******************************/

/****************************** pf::E1::E START ******************************/
template<>
struct StaticInfo<ID{0x3250235a3573c873u, 0x42b3217684717a94u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x3250235a3573c873u, 0x42b3217684717a94u};
    constexpr static ID TypeID = ID{0x3250235a3573c873u, 0x42b3217684717a94u};
    using Type = pf::E1;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 33;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E1::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E1 Value = pf::E1::E;
};
/****************************** pf::E1::E END ******************************/

/****************************** pf::E1 START ******************************/
template<>
struct StaticInfo<ID{0xcb504f03088f9c56u, 0x8c9993d9c0f5e49eu}> {
    struct details {
        
    };
    using Type = pf::E1;
    constexpr static ID TypeID = ID{0xcb504f03088f9c56u, 0x8c9993d9c0f5e49eu};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"E1"};
    constexpr static auto FullName = StringLiteral{"pf::E1"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<Info> auto EnumValues = make_array<Info>(ID{0x9d50aa4fa46bdfa4u, 0xc862ecf7d777b2afu}, ID{0x595dcd37a6727fe4u, 0x74ef46b2ac478587u}, ID{0x205bf6051910e295u, 0x5ae8dcf71bfbdcb6u}, ID{0x64539613f69a90ccu, 0xf19e907dde2d15b4u}, ID{0x3250235a3573c873u, 0x42b3217684717a94u});
};

// const
template<>
struct StaticInfo<ID{0x9756ffdd40e70838u, 0x1c4b21a1343eb7bcu}>
    : StaticInfo_ConstWrap<ID{0x9756ffdd40e70838u, 0x1c4b21a1343eb7bcu}, ID{0xcb504f03088f9c56u, 0x8c9993d9c0f5e49eu}> {};
// &
template<>
struct StaticInfo<ID{0xf356705872d3bea3u, 0xd6a76ca1a7380d80u}>
    : StaticInfo_LRefWrap<ID{0xf356705872d3bea3u, 0xd6a76ca1a7380d80u}, ID{0xcb504f03088f9c56u, 0x8c9993d9c0f5e49eu}> {};
// &&
template<>
struct StaticInfo<ID{0x7b52ce8f484420b0u, 0xd0fdf63bf60d4bbdu}>
    : StaticInfo_RRefWrap<ID{0x7b52ce8f484420b0u, 0xd0fdf63bf60d4bbdu}, ID{0xcb504f03088f9c56u, 0x8c9993d9c0f5e49eu}> {};
// const &
template<>
struct StaticInfo<ID{0x685417a4cde99782u, 0x6ad6c21221a16386u}>
    : StaticInfo_ConstLRefWrap<ID{0x685417a4cde99782u, 0x6ad6c21221a16386u}, ID{0xcb504f03088f9c56u, 0x8c9993d9c0f5e49eu}> {};
// *
template<>
struct StaticInfo<ID{0x2588f8b4be43c44u, 0x4cf0f104c2a4a1aau}>
    : StaticInfo_PtrWrap<ID{0x2588f8b4be43c44u, 0x4cf0f104c2a4a1aau}, ID{0xcb504f03088f9c56u, 0x8c9993d9c0f5e49eu}> {};
// const *
template<>
struct StaticInfo<ID{0x355433b5f8693e03u, 0xa3b725480cfe299du}>
    : StaticInfo_ConstPtrWrap<ID{0x355433b5f8693e03u, 0xa3b725480cfe299du}, ID{0xcb504f03088f9c56u, 0x8c9993d9c0f5e49eu}> {};

/****************************** pf::E1 END ******************************/

/****************************** pf::E1 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1>() {
    return ID{0xcb504f03088f9c56u, 0x8c9993d9c0f5e49eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1>() {
    return ID{0x9756ffdd40e70838u, 0x1c4b21a1343eb7bcu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 &>() {
    return ID{0xf356705872d3bea3u, 0xd6a76ca1a7380d80u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 &&>() {
    return ID{0x7b52ce8f484420b0u, 0xd0fdf63bf60d4bbdu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1 &>() {
    return ID{0x685417a4cde99782u, 0x6ad6c21221a16386u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E1 *>() {
    return ID{0x2588f8b4be43c44u, 0x4cf0f104c2a4a1aau};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E1 *>() {
    return ID{0x355433b5f8693e03u, 0xa3b725480cfe299du};
}
/****************************** pf::E1 END ******************************/

/****************************** pf::E1::pf::E1::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::A>() {
return ID{0x9d50aa4fa46bdfa4u, 0xc862ecf7d777b2afu};
}
/****************************** pf::E1::pf::E1::A END ******************************/

/****************************** pf::E1::pf::E1::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::B>() {
return ID{0x595dcd37a6727fe4u, 0x74ef46b2ac478587u};
}
/****************************** pf::E1::pf::E1::B END ******************************/

/****************************** pf::E1::pf::E1::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::C>() {
return ID{0x205bf6051910e295u, 0x5ae8dcf71bfbdcb6u};
}
/****************************** pf::E1::pf::E1::C END ******************************/

/****************************** pf::E1::pf::E1::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::D>() {
return ID{0x64539613f69a90ccu, 0xf19e907dde2d15b4u};
}
/****************************** pf::E1::pf::E1::D END ******************************/

/****************************** pf::E1::pf::E1::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E1::E>() {
return ID{0x3250235a3573c873u, 0x42b3217684717a94u};
}
/****************************** pf::E1::pf::E1::E END ******************************/

/****************************** pf::E2::A START ******************************/
template<>
struct StaticInfo<ID{0x635d3ca13ef42527u, 0x926874a0b56e4d98u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x635d3ca13ef42527u, 0x926874a0b56e4d98u};
    constexpr static ID TypeID = ID{0x635d3ca13ef42527u, 0x926874a0b56e4d98u};
    using Type = pf::E2;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 21;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E2::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E2 Value = pf::E2::A;
};
/****************************** pf::E2::A END ******************************/

/****************************** pf::E2::B START ******************************/
template<>
struct StaticInfo<ID{0x7c535d5df511eefcu, 0xdd4fa2d6af643589u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x7c535d5df511eefcu, 0xdd4fa2d6af643589u};
    constexpr static ID TypeID = ID{0x7c535d5df511eefcu, 0xdd4fa2d6af643589u};
    using Type = pf::E2;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 24;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E2::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E2 Value = pf::E2::B;
};
/****************************** pf::E2::B END ******************************/

/****************************** pf::E2::C START ******************************/
template<>
struct StaticInfo<ID{0x48520c952de8ce9eu, 0x270ba43d59fa6e80u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x48520c952de8ce9eu, 0x270ba43d59fa6e80u};
    constexpr static ID TypeID = ID{0x48520c952de8ce9eu, 0x270ba43d59fa6e80u};
    using Type = pf::E2;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 27;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E2::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E2 Value = pf::E2::C;
};
/****************************** pf::E2::C END ******************************/

/****************************** pf::E2::D START ******************************/
template<>
struct StaticInfo<ID{0xcf5fd20c8dafe0ecu, 0xec6dbae7b8749aa7u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xcf5fd20c8dafe0ecu, 0xec6dbae7b8749aa7u};
    constexpr static ID TypeID = ID{0xcf5fd20c8dafe0ecu, 0xec6dbae7b8749aa7u};
    using Type = pf::E2;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 30;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E2::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E2 Value = pf::E2::D;
};
/****************************** pf::E2::D END ******************************/

/****************************** pf::E2::E START ******************************/
template<>
struct StaticInfo<ID{0x255e76386f8dd690u, 0xce149b18d56a2182u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x255e76386f8dd690u, 0xce149b18d56a2182u};
    constexpr static ID TypeID = ID{0x255e76386f8dd690u, 0xce149b18d56a2182u};
    using Type = pf::E2;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 33;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E2::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E2 Value = pf::E2::E;
};
/****************************** pf::E2::E END ******************************/

/****************************** pf::E2 START ******************************/
template<>
struct StaticInfo<ID{0x2c56b110e5dd6324u, 0xf3c6ad1f22f4d28au}> {
    struct details {
        
    };
    using Type = pf::E2;
    constexpr static ID TypeID = ID{0x2c56b110e5dd6324u, 0xf3c6ad1f22f4d28au};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"E2"};
    constexpr static auto FullName = StringLiteral{"pf::E2"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<Info> auto EnumValues = make_array<Info>(ID{0x635d3ca13ef42527u, 0x926874a0b56e4d98u}, ID{0x7c535d5df511eefcu, 0xdd4fa2d6af643589u}, ID{0x48520c952de8ce9eu, 0x270ba43d59fa6e80u}, ID{0xcf5fd20c8dafe0ecu, 0xec6dbae7b8749aa7u}, ID{0x255e76386f8dd690u, 0xce149b18d56a2182u});
};

// const
template<>
struct StaticInfo<ID{0x715beee29dc079f6u, 0xd383b3ff54cfdeb3u}>
    : StaticInfo_ConstWrap<ID{0x715beee29dc079f6u, 0xd383b3ff54cfdeb3u}, ID{0x2c56b110e5dd6324u, 0xf3c6ad1f22f4d28au}> {};
// &
template<>
struct StaticInfo<ID{0x6052057514df37ebu, 0x582ae2e04d3092b5u}>
    : StaticInfo_LRefWrap<ID{0x6052057514df37ebu, 0x582ae2e04d3092b5u}, ID{0x2c56b110e5dd6324u, 0xf3c6ad1f22f4d28au}> {};
// &&
template<>
struct StaticInfo<ID{0x2156358873947398u, 0x5507caeb287aa1b3u}>
    : StaticInfo_RRefWrap<ID{0x2156358873947398u, 0x5507caeb287aa1b3u}, ID{0x2c56b110e5dd6324u, 0xf3c6ad1f22f4d28au}> {};
// const &
template<>
struct StaticInfo<ID{0x9f5ff0622d58476fu, 0xc589118f9de87fb9u}>
    : StaticInfo_ConstLRefWrap<ID{0x9f5ff0622d58476fu, 0xc589118f9de87fb9u}, ID{0x2c56b110e5dd6324u, 0xf3c6ad1f22f4d28au}> {};
// *
template<>
struct StaticInfo<ID{0x2c57977ea5f371a1u, 0xabe89e929dbbc8a0u}>
    : StaticInfo_PtrWrap<ID{0x2c57977ea5f371a1u, 0xabe89e929dbbc8a0u}, ID{0x2c56b110e5dd6324u, 0xf3c6ad1f22f4d28au}> {};
// const *
template<>
struct StaticInfo<ID{0x7d5549e95dcc38f6u, 0x20cec16af00ddeb7u}>
    : StaticInfo_ConstPtrWrap<ID{0x7d5549e95dcc38f6u, 0x20cec16af00ddeb7u}, ID{0x2c56b110e5dd6324u, 0xf3c6ad1f22f4d28au}> {};

/****************************** pf::E2 END ******************************/

/****************************** pf::E2 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2>() {
    return ID{0x2c56b110e5dd6324u, 0xf3c6ad1f22f4d28au};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2>() {
    return ID{0x715beee29dc079f6u, 0xd383b3ff54cfdeb3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 &>() {
    return ID{0x6052057514df37ebu, 0x582ae2e04d3092b5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 &&>() {
    return ID{0x2156358873947398u, 0x5507caeb287aa1b3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2 &>() {
    return ID{0x9f5ff0622d58476fu, 0xc589118f9de87fb9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E2 *>() {
    return ID{0x2c57977ea5f371a1u, 0xabe89e929dbbc8a0u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E2 *>() {
    return ID{0x7d5549e95dcc38f6u, 0x20cec16af00ddeb7u};
}
/****************************** pf::E2 END ******************************/

/****************************** pf::E2::pf::E2::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::A>() {
return ID{0x635d3ca13ef42527u, 0x926874a0b56e4d98u};
}
/****************************** pf::E2::pf::E2::A END ******************************/

/****************************** pf::E2::pf::E2::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::B>() {
return ID{0x7c535d5df511eefcu, 0xdd4fa2d6af643589u};
}
/****************************** pf::E2::pf::E2::B END ******************************/

/****************************** pf::E2::pf::E2::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::C>() {
return ID{0x48520c952de8ce9eu, 0x270ba43d59fa6e80u};
}
/****************************** pf::E2::pf::E2::C END ******************************/

/****************************** pf::E2::pf::E2::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::D>() {
return ID{0xcf5fd20c8dafe0ecu, 0xec6dbae7b8749aa7u};
}
/****************************** pf::E2::pf::E2::D END ******************************/

/****************************** pf::E2::pf::E2::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E2::E>() {
return ID{0x255e76386f8dd690u, 0xce149b18d56a2182u};
}
/****************************** pf::E2::pf::E2::E END ******************************/

/****************************** pf::E3::A START ******************************/
template<>
struct StaticInfo<ID{0x30558b4d8da1d4e3u, 0xf5b4713dcede7e81u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x30558b4d8da1d4e3u, 0xf5b4713dcede7e81u};
    constexpr static ID TypeID = ID{0x30558b4d8da1d4e3u, 0xf5b4713dcede7e81u};
    using Type = pf::E3;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 21;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E3::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E3 Value = pf::E3::A;
};
/****************************** pf::E3::A END ******************************/

/****************************** pf::E3::B START ******************************/
template<>
struct StaticInfo<ID{0xad592735fd7e7f43u, 0x4502901b3922dabcu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xad592735fd7e7f43u, 0x4502901b3922dabcu};
    constexpr static ID TypeID = ID{0xad592735fd7e7f43u, 0x4502901b3922dabcu};
    using Type = pf::E3;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 24;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E3::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E3 Value = pf::E3::B;
};
/****************************** pf::E3::B END ******************************/

/****************************** pf::E3::C START ******************************/
template<>
struct StaticInfo<ID{0x8459593ba358ccbcu, 0x86ea2641f579afbeu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x8459593ba358ccbcu, 0x86ea2641f579afbeu};
    constexpr static ID TypeID = ID{0x8459593ba358ccbcu, 0x86ea2641f579afbeu};
    using Type = pf::E3;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 27;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E3::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E3 Value = pf::E3::C;
};
/****************************** pf::E3::C END ******************************/

/****************************** pf::E3::D START ******************************/
template<>
struct StaticInfo<ID{0x3f5d064679ddc1b8u, 0x737ccc35c3497ba5u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x3f5d064679ddc1b8u, 0x737ccc35c3497ba5u};
    constexpr static ID TypeID = ID{0x3f5d064679ddc1b8u, 0x737ccc35c3497ba5u};
    using Type = pf::E3;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 30;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E3::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E3 Value = pf::E3::D;
};
/****************************** pf::E3::D END ******************************/

/****************************** pf::E3::E START ******************************/
template<>
struct StaticInfo<ID{0xe1523b0807bc3f28u, 0x837ba27cb53629bu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xe1523b0807bc3f28u, 0x837ba27cb53629bu};
    constexpr static ID TypeID = ID{0xe1523b0807bc3f28u, 0x837ba27cb53629bu};
    using Type = pf::E3;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 33;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E3::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E3 Value = pf::E3::E;
};
/****************************** pf::E3::E END ******************************/

/****************************** pf::E3 START ******************************/
template<>
struct StaticInfo<ID{0x525020d591a873a1u, 0x583e908c00632d8bu}> {
    struct details {
        
    };
    using Type = pf::E3;
    constexpr static ID TypeID = ID{0x525020d591a873a1u, 0x583e908c00632d8bu};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"E3"};
    constexpr static auto FullName = StringLiteral{"pf::E3"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<Info> auto EnumValues = make_array<Info>(ID{0x30558b4d8da1d4e3u, 0xf5b4713dcede7e81u}, ID{0xad592735fd7e7f43u, 0x4502901b3922dabcu}, ID{0x8459593ba358ccbcu, 0x86ea2641f579afbeu}, ID{0x3f5d064679ddc1b8u, 0x737ccc35c3497ba5u}, ID{0xe1523b0807bc3f28u, 0x837ba27cb53629bu});
};

// const
template<>
struct StaticInfo<ID{0x635295a0da6320ddu, 0x9bf76e285105d87u}>
    : StaticInfo_ConstWrap<ID{0x635295a0da6320ddu, 0x9bf76e285105d87u}, ID{0x525020d591a873a1u, 0x583e908c00632d8bu}> {};
// &
template<>
struct StaticInfo<ID{0x9e516925df142281u, 0x6aaa3375632c599cu}>
    : StaticInfo_LRefWrap<ID{0x9e516925df142281u, 0x6aaa3375632c599cu}, ID{0x525020d591a873a1u, 0x583e908c00632d8bu}> {};
// &&
template<>
struct StaticInfo<ID{0x9f5403b8f0832414u, 0xd2f6a242fca0628eu}>
    : StaticInfo_RRefWrap<ID{0x9f5403b8f0832414u, 0xd2f6a242fca0628eu}, ID{0x525020d591a873a1u, 0x583e908c00632d8bu}> {};
// const &
template<>
struct StaticInfo<ID{0xff5e80aaec492ddcu, 0x16ce658b58232aa1u}>
    : StaticInfo_ConstLRefWrap<ID{0xff5e80aaec492ddcu, 0x16ce658b58232aa1u}, ID{0x525020d591a873a1u, 0x583e908c00632d8bu}> {};
// *
template<>
struct StaticInfo<ID{0xee506bf0b2edb96au, 0x9d6f84e764b54793u}>
    : StaticInfo_PtrWrap<ID{0xee506bf0b2edb96au, 0x9d6f84e764b54793u}, ID{0x525020d591a873a1u, 0x583e908c00632d8bu}> {};
// const *
template<>
struct StaticInfo<ID{0x2d57383fad63ed57u, 0xcbd00f4e369fdfaeu}>
    : StaticInfo_ConstPtrWrap<ID{0x2d57383fad63ed57u, 0xcbd00f4e369fdfaeu}, ID{0x525020d591a873a1u, 0x583e908c00632d8bu}> {};

/****************************** pf::E3 END ******************************/

/****************************** pf::E3 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3>() {
    return ID{0x525020d591a873a1u, 0x583e908c00632d8bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3>() {
    return ID{0x635295a0da6320ddu, 0x9bf76e285105d87u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 &>() {
    return ID{0x9e516925df142281u, 0x6aaa3375632c599cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 &&>() {
    return ID{0x9f5403b8f0832414u, 0xd2f6a242fca0628eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3 &>() {
    return ID{0xff5e80aaec492ddcu, 0x16ce658b58232aa1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E3 *>() {
    return ID{0xee506bf0b2edb96au, 0x9d6f84e764b54793u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E3 *>() {
    return ID{0x2d57383fad63ed57u, 0xcbd00f4e369fdfaeu};
}
/****************************** pf::E3 END ******************************/

/****************************** pf::E3::pf::E3::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::A>() {
return ID{0x30558b4d8da1d4e3u, 0xf5b4713dcede7e81u};
}
/****************************** pf::E3::pf::E3::A END ******************************/

/****************************** pf::E3::pf::E3::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::B>() {
return ID{0xad592735fd7e7f43u, 0x4502901b3922dabcu};
}
/****************************** pf::E3::pf::E3::B END ******************************/

/****************************** pf::E3::pf::E3::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::C>() {
return ID{0x8459593ba358ccbcu, 0x86ea2641f579afbeu};
}
/****************************** pf::E3::pf::E3::C END ******************************/

/****************************** pf::E3::pf::E3::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::D>() {
return ID{0x3f5d064679ddc1b8u, 0x737ccc35c3497ba5u};
}
/****************************** pf::E3::pf::E3::D END ******************************/

/****************************** pf::E3::pf::E3::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E3::E>() {
return ID{0xe1523b0807bc3f28u, 0x837ba27cb53629bu};
}
/****************************** pf::E3::pf::E3::E END ******************************/

/****************************** pf::E4::A START ******************************/
template<>
struct StaticInfo<ID{0x9253c311ecece739u, 0xe7621ff79d829eabu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x9253c311ecece739u, 0xe7621ff79d829eabu};
    constexpr static ID TypeID = ID{0x9253c311ecece739u, 0xe7621ff79d829eabu};
    using Type = pf::E4;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 21;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E4::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E4 Value = pf::E4::A;
};
/****************************** pf::E4::A END ******************************/

/****************************** pf::E4::B START ******************************/
template<>
struct StaticInfo<ID{0x6a5ecc8fbe343a3bu, 0x337a1ef7dd35cbb7u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x6a5ecc8fbe343a3bu, 0x337a1ef7dd35cbb7u};
    constexpr static ID TypeID = ID{0x6a5ecc8fbe343a3bu, 0x337a1ef7dd35cbb7u};
    using Type = pf::E4;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 24;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E4::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E4 Value = pf::E4::B;
};
/****************************** pf::E4::B END ******************************/

/****************************** pf::E4::C START ******************************/
template<>
struct StaticInfo<ID{0xe35f3808a849b890u, 0x9cdc0e68a25b48au}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xe35f3808a849b890u, 0x9cdc0e68a25b48au};
    constexpr static ID TypeID = ID{0xe35f3808a849b890u, 0x9cdc0e68a25b48au};
    using Type = pf::E4;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 27;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E4::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E4 Value = pf::E4::C;
};
/****************************** pf::E4::C END ******************************/

/****************************** pf::E4::D START ******************************/
template<>
struct StaticInfo<ID{0x3057eac37dc96baau, 0x2ddea432523c71a6u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x3057eac37dc96baau, 0x2ddea432523c71a6u};
    constexpr static ID TypeID = ID{0x3057eac37dc96baau, 0x2ddea432523c71a6u};
    using Type = pf::E4;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 30;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E4::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E4 Value = pf::E4::D;
};
/****************************** pf::E4::D END ******************************/

/****************************** pf::E4::E START ******************************/
template<>
struct StaticInfo<ID{0x4e56d3c60af2903du, 0x9db9fc94bea8d8a7u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x4e56d3c60af2903du, 0x9db9fc94bea8d8a7u};
    constexpr static ID TypeID = ID{0x4e56d3c60af2903du, 0x9db9fc94bea8d8a7u};
    using Type = pf::E4;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 33;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E4::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E4 Value = pf::E4::E;
};
/****************************** pf::E4::E END ******************************/

/****************************** pf::E4 START ******************************/
template<>
struct StaticInfo<ID{0x3754a7ca70bd9772u, 0xff2988dc42d54f86u}> {
    struct details {
        
    };
    using Type = pf::E4;
    constexpr static ID TypeID = ID{0x3754a7ca70bd9772u, 0xff2988dc42d54f86u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"E4"};
    constexpr static auto FullName = StringLiteral{"pf::E4"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<Info> auto EnumValues = make_array<Info>(ID{0x9253c311ecece739u, 0xe7621ff79d829eabu}, ID{0x6a5ecc8fbe343a3bu, 0x337a1ef7dd35cbb7u}, ID{0xe35f3808a849b890u, 0x9cdc0e68a25b48au}, ID{0x3057eac37dc96baau, 0x2ddea432523c71a6u}, ID{0x4e56d3c60af2903du, 0x9db9fc94bea8d8a7u});
};

// const
template<>
struct StaticInfo<ID{0xc453f3cf1834353fu, 0x48e85a651389f9aeu}>
    : StaticInfo_ConstWrap<ID{0xc453f3cf1834353fu, 0x48e85a651389f9aeu}, ID{0x3754a7ca70bd9772u, 0xff2988dc42d54f86u}> {};
// &
template<>
struct StaticInfo<ID{0x655f7a8d56336308u, 0x10ac04ebcd0cc6a3u}>
    : StaticInfo_LRefWrap<ID{0x655f7a8d56336308u, 0x10ac04ebcd0cc6a3u}, ID{0x3754a7ca70bd9772u, 0xff2988dc42d54f86u}> {};
// &&
template<>
struct StaticInfo<ID{0xa8534ec58bcfc1a1u, 0x270f5831ef8f4d98u}>
    : StaticInfo_RRefWrap<ID{0xa8534ec58bcfc1a1u, 0x270f5831ef8f4d98u}, ID{0x3754a7ca70bd9772u, 0xff2988dc42d54f86u}> {};
// const &
template<>
struct StaticInfo<ID{0x2c5eea5c1efcca3fu, 0x254af9114cc05d8fu}>
    : StaticInfo_ConstLRefWrap<ID{0x2c5eea5c1efcca3fu, 0x254af9114cc05d8fu}, ID{0x3754a7ca70bd9772u, 0xff2988dc42d54f86u}> {};
// *
template<>
struct StaticInfo<ID{0xb8596d39c1da1106u, 0x52b253d307df48b5u}>
    : StaticInfo_PtrWrap<ID{0xb8596d39c1da1106u, 0x52b253d307df48b5u}, ID{0x3754a7ca70bd9772u, 0xff2988dc42d54f86u}> {};
// const *
template<>
struct StaticInfo<ID{0x4c586a4d329916e1u, 0xa036c662f16faea6u}>
    : StaticInfo_ConstPtrWrap<ID{0x4c586a4d329916e1u, 0xa036c662f16faea6u}, ID{0x3754a7ca70bd9772u, 0xff2988dc42d54f86u}> {};

/****************************** pf::E4 END ******************************/

/****************************** pf::E4 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4>() {
    return ID{0x3754a7ca70bd9772u, 0xff2988dc42d54f86u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4>() {
    return ID{0xc453f3cf1834353fu, 0x48e85a651389f9aeu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 &>() {
    return ID{0x655f7a8d56336308u, 0x10ac04ebcd0cc6a3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 &&>() {
    return ID{0xa8534ec58bcfc1a1u, 0x270f5831ef8f4d98u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4 &>() {
    return ID{0x2c5eea5c1efcca3fu, 0x254af9114cc05d8fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E4 *>() {
    return ID{0xb8596d39c1da1106u, 0x52b253d307df48b5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E4 *>() {
    return ID{0x4c586a4d329916e1u, 0xa036c662f16faea6u};
}
/****************************** pf::E4 END ******************************/

/****************************** pf::E4::pf::E4::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::A>() {
return ID{0x9253c311ecece739u, 0xe7621ff79d829eabu};
}
/****************************** pf::E4::pf::E4::A END ******************************/

/****************************** pf::E4::pf::E4::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::B>() {
return ID{0x6a5ecc8fbe343a3bu, 0x337a1ef7dd35cbb7u};
}
/****************************** pf::E4::pf::E4::B END ******************************/

/****************************** pf::E4::pf::E4::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::C>() {
return ID{0xe35f3808a849b890u, 0x9cdc0e68a25b48au};
}
/****************************** pf::E4::pf::E4::C END ******************************/

/****************************** pf::E4::pf::E4::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::D>() {
return ID{0x3057eac37dc96baau, 0x2ddea432523c71a6u};
}
/****************************** pf::E4::pf::E4::D END ******************************/

/****************************** pf::E4::pf::E4::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E4::E>() {
return ID{0x4e56d3c60af2903du, 0x9db9fc94bea8d8a7u};
}
/****************************** pf::E4::pf::E4::E END ******************************/

/****************************** pf::E5::A START ******************************/
template<>
struct StaticInfo<ID{0xf258fa8ec1e8c0ecu, 0xbd7643b85da095aau}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xf258fa8ec1e8c0ecu, 0xbd7643b85da095aau};
    constexpr static ID TypeID = ID{0xf258fa8ec1e8c0ecu, 0xbd7643b85da095aau};
    using Type = pf::E5;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 21;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E5::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E5 Value = pf::E5::A;
};
/****************************** pf::E5::A END ******************************/

/****************************** pf::E5::B START ******************************/
template<>
struct StaticInfo<ID{0x775ab7f4c9149231u, 0x544a925355408da6u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x775ab7f4c9149231u, 0x544a925355408da6u};
    constexpr static ID TypeID = ID{0x775ab7f4c9149231u, 0x544a925355408da6u};
    using Type = pf::E5;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 24;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E5::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E5 Value = pf::E5::B;
};
/****************************** pf::E5::B END ******************************/

/****************************** pf::E5::C START ******************************/
template<>
struct StaticInfo<ID{0xe958c5f0d721ff19u, 0xc9c68c235e2542a4u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xe958c5f0d721ff19u, 0xc9c68c235e2542a4u};
    constexpr static ID TypeID = ID{0xe958c5f0d721ff19u, 0xc9c68c235e2542a4u};
    using Type = pf::E5;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 27;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E5::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E5 Value = pf::E5::C;
};
/****************************** pf::E5::C END ******************************/

/****************************** pf::E5::D START ******************************/
template<>
struct StaticInfo<ID{0x2755ec3455c47b4eu, 0x8611d8b64c3eb695u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x2755ec3455c47b4eu, 0x8611d8b64c3eb695u};
    constexpr static ID TypeID = ID{0x2755ec3455c47b4eu, 0x8611d8b64c3eb695u};
    using Type = pf::E5;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 30;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E5::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E5 Value = pf::E5::D;
};
/****************************** pf::E5::D END ******************************/

/****************************** pf::E5::E START ******************************/
template<>
struct StaticInfo<ID{0x2f5033660c664b4au, 0x5765cd1d5d78f98eu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x2f5033660c664b4au, 0x5765cd1d5d78f98eu};
    constexpr static ID TypeID = ID{0x2f5033660c664b4au, 0x5765cd1d5d78f98eu};
    using Type = pf::E5;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 33;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E5::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E5 Value = pf::E5::E;
};
/****************************** pf::E5::E END ******************************/

/****************************** pf::E5 START ******************************/
template<>
struct StaticInfo<ID{0x6d55aed9c281d2dcu, 0x9e8f002a31c3258eu}> {
    struct details {
        
    };
    using Type = pf::E5;
    constexpr static ID TypeID = ID{0x6d55aed9c281d2dcu, 0x9e8f002a31c3258eu};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"E5"};
    constexpr static auto FullName = StringLiteral{"pf::E5"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<Info> auto EnumValues = make_array<Info>(ID{0xf258fa8ec1e8c0ecu, 0xbd7643b85da095aau}, ID{0x775ab7f4c9149231u, 0x544a925355408da6u}, ID{0xe958c5f0d721ff19u, 0xc9c68c235e2542a4u}, ID{0x2755ec3455c47b4eu, 0x8611d8b64c3eb695u}, ID{0x2f5033660c664b4au, 0x5765cd1d5d78f98eu});
};

// const
template<>
struct StaticInfo<ID{0xf6524a5404741d1cu, 0x18a07d075c6f5c8bu}>
    : StaticInfo_ConstWrap<ID{0xf6524a5404741d1cu, 0x18a07d075c6f5c8bu}, ID{0x6d55aed9c281d2dcu, 0x9e8f002a31c3258eu}> {};
// &
template<>
struct StaticInfo<ID{0x1050a8d98158dee2u, 0x318237986b9f5582u}>
    : StaticInfo_LRefWrap<ID{0x1050a8d98158dee2u, 0x318237986b9f5582u}, ID{0x6d55aed9c281d2dcu, 0x9e8f002a31c3258eu}> {};
// &&
template<>
struct StaticInfo<ID{0x751ec7f0c05f9a4u, 0x838d7a7e3c06a7a0u}>
    : StaticInfo_RRefWrap<ID{0x751ec7f0c05f9a4u, 0x838d7a7e3c06a7a0u}, ID{0x6d55aed9c281d2dcu, 0x9e8f002a31c3258eu}> {};
// const &
template<>
struct StaticInfo<ID{0xf252653206fa70d9u, 0x64370ad9ca158e9au}>
    : StaticInfo_ConstLRefWrap<ID{0xf252653206fa70d9u, 0x64370ad9ca158e9au}, ID{0x6d55aed9c281d2dcu, 0x9e8f002a31c3258eu}> {};
// *
template<>
struct StaticInfo<ID{0x7e5c4a3cad9b61cdu, 0xa46e83947a0b6aa7u}>
    : StaticInfo_PtrWrap<ID{0x7e5c4a3cad9b61cdu, 0xa46e83947a0b6aa7u}, ID{0x6d55aed9c281d2dcu, 0x9e8f002a31c3258eu}> {};
// const *
template<>
struct StaticInfo<ID{0x95552f970adf0087u, 0x461256038b3b081u}>
    : StaticInfo_ConstPtrWrap<ID{0x95552f970adf0087u, 0x461256038b3b081u}, ID{0x6d55aed9c281d2dcu, 0x9e8f002a31c3258eu}> {};

/****************************** pf::E5 END ******************************/

/****************************** pf::E5 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5>() {
    return ID{0x6d55aed9c281d2dcu, 0x9e8f002a31c3258eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5>() {
    return ID{0xf6524a5404741d1cu, 0x18a07d075c6f5c8bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 &>() {
    return ID{0x1050a8d98158dee2u, 0x318237986b9f5582u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 &&>() {
    return ID{0x751ec7f0c05f9a4u, 0x838d7a7e3c06a7a0u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5 &>() {
    return ID{0xf252653206fa70d9u, 0x64370ad9ca158e9au};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E5 *>() {
    return ID{0x7e5c4a3cad9b61cdu, 0xa46e83947a0b6aa7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E5 *>() {
    return ID{0x95552f970adf0087u, 0x461256038b3b081u};
}
/****************************** pf::E5 END ******************************/

/****************************** pf::E5::pf::E5::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::A>() {
return ID{0xf258fa8ec1e8c0ecu, 0xbd7643b85da095aau};
}
/****************************** pf::E5::pf::E5::A END ******************************/

/****************************** pf::E5::pf::E5::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::B>() {
return ID{0x775ab7f4c9149231u, 0x544a925355408da6u};
}
/****************************** pf::E5::pf::E5::B END ******************************/

/****************************** pf::E5::pf::E5::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::C>() {
return ID{0xe958c5f0d721ff19u, 0xc9c68c235e2542a4u};
}
/****************************** pf::E5::pf::E5::C END ******************************/

/****************************** pf::E5::pf::E5::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::D>() {
return ID{0x2755ec3455c47b4eu, 0x8611d8b64c3eb695u};
}
/****************************** pf::E5::pf::E5::D END ******************************/

/****************************** pf::E5::pf::E5::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E5::E>() {
return ID{0x2f5033660c664b4au, 0x5765cd1d5d78f98eu};
}
/****************************** pf::E5::pf::E5::E END ******************************/

/****************************** pf::E6::A START ******************************/
template<>
struct StaticInfo<ID{0x4854a8d88681b84bu, 0x26e2a23de2f27f87u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x4854a8d88681b84bu, 0x26e2a23de2f27f87u};
    constexpr static ID TypeID = ID{0x4854a8d88681b84bu, 0x26e2a23de2f27f87u};
    using Type = pf::E6;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 21;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E6::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E6 Value = pf::E6::A;
};
/****************************** pf::E6::A END ******************************/

/****************************** pf::E6::B START ******************************/
template<>
struct StaticInfo<ID{0xed5a98fdb027bdd5u, 0xe70fd8b8c3021e85u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xed5a98fdb027bdd5u, 0xe70fd8b8c3021e85u};
    constexpr static ID TypeID = ID{0xed5a98fdb027bdd5u, 0xe70fd8b8c3021e85u};
    using Type = pf::E6;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 24;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E6::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E6 Value = pf::E6::B;
};
/****************************** pf::E6::B END ******************************/

/****************************** pf::E6::C START ******************************/
template<>
struct StaticInfo<ID{0x145ab2a4e82ec74cu, 0xe83a8af4541312abu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x145ab2a4e82ec74cu, 0xe83a8af4541312abu};
    constexpr static ID TypeID = ID{0x145ab2a4e82ec74cu, 0xe83a8af4541312abu};
    using Type = pf::E6;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 27;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E6::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E6 Value = pf::E6::C;
};
/****************************** pf::E6::C END ******************************/

/****************************** pf::E6::D START ******************************/
template<>
struct StaticInfo<ID{0xcd5509d4b50cafaau, 0xa5de537e1f5e5285u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xcd5509d4b50cafaau, 0xa5de537e1f5e5285u};
    constexpr static ID TypeID = ID{0xcd5509d4b50cafaau, 0xa5de537e1f5e5285u};
    using Type = pf::E6;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 30;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E6::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E6 Value = pf::E6::D;
};
/****************************** pf::E6::D END ******************************/

/****************************** pf::E6::E START ******************************/
template<>
struct StaticInfo<ID{0xc353858ae9d10a9au, 0xfe2cbf5cf6e5b2a7u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xc353858ae9d10a9au, 0xfe2cbf5cf6e5b2a7u};
    constexpr static ID TypeID = ID{0xc353858ae9d10a9au, 0xfe2cbf5cf6e5b2a7u};
    using Type = pf::E6;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 33;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E6::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E6 Value = pf::E6::E;
};
/****************************** pf::E6::E END ******************************/

/****************************** pf::E6 START ******************************/
template<>
struct StaticInfo<ID{0x545c6f4edc5d5b2du, 0xa3e64f9af1ad75bcu}> {
    struct details {
        
    };
    using Type = pf::E6;
    constexpr static ID TypeID = ID{0x545c6f4edc5d5b2du, 0xa3e64f9af1ad75bcu};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"E6"};
    constexpr static auto FullName = StringLiteral{"pf::E6"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<Info> auto EnumValues = make_array<Info>(ID{0x4854a8d88681b84bu, 0x26e2a23de2f27f87u}, ID{0xed5a98fdb027bdd5u, 0xe70fd8b8c3021e85u}, ID{0x145ab2a4e82ec74cu, 0xe83a8af4541312abu}, ID{0xcd5509d4b50cafaau, 0xa5de537e1f5e5285u}, ID{0xc353858ae9d10a9au, 0xfe2cbf5cf6e5b2a7u});
};

// const
template<>
struct StaticInfo<ID{0xea526ac00902896cu, 0x37b863477a30adafu}>
    : StaticInfo_ConstWrap<ID{0xea526ac00902896cu, 0x37b863477a30adafu}, ID{0x545c6f4edc5d5b2du, 0xa3e64f9af1ad75bcu}> {};
// &
template<>
struct StaticInfo<ID{0xe55218d688ea1868u, 0x5de6c1fdfcb5cf9eu}>
    : StaticInfo_LRefWrap<ID{0xe55218d688ea1868u, 0x5de6c1fdfcb5cf9eu}, ID{0x545c6f4edc5d5b2du, 0xa3e64f9af1ad75bcu}> {};
// &&
template<>
struct StaticInfo<ID{0x9f5c349474bbe72du, 0x329b6921dd160ab8u}>
    : StaticInfo_RRefWrap<ID{0x9f5c349474bbe72du, 0x329b6921dd160ab8u}, ID{0x545c6f4edc5d5b2du, 0xa3e64f9af1ad75bcu}> {};
// const &
template<>
struct StaticInfo<ID{0xd05b987777cf2660u, 0xacd4c84de449e5a3u}>
    : StaticInfo_ConstLRefWrap<ID{0xd05b987777cf2660u, 0xacd4c84de449e5a3u}, ID{0x545c6f4edc5d5b2du, 0xa3e64f9af1ad75bcu}> {};
// *
template<>
struct StaticInfo<ID{0x195caece4f019abau, 0x2df24a1468fd2988u}>
    : StaticInfo_PtrWrap<ID{0x195caece4f019abau, 0x2df24a1468fd2988u}, ID{0x545c6f4edc5d5b2du, 0xa3e64f9af1ad75bcu}> {};
// const *
template<>
struct StaticInfo<ID{0x865fc08d4b7bc346u, 0x8999e43bf6e3e2b0u}>
    : StaticInfo_ConstPtrWrap<ID{0x865fc08d4b7bc346u, 0x8999e43bf6e3e2b0u}, ID{0x545c6f4edc5d5b2du, 0xa3e64f9af1ad75bcu}> {};

/****************************** pf::E6 END ******************************/

/****************************** pf::E6 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6>() {
    return ID{0x545c6f4edc5d5b2du, 0xa3e64f9af1ad75bcu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6>() {
    return ID{0xea526ac00902896cu, 0x37b863477a30adafu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 &>() {
    return ID{0xe55218d688ea1868u, 0x5de6c1fdfcb5cf9eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 &&>() {
    return ID{0x9f5c349474bbe72du, 0x329b6921dd160ab8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6 &>() {
    return ID{0xd05b987777cf2660u, 0xacd4c84de449e5a3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E6 *>() {
    return ID{0x195caece4f019abau, 0x2df24a1468fd2988u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E6 *>() {
    return ID{0x865fc08d4b7bc346u, 0x8999e43bf6e3e2b0u};
}
/****************************** pf::E6 END ******************************/

/****************************** pf::E6::pf::E6::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::A>() {
return ID{0x4854a8d88681b84bu, 0x26e2a23de2f27f87u};
}
/****************************** pf::E6::pf::E6::A END ******************************/

/****************************** pf::E6::pf::E6::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::B>() {
return ID{0xed5a98fdb027bdd5u, 0xe70fd8b8c3021e85u};
}
/****************************** pf::E6::pf::E6::B END ******************************/

/****************************** pf::E6::pf::E6::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::C>() {
return ID{0x145ab2a4e82ec74cu, 0xe83a8af4541312abu};
}
/****************************** pf::E6::pf::E6::C END ******************************/

/****************************** pf::E6::pf::E6::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::D>() {
return ID{0xcd5509d4b50cafaau, 0xa5de537e1f5e5285u};
}
/****************************** pf::E6::pf::E6::D END ******************************/

/****************************** pf::E6::pf::E6::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E6::E>() {
return ID{0xc353858ae9d10a9au, 0xfe2cbf5cf6e5b2a7u};
}
/****************************** pf::E6::pf::E6::E END ******************************/

/****************************** pf::E7::A START ******************************/
template<>
struct StaticInfo<ID{0x2b5b1ae3f274690eu, 0x18d0d2397975848du}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x2b5b1ae3f274690eu, 0x18d0d2397975848du};
    constexpr static ID TypeID = ID{0x2b5b1ae3f274690eu, 0x18d0d2397975848du};
    using Type = pf::E7;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 21;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E7::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E7 Value = pf::E7::A;
};
/****************************** pf::E7::A END ******************************/

/****************************** pf::E7::B START ******************************/
template<>
struct StaticInfo<ID{0xaa5f78c580a48aacu, 0x3ebd7d80946b0f9au}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xaa5f78c580a48aacu, 0x3ebd7d80946b0f9au};
    constexpr static ID TypeID = ID{0xaa5f78c580a48aacu, 0x3ebd7d80946b0f9au};
    using Type = pf::E7;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 24;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E7::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E7 Value = pf::E7::B;
};
/****************************** pf::E7::B END ******************************/

/****************************** pf::E7::C START ******************************/
template<>
struct StaticInfo<ID{0xb357fe6bc61228cau, 0x10640ea39d25118eu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xb357fe6bc61228cau, 0x10640ea39d25118eu};
    constexpr static ID TypeID = ID{0xb357fe6bc61228cau, 0x10640ea39d25118eu};
    using Type = pf::E7;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 27;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E7::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E7 Value = pf::E7::C;
};
/****************************** pf::E7::C END ******************************/

/****************************** pf::E7::D START ******************************/
template<>
struct StaticInfo<ID{0x245d186999e6c332u, 0x4e620d1a30ac5faau}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x245d186999e6c332u, 0x4e620d1a30ac5faau};
    constexpr static ID TypeID = ID{0x245d186999e6c332u, 0x4e620d1a30ac5faau};
    using Type = pf::E7;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 30;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E7::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E7 Value = pf::E7::D;
};
/****************************** pf::E7::D END ******************************/

/****************************** pf::E7::E START ******************************/
template<>
struct StaticInfo<ID{0x295844551cab62c5u, 0x7903a16c636341bcu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x295844551cab62c5u, 0x7903a16c636341bcu};
    constexpr static ID TypeID = ID{0x295844551cab62c5u, 0x7903a16c636341bcu};
    using Type = pf::E7;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 33;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E7::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E7 Value = pf::E7::E;
};
/****************************** pf::E7::E END ******************************/

/****************************** pf::E7 START ******************************/
template<>
struct StaticInfo<ID{0xd15b25619c40a2efu, 0x28201a793f4beebau}> {
    struct details {
        
    };
    using Type = pf::E7;
    constexpr static ID TypeID = ID{0xd15b25619c40a2efu, 0x28201a793f4beebau};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"E7"};
    constexpr static auto FullName = StringLiteral{"pf::E7"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<Info> auto EnumValues = make_array<Info>(ID{0x2b5b1ae3f274690eu, 0x18d0d2397975848du}, ID{0xaa5f78c580a48aacu, 0x3ebd7d80946b0f9au}, ID{0xb357fe6bc61228cau, 0x10640ea39d25118eu}, ID{0x245d186999e6c332u, 0x4e620d1a30ac5faau}, ID{0x295844551cab62c5u, 0x7903a16c636341bcu});
};

// const
template<>
struct StaticInfo<ID{0xb55fe5473f6d422du, 0x8ee37454b28c63b3u}>
    : StaticInfo_ConstWrap<ID{0xb55fe5473f6d422du, 0x8ee37454b28c63b3u}, ID{0xd15b25619c40a2efu, 0x28201a793f4beebau}> {};
// &
template<>
struct StaticInfo<ID{0x1d59c44b5d8755a6u, 0x5b38d14ce50dc0b3u}>
    : StaticInfo_LRefWrap<ID{0x1d59c44b5d8755a6u, 0x5b38d14ce50dc0b3u}, ID{0xd15b25619c40a2efu, 0x28201a793f4beebau}> {};
// &&
template<>
struct StaticInfo<ID{0xdc5693c318f3fcf3u, 0x670cd8d9eb6a8f8fu}>
    : StaticInfo_RRefWrap<ID{0xdc5693c318f3fcf3u, 0x670cd8d9eb6a8f8fu}, ID{0xd15b25619c40a2efu, 0x28201a793f4beebau}> {};
// const &
template<>
struct StaticInfo<ID{0x9b5cc6d7b5776bc6u, 0xafa764d0492ed081u}>
    : StaticInfo_ConstLRefWrap<ID{0x9b5cc6d7b5776bc6u, 0xafa764d0492ed081u}, ID{0xd15b25619c40a2efu, 0x28201a793f4beebau}> {};
// *
template<>
struct StaticInfo<ID{0xde5f1c0f59d24486u, 0x2fae61bc2302d488u}>
    : StaticInfo_PtrWrap<ID{0xde5f1c0f59d24486u, 0x2fae61bc2302d488u}, ID{0xd15b25619c40a2efu, 0x28201a793f4beebau}> {};
// const *
template<>
struct StaticInfo<ID{0xd65e4eeba64be602u, 0xe63044690c954699u}>
    : StaticInfo_ConstPtrWrap<ID{0xd65e4eeba64be602u, 0xe63044690c954699u}, ID{0xd15b25619c40a2efu, 0x28201a793f4beebau}> {};

/****************************** pf::E7 END ******************************/

/****************************** pf::E7 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7>() {
    return ID{0xd15b25619c40a2efu, 0x28201a793f4beebau};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7>() {
    return ID{0xb55fe5473f6d422du, 0x8ee37454b28c63b3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 &>() {
    return ID{0x1d59c44b5d8755a6u, 0x5b38d14ce50dc0b3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 &&>() {
    return ID{0xdc5693c318f3fcf3u, 0x670cd8d9eb6a8f8fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7 &>() {
    return ID{0x9b5cc6d7b5776bc6u, 0xafa764d0492ed081u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E7 *>() {
    return ID{0xde5f1c0f59d24486u, 0x2fae61bc2302d488u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E7 *>() {
    return ID{0xd65e4eeba64be602u, 0xe63044690c954699u};
}
/****************************** pf::E7 END ******************************/

/****************************** pf::E7::pf::E7::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::A>() {
return ID{0x2b5b1ae3f274690eu, 0x18d0d2397975848du};
}
/****************************** pf::E7::pf::E7::A END ******************************/

/****************************** pf::E7::pf::E7::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::B>() {
return ID{0xaa5f78c580a48aacu, 0x3ebd7d80946b0f9au};
}
/****************************** pf::E7::pf::E7::B END ******************************/

/****************************** pf::E7::pf::E7::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::C>() {
return ID{0xb357fe6bc61228cau, 0x10640ea39d25118eu};
}
/****************************** pf::E7::pf::E7::C END ******************************/

/****************************** pf::E7::pf::E7::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::D>() {
return ID{0x245d186999e6c332u, 0x4e620d1a30ac5faau};
}
/****************************** pf::E7::pf::E7::D END ******************************/

/****************************** pf::E7::pf::E7::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E7::E>() {
return ID{0x295844551cab62c5u, 0x7903a16c636341bcu};
}
/****************************** pf::E7::pf::E7::E END ******************************/

/****************************** pf::E8::A START ******************************/
template<>
struct StaticInfo<ID{0xe52a125c373eb03u, 0x408eb8c6dba87485u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xe52a125c373eb03u, 0x408eb8c6dba87485u};
    constexpr static ID TypeID = ID{0xe52a125c373eb03u, 0x408eb8c6dba87485u};
    using Type = pf::E8;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 21;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E8::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E8 Value = pf::E8::A;
};
/****************************** pf::E8::A END ******************************/

/****************************** pf::E8::B START ******************************/
template<>
struct StaticInfo<ID{0x8e5e119c3a02a3cfu, 0xd71c26a8d426b7bbu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x8e5e119c3a02a3cfu, 0xd71c26a8d426b7bbu};
    constexpr static ID TypeID = ID{0x8e5e119c3a02a3cfu, 0xd71c26a8d426b7bbu};
    using Type = pf::E8;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 24;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E8::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E8 Value = pf::E8::B;
};
/****************************** pf::E8::B END ******************************/

/****************************** pf::E8::C START ******************************/
template<>
struct StaticInfo<ID{0xcf556f61c39e8b66u, 0x47b9d97489392a81u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xcf556f61c39e8b66u, 0x47b9d97489392a81u};
    constexpr static ID TypeID = ID{0xcf556f61c39e8b66u, 0x47b9d97489392a81u};
    using Type = pf::E8;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 27;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E8::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E8 Value = pf::E8::C;
};
/****************************** pf::E8::C END ******************************/

/****************************** pf::E8::D START ******************************/
template<>
struct StaticInfo<ID{0x215cc301caf59167u, 0xbe3063c46683e7b1u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x215cc301caf59167u, 0xbe3063c46683e7b1u};
    constexpr static ID TypeID = ID{0x215cc301caf59167u, 0xbe3063c46683e7b1u};
    using Type = pf::E8;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 30;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E8::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E8 Value = pf::E8::D;
};
/****************************** pf::E8::D END ******************************/

/****************************** pf::E8::E START ******************************/
template<>
struct StaticInfo<ID{0xbf594c204ff3dce3u, 0xd7b4b0626e0a09bu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xbf594c204ff3dce3u, 0xd7b4b0626e0a09bu};
    constexpr static ID TypeID = ID{0xbf594c204ff3dce3u, 0xd7b4b0626e0a09bu};
    using Type = pf::E8;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 33;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E8::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E8 Value = pf::E8::E;
};
/****************************** pf::E8::E END ******************************/

/****************************** pf::E8 START ******************************/
template<>
struct StaticInfo<ID{0xb0501ed449af7c09u, 0x622e030a4ca11ebeu}> {
    struct details {
        
    };
    using Type = pf::E8;
    constexpr static ID TypeID = ID{0xb0501ed449af7c09u, 0x622e030a4ca11ebeu};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"E8"};
    constexpr static auto FullName = StringLiteral{"pf::E8"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<Info> auto EnumValues = make_array<Info>(ID{0xe52a125c373eb03u, 0x408eb8c6dba87485u}, ID{0x8e5e119c3a02a3cfu, 0xd71c26a8d426b7bbu}, ID{0xcf556f61c39e8b66u, 0x47b9d97489392a81u}, ID{0x215cc301caf59167u, 0xbe3063c46683e7b1u}, ID{0xbf594c204ff3dce3u, 0xd7b4b0626e0a09bu});
};

// const
template<>
struct StaticInfo<ID{0x50505f439bde167du, 0x2496096db421d9adu}>
    : StaticInfo_ConstWrap<ID{0x50505f439bde167du, 0x2496096db421d9adu}, ID{0xb0501ed449af7c09u, 0x622e030a4ca11ebeu}> {};
// &
template<>
struct StaticInfo<ID{0xe5b337848093ccfu, 0xe17051de299489b1u}>
    : StaticInfo_LRefWrap<ID{0xe5b337848093ccfu, 0xe17051de299489b1u}, ID{0xb0501ed449af7c09u, 0x622e030a4ca11ebeu}> {};
// &&
template<>
struct StaticInfo<ID{0x2952d7727b5f97b6u, 0x7043c2a7915f2992u}>
    : StaticInfo_RRefWrap<ID{0x2952d7727b5f97b6u, 0x7043c2a7915f2992u}, ID{0xb0501ed449af7c09u, 0x622e030a4ca11ebeu}> {};
// const &
template<>
struct StaticInfo<ID{0xdc5d06ff6454fdbdu, 0x37fb2f4d75065299u}>
    : StaticInfo_ConstLRefWrap<ID{0xdc5d06ff6454fdbdu, 0x37fb2f4d75065299u}, ID{0xb0501ed449af7c09u, 0x622e030a4ca11ebeu}> {};
// *
template<>
struct StaticInfo<ID{0x135926223b3a798cu, 0x17d470114cee988cu}>
    : StaticInfo_PtrWrap<ID{0x135926223b3a798cu, 0x17d470114cee988cu}, ID{0xb0501ed449af7c09u, 0x622e030a4ca11ebeu}> {};
// const *
template<>
struct StaticInfo<ID{0x8c532ce854761fd3u, 0xd1e64a8bcfeed5bau}>
    : StaticInfo_ConstPtrWrap<ID{0x8c532ce854761fd3u, 0xd1e64a8bcfeed5bau}, ID{0xb0501ed449af7c09u, 0x622e030a4ca11ebeu}> {};

/****************************** pf::E8 END ******************************/

/****************************** pf::E8 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8>() {
    return ID{0xb0501ed449af7c09u, 0x622e030a4ca11ebeu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8>() {
    return ID{0x50505f439bde167du, 0x2496096db421d9adu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 &>() {
    return ID{0xe5b337848093ccfu, 0xe17051de299489b1u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 &&>() {
    return ID{0x2952d7727b5f97b6u, 0x7043c2a7915f2992u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8 &>() {
    return ID{0xdc5d06ff6454fdbdu, 0x37fb2f4d75065299u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E8 *>() {
    return ID{0x135926223b3a798cu, 0x17d470114cee988cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E8 *>() {
    return ID{0x8c532ce854761fd3u, 0xd1e64a8bcfeed5bau};
}
/****************************** pf::E8 END ******************************/

/****************************** pf::E8::pf::E8::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::A>() {
return ID{0xe52a125c373eb03u, 0x408eb8c6dba87485u};
}
/****************************** pf::E8::pf::E8::A END ******************************/

/****************************** pf::E8::pf::E8::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::B>() {
return ID{0x8e5e119c3a02a3cfu, 0xd71c26a8d426b7bbu};
}
/****************************** pf::E8::pf::E8::B END ******************************/

/****************************** pf::E8::pf::E8::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::C>() {
return ID{0xcf556f61c39e8b66u, 0x47b9d97489392a81u};
}
/****************************** pf::E8::pf::E8::C END ******************************/

/****************************** pf::E8::pf::E8::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::D>() {
return ID{0x215cc301caf59167u, 0xbe3063c46683e7b1u};
}
/****************************** pf::E8::pf::E8::D END ******************************/

/****************************** pf::E8::pf::E8::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E8::E>() {
return ID{0xbf594c204ff3dce3u, 0xd7b4b0626e0a09bu};
}
/****************************** pf::E8::pf::E8::E END ******************************/

/****************************** pf::E9::A START ******************************/
template<>
struct StaticInfo<ID{0xf558f81596978c12u, 0x6b15ad539b7777acu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xf558f81596978c12u, 0x6b15ad539b7777acu};
    constexpr static ID TypeID = ID{0xf558f81596978c12u, 0x6b15ad539b7777acu};
    using Type = pf::E9;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 21;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E9::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E9 Value = pf::E9::A;
};
/****************************** pf::E9::A END ******************************/

/****************************** pf::E9::B START ******************************/
template<>
struct StaticInfo<ID{0x9f55c71d60218126u, 0x75ba8c695c2485acu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x9f55c71d60218126u, 0x75ba8c695c2485acu};
    constexpr static ID TypeID = ID{0x9f55c71d60218126u, 0x75ba8c695c2485acu};
    using Type = pf::E9;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 24;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E9::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E9 Value = pf::E9::B;
};
/****************************** pf::E9::B END ******************************/

/****************************** pf::E9::C START ******************************/
template<>
struct StaticInfo<ID{0xf5c64589ad9f505u, 0x8931e11fbee44c9cu}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0xf5c64589ad9f505u, 0x8931e11fbee44c9cu};
    constexpr static ID TypeID = ID{0xf5c64589ad9f505u, 0x8931e11fbee44c9cu};
    using Type = pf::E9;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 27;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E9::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E9 Value = pf::E9::C;
};
/****************************** pf::E9::C END ******************************/

/****************************** pf::E9::D START ******************************/
template<>
struct StaticInfo<ID{0x252d6830480f43bu, 0xa74a0b2f241ceeb8u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x252d6830480f43bu, 0xa74a0b2f241ceeb8u};
    constexpr static ID TypeID = ID{0x252d6830480f43bu, 0xa74a0b2f241ceeb8u};
    using Type = pf::E9;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 30;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E9::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E9 Value = pf::E9::D;
};
/****************************** pf::E9::D END ******************************/

/****************************** pf::E9::E START ******************************/
template<>
struct StaticInfo<ID{0x60565d153370aeb3u, 0x29a2ad77877eb780u}> {
    struct details {
        
    };
    constexpr static ID ValueID = ID{0x60565d153370aeb3u, 0x29a2ad77877eb780u};
    constexpr static ID TypeID = ID{0x60565d153370aeb3u, 0x29a2ad77877eb780u};
    using Type = pf::E9;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 33;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E9::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E9 Value = pf::E9::E;
};
/****************************** pf::E9::E END ******************************/

/****************************** pf::E9 START ******************************/
template<>
struct StaticInfo<ID{0xdb5f6197d3daadfdu, 0xc943b069a78ed385u}> {
    struct details {
        
    };
    using Type = pf::E9;
    constexpr static ID TypeID = ID{0xdb5f6197d3daadfdu, 0xc943b069a78ed385u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"E9"};
    constexpr static auto FullName = StringLiteral{"pf::E9"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<Info> auto EnumValues = make_array<Info>(ID{0xf558f81596978c12u, 0x6b15ad539b7777acu}, ID{0x9f55c71d60218126u, 0x75ba8c695c2485acu}, ID{0xf5c64589ad9f505u, 0x8931e11fbee44c9cu}, ID{0x252d6830480f43bu, 0xa74a0b2f241ceeb8u}, ID{0x60565d153370aeb3u, 0x29a2ad77877eb780u});
};

// const
template<>
struct StaticInfo<ID{0x7e5a8e83d6fb552bu, 0x82cac175b9d3d8acu}>
    : StaticInfo_ConstWrap<ID{0x7e5a8e83d6fb552bu, 0x82cac175b9d3d8acu}, ID{0xdb5f6197d3daadfdu, 0xc943b069a78ed385u}> {};
// &
template<>
struct StaticInfo<ID{0x935e5c00e5f8aab7u, 0xaf19b8c309eb9c93u}>
    : StaticInfo_LRefWrap<ID{0x935e5c00e5f8aab7u, 0xaf19b8c309eb9c93u}, ID{0xdb5f6197d3daadfdu, 0xc943b069a78ed385u}> {};
// &&
template<>
struct StaticInfo<ID{0xa45e4eca371ea608u, 0xbc9843a9de7316a8u}>
    : StaticInfo_RRefWrap<ID{0xa45e4eca371ea608u, 0xbc9843a9de7316a8u}, ID{0xdb5f6197d3daadfdu, 0xc943b069a78ed385u}> {};
// const &
template<>
struct StaticInfo<ID{0x955187e5c6597d8cu, 0xa5c85da7db084ea9u}>
    : StaticInfo_ConstLRefWrap<ID{0x955187e5c6597d8cu, 0xa5c85da7db084ea9u}, ID{0xdb5f6197d3daadfdu, 0xc943b069a78ed385u}> {};
// *
template<>
struct StaticInfo<ID{0x3d5e04b0818130fdu, 0xca7466700cf248b2u}>
    : StaticInfo_PtrWrap<ID{0x3d5e04b0818130fdu, 0xca7466700cf248b2u}, ID{0xdb5f6197d3daadfdu, 0xc943b069a78ed385u}> {};
// const *
template<>
struct StaticInfo<ID{0x9556269096a22c45u, 0x2df3e062777713b2u}>
    : StaticInfo_ConstPtrWrap<ID{0x9556269096a22c45u, 0x2df3e062777713b2u}, ID{0xdb5f6197d3daadfdu, 0xc943b069a78ed385u}> {};

/****************************** pf::E9 END ******************************/

/****************************** pf::E9 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9>() {
    return ID{0xdb5f6197d3daadfdu, 0xc943b069a78ed385u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9>() {
    return ID{0x7e5a8e83d6fb552bu, 0x82cac175b9d3d8acu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 &>() {
    return ID{0x935e5c00e5f8aab7u, 0xaf19b8c309eb9c93u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 &&>() {
    return ID{0xa45e4eca371ea608u, 0xbc9843a9de7316a8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9 &>() {
    return ID{0x955187e5c6597d8cu, 0xa5c85da7db084ea9u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::E9 *>() {
    return ID{0x3d5e04b0818130fdu, 0xca7466700cf248b2u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::E9 *>() {
    return ID{0x9556269096a22c45u, 0x2df3e062777713b2u};
}
/****************************** pf::E9 END ******************************/

/****************************** pf::E9::pf::E9::A START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::A>() {
return ID{0xf558f81596978c12u, 0x6b15ad539b7777acu};
}
/****************************** pf::E9::pf::E9::A END ******************************/

/****************************** pf::E9::pf::E9::B START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::B>() {
return ID{0x9f55c71d60218126u, 0x75ba8c695c2485acu};
}
/****************************** pf::E9::pf::E9::B END ******************************/

/****************************** pf::E9::pf::E9::C START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::C>() {
return ID{0xf5c64589ad9f505u, 0x8931e11fbee44c9cu};
}
/****************************** pf::E9::pf::E9::C END ******************************/

/****************************** pf::E9::pf::E9::D START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::D>() {
return ID{0x252d6830480f43bu, 0xa74a0b2f241ceeb8u};
}
/****************************** pf::E9::pf::E9::D END ******************************/

/****************************** pf::E9::pf::E9::E START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<pf::E9::E>() {
return ID{0x60565d153370aeb3u, 0x29a2ad77877eb780u};
}
/****************************** pf::E9::pf::E9::E END ******************************/

}
