//
// Created by xflajs00 on 15.03.2023.
//

#ifndef PF_META_DETAILS_STATICTYPEINFO_H
#define PF_META_DETAILS_STATICTYPEINFO_H

#include "meta_helpers.h"
#include "ID.h"
#include <pf_common/containers/StringLiteral.h>

namespace pf::meta::details {

    template<ID ID>
    struct StaticInfo {
        static_assert(AlwaysFalseV<ID>, "Static reflection not generated for type");
    };

}

#endif //PF_META_DETAILS_STATICTYPEINFO_H
