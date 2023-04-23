#pragma once

#include <meta/Attribute.h>
#include <meta/Info.h>
#include <meta/details/StaticInfo.h>
#include <meta/details/StringLiteral.hpp>
#include <meta/details/StaticInfo_Wrappers.h>
#include <meta/details/array.h>

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
struct StaticInfo<ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u}> : FundamentalStaticTypeInfo<bool, ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u}, StringLiteral{"bool"}, StringLiteral{"bool"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<bool>() {
    return ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u};
}

template<>
struct StaticInfo<ID{0x3955509119bfedbau, 0x390227b6574b7cb4u}> : StaticInfo_ConstWrap<ID{0x3955509119bfedbau, 0x390227b6574b7cb4u}, ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const bool>() {
    return ID{0x3955509119bfedbau, 0x390227b6574b7cb4u};
}

template<>
struct StaticInfo<ID{0x6257ab1ea16cb777u, 0x8f4efe359576158cu}> : StaticInfo_LRefWrap<ID{0x6257ab1ea16cb777u, 0x8f4efe359576158cu}, ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<bool &>() {
    return ID{0x6257ab1ea16cb777u, 0x8f4efe359576158cu};
}

template<>
struct StaticInfo<ID{0x2d58d13c75aca8aau, 0xfafd6cd95b79f2aeu}> : StaticInfo_ConstLRefWrap<ID{0x2d58d13c75aca8aau, 0xfafd6cd95b79f2aeu}, ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const bool &>() {
    return ID{0x2d58d13c75aca8aau, 0xfafd6cd95b79f2aeu};
}

template<>
struct StaticInfo<ID{0xe35d0d538e2550bfu, 0x3dd7a62efd8218bfu}> : StaticInfo_RRefWrap<ID{0xe35d0d538e2550bfu, 0x3dd7a62efd8218bfu}, ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<bool &&>() {
    return ID{0xe35d0d538e2550bfu, 0x3dd7a62efd8218bfu};
}

template<>
struct StaticInfo<ID{0x6f57ee830aa04756u, 0x68562de9e060dfbbu}> : StaticInfo_PtrWrap<ID{0x6f57ee830aa04756u, 0x68562de9e060dfbbu}, ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<bool *>() {
    return ID{0x6f57ee830aa04756u, 0x68562de9e060dfbbu};
}

template<>
struct StaticInfo<ID{0xac5616452b1549fau, 0x96e42ccd5cd16185u}> : StaticInfo_ConstPtrWrap<ID{0xac5616452b1549fau, 0x96e42ccd5cd16185u}, ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const bool *>() {
    return ID{0xac5616452b1549fau, 0x96e42ccd5cd16185u};
}

/****************************** bool END ******************************/


/****************************** char START ******************************/

template<>
struct StaticInfo<ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u}> : FundamentalStaticTypeInfo<char, ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u}, StringLiteral{"char"}, StringLiteral{"char"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<char>() {
    return ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u};
}

template<>
struct StaticInfo<ID{0x5a5831b93f51f2b7u, 0x29731d2971712783u}> : StaticInfo_ConstWrap<ID{0x5a5831b93f51f2b7u, 0x29731d2971712783u}, ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const char>() {
    return ID{0x5a5831b93f51f2b7u, 0x29731d2971712783u};
}

template<>
struct StaticInfo<ID{0x1a554e1be39d5385u, 0xff526d589eb11498u}> : StaticInfo_LRefWrap<ID{0x1a554e1be39d5385u, 0xff526d589eb11498u}, ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<char &>() {
    return ID{0x1a554e1be39d5385u, 0xff526d589eb11498u};
}

template<>
struct StaticInfo<ID{0xd05564d7b21d3eadu, 0x121ffcfd5cf6981u}> : StaticInfo_ConstLRefWrap<ID{0xd05564d7b21d3eadu, 0x121ffcfd5cf6981u}, ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const char &>() {
    return ID{0xd05564d7b21d3eadu, 0x121ffcfd5cf6981u};
}

template<>
struct StaticInfo<ID{0xf954daa206724fa0u, 0xd2524e7ea007d48bu}> : StaticInfo_RRefWrap<ID{0xf954daa206724fa0u, 0xd2524e7ea007d48bu}, ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<char &&>() {
    return ID{0xf954daa206724fa0u, 0xd2524e7ea007d48bu};
}

template<>
struct StaticInfo<ID{0x6e5c48010e06195au, 0xba309fdf2e43ce81u}> : StaticInfo_PtrWrap<ID{0x6e5c48010e06195au, 0xba309fdf2e43ce81u}, ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<char *>() {
    return ID{0x6e5c48010e06195au, 0xba309fdf2e43ce81u};
}

template<>
struct StaticInfo<ID{0xcb593637815ab80bu, 0x1be8fa5cd93a23aeu}> : StaticInfo_ConstPtrWrap<ID{0xcb593637815ab80bu, 0x1be8fa5cd93a23aeu}, ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const char *>() {
    return ID{0xcb593637815ab80bu, 0x1be8fa5cd93a23aeu};
}

/****************************** char END ******************************/


/****************************** signed char START ******************************/

template<>
struct StaticInfo<ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu}> : FundamentalStaticTypeInfo<signed char, ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu}, StringLiteral{"signed char"}, StringLiteral{"signed char"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<signed char>() {
    return ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu};
}

template<>
struct StaticInfo<ID{0xa15a4308db285fd5u, 0xf33d92ae3380d9a8u}> : StaticInfo_ConstWrap<ID{0xa15a4308db285fd5u, 0xf33d92ae3380d9a8u}, ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const signed char>() {
    return ID{0xa15a4308db285fd5u, 0xf33d92ae3380d9a8u};
}

template<>
struct StaticInfo<ID{0xc153b5e6207e7733u, 0xcd3aa4027ed01d8eu}> : StaticInfo_LRefWrap<ID{0xc153b5e6207e7733u, 0xcd3aa4027ed01d8eu}, ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<signed char &>() {
    return ID{0xc153b5e6207e7733u, 0xcd3aa4027ed01d8eu};
}

