/// @file OneOf.hpp
/// @brief
/// @author PetrFlajsingr

#pragma once

#include <concepts>

namespace speculo {
    template<typename T, typename... TOthers>
    concept OneOf = (std::same_as<T, TOthers> || ...);
}