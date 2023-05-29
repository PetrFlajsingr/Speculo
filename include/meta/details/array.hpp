/**
 * @file array.h
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <array>
#include <concepts>

namespace pf::meta::details {
    template<typename T, std::convertible_to<T>... Args>
    [[nodiscard]] constexpr std::array<T, sizeof...(Args)> make_array(Args &&...args) {
        return {std::forward<Args>(args)...};
    }
}// namespace pf::meta::details
