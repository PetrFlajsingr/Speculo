
#pragma once

#include <test.h>
#include <meta/details/array.h>
#include <meta/details/RangeOf.h>
#include <type_traits>
#include <meta/details/StaticInfo.h>
#include <meta/details/StaticInfo_Wrappers.h>
#include <meta/details/ID.h>
#include <meta/Attribute.h>
#include <meta/Info.h>

namespace pf::meta::details {

/****************************** pf::SomeEnum::Value1 START ******************************/
template<>
struct StaticInfo<ID{0xc0597f7732016649u, 0xed19a615bd3023bau}> {
    
    constexpr static ID ValueID = ID{0xc0597f7732016649u, 0xed19a615bd3023bau};
    constexpr static ID TypeID = ID{0xc0597f7732016649u, 0xed19a615bd3023bau};
    using Type = pf::SomeEnum;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 9;
    constexpr static std::uint64_t SourceColumn = 13;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(Attribute{"pf::test", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"pf::test2", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"pf::test3", std::span<const std::string_view>{EmptyAttributeArgArray}});

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
    
    constexpr static ID ValueID = ID{0x445d2037590be14au, 0xd949752de2aa1786u};
    constexpr static ID TypeID = ID{0x445d2037590be14au, 0xd949752de2aa1786u};
    using Type = pf::SomeEnum;

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 9;
    constexpr static std::uint64_t SourceColumn = 59;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

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
constexpr static auto ArgArray_2685153593162509895 = pf::meta::details::make_array<std::string_view>(R"arg(()()()((())))arg", R"arg([[nodiscard]])arg", R"arg(1ll)arg", R"arg(1.011)arg", R"arg([]{}())arg", R"arg("yeet")arg", R"arg('a')arg", R"arg([][][]:::3214234...[][][][])arg");
constexpr static auto ArgArray_3750427590782305590 = pf::meta::details::make_array<std::string_view>(R"arg(1ll)arg", R"arg(1.011)arg", R"arg("yeet")arg");
};
    using Type = pf::SomeEnum;
    constexpr static ID TypeID = ID{0x2b53af1c1cf57f8au, 0xe97917064d8b3696u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 7;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(Attribute{"pf::operators", std::span<const std::string_view>{details::ArgArray_2685153593162509895}}, Attribute{"pf::hihi", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"pf::operators2", std::span<const std::string_view>{details::ArgArray_3750427590782305590}}, Attribute{"pf::hihi2", std::span<const std::string_view>{EmptyAttributeArgArray}});

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"SomeEnum"};
    constexpr static auto FullName = StringLiteral{"pf::SomeEnum"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<Info> auto EnumValues = pf::meta::details::make_array<Info>(ID{0xc0597f7732016649u, 0xed19a615bd3023bau}, ID{0x445d2037590be14au, 0xd949752de2aa1786u});
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

/****************************** pf::B1 START ******************************/
template<>
struct StaticInfo<ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u}> {
    
    using Type = pf::B1;
    constexpr static ID TypeID = ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 12;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::RecordType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"B1"};
    constexpr static auto FullName = StringLiteral{"pf::B1"};

    constexpr static bool IsUnion = false;
    constexpr static bool IsPolymorphic = false;
    constexpr static bool IsAbstract = false;
    constexpr static bool IsFinal = false;
    constexpr static RangeOf<Info> auto Bases = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>();
    constexpr static Info Destructor = ID{0xd552f19eae53efa9u, 0xdb1981450a58b4b9u};
    constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto StaticFunctions = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto MemberVariables = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto StaticVariables = pf::meta::details::make_array<Info>();
};

// const
template<>
struct StaticInfo<ID{0xed5d311f2d348e8eu, 0xbda3350154b0b0a8u}>
    : StaticInfo_ConstWrap<ID{0xed5d311f2d348e8eu, 0xbda3350154b0b0a8u}, ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u}> {};
// &
template<>
struct StaticInfo<ID{0x8257aef84cd505f5u, 0x8e7520928795e8bau}>
    : StaticInfo_LRefWrap<ID{0x8257aef84cd505f5u, 0x8e7520928795e8bau}, ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u}> {};
// &&
template<>
struct StaticInfo<ID{0xbd5574634741c644u, 0xd215026848538aacu}>
    : StaticInfo_RRefWrap<ID{0xbd5574634741c644u, 0xd215026848538aacu}, ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u}> {};
// const &
template<>
struct StaticInfo<ID{0x135f2193a7f32297u, 0x1793cae763d8bb7u}>
    : StaticInfo_ConstLRefWrap<ID{0x135f2193a7f32297u, 0x1793cae763d8bb7u}, ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u}> {};
