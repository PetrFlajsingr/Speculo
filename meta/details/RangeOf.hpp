/**
 * @file RangeOf.h
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <concepts>
#include <ranges>

namespace pf::meta::details {

    template<typename R, typename ElementType>
    concept RangeOf = std::ranges::range<R> && std::same_as<std::ranges::range_value_t<R>, ElementType>;
}// namespace pf::meta::details
