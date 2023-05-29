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

namespace pf::meta_gen {

    template<std::ranges::range Range, typename Proj = std::identity>
    [[nodiscard]] constexpr bool contains(Range &&haystack, const auto &needle, Proj proj = {})
        requires(std::equality_comparable_with<decltype(needle), std::ranges::range_value_t<Range>>)
    {
        return std::ranges::any_of(
                haystack, [&](auto &&value) { return needle == value; }, proj);
    }

}// namespace pf::meta_gen