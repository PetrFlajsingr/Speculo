
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
// Record SimpleStruct, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test2.hpp:11:1 
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
    constexpr static RangeOf<Info> auto MemberVariables = pf::meta::details::make_array<Info>(ID{0xb85e7b5dbcb67be4u, 0x5e9ed30670dab999u}, ID{0x685f6a6c23efb491u, 0x30d16e2ef7d8ffb1u}, ID{0xb55d3aef7b4ffe23u, 0x8f06566db59c83b7u}, ID{0xaa5626b34ff6b026u, 0xd0e32ef8310e1abau}, ID{0x875a46f77d5b032du, 0x5ed1a863bb6b3e8eu});
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
// Record SimpleStruct static info getters

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
// Record SimpleStruct member function SimpleStruct::footadlo

template<>
struct StaticInfo<ID{0x23561358310a0cbeu, 0xebb11a197749f289u}> {
    
    constexpr static ID FunctionID = ID{0x23561358310a0cbeu, 0xebb11a197749f289u};
    constexpr static ID TypeID = ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test2.hpp)path";
    constexpr static std::uint64_t SourceLine = 28;
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
    constexpr static bool IsConstexpr = false;
    constexpr static bool IsConsteval = false;
    constexpr static bool IsInline = true;
    constexpr static bool IsInlineSpecified = false;

    constexpr static auto Name = StringLiteral{"footadlo"};
    constexpr static auto FullName = StringLiteral{"SimpleStruct::footadlo"};

    constexpr static Info ReturnType = ID{0x115e3a70749cfd72u, 0xadd9686c1dcb30a2u};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>();

    constexpr static void(SimpleStruct::*MemberPtr)() = &SimpleStruct::footadlo;
    };
// Record SimpleStruct member variable SimpleStruct::b1

template<>
struct StaticInfo<ID{0xb85e7b5dbcb67be4u, 0x5e9ed30670dab999u}> {
    
    constexpr static ID VariableID = ID{0xb85e7b5dbcb67be4u, 0x5e9ed30670dab999u};
    constexpr static ID TypeID = ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test2.hpp)path";
    constexpr static std::uint64_t SourceLine = 14;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsMutable = false;
    constexpr static bool IsBitfield = true;
    constexpr static std::size_t BitfieldSize = 1;

    template<bool IsConst>
    struct BitfieldAccessor {
        using Parent = std::conditional_t<IsConst, const SimpleStruct, SimpleStruct>;
        constexpr explicit BitfieldAccessor(Parent *p) : parent{p} {}
        constexpr auto &operator=(int rhs) requires (!IsConst) {
            parent->b1 = rhs;
            return *this;
        }
        constexpr explicit(false) operator int() const {
            return parent->b1;
        }
    private:
        Parent *parent;
    };

    constexpr static BitfieldAccessor<false> CreateBitfieldAccessor(SimpleStruct *self) {
        return BitfieldAccessor<false>{self};
    }
    constexpr static BitfieldAccessor<true> CreateBitfieldAccessor(const SimpleStruct *self) {
        return BitfieldAccessor<true>{self};
    }


    constexpr static auto Name = StringLiteral{"b1"};
    constexpr static auto FullName = StringLiteral{"SimpleStruct::b1"};

    
    };
// Record SimpleStruct member variable SimpleStruct::b2

template<>
struct StaticInfo<ID{0x685f6a6c23efb491u, 0x30d16e2ef7d8ffb1u}> {
    
