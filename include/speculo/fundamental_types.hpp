#pragma once

#include <speculo/Attribute.hpp>
#include <speculo/Info.hpp>
#include <speculo/details/StaticInfo.hpp>
#include <speculo/details/StringLiteral.hpp>
#include <speculo/details/StaticInfo_Wrappers.hpp>
#include <speculo/details/array.hpp>

namespace speculo::details {

    template<typename T, ID TID, StringLiteral TypeName, StringLiteral FullTypeName = TypeName> requires(std::is_fundamental_v<T>)
    struct FundamentalStaticTypeInfo {
        using Type = T;
        constexpr static ID Id = TID;

        // FIXME: RangeOf msvc failure here
        constexpr static /*RangeOf<speculo::Attribute>*/ auto Attributes = speculo::make_array<speculo::Attribute>();


        constexpr static auto StaticInfoObjectType = StaticInfoType::FundamentalType;

        constexpr static bool IsLvalueReference = false;
        constexpr static bool IsRvalueReference = false;
        constexpr static bool IsConst = false;
        constexpr static bool IsPtr = false;
        constexpr static bool IsVolatile = false;
        constexpr static bool IsLiteral = true;
        constexpr static bool IsPOD = true;
        constexpr static bool IsStandardLayout = true;
        constexpr static bool IsTriviallyCopyable = true;
        constexpr static bool IsTrivial = true;
        constexpr static bool IsEmpty = false;
        constexpr static bool IsAggregate = false;

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

template<>
struct StaticInfo<ID{0x9e58772be1cefff7u, 0x5d43d5ea9527ee9cu}> : StaticInfo_VolatileConstWrap<ID{0x9e58772be1cefff7u, 0x5d43d5ea9527ee9cu}, ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const bool>() {
    return ID{0x9e58772be1cefff7u, 0x5d43d5ea9527ee9cu};
}

template<>
struct StaticInfo<ID{0x775a6b3eead29320u, 0x26b8d15575e1f18eu}> : StaticInfo_VolatileLRefWrap<ID{0x775a6b3eead29320u, 0x26b8d15575e1f18eu}, ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile bool &>() {
    return ID{0x775a6b3eead29320u, 0x26b8d15575e1f18eu};
}

template<>
struct StaticInfo<ID{0x4b5d72ad105b28abu, 0x322f18bd151e8090u}> : StaticInfo_VolatileConstLRefWrap<ID{0x4b5d72ad105b28abu, 0x322f18bd151e8090u}, ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const bool &>() {
    return ID{0x4b5d72ad105b28abu, 0x322f18bd151e8090u};
}

template<>
struct StaticInfo<ID{0xc95af03812060187u, 0x7f11a8d4efee1f9du}> : StaticInfo_VolatileRRefWrap<ID{0xc95af03812060187u, 0x7f11a8d4efee1f9du}, ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile bool &&>() {
    return ID{0xc95af03812060187u, 0x7f11a8d4efee1f9du};
}

template<>
struct StaticInfo<ID{0x20511465824d2f5eu, 0xe2ad2ee374f8f8bu}> : StaticInfo_VolatilePtrWrap<ID{0x20511465824d2f5eu, 0xe2ad2ee374f8f8bu}, ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile bool *>() {
    return ID{0x20511465824d2f5eu, 0xe2ad2ee374f8f8bu};
}

template<>
struct StaticInfo<ID{0x975af56d197d3d38u, 0xe7889761fdccd8adu}> : StaticInfo_VolatileConstPtrWrap<ID{0x975af56d197d3d38u, 0xe7889761fdccd8adu}, ID{0x5a570b30e217d281u, 0xd68971b95fd84e99u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const bool *>() {
    return ID{0x975af56d197d3d38u, 0xe7889761fdccd8adu};
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

template<>
struct StaticInfo<ID{0xeb55e64b42f1cde2u, 0x20cd2c60e49bde8au}> : StaticInfo_VolatileConstWrap<ID{0xeb55e64b42f1cde2u, 0x20cd2c60e49bde8au}, ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const char>() {
    return ID{0xeb55e64b42f1cde2u, 0x20cd2c60e49bde8au};
}

template<>
struct StaticInfo<ID{0x215d7123e3a55239u, 0x9123520b34162a0u}> : StaticInfo_VolatileLRefWrap<ID{0x215d7123e3a55239u, 0x9123520b34162a0u}, ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile char &>() {
    return ID{0x215d7123e3a55239u, 0x9123520b34162a0u};
}

template<>
struct StaticInfo<ID{0x1a5b8d0d8a4e1885u, 0x1c1ec866050752a3u}> : StaticInfo_VolatileConstLRefWrap<ID{0x1a5b8d0d8a4e1885u, 0x1c1ec866050752a3u}, ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const char &>() {
    return ID{0x1a5b8d0d8a4e1885u, 0x1c1ec866050752a3u};
}

template<>
struct StaticInfo<ID{0xf75b9f023b0ecd7du, 0x1659e2342da07489u}> : StaticInfo_VolatileRRefWrap<ID{0xf75b9f023b0ecd7du, 0x1659e2342da07489u}, ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile char &&>() {
    return ID{0xf75b9f023b0ecd7du, 0x1659e2342da07489u};
}

template<>
struct StaticInfo<ID{0x135986fed9d1a287u, 0xe1dc5fedb2f0108du}> : StaticInfo_VolatilePtrWrap<ID{0x135986fed9d1a287u, 0xe1dc5fedb2f0108du}, ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile char *>() {
    return ID{0x135986fed9d1a287u, 0xe1dc5fedb2f0108du};
}

template<>
struct StaticInfo<ID{0xe35cf2868dce8fe1u, 0x3ab21066f41fb895u}> : StaticInfo_VolatileConstPtrWrap<ID{0xe35cf2868dce8fe1u, 0x3ab21066f41fb895u}, ID{0x345df9e6c3d2d91eu, 0x9dedd3a74f8fd5a1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const char *>() {
    return ID{0xe35cf2868dce8fe1u, 0x3ab21066f41fb895u};
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

template<>
struct StaticInfo<ID{0x8d592bb36583daf5u, 0x67d63202682cc191u}> : StaticInfo_VolatileConstWrap<ID{0x8d592bb36583daf5u, 0x67d63202682cc191u}, ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const signed char>() {
    return ID{0x8d592bb36583daf5u, 0x67d63202682cc191u};
}

template<>
struct StaticInfo<ID{0xd55acc4d5c0f2ca0u, 0x4b0e79838e5d279au}> : StaticInfo_VolatileLRefWrap<ID{0xd55acc4d5c0f2ca0u, 0x4b0e79838e5d279au}, ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile signed char &>() {
    return ID{0xd55acc4d5c0f2ca0u, 0x4b0e79838e5d279au};
}

template<>
struct StaticInfo<ID{0x655732a10a16cddfu, 0x9cb0e0f95f2459au}> : StaticInfo_VolatileConstLRefWrap<ID{0x655732a10a16cddfu, 0x9cb0e0f95f2459au}, ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const signed char &>() {
    return ID{0x655732a10a16cddfu, 0x9cb0e0f95f2459au};
}

template<>
struct StaticInfo<ID{0x3a53b972b432509au, 0xae99ed8f6fb1ad9cu}> : StaticInfo_VolatileRRefWrap<ID{0x3a53b972b432509au, 0xae99ed8f6fb1ad9cu}, ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile signed char &&>() {
    return ID{0x3a53b972b432509au, 0xae99ed8f6fb1ad9cu};
}

template<>
struct StaticInfo<ID{0x9e5680e206658014u, 0x1fd291800c33a8bbu}> : StaticInfo_VolatilePtrWrap<ID{0x9e5680e206658014u, 0x1fd291800c33a8bbu}, ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile signed char *>() {
    return ID{0x9e5680e206658014u, 0x1fd291800c33a8bbu};
}

template<>
struct StaticInfo<ID{0xb55dc6f11c61f46u, 0x9ab5e48242bd89b0u}> : StaticInfo_VolatileConstPtrWrap<ID{0xb55dc6f11c61f46u, 0x9ab5e48242bd89b0u}, ID{0x1c5ece854198fec0u, 0xe8f24cb935bb89fu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const signed char *>() {
    return ID{0xb55dc6f11c61f46u, 0x9ab5e48242bd89b0u};
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

template<>
struct StaticInfo<ID{0xca5c765f88386c87u, 0xddd4281a4f899d8cu}> : StaticInfo_VolatileConstWrap<ID{0xca5c765f88386c87u, 0xddd4281a4f899d8cu}, ID{0x5f56c0b531733454u, 0x552996f604766e9au}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const unsigned char>() {
    return ID{0xca5c765f88386c87u, 0xddd4281a4f899d8cu};
}

template<>
struct StaticInfo<ID{0x87563bd643ee79b1u, 0x97f3f7f1e0069591u}> : StaticInfo_VolatileLRefWrap<ID{0x87563bd643ee79b1u, 0x97f3f7f1e0069591u}, ID{0x5f56c0b531733454u, 0x552996f604766e9au}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile unsigned char &>() {
    return ID{0x87563bd643ee79b1u, 0x97f3f7f1e0069591u};
}

template<>
struct StaticInfo<ID{0x7d5081d2787375b8u, 0x3cc235c13eff2c9cu}> : StaticInfo_VolatileConstLRefWrap<ID{0x7d5081d2787375b8u, 0x3cc235c13eff2c9cu}, ID{0x5f56c0b531733454u, 0x552996f604766e9au}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const unsigned char &>() {
    return ID{0x7d5081d2787375b8u, 0x3cc235c13eff2c9cu};
}

template<>
struct StaticInfo<ID{0xb50975a60b089a6u, 0x672fd77aec840aafu}> : StaticInfo_VolatileRRefWrap<ID{0xb50975a60b089a6u, 0x672fd77aec840aafu}, ID{0x5f56c0b531733454u, 0x552996f604766e9au}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile unsigned char &&>() {
    return ID{0xb50975a60b089a6u, 0x672fd77aec840aafu};
}

template<>
struct StaticInfo<ID{0x5953d6c278024cc2u, 0x27b9285afd4fcba0u}> : StaticInfo_VolatilePtrWrap<ID{0x5953d6c278024cc2u, 0x27b9285afd4fcba0u}, ID{0x5f56c0b531733454u, 0x552996f604766e9au}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile unsigned char *>() {
    return ID{0x5953d6c278024cc2u, 0x27b9285afd4fcba0u};
}

template<>
struct StaticInfo<ID{0x1558e8fac253fc93u, 0x7d3d59b59a662894u}> : StaticInfo_VolatileConstPtrWrap<ID{0x1558e8fac253fc93u, 0x7d3d59b59a662894u}, ID{0x5f56c0b531733454u, 0x552996f604766e9au}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const unsigned char *>() {
    return ID{0x1558e8fac253fc93u, 0x7d3d59b59a662894u};
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

template<>
struct StaticInfo<ID{0x455461d42336e616u, 0xe2e48b71856d3cb0u}> : StaticInfo_VolatileConstWrap<ID{0x455461d42336e616u, 0xe2e48b71856d3cb0u}, ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const char8_t>() {
    return ID{0x455461d42336e616u, 0xe2e48b71856d3cb0u};
}

template<>
struct StaticInfo<ID{0x4b57fee9ed979dbdu, 0x2ca3d274f9212586u}> : StaticInfo_VolatileLRefWrap<ID{0x4b57fee9ed979dbdu, 0x2ca3d274f9212586u}, ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile char8_t &>() {
    return ID{0x4b57fee9ed979dbdu, 0x2ca3d274f9212586u};
}

template<>
struct StaticInfo<ID{0xb95bcba7a91138e2u, 0xb2fb5d325e41a785u}> : StaticInfo_VolatileConstLRefWrap<ID{0xb95bcba7a91138e2u, 0xb2fb5d325e41a785u}, ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const char8_t &>() {
    return ID{0xb95bcba7a91138e2u, 0xb2fb5d325e41a785u};
}

template<>
struct StaticInfo<ID{0x775a4b4f79fad35du, 0x316481e20a0af696u}> : StaticInfo_VolatileRRefWrap<ID{0x775a4b4f79fad35du, 0x316481e20a0af696u}, ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile char8_t &&>() {
    return ID{0x775a4b4f79fad35du, 0x316481e20a0af696u};
}

template<>
struct StaticInfo<ID{0x8d5d82e7e9d7b33fu, 0x4cc085c481e78090u}> : StaticInfo_VolatilePtrWrap<ID{0x8d5d82e7e9d7b33fu, 0x4cc085c481e78090u}, ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile char8_t *>() {
    return ID{0x8d5d82e7e9d7b33fu, 0x4cc085c481e78090u};
}

template<>
struct StaticInfo<ID{0x705e56a1076bbeb4u, 0xf71379fae9f359bdu}> : StaticInfo_VolatileConstPtrWrap<ID{0x705e56a1076bbeb4u, 0xf71379fae9f359bdu}, ID{0x2a5366d825be6734u, 0x5f9d8d9790f1fe80u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const char8_t *>() {
    return ID{0x705e56a1076bbeb4u, 0xf71379fae9f359bdu};
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

template<>
struct StaticInfo<ID{0xe45da65c91b7369du, 0xa59310002f689e89u}> : StaticInfo_VolatileConstWrap<ID{0xe45da65c91b7369du, 0xa59310002f689e89u}, ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const char16_t>() {
    return ID{0xe45da65c91b7369du, 0xa59310002f689e89u};
}

template<>
struct StaticInfo<ID{0xcb5ed86256e43261u, 0xdb4ad9b304b72ea8u}> : StaticInfo_VolatileLRefWrap<ID{0xcb5ed86256e43261u, 0xdb4ad9b304b72ea8u}, ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile char16_t &>() {
    return ID{0xcb5ed86256e43261u, 0xdb4ad9b304b72ea8u};
}

template<>
struct StaticInfo<ID{0x5550828caac514e5u, 0x94e2d85829c245aeu}> : StaticInfo_VolatileConstLRefWrap<ID{0x5550828caac514e5u, 0x94e2d85829c245aeu}, ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const char16_t &>() {
    return ID{0x5550828caac514e5u, 0x94e2d85829c245aeu};
}

template<>
struct StaticInfo<ID{0x965eed26f4840853u, 0x604ec1a628021a87u}> : StaticInfo_VolatileRRefWrap<ID{0x965eed26f4840853u, 0x604ec1a628021a87u}, ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile char16_t &&>() {
    return ID{0x965eed26f4840853u, 0x604ec1a628021a87u};
}

template<>
struct StaticInfo<ID{0x92558fabe6472202u, 0xd116caa87c205b9eu}> : StaticInfo_VolatilePtrWrap<ID{0x92558fabe6472202u, 0xd116caa87c205b9eu}, ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile char16_t *>() {
    return ID{0x92558fabe6472202u, 0xd116caa87c205b9eu};
}

template<>
struct StaticInfo<ID{0x653eda2c9e3cf3cu, 0x6a57b4d06f7726b5u}> : StaticInfo_VolatileConstPtrWrap<ID{0x653eda2c9e3cf3cu, 0x6a57b4d06f7726b5u}, ID{0xfa58dad47aa85e76u, 0x373b3387706c3aacu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const char16_t *>() {
    return ID{0x653eda2c9e3cf3cu, 0x6a57b4d06f7726b5u};
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

template<>
struct StaticInfo<ID{0xdb5bca20ea507326u, 0x5de753897fe5eb8du}> : StaticInfo_VolatileConstWrap<ID{0xdb5bca20ea507326u, 0x5de753897fe5eb8du}, ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const char32_t>() {
    return ID{0xdb5bca20ea507326u, 0x5de753897fe5eb8du};
}

template<>
struct StaticInfo<ID{0x15c78e599454a21u, 0xded7ce3f6fa55c86u}> : StaticInfo_VolatileLRefWrap<ID{0x15c78e599454a21u, 0xded7ce3f6fa55c86u}, ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile char32_t &>() {
    return ID{0x15c78e599454a21u, 0xded7ce3f6fa55c86u};
}

template<>
struct StaticInfo<ID{0xb55531ade20ae1c3u, 0x36ef7e476439faa4u}> : StaticInfo_VolatileConstLRefWrap<ID{0xb55531ade20ae1c3u, 0x36ef7e476439faa4u}, ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const char32_t &>() {
    return ID{0xb55531ade20ae1c3u, 0x36ef7e476439faa4u};
}

template<>
struct StaticInfo<ID{0x5d54b364df42fd7au, 0x9eeee9536685bb0u}> : StaticInfo_VolatileRRefWrap<ID{0x5d54b364df42fd7au, 0x9eeee9536685bb0u}, ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile char32_t &&>() {
    return ID{0x5d54b364df42fd7au, 0x9eeee9536685bb0u};
}

template<>
struct StaticInfo<ID{0x905106877f7aa5f4u, 0xbd5b906c33149795u}> : StaticInfo_VolatilePtrWrap<ID{0x905106877f7aa5f4u, 0xbd5b906c33149795u}, ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile char32_t *>() {
    return ID{0x905106877f7aa5f4u, 0xbd5b906c33149795u};
}

template<>
struct StaticInfo<ID{0x405fc6e5742ec73du, 0xd55f63c0d82033b0u}> : StaticInfo_VolatileConstPtrWrap<ID{0x405fc6e5742ec73du, 0xd55f63c0d82033b0u}, ID{0xcd5a3d19e1cb47e2u, 0x7c85d800ee25e093u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const char32_t *>() {
    return ID{0x405fc6e5742ec73du, 0xd55f63c0d82033b0u};
}

/****************************** char32_t END ******************************/


/****************************** wchar_t START ******************************/

template<>
struct StaticInfo<ID{0x8b5425071561cc27u, 0xb1399715e98c2b95u}> : FundamentalStaticTypeInfo<wchar_t, ID{0x8b5425071561cc27u, 0xb1399715e98c2b95u}, StringLiteral{"wchar_t"}, StringLiteral{"wchar_t"}> {};
template<>
[[nodiscard]] consteval ID getTypeId<wchar_t>() {
    return ID{0x8b5425071561cc27u, 0xb1399715e98c2b95u};
}

template<>
struct StaticInfo<ID{0x735256227cbfcb86u, 0x56a67410438e3597u}> : StaticInfo_ConstWrap<ID{0x735256227cbfcb86u, 0x56a67410438e3597u}, ID{0x8b5425071561cc27u, 0xb1399715e98c2b95u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const wchar_t>() {
    return ID{0x735256227cbfcb86u, 0x56a67410438e3597u};
}

template<>
struct StaticInfo<ID{0x5758014a26a927d7u, 0x33180942e3bfdaa4u}> : StaticInfo_LRefWrap<ID{0x5758014a26a927d7u, 0x33180942e3bfdaa4u}, ID{0x8b5425071561cc27u, 0xb1399715e98c2b95u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<wchar_t &>() {
    return ID{0x5758014a26a927d7u, 0x33180942e3bfdaa4u};
}

template<>
struct StaticInfo<ID{0xa951f66ddf10efbeu, 0x7e538facec0e4eafu}> : StaticInfo_ConstLRefWrap<ID{0xa951f66ddf10efbeu, 0x7e538facec0e4eafu}, ID{0x8b5425071561cc27u, 0xb1399715e98c2b95u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const wchar_t &>() {
    return ID{0xa951f66ddf10efbeu, 0x7e538facec0e4eafu};
}

template<>
struct StaticInfo<ID{0x215efe46326691c6u, 0x2c9923efc15c54b8u}> : StaticInfo_RRefWrap<ID{0x215efe46326691c6u, 0x2c9923efc15c54b8u}, ID{0x8b5425071561cc27u, 0xb1399715e98c2b95u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<wchar_t &&>() {
    return ID{0x215efe46326691c6u, 0x2c9923efc15c54b8u};
}

template<>
struct StaticInfo<ID{0x105fb0681bbf3463u, 0x6d26c9a65c889d96u}> : StaticInfo_PtrWrap<ID{0x105fb0681bbf3463u, 0x6d26c9a65c889d96u}, ID{0x8b5425071561cc27u, 0xb1399715e98c2b95u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<wchar_t *>() {
    return ID{0x105fb0681bbf3463u, 0x6d26c9a65c889d96u};
}

template<>
struct StaticInfo<ID{0x95576c30f869c3dcu, 0x1cba1385cf7cf0a3u}> : StaticInfo_ConstPtrWrap<ID{0x95576c30f869c3dcu, 0x1cba1385cf7cf0a3u}, ID{0x8b5425071561cc27u, 0xb1399715e98c2b95u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<const wchar_t *>() {
    return ID{0x95576c30f869c3dcu, 0x1cba1385cf7cf0a3u};
}

template<>
struct StaticInfo<ID{0xb5403edb54ceecbu, 0x9a115ca0eb374cb7u}> : StaticInfo_VolatileConstWrap<ID{0xb5403edb54ceecbu, 0x9a115ca0eb374cb7u}, ID{0x8b5425071561cc27u, 0xb1399715e98c2b95u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const wchar_t>() {
    return ID{0xb5403edb54ceecbu, 0x9a115ca0eb374cb7u};
}

template<>
struct StaticInfo<ID{0x2352351787afababu, 0xdb5d05b53f14b5bdu}> : StaticInfo_VolatileLRefWrap<ID{0x2352351787afababu, 0xdb5d05b53f14b5bdu}, ID{0x8b5425071561cc27u, 0xb1399715e98c2b95u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile wchar_t &>() {
    return ID{0x2352351787afababu, 0xdb5d05b53f14b5bdu};
}

template<>
struct StaticInfo<ID{0x98506eb5f518291au, 0x6b4e84334ba577acu}> : StaticInfo_VolatileConstLRefWrap<ID{0x98506eb5f518291au, 0x6b4e84334ba577acu}, ID{0x8b5425071561cc27u, 0xb1399715e98c2b95u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const wchar_t &>() {
    return ID{0x98506eb5f518291au, 0x6b4e84334ba577acu};
}

template<>
struct StaticInfo<ID{0x145c73f01dca2af7u, 0xd566e453a9adfbbbu}> : StaticInfo_VolatileRRefWrap<ID{0x145c73f01dca2af7u, 0xd566e453a9adfbbbu}, ID{0x8b5425071561cc27u, 0xb1399715e98c2b95u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile wchar_t &&>() {
    return ID{0x145c73f01dca2af7u, 0xd566e453a9adfbbbu};
}

template<>
struct StaticInfo<ID{0xcb572a8038811b87u, 0xd9d22bc620c825a5u}> : StaticInfo_VolatilePtrWrap<ID{0xcb572a8038811b87u, 0xd9d22bc620c825a5u}, ID{0x8b5425071561cc27u, 0xb1399715e98c2b95u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile wchar_t *>() {
    return ID{0xcb572a8038811b87u, 0xd9d22bc620c825a5u};
}

template<>
struct StaticInfo<ID{0x355b562658bd4024u, 0xb0fcc55fc945f6b8u}> : StaticInfo_VolatileConstPtrWrap<ID{0x355b562658bd4024u, 0xb0fcc55fc945f6b8u}, ID{0x8b5425071561cc27u, 0xb1399715e98c2b95u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const wchar_t *>() {
    return ID{0x355b562658bd4024u, 0xb0fcc55fc945f6b8u};
}

/****************************** wchar_t END ******************************/


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

template<>
struct StaticInfo<ID{0xf15f69012dfb02c2u, 0x24dddb30abd435bfu}> : StaticInfo_VolatileConstWrap<ID{0xf15f69012dfb02c2u, 0x24dddb30abd435bfu}, ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const short>() {
    return ID{0xf15f69012dfb02c2u, 0x24dddb30abd435bfu};
}

template<>
struct StaticInfo<ID{0x1951bda14d5bd65bu, 0x256049079d0c5ea0u}> : StaticInfo_VolatileLRefWrap<ID{0x1951bda14d5bd65bu, 0x256049079d0c5ea0u}, ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile short &>() {
    return ID{0x1951bda14d5bd65bu, 0x256049079d0c5ea0u};
}

template<>
struct StaticInfo<ID{0x1858c6722860028fu, 0x1e0978937e577296u}> : StaticInfo_VolatileConstLRefWrap<ID{0x1858c6722860028fu, 0x1e0978937e577296u}, ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const short &>() {
    return ID{0x1858c6722860028fu, 0x1e0978937e577296u};
}

template<>
struct StaticInfo<ID{0x8a533c6bfec8040du, 0x7c675cbd56cbc6a4u}> : StaticInfo_VolatileRRefWrap<ID{0x8a533c6bfec8040du, 0x7c675cbd56cbc6a4u}, ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile short &&>() {
    return ID{0x8a533c6bfec8040du, 0x7c675cbd56cbc6a4u};
}

template<>
struct StaticInfo<ID{0x52561c5b3e4ba383u, 0x8d579bb7ecea349bu}> : StaticInfo_VolatilePtrWrap<ID{0x52561c5b3e4ba383u, 0x8d579bb7ecea349bu}, ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile short *>() {
    return ID{0x52561c5b3e4ba383u, 0x8d579bb7ecea349bu};
}

template<>
struct StaticInfo<ID{0x565bdcda1e0157ceu, 0x1a72531c9d7a5589u}> : StaticInfo_VolatileConstPtrWrap<ID{0x565bdcda1e0157ceu, 0x1a72531c9d7a5589u}, ID{0x251fd1d86adfe99u, 0xfc3def08bda6d181u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const short *>() {
    return ID{0x565bdcda1e0157ceu, 0x1a72531c9d7a5589u};
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

template<>
struct StaticInfo<ID{0x415e76ea5c7ccbf7u, 0xbf5078c301de17b5u}> : StaticInfo_VolatileConstWrap<ID{0x415e76ea5c7ccbf7u, 0xbf5078c301de17b5u}, ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const unsigned short>() {
    return ID{0x415e76ea5c7ccbf7u, 0xbf5078c301de17b5u};
}

template<>
struct StaticInfo<ID{0xd5507e44f0d79123u, 0x2e46c5d32f34ff85u}> : StaticInfo_VolatileLRefWrap<ID{0xd5507e44f0d79123u, 0x2e46c5d32f34ff85u}, ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile unsigned short &>() {
    return ID{0xd5507e44f0d79123u, 0x2e46c5d32f34ff85u};
}

template<>
struct StaticInfo<ID{0x9e5ac17c58663ed7u, 0xc740811667df08beu}> : StaticInfo_VolatileConstLRefWrap<ID{0x9e5ac17c58663ed7u, 0xc740811667df08beu}, ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const unsigned short &>() {
    return ID{0x9e5ac17c58663ed7u, 0xc740811667df08beu};
}

template<>
struct StaticInfo<ID{0x6a54747de5cbb1c1u, 0xe070f9a4d14f82a9u}> : StaticInfo_VolatileRRefWrap<ID{0x6a54747de5cbb1c1u, 0xe070f9a4d14f82a9u}, ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile unsigned short &&>() {
    return ID{0x6a54747de5cbb1c1u, 0xe070f9a4d14f82a9u};
}

template<>
struct StaticInfo<ID{0x635d99cdcd3b80ebu, 0x42baf656934d00bau}> : StaticInfo_VolatilePtrWrap<ID{0x635d99cdcd3b80ebu, 0x42baf656934d00bau}, ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile unsigned short *>() {
    return ID{0x635d99cdcd3b80ebu, 0x42baf656934d00bau};
}

template<>
struct StaticInfo<ID{0x4b5b2761ca762ebeu, 0xa6ebb23544486e97u}> : StaticInfo_VolatileConstPtrWrap<ID{0x4b5b2761ca762ebeu, 0xa6ebb23544486e97u}, ID{0x935b0d8640a8c1cau, 0x3a76325e0c3ca49bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const unsigned short *>() {
    return ID{0x4b5b2761ca762ebeu, 0xa6ebb23544486e97u};
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

template<>
struct StaticInfo<ID{0xc15c0d845445323cu, 0xcfa5a70417aea0a1u}> : StaticInfo_VolatileConstWrap<ID{0xc15c0d845445323cu, 0xcfa5a70417aea0a1u}, ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const int>() {
    return ID{0xc15c0d845445323cu, 0xcfa5a70417aea0a1u};
}

template<>
struct StaticInfo<ID{0x655483aeb6b08a2fu, 0x41a53ea752039fb3u}> : StaticInfo_VolatileLRefWrap<ID{0x655483aeb6b08a2fu, 0x41a53ea752039fb3u}, ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile int &>() {
    return ID{0x655483aeb6b08a2fu, 0x41a53ea752039fb3u};
}

template<>
struct StaticInfo<ID{0x7a53d502bd115d89u, 0xd62d4d5055f40b8u}> : StaticInfo_VolatileConstLRefWrap<ID{0x7a53d502bd115d89u, 0xd62d4d5055f40b8u}, ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const int &>() {
    return ID{0x7a53d502bd115d89u, 0xd62d4d5055f40b8u};
}

template<>
struct StaticInfo<ID{0x9c55280d90f7bff0u, 0x6dcbe0408c36919fu}> : StaticInfo_VolatileRRefWrap<ID{0x9c55280d90f7bff0u, 0x6dcbe0408c36919fu}, ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile int &&>() {
    return ID{0x9c55280d90f7bff0u, 0x6dcbe0408c36919fu};
}

template<>
struct StaticInfo<ID{0x3a54c1529db516eeu, 0x607349d0c9f11283u}> : StaticInfo_VolatilePtrWrap<ID{0x3a54c1529db516eeu, 0x607349d0c9f11283u}, ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile int *>() {
    return ID{0x3a54c1529db516eeu, 0x607349d0c9f11283u};
}

template<>
struct StaticInfo<ID{0x895d18a216b8de41u, 0x23ca510e80f7019du}> : StaticInfo_VolatileConstPtrWrap<ID{0x895d18a216b8de41u, 0x23ca510e80f7019du}, ID{0x6754bf6294b33eaau, 0xee27c164a5eec791u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const int *>() {
    return ID{0x895d18a216b8de41u, 0x23ca510e80f7019du};
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

template<>
struct StaticInfo<ID{0xab5bcb0f9b0a0d15u, 0x380ba7607bf1328eu}> : StaticInfo_VolatileConstWrap<ID{0xab5bcb0f9b0a0d15u, 0x380ba7607bf1328eu}, ID{0x7c5094c82df7651au, 0x29ec00ba496465acu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const unsigned int>() {
    return ID{0xab5bcb0f9b0a0d15u, 0x380ba7607bf1328eu};
}

template<>
struct StaticInfo<ID{0x5b56a4367740210du, 0x864f35a2c05fb695u}> : StaticInfo_VolatileLRefWrap<ID{0x5b56a4367740210du, 0x864f35a2c05fb695u}, ID{0x7c5094c82df7651au, 0x29ec00ba496465acu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile unsigned int &>() {
    return ID{0x5b56a4367740210du, 0x864f35a2c05fb695u};
}

template<>
struct StaticInfo<ID{0x9a5efeb78e732af3u, 0x6f2471d3ccc0dc8cu}> : StaticInfo_VolatileConstLRefWrap<ID{0x9a5efeb78e732af3u, 0x6f2471d3ccc0dc8cu}, ID{0x7c5094c82df7651au, 0x29ec00ba496465acu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const unsigned int &>() {
    return ID{0x9a5efeb78e732af3u, 0x6f2471d3ccc0dc8cu};
}

template<>
struct StaticInfo<ID{0x71579a3be1a1ded8u, 0x8238af9a37990994u}> : StaticInfo_VolatileRRefWrap<ID{0x71579a3be1a1ded8u, 0x8238af9a37990994u}, ID{0x7c5094c82df7651au, 0x29ec00ba496465acu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile unsigned int &&>() {
    return ID{0x71579a3be1a1ded8u, 0x8238af9a37990994u};
}

template<>
struct StaticInfo<ID{0xf5de21968f099c4u, 0xe86b9b95b6a5048bu}> : StaticInfo_VolatilePtrWrap<ID{0xf5de21968f099c4u, 0xe86b9b95b6a5048bu}, ID{0x7c5094c82df7651au, 0x29ec00ba496465acu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile unsigned int *>() {
    return ID{0xf5de21968f099c4u, 0xe86b9b95b6a5048bu};
}

template<>
struct StaticInfo<ID{0x32526205837196e1u, 0x53e62fc0f5efa686u}> : StaticInfo_VolatileConstPtrWrap<ID{0x32526205837196e1u, 0x53e62fc0f5efa686u}, ID{0x7c5094c82df7651au, 0x29ec00ba496465acu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const unsigned int *>() {
    return ID{0x32526205837196e1u, 0x53e62fc0f5efa686u};
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

template<>
struct StaticInfo<ID{0xa958147db773c5cbu, 0x6317765d3b4bd69au}> : StaticInfo_VolatileConstWrap<ID{0xa958147db773c5cbu, 0x6317765d3b4bd69au}, ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const long>() {
    return ID{0xa958147db773c5cbu, 0x6317765d3b4bd69au};
}

template<>
struct StaticInfo<ID{0x335382c07a411ad7u, 0x9414fc7878d6b0a7u}> : StaticInfo_VolatileLRefWrap<ID{0x335382c07a411ad7u, 0x9414fc7878d6b0a7u}, ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile long &>() {
    return ID{0x335382c07a411ad7u, 0x9414fc7878d6b0a7u};
}

template<>
struct StaticInfo<ID{0x6c57948d07deeefdu, 0xd98a702820b52b9bu}> : StaticInfo_VolatileConstLRefWrap<ID{0x6c57948d07deeefdu, 0xd98a702820b52b9bu}, ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const long &>() {
    return ID{0x6c57948d07deeefdu, 0xd98a702820b52b9bu};
}

template<>
struct StaticInfo<ID{0xcf597d5962bdc12bu, 0xcec7cc8525365e84u}> : StaticInfo_VolatileRRefWrap<ID{0xcf597d5962bdc12bu, 0xcec7cc8525365e84u}, ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile long &&>() {
    return ID{0xcf597d5962bdc12bu, 0xcec7cc8525365e84u};
}

template<>
struct StaticInfo<ID{0x85923f0b47ead96u, 0x1bbf50a10c9c979cu}> : StaticInfo_VolatilePtrWrap<ID{0x85923f0b47ead96u, 0x1bbf50a10c9c979cu}, ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile long *>() {
    return ID{0x85923f0b47ead96u, 0x1bbf50a10c9c979cu};
}

template<>
struct StaticInfo<ID{0x275e5120ff94ca52u, 0xfeb180391db60a8au}> : StaticInfo_VolatileConstPtrWrap<ID{0x275e5120ff94ca52u, 0xfeb180391db60a8au}, ID{0x195eba21bd9000b8u, 0xfa34afb486ed7da1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const long *>() {
    return ID{0x275e5120ff94ca52u, 0xfeb180391db60a8au};
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

template<>
struct StaticInfo<ID{0xe958a2ecf3f5fcfeu, 0xe3021f37f87a4a9fu}> : StaticInfo_VolatileConstWrap<ID{0xe958a2ecf3f5fcfeu, 0xe3021f37f87a4a9fu}, ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const unsigned long>() {
    return ID{0xe958a2ecf3f5fcfeu, 0xe3021f37f87a4a9fu};
}

template<>
struct StaticInfo<ID{0x852b9058201bb5au, 0xc982ced5c18e69abu}> : StaticInfo_VolatileLRefWrap<ID{0x852b9058201bb5au, 0xc982ced5c18e69abu}, ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile unsigned long &>() {
    return ID{0x852b9058201bb5au, 0xc982ced5c18e69abu};
}

template<>
struct StaticInfo<ID{0x74515f75a13d36e0u, 0x3ca3419f5950f99u}> : StaticInfo_VolatileConstLRefWrap<ID{0x74515f75a13d36e0u, 0x3ca3419f5950f99u}, ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const unsigned long &>() {
    return ID{0x74515f75a13d36e0u, 0x3ca3419f5950f99u};
}

template<>
struct StaticInfo<ID{0x4758c8d0d4c5f552u, 0xea3b0bd50ff67c9au}> : StaticInfo_VolatileRRefWrap<ID{0x4758c8d0d4c5f552u, 0xea3b0bd50ff67c9au}, ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile unsigned long &&>() {
    return ID{0x4758c8d0d4c5f552u, 0xea3b0bd50ff67c9au};
}

template<>
struct StaticInfo<ID{0x245f12baba9bf48bu, 0xc6ca14492b08c5bbu}> : StaticInfo_VolatilePtrWrap<ID{0x245f12baba9bf48bu, 0xc6ca14492b08c5bbu}, ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile unsigned long *>() {
    return ID{0x245f12baba9bf48bu, 0xc6ca14492b08c5bbu};
}

template<>
struct StaticInfo<ID{0x53530607e3815218u, 0x675d327a693ab0a3u}> : StaticInfo_VolatileConstPtrWrap<ID{0x53530607e3815218u, 0x675d327a693ab0a3u}, ID{0x445dbb8fa880cabbu, 0x58af47f69441c9bu}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const unsigned long *>() {
    return ID{0x53530607e3815218u, 0x675d327a693ab0a3u};
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

template<>
struct StaticInfo<ID{0x5c5aacf7792c8497u, 0x2414ad5a55f719b3u}> : StaticInfo_VolatileConstWrap<ID{0x5c5aacf7792c8497u, 0x2414ad5a55f719b3u}, ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const long long>() {
    return ID{0x5c5aacf7792c8497u, 0x2414ad5a55f719b3u};
}

template<>
struct StaticInfo<ID{0x4455bceef0a74761u, 0xa765d9174392c39eu}> : StaticInfo_VolatileLRefWrap<ID{0x4455bceef0a74761u, 0xa765d9174392c39eu}, ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile long long &>() {
    return ID{0x4455bceef0a74761u, 0xa765d9174392c39eu};
}

template<>
struct StaticInfo<ID{0xd655f0d8334e9619u, 0x407d38bcc2e516b2u}> : StaticInfo_VolatileConstLRefWrap<ID{0xd655f0d8334e9619u, 0x407d38bcc2e516b2u}, ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const long long &>() {
    return ID{0xd655f0d8334e9619u, 0x407d38bcc2e516b2u};
}

template<>
struct StaticInfo<ID{0xb850de29502d5b73u, 0xe64f209091ba98u}> : StaticInfo_VolatileRRefWrap<ID{0xb850de29502d5b73u, 0xe64f209091ba98u}, ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile long long &&>() {
    return ID{0xb850de29502d5b73u, 0xe64f209091ba98u};
}

template<>
struct StaticInfo<ID{0x9a5da7f35dbd6129u, 0xb7eb1910436bbca8u}> : StaticInfo_VolatilePtrWrap<ID{0x9a5da7f35dbd6129u, 0xb7eb1910436bbca8u}, ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile long long *>() {
    return ID{0x9a5da7f35dbd6129u, 0xb7eb1910436bbca8u};
}

template<>
struct StaticInfo<ID{0xe85273162270acd6u, 0x3145740a19b53e90u}> : StaticInfo_VolatileConstPtrWrap<ID{0xe85273162270acd6u, 0x3145740a19b53e90u}, ID{0x6c528b40bb068e4cu, 0x4613be33456420b1u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const long long *>() {
    return ID{0xe85273162270acd6u, 0x3145740a19b53e90u};
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

template<>
struct StaticInfo<ID{0x115a62ec8b36734cu, 0x8250120822783da9u}> : StaticInfo_VolatileConstWrap<ID{0x115a62ec8b36734cu, 0x8250120822783da9u}, ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const unsigned long long>() {
    return ID{0x115a62ec8b36734cu, 0x8250120822783da9u};
}

template<>
struct StaticInfo<ID{0x3255fdfa15b73ae8u, 0x2597da629f09d3a6u}> : StaticInfo_VolatileLRefWrap<ID{0x3255fdfa15b73ae8u, 0x2597da629f09d3a6u}, ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile unsigned long long &>() {
    return ID{0x3255fdfa15b73ae8u, 0x2597da629f09d3a6u};
}

template<>
struct StaticInfo<ID{0x635a5a97e34604cdu, 0x457e8d712237f781u}> : StaticInfo_VolatileConstLRefWrap<ID{0x635a5a97e34604cdu, 0x457e8d712237f781u}, ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const unsigned long long &>() {
    return ID{0x635a5a97e34604cdu, 0x457e8d712237f781u};
}

template<>
struct StaticInfo<ID{0xfc510a7c9aca0861u, 0x15c66740f93ff08bu}> : StaticInfo_VolatileRRefWrap<ID{0xfc510a7c9aca0861u, 0x15c66740f93ff08bu}, ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile unsigned long long &&>() {
    return ID{0xfc510a7c9aca0861u, 0x15c66740f93ff08bu};
}

template<>
struct StaticInfo<ID{0x565da88eac2221e9u, 0xc457cb697baa7081u}> : StaticInfo_VolatilePtrWrap<ID{0x565da88eac2221e9u, 0xc457cb697baa7081u}, ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile unsigned long long *>() {
    return ID{0x565da88eac2221e9u, 0xc457cb697baa7081u};
}

template<>
struct StaticInfo<ID{0x1753d6c5c2802c08u, 0x68eb1b4ff7b86187u}> : StaticInfo_VolatileConstPtrWrap<ID{0x1753d6c5c2802c08u, 0x68eb1b4ff7b86187u}, ID{0xfa5c08425b0a22c4u, 0xb47a3509db6ca1b2u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const unsigned long long *>() {
    return ID{0x1753d6c5c2802c08u, 0x68eb1b4ff7b86187u};
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

template<>
struct StaticInfo<ID{0x9b5ce11243d5164bu, 0x2d63026f54ffa38au}> : StaticInfo_VolatileConstWrap<ID{0x9b5ce11243d5164bu, 0x2d63026f54ffa38au}, ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const float>() {
    return ID{0x9b5ce11243d5164bu, 0x2d63026f54ffa38au};
}

template<>
struct StaticInfo<ID{0x6b50483645619090u, 0x1e26c22fa70988b3u}> : StaticInfo_VolatileLRefWrap<ID{0x6b50483645619090u, 0x1e26c22fa70988b3u}, ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile float &>() {
    return ID{0x6b50483645619090u, 0x1e26c22fa70988b3u};
}

template<>
struct StaticInfo<ID{0x5d5196b5d2b677e3u, 0x164fab7048738bb3u}> : StaticInfo_VolatileConstLRefWrap<ID{0x5d5196b5d2b677e3u, 0x164fab7048738bb3u}, ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const float &>() {
    return ID{0x5d5196b5d2b677e3u, 0x164fab7048738bb3u};
}

template<>
struct StaticInfo<ID{0x4a579a79a2c3c873u, 0xcc95293412357fb0u}> : StaticInfo_VolatileRRefWrap<ID{0x4a579a79a2c3c873u, 0xcc95293412357fb0u}, ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile float &&>() {
    return ID{0x4a579a79a2c3c873u, 0xcc95293412357fb0u};
}

template<>
struct StaticInfo<ID{0xef58971246b41edbu, 0xfb82d7753eeb09bbu}> : StaticInfo_VolatilePtrWrap<ID{0xef58971246b41edbu, 0xfb82d7753eeb09bbu}, ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile float *>() {
    return ID{0xef58971246b41edbu, 0xfb82d7753eeb09bbu};
}

template<>
struct StaticInfo<ID{0x25518cdf371d11e0u, 0x6756eb0861d8209au}> : StaticInfo_VolatileConstPtrWrap<ID{0x25518cdf371d11e0u, 0x6756eb0861d8209au}, ID{0x2a58833512c58737u, 0x9967d24b6cfbaba3u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const float *>() {
    return ID{0x25518cdf371d11e0u, 0x6756eb0861d8209au};
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

template<>
struct StaticInfo<ID{0xd858851f7325ab53u, 0x207a10d75481598du}> : StaticInfo_VolatileConstWrap<ID{0xd858851f7325ab53u, 0x207a10d75481598du}, ID{0x2250987dc79c7536u, 0x918fef864de1c190u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const double>() {
    return ID{0xd858851f7325ab53u, 0x207a10d75481598du};
}

template<>
struct StaticInfo<ID{0xd1511a35bb02760au, 0x8fd55aba9f09f4a7u}> : StaticInfo_VolatileLRefWrap<ID{0xd1511a35bb02760au, 0x8fd55aba9f09f4a7u}, ID{0x2250987dc79c7536u, 0x918fef864de1c190u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile double &>() {
    return ID{0xd1511a35bb02760au, 0x8fd55aba9f09f4a7u};
}

template<>
struct StaticInfo<ID{0xf508809f1350adcu, 0x660093b09cafu}> : StaticInfo_VolatileConstLRefWrap<ID{0xf508809f1350adcu, 0x660093b09cafu}, ID{0x2250987dc79c7536u, 0x918fef864de1c190u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const double &>() {
    return ID{0xf508809f1350adcu, 0x660093b09cafu};
}

template<>
struct StaticInfo<ID{0x5d5f12ac61b74f3bu, 0x76eb494856418d97u}> : StaticInfo_VolatileRRefWrap<ID{0x5d5f12ac61b74f3bu, 0x76eb494856418d97u}, ID{0x2250987dc79c7536u, 0x918fef864de1c190u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile double &&>() {
    return ID{0x5d5f12ac61b74f3bu, 0x76eb494856418d97u};
}

template<>
struct StaticInfo<ID{0x4f516519e7c76afeu, 0x5a7911bbb5d6a4b7u}> : StaticInfo_VolatilePtrWrap<ID{0x4f516519e7c76afeu, 0x5a7911bbb5d6a4b7u}, ID{0x2250987dc79c7536u, 0x918fef864de1c190u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile double *>() {
    return ID{0x4f516519e7c76afeu, 0x5a7911bbb5d6a4b7u};
}

template<>
struct StaticInfo<ID{0x8a5eee31e7e3b196u, 0xcb4905e99f2a68b2u}> : StaticInfo_VolatileConstPtrWrap<ID{0x8a5eee31e7e3b196u, 0xcb4905e99f2a68b2u}, ID{0x2250987dc79c7536u, 0x918fef864de1c190u}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const double *>() {
    return ID{0x8a5eee31e7e3b196u, 0xcb4905e99f2a68b2u};
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

template<>
struct StaticInfo<ID{0xcc5de25a569817a9u, 0x83b464b85946e6a0u}> : StaticInfo_VolatileConstWrap<ID{0xcc5de25a569817a9u, 0x83b464b85946e6a0u}, ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const long double>() {
    return ID{0xcc5de25a569817a9u, 0x83b464b85946e6a0u};
}

template<>
struct StaticInfo<ID{0x575797ea8ddf56cbu, 0x94cddd7dce786eadu}> : StaticInfo_VolatileLRefWrap<ID{0x575797ea8ddf56cbu, 0x94cddd7dce786eadu}, ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile long double &>() {
    return ID{0x575797ea8ddf56cbu, 0x94cddd7dce786eadu};
}

template<>
struct StaticInfo<ID{0x8f52cf86adcb44adu, 0x1c8fc285def0a9a0u}> : StaticInfo_VolatileConstLRefWrap<ID{0x8f52cf86adcb44adu, 0x1c8fc285def0a9a0u}, ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const long double &>() {
    return ID{0x8f52cf86adcb44adu, 0x1c8fc285def0a9a0u};
}

template<>
struct StaticInfo<ID{0xcd556740f994b11cu, 0x6834b9ee37a93dbfu}> : StaticInfo_VolatileRRefWrap<ID{0xcd556740f994b11cu, 0x6834b9ee37a93dbfu}, ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile long double &&>() {
    return ID{0xcd556740f994b11cu, 0x6834b9ee37a93dbfu};
}

template<>
struct StaticInfo<ID{0x2c54cc77017197f0u, 0x3b2491eac269fd9du}> : StaticInfo_VolatilePtrWrap<ID{0x2c54cc77017197f0u, 0x3b2491eac269fd9du}, ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile long double *>() {
    return ID{0x2c54cc77017197f0u, 0x3b2491eac269fd9du};
}

template<>
struct StaticInfo<ID{0x9f52b0bcac051936u, 0xe79d473bff5bfdb2u}> : StaticInfo_VolatileConstPtrWrap<ID{0x9f52b0bcac051936u, 0xe79d473bff5bfdb2u}, ID{0x1652ec5d2ecf538fu, 0x4f1f1410fe94a99du}> {};
template<>
[[nodiscard]] consteval ID getTypeId<volatile const long double *>() {
    return ID{0x9f52b0bcac051936u, 0xe79d473bff5bfdb2u};
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