//
// Created by xflajs00 on 15.03.2023.
//

#pragma once

#include <meta/details/ID.hpp>
#include <meta/details/StringLiteral.hpp>
#include <meta/details/meta_helpers.hpp>

namespace pf::meta::details {

    enum class StaticInfoType {
        EnumType,
        EnumValue,
        RecordType,
        Base,
        Constructor,
        Destructor,
        MemberFunction,
        MemberVariable,
        StaticFunction,
        StaticVariable,
        Argument,
        FundamentalType
    };

    template<ID ID>
    struct StaticInfo {
        static_assert(AlwaysFalseV<ID>, "Static reflection not generated for type or the required meta file was not included");
    };

    constexpr static std::array<std::string_view, 0> EmptyAttributeArgArray{};

}// namespace pf::meta::details