template<>
struct StaticInfo<ID{0xd3535f2cadb5aa2cu, 0xa9b71af23b0ce1adu}> : StaticInfo_ConstLRefWrap<ID{0xd3535f2cadb5aa2cu, 0xa9b71af23b0ce1adu}, ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const signed char &>() {
    return ID{0xd3535f2cadb5aa2cu, 0xa9b71af23b0ce1adu};
}

template<>
struct StaticInfo<ID{0xdc58a62b0e712b12u, 0x7108e9619d68d0afu}> : StaticInfo_RRefWrap<ID{0xdc58a62b0e712b12u, 0x7108e9619d68d0afu}, ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<signed char &&>() {
    return ID{0xdc58a62b0e712b12u, 0x7108e9619d68d0afu};
}

template<>
struct StaticInfo<ID{0xcc51a0bed1b4d60du, 0x4726df8c37b25c9au}> : StaticInfo_PtrWrap<ID{0xcc51a0bed1b4d60du, 0x4726df8c37b25c9au}, ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<signed char *>() {
    return ID{0xcc51a0bed1b4d60du, 0x4726df8c37b25c9au};
}

template<>
struct StaticInfo<ID{0xba55b7a798e6319du, 0x761bd4edeed95d92u}> : StaticInfo_ConstPtrWrap<ID{0xba55b7a798e6319du, 0x761bd4edeed95d92u}, ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const signed char *>() {
    return ID{0xba55b7a798e6319du, 0x761bd4edeed95d92u};
}

/****************************** signed char END ******************************/


/****************************** unsigned char START ******************************/

template<>
struct StaticInfo<ID{0x5f56c0b531733454u, 0x552996f604766e9au}> : FundamentalStaticTypeInfo<unsigned char, ID{0x5f56c0b531733454u, 0x552996f604766e9au}, StringLiteral{"unsigned char"}, StringLiteral{"unsigned char"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned char>() {
    return ID{0x5f56c0b531733454u, 0x552996f604766e9au};
}

template<>
struct StaticInfo<ID{0x7056905a8106507fu, 0x71ae48440ccffcb4u}> : StaticInfo_ConstWrap<ID{0x7056905a8106507fu, 0x71ae48440ccffcb4u}, ID{0x5f56c0b531733454u, 0x552996f604766e9au}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const unsigned char>() {
    return ID{0x7056905a8106507fu, 0x71ae48440ccffcb4u};
}

template<>
struct StaticInfo<ID{0x72551817d67907bcu, 0x799dd5c45e0566a3u}> : StaticInfo_LRefWrap<ID{0x72551817d67907bcu, 0x799dd5c45e0566a3u}, ID{0x5f56c0b531733454u, 0x552996f604766e9au}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned char &>() {
    return ID{0x72551817d67907bcu, 0x799dd5c45e0566a3u};
}

template<>
struct StaticInfo<ID{0x565aabbfe666c1a5u, 0x8748d6077723a0afu}> : StaticInfo_ConstLRefWrap<ID{0x565aabbfe666c1a5u, 0x8748d6077723a0afu}, ID{0x5f56c0b531733454u, 0x552996f604766e9au}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const unsigned char &>() {
    return ID{0x565aabbfe666c1a5u, 0x8748d6077723a0afu};
}

template<>
struct StaticInfo<ID{0xaf56f948688cba17u, 0xd792304e886c1ebeu}> : StaticInfo_RRefWrap<ID{0xaf56f948688cba17u, 0xd792304e886c1ebeu}, ID{0x5f56c0b531733454u, 0x552996f604766e9au}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned char &&>() {
    return ID{0xaf56f948688cba17u, 0xd792304e886c1ebeu};
}

template<>
struct StaticInfo<ID{0x855f257e8918dfefu, 0x9f68429bd2797f9eu}> : StaticInfo_PtrWrap<ID{0x855f257e8918dfefu, 0x9f68429bd2797f9eu}, ID{0x5f56c0b531733454u, 0x552996f604766e9au}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned char *>() {
    return ID{0x855f257e8918dfefu, 0x9f68429bd2797f9eu};
}

template<>
struct StaticInfo<ID{0x705e43a18ef0b073u, 0xa16e7a3bde43e0b4u}> : StaticInfo_ConstPtrWrap<ID{0x705e43a18ef0b073u, 0xa16e7a3bde43e0b4u}, ID{0x5f56c0b531733454u, 0x552996f604766e9au}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const unsigned char *>() {
    return ID{0x705e43a18ef0b073u, 0xa16e7a3bde43e0b4u};
}

/****************************** unsigned char END ******************************/


/****************************** char8_t START ******************************/

template<>
struct StaticInfo<ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u}> : FundamentalStaticTypeInfo<char8_t, ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u}, StringLiteral{"char8_t"}, StringLiteral{"char8_t"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<char8_t>() {
    return ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u};
}

template<>
struct StaticInfo<ID{0xc9530303ca614c38u, 0x4af94572d14b66bcu}> : StaticInfo_ConstWrap<ID{0xc9530303ca614c38u, 0x4af94572d14b66bcu}, ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const char8_t>() {
    return ID{0xc9530303ca614c38u, 0x4af94572d14b66bcu};
}

template<>
struct StaticInfo<ID{0xcb59818c815e73dbu, 0x6b7586412210e9bdu}> : StaticInfo_LRefWrap<ID{0xcb59818c815e73dbu, 0x6b7586412210e9bdu}, ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<char8_t &>() {
    return ID{0xcb59818c815e73dbu, 0x6b7586412210e9bdu};
}

template<>
struct StaticInfo<ID{0xab5e10ab5178614bu, 0xb31bfdea3e3f5986u}> : StaticInfo_ConstLRefWrap<ID{0xab5e10ab5178614bu, 0xb31bfdea3e3f5986u}, ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const char8_t &>() {
    return ID{0xab5e10ab5178614bu, 0xb31bfdea3e3f5986u};
}