    constexpr static ID VariableID = ID{0x685f6a6c23efb491u, 0x30d16e2ef7d8ffb1u};
    constexpr static ID TypeID = ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test2.hpp)path";
    constexpr static std::uint64_t SourceLine = 15;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsMutable = false;
    constexpr static bool IsBitfield = true;
    constexpr static std::size_t BitfieldSize = 2;

    template<bool IsConst>
    struct BitfieldAccessor {
        using Parent = std::conditional_t<IsConst, const SimpleStruct, SimpleStruct>;
        constexpr explicit BitfieldAccessor(Parent *p) : parent{p} {}
        constexpr auto &operator=(int rhs) requires (!IsConst) {
            parent->b2 = rhs;
            return *this;
        }
        constexpr explicit(false) operator int() const {
            return parent->b2;
        }
    private:
        Parent *parent;
    };

    constexpr static BitfieldAccessor<false> CreateBitfieldAccessor(SimpleStruct *self) {
        return BitfieldAccessor<false>{self};
    }
    constexpr static BitfieldAccessor<true> CreateBitfieldAccessor(const SimpleStruct *self) {
        return BitfieldAccessor<true>{self};
    }


    constexpr static auto Name = StringLiteral{"b2"};
    constexpr static auto FullName = StringLiteral{"SimpleStruct::b2"};

    
    };
// Record SimpleStruct member variable SimpleStruct::b3

template<>
struct StaticInfo<ID{0xb55d3aef7b4ffe23u, 0x8f06566db59c83b7u}> {
    
    constexpr static ID VariableID = ID{0xb55d3aef7b4ffe23u, 0x8f06566db59c83b7u};
    constexpr static ID TypeID = ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test2.hpp)path";
    constexpr static std::uint64_t SourceLine = 16;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsMutable = false;
    constexpr static bool IsBitfield = true;
    constexpr static std::size_t BitfieldSize = 3;

    template<bool IsConst>
    struct BitfieldAccessor {
        using Parent = std::conditional_t<IsConst, const SimpleStruct, SimpleStruct>;
        constexpr explicit BitfieldAccessor(Parent *p) : parent{p} {}
        constexpr auto &operator=(int rhs) requires (!IsConst) {
            parent->b3 = rhs;
            return *this;
        }
        constexpr explicit(false) operator int() const {
            return parent->b3;
        }
    private:
        Parent *parent;
    };

    constexpr static BitfieldAccessor<false> CreateBitfieldAccessor(SimpleStruct *self) {
        return BitfieldAccessor<false>{self};
    }
    constexpr static BitfieldAccessor<true> CreateBitfieldAccessor(const SimpleStruct *self) {
        return BitfieldAccessor<true>{self};
    }


    constexpr static auto Name = StringLiteral{"b3"};
    constexpr static auto FullName = StringLiteral{"SimpleStruct::b3"};

    
    };
// Record SimpleStruct member variable SimpleStruct::b4

template<>
struct StaticInfo<ID{0xaa5626b34ff6b026u, 0xd0e32ef8310e1abau}> {
    
    constexpr static ID VariableID = ID{0xaa5626b34ff6b026u, 0xd0e32ef8310e1abau};
    constexpr static ID TypeID = ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test2.hpp)path";
    constexpr static std::uint64_t SourceLine = 17;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsMutable = false;
    constexpr static bool IsBitfield = true;
    constexpr static std::size_t BitfieldSize = 4;

    template<bool IsConst>
    struct BitfieldAccessor {
        using Parent = std::conditional_t<IsConst, const SimpleStruct, SimpleStruct>;
        constexpr explicit BitfieldAccessor(Parent *p) : parent{p} {}
        constexpr auto &operator=(int rhs) requires (!IsConst) {
            parent->b4 = rhs;
            return *this;
        }
        constexpr explicit(false) operator int() const {
            return parent->b4;
        }
    private:
        Parent *parent;
    };

    constexpr static BitfieldAccessor<false> CreateBitfieldAccessor(SimpleStruct *self) {
        return BitfieldAccessor<false>{self};
    }
    constexpr static BitfieldAccessor<true> CreateBitfieldAccessor(const SimpleStruct *self) {
        return BitfieldAccessor<true>{self};
    }


    constexpr static auto Name = StringLiteral{"b4"};
    constexpr static auto FullName = StringLiteral{"SimpleStruct::b4"};

    
    };
// Record SimpleStruct member variable SimpleStruct::b5

template<>
struct StaticInfo<ID{0x875a46f77d5b032du, 0x5ed1a863bb6b3e8eu}> {
    
