
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
    constexpr static std::uint64_t SourceLine = 8;
    constexpr static std::uint64_t SourceColumn = 92;

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
    constexpr static std::uint64_t SourceLine = 8;
    constexpr static std::uint64_t SourceColumn = 138;

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
constexpr static auto ArgArray_5196238426359288975 = pf::meta::details::make_array<std::string_view>(R"arg(()()()((())))arg", R"arg([[nodiscard]])arg", R"arg(1ll)arg", R"arg(1.011)arg", R"arg([]{}())arg", R"arg("yeet")arg", R"arg('a')arg", R"arg([][][]:::3214234...[][][][])arg");
constexpr static auto ArgArray_16470058561975011503 = pf::meta::details::make_array<std::string_view>(R"arg(1ll)arg", R"arg(1.011)arg", R"arg("yeet")arg");
};
    using Type = pf::SomeEnum;
    constexpr static ID TypeID = ID{0x2b53af1c1cf57f8au, 0xe97917064d8b3696u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 7;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(Attribute{"pf::operators", std::span<const std::string_view>{details::ArgArray_5196238426359288975}}, Attribute{"pf::hihi", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"pf::operators2", std::span<const std::string_view>{details::ArgArray_16470058561975011503}}, Attribute{"pf::hihi2", std::span<const std::string_view>{EmptyAttributeArgArray}});

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
    constexpr static std::uint64_t SourceLine = 10;
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
    constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>(ID{0x4c5099a918422ab8u, 0x9225b6a2eee64fbdu}, ID{0x525fa1bd260b57d7u, 0x442af4f18a3c0cb4u}, ID{0x7a5f0a3ff95f45e2u, 0x62487939857bdfa0u});
    constexpr static Info Destructor = ID{0xd552f19eae53efa9u, 0xdb1981450a58b4b9u};
    constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>(ID{0x5c59a5443ba13b2cu, 0x8432598bcc44efa6u}, ID{0x6a5cd1ccade9ee8cu, 0xcfeb33667c00b491u});
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

/****************************** pf::B1::B1 START ******************************/
template<>
struct StaticInfo<ID{0x4c5099a918422ab8u, 0x9225b6a2eee64fbdu}> {
    
    constexpr static ID ConstructorID = ID{0x4c5099a918422ab8u, 0x9225b6a2eee64fbdu};
    constexpr static ID TypeID = ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsExplicit = false;
    constexpr static bool IsCopy = false;
    constexpr static bool IsMove = false;

    constexpr static auto Name = StringLiteral{"B1"};
    constexpr static auto FullName = StringLiteral{"pf::B1::B1"};

    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();
    };

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0x8756b596792654abu, 0x59269ae9f7c9bba1u}> {
    
    constexpr static ID ArgumentID = ID{0x8756b596792654abu, 0x59269ae9f7c9bba1u};
    constexpr static ID TypeID = ID{0x135f2193a7f32297u, 0x1793cae763d8bb7u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::B1::B1 START ******************************/
template<>
struct StaticInfo<ID{0x525fa1bd260b57d7u, 0x442af4f18a3c0cb4u}> {
    
    constexpr static ID ConstructorID = ID{0x525fa1bd260b57d7u, 0x442af4f18a3c0cb4u};
    constexpr static ID TypeID = ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsExplicit = false;
    constexpr static bool IsCopy = true;
    constexpr static bool IsMove = false;

    constexpr static auto Name = StringLiteral{"B1"};
    constexpr static auto FullName = StringLiteral{"pf::B1::B1"};

    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x8756b596792654abu, 0x59269ae9f7c9bba1u});
    };

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0xf7527d368a479349u, 0x96fd5309ad5d76bau}> {
    
    constexpr static ID ArgumentID = ID{0xf7527d368a479349u, 0x96fd5309ad5d76bau};
    constexpr static ID TypeID = ID{0xbd5574634741c644u, 0xd215026848538aacu};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::B1::B1 START ******************************/
template<>
struct StaticInfo<ID{0x7a5f0a3ff95f45e2u, 0x62487939857bdfa0u}> {
    
    constexpr static ID ConstructorID = ID{0x7a5f0a3ff95f45e2u, 0x62487939857bdfa0u};
    constexpr static ID TypeID = ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsExplicit = false;
    constexpr static bool IsCopy = false;
    constexpr static bool IsMove = true;

    constexpr static auto Name = StringLiteral{"B1"};
    constexpr static auto FullName = StringLiteral{"pf::B1::B1"};

    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0xf7527d368a479349u, 0x96fd5309ad5d76bau});
    };

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

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0x535fec2e762aaa45u, 0x6e1892ab0499189cu}> {
    
    constexpr static ID ArgumentID = ID{0x535fec2e762aaa45u, 0x6e1892ab0499189cu};
    constexpr static ID TypeID = ID{0x135f2193a7f32297u, 0x1793cae763d8bb7u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::B1::operator= START ******************************/
template<>
struct StaticInfo<ID{0x5c59a5443ba13b2cu, 0x8432598bcc44efa6u}> {
    
    constexpr static ID FunctionID = ID{0x5c59a5443ba13b2cu, 0x8432598bcc44efa6u};
    constexpr static ID TypeID = ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsVirtual = false;
    constexpr static bool IsPureVirtual = false;

    constexpr static auto Name = StringLiteral{"operator="};
    constexpr static auto FullName = StringLiteral{"pf::B1::operator="};

    constexpr static Info ReturnType = ID{0x8257aef84cd505f5u, 0x8e7520928795e8bau};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x535fec2e762aaa45u, 0x6e1892ab0499189cu});
    };

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0xe5714136f37e08du, 0x7a9d4cee92cf52b7u}> {
    
    constexpr static ID ArgumentID = ID{0xe5714136f37e08du, 0x7a9d4cee92cf52b7u};
    constexpr static ID TypeID = ID{0xbd5574634741c644u, 0xd215026848538aacu};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::B1::operator= START ******************************/
template<>
struct StaticInfo<ID{0x6a5cd1ccade9ee8cu, 0xcfeb33667c00b491u}> {
    
    constexpr static ID FunctionID = ID{0x6a5cd1ccade9ee8cu, 0xcfeb33667c00b491u};
    constexpr static ID TypeID = ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsVirtual = false;
    constexpr static bool IsPureVirtual = false;

    constexpr static auto Name = StringLiteral{"operator="};
    constexpr static auto FullName = StringLiteral{"pf::B1::operator="};

    constexpr static Info ReturnType = ID{0x8257aef84cd505f5u, 0x8e7520928795e8bau};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0xe5714136f37e08du, 0x7a9d4cee92cf52b7u});
    };

