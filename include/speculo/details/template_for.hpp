//
// Created by xflajs00 on 15.03.2023.
//

#pragma once

#include <cstddef>
#include <optional>
#include <utility>

namespace speculo::details {

    template<auto V, typename F, std::size_t... Is>
    constexpr void template_for_impl(F &&f, std::index_sequence<Is...>) {
        (f.template operator()<V[Is]>(), ...);
    }

    template<auto V, typename Result, typename F, std::size_t... Is>
    constexpr auto template_for_impl_r(F &&f, std::index_sequence<Is...>) -> Result {
        Result res;
        [[maybe_unused]] const auto _ = ((res = f.template operator()<V[Is]>(), res.has_value()) || ...);
        return res;
    }
}// namespace speculo::details
