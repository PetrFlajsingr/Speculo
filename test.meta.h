
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

/****************************** pf::A START ******************************/
    template<>
    struct StaticInfo<ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u}> {
        struct details {

        };
        using Type = pf::A;
        constexpr static ID TypeID = ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
        constexpr static std::uint64_t SourceLine = 8;
        constexpr static std::uint64_t SourceColumn = 4;

        constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

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
        constexpr static RangeOf<Info> auto Constructors = make_array<Info>(ID{0xf597eea5e1760bfu, 0x797c08db90791d84u},
                                                                            ID{0x5254646ae7d1e4b9u,
                                                                               0xb648cc79fc2b85b0u},
                                                                            ID{0x1954895cb4645f6eu,
                                                                               0x534015734ab7b498u});
        constexpr static Info Destructor = ID{0x985d28b56ec36af8u, 0x3517760838a68a86u};
        constexpr static RangeOf<Info> auto MemberFunctions = make_array<Info>(
                ID{0x225525f0788858deu, 0x9edf3c90fb14daacu}, ID{0x335ea928a7052954u, 0x6d6fdfcadb9b2a97u});
        constexpr static RangeOf<Info> auto StaticFunctions = make_array<Info>();
        constexpr static RangeOf<Info> auto MemberVariables = make_array<Info>(
                ID{0x245c9731e42e16c0u, 0x5bb3456d5a84f189u});
        constexpr static RangeOf<Info> auto StaticVariables = make_array<Info>();
    };

// const
    template<>
    struct StaticInfo<ID{0xed51a6892a08c5b4u, 0x2710ecf40a5944b5u}>
            : StaticInfo_ConstWrap<ID{0xed51a6892a08c5b4u, 0x2710ecf40a5944b5u}, ID{0xdc56cd7e6204e1a9u,
                                                                                    0xddca1a3d5e5b2389u}> {
    };
// &
    template<>
    struct StaticInfo<ID{0x46554a96de2d6cdfu, 0x379a235e99f9f8b0u}>
            : StaticInfo_LRefWrap<ID{0x46554a96de2d6cdfu, 0x379a235e99f9f8b0u}, ID{0xdc56cd7e6204e1a9u,
                                                                                   0xddca1a3d5e5b2389u}> {
    };
// &&
    template<>
    struct StaticInfo<ID{0x595c066d66e12edcu, 0x976e9022e26d788u}>
            : StaticInfo_RRefWrap<ID{0x595c066d66e12edcu, 0x976e9022e26d788u}, ID{0xdc56cd7e6204e1a9u,
                                                                                  0xddca1a3d5e5b2389u}> {
    };
// const &
    template<>
    struct StaticInfo<ID{0x755a6050db5538a4u, 0xdbec077cc9c5cdbdu}>
            : StaticInfo_ConstLRefWrap<ID{0x755a6050db5538a4u, 0xdbec077cc9c5cdbdu}, ID{0xdc56cd7e6204e1a9u,
                                                                                        0xddca1a3d5e5b2389u}> {
    };
// *
    template<>
    struct StaticInfo<ID{0xb251737e9c898e9eu, 0x389aa5bd43572286u}>
            : StaticInfo_PtrWrap<ID{0xb251737e9c898e9eu, 0x389aa5bd43572286u}, ID{0xdc56cd7e6204e1a9u,
                                                                                  0xddca1a3d5e5b2389u}> {
    };
// const *
    template<>
    struct StaticInfo<ID{0x15585d55c434fd12u, 0xb437a217985b4187u}>
            : StaticInfo_ConstPtrWrap<ID{0x15585d55c434fd12u, 0xb437a217985b4187u}, ID{0xdc56cd7e6204e1a9u,
                                                                                       0xddca1a3d5e5b2389u}> {
    };

/****************************** pf::A END ******************************/