template<>
struct StaticInfo<ID{0x6d5260341a35e936u, 0x5c0ed2bf2b1fbeafu}> : StaticInfo_RRefWrap<ID{0x6d5260341a35e936u, 0x5c0ed2bf2b1fbeafu}, ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<char8_t &&>() {
    return ID{0x6d5260341a35e936u, 0x5c0ed2bf2b1fbeafu};
}

template<>
struct StaticInfo<ID{0x845983d6738017a5u, 0xc62744d5443cd889u}> : StaticInfo_PtrWrap<ID{0x845983d6738017a5u, 0xc62744d5443cd889u}, ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<char8_t *>() {
    return ID{0x845983d6738017a5u, 0xc62744d5443cd889u};
}

template<>
struct StaticInfo<ID{0x2a58a22ae5edf288u, 0x66a462cf1fa33e95u}> : StaticInfo_ConstPtrWrap<ID{0x2a58a22ae5edf288u, 0x66a462cf1fa33e95u}, ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const char8_t *>() {
    return ID{0x2a58a22ae5edf288u, 0x66a462cf1fa33e95u};
}

/****************************** char8_t END ******************************/


/****************************** char16_t START ******************************/

template<>
struct StaticInfo<ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu}> : FundamentalStaticTypeInfo<char16_t, ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu}, StringLiteral{"char16_t"}, StringLiteral{"char16_t"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<char16_t>() {
    return ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu};
}

template<>
struct StaticInfo<ID{0x1f50450503737047u, 0xe787f92a0a689498u}> : StaticInfo_ConstWrap<ID{0x1f50450503737047u, 0xe787f92a0a689498u}, ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const char16_t>() {
    return ID{0x1f50450503737047u, 0xe787f92a0a689498u};
}

template<>
struct StaticInfo<ID{0x675f7da8b7164c2cu, 0x7933a6b6437c49a9u}> : StaticInfo_LRefWrap<ID{0x675f7da8b7164c2cu, 0x7933a6b6437c49a9u}, ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<char16_t &>() {
    return ID{0x675f7da8b7164c2cu, 0x7933a6b6437c49a9u};
}

template<>
struct StaticInfo<ID{0x5754d2aea9b3e5a9u, 0x96f24bd91429888u}> : StaticInfo_ConstLRefWrap<ID{0x5754d2aea9b3e5a9u, 0x96f24bd91429888u}, ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const char16_t &>() {
    return ID{0x5754d2aea9b3e5a9u, 0x96f24bd91429888u};
}

template<>
struct StaticInfo<ID{0x7c5e5d5546743eacu, 0xed4600ac2720097u}> : StaticInfo_RRefWrap<ID{0x7c5e5d5546743eacu, 0xed4600ac2720097u}, ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<char16_t &&>() {
    return ID{0x7c5e5d5546743eacu, 0xed4600ac2720097u};
}

template<>
struct StaticInfo<ID{0x1b546b5fa30eb5e1u, 0xa6896c295581c288u}> : StaticInfo_PtrWrap<ID{0x1b546b5fa30eb5e1u, 0xa6896c295581c288u}, ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<char16_t *>() {
    return ID{0x1b546b5fa30eb5e1u, 0xa6896c295581c288u};
}

template<>
struct StaticInfo<ID{0x2451f5124168f239u, 0xcba80e43db2cac87u}> : StaticInfo_ConstPtrWrap<ID{0x2451f5124168f239u, 0xcba80e43db2cac87u}, ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const char16_t *>() {
    return ID{0x2451f5124168f239u, 0xcba80e43db2cac87u};
}

/****************************** char16_t END ******************************/


/****************************** char32_t START ******************************/

template<>
struct StaticInfo<ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u}> : FundamentalStaticTypeInfo<char32_t, ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u}, StringLiteral{"char32_t"}, StringLiteral{"char32_t"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<char32_t>() {
    return ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u};
}

template<>
struct StaticInfo<ID{0x7533af4c07fe974u, 0xed00d63ecd2b4985u}> : StaticInfo_ConstWrap<ID{0x7533af4c07fe974u, 0xed00d63ecd2b4985u}, ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const char32_t>() {
    return ID{0x7533af4c07fe974u, 0xed00d63ecd2b4985u};
}

template<>
struct StaticInfo<ID{0x565bb498db8e5e99u, 0xf2a0a38a8a9ac7aeu}> : StaticInfo_LRefWrap<ID{0x565bb498db8e5e99u, 0xf2a0a38a8a9ac7aeu}, ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<char32_t &>() {
    return ID{0x565bb498db8e5e99u, 0xf2a0a38a8a9ac7aeu};
}

template<>
struct StaticInfo<ID{0x7f556391e24f1831u, 0x4ba88489fd0ed6b0u}> : StaticInfo_ConstLRefWrap<ID{0x7f556391e24f1831u, 0x4ba88489fd0ed6b0u}, ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const char32_t &>() {
    return ID{0x7f556391e24f1831u, 0x4ba88489fd0ed6b0u};
}

template<>
struct StaticInfo<ID{0x8f5170ad60b30ff3u, 0x184c7f0d6700d89fu}> : StaticInfo_RRefWrap<ID{0x8f5170ad60b30ff3u, 0x184c7f0d6700d89fu}, ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<char32_t &&>() {
    return ID{0x8f5170ad60b30ff3u, 0x184c7f0d6700d89fu};
}

template<>
struct StaticInfo<ID{0x8f54207e30aa933cu, 0x92ee1afc3c8aa18au}> : StaticInfo_PtrWrap<ID{0x8f54207e30aa933cu, 0x92ee1afc3c8aa18au}, ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<char32_t *>() {
    return ID{0x8f54207e30aa933cu, 0x92ee1afc3c8aa18au};
}

template<>
struct StaticInfo<ID{0x83540e126fb7b908u, 0xa8f509693a875888u}> : StaticInfo_ConstPtrWrap<ID{0x83540e126fb7b908u, 0xa8f509693a875888u}, ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const char32_t *>() {
    return ID{0x83540e126fb7b908u, 0xa8f509693a875888u};
}

