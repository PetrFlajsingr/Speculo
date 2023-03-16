//
// Created by xflajs00 on 15.03.2023.
//

#ifndef PF_META_DETAILS_TEMPLATE_FOR_H
#define PF_META_DETAILS_TEMPLATE_FOR_H

#include <cstddef>
#include <utility>

namespace pf::meta::details {

    template<auto V, std::size_t I, typename F>
    constexpr void template_for_impl(F &&f) {
        if constexpr (I == V.size()) {
            return;
        } else {
            f.template operator()<V[I]>();
            template_for_impl<V, I + 1, F>(std::forward<F>(f));
        }
    }
}

#endif //PF_META_DETAILS_TEMPLATE_FOR_H
