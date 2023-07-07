//
// Created by xflajs00 on 08.03.2023.
//

#include "speculo/fundamental_types.hpp"
#include "speculo/meta.hpp"
#include "src/meta/test.hpp"
#include "src/meta/test2.hpp"
#include <optional>
#include <vector>
#include <functional>

#include "speculo/enums.hpp"
#include "speculo/reflect.hpp"
#include "speculo/template_for.hpp"


template<speculo::Info Type>
[[nodiscard]] constexpr std::optional<speculo::Info> functionByName(std::string_view name) {
    using aImpl = speculo::details::StaticInfo<Type.id>;
    return speculo::template_for_r<aImpl::MemberFunctions>([&]<auto Fnc>() -> std::optional<speculo::Info> {
        using fImpl = speculo::details::StaticInfo<Fnc.id>;
        if (fImpl::Name.compare(name) == 0) { return speculo::Info{Fnc.id}; }
        return std::nullopt;
    });
}

template<speculo::Info Fnc, typename... Args>
[[nodiscard]] constexpr auto invoke(Args &&...args) {
    using aImpl = speculo::details::StaticInfo<Fnc.id>;
    // only member fnc now
    constexpr auto f = aImpl::MemberPtr;
    static_assert(std::invocable<decltype(f), Args...>);
    if constexpr (!std::same_as<decltype(std::invoke(f, std::forward<Args>(args)...)), bool>) {
        return std::invoke(f, std::forward<Args>(args)...);
    } else {
        std::invoke(f, std::forward<Args>(args)...);
    }
}
template<speculo::Info I>
[[nodiscard]] constexpr std::string_view getFullName() {
    using aImpl = speculo::details::StaticInfo<I.id>;
    return static_cast<std::string_view>(aImpl::FullName);
}

template<speculo::Info I>
[[nodiscard]] consteval speculo::RangeOf<speculo::Info> auto getConstructors() {
    using aImpl = speculo::details::StaticInfo<I.id>;
    return aImpl::Constructors;
}

#include <iostream>


