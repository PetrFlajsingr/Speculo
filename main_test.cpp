//
// Created by xflajs00 on 08.03.2023.
//

#include "meta/fundamental_types.meta.hpp"
#include "meta/meta.hpp"
#include "src/meta/test.hpp"
#include "src/meta/test2.hpp"
#include <optional>
#include <vector>

#include "meta/enums.hpp"
#include "meta/reflect.hpp"
#include "meta/template_for.hpp"


template<pf::meta::Info Type>
[[nodiscard]] constexpr std::optional<pf::meta::Info> functionByName(std::string_view name) {
    using aImpl = pf::meta::details::StaticInfo<Type.id>;
    return pf::meta::template_for_r<aImpl::MemberFunctions>([&]<auto Fnc>() -> std::optional<pf::meta::Info> {
        using fImpl = pf::meta::details::StaticInfo<Fnc.id>;
        if (fImpl::Name.compare(name) == 0) { return pf::meta::Info{Fnc.id}; }
        return std::nullopt;
    });
}

template<pf::meta::Info Fnc, typename... Args>
[[nodiscard]] constexpr auto invoke(Args &&...args) {
    using aImpl = pf::meta::details::StaticInfo<Fnc.id>;
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
    using aImpl = pf::meta::details::StaticInfo<I.id>;
    return static_cast<std::string_view>(aImpl::FullName);
}

template<pf::meta::Info I>
[[nodiscard]] consteval pf::meta::details::RangeOf<pf::meta::Info> auto getConstructors() {
    using aImpl = pf::meta::details::StaticInfo<I.id>;
    return aImpl::Constructors;
}

#include <iostream>


int main() {
    std::cout << pf::meta::to_string(pf::SomeEnum{0}) << std::endl;
    std::cout << pf::meta::to_string(pf::SomeEnum::Value1) << std::endl;
    std::cout << pf::meta::to_string(pf::SomeEnum::Value2) << std::endl;

    constexpr auto a = pf::meta::from_string<pf::SomeEnum>("Value1");
    static_assert(a.has_value());
    constexpr auto b = pf::meta::from_string<pf::SomeEnum>("Value2");
    static_assert(b.has_value());
    constexpr auto c = pf::meta::from_string<pf::SomeEnum>("Value3");
    static_assert(!c.has_value());

    std::cout << pf::meta::to_string(*a) << std::endl;
    std::cout << pf::meta::to_string(*b) << std::endl;

    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT(pf::SomeEnum);
        using A = pf::meta::details::StaticInfo<enumInfo.id>;
        std::cout << A::FullName << std::endl;
        std::cout << std::hex << A::Id.id[0] << std::endl;
        std::cout << std::hex << A::Id.id[1] << std::endl;
        std::cout << std::dec;
        static_assert(!A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, pf::SomeEnum>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT(const pf::SomeEnum);
        using A = pf::meta::details::StaticInfo<enumInfo.id>;
        std::cout << A::FullName << std::endl;
        static_assert(A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, const pf::SomeEnum>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT(pf::SomeEnum &);
        using A = pf::meta::details::StaticInfo<enumInfo.id>;
        std::cout << A::FullName << std::endl;
        static_assert(!A::IsConst);
        static_assert(A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, pf::SomeEnum &>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT(pf::SomeEnum &&);
        using A = pf::meta::details::StaticInfo<enumInfo.id>;
        std::cout << A::FullName << std::endl;
        static_assert(!A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, pf::SomeEnum &&>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT(const pf::SomeEnum &);
        using A = pf::meta::details::StaticInfo<enumInfo.id>;
        std::cout << A::FullName << std::endl;
        static_assert(A::IsConst);
        static_assert(A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, const pf::SomeEnum &>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT(pf::SomeEnum *);
        using A = pf::meta::details::StaticInfo<enumInfo.id>;
        std::cout << A::FullName << std::endl;
        static_assert(!A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(A::IsPtr);
        static_assert(std::same_as<A::Type, pf::SomeEnum *>);
    }
    {
        constexpr pf::meta::Info enumInfo = PF_REFLECT(const pf::SomeEnum *);
        using A = pf::meta::details::StaticInfo<enumInfo.id>;
        std::cout << A::FullName << std::endl;
        static_assert(A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(A::IsPtr);
        static_assert(std::same_as<A::Type, const pf::SomeEnum *>);
    }
    constexpr pf::meta::Info enumInfo = PF_REFLECT(pf::SomeEnum *);
    using A = pf::meta::details::StaticInfo<enumInfo.id>;

    for (const auto &attr: pf::meta::attributes_of<enumInfo>()) {
        std::cout << attr.name << std::endl;
        for (const auto &arg: attr.arguments) { std::cout << arg << std::endl; }
    }
    constexpr auto boolInfo = PF_REFLECT(bool);
    static_assert(pf::meta::is_same<boolInfo, boolInfo>());
    static_assert(!pf::meta::is_same<boolInfo, PF_REFLECT(bool *)>());
    [[maybe_unused]] PF_SPLICE(boolInfo) hihi = false;

    pf::meta::template_for<pf::meta::members_of<enumInfo>()>(
            []<auto VI>() { std::cout << pf::meta::name_of<VI>() << "=" << static_cast<int>(PF_SPLICE(VI)) << std::endl; });
    for (const auto v: pf::meta::enumerator_values<pf::SomeEnum>()) {
        std::cout << pf::meta::to_string(v) << "=" << static_cast<int>(v) << std::endl;
    }

    constexpr auto AINFO = PF_REFLECT(pf::A);
    constexpr pf::A cA = pf::A();
    using ImplFoo = pf::meta::details::StaticInfo<pf::meta::ID{0x575fdd108108c3d9u, 0xf4b82162dd7fc096u}>;


    constexpr auto ctors = getConstructors<AINFO>();

    auto dfsds = PF_SPLICE(ctors[1])(131);
    constexpr auto mbrInfo = functionByName<AINFO>("letadlo");
    if (!mbrInfo.has_value()) {
        std::cout << "Function not found" << std::endl;
        return 0;
    }
    std::cout << "Member ptr '" << getFullName<*mbrInfo>() << "' call: " << invoke<*mbrInfo>(&dfsds) << std::endl;
    std::cout << "Member ptr '" << getFullName<*mbrInfo>() << "' call: " << (dfsds.*PF_SPLICE(*mbrInfo))() << std::endl;
    dfsds.test = 100;
    std::cout << "Member ptr '" << getFullName<*mbrInfo>() << "' call: " << invoke<*mbrInfo>(&dfsds) << std::endl;

    constexpr auto b1 = pf::meta::members_of<PF_REFLECT(SimpleStruct)>()[1];
    std::cout << pf::meta::display_name_of<b1>() << std::endl;
    SimpleStruct s{};
    auto accessor = pf::meta::create_bit_field_accessor<b1>(&s);
    std::cout << s.b1 << std::endl;
    accessor = 1;
    std::cout << s.b1 << std::endl;
    int v = accessor;
    std::cout << v << std::endl;

   // std::cout << "Generated fnc " << s.demo() << std::endl;

    return 0;
}