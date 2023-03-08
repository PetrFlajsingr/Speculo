//
// Created by xflajs00 on 08.03.2023.
//

#include "test_meta.h"
#include <optional>
#include <pf_common/concepts/ranges.h>

namespace pf::meta {
    template<Info I>
    concept Named = requires {
        { details::StaticTypeInfo<I.implId>::Name } -> std::convertible_to<std::string_view>;
    };
    template<Info I>
    concept Enum = details::StaticTypeInfo<I.implId>::IsEnum;

    template<Info I>
        requires(Enum<I>)
    [[nodiscard]] consteval RangeOf<Info> auto members_of() {
        using impl = details::StaticTypeInfo<I.implId>;
        static_assert(impl::IsEnum);
        return impl::EnumValues;
    }

    template<Info I>
        requires(Named<I>)
    [[nodiscard]] consteval std::string_view name_of() {
        using impl = details::StaticTypeInfo<I.implId>;
        return impl::Name;
    }

}// namespace pf::meta

template<typename E>
[[nodiscard]] constexpr std::string to_string(E value) {
    constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(E);
    std::string result{};
    pf::meta::template_for<pf::meta::members_of<enumInfo>()>([&]<pf::meta::Info valueInfo>() {
        if (PF_SPLICE_VALUE(valueInfo) == value) { result = std::string{pf::meta::name_of<valueInfo>()}; }
    });
    if (result.empty()) { result = "<INVALID_ENUM_VALUE>"; }
    return result;
}

template<typename E>
[[nodiscard]] constexpr std::optional<E> from_string(std::string_view name) {
    constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(E);
    std::optional<E> result = std::nullopt;
    pf::meta::template_for<pf::meta::members_of<enumInfo>()>([&]<pf::meta::Info valueInfo>() {
        if (pf::meta::name_of<valueInfo>() == name) { result = PF_SPLICE_VALUE(valueInfo); }
    });
    return result;
}

#include <iostream>



int main() {
    /* std::cout << to_string(pf::SomeEnum::Value1) << std::endl;
    std::cout << to_string(pf::SomeEnum::Value2) << std::endl;

    constexpr auto a = from_string<pf::SomeEnum>("Value1");
    static_assert(a.has_value());
    constexpr auto b = from_string<pf::SomeEnum>("Value2");
    static_assert(b.has_value());
    constexpr auto c = from_string<pf::SomeEnum>("Value3");
    static_assert(!c.has_value());

    std::cout << to_string(*a) << std::endl;
    std::cout << to_string(*b) << std::endl;*/

    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(pf::SomeEnum);
        using A = pf::meta::details::StaticTypeInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(!A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, pf::SomeEnum>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(const pf::SomeEnum);
        using A = pf::meta::details::StaticTypeInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, const pf::SomeEnum>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(pf::SomeEnum &);
        using A = pf::meta::details::StaticTypeInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(!A::IsConst);
        static_assert(A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, pf::SomeEnum &>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(pf::SomeEnum &&);
        using A = pf::meta::details::StaticTypeInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(!A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, pf::SomeEnum &&>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(const pf::SomeEnum &);
        using A = pf::meta::details::StaticTypeInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(A::IsConst);
        static_assert(A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, const pf::SomeEnum &>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(pf::SomeEnum *);
        using A = pf::meta::details::StaticTypeInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(!A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(A::IsPtr);
        static_assert(std::same_as<A::Type, pf::SomeEnum *>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(const pf::SomeEnum *);
        using A = pf::meta::details::StaticTypeInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(A::IsPtr);
        static_assert(std::same_as<A::Type, const pf::SomeEnum *>);
    }

    return 0;
}