// *
template<>
struct StaticInfo<ID{0x2a54d3ccc81ceebdu, 0x517afb17c82fe98fu}>
    : StaticInfo_PtrWrap<ID{0x2a54d3ccc81ceebdu, 0x517afb17c82fe98fu}, ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u}> {};
// const *
template<>
struct StaticInfo<ID{0x4a57812b7c951e74u, 0x96f3df9d317097a3u}>
    : StaticInfo_ConstPtrWrap<ID{0x4a57812b7c951e74u, 0x96f3df9d317097a3u}, ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u}> {};

/****************************** pf::B1 END ******************************/

/****************************** pf::B1 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::B1>() {
    return ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::B1>() {
    return ID{0xed5d311f2d348e8eu, 0xbda3350154b0b0a8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::B1 &>() {
    return ID{0x8257aef84cd505f5u, 0x8e7520928795e8bau};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::B1 &&>() {
    return ID{0xbd5574634741c644u, 0xd215026848538aacu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::B1 &>() {
    return ID{0x135f2193a7f32297u, 0x1793cae763d8bb7u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::B1 *>() {
    return ID{0x2a54d3ccc81ceebdu, 0x517afb17c82fe98fu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::B1 *>() {
    return ID{0x4a57812b7c951e74u, 0x96f3df9d317097a3u};
}
/****************************** pf::B1 END ******************************/

/****************************** pf::B1::~B1 START ******************************/
template<>
struct StaticInfo<ID{0xd552f19eae53efa9u, 0xdb1981450a58b4b9u}> {
    
    constexpr static ID DestructorID = ID{0xd552f19eae53efa9u, 0xdb1981450a58b4b9u};
    constexpr static ID TypeID = ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Destructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static auto IsConstexpr = true;
    constexpr static auto IsConsteval = false;
    constexpr static auto IsVirtual = false;
    constexpr static auto IsPureVirtual = false;

    constexpr static auto Name = StringLiteral{"~B1"};
    constexpr static auto FullName = StringLiteral{"pf::B1::~B1"};
    };

/****************************** pf::B2 START ******************************/
template<>
struct StaticInfo<ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u}> {
    
    using Type = pf::B2;
    constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 13;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::RecordType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"B2"};
    constexpr static auto FullName = StringLiteral{"pf::B2"};

    constexpr static bool IsUnion = false;
    constexpr static bool IsPolymorphic = false;
    constexpr static bool IsAbstract = false;
    constexpr static bool IsFinal = false;
    constexpr static RangeOf<Info> auto Bases = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>();
    constexpr static Info Destructor = ID{0x75598d2a0e986fadu, 0x24bfa1eb9392f7a5u};
    constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto StaticFunctions = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto MemberVariables = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto StaticVariables = pf::meta::details::make_array<Info>();
};

// const
template<>
struct StaticInfo<ID{0xe25726891916a0dbu, 0x5d56ad0ebd5c92bau}>
    : StaticInfo_ConstWrap<ID{0xe25726891916a0dbu, 0x5d56ad0ebd5c92bau}, ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u}> {};
// &
template<>
struct StaticInfo<ID{0x755e9eb5eb455adbu, 0xe9a1040b691c9a80u}>
    : StaticInfo_LRefWrap<ID{0x755e9eb5eb455adbu, 0xe9a1040b691c9a80u}, ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u}> {};
// &&
template<>
struct StaticInfo<ID{0x4c52c786c5322447u, 0x271a6e9107fe13abu}>
    : StaticInfo_RRefWrap<ID{0x4c52c786c5322447u, 0x271a6e9107fe13abu}, ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u}> {};
// const &
template<>
struct StaticInfo<ID{0x3c5db803dc8b766cu, 0x6122e33c50d5d981u}>
    : StaticInfo_ConstLRefWrap<ID{0x3c5db803dc8b766cu, 0x6122e33c50d5d981u}, ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u}> {};
// *
template<>
struct StaticInfo<ID{0x5a561135be4047bcu, 0xa5cd64df630c52b5u}>
    : StaticInfo_PtrWrap<ID{0x5a561135be4047bcu, 0xa5cd64df630c52b5u}, ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u}> {};
// const *
template<>
struct StaticInfo<ID{0xd85826646f8d8d59u, 0x80888acaf85225b9u}>
    : StaticInfo_ConstPtrWrap<ID{0xd85826646f8d8d59u, 0x80888acaf85225b9u}, ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u}> {};

