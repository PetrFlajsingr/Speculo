//
// Created by xflajs00 on 14.03.2023.
//

#ifndef PF_META_FUNDAMENTAL_TYPES_META_H
#define PF_META_FUNDAMENTAL_TYPES_META_H

#include <meta/details/array.h>
#include <meta/Info.h>

namespace pf::meta::details {
    template<typename T, ID TID, StringLiteral TypeName, StringLiteral FullTypeName = TypeName> requires(std::is_fundamental_v<T>)
    struct FundamentalStaticTypeInfo {
        using Type = T;
        constexpr static ID TypeID = TID;

        // FIXME: RangeOf msvc failure here
        constexpr static /*RangeOf<pf::meta::Attribute>*/ auto Attributes = pf::meta::details::make_array<pf::meta::Attribute>();


        constexpr static auto StaticInfoObjectType = StaticInfoType::FundamentalType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;

        constexpr static auto Name = TypeName;
        constexpr static auto FullName = FullTypeName;
    };
    /****************************** bool START ******************************/

    template<>
    struct StaticInfo<ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u}>
            : FundamentalStaticTypeInfo<bool, ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u}, StringLiteral{
                    "bool"}, StringLiteral{"bool"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<bool>() {
        return ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u};
    }

    template<>
    struct StaticInfo<ID{0x3955509119bfedbau, 0x390227b6574b7cb4u}>
            : StaticInfo_ConstWrap<ID{0x3955509119bfedbau, 0x390227b6574b7cb4u}, ID{0x5a570b30e217d281u,
                                                                                    0xd68971b95fd84e99u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const bool>() {
        return ID{0x3955509119bfedbau, 0x390227b6574b7cb4u};
    }

    template<>
    struct StaticInfo<ID{0x415821931e321bf4u, 0xafc251f16438d692u}>
            : StaticInfo_LRefWrap<ID{0x415821931e321bf4u, 0xafc251f16438d692u}, ID{0x5a570b30e217d281u,
                                                                                   0xd68971b95fd84e99u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<bool &>() {
        return ID{0x415821931e321bf4u, 0xafc251f16438d692u};
    }

    template<>
    struct StaticInfo<ID{0x8558e4cb5bc9018eu, 0xc57b4c01b56d26bau}>
            : StaticInfo_ConstLRefWrap<ID{0x8558e4cb5bc9018eu, 0xc57b4c01b56d26bau}, ID{0x5a570b30e217d281u,
                                                                                        0xd68971b95fd84e99u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const bool &>() {
        return ID{0x8558e4cb5bc9018eu, 0xc57b4c01b56d26bau};
    }

    template<>
    struct StaticInfo<ID{0x94580200c01884f8u, 0xfc1cfede4a4e6db1u}>
            : StaticInfo_RRefWrap<ID{0x94580200c01884f8u, 0xfc1cfede4a4e6db1u}, ID{0x5a570b30e217d281u,
                                                                                   0xd68971b95fd84e99u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<bool &&>() {
        return ID{0x94580200c01884f8u, 0xfc1cfede4a4e6db1u};
    }

    template<>
    struct StaticInfo<ID{0xd5552e71e996fc88u, 0x3b2e97f23fca5990u}>
            : StaticInfo_PtrWrap<ID{0xd5552e71e996fc88u, 0x3b2e97f23fca5990u}, ID{0x5a570b30e217d281u,
                                                                                  0xd68971b95fd84e99u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<bool *>() {
        return ID{0xd5552e71e996fc88u, 0x3b2e97f23fca5990u};
    }

    template<>
    struct StaticInfo<ID{0xcf59dfa9e890d740u, 0x22e67b1c92f2019fu}>
            : StaticInfo_ConstPtrWrap<ID{0xcf59dfa9e890d740u, 0x22e67b1c92f2019fu}, ID{0x5a570b30e217d281u,
                                                                                       0xd68971b95fd84e99u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const bool *>() {
        return ID{0xcf59dfa9e890d740u, 0x22e67b1c92f2019fu};
    }

    /****************************** bool END ******************************/


    /****************************** char START ******************************/

    template<>
    struct StaticInfo<ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u}>
            : FundamentalStaticTypeInfo<char, ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u}, StringLiteral{
                    "char"}, StringLiteral{"char"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<char>() {
        return ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u};
    }

    template<>
    struct StaticInfo<ID{0x5a5831b93f51f2b7u, 0x29731d2971712783u}>
            : StaticInfo_ConstWrap<ID{0x5a5831b93f51f2b7u, 0x29731d2971712783u}, ID{0x345df9e6c3d2d91eu,
                                                                                    0x9dedd3a74f8fd5a1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const char>() {
        return ID{0x5a5831b93f51f2b7u, 0x29731d2971712783u};
    }

    template<>
    struct StaticInfo<ID{0xe57fd83878d0c3du, 0x2579bb43ee305cabu}>
            : StaticInfo_LRefWrap<ID{0xe57fd83878d0c3du, 0x2579bb43ee305cabu}, ID{0x345df9e6c3d2d91eu,
                                                                                  0x9dedd3a74f8fd5a1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<char &>() {
        return ID{0xe57fd83878d0c3du, 0x2579bb43ee305cabu};
    }

    template<>
    struct StaticInfo<ID{0xb5540a27a74643fcu, 0x2280bebdf30509a1u}>
            : StaticInfo_ConstLRefWrap<ID{0xb5540a27a74643fcu, 0x2280bebdf30509a1u}, ID{0x345df9e6c3d2d91eu,
                                                                                        0x9dedd3a74f8fd5a1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const char &>() {
        return ID{0xb5540a27a74643fcu, 0x2280bebdf30509a1u};
    }

    template<>
    struct StaticInfo<ID{0xb456c6ade861f2c7u, 0x27fa77a0ea1b528eu}>
            : StaticInfo_RRefWrap<ID{0xb456c6ade861f2c7u, 0x27fa77a0ea1b528eu}, ID{0x345df9e6c3d2d91eu,
                                                                                   0x9dedd3a74f8fd5a1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<char &&>() {
        return ID{0xb456c6ade861f2c7u, 0x27fa77a0ea1b528eu};
    }

    template<>
    struct StaticInfo<ID{0x30542f1371acde0fu, 0x3cfdf0ae7092f19du}>
            : StaticInfo_PtrWrap<ID{0x30542f1371acde0fu, 0x3cfdf0ae7092f19du}, ID{0x345df9e6c3d2d91eu,
                                                                                  0x9dedd3a74f8fd5a1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<char *>() {
        return ID{0x30542f1371acde0fu, 0x3cfdf0ae7092f19du};
    }

    template<>
    struct StaticInfo<ID{0x89521adec77a74f2u, 0xaa87a78fd51da19bu}>
            : StaticInfo_ConstPtrWrap<ID{0x89521adec77a74f2u, 0xaa87a78fd51da19bu}, ID{0x345df9e6c3d2d91eu,
                                                                                       0x9dedd3a74f8fd5a1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const char *>() {
        return ID{0x89521adec77a74f2u, 0xaa87a78fd51da19bu};
    }

    /****************************** char END ******************************/


    /****************************** signed char START ******************************/

    template<>
    struct StaticInfo<ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu}>
            : FundamentalStaticTypeInfo<signed char, ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu}, StringLiteral{
                    "signed char"},
                    StringLiteral{"signed char"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<signed char>() {
        return ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu};
    }

    template<>
    struct StaticInfo<ID{0xa15a4308db285fd5u, 0xf33d92ae3380d9a8u}>
            : StaticInfo_ConstWrap<ID{0xa15a4308db285fd5u, 0xf33d92ae3380d9a8u}, ID{0x1c5ece854198fec0u,
                                                                                    0xe8f24cb935bb89fu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const signed char>() {
        return ID{0xa15a4308db285fd5u, 0xf33d92ae3380d9a8u};
    }

    template<>
    struct StaticInfo<ID{0x2459dc515a7a61e3u, 0xca9a6a6c33242e90u}>
            : StaticInfo_LRefWrap<ID{0x2459dc515a7a61e3u, 0xca9a6a6c33242e90u}, ID{0x1c5ece854198fec0u,
                                                                                   0xe8f24cb935bb89fu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<signed char &>() {
        return ID{0x2459dc515a7a61e3u, 0xca9a6a6c33242e90u};
    }

    template<>
    struct StaticInfo<ID{0x655454e03535d687u, 0xddb9c2aa540767bdu}>
            : StaticInfo_ConstLRefWrap<ID{0x655454e03535d687u, 0xddb9c2aa540767bdu}, ID{0x1c5ece854198fec0u,
                                                                                        0xe8f24cb935bb89fu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const signed char &>() {
        return ID{0x655454e03535d687u, 0xddb9c2aa540767bdu};
    }

    template<>
    struct StaticInfo<ID{0x3e5edb06d6141f3bu, 0x5b29ae0f6661f193u}>
            : StaticInfo_RRefWrap<ID{0x3e5edb06d6141f3bu, 0x5b29ae0f6661f193u}, ID{0x1c5ece854198fec0u,
                                                                                   0xe8f24cb935bb89fu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<signed char &&>() {
        return ID{0x3e5edb06d6141f3bu, 0x5b29ae0f6661f193u};
    }

    template<>
    struct StaticInfo<ID{0xa15bd49dc6846b25u, 0xde2b1ffe5b9262b9u}>
            : StaticInfo_PtrWrap<ID{0xa15bd49dc6846b25u, 0xde2b1ffe5b9262b9u}, ID{0x1c5ece854198fec0u,
                                                                                  0xe8f24cb935bb89fu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<signed char *>() {
        return ID{0xa15bd49dc6846b25u, 0xde2b1ffe5b9262b9u};
    }

    template<>
    struct StaticInfo<ID{0x955dacb4f7201aecu, 0x2d3f4ee09311229eu}>
            : StaticInfo_ConstPtrWrap<ID{0x955dacb4f7201aecu, 0x2d3f4ee09311229eu}, ID{0x1c5ece854198fec0u,
                                                                                       0xe8f24cb935bb89fu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const signed char *>() {
        return ID{0x955dacb4f7201aecu, 0x2d3f4ee09311229eu};
    }

    /****************************** signed char END ******************************/


    /****************************** unsigned char START ******************************/

    template<>
    struct StaticInfo<ID{0x5f56c0b531733454u, 0x552996f604766e9au}>
            : FundamentalStaticTypeInfo<unsigned char, ID{0x5f56c0b531733454u, 0x552996f604766e9au}, StringLiteral{
                    "unsigned char"},
                    StringLiteral{"unsigned char"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned char>() {
        return ID{0x5f56c0b531733454u, 0x552996f604766e9au};
    }

    template<>
    struct StaticInfo<ID{0x7056905a8106507fu, 0x71ae48440ccffcb4u}>
            : StaticInfo_ConstWrap<ID{0x7056905a8106507fu, 0x71ae48440ccffcb4u}, ID{0x5f56c0b531733454u,
                                                                                    0x552996f604766e9au}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned char>() {
        return ID{0x7056905a8106507fu, 0x71ae48440ccffcb4u};
    }

    template<>
    struct StaticInfo<ID{0x375c05d3b15a112eu, 0x81cfa8dda7341185u}>
            : StaticInfo_LRefWrap<ID{0x375c05d3b15a112eu, 0x81cfa8dda7341185u}, ID{0x5f56c0b531733454u,
                                                                                   0x552996f604766e9au}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned char &>() {
        return ID{0x375c05d3b15a112eu, 0x81cfa8dda7341185u};
    }

    template<>
    struct StaticInfo<ID{0x3563c641936ce91u, 0x8a4b9a65a4c419b0u}>
            : StaticInfo_ConstLRefWrap<ID{0x3563c641936ce91u, 0x8a4b9a65a4c419b0u}, ID{0x5f56c0b531733454u,
                                                                                       0x552996f604766e9au}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned char &>() {
        return ID{0x3563c641936ce91u, 0x8a4b9a65a4c419b0u};
    }

    template<>
    struct StaticInfo<ID{0x9c5f7f8f43ce4c7fu, 0x8517d5b569d4e48bu}>
            : StaticInfo_RRefWrap<ID{0x9c5f7f8f43ce4c7fu, 0x8517d5b569d4e48bu}, ID{0x5f56c0b531733454u,
                                                                                   0x552996f604766e9au}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned char &&>() {
        return ID{0x9c5f7f8f43ce4c7fu, 0x8517d5b569d4e48bu};
    }

    template<>
    struct StaticInfo<ID{0xba5fedfdd3af89c1u, 0x18b39b2eb0c19abeu}>
            : StaticInfo_PtrWrap<ID{0xba5fedfdd3af89c1u, 0x18b39b2eb0c19abeu}, ID{0x5f56c0b531733454u,
                                                                                  0x552996f604766e9au}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned char *>() {
        return ID{0xba5fedfdd3af89c1u, 0x18b39b2eb0c19abeu};
    }

    template<>
    struct StaticInfo<ID{0xf459e1a3c9047ae0u, 0x455e16962d8ff7a6u}>
            : StaticInfo_ConstPtrWrap<ID{0xf459e1a3c9047ae0u, 0x455e16962d8ff7a6u}, ID{0x5f56c0b531733454u,
                                                                                       0x552996f604766e9au}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned char *>() {
        return ID{0xf459e1a3c9047ae0u, 0x455e16962d8ff7a6u};
    }

    /****************************** unsigned char END ******************************/


    /****************************** char8_t START ******************************/

    template<>
    struct StaticInfo<ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u}>
            : FundamentalStaticTypeInfo<char8_t, ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u}, StringLiteral{"char8_t"},
                    StringLiteral{"char8_t"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<char8_t>() {
        return ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u};
    }

    template<>
    struct StaticInfo<ID{0xc9530303ca614c38u, 0x4af94572d14b66bcu}>
            : StaticInfo_ConstWrap<ID{0xc9530303ca614c38u, 0x4af94572d14b66bcu}, ID{0x2a5366d825be6734u,
                                                                                    0x5f9d8d9790f1fe80u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const char8_t>() {
        return ID{0xc9530303ca614c38u, 0x4af94572d14b66bcu};
    }

    template<>
    struct StaticInfo<ID{0x4f568c1d9f32963fu, 0xc24b2c9bd068fe82u}>
            : StaticInfo_LRefWrap<ID{0x4f568c1d9f32963fu, 0xc24b2c9bd068fe82u}, ID{0x2a5366d825be6734u,
                                                                                   0x5f9d8d9790f1fe80u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<char8_t &>() {
        return ID{0x4f568c1d9f32963fu, 0xc24b2c9bd068fe82u};
    }

    template<>
    struct StaticInfo<ID{0x2955497ed7157491u, 0xf91f1ca6c0e6ce8cu}>
            : StaticInfo_ConstLRefWrap<ID{0x2955497ed7157491u, 0xf91f1ca6c0e6ce8cu}, ID{0x2a5366d825be6734u,
                                                                                        0x5f9d8d9790f1fe80u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const char8_t &>() {
        return ID{0x2955497ed7157491u, 0xf91f1ca6c0e6ce8cu};
    }

    template<>
    struct StaticInfo<ID{0x1c59d3ca7f7aa1c1u, 0x4b0d5e3e736962b6u}>
            : StaticInfo_RRefWrap<ID{0x1c59d3ca7f7aa1c1u, 0x4b0d5e3e736962b6u}, ID{0x2a5366d825be6734u,
                                                                                   0x5f9d8d9790f1fe80u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<char8_t &&>() {
        return ID{0x1c59d3ca7f7aa1c1u, 0x4b0d5e3e736962b6u};
    }

    template<>
    struct StaticInfo<ID{0xa65503edfb6c0282u, 0xfee6dc9e11182caau}>
            : StaticInfo_PtrWrap<ID{0xa65503edfb6c0282u, 0xfee6dc9e11182caau}, ID{0x2a5366d825be6734u,
                                                                                  0x5f9d8d9790f1fe80u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<char8_t *>() {
        return ID{0xa65503edfb6c0282u, 0xfee6dc9e11182caau};
    }

    template<>
    struct StaticInfo<ID{0xa56555eabcb9ed1u, 0xcbec9b1453d9a68fu}>
            : StaticInfo_ConstPtrWrap<ID{0xa56555eabcb9ed1u, 0xcbec9b1453d9a68fu}, ID{0x2a5366d825be6734u,
                                                                                      0x5f9d8d9790f1fe80u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const char8_t *>() {
        return ID{0xa56555eabcb9ed1u, 0xcbec9b1453d9a68fu};
    }

    /****************************** char8_t END ******************************/


    /****************************** char16_t START ******************************/

    template<>
    struct StaticInfo<ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu}>
            : FundamentalStaticTypeInfo<char16_t, ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu}, StringLiteral{
                    "char16_t"},
                    StringLiteral{"char16_t"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<char16_t>() {
        return ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu};
    }

    template<>
    struct StaticInfo<ID{0x1f50450503737047u, 0xe787f92a0a689498u}>
            : StaticInfo_ConstWrap<ID{0x1f50450503737047u, 0xe787f92a0a689498u}, ID{0xfa58dad47aa85e76u,
                                                                                    0x373b3387706c3aacu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const char16_t>() {
        return ID{0x1f50450503737047u, 0xe787f92a0a689498u};
    }

    template<>
    struct StaticInfo<ID{0x685380e1d3087d79u, 0x3c8bbd744c4918a2u}>
            : StaticInfo_LRefWrap<ID{0x685380e1d3087d79u, 0x3c8bbd744c4918a2u}, ID{0xfa58dad47aa85e76u,
                                                                                   0x373b3387706c3aacu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<char16_t &>() {
        return ID{0x685380e1d3087d79u, 0x3c8bbd744c4918a2u};
    }

    template<>
    struct StaticInfo<ID{0x72522bfae11980abu, 0x9c1e42918b422adu}>
            : StaticInfo_ConstLRefWrap<ID{0x72522bfae11980abu, 0x9c1e42918b422adu}, ID{0xfa58dad47aa85e76u,
                                                                                       0x373b3387706c3aacu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const char16_t &>() {
        return ID{0x72522bfae11980abu, 0x9c1e42918b422adu};
    }

    template<>
    struct StaticInfo<ID{0xbf528289db669011u, 0x1a16d5e7566962b5u}>
            : StaticInfo_RRefWrap<ID{0xbf528289db669011u, 0x1a16d5e7566962b5u}, ID{0xfa58dad47aa85e76u,
                                                                                   0x373b3387706c3aacu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<char16_t &&>() {
        return ID{0xbf528289db669011u, 0x1a16d5e7566962b5u};
    }

    template<>
    struct StaticInfo<ID{0x275ac782f7bbe753u, 0x51fd5b41a19d3789u}>
            : StaticInfo_PtrWrap<ID{0x275ac782f7bbe753u, 0x51fd5b41a19d3789u}, ID{0xfa58dad47aa85e76u,
                                                                                  0x373b3387706c3aacu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<char16_t *>() {
        return ID{0x275ac782f7bbe753u, 0x51fd5b41a19d3789u};
    }

    template<>
    struct StaticInfo<ID{0x6e5495170a523006u, 0x3d8c8dbac7497cbeu}>
            : StaticInfo_ConstPtrWrap<ID{0x6e5495170a523006u, 0x3d8c8dbac7497cbeu}, ID{0xfa58dad47aa85e76u,
                                                                                       0x373b3387706c3aacu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const char16_t *>() {
        return ID{0x6e5495170a523006u, 0x3d8c8dbac7497cbeu};
    }

    /****************************** char16_t END ******************************/


    /****************************** char32_t START ******************************/

    template<>
    struct StaticInfo<ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u}>
            : FundamentalStaticTypeInfo<char32_t, ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u}, StringLiteral{
                    "char32_t"},
                    StringLiteral{"char32_t"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<char32_t>() {
        return ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u};
    }

    template<>
    struct StaticInfo<ID{0x7533af4c07fe974u, 0xed00d63ecd2b4985u}>
            : StaticInfo_ConstWrap<ID{0x7533af4c07fe974u, 0xed00d63ecd2b4985u}, ID{0xcd5a3d19e1cb47e2u,
                                                                                   0x7c85d800ee25e093u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const char32_t>() {
        return ID{0x7533af4c07fe974u, 0xed00d63ecd2b4985u};
    }

    template<>
    struct StaticInfo<ID{0x7254722e55036281u, 0x3152185dff061c8bu}>
            : StaticInfo_LRefWrap<ID{0x7254722e55036281u, 0x3152185dff061c8bu}, ID{0xcd5a3d19e1cb47e2u,
                                                                                   0x7c85d800ee25e093u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<char32_t &>() {
        return ID{0x7254722e55036281u, 0x3152185dff061c8bu};
    }

    template<>
    struct StaticInfo<ID{0x21550a03ab48d6e7u, 0x5308b4bfb03087b7u}>
            : StaticInfo_ConstLRefWrap<ID{0x21550a03ab48d6e7u, 0x5308b4bfb03087b7u}, ID{0xcd5a3d19e1cb47e2u,
                                                                                        0x7c85d800ee25e093u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const char32_t &>() {
        return ID{0x21550a03ab48d6e7u, 0x5308b4bfb03087b7u};
    }

    template<>
    struct StaticInfo<ID{0xf54c8a47b019376u, 0xe14654d806eb0d8bu}>
            : StaticInfo_RRefWrap<ID{0xf54c8a47b019376u, 0xe14654d806eb0d8bu}, ID{0xcd5a3d19e1cb47e2u,
                                                                                  0x7c85d800ee25e093u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<char32_t &&>() {
        return ID{0xf54c8a47b019376u, 0xe14654d806eb0d8bu};
    }

    template<>
    struct StaticInfo<ID{0xd8537f7be3f1f94bu, 0xfb4775f3b04d748eu}>
            : StaticInfo_PtrWrap<ID{0xd8537f7be3f1f94bu, 0xfb4775f3b04d748eu}, ID{0xcd5a3d19e1cb47e2u,
                                                                                  0x7c85d800ee25e093u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<char32_t *>() {
        return ID{0xd8537f7be3f1f94bu, 0xfb4775f3b04d748eu};
    }

    template<>
    struct StaticInfo<ID{0x7357837e1aede48fu, 0xacb076072aad49bfu}>
            : StaticInfo_ConstPtrWrap<ID{0x7357837e1aede48fu, 0xacb076072aad49bfu}, ID{0xcd5a3d19e1cb47e2u,
                                                                                       0x7c85d800ee25e093u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const char32_t *>() {
        return ID{0x7357837e1aede48fu, 0xacb076072aad49bfu};
    }

    /****************************** char32_t END ******************************/


    /****************************** short START ******************************/

    template<>
    struct StaticInfo<ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u}>
            : FundamentalStaticTypeInfo<short, ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u}, StringLiteral{
                    "short"}, StringLiteral{"short"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<short>() {
        return ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u};
    }

    template<>
    struct StaticInfo<ID{0xed5cec9977e0c245u, 0x7500d9ddeac172b7u}>
            : StaticInfo_ConstWrap<ID{0xed5cec9977e0c245u, 0x7500d9ddeac172b7u}, ID{0x251fd1d86adfe99u,
                                                                                    0xfc3def08bda6d181u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const short>() {
        return ID{0xed5cec9977e0c245u, 0x7500d9ddeac172b7u};
    }

    template<>
    struct StaticInfo<ID{0xac519de3ddb5729cu, 0x3d5813badd346d9bu}>
            : StaticInfo_LRefWrap<ID{0xac519de3ddb5729cu, 0x3d5813badd346d9bu}, ID{0x251fd1d86adfe99u,
                                                                                   0xfc3def08bda6d181u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<short &>() {
        return ID{0xac519de3ddb5729cu, 0x3d5813badd346d9bu};
    }

    template<>
    struct StaticInfo<ID{0xb957ec8d8fd50425u, 0x5f0b1f6d3f4f31aau}>
            : StaticInfo_ConstLRefWrap<ID{0xb957ec8d8fd50425u, 0x5f0b1f6d3f4f31aau}, ID{0x251fd1d86adfe99u,
                                                                                        0xfc3def08bda6d181u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const short &>() {
        return ID{0xb957ec8d8fd50425u, 0x5f0b1f6d3f4f31aau};
    }

    template<>
    struct StaticInfo<ID{0xf657767ad123c9b5u, 0x163dadb1e387a098u}>
            : StaticInfo_RRefWrap<ID{0xf657767ad123c9b5u, 0x163dadb1e387a098u}, ID{0x251fd1d86adfe99u,
                                                                                   0xfc3def08bda6d181u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<short &&>() {
        return ID{0xf657767ad123c9b5u, 0x163dadb1e387a098u};
    }

    template<>
    struct StaticInfo<ID{0x235969853f625168u, 0x70bd45c22ddda398u}>
            : StaticInfo_PtrWrap<ID{0x235969853f625168u, 0x70bd45c22ddda398u}, ID{0x251fd1d86adfe99u,
                                                                                  0xfc3def08bda6d181u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<short *>() {
        return ID{0x235969853f625168u, 0x70bd45c22ddda398u};
    }

    template<>
    struct StaticInfo<ID{0xf5e54d8d26736c8u, 0x4de096d49f9ea680u}>
            : StaticInfo_ConstPtrWrap<ID{0xf5e54d8d26736c8u, 0x4de096d49f9ea680u}, ID{0x251fd1d86adfe99u,
                                                                                      0xfc3def08bda6d181u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const short *>() {
        return ID{0xf5e54d8d26736c8u, 0x4de096d49f9ea680u};
    }

    /****************************** short END ******************************/


    /****************************** unsigned short START ******************************/

    template<>
    struct StaticInfo<ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu}>
            : FundamentalStaticTypeInfo<unsigned short, ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu}, StringLiteral{
                    "unsigned short"},
                    StringLiteral{"unsigned short"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned short>() {
        return ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu};
    }

    template<>
    struct StaticInfo<ID{0x53566a9529bc2feau, 0x23c5a3c007be67acu}>
            : StaticInfo_ConstWrap<ID{0x53566a9529bc2feau, 0x23c5a3c007be67acu}, ID{0x935b0d8640a8c1cau,
                                                                                    0x3a76325e0c3ca49bu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned short>() {
        return ID{0x53566a9529bc2feau, 0x23c5a3c007be67acu};
    }

    template<>
    struct StaticInfo<ID{0x475221a7df54ffc7u, 0xb8cb4cd569392c8fu}>
            : StaticInfo_LRefWrap<ID{0x475221a7df54ffc7u, 0xb8cb4cd569392c8fu}, ID{0x935b0d8640a8c1cau,
                                                                                   0x3a76325e0c3ca49bu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned short &>() {
        return ID{0x475221a7df54ffc7u, 0xb8cb4cd569392c8fu};
    }

    template<>
    struct StaticInfo<ID{0x255f71a74692c44cu, 0x248d69c4aebdb88cu}>
            : StaticInfo_ConstLRefWrap<ID{0x255f71a74692c44cu, 0x248d69c4aebdb88cu}, ID{0x935b0d8640a8c1cau,
                                                                                        0x3a76325e0c3ca49bu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned short &>() {
        return ID{0x255f71a74692c44cu, 0x248d69c4aebdb88cu};
    }

    template<>
    struct StaticInfo<ID{0x305f6ac5122393b1u, 0xc286eb8c78a448a3u}>
            : StaticInfo_RRefWrap<ID{0x305f6ac5122393b1u, 0xc286eb8c78a448a3u}, ID{0x935b0d8640a8c1cau,
                                                                                   0x3a76325e0c3ca49bu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned short &&>() {
        return ID{0x305f6ac5122393b1u, 0xc286eb8c78a448a3u};
    }

    template<>
    struct StaticInfo<ID{0x2c5699d04826682cu, 0xfdf4910c7268f3b0u}>
            : StaticInfo_PtrWrap<ID{0x2c5699d04826682cu, 0xfdf4910c7268f3b0u}, ID{0x935b0d8640a8c1cau,
                                                                                  0x3a76325e0c3ca49bu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned short *>() {
        return ID{0x2c5699d04826682cu, 0xfdf4910c7268f3b0u};
    }

    template<>
    struct StaticInfo<ID{0x6b57e099fc4f7d1du, 0x6c64524376dd8797u}>
            : StaticInfo_ConstPtrWrap<ID{0x6b57e099fc4f7d1du, 0x6c64524376dd8797u}, ID{0x935b0d8640a8c1cau,
                                                                                       0x3a76325e0c3ca49bu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned short *>() {
        return ID{0x6b57e099fc4f7d1du, 0x6c64524376dd8797u};
    }

    /****************************** unsigned short END ******************************/


    /****************************** int START ******************************/

    template<>
    struct StaticInfo<ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u}>
            : FundamentalStaticTypeInfo<int, ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u}, StringLiteral{
                    "int"}, StringLiteral{"int"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<int>() {
        return ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};
    }

    template<>
    struct StaticInfo<ID{0x665f410a09366b80u, 0x6b633d160b5bec92u}>
            : StaticInfo_ConstWrap<ID{0x665f410a09366b80u, 0x6b633d160b5bec92u}, ID{0x6754bf6294b33eaau,
                                                                                    0xee27c164a5eec791u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const int>() {
        return ID{0x665f410a09366b80u, 0x6b633d160b5bec92u};
    }

    template<>
    struct StaticInfo<ID{0x475900e9b8f47f64u, 0x7264575f1cc9c48eu}>
            : StaticInfo_LRefWrap<ID{0x475900e9b8f47f64u, 0x7264575f1cc9c48eu}, ID{0x6754bf6294b33eaau,
                                                                                   0xee27c164a5eec791u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<int &>() {
        return ID{0x475900e9b8f47f64u, 0x7264575f1cc9c48eu};
    }

    template<>
    struct StaticInfo<ID{0xfd56559f6c66672bu, 0x7bda8b31e480e0b1u}>
            : StaticInfo_ConstLRefWrap<ID{0xfd56559f6c66672bu, 0x7bda8b31e480e0b1u}, ID{0x6754bf6294b33eaau,
                                                                                        0xee27c164a5eec791u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const int &>() {
        return ID{0xfd56559f6c66672bu, 0x7bda8b31e480e0b1u};
    }

    template<>
    struct StaticInfo<ID{0x85b8e46aa7a1966u, 0x5fa614f8703c98bfu}>
            : StaticInfo_RRefWrap<ID{0x85b8e46aa7a1966u, 0x5fa614f8703c98bfu}, ID{0x6754bf6294b33eaau,
                                                                                  0xee27c164a5eec791u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<int &&>() {
        return ID{0x85b8e46aa7a1966u, 0x5fa614f8703c98bfu};
    }

    template<>
    struct StaticInfo<ID{0x215b4c3a2de0d728u, 0x8ff9c30daab9bb97u}>
            : StaticInfo_PtrWrap<ID{0x215b4c3a2de0d728u, 0x8ff9c30daab9bb97u}, ID{0x6754bf6294b33eaau,
                                                                                  0xee27c164a5eec791u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<int *>() {
        return ID{0x215b4c3a2de0d728u, 0x8ff9c30daab9bb97u};
    }

    template<>
    struct StaticInfo<ID{0x495fab1dffe2002cu, 0xde23f78b1be389a9u}>
            : StaticInfo_ConstPtrWrap<ID{0x495fab1dffe2002cu, 0xde23f78b1be389a9u}, ID{0x6754bf6294b33eaau,
                                                                                       0xee27c164a5eec791u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const int *>() {
        return ID{0x495fab1dffe2002cu, 0xde23f78b1be389a9u};
    }

    /****************************** int END ******************************/


    /****************************** unsigned int START ******************************/

    template<>
    struct StaticInfo<ID{0x7c5094c82df7651au, 0x29ec00ba496465acu}>
            : FundamentalStaticTypeInfo<unsigned int, ID{0x7c5094c82df7651au, 0x29ec00ba496465acu}, StringLiteral{
                    "unsigned int"},
                    StringLiteral{"unsigned int"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned int>() {
        return ID{0x7c5094c82df7651au, 0x29ec00ba496465acu};
    }

    template<>
    struct StaticInfo<ID{0x7254b59fc96619ecu, 0x40bf3095f905d2a3u}>
            : StaticInfo_ConstWrap<ID{0x7254b59fc96619ecu, 0x40bf3095f905d2a3u}, ID{0x7c5094c82df7651au,
                                                                                    0x29ec00ba496465acu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned int>() {
        return ID{0x7254b59fc96619ecu, 0x40bf3095f905d2a3u};
    }

    template<>
    struct StaticInfo<ID{0x2e59fd8e0049d383u, 0x85102fbb53bba698u}>
            : StaticInfo_LRefWrap<ID{0x2e59fd8e0049d383u, 0x85102fbb53bba698u}, ID{0x7c5094c82df7651au,
                                                                                   0x29ec00ba496465acu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned int &>() {
        return ID{0x2e59fd8e0049d383u, 0x85102fbb53bba698u};
    }

    template<>
    struct StaticInfo<ID{0x9154980b58a21888u, 0xb860ce7528c1349au}>
            : StaticInfo_ConstLRefWrap<ID{0x9154980b58a21888u, 0xb860ce7528c1349au}, ID{0x7c5094c82df7651au,
                                                                                        0x29ec00ba496465acu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned int &>() {
        return ID{0x9154980b58a21888u, 0xb860ce7528c1349au};
    }

    template<>
    struct StaticInfo<ID{0xe45ee3b0eda5ab55u, 0xb226b237f7d810b3u}>
            : StaticInfo_RRefWrap<ID{0xe45ee3b0eda5ab55u, 0xb226b237f7d810b3u}, ID{0x7c5094c82df7651au,
                                                                                   0x29ec00ba496465acu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned int &&>() {
        return ID{0xe45ee3b0eda5ab55u, 0xb226b237f7d810b3u};
    }

    template<>
    struct StaticInfo<ID{0xd3539c2685ab88c0u, 0x3eb6ccad52bc2099u}>
            : StaticInfo_PtrWrap<ID{0xd3539c2685ab88c0u, 0x3eb6ccad52bc2099u}, ID{0x7c5094c82df7651au,
                                                                                  0x29ec00ba496465acu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned int *>() {
        return ID{0xd3539c2685ab88c0u, 0x3eb6ccad52bc2099u};
    }

    template<>
    struct StaticInfo<ID{0x75bf229cacd3be9u, 0x900379980a3788bau}>
            : StaticInfo_ConstPtrWrap<ID{0x75bf229cacd3be9u, 0x900379980a3788bau}, ID{0x7c5094c82df7651au,
                                                                                      0x29ec00ba496465acu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned int *>() {
        return ID{0x75bf229cacd3be9u, 0x900379980a3788bau};
    }

    /****************************** unsigned int END ******************************/


    /****************************** long START ******************************/

    template<>
    struct StaticInfo<ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u}>
            : FundamentalStaticTypeInfo<long, ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u}, StringLiteral{
                    "long"}, StringLiteral{"long"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<long>() {
        return ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u};
    }

    template<>
    struct StaticInfo<ID{0x45b292eb3e32248u, 0x4061035c34091cbdu}>
            : StaticInfo_ConstWrap<ID{0x45b292eb3e32248u, 0x4061035c34091cbdu}, ID{0x195eba21bd9000b8u,
                                                                                   0xfa34afb486ed7da1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const long>() {
        return ID{0x45b292eb3e32248u, 0x4061035c34091cbdu};
    }

    template<>
    struct StaticInfo<ID{0xf85d977d7ecbb0e5u, 0xa02e5ff6dfabda93u}>
            : StaticInfo_LRefWrap<ID{0xf85d977d7ecbb0e5u, 0xa02e5ff6dfabda93u}, ID{0x195eba21bd9000b8u,
                                                                                   0xfa34afb486ed7da1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<long &>() {
        return ID{0xf85d977d7ecbb0e5u, 0xa02e5ff6dfabda93u};
    }

    template<>
    struct StaticInfo<ID{0x1159e3a55080a5feu, 0x816f7931e7c3d784u}>
            : StaticInfo_ConstLRefWrap<ID{0x1159e3a55080a5feu, 0x816f7931e7c3d784u}, ID{0x195eba21bd9000b8u,
                                                                                        0xfa34afb486ed7da1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const long &>() {
        return ID{0x1159e3a55080a5feu, 0x816f7931e7c3d784u};
    }

    template<>
    struct StaticInfo<ID{0x3c5f6c8ec07d3398u, 0x11b3892297a2d3b8u}>
            : StaticInfo_RRefWrap<ID{0x3c5f6c8ec07d3398u, 0x11b3892297a2d3b8u}, ID{0x195eba21bd9000b8u,
                                                                                   0xfa34afb486ed7da1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<long &&>() {
        return ID{0x3c5f6c8ec07d3398u, 0x11b3892297a2d3b8u};
    }

    template<>
    struct StaticInfo<ID{0x9d5f204d756d38e6u, 0xf6e9959dec0f84a3u}>
            : StaticInfo_PtrWrap<ID{0x9d5f204d756d38e6u, 0xf6e9959dec0f84a3u}, ID{0x195eba21bd9000b8u,
                                                                                  0xfa34afb486ed7da1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<long *>() {
        return ID{0x9d5f204d756d38e6u, 0xf6e9959dec0f84a3u};
    }

    template<>
    struct StaticInfo<ID{0x1f53915a387b500fu, 0x41638efcc8deb2b3u}>
            : StaticInfo_ConstPtrWrap<ID{0x1f53915a387b500fu, 0x41638efcc8deb2b3u}, ID{0x195eba21bd9000b8u,
                                                                                       0xfa34afb486ed7da1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const long *>() {
        return ID{0x1f53915a387b500fu, 0x41638efcc8deb2b3u};
    }

    /****************************** long END ******************************/


    /****************************** unsigned long START ******************************/

    template<>
    struct StaticInfo<ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu}>
            : FundamentalStaticTypeInfo<unsigned long, ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu}, StringLiteral{
                    "unsigned long"},
                    StringLiteral{"unsigned long"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned long>() {
        return ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu};
    }

    template<>
    struct StaticInfo<ID{0x215e7c366e1d8c69u, 0x869a539e86ef749du}>
            : StaticInfo_ConstWrap<ID{0x215e7c366e1d8c69u, 0x869a539e86ef749du}, ID{0x445dbb8fa880cabbu,
                                                                                    0x58af47f69441c9bu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned long>() {
        return ID{0x215e7c366e1d8c69u, 0x869a539e86ef749du};
    }

    template<>
    struct StaticInfo<ID{0x3c5bda65185b4ebeu, 0xaa7361e30296d494u}>
            : StaticInfo_LRefWrap<ID{0x3c5bda65185b4ebeu, 0xaa7361e30296d494u}, ID{0x445dbb8fa880cabbu,
                                                                                   0x58af47f69441c9bu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned long &>() {
        return ID{0x3c5bda65185b4ebeu, 0xaa7361e30296d494u};
    }

    template<>
    struct StaticInfo<ID{0x5c547be0724eaeccu, 0x3bb8e77abad0daa4u}>
            : StaticInfo_ConstLRefWrap<ID{0x5c547be0724eaeccu, 0x3bb8e77abad0daa4u}, ID{0x445dbb8fa880cabbu,
                                                                                        0x58af47f69441c9bu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned long &>() {
        return ID{0x5c547be0724eaeccu, 0x3bb8e77abad0daa4u};
    }

    template<>
    struct StaticInfo<ID{0xcc53018a9649c631u, 0x7f4522d1d10762beu}>
            : StaticInfo_RRefWrap<ID{0xcc53018a9649c631u, 0x7f4522d1d10762beu}, ID{0x445dbb8fa880cabbu,
                                                                                   0x58af47f69441c9bu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned long &&>() {
        return ID{0xcc53018a9649c631u, 0x7f4522d1d10762beu};
    }

    template<>
    struct StaticInfo<ID{0x1b59173285f7e797u, 0xf70248f328d1bb8bu}>
            : StaticInfo_PtrWrap<ID{0x1b59173285f7e797u, 0xf70248f328d1bb8bu}, ID{0x445dbb8fa880cabbu,
                                                                                  0x58af47f69441c9bu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned long *>() {
        return ID{0x1b59173285f7e797u, 0xf70248f328d1bb8bu};
    }

    template<>
    struct StaticInfo<ID{0xb153ac170512657bu, 0xa4c8552c76ffd58fu}>
            : StaticInfo_ConstPtrWrap<ID{0xb153ac170512657bu, 0xa4c8552c76ffd58fu}, ID{0x445dbb8fa880cabbu,
                                                                                       0x58af47f69441c9bu}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned long *>() {
        return ID{0xb153ac170512657bu, 0xa4c8552c76ffd58fu};
    }

    /****************************** unsigned long END ******************************/


    /****************************** long long START ******************************/

    template<>
    struct StaticInfo<ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u}>
            : FundamentalStaticTypeInfo<long long, ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u}, StringLiteral{
                    "long long"},
                    StringLiteral{"long long"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<long long>() {
        return ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u};
    }

    template<>
    struct StaticInfo<ID{0xe650340d4d5732d5u, 0x1c0528dbc3bd0ca1u}>
            : StaticInfo_ConstWrap<ID{0xe650340d4d5732d5u, 0x1c0528dbc3bd0ca1u}, ID{0x6c528b40bb068e4cu,
                                                                                    0x4613be33456420b1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const long long>() {
        return ID{0xe650340d4d5732d5u, 0x1c0528dbc3bd0ca1u};
    }

    template<>
    struct StaticInfo<ID{0x1550ebcedc604b97u, 0x8912e93269941889u}>
            : StaticInfo_LRefWrap<ID{0x1550ebcedc604b97u, 0x8912e93269941889u}, ID{0x6c528b40bb068e4cu,
                                                                                   0x4613be33456420b1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<long long &>() {
        return ID{0x1550ebcedc604b97u, 0x8912e93269941889u};
    }

    template<>
    struct StaticInfo<ID{0x7a599689ad4ba8b7u, 0x732497823eb26980u}>
            : StaticInfo_ConstLRefWrap<ID{0x7a599689ad4ba8b7u, 0x732497823eb26980u}, ID{0x6c528b40bb068e4cu,
                                                                                        0x4613be33456420b1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const long long &>() {
        return ID{0x7a599689ad4ba8b7u, 0x732497823eb26980u};
    }

    template<>
    struct StaticInfo<ID{0x3a5d08e365c84050u, 0x51ba74e559b54898u}>
            : StaticInfo_RRefWrap<ID{0x3a5d08e365c84050u, 0x51ba74e559b54898u}, ID{0x6c528b40bb068e4cu,
                                                                                   0x4613be33456420b1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<long long &&>() {
        return ID{0x3a5d08e365c84050u, 0x51ba74e559b54898u};
    }

    template<>
    struct StaticInfo<ID{0x75513ed0e1d6335au, 0x9f0a1d0ecab1d6a4u}>
            : StaticInfo_PtrWrap<ID{0x75513ed0e1d6335au, 0x9f0a1d0ecab1d6a4u}, ID{0x6c528b40bb068e4cu,
                                                                                  0x4613be33456420b1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<long long *>() {
        return ID{0x75513ed0e1d6335au, 0x9f0a1d0ecab1d6a4u};
    }

    template<>
    struct StaticInfo<ID{0x1b5389dd2b6bc9f5u, 0xabade2af9e89c398u}>
            : StaticInfo_ConstPtrWrap<ID{0x1b5389dd2b6bc9f5u, 0xabade2af9e89c398u}, ID{0x6c528b40bb068e4cu,
                                                                                       0x4613be33456420b1u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const long long *>() {
        return ID{0x1b5389dd2b6bc9f5u, 0xabade2af9e89c398u};
    }

    /****************************** long long END ******************************/


    /****************************** unsigned long long START ******************************/

    template<>
    struct StaticInfo<ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u}>
            : FundamentalStaticTypeInfo<unsigned long long, ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u}, StringLiteral{
                    "unsigned long long"},
                    StringLiteral{"unsigned long long"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned long long>() {
        return ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u};
    }

    template<>
    struct StaticInfo<ID{0x745d37dfa15ac458u, 0xef44eac5b825d188u}>
            : StaticInfo_ConstWrap<ID{0x745d37dfa15ac458u, 0xef44eac5b825d188u}, ID{0xfa5c08425b0a22c4u,
                                                                                    0xb47a3509db6ca1b2u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned long long>() {
        return ID{0x745d37dfa15ac458u, 0xef44eac5b825d188u};
    }

    template<>
    struct StaticInfo<ID{0x7b5ffb59d9b3e373u, 0x48cb37fb95232ab6u}>
            : StaticInfo_LRefWrap<ID{0x7b5ffb59d9b3e373u, 0x48cb37fb95232ab6u}, ID{0xfa5c08425b0a22c4u,
                                                                                   0xb47a3509db6ca1b2u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned long long &>() {
        return ID{0x7b5ffb59d9b3e373u, 0x48cb37fb95232ab6u};
    }

    template<>
    struct StaticInfo<ID{0x2a57d4b2dc79f48eu, 0x13dd99df05f844afu}>
            : StaticInfo_ConstLRefWrap<ID{0x2a57d4b2dc79f48eu, 0x13dd99df05f844afu}, ID{0xfa5c08425b0a22c4u,
                                                                                        0xb47a3509db6ca1b2u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned long long &>() {
        return ID{0x2a57d4b2dc79f48eu, 0x13dd99df05f844afu};
    }

    template<>
    struct StaticInfo<ID{0x435fb6b0bea08bc3u, 0x61eb7fa666616682u}>
            : StaticInfo_RRefWrap<ID{0x435fb6b0bea08bc3u, 0x61eb7fa666616682u}, ID{0xfa5c08425b0a22c4u,
                                                                                   0xb47a3509db6ca1b2u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned long long &&>() {
        return ID{0x435fb6b0bea08bc3u, 0x61eb7fa666616682u};
    }

    template<>
    struct StaticInfo<ID{0xa15988cc204dca32u, 0x54c7f4f9439011a5u}>
            : StaticInfo_PtrWrap<ID{0xa15988cc204dca32u, 0x54c7f4f9439011a5u}, ID{0xfa5c08425b0a22c4u,
                                                                                  0xb47a3509db6ca1b2u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<unsigned long long *>() {
        return ID{0xa15988cc204dca32u, 0x54c7f4f9439011a5u};
    }

    template<>
    struct StaticInfo<ID{0xa658007b3bd552afu, 0x6a9b4318c9b537b9u}>
            : StaticInfo_ConstPtrWrap<ID{0xa658007b3bd552afu, 0x6a9b4318c9b537b9u}, ID{0xfa5c08425b0a22c4u,
                                                                                       0xb47a3509db6ca1b2u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const unsigned long long *>() {
        return ID{0xa658007b3bd552afu, 0x6a9b4318c9b537b9u};
    }

    /****************************** unsigned long long END ******************************/


    /****************************** float START ******************************/

    template<>
    struct StaticInfo<ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u}>
            : FundamentalStaticTypeInfo<float, ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u}, StringLiteral{
                    "float"}, StringLiteral{"float"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<float>() {
        return ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u};
    }

    template<>
    struct StaticInfo<ID{0x6c5181990dbe2580u, 0x79cf95a0b08f9099u}>
            : StaticInfo_ConstWrap<ID{0x6c5181990dbe2580u, 0x79cf95a0b08f9099u}, ID{0x2a58833512c58737u,
                                                                                    0x9967d24b6cfbaba3u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const float>() {
        return ID{0x6c5181990dbe2580u, 0x79cf95a0b08f9099u};
    }

    template<>
    struct StaticInfo<ID{0x4c5337bfd2a10f45u, 0xa06d672c8f319790u}>
            : StaticInfo_LRefWrap<ID{0x4c5337bfd2a10f45u, 0xa06d672c8f319790u}, ID{0x2a58833512c58737u,
                                                                                   0x9967d24b6cfbaba3u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<float &>() {
        return ID{0x4c5337bfd2a10f45u, 0xa06d672c8f319790u};
    }

    template<>
    struct StaticInfo<ID{0x7e592743ddd20612u, 0x3b8aa4561c365ca3u}>
            : StaticInfo_ConstLRefWrap<ID{0x7e592743ddd20612u, 0x3b8aa4561c365ca3u}, ID{0x2a58833512c58737u,
                                                                                        0x9967d24b6cfbaba3u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const float &>() {
        return ID{0x7e592743ddd20612u, 0x3b8aa4561c365ca3u};
    }

    template<>
    struct StaticInfo<ID{0xc85e10a5baf39006u, 0x47f6854340fe6996u}>
            : StaticInfo_RRefWrap<ID{0xc85e10a5baf39006u, 0x47f6854340fe6996u}, ID{0x2a58833512c58737u,
                                                                                   0x9967d24b6cfbaba3u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<float &&>() {
        return ID{0xc85e10a5baf39006u, 0x47f6854340fe6996u};
    }

    template<>
    struct StaticInfo<ID{0x4d5feb5a22826427u, 0x19991eb4561598b2u}>
            : StaticInfo_PtrWrap<ID{0x4d5feb5a22826427u, 0x19991eb4561598b2u}, ID{0x2a58833512c58737u,
                                                                                  0x9967d24b6cfbaba3u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<float *>() {
        return ID{0x4d5feb5a22826427u, 0x19991eb4561598b2u};
    }

    template<>
    struct StaticInfo<ID{0x5b52f737a000b500u, 0x1108e609b3b105b2u}>
            : StaticInfo_ConstPtrWrap<ID{0x5b52f737a000b500u, 0x1108e609b3b105b2u}, ID{0x2a58833512c58737u,
                                                                                       0x9967d24b6cfbaba3u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const float *>() {
        return ID{0x5b52f737a000b500u, 0x1108e609b3b105b2u};
    }

    /****************************** float END ******************************/


    /****************************** double START ******************************/

    template<>
    struct StaticInfo<ID{0x2250987dc79c7536u, 0x918fef864de1c190u}>
            : FundamentalStaticTypeInfo<double, ID{0x2250987dc79c7536u, 0x918fef864de1c190u}, StringLiteral{"double"},
                    StringLiteral{"double"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<double>() {
        return ID{0x2250987dc79c7536u, 0x918fef864de1c190u};
    }

    template<>
    struct StaticInfo<ID{0x5c5f0d6c2ec65a42u, 0xdf948560f301c0a5u}>
            : StaticInfo_ConstWrap<ID{0x5c5f0d6c2ec65a42u, 0xdf948560f301c0a5u}, ID{0x2250987dc79c7536u,
                                                                                    0x918fef864de1c190u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const double>() {
        return ID{0x5c5f0d6c2ec65a42u, 0xdf948560f301c0a5u};
    }

    template<>
    struct StaticInfo<ID{0x745f882955d75cd1u, 0x96e9c2b192c713b1u}>
            : StaticInfo_LRefWrap<ID{0x745f882955d75cd1u, 0x96e9c2b192c713b1u}, ID{0x2250987dc79c7536u,
                                                                                   0x918fef864de1c190u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<double &>() {
        return ID{0x745f882955d75cd1u, 0x96e9c2b192c713b1u};
    }

    template<>
    struct StaticInfo<ID{0x4f51d59774a8e0beu, 0xb49953ef50727f94u}>
            : StaticInfo_ConstLRefWrap<ID{0x4f51d59774a8e0beu, 0xb49953ef50727f94u}, ID{0x2250987dc79c7536u,
                                                                                        0x918fef864de1c190u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const double &>() {
        return ID{0x4f51d59774a8e0beu, 0xb49953ef50727f94u};
    }

    template<>
    struct StaticInfo<ID{0xfe516c62db3abb90u, 0xed0600f5edadd87u}>
            : StaticInfo_RRefWrap<ID{0xfe516c62db3abb90u, 0xed0600f5edadd87u}, ID{0x2250987dc79c7536u,
                                                                                  0x918fef864de1c190u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<double &&>() {
        return ID{0xfe516c62db3abb90u, 0xed0600f5edadd87u};
    }

    template<>
    struct StaticInfo<ID{0x82542f9245568929u, 0x8fdc42dae4e98b8u}>
            : StaticInfo_PtrWrap<ID{0x82542f9245568929u, 0x8fdc42dae4e98b8u}, ID{0x2250987dc79c7536u,
                                                                                 0x918fef864de1c190u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<double *>() {
        return ID{0x82542f9245568929u, 0x8fdc42dae4e98b8u};
    }

    template<>
    struct StaticInfo<ID{0xbc5f93b89a67ac60u, 0xa92be9a75b290fa8u}>
            : StaticInfo_ConstPtrWrap<ID{0xbc5f93b89a67ac60u, 0xa92be9a75b290fa8u}, ID{0x2250987dc79c7536u,
                                                                                       0x918fef864de1c190u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const double *>() {
        return ID{0xbc5f93b89a67ac60u, 0xa92be9a75b290fa8u};
    }

    /****************************** double END ******************************/


    /****************************** long double START ******************************/

    template<>
    struct StaticInfo<ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du}>
            : FundamentalStaticTypeInfo<long double, ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du}, StringLiteral{
                    "long double"},
                    StringLiteral{"long double"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<long double>() {
        return ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du};
    }

    template<>
    struct StaticInfo<ID{0x1f5ff0e360f679e3u, 0x3842c7bff674f99au}>
            : StaticInfo_ConstWrap<ID{0x1f5ff0e360f679e3u, 0x3842c7bff674f99au}, ID{0x1652ec5d2ecf538fu,
                                                                                    0x4f1f1410fe94a99du}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const long double>() {
        return ID{0x1f5ff0e360f679e3u, 0x3842c7bff674f99au};
    }

    template<>
    struct StaticInfo<ID{0x3050fed0235d5808u, 0x4a80db48d8fb0699u}>
            : StaticInfo_LRefWrap<ID{0x3050fed0235d5808u, 0x4a80db48d8fb0699u}, ID{0x1652ec5d2ecf538fu,
                                                                                   0x4f1f1410fe94a99du}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<long double &>() {
        return ID{0x3050fed0235d5808u, 0x4a80db48d8fb0699u};
    }

    template<>
    struct StaticInfo<ID{0xc255aaaba58c8496u, 0xf64c15a201f1c5adu}>
            : StaticInfo_ConstLRefWrap<ID{0xc255aaaba58c8496u, 0xf64c15a201f1c5adu}, ID{0x1652ec5d2ecf538fu,
                                                                                        0x4f1f1410fe94a99du}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const long double &>() {
        return ID{0xc255aaaba58c8496u, 0xf64c15a201f1c5adu};
    }

    template<>
    struct StaticInfo<ID{0x98544632fbea73deu, 0x9866d10c264fd59eu}>
            : StaticInfo_RRefWrap<ID{0x98544632fbea73deu, 0x9866d10c264fd59eu}, ID{0x1652ec5d2ecf538fu,
                                                                                   0x4f1f1410fe94a99du}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<long double &&>() {
        return ID{0x98544632fbea73deu, 0x9866d10c264fd59eu};
    }

    template<>
    struct StaticInfo<ID{0x32584c645b0f50fdu, 0xb61e58614863869au}>
            : StaticInfo_PtrWrap<ID{0x32584c645b0f50fdu, 0xb61e58614863869au}, ID{0x1652ec5d2ecf538fu,
                                                                                  0x4f1f1410fe94a99du}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<long double *>() {
        return ID{0x32584c645b0f50fdu, 0xb61e58614863869au};
    }

    template<>
    struct StaticInfo<ID{0x595fde3b44375cf7u, 0xb23e906801e31b8fu}>
            : StaticInfo_ConstPtrWrap<ID{0x595fde3b44375cf7u, 0xb23e906801e31b8fu}, ID{0x1652ec5d2ecf538fu,
                                                                                       0x4f1f1410fe94a99du}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const long double *>() {
        return ID{0x595fde3b44375cf7u, 0xb23e906801e31b8fu};
    }

    /****************************** long double END ******************************/


    /****************************** void START ******************************/

    template<>
    struct StaticInfo<ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u}>
            : FundamentalStaticTypeInfo<void, ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u}, StringLiteral{
                    "void"}, StringLiteral{"void"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<void>() {
        return ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u};
    }

    template<>
    struct StaticInfo<ID{0xf05076834e6d58b8u, 0x261c32ecd65c1a9eu}>
            : StaticInfo_PtrWrap<ID{0xf05076834e6d58b8u, 0x261c32ecd65c1a9eu}, ID{0x115e3a70749cfd72u,
                                                                                  0xadd9686c1dcb30a2u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<void *>() {
        return ID{0xf05076834e6d58b8u, 0x261c32ecd65c1a9eu};
    }

    template<>
    struct StaticInfo<ID{0xbb501da6b2a64927u, 0x2055b662df5b979fu}>
            : StaticInfo_ConstPtrWrap<ID{0xbb501da6b2a64927u, 0x2055b662df5b979fu}, ID{0x115e3a70749cfd72u,
                                                                                       0xadd9686c1dcb30a2u}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<const void *>() {
        return ID{0xbb501da6b2a64927u, 0x2055b662df5b979fu};
    }

    /****************************** void END ******************************/


    /****************************** std::nullptr_t START ******************************/

    template<>
    struct StaticInfo<ID{0x38544f066c280c57u, 0xa81e153a29bca6a3u}>
            : FundamentalStaticTypeInfo<std::nullptr_t, ID{0x38544f066c280c57u, 0xa81e153a29bca6a3u}, StringLiteral{
                    "nullptr_t"},
                    StringLiteral{"std::nullptr_t"}> {
    };

    template<>
    [[nodiscard]] consteval ID getTypeId<std::nullptr_t>() {
        return ID{0x38544f066c280c57u, 0xa81e153a29bca6a3u};
    }

    /****************************** std::nullptr_t END ******************************/


}// namespace pf::meta::details


#endif//PF_META_FUNDAMENTAL_TYPES_META_H
