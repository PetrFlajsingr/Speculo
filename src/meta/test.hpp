
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
    // Record pf::Hoho, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:7:5
    template<>
    struct StaticInfo<ID{0x8d5b8563df0be54bu, 0x6e288d623e2d93b9u}> {

        using Type = pf::Hoho;
        constexpr static ID TypeID = ID{0x8d5b8563df0be54bu, 0x6e288d623e2d93b9u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 7;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::RecordType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"Hoho"};
        constexpr static auto FullName = StringLiteral{"pf::Hoho"};

        constexpr static bool IsUnion = false;
        constexpr static bool IsClass = true;
        constexpr static bool IsStruct = false;
        constexpr static bool IsPolymorphic = false;
        constexpr static bool IsAbstract = false;
        constexpr static bool IsFinal = false;
        constexpr static RangeOf<Info> auto Bases = pf::meta::details::make_array<Info>(ID{0x3a523ac17eee65cfu, 0x590ed0e3af7dcf9fu});
        constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>();
        constexpr static Info Destructor = ID{0x9653fcd84478bbcau, 0xfa251342884931b0u};
        constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>();
        constexpr static RangeOf<Info> auto StaticFunctions = pf::meta::details::make_array<Info>();
        constexpr static RangeOf<Info> auto MemberVariables =
                pf::meta::details::make_array<Info>(ID{0x2f5a3626a1752cfeu, 0xd7cd52d84ba02299u});
        constexpr static RangeOf<Info> auto StaticVariables = pf::meta::details::make_array<Info>();
    };

    // const
    template<>
    struct StaticInfo<ID{0xc55609d1197e332u, 0xbd70f4197aaea5b7u}>
        : StaticInfo_ConstWrap<ID{0xc55609d1197e332u, 0xbd70f4197aaea5b7u}, ID{0x8d5b8563df0be54bu, 0x6e288d623e2d93b9u}> {};
    // &
    template<>
    struct StaticInfo<ID{0x3e5e84bb7ed33c09u, 0x1a1df75575bb7e9bu}>
        : StaticInfo_LRefWrap<ID{0x3e5e84bb7ed33c09u, 0x1a1df75575bb7e9bu}, ID{0x8d5b8563df0be54bu, 0x6e288d623e2d93b9u}> {};
    // &&
    template<>
    struct StaticInfo<ID{0xb854c0bfb3969048u, 0x5b249cb7f7507ea6u}>
        : StaticInfo_RRefWrap<ID{0xb854c0bfb3969048u, 0x5b249cb7f7507ea6u}, ID{0x8d5b8563df0be54bu, 0x6e288d623e2d93b9u}> {};
    // const &
    template<>
    struct StaticInfo<ID{0xb350dd01df63bae5u, 0x733a39b0846e7da0u}>
        : StaticInfo_ConstLRefWrap<ID{0xb350dd01df63bae5u, 0x733a39b0846e7da0u}, ID{0x8d5b8563df0be54bu, 0x6e288d623e2d93b9u}> {};
    // *
    template<>
    struct StaticInfo<ID{0xfd5cddd4c7283228u, 0x2a86b6e9f5712ab1u}>
        : StaticInfo_PtrWrap<ID{0xfd5cddd4c7283228u, 0x2a86b6e9f5712ab1u}, ID{0x8d5b8563df0be54bu, 0x6e288d623e2d93b9u}> {};
    // const *
    template<>
    struct StaticInfo<ID{0x9852ca98825989b7u, 0x2cc5fdad65a69a96u}>
        : StaticInfo_ConstPtrWrap<ID{0x9852ca98825989b7u, 0x2cc5fdad65a69a96u}, ID{0x8d5b8563df0be54bu, 0x6e288d623e2d93b9u}> {};
    // Record pf::Hoho static info getters

    template<>
    [[nodiscard]] consteval ID getTypeId<pf::Hoho>() {
        return ID{0x8d5b8563df0be54bu, 0x6e288d623e2d93b9u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::Hoho>() {
        return ID{0xc55609d1197e332u, 0xbd70f4197aaea5b7u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::Hoho &>() {
        return ID{0x3e5e84bb7ed33c09u, 0x1a1df75575bb7e9bu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::Hoho &&>() {
        return ID{0xb854c0bfb3969048u, 0x5b249cb7f7507ea6u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::Hoho &>() {
        return ID{0xb350dd01df63bae5u, 0x733a39b0846e7da0u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::Hoho *>() {
        return ID{0xfd5cddd4c7283228u, 0x2a86b6e9f5712ab1u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::Hoho *>() {
        return ID{0x9852ca98825989b7u, 0x2cc5fdad65a69a96u};
    }
    // Record pf::Hoho base class Haha

    template<>
    struct StaticInfo<ID{0x3a523ac17eee65cfu, 0x590ed0e3af7dcf9fu}> {

        constexpr static ID BaseID = ID{0x3a523ac17eee65cfu, 0x590ed0e3af7dcf9fu};
        constexpr static ID TypeID = ID{0x3c5d5afabb97750fu, 0x525b0b9cef60dc88u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 7;
        constexpr static std::uint64_t SourceColumn = 18;

        constexpr static auto StaticInfoObjectType = StaticInfoType::Base;

        constexpr static bool IsPublic = false;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = true;
        constexpr static auto IsVirtual = false;

        constexpr static auto Name = StringLiteral{"Haha"};
        constexpr static auto FullName = StringLiteral{"Haha"};
    };
    // Record pf::Hoho member variable pf::Hoho::stan

    template<>
    struct StaticInfo<ID{0x2f5a3626a1752cfeu, 0xd7cd52d84ba02299u}> {

        constexpr static ID VariableID = ID{0x2f5a3626a1752cfeu, 0xd7cd52d84ba02299u};
        constexpr static ID TypeID = ID{0x8d5b8563df0be54bu, 0x6e288d623e2d93b9u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 10;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

        constexpr static bool IsPublic = false;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = true;
        constexpr static bool IsMutable = false;
        constexpr static bool IsBitfield = false;


        constexpr static auto Name = StringLiteral{"stan"};
        constexpr static auto FullName = StringLiteral{"pf::Hoho::stan"};

        constexpr static int pf::Hoho::*MemberPtr = &pf::Hoho::stan;
    };
    // Record pf::Hoho **END**// Enum pf::SomeEnum, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:15:5 with 2 enumerators
    // Enumerator pf::SomeEnum::Value1, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:18:9

    template<>
    struct StaticInfo<ID{0xc0597f7732016649u, 0xed19a615bd3023bau}> {

        constexpr static ID ValueID = ID{0xc0597f7732016649u, 0xed19a615bd3023bau};
        constexpr static ID TypeID = ID{0xc0597f7732016649u, 0xed19a615bd3023bau};
        using Type = pf::SomeEnum;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 18;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(
                Attribute{"pf", "test", std::span<const std::string_view>{EmptyAttributeArgArray}},
                Attribute{"pf", "test2", std::span<const std::string_view>{EmptyAttributeArgArray}},
                Attribute{"pf", "test3", std::span<const std::string_view>{EmptyAttributeArgArray}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"Value1"};
        constexpr static auto FullName = StringLiteral{"pf::SomeEnum::Value1"};

        constexpr static int UnderlyingValue = 0;
        constexpr static pf::SomeEnum Value = pf::SomeEnum::Value1;
    };
    // Enumerator pf::SomeEnum::Value2, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:19:9

    template<>
    struct StaticInfo<ID{0x445d2037590be14au, 0xd949752de2aa1786u}> {

        constexpr static ID ValueID = ID{0x445d2037590be14au, 0xd949752de2aa1786u};
        constexpr static ID TypeID = ID{0x445d2037590be14au, 0xd949752de2aa1786u};
        using Type = pf::SomeEnum;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 19;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"Value2"};
        constexpr static auto FullName = StringLiteral{"pf::SomeEnum::Value2"};

        constexpr static int UnderlyingValue = 1;
        constexpr static pf::SomeEnum Value = pf::SomeEnum::Value2;
    };

    template<>
    struct StaticInfo<ID{0x2b53af1c1cf57f8au, 0xe97917064d8b3696u}> {
        struct details {
            constexpr static auto ArgArray_17422279790921084300 = pf::meta::details::make_array<std::string_view>(
                    R"arg("yeet")arg", R"arg('a')arg", R"arg(()()()((())))arg", R"arg(1.011)arg", R"arg(1ll)arg", R"arg([[nodiscard]])arg",
                    R"arg([][][]:::3214234...[][][][])arg", R"arg([]{}())arg");
            constexpr static auto ArgArray_14287779606558700218 =
                    pf::meta::details::make_array<std::string_view>(R"arg("yeet")arg", R"arg(1.011)arg", R"arg(1ll)arg");
        };
        using Type = pf::SomeEnum;
        constexpr static ID TypeID = ID{0x2b53af1c1cf57f8au, 0xe97917064d8b3696u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 15;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(
                Attribute{"", "hihi", std::span<const std::string_view>{EmptyAttributeArgArray}},
                Attribute{"", "nodiscard", std::span<const std::string_view>{EmptyAttributeArgArray}},
                Attribute{"", "operators", std::span<const std::string_view>{details::ArgArray_17422279790921084300}},
                Attribute{"", "pf", std::span<const std::string_view>{EmptyAttributeArgArray}},
                Attribute{"pf", "hihi2", std::span<const std::string_view>{EmptyAttributeArgArray}},
                Attribute{"pf", "operators2", std::span<const std::string_view>{details::ArgArray_14287779606558700218}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"SomeEnum"};
        constexpr static auto FullName = StringLiteral{"pf::SomeEnum"};

        using UnderlyingType = int;
        constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
        constexpr static RangeOf<Info> auto EnumValues = pf::meta::details::make_array<Info>(ID{0xc0597f7732016649u, 0xed19a615bd3023bau},
                                                                                             ID{0x445d2037590be14au, 0xd949752de2aa1786u});
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
    // Enum pf::SomeEnum static info getters

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
    // Enumerators of pf::SomeEnum static info getters

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value1>() {
        return ID{0xc0597f7732016649u, 0xed19a615bd3023bau};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value2>() {
        return ID{0x445d2037590be14au, 0xd949752de2aa1786u};
    }
    //Enum pf::SomeEnum **END**
    // Record pf::B2, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:24:5
    template<>
    struct StaticInfo<ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u}> {

        using Type = pf::B2;
        constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 24;
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
        constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>(
                ID{0xbb5a664b988f77f8u, 0x531e167743e766b6u}, ID{0xee55b15e030f0b51u, 0xb0990502d492e5a3u},
                ID{0xf7527360fc6ada92u, 0xa4133785a1400e82u});
        constexpr static Info Destructor = ID{0x75598d2a0e986fadu, 0x24bfa1eb9392f7a5u};
        constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>(
                ID{0x99580cca89f72044u, 0x584f40bbf7150b4u}, ID{0x69576a33bcbc4b77u, 0x4121319930da7291u});
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
    // Record pf::B2 static info getters

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
    // Record pf::B2 constructor pf::B2::B2 argument

    template<>
    struct StaticInfo<ID{0xe95e4b41f0581db5u, 0xc1dae8040b904198u}> {

        constexpr static ID ArgumentID = ID{0xe95e4b41f0581db5u, 0xc1dae8040b904198u};
        constexpr static ID TypeID = ID{0xf35da7afdf779c62u, 0xaa45e39f3ea888a5u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 24;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{""};
        constexpr static auto FullName = StringLiteral{""};
    };
    // Record pf::B2 constructor pf::B2::B2

    template<>
    struct StaticInfo<ID{0xbb5a664b988f77f8u, 0x531e167743e766b6u}> {

        constexpr static ID ConstructorID = ID{0xbb5a664b988f77f8u, 0x531e167743e766b6u};
        constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 24;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsExplicit = false;
        constexpr static bool IsCopy = true;
        constexpr static bool IsMove = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = false;
        constexpr static bool IsInlineSpecified = true;

        constexpr static auto Name = StringLiteral{"B2"};
        constexpr static auto FullName = StringLiteral{"pf::B2::B2"};

        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0xe95e4b41f0581db5u, 0xc1dae8040b904198u});

        constexpr static auto CtorWrap = [](const B2 &arg_0) constexpr -> pf::B2 { return pf::B2(arg_0); };
        constexpr static auto NewCtorWrap = [](const B2 &arg_0) constexpr -> pf::B2 * { return new pf::B2(arg_0); };
        constexpr static auto PlacementNewCtorWrap = [](void *mem, const B2 &arg_0) -> pf::B2 * { return new (mem) pf::B2(arg_0); };
    };
    // Record pf::B2 constructor pf::B2::B2 argument

    template<>
    struct StaticInfo<ID{0xb587c7b0affd036u, 0xa85001acac5163a2u}> {

        constexpr static ID ArgumentID = ID{0xb587c7b0affd036u, 0xa85001acac5163a2u};
        constexpr static ID TypeID = ID{0xcf5b889bb54e3121u, 0x479aa07f2f530d80u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 24;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{""};
        constexpr static auto FullName = StringLiteral{""};
    };
    // Record pf::B2 constructor pf::B2::B2

    template<>
    struct StaticInfo<ID{0xee55b15e030f0b51u, 0xb0990502d492e5a3u}> {

        constexpr static ID ConstructorID = ID{0xee55b15e030f0b51u, 0xb0990502d492e5a3u};
        constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 24;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsExplicit = false;
        constexpr static bool IsCopy = false;
        constexpr static bool IsMove = true;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = false;
        constexpr static bool IsInlineSpecified = true;

        constexpr static auto Name = StringLiteral{"B2"};
        constexpr static auto FullName = StringLiteral{"pf::B2::B2"};

        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0xb587c7b0affd036u, 0xa85001acac5163a2u});

        constexpr static auto CtorWrap = [](B2 &&arg_0) constexpr -> pf::B2 { return pf::B2(arg_0); };
        constexpr static auto NewCtorWrap = [](B2 &&arg_0) constexpr -> pf::B2 * { return new pf::B2(arg_0); };
        constexpr static auto PlacementNewCtorWrap = [](void *mem, B2 &&arg_0) -> pf::B2 * { return new (mem) pf::B2(arg_0); };
    };
    // Record pf::B2 constructor pf::B2::B2

    template<>
    struct StaticInfo<ID{0xf7527360fc6ada92u, 0xa4133785a1400e82u}> {

        constexpr static ID ConstructorID = ID{0xf7527360fc6ada92u, 0xa4133785a1400e82u};
        constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 24;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsExplicit = false;
        constexpr static bool IsCopy = false;
        constexpr static bool IsMove = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = true;

        constexpr static auto Name = StringLiteral{"B2"};
        constexpr static auto FullName = StringLiteral{"pf::B2::B2"};

        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();

        constexpr static auto CtorWrap = []() constexpr -> pf::B2 { return pf::B2(); };
        constexpr static auto NewCtorWrap = []() constexpr -> pf::B2 * { return new pf::B2(); };
        constexpr static auto PlacementNewCtorWrap = [](void *mem) -> pf::B2 * { return new (mem) pf::B2(); };
    };
    // Record pf::B2 member function pf::B2::operator= argument

    template<>
    struct StaticInfo<ID{0xb15f08a3c374f0f5u, 0xd01bded4c0a88593u}> {

        constexpr static ID ArgumentID = ID{0xb15f08a3c374f0f5u, 0xd01bded4c0a88593u};
        constexpr static ID TypeID = ID{0xf35da7afdf779c62u, 0xaa45e39f3ea888a5u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 24;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{""};
        constexpr static auto FullName = StringLiteral{""};
    };
    // Record pf::B2 member function pf::B2::operator=

    template<>
    struct StaticInfo<ID{0x99580cca89f72044u, 0x584f40bbf7150b4u}> {

        constexpr static ID FunctionID = ID{0x99580cca89f72044u, 0x584f40bbf7150b4u};
        constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 24;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsVirtual = false;
        constexpr static bool IsPureVirtual = false;
        constexpr static auto IsFinal = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = false;
        constexpr static bool IsInlineSpecified = true;

        constexpr static auto Name = StringLiteral{"operator="};
        constexpr static auto FullName = StringLiteral{"pf::B2::operator="};

        constexpr static Info ReturnType = ID{0x3a59269d2b29d23fu, 0xacc88b6947004dadu};
        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0xb15f08a3c374f0f5u, 0xd01bded4c0a88593u});

        constexpr static B2 &(pf::B2::*MemberPtr)(const B2 &) = &pf::B2::operator=;
    };
    // Record pf::B2 member function pf::B2::operator= argument

    template<>
    struct StaticInfo<ID{0x965d84d2c706f5a8u, 0xb535ab3fa4deb096u}> {

        constexpr static ID ArgumentID = ID{0x965d84d2c706f5a8u, 0xb535ab3fa4deb096u};
        constexpr static ID TypeID = ID{0xcf5b889bb54e3121u, 0x479aa07f2f530d80u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 24;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{""};
        constexpr static auto FullName = StringLiteral{""};
    };
    // Record pf::B2 member function pf::B2::operator=

    template<>
    struct StaticInfo<ID{0x69576a33bcbc4b77u, 0x4121319930da7291u}> {

        constexpr static ID FunctionID = ID{0x69576a33bcbc4b77u, 0x4121319930da7291u};
        constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 24;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsVirtual = false;
        constexpr static bool IsPureVirtual = false;
        constexpr static auto IsFinal = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = false;
        constexpr static bool IsInlineSpecified = true;

        constexpr static auto Name = StringLiteral{"operator="};
        constexpr static auto FullName = StringLiteral{"pf::B2::operator="};

        constexpr static Info ReturnType = ID{0x3a59269d2b29d23fu, 0xacc88b6947004dadu};
        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x965d84d2c706f5a8u, 0xb535ab3fa4deb096u});

        constexpr static B2 &(pf::B2::*MemberPtr)(B2 &&) = &pf::B2::operator=;
    };
    // Record pf::B2 member variable pf::B2::value

    template<>
    struct StaticInfo<ID{0xaf5e03b957ddff55u, 0xeff0cad10d03aa87u}> {

        constexpr static ID VariableID = ID{0xaf5e03b957ddff55u, 0xeff0cad10d03aa87u};
        constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 25;
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
    // Record pf::B2 member variable pf::B2::value2

    template<>
    struct StaticInfo<ID{0xe857cf8dc5d267dcu, 0xfba379891107518du}> {

        constexpr static ID VariableID = ID{0xe857cf8dc5d267dcu, 0xfba379891107518du};
        constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 26;
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
    // Record pf::B2 static variable pf::B2::value3

    template<>
    struct StaticInfo<ID{0x6b5dfe9e58a89813u, 0x3b9081e7e6e13aaau}> {

        constexpr static ID VariableID = ID{0x6b5dfe9e58a89813u, 0x3b9081e7e6e13aaau};
        constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 27;
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
    // Record pf::B2 **END**// Record pf::B3, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:29:5
    template<>
    struct StaticInfo<ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu}> {
        struct details {
            constexpr static auto ArgArray_18039988757875692255 =
                    pf::meta::details::make_array<std::string_view>(R"arg(111)arg", R"arg(222)arg", R"arg(333)arg", R"arg(444)arg");
        };
        using Type = pf::B3;
        constexpr static ID TypeID = ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 29;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(
                Attribute{"", "lala", std::span<const std::string_view>{details::ArgArray_18039988757875692255}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::RecordType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"B3"};
        constexpr static auto FullName = StringLiteral{"pf::B3"};

        constexpr static bool IsUnion = false;
        constexpr static bool IsClass = false;
        constexpr static bool IsStruct = true;
        constexpr static bool IsPolymorphic = false;
        constexpr static bool IsAbstract = false;
        constexpr static bool IsFinal = false;
        constexpr static RangeOf<Info> auto Bases = pf::meta::details::make_array<Info>();
        constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>(
                ID{0x775e6404bd915ec5u, 0x87c8ed532da21da5u}, ID{0x459f578dbb543d1u, 0x8a25947060a5b983u},
                ID{0x9158d51e7c91adbbu, 0xcdaeb1cb5d6ea09fu});
        constexpr static Info Destructor = ID{0x115b1c832b9d7569u, 0x163a50a92d0c318bu};
        constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>(
                ID{0x2f51c76461390f4eu, 0xfec8eb2dbd761c92u}, ID{0x885387cda84d6d70u, 0xf66d08849e9edca8u});
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
    // Record pf::B3 static info getters

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
    // Record pf::B3 constructor pf::B3::B3 argument

    template<>
    struct StaticInfo<ID{0x51519b03f24f807du, 0xf2ed29cf6856493u}> {

        constexpr static ID ArgumentID = ID{0x51519b03f24f807du, 0xf2ed29cf6856493u};
        constexpr static ID TypeID = ID{0xc854a3e494ad0d14u, 0x131316cbcba1c880u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 29;
        constexpr static std::uint64_t SourceColumn = 56;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{""};
        constexpr static auto FullName = StringLiteral{""};
    };
    // Record pf::B3 constructor pf::B3::B3

    template<>
    struct StaticInfo<ID{0x775e6404bd915ec5u, 0x87c8ed532da21da5u}> {
        struct details {
            constexpr static auto ArgArray_14565078776437132038 =
                    pf::meta::details::make_array<std::string_view>(R"arg(111)arg", R"arg(222)arg", R"arg(333)arg", R"arg(444)arg");
        };
        constexpr static ID ConstructorID = ID{0x775e6404bd915ec5u, 0x87c8ed532da21da5u};
        constexpr static ID TypeID = ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 29;
        constexpr static std::uint64_t SourceColumn = 56;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(
                Attribute{"", "lala", std::span<const std::string_view>{details::ArgArray_14565078776437132038}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsExplicit = false;
        constexpr static bool IsCopy = true;
        constexpr static bool IsMove = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = false;
        constexpr static bool IsInlineSpecified = true;

        constexpr static auto Name = StringLiteral{"B3"};
        constexpr static auto FullName = StringLiteral{"pf::B3::B3"};

        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x51519b03f24f807du, 0xf2ed29cf6856493u});

        constexpr static auto CtorWrap = [](const B3 &arg_0) constexpr -> pf::B3 { return pf::B3(arg_0); };
        constexpr static auto NewCtorWrap = [](const B3 &arg_0) constexpr -> pf::B3 * { return new pf::B3(arg_0); };
        constexpr static auto PlacementNewCtorWrap = [](void *mem, const B3 &arg_0) -> pf::B3 * { return new (mem) pf::B3(arg_0); };
    };
    // Record pf::B3 constructor pf::B3::B3 argument

    template<>
    struct StaticInfo<ID{0xa35a4f4501553963u, 0x5c8421596d3fc18du}> {

        constexpr static ID ArgumentID = ID{0xa35a4f4501553963u, 0x5c8421596d3fc18du};
        constexpr static ID TypeID = ID{0x15509f81d684c525u, 0x8afdaf4762bafbfu};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 29;
        constexpr static std::uint64_t SourceColumn = 56;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{""};
        constexpr static auto FullName = StringLiteral{""};
    };
    // Record pf::B3 constructor pf::B3::B3

    template<>
    struct StaticInfo<ID{0x459f578dbb543d1u, 0x8a25947060a5b983u}> {
        struct details {
            constexpr static auto ArgArray_6688358099500093557 =
                    pf::meta::details::make_array<std::string_view>(R"arg(111)arg", R"arg(222)arg", R"arg(333)arg", R"arg(444)arg");
        };
        constexpr static ID ConstructorID = ID{0x459f578dbb543d1u, 0x8a25947060a5b983u};
        constexpr static ID TypeID = ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 29;
        constexpr static std::uint64_t SourceColumn = 56;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(
                Attribute{"", "lala", std::span<const std::string_view>{details::ArgArray_6688358099500093557}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsExplicit = false;
        constexpr static bool IsCopy = false;
        constexpr static bool IsMove = true;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = false;
        constexpr static bool IsInlineSpecified = true;

        constexpr static auto Name = StringLiteral{"B3"};
        constexpr static auto FullName = StringLiteral{"pf::B3::B3"};

        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0xa35a4f4501553963u, 0x5c8421596d3fc18du});

        constexpr static auto CtorWrap = [](B3 &&arg_0) constexpr -> pf::B3 { return pf::B3(arg_0); };
        constexpr static auto NewCtorWrap = [](B3 &&arg_0) constexpr -> pf::B3 * { return new pf::B3(arg_0); };
        constexpr static auto PlacementNewCtorWrap = [](void *mem, B3 &&arg_0) -> pf::B3 * { return new (mem) pf::B3(arg_0); };
    };
    // Record pf::B3 constructor pf::B3::B3

    template<>
    struct StaticInfo<ID{0x9158d51e7c91adbbu, 0xcdaeb1cb5d6ea09fu}> {
        struct details {
            constexpr static auto ArgArray_11925678696793150522 =
                    pf::meta::details::make_array<std::string_view>(R"arg(111)arg", R"arg(222)arg", R"arg(333)arg", R"arg(444)arg");
        };
        constexpr static ID ConstructorID = ID{0x9158d51e7c91adbbu, 0xcdaeb1cb5d6ea09fu};
        constexpr static ID TypeID = ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 29;
        constexpr static std::uint64_t SourceColumn = 56;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(
                Attribute{"", "lala", std::span<const std::string_view>{details::ArgArray_11925678696793150522}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsExplicit = false;
        constexpr static bool IsCopy = false;
        constexpr static bool IsMove = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = true;

        constexpr static auto Name = StringLiteral{"B3"};
        constexpr static auto FullName = StringLiteral{"pf::B3::B3"};

        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();

        constexpr static auto CtorWrap = []() constexpr -> pf::B3 { return pf::B3(); };
        constexpr static auto NewCtorWrap = []() constexpr -> pf::B3 * { return new pf::B3(); };
        constexpr static auto PlacementNewCtorWrap = [](void *mem) -> pf::B3 * { return new (mem) pf::B3(); };
    };
    // Record pf::B3 member function pf::B3::operator= argument

    template<>
    struct StaticInfo<ID{0xaa5a62f996d64f5bu, 0x776f9a0f5bd417b5u}> {

        constexpr static ID ArgumentID = ID{0xaa5a62f996d64f5bu, 0x776f9a0f5bd417b5u};
        constexpr static ID TypeID = ID{0xc854a3e494ad0d14u, 0x131316cbcba1c880u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 29;
        constexpr static std::uint64_t SourceColumn = 56;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{""};
        constexpr static auto FullName = StringLiteral{""};
    };
    // Record pf::B3 member function pf::B3::operator=

    template<>
    struct StaticInfo<ID{0x2f51c76461390f4eu, 0xfec8eb2dbd761c92u}> {
        struct details {
            constexpr static auto ArgArray_12826247973951880050 =
                    pf::meta::details::make_array<std::string_view>(R"arg(111)arg", R"arg(222)arg", R"arg(333)arg", R"arg(444)arg");
        };
        constexpr static ID FunctionID = ID{0x2f51c76461390f4eu, 0xfec8eb2dbd761c92u};
        constexpr static ID TypeID = ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 29;
        constexpr static std::uint64_t SourceColumn = 56;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(
                Attribute{"", "lala", std::span<const std::string_view>{details::ArgArray_12826247973951880050}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsVirtual = false;
        constexpr static bool IsPureVirtual = false;
        constexpr static auto IsFinal = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = false;
        constexpr static bool IsInlineSpecified = true;

        constexpr static auto Name = StringLiteral{"operator="};
        constexpr static auto FullName = StringLiteral{"pf::B3::operator="};

        constexpr static Info ReturnType = ID{0xbb547235767bac97u, 0x73b739c83f01a0bau};
        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0xaa5a62f996d64f5bu, 0x776f9a0f5bd417b5u});

        constexpr static B3 &(pf::B3::*MemberPtr)(const B3 &) = &pf::B3::operator=;
    };
    // Record pf::B3 member function pf::B3::operator= argument

    template<>
    struct StaticInfo<ID{0x505688227faa7d73u, 0x398c86ec0ca4029fu}> {

        constexpr static ID ArgumentID = ID{0x505688227faa7d73u, 0x398c86ec0ca4029fu};
        constexpr static ID TypeID = ID{0x15509f81d684c525u, 0x8afdaf4762bafbfu};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 29;
        constexpr static std::uint64_t SourceColumn = 56;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{""};
        constexpr static auto FullName = StringLiteral{""};
    };
    // Record pf::B3 member function pf::B3::operator=

    template<>
    struct StaticInfo<ID{0x885387cda84d6d70u, 0xf66d08849e9edca8u}> {
        struct details {
            constexpr static auto ArgArray_13746924265558717676 =
                    pf::meta::details::make_array<std::string_view>(R"arg(111)arg", R"arg(222)arg", R"arg(333)arg", R"arg(444)arg");
        };
        constexpr static ID FunctionID = ID{0x885387cda84d6d70u, 0xf66d08849e9edca8u};
        constexpr static ID TypeID = ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 29;
        constexpr static std::uint64_t SourceColumn = 56;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(
                Attribute{"", "lala", std::span<const std::string_view>{details::ArgArray_13746924265558717676}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsVirtual = false;
        constexpr static bool IsPureVirtual = false;
        constexpr static auto IsFinal = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = false;
        constexpr static bool IsInlineSpecified = true;

        constexpr static auto Name = StringLiteral{"operator="};
        constexpr static auto FullName = StringLiteral{"pf::B3::operator="};

        constexpr static Info ReturnType = ID{0xbb547235767bac97u, 0x73b739c83f01a0bau};
        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x505688227faa7d73u, 0x398c86ec0ca4029fu});

        constexpr static B3 &(pf::B3::*MemberPtr)(B3 &&) = &pf::B3::operator=;
    };
    // Record pf::B3 **END**// Record pf::A, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:32:5
    template<>
    struct StaticInfo<ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u}> {

        using Type = pf::A;
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 32;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(
                Attribute{"", "first", std::span<const std::string_view>{EmptyAttributeArgArray}},
                Attribute{"", "nodiscard", std::span<const std::string_view>{EmptyAttributeArgArray}},
                Attribute{"", "second", std::span<const std::string_view>{EmptyAttributeArgArray}},
                Attribute{"", "third", std::span<const std::string_view>{EmptyAttributeArgArray}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::RecordType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"pf::A"};

        constexpr static bool IsUnion = false;
        constexpr static bool IsClass = false;
        constexpr static bool IsStruct = true;
        constexpr static bool IsPolymorphic = true;
        constexpr static bool IsAbstract = false;
        constexpr static bool IsFinal = false;
        constexpr static RangeOf<Info> auto Bases = pf::meta::details::make_array<Info>(ID{0x925a379bde23315eu, 0x48e00dcbb6b17ea7u},
                                                                                        ID{0x3a589977fc087aefu, 0x1dfe9dbc187d6bb2u},
                                                                                        ID{0x5358aab1d01f14d9u, 0xacf43a2903663a80u});
        constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>(
                ID{0xf597eea5e1760bfu, 0x797c08db90791d84u}, ID{0x815407ebc8e88a02u, 0x2149a35bbcc7e2b3u},
                ID{0x57555b6607562e41u, 0xa37e35a1094ff4a2u});
        constexpr static Info Destructor = ID{0x985d28b56ec36af8u, 0x3517760838a68a86u};
        constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>(
                ID{0x225525f0788858deu, 0x9edf3c90fb14daacu}, ID{0x575fdd108108c3d9u, 0xf4b82162dd7fc096u},
                ID{0xb651642ac8c5f237u, 0xfe0f1011e8f1b95u}, ID{0x9f5d7b21263d723fu, 0xc090822c6cd77cb1u},
                ID{0xb151275a6f2b5b4bu, 0x932b3500b737d4a6u}, ID{0x3d55f23651de9cbcu, 0x3ec37599fa78fcb3u});
        constexpr static RangeOf<Info> auto StaticFunctions =
                pf::meta::details::make_array<Info>(ID{0x645f1db97c2f0115u, 0xb3e5baae4a842bb6u});
        constexpr static RangeOf<Info> auto MemberVariables = pf::meta::details::make_array<Info>(
                ID{0x335f6f365cea35fdu, 0xab992c0c2c38a8a9u}, ID{0x885025556cce2f68u, 0x589def016d4c20beu},
                ID{0xce5e676fefa30dafu, 0x4eb0970230b6a49eu}, ID{0x85a1fc2b7924f35u, 0xab0ea2512267d8adu},
                ID{0x8f5f18cfb176f51cu, 0xd2107751b20304bcu});
        constexpr static RangeOf<Info> auto StaticVariables = pf::meta::details::make_array<Info>(
                ID{0x735d748eea9251efu, 0xe50efb391449b093u}, ID{0x5353cb42e1a5c7a7u, 0x962a030897c298a4u});
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
    // Record pf::A static info getters

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
    // Record pf::A base class pf::B1

    template<>
    struct StaticInfo<ID{0x925a379bde23315eu, 0x48e00dcbb6b17ea7u}> {

        constexpr static ID BaseID = ID{0x925a379bde23315eu, 0x48e00dcbb6b17ea7u};
        constexpr static ID TypeID = ID{0xd75b6042b1205435u, 0xeafc4a90a9b858b5u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 32;
        constexpr static std::uint64_t SourceColumn = 58;

        constexpr static auto StaticInfoObjectType = StaticInfoType::Base;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static auto IsVirtual = false;

        constexpr static auto Name = StringLiteral{"B1"};
        constexpr static auto FullName = StringLiteral{"pf::B1"};
    };
    // Record pf::A base class pf::B2

    template<>
    struct StaticInfo<ID{0x3a589977fc087aefu, 0x1dfe9dbc187d6bb2u}> {

        constexpr static ID BaseID = ID{0x3a589977fc087aefu, 0x1dfe9dbc187d6bb2u};
        constexpr static ID TypeID = ID{0xfe5d496cf3820c10u, 0x526b4884cc76f8b3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 32;
        constexpr static std::uint64_t SourceColumn = 62;

        constexpr static auto StaticInfoObjectType = StaticInfoType::Base;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static auto IsVirtual = false;

        constexpr static auto Name = StringLiteral{"B2"};
        constexpr static auto FullName = StringLiteral{"pf::B2"};
    };
    // Record pf::A base class pf::B3

    template<>
    struct StaticInfo<ID{0x5358aab1d01f14d9u, 0xacf43a2903663a80u}> {

        constexpr static ID BaseID = ID{0x5358aab1d01f14d9u, 0xacf43a2903663a80u};
        constexpr static ID TypeID = ID{0xf0524c50359e569cu, 0x4c14cca06db4089cu};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 32;
        constexpr static std::uint64_t SourceColumn = 66;

        constexpr static auto StaticInfoObjectType = StaticInfoType::Base;

        constexpr static bool IsPublic = false;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = true;
        constexpr static auto IsVirtual = false;

        constexpr static auto Name = StringLiteral{"B3"};
        constexpr static auto FullName = StringLiteral{"pf::B3"};
    };
    // Record pf::A constructor pf::A::A

    template<>
    struct StaticInfo<ID{0xf597eea5e1760bfu, 0x797c08db90791d84u}> {

        constexpr static ID ConstructorID = ID{0xf597eea5e1760bfu, 0x797c08db90791d84u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 35;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsExplicit = false;
        constexpr static bool IsCopy = false;
        constexpr static bool IsMove = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"pf::A::A"};

        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();

        constexpr static auto CtorWrap = []() constexpr -> pf::A { return pf::A(); };
        constexpr static auto NewCtorWrap = []() constexpr -> pf::A * { return new pf::A(); };
        constexpr static auto PlacementNewCtorWrap = [](void *mem) -> pf::A * { return new (mem) pf::A(); };
    };
    // Record pf::A constructor pf::A::A argument a

    template<>
    struct StaticInfo<ID{0x3053755d5467bcf7u, 0x6c1a1a4c33857796u}> {

        constexpr static ID ArgumentID = ID{0x3053755d5467bcf7u, 0x6c1a1a4c33857796u};
        constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 37;
        constexpr static std::uint64_t SourceColumn = 11;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"a"};
        constexpr static auto FullName = StringLiteral{"a"};
    };
    // Record pf::A constructor pf::A::A

    template<>
    struct StaticInfo<ID{0x815407ebc8e88a02u, 0x2149a35bbcc7e2b3u}> {

        constexpr static ID ConstructorID = ID{0x815407ebc8e88a02u, 0x2149a35bbcc7e2b3u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 37;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsExplicit = false;
        constexpr static bool IsCopy = false;
        constexpr static bool IsMove = false;
        constexpr static bool IsConstexpr = false;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"pf::A::A"};

        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x3053755d5467bcf7u, 0x6c1a1a4c33857796u});

        constexpr static auto CtorWrap = [](std::same_as<int> auto &&arg_0) -> pf::A {
            return pf::A(std::forward<decltype(arg_0)>(arg_0));
        };
        constexpr static auto NewCtorWrap = [](std::same_as<int> auto &&arg_0) -> pf::A * {
            return new pf::A(std::forward<decltype(arg_0)>(arg_0));
        };
        constexpr static auto PlacementNewCtorWrap = [](void *mem, std::same_as<int> auto &&arg_0) -> pf::A * {
            return new (mem) pf::A(std::forward<decltype(arg_0)>(arg_0));
        };
    };
    // Record pf::A constructor pf::A::A argument sadfsdf

    template<>
    struct StaticInfo<ID{0x985c8105384db190u, 0x78c31fee58a0aca1u}> {

        constexpr static ID ArgumentID = ID{0x985c8105384db190u, 0x78c31fee58a0aca1u};
        constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 39;
        constexpr static std::uint64_t SourceColumn = 11;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"sadfsdf"};
        constexpr static auto FullName = StringLiteral{"sadfsdf"};
    };
    // Record pf::A constructor pf::A::A argument asdsa

    template<>
    struct StaticInfo<ID{0xdb580cc5d30c1cd8u, 0xeb635abea5e641a5u}> {

        constexpr static ID ArgumentID = ID{0xdb580cc5d30c1cd8u, 0xeb635abea5e641a5u};
        constexpr static ID TypeID = ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 39;
        constexpr static std::uint64_t SourceColumn = 24;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"asdsa"};
        constexpr static auto FullName = StringLiteral{"asdsa"};
    };
    // Record pf::A constructor pf::A::A

    template<>
    struct StaticInfo<ID{0x57555b6607562e41u, 0xa37e35a1094ff4a2u}> {

        constexpr static ID ConstructorID = ID{0x57555b6607562e41u, 0xa37e35a1094ff4a2u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 39;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsExplicit = false;
        constexpr static bool IsCopy = false;
        constexpr static bool IsMove = false;
        constexpr static bool IsConstexpr = false;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"pf::A::A"};

        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x985c8105384db190u, 0x78c31fee58a0aca1u},
                                                                                            ID{0xdb580cc5d30c1cd8u, 0xeb635abea5e641a5u});

        constexpr static auto CtorWrap = [](std::same_as<int> auto &&arg_0, std::same_as<float> auto &&arg_1) -> pf::A {
            return pf::A(std::forward<decltype(arg_0)>(arg_0), std::forward<decltype(arg_1)>(arg_1));
        };
        constexpr static auto NewCtorWrap = [](std::same_as<int> auto &&arg_0, std::same_as<float> auto &&arg_1) -> pf::A * {
            return new pf::A(std::forward<decltype(arg_0)>(arg_0), std::forward<decltype(arg_1)>(arg_1));
        };
        constexpr static auto PlacementNewCtorWrap = [](void *mem, std::same_as<int> auto &&arg_0,
                                                        std::same_as<float> auto &&arg_1) -> pf::A * {
            return new (mem) pf::A(std::forward<decltype(arg_0)>(arg_0), std::forward<decltype(arg_1)>(arg_1));
        };
    };
    // Record pf::A member function pf::A::operator= argument

    template<>
    struct StaticInfo<ID{0x25291b5fda86614u, 0x9eb2c6f726dbdabau}> {

        constexpr static ID ArgumentID = ID{0x25291b5fda86614u, 0x9eb2c6f726dbdabau};
        constexpr static ID TypeID = ID{0xbb5e42104794c546u, 0x86636ace5d6bbdb7u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 43;
        constexpr static std::uint64_t SourceColumn = 22;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{""};
        constexpr static auto FullName = StringLiteral{""};
    };
    // Record pf::A member function pf::A::operator=

    template<>
    struct StaticInfo<ID{0x225525f0788858deu, 0x9edf3c90fb14daacu}> {

        constexpr static ID FunctionID = ID{0x225525f0788858deu, 0x9edf3c90fb14daacu};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 43;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsVirtual = false;
        constexpr static bool IsPureVirtual = false;
        constexpr static auto IsFinal = false;
        constexpr static bool IsConstexpr = false;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"operator="};
        constexpr static auto FullName = StringLiteral{"pf::A::operator="};

        constexpr static Info ReturnType = ID{0x7d587451d13fe0e7u, 0xc033b6fb12bb2a8cu};
        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x25291b5fda86614u, 0x9eb2c6f726dbdabau});

        constexpr static A &(pf::A::*MemberPtr)(const A &) = &pf::A::operator=;
    };
    // Record pf::A member function pf::A::foo argument dzea

    template<>
    struct StaticInfo<ID{0x285fa243136a2539u, 0xd92a9fbd3c821b8u}> {
        struct details {
            constexpr static auto ArgArray_8369703634227216663 =
                    pf::meta::details::make_array<std::string_view>(R"arg(dzea)arg", R"arg(dzea2)arg");
        };
        constexpr static ID ArgumentID = ID{0x285fa243136a2539u, 0xd92a9fbd3c821b8u};
        constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 49;
        constexpr static std::uint64_t SourceColumn = 38;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(
                Attribute{"", "letadlo", std::span<const std::string_view>{details::ArgArray_8369703634227216663}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"dzea"};
        constexpr static auto FullName = StringLiteral{"dzea"};
    };
    // Record pf::A member function pf::A::foo argument A

    template<>
    struct StaticInfo<ID{0x505f49fe2f26ad62u, 0x466eafc2e33858a3u}> {

        constexpr static ID ArgumentID = ID{0x505f49fe2f26ad62u, 0x466eafc2e33858a3u};
        constexpr static ID TypeID = ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 49;
        constexpr static std::uint64_t SourceColumn = 65;

        constexpr static RangeOf<Attribute> auto Attributes =
                pf::meta::details::make_array<Attribute>(Attribute{"", "yuh", std::span<const std::string_view>{EmptyAttributeArgArray}},
                                                         Attribute{"", "yuh2", std::span<const std::string_view>{EmptyAttributeArgArray}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"A"};
    };
    // Record pf::A member function pf::A::foo

    template<>
    struct StaticInfo<ID{0x575fdd108108c3d9u, 0xf4b82162dd7fc096u}> {

        constexpr static ID FunctionID = ID{0x575fdd108108c3d9u, 0xf4b82162dd7fc096u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 48;
        constexpr static std::uint64_t SourceColumn = 37;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(
                Attribute{"", "kjhnn", std::span<const std::string_view>{EmptyAttributeArgArray}},
                Attribute{"", "maybe_unused", std::span<const std::string_view>{EmptyAttributeArgArray}},
                Attribute{"", "nodiscard", std::span<const std::string_view>{EmptyAttributeArgArray}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsConst = true;
        constexpr static bool IsVirtual = false;
        constexpr static bool IsPureVirtual = false;
        constexpr static auto IsFinal = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = true;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"foo"};
        constexpr static auto FullName = StringLiteral{"pf::A::foo"};

        constexpr static Info ReturnType = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};
        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x285fa243136a2539u, 0xd92a9fbd3c821b8u},
                                                                                            ID{0x505f49fe2f26ad62u, 0x466eafc2e33858a3u});

        constexpr static auto ConstevalWrap = [](const pf::A *self, int arg_0, float arg_1) consteval -> int {
            return self->foo(arg_0, arg_1);
        };
    };
    // Record pf::A member function pf::A::foo2 argument dzea2

    template<>
    struct StaticInfo<ID{0xa65963f0f043d5c8u, 0x8c4c551f4f92f2b6u}> {

        constexpr static ID ArgumentID = ID{0xa65963f0f043d5c8u, 0x8c4c551f4f92f2b6u};
        constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 53;
        constexpr static std::uint64_t SourceColumn = 57;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(
                Attribute{"", "letadlo", std::span<const std::string_view>{EmptyAttributeArgArray}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"dzea2"};
        constexpr static auto FullName = StringLiteral{"dzea2"};
    };
    // Record pf::A member function pf::A::foo2

    template<>
    struct StaticInfo<ID{0xb651642ac8c5f237u, 0xfe0f1011e8f1b95u}> {

        constexpr static ID FunctionID = ID{0xb651642ac8c5f237u, 0xfe0f1011e8f1b95u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 53;
        constexpr static std::uint64_t SourceColumn = 26;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>(
                Attribute{"", "kjhnn", std::span<const std::string_view>{EmptyAttributeArgArray}},
                Attribute{"", "maybe_unused", std::span<const std::string_view>{EmptyAttributeArgArray}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsVirtual = true;
        constexpr static bool IsPureVirtual = false;
        constexpr static auto IsFinal = true;
        constexpr static bool IsConstexpr = false;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"foo2"};
        constexpr static auto FullName = StringLiteral{"pf::A::foo2"};

        constexpr static Info ReturnType = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};
        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0xa65963f0f043d5c8u, 0x8c4c551f4f92f2b6u});

        constexpr static int (pf::A::*MemberPtr)(int) = &pf::A::foo2;
    };
    // Record pf::A member function pf::A::letadlo

    template<>
    struct StaticInfo<ID{0x9f5d7b21263d723fu, 0xc090822c6cd77cb1u}> {

        constexpr static ID FunctionID = ID{0x9f5d7b21263d723fu, 0xc090822c6cd77cb1u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 62;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

        constexpr static bool IsPublic = false;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = true;
        constexpr static bool IsConst = false;
        constexpr static bool IsVirtual = false;
        constexpr static bool IsPureVirtual = false;
        constexpr static auto IsFinal = false;
        constexpr static bool IsConstexpr = false;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"letadlo"};
        constexpr static auto FullName = StringLiteral{"pf::A::letadlo"};

        constexpr static Info ReturnType = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};
        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();

        constexpr static int (pf::A::*MemberPtr)() = &pf::A::letadlo;
    };
    // Record pf::A member function pf::A::letadlo2

    template<>
    struct StaticInfo<ID{0xb151275a6f2b5b4bu, 0x932b3500b737d4a6u}> {

        constexpr static ID FunctionID = ID{0xb151275a6f2b5b4bu, 0x932b3500b737d4a6u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 64;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

        constexpr static bool IsPublic = false;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = true;
        constexpr static bool IsConst = false;
        constexpr static bool IsVirtual = false;
        constexpr static bool IsPureVirtual = false;
        constexpr static auto IsFinal = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"letadlo2"};
        constexpr static auto FullName = StringLiteral{"pf::A::letadlo2"};

        constexpr static Info ReturnType = ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u};
        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();

        constexpr static void (pf::A::*MemberPtr)() = &pf::A::letadlo2;
    };
    // Record pf::A member function pf::A::letadlo3 argument asdasdas

    template<>
    struct StaticInfo<ID{0x50a224288b61b5u, 0x702d04c0a935d1a1u}> {

        constexpr static ID ArgumentID = ID{0x50a224288b61b5u, 0x702d04c0a935d1a1u};
        constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 66;
        constexpr static std::uint64_t SourceColumn = 23;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"asdasdas"};
        constexpr static auto FullName = StringLiteral{"asdasdas"};
    };
    // Record pf::A member function pf::A::letadlo3

    template<>
    struct StaticInfo<ID{0x3d55f23651de9cbcu, 0x3ec37599fa78fcb3u}> {

        constexpr static ID FunctionID = ID{0x3d55f23651de9cbcu, 0x3ec37599fa78fcb3u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 66;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

        constexpr static bool IsPublic = false;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = true;
        constexpr static bool IsConst = false;
        constexpr static bool IsVirtual = false;
        constexpr static bool IsPureVirtual = false;
        constexpr static auto IsFinal = false;
        constexpr static bool IsConstexpr = false;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"letadlo3"};
        constexpr static auto FullName = StringLiteral{"pf::A::letadlo3"};

        constexpr static Info ReturnType = ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u};
        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x50a224288b61b5u, 0x702d04c0a935d1a1u});

        constexpr static void (pf::A::*MemberPtr)(int) = &pf::A::letadlo3;
    };
    // Record pf::A member variable pf::A::test

    template<>
    struct StaticInfo<ID{0x335f6f365cea35fdu, 0xab992c0c2c38a8a9u}> {

        constexpr static ID VariableID = ID{0x335f6f365cea35fdu, 0xab992c0c2c38a8a9u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 58;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsMutable = false;
        constexpr static bool IsBitfield = false;


        constexpr static auto Name = StringLiteral{"test"};
        constexpr static auto FullName = StringLiteral{"pf::A::test"};

        constexpr static int pf::A::*MemberPtr = &pf::A::test;
    };
    // Record pf::A member variable pf::A::privateVar

    template<>
    struct StaticInfo<ID{0x885025556cce2f68u, 0x589def016d4c20beu}> {

        constexpr static ID VariableID = ID{0x885025556cce2f68u, 0x589def016d4c20beu};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 68;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

        constexpr static bool IsPublic = false;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = true;
        constexpr static bool IsMutable = false;
        constexpr static bool IsBitfield = false;


        constexpr static auto Name = StringLiteral{"privateVar"};
        constexpr static auto FullName = StringLiteral{"pf::A::privateVar"};

        constexpr static int pf::A::*MemberPtr = &pf::A::privateVar;
    };
    // Record pf::A member variable pf::A::privateVar2

    template<>
    struct StaticInfo<ID{0xce5e676fefa30dafu, 0x4eb0970230b6a49eu}> {

        constexpr static ID VariableID = ID{0xce5e676fefa30dafu, 0x4eb0970230b6a49eu};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 69;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

        constexpr static bool IsPublic = false;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = true;
        constexpr static bool IsMutable = false;
        constexpr static bool IsBitfield = false;


        constexpr static auto Name = StringLiteral{"privateVar2"};
        constexpr static auto FullName = StringLiteral{"pf::A::privateVar2"};

        constexpr static int pf::A::*MemberPtr = &pf::A::privateVar2;
    };
    // Record pf::A member variable pf::A::privateVar3

    template<>
    struct StaticInfo<ID{0x85a1fc2b7924f35u, 0xab0ea2512267d8adu}> {

        constexpr static ID VariableID = ID{0x85a1fc2b7924f35u, 0xab0ea2512267d8adu};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 70;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

        constexpr static bool IsPublic = false;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = true;
        constexpr static bool IsMutable = false;
        constexpr static bool IsBitfield = false;


        constexpr static auto Name = StringLiteral{"privateVar3"};
        constexpr static auto FullName = StringLiteral{"pf::A::privateVar3"};

        constexpr static int pf::A::*MemberPtr = &pf::A::privateVar3;
    };
    // Record pf::A member variable pf::A::privateVar4

    template<>
    struct StaticInfo<ID{0x8f5f18cfb176f51cu, 0xd2107751b20304bcu}> {

        constexpr static ID VariableID = ID{0x8f5f18cfb176f51cu, 0xd2107751b20304bcu};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 71;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

        constexpr static bool IsPublic = false;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = true;
        constexpr static bool IsMutable = false;
        constexpr static bool IsBitfield = false;


        constexpr static auto Name = StringLiteral{"privateVar4"};
        constexpr static auto FullName = StringLiteral{"pf::A::privateVar4"};

        constexpr static int pf::A::*MemberPtr = &pf::A::privateVar4;
    };
    // Record pf::A static function pf::A::statFoo

    template<>
    struct StaticInfo<ID{0x645f1db97c2f0115u, 0xb3e5baae4a842bb6u}> {

        constexpr static ID FunctionID = ID{0x645f1db97c2f0115u, 0xb3e5baae4a842bb6u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 73;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::StaticFunction;

        constexpr static bool IsPublic = false;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = true;
        constexpr static bool IsConstexpr = false;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"statFoo"};
        constexpr static auto FullName = StringLiteral{"pf::A::statFoo"};

        constexpr static Info ReturnType = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};
        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();

        constexpr static int (*MemberPtr)() = &pf::A::statFoo;
    };
    // Record pf::A static variable pf::A::constexpr_test

    template<>
    struct StaticInfo<ID{0x735d748eea9251efu, 0xe50efb391449b093u}> {

        constexpr static ID VariableID = ID{0x735d748eea9251efu, 0xe50efb391449b093u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 59;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::StaticVariable;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsInline = false;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"constexpr_test"};
        constexpr static auto FullName = StringLiteral{"pf::A::constexpr_test"};

        constexpr static const int *MemberPtr = &pf::A::constexpr_test;
    };
    // Record pf::A static variable pf::A::statValue

    template<>
    struct StaticInfo<ID{0x5353cb42e1a5c7a7u, 0x962a030897c298a4u}> {

        constexpr static ID VariableID = ID{0x5353cb42e1a5c7a7u, 0x962a030897c298a4u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 75;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::StaticVariable;

        constexpr static bool IsPublic = false;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = true;
        constexpr static bool IsConstexpr = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = true;

        constexpr static auto Name = StringLiteral{"statValue"};
        constexpr static auto FullName = StringLiteral{"pf::A::statValue"};

        constexpr static int *MemberPtr = &pf::A::statValue;
    };
    // Record pf::A **END**// Record pf::B, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:78:5
    template<>
    struct StaticInfo<ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u}> {

        using Type = pf::B;
        constexpr static ID TypeID = ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 78;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::RecordType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"B"};
        constexpr static auto FullName = StringLiteral{"pf::B"};

        constexpr static bool IsUnion = false;
        constexpr static bool IsClass = false;
        constexpr static bool IsStruct = true;
        constexpr static bool IsPolymorphic = true;
        constexpr static bool IsAbstract = true;
        constexpr static bool IsFinal = false;
        constexpr static RangeOf<Info> auto Bases = pf::meta::details::make_array<Info>();
        constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>(
                ID{0x5054a98cf7c8fcadu, 0x81e0621d5301d4acu}, ID{0x60534a54fb82e7eau, 0x240c895305848f89u});
        constexpr static Info Destructor = ID{0xa9567d344d82809fu, 0x2a140755952d40a2u};
        constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>(
                ID{0x14548f9a1ac7b3f4u, 0x63470a5671596a9cu}, ID{0x9a540d1f2173f3b4u, 0xfbf9d130859343aeu},
                ID{0x965777e730c4cd33u, 0x7bd57bfc8590c3a1u});
        constexpr static RangeOf<Info> auto StaticFunctions = pf::meta::details::make_array<Info>();
        constexpr static RangeOf<Info> auto MemberVariables = pf::meta::details::make_array<Info>();
        constexpr static RangeOf<Info> auto StaticVariables = pf::meta::details::make_array<Info>();
    };

    // const
    template<>
    struct StaticInfo<ID{0x9e533a49fded64abu, 0x83055bf08667c183u}>
        : StaticInfo_ConstWrap<ID{0x9e533a49fded64abu, 0x83055bf08667c183u}, ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u}> {};
    // &
    template<>
    struct StaticInfo<ID{0xde5a2a4c0b86749du, 0x89b8891279284797u}>
        : StaticInfo_LRefWrap<ID{0xde5a2a4c0b86749du, 0x89b8891279284797u}, ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u}> {};
    // &&
    template<>
    struct StaticInfo<ID{0x3a586acdd38940a8u, 0xe99ee2c9bcebd4a5u}>
        : StaticInfo_RRefWrap<ID{0x3a586acdd38940a8u, 0xe99ee2c9bcebd4a5u}, ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u}> {};
    // const &
    template<>
    struct StaticInfo<ID{0xf25402f03dd1faa1u, 0xb03c8205bc561eb7u}>
        : StaticInfo_ConstLRefWrap<ID{0xf25402f03dd1faa1u, 0xb03c8205bc561eb7u}, ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u}> {};
    // *
    template<>
    struct StaticInfo<ID{0x315de31de2e67835u, 0xad5b007b0c47b4aau}>
        : StaticInfo_PtrWrap<ID{0x315de31de2e67835u, 0xad5b007b0c47b4aau}, ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u}> {};
    // const *
    template<>
    struct StaticInfo<ID{0xd45cb324f63b0588u, 0xf4d9056ad5ee0ab6u}>
        : StaticInfo_ConstPtrWrap<ID{0xd45cb324f63b0588u, 0xf4d9056ad5ee0ab6u}, ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u}> {};
    // Record pf::B static info getters

    template<>
    [[nodiscard]] consteval ID getTypeId<pf::B>() {
        return ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::B>() {
        return ID{0x9e533a49fded64abu, 0x83055bf08667c183u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::B &>() {
        return ID{0xde5a2a4c0b86749du, 0x89b8891279284797u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::B &&>() {
        return ID{0x3a586acdd38940a8u, 0xe99ee2c9bcebd4a5u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::B &>() {
        return ID{0xf25402f03dd1faa1u, 0xb03c8205bc561eb7u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::B *>() {
        return ID{0x315de31de2e67835u, 0xad5b007b0c47b4aau};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::B *>() {
        return ID{0xd45cb324f63b0588u, 0xf4d9056ad5ee0ab6u};
    }
    // Record pf::B constructor pf::B::B

    template<>
    struct StaticInfo<ID{0x5054a98cf7c8fcadu, 0x81e0621d5301d4acu}> {

        constexpr static ID ConstructorID = ID{0x5054a98cf7c8fcadu, 0x81e0621d5301d4acu};
        constexpr static ID TypeID = ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 78;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsExplicit = false;
        constexpr static bool IsCopy = false;
        constexpr static bool IsMove = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = true;

        constexpr static auto Name = StringLiteral{"B"};
        constexpr static auto FullName = StringLiteral{"pf::B::B"};

        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();
    };
    // Record pf::B constructor pf::B::B argument

    template<>
    struct StaticInfo<ID{0x365abff2f0dfa9b0u, 0xee28dfc88b96e596u}> {

        constexpr static ID ArgumentID = ID{0x365abff2f0dfa9b0u, 0xee28dfc88b96e596u};
        constexpr static ID TypeID = ID{0x55f9a60b5ba6255u, 0xc930b257936c4894u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 78;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{""};
        constexpr static auto FullName = StringLiteral{""};
    };
    // Record pf::B constructor pf::B::B

    template<>
    struct StaticInfo<ID{0x60534a54fb82e7eau, 0x240c895305848f89u}> {

        constexpr static ID ConstructorID = ID{0x60534a54fb82e7eau, 0x240c895305848f89u};
        constexpr static ID TypeID = ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 78;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsExplicit = false;
        constexpr static bool IsCopy = true;
        constexpr static bool IsMove = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = false;
        constexpr static bool IsInlineSpecified = true;

        constexpr static auto Name = StringLiteral{"B"};
        constexpr static auto FullName = StringLiteral{"pf::B::B"};

        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x365abff2f0dfa9b0u, 0xee28dfc88b96e596u});
    };
    // Record pf::B member function pf::B::pure_foo argument a

    template<>
    struct StaticInfo<ID{0x95d91b43cdb52d9u, 0xeaf6b4b36eb15a9cu}> {

        constexpr static ID ArgumentID = ID{0x95d91b43cdb52d9u, 0xeaf6b4b36eb15a9cu};
        constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 81;
        constexpr static std::uint64_t SourceColumn = 31;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"a"};
        constexpr static auto FullName = StringLiteral{"a"};
    };
    // Record pf::B member function pf::B::pure_foo

    template<>
    struct StaticInfo<ID{0x14548f9a1ac7b3f4u, 0x63470a5671596a9cu}> {

        constexpr static ID FunctionID = ID{0x14548f9a1ac7b3f4u, 0x63470a5671596a9cu};
        constexpr static ID TypeID = ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 81;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsVirtual = true;
        constexpr static bool IsPureVirtual = true;
        constexpr static auto IsFinal = false;
        constexpr static bool IsConstexpr = false;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = false;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"pure_foo"};
        constexpr static auto FullName = StringLiteral{"pf::B::pure_foo"};

        constexpr static Info ReturnType = ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u};
        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x95d91b43cdb52d9u, 0xeaf6b4b36eb15a9cu});

        constexpr static void (pf::B::*MemberPtr)(int) = &pf::B::pure_foo;
    };
    // Record pf::B member function pf::B::virt_foo argument a

    template<>
    struct StaticInfo<ID{0xd65776fa5768a6d5u, 0xf591252daaf0f281u}> {

        constexpr static ID ArgumentID = ID{0xd65776fa5768a6d5u, 0xf591252daaf0f281u};
        constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 83;
        constexpr static std::uint64_t SourceColumn = 31;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"a"};
        constexpr static auto FullName = StringLiteral{"a"};
    };
    // Record pf::B member function pf::B::virt_foo

    template<>
    struct StaticInfo<ID{0x9a540d1f2173f3b4u, 0xfbf9d130859343aeu}> {

        constexpr static ID FunctionID = ID{0x9a540d1f2173f3b4u, 0xfbf9d130859343aeu};
        constexpr static ID TypeID = ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 83;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsVirtual = true;
        constexpr static bool IsPureVirtual = false;
        constexpr static auto IsFinal = false;
        constexpr static bool IsConstexpr = false;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"virt_foo"};
        constexpr static auto FullName = StringLiteral{"pf::B::virt_foo"};

        constexpr static Info ReturnType = ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u};
        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0xd65776fa5768a6d5u, 0xf591252daaf0f281u});

        constexpr static void (pf::B::*MemberPtr)(int) = &pf::B::virt_foo;
    };
    // Record pf::B member function pf::B::operator= argument

    template<>
    struct StaticInfo<ID{0xfe51a31113afea5du, 0x87eabdc60d1506bbu}> {

        constexpr static ID ArgumentID = ID{0xfe51a31113afea5du, 0x87eabdc60d1506bbu};
        constexpr static ID TypeID = ID{0x55f9a60b5ba6255u, 0xc930b257936c4894u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 78;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{""};
        constexpr static auto FullName = StringLiteral{""};
    };
    // Record pf::B member function pf::B::operator=

    template<>
    struct StaticInfo<ID{0x965777e730c4cd33u, 0x7bd57bfc8590c3a1u}> {

        constexpr static ID FunctionID = ID{0x965777e730c4cd33u, 0x7bd57bfc8590c3a1u};
        constexpr static ID TypeID = ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 78;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsVirtual = false;
        constexpr static bool IsPureVirtual = false;
        constexpr static auto IsFinal = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = false;
        constexpr static bool IsInlineSpecified = true;

        constexpr static auto Name = StringLiteral{"operator="};
        constexpr static auto FullName = StringLiteral{"pf::B::operator="};

        constexpr static Info ReturnType = ID{0x44583a32e9feaff8u, 0x443dba8a6654f892u};
        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0xfe51a31113afea5du, 0x87eabdc60d1506bbu});

        constexpr static B &(pf::B::*MemberPtr)(const B &) = &pf::B::operator=;
    };
    // Record pf::B **END**// Record pf::Test, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:86:5
    template<>
    struct StaticInfo<ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u}> {

        using Type = pf::Test;
        constexpr static ID TypeID = ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 86;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::RecordType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"Test"};
        constexpr static auto FullName = StringLiteral{"pf::Test"};

        constexpr static bool IsUnion = false;
        constexpr static bool IsClass = false;
        constexpr static bool IsStruct = true;
        constexpr static bool IsPolymorphic = true;
        constexpr static bool IsAbstract = false;
        constexpr static bool IsFinal = false;
        constexpr static RangeOf<Info> auto Bases = pf::meta::details::make_array<Info>(ID{0x6e5085368a0d0f21u, 0x65514f312a361eacu},
                                                                                        ID{0x7e5fc433d1c23d10u, 0xdec5fda59ac46a0u});
        constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>(
                ID{0xc755d889c9afcfc0u, 0xa0f9a22e2a89ada4u}, ID{0x895d90ae76b9dc30u, 0xf841242b37ac00b7u},
                ID{0x5a5168cc7bb4f6a4u, 0x4bf005a81d020c9eu});
        constexpr static Info Destructor = ID{0xb75617b85f96032bu, 0x2b94d6e0162578b9u};
        constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>(
                ID{0xab50ef4c6f7fd7e0u, 0x75a84acb3f053e80u}, ID{0x5d537fe41bed167eu, 0x646f23e04ea2ec9bu},
                ID{0x645af4c043fdb70eu, 0x6e125afd7264cd8au}, ID{0x3f5dc3b0cb932998u, 0xfaac361ccb864282u},
                ID{0x3f5dc3b0cb932998u, 0xfaac361ccb864282u});
        constexpr static RangeOf<Info> auto StaticFunctions = pf::meta::details::make_array<Info>(
                ID{0xd6506c04cb46efdcu, 0x725b025b790e1a85u}, ID{0x9850e0e0103f1677u, 0x5b07408433193a86u});
        constexpr static RangeOf<Info> auto MemberVariables = pf::meta::details::make_array<Info>(
                ID{0xb658e3e39aa041fbu, 0xa8733c8d899de096u}, ID{0x76532147d735817eu, 0x1bc21ab380cb68a4u},
                ID{0x1953f73356de271cu, 0x6846635c715f8986u}, ID{0x6d5b23bda3bb5e09u, 0x624df9b94e9ab8adu});
        constexpr static RangeOf<Info> auto StaticVariables = pf::meta::details::make_array<Info>(
                ID{0xe1526a3f2692dd10u, 0xe4309a526cb96fb6u}, ID{0xa15ed0e1a6d3a97au, 0x3c69715da03789b2u});
    };

    // const
    template<>
    struct StaticInfo<ID{0x885f713ed52edd43u, 0x4ad00c420e4cebacu}>
        : StaticInfo_ConstWrap<ID{0x885f713ed52edd43u, 0x4ad00c420e4cebacu}, ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u}> {};
    // &
    template<>
    struct StaticInfo<ID{0x535907439e0eaa8bu, 0xaa251e67c7a1dfb8u}>
        : StaticInfo_LRefWrap<ID{0x535907439e0eaa8bu, 0xaa251e67c7a1dfb8u}, ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u}> {};
    // &&
    template<>
    struct StaticInfo<ID{0xbe5812ad03b80b92u, 0x5ac67cd12b292783u}>
        : StaticInfo_RRefWrap<ID{0xbe5812ad03b80b92u, 0x5ac67cd12b292783u}, ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u}> {};
    // const &
    template<>
    struct StaticInfo<ID{0x365a3f3011d34dbfu, 0x61a1602af9df91a9u}>
        : StaticInfo_ConstLRefWrap<ID{0x365a3f3011d34dbfu, 0x61a1602af9df91a9u}, ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u}> {};
    // *
    template<>
    struct StaticInfo<ID{0xee5ea045032ac904u, 0x413decc08879e4a9u}>
        : StaticInfo_PtrWrap<ID{0xee5ea045032ac904u, 0x413decc08879e4a9u}, ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u}> {};
    // const *
    template<>
    struct StaticInfo<ID{0x51561d84153a2edcu, 0x23ac6c802298bcbdu}>
        : StaticInfo_ConstPtrWrap<ID{0x51561d84153a2edcu, 0x23ac6c802298bcbdu}, ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u}> {};
    // Record pf::Test static info getters

    template<>
    [[nodiscard]] consteval ID getTypeId<pf::Test>() {
        return ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::Test>() {
        return ID{0x885f713ed52edd43u, 0x4ad00c420e4cebacu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::Test &>() {
        return ID{0x535907439e0eaa8bu, 0xaa251e67c7a1dfb8u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::Test &&>() {
        return ID{0xbe5812ad03b80b92u, 0x5ac67cd12b292783u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::Test &>() {
        return ID{0x365a3f3011d34dbfu, 0x61a1602af9df91a9u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::Test *>() {
        return ID{0xee5ea045032ac904u, 0x413decc08879e4a9u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::Test *>() {
        return ID{0x51561d84153a2edcu, 0x23ac6c802298bcbdu};
    }
    // Record pf::Test base class pf::A

    template<>
    struct StaticInfo<ID{0x6e5085368a0d0f21u, 0x65514f312a361eacu}> {

        constexpr static ID BaseID = ID{0x6e5085368a0d0f21u, 0x65514f312a361eacu};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 86;
        constexpr static std::uint64_t SourceColumn = 19;

        constexpr static auto StaticInfoObjectType = StaticInfoType::Base;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static auto IsVirtual = false;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"pf::A"};
    };
    // Record pf::Test base class pf::B

    template<>
    struct StaticInfo<ID{0x7e5fc433d1c23d10u, 0xdec5fda59ac46a0u}> {

        constexpr static ID BaseID = ID{0x7e5fc433d1c23d10u, 0xdec5fda59ac46a0u};
        constexpr static ID TypeID = ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 86;
        constexpr static std::uint64_t SourceColumn = 29;

        constexpr static auto StaticInfoObjectType = StaticInfoType::Base;

        constexpr static bool IsPublic = false;
        constexpr static bool IsProtected = true;
        constexpr static bool IsPrivate = false;
        constexpr static auto IsVirtual = false;

        constexpr static auto Name = StringLiteral{"B"};
        constexpr static auto FullName = StringLiteral{"pf::B"};
    };
    // Record pf::Test constructor pf::Test::Test

    template<>
    struct StaticInfo<ID{0xc755d889c9afcfc0u, 0xa0f9a22e2a89ada4u}> {

        constexpr static ID ConstructorID = ID{0xc755d889c9afcfc0u, 0xa0f9a22e2a89ada4u};
        constexpr static ID TypeID = ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 88;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsExplicit = false;
        constexpr static bool IsCopy = false;
        constexpr static bool IsMove = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = false;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"Test"};
        constexpr static auto FullName = StringLiteral{"pf::Test::Test"};

        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();

        constexpr static auto CtorWrap = []() constexpr -> pf::Test { return pf::Test(); };
        constexpr static auto NewCtorWrap = []() constexpr -> pf::Test * { return new pf::Test(); };
        constexpr static auto PlacementNewCtorWrap = [](void *mem) -> pf::Test * { return new (mem) pf::Test(); };
    };
    // Record pf::Test constructor pf::Test::Test argument v

    template<>
    struct StaticInfo<ID{0xfd5d101b24fffe94u, 0x912e3e1c7ca937b0u}> {

        constexpr static ID ArgumentID = ID{0xfd5d101b24fffe94u, 0x912e3e1c7ca937b0u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 90;
        constexpr static std::uint64_t SourceColumn = 33;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"v"};
        constexpr static auto FullName = StringLiteral{"v"};
    };
    // Record pf::Test constructor pf::Test::Test

    template<>
    struct StaticInfo<ID{0x895d90ae76b9dc30u, 0xf841242b37ac00b7u}> {

        constexpr static ID ConstructorID = ID{0x895d90ae76b9dc30u, 0xf841242b37ac00b7u};
        constexpr static ID TypeID = ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 90;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsExplicit = true;
        constexpr static bool IsCopy = false;
        constexpr static bool IsMove = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = true;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"Test"};
        constexpr static auto FullName = StringLiteral{"pf::Test::Test"};

        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0xfd5d101b24fffe94u, 0x912e3e1c7ca937b0u});

        constexpr static auto CtorWrap = [](std::same_as<pf::A> auto &&arg_0) consteval -> pf::Test {
            return pf::Test(std::forward<decltype(arg_0)>(arg_0));
        };
        constexpr static auto NewCtorWrap = [](std::same_as<pf::A> auto &&arg_0) consteval -> pf::Test * {
            return new pf::Test(std::forward<decltype(arg_0)>(arg_0));
        };
        constexpr static auto PlacementNewCtorWrap = [](void *mem, std::same_as<pf::A> auto &&arg_0) -> pf::Test * {
            return new (mem) pf::Test(std::forward<decltype(arg_0)>(arg_0));
        };
    };
    // Record pf::Test constructor pf::Test::Test argument v1

    template<>
    struct StaticInfo<ID{0x2051b6a0b628fd57u, 0xf8373a91778ffa8u}> {

        constexpr static ID ArgumentID = ID{0x2051b6a0b628fd57u, 0xf8373a91778ffa8u};
        constexpr static ID TypeID = ID{0x5353f353f7061791u, 0xb12d52dfd778708au};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 92;
        constexpr static std::uint64_t SourceColumn = 24;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"v1"};
        constexpr static auto FullName = StringLiteral{"v1"};
    };
    // Record pf::Test constructor pf::Test::Test argument v2

    template<>
    struct StaticInfo<ID{0x31596a28a261fc5bu, 0x361e714c0e5b6485u}> {

        constexpr static ID ArgumentID = ID{0x31596a28a261fc5bu, 0x361e714c0e5b6485u};
        constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 92;
        constexpr static std::uint64_t SourceColumn = 39;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"v2"};
        constexpr static auto FullName = StringLiteral{"v2"};
    };
    // Record pf::Test constructor pf::Test::Test

    template<>
    struct StaticInfo<ID{0x5a5168cc7bb4f6a4u, 0x4bf005a81d020c9eu}> {

        constexpr static ID ConstructorID = ID{0x5a5168cc7bb4f6a4u, 0x4bf005a81d020c9eu};
        constexpr static ID TypeID = ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 92;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsExplicit = false;
        constexpr static bool IsCopy = false;
        constexpr static bool IsMove = false;
        constexpr static bool IsConstexpr = true;
        constexpr static bool IsConsteval = true;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"Test"};
        constexpr static auto FullName = StringLiteral{"pf::Test::Test"};

        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x2051b6a0b628fd57u, 0xf8373a91778ffa8u},
                                                                                            ID{0x31596a28a261fc5bu, 0x361e714c0e5b6485u});

        constexpr static auto CtorWrap = [](const int &arg_0, std::same_as<int> auto &&arg_1) consteval -> pf::Test {
            return pf::Test(arg_0, std::forward<decltype(arg_1)>(arg_1));
        };
        constexpr static auto NewCtorWrap = [](const int &arg_0, std::same_as<int> auto &&arg_1) consteval -> pf::Test * {
            return new pf::Test(arg_0, std::forward<decltype(arg_1)>(arg_1));
        };
        constexpr static auto PlacementNewCtorWrap = [](void *mem, const int &arg_0, std::same_as<int> auto &&arg_1) -> pf::Test * {
            return new (mem) pf::Test(arg_0, std::forward<decltype(arg_1)>(arg_1));
        };
    };
    // Record pf::Test member function pf::Test::operator= argument

    template<>
    struct StaticInfo<ID{0xfe5737e6090950f5u, 0x43a06e25753804bau}> {

        constexpr static ID ArgumentID = ID{0xfe5737e6090950f5u, 0x43a06e25753804bau};
        constexpr static ID TypeID = ID{0x6357d49ffc2b2b69u, 0xf6ec18c1426ae4beu};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 96;
        constexpr static std::uint64_t SourceColumn = 25;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{""};
        constexpr static auto FullName = StringLiteral{""};
    };
    // Record pf::Test member function pf::Test::operator=

    template<>
    struct StaticInfo<ID{0xab50ef4c6f7fd7e0u, 0x75a84acb3f053e80u}> {

        constexpr static ID FunctionID = ID{0xab50ef4c6f7fd7e0u, 0x75a84acb3f053e80u};
        constexpr static ID TypeID = ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 96;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsVirtual = false;
        constexpr static bool IsPureVirtual = false;
        constexpr static auto IsFinal = false;
        constexpr static bool IsConstexpr = false;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = false;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"operator="};
        constexpr static auto FullName = StringLiteral{"pf::Test::operator="};

        constexpr static Info ReturnType = ID{0x6b50269019edd791u, 0x42cc0035b63586bbu};
        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0xfe5737e6090950f5u, 0x43a06e25753804bau});

        constexpr static Test &(pf::Test::*MemberPtr)(const Test &) = &pf::Test::operator=;
    };
    // Record pf::Test member function pf::Test::foo argument a

    template<>
    struct StaticInfo<ID{0x775c1386a52491e5u, 0x477b14e3fae922a3u}> {

        constexpr static ID ArgumentID = ID{0x775c1386a52491e5u, 0x477b14e3fae922a3u};
        constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 119;
        constexpr static std::uint64_t SourceColumn = 18;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"a"};
        constexpr static auto FullName = StringLiteral{"a"};
    };
    // Record pf::Test member function pf::Test::foo argument b

    template<>
    struct StaticInfo<ID{0xa558dd0c74bffc9du, 0xfcbc860490bc5da0u}> {

        constexpr static ID ArgumentID = ID{0xa558dd0c74bffc9du, 0xfcbc860490bc5da0u};
        constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 119;
        constexpr static std::uint64_t SourceColumn = 25;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"b"};
        constexpr static auto FullName = StringLiteral{"b"};
    };
    // Record pf::Test member function pf::Test::foo

    template<>
    struct StaticInfo<ID{0x3f5dc3b0cb932998u, 0xfaac361ccb864282u}> {

        constexpr static ID FunctionID = ID{0x3f5dc3b0cb932998u, 0xfaac361ccb864282u};
        constexpr static ID TypeID = ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 119;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberFunction;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsVirtual = false;
        constexpr static bool IsPureVirtual = false;
        constexpr static auto IsFinal = false;
        constexpr static bool IsConstexpr = false;
        constexpr static bool IsConsteval = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"foo"};
        constexpr static auto FullName = StringLiteral{"pf::Test::foo"};

        constexpr static Info ReturnType = ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u};
        constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>(ID{0x775c1386a52491e5u, 0x477b14e3fae922a3u},
                                                                                            ID{0xa558dd0c74bffc9du, 0xfcbc860490bc5da0u});

        constexpr static void (pf::Test::*MemberPtr)(int, int) = &pf::Test::foo;
    };
    // Record pf::Test member variable pf::Test::a

    template<>
    struct StaticInfo<ID{0xb658e3e39aa041fbu, 0xa8733c8d899de096u}> {

        constexpr static ID VariableID = ID{0xb658e3e39aa041fbu, 0xa8733c8d899de096u};
        constexpr static ID TypeID = ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 112;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsMutable = false;
        constexpr static bool IsBitfield = false;


        constexpr static auto Name = StringLiteral{"a"};
        constexpr static auto FullName = StringLiteral{"pf::Test::a"};

        constexpr static int pf::Test::*MemberPtr = &pf::Test::a;
    };
    // Record pf::Test member variable pf::Test::b

    template<>
    struct StaticInfo<ID{0x76532147d735817eu, 0x1bc21ab380cb68a4u}> {

        constexpr static ID VariableID = ID{0x76532147d735817eu, 0x1bc21ab380cb68a4u};
        constexpr static ID TypeID = ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 113;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsMutable = false;
        constexpr static bool IsBitfield = false;


        constexpr static auto Name = StringLiteral{"b"};
        constexpr static auto FullName = StringLiteral{"pf::Test::b"};

        constexpr static int pf::Test::*MemberPtr = &pf::Test::b;
    };
    // Record pf::Test member variable pf::Test::c

    template<>
    struct StaticInfo<ID{0x1953f73356de271cu, 0x6846635c715f8986u}> {

        constexpr static ID VariableID = ID{0x1953f73356de271cu, 0x6846635c715f8986u};
        constexpr static ID TypeID = ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 114;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsMutable = false;
        constexpr static bool IsBitfield = false;


        constexpr static auto Name = StringLiteral{"c"};
        constexpr static auto FullName = StringLiteral{"pf::Test::c"};

        constexpr static float pf::Test::*MemberPtr = &pf::Test::c;
    };
    // Record pf::Test member variable pf::Test::d

    template<>
    struct StaticInfo<ID{0x6d5b23bda3bb5e09u, 0x624df9b94e9ab8adu}> {

        constexpr static ID VariableID = ID{0x6d5b23bda3bb5e09u, 0x624df9b94e9ab8adu};
        constexpr static ID TypeID = ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 114;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsMutable = false;
        constexpr static bool IsBitfield = false;


        constexpr static auto Name = StringLiteral{"d"};
        constexpr static auto FullName = StringLiteral{"pf::Test::d"};

        constexpr static float pf::Test::*MemberPtr = &pf::Test::d;
    };
    // Record pf::Test static variable pf::Test::inline_static_int

    template<>
    struct StaticInfo<ID{0xe1526a3f2692dd10u, 0xe4309a526cb96fb6u}> {

        constexpr static ID VariableID = ID{0xe1526a3f2692dd10u, 0xe4309a526cb96fb6u};
        constexpr static ID TypeID = ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 116;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::StaticVariable;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsConstexpr = false;
        constexpr static bool IsInline = true;
        constexpr static bool IsInlineSpecified = true;

        constexpr static auto Name = StringLiteral{"inline_static_int"};
        constexpr static auto FullName = StringLiteral{"pf::Test::inline_static_int"};

        constexpr static int *MemberPtr = &pf::Test::inline_static_int;
    };
    // Record pf::Test static variable pf::Test::static_int

    template<>
    struct StaticInfo<ID{0xa15ed0e1a6d3a97au, 0x3c69715da03789b2u}> {

        constexpr static ID VariableID = ID{0xa15ed0e1a6d3a97au, 0x3c69715da03789b2u};
        constexpr static ID TypeID = ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 117;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::StaticVariable;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsConstexpr = false;
        constexpr static bool IsInline = false;
        constexpr static bool IsInlineSpecified = false;

        constexpr static auto Name = StringLiteral{"static_int"};
        constexpr static auto FullName = StringLiteral{"pf::Test::static_int"};

        constexpr static int *MemberPtr = &pf::Test::static_int;
    };
    // Record pf::Test **END**// Enum pf::EmptyEnum, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:130:5 with 0 enumerators

    template<>
    struct StaticInfo<ID{0xbc515bce03872d28u, 0x7300b5983a3fffbfu}> {

        using Type = pf::EmptyEnum;
        constexpr static ID TypeID = ID{0xbc515bce03872d28u, 0x7300b5983a3fffbfu};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 130;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"EmptyEnum"};
        constexpr static auto FullName = StringLiteral{"pf::EmptyEnum"};

        using UnderlyingType = int;
        constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
        constexpr static RangeOf<Info> auto EnumValues = pf::meta::details::make_array<Info>();
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
    // Enum pf::EmptyEnum static info getters

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
    // Enumerators of pf::EmptyEnum static info getters
    //Enum pf::EmptyEnum **END**
    // Enum pf::E1, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:133:5 with 5 enumerators
    // Enumerator pf::E1::A, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:134:9

    template<>
    struct StaticInfo<ID{0x9d50aa4fa46bdfa4u, 0xc862ecf7d777b2afu}> {

        constexpr static ID ValueID = ID{0x9d50aa4fa46bdfa4u, 0xc862ecf7d777b2afu};
        constexpr static ID TypeID = ID{0x9d50aa4fa46bdfa4u, 0xc862ecf7d777b2afu};
        using Type = pf::E1;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 134;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"pf::E1::A"};

        constexpr static int UnderlyingValue = 0;
        constexpr static pf::E1 Value = pf::E1::A;
    };
    // Enumerator pf::E1::B, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:134:12

    template<>
    struct StaticInfo<ID{0x595dcd37a6727fe4u, 0x74ef46b2ac478587u}> {

        constexpr static ID ValueID = ID{0x595dcd37a6727fe4u, 0x74ef46b2ac478587u};
        constexpr static ID TypeID = ID{0x595dcd37a6727fe4u, 0x74ef46b2ac478587u};
        using Type = pf::E1;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 134;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"B"};
        constexpr static auto FullName = StringLiteral{"pf::E1::B"};

        constexpr static int UnderlyingValue = 1;
        constexpr static pf::E1 Value = pf::E1::B;
    };
    // Enumerator pf::E1::C, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:134:15

    template<>
    struct StaticInfo<ID{0x205bf6051910e295u, 0x5ae8dcf71bfbdcb6u}> {

        constexpr static ID ValueID = ID{0x205bf6051910e295u, 0x5ae8dcf71bfbdcb6u};
        constexpr static ID TypeID = ID{0x205bf6051910e295u, 0x5ae8dcf71bfbdcb6u};
        using Type = pf::E1;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 134;
        constexpr static std::uint64_t SourceColumn = 15;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"C"};
        constexpr static auto FullName = StringLiteral{"pf::E1::C"};

        constexpr static int UnderlyingValue = 2;
        constexpr static pf::E1 Value = pf::E1::C;
    };
    // Enumerator pf::E1::D, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:134:18

    template<>
    struct StaticInfo<ID{0x64539613f69a90ccu, 0xf19e907dde2d15b4u}> {

        constexpr static ID ValueID = ID{0x64539613f69a90ccu, 0xf19e907dde2d15b4u};
        constexpr static ID TypeID = ID{0x64539613f69a90ccu, 0xf19e907dde2d15b4u};
        using Type = pf::E1;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 134;
        constexpr static std::uint64_t SourceColumn = 18;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"D"};
        constexpr static auto FullName = StringLiteral{"pf::E1::D"};

        constexpr static int UnderlyingValue = 3;
        constexpr static pf::E1 Value = pf::E1::D;
    };
    // Enumerator pf::E1::E, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:134:21

    template<>
    struct StaticInfo<ID{0x3250235a3573c873u, 0x42b3217684717a94u}> {

        constexpr static ID ValueID = ID{0x3250235a3573c873u, 0x42b3217684717a94u};
        constexpr static ID TypeID = ID{0x3250235a3573c873u, 0x42b3217684717a94u};
        using Type = pf::E1;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 134;
        constexpr static std::uint64_t SourceColumn = 21;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"E"};
        constexpr static auto FullName = StringLiteral{"pf::E1::E"};

        constexpr static int UnderlyingValue = 4;
        constexpr static pf::E1 Value = pf::E1::E;
    };

    template<>
    struct StaticInfo<ID{0xcb504f03088f9c56u, 0x8c9993d9c0f5e49eu}> {

        using Type = pf::E1;
        constexpr static ID TypeID = ID{0xcb504f03088f9c56u, 0x8c9993d9c0f5e49eu};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 133;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"E1"};
        constexpr static auto FullName = StringLiteral{"pf::E1"};

        using UnderlyingType = int;
        constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
        constexpr static RangeOf<Info> auto EnumValues = pf::meta::details::make_array<Info>(
                ID{0x9d50aa4fa46bdfa4u, 0xc862ecf7d777b2afu}, ID{0x595dcd37a6727fe4u, 0x74ef46b2ac478587u},
                ID{0x205bf6051910e295u, 0x5ae8dcf71bfbdcb6u}, ID{0x64539613f69a90ccu, 0xf19e907dde2d15b4u},
                ID{0x3250235a3573c873u, 0x42b3217684717a94u});
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
    // Enum pf::E1 static info getters

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
    // Enumerators of pf::E1 static info getters

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E1::A>() {
        return ID{0x9d50aa4fa46bdfa4u, 0xc862ecf7d777b2afu};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E1::B>() {
        return ID{0x595dcd37a6727fe4u, 0x74ef46b2ac478587u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E1::C>() {
        return ID{0x205bf6051910e295u, 0x5ae8dcf71bfbdcb6u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E1::D>() {
        return ID{0x64539613f69a90ccu, 0xf19e907dde2d15b4u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E1::E>() {
        return ID{0x3250235a3573c873u, 0x42b3217684717a94u};
    }
    //Enum pf::E1 **END**
    // Enum pf::E2, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:136:5 with 5 enumerators
    // Enumerator pf::E2::A, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:137:9

    template<>
    struct StaticInfo<ID{0x635d3ca13ef42527u, 0x926874a0b56e4d98u}> {

        constexpr static ID ValueID = ID{0x635d3ca13ef42527u, 0x926874a0b56e4d98u};
        constexpr static ID TypeID = ID{0x635d3ca13ef42527u, 0x926874a0b56e4d98u};
        using Type = pf::E2;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 137;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"pf::E2::A"};

        constexpr static int UnderlyingValue = 0;
        constexpr static pf::E2 Value = pf::E2::A;
    };
    // Enumerator pf::E2::B, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:137:12

    template<>
    struct StaticInfo<ID{0x7c535d5df511eefcu, 0xdd4fa2d6af643589u}> {

        constexpr static ID ValueID = ID{0x7c535d5df511eefcu, 0xdd4fa2d6af643589u};
        constexpr static ID TypeID = ID{0x7c535d5df511eefcu, 0xdd4fa2d6af643589u};
        using Type = pf::E2;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 137;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"B"};
        constexpr static auto FullName = StringLiteral{"pf::E2::B"};

        constexpr static int UnderlyingValue = 1;
        constexpr static pf::E2 Value = pf::E2::B;
    };
    // Enumerator pf::E2::C, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:137:15

    template<>
    struct StaticInfo<ID{0x48520c952de8ce9eu, 0x270ba43d59fa6e80u}> {

        constexpr static ID ValueID = ID{0x48520c952de8ce9eu, 0x270ba43d59fa6e80u};
        constexpr static ID TypeID = ID{0x48520c952de8ce9eu, 0x270ba43d59fa6e80u};
        using Type = pf::E2;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 137;
        constexpr static std::uint64_t SourceColumn = 15;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"C"};
        constexpr static auto FullName = StringLiteral{"pf::E2::C"};

        constexpr static int UnderlyingValue = 2;
        constexpr static pf::E2 Value = pf::E2::C;
    };
    // Enumerator pf::E2::D, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:137:18

    template<>
    struct StaticInfo<ID{0xcf5fd20c8dafe0ecu, 0xec6dbae7b8749aa7u}> {

        constexpr static ID ValueID = ID{0xcf5fd20c8dafe0ecu, 0xec6dbae7b8749aa7u};
        constexpr static ID TypeID = ID{0xcf5fd20c8dafe0ecu, 0xec6dbae7b8749aa7u};
        using Type = pf::E2;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 137;
        constexpr static std::uint64_t SourceColumn = 18;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"D"};
        constexpr static auto FullName = StringLiteral{"pf::E2::D"};

        constexpr static int UnderlyingValue = 3;
        constexpr static pf::E2 Value = pf::E2::D;
    };
    // Enumerator pf::E2::E, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:137:21

    template<>
    struct StaticInfo<ID{0x255e76386f8dd690u, 0xce149b18d56a2182u}> {

        constexpr static ID ValueID = ID{0x255e76386f8dd690u, 0xce149b18d56a2182u};
        constexpr static ID TypeID = ID{0x255e76386f8dd690u, 0xce149b18d56a2182u};
        using Type = pf::E2;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 137;
        constexpr static std::uint64_t SourceColumn = 21;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"E"};
        constexpr static auto FullName = StringLiteral{"pf::E2::E"};

        constexpr static int UnderlyingValue = 4;
        constexpr static pf::E2 Value = pf::E2::E;
    };

    template<>
    struct StaticInfo<ID{0x2c56b110e5dd6324u, 0xf3c6ad1f22f4d28au}> {

        using Type = pf::E2;
        constexpr static ID TypeID = ID{0x2c56b110e5dd6324u, 0xf3c6ad1f22f4d28au};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 136;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"E2"};
        constexpr static auto FullName = StringLiteral{"pf::E2"};

        using UnderlyingType = int;
        constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
        constexpr static RangeOf<Info> auto EnumValues = pf::meta::details::make_array<Info>(
                ID{0x635d3ca13ef42527u, 0x926874a0b56e4d98u}, ID{0x7c535d5df511eefcu, 0xdd4fa2d6af643589u},
                ID{0x48520c952de8ce9eu, 0x270ba43d59fa6e80u}, ID{0xcf5fd20c8dafe0ecu, 0xec6dbae7b8749aa7u},
                ID{0x255e76386f8dd690u, 0xce149b18d56a2182u});
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
    // Enum pf::E2 static info getters

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
    // Enumerators of pf::E2 static info getters

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E2::A>() {
        return ID{0x635d3ca13ef42527u, 0x926874a0b56e4d98u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E2::B>() {
        return ID{0x7c535d5df511eefcu, 0xdd4fa2d6af643589u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E2::C>() {
        return ID{0x48520c952de8ce9eu, 0x270ba43d59fa6e80u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E2::D>() {
        return ID{0xcf5fd20c8dafe0ecu, 0xec6dbae7b8749aa7u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E2::E>() {
        return ID{0x255e76386f8dd690u, 0xce149b18d56a2182u};
    }
    //Enum pf::E2 **END**
    // Enum pf::E3, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:139:5 with 5 enumerators
    // Enumerator pf::E3::A, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:140:9

    template<>
    struct StaticInfo<ID{0x30558b4d8da1d4e3u, 0xf5b4713dcede7e81u}> {

        constexpr static ID ValueID = ID{0x30558b4d8da1d4e3u, 0xf5b4713dcede7e81u};
        constexpr static ID TypeID = ID{0x30558b4d8da1d4e3u, 0xf5b4713dcede7e81u};
        using Type = pf::E3;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 140;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"pf::E3::A"};

        constexpr static int UnderlyingValue = 0;
        constexpr static pf::E3 Value = pf::E3::A;
    };
    // Enumerator pf::E3::B, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:140:12

    template<>
    struct StaticInfo<ID{0xad592735fd7e7f43u, 0x4502901b3922dabcu}> {

        constexpr static ID ValueID = ID{0xad592735fd7e7f43u, 0x4502901b3922dabcu};
        constexpr static ID TypeID = ID{0xad592735fd7e7f43u, 0x4502901b3922dabcu};
        using Type = pf::E3;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 140;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"B"};
        constexpr static auto FullName = StringLiteral{"pf::E3::B"};

        constexpr static int UnderlyingValue = 1;
        constexpr static pf::E3 Value = pf::E3::B;
    };
    // Enumerator pf::E3::C, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:140:15

    template<>
    struct StaticInfo<ID{0x8459593ba358ccbcu, 0x86ea2641f579afbeu}> {

        constexpr static ID ValueID = ID{0x8459593ba358ccbcu, 0x86ea2641f579afbeu};
        constexpr static ID TypeID = ID{0x8459593ba358ccbcu, 0x86ea2641f579afbeu};
        using Type = pf::E3;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 140;
        constexpr static std::uint64_t SourceColumn = 15;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"C"};
        constexpr static auto FullName = StringLiteral{"pf::E3::C"};

        constexpr static int UnderlyingValue = 2;
        constexpr static pf::E3 Value = pf::E3::C;
    };
    // Enumerator pf::E3::D, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:140:18

    template<>
    struct StaticInfo<ID{0x3f5d064679ddc1b8u, 0x737ccc35c3497ba5u}> {

        constexpr static ID ValueID = ID{0x3f5d064679ddc1b8u, 0x737ccc35c3497ba5u};
        constexpr static ID TypeID = ID{0x3f5d064679ddc1b8u, 0x737ccc35c3497ba5u};
        using Type = pf::E3;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 140;
        constexpr static std::uint64_t SourceColumn = 18;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"D"};
        constexpr static auto FullName = StringLiteral{"pf::E3::D"};

        constexpr static int UnderlyingValue = 3;
        constexpr static pf::E3 Value = pf::E3::D;
    };
    // Enumerator pf::E3::E, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:140:21

    template<>
    struct StaticInfo<ID{0xe1523b0807bc3f28u, 0x837ba27cb53629bu}> {

        constexpr static ID ValueID = ID{0xe1523b0807bc3f28u, 0x837ba27cb53629bu};
        constexpr static ID TypeID = ID{0xe1523b0807bc3f28u, 0x837ba27cb53629bu};
        using Type = pf::E3;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 140;
        constexpr static std::uint64_t SourceColumn = 21;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"E"};
        constexpr static auto FullName = StringLiteral{"pf::E3::E"};

        constexpr static int UnderlyingValue = 4;
        constexpr static pf::E3 Value = pf::E3::E;
    };

    template<>
    struct StaticInfo<ID{0x525020d591a873a1u, 0x583e908c00632d8bu}> {

        using Type = pf::E3;
        constexpr static ID TypeID = ID{0x525020d591a873a1u, 0x583e908c00632d8bu};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 139;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"E3"};
        constexpr static auto FullName = StringLiteral{"pf::E3"};

        using UnderlyingType = int;
        constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
        constexpr static RangeOf<Info> auto EnumValues = pf::meta::details::make_array<Info>(
                ID{0x30558b4d8da1d4e3u, 0xf5b4713dcede7e81u}, ID{0xad592735fd7e7f43u, 0x4502901b3922dabcu},
                ID{0x8459593ba358ccbcu, 0x86ea2641f579afbeu}, ID{0x3f5d064679ddc1b8u, 0x737ccc35c3497ba5u},
                ID{0xe1523b0807bc3f28u, 0x837ba27cb53629bu});
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
    // Enum pf::E3 static info getters

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
    // Enumerators of pf::E3 static info getters

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E3::A>() {
        return ID{0x30558b4d8da1d4e3u, 0xf5b4713dcede7e81u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E3::B>() {
        return ID{0xad592735fd7e7f43u, 0x4502901b3922dabcu};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E3::C>() {
        return ID{0x8459593ba358ccbcu, 0x86ea2641f579afbeu};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E3::D>() {
        return ID{0x3f5d064679ddc1b8u, 0x737ccc35c3497ba5u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E3::E>() {
        return ID{0xe1523b0807bc3f28u, 0x837ba27cb53629bu};
    }
    //Enum pf::E3 **END**
    // Enum pf::E4, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:142:5 with 5 enumerators
    // Enumerator pf::E4::A, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:143:9

    template<>
    struct StaticInfo<ID{0x9253c311ecece739u, 0xe7621ff79d829eabu}> {

        constexpr static ID ValueID = ID{0x9253c311ecece739u, 0xe7621ff79d829eabu};
        constexpr static ID TypeID = ID{0x9253c311ecece739u, 0xe7621ff79d829eabu};
        using Type = pf::E4;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 143;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"pf::E4::A"};

        constexpr static int UnderlyingValue = 0;
        constexpr static pf::E4 Value = pf::E4::A;
    };
    // Enumerator pf::E4::B, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:143:12

    template<>
    struct StaticInfo<ID{0x6a5ecc8fbe343a3bu, 0x337a1ef7dd35cbb7u}> {

        constexpr static ID ValueID = ID{0x6a5ecc8fbe343a3bu, 0x337a1ef7dd35cbb7u};
        constexpr static ID TypeID = ID{0x6a5ecc8fbe343a3bu, 0x337a1ef7dd35cbb7u};
        using Type = pf::E4;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 143;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"B"};
        constexpr static auto FullName = StringLiteral{"pf::E4::B"};

        constexpr static int UnderlyingValue = 1;
        constexpr static pf::E4 Value = pf::E4::B;
    };
    // Enumerator pf::E4::C, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:143:15

    template<>
    struct StaticInfo<ID{0xe35f3808a849b890u, 0x9cdc0e68a25b48au}> {

        constexpr static ID ValueID = ID{0xe35f3808a849b890u, 0x9cdc0e68a25b48au};
        constexpr static ID TypeID = ID{0xe35f3808a849b890u, 0x9cdc0e68a25b48au};
        using Type = pf::E4;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 143;
        constexpr static std::uint64_t SourceColumn = 15;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"C"};
        constexpr static auto FullName = StringLiteral{"pf::E4::C"};

        constexpr static int UnderlyingValue = 2;
        constexpr static pf::E4 Value = pf::E4::C;
    };
    // Enumerator pf::E4::D, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:143:18

    template<>
    struct StaticInfo<ID{0x3057eac37dc96baau, 0x2ddea432523c71a6u}> {

        constexpr static ID ValueID = ID{0x3057eac37dc96baau, 0x2ddea432523c71a6u};
        constexpr static ID TypeID = ID{0x3057eac37dc96baau, 0x2ddea432523c71a6u};
        using Type = pf::E4;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 143;
        constexpr static std::uint64_t SourceColumn = 18;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"D"};
        constexpr static auto FullName = StringLiteral{"pf::E4::D"};

        constexpr static int UnderlyingValue = 3;
        constexpr static pf::E4 Value = pf::E4::D;
    };
    // Enumerator pf::E4::E, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:143:21

    template<>
    struct StaticInfo<ID{0x4e56d3c60af2903du, 0x9db9fc94bea8d8a7u}> {

        constexpr static ID ValueID = ID{0x4e56d3c60af2903du, 0x9db9fc94bea8d8a7u};
        constexpr static ID TypeID = ID{0x4e56d3c60af2903du, 0x9db9fc94bea8d8a7u};
        using Type = pf::E4;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 143;
        constexpr static std::uint64_t SourceColumn = 21;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"E"};
        constexpr static auto FullName = StringLiteral{"pf::E4::E"};

        constexpr static int UnderlyingValue = 4;
        constexpr static pf::E4 Value = pf::E4::E;
    };

    template<>
    struct StaticInfo<ID{0x3754a7ca70bd9772u, 0xff2988dc42d54f86u}> {

        using Type = pf::E4;
        constexpr static ID TypeID = ID{0x3754a7ca70bd9772u, 0xff2988dc42d54f86u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 142;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"E4"};
        constexpr static auto FullName = StringLiteral{"pf::E4"};

        using UnderlyingType = int;
        constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
        constexpr static RangeOf<Info> auto EnumValues = pf::meta::details::make_array<Info>(
                ID{0x9253c311ecece739u, 0xe7621ff79d829eabu}, ID{0x6a5ecc8fbe343a3bu, 0x337a1ef7dd35cbb7u},
                ID{0xe35f3808a849b890u, 0x9cdc0e68a25b48au}, ID{0x3057eac37dc96baau, 0x2ddea432523c71a6u},
                ID{0x4e56d3c60af2903du, 0x9db9fc94bea8d8a7u});
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
    // Enum pf::E4 static info getters

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
    // Enumerators of pf::E4 static info getters

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E4::A>() {
        return ID{0x9253c311ecece739u, 0xe7621ff79d829eabu};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E4::B>() {
        return ID{0x6a5ecc8fbe343a3bu, 0x337a1ef7dd35cbb7u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E4::C>() {
        return ID{0xe35f3808a849b890u, 0x9cdc0e68a25b48au};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E4::D>() {
        return ID{0x3057eac37dc96baau, 0x2ddea432523c71a6u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E4::E>() {
        return ID{0x4e56d3c60af2903du, 0x9db9fc94bea8d8a7u};
    }
    //Enum pf::E4 **END**
    // Enum pf::E5, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:145:5 with 5 enumerators
    // Enumerator pf::E5::A, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:146:9

    template<>
    struct StaticInfo<ID{0xf258fa8ec1e8c0ecu, 0xbd7643b85da095aau}> {

        constexpr static ID ValueID = ID{0xf258fa8ec1e8c0ecu, 0xbd7643b85da095aau};
        constexpr static ID TypeID = ID{0xf258fa8ec1e8c0ecu, 0xbd7643b85da095aau};
        using Type = pf::E5;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 146;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"pf::E5::A"};

        constexpr static int UnderlyingValue = 0;
        constexpr static pf::E5 Value = pf::E5::A;
    };
    // Enumerator pf::E5::B, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:146:12

    template<>
    struct StaticInfo<ID{0x775ab7f4c9149231u, 0x544a925355408da6u}> {

        constexpr static ID ValueID = ID{0x775ab7f4c9149231u, 0x544a925355408da6u};
        constexpr static ID TypeID = ID{0x775ab7f4c9149231u, 0x544a925355408da6u};
        using Type = pf::E5;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 146;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"B"};
        constexpr static auto FullName = StringLiteral{"pf::E5::B"};

        constexpr static int UnderlyingValue = 1;
        constexpr static pf::E5 Value = pf::E5::B;
    };
    // Enumerator pf::E5::C, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:146:15

    template<>
    struct StaticInfo<ID{0xe958c5f0d721ff19u, 0xc9c68c235e2542a4u}> {

        constexpr static ID ValueID = ID{0xe958c5f0d721ff19u, 0xc9c68c235e2542a4u};
        constexpr static ID TypeID = ID{0xe958c5f0d721ff19u, 0xc9c68c235e2542a4u};
        using Type = pf::E5;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 146;
        constexpr static std::uint64_t SourceColumn = 15;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"C"};
        constexpr static auto FullName = StringLiteral{"pf::E5::C"};

        constexpr static int UnderlyingValue = 2;
        constexpr static pf::E5 Value = pf::E5::C;
    };
    // Enumerator pf::E5::D, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:146:18

    template<>
    struct StaticInfo<ID{0x2755ec3455c47b4eu, 0x8611d8b64c3eb695u}> {

        constexpr static ID ValueID = ID{0x2755ec3455c47b4eu, 0x8611d8b64c3eb695u};
        constexpr static ID TypeID = ID{0x2755ec3455c47b4eu, 0x8611d8b64c3eb695u};
        using Type = pf::E5;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 146;
        constexpr static std::uint64_t SourceColumn = 18;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"D"};
        constexpr static auto FullName = StringLiteral{"pf::E5::D"};

        constexpr static int UnderlyingValue = 3;
        constexpr static pf::E5 Value = pf::E5::D;
    };
    // Enumerator pf::E5::E, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:146:21

    template<>
    struct StaticInfo<ID{0x2f5033660c664b4au, 0x5765cd1d5d78f98eu}> {

        constexpr static ID ValueID = ID{0x2f5033660c664b4au, 0x5765cd1d5d78f98eu};
        constexpr static ID TypeID = ID{0x2f5033660c664b4au, 0x5765cd1d5d78f98eu};
        using Type = pf::E5;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 146;
        constexpr static std::uint64_t SourceColumn = 21;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"E"};
        constexpr static auto FullName = StringLiteral{"pf::E5::E"};

        constexpr static int UnderlyingValue = 4;
        constexpr static pf::E5 Value = pf::E5::E;
    };

    template<>
    struct StaticInfo<ID{0x6d55aed9c281d2dcu, 0x9e8f002a31c3258eu}> {

        using Type = pf::E5;
        constexpr static ID TypeID = ID{0x6d55aed9c281d2dcu, 0x9e8f002a31c3258eu};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 145;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"E5"};
        constexpr static auto FullName = StringLiteral{"pf::E5"};

        using UnderlyingType = int;
        constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
        constexpr static RangeOf<Info> auto EnumValues = pf::meta::details::make_array<Info>(
                ID{0xf258fa8ec1e8c0ecu, 0xbd7643b85da095aau}, ID{0x775ab7f4c9149231u, 0x544a925355408da6u},
                ID{0xe958c5f0d721ff19u, 0xc9c68c235e2542a4u}, ID{0x2755ec3455c47b4eu, 0x8611d8b64c3eb695u},
                ID{0x2f5033660c664b4au, 0x5765cd1d5d78f98eu});
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
    // Enum pf::E5 static info getters

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
    // Enumerators of pf::E5 static info getters

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E5::A>() {
        return ID{0xf258fa8ec1e8c0ecu, 0xbd7643b85da095aau};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E5::B>() {
        return ID{0x775ab7f4c9149231u, 0x544a925355408da6u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E5::C>() {
        return ID{0xe958c5f0d721ff19u, 0xc9c68c235e2542a4u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E5::D>() {
        return ID{0x2755ec3455c47b4eu, 0x8611d8b64c3eb695u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E5::E>() {
        return ID{0x2f5033660c664b4au, 0x5765cd1d5d78f98eu};
    }
    //Enum pf::E5 **END**
    // Enum pf::E6, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:148:5 with 5 enumerators
    // Enumerator pf::E6::A, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:149:9

    template<>
    struct StaticInfo<ID{0x4854a8d88681b84bu, 0x26e2a23de2f27f87u}> {

        constexpr static ID ValueID = ID{0x4854a8d88681b84bu, 0x26e2a23de2f27f87u};
        constexpr static ID TypeID = ID{0x4854a8d88681b84bu, 0x26e2a23de2f27f87u};
        using Type = pf::E6;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 149;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"pf::E6::A"};

        constexpr static int UnderlyingValue = 0;
        constexpr static pf::E6 Value = pf::E6::A;
    };
    // Enumerator pf::E6::B, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:149:12

    template<>
    struct StaticInfo<ID{0xed5a98fdb027bdd5u, 0xe70fd8b8c3021e85u}> {

        constexpr static ID ValueID = ID{0xed5a98fdb027bdd5u, 0xe70fd8b8c3021e85u};
        constexpr static ID TypeID = ID{0xed5a98fdb027bdd5u, 0xe70fd8b8c3021e85u};
        using Type = pf::E6;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 149;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"B"};
        constexpr static auto FullName = StringLiteral{"pf::E6::B"};

        constexpr static int UnderlyingValue = 1;
        constexpr static pf::E6 Value = pf::E6::B;
    };
    // Enumerator pf::E6::C, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:149:15

    template<>
    struct StaticInfo<ID{0x145ab2a4e82ec74cu, 0xe83a8af4541312abu}> {

        constexpr static ID ValueID = ID{0x145ab2a4e82ec74cu, 0xe83a8af4541312abu};
        constexpr static ID TypeID = ID{0x145ab2a4e82ec74cu, 0xe83a8af4541312abu};
        using Type = pf::E6;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 149;
        constexpr static std::uint64_t SourceColumn = 15;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"C"};
        constexpr static auto FullName = StringLiteral{"pf::E6::C"};

        constexpr static int UnderlyingValue = 2;
        constexpr static pf::E6 Value = pf::E6::C;
    };
    // Enumerator pf::E6::D, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:149:18

    template<>
    struct StaticInfo<ID{0xcd5509d4b50cafaau, 0xa5de537e1f5e5285u}> {

        constexpr static ID ValueID = ID{0xcd5509d4b50cafaau, 0xa5de537e1f5e5285u};
        constexpr static ID TypeID = ID{0xcd5509d4b50cafaau, 0xa5de537e1f5e5285u};
        using Type = pf::E6;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 149;
        constexpr static std::uint64_t SourceColumn = 18;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"D"};
        constexpr static auto FullName = StringLiteral{"pf::E6::D"};

        constexpr static int UnderlyingValue = 3;
        constexpr static pf::E6 Value = pf::E6::D;
    };
    // Enumerator pf::E6::E, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:149:21

    template<>
    struct StaticInfo<ID{0xc353858ae9d10a9au, 0xfe2cbf5cf6e5b2a7u}> {

        constexpr static ID ValueID = ID{0xc353858ae9d10a9au, 0xfe2cbf5cf6e5b2a7u};
        constexpr static ID TypeID = ID{0xc353858ae9d10a9au, 0xfe2cbf5cf6e5b2a7u};
        using Type = pf::E6;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 149;
        constexpr static std::uint64_t SourceColumn = 21;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"E"};
        constexpr static auto FullName = StringLiteral{"pf::E6::E"};

        constexpr static int UnderlyingValue = 4;
        constexpr static pf::E6 Value = pf::E6::E;
    };

    template<>
    struct StaticInfo<ID{0x545c6f4edc5d5b2du, 0xa3e64f9af1ad75bcu}> {

        using Type = pf::E6;
        constexpr static ID TypeID = ID{0x545c6f4edc5d5b2du, 0xa3e64f9af1ad75bcu};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 148;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"E6"};
        constexpr static auto FullName = StringLiteral{"pf::E6"};

        using UnderlyingType = int;
        constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
        constexpr static RangeOf<Info> auto EnumValues = pf::meta::details::make_array<Info>(
                ID{0x4854a8d88681b84bu, 0x26e2a23de2f27f87u}, ID{0xed5a98fdb027bdd5u, 0xe70fd8b8c3021e85u},
                ID{0x145ab2a4e82ec74cu, 0xe83a8af4541312abu}, ID{0xcd5509d4b50cafaau, 0xa5de537e1f5e5285u},
                ID{0xc353858ae9d10a9au, 0xfe2cbf5cf6e5b2a7u});
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
    // Enum pf::E6 static info getters

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
    // Enumerators of pf::E6 static info getters

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E6::A>() {
        return ID{0x4854a8d88681b84bu, 0x26e2a23de2f27f87u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E6::B>() {
        return ID{0xed5a98fdb027bdd5u, 0xe70fd8b8c3021e85u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E6::C>() {
        return ID{0x145ab2a4e82ec74cu, 0xe83a8af4541312abu};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E6::D>() {
        return ID{0xcd5509d4b50cafaau, 0xa5de537e1f5e5285u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E6::E>() {
        return ID{0xc353858ae9d10a9au, 0xfe2cbf5cf6e5b2a7u};
    }
    //Enum pf::E6 **END**
    // Enum pf::E7, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:151:5 with 5 enumerators
    // Enumerator pf::E7::A, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:152:9

    template<>
    struct StaticInfo<ID{0x2b5b1ae3f274690eu, 0x18d0d2397975848du}> {

        constexpr static ID ValueID = ID{0x2b5b1ae3f274690eu, 0x18d0d2397975848du};
        constexpr static ID TypeID = ID{0x2b5b1ae3f274690eu, 0x18d0d2397975848du};
        using Type = pf::E7;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 152;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"pf::E7::A"};

        constexpr static int UnderlyingValue = 0;
        constexpr static pf::E7 Value = pf::E7::A;
    };
    // Enumerator pf::E7::B, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:152:12

    template<>
    struct StaticInfo<ID{0xaa5f78c580a48aacu, 0x3ebd7d80946b0f9au}> {

        constexpr static ID ValueID = ID{0xaa5f78c580a48aacu, 0x3ebd7d80946b0f9au};
        constexpr static ID TypeID = ID{0xaa5f78c580a48aacu, 0x3ebd7d80946b0f9au};
        using Type = pf::E7;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 152;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"B"};
        constexpr static auto FullName = StringLiteral{"pf::E7::B"};

        constexpr static int UnderlyingValue = 1;
        constexpr static pf::E7 Value = pf::E7::B;
    };
    // Enumerator pf::E7::C, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:152:15

    template<>
    struct StaticInfo<ID{0xb357fe6bc61228cau, 0x10640ea39d25118eu}> {

        constexpr static ID ValueID = ID{0xb357fe6bc61228cau, 0x10640ea39d25118eu};
        constexpr static ID TypeID = ID{0xb357fe6bc61228cau, 0x10640ea39d25118eu};
        using Type = pf::E7;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 152;
        constexpr static std::uint64_t SourceColumn = 15;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"C"};
        constexpr static auto FullName = StringLiteral{"pf::E7::C"};

        constexpr static int UnderlyingValue = 2;
        constexpr static pf::E7 Value = pf::E7::C;
    };
    // Enumerator pf::E7::D, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:152:18

    template<>
    struct StaticInfo<ID{0x245d186999e6c332u, 0x4e620d1a30ac5faau}> {

        constexpr static ID ValueID = ID{0x245d186999e6c332u, 0x4e620d1a30ac5faau};
        constexpr static ID TypeID = ID{0x245d186999e6c332u, 0x4e620d1a30ac5faau};
        using Type = pf::E7;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 152;
        constexpr static std::uint64_t SourceColumn = 18;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"D"};
        constexpr static auto FullName = StringLiteral{"pf::E7::D"};

        constexpr static int UnderlyingValue = 3;
        constexpr static pf::E7 Value = pf::E7::D;
    };
    // Enumerator pf::E7::E, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:152:21

    template<>
    struct StaticInfo<ID{0x295844551cab62c5u, 0x7903a16c636341bcu}> {

        constexpr static ID ValueID = ID{0x295844551cab62c5u, 0x7903a16c636341bcu};
        constexpr static ID TypeID = ID{0x295844551cab62c5u, 0x7903a16c636341bcu};
        using Type = pf::E7;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 152;
        constexpr static std::uint64_t SourceColumn = 21;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"E"};
        constexpr static auto FullName = StringLiteral{"pf::E7::E"};

        constexpr static int UnderlyingValue = 4;
        constexpr static pf::E7 Value = pf::E7::E;
    };

    template<>
    struct StaticInfo<ID{0xd15b25619c40a2efu, 0x28201a793f4beebau}> {

        using Type = pf::E7;
        constexpr static ID TypeID = ID{0xd15b25619c40a2efu, 0x28201a793f4beebau};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 151;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"E7"};
        constexpr static auto FullName = StringLiteral{"pf::E7"};

        using UnderlyingType = int;
        constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
        constexpr static RangeOf<Info> auto EnumValues = pf::meta::details::make_array<Info>(
                ID{0x2b5b1ae3f274690eu, 0x18d0d2397975848du}, ID{0xaa5f78c580a48aacu, 0x3ebd7d80946b0f9au},
                ID{0xb357fe6bc61228cau, 0x10640ea39d25118eu}, ID{0x245d186999e6c332u, 0x4e620d1a30ac5faau},
                ID{0x295844551cab62c5u, 0x7903a16c636341bcu});
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
    // Enum pf::E7 static info getters

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
    // Enumerators of pf::E7 static info getters

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E7::A>() {
        return ID{0x2b5b1ae3f274690eu, 0x18d0d2397975848du};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E7::B>() {
        return ID{0xaa5f78c580a48aacu, 0x3ebd7d80946b0f9au};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E7::C>() {
        return ID{0xb357fe6bc61228cau, 0x10640ea39d25118eu};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E7::D>() {
        return ID{0x245d186999e6c332u, 0x4e620d1a30ac5faau};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E7::E>() {
        return ID{0x295844551cab62c5u, 0x7903a16c636341bcu};
    }
    //Enum pf::E7 **END**
    // Enum pf::E8, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:154:5 with 5 enumerators
    // Enumerator pf::E8::A, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:155:9

    template<>
    struct StaticInfo<ID{0xe52a125c373eb03u, 0x408eb8c6dba87485u}> {

        constexpr static ID ValueID = ID{0xe52a125c373eb03u, 0x408eb8c6dba87485u};
        constexpr static ID TypeID = ID{0xe52a125c373eb03u, 0x408eb8c6dba87485u};
        using Type = pf::E8;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 155;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"pf::E8::A"};

        constexpr static int UnderlyingValue = 0;
        constexpr static pf::E8 Value = pf::E8::A;
    };
    // Enumerator pf::E8::B, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:155:12

    template<>
    struct StaticInfo<ID{0x8e5e119c3a02a3cfu, 0xd71c26a8d426b7bbu}> {

        constexpr static ID ValueID = ID{0x8e5e119c3a02a3cfu, 0xd71c26a8d426b7bbu};
        constexpr static ID TypeID = ID{0x8e5e119c3a02a3cfu, 0xd71c26a8d426b7bbu};
        using Type = pf::E8;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 155;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"B"};
        constexpr static auto FullName = StringLiteral{"pf::E8::B"};

        constexpr static int UnderlyingValue = 1;
        constexpr static pf::E8 Value = pf::E8::B;
    };
    // Enumerator pf::E8::C, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:155:15

    template<>
    struct StaticInfo<ID{0xcf556f61c39e8b66u, 0x47b9d97489392a81u}> {

        constexpr static ID ValueID = ID{0xcf556f61c39e8b66u, 0x47b9d97489392a81u};
        constexpr static ID TypeID = ID{0xcf556f61c39e8b66u, 0x47b9d97489392a81u};
        using Type = pf::E8;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 155;
        constexpr static std::uint64_t SourceColumn = 15;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"C"};
        constexpr static auto FullName = StringLiteral{"pf::E8::C"};

        constexpr static int UnderlyingValue = 2;
        constexpr static pf::E8 Value = pf::E8::C;
    };
    // Enumerator pf::E8::D, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:155:18

    template<>
    struct StaticInfo<ID{0x215cc301caf59167u, 0xbe3063c46683e7b1u}> {

        constexpr static ID ValueID = ID{0x215cc301caf59167u, 0xbe3063c46683e7b1u};
        constexpr static ID TypeID = ID{0x215cc301caf59167u, 0xbe3063c46683e7b1u};
        using Type = pf::E8;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 155;
        constexpr static std::uint64_t SourceColumn = 18;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"D"};
        constexpr static auto FullName = StringLiteral{"pf::E8::D"};

        constexpr static int UnderlyingValue = 3;
        constexpr static pf::E8 Value = pf::E8::D;
    };
    // Enumerator pf::E8::E, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:155:21

    template<>
    struct StaticInfo<ID{0xbf594c204ff3dce3u, 0xd7b4b0626e0a09bu}> {

        constexpr static ID ValueID = ID{0xbf594c204ff3dce3u, 0xd7b4b0626e0a09bu};
        constexpr static ID TypeID = ID{0xbf594c204ff3dce3u, 0xd7b4b0626e0a09bu};
        using Type = pf::E8;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 155;
        constexpr static std::uint64_t SourceColumn = 21;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"E"};
        constexpr static auto FullName = StringLiteral{"pf::E8::E"};

        constexpr static int UnderlyingValue = 4;
        constexpr static pf::E8 Value = pf::E8::E;
    };

    template<>
    struct StaticInfo<ID{0xb0501ed449af7c09u, 0x622e030a4ca11ebeu}> {

        using Type = pf::E8;
        constexpr static ID TypeID = ID{0xb0501ed449af7c09u, 0x622e030a4ca11ebeu};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 154;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"E8"};
        constexpr static auto FullName = StringLiteral{"pf::E8"};

        using UnderlyingType = int;
        constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
        constexpr static RangeOf<Info> auto EnumValues = pf::meta::details::make_array<Info>(
                ID{0xe52a125c373eb03u, 0x408eb8c6dba87485u}, ID{0x8e5e119c3a02a3cfu, 0xd71c26a8d426b7bbu},
                ID{0xcf556f61c39e8b66u, 0x47b9d97489392a81u}, ID{0x215cc301caf59167u, 0xbe3063c46683e7b1u},
                ID{0xbf594c204ff3dce3u, 0xd7b4b0626e0a09bu});
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
    // Enum pf::E8 static info getters

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
    // Enumerators of pf::E8 static info getters

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E8::A>() {
        return ID{0xe52a125c373eb03u, 0x408eb8c6dba87485u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E8::B>() {
        return ID{0x8e5e119c3a02a3cfu, 0xd71c26a8d426b7bbu};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E8::C>() {
        return ID{0xcf556f61c39e8b66u, 0x47b9d97489392a81u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E8::D>() {
        return ID{0x215cc301caf59167u, 0xbe3063c46683e7b1u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E8::E>() {
        return ID{0xbf594c204ff3dce3u, 0xd7b4b0626e0a09bu};
    }
    //Enum pf::E8 **END**
    // Enum pf::E9, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:157:5 with 5 enumerators
    // Enumerator pf::E9::A, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:158:9

    template<>
    struct StaticInfo<ID{0xf558f81596978c12u, 0x6b15ad539b7777acu}> {

        constexpr static ID ValueID = ID{0xf558f81596978c12u, 0x6b15ad539b7777acu};
        constexpr static ID TypeID = ID{0xf558f81596978c12u, 0x6b15ad539b7777acu};
        using Type = pf::E9;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 158;
        constexpr static std::uint64_t SourceColumn = 9;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"pf::E9::A"};

        constexpr static int UnderlyingValue = 0;
        constexpr static pf::E9 Value = pf::E9::A;
    };
    // Enumerator pf::E9::B, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:158:12

    template<>
    struct StaticInfo<ID{0x9f55c71d60218126u, 0x75ba8c695c2485acu}> {

        constexpr static ID ValueID = ID{0x9f55c71d60218126u, 0x75ba8c695c2485acu};
        constexpr static ID TypeID = ID{0x9f55c71d60218126u, 0x75ba8c695c2485acu};
        using Type = pf::E9;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 158;
        constexpr static std::uint64_t SourceColumn = 12;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"B"};
        constexpr static auto FullName = StringLiteral{"pf::E9::B"};

        constexpr static int UnderlyingValue = 1;
        constexpr static pf::E9 Value = pf::E9::B;
    };
    // Enumerator pf::E9::C, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:158:15

    template<>
    struct StaticInfo<ID{0xf5c64589ad9f505u, 0x8931e11fbee44c9cu}> {

        constexpr static ID ValueID = ID{0xf5c64589ad9f505u, 0x8931e11fbee44c9cu};
        constexpr static ID TypeID = ID{0xf5c64589ad9f505u, 0x8931e11fbee44c9cu};
        using Type = pf::E9;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 158;
        constexpr static std::uint64_t SourceColumn = 15;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"C"};
        constexpr static auto FullName = StringLiteral{"pf::E9::C"};

        constexpr static int UnderlyingValue = 2;
        constexpr static pf::E9 Value = pf::E9::C;
    };
    // Enumerator pf::E9::D, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:158:18

    template<>
    struct StaticInfo<ID{0x252d6830480f43bu, 0xa74a0b2f241ceeb8u}> {

        constexpr static ID ValueID = ID{0x252d6830480f43bu, 0xa74a0b2f241ceeb8u};
        constexpr static ID TypeID = ID{0x252d6830480f43bu, 0xa74a0b2f241ceeb8u};
        using Type = pf::E9;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 158;
        constexpr static std::uint64_t SourceColumn = 18;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"D"};
        constexpr static auto FullName = StringLiteral{"pf::E9::D"};

        constexpr static int UnderlyingValue = 3;
        constexpr static pf::E9 Value = pf::E9::D;
    };
    // Enumerator pf::E9::E, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h:158:21

    template<>
    struct StaticInfo<ID{0x60565d153370aeb3u, 0x29a2ad77877eb780u}> {

        constexpr static ID ValueID = ID{0x60565d153370aeb3u, 0x29a2ad77877eb780u};
        constexpr static ID TypeID = ID{0x60565d153370aeb3u, 0x29a2ad77877eb780u};
        using Type = pf::E9;

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 158;
        constexpr static std::uint64_t SourceColumn = 21;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

        constexpr static auto Name = StringLiteral{"E"};
        constexpr static auto FullName = StringLiteral{"pf::E9::E"};

        constexpr static int UnderlyingValue = 4;
        constexpr static pf::E9 Value = pf::E9::E;
    };

    template<>
    struct StaticInfo<ID{0xdb5f6197d3daadfdu, 0xc943b069a78ed385u}> {

        using Type = pf::E9;
        constexpr static ID TypeID = ID{0xdb5f6197d3daadfdu, 0xc943b069a78ed385u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test.h)path";
        constexpr static std::uint64_t SourceLine = 157;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::EnumType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"E9"};
        constexpr static auto FullName = StringLiteral{"pf::E9"};

        using UnderlyingType = int;
        constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
        constexpr static RangeOf<Info> auto EnumValues = pf::meta::details::make_array<Info>(
                ID{0xf558f81596978c12u, 0x6b15ad539b7777acu}, ID{0x9f55c71d60218126u, 0x75ba8c695c2485acu},
                ID{0xf5c64589ad9f505u, 0x8931e11fbee44c9cu}, ID{0x252d6830480f43bu, 0xa74a0b2f241ceeb8u},
                ID{0x60565d153370aeb3u, 0x29a2ad77877eb780u});
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
    // Enum pf::E9 static info getters

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
    // Enumerators of pf::E9 static info getters

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E9::A>() {
        return ID{0xf558f81596978c12u, 0x6b15ad539b7777acu};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E9::B>() {
        return ID{0x9f55c71d60218126u, 0x75ba8c695c2485acu};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E9::C>() {
        return ID{0xf5c64589ad9f505u, 0x8931e11fbee44c9cu};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E9::D>() {
        return ID{0x252d6830480f43bu, 0xa74a0b2f241ceeb8u};
    }

    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E9::E>() {
        return ID{0x60565d153370aeb3u, 0x29a2ad77877eb780u};
    }
    //Enum pf::E9 **END**

}// namespace pf::meta::details