/****************************** pf::B2 END ******************************/

/****************************** pf::B2 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::B2>() {
    return ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::B2>() {
    return ID{0xe25726891916a0dbu, 0x5d56ad0ebd5c92bau};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::B2 &>() {
    return ID{0x755e9eb5eb455adbu, 0xe9a1040b691c9a80u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::B2 &&>() {
    return ID{0x4c52c786c5322447u, 0x271a6e9107fe13abu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::B2 &>() {
    return ID{0x3c5db803dc8b766cu, 0x6122e33c50d5d981u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::B2 *>() {
    return ID{0x5a561135be4047bcu, 0xa5cd64df630c52b5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::B2 *>() {
    return ID{0xd85826646f8d8d59u, 0x80888acaf85225b9u};
}
/****************************** pf::B2 END ******************************/

/****************************** pf::B2::~B2 START ******************************/
template<>
struct StaticInfo<ID{0x75598d2a0e986fadu, 0x24bfa1eb9392f7a5u}> {
    
    constexpr static ID DestructorID = ID{0x75598d2a0e986fadu, 0x24bfa1eb9392f7a5u};
    constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Destructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static auto IsConstexpr = true;
    constexpr static auto IsConsteval = false;
    constexpr static auto IsVirtual = false;
    constexpr static auto IsPureVirtual = false;

    constexpr static auto Name = StringLiteral{"~B2"};
    constexpr static auto FullName = StringLiteral{"pf::B2::~B2"};
    };

/****************************** pf::B3 START ******************************/
template<>
struct StaticInfo<ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu}> {
    
    using Type = pf::B3;
    constexpr static ID TypeID = ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 14;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::RecordType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"B3"};
    constexpr static auto FullName = StringLiteral{"pf::B3"};

    constexpr static bool IsUnion = false;
    constexpr static bool IsPolymorphic = false;
    constexpr static bool IsAbstract = false;
    constexpr static bool IsFinal = false;
    constexpr static RangeOf<Info> auto Bases = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>();
    constexpr static Info Destructor = ID{0x115b1c832b9d7569u, 0x163a50a92d0c318bu};
    constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto StaticFunctions = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto MemberVariables = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto StaticVariables = pf::meta::details::make_array<Info>();
};

// const
template<>
struct StaticInfo<ID{0x1c5f34d949fee916u, 0x6c09a7016a5f4a98u}>
    : StaticInfo_ConstWrap<ID{0x1c5f34d949fee916u, 0x6c09a7016a5f4a98u}, ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu}> {};
// &
template<>
struct StaticInfo<ID{0x2956e4d91940fc4bu, 0xacc6d7dbc030b8b5u}>
    : StaticInfo_LRefWrap<ID{0x2956e4d91940fc4bu, 0xacc6d7dbc030b8b5u}, ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu}> {};
// &&
template<>
struct StaticInfo<ID{0xf5b6b3f6d5e61a0u, 0xbee6ca15f47a9d91u}>
    : StaticInfo_RRefWrap<ID{0xf5b6b3f6d5e61a0u, 0xbee6ca15f47a9d91u}, ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu}> {};
// const &
template<>
struct StaticInfo<ID{0xdf5ef9813915fdd3u, 0x1f4361105a86a4b8u}>
    : StaticInfo_ConstLRefWrap<ID{0xdf5ef9813915fdd3u, 0x1f4361105a86a4b8u}, ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu}> {};
// *
template<>
struct StaticInfo<ID{0x55d1e7716633524u, 0xeab125ee05657eb8u}>
    : StaticInfo_PtrWrap<ID{0x55d1e7716633524u, 0xeab125ee05657eb8u}, ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu}> {};
// const *
template<>
struct StaticInfo<ID{0xa15743fef763d17bu, 0x35436c4559a29f80u}>
    : StaticInfo_ConstPtrWrap<ID{0xa15743fef763d17bu, 0x35436c4559a29f80u}, ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu}> {};

/****************************** pf::B3 END ******************************/

/****************************** pf::B3 START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::B3>() {
    return ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::B3>() {
    return ID{0x1c5f34d949fee916u, 0x6c09a7016a5f4a98u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::B3 &>() {
    return ID{0x2956e4d91940fc4bu, 0xacc6d7dbc030b8b5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::B3 &&>() {
    return ID{0xf5b6b3f6d5e61a0u, 0xbee6ca15f47a9d91u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::B3 &>() {
    return ID{0xdf5ef9813915fdd3u, 0x1f4361105a86a4b8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::B3 *>() {
    return ID{0x55d1e7716633524u, 0xeab125ee05657eb8u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::B3 *>() {
    return ID{0xa15743fef763d17bu, 0x35436c4559a29f80u};
}
/****************************** pf::B3 END ******************************/

