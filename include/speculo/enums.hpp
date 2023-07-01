/**
 * @file enums.h
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <string_view>

#include <speculo/details/RangeOf.hpp>
#include <speculo/meta.hpp>
#include <speculo/reflect.hpp>
#include <speculo/template_for.hpp>

namespace speculo {
    template<typename E>
    concept EnumType = std::is_enum_v<E>;

    template<EnumType E>
    [[nodiscard]] constexpr std::string_view to_string(E value) {
        constexpr Info enumInfo = SPECULO_REFLECT(E);
        return template_for_r<members_of<enumInfo>()>([&]<Info valueInfo>() -> std::optional<std::string_view> {
                   if (SPECULO_SPLICE(valueInfo) == value) { return std::optional{name_of<valueInfo>()}; }
                   return std::nullopt;
               })
                .value_or("<INVALID_ENUM_VALUE>");
    }

    template<EnumType E>
    [[nodiscard]] constexpr std::optional<E> from_string(std::string_view name) {
        constexpr Info enumInfo = SPECULO_REFLECT(E);
        return template_for_r<members_of<enumInfo>()>([&]<Info valueInfo>() -> std::optional<E> {
            if (name_of<valueInfo>() == name) { return SPECULO_SPLICE(valueInfo); }
            return std::nullopt;
        });
    }

    template<EnumType E>
    [[nodiscard]] constexpr RangeOf<E> auto enumerator_values() {
        constexpr Info enumInfo = SPECULO_REFLECT(E);
        constexpr auto enumerators = members_of<enumInfo>();
        std::array<E, enumerators.size()> result{};
        std::size_t i{};
        template_for<enumerators>([&]<auto VI>() { result[i++] = SPECULO_SPLICE(VI); });
        return result;
    }

}// namespace speculo