    constexpr static ID VariableID = ID{0x875a46f77d5b032du, 0x5ed1a863bb6b3e8eu};
    constexpr static ID TypeID = ID{0x8a5eea7eb9fa4825u, 0x12c601cd168aca3u};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test2.hpp)path";
    constexpr static std::uint64_t SourceLine = 18;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsMutable = false;
    constexpr static bool IsBitfield = true;
    constexpr static std::size_t BitfieldSize = 5;

    template<bool IsConst>
    struct BitfieldAccessor {
        using Parent = std::conditional_t<IsConst, const SimpleStruct, SimpleStruct>;
        constexpr explicit BitfieldAccessor(Parent *p) : parent{p} {}
        constexpr auto &operator=(int rhs) requires (!IsConst) {
            parent->b5 = rhs;
            return *this;
        }
        constexpr explicit(false) operator int() const {
            return parent->b5;
        }
    private:
        Parent *parent;
    };

    constexpr static BitfieldAccessor<false> CreateBitfieldAccessor(SimpleStruct *self) {
        return BitfieldAccessor<false>{self};
    }
    constexpr static BitfieldAccessor<true> CreateBitfieldAccessor(const SimpleStruct *self) {
        return BitfieldAccessor<true>{self};
    }


    constexpr static auto Name = StringLiteral{"b5"};
    constexpr static auto FullName = StringLiteral{"SimpleStruct::b5"};

    
    };
// Record SimpleStruct **END**// Record SimpleStruct::NestedPublic, location C:\Users\xflajs00\CLionProjects\libclang_test\src\test2.hpp:20:5 
template<>
struct StaticInfo<ID{0xcb52df3a8620d8fbu, 0xa4b482a29391dc9bu}> {
    
    using Type = SimpleStruct::NestedPublic;
    constexpr static ID TypeID = ID{0xcb52df3a8620d8fbu, 0xa4b482a29391dc9bu};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test2.hpp)path";
    constexpr static std::uint64_t SourceLine = 20;
    constexpr static std::uint64_t SourceColumn = 5;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::RecordType;

    constexpr static bool IsLvalueReference = false;
    constexpr static bool IsRvalueReference = false;
    constexpr static bool IsConst = false;
    constexpr static bool IsPtr = false;

    constexpr static auto Name = StringLiteral{"NestedPublic"};
    constexpr static auto FullName = StringLiteral{"SimpleStruct::NestedPublic"};

    constexpr static bool IsUnion = false;
    constexpr static bool IsClass = false;
    constexpr static bool IsStruct = true;
    constexpr static bool IsPolymorphic = false;
    constexpr static bool IsAbstract = false;
    constexpr static bool IsFinal = false;
    constexpr static RangeOf<Info> auto Bases = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto Constructors = pf::meta::details::make_array<Info>();
    constexpr static Info Destructor = ID{0xe85925bf304d3be0u, 0x2a872c900c954884u};
    constexpr static RangeOf<Info> auto MemberFunctions = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto StaticFunctions = pf::meta::details::make_array<Info>();
    constexpr static RangeOf<Info> auto MemberVariables = pf::meta::details::make_array<Info>(ID{0x995e8284d41542d4u, 0x6ed26f5e7949a893u});
    constexpr static RangeOf<Info> auto StaticVariables = pf::meta::details::make_array<Info>();
};

// const
template<>
struct StaticInfo<ID{0x5534625651c42d7u, 0xe73c59835c93d493u}>
    : StaticInfo_ConstWrap<ID{0x5534625651c42d7u, 0xe73c59835c93d493u}, ID{0xcb52df3a8620d8fbu, 0xa4b482a29391dc9bu}> {};
// &
template<>
struct StaticInfo<ID{0xea551a1988fb1eacu, 0x5b6a5839b320e58au}>
    : StaticInfo_LRefWrap<ID{0xea551a1988fb1eacu, 0x5b6a5839b320e58au}, ID{0xcb52df3a8620d8fbu, 0xa4b482a29391dc9bu}> {};
