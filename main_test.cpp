//
// Created by xflajs00 on 08.03.2023.
//

#include "meta/fundamental_types.meta.h"
#include "test.meta.h"
#include <optional>
#include <pf_common/concepts/ranges.h>
#include <vector>

#include "meta/reflect.h"
#include "meta/template_for.h"

namespace pf::meta {
    template<Info I>
    concept Named = requires {
        { std::string_view{details::StaticInfo<I.implId>::Name} };
        { std::string_view{details::StaticInfo<I.implId>::FullName} };
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
        return I1.implId == I2.implId;
    }

}// namespace pf::meta


template<typename E>
[[nodiscard]] constexpr std::string_view to_string(E value) {
    constexpr pf::meta::Info enumInfo = PF_REFLECT(E);
    const auto result =
            pf::meta::template_for_r<pf::meta::members_of<enumInfo>()>([&]<pf::meta::Info valueInfo>() -> std::optional<std::string_view> {
                if (PF_SPLICE(valueInfo) == value) { return std::optional{pf::meta::name_of<valueInfo>()}; }
                return std::nullopt;
            });
    return result.value_or("<INVALID_ENUM_VALUE>");
}

template<typename E>
[[nodiscard]] constexpr std::optional<E> from_string(std::string_view name) {
    constexpr pf::meta::Info enumInfo = PF_REFLECT(E);
    return pf::meta::template_for_r<pf::meta::members_of<enumInfo>()>([&]<pf::meta::Info valueInfo>() -> std::optional<E> {
        if (pf::meta::name_of<valueInfo>() == name) { return PF_SPLICE(valueInfo); }
        return std::nullopt;
    });
}

template<typename E>
[[nodiscard]] constexpr pf::meta::details::RangeOf<E> auto getEnumValues() {
    constexpr pf::meta::Info enumInfo = PF_REFLECT(E);
    static_assert(pf::meta::Enum<enumInfo>);
    using impl = pf::meta::details::StaticInfo<enumInfo.implId>;

    std::array<E, impl::EnumValues.size()> result{};
    std::size_t i{};
    pf::meta::template_for<pf::meta::members_of<enumInfo>()>([&]<auto VI>() { result[i++] = PF_SPLICE(VI); });
    return result;
}

template<pf::meta::Info Type>
[[nodiscard]] constexpr std::optional<pf::meta::Info> functionByName(std::string_view name) {
    using aImpl = pf::meta::details::StaticInfo<Type.implId>;
    return pf::meta::template_for_r<aImpl::MemberFunctions>([&]<auto Fnc>() -> std::optional<pf::meta::Info> {
        using fImpl = pf::meta::details::StaticInfo<Fnc.implId>;
        if (fImpl::Name.compare(name) == 0) { return pf::meta::Info{Fnc.implId}; }
        return std::nullopt;
    });
}

template<pf::meta::Info Fnc, typename... Args>
[[nodiscard]] constexpr auto invoke(Args &&...args) {
    using aImpl = pf::meta::details::StaticInfo<Fnc.implId>;
    // only member fnc now
    constexpr auto f = aImpl::MemberPtr;
    static_assert(std::invocable<decltype(f), Args...>);
    if constexpr (!std::same_as<decltype(std::invoke(f, std::forward<Args>(args)...)), bool>) {
        return std::invoke(f, std::forward<Args>(args)...);
    } else {
        std::invoke(f, std::forward<Args>(args)...);
    }
}
template<pf::meta::Info I>
[[nodiscard]] constexpr std::string_view getFullName() {
    using aImpl = pf::meta::details::StaticInfo<I.implId>;
    return static_cast<std::string_view>(aImpl::FullName);
}

template<pf::meta::Info I>
[[nodiscard]] consteval pf::meta::details::RangeOf<pf::meta::Info> auto getConstructors() {
    using aImpl = pf::meta::details::StaticInfo<I.implId>;
    return aImpl::Constructors;
}

#include <iostream>


int main() {
    std::cout << to_string(pf::SomeEnum{0}) << std::endl;
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
        constexpr pf::meta::Info enumInfo = PF_REFLECT(pf::SomeEnum);
        using A = pf::meta::details::StaticInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        std::cout << std::hex << A::TypeID.id[0] << std::endl;
        std::cout << std::hex << A::TypeID.id[1] << std::endl;
        std::cout << std::dec;
        static_assert(!A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, pf::SomeEnum>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT(const pf::SomeEnum);
        using A = pf::meta::details::StaticInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, const pf::SomeEnum>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT(pf::SomeEnum &);
        using A = pf::meta::details::StaticInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(!A::IsConst);
        static_assert(A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, pf::SomeEnum &>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT(pf::SomeEnum &&);
        using A = pf::meta::details::StaticInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(!A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, pf::SomeEnum &&>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT(const pf::SomeEnum &);
        using A = pf::meta::details::StaticInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(A::IsConst);
        static_assert(A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, const pf::SomeEnum &>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT(pf::SomeEnum *);
        using A = pf::meta::details::StaticInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(!A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(A::IsPtr);
        static_assert(std::same_as<A::Type, pf::SomeEnum *>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT(const pf::SomeEnum *);
        using A = pf::meta::details::StaticInfo<enumInfo.implId>;
        std::cout << A::FullName << std::endl;
        static_assert(A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(A::IsPtr);
        static_assert(std::same_as<A::Type, const pf::SomeEnum *>);
    }
    constexpr pf::meta::Info enumInfo = PF_REFLECT(pf::SomeEnum *);
    using A = pf::meta::details::StaticInfo<enumInfo.implId>;

    for (const auto &attr: pf::meta::attributes_of<enumInfo>()) {
        std::cout << attr.name << std::endl;
        for (const auto &arg: attr.arguments) { std::cout << arg << std::endl; }
    }
    constexpr auto boolInfo = PF_REFLECT(bool);
    static_assert(pf::meta::reflects_same<boolInfo, boolInfo>());
    static_assert(!pf::meta::reflects_same<boolInfo, PF_REFLECT(bool *)>());
    [[maybe_unused]] PF_SPLICE(boolInfo) hihi = false;

    pf::meta::template_for<pf::meta::members_of<enumInfo>()>(
            []<auto VI>() { std::cout << pf::meta::name_of<VI>() << "=" << static_cast<int>(PF_SPLICE(VI)) << std::endl; });
    for (const auto v: getEnumValues<pf::SomeEnum>()) { std::cout << to_string(v) << "=" << static_cast<int>(v) << std::endl; }

    constexpr auto AINFO = PF_REFLECT(pf::A);

    constexpr auto ctors = getConstructors<AINFO>();

    auto dfsds = PF_SPLICE(ctors[0])(131);
    constexpr auto mbrInfo = functionByName<AINFO>("letadlo");
    if (!mbrInfo.has_value()) {
        std::cout << "Function not found" << std::endl;
        return 0;
    }
    std::cout << "Member ptr '" << getFullName<*mbrInfo>() << "' call: " << invoke<*mbrInfo>(&dfsds) << std::endl;
    std::cout << "Member ptr '" << getFullName<*mbrInfo>() << "' call: " << (dfsds.*PF_SPLICE(*mbrInfo))() << std::endl;
    dfsds.test = 100;
    std::cout << "Member ptr '" << getFullName<*mbrInfo>() << "' call: " << invoke<*mbrInfo>(&dfsds) << std::endl;

    return 0;
}