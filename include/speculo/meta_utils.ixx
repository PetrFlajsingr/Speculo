module;

#include <type_traits>

export module speculo:meta_utils;

export namespace speculo::details {

    template<typename T, template<typename...> typename Primary>
    struct IsSpecializationOf : std::false_type {};

    template<template<typename...> class Primary, typename... Args>
    struct IsSpecializationOf<Primary<Args...>, Primary> : std::true_type {};

    template<auto...>
    constexpr bool AlwaysFalseV = false;
    template<typename...>
    constexpr bool AlwaysFalseT = false;

}