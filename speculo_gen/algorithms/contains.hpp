/**
 * @file Contains.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <algorithm>
#include <concepts>
#include <optional>
#include <ranges>

namespace speculo::gen {

    template<std::ranges::range Range, typename Proj = std::identity>
    [[nodiscard]] constexpr bool
    contains(Range &&haystack, const std::equality_comparable_with<std::ranges::range_value_t<Range>> auto &needle, Proj proj = {}) {
        return std::ranges::any_of(
                haystack, [&](auto &&value) { return needle == value; }, proj);
    }

}// namespace speculo::gen