/****************************** char32_t END ******************************/


/****************************** short START ******************************/

template<>
struct StaticInfo<ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u}> : FundamentalStaticTypeInfo<short, ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u}, StringLiteral{"short"}, StringLiteral{"short"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<short>() {
    return ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u};
}

template<>
struct StaticInfo<ID{0xed5cec9977e0c245u, 0x7500d9ddeac172b7u}> : StaticInfo_ConstWrap<ID{0xed5cec9977e0c245u, 0x7500d9ddeac172b7u}, ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const short>() {
    return ID{0xed5cec9977e0c245u, 0x7500d9ddeac172b7u};
}

template<>
struct StaticInfo<ID{0x6c5a46dc5e19013fu, 0x1164ec6427a9bbb0u}> : StaticInfo_LRefWrap<ID{0x6c5a46dc5e19013fu, 0x1164ec6427a9bbb0u}, ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<short &>() {
    return ID{0x6c5a46dc5e19013fu, 0x1164ec6427a9bbb0u};
}

template<>
struct StaticInfo<ID{0xc25fbdd6d75dead8u, 0x85543b0da9cbe2aeu}> : StaticInfo_ConstLRefWrap<ID{0xc25fbdd6d75dead8u, 0x85543b0da9cbe2aeu}, ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const short &>() {
    return ID{0xc25fbdd6d75dead8u, 0x85543b0da9cbe2aeu};
}

template<>
struct StaticInfo<ID{0x815faa9d0c5a0b6cu, 0x6727144a2701b1b4u}> : StaticInfo_RRefWrap<ID{0x815faa9d0c5a0b6cu, 0x6727144a2701b1b4u}, ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<short &&>() {
    return ID{0x815faa9d0c5a0b6cu, 0x6727144a2701b1b4u};
}

template<>
struct StaticInfo<ID{0xf3557f88baf01c79u, 0x38ab1678367f829eu}> : StaticInfo_PtrWrap<ID{0xf3557f88baf01c79u, 0x38ab1678367f829eu}, ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<short *>() {
    return ID{0xf3557f88baf01c79u, 0x38ab1678367f829eu};
}

template<>
struct StaticInfo<ID{0x345db25d3961bfdau, 0x9dcfac17c42488a5u}> : StaticInfo_ConstPtrWrap<ID{0x345db25d3961bfdau, 0x9dcfac17c42488a5u}, ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const short *>() {
    return ID{0x345db25d3961bfdau, 0x9dcfac17c42488a5u};
}

/****************************** short END ******************************/


/****************************** unsigned short START ******************************/

template<>
struct StaticInfo<ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu}> : FundamentalStaticTypeInfo<unsigned short, ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu}, StringLiteral{"unsigned short"}, StringLiteral{"unsigned short"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned short>() {
    return ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu};
}

template<>
struct StaticInfo<ID{0x53566a9529bc2feau, 0x23c5a3c007be67acu}> : StaticInfo_ConstWrap<ID{0x53566a9529bc2feau, 0x23c5a3c007be67acu}, ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const unsigned short>() {
    return ID{0x53566a9529bc2feau, 0x23c5a3c007be67acu};
}

template<>
struct StaticInfo<ID{0xf15fbc42109decb0u, 0xad1a2bec86129eb7u}> : StaticInfo_LRefWrap<ID{0xf15fbc42109decb0u, 0xad1a2bec86129eb7u}, ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned short &>() {
    return ID{0xf15fbc42109decb0u, 0xad1a2bec86129eb7u};
}

template<>
struct StaticInfo<ID{0xce57aeb150bd9e6fu, 0x99f69e774b30cea7u}> : StaticInfo_ConstLRefWrap<ID{0xce57aeb150bd9e6fu, 0x99f69e774b30cea7u}, ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const unsigned short &>() {
    return ID{0xce57aeb150bd9e6fu, 0x99f69e774b30cea7u};
}

template<>
struct StaticInfo<ID{0x655ae7798f0c46f7u, 0x81d900c94c55a6a6u}> : StaticInfo_RRefWrap<ID{0x655ae7798f0c46f7u, 0x81d900c94c55a6a6u}, ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned short &&>() {
    return ID{0x655ae7798f0c46f7u, 0x81d900c94c55a6a6u};
}

template<>
struct StaticInfo<ID{0x985c34a45f6a4078u, 0x107ad66b67ec4191u}> : StaticInfo_PtrWrap<ID{0x985c34a45f6a4078u, 0x107ad66b67ec4191u}, ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned short *>() {
    return ID{0x985c34a45f6a4078u, 0x107ad66b67ec4191u};
}

template<>
struct StaticInfo<ID{0x355b3bbddde4ddc0u, 0xa1d9b34a21efe685u}> : StaticInfo_ConstPtrWrap<ID{0x355b3bbddde4ddc0u, 0xa1d9b34a21efe685u}, ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const unsigned short *>() {
    return ID{0x355b3bbddde4ddc0u, 0xa1d9b34a21efe685u};
}

/****************************** unsigned short END ******************************/


/****************************** int START ******************************/

template<>
struct StaticInfo<ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u}> : FundamentalStaticTypeInfo<int, ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u}, StringLiteral{"int"}, StringLiteral{"int"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<int>() {
    return ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u};
}

template<>
struct StaticInfo<ID{0x665f410a09366b80u, 0x6b633d160b5bec92u}> : StaticInfo_ConstWrap<ID{0x665f410a09366b80u, 0x6b633d160b5bec92u}, ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const int>() {
    return ID{0x665f410a09366b80u, 0x6b633d160b5bec92u};
}

template<>
struct StaticInfo<ID{0xbf5a5bd5fafcef78u, 0xb4f19f7559ac7c8cu}> : StaticInfo_LRefWrap<ID{0xbf5a5bd5fafcef78u, 0xb4f19f7559ac7c8cu}, ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<int &>() {
    return ID{0xbf5a5bd5fafcef78u, 0xb4f19f7559ac7c8cu};
}

