//
// Created by xflajs00 on 08.03.2023.
//

#ifndef PF_META_COMMON_H
#define PF_META_COMMON_H

#include <array>
#include <cstddef>
#include <pf_common/containers/StringLiteral.h>
#include <string_view>

#if !defined(PF_META_MAX_ATTRIBUTE_ARG_COUNT)
#define PF_META_MAX_ATTRIBUTE_ARG_COUNT 10
#endif

#define PF_REFLECT_TYPE(X)                                                                                                                 \
    ::pf::meta::Info { ::pf::meta::details::getTypeId<X>() }

#define PF_REFLECT_VALUE(V)                                                                                                                \
    ::pf::meta::Info { ::pf::meta::details::getConstantId<V>() }

#define PF_SPLICE_TYPE(I) ::pf::meta::details::StaticInfo<I.implId>::Type

#define PF_SPLICE_VALUE(I)                                                                                                                 \
    []<::pf::meta::Info i>() consteval {                                                                                                   \
        using impl = ::pf::meta::details::StaticInfo<i.implId>;                                                                        \
        return impl::Value;                                                                                                                \
    }.template operator()<I>()

namespace pf::meta {

    template<typename T, std::size_t N>
        requires std::is_default_constructible_v<T>
    class StaticVector {
    public:
        using Storage = std::array<T, N>;
        using value_type = typename Storage::value_type;
        using pointer = typename Storage::pointer;
        using const_pointer = typename Storage::const_pointer;
        using reference = typename Storage::reference;
        using const_reference = typename Storage::const_reference;
        using iterator = typename Storage::iterator;
        using const_iterator = typename Storage::const_iterator;
        using reverse_iterator = typename Storage::reverse_iterator;
        using const_reverse_iterator = typename Storage::const_reverse_iterator;
        using size_type = typename Storage::size_type;
        using difference_type = typename Storage::difference_type;

        constexpr StaticVector() = default;
        constexpr StaticVector(const StaticVector &) = default;
        constexpr StaticVector &operator=(const StaticVector &) = default;
        constexpr StaticVector(StaticVector &&) noexcept = default;
        constexpr StaticVector &operator=(StaticVector &&) noexcept = default;

        constexpr StaticVector(std::initializer_list<T> iList) : cnt{iList.size()} {
            auto iter = iList.begin();
            for (std::size_t i = 0; i < iList.size(); ++i) {
                storage.data()[i] = *iter;
                ++iter;
            }
        }

