/// @file optional_utils.hpp
/// @brief
/// @author PetrFlajsingr

#pragma once

#include <concepts>
#include <functional>
#include <optional>
#include <utility>

namespace speculo::gen {

    template<typename T, std::invocable<const T &> Projection,
             std::convertible_to<std::remove_cvref_t<std::invoke_result_t<Projection, const T &>>> U>
    [[nodiscard]] std::remove_cvref_t<std::invoke_result_t<Projection, const T &>> projectOr(const std::optional<T> &opt, Projection proj,
                                                                                             U &&defaultValue) {
        if (opt.has_value()) { return std::invoke(proj, *opt); }
        return std::forward<U>(defaultValue);
    }

}// namespace speculo::gen