//
// Created by xflajs00 on 15.03.2023.
//

#pragma once

#include <array>
#include <cstdint>
#include <speculo/details/meta_helpers.hpp>

namespace speculo {

    struct ID {
        constexpr ID() : ID{0x0u, 0x0u} {}

        constexpr explicit ID(const std::array<std::uint64_t, 2> &data) : id{data} {}

        constexpr ID(std::uint64_t w1, std::uint64_t w2) : id{w1, w2} {}

        [[nodiscard]] constexpr bool isValid() const { return id[0] != 0x0u && id[1] != 0x0u; }

        [[nodiscard]] constexpr bool operator==(const ID &other) const noexcept = default;

        constexpr static ID Invalid() { return ID{0x0u, 0x0u}; };

        std::array<std::uint64_t, 2> id;
    };

    namespace details {
        template<typename T>
        [[nodiscard]] consteval ID getTypeId() {
            static_assert(details::AlwaysFalseT<T>, "Static reflection not generated for type or an include missing");
            return {};
        }

        template<auto V>
        [[nodiscard]] consteval ID getConstantId() {
            static_assert(details::AlwaysFalseV<V>, "Static reflection not generated for value or an include missing");
            return {};
        }
    }// namespace details
}// namespace speculo