int main() {
    std::cout << speculo::to_string(*speculo::from_underlying<speculo::SomeEnum>(0)) << std::endl;
    std::cout << speculo::to_string(speculo::SomeEnum{0}) << std::endl;
    std::cout << speculo::to_string(speculo::SomeEnum::Value1) << std::endl;
    std::cout << speculo::to_string(speculo::SomeEnum::Value2) << std::endl;

    constexpr auto a = speculo::from_string<speculo::SomeEnum>("Value1");
    static_assert(a.has_value());
    constexpr auto b = speculo::from_string<speculo::SomeEnum>("Value2");
    static_assert(b.has_value());
    constexpr auto c = speculo::from_string<speculo::SomeEnum>("Value3");
    static_assert(!c.has_value());

    std::cout << speculo::to_string(*a) << std::endl;
    std::cout << speculo::to_string(*b) << std::endl;

    {
        constexpr speculo::Info enumInfo = SPECULO_REFLECT(speculo::SomeEnum);
        using A = speculo::details::StaticInfo<enumInfo.id>;
        std::cout << A::FullName << std::endl;
        std::cout << std::hex << A::Id.id[0] << std::endl;
        std::cout << std::hex << A::Id.id[1] << std::endl;
        std::cout << std::dec;
        static_assert(!A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, speculo::SomeEnum>);
    }
    {
        constexpr speculo::Info enumInfo = SPECULO_REFLECT(const speculo::SomeEnum);
        using A = speculo::details::StaticInfo<enumInfo.id>;
        std::cout << A::FullName << std::endl;
        static_assert(A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, const speculo::SomeEnum>);
    }
    {
        constexpr speculo::Info enumInfo = SPECULO_REFLECT(speculo::SomeEnum &);
        using A = speculo::details::StaticInfo<enumInfo.id>;
        std::cout << A::FullName << std::endl;
        static_assert(!A::IsConst);
        static_assert(A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, speculo::SomeEnum &>);
    }
    {
        constexpr speculo::Info enumInfo = SPECULO_REFLECT(speculo::SomeEnum &&);
        using A = speculo::details::StaticInfo<enumInfo.id>;
        std::cout << A::FullName << std::endl;
        static_assert(!A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, speculo::SomeEnum &&>);
    }
    {
        constexpr speculo::Info enumInfo = SPECULO_REFLECT(const speculo::SomeEnum &);
        using A = speculo::details::StaticInfo<enumInfo.id>;
        std::cout << A::FullName << std::endl;
        static_assert(A::IsConst);
        static_assert(A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(!A::IsPtr);
        static_assert(std::same_as<A::Type, const speculo::SomeEnum &>);
    }
    {
        constexpr speculo::Info enumInfo = SPECULO_REFLECT(speculo::SomeEnum *);
        using A = speculo::details::StaticInfo<enumInfo.id>;
        std::cout << A::FullName << std::endl;
        static_assert(!A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(A::IsPtr);
        static_assert(std::same_as<A::Type, speculo::SomeEnum *>);
    }
    {
        constexpr speculo::Info enumInfo = SPECULO_REFLECT(const speculo::SomeEnum *);
        using A = speculo::details::StaticInfo<enumInfo.id>;
        std::cout << A::FullName << std::endl;
        static_assert(A::IsConst);
        static_assert(!A::IsLvalueReference);
        static_assert(!A::IsRvalueReference);
        static_assert(A::IsPtr);
        static_assert(std::same_as<A::Type, const speculo::SomeEnum *>);
    }
    constexpr speculo::Info enumInfo = SPECULO_REFLECT(speculo::SomeEnum *);
    using A = speculo::details::StaticInfo<enumInfo.id>;

    for (const auto &attr: speculo::attributes_of<enumInfo>()) {
        std::cout << attr.name << std::endl;
        for (const auto &arg: attr.arguments) { std::cout << arg << std::endl; }
    }
    constexpr auto boolInfo = SPECULO_REFLECT(bool);
    static_assert(speculo::is_same<boolInfo, boolInfo>());
    static_assert(!speculo::is_same<boolInfo, SPECULO_REFLECT(bool *)>());
    [[maybe_unused]] SPECULO_SPLICE(boolInfo) hihi = false;

    speculo::template_for<speculo::members_of<enumInfo>()>(
            []<auto VI>() { std::cout << speculo::name_of<VI>() << "=" << static_cast<int>(SPECULO_SPLICE(VI)) << std::endl; });
    for (const auto v: speculo::enumerator_values<speculo::SomeEnum>()) {
        std::cout << speculo::to_string(v) << "=" << static_cast<int>(v) << std::endl;
    }

    constexpr auto AINFO = SPECULO_REFLECT(speculo::A);
    constexpr speculo::A cA = SPECULO_SPLICE(AINFO)();
    using ImplFoo = speculo::details::StaticInfo<speculo::ID{0x575fdd108108c3d9u, 0xf4b82162dd7fc096u}>;


    constexpr auto ctors = getConstructors<AINFO>();

    auto dfsds = SPECULO_SPLICE(ctors[1])(131);
    constexpr auto mbrInfo = functionByName<AINFO>("letadlo");
    if (!mbrInfo.has_value()) {
        std::cout << "Function not found" << std::endl;
        return 0;
    }
    std::cout << "Member ptr '" << getFullName<*mbrInfo>() << "' call: " << invoke<*mbrInfo>(&dfsds) << std::endl;
    std::cout << "Member ptr '" << getFullName<*mbrInfo>() << "' call: " << (dfsds.*SPECULO_SPLICE(*mbrInfo))() << std::endl;
    dfsds.test = 100;
    std::cout << "Member ptr '" << getFullName<*mbrInfo>() << "' call: " << invoke<*mbrInfo>(&dfsds) << std::endl;

    constexpr auto b1 = speculo::members_of<SPECULO_REFLECT(test::SimpleStruct)>()[1];
    std::cout << speculo::display_name_of<b1>() << std::endl;
    test::SimpleStruct s{};
    auto accessor = speculo::create_bit_field_accessor<b1>(&s);
    std::cout << s.b1 << std::endl;
    accessor = 1;
    std::cout << s.b1 << std::endl;
    int v = accessor;
    std::cout << v << std::endl;

   // std::cout << "Generated fnc " << s.demo() << std::endl;


    test::Flags f1 = test::Flags::V1;
    test::Flags f2 = test::Flags::V2;

    const auto f3 = f1 + f2;
    ++f1;
    f1++;
    const auto f4 = f1 % f2;


    const auto f5 = f1 & f2;
    const auto f6 = f1 ^ f2;
    f2 ^= test::Flags{1};


    return 0;
}