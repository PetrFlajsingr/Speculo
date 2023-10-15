module;

#include <string_view>
#include <optional>

#include <speculo/reflect.hpp>

export module speculo:enums;
import :details;
import :info;

export namespace speculo {
    /// Type which is an enum or an enum class
    template<typename E>
    concept EnumType = std::is_enum_v<E>;

    /// Convert enum value to its string representation.
    /// @tparam E type of the enum value
    /// @param value value to convert
    /// @return string representation of the enum value or a warning string if no such enumerator exists
    template<EnumType E>
    [[nodiscard]] constexpr std::string_view to_string(E value) {
        constexpr Info enumInfo = SPECULO_REFLECT(E);
        return template_for_r<members_of<enumInfo>()>([&]<Info valueInfo>() -> std::optional<std::string_view> {
                   if (SPECULO_SPLICE(valueInfo) == value) { return std::optional{name_of<valueInfo>()}; }
                   return std::nullopt;
               })
                .value_or("<INVALID_ENUM_VALUE>");
    }
    /// Create an enum value from its string representation.
    /// @tparam E type of the enum to create
    /// @param name string representation of the enumerator
    /// @return enumerator if the name is contained within the enum, nullopt otherwise
    template<EnumType E>
    [[nodiscard]] constexpr std::optional<E> from_string(std::string_view name) {
        constexpr Info enumInfo = SPECULO_REFLECT(E);
        return template_for_r<members_of<enumInfo>()>([&]<Info valueInfo>() -> std::optional<E> {
            if (name_of<valueInfo>() == name) { return SPECULO_SPLICE(valueInfo); }
            return std::nullopt;
        });
    }
    /// Create enum value from its underlying value.
    /// @tparam E type of the enum to create
    /// @param value value to convert to an enumerator
    /// @return converted enumerator or nullopt if no such enumerator exists
    template<EnumType E>
    [[nodiscard]] constexpr std::optional<E> from_underlying(std::underlying_type_t<E> value) {
        constexpr Info enumInfo = SPECULO_REFLECT(E);
        return template_for_r<members_of<enumInfo>()>([&]<Info valueInfo>() -> std::optional<E> {
            if (static_cast<std::underlying_type_t<E>>(SPECULO_SPLICE(valueInfo)) == value) { return SPECULO_SPLICE(valueInfo); }
            return std::nullopt;
        });
    }
    /// Get all values contained within an enum.
    /// @tparam E enum type to get values from
    /// @return range of enumerators
    template<EnumType E>
    [[nodiscard]] constexpr RangeOf<E> auto enumerator_values() {
        constexpr Info enumInfo = SPECULO_REFLECT(E);
        constexpr auto enumerators = members_of<enumInfo>();
        std::array<E, enumerators.size()> result{};
        std::size_t i{};
        template_for<enumerators>([&]<auto VI>() { result[i++] = SPECULO_SPLICE(VI); });
        return result;
    }
    /// Get declaration order index of an enumerator.
    /// @tparam E enum value type
    /// @param value value to get index of
    /// @return index of the enumerator if valid, nullopt otherwise
    template<EnumType E>
    [[nodiscard]] constexpr std::optional<std::size_t> index_of(E value) {
        constexpr Info enumInfo = SPECULO_REFLECT(E);
        std::size_t i{};
        return template_for_r<members_of<enumInfo>()>([&]<Info valueInfo>() -> std::optional<std::size_t> {
            if (SPECULO_SPLICE(valueInfo) == value) { return i; }
            ++i;
            return std::nullopt;
        });
    }

}// namespace speculo