// &&
template<>
struct StaticInfo<ID{0x2c58bc0007c6cd75u, 0xa5265c7878fd268eu}>
    : StaticInfo_RRefWrap<ID{0x2c58bc0007c6cd75u, 0xa5265c7878fd268eu}, ID{0xcb52df3a8620d8fbu, 0xa4b482a29391dc9bu}> {};
// const &
template<>
struct StaticInfo<ID{0xbd5755db1793d484u, 0x703199853a199092u}>
    : StaticInfo_ConstLRefWrap<ID{0xbd5755db1793d484u, 0x703199853a199092u}, ID{0xcb52df3a8620d8fbu, 0xa4b482a29391dc9bu}> {};
// *
template<>
struct StaticInfo<ID{0xc65d4063dfdf6e44u, 0x75ef5aead431ef99u}>
    : StaticInfo_PtrWrap<ID{0xc65d4063dfdf6e44u, 0x75ef5aead431ef99u}, ID{0xcb52df3a8620d8fbu, 0xa4b482a29391dc9bu}> {};
// const *
template<>
struct StaticInfo<ID{0xc7514f5356c934c9u, 0x782b4af47abab689u}>
    : StaticInfo_ConstPtrWrap<ID{0xc7514f5356c934c9u, 0x782b4af47abab689u}, ID{0xcb52df3a8620d8fbu, 0xa4b482a29391dc9bu}> {};
// Record SimpleStruct::NestedPublic static info getters

template<>
[[nodiscard]] consteval ID getTypeId<SimpleStruct::NestedPublic>() {
    return ID{0xcb52df3a8620d8fbu, 0xa4b482a29391dc9bu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const SimpleStruct::NestedPublic>() {
    return ID{0x5534625651c42d7u, 0xe73c59835c93d493u};
}
template<>
[[nodiscard]] consteval ID getTypeId<SimpleStruct::NestedPublic &>() {
    return ID{0xea551a1988fb1eacu, 0x5b6a5839b320e58au};
}
template<>
[[nodiscard]] consteval ID getTypeId<SimpleStruct::NestedPublic &&>() {
    return ID{0x2c58bc0007c6cd75u, 0xa5265c7878fd268eu};
}
template<>
[[nodiscard]] consteval ID getTypeId<const SimpleStruct::NestedPublic &>() {
    return ID{0xbd5755db1793d484u, 0x703199853a199092u};
}
template<>
[[nodiscard]] consteval ID getTypeId<SimpleStruct::NestedPublic *>() {
    return ID{0xc65d4063dfdf6e44u, 0x75ef5aead431ef99u};
}
template<>
[[nodiscard]] consteval ID getTypeId<const SimpleStruct::NestedPublic *>() {
    return ID{0xc7514f5356c934c9u, 0x782b4af47abab689u};
}
// Record SimpleStruct::NestedPublic member variable SimpleStruct::NestedPublic::a

template<>
struct StaticInfo<ID{0x995e8284d41542d4u, 0x6ed26f5e7949a893u}> {
    
    constexpr static ID VariableID = ID{0x995e8284d41542d4u, 0x6ed26f5e7949a893u};
    constexpr static ID TypeID = ID{0xcb52df3a8620d8fbu, 0xa4b482a29391dc9bu};

    constexpr static auto SourceFile = R"path(C:\Users\xflajs00\CLionProjects\libclang_test\src\test2.hpp)path";
    constexpr static std::uint64_t SourceLine = 21;
    constexpr static std::uint64_t SourceColumn = 9;

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>();

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

    constexpr static bool IsPublic = true;
    constexpr static bool IsProtected = false;
    constexpr static bool IsPrivate = false;
    constexpr static bool IsMutable = false;
    constexpr static bool IsBitfield = false;
    

    constexpr static auto Name = StringLiteral{"a"};
    constexpr static auto FullName = StringLiteral{"SimpleStruct::NestedPublic::a"};

    constexpr static int SimpleStruct::NestedPublic::* MemberPtr = &SimpleStruct::NestedPublic::a;
    };
// Record SimpleStruct::NestedPublic **END**
}
