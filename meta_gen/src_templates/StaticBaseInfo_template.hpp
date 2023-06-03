//
// Created by xflajs00 on 27.03.2023.
//

#pragma once

constexpr auto StaticTypeInfoTemplate_Base = R"fmt(
template<>
struct StaticInfo<{id}> {{
    {details}
    constexpr static ID BaseID = {id};
    constexpr static ID TypeID = {type_id};

    constexpr static auto SourceFile = R"path({source_file})path";
    constexpr static std::uint64_t SourceLine = {source_line};
    constexpr static std::uint64_t SourceColumn = {source_column};

    constexpr static auto StaticInfoObjectType = StaticInfoType::Base;

    constexpr static bool IsPublic = {is_public};
    constexpr static bool IsProtected = {is_protected};
    constexpr static bool IsPrivate = {is_private};
    constexpr static auto IsVirtual = {is_virtual};
    constexpr static std::size_t Offset = {offset};
    constexpr static std::size_t Size = {size};

    constexpr static auto Name = StringLiteral{{"{name}"}};
    constexpr static auto FullName = StringLiteral{{"{full_name}"}};
    }};
)fmt";