/****************************** pf::B2 START ******************************/
template<>
struct StaticInfo<ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u}> {
    
    using Type = pf::B2;
    constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 11;
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
    constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>(ID{0xf7527360fc6ada92u, 0xa4133785a1400e82u}, ID{0x685469dc31b707f6u, 0x78b4825c990b0288u}, ID{0x935fef5590e21123u, 0xda400d0c1bd7ca8fu});
    constexpr static Info Destructor = ID{0x75598d2a0e986fadu, 0x24bfa1eb9392f7a5u};
    constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>(ID{0x95ec7e6b4ddbb14u, 0xaa6219a2b0fe3786u}, ID{0x655223907c172ddu, 0xc1546dc0af539590u});
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

/****************************** pf::B2::B2 START ******************************/
template<>
struct StaticInfo<ID{0xf7527360fc6ada92u, 0xa4133785a1400e82u}> {
    
    constexpr static ID ConstructorID = ID{0xf7527360fc6ada92u, 0xa4133785a1400e82u};
    constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsExplicit = false;
    constexpr static bool IsCopy = false;
    constexpr static bool IsMove = false;

    constexpr static auto Name = StringLiteral{"B2"};
    constexpr static auto FullName = StringLiteral{"pf::B2::B2"};

    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();
    };

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0x3c573e202da62f9au, 0x4c1579986dbd80abu}> {
    
    constexpr static ID ArgumentID = ID{0x3c573e202da62f9au, 0x4c1579986dbd80abu};
    constexpr static ID TypeID = ID{0x3c5db803dc8b766cu, 0x6122e33c50d5d981u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::B2::B2 START ******************************/
template<>
struct StaticInfo<ID{0x685469dc31b707f6u, 0x78b4825c990b0288u}> {
    
    constexpr static ID ConstructorID = ID{0x685469dc31b707f6u, 0x78b4825c990b0288u};
    constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsExplicit = false;
    constexpr static bool IsCopy = true;
    constexpr static bool IsMove = false;

    constexpr static auto Name = StringLiteral{"B2"};
    constexpr static auto FullName = StringLiteral{"pf::B2::B2"};

    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x3c573e202da62f9au, 0x4c1579986dbd80abu});
    };

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0x555a8a3d5cfad84bu, 0x788e511d4394a690u}> {
    
    constexpr static ID ArgumentID = ID{0x555a8a3d5cfad84bu, 0x788e511d4394a690u};
    constexpr static ID TypeID = ID{0x4c52c786c5322447u, 0x271a6e9107fe13abu};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::B2::B2 START ******************************/
template<>
struct StaticInfo<ID{0x935fef5590e21123u, 0xda400d0c1bd7ca8fu}> {
    
    constexpr static ID ConstructorID = ID{0x935fef5590e21123u, 0xda400d0c1bd7ca8fu};
    constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsExplicit = false;
    constexpr static bool IsCopy = false;
    constexpr static bool IsMove = true;

    constexpr static auto Name = StringLiteral{"B2"};
    constexpr static auto FullName = StringLiteral{"pf::B2::B2"};

    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x555a8a3d5cfad84bu, 0x788e511d4394a690u});
    };

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

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0xdd585974e172013bu, 0xe44cea9fa1185ea1u}> {
    
    constexpr static ID ArgumentID = ID{0xdd585974e172013bu, 0xe44cea9fa1185ea1u};
    constexpr static ID TypeID = ID{0x3c5db803dc8b766cu, 0x6122e33c50d5d981u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::B2::operator= START ******************************/
template<>
struct StaticInfo<ID{0x95ec7e6b4ddbb14u, 0xaa6219a2b0fe3786u}> {
    
    constexpr static ID FunctionID = ID{0x95ec7e6b4ddbb14u, 0xaa6219a2b0fe3786u};
    constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsVirtual = false;
    constexpr static bool IsPureVirtual = false;

    constexpr static auto Name = StringLiteral{"operator="};
    constexpr static auto FullName = StringLiteral{"pf::B2::operator="};

    constexpr static Info ReturnType = ID{0x755e9eb5eb455adbu, 0xe9a1040b691c9a80u};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0xdd585974e172013bu, 0xe44cea9fa1185ea1u});
    };

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0x315ea76717b0367du, 0x8369f901596d00b9u}> {
    
    constexpr static ID ArgumentID = ID{0x315ea76717b0367du, 0x8369f901596d00b9u};
    constexpr static ID TypeID = ID{0x4c52c786c5322447u, 0x271a6e9107fe13abu};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::B2::operator= START ******************************/
template<>
struct StaticInfo<ID{0x655223907c172ddu, 0xc1546dc0af539590u}> {
    
    constexpr static ID FunctionID = ID{0x655223907c172ddu, 0xc1546dc0af539590u};
    constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsVirtual = false;
    constexpr static bool IsPureVirtual = false;

    constexpr static auto Name = StringLiteral{"operator="};
    constexpr static auto FullName = StringLiteral{"pf::B2::operator="};

    constexpr static Info ReturnType = ID{0x755e9eb5eb455adbu, 0xe9a1040b691c9a80u};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x315ea76717b0367du, 0x8369f901596d00b9u});
    };

