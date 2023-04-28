
#pragma once

#include <src/test2.hpp>
#include <meta/details/array.hpp>
#include <meta/details/RangeOf.hpp>
#include <type_traits>
#include <meta/details/StaticInfo.hpp>
#include <meta/details/StaticInfo_Wrappers.hpp>
#include <meta/details/ID.hpp>
#include <meta/Attribute.hpp>
#include <meta/Info.hpp>

namespace pf::meta::details {

/****************************** SimpleStruct START ******************************/
template<>
struct StaticInfo<ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u}> {
    
    using Type = SimpleStruct;
    constexpr static ID TypeID = ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test2.hpp)path";
    constexpr static std::uint64_t SourceLine = 11;
    constexpr static std::uint64_t SourceColumn = 1;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::RecordType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"SimpleStruct"};
    constexpr static auto FullName = StringLiteral{"SimpleStruct"};

    constexpr static bool IsUnion = false;
    constexpr static bool IsClass = false;
    constexpr static bool IsStruct = true;
    constexpr static bool IsPolymorphic = false;
    constexpr static bool IsAbstract = false;
    constexpr static bool IsFinal = false;
    constexpr static RangeOf<Info> auto Bases = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>();
    constexpr static Info Destructor = ID{0x9959c038d505396du, 0x313031533c943cb1u};
    constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>(ID{0x23561358310a0cbeu, 0xebb11a197749f289u});
    constexpr static RangeOf<Info> auto StaticFunctions = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto MemberVariables = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto StaticVariables = pf::meta::details::make_array<Info>();
};

// const
template<>
struct StaticInfo<ID{0x1159e006d36557ffu, 0x227c3e42c255249eu}>
    : StaticInfo_ConstWrap<ID{0x1159e006d36557ffu, 0x227c3e42c255249eu}, ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u}> {};
// &
template<>
struct StaticInfo<ID{0x9850d85949665134u, 0xad59e4fea25cf8eu}>
    : StaticInfo_LRefWrap<ID{0x9850d85949665134u, 0xad59e4fea25cf8eu}, ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u}> {};
// &&
template<>
struct StaticInfo<ID{0xa759768f786da9adu, 0x7fcb849f0a885c9bu}>
    : StaticInfo_RRefWrap<ID{0xa759768f786da9adu, 0x7fcb849f0a885c9bu}, ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u}> {};
// const &
template<>
struct StaticInfo<ID{0x6954e1d515a433f4u, 0x6a57100456c1aaabu}>
    : StaticInfo_ConstLRefWrap<ID{0x6954e1d515a433f4u, 0x6a57100456c1aaabu}, ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u}> {};
// *
template<>
struct StaticInfo<ID{0x1a5e99b4864623d8u, 0xb556a16070162094u}>
    : StaticInfo_PtrWrap<ID{0x1a5e99b4864623d8u, 0xb556a16070162094u}, ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u}> {};
// const *
template<>
struct StaticInfo<ID{0x9752a19bdbed23b1u, 0x423461463d9b5492u}>
    : StaticInfo_ConstPtrWrap<ID{0x9752a19bdbed23b1u, 0x423461463d9b5492u}, ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u}> {};

/****************************** SimpleStruct END ******************************/

/****************************** SimpleStruct START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<SimpleStruct>() {
    return ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const SimpleStruct>() {
    return ID{0x1159e006d36557ffu, 0x227c3e42c255249eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<SimpleStruct &>() {
    return ID{0x9850d85949665134u, 0xad59e4fea25cf8eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<SimpleStruct &&>() {
    return ID{0xa759768f786da9adu, 0x7fcb849f0a885c9bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const SimpleStruct &>() {
    return ID{0x6954e1d515a433f4u, 0x6a57100456c1aaabu};
}
template<>
[[nodiscard]] consteval ID getTypeId<SimpleStruct *>() {
    return ID{0x1a5e99b4864623d8u, 0xb556a16070162094u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const SimpleStruct *>() {
    return ID{0x9752a19bdbed23b1u, 0x423461463d9b5492u};
}
/****************************** SimpleStruct END ******************************/

/****************************** SimpleStruct::~SimpleStruct START ******************************/
template<>
struct StaticInfo<ID{0x9959c038d505396du, 0x313031533c943cb1u}> {
    
    constexpr static ID DestructorID = ID{0x9959c038d505396du, 0x313031533c943cb1u};
    constexpr static ID TypeID = ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u};

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
    constexpr static auto IsFinal = false;

    constexpr static auto Name = StringLiteral{"~SimpleStruct"};
    constexpr static auto FullName = StringLiteral{"SimpleStruct::~SimpleStruct"};
    };

/****************************** SimpleStruct::footadlo START ******************************/
template<>
struct StaticInfo<ID{0x23561358310a0cbeu, 0xebb11a197749f289u}> {
    
    constexpr static ID FunctionID = ID{0x23561358310a0cbeu, 0xebb11a197749f289u};
    constexpr static ID TypeID = ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test2.hpp)path";
    constexpr static std::uint64_t SourceLine = 14;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

    constexpr static bool IsPublic = false;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = true;
    constexpr static bool IsConst = false;
    constexpr static bool IsVirtual = false;
    constexpr static bool IsPureVirtual = false;
    constexpr static auto IsFinal = false;

    constexpr static auto Name = StringLiteral{"footadlo"};
    constexpr static auto FullName = StringLiteral{"SimpleStruct::footadlo"};

    constexpr static Info ReturnType = ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();

    constexpr static void(SimpleStruct::*MemberPtr)() = &SimpleStruct::footadlo;
    };

}
