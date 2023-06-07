/**
 * @file ReflectInfoProviders.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <meta/ID.hpp>
#include <meta/Info.hpp>
#include <meta/details/StaticInfo.hpp>

#define PF_REFLECT_TYPE(X)                                                                                                                 \
    ::pf::meta::Info { ::pf::meta::details::getTypeId<X>() }

#define PF_REFLECT_VALUE(V)                                                                                                                \
    ::pf::meta::Info { ::pf::meta::details::getConstantId<V>() }

namespace pf::meta::details {

    template<typename T>
    struct TypeReflectInfoProvider {
        constexpr static auto Result = PF_REFLECT_TYPE(T);
    };
    template<auto V>
    struct ValueReflectInfoProvider {
        constexpr static auto Result = PF_REFLECT_VALUE(V);
    };

    template<typename T>
    consteval auto provideReflectInfo() {
        return TypeReflectInfoProvider<T>{};
    }
    template<auto V>
    consteval auto provideReflectInfo() {
        return ValueReflectInfoProvider<V>{};
    }

}// namespace pf::meta::details