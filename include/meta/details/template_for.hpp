//
// Created by xflajs00 on 15.03.2023.
//

#pragma once

#include <cstddef>
#include <optional>
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

    // hackery in return type deduction:
    // gotta do [0], because in the last iteration the callable would no longer be valid
    template<auto V, std::size_t I, typename F>
    constexpr auto template_for_impl_r(F &&f) -> decltype(f.template operator()<V[0]>()) {
        if constexpr (I == V.size()) {
            return std::nullopt;
        } else {
            auto result = f.template operator()<V[I]>();
            if (result.has_value()) { return result; }
            return template_for_impl_r<V, I + 1, F>(std::forward<F>(f));
        }
    }
}// namespace pf::meta::details
