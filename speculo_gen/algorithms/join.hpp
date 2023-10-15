/// @file Join.hpp
/// @brief
/// @author PetrFlajsingr

#pragma once

import speculo;

#include <algorithm>
#include <functional>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

namespace speculo::gen {

    [[nodiscard]] std::string join(const speculo::RangeOf<std::string> auto &strings, const std::string &delimiter) {
        auto commonStrings = strings | std::views::common;
        const auto requiredCapacity =
                std::accumulate(std::ranges::begin(commonStrings), std::ranges::end(commonStrings), 0ull,
                                [&](std::size_t total, const auto &str) { return total + str.size() + delimiter.size(); });
        std::string result;
        result.reserve(requiredCapacity);
        for (auto iter = std::ranges::begin(strings); iter != std::ranges::end(strings);) {
            result += *iter;
            if (++iter != std::ranges::end(strings)) { result += delimiter; }
        }
        return result;
    }

}// namespace speculo::gen