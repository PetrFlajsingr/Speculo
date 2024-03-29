//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

namespace speculo::gen::templates {

    constexpr auto StaticValueInfo_Enum = R"fmt(
template<>
struct StaticInfo<{value_id}> {{
    {details}
    constexpr static ID ValueID = {value_id};
    constexpr static ID Id = {type_id};
    using Type = {type};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = speculo::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static {underlying_type} UnderlyingValue = {underlying_value};
    constexpr static {type} Value = {value};
}};
)fmt";

}