/****************************** pf::B3::~B3 START ******************************/
template<>
struct StaticInfo<ID{0x115b1c832b9d7569u, 0x163a50a92d0c318bu}> {
    
    constexpr static ID DestructorID = ID{0x115b1c832b9d7569u, 0x163a50a92d0c318bu};
    constexpr static ID TypeID = ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Destructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static auto IsConstexpr = true;
    constexpr static auto IsConsteval = false;
    constexpr static auto IsVirtual = false;
    constexpr static auto IsPureVirtual = false;

    constexpr static auto Name = StringLiteral{"~B3"};
    constexpr static auto FullName = StringLiteral{"pf::B3::~B3"};
    };

/****************************** pf::A START ******************************/
template<>
struct StaticInfo<ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u}> {
    
    using Type = pf::A;
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 16;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(Attribute{"first", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"second", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"third", std::span<const std::string_view>{EmptyAttributeArgArray}});

    constexpr static auto StaticInfoObjectType = StaticInfoType::RecordType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::A"};

    constexpr static bool IsUnion = false;
    constexpr static bool IsPolymorphic = false;
    constexpr static bool IsAbstract = false;
    constexpr static bool IsFinal = false;
    constexpr static RangeOf<Info> auto Bases = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>(ID{0xd65a217499b928d5u, 0xc2367340748d668eu}, ID{0x57555b6607562e41u, 0xa37e35a1094ff4a2u});
    constexpr static Info Destructor = ID{0x985d28b56ec36af8u, 0x3517760838a68a86u};
    constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>(ID{0x225525f0788858deu, 0x9edf3c90fb14daacu}, ID{0x575fdd108108c3d9u, 0xf4b82162dd7fc096u}, ID{0xb651642ac8c5f237u, 0xfe0f1011e8f1b95u}, ID{0x9f5d7b21263d723fu, 0xc090822c6cd77cb1u}, ID{0xb151275a6f2b5b4bu, 0x932b3500b737d4a6u}, ID{0x3d55f23651de9cbcu, 0x3ec37599fa78fcb3u});
    constexpr static RangeOf<Info> auto StaticFunctions = pf::meta::details::make_array<Info>(ID{0x645f1db97c2f0115u, 0xb3e5baae4a842bb6u});
    constexpr static RangeOf<Info> auto MemberVariables = pf::meta::details::make_array<Info>(ID{0xad56d126355324dbu, 0x30de7f4e0cfbdb95u}, ID{0x335f6f365cea35fdu, 0xab992c0c2c38a8a9u}, ID{0x885025556cce2f68u, 0x589def016d4c20beu}, ID{0xce5e676fefa30dafu, 0x4eb0970230b6a49eu}, ID{0x85a1fc2b7924f35u, 0xab0ea2512267d8adu}, ID{0x8f5f18cfb176f51cu, 0xd2107751b20304bcu});
    constexpr static RangeOf<Info> auto StaticVariables = pf::meta::details::make_array<Info>(ID{0x5353cb42e1a5c7a7u, 0x962a030897c298a4u});
};

// const
template<>
struct StaticInfo<ID{0xed51a6892a08c5b4u, 0x2710ecf40a5944b5u}>
    : StaticInfo_ConstWrap<ID{0xed51a6892a08c5b4u, 0x2710ecf40a5944b5u}, ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u}> {};
// &
template<>
struct StaticInfo<ID{0x46554a96de2d6cdfu, 0x379a235e99f9f8b0u}>
    : StaticInfo_LRefWrap<ID{0x46554a96de2d6cdfu, 0x379a235e99f9f8b0u}, ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u}> {};
// &&
template<>
struct StaticInfo<ID{0x595c066d66e12edcu, 0x976e9022e26d788u}>
    : StaticInfo_RRefWrap<ID{0x595c066d66e12edcu, 0x976e9022e26d788u}, ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u}> {};
// const &
template<>
struct StaticInfo<ID{0x755a6050db5538a4u, 0xdbec077cc9c5cdbdu}>
    : StaticInfo_ConstLRefWrap<ID{0x755a6050db5538a4u, 0xdbec077cc9c5cdbdu}, ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u}> {};
