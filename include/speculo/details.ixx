module;

#include <array>
#include <concepts>
#include <optional>
#include <ranges>
#include <utility>

export module speculo:details;
import :string_literal;
import :info;
import :meta_utils;

export namespace speculo {
    template<typename T, std::convertible_to<T>... Args>
    [[nodiscard]] constexpr std::array<T, sizeof...(Args)> make_array(Args &&...args) {
        return {std::forward<Args>(args)...};
    }

    template<typename T, typename... TOthers>
    concept OneOf = (std::same_as<T, TOthers> || ...);


    template<typename R, typename ElementType>
    concept RangeOf = std::ranges::range<R> && std::same_as<std::ranges::range_value_t<R>, ElementType>;

    namespace details {
        template<typename T>
        struct TypeReflectInfoProvider {
            constexpr static auto Result = Info{::speculo::details::getTypeId<T>()};
        };
        template<auto V>
        struct ValueReflectInfoProvider {
            constexpr static auto Result = Info{getConstantId<V>()};
        };

        enum class StaticInfoType {
            EnumType,
            EnumValue,
            RecordType,
            Base,
            Constructor,
            Destructor,
            MemberFunction,
            MemberVariable,
            StaticFunction,
            StaticVariable,
            Argument,
            FundamentalType
        };

        template<ID ID>
        struct StaticInfo {
            static_assert(AlwaysFalseV<ID>, "Static reflection not generated for type or the required meta file was not included");
        };

        constexpr std::array<std::string_view, 0> EmptyAttributeArgArray{};

        template<typename T>
        consteval auto provideReflectInfo() {
            return TypeReflectInfoProvider<T>{};
        }
        template<auto V>
        consteval auto provideReflectInfo() {
            return ValueReflectInfoProvider<V>{};
        }

        template<Info I>
        using splice_type = typename StaticInfo<I.id>::Type;

        template<Info I>
        consteval auto splice_value() {
            return StaticInfo<I.id>::Value;
        }

        template<Info I>
        consteval auto splice_member() {
            return StaticInfo<I.id>::MemberPtr;
        }

        template<Info I>
        consteval auto splice_ctor() {
            return StaticInfo<I.id>::CtorWrap;
        }

        template<Info I>
        consteval speculo::details::StaticInfoType getInfoType() {
            return speculo::details::StaticInfo<I.id>::StaticInfoObjectType;
        }

        template<Info I>
        struct SpliceResultProvider {
            static_assert(AlwaysFalseV<I>, "Not implemented or splice not supported for this meta type");
        };

        template<Info I>
            requires(getInfoType<I>() == speculo::details::StaticInfoType::EnumValue)
        struct SpliceResultProvider<I> {
            constexpr static auto Result = splice_value<I>();
        };
        template<Info I>
            requires(getInfoType<I>() == speculo::details::StaticInfoType::EnumType ||
                     getInfoType<I>() == speculo::details::StaticInfoType::FundamentalType ||
                     getInfoType<I>() == speculo::details::StaticInfoType::RecordType)
        struct SpliceResultProvider<I> {
            using Result = splice_type<I>;
        };

        template<Info I>
            requires(getInfoType<I>() == speculo::details::StaticInfoType::MemberFunction ||
                     getInfoType<I>() == speculo::details::StaticInfoType::MemberVariable ||
                     getInfoType<I>() == speculo::details::StaticInfoType::StaticFunction ||
                     getInfoType<I>() == speculo::details::StaticInfoType::StaticVariable)
        struct SpliceResultProvider<I> {
            constexpr static auto Result = splice_member<I>();
        };

        template<Info I>
            requires(getInfoType<I>() == speculo::details::StaticInfoType::Constructor)
        struct SpliceResultProvider<I> {
            constexpr static auto Result = splice_ctor<I>();
        };


