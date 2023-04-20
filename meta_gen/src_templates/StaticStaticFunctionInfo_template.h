//
// Created by xflajs00 on 27.03.2023.
//

#ifndef PF_META_GEN_STATICSTATICFUNCTIONINFO_TEMPLATE_H
#define PF_META_GEN_STATICSTATICFUNCTIONINFO_TEMPLATE_H

constexpr auto StaticTypeInfoTemplate_StaticFunction = R"fmt(
/****************************** {full_name} START ******************************/
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID FunctionID = {id};
    constexpr static ID TypeID = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::StaticFunction;

    constexpr static bool IsPublic = {is_public};
    constexpr static bool IsProtected = {is_protected};
    constexpr static bool IsPrivate = {is_private};

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};

    constexpr static Info ReturnType = {return_type_id};
    constexpr static RangeOf<Info> auto Arguments = pf::meta::details::make_array<Info>({arguments});

    constexpr static {member_type} = &{member};
    }};
)fmt";

#endif//PF_META_GEN_STATICSTATICFUNCTIONINFO_TEMPLATE_H