// *
template<>
struct StaticInfo<ID{0xb251737e9c898e9eu, 0x389aa5bd43572286u}>
    : StaticInfo_PtrWrap<ID{0xb251737e9c898e9eu, 0x389aa5bd43572286u}, ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u}> {};
// const *
template<>
struct StaticInfo<ID{0x15585d55c434fd12u, 0xb437a217985b4187u}>
    : StaticInfo_ConstPtrWrap<ID{0x15585d55c434fd12u, 0xb437a217985b4187u}, ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u}> {};

/****************************** pf::A END ******************************/

/****************************** pf::A START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<pf::A>() {
    return ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::A>() {
    return ID{0xed51a6892a08c5b4u, 0x2710ecf40a5944b5u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::A &>() {
    return ID{0x46554a96de2d6cdfu, 0x379a235e99f9f8b0u};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::A &&>() {
    return ID{0x595c066d66e12edcu, 0x976e9022e26d788u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::A &>() {
    return ID{0x755a6050db5538a4u, 0xdbec077cc9c5cdbdu};
}
template<>
[[nodiscard]] consteval ID getTypeId<pf::A *>() {
    return ID{0xb251737e9c898e9eu, 0x389aa5bd43572286u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const pf::A *>() {
    return ID{0x15585d55c434fd12u, 0xb437a217985b4187u};
}
/****************************** pf::A END ******************************/

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0x3c5fe57608a0dab3u, 0x342fbdc95d8d41a7u}> {
    
    constexpr static ID ArgumentID = ID{0x3c5fe57608a0dab3u, 0x342fbdc95d8d41a7u};
    constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 17;
    constexpr static std::uint64_t SourceColumn = 11;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::A::A START ******************************/
template<>
struct StaticInfo<ID{0xd65a217499b928d5u, 0xc2367340748d668eu}> {
    
    constexpr static ID ConstructorID = ID{0xd65a217499b928d5u, 0xc2367340748d668eu};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 17;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsExplicit = false;
    constexpr static bool IsCopy = false;
    constexpr static bool IsMove = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::A::A"};

    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x3c5fe57608a0dab3u, 0x342fbdc95d8d41a7u});

    constexpr static auto CtorWrap = [](int arg_0) -> pf::A { return pf::A(arg_0); };
    constexpr static auto PlacementNewCtorWrap = [](void *dest, int arg_0) -> pf::A* { return new (dest)pf::A(arg_0); };
    constexpr static auto NewCtorWrap = [](int arg_0) -> pf::A* { return new pf::A(arg_0); };
    };

/****************************** sadfsdf START ******************************/
template<>
struct StaticInfo<ID{0x985c8105384db190u, 0x78c31fee58a0aca1u}> {
    
    constexpr static ID ArgumentID = ID{0x985c8105384db190u, 0x78c31fee58a0aca1u};
    constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 18;
    constexpr static std::uint64_t SourceColumn = 11;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{"sadfsdf"};
    constexpr static auto FullName = StringLiteral{"sadfsdf"};
    };

/****************************** asdsa START ******************************/
template<>
struct StaticInfo<ID{0xdb580cc5d30c1cd8u, 0xeb635abea5e641a5u}> {
    
    constexpr static ID ArgumentID = ID{0xdb580cc5d30c1cd8u, 0xeb635abea5e641a5u};
    constexpr static ID TypeID = ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 18;
    constexpr static std::uint64_t SourceColumn = 24;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{"asdsa"};
    constexpr static auto FullName = StringLiteral{"asdsa"};
    };

/****************************** pf::A::A START ******************************/
template<>
struct StaticInfo<ID{0x57555b6607562e41u, 0xa37e35a1094ff4a2u}> {
    
    constexpr static ID ConstructorID = ID{0x57555b6607562e41u, 0xa37e35a1094ff4a2u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 18;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsExplicit = false;
    constexpr static bool IsCopy = false;
    constexpr static bool IsMove = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::A::A"};

    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x985c8105384db190u, 0x78c31fee58a0aca1u}, ID{0xdb580cc5d30c1cd8u, 0xeb635abea5e641a5u});

    constexpr static auto CtorWrap = [](int arg_0, float arg_1) -> pf::A { return pf::A(arg_0, arg_1); };
    constexpr static auto PlacementNewCtorWrap = [](void *dest, int arg_0, float arg_1) -> pf::A* { return new (dest)pf::A(arg_0, arg_1); };
    constexpr static auto NewCtorWrap = [](int arg_0, float arg_1) -> pf::A* { return new pf::A(arg_0, arg_1); };
    };