template<>
struct StaticInfo<ID{0x5353f353f7061791u, 0xb12d52dfd778708au}> : StaticInfo_ConstLRefWrap<ID{0x5353f353f7061791u, 0xb12d52dfd778708au}, ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const int &>() {
    return ID{0x5353f353f7061791u, 0xb12d52dfd778708au};
}

template<>
struct StaticInfo<ID{0x75dbde129af80fbu, 0x5dcd0809b054718bu}> : StaticInfo_RRefWrap<ID{0x75dbde129af80fbu, 0x5dcd0809b054718bu}, ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<int &&>() {
    return ID{0x75dbde129af80fbu, 0x5dcd0809b054718bu};
}

template<>
struct StaticInfo<ID{0xc155994cc399e96bu, 0x931d8aae3f811891u}> : StaticInfo_PtrWrap<ID{0xc155994cc399e96bu, 0x931d8aae3f811891u}, ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<int *>() {
    return ID{0xc155994cc399e96bu, 0x931d8aae3f811891u};
}

template<>
struct StaticInfo<ID{0xec5c8c071560a289u, 0xe958ef625f8faaeu}> : StaticInfo_ConstPtrWrap<ID{0xec5c8c071560a289u, 0xe958ef625f8faaeu}, ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const int *>() {
    return ID{0xec5c8c071560a289u, 0xe958ef625f8faaeu};
}

/****************************** int END ******************************/


/****************************** unsigned int START ******************************/

