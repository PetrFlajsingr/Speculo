/**
 * @file enums.h
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <string_view>

#include <meta/details/RangeOf.hpp>
#include <meta/meta.hpp>
#include <meta/reflect.hpp>
#include <meta/template_for.hpp>

namespace pf::meta {
    template<typename E>
    concept EnumType = std::is_enum_v<E>;

    template<EnumType E>
    [[nodiscard]] constexpr std::string_view to_string(E value) {
        constexpr pf::meta::Info enumInfo = PF_REFLECT(E);
        const auto result = pf::meta::template_for_r<pf::meta::members_of<enumInfo>()>(
                [&]<pf::meta::Info valueInfo>() -> std::optional<std::string_view> {
                    if (PF_SPLICE(valueInfo) == value) { return std::optional{pf::meta::name_of<valueInfo>()}; }
                    return std::nullopt;
                });
        return result.value_or("<INVALID_ENUM_VALUE>");
    }

    template<EnumType E>
    [[nodiscard]] constexpr std::optional<E> from_string(std::string_view name) {
        constexpr pf::meta::Info enumInfo = PF_REFLECT(E);
        return pf::meta::template_for_r<pf::meta::members_of<enumInfo>()>([&]<pf::meta::Info valueInfo>() -> std::optional<E> {
            if (pf::meta::name_of<valueInfo>() == name) { return PF_SPLICE(valueInfo); }
            return std::nullopt;
        });
    }

    template<typename E>
    [[nodiscard]] constexpr pf::meta::details::RangeOf<E> auto enumerator_values() {
        constexpr pf::meta::Info enumInfo = PF_REFLECT(E);
        constexpr auto enumerators = pf::meta::members_of<enumInfo>();
        std::array<E, enumerators.size()> result{};
        std::size_t i{};
        pf::meta::template_for<enumerators>([&]<auto VI>() { result[i++] = PF_SPLICE(VI); });
        return result;
    }

}// namespace pf::meta