/****************************** pf::A::~A START ******************************/
template<>
struct StaticInfo<ID{0x985d28b56ec36af8u, 0x3517760838a68a86u}> {
    
    constexpr static ID DestructorID = ID{0x985d28b56ec36af8u, 0x3517760838a68a86u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Destructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static auto IsConstexpr = true;
    constexpr static auto IsConsteval = false;
    constexpr static auto IsVirtual = false;
    constexpr static auto IsPureVirtual = false;

    constexpr static auto Name = StringLiteral{"~A"};
    constexpr static auto FullName = StringLiteral{"pf::A::~A"};
    };

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0x25291b5fda86614u, 0x9eb2c6f726dbdabau}> {
    
    constexpr static ID ArgumentID = ID{0x25291b5fda86614u, 0x9eb2c6f726dbdabau};
    constexpr static ID TypeID = ID{0xbb5e42104794c546u, 0x86636ace5d6bbdb7u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 20;
    constexpr static std::uint64_t SourceColumn = 21;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::A::operator= START ******************************/
template<>
struct StaticInfo<ID{0x225525f0788858deu, 0x9edf3c90fb14daacu}> {
    
    constexpr static ID FunctionID = ID{0x225525f0788858deu, 0x9edf3c90fb14daacu};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 20;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsVirtual = false;
    constexpr static bool IsPureVirtual = false;

    constexpr static auto Name = StringLiteral{"operator="};
    constexpr static auto FullName = StringLiteral{"pf::A::operator="};

    constexpr static Info ReturnType = ID{0x7d587451d13fe0e7u, 0xc033b6fb12bb2a8cu};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x25291b5fda86614u, 0x9eb2c6f726dbdabau});

    constexpr static A &(pf::A::*MemberPtr)(const A &) = &pf::A::operator=;
    };

/****************************** dzea START ******************************/
template<>
struct StaticInfo<ID{0x285fa243136a2539u, 0xd92a9fbd3c821b8u}> {
    struct details {
constexpr static auto ArgArray_7994442885555759611 = pf::meta::details::make_array<std::string_view>(R"arg(dzea)arg", R"arg(dzea2)arg");
};
    constexpr static ID ArgumentID = ID{0x285fa243136a2539u, 0xd92a9fbd3c821b8u};
    constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 59;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(Attribute{"letadlo", std::span<const std::string_view>{details::ArgArray_7994442885555759611}});

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{"dzea"};
    constexpr static auto FullName = StringLiteral{"dzea"};
    };

/****************************** A START ******************************/
template<>
struct StaticInfo<ID{0x505f49fe2f26ad62u, 0x466eafc2e33858a3u}> {
    
    constexpr static ID ArgumentID = ID{0x505f49fe2f26ad62u, 0x466eafc2e33858a3u};
    constexpr static ID TypeID = ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 85;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(Attribute{"yuh", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"yuh2", std::span<const std::string_view>{EmptyAttributeArgArray}});

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"A"};
    };

/****************************** pf::A::foo START ******************************/
template<>
struct StaticInfo<ID{0x575fdd108108c3d9u, 0xf4b82162dd7fc096u}> {
    struct details {
constexpr static auto ArgArray_2805322761694403999 = pf::meta::details::make_array<std::string_view>(R"arg(dzea)arg", R"arg(dzea2)arg");
};
    constexpr static ID FunctionID = ID{0x575fdd108108c3d9u, 0xf4b82162dd7fc096u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 26;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(Attribute{"maybe_unused", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"letadlo", std::span<const std::string_view>{details::ArgArray_2805322761694403999}}, Attribute{"yuh", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"yuh2", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"kjhnn", std::span<const std::string_view>{EmptyAttributeArgArray}});

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsVirtual = false;
    constexpr static bool IsPureVirtual = false;

    constexpr static auto Name = StringLiteral{"foo"};
    constexpr static auto FullName = StringLiteral{"pf::A::foo"};

    constexpr static Info ReturnType = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x285fa243136a2539u, 0xd92a9fbd3c821b8u}, ID{0x505f49fe2f26ad62u, 0x466eafc2e33858a3u});

    constexpr static int(pf::A::*MemberPtr)(int, float) = &pf::A::foo;
    };

/****************************** dzea2 START ******************************/
template<>
struct StaticInfo<ID{0xa65963f0f043d5c8u, 0x8c4c551f4f92f2b6u}> {
    
    constexpr static ID ArgumentID = ID{0xa65963f0f043d5c8u, 0x8c4c551f4f92f2b6u};
    constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 49;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(Attribute{"letadlo", std::span<const std::string_view>{EmptyAttributeArgArray}});

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{"dzea2"};
    constexpr static auto FullName = StringLiteral{"dzea2"};
    };

