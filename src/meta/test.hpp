
#pragma once

#include <meta/Attribute.hpp>
#include <meta/Info.hpp>
#include <meta/details/ID.hpp>
#include <meta/details/RangeOf.hpp>
#include <meta/details/StaticInfo.hpp>
#include <meta/details/StaticInfo_Wrappers.hpp>
#include <meta/details/array.hpp>
#include <src/test.h>
#include <type_traits>

namespace pf::meta::details {

    /****************************** pf::B2 START ******************************/
    template<>
    struct StaticInfo<ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u}> {

        using Type = pf::B2;
        constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 20;
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
        constexpr static bool IsClass = false;
        constexpr static bool IsStruct = true;
        constexpr static bool IsPolymorphic = false;
        constexpr static bool IsAbstract = false;
        constexpr static bool IsFinal = false;
        constexpr static RangeOf<Info> auto Bases = pf::meta::details::make_array<Info>();
        constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>();
        constexpr static Info Destructor = ID{0x75598d2a0e986fadu, 0x24bfa1eb9392f7a5u};
        constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>();
        constexpr static RangeOf<Info> auto StaticFunctions = pf::meta::details::make_array<Info>();
        constexpr static RangeOf<Info> auto MemberVariables = pf::meta::details::make_array<Info>(
                ID{0xaf5e03b957ddff55u, 0xeff0cad10d03aa87u}, ID{0xe857cf8dc5d267dcu, 0xfba379891107518du});
        constexpr static RangeOf<Info> auto StaticVariables =
                pf::meta::details::make_array<Info>(ID{0x6b5dfe9e58a89813u, 0x3b9081e7e6e13aaau});
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
        constexpr static auto IsFinal = false;
        constexpr static bool IsInline = false;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"~B2"};
        constexpr static auto FullName = StringLiteral{"pf::B2::~B2"};

        constexpr static auto DtorWrap = [](pf::B2 &self) constexpr -> void { self.~B2(); };
    };

    /****************************** pf::B2::value START ******************************/
    template<>
    struct StaticInfo<ID{0xaf5e03b957ddff55u, 0xeff0cad10d03aa87u}> {

        constexpr static ID VariableID = ID{0xaf5e03b957ddff55u, 0xeff0cad10d03aa87u};
        constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 21;
        constexpr static std::uint64_t SourceColumn = 19;

        constexpr static RangeOf<Attribute> auto Attributes =
                pf::meta::details::make_array<Attribute>(Attribute{"", "test1", std::span<const std::string_view>{EmptyAttributeArgArray}},
                                                         Attribute{"", "test2", std::span<const std::string_view>{EmptyAttributeArgArray}},
                                                         Attribute{"", "test3", std::span<const std::string_view>{EmptyAttributeArgArray}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsMutable = false;
        constexpr static bool IsBitfield = false;


        constexpr static auto Name = StringLiteral{"value"};
        constexpr static auto FullName = StringLiteral{"pf::B2::value"};

        constexpr static int pf::B2::*MemberPtr = &pf::B2::value;
    };

    /****************************** pf::B2::value2 START ******************************/
    template<>
    struct StaticInfo<ID{0xe857cf8dc5d267dcu, 0xfba379891107518du}> {

        constexpr static ID VariableID = ID{0xe857cf8dc5d267dcu, 0xfba379891107518du};
        constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 22;
        constexpr static std::uint64_t SourceColumn = 19;

        constexpr static RangeOf<Attribute> auto Attributes =
                pf::meta::details::make_array<Attribute>(Attribute{"", "test1", std::span<const std::string_view>{EmptyAttributeArgArray}},
                                                         Attribute{"", "test2", std::span<const std::string_view>{EmptyAttributeArgArray}},
                                                         Attribute{"", "test3", std::span<const std::string_view>{EmptyAttributeArgArray}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsMutable = false;
        constexpr static bool IsBitfield = false;


        constexpr static auto Name = StringLiteral{"value2"};
        constexpr static auto FullName = StringLiteral{"pf::B2::value2"};

        constexpr static int pf::B2::*MemberPtr = &pf::B2::value2;
    };

    /****************************** pf::B2::value3 START ******************************/
    template<>
    struct StaticInfo<ID{0x6b5dfe9e58a89813u, 0x3b9081e7e6e13aaau}> {

        constexpr static ID VariableID = ID{0x6b5dfe9e58a89813u, 0x3b9081e7e6e13aaau};
        constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 23;
        constexpr static std::uint64_t SourceColumn = 19;

        constexpr static RangeOf<Attribute> auto Attributes =
                pf::meta::details::make_array<Attribute>(Attribute{"", "test1", std::span<const std::string_view>{EmptyAttributeArgArray}},
                                                         Attribute{"", "test2", std::span<const std::string_view>{EmptyAttributeArgArray}},
                                                         Attribute{"", "test3", std::span<const std::string_view>{EmptyAttributeArgArray}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::StaticVariable;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsConstexpr = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = true;

        constexpr static auto Name = StringLiteral{"value3"};
        constexpr static auto FullName = StringLiteral{"pf::B2::value3"};

        constexpr static int *MemberPtr = &pf::B2::value3;
    };

}// namespace pf::meta::details