/****************************** pf::B3 START ******************************/
template<>
struct StaticInfo<ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu}> {
    
    using Type = pf::B3;
    constexpr static ID TypeID = ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 12;
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
    constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>(ID{0x9158d51e7c91adbbu, 0xcdaeb1cb5d6ea09fu}, ID{0xeb5ad68803c19d00u, 0xc2cac12f408b0d9eu}, ID{0xf6549261f2c6b63cu, 0x5461943e697ce094u});
    constexpr static Info Destructor = ID{0x115b1c832b9d7569u, 0x163a50a92d0c318bu};
    constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>(ID{0xbd5c990df4a4e368u, 0xe8df461d8d5a94a7u}, ID{0x1d550c59e6f18116u, 0x34e5a7f5d8c2839eu});
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

/****************************** pf::B3::B3 START ******************************/
template<>
struct StaticInfo<ID{0x9158d51e7c91adbbu, 0xcdaeb1cb5d6ea09fu}> {
    
    constexpr static ID ConstructorID = ID{0x9158d51e7c91adbbu, 0xcdaeb1cb5d6ea09fu};
    constexpr static ID TypeID = ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsExplicit = false;
    constexpr static bool IsCopy = false;
    constexpr static bool IsMove = false;

    constexpr static auto Name = StringLiteral{"B3"};
    constexpr static auto FullName = StringLiteral{"pf::B3::B3"};

    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();
    };

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0x4e57b40fbb50cbf5u, 0x905421dc39f42899u}> {
    
    constexpr static ID ArgumentID = ID{0x4e57b40fbb50cbf5u, 0x905421dc39f42899u};
    constexpr static ID TypeID = ID{0xdf5ef9813915fdd3u, 0x1f4361105a86a4b8u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::B3::B3 START ******************************/
template<>
struct StaticInfo<ID{0xeb5ad68803c19d00u, 0xc2cac12f408b0d9eu}> {
    
    constexpr static ID ConstructorID = ID{0xeb5ad68803c19d00u, 0xc2cac12f408b0d9eu};
    constexpr static ID TypeID = ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsExplicit = false;
    constexpr static bool IsCopy = true;
    constexpr static bool IsMove = false;

    constexpr static auto Name = StringLiteral{"B3"};
    constexpr static auto FullName = StringLiteral{"pf::B3::B3"};

    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x4e57b40fbb50cbf5u, 0x905421dc39f42899u});
    };

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0x8151bf9246f9401cu, 0x56012d14b2dfcbbau}> {
    
    constexpr static ID ArgumentID = ID{0x8151bf9246f9401cu, 0x56012d14b2dfcbbau};
    constexpr static ID TypeID = ID{0xf5b6b3f6d5e61a0u, 0xbee6ca15f47a9d91u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::B3::B3 START ******************************/
template<>
struct StaticInfo<ID{0xf6549261f2c6b63cu, 0x5461943e697ce094u}> {
    
    constexpr static ID ConstructorID = ID{0xf6549261f2c6b63cu, 0x5461943e697ce094u};
    constexpr static ID TypeID = ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsExplicit = false;
    constexpr static bool IsCopy = false;
    constexpr static bool IsMove = true;

    constexpr static auto Name = StringLiteral{"B3"};
    constexpr static auto FullName = StringLiteral{"pf::B3::B3"};

    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x8151bf9246f9401cu, 0x56012d14b2dfcbbau});
    };

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

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0x6955af43f7d98c68u, 0x265d46dda6d37185u}> {
    
    constexpr static ID ArgumentID = ID{0x6955af43f7d98c68u, 0x265d46dda6d37185u};
    constexpr static ID TypeID = ID{0xdf5ef9813915fdd3u, 0x1f4361105a86a4b8u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::B3::operator= START ******************************/
template<>
struct StaticInfo<ID{0xbd5c990df4a4e368u, 0xe8df461d8d5a94a7u}> {
    
    constexpr static ID FunctionID = ID{0xbd5c990df4a4e368u, 0xe8df461d8d5a94a7u};
    constexpr static ID TypeID = ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsVirtual = false;
    constexpr static bool IsPureVirtual = false;

    constexpr static auto Name = StringLiteral{"operator="};
    constexpr static auto FullName = StringLiteral{"pf::B3::operator="};

    constexpr static Info ReturnType = ID{0x2956e4d91940fc4bu, 0xacc6d7dbc030b8b5u};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x6955af43f7d98c68u, 0x265d46dda6d37185u});
    };

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0x735fb1ee316c9b5eu, 0xf93498e83d1421adu}> {
    
    constexpr static ID ArgumentID = ID{0x735fb1ee316c9b5eu, 0xf93498e83d1421adu};
    constexpr static ID TypeID = ID{0xf5b6b3f6d5e61a0u, 0xbee6ca15f47a9d91u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::B3::operator= START ******************************/
template<>
struct StaticInfo<ID{0x1d550c59e6f18116u, 0x34e5a7f5d8c2839eu}> {
    
    constexpr static ID FunctionID = ID{0x1d550c59e6f18116u, 0x34e5a7f5d8c2839eu};
    constexpr static ID TypeID = ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsVirtual = false;
    constexpr static bool IsPureVirtual = false;

    constexpr static auto Name = StringLiteral{"operator="};
    constexpr static auto FullName = StringLiteral{"pf::B3::operator="};

    constexpr static Info ReturnType = ID{0x2956e4d91940fc4bu, 0xacc6d7dbc030b8b5u};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x735fb1ee316c9b5eu, 0xf93498e83d1421adu});
    };