/****************************** pf::A::foo2 START ******************************/
template<>
struct StaticInfo<ID{0xb651642ac8c5f237u, 0xfe0f1011e8f1b95u}> {
    
    constexpr static ID FunctionID = ID{0xb651642ac8c5f237u, 0xfe0f1011e8f1b95u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 26;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(Attribute{"maybe_unused", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"letadlo", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"kjhnn", std::span<const std::string_view>{EmptyAttributeArgArray}});

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsVirtual = false;
    constexpr static bool IsPureVirtual = false;

    constexpr static auto Name = StringLiteral{"foo2"};
    constexpr static auto FullName = StringLiteral{"pf::A::foo2"};

    constexpr static Info ReturnType = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0xa65963f0f043d5c8u, 0x8c4c551f4f92f2b6u});

    constexpr static int(pf::A::*MemberPtr)(int) = &pf::A::foo2;
    };

/****************************** pf::A::letadlo START ******************************/
template<>
struct StaticInfo<ID{0x9f5d7b21263d723fu, 0xc090822c6cd77cb1u}> {
    
    constexpr static ID FunctionID = ID{0x9f5d7b21263d723fu, 0xc090822c6cd77cb1u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 33;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

    constexpr static bool IsPublic = false;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = true;
    constexpr static bool IsConst = false;
    constexpr static bool IsVirtual = false;
    constexpr static bool IsPureVirtual = false;

    constexpr static auto Name = StringLiteral{"letadlo"};
    constexpr static auto FullName = StringLiteral{"pf::A::letadlo"};

    constexpr static Info ReturnType = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();

    constexpr static int(pf::A::*MemberPtr)() = &pf::A::letadlo;
    };

/****************************** pf::A::letadlo2 START ******************************/
template<>
struct StaticInfo<ID{0xb151275a6f2b5b4bu, 0x932b3500b737d4a6u}> {
    
    constexpr static ID FunctionID = ID{0xb151275a6f2b5b4bu, 0x932b3500b737d4a6u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 36;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

    constexpr static bool IsPublic = false;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = true;
    constexpr static bool IsConst = false;
    constexpr static bool IsVirtual = false;
    constexpr static bool IsPureVirtual = false;

    constexpr static auto Name = StringLiteral{"letadlo2"};
    constexpr static auto FullName = StringLiteral{"pf::A::letadlo2"};

    constexpr static Info ReturnType = ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();

    constexpr static void(pf::A::*MemberPtr)() = &pf::A::letadlo2;
    };

/****************************** asdasdas START ******************************/
template<>
struct StaticInfo<ID{0x50a224288b61b5u, 0x702d04c0a935d1a1u}> {
    
    constexpr static ID ArgumentID = ID{0x50a224288b61b5u, 0x702d04c0a935d1a1u};
    constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 37;
    constexpr static std::uint64_t SourceColumn = 23;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{"asdasdas"};
    constexpr static auto FullName = StringLiteral{"asdasdas"};
    };

/****************************** pf::A::letadlo3 START ******************************/
template<>
struct StaticInfo<ID{0x3d55f23651de9cbcu, 0x3ec37599fa78fcb3u}> {
    
    constexpr static ID FunctionID = ID{0x3d55f23651de9cbcu, 0x3ec37599fa78fcb3u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 37;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

    constexpr static bool IsPublic = false;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = true;
    constexpr static bool IsConst = false;
    constexpr static bool IsVirtual = false;
    constexpr static bool IsPureVirtual = false;

    constexpr static auto Name = StringLiteral{"letadlo3"};
    constexpr static auto FullName = StringLiteral{"pf::A::letadlo3"};

    constexpr static Info ReturnType = ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x50a224288b61b5u, 0x702d04c0a935d1a1u});

    constexpr static void(pf::A::*MemberPtr)(int) = &pf::A::letadlo3;
    };

/****************************** pf::A::c START ******************************/
template<>
struct StaticInfo<ID{0xad56d126355324dbu, 0x30de7f4e0cfbdb95u}> {
    
    constexpr static ID VariableID = ID{0xad56d126355324dbu, 0x30de7f4e0cfbdb95u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 35;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(Attribute{"yeet", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"maybe_unused", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"cxvxc", std::span<const std::string_view>{EmptyAttributeArgArray}});

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsMutable = false;

    constexpr static auto Name = StringLiteral{"c"};
    constexpr static auto FullName = StringLiteral{"pf::A::c"};

    constexpr static int pf::A::* MemberPtr = &pf::A::c;
    };

/****************************** pf::A::test START ******************************/
template<>
struct StaticInfo<ID{0x335f6f365cea35fdu, 0xab992c0c2c38a8a9u}> {
    
