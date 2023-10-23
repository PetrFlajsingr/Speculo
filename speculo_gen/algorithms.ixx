module;

#include <algorithm>
#include <ranges>
#include <numeric>
#include <optional>

export module speculo.gen:algorithms;

import speculo;

namespace speculo::gen {

    template<std::ranges::range Range, typename Proj = std::identity>
    [[nodiscard]] constexpr bool
    contains(Range &&haystack, const std::equality_comparable_with<std::ranges::range_value_t<Range>> auto &needle,
             Proj proj = {}) {
        return std::ranges::any_of(
                haystack, [&](auto &&value) { return needle == value; }, proj);
    }

    [[nodiscard]] std::string join(const speculo::RangeOf<std::string> auto &strings, const std::string &delimiter) {
        auto commonStrings = strings | std::views::common;
        const auto requiredCapacity =
                std::accumulate(std::ranges::begin(commonStrings), std::ranges::end(commonStrings), 0ull,
                                [&](std::size_t total, const auto &str) {
                                    return total + str.size() + delimiter.size();
                                });
        std::string result;
        result.reserve(requiredCapacity);
        for (auto iter = std::ranges::begin(strings); iter != std::ranges::end(strings);) {
            result += *iter;
            if (++iter != std::ranges::end(strings)) { result += delimiter; }
        }
        return result;
    }

    template<typename CharT, typename CharTraits>
    void replaceAllOccurrences(std::basic_string<CharT, CharTraits> &str,
                               speculo::OneOf<std::basic_string_view<CharT, CharTraits>, const CharT *> auto search,
                               speculo::OneOf<std::basic_string_view<CharT, CharTraits>, const CharT *> auto replace) {
        std::basic_string_view<CharT, CharTraits> replaceS{replace};
        std::basic_string_view<CharT, CharTraits> searchS{search};
        for (auto pos = 0ull; (pos = str.find(searchS, pos)) != std::string::npos; pos += replaceS.length()) {
            str.replace(pos, searchS.length(), replaceS);
        }
    }

    template<typename T, std::invocable<const T &> Projection,
            std::convertible_to<std::remove_cvref_t<std::invoke_result_t<Projection, const T &>>> U>
    [[nodiscard]] std::remove_cvref_t<std::invoke_result_t<Projection, const T &>>
    projectOr(const std::optional<T> &opt, Projection proj,
              U &&defaultValue) {
        if (opt.has_value()) { return std::invoke(proj, *opt); }
        return std::forward<U>(defaultValue);
    }

    template<typename... Ts>
    struct Visitor : Ts ... {
        using Ts::operator()...;
    };
    template<typename... Ts>
    Visitor(Ts...) -> Visitor<Ts...>;
}// namespace speculo::gen
