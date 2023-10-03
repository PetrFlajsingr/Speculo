/// @file SpecializationOf.hpp
/// @brief Concept to check if T is a specialization of provided template.
/// @author PetrFlajsingr

#pragma once

#include <concepts>

namespace speculo {
    namespace details {
        template<typename T, template<typename...> typename Primary>
        struct IsSpecializationOf : std::false_type {};

        template<template<typename...> class Primary, typename... Args>
        struct IsSpecializationOf<Primary<Args...>, Primary> : std::true_type {};
    }// namespace details

    /// Query whether provided type is a direct specialization of a template.
    /// @tparam T type to query
    /// @tparam TTempl template to check against
    template<typename T, template<typename...> typename TTempl>
    concept SpecializationOf = details::IsSpecializationOf<T, TTempl>::value;

}// namespace speculo