/****************************** pf::A START ******************************/
template<>
struct StaticInfo<ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u}> {
    
    using Type = pf::A;
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 14;
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
    constexpr static RangeOf<Info> auto Bases = pf::meta::details::make_array<Info>(ID{0x925a379bde23315eu, 0x48e00dcbb6b17ea7u}, ID{0x3a589977fc087aefu, 0x1dfe9dbc187d6bb2u}, ID{0x5358aab1d01f14d9u, 0xacf43a2903663a80u});
    constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>(ID{0xf597eea5e1760bfu, 0x797c08db90791d84u}, ID{0xfa5eaad11a25c310u, 0xa28f58c34a8f1693u}, ID{0x3e5c3e84c9e03aedu, 0x2f42cd80102f588fu});
    constexpr static Info Destructor = ID{0x985d28b56ec36af8u, 0x3517760838a68a86u};
    constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>(ID{0x575fdd108108c3d9u, 0xf4b82162dd7fc096u}, ID{0xb651642ac8c5f237u, 0xfe0f1011e8f1b95u}, ID{0x9f5d7b21263d723fu, 0xc090822c6cd77cb1u}, ID{0xb151275a6f2b5b4bu, 0x932b3500b737d4a6u}, ID{0x3d55f23651de9cbcu, 0x3ec37599fa78fcb3u}, ID{0xd0502bcdb175a17fu, 0xb65cd85322939c8cu}, ID{0x7d5d6b0a401b9a2fu, 0x9dbfd30788a427a4u});
    constexpr static RangeOf<Info> auto StaticFunctions = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto MemberVariables = pf::meta::details::make_array<Info>(ID{0xad56d126355324dbu, 0x30de7f4e0cfbdb95u});
    constexpr static RangeOf<Info> auto StaticVariables = pf::meta::details::make_array<Info>();
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

/****************************** pf::B1 START ******************************/
template<>
struct StaticInfo<ID{0x925a379bde23315eu, 0x48e00dcbb6b17ea7u}> {
    
