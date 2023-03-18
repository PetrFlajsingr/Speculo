//
// Created by xflajs00 on 08.03.2023.
//

#include "test.meta.h"
#include "meta/fundamental_types.meta.h"
#include <optional>
#include <vector>
#include <pf_common/concepts/ranges.h>

#include "meta/reflect.h"
#include "meta/template_for.h"

namespace pf::meta {
    template<Info I>
    concept Named = requires {
        { std::string_view{details::StaticInfo<I.implId>::Name}};
        { std::string_view{details::StaticInfo<I.implId>::FullName}};
    };
    template<Info I>
    concept Enum = details::StaticInfo<I.implId>::StaticInfoObjectType == details::StaticInfoType::EnumType;

    template<Info I>
    requires(Enum<I>)
    [[nodiscard]] consteval RangeOf<Info> auto members_of() {
        using impl = details::StaticInfo<I.implId>;
        return impl::EnumValues;
    }

    template<Info I>
    requires(Named<I>)
    [[nodiscard]] consteval std::string_view name_of() {
        using impl = details::StaticInfo<I.implId>;
        return static_cast<std::string_view>(impl::Name);
    }

    template<Info I>
    [[nodiscard]] consteval std::span<const Attribute> attributes_of() {
        using impl = details::StaticInfo<I.implId>;
        if constexpr (requires {
            { impl::Attributes } -> RangeOf<Attribute>;
        }) {
            return std::span<const Attribute>(impl::Attributes);
        } else {
            return std::span<const Attribute>{};
        }
    }

    template<Info I1, Info I2>
    [[nodiscard]] consteval bool reflects_same() {
        using impl1 = details::StaticInfo<I1.implId>;
        using impl2 = details::StaticInfo<I2.implId>;
        return std::same_as<typename impl1::Type, typename impl2::Type>;
    }

}// namespace pf::meta


template<typename E>
[[nodiscard]] constexpr std::string_view to_string(E value) {
    constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(E);
    std::string_view result{};
    pf::meta::template_for<pf::meta::members_of<enumInfo>()>([&]<pf::meta::Info valueInfo>() {
        if (PF_SPLICE_VALUE(valueInfo) == value) { result = pf::meta::name_of<valueInfo>(); }
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

template<typename E>
[[nodiscard]] constexpr std::vector<E> getEnumValues() {
    constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(E);
    std::vector<E> result;
    result.reserve(std::ranges::size(pf::meta::members_of<enumInfo>()));
    pf::meta::template_for<pf::meta::members_of<enumInfo>()>([&]<auto VI>() {
        result.emplace_back(PF_SPLICE_VALUE(VI));
    });
    return result;
}

#include <iostream>


int main() {
    std::cout << to_string(pf::SomeEnum::Value1) << std::endl;
    std::cout << to_string(pf::SomeEnum::Value2) << std::endl;

    constexpr auto a = from_string<pf::SomeEnum>("Value1");
    static_assert(a.has_value());
    constexpr auto b = from_string<pf::SomeEnum>("Value2");
    static_assert(b.has_value());
    constexpr auto c = from_string<pf::SomeEnum>("Value3");
    static_assert(!c.has_value());

    std::cout << to_string(*a) << std::endl;
    std::cout << to_string(*b) << std::endl;

    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(pf::SomeEnum);
        using A = pf::meta::details::StaticInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        std::cout << std::hex << A::TypeID.id[0] << std::endl;
        std::cout << std::hex << A::TypeID.id[1] << std::endl;
        static_assert(!A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, pf::SomeEnum>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(const pf::SomeEnum);
        using A = pf::meta::details::StaticInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, const pf::SomeEnum>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(pf::SomeEnum &);
        using A = pf::meta::details::StaticInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(!A::IsConst);
        static_assert(A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, pf::SomeEnum &>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(pf::SomeEnum &&);
        using A = pf::meta::details::StaticInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(!A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, pf::SomeEnum &&>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(const pf::SomeEnum &);
        using A = pf::meta::details::StaticInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(A::IsConst);
        static_assert(A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, const pf::SomeEnum &>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(pf::SomeEnum *);
        using A = pf::meta::details::StaticInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(!A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(A::IsPtr);
        static_assert(std::same_as<A::Type, pf::SomeEnum *>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(const pf::SomeEnum *);
        using A = pf::meta::details::StaticInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(A::IsPtr);
        static_assert(std::same_as<A::Type, const pf::SomeEnum *>);
    }
    constexpr pf::meta::Info enumInfo = PF_REFLECT_TYPE(pf::SomeEnum *);
    using A = pf::meta::details::StaticInfo<enumInfo.implId>;

    for (const auto &attr: pf::meta::attributes_of<enumInfo>()) {
        std::cout << attr.name << std::endl;
        for (const auto &arg: attr.arguments) { std::cout << arg << std::endl; }
    }
    constexpr auto boolInfo = PF_REFLECT_TYPE(bool);
    static_assert(pf::meta::reflects_same<boolInfo, boolInfo>());
    static_assert(!pf::meta::reflects_same<boolInfo, PF_REFLECT_TYPE(bool*)>());
    [[maybe_unused]] PF_SPLICE_TYPE(boolInfo) hihi = false;

    pf::meta::template_for<pf::meta::members_of<enumInfo>()>([]<auto VI>() {
        std::cout << pf::meta::name_of<VI>() << "=" << static_cast<int>(PF_SPLICE_VALUE(VI)) << std::endl;
    });
    for (const auto v : getEnumValues<pf::SomeEnum>()) {
        std::cout << to_string(v) << "=" << static_cast<int>(v) << std::endl;
    }
    return 0;
}