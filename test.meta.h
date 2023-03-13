
#pragma once

#include "meta/common.h"
#include "test.h"
#include <pf_common/array.h>
#include <pf_common/concepts/ranges.h>
#include <type_traits>

/****************************** pf::SomeEnum::Value1 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x36cb3097b3280304u, 0xe884d5516371da24u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x36cb3097b3280304u, 0xe884d5516371da24u};
    constexpr static ID TypeID = ::pf::meta::ID{0x7d1cf9b56ad5a46fu, 0x6b2905c430ca8c41u};
    using Type = pf::SomeEnum;

    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(
            pf::meta::Attribute{"test", {}}, pf::meta::Attribute{"test2", {}}, pf::meta::Attribute{"test3", {}});

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"Value1"};
    constexpr static auto FullName = StringLiteral{"pf::SomeEnum::Value1"};

    constexpr static bool UnderlyingValue = false;
    constexpr static pf::SomeEnum Value = pf::SomeEnum::Value1;
};
/****************************** pf::SomeEnum::Value1 END ******************************/

/****************************** pf::SomeEnum::Value2 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x258b073a3009a12du, 0xed361ced438aaf0u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x258b073a3009a12du, 0xed361ced438aaf0u};
    constexpr static ID TypeID = ::pf::meta::ID{0x7d1cf9b56ad5a46fu, 0x6b2905c430ca8c41u};
    using Type = pf::SomeEnum;

    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"Value2"};
    constexpr static auto FullName = StringLiteral{"pf::SomeEnum::Value2"};

    constexpr static bool UnderlyingValue = true;
    constexpr static pf::SomeEnum Value = pf::SomeEnum::Value2;
};
/****************************** pf::SomeEnum::Value2 END ******************************/

