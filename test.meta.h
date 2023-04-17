
#pragma once

#include "meta/Attribute.h"
#include "meta/Info.h"
#include "meta/details/ID.h"
#include "meta/details/StaticInfo.h"
#include "meta/details/StaticInfo_Wrappers.h"
#include "test.h"// FIXME: include file from tool input
#include <pf_common/array.h>
#include <pf_common/concepts/ranges.h>
#include <type_traits>

namespace pf::meta::details {

    /****************************** pf::A START ******************************/
    template<>
    struct StaticInfo<ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u}> {
        struct details {
            constexpr static auto ArgArray_6150896863629743536 = make_array<std::string_view>();
            constexpr static auto ArgArray_9673874928548847761 = make_array<std::string_view>();
            constexpr static auto ArgArray_17204247334455764432 = make_array<std::string_view>();
        };
        using Type = pf::A;
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
        constexpr static std::uint64_t SourceLine = 6;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes =
                make_array<Attribute>(Attribute{"first", std::span<const std::string_view>{details::ArgArray_6150896863629743536}},
                                      Attribute{"second", std::span<const std::string_view>{details::ArgArray_9673874928548847761}},
                                      Attribute{"third", std::span<const std::string_view>{details::ArgArray_17204247334455764432}});

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
        constexpr static RangeOf<Info> auto Bases = make_array<Info>();
        constexpr static RangeOf<Info> auto Constructors =
                make_array<Info>(ID{0xf597eea5e1760bfu, 0x797c08db90791d84u}, ID{0xfa5eaad11a25c310u, 0xa28f58c34a8f1693u});
        constexpr static Info Destructor = ID{0x985d28b56ec36af8u, 0x3517760838a68a86u};
        constexpr static RangeOf<Info> auto MemberFunctions =
                make_array<Info>(ID{0x575fdd108108c3d9u, 0xf4b82162dd7fc096u}, ID{0xb651642ac8c5f237u, 0xfe0f1011e8f1b95u},
                                 ID{0xd0502bcdb175a17fu, 0xb65cd85322939c8cu});
        constexpr static RangeOf<Info> auto StaticFunctions = make_array<Info>();
        constexpr static RangeOf<Info> auto MemberVariables = make_array<Info>(ID{0xad56d126355324dbu, 0x30de7f4e0cfbdb95u});
        constexpr static RangeOf<Info> auto StaticVariables = make_array<Info>();
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

    /****************************** pf::A::A START ******************************/
    template<>
    struct StaticInfo<ID{0xf597eea5e1760bfu, 0x797c08db90791d84u}> {
        struct details {
            constexpr static auto ArgArray_8590435811972290979 = make_array<std::string_view>();
            constexpr static auto ArgArray_8384307549146138593 = make_array<std::string_view>();
        };
        constexpr static ID ConstructorID = ID{0xf597eea5e1760bfu, 0x797c08db90791d84u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
        constexpr static std::uint64_t SourceLine = 8;
        constexpr static std::uint64_t SourceColumn = 26;

        constexpr static RangeOf<Attribute> auto Attributes =
                make_array<Attribute>(Attribute{"maybe_unused", std::span<const std::string_view>{details::ArgArray_8590435811972290979}},
                                      Attribute{"gdfsgdf", std::span<const std::string_view>{details::ArgArray_8384307549146138593}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsExplicit = false;
        constexpr static bool IsCopy = false;
        constexpr static bool IsMove = false;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"pf::A::A"};

        constexpr static RangeOf<Info> auto Arguments = make_array<Info>();
    };

    /******************************  START ******************************/
    template<>
    struct StaticInfo<ID{0xd55d261b5b8d2a6fu, 0xb6c548bc0f958193u}> {
        struct details {};
        constexpr static ID ArgumentID = ID{0xd55d261b5b8d2a6fu, 0xb6c548bc0f958193u};
        constexpr static ID TypeID = ID{0x755a6050db5538a4u, 0xdbec077cc9c5cdbdu};

        constexpr static auto SourceFile = R"path(<generated>)path";
        constexpr static std::uint64_t SourceLine = 0;
        constexpr static std::uint64_t SourceColumn = 0;

        constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{""};
        constexpr static auto FullName = StringLiteral{""};
    };

    /****************************** pf::A::A START ******************************/
    template<>
    struct StaticInfo<ID{0xfa5eaad11a25c310u, 0xa28f58c34a8f1693u}> {
        struct details {};
        constexpr static ID ConstructorID = ID{0xfa5eaad11a25c310u, 0xa28f58c34a8f1693u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(<generated>)path";
        constexpr static std::uint64_t SourceLine = 0;
        constexpr static std::uint64_t SourceColumn = 0;

        constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Constructor;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsExplicit = false;
        constexpr static bool IsCopy = true;
        constexpr static bool IsMove = false;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"pf::A::A"};

        constexpr static RangeOf<Info> auto Arguments = make_array<Info>(ID{0xd55d261b5b8d2a6fu, 0xb6c548bc0f958193u});
    };

    /****************************** pf::A::~A START ******************************/
    template<>
    struct StaticInfo<ID{0x985d28b56ec36af8u, 0x3517760838a68a86u}> {
        struct details {
            constexpr static auto ArgArray_16006236641527277836 = make_array<std::string_view>();
            constexpr static auto ArgArray_13831480891765603012 = make_array<std::string_view>();
            constexpr static auto ArgArray_8496831806904703913 = make_array<std::string_view>();
            constexpr static auto ArgArray_9457767321489340158 = make_array<std::string_view>();
        };
        constexpr static ID DestructorID = ID{0x985d28b56ec36af8u, 0x3517760838a68a86u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
        constexpr static std::uint64_t SourceLine = 9;
        constexpr static std::uint64_t SourceColumn = 32;

        constexpr static RangeOf<Attribute> auto Attributes =
                make_array<Attribute>(Attribute{"papuce", std::span<const std::string_view>{details::ArgArray_16006236641527277836}},
                                      Attribute{"a", std::span<const std::string_view>{details::ArgArray_13831480891765603012}},
                                      Attribute{"b", std::span<const std::string_view>{details::ArgArray_8496831806904703913}},
                                      Attribute{"c", std::span<const std::string_view>{details::ArgArray_9457767321489340158}});

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
            constexpr static auto ArgArray_17077311901809226894 = make_array<std::string_view>();
        };
        constexpr static ID ArgumentID = ID{0x285fa243136a2539u, 0xd92a9fbd3c821b8u};
        constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
        constexpr static std::uint64_t SourceLine = 12;
        constexpr static std::uint64_t SourceColumn = 48;

        constexpr static RangeOf<Attribute> auto Attributes =
                make_array<Attribute>(Attribute{"letadlo", std::span<const std::string_view>{details::ArgArray_17077311901809226894}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"dzea"};
        constexpr static auto FullName = StringLiteral{"dzea"};
    };

    /****************************** A START ******************************/
    template<>
    struct StaticInfo<ID{0x505f49fe2f26ad62u, 0x466eafc2e33858a3u}> {
        struct details {
            constexpr static auto ArgArray_12025256727660744736 = make_array<std::string_view>();
            constexpr static auto ArgArray_4621925886799809223 = make_array<std::string_view>();
        };
        constexpr static ID ArgumentID = ID{0x505f49fe2f26ad62u, 0x466eafc2e33858a3u};
        constexpr static ID TypeID = ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
        constexpr static std::uint64_t SourceLine = 12;
        constexpr static std::uint64_t SourceColumn = 74;

        constexpr static RangeOf<Attribute> auto Attributes =
                make_array<Attribute>(Attribute{"yuh", std::span<const std::string_view>{details::ArgArray_12025256727660744736}},
                                      Attribute{"yuh2", std::span<const std::string_view>{details::ArgArray_4621925886799809223}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"A"};
        constexpr static auto FullName = StringLiteral{"A"};
    };

    /****************************** pf::A::foo START ******************************/
    template<>
    struct StaticInfo<ID{0x575fdd108108c3d9u, 0xf4b82162dd7fc096u}> {
        struct details {
            constexpr static auto ArgArray_14007599727722618291 = make_array<std::string_view>();
            constexpr static auto ArgArray_3817797272941666327 = make_array<std::string_view>();
            constexpr static auto ArgArray_4404170388304384721 = make_array<std::string_view>();
            constexpr static auto ArgArray_17227154182792099890 = make_array<std::string_view>();
            constexpr static auto ArgArray_7394356095499375008 = make_array<std::string_view>();
        };
        constexpr static ID FunctionID = ID{0x575fdd108108c3d9u, 0xf4b82162dd7fc096u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
        constexpr static std::uint64_t SourceLine = 12;
        constexpr static std::uint64_t SourceColumn = 26;

        constexpr static RangeOf<Attribute> auto Attributes =
                make_array<Attribute>(Attribute{"maybe_unused", std::span<const std::string_view>{details::ArgArray_14007599727722618291}},
                                      Attribute{"letadlo", std::span<const std::string_view>{details::ArgArray_3817797272941666327}},
                                      Attribute{"yuh", std::span<const std::string_view>{details::ArgArray_4404170388304384721}},
                                      Attribute{"yuh2", std::span<const std::string_view>{details::ArgArray_17227154182792099890}},
                                      Attribute{"kjhnn", std::span<const std::string_view>{details::ArgArray_7394356095499375008}});

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
        constexpr static RangeOf<Info> auto Arguments =
                make_array<Info>(ID{0x285fa243136a2539u, 0xd92a9fbd3c821b8u}, ID{0x505f49fe2f26ad62u, 0x466eafc2e33858a3u});
    };

    /****************************** dzea2 START ******************************/
    template<>
    struct StaticInfo<ID{0xa65963f0f043d5c8u, 0x8c4c551f4f92f2b6u}> {
        struct details {
            constexpr static auto ArgArray_6683345577118606287 = make_array<std::string_view>();
        };
        constexpr static ID ArgumentID = ID{0xa65963f0f043d5c8u, 0x8c4c551f4f92f2b6u};
        constexpr static ID TypeID = ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
        constexpr static std::uint64_t SourceLine = 13;
        constexpr static std::uint64_t SourceColumn = 49;

        constexpr static RangeOf<Attribute> auto Attributes =
                make_array<Attribute>(Attribute{"letadlo", std::span<const std::string_view>{details::ArgArray_6683345577118606287}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{"dzea2"};
        constexpr static auto FullName = StringLiteral{"dzea2"};
    };

    /****************************** pf::A::foo2 START ******************************/
    template<>
    struct StaticInfo<ID{0xb651642ac8c5f237u, 0xfe0f1011e8f1b95u}> {
        struct details {
            constexpr static auto ArgArray_14888158208749942728 = make_array<std::string_view>();
            constexpr static auto ArgArray_1476310549755521376 = make_array<std::string_view>();
            constexpr static auto ArgArray_9417394659003187224 = make_array<std::string_view>();
        };
        constexpr static ID FunctionID = ID{0xb651642ac8c5f237u, 0xfe0f1011e8f1b95u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
        constexpr static std::uint64_t SourceLine = 13;
        constexpr static std::uint64_t SourceColumn = 26;

        constexpr static RangeOf<Attribute> auto Attributes =
                make_array<Attribute>(Attribute{"maybe_unused", std::span<const std::string_view>{details::ArgArray_14888158208749942728}},
                                      Attribute{"letadlo", std::span<const std::string_view>{details::ArgArray_1476310549755521376}},
                                      Attribute{"kjhnn", std::span<const std::string_view>{details::ArgArray_9417394659003187224}});

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
        constexpr static RangeOf<Info> auto Arguments = make_array<Info>(ID{0xa65963f0f043d5c8u, 0x8c4c551f4f92f2b6u});
    };

    /******************************  START ******************************/
    template<>
    struct StaticInfo<ID{0x38570030af11cfa9u, 0x2298ac40a2818bb0u}> {
        struct details {};
        constexpr static ID ArgumentID = ID{0x38570030af11cfa9u, 0x2298ac40a2818bb0u};
        constexpr static ID TypeID = ID{0x755a6050db5538a4u, 0xdbec077cc9c5cdbdu};

        constexpr static auto SourceFile = R"path(<generated>)path";
        constexpr static std::uint64_t SourceLine = 0;
        constexpr static std::uint64_t SourceColumn = 0;

        constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

        constexpr static auto Name = StringLiteral{""};
        constexpr static auto FullName = StringLiteral{""};
    };

    /****************************** pf::A::operator= START ******************************/
    template<>
    struct StaticInfo<ID{0xd0502bcdb175a17fu, 0xb65cd85322939c8cu}> {
        struct details {};
        constexpr static ID FunctionID = ID{0xd0502bcdb175a17fu, 0xb65cd85322939c8cu};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(<generated>)path";
        constexpr static std::uint64_t SourceLine = 0;
        constexpr static std::uint64_t SourceColumn = 0;

        constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

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
        constexpr static RangeOf<Info> auto Arguments = make_array<Info>(ID{0x38570030af11cfa9u, 0x2298ac40a2818bb0u});
    };

    /****************************** pf::A::c START ******************************/
    template<>
    struct StaticInfo<ID{0xad56d126355324dbu, 0x30de7f4e0cfbdb95u}> {
        struct details {
            constexpr static auto ArgArray_16742103623930499094 = make_array<std::string_view>();
            constexpr static auto ArgArray_1823778925406449139 = make_array<std::string_view>();
            constexpr static auto ArgArray_563378641962981779 = make_array<std::string_view>();
        };
        constexpr static ID VariableID = ID{0xad56d126355324dbu, 0x30de7f4e0cfbdb95u};
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
        constexpr static std::uint64_t SourceLine = 11;
        constexpr static std::uint64_t SourceColumn = 35;

        constexpr static RangeOf<Attribute> auto Attributes =
                make_array<Attribute>(Attribute{"yeet", std::span<const std::string_view>{details::ArgArray_16742103623930499094}},
                                      Attribute{"maybe_unused", std::span<const std::string_view>{details::ArgArray_1823778925406449139}},
                                      Attribute{"cxvxc", std::span<const std::string_view>{details::ArgArray_563378641962981779}});

        constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

        constexpr static bool IsPublic = true;
        constexpr static bool IsProtected = false;
        constexpr static bool IsPrivate = false;
        constexpr static bool IsMutable = false;

        constexpr static auto Name = StringLiteral{"c"};
        constexpr static auto FullName = StringLiteral{"pf::A::c"};
    };

}// namespace pf::meta::details