/****************************** pf::B START ******************************/
    template<>
    struct StaticInfo<ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u}> {
        struct details {

        };
        using Type = pf::B;
        constexpr static ID TypeID = ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
        constexpr static std::uint64_t SourceLine = 13;
        constexpr static std::uint64_t SourceColumn = 4;

        constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::RecordType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"B"};
        constexpr static auto FullName = StringLiteral{"pf::B"};

        constexpr static bool IsUnion = false;
        constexpr static bool IsPolymorphic = true;
        constexpr static bool IsAbstract = true;
        constexpr static bool IsFinal = false;
        constexpr static RangeOf<Info> auto Bases = make_array<Info>();
        constexpr static RangeOf<Info> auto Constructors = make_array<Info>(
                ID{0x5054a98cf7c8fcadu, 0x81e0621d5301d4acu}, ID{0x60534a54fb82e7eau, 0x240c895305848f89u});
        constexpr static Info Destructor = ID{0xa9567d344d82809fu, 0x2a140755952d40a2u};
        constexpr static RangeOf<Info> auto MemberFunctions = make_array<Info>(
                ID{0x14548f9a1ac7b3f4u, 0x63470a5671596a9cu}, ID{0x9a540d1f2173f3b4u, 0xfbf9d130859343aeu},
                ID{0x965777e730c4cd33u, 0x7bd57bfc8590c3a1u});
        constexpr static RangeOf<Info> auto StaticFunctions = make_array<Info>();
        constexpr static RangeOf<Info> auto MemberVariables = make_array<Info>();
        constexpr static RangeOf<Info> auto StaticVariables = make_array<Info>();
    };

// const
    template<>
    struct StaticInfo<ID{0x9e533a49fded64abu, 0x83055bf08667c183u}>
            : StaticInfo_ConstWrap<ID{0x9e533a49fded64abu, 0x83055bf08667c183u}, ID{0x82516c5bbf7430aau,
                                                                                    0x1ffe30223377b487u}> {
    };
// &
    template<>
    struct StaticInfo<ID{0xde5a2a4c0b86749du, 0x89b8891279284797u}>
            : StaticInfo_LRefWrap<ID{0xde5a2a4c0b86749du, 0x89b8891279284797u}, ID{0x82516c5bbf7430aau,
                                                                                   0x1ffe30223377b487u}> {
    };
// &&
    template<>
    struct StaticInfo<ID{0x3a586acdd38940a8u, 0xe99ee2c9bcebd4a5u}>
            : StaticInfo_RRefWrap<ID{0x3a586acdd38940a8u, 0xe99ee2c9bcebd4a5u}, ID{0x82516c5bbf7430aau,
                                                                                   0x1ffe30223377b487u}> {
    };
// const &
    template<>
    struct StaticInfo<ID{0xf25402f03dd1faa1u, 0xb03c8205bc561eb7u}>
            : StaticInfo_ConstLRefWrap<ID{0xf25402f03dd1faa1u, 0xb03c8205bc561eb7u}, ID{0x82516c5bbf7430aau,
                                                                                        0x1ffe30223377b487u}> {
    };
// *
    template<>
    struct StaticInfo<ID{0x315de31de2e67835u, 0xad5b007b0c47b4aau}>
            : StaticInfo_PtrWrap<ID{0x315de31de2e67835u, 0xad5b007b0c47b4aau}, ID{0x82516c5bbf7430aau,
                                                                                  0x1ffe30223377b487u}> {
    };
// const *
    template<>
    struct StaticInfo<ID{0xd45cb324f63b0588u, 0xf4d9056ad5ee0ab6u}>
            : StaticInfo_ConstPtrWrap<ID{0xd45cb324f63b0588u, 0xf4d9056ad5ee0ab6u}, ID{0x82516c5bbf7430aau,
                                                                                       0x1ffe30223377b487u}> {
    };

/****************************** pf::B END ******************************/

