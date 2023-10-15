/// @file idToString.hpp
/// @brief
/// @author PetrFlajsingr

#pragma once

import speculo;

#include <string>

#include <fmt/format.h>

namespace speculo::gen {

    [[nodiscard]] inline std::string idToString(speculo::ID id) {
        return fmt::format("ID{{0x{:x}u, 0x{:x}u}}", id.id[0], id.id[1]);
    }

}// namespace speculo::gen