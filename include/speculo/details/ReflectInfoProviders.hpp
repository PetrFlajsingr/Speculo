/**
 * @file ReflectInfoProviders.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <speculo/ID.hpp>
#include <speculo/Info.hpp>
#include <speculo/details/StaticInfo.hpp>

#define SPECULO_REFLECT_TYPE(X)                                                                                                                 \
    ::speculo::Info { ::speculo::details::getTypeId<X>() }

#define SPECULO_REFLECT_VALUE(V)                                                                                                                \
    ::speculo::Info { ::speculo::details::getConstantId<V>() }

namespace speculo::details {

    template<typename T>
    struct TypeReflectInfoProvider {
        constexpr static auto Result = SPECULO_REFLECT_TYPE(T);
    };
    template<auto V>
    struct ValueReflectInfoProvider {
        constexpr static auto Result = SPECULO_REFLECT_VALUE(V);
    };

    template<typename T>
    consteval auto provideReflectInfo() {
        return TypeReflectInfoProvider<T>{};
    }
    template<auto V>
    consteval auto provideReflectInfo() {
        return ValueReflectInfoProvider<V>{};
    }

}// namespace speculo::details