//
// Created by xflajs00 on 27.03.2023.
//

#pragma once

namespace speculo::gen::templates {

    constexpr auto StaticTypeInfo_Argument = R"fmt(
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID ArgumentID = {id};
    constexpr static ID Id = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = speculo::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::Argument;

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};
    }};
)fmt";
}