        // const T
        template<ID I, ID ParentID>
        struct StaticInfo_ConstWrap : details::StaticInfo<ParentID> {
            using Type = const typename details::StaticInfo<ParentID>::Type;
            constexpr static ID TypeID = I;
            constexpr static bool IsConst = true;
            constexpr static auto Name = StringLiteral{"const "} + details::StaticInfo<ParentID>::Name;
            constexpr static auto FullName = StringLiteral{"const "} + details::StaticInfo<ParentID>::FullName;
        };
        // T&
        template<ID I, ID ParentID>
        struct StaticInfo_LRefWrap : details::StaticInfo<ParentID> {
            using Type = typename details::StaticInfo<ParentID>::Type &;
            constexpr static ID TypeID = I;
            constexpr static bool IsLvalueReference = true;
            constexpr static auto Name = details::StaticInfo<ParentID>::Name + StringLiteral{" &"};
            constexpr static auto FullName = details::StaticInfo<ParentID>::FullName + StringLiteral{" &"};
        };
        // const T&
        template<ID I, ID ParentID>
        struct StaticInfo_ConstLRefWrap : details::StaticInfo<ParentID> {
            using Type = const typename details::StaticInfo<ParentID>::Type &;
            constexpr static ID TypeID = I;
            constexpr static bool IsLvalueReference = true;
            constexpr static bool IsConst = true;
            constexpr static auto Name = StringLiteral{"const "} + details::StaticInfo<ParentID>::Name + StringLiteral{" &"};
            constexpr static auto FullName = StringLiteral{"const "} + details::StaticInfo<ParentID>::FullName + StringLiteral{" &"};
        };
        // T &&
        template<ID I, ID ParentID>
        struct StaticInfo_RRefWrap : details::StaticInfo<ParentID> {
            using Type = typename details::StaticInfo<ParentID>::Type &&;
            constexpr static ID TypeID = I;
            constexpr static bool IsRvalueReference = true;
            constexpr static auto Name = details::StaticInfo<ParentID>::Name + StringLiteral{" &&"};
            constexpr static auto FullName = details::StaticInfo<ParentID>::FullName + StringLiteral{" &&"};
        };
        // T *
        template<ID I, ID ParentID>
        struct StaticInfo_PtrWrap : details::StaticInfo<ParentID> {
            using Type = typename details::StaticInfo<ParentID>::Type *;
            constexpr static ID TypeID = I;
            constexpr static bool IsPtr = true;
            constexpr static auto Name = details::StaticInfo<ParentID>::Name + StringLiteral{" *"};
            constexpr static auto FullName = details::StaticInfo<ParentID>::FullName + StringLiteral{" *"};
        };
        // const T *
        template<ID I, ID ParentID>
        struct StaticInfo_ConstPtrWrap : details::StaticInfo<ParentID> {
            using Type = const typename details::StaticInfo<ParentID>::Type *;
            constexpr static ID TypeID = I;
            constexpr static bool IsPtr = true;
            constexpr static bool IsConst = true;
            constexpr static auto Name = StringLiteral{"const "} + details::StaticInfo<ParentID>::Name + StringLiteral{" *"};
            constexpr static auto FullName = StringLiteral{"const "} + details::StaticInfo<ParentID>::FullName + StringLiteral{" *"};
        };
        // volatile T
        template<ID I, ID ParentID>
        struct StaticInfo_VolatileWrap : details::StaticInfo<ParentID> {
            using Type = volatile typename details::StaticInfo<ParentID>::Type;
            constexpr static ID TypeID = I;
            constexpr static bool IsVolatile = true;
            constexpr static auto Name = StringLiteral{"volatile "} + details::StaticInfo<ParentID>::Name;
            constexpr static auto FullName = StringLiteral{"volatile "} + details::StaticInfo<ParentID>::FullName;
        };
        // volatile const T
        template<ID I, ID ParentID>
        struct StaticInfo_VolatileConstWrap : details::StaticInfo<ParentID> {
            using Type = const typename details::StaticInfo<ParentID>::Type;
            constexpr static ID TypeID = I;
            constexpr static bool IsConst = true;
            constexpr static bool IsVolatile = true;
            constexpr static auto Name = StringLiteral{"volatile const "} + details::StaticInfo<ParentID>::Name;
            constexpr static auto FullName = StringLiteral{"volatile const "} + details::StaticInfo<ParentID>::FullName;
        };
        // volatile T&
        template<ID I, ID ParentID>
        struct StaticInfo_VolatileLRefWrap : details::StaticInfo<ParentID> {
            using Type = typename details::StaticInfo<ParentID>::Type &;
            constexpr static ID TypeID = I;
            constexpr static bool IsLvalueReference = true;
            constexpr static bool IsVolatile = true;
            constexpr static auto Name = StringLiteral{"volatile "} + details::StaticInfo<ParentID>::Name + StringLiteral{" &"};
            constexpr static auto FullName = StringLiteral{"volatile "} + details::StaticInfo<ParentID>::FullName + StringLiteral{" &"};
        };
        // volatile const T&
        template<ID I, ID ParentID>
        struct StaticInfo_VolatileConstLRefWrap : details::StaticInfo<ParentID> {
            using Type = const typename details::StaticInfo<ParentID>::Type &;
            constexpr static ID TypeID = I;
            constexpr static bool IsLvalueReference = true;
            constexpr static bool IsConst = true;
            constexpr static bool IsVolatile = true;
            constexpr static auto Name = StringLiteral{"volatile const "} + details::StaticInfo<ParentID>::Name + StringLiteral{" &"};
            constexpr static auto FullName =
                    StringLiteral{"volatile const "} + details::StaticInfo<ParentID>::FullName + StringLiteral{" &"};
        };
        // volatile T &&
        template<ID I, ID ParentID>
        struct StaticInfo_VolatileRRefWrap : details::StaticInfo<ParentID> {
            using Type = typename details::StaticInfo<ParentID>::Type &&;
            constexpr static ID TypeID = I;
            constexpr static bool IsRvalueReference = true;
            constexpr static bool IsVolatile = true;
            constexpr static auto Name = StringLiteral{"volatile "} + details::StaticInfo<ParentID>::Name + StringLiteral{" &&"};
            constexpr static auto FullName = StringLiteral{"volatile "} + details::StaticInfo<ParentID>::FullName + StringLiteral{" &&"};
        };
        // volatile T *
        template<ID I, ID ParentID>
        struct StaticInfo_VolatilePtrWrap : details::StaticInfo<ParentID> {
            using Type = typename details::StaticInfo<ParentID>::Type *;
            constexpr static ID TypeID = I;
            constexpr static bool IsPtr = true;
            constexpr static bool IsVolatile = true;
            constexpr static auto Name = StringLiteral{"volatile "} + details::StaticInfo<ParentID>::Name + StringLiteral{" *"};
            constexpr static auto FullName = StringLiteral{"volatile "} + details::StaticInfo<ParentID>::FullName + StringLiteral{" *"};
        };
        // volatile const T *
        template<ID I, ID ParentID>
        struct StaticInfo_VolatileConstPtrWrap : details::StaticInfo<ParentID> {
            using Type = const typename details::StaticInfo<ParentID>::Type *;
            constexpr static ID TypeID = I;
            constexpr static bool IsPtr = true;
            constexpr static bool IsConst = true;
            constexpr static bool IsVolatile = true;
            constexpr static auto Name = StringLiteral{"volatile const "} + details::StaticInfo<ParentID>::Name + StringLiteral{" *"};
            constexpr static auto FullName =
                    StringLiteral{"volatile const "} + details::StaticInfo<ParentID>::FullName + StringLiteral{" *"};
        };

        template<auto V, typename F, std::size_t... Is>
        constexpr void template_for_impl(F &&f, std::index_sequence<Is...>) {
            (f.template operator()<V[Is]>(), ...);
        }

        template<auto V, typename Result, typename F, std::size_t... Is>
        constexpr auto template_for_impl_r(F &&f, std::index_sequence<Is...>) -> Result {
            Result res;
            [[maybe_unused]] const auto _ = (((res = f.template operator()<V[Is]>()).has_value()) || ...);
            return res;
        }

    }// namespace details


    /// Query whether provided type is a direct specialization of a template.
    /// @tparam T type to query
    /// @tparam TTempl template to check against
    template<typename T, template<typename...> typename TTempl>
    concept SpecializationOf = details::IsSpecializationOf<T, TTempl>::value;

}// namespace speculo