template<>
struct StaticInfo<ID{0x7c5094c82df7651au, 0x29ec00ba496465acu}> : FundamentalStaticTypeInfo<unsigned int, ID{0x7c5094c82df7651au, 0x29ec00ba496465acu}, StringLiteral{"unsigned int"}, StringLiteral{"unsigned int"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned int>() {
    return ID{0x7c5094c82df7651au, 0x29ec00ba496465acu};
}

template<>
struct StaticInfo<ID{0x7254b59fc96619ecu, 0x40bf3095f905d2a3u}> : StaticInfo_ConstWrap<ID{0x7254b59fc96619ecu, 0x40bf3095f905d2a3u}, ID{0x7c5094c82df7651au, 0x29ec00ba496465acu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const unsigned int>() {
    return ID{0x7254b59fc96619ecu, 0x40bf3095f905d2a3u};
}

template<>
struct StaticInfo<ID{0x585034b1da852dc9u, 0x528ffaf1701fffbeu}> : StaticInfo_LRefWrap<ID{0x585034b1da852dc9u, 0x528ffaf1701fffbeu}, ID{0x7c5094c82df7651au, 0x29ec00ba496465acu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned int &>() {
    return ID{0x585034b1da852dc9u, 0x528ffaf1701fffbeu};
}

template<>
struct StaticInfo<ID{0x5d59dfc2319ac89au, 0xd5d5f3b44b51f85u}> : StaticInfo_ConstLRefWrap<ID{0x5d59dfc2319ac89au, 0xd5d5f3b44b51f85u}, ID{0x7c5094c82df7651au, 0x29ec00ba496465acu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const unsigned int &>() {
    return ID{0x5d59dfc2319ac89au, 0xd5d5f3b44b51f85u};
}

template<>
struct StaticInfo<ID{0x253a791f38b8356u, 0x93946483f0548ba3u}> : StaticInfo_RRefWrap<ID{0x253a791f38b8356u, 0x93946483f0548ba3u}, ID{0x7c5094c82df7651au, 0x29ec00ba496465acu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned int &&>() {
    return ID{0x253a791f38b8356u, 0x93946483f0548ba3u};
}

template<>
struct StaticInfo<ID{0x555fe1e00c7e88cfu, 0x60f3a5fe4b257aaau}> : StaticInfo_PtrWrap<ID{0x555fe1e00c7e88cfu, 0x60f3a5fe4b257aaau}, ID{0x7c5094c82df7651au, 0x29ec00ba496465acu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned int *>() {
    return ID{0x555fe1e00c7e88cfu, 0x60f3a5fe4b257aaau};
}

template<>
struct StaticInfo<ID{0xf95cd76397f6d714u, 0x32aff089eab9abb0u}> : StaticInfo_ConstPtrWrap<ID{0xf95cd76397f6d714u, 0x32aff089eab9abb0u}, ID{0x7c5094c82df7651au, 0x29ec00ba496465acu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const unsigned int *>() {
    return ID{0xf95cd76397f6d714u, 0x32aff089eab9abb0u};
}

/****************************** unsigned int END ******************************/


/****************************** long START ******************************/

template<>
struct StaticInfo<ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u}> : FundamentalStaticTypeInfo<long, ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u}, StringLiteral{"long"}, StringLiteral{"long"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<long>() {
    return ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u};
}

template<>
struct StaticInfo<ID{0x45b292eb3e32248u, 0x4061035c34091cbdu}> : StaticInfo_ConstWrap<ID{0x45b292eb3e32248u, 0x4061035c34091cbdu}, ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const long>() {
    return ID{0x45b292eb3e32248u, 0x4061035c34091cbdu};
}

template<>
struct StaticInfo<ID{0x2050fd06738b9aefu, 0xdd0fdec000047797u}> : StaticInfo_LRefWrap<ID{0x2050fd06738b9aefu, 0xdd0fdec000047797u}, ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<long &>() {
    return ID{0x2050fd06738b9aefu, 0xdd0fdec000047797u};
}

template<>
struct StaticInfo<ID{0x8e5e86db150c7761u, 0x35c5c1074a6441bau}> : StaticInfo_ConstLRefWrap<ID{0x8e5e86db150c7761u, 0x35c5c1074a6441bau}, ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const long &>() {
    return ID{0x8e5e86db150c7761u, 0x35c5c1074a6441bau};
}

template<>
struct StaticInfo<ID{0xdb50b6a07a30f971u, 0xb6522f7c3a00eebbu}> : StaticInfo_RRefWrap<ID{0xdb50b6a07a30f971u, 0xb6522f7c3a00eebbu}, ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<long &&>() {
    return ID{0xdb50b6a07a30f971u, 0xb6522f7c3a00eebbu};
}

template<>
struct StaticInfo<ID{0x6c55409fb89312b3u, 0x72ddff22b63322a4u}> : StaticInfo_PtrWrap<ID{0x6c55409fb89312b3u, 0x72ddff22b63322a4u}, ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<long *>() {
    return ID{0x6c55409fb89312b3u, 0x72ddff22b63322a4u};
}

template<>
struct StaticInfo<ID{0x8c5c57b1848f9670u, 0x500287317e6878au}> : StaticInfo_ConstPtrWrap<ID{0x8c5c57b1848f9670u, 0x500287317e6878au}, ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const long *>() {
    return ID{0x8c5c57b1848f9670u, 0x500287317e6878au};
}

/****************************** long END ******************************/


/****************************** unsigned long START ******************************/

template<>
struct StaticInfo<ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu}> : FundamentalStaticTypeInfo<unsigned long, ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu}, StringLiteral{"unsigned long"}, StringLiteral{"unsigned long"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned long>() {
    return ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu};
}

template<>
struct StaticInfo<ID{0x215e7c366e1d8c69u, 0x869a539e86ef749du}> : StaticInfo_ConstWrap<ID{0x215e7c366e1d8c69u, 0x869a539e86ef749du}, ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const unsigned long>() {
    return ID{0x215e7c366e1d8c69u, 0x869a539e86ef749du};
}

template<>
struct StaticInfo<ID{0x25505247b63a02bfu, 0x9499d2da091b359du}> : StaticInfo_LRefWrap<ID{0x25505247b63a02bfu, 0x9499d2da091b359du}, ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned long &>() {
    return ID{0x25505247b63a02bfu, 0x9499d2da091b359du};
}

template<>
struct StaticInfo<ID{0xdf5b03646560fb92u, 0xa5db8de193bc65a8u}> : StaticInfo_ConstLRefWrap<ID{0xdf5b03646560fb92u, 0xa5db8de193bc65a8u}, ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const unsigned long &>() {
    return ID{0xdf5b03646560fb92u, 0xa5db8de193bc65a8u};
}

template<>
struct StaticInfo<ID{0xb657b42f8d1dc548u, 0xd43915443809e693u}> : StaticInfo_RRefWrap<ID{0xb657b42f8d1dc548u, 0xd43915443809e693u}, ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned long &&>() {
    return ID{0xb657b42f8d1dc548u, 0xd43915443809e693u};
}

template<>
struct StaticInfo<ID{0xfb5af8941ba995a2u, 0x9282eec8f8f03ea7u}> : StaticInfo_PtrWrap<ID{0xfb5af8941ba995a2u, 0x9282eec8f8f03ea7u}, ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned long *>() {
    return ID{0xfb5af8941ba995a2u, 0x9282eec8f8f03ea7u};
}

template<>
struct StaticInfo<ID{0x94589d0256ef4a6cu, 0x33ec2d6612dbc388u}> : StaticInfo_ConstPtrWrap<ID{0x94589d0256ef4a6cu, 0x33ec2d6612dbc388u}, ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const unsigned long *>() {
    return ID{0x94589d0256ef4a6cu, 0x33ec2d6612dbc388u};
}

/****************************** unsigned long END ******************************/


/****************************** long long START ******************************/

template<>
struct StaticInfo<ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u}> : FundamentalStaticTypeInfo<long long, ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u}, StringLiteral{"long long"}, StringLiteral{"long long"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<long long>() {
    return ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u};
}

template<>
struct StaticInfo<ID{0xe650340d4d5732d5u, 0x1c0528dbc3bd0ca1u}> : StaticInfo_ConstWrap<ID{0xe650340d4d5732d5u, 0x1c0528dbc3bd0ca1u}, ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const long long>() {
    return ID{0xe650340d4d5732d5u, 0x1c0528dbc3bd0ca1u};
}

template<>
struct StaticInfo<ID{0xff55c23c33ab6a57u, 0xa86b012670a3e293u}> : StaticInfo_LRefWrap<ID{0xff55c23c33ab6a57u, 0xa86b012670a3e293u}, ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<long long &>() {
    return ID{0xff55c23c33ab6a57u, 0xa86b012670a3e293u};
}

template<>
struct StaticInfo<ID{0xf95ff0121fd5039fu, 0xfbe1a762c651b68fu}> : StaticInfo_ConstLRefWrap<ID{0xf95ff0121fd5039fu, 0xfbe1a762c651b68fu}, ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const long long &>() {
    return ID{0xf95ff0121fd5039fu, 0xfbe1a762c651b68fu};
}

template<>
struct StaticInfo<ID{0x785ab1b4f0367d8bu, 0x29c741f1d84b858eu}> : StaticInfo_RRefWrap<ID{0x785ab1b4f0367d8bu, 0x29c741f1d84b858eu}, ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<long long &&>() {
    return ID{0x785ab1b4f0367d8bu, 0x29c741f1d84b858eu};
}

template<>
struct StaticInfo<ID{0x7157d73abe28d24eu, 0xeca4e8420feaeaaau}> : StaticInfo_PtrWrap<ID{0x7157d73abe28d24eu, 0xeca4e8420feaeaaau}, ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<long long *>() {
    return ID{0x7157d73abe28d24eu, 0xeca4e8420feaeaaau};
}

template<>
struct StaticInfo<ID{0x46533e3353deb8bdu, 0x791330bc9ff4c598u}> : StaticInfo_ConstPtrWrap<ID{0x46533e3353deb8bdu, 0x791330bc9ff4c598u}, ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const long long *>() {
    return ID{0x46533e3353deb8bdu, 0x791330bc9ff4c598u};
}

/****************************** long long END ******************************/


/****************************** unsigned long long START ******************************/

template<>
struct StaticInfo<ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u}> : FundamentalStaticTypeInfo<unsigned long long, ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u}, StringLiteral{"unsigned long long"}, StringLiteral{"unsigned long long"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned long long>() {
    return ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u};
}

