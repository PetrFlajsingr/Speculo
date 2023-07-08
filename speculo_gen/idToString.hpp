/// @file idToString.hpp
/// @brief
/// @author PetrFlajsingr

#pragma once

#include <string>

#include <fmt/format.h>

#include <speculo/ID.hpp>

namespace speculo::gen {

    [[nodiscard]] inline std::string idToString(speculo::ID id) { return fmt::format("ID{{0x{:x}u, 0x{:x}u}}", id.id[0], id.id[1]); }

}// namespace speculo::gen