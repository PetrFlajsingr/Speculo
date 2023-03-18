//
// Created by xflajs00 on 17.03.2023.
//

#ifndef PF_META_GEN_STATICVALUEINFO_TEMPLATE_H
#define PF_META_GEN_STATICVALUEINFO_TEMPLATE_H

namespace pf::meta_gen {

    constexpr auto StaticValueInfoTemplate_Enum = R"fmt(
/****************************** {full_name} START ******************************/
template<>
struct StaticInfo<{value_id}> {{
    struct details {{
        {details}
    }};
    constexpr static ID ValueID = {value_id};
    constexpr static ID TypeID = {type_id};
    using Type = {type};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::EnumValue;

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static {underlying_type} UnderlyingValue = {underlying_value};
    constexpr static {type} Value = {value};
}};
/****************************** {full_name} END ******************************/
)fmt";

}

#endif //PF_META_GEN_STATICVALUEINFO_TEMPLATE_H
