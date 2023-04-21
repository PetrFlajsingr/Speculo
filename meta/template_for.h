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

    template<auto R, typename F>
    constexpr decltype(auto) template_for_r(F &&f) {
        return details::template_for_impl_r<R, 0>(std::forward<F>(f));
    }


    // TODO: hack for empty ranges
    //template<auto R, typename F>
    //requires(std::ranges::size(R) == 0)
    //constexpr decltype(auto) template_for_r(F &&f) {
    //    using Vfds = std::ranges::range_value_t<decltype(R)>;
    //    using A = decltype(f.template operator()<std::declval<Vfds>()>());
    //    return std::optional<A>{};
    //}

}

#endif //PF_META_TEMPLATE_FOR_H