/****************************** pf::SomeEnum START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7d1cf9b56ad5a46fu, 0x6b2905c430ca8c41u}> {
    using Type = pf::SomeEnum;
    constexpr static ID TypeID = ::pf::meta::ID{0x7d1cf9b56ad5a46fu, 0x6b2905c430ca8c41u};

    constexpr static std::uint64_t SourceLine = 5;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>(
            pf::meta::Attribute{"pf::operators",
                                {R"(()()()((())))", R"([[nodiscard]])", R"(1ll)", R"(1.011)", R"([]{}())", R"("yeet")", R"('a')",
                                 R"([][][]:::3214234...[][][][])"}},
            pf::meta::Attribute{"pf::hihi", {}}, pf::meta::Attribute{"pf::operators2", {R"(1ll)", R"(1.011)", R"("yeet")"}},
            pf::meta::Attribute{"pf::hihi2", {}});

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = ::pf::StringLiteral{"SomeEnum"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::SomeEnum"};

    using UnderlyingType = bool;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
            ::pf::meta::ID{0x36cb3097b3280304u, 0xe884d5516371da24u}, ::pf::meta::ID{0x258b073a3009a12du, 0xed361ced438aaf0u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x117eb9f38bf640eeu, 0xcf31fc88a54659a2u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x117eb9f38bf640eeu, 0xcf31fc88a54659a2u},
                                                ::pf::meta::ID{0x7d1cf9b56ad5a46fu, 0x6b2905c430ca8c41u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x91a59854cf55295bu, 0x40119414997cadadu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x91a59854cf55295bu, 0x40119414997cadadu},
                                               ::pf::meta::ID{0x7d1cf9b56ad5a46fu, 0x6b2905c430ca8c41u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x16998d89cc627cd6u, 0xc36da5fc4ee4baebu}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x16998d89cc627cd6u, 0xc36da5fc4ee4baebu},
                                               ::pf::meta::ID{0x7d1cf9b56ad5a46fu, 0x6b2905c430ca8c41u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa804d5a1c7b6534du, 0xcde072cc71eeb7f0u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xa804d5a1c7b6534du, 0xcde072cc71eeb7f0u},
                                               ::pf::meta::ID{0x117eb9f38bf640eeu, 0xcf31fc88a54659a2u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1674e16848dbdc6au, 0xe193630e577a58eeu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x1674e16848dbdc6au, 0xe193630e577a58eeu},
                                              ::pf::meta::ID{0x7d1cf9b56ad5a46fu, 0x6b2905c430ca8c41u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x5290b4ceca87e1a8u, 0x467f8bab5137a137u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x5290b4ceca87e1a8u, 0x467f8bab5137a137u},
                                              ::pf::meta::ID{0x117eb9f38bf640eeu, 0xcf31fc88a54659a2u}> {};

/****************************** pf::SomeEnum END ******************************/
namespace pf::meta::details {
    /****************************** pf::SomeEnum START ******************************/
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::SomeEnum>() {
        return ::pf::meta::ID{0x7d1cf9b56ad5a46fu, 0x6b2905c430ca8c41u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum>() {
        return ::pf::meta::ID{0x117eb9f38bf640eeu, 0xcf31fc88a54659a2u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::SomeEnum &>() {
        return ::pf::meta::ID{0x91a59854cf55295bu, 0x40119414997cadadu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::SomeEnum &&>() {
        return ::pf::meta::ID{0x16998d89cc627cd6u, 0xc36da5fc4ee4baebu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum &>() {
        return ::pf::meta::ID{0xa804d5a1c7b6534du, 0xcde072cc71eeb7f0u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::SomeEnum *>() {
        return ::pf::meta::ID{0x1674e16848dbdc6au, 0xe193630e577a58eeu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::SomeEnum *>() {
        return ::pf::meta::ID{0x5290b4ceca87e1a8u, 0x467f8bab5137a137u};
    }
    /****************************** pf::SomeEnum END ******************************/

    /****************************** pf::SomeEnum::pf::SomeEnum::Value1 START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value1>() {
        return ::pf::meta::ID{0x36cb3097b3280304u, 0xe884d5516371da24u};
    }
    /****************************** pf::SomeEnum::pf::SomeEnum::Value1 END ******************************/

    /****************************** pf::SomeEnum::pf::SomeEnum::Value2 START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::SomeEnum::Value2>() {
        return ::pf::meta::ID{0x258b073a3009a12du, 0xed361ced438aaf0u};
    }
    /****************************** pf::SomeEnum::pf::SomeEnum::Value2 END ******************************/
}// namespace pf::meta::details
/****************************** pf::Test::E::Value1 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf44ac91bde5d8b1bu, 0xfb6e5822918583b1u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xf44ac91bde5d8b1bu, 0xfb6e5822918583b1u};
    constexpr static ID TypeID = ::pf::meta::ID{0x48419974fe88c03eu, 0xd96eb4e4d70efa40u};
    using Type = pf::Test::E;

    constexpr static std::uint64_t SourceLine = 8;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"Value1"};
    constexpr static auto FullName = StringLiteral{"pf::Test::E::Value1"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::Test::E Value = pf::Test::E::Value1;
};
/****************************** pf::Test::E::Value1 END ******************************/

/****************************** pf::Test::E::Value2 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3ab8fca15737de99u, 0xb3d8be03046389dbu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x3ab8fca15737de99u, 0xb3d8be03046389dbu};
    constexpr static ID TypeID = ::pf::meta::ID{0x48419974fe88c03eu, 0xd96eb4e4d70efa40u};
    using Type = pf::Test::E;

    constexpr static std::uint64_t SourceLine = 8;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"Value2"};
    constexpr static auto FullName = StringLiteral{"pf::Test::E::Value2"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::Test::E Value = pf::Test::E::Value2;
};
/****************************** pf::Test::E::Value2 END ******************************/

/****************************** pf::Test::E START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x48419974fe88c03eu, 0xd96eb4e4d70efa40u}> {
    using Type = pf::Test::E;
    constexpr static ID TypeID = ::pf::meta::ID{0x48419974fe88c03eu, 0xd96eb4e4d70efa40u};

    constexpr static std::uint64_t SourceLine = 8;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = ::pf::StringLiteral{"E"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::Test::E"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
            ::pf::meta::ID{0xf44ac91bde5d8b1bu, 0xfb6e5822918583b1u}, ::pf::meta::ID{0x3ab8fca15737de99u, 0xb3d8be03046389dbu});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x23afb856d8cda768u, 0xe9d092f2da911d26u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x23afb856d8cda768u, 0xe9d092f2da911d26u},
                                                ::pf::meta::ID{0x48419974fe88c03eu, 0xd96eb4e4d70efa40u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xee438215e2ed1475u, 0x2d08f84594e58af7u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xee438215e2ed1475u, 0x2d08f84594e58af7u},
                                               ::pf::meta::ID{0x48419974fe88c03eu, 0xd96eb4e4d70efa40u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xcd95a0118ba97dcdu, 0xbfe03204a0fe3425u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xcd95a0118ba97dcdu, 0xbfe03204a0fe3425u},
                                               ::pf::meta::ID{0x48419974fe88c03eu, 0xd96eb4e4d70efa40u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9848af528e4ef257u, 0x3942780f6bec2c92u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x9848af528e4ef257u, 0x3942780f6bec2c92u},
                                               ::pf::meta::ID{0x23afb856d8cda768u, 0xe9d092f2da911d26u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x86971cc68a5f143bu, 0xe11454dd13893d42u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x86971cc68a5f143bu, 0xe11454dd13893d42u},
                                              ::pf::meta::ID{0x48419974fe88c03eu, 0xd96eb4e4d70efa40u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc7d3833673e3c6c2u, 0x425b778d3dce4244u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xc7d3833673e3c6c2u, 0x425b778d3dce4244u},
                                              ::pf::meta::ID{0x23afb856d8cda768u, 0xe9d092f2da911d26u}> {};

/****************************** pf::Test::E END ******************************/
namespace pf::meta::details {
    /****************************** pf::Test::E START ******************************/
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::Test::E>() {
        return ::pf::meta::ID{0x48419974fe88c03eu, 0xd96eb4e4d70efa40u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::Test::E>() {
        return ::pf::meta::ID{0x23afb856d8cda768u, 0xe9d092f2da911d26u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::Test::E &>() {
        return ::pf::meta::ID{0xee438215e2ed1475u, 0x2d08f84594e58af7u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::Test::E &&>() {
        return ::pf::meta::ID{0xcd95a0118ba97dcdu, 0xbfe03204a0fe3425u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::Test::E &>() {
        return ::pf::meta::ID{0x9848af528e4ef257u, 0x3942780f6bec2c92u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::Test::E *>() {
        return ::pf::meta::ID{0x86971cc68a5f143bu, 0xe11454dd13893d42u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::Test::E *>() {
        return ::pf::meta::ID{0xc7d3833673e3c6c2u, 0x425b778d3dce4244u};
    }
    /****************************** pf::Test::E END ******************************/

    /****************************** pf::Test::E::pf::Test::E::Value1 START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::Test::E::Value1>() {
        return ::pf::meta::ID{0xf44ac91bde5d8b1bu, 0xfb6e5822918583b1u};
    }
    /****************************** pf::Test::E::pf::Test::E::Value1 END ******************************/

    /****************************** pf::Test::E::pf::Test::E::Value2 START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::Test::E::Value2>() {
        return ::pf::meta::ID{0x3ab8fca15737de99u, 0xb3d8be03046389dbu};
    }
    /****************************** pf::Test::E::pf::Test::E::Value2 END ******************************/
}// namespace pf::meta::details
/****************************** pf::EmptyEnum START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdd60513ffc532ea4u, 0x4d527ac2a1a24de2u}> {
    using Type = pf::EmptyEnum;
    constexpr static ID TypeID = ::pf::meta::ID{0xdd60513ffc532ea4u, 0x4d527ac2a1a24de2u};

    constexpr static std::uint64_t SourceLine = 19;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = ::pf::StringLiteral{"EmptyEnum"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::EmptyEnum"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>();
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8fbbdff0480f7534u, 0x477268e054af3dabu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x8fbbdff0480f7534u, 0x477268e054af3dabu},
                                                ::pf::meta::ID{0xdd60513ffc532ea4u, 0x4d527ac2a1a24de2u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf2268feda036f086u, 0xdf0c0e755a2d8db9u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xf2268feda036f086u, 0xdf0c0e755a2d8db9u},
                                               ::pf::meta::ID{0xdd60513ffc532ea4u, 0x4d527ac2a1a24de2u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x5ddd621e65598141u, 0x7671b59a08314673u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x5ddd621e65598141u, 0x7671b59a08314673u},
                                               ::pf::meta::ID{0xdd60513ffc532ea4u, 0x4d527ac2a1a24de2u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf26a64d8ae19ed84u, 0xd9e1ec45e5307fc6u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xf26a64d8ae19ed84u, 0xd9e1ec45e5307fc6u},
                                               ::pf::meta::ID{0x8fbbdff0480f7534u, 0x477268e054af3dabu}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa2fe9bad31a58c4eu, 0xf2957f4a4148e6fdu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xa2fe9bad31a58c4eu, 0xf2957f4a4148e6fdu},
                                              ::pf::meta::ID{0xdd60513ffc532ea4u, 0x4d527ac2a1a24de2u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x471713b581e4b614u, 0xdc609bbf6fc68d18u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x471713b581e4b614u, 0xdc609bbf6fc68d18u},
                                              ::pf::meta::ID{0x8fbbdff0480f7534u, 0x477268e054af3dabu}> {};

/****************************** pf::EmptyEnum END ******************************/
namespace pf::meta::details {
    /****************************** pf::EmptyEnum START ******************************/
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::EmptyEnum>() {
        return ::pf::meta::ID{0xdd60513ffc532ea4u, 0x4d527ac2a1a24de2u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum>() {
        return ::pf::meta::ID{0x8fbbdff0480f7534u, 0x477268e054af3dabu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &>() {
        return ::pf::meta::ID{0xf2268feda036f086u, 0xdf0c0e755a2d8db9u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::EmptyEnum &&>() {
        return ::pf::meta::ID{0x5ddd621e65598141u, 0x7671b59a08314673u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum &>() {
        return ::pf::meta::ID{0xf26a64d8ae19ed84u, 0xd9e1ec45e5307fc6u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::EmptyEnum *>() {
        return ::pf::meta::ID{0xa2fe9bad31a58c4eu, 0xf2957f4a4148e6fdu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::EmptyEnum *>() {
        return ::pf::meta::ID{0x471713b581e4b614u, 0xdc609bbf6fc68d18u};
    }
    /****************************** pf::EmptyEnum END ******************************/
}// namespace pf::meta::details
/****************************** pf::E1::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xcd66eba065f51ba6u, 0x9dcdcc7c12eeaaa4u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xcd66eba065f51ba6u, 0x9dcdcc7c12eeaaa4u};
    constexpr static ID TypeID = ::pf::meta::ID{0x5f0b5799daa9dde5u, 0xbf0ec7b396a3b56fu};
    using Type = pf::E1;

    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E1::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E1 Value = pf::E1::A;
};
/****************************** pf::E1::A END ******************************/

/****************************** pf::E1::B START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc98d366fe270c77du, 0xe87d12be5e89a93du}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xc98d366fe270c77du, 0xe87d12be5e89a93du};
    constexpr static ID TypeID = ::pf::meta::ID{0x5f0b5799daa9dde5u, 0xbf0ec7b396a3b56fu};
    using Type = pf::E1;

    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E1::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E1 Value = pf::E1::B;
};
/****************************** pf::E1::B END ******************************/

/****************************** pf::E1::C START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x5ae3a30462fd206au, 0xd31724b0086c8637u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x5ae3a30462fd206au, 0xd31724b0086c8637u};
    constexpr static ID TypeID = ::pf::meta::ID{0x5f0b5799daa9dde5u, 0xbf0ec7b396a3b56fu};
    using Type = pf::E1;

    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E1::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E1 Value = pf::E1::C;
};
/****************************** pf::E1::C END ******************************/

/****************************** pf::E1::D START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4c00b5ac572fb552u, 0x35f204f946491806u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x4c00b5ac572fb552u, 0x35f204f946491806u};
    constexpr static ID TypeID = ::pf::meta::ID{0x5f0b5799daa9dde5u, 0xbf0ec7b396a3b56fu};
    using Type = pf::E1;

    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E1::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E1 Value = pf::E1::D;
};
/****************************** pf::E1::D END ******************************/

/****************************** pf::E1::E START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xcee1f9b294074df9u, 0x1a4a3c1d9c6e64u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xcee1f9b294074df9u, 0x1a4a3c1d9c6e64u};
    constexpr static ID TypeID = ::pf::meta::ID{0x5f0b5799daa9dde5u, 0xbf0ec7b396a3b56fu};
    using Type = pf::E1;

    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E1::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E1 Value = pf::E1::E;
};
/****************************** pf::E1::E END ******************************/

/****************************** pf::E1 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x5f0b5799daa9dde5u, 0xbf0ec7b396a3b56fu}> {
    using Type = pf::E1;
    constexpr static ID TypeID = ::pf::meta::ID{0x5f0b5799daa9dde5u, 0xbf0ec7b396a3b56fu};

    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = ::pf::StringLiteral{"E1"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E1"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
            ::pf::meta::ID{0xcd66eba065f51ba6u, 0x9dcdcc7c12eeaaa4u}, ::pf::meta::ID{0xc98d366fe270c77du, 0xe87d12be5e89a93du},
            ::pf::meta::ID{0x5ae3a30462fd206au, 0xd31724b0086c8637u}, ::pf::meta::ID{0x4c00b5ac572fb552u, 0x35f204f946491806u},
            ::pf::meta::ID{0xcee1f9b294074df9u, 0x1a4a3c1d9c6e64u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6e2e38c6fdcf71f5u, 0x5ae505cb9879c163u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x6e2e38c6fdcf71f5u, 0x5ae505cb9879c163u},
                                                ::pf::meta::ID{0x5f0b5799daa9dde5u, 0xbf0ec7b396a3b56fu}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc2eb82a2246c83e5u, 0x4f48051f2f122a77u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xc2eb82a2246c83e5u, 0x4f48051f2f122a77u},
                                               ::pf::meta::ID{0x5f0b5799daa9dde5u, 0xbf0ec7b396a3b56fu}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3a854f8e1aeea6e6u, 0x66268ea714d1df5du}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x3a854f8e1aeea6e6u, 0x66268ea714d1df5du},
                                               ::pf::meta::ID{0x5f0b5799daa9dde5u, 0xbf0ec7b396a3b56fu}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2cfd9459adc48f7du, 0xab31246b610ff2b3u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x2cfd9459adc48f7du, 0xab31246b610ff2b3u},
                                               ::pf::meta::ID{0x6e2e38c6fdcf71f5u, 0x5ae505cb9879c163u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xacf1e34c7d2c9b5du, 0x4c973357128f956bu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xacf1e34c7d2c9b5du, 0x4c973357128f956bu},
                                              ::pf::meta::ID{0x5f0b5799daa9dde5u, 0xbf0ec7b396a3b56fu}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xeff3d77525485055u, 0x6430ba298f39d9b7u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xeff3d77525485055u, 0x6430ba298f39d9b7u},
                                              ::pf::meta::ID{0x6e2e38c6fdcf71f5u, 0x5ae505cb9879c163u}> {};

/****************************** pf::E1 END ******************************/
namespace pf::meta::details {
    /****************************** pf::E1 START ******************************/
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E1>() {
        return ::pf::meta::ID{0x5f0b5799daa9dde5u, 0xbf0ec7b396a3b56fu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E1>() {
        return ::pf::meta::ID{0x6e2e38c6fdcf71f5u, 0x5ae505cb9879c163u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E1 &>() {
        return ::pf::meta::ID{0xc2eb82a2246c83e5u, 0x4f48051f2f122a77u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E1 &&>() {
        return ::pf::meta::ID{0x3a854f8e1aeea6e6u, 0x66268ea714d1df5du};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E1 &>() {
        return ::pf::meta::ID{0x2cfd9459adc48f7du, 0xab31246b610ff2b3u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E1 *>() {
        return ::pf::meta::ID{0xacf1e34c7d2c9b5du, 0x4c973357128f956bu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E1 *>() {
        return ::pf::meta::ID{0xeff3d77525485055u, 0x6430ba298f39d9b7u};
    }
    /****************************** pf::E1 END ******************************/

    /****************************** pf::E1::pf::E1::A START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E1::A>() {
        return ::pf::meta::ID{0xcd66eba065f51ba6u, 0x9dcdcc7c12eeaaa4u};
    }
    /****************************** pf::E1::pf::E1::A END ******************************/

    /****************************** pf::E1::pf::E1::B START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E1::B>() {
        return ::pf::meta::ID{0xc98d366fe270c77du, 0xe87d12be5e89a93du};
    }
    /****************************** pf::E1::pf::E1::B END ******************************/

    /****************************** pf::E1::pf::E1::C START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E1::C>() {
        return ::pf::meta::ID{0x5ae3a30462fd206au, 0xd31724b0086c8637u};
    }
    /****************************** pf::E1::pf::E1::C END ******************************/

    /****************************** pf::E1::pf::E1::D START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E1::D>() {
        return ::pf::meta::ID{0x4c00b5ac572fb552u, 0x35f204f946491806u};
    }
    /****************************** pf::E1::pf::E1::D END ******************************/

    /****************************** pf::E1::pf::E1::E START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E1::E>() {
        return ::pf::meta::ID{0xcee1f9b294074df9u, 0x1a4a3c1d9c6e64u};
    }
    /****************************** pf::E1::pf::E1::E END ******************************/
}// namespace pf::meta::details
/****************************** pf::E2::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x60a07f1198e2d161u, 0x37c3f11239335156u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x60a07f1198e2d161u, 0x37c3f11239335156u};
    constexpr static ID TypeID = ::pf::meta::ID{0x4569c634cac2afdau, 0x40a907554c722702u};
    using Type = pf::E2;

    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E2::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E2 Value = pf::E2::A;
};
/****************************** pf::E2::A END ******************************/

/****************************** pf::E2::B START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x5386801a7d705ca9u, 0x6d398279349f7edcu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x5386801a7d705ca9u, 0x6d398279349f7edcu};
    constexpr static ID TypeID = ::pf::meta::ID{0x4569c634cac2afdau, 0x40a907554c722702u};
    using Type = pf::E2;

    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E2::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E2 Value = pf::E2::B;
};
/****************************** pf::E2::B END ******************************/

/****************************** pf::E2::C START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x194bf4c4b8d15fc3u, 0x4a27d288ede171cdu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x194bf4c4b8d15fc3u, 0x4a27d288ede171cdu};
    constexpr static ID TypeID = ::pf::meta::ID{0x4569c634cac2afdau, 0x40a907554c722702u};
    using Type = pf::E2;

    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E2::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E2 Value = pf::E2::C;
};
/****************************** pf::E2::C END ******************************/

/****************************** pf::E2::D START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd0ea8e8f24430b70u, 0x8f807fffd1ffd723u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xd0ea8e8f24430b70u, 0x8f807fffd1ffd723u};
    constexpr static ID TypeID = ::pf::meta::ID{0x4569c634cac2afdau, 0x40a907554c722702u};
    using Type = pf::E2;

    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E2::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E2 Value = pf::E2::D;
};
/****************************** pf::E2::D END ******************************/

/****************************** pf::E2::E START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1de489d885e9b2du, 0x327d5272ae4d0ad7u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x1de489d885e9b2du, 0x327d5272ae4d0ad7u};
    constexpr static ID TypeID = ::pf::meta::ID{0x4569c634cac2afdau, 0x40a907554c722702u};
    using Type = pf::E2;

    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E2::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E2 Value = pf::E2::E;
};
/****************************** pf::E2::E END ******************************/

/****************************** pf::E2 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4569c634cac2afdau, 0x40a907554c722702u}> {
    using Type = pf::E2;
    constexpr static ID TypeID = ::pf::meta::ID{0x4569c634cac2afdau, 0x40a907554c722702u};

    constexpr static std::uint64_t SourceLine = 22;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = ::pf::StringLiteral{"E2"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E2"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
            ::pf::meta::ID{0x60a07f1198e2d161u, 0x37c3f11239335156u}, ::pf::meta::ID{0x5386801a7d705ca9u, 0x6d398279349f7edcu},
            ::pf::meta::ID{0x194bf4c4b8d15fc3u, 0x4a27d288ede171cdu}, ::pf::meta::ID{0xd0ea8e8f24430b70u, 0x8f807fffd1ffd723u},
            ::pf::meta::ID{0x1de489d885e9b2du, 0x327d5272ae4d0ad7u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf6e5afb0e8e6231au, 0xd9ff52df8c82a052u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xf6e5afb0e8e6231au, 0xd9ff52df8c82a052u},
                                                ::pf::meta::ID{0x4569c634cac2afdau, 0x40a907554c722702u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x729aac9bb1d28c0cu, 0xa2d639f920a92275u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x729aac9bb1d28c0cu, 0xa2d639f920a92275u},
                                               ::pf::meta::ID{0x4569c634cac2afdau, 0x40a907554c722702u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x516c1ed53058cd4eu, 0x95173659b6b60094u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x516c1ed53058cd4eu, 0x95173659b6b60094u},
                                               ::pf::meta::ID{0x4569c634cac2afdau, 0x40a907554c722702u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x575bca28cd86ec8bu, 0xa48524c0e3eb07f2u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x575bca28cd86ec8bu, 0xa48524c0e3eb07f2u},
                                               ::pf::meta::ID{0xf6e5afb0e8e6231au, 0xd9ff52df8c82a052u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x21b0090fe8d3638bu, 0xc2cc9b0ce4e379a6u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x21b0090fe8d3638bu, 0xc2cc9b0ce4e379a6u},
                                              ::pf::meta::ID{0x4569c634cac2afdau, 0x40a907554c722702u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x82cc110007823409u, 0x55d1b83202fc5f23u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x82cc110007823409u, 0x55d1b83202fc5f23u},
                                              ::pf::meta::ID{0xf6e5afb0e8e6231au, 0xd9ff52df8c82a052u}> {};

/****************************** pf::E2 END ******************************/
namespace pf::meta::details {
    /****************************** pf::E2 START ******************************/
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E2>() {
        return ::pf::meta::ID{0x4569c634cac2afdau, 0x40a907554c722702u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E2>() {
        return ::pf::meta::ID{0xf6e5afb0e8e6231au, 0xd9ff52df8c82a052u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E2 &>() {
        return ::pf::meta::ID{0x729aac9bb1d28c0cu, 0xa2d639f920a92275u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E2 &&>() {
        return ::pf::meta::ID{0x516c1ed53058cd4eu, 0x95173659b6b60094u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E2 &>() {
        return ::pf::meta::ID{0x575bca28cd86ec8bu, 0xa48524c0e3eb07f2u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E2 *>() {
        return ::pf::meta::ID{0x21b0090fe8d3638bu, 0xc2cc9b0ce4e379a6u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E2 *>() {
        return ::pf::meta::ID{0x82cc110007823409u, 0x55d1b83202fc5f23u};
    }
    /****************************** pf::E2 END ******************************/

    /****************************** pf::E2::pf::E2::A START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E2::A>() {
        return ::pf::meta::ID{0x60a07f1198e2d161u, 0x37c3f11239335156u};
    }
    /****************************** pf::E2::pf::E2::A END ******************************/

    /****************************** pf::E2::pf::E2::B START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E2::B>() {
        return ::pf::meta::ID{0x5386801a7d705ca9u, 0x6d398279349f7edcu};
    }
    /****************************** pf::E2::pf::E2::B END ******************************/

    /****************************** pf::E2::pf::E2::C START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E2::C>() {
        return ::pf::meta::ID{0x194bf4c4b8d15fc3u, 0x4a27d288ede171cdu};
    }
    /****************************** pf::E2::pf::E2::C END ******************************/

    /****************************** pf::E2::pf::E2::D START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E2::D>() {
        return ::pf::meta::ID{0xd0ea8e8f24430b70u, 0x8f807fffd1ffd723u};
    }
    /****************************** pf::E2::pf::E2::D END ******************************/

    /****************************** pf::E2::pf::E2::E START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E2::E>() {
        return ::pf::meta::ID{0x1de489d885e9b2du, 0x327d5272ae4d0ad7u};
    }
    /****************************** pf::E2::pf::E2::E END ******************************/
}// namespace pf::meta::details
/****************************** pf::E3::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x45a01b659c84c915u, 0x836900ea75c731a0u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x45a01b659c84c915u, 0x836900ea75c731a0u};
    constexpr static ID TypeID = ::pf::meta::ID{0x86c32d64e656281au, 0xedff83093f0a0ad1u};
    using Type = pf::E3;

    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E3::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E3 Value = pf::E3::A;
};
/****************************** pf::E3::A END ******************************/

/****************************** pf::E3::B START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4047693edefb1df1u, 0xd12e6fe4f27385cu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x4047693edefb1df1u, 0xd12e6fe4f27385cu};
    constexpr static ID TypeID = ::pf::meta::ID{0x86c32d64e656281au, 0xedff83093f0a0ad1u};
    using Type = pf::E3;

    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E3::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E3 Value = pf::E3::B;
};
/****************************** pf::E3::B END ******************************/

/****************************** pf::E3::C START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7a64ca448fb7037cu, 0xcc4ac5d2f726cd0au}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x7a64ca448fb7037cu, 0xcc4ac5d2f726cd0au};
    constexpr static ID TypeID = ::pf::meta::ID{0x86c32d64e656281au, 0xedff83093f0a0ad1u};
    using Type = pf::E3;

    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E3::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E3 Value = pf::E3::C;
};
/****************************** pf::E3::C END ******************************/

/****************************** pf::E3::D START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd49b53a1288dd3b3u, 0x8c030dd5c1d2b1f1u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xd49b53a1288dd3b3u, 0x8c030dd5c1d2b1f1u};
    constexpr static ID TypeID = ::pf::meta::ID{0x86c32d64e656281au, 0xedff83093f0a0ad1u};
    using Type = pf::E3;

    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E3::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E3 Value = pf::E3::D;
};
/****************************** pf::E3::D END ******************************/

/****************************** pf::E3::E START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x4fce962ed8394f48u, 0xc2f3f0bf24de6525u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x4fce962ed8394f48u, 0xc2f3f0bf24de6525u};
    constexpr static ID TypeID = ::pf::meta::ID{0x86c32d64e656281au, 0xedff83093f0a0ad1u};
    using Type = pf::E3;

    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E3::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E3 Value = pf::E3::E;
};
/****************************** pf::E3::E END ******************************/

/****************************** pf::E3 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x86c32d64e656281au, 0xedff83093f0a0ad1u}> {
    using Type = pf::E3;
    constexpr static ID TypeID = ::pf::meta::ID{0x86c32d64e656281au, 0xedff83093f0a0ad1u};

    constexpr static std::uint64_t SourceLine = 23;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = ::pf::StringLiteral{"E3"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E3"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
            ::pf::meta::ID{0x45a01b659c84c915u, 0x836900ea75c731a0u}, ::pf::meta::ID{0x4047693edefb1df1u, 0xd12e6fe4f27385cu},
            ::pf::meta::ID{0x7a64ca448fb7037cu, 0xcc4ac5d2f726cd0au}, ::pf::meta::ID{0xd49b53a1288dd3b3u, 0x8c030dd5c1d2b1f1u},
            ::pf::meta::ID{0x4fce962ed8394f48u, 0xc2f3f0bf24de6525u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x60f0719d4cf6dfdu, 0x72229b1a403f2c58u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x60f0719d4cf6dfdu, 0x72229b1a403f2c58u},
                                                ::pf::meta::ID{0x86c32d64e656281au, 0xedff83093f0a0ad1u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdf0bc8a961e8ace6u, 0xe5033543e39705afu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xdf0bc8a961e8ace6u, 0xe5033543e39705afu},
                                               ::pf::meta::ID{0x86c32d64e656281au, 0xedff83093f0a0ad1u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8f10e214fdb5d206u, 0xd2b6544f213fcafeu}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x8f10e214fdb5d206u, 0xd2b6544f213fcafeu},
                                               ::pf::meta::ID{0x86c32d64e656281au, 0xedff83093f0a0ad1u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7bba0b313d08710u, 0x582237bf6fffc2c2u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x7bba0b313d08710u, 0x582237bf6fffc2c2u},
                                               ::pf::meta::ID{0x60f0719d4cf6dfdu, 0x72229b1a403f2c58u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa82c177045cf3fcau, 0xafcf1dd9b006152fu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xa82c177045cf3fcau, 0xafcf1dd9b006152fu},
                                              ::pf::meta::ID{0x86c32d64e656281au, 0xedff83093f0a0ad1u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc7d71d62b175fa2cu, 0xbc938fc3ae6e6a5du}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xc7d71d62b175fa2cu, 0xbc938fc3ae6e6a5du},
                                              ::pf::meta::ID{0x60f0719d4cf6dfdu, 0x72229b1a403f2c58u}> {};

/****************************** pf::E3 END ******************************/
namespace pf::meta::details {
    /****************************** pf::E3 START ******************************/
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E3>() {
        return ::pf::meta::ID{0x86c32d64e656281au, 0xedff83093f0a0ad1u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E3>() {
        return ::pf::meta::ID{0x60f0719d4cf6dfdu, 0x72229b1a403f2c58u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E3 &>() {
        return ::pf::meta::ID{0xdf0bc8a961e8ace6u, 0xe5033543e39705afu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E3 &&>() {
        return ::pf::meta::ID{0x8f10e214fdb5d206u, 0xd2b6544f213fcafeu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E3 &>() {
        return ::pf::meta::ID{0x7bba0b313d08710u, 0x582237bf6fffc2c2u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E3 *>() {
        return ::pf::meta::ID{0xa82c177045cf3fcau, 0xafcf1dd9b006152fu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E3 *>() {
        return ::pf::meta::ID{0xc7d71d62b175fa2cu, 0xbc938fc3ae6e6a5du};
    }
    /****************************** pf::E3 END ******************************/

    /****************************** pf::E3::pf::E3::A START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E3::A>() {
        return ::pf::meta::ID{0x45a01b659c84c915u, 0x836900ea75c731a0u};
    }
    /****************************** pf::E3::pf::E3::A END ******************************/

    /****************************** pf::E3::pf::E3::B START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E3::B>() {
        return ::pf::meta::ID{0x4047693edefb1df1u, 0xd12e6fe4f27385cu};
    }
    /****************************** pf::E3::pf::E3::B END ******************************/

    /****************************** pf::E3::pf::E3::C START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E3::C>() {
        return ::pf::meta::ID{0x7a64ca448fb7037cu, 0xcc4ac5d2f726cd0au};
    }
    /****************************** pf::E3::pf::E3::C END ******************************/

    /****************************** pf::E3::pf::E3::D START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E3::D>() {
        return ::pf::meta::ID{0xd49b53a1288dd3b3u, 0x8c030dd5c1d2b1f1u};
    }
    /****************************** pf::E3::pf::E3::D END ******************************/

    /****************************** pf::E3::pf::E3::E START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E3::E>() {
        return ::pf::meta::ID{0x4fce962ed8394f48u, 0xc2f3f0bf24de6525u};
    }
    /****************************** pf::E3::pf::E3::E END ******************************/
}// namespace pf::meta::details
/****************************** pf::E4::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x262aeecfd68ec65bu, 0x7a8b30f2e2477823u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x262aeecfd68ec65bu, 0x7a8b30f2e2477823u};
    constexpr static ID TypeID = ::pf::meta::ID{0x8a2fcb5a16fd908cu, 0x3a1b5c34b8f6b2f4u};
    using Type = pf::E4;

    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E4::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E4 Value = pf::E4::A;
};
/****************************** pf::E4::A END ******************************/

/****************************** pf::E4::B START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb0fc78bd120813d3u, 0xd4e4f480775bf778u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xb0fc78bd120813d3u, 0xd4e4f480775bf778u};
    constexpr static ID TypeID = ::pf::meta::ID{0x8a2fcb5a16fd908cu, 0x3a1b5c34b8f6b2f4u};
    using Type = pf::E4;

    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E4::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E4 Value = pf::E4::B;
};
/****************************** pf::E4::B END ******************************/

/****************************** pf::E4::C START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x36ee8f85a3b29476u, 0x23d9e3ef29f69038u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x36ee8f85a3b29476u, 0x23d9e3ef29f69038u};
    constexpr static ID TypeID = ::pf::meta::ID{0x8a2fcb5a16fd908cu, 0x3a1b5c34b8f6b2f4u};
    using Type = pf::E4;

    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E4::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E4 Value = pf::E4::C;
};
/****************************** pf::E4::C END ******************************/

/****************************** pf::E4::D START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8e4285bad53d8d9eu, 0x5cec39269feec990u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x8e4285bad53d8d9eu, 0x5cec39269feec990u};
    constexpr static ID TypeID = ::pf::meta::ID{0x8a2fcb5a16fd908cu, 0x3a1b5c34b8f6b2f4u};
    using Type = pf::E4;

    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E4::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E4 Value = pf::E4::D;
};
/****************************** pf::E4::D END ******************************/

/****************************** pf::E4::E START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6eb0a6b3a5da2922u, 0xa45616cc71c50c89u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x6eb0a6b3a5da2922u, 0xa45616cc71c50c89u};
    constexpr static ID TypeID = ::pf::meta::ID{0x8a2fcb5a16fd908cu, 0x3a1b5c34b8f6b2f4u};
    using Type = pf::E4;

    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E4::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E4 Value = pf::E4::E;
};
/****************************** pf::E4::E END ******************************/

/****************************** pf::E4 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8a2fcb5a16fd908cu, 0x3a1b5c34b8f6b2f4u}> {
    using Type = pf::E4;
    constexpr static ID TypeID = ::pf::meta::ID{0x8a2fcb5a16fd908cu, 0x3a1b5c34b8f6b2f4u};

    constexpr static std::uint64_t SourceLine = 24;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = ::pf::StringLiteral{"E4"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E4"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
            ::pf::meta::ID{0x262aeecfd68ec65bu, 0x7a8b30f2e2477823u}, ::pf::meta::ID{0xb0fc78bd120813d3u, 0xd4e4f480775bf778u},
            ::pf::meta::ID{0x36ee8f85a3b29476u, 0x23d9e3ef29f69038u}, ::pf::meta::ID{0x8e4285bad53d8d9eu, 0x5cec39269feec990u},
            ::pf::meta::ID{0x6eb0a6b3a5da2922u, 0xa45616cc71c50c89u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x13e6263c82e84057u, 0x55e99076cedfeed2u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x13e6263c82e84057u, 0x55e99076cedfeed2u},
                                                ::pf::meta::ID{0x8a2fcb5a16fd908cu, 0x3a1b5c34b8f6b2f4u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7a4a6ad9855d8075u, 0x49ab87e6d926a13du}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x7a4a6ad9855d8075u, 0x49ab87e6d926a13du},
                                               ::pf::meta::ID{0x8a2fcb5a16fd908cu, 0x3a1b5c34b8f6b2f4u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x78f2cf7c5fc9d8acu, 0x4cb73bf4f0d89c6au}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x78f2cf7c5fc9d8acu, 0x4cb73bf4f0d89c6au},
                                               ::pf::meta::ID{0x8a2fcb5a16fd908cu, 0x3a1b5c34b8f6b2f4u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf913c34d201aeb46u, 0xf1809b79ab97dda6u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xf913c34d201aeb46u, 0xf1809b79ab97dda6u},
                                               ::pf::meta::ID{0x13e6263c82e84057u, 0x55e99076cedfeed2u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x48fd8fea8dbc7020u, 0xef3e7e294ba28287u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x48fd8fea8dbc7020u, 0xef3e7e294ba28287u},
                                              ::pf::meta::ID{0x8a2fcb5a16fd908cu, 0x3a1b5c34b8f6b2f4u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf11ca0dd1e0fc07du, 0x81db6b6a8c4d6423u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xf11ca0dd1e0fc07du, 0x81db6b6a8c4d6423u},
                                              ::pf::meta::ID{0x13e6263c82e84057u, 0x55e99076cedfeed2u}> {};

/****************************** pf::E4 END ******************************/
namespace pf::meta::details {
    /****************************** pf::E4 START ******************************/
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E4>() {
        return ::pf::meta::ID{0x8a2fcb5a16fd908cu, 0x3a1b5c34b8f6b2f4u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E4>() {
        return ::pf::meta::ID{0x13e6263c82e84057u, 0x55e99076cedfeed2u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E4 &>() {
        return ::pf::meta::ID{0x7a4a6ad9855d8075u, 0x49ab87e6d926a13du};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E4 &&>() {
        return ::pf::meta::ID{0x78f2cf7c5fc9d8acu, 0x4cb73bf4f0d89c6au};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E4 &>() {
        return ::pf::meta::ID{0xf913c34d201aeb46u, 0xf1809b79ab97dda6u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E4 *>() {
        return ::pf::meta::ID{0x48fd8fea8dbc7020u, 0xef3e7e294ba28287u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E4 *>() {
        return ::pf::meta::ID{0xf11ca0dd1e0fc07du, 0x81db6b6a8c4d6423u};
    }
    /****************************** pf::E4 END ******************************/

    /****************************** pf::E4::pf::E4::A START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E4::A>() {
        return ::pf::meta::ID{0x262aeecfd68ec65bu, 0x7a8b30f2e2477823u};
    }
    /****************************** pf::E4::pf::E4::A END ******************************/

    /****************************** pf::E4::pf::E4::B START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E4::B>() {
        return ::pf::meta::ID{0xb0fc78bd120813d3u, 0xd4e4f480775bf778u};
    }
    /****************************** pf::E4::pf::E4::B END ******************************/

    /****************************** pf::E4::pf::E4::C START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E4::C>() {
        return ::pf::meta::ID{0x36ee8f85a3b29476u, 0x23d9e3ef29f69038u};
    }
    /****************************** pf::E4::pf::E4::C END ******************************/

    /****************************** pf::E4::pf::E4::D START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E4::D>() {
        return ::pf::meta::ID{0x8e4285bad53d8d9eu, 0x5cec39269feec990u};
    }
    /****************************** pf::E4::pf::E4::D END ******************************/

    /****************************** pf::E4::pf::E4::E START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E4::E>() {
        return ::pf::meta::ID{0x6eb0a6b3a5da2922u, 0xa45616cc71c50c89u};
    }
    /****************************** pf::E4::pf::E4::E END ******************************/
}// namespace pf::meta::details
/****************************** pf::E5::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd8289d7ae1c5ac29u, 0xf46e7ce9ec543f2cu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xd8289d7ae1c5ac29u, 0xf46e7ce9ec543f2cu};
    constexpr static ID TypeID = ::pf::meta::ID{0xe2d28252c5786675u, 0x77ad1057c18fddb0u};
    using Type = pf::E5;

    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E5::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E5 Value = pf::E5::A;
};
/****************************** pf::E5::A END ******************************/

/****************************** pf::E5::B START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf6374cffebc44e20u, 0xb9bf79e95932ee8au}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xf6374cffebc44e20u, 0xb9bf79e95932ee8au};
    constexpr static ID TypeID = ::pf::meta::ID{0xe2d28252c5786675u, 0x77ad1057c18fddb0u};
    using Type = pf::E5;

    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E5::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E5 Value = pf::E5::B;
};
/****************************** pf::E5::B END ******************************/

/****************************** pf::E5::C START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2547aec0ac0b655bu, 0xe899f720b90457f3u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x2547aec0ac0b655bu, 0xe899f720b90457f3u};
    constexpr static ID TypeID = ::pf::meta::ID{0xe2d28252c5786675u, 0x77ad1057c18fddb0u};
    using Type = pf::E5;

    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E5::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E5 Value = pf::E5::C;
};
/****************************** pf::E5::C END ******************************/

/****************************** pf::E5::D START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb867486ad6b07946u, 0xef52c3d1d25cead6u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xb867486ad6b07946u, 0xef52c3d1d25cead6u};
    constexpr static ID TypeID = ::pf::meta::ID{0xe2d28252c5786675u, 0x77ad1057c18fddb0u};
    using Type = pf::E5;

    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E5::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E5 Value = pf::E5::D;
};
/****************************** pf::E5::D END ******************************/

/****************************** pf::E5::E START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x5201f819e4112350u, 0xc0726bb766c59102u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x5201f819e4112350u, 0xc0726bb766c59102u};
    constexpr static ID TypeID = ::pf::meta::ID{0xe2d28252c5786675u, 0x77ad1057c18fddb0u};
    using Type = pf::E5;

    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E5::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E5 Value = pf::E5::E;
};
/****************************** pf::E5::E END ******************************/

/****************************** pf::E5 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe2d28252c5786675u, 0x77ad1057c18fddb0u}> {
    using Type = pf::E5;
    constexpr static ID TypeID = ::pf::meta::ID{0xe2d28252c5786675u, 0x77ad1057c18fddb0u};

    constexpr static std::uint64_t SourceLine = 25;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = ::pf::StringLiteral{"E5"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E5"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
            ::pf::meta::ID{0xd8289d7ae1c5ac29u, 0xf46e7ce9ec543f2cu}, ::pf::meta::ID{0xf6374cffebc44e20u, 0xb9bf79e95932ee8au},
            ::pf::meta::ID{0x2547aec0ac0b655bu, 0xe899f720b90457f3u}, ::pf::meta::ID{0xb867486ad6b07946u, 0xef52c3d1d25cead6u},
            ::pf::meta::ID{0x5201f819e4112350u, 0xc0726bb766c59102u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x80ff948d0e609933u, 0xbcc56815cfb8900du}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x80ff948d0e609933u, 0xbcc56815cfb8900du},
                                                ::pf::meta::ID{0xe2d28252c5786675u, 0x77ad1057c18fddb0u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2507290d97317ee2u, 0x315e97c94cf3d5abu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x2507290d97317ee2u, 0x315e97c94cf3d5abu},
                                               ::pf::meta::ID{0xe2d28252c5786675u, 0x77ad1057c18fddb0u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdee4f9390d5f61f2u, 0x1c40ca0b51cd0affu}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xdee4f9390d5f61f2u, 0x1c40ca0b51cd0affu},
                                               ::pf::meta::ID{0xe2d28252c5786675u, 0x77ad1057c18fddb0u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xee5eb29daecd2645u, 0x3cdda3cb29a6ed8bu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xee5eb29daecd2645u, 0x3cdda3cb29a6ed8bu},
                                               ::pf::meta::ID{0x80ff948d0e609933u, 0xbcc56815cfb8900du}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc2739ebd546f1ef4u, 0xca490f51722ad5a5u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xc2739ebd546f1ef4u, 0xca490f51722ad5a5u},
                                              ::pf::meta::ID{0xe2d28252c5786675u, 0x77ad1057c18fddb0u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xa2787a41e856506bu, 0x13a63568a112aa83u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xa2787a41e856506bu, 0x13a63568a112aa83u},
                                              ::pf::meta::ID{0x80ff948d0e609933u, 0xbcc56815cfb8900du}> {};

/****************************** pf::E5 END ******************************/
namespace pf::meta::details {
    /****************************** pf::E5 START ******************************/
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E5>() {
        return ::pf::meta::ID{0xe2d28252c5786675u, 0x77ad1057c18fddb0u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E5>() {
        return ::pf::meta::ID{0x80ff948d0e609933u, 0xbcc56815cfb8900du};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E5 &>() {
        return ::pf::meta::ID{0x2507290d97317ee2u, 0x315e97c94cf3d5abu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E5 &&>() {
        return ::pf::meta::ID{0xdee4f9390d5f61f2u, 0x1c40ca0b51cd0affu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E5 &>() {
        return ::pf::meta::ID{0xee5eb29daecd2645u, 0x3cdda3cb29a6ed8bu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E5 *>() {
        return ::pf::meta::ID{0xc2739ebd546f1ef4u, 0xca490f51722ad5a5u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E5 *>() {
        return ::pf::meta::ID{0xa2787a41e856506bu, 0x13a63568a112aa83u};
    }
    /****************************** pf::E5 END ******************************/

    /****************************** pf::E5::pf::E5::A START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E5::A>() {
        return ::pf::meta::ID{0xd8289d7ae1c5ac29u, 0xf46e7ce9ec543f2cu};
    }
    /****************************** pf::E5::pf::E5::A END ******************************/

    /****************************** pf::E5::pf::E5::B START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E5::B>() {
        return ::pf::meta::ID{0xf6374cffebc44e20u, 0xb9bf79e95932ee8au};
    }
    /****************************** pf::E5::pf::E5::B END ******************************/

    /****************************** pf::E5::pf::E5::C START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E5::C>() {
        return ::pf::meta::ID{0x2547aec0ac0b655bu, 0xe899f720b90457f3u};
    }
    /****************************** pf::E5::pf::E5::C END ******************************/

    /****************************** pf::E5::pf::E5::D START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E5::D>() {
        return ::pf::meta::ID{0xb867486ad6b07946u, 0xef52c3d1d25cead6u};
    }
    /****************************** pf::E5::pf::E5::D END ******************************/

    /****************************** pf::E5::pf::E5::E START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E5::E>() {
        return ::pf::meta::ID{0x5201f819e4112350u, 0xc0726bb766c59102u};
    }
    /****************************** pf::E5::pf::E5::E END ******************************/
}// namespace pf::meta::details
/****************************** pf::E6::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3083e03bb0cfcdf1u, 0x2b639917385921e7u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x3083e03bb0cfcdf1u, 0x2b639917385921e7u};
    constexpr static ID TypeID = ::pf::meta::ID{0x2d488958c0661e20u, 0xec4a0c8208b359ceu};
    using Type = pf::E6;

    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E6::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E6 Value = pf::E6::A;
};
/****************************** pf::E6::A END ******************************/

/****************************** pf::E6::B START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x9cb3b43da84c2804u, 0x7094341b55a9e865u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x9cb3b43da84c2804u, 0x7094341b55a9e865u};
    constexpr static ID TypeID = ::pf::meta::ID{0x2d488958c0661e20u, 0xec4a0c8208b359ceu};
    using Type = pf::E6;

    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E6::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E6 Value = pf::E6::B;
};
/****************************** pf::E6::B END ******************************/

/****************************** pf::E6::C START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd5353da8ae36c662u, 0x575de0d984b7fd30u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xd5353da8ae36c662u, 0x575de0d984b7fd30u};
    constexpr static ID TypeID = ::pf::meta::ID{0x2d488958c0661e20u, 0xec4a0c8208b359ceu};
    using Type = pf::E6;

    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E6::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E6 Value = pf::E6::C;
};
/****************************** pf::E6::C END ******************************/

/****************************** pf::E6::D START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb8b8dff7747e3f02u, 0x2372bc9936259ec8u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xb8b8dff7747e3f02u, 0x2372bc9936259ec8u};
    constexpr static ID TypeID = ::pf::meta::ID{0x2d488958c0661e20u, 0xec4a0c8208b359ceu};
    using Type = pf::E6;

    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E6::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E6 Value = pf::E6::D;
};
/****************************** pf::E6::D END ******************************/

/****************************** pf::E6::E START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xe29b2d458571096u, 0x12ee5476d983d5c3u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xe29b2d458571096u, 0x12ee5476d983d5c3u};
    constexpr static ID TypeID = ::pf::meta::ID{0x2d488958c0661e20u, 0xec4a0c8208b359ceu};
    using Type = pf::E6;

    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E6::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E6 Value = pf::E6::E;
};
/****************************** pf::E6::E END ******************************/

/****************************** pf::E6 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2d488958c0661e20u, 0xec4a0c8208b359ceu}> {
    using Type = pf::E6;
    constexpr static ID TypeID = ::pf::meta::ID{0x2d488958c0661e20u, 0xec4a0c8208b359ceu};

    constexpr static std::uint64_t SourceLine = 26;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = ::pf::StringLiteral{"E6"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E6"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
            ::pf::meta::ID{0x3083e03bb0cfcdf1u, 0x2b639917385921e7u}, ::pf::meta::ID{0x9cb3b43da84c2804u, 0x7094341b55a9e865u},
            ::pf::meta::ID{0xd5353da8ae36c662u, 0x575de0d984b7fd30u}, ::pf::meta::ID{0xb8b8dff7747e3f02u, 0x2372bc9936259ec8u},
            ::pf::meta::ID{0xe29b2d458571096u, 0x12ee5476d983d5c3u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x125837a88ec9a373u, 0x61d7eaeacc12d5a0u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x125837a88ec9a373u, 0x61d7eaeacc12d5a0u},
                                                ::pf::meta::ID{0x2d488958c0661e20u, 0xec4a0c8208b359ceu}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xdcd0933fbc43df81u, 0xaec8d4d84db73f62u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xdcd0933fbc43df81u, 0xaec8d4d84db73f62u},
                                               ::pf::meta::ID{0x2d488958c0661e20u, 0xec4a0c8208b359ceu}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xbb73fa209332df6fu, 0x1c30497e545e705u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xbb73fa209332df6fu, 0x1c30497e545e705u},
                                               ::pf::meta::ID{0x2d488958c0661e20u, 0xec4a0c8208b359ceu}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7835f5e3b90112efu, 0xa626f33ef5fae305u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x7835f5e3b90112efu, 0xa626f33ef5fae305u},
                                               ::pf::meta::ID{0x125837a88ec9a373u, 0x61d7eaeacc12d5a0u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc4728a0c02bfefceu, 0x58dad59582f0074eu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xc4728a0c02bfefceu, 0x58dad59582f0074eu},
                                              ::pf::meta::ID{0x2d488958c0661e20u, 0xec4a0c8208b359ceu}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x6e8c239bdf34240fu, 0x8973fe0c259e633eu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x6e8c239bdf34240fu, 0x8973fe0c259e633eu},
                                              ::pf::meta::ID{0x125837a88ec9a373u, 0x61d7eaeacc12d5a0u}> {};

/****************************** pf::E6 END ******************************/
namespace pf::meta::details {
    /****************************** pf::E6 START ******************************/
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E6>() {
        return ::pf::meta::ID{0x2d488958c0661e20u, 0xec4a0c8208b359ceu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E6>() {
        return ::pf::meta::ID{0x125837a88ec9a373u, 0x61d7eaeacc12d5a0u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E6 &>() {
        return ::pf::meta::ID{0xdcd0933fbc43df81u, 0xaec8d4d84db73f62u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E6 &&>() {
        return ::pf::meta::ID{0xbb73fa209332df6fu, 0x1c30497e545e705u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E6 &>() {
        return ::pf::meta::ID{0x7835f5e3b90112efu, 0xa626f33ef5fae305u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E6 *>() {
        return ::pf::meta::ID{0xc4728a0c02bfefceu, 0x58dad59582f0074eu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E6 *>() {
        return ::pf::meta::ID{0x6e8c239bdf34240fu, 0x8973fe0c259e633eu};
    }
    /****************************** pf::E6 END ******************************/

    /****************************** pf::E6::pf::E6::A START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E6::A>() {
        return ::pf::meta::ID{0x3083e03bb0cfcdf1u, 0x2b639917385921e7u};
    }
    /****************************** pf::E6::pf::E6::A END ******************************/

    /****************************** pf::E6::pf::E6::B START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E6::B>() {
        return ::pf::meta::ID{0x9cb3b43da84c2804u, 0x7094341b55a9e865u};
    }
    /****************************** pf::E6::pf::E6::B END ******************************/

    /****************************** pf::E6::pf::E6::C START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E6::C>() {
        return ::pf::meta::ID{0xd5353da8ae36c662u, 0x575de0d984b7fd30u};
    }
    /****************************** pf::E6::pf::E6::C END ******************************/

    /****************************** pf::E6::pf::E6::D START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E6::D>() {
        return ::pf::meta::ID{0xb8b8dff7747e3f02u, 0x2372bc9936259ec8u};
    }
    /****************************** pf::E6::pf::E6::D END ******************************/

    /****************************** pf::E6::pf::E6::E START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E6::E>() {
        return ::pf::meta::ID{0xe29b2d458571096u, 0x12ee5476d983d5c3u};
    }
    /****************************** pf::E6::pf::E6::E END ******************************/
}// namespace pf::meta::details
/****************************** pf::E7::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb38996f3f600fc11u, 0xec726f4b58c65b5eu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xb38996f3f600fc11u, 0xec726f4b58c65b5eu};
    constexpr static ID TypeID = ::pf::meta::ID{0xfc8ef84d71db707bu, 0x6a1a02c8d623a323u};
    using Type = pf::E7;

    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E7::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E7 Value = pf::E7::A;
};
/****************************** pf::E7::A END ******************************/

/****************************** pf::E7::B START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xc999b054aed9132du, 0xaf0af8b6a65e4dccu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xc999b054aed9132du, 0xaf0af8b6a65e4dccu};
    constexpr static ID TypeID = ::pf::meta::ID{0xfc8ef84d71db707bu, 0x6a1a02c8d623a323u};
    using Type = pf::E7;

    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E7::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E7 Value = pf::E7::B;
};
/****************************** pf::E7::B END ******************************/

/****************************** pf::E7::C START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x10995467f307f67fu, 0x2abbce111de8c02du}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x10995467f307f67fu, 0x2abbce111de8c02du};
    constexpr static ID TypeID = ::pf::meta::ID{0xfc8ef84d71db707bu, 0x6a1a02c8d623a323u};
    using Type = pf::E7;

    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E7::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E7 Value = pf::E7::C;
};
/****************************** pf::E7::C END ******************************/

/****************************** pf::E7::D START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x2f35a095eb3488dau, 0x19285eefced9bb82u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x2f35a095eb3488dau, 0x19285eefced9bb82u};
    constexpr static ID TypeID = ::pf::meta::ID{0xfc8ef84d71db707bu, 0x6a1a02c8d623a323u};
    using Type = pf::E7;

    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E7::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E7 Value = pf::E7::D;
};
/****************************** pf::E7::D END ******************************/

/****************************** pf::E7::E START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x1cb2a7bb71e1cdc6u, 0x37d8e55e9f7ac2b6u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x1cb2a7bb71e1cdc6u, 0x37d8e55e9f7ac2b6u};
    constexpr static ID TypeID = ::pf::meta::ID{0xfc8ef84d71db707bu, 0x6a1a02c8d623a323u};
    using Type = pf::E7;

    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E7::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E7 Value = pf::E7::E;
};
/****************************** pf::E7::E END ******************************/

/****************************** pf::E7 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xfc8ef84d71db707bu, 0x6a1a02c8d623a323u}> {
    using Type = pf::E7;
    constexpr static ID TypeID = ::pf::meta::ID{0xfc8ef84d71db707bu, 0x6a1a02c8d623a323u};

    constexpr static std::uint64_t SourceLine = 27;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = ::pf::StringLiteral{"E7"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E7"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
            ::pf::meta::ID{0xb38996f3f600fc11u, 0xec726f4b58c65b5eu}, ::pf::meta::ID{0xc999b054aed9132du, 0xaf0af8b6a65e4dccu},
            ::pf::meta::ID{0x10995467f307f67fu, 0x2abbce111de8c02du}, ::pf::meta::ID{0x2f35a095eb3488dau, 0x19285eefced9bb82u},
            ::pf::meta::ID{0x1cb2a7bb71e1cdc6u, 0x37d8e55e9f7ac2b6u});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd0afb9f0c158e759u, 0xc69eaf287a4bddbcu}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xd0afb9f0c158e759u, 0xc69eaf287a4bddbcu},
                                                ::pf::meta::ID{0xfc8ef84d71db707bu, 0x6a1a02c8d623a323u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xf4d8fe066f4fa46du, 0x8e892fbc9be45b45u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0xf4d8fe066f4fa46du, 0x8e892fbc9be45b45u},
                                               ::pf::meta::ID{0xfc8ef84d71db707bu, 0x6a1a02c8d623a323u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3e0266f6301f9c66u, 0xf1b83a6825fe0988u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0x3e0266f6301f9c66u, 0xf1b83a6825fe0988u},
                                               ::pf::meta::ID{0xfc8ef84d71db707bu, 0x6a1a02c8d623a323u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x96fd2dc09e75f0a5u, 0xca83192b30cbfd22u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x96fd2dc09e75f0a5u, 0xca83192b30cbfd22u},
                                               ::pf::meta::ID{0xd0afb9f0c158e759u, 0xc69eaf287a4bddbcu}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x724b8b5da8279e20u, 0x4e1923678780e1f1u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x724b8b5da8279e20u, 0x4e1923678780e1f1u},
                                              ::pf::meta::ID{0xfc8ef84d71db707bu, 0x6a1a02c8d623a323u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xedea753a6b460bc2u, 0xafd9b85d529caa3cu}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0xedea753a6b460bc2u, 0xafd9b85d529caa3cu},
                                              ::pf::meta::ID{0xd0afb9f0c158e759u, 0xc69eaf287a4bddbcu}> {};

/****************************** pf::E7 END ******************************/
namespace pf::meta::details {
    /****************************** pf::E7 START ******************************/
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E7>() {
        return ::pf::meta::ID{0xfc8ef84d71db707bu, 0x6a1a02c8d623a323u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E7>() {
        return ::pf::meta::ID{0xd0afb9f0c158e759u, 0xc69eaf287a4bddbcu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E7 &>() {
        return ::pf::meta::ID{0xf4d8fe066f4fa46du, 0x8e892fbc9be45b45u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E7 &&>() {
        return ::pf::meta::ID{0x3e0266f6301f9c66u, 0xf1b83a6825fe0988u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E7 &>() {
        return ::pf::meta::ID{0x96fd2dc09e75f0a5u, 0xca83192b30cbfd22u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E7 *>() {
        return ::pf::meta::ID{0x724b8b5da8279e20u, 0x4e1923678780e1f1u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E7 *>() {
        return ::pf::meta::ID{0xedea753a6b460bc2u, 0xafd9b85d529caa3cu};
    }
    /****************************** pf::E7 END ******************************/

    /****************************** pf::E7::pf::E7::A START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E7::A>() {
        return ::pf::meta::ID{0xb38996f3f600fc11u, 0xec726f4b58c65b5eu};
    }
    /****************************** pf::E7::pf::E7::A END ******************************/

    /****************************** pf::E7::pf::E7::B START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E7::B>() {
        return ::pf::meta::ID{0xc999b054aed9132du, 0xaf0af8b6a65e4dccu};
    }
    /****************************** pf::E7::pf::E7::B END ******************************/

    /****************************** pf::E7::pf::E7::C START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E7::C>() {
        return ::pf::meta::ID{0x10995467f307f67fu, 0x2abbce111de8c02du};
    }
    /****************************** pf::E7::pf::E7::C END ******************************/

    /****************************** pf::E7::pf::E7::D START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E7::D>() {
        return ::pf::meta::ID{0x2f35a095eb3488dau, 0x19285eefced9bb82u};
    }
    /****************************** pf::E7::pf::E7::D END ******************************/

    /****************************** pf::E7::pf::E7::E START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E7::E>() {
        return ::pf::meta::ID{0x1cb2a7bb71e1cdc6u, 0x37d8e55e9f7ac2b6u};
    }
    /****************************** pf::E7::pf::E7::E END ******************************/
}// namespace pf::meta::details
/****************************** pf::E8::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x28df45c582582e2du, 0x1eb31808bc578d9eu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x28df45c582582e2du, 0x1eb31808bc578d9eu};
    constexpr static ID TypeID = ::pf::meta::ID{0x67a249b7cb5bafdau, 0x85d3608a6217b470u};
    using Type = pf::E8;

    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E8::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E8 Value = pf::E8::A;
};
/****************************** pf::E8::A END ******************************/

/****************************** pf::E8::B START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x685b7bbd3846be99u, 0x1f5fc961dddf1d7au}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x685b7bbd3846be99u, 0x1f5fc961dddf1d7au};
    constexpr static ID TypeID = ::pf::meta::ID{0x67a249b7cb5bafdau, 0x85d3608a6217b470u};
    using Type = pf::E8;

    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E8::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E8 Value = pf::E8::B;
};
/****************************** pf::E8::B END ******************************/

/****************************** pf::E8::C START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x770d6d8745da99bu, 0xed5e063545be0203u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x770d6d8745da99bu, 0xed5e063545be0203u};
    constexpr static ID TypeID = ::pf::meta::ID{0x67a249b7cb5bafdau, 0x85d3608a6217b470u};
    using Type = pf::E8;

    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E8::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E8 Value = pf::E8::C;
};
/****************************** pf::E8::C END ******************************/

/****************************** pf::E8::D START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8d51a98317303a7bu, 0x7d49b1169feab528u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x8d51a98317303a7bu, 0x7d49b1169feab528u};
    constexpr static ID TypeID = ::pf::meta::ID{0x67a249b7cb5bafdau, 0x85d3608a6217b470u};
    using Type = pf::E8;

    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E8::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E8 Value = pf::E8::D;
};
/****************************** pf::E8::D END ******************************/

/****************************** pf::E8::E START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd423682e7dae8684u, 0x237e7a10d18f1a6bu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xd423682e7dae8684u, 0x237e7a10d18f1a6bu};
    constexpr static ID TypeID = ::pf::meta::ID{0x67a249b7cb5bafdau, 0x85d3608a6217b470u};
    using Type = pf::E8;

    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E8::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E8 Value = pf::E8::E;
};
/****************************** pf::E8::E END ******************************/

/****************************** pf::E8 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x67a249b7cb5bafdau, 0x85d3608a6217b470u}> {
    using Type = pf::E8;
    constexpr static ID TypeID = ::pf::meta::ID{0x67a249b7cb5bafdau, 0x85d3608a6217b470u};

    constexpr static std::uint64_t SourceLine = 28;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = ::pf::StringLiteral{"E8"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E8"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
            ::pf::meta::ID{0x28df45c582582e2du, 0x1eb31808bc578d9eu}, ::pf::meta::ID{0x685b7bbd3846be99u, 0x1f5fc961dddf1d7au},
            ::pf::meta::ID{0x770d6d8745da99bu, 0xed5e063545be0203u}, ::pf::meta::ID{0x8d51a98317303a7bu, 0x7d49b1169feab528u},
            ::pf::meta::ID{0xd423682e7dae8684u, 0x237e7a10d18f1a6bu});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb5603b73a04f3fd6u, 0x4d9444d01b44cab8u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0xb5603b73a04f3fd6u, 0x4d9444d01b44cab8u},
                                                ::pf::meta::ID{0x67a249b7cb5bafdau, 0x85d3608a6217b470u}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x5f5aed0876a1c01du, 0x59b48acb114246c2u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x5f5aed0876a1c01du, 0x59b48acb114246c2u},
                                               ::pf::meta::ID{0x67a249b7cb5bafdau, 0x85d3608a6217b470u}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xb9b477e505fa3cb0u, 0x4f9b7569be547e10u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xb9b477e505fa3cb0u, 0x4f9b7569be547e10u},
                                               ::pf::meta::ID{0x67a249b7cb5bafdau, 0x85d3608a6217b470u}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8b2920b311bc91e3u, 0xa19c822bd193c346u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x8b2920b311bc91e3u, 0xa19c822bd193c346u},
                                               ::pf::meta::ID{0xb5603b73a04f3fd6u, 0x4d9444d01b44cab8u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x8fa9fee7b81427b5u, 0x7cbfb87e021bc29u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x8fa9fee7b81427b5u, 0x7cbfb87e021bc29u},
                                              ::pf::meta::ID{0x67a249b7cb5bafdau, 0x85d3608a6217b470u}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7108b08943227fd5u, 0x7e09607756fb5c9du}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x7108b08943227fd5u, 0x7e09607756fb5c9du},
                                              ::pf::meta::ID{0xb5603b73a04f3fd6u, 0x4d9444d01b44cab8u}> {};

/****************************** pf::E8 END ******************************/
namespace pf::meta::details {
    /****************************** pf::E8 START ******************************/
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E8>() {
        return ::pf::meta::ID{0x67a249b7cb5bafdau, 0x85d3608a6217b470u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E8>() {
        return ::pf::meta::ID{0xb5603b73a04f3fd6u, 0x4d9444d01b44cab8u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E8 &>() {
        return ::pf::meta::ID{0x5f5aed0876a1c01du, 0x59b48acb114246c2u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E8 &&>() {
        return ::pf::meta::ID{0xb9b477e505fa3cb0u, 0x4f9b7569be547e10u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E8 &>() {
        return ::pf::meta::ID{0x8b2920b311bc91e3u, 0xa19c822bd193c346u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E8 *>() {
        return ::pf::meta::ID{0x8fa9fee7b81427b5u, 0x7cbfb87e021bc29u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E8 *>() {
        return ::pf::meta::ID{0x7108b08943227fd5u, 0x7e09607756fb5c9du};
    }
    /****************************** pf::E8 END ******************************/

    /****************************** pf::E8::pf::E8::A START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E8::A>() {
        return ::pf::meta::ID{0x28df45c582582e2du, 0x1eb31808bc578d9eu};
    }
    /****************************** pf::E8::pf::E8::A END ******************************/

    /****************************** pf::E8::pf::E8::B START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E8::B>() {
        return ::pf::meta::ID{0x685b7bbd3846be99u, 0x1f5fc961dddf1d7au};
    }
    /****************************** pf::E8::pf::E8::B END ******************************/

    /****************************** pf::E8::pf::E8::C START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E8::C>() {
        return ::pf::meta::ID{0x770d6d8745da99bu, 0xed5e063545be0203u};
    }
    /****************************** pf::E8::pf::E8::C END ******************************/

    /****************************** pf::E8::pf::E8::D START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E8::D>() {
        return ::pf::meta::ID{0x8d51a98317303a7bu, 0x7d49b1169feab528u};
    }
    /****************************** pf::E8::pf::E8::D END ******************************/

    /****************************** pf::E8::pf::E8::E START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E8::E>() {
        return ::pf::meta::ID{0xd423682e7dae8684u, 0x237e7a10d18f1a6bu};
    }
    /****************************** pf::E8::pf::E8::E END ******************************/
}// namespace pf::meta::details
/****************************** pf::E9::A START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x51d53c1f68ae2909u, 0x8006abc878e9aba0u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x51d53c1f68ae2909u, 0x8006abc878e9aba0u};
    constexpr static ID TypeID = ::pf::meta::ID{0x3f45495e26ddeea4u, 0xa3c14a47b73ecc9bu};
    using Type = pf::E9;

    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"A"};
    constexpr static auto FullName = StringLiteral{"pf::E9::A"};

    constexpr static int UnderlyingValue = 0;
    constexpr static pf::E9 Value = pf::E9::A;
};
/****************************** pf::E9::A END ******************************/

/****************************** pf::E9::B START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xfbbd3ca2c747eafdu, 0xb14b50ea72040f62u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xfbbd3ca2c747eafdu, 0xb14b50ea72040f62u};
    constexpr static ID TypeID = ::pf::meta::ID{0x3f45495e26ddeea4u, 0xa3c14a47b73ecc9bu};
    using Type = pf::E9;

    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"B"};
    constexpr static auto FullName = StringLiteral{"pf::E9::B"};

    constexpr static int UnderlyingValue = 1;
    constexpr static pf::E9 Value = pf::E9::B;
};
/****************************** pf::E9::B END ******************************/

/****************************** pf::E9::C START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x66fe7f777ec3c436u, 0x626f39492d8f0f0au}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x66fe7f777ec3c436u, 0x626f39492d8f0f0au};
    constexpr static ID TypeID = ::pf::meta::ID{0x3f45495e26ddeea4u, 0xa3c14a47b73ecc9bu};
    using Type = pf::E9;

    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"C"};
    constexpr static auto FullName = StringLiteral{"pf::E9::C"};

    constexpr static int UnderlyingValue = 2;
    constexpr static pf::E9 Value = pf::E9::C;
};
/****************************** pf::E9::C END ******************************/

/****************************** pf::E9::D START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xd07e1553f3bc40afu, 0x6dc9f63754b60046u}> {
    constexpr static ID ValueID = ::pf::meta::ID{0xd07e1553f3bc40afu, 0x6dc9f63754b60046u};
    constexpr static ID TypeID = ::pf::meta::ID{0x3f45495e26ddeea4u, 0xa3c14a47b73ecc9bu};
    using Type = pf::E9;

    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"D"};
    constexpr static auto FullName = StringLiteral{"pf::E9::D"};

    constexpr static int UnderlyingValue = 3;
    constexpr static pf::E9 Value = pf::E9::D;
};
/****************************** pf::E9::D END ******************************/

/****************************** pf::E9::E START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x77dd7ffdd61c1996u, 0xdf70ff039fc5a4afu}> {
    constexpr static ID ValueID = ::pf::meta::ID{0x77dd7ffdd61c1996u, 0xdf70ff039fc5a4afu};
    constexpr static ID TypeID = ::pf::meta::ID{0x3f45495e26ddeea4u, 0xa3c14a47b73ecc9bu};
    using Type = pf::E9;

    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = false;
    constexpr static bool IsEnumValue = true;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static auto Name = StringLiteral{"E"};
    constexpr static auto FullName = StringLiteral{"pf::E9::E"};

    constexpr static int UnderlyingValue = 4;
    constexpr static pf::E9 Value = pf::E9::E;
};
/****************************** pf::E9::E END ******************************/

/****************************** pf::E9 START ******************************/
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x3f45495e26ddeea4u, 0xa3c14a47b73ecc9bu}> {
    using Type = pf::E9;
    constexpr static ID TypeID = ::pf::meta::ID{0x3f45495e26ddeea4u, 0xa3c14a47b73ecc9bu};

    constexpr static std::uint64_t SourceLine = 29;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<pf::meta::Attribute> auto Attributes = pf::make_array<pf::meta::Attribute>();

    constexpr static bool IsEnum = true;
    constexpr static bool IsEnumValue = false;
    constexpr static bool IsRecord = false;
    constexpr static bool IsUnion = false;
    constexpr static bool IsPrimitiveType = false;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = ::pf::StringLiteral{"E9"};
    constexpr static auto FullName = ::pf::StringLiteral{"pf::E9"};

    using UnderlyingType = int;
    constexpr static bool IsScoped = std::is_scoped_enum_v<Type>;
    constexpr static RangeOf<pf::meta::Info> auto EnumValues = pf::make_array<pf::meta::Info>(
            ::pf::meta::ID{0x51d53c1f68ae2909u, 0x8006abc878e9aba0u}, ::pf::meta::ID{0xfbbd3ca2c747eafdu, 0xb14b50ea72040f62u},
            ::pf::meta::ID{0x66fe7f777ec3c436u, 0x626f39492d8f0f0au}, ::pf::meta::ID{0xd07e1553f3bc40afu, 0x6dc9f63754b60046u},
            ::pf::meta::ID{0x77dd7ffdd61c1996u, 0xdf70ff039fc5a4afu});
};

// const
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x85c41c8c5f121ab4u, 0x534adf1312686428u}>
    : ::pf::meta::details::StaticInfo_ConstWrap<::pf::meta::ID{0x85c41c8c5f121ab4u, 0x534adf1312686428u},
                                                ::pf::meta::ID{0x3f45495e26ddeea4u, 0xa3c14a47b73ecc9bu}> {};
// &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x7be7efbfee13f746u, 0x2237f40fdc81bb59u}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x7be7efbfee13f746u, 0x2237f40fdc81bb59u},
                                               ::pf::meta::ID{0x3f45495e26ddeea4u, 0xa3c14a47b73ecc9bu}> {};
// &&
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0xfef5e03a3d92392bu, 0x4ef442075df5ad03u}>
    : ::pf::meta::details::StaticInfo_RRefWrap<::pf::meta::ID{0xfef5e03a3d92392bu, 0x4ef442075df5ad03u},
                                               ::pf::meta::ID{0x3f45495e26ddeea4u, 0xa3c14a47b73ecc9bu}> {};
// const &
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x842af7bc4d01d1bau, 0xefaced9200410f2cu}>
    : ::pf::meta::details::StaticInfo_LRefWrap<::pf::meta::ID{0x842af7bc4d01d1bau, 0xefaced9200410f2cu},
                                               ::pf::meta::ID{0x85c41c8c5f121ab4u, 0x534adf1312686428u}> {};
// *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x15536b1151410d01u, 0x75827db8ce39257u}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x15536b1151410d01u, 0x75827db8ce39257u},
                                              ::pf::meta::ID{0x3f45495e26ddeea4u, 0xa3c14a47b73ecc9bu}> {};
// const *
template<>
struct ::pf::meta::details::StaticInfo<::pf::meta::ID{0x987722cc7b07e756u, 0x30b8819a3ea9676du}>
    : ::pf::meta::details::StaticInfo_PtrWrap<::pf::meta::ID{0x987722cc7b07e756u, 0x30b8819a3ea9676du},
                                              ::pf::meta::ID{0x85c41c8c5f121ab4u, 0x534adf1312686428u}> {};

/****************************** pf::E9 END ******************************/
namespace pf::meta::details {
    /****************************** pf::E9 START ******************************/
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E9>() {
        return ::pf::meta::ID{0x3f45495e26ddeea4u, 0xa3c14a47b73ecc9bu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E9>() {
        return ::pf::meta::ID{0x85c41c8c5f121ab4u, 0x534adf1312686428u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E9 &>() {
        return ::pf::meta::ID{0x7be7efbfee13f746u, 0x2237f40fdc81bb59u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E9 &&>() {
        return ::pf::meta::ID{0xfef5e03a3d92392bu, 0x4ef442075df5ad03u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E9 &>() {
        return ::pf::meta::ID{0x842af7bc4d01d1bau, 0xefaced9200410f2cu};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<pf::E9 *>() {
        return ::pf::meta::ID{0x15536b1151410d01u, 0x75827db8ce39257u};
    }
    template<>
    [[nodiscard]] consteval ID getTypeId<const pf::E9 *>() {
        return ::pf::meta::ID{0x987722cc7b07e756u, 0x30b8819a3ea9676du};
    }
    /****************************** pf::E9 END ******************************/

    /****************************** pf::E9::pf::E9::A START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E9::A>() {
        return ::pf::meta::ID{0x51d53c1f68ae2909u, 0x8006abc878e9aba0u};
    }
    /****************************** pf::E9::pf::E9::A END ******************************/

    /****************************** pf::E9::pf::E9::B START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E9::B>() {
        return ::pf::meta::ID{0xfbbd3ca2c747eafdu, 0xb14b50ea72040f62u};
    }
    /****************************** pf::E9::pf::E9::B END ******************************/

    /****************************** pf::E9::pf::E9::C START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E9::C>() {
        return ::pf::meta::ID{0x66fe7f777ec3c436u, 0x626f39492d8f0f0au};
    }
    /****************************** pf::E9::pf::E9::C END ******************************/

    /****************************** pf::E9::pf::E9::D START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E9::D>() {
        return ::pf::meta::ID{0xd07e1553f3bc40afu, 0x6dc9f63754b60046u};
    }
    /****************************** pf::E9::pf::E9::D END ******************************/

    /****************************** pf::E9::pf::E9::E START ******************************/
    template<>
    [[nodiscard]] consteval ID getConstantId<pf::E9::E>() {
        return ::pf::meta::ID{0x77dd7ffdd61c1996u, 0xdf70ff039fc5a4afu};
    }
    /****************************** pf::E9::pf::E9::E END ******************************/
}// namespace pf::meta::details