    constexpr static ID BaseID = ID{0x925a379bde23315eu, 0x48e00dcbb6b17ea7u};
    constexpr static ID TypeID = ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 14;
    constexpr static std::uint64_t SourceColumn = 45;

    constexpr static auto StaticInfoObjectType = StaticInfoType::Base;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static auto IsVirtual = false;

    constexpr static auto Name = StringLiteral{"B1"};
    constexpr static auto FullName = StringLiteral{"pf::B1"};
    };

/****************************** pf::B2 START ******************************/
template<>
struct StaticInfo<ID{0x3a589977fc087aefu, 0x1dfe9dbc187d6bb2u}> {
    
    constexpr static ID BaseID = ID{0x3a589977fc087aefu, 0x1dfe9dbc187d6bb2u};
    constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 14;
    constexpr static std::uint64_t SourceColumn = 49;

    constexpr static auto StaticInfoObjectType = StaticInfoType::Base;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static auto IsVirtual = false;

    constexpr static auto Name = StringLiteral{"B2"};
    constexpr static auto FullName = StringLiteral{"pf::B2"};
    };

/****************************** pf::B3 START ******************************/
template<>
struct StaticInfo<ID{0x5358aab1d01f14d9u, 0xacf43a2903663a80u}> {
    
    constexpr static ID BaseID = ID{0x5358aab1d01f14d9u, 0xacf43a2903663a80u};
    constexpr static ID TypeID = ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 14;
    constexpr static std::uint64_t SourceColumn = 53;

