module;

#include <ranges>
#include <utility>
#include <optional>

export module speculo:template_for;
import :details;

export namespace speculo {

    /// Call a templated function for every element in range V.
    /// @tparam V contiguous range to iterate through
    /// @tparam F type of a templated callable
    /// @param f instance of a templated callable
    template<std::ranges::contiguous_range auto V, typename F>
    constexpr void template_for(F &&f) {
        details::template_for_impl<V>(std::forward<F>(f), std::make_index_sequence<V.size()>{});
    }
    /// Call a templated function for every element in range V until a non empty optional is returned.
    /// All possible invocations of the function must return the same type which has to be a specialization of std::optional.
    /// @tparam V contiguous range to iterate through
    /// @tparam F type of a templated callable
    /// @param f instance of a templated callable
    /// @return an instance of std::optional
    template<std::ranges::contiguous_range auto V, typename F>
    constexpr auto template_for_r(F &&f) {
        using Result = decltype(std::declval<F>().template operator()<std::ranges::range_value_t<decltype(V)>{}>());
        static_assert(SpecializationOf<Result, std::optional>);
        return details::template_for_impl_r<V, Result>(std::forward<F>(f), std::make_index_sequence<V.size()>{});
    }

}
