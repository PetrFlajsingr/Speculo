//
// Created by xflajs00 on 27.03.2023.
//

#ifndef PF_META_GEN_STATICDESTRUCTORINFO_TEMPLATE_H
#define PF_META_GEN_STATICDESTRUCTORINFO_TEMPLATE_H

constexpr auto StaticTypeInfoTemplate_Destructor = R"fmt(
/****************************** {full_name} START ******************************/
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID DestructorID = {id};
    constexpr static ID TypeID = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static RangeOf<Attribute> auto Attributes = pf::meta::details::make_array<Attribute>({attributes});

    constexpr static auto StaticInfoObjectType = StaticInfoType::Destructor;

    constexpr static bool IsPublic = {is_public};
    constexpr static bool IsProtected = {is_protected};
    constexpr static bool IsPrivate = {is_private};
    constexpr static auto IsConstexpr = {is_constexpr};
    constexpr static auto IsConsteval = {is_consteval};
    constexpr static auto IsVirtual = {is_virtual};
    constexpr static auto IsPureVirtual = {is_pure_virtual};

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};
    }};
)fmt";

#endif//PF_META_GEN_STATICDESTRUCTORINFO_TEMPLATE_H
