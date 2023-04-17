//
// Created by xflajs00 on 15.03.2023.
//

#ifndef PF_META_DETAILS_STATICTYPEINFO_H
#define PF_META_DETAILS_STATICTYPEINFO_H

#include "ID.h"
#include "meta_helpers.h"
#include <pf_common/containers/StringLiteral.h>

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
        static_assert(AlwaysFalseV<ID>, "Static reflection not generated for type");
    };

    constexpr static std::array<std::string_view, 0> EmptyAttributeArgArray{};

}// namespace pf::meta::details

#endif//PF_META_DETAILS_STATICTYPEINFO_H