    constexpr static auto StaticInfoObjectType = StaticInfoType::Base;

    constexpr static bool IsPublic = false;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = true;
    constexpr static auto IsVirtual = false;

    constexpr static auto Name = StringLiteral{"B3"};
    constexpr static auto FullName = StringLiteral{"pf::B3"};
    };

/****************************** pf::A::A START ******************************/
template<>
struct StaticInfo<ID{0xf597eea5e1760bfu, 0x797c08db90791d84u}> {
    
    constexpr static ID ConstructorID = ID{0xf597eea5e1760bfu, 0x797c08db90791d84u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

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

    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();
    };

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0xd55d261b5b8d2a6fu, 0xb6c548bc0f958193u}> {
    
    constexpr static ID ArgumentID = ID{0xd55d261b5b8d2a6fu, 0xb6c548bc0f958193u};
    constexpr static ID TypeID = ID{0x755a6050db5538a4u, 0xdbec077cc9c5cdbdu};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::A::A START ******************************/
template<>
struct StaticInfo<ID{0xfa5eaad11a25c310u, 0xa28f58c34a8f1693u}> {
    
    constexpr static ID ConstructorID = ID{0xfa5eaad11a25c310u, 0xa28f58c34a8f1693u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsExplicit = false;
    constexpr static bool IsCopy = true;
    constexpr static bool IsMove = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::A::A"};

    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0xd55d261b5b8d2a6fu, 0xb6c548bc0f958193u});
    };

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0xf250d762f195fb11u, 0x8de1477f57ca1adu}> {
    
    constexpr static ID ArgumentID = ID{0xf250d762f195fb11u, 0x8de1477f57ca1adu};
    constexpr static ID TypeID = ID{0x595c066d66e12edcu, 0x976e9022e26d788u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::A::A START ******************************/
template<>
struct StaticInfo<ID{0x3e5c3e84c9e03aedu, 0x2f42cd80102f588fu}> {
    
    constexpr static ID ConstructorID = ID{0x3e5c3e84c9e03aedu, 0x2f42cd80102f588fu};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsExplicit = false;
    constexpr static bool IsCopy = false;
    constexpr static bool IsMove = true;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::A::A"};

    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0xf250d762f195fb11u, 0x8de1477f57ca1adu});
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

/****************************** dzea START ******************************/
template<>
struct StaticInfo<ID{0x285fa243136a2539u, 0xd92a9fbd3c821b8u}> {
    struct details {
constexpr static auto ArgArray_13932582296840310768 = pf::meta::details::make_array<std::string_view>(R"arg(dzea)arg", R"arg(dzea2)arg");
};
    constexpr static ID ArgumentID = ID{0x285fa243136a2539u, 0xd92a9fbd3c821b8u};
    constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 59;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(Attribute{"letadlo", std::span<const std::string_view>{details::ArgArray_13932582296840310768}});

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
    constexpr static std::uint64_t SourceLine = 21;
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
constexpr static auto ArgArray_14960776358744734312 = pf::meta::details::make_array<std::string_view>(R"arg(dzea)arg", R"arg(dzea2)arg");
};
    constexpr static ID FunctionID = ID{0x575fdd108108c3d9u, 0xf4b82162dd7fc096u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 26;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(Attribute{"maybe_unused", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"letadlo", std::span<const std::string_view>{details::ArgArray_14960776358744734312}}, Attribute{"yuh", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"yuh2", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"kjhnn", std::span<const std::string_view>{EmptyAttributeArgArray}});

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
    };

/****************************** dzea2 START ******************************/
template<>
struct StaticInfo<ID{0xa65963f0f043d5c8u, 0x8c4c551f4f92f2b6u}> {
    
    constexpr static ID ArgumentID = ID{0xa65963f0f043d5c8u, 0x8c4c551f4f92f2b6u};
    constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 22;
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
    constexpr static std::uint64_t SourceLine = 22;
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
    };

/****************************** pf::A::letadlo START ******************************/
template<>
struct StaticInfo<ID{0x9f5d7b21263d723fu, 0xc090822c6cd77cb1u}> {
    
    constexpr static ID FunctionID = ID{0x9f5d7b21263d723fu, 0xc090822c6cd77cb1u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 27;
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
    };

/****************************** pf::A::letadlo2 START ******************************/
template<>
struct StaticInfo<ID{0xb151275a6f2b5b4bu, 0x932b3500b737d4a6u}> {
    
    constexpr static ID FunctionID = ID{0xb151275a6f2b5b4bu, 0x932b3500b737d4a6u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 30;
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
    };

/****************************** asdasdas START ******************************/
template<>
struct StaticInfo<ID{0x50a224288b61b5u, 0x702d04c0a935d1a1u}> {
    
    constexpr static ID ArgumentID = ID{0x50a224288b61b5u, 0x702d04c0a935d1a1u};
    constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 31;
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
    constexpr static std::uint64_t SourceLine = 31;
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
    };

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0x38570030af11cfa9u, 0x2298ac40a2818bb0u}> {
    
    constexpr static ID ArgumentID = ID{0x38570030af11cfa9u, 0x2298ac40a2818bb0u};
    constexpr static ID TypeID = ID{0x755a6050db5538a4u, 0xdbec077cc9c5cdbdu};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::A::operator= START ******************************/
template<>
struct StaticInfo<ID{0xd0502bcdb175a17fu, 0xb65cd85322939c8cu}> {
    
    constexpr static ID FunctionID = ID{0xd0502bcdb175a17fu, 0xb65cd85322939c8cu};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

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

    constexpr static Info ReturnType = ID{0x46554a96de2d6cdfu, 0x379a235e99f9f8b0u};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x38570030af11cfa9u, 0x2298ac40a2818bb0u});
    };

/******************************  START ******************************/
template<>
struct StaticInfo<ID{0x3852d263242c729du, 0xc57bd620b7fbc1b8u}> {
    
    constexpr static ID ArgumentID = ID{0x3852d263242c729du, 0xc57bd620b7fbc1b8u};
    constexpr static ID TypeID = ID{0x595c066d66e12edcu, 0x976e9022e26d788u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{""};
    constexpr static auto FullName = StringLiteral{""};
    };

/****************************** pf::A::operator= START ******************************/
template<>
struct StaticInfo<ID{0x7d5d6b0a401b9a2fu, 0x9dbfd30788a427a4u}> {
    
    constexpr static ID FunctionID = ID{0x7d5d6b0a401b9a2fu, 0x9dbfd30788a427a4u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(<generated>)path";
    constexpr static std::uint64_t SourceLine = 0;
    constexpr static std::uint64_t SourceColumn = 0;

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

    constexpr static Info ReturnType = ID{0x46554a96de2d6cdfu, 0x379a235e99f9f8b0u};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x3852d263242c729du, 0xc57bd620b7fbc1b8u});
    };

/****************************** pf::A::c START ******************************/
template<>
struct StaticInfo<ID{0xad56d126355324dbu, 0x30de7f4e0cfbdb95u}> {
    
    constexpr static ID VariableID = ID{0xad56d126355324dbu, 0x30de7f4e0cfbdb95u};
    constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
    constexpr static std::uint64_t SourceLine = 20;
    constexpr static std::uint64_t SourceColumn = 35;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(Attribute{"yeet", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"maybe_unused", std::span<const std::string_view>{EmptyAttributeArgArray}}, Attribute{"cxvxc", std::span<const std::string_view>{EmptyAttributeArgArray}});

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsMutable = false;

    constexpr static auto Name = StringLiteral{"c"};
    constexpr static auto FullName = StringLiteral{"pf::A::c"};
    };

}
