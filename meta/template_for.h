//
// Created by xflajs00 on 15.03.2023.
//

#ifndef PF_META_TEMPLATE_FOR_H
#define PF_META_TEMPLATE_FOR_H

#include "details/template_for.h"

namespace pf::meta {

    template<auto R, typename F>
    constexpr void template_for(F &&f) {
        details::template_for_impl<R, 0>(std::forward<F>(f));
    }

}

#endif //PF_META_TEMPLATE_FOR_H