template<>
struct StaticInfo<ID{0x745d37dfa15ac458u, 0xef44eac5b825d188u}> : StaticInfo_ConstWrap<ID{0x745d37dfa15ac458u, 0xef44eac5b825d188u}, ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const unsigned long long>() {
    return ID{0x745d37dfa15ac458u, 0xef44eac5b825d188u};
}

template<>
struct StaticInfo<ID{0x22562bdc2632281cu, 0xa5e72eb2fa07d589u}> : StaticInfo_LRefWrap<ID{0x22562bdc2632281cu, 0xa5e72eb2fa07d589u}, ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned long long &>() {
    return ID{0x22562bdc2632281cu, 0xa5e72eb2fa07d589u};
}

template<>
struct StaticInfo<ID{0x65593ec8799c88e8u, 0xd4efe53ac499b0afu}> : StaticInfo_ConstLRefWrap<ID{0x65593ec8799c88e8u, 0xd4efe53ac499b0afu}, ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const unsigned long long &>() {
    return ID{0x65593ec8799c88e8u, 0xd4efe53ac499b0afu};
}

template<>
struct StaticInfo<ID{0xc356be02d188dfa8u, 0x1028a0b7987c68a2u}> : StaticInfo_RRefWrap<ID{0xc356be02d188dfa8u, 0x1028a0b7987c68a2u}, ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned long long &&>() {
    return ID{0xc356be02d188dfa8u, 0x1028a0b7987c68a2u};
}

template<>
struct StaticInfo<ID{0xbc5062a778eb09f8u, 0x985c0c72507cecbbu}> : StaticInfo_PtrWrap<ID{0xbc5062a778eb09f8u, 0x985c0c72507cecbbu}, ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<unsigned long long *>() {
    return ID{0xbc5062a778eb09f8u, 0x985c0c72507cecbbu};
}

template<>
struct StaticInfo<ID{0xba5bd61123d471efu, 0xdd3c0076f0afe89cu}> : StaticInfo_ConstPtrWrap<ID{0xba5bd61123d471efu, 0xdd3c0076f0afe89cu}, ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const unsigned long long *>() {
    return ID{0xba5bd61123d471efu, 0xdd3c0076f0afe89cu};
}

/****************************** unsigned long long END ******************************/


/****************************** float START ******************************/

template<>
struct StaticInfo<ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u}> : FundamentalStaticTypeInfo<float, ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u}, StringLiteral{"float"}, StringLiteral{"float"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<float>() {
    return ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u};
}

template<>
struct StaticInfo<ID{0x6c5181990dbe2580u, 0x79cf95a0b08f9099u}> : StaticInfo_ConstWrap<ID{0x6c5181990dbe2580u, 0x79cf95a0b08f9099u}, ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const float>() {
    return ID{0x6c5181990dbe2580u, 0x79cf95a0b08f9099u};
}

template<>
struct StaticInfo<ID{0xe4536bd9e01170f3u, 0xbc4c750314792bbfu}> : StaticInfo_LRefWrap<ID{0xe4536bd9e01170f3u, 0xbc4c750314792bbfu}, ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<float &>() {
    return ID{0xe4536bd9e01170f3u, 0xbc4c750314792bbfu};
}

template<>
struct StaticInfo<ID{0xc55a8014f6243f29u, 0xfd4249a582c2a99au}> : StaticInfo_ConstLRefWrap<ID{0xc55a8014f6243f29u, 0xfd4249a582c2a99au}, ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const float &>() {
    return ID{0xc55a8014f6243f29u, 0xfd4249a582c2a99au};
}

template<>
struct StaticInfo<ID{0x405ef9475d6fd08eu, 0x3d15cf51f33ae18fu}> : StaticInfo_RRefWrap<ID{0x405ef9475d6fd08eu, 0x3d15cf51f33ae18fu}, ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<float &&>() {
    return ID{0x405ef9475d6fd08eu, 0x3d15cf51f33ae18fu};
}

template<>
struct StaticInfo<ID{0xf8530e4b18d0e471u, 0x9514abf5dbb0c1a5u}> : StaticInfo_PtrWrap<ID{0xf8530e4b18d0e471u, 0x9514abf5dbb0c1a5u}, ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<float *>() {
    return ID{0xf8530e4b18d0e471u, 0x9514abf5dbb0c1a5u};
}

template<>
struct StaticInfo<ID{0xae5ba05a4ed06c15u, 0x43f99ca2303f929au}> : StaticInfo_ConstPtrWrap<ID{0xae5ba05a4ed06c15u, 0x43f99ca2303f929au}, ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const float *>() {
    return ID{0xae5ba05a4ed06c15u, 0x43f99ca2303f929au};
}

/****************************** float END ******************************/


/****************************** double START ******************************/