    constexpr static ID VariableID = ID{0x335f6f365cea35fdu, 0xab992c0c2c38a8a9u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 30;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsMutable = false;

    constexpr static auto Name = StringLiteral{"test"};
    constexpr static auto FullName = StringLiteral{"pf::A::test"};

    constexpr static int pf::A::* MemberPtr = &pf::A::test;
    };

/****************************** pf::A::privateVar START ******************************/
template<>
struct StaticInfo<ID{0x885025556cce2f68u, 0x589def016d4c20beu}> {
    
    constexpr static ID VariableID = ID{0x885025556cce2f68u, 0x589def016d4c20beu};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 39;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

    constexpr static bool IsPublic = false;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = true;
    constexpr static bool IsMutable = false;

    constexpr static auto Name = StringLiteral{"privateVar"};
    constexpr static auto FullName = StringLiteral{"pf::A::privateVar"};

    constexpr static int pf::A::* MemberPtr = &pf::A::privateVar;
    };

/****************************** pf::A::privateVar2 START ******************************/
template<>
struct StaticInfo<ID{0xce5e676fefa30dafu, 0x4eb0970230b6a49eu}> {
    
    constexpr static ID VariableID = ID{0xce5e676fefa30dafu, 0x4eb0970230b6a49eu};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 40;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

    constexpr static bool IsPublic = false;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = true;
    constexpr static bool IsMutable = false;

    constexpr static auto Name = StringLiteral{"privateVar2"};
    constexpr static auto FullName = StringLiteral{"pf::A::privateVar2"};

    constexpr static int pf::A::* MemberPtr = &pf::A::privateVar2;
    };

/****************************** pf::A::privateVar3 START ******************************/
template<>
struct StaticInfo<ID{0x85a1fc2b7924f35u, 0xab0ea2512267d8adu}> {
    
    constexpr static ID VariableID = ID{0x85a1fc2b7924f35u, 0xab0ea2512267d8adu};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 41;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

    constexpr static bool IsPublic = false;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = true;
    constexpr static bool IsMutable = false;

    constexpr static auto Name = StringLiteral{"privateVar3"};
    constexpr static auto FullName = StringLiteral{"pf::A::privateVar3"};

    constexpr static int pf::A::* MemberPtr = &pf::A::privateVar3;
    };

/****************************** pf::A::privateVar4 START ******************************/
template<>
struct StaticInfo<ID{0x8f5f18cfb176f51cu, 0xd2107751b20304bcu}> {
    
    constexpr static ID VariableID = ID{0x8f5f18cfb176f51cu, 0xd2107751b20304bcu};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 42;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

    constexpr static bool IsPublic = false;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = true;
    constexpr static bool IsMutable = false;

    constexpr static auto Name = StringLiteral{"privateVar4"};
    constexpr static auto FullName = StringLiteral{"pf::A::privateVar4"};

    constexpr static int pf::A::* MemberPtr = &pf::A::privateVar4;
    };

/****************************** pf::A::statFoo START ******************************/
template<>
struct StaticInfo<ID{0x645f1db97c2f0115u, 0xb3e5baae4a842bb6u}> {
    
    constexpr static ID FunctionID = ID{0x645f1db97c2f0115u, 0xb3e5baae4a842bb6u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 44;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::StaticFunction;

    constexpr static bool IsPublic = false;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = true;

    constexpr static auto Name = StringLiteral{"statFoo"};
    constexpr static auto FullName = StringLiteral{"pf::A::statFoo"};

    constexpr static Info ReturnType = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();

    constexpr static int(*MemberPtr)() = &pf::A::statFoo;
    };

/****************************** pf::A::statValue START ******************************/
template<>
struct StaticInfo<ID{0x5353cb42e1a5c7a7u, 0x962a030897c298a4u}> {
    
    constexpr static ID VariableID = ID{0x5353cb42e1a5c7a7u, 0x962a030897c298a4u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 45;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::StaticVariable;

    constexpr static bool IsPublic = false;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = true;

    constexpr static auto Name = StringLiteral{"statValue"};
    constexpr static auto FullName = StringLiteral{"pf::A::statValue"};

    constexpr static int* MemberPtr = &pf::A::statValue;
    };

}