        [[nodiscard]] constexpr bool empty() const noexcept { return cnt == 0; }
        [[nodiscard]] constexpr size_type size() const noexcept { return cnt; }
        [[nodiscard]] constexpr iterator begin() noexcept { return storage.begin(); }
        [[nodiscard]] constexpr iterator end() noexcept { return storage.begin() + cnt; }
        [[nodiscard]] constexpr const_iterator begin() const noexcept { return storage.begin(); }
        [[nodiscard]] constexpr const_iterator end() const noexcept { return storage.begin() + cnt; }
        [[nodiscard]] constexpr const_iterator cbegin() const noexcept { return storage.cbegin(); }
        [[nodiscard]] constexpr const_iterator cend() const noexcept { return storage.cbegin() + cnt; }
        [[nodiscard]] constexpr reverse_iterator rbegin() noexcept { return storage.rbegin(); }
        [[nodiscard]] constexpr reverse_iterator rend() noexcept { return storage.rbegin() + cnt; }
        [[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept { return storage.rbegin(); }
        [[nodiscard]] constexpr const_reverse_iterator rend() const noexcept { return storage.rbegin() + cnt; }
        [[nodiscard]] constexpr const_reverse_iterator rcbegin() const noexcept { return storage.rcbegin(); }
        [[nodiscard]] constexpr const_reverse_iterator rcend() const noexcept { return storage.rcbegin() + cnt; }
        [[nodiscard]] constexpr reference operator[](size_type index) noexcept { return storage[index]; }
        [[nodiscard]] constexpr const_reference operator[](size_type index) const noexcept { return storage[index]; }
        [[nodiscard]] constexpr reference front() noexcept { return storage.front(); }
        [[nodiscard]] constexpr reference back() noexcept { return *(end() - 1); }
        [[nodiscard]] constexpr value_type front() const noexcept { return storage.front(); }
        [[nodiscard]] constexpr value_type back() const noexcept { return *(end() - 1); }
        [[nodiscard]] constexpr pointer data() noexcept { return storage.data(); }
        [[nodiscard]] constexpr const_pointer data() const noexcept { return storage.data(); }

    private:
        Storage storage{};
        std::size_t cnt{};
    };

    struct ID {
        constexpr ID() : ID{0x0u, 0x0u} {}
        constexpr explicit ID(const std::array<std::uint64_t, 2> &data) : id{data} {}

        constexpr ID(std::uint64_t w1, std::uint64_t w2) : id{w1, w2} {}

        [[nodiscard]] constexpr bool isValid() const { return id[0] == 0x0u && id[1] == 0x0u; }
        [[nodiscard]] constexpr bool operator==(const ID &other) const noexcept = default;
        std::array<std::uint64_t, 2> id;
    };

    namespace details {
        template<auto...>
        constexpr bool AlwaysFalseV = false;
        template<typename...>
        constexpr bool AlwaysFalseT = false;

        template<ID ID>
        struct StaticInfo {
            static_assert(AlwaysFalseV<ID>, "Static reflection not generated for type");
        };

        template<::pf::meta::ID I, ::pf::meta::ID ParentID>
        struct StaticInfo_ConstWrap : ::pf::meta::details::StaticInfo<ParentID> {
            using Type = const typename ::pf::meta::details::StaticInfo<ParentID>::Type;
            constexpr static ID TypeID = I;
            constexpr static bool IsConst = true;
            constexpr static auto Name = StringLiteral{"const "} + ::pf::meta::details::StaticInfo<ParentID>::Name;
            constexpr static auto FullName = StringLiteral{"const "} + ::pf::meta::details::StaticInfo<ParentID>::FullName;
        };
        template<::pf::meta::ID I, ::pf::meta::ID ParentID>
        struct StaticInfo_LRefWrap : ::pf::meta::details::StaticInfo<ParentID> {
            using Type = typename ::pf::meta::details::StaticInfo<ParentID>::Type &;
            constexpr static ID TypeID = I;
            constexpr static bool IsLvalueReference = true;
            constexpr static auto Name = ::pf::meta::details::StaticInfo<ParentID>::Name + StringLiteral{"&"};
            constexpr static auto FullName = ::pf::meta::details::StaticInfo<ParentID>::FullName + StringLiteral{"&"};
        };
        template<::pf::meta::ID I, ::pf::meta::ID ParentID>
        struct StaticInfo_RRefWrap : ::pf::meta::details::StaticInfo<ParentID> {
            using Type = typename ::pf::meta::details::StaticInfo<ParentID>::Type &&;
            constexpr static ID TypeID = I;
            constexpr static bool IsRvalueReference = true;
            constexpr static auto Name = ::pf::meta::details::StaticInfo<ParentID>::Name + StringLiteral{"&&"};
            constexpr static auto FullName = ::pf::meta::details::StaticInfo<ParentID>::FullName + StringLiteral{"&&"};
        };
        template<::pf::meta::ID I, ::pf::meta::ID ParentID>
        struct StaticInfo_PtrWrap : ::pf::meta::details::StaticInfo<ParentID> {
            using Type = typename ::pf::meta::details::StaticInfo<ParentID>::Type *;
            constexpr static ID TypeID = I;
            constexpr static bool IsPtr = true;
            constexpr static auto Name = ::pf::meta::details::StaticInfo<ParentID>::Name + StringLiteral{"*"};
            constexpr static auto FullName = ::pf::meta::details::StaticInfo<ParentID>::FullName + StringLiteral{"*"};
        };
        template<typename T>
        [[nodiscard]] consteval ID getTypeId() {
            static_assert(AlwaysFalseT<T>, "Static reflection not generated for type");
            return {};
        }
        template<auto V>
        [[nodiscard]] consteval ID getConstantId() {
            static_assert(AlwaysFalseV<V>, "Static reflection not generated for value");
            return {};
        }

        template<auto V, std::size_t I, typename F>
        constexpr void template_for_impl(F &&f) {
            if constexpr (I == V.size()) {
                return;
            } else {
                f.template operator()<V[I]>();
                template_for_impl<V, I + 1, F>(std::forward<F>(f));
            }
        }
    }// namespace details

    struct Info {
        constexpr explicit(false) Info(ID id) : implId{id} {}
        ID implId;
    };

    struct Attribute {
        constexpr Attribute(std::string_view n, StaticVector<std::string_view, PF_META_MAX_ATTRIBUTE_ARG_COUNT> args)
            : name{n}, arguments{args} {}
        std::string_view name;
        StaticVector<std::string_view, PF_META_MAX_ATTRIBUTE_ARG_COUNT> arguments;
    };

    template<auto R, typename F>
    constexpr void template_for(F &&f) {
        details::template_for_impl<R, 0>(std::forward<F>(f));
    }

}// namespace pf::meta

#endif//PF_META_COMMON_H