template<>
struct StaticInfo<ID{0x2250987dc79c7536u, 0x918fef864de1c190u}> : FundamentalStaticTypeInfo<double, ID{0x2250987dc79c7536u, 0x918fef864de1c190u}, StringLiteral{"double"}, StringLiteral{"double"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<double>() {
    return ID{0x2250987dc79c7536u, 0x918fef864de1c190u};
}

template<>
struct StaticInfo<ID{0x5c5f0d6c2ec65a42u, 0xdf948560f301c0a5u}> : StaticInfo_ConstWrap<ID{0x5c5f0d6c2ec65a42u, 0xdf948560f301c0a5u}, ID{0x2250987dc79c7536u, 0x918fef864de1c190u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const double>() {
    return ID{0x5c5f0d6c2ec65a42u, 0xdf948560f301c0a5u};
}

template<>
struct StaticInfo<ID{0x135c1109810d1dafu, 0x5b6e1fce8f58f9cu}> : StaticInfo_LRefWrap<ID{0x135c1109810d1dafu, 0x5b6e1fce8f58f9cu}, ID{0x2250987dc79c7536u, 0x918fef864de1c190u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<double &>() {
    return ID{0x135c1109810d1dafu, 0x5b6e1fce8f58f9cu};
}

template<>
struct StaticInfo<ID{0xd7528a84dbdc163au, 0xe7d6b68ec06b918du}> : StaticInfo_ConstLRefWrap<ID{0xd7528a84dbdc163au, 0xe7d6b68ec06b918du}, ID{0x2250987dc79c7536u, 0x918fef864de1c190u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const double &>() {
    return ID{0xd7528a84dbdc163au, 0xe7d6b68ec06b918du};
}

template<>
struct StaticInfo<ID{0x5c5818fdd9e2446fu, 0xfd22a82b628268b9u}> : StaticInfo_RRefWrap<ID{0x5c5818fdd9e2446fu, 0xfd22a82b628268b9u}, ID{0x2250987dc79c7536u, 0x918fef864de1c190u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<double &&>() {
    return ID{0x5c5818fdd9e2446fu, 0xfd22a82b628268b9u};
}

template<>
struct StaticInfo<ID{0xbc5029a3e550b0aau, 0x4710910c7bec06b0u}> : StaticInfo_PtrWrap<ID{0xbc5029a3e550b0aau, 0x4710910c7bec06b0u}, ID{0x2250987dc79c7536u, 0x918fef864de1c190u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<double *>() {
    return ID{0xbc5029a3e550b0aau, 0x4710910c7bec06b0u};
}

template<>
struct StaticInfo<ID{0xf05eb24587fa2944u, 0x35e8ba246b6a7f85u}> : StaticInfo_ConstPtrWrap<ID{0xf05eb24587fa2944u, 0x35e8ba246b6a7f85u}, ID{0x2250987dc79c7536u, 0x918fef864de1c190u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const double *>() {
    return ID{0xf05eb24587fa2944u, 0x35e8ba246b6a7f85u};
}

/****************************** double END ******************************/


/****************************** long double START ******************************/

template<>
struct StaticInfo<ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du}> : FundamentalStaticTypeInfo<long double, ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du}, StringLiteral{"long double"}, StringLiteral{"long double"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<long double>() {
    return ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du};
}

template<>
struct StaticInfo<ID{0x1f5ff0e360f679e3u, 0x3842c7bff674f99au}> : StaticInfo_ConstWrap<ID{0x1f5ff0e360f679e3u, 0x3842c7bff674f99au}, ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const long double>() {
    return ID{0x1f5ff0e360f679e3u, 0x3842c7bff674f99au};
}

template<>
struct StaticInfo<ID{0xba5bdec9aca9c424u, 0x23d15140bf4d5dacu}> : StaticInfo_LRefWrap<ID{0xba5bdec9aca9c424u, 0x23d15140bf4d5dacu}, ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du}> {};
template<>
[[nodiscard]] consteval ID getTypeId<long double &>() {
    return ID{0xba5bdec9aca9c424u, 0x23d15140bf4d5dacu};
}

template<>
struct StaticInfo<ID{0x6e56d4b3c13628f1u, 0x68a28ef42964f2acu}> : StaticInfo_ConstLRefWrap<ID{0x6e56d4b3c13628f1u, 0x68a28ef42964f2acu}, ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const long double &>() {
    return ID{0x6e56d4b3c13628f1u, 0x68a28ef42964f2acu};
}

template<>
struct StaticInfo<ID{0x165d2e5e0b2a11b3u, 0xe2931ab03295839bu}> : StaticInfo_RRefWrap<ID{0x165d2e5e0b2a11b3u, 0xe2931ab03295839bu}, ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du}> {};
template<>
[[nodiscard]] consteval ID getTypeId<long double &&>() {
    return ID{0x165d2e5e0b2a11b3u, 0xe2931ab03295839bu};
}

template<>
struct StaticInfo<ID{0xed5df6efefa37675u, 0x2fabfd6608cde83u}> : StaticInfo_PtrWrap<ID{0xed5df6efefa37675u, 0x2fabfd6608cde83u}, ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du}> {};
template<>
[[nodiscard]] consteval ID getTypeId<long double *>() {
    return ID{0xed5df6efefa37675u, 0x2fabfd6608cde83u};
}

template<>
struct StaticInfo<ID{0xc552c9ea3efa46bau, 0xf6e4e3352116f88du}> : StaticInfo_ConstPtrWrap<ID{0xc552c9ea3efa46bau, 0xf6e4e3352116f88du}, ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const long double *>() {
    return ID{0xc552c9ea3efa46bau, 0xf6e4e3352116f88du};
}

/****************************** long double END ******************************/


/****************************** void START ******************************/

template<>
struct StaticInfo<ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u}> : FundamentalStaticTypeInfo<void, ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u}, StringLiteral{"void"}, StringLiteral{"void"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<void>() {
    return ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u};
}

template<>
struct StaticInfo<ID{0x195508b79b43c28du, 0xffb0cb0c8279edbfu}> : StaticInfo_PtrWrap<ID{0x195508b79b43c28du, 0xffb0cb0c8279edbfu}, ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<void *>() {
    return ID{0x195508b79b43c28du, 0xffb0cb0c8279edbfu};
}

template<>
struct StaticInfo<ID{0x9d55c6d634271484u, 0x9770aebd47a836a8u}> : StaticInfo_ConstPtrWrap<ID{0x9d55c6d634271484u, 0x9770aebd47a836a8u}, ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const void *>() {
    return ID{0x9d55c6d634271484u, 0x9770aebd47a836a8u};
}

/****************************** void END ******************************/


/****************************** std::nullptr_t START ******************************/

template<>
struct StaticInfo<ID{0x38544f066c280c57u, 0xa81e153a29bca6a3u}> : FundamentalStaticTypeInfo<std::nullptr_t, ID{0x38544f066c280c57u, 0xa81e153a29bca6a3u}, StringLiteral{"nullptr_t"}, StringLiteral{"std::nullptr_t"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<std::nullptr_t>() {
    return ID{0x38544f066c280c57u, 0xa81e153a29bca6a3u};
}

/****************************** std::nullptr_t END ******************************/

}