/****************************** pf::Test START ******************************/
    template<>
    struct StaticInfo<ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u}> {
        struct details {

        };
        using Type = pf::Test;
        constexpr static ID TypeID = ID{0xde53fafb7a1f24bfu, 0xc1d896834081ab84u};

        constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\test.h)path";
        constexpr static std::uint64_t SourceLine = 19;
        constexpr static std::uint64_t SourceColumn = 5;

        constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>();

        constexpr static auto StaticInfoObjectType = StaticInfoType::RecordType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = StringLiteral{"Test"};
        constexpr static auto FullName = StringLiteral{"pf::Test"};

        constexpr static bool IsUnion = false;
        constexpr static bool IsPolymorphic = true;
        constexpr static bool IsAbstract = false;
        constexpr static bool IsFinal = false;
        constexpr static RangeOf<Info> auto Bases = make_array<Info>(ID{0xdc56cd7e6204e1a9u, 0xddca1a3d5e5b2389u},
                                                                     ID{0x82516c5bbf7430aau, 0x1ffe30223377b487u});
        constexpr static RangeOf<Info> auto Constructors = make_array<Info>(
                ID{0xc755d889c9afcfc0u, 0xa0f9a22e2a89ada4u}, ID{0x895d90ae76b9dc30u, 0xf841242b37ac00b7u},
                ID{0x5a5168cc7bb4f6a4u, 0x4bf005a81d020c9eu}, ID{0x815cba4b473ce1d2u, 0xf2d83feb29ab5499u});
        constexpr static Info Destructor = ID{0xb75617b85f96032bu, 0x2b94d6e0162578b9u};
        constexpr static RangeOf<Info> auto MemberFunctions = make_array<Info>(
                ID{0xab50ef4c6f7fd7e0u, 0x75a84acb3f053e80u}, ID{0x5d537fe41bed167eu, 0x646f23e04ea2ec9bu},
                ID{0x645af4c043fdb70eu, 0x6e125afd7264cd8au}, ID{0x3f5dc3b0cb932998u, 0xfaac361ccb864282u},
                ID{0x3f5dc3b0cb932998u, 0xfaac361ccb864282u});
        constexpr static RangeOf<Info> auto StaticFunctions = make_array<Info>(
                ID{0xd6506c04cb46efdcu, 0x725b025b790e1a85u}, ID{0x9850e0e0103f1677u, 0x5b07408433193a86u});
        constexpr static RangeOf<Info> auto MemberVariables = make_array<Info>(
                ID{0xb658e3e39aa041fbu, 0xa8733c8d899de096u}, ID{0x76532147d735817eu, 0x1bc21ab380cb68a4u},
                ID{0x1953f73356de271cu, 0x6846635c715f8986u}, ID{0x6d5b23bda3bb5e09u, 0x624df9b94e9ab8adu});
        constexpr static RangeOf<Info> auto StaticVariables = make_array<Info>(
                ID{0xe1526a3f2692dd10u, 0xe4309a526cb96fb6u}, ID{0xa15ed0e1a6d3a97au, 0x3c69715da03789b2u});
    };

// const
    template<>
    struct StaticInfo<ID{0x885f713ed52edd43u, 0x4ad00c420e4cebacu}>
            : StaticInfo_ConstWrap<ID{0x885f713ed52edd43u, 0x4ad00c420e4cebacu}, ID{0xde53fafb7a1f24bfu,
                                                                                    0xc1d896834081ab84u}> {
    };
// &
    template<>
    struct StaticInfo<ID{0x535907439e0eaa8bu, 0xaa251e67c7a1dfb8u}>
            : StaticInfo_LRefWrap<ID{0x535907439e0eaa8bu, 0xaa251e67c7a1dfb8u}, ID{0xde53fafb7a1f24bfu,
                                                                                   0xc1d896834081ab84u}> {
    };
// &&
    template<>
    struct StaticInfo<ID{0xbe5812ad03b80b92u, 0x5ac67cd12b292783u}>
            : StaticInfo_RRefWrap<ID{0xbe5812ad03b80b92u, 0x5ac67cd12b292783u}, ID{0xde53fafb7a1f24bfu,
                                                                                   0xc1d896834081ab84u}> {
    };
// const &
    template<>
    struct StaticInfo<ID{0x365a3f3011d34dbfu, 0x61a1602af9df91a9u}>
            : StaticInfo_ConstLRefWrap<ID{0x365a3f3011d34dbfu, 0x61a1602af9df91a9u}, ID{0xde53fafb7a1f24bfu,
                                                                                        0xc1d896834081ab84u}> {
    };
// *
    template<>
    struct StaticInfo<ID{0xee5ea045032ac904u, 0x413decc08879e4a9u}>
            : StaticInfo_PtrWrap<ID{0xee5ea045032ac904u, 0x413decc08879e4a9u}, ID{0xde53fafb7a1f24bfu,
                                                                                  0xc1d896834081ab84u}> {
    };
// const *
    template<>
    struct StaticInfo<ID{0x51561d84153a2edcu, 0x23ac6c802298bcbdu}>
            : StaticInfo_ConstPtrWrap<ID{0x51561d84153a2edcu, 0x23ac6c802298bcbdu}, ID{0xde53fafb7a1f24bfu,
                                                                                       0xc1d896834081ab84u}> {
    };

/****************************** pf::Test END ******************************/

}
