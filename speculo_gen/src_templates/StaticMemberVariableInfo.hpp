//
// Created by xflajs00 on 27.03.2023.
//

#pragma once


namespace speculo::gen::templates {
    constexpr auto StaticTypeInfo_MemberVariable = R"fmt(
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID VariableID = {id};
    constexpr static ID Id = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = speculo::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::MemberVariable;

    constexpr static bool IsPublic = {is_public};
    constexpr static bool IsProtected = {is_protected};
    constexpr static bool IsPrivate = {is_private};
    constexpr static bool IsMutable = {is_mutable};
    constexpr static bool IsBitfield = {is_bitfield};
    constexpr static std::size_t Offset = {offset};
    constexpr static std::size_t Size = {size};
    {bitfield_block}

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    {member_ptr_block}
    }};
)fmt";


    constexpr auto StaticTypeInfo_BitfieldAccessor = R"fmt(
    template<bool IsConst>
    struct BitfieldAccessor {{
        using Parent = std::conditional_t<IsConst, const {parent_type}, {parent_type}>;
        constexpr explicit BitfieldAccessor(Parent *p) : parent{{p}} {{}}
        constexpr auto &operator=(int rhs) requires (!IsConst) {{
            parent->{bitfield_name} = rhs;
            return *this;
        }}
        constexpr explicit(false) operator int() const {{
            return parent->{bitfield_name};
        }}
    private:
        Parent *parent;
    }};

    constexpr static BitfieldAccessor<false> CreateBitfieldAccessor({parent_type} *self) {{
        return BitfieldAccessor<false>{{self}};
    }}
    constexpr static BitfieldAccessor<true> CreateBitfieldAccessor(const {parent_type} *self) {{
        return BitfieldAccessor<true>{{self}};
    }}
)fmt";
}// namespace speculo::gen::templates