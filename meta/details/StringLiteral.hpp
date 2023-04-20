/**
 * @file StringLiteral.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <array>
#include <cstddef>
#include <string_view>

namespace pf {
    /**
 * @brief Constexpr friendly fixed string.
 * @tparam N Size of the string
 */
    template<typename TChar, std::size_t N, typename CharTraits = std::char_traits<TChar>>
    class BasicStringLiteral {
    public:
        using storage = std::array<TChar, N + 1>;
        using traits_type = CharTraits;
        using value_type = TChar;
        using pointer = value_type *;
        using const_pointer = const value_type *;
        using reference = value_type &;
        using const_reference = const value_type &;
        using iterator = typename storage::iterator;
        using const_iterator = typename storage::const_iterator;
        using reverse_iterator = typename storage::reverse_iterator;
        using const_reverse_iterator = typename storage::const_reverse_iterator;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using string_view_type = std::basic_string_view<value_type, traits_type>;
        constexpr static auto npos = string_view_type::npos;

        constexpr BasicStringLiteral() noexcept = default;
        explicit constexpr BasicStringLiteral(const TChar (&arr)[N + 1]) noexcept { traits_type::copy(str.data(), arr, N + 1); }
        explicit constexpr BasicStringLiteral(string_view_type src) noexcept {
            traits_type::copy(str.data(), src.data(), N);
            traits_type::assign(str.back(), TChar{'\0'});
        }

        [[nodiscard]] explicit constexpr operator string_view_type() const noexcept { return string_view_type{data(), size()}; }

        template<size_type N2>
        [[nodiscard]] constexpr BasicStringLiteral<value_type, N + N2, traits_type>
        append(const BasicStringLiteral<value_type, N2, traits_type> &str2) const noexcept {
            auto result = BasicStringLiteral<value_type, N + N2, traits_type>{};
            for (size_type i = 0; i < N; ++i) { traits_type::assign(result.data()[i], str[i]); }
            for (size_type i = 0; i < N2; ++i) { traits_type::assign(result.data()[N + i], str2.data()[i]); }
            traits_type::assign(result.data()[N + N2], TChar{'\0'});
            return result;
        }

        template<size_type N2>
        [[nodiscard]] constexpr BasicStringLiteral<value_type, N + N2 - 1, traits_type> append(TChar const (&arr)[N2]) const noexcept {
            auto result = BasicStringLiteral<value_type, N + N2 - 1, traits_type>{};
            for (size_type i = 0; i < N; ++i) { traits_type::assign(result.data()[i], data()[i]); }
            for (size_type i = 0; i < N2; ++i) { traits_type::assign(result.data()[N + i], arr[i]); }
            return result;
        }

        [[nodiscard]] constexpr int compare(string_view_type other) const noexcept { return static_cast<string_view_type>(*this).compare(other); }

        template<size_type N2>
        [[nodiscard]] constexpr BasicStringLiteral<TChar, N + N2 - 1, traits_type> insert(size_type index,
                                                                                          TChar const (&arr)[N2]) const noexcept {
            BasicStringLiteral<TChar, N + N2 - 1, traits_type> result{};
            for (size_type i = 0; i < index; ++i) { traits_type::assign(result.data()[i], data()[i]); }
            for (size_type i = index; i < index + N2 - 1; ++i) { traits_type::assign(result.data()[i], arr[i]); }
            for (size_type i = index; i < N; ++i) { traits_type::assign(result.data()[i + N2 - 1], data()[i]); }
            traits_type::assign(result.data()[N + N2 - 1], TChar{'\0'});
            return result;
        }
        template<size_type N2>
        [[nodiscard]] constexpr BasicStringLiteral<TChar, N + N2, traits_type>
        insert(size_type index, const BasicStringLiteral<TChar, N2, traits_type> &other) const noexcept {
            BasicStringLiteral<TChar, N + N2, traits_type> result{};
            for (size_type i = 0; i < index; ++i) { traits_type::assign(result.data()[i], data()[i]); }
            for (size_type i = index; i < index + N2; ++i) { traits_type::assign(result.data()[i], other.data()[i]); }
            for (size_type i = index; i < N; ++i) { traits_type::assign(result.data()[i + N2], data()[i]); }
            traits_type::assign(result.data()[N + N2], TChar{'\0'});
            return result;
        }

        [[nodiscard]] constexpr BasicStringLiteral<TChar, N + 1, traits_type> push_back(TChar ch) const noexcept {
            BasicStringLiteral<TChar, N + 1, traits_type> result;
            traits_type::copy(result.data(), data(), N);
            traits_type::assign(result.data()[N], ch);
            traits_type::assign(result.data()[N + 1], TChar{'\0'});
            return result;
        }
        [[nodiscard]] constexpr BasicStringLiteral<TChar, N - 1, traits_type> pop_back() const noexcept
            requires(N != 0)
        {
            BasicStringLiteral<TChar, N - 1, traits_type> result{};
            traits_type::copy(result.data(), data(), N - 1);
            traits_type::assign(result.data()[N - 1], TChar{'\0'});
            return result;
        }

        [[nodiscard]] constexpr bool starts_with(TChar ch) const noexcept { return static_cast<string_view_type>(*this).starts_with(ch); }
        [[nodiscard]] constexpr bool starts_with(string_view_type sv) const noexcept {
            return static_cast<string_view_type>(*this).starts_with(sv);
        }

        [[nodiscard]] constexpr bool ends_with(TChar ch) const noexcept { return static_cast<string_view_type>(*this).ends_with(ch); }
        [[nodiscard]] constexpr bool ends_with(string_view_type sv) const noexcept { return static_cast<string_view_type>(*this).ends_with(sv); }

        [[nodiscard]] constexpr bool contains(TChar ch) const noexcept { return find(ch) != npos; }
        [[nodiscard]] constexpr bool contains(string_view_type sv) const noexcept { return find(sv) != npos; }

        [[nodiscard]] constexpr size_type find(TChar ch, size_type pos = 0) const noexcept {
            return static_cast<string_view_type>(*this).find(ch, pos);
        }
        template<size_type N2>
        [[nodiscard]] constexpr size_type find(string_view_type sv, size_type pos = 0) const noexcept {
            return static_cast<string_view_type>(*this).find(sv, pos);
        }

        [[nodiscard]] constexpr size_type rfind(TChar ch, size_type pos = 0) const noexcept {
            return static_cast<string_view_type>(*this).rfind(ch, pos);
        }
        [[nodiscard]] constexpr size_type rfind(string_view_type sv, size_type pos = 0) const noexcept {
            return static_cast<string_view_type>(*this).rfind(sv, pos);
        }

        [[nodiscard]] constexpr size_type find_first_of(TChar ch, size_type pos = 0) const noexcept {
            return static_cast<string_view_type>(*this).find_first_of(ch, pos);
        }
        [[nodiscard]] constexpr size_type find_first_of(string_view_type sv, size_type pos = 0) const noexcept {
            return static_cast<string_view_type>(*this).find_first_of(sv, pos);
        }

        [[nodiscard]] constexpr size_type find_first_not_of(TChar ch, size_type pos = 0) const noexcept {
            return static_cast<string_view_type>(*this).find_first_not_of(ch, pos);
        }
        [[nodiscard]] constexpr size_type find_first_not_of(string_view_type sv, size_type pos = 0) const noexcept {
            return static_cast<string_view_type>(*this).find_first_not_of(sv, pos);
        }

        [[nodiscard]] constexpr size_type find_last_of(TChar ch, size_type pos = 0) const noexcept {
            return static_cast<string_view_type>(*this).find_last_of(ch, pos);
        }
        [[nodiscard]] constexpr size_type find_last_of(string_view_type sv, size_type pos = 0) const noexcept {
            return static_cast<string_view_type>(*this).find_last_of(sv, pos);
        }

        [[nodiscard]] constexpr size_type find_last_not_of(TChar ch, size_type pos = 0) const noexcept {
            return static_cast<string_view_type>(*this).find_last_not_of(ch, pos);
        }
        [[nodiscard]] constexpr size_type find_last_not_of(string_view_type sv, size_type pos = 0) const noexcept {
            return static_cast<string_view_type>(*this).find_last_not_of(sv, pos);
        }

        template<size_type N2>
        [[nodiscard]] constexpr friend BasicStringLiteral<TChar, N + N2, CharTraits>
        operator+(const BasicStringLiteral<TChar, N, CharTraits> &lhs, const BasicStringLiteral<TChar, N2, CharTraits> &rhs) noexcept {
            BasicStringLiteral<TChar, N + N2, CharTraits> result{};
            traits_type::copy(result.data(), lhs.data(), N);
            traits_type::copy(result.data() + N, rhs.data(), N2);
            traits_type::assign(result.data()[N + N2], TChar{'\0'});
            return result;
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend BasicStringLiteral<TChar, N + N2 - 1, CharTraits>
        operator+(const BasicStringLiteral<TChar, N, CharTraits> &lhs, TChar const (&rhs)[N2]) noexcept {
            BasicStringLiteral<TChar, N + N2 - 1, CharTraits> result{};
            traits_type::copy(result.data(), lhs.data(), N);
            traits_type::copy(result.data() + N, rhs, N2);
            return result;
        }

        template<size_type N2>
        [[nodiscard]] constexpr friend auto operator<=>(const BasicStringLiteral<TChar, N, CharTraits> &lhs,
                                                        const BasicStringLiteral<TChar, N2, CharTraits> &rhs) noexcept {
            const auto cmp_result = lhs.compare(static_cast<string_view_type>(rhs));
            if (cmp_result < 0) { return std::strong_ordering::less; }
            if (cmp_result > 0) { return std::strong_ordering::greater; }
            return std::strong_ordering::equal;
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator==(const BasicStringLiteral<TChar, N, CharTraits> &lhs,
                                                       const BasicStringLiteral<TChar, N2, CharTraits> &rhs) noexcept {
            return (lhs <=> rhs) == std::strong_ordering::equal;
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator!=(const BasicStringLiteral<TChar, N, CharTraits> &lhs,
                                                       const BasicStringLiteral<TChar, N2, CharTraits> &rhs) noexcept {
            return !(lhs == rhs);
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator<(const BasicStringLiteral<TChar, N, CharTraits> &lhs,
                                                      const BasicStringLiteral<TChar, N2, CharTraits> &rhs) noexcept {
            return (lhs <=> rhs) == std::strong_ordering::less;
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator<=(const BasicStringLiteral<TChar, N, CharTraits> &lhs,
                                                       const BasicStringLiteral<TChar, N2, CharTraits> &rhs) noexcept {
            const auto cmp_result = lhs <=> rhs;
            return cmp_result == std::strong_ordering::less || cmp_result == std::strong_ordering::equal;
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator>(const BasicStringLiteral<TChar, N, CharTraits> &lhs,
                                                      const BasicStringLiteral<TChar, N2, CharTraits> &rhs) noexcept {
            return (lhs <=> rhs) == std::strong_ordering::greater;
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator>=(const BasicStringLiteral<TChar, N, CharTraits> &lhs,
                                                       const BasicStringLiteral<TChar, N2, CharTraits> &rhs) noexcept {
            const auto cmp_result = lhs <=> rhs;
            return cmp_result == std::strong_ordering::greater || cmp_result == std::strong_ordering::equal;
        }

        template<size_type N2>
        [[nodiscard]] constexpr friend auto operator<=>(const BasicStringLiteral<TChar, N, CharTraits> &lhs, const TChar (&rhs)[N2]) noexcept {
            const auto cmp_result = lhs.compare(string_view_type{rhs});
            if (cmp_result < 0) { return std::strong_ordering::less; }
            if (cmp_result > 0) { return std::strong_ordering::greater; }
            return std::strong_ordering::equal;
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator==(const BasicStringLiteral<TChar, N, CharTraits> &lhs, const TChar (&rhs)[N2]) noexcept {
            return (lhs <=> rhs) == std::strong_ordering::equal;
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator!=(const BasicStringLiteral<TChar, N, CharTraits> &lhs, const TChar (&rhs)[N2]) noexcept {
            return !(lhs == rhs);
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator<(const BasicStringLiteral<TChar, N, CharTraits> &lhs, const TChar (&rhs)[N2]) noexcept {
            return (lhs <=> rhs) == std::strong_ordering::less;
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator<=(const BasicStringLiteral<TChar, N, CharTraits> &lhs, const TChar (&rhs)[N2]) noexcept {
            const auto cmp_result = lhs <=> rhs;
            return cmp_result == std::strong_ordering::less || cmp_result == std::strong_ordering::equal;
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator>(const BasicStringLiteral<TChar, N, CharTraits> &lhs, const TChar (&rhs)[N2]) noexcept {
            return (lhs <=> rhs) == std::strong_ordering::greater;
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator>=(const BasicStringLiteral<TChar, N, CharTraits> &lhs, const TChar (&rhs)[N2]) noexcept {
            const auto cmp_result = lhs <=> rhs;
            return cmp_result == std::strong_ordering::greater || cmp_result == std::strong_ordering::equal;
        }

        template<size_type N2>
        [[nodiscard]] constexpr friend auto operator<=>(const TChar (&lhs)[N2], const BasicStringLiteral<TChar, N, CharTraits> &rhs) noexcept {
            const auto cmp_result = rhs.compare(lhs) * -1;
            if (cmp_result < 0) { return std::strong_ordering::less; }
            if (cmp_result > 0) { return std::strong_ordering::greater; }
            return std::strong_ordering::equal;
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator==(const TChar (&lhs)[N2], const BasicStringLiteral<TChar, N, CharTraits> &rhs) noexcept {
            return (lhs <=> rhs) == std::strong_ordering::equal;
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator!=(const TChar (&lhs)[N2], const BasicStringLiteral<TChar, N, CharTraits> &rhs) noexcept {
            return !(lhs == rhs);
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator<(const TChar (&lhs)[N2], const BasicStringLiteral<TChar, N, CharTraits> &rhs) noexcept {
            return (lhs <=> rhs) == std::strong_ordering::less;
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator<=(const TChar (&lhs)[N2], const BasicStringLiteral<TChar, N, CharTraits> &rhs) noexcept {
            const auto cmp_result = lhs <=> rhs;
            return cmp_result == std::strong_ordering::less || cmp_result == std::strong_ordering::equal;
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator>(const TChar (&lhs)[N2], const BasicStringLiteral<TChar, N, CharTraits> &rhs) noexcept {
            return (lhs <=> rhs) == std::strong_ordering::greater;
        }
        template<size_type N2>
        [[nodiscard]] constexpr friend bool operator>=(const TChar (&lhs)[N2], const BasicStringLiteral<TChar, N, CharTraits> &rhs) noexcept {
            const auto cmp_result = lhs <=> rhs;
            return cmp_result == std::strong_ordering::greater || cmp_result == std::strong_ordering::equal;
        }

        friend std::ostream &operator<<(std::ostream &o, const BasicStringLiteral<TChar, N, CharTraits> &s) {
            o << s.c_str();
            return o;
        }
        friend std::istream &operator>>(const BasicStringLiteral<TChar, N, CharTraits> &s, std::istream &i) {
            s.c_str() >> i;
            return i;
        }

        [[nodiscard]] constexpr bool empty() const noexcept { return size() == 0ull; }
        [[nodiscard]] constexpr size_type size() const noexcept { return traits_type::length(str.data()); }
        [[nodiscard]] constexpr size_type length() const noexcept { return size(); }
        [[nodiscard]] static constexpr size_type capacity() noexcept { return N; }
        [[nodiscard]] static constexpr size_type max_size() noexcept { return capacity(); }
        [[nodiscard]] constexpr iterator begin() noexcept { return str.begin(); }
        [[nodiscard]] constexpr iterator end() noexcept { return str.end(); }
        [[nodiscard]] constexpr const_iterator begin() const noexcept { return str.begin(); }
        [[nodiscard]] constexpr const_iterator end() const noexcept { return str.end(); }
        [[nodiscard]] constexpr const_iterator cbegin() const noexcept { return str.cbegin(); }
        [[nodiscard]] constexpr const_iterator cend() const noexcept { return str.cend(); }
        [[nodiscard]] constexpr reverse_iterator rbegin() noexcept { return str.rbegin(); }
        [[nodiscard]] constexpr reverse_iterator rend() noexcept { return str.rend(); }
        [[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept { return str.rbegin(); }
        [[nodiscard]] constexpr const_reverse_iterator rend() const noexcept { return str.rend(); }
        [[nodiscard]] constexpr const_reverse_iterator rcbegin() const noexcept { return str.rcbegin(); }
        [[nodiscard]] constexpr const_reverse_iterator rcend() const noexcept { return str.rcend(); }
        [[nodiscard]] constexpr reference operator[](size_type index) noexcept { return str[index]; }
        [[nodiscard]] constexpr const_reference operator[](size_type index) const noexcept { return str[index]; }
        [[nodiscard]] constexpr reference front() noexcept { return str.front(); }
        [[nodiscard]] constexpr reference back() noexcept { return str.back(); }
        [[nodiscard]] constexpr value_type front() const noexcept { return str.front(); }
        [[nodiscard]] constexpr value_type back() const noexcept { return str.back(); }
        [[nodiscard]] constexpr pointer data() noexcept { return str.data(); }
        [[nodiscard]] constexpr const_pointer data() const noexcept { return str.data(); }
        [[nodiscard]] constexpr const_pointer c_str() const noexcept { return str.data(); }

        storage str{value_type{'\0'}};
    };

    template<typename TChar, std::size_t N, typename CharTraits = std::char_traits<TChar>>
    BasicStringLiteral(const TChar (&)[N]) -> BasicStringLiteral<TChar, N - 1, CharTraits>;

    namespace details {
        template<std::size_t N, typename TChar, typename CharTraits = std::char_traits<TChar>>
        struct BasicFixedStringUDLBuffer {

            consteval BasicFixedStringUDLBuffer(const TChar (&str)[N]) noexcept { CharTraits::copy(data, str, N); }

            TChar data[N];
            constexpr static size_t count = N;
        };
    }// namespace details

// Can't do deduction guides for templated aliases, so it has to be done this way
#define PF_STRINGLITERAL_SPECIALIZATION(name, char_type)                                                                                   \
  template<std::size_t N>                                                                                                                  \
  struct name : BasicStringLiteral<char_type, N> {                                                                                         \
    using BasicStringLiteral<char_type, N>::BasicStringLiteral;                                                                            \
  };                                                                                                                                       \
  template<std::size_t N>                                                                                                                  \
  name(const char_type(&)[N]) -> name<N - 1>;

    PF_STRINGLITERAL_SPECIALIZATION(StringLiteral, char)
    PF_STRINGLITERAL_SPECIALIZATION(U8StringLiteral, char8_t)
    PF_STRINGLITERAL_SPECIALIZATION(U16StringLiteral, char16_t)
    PF_STRINGLITERAL_SPECIALIZATION(U32StringLiteral, char32_t)
    PF_STRINGLITERAL_SPECIALIZATION(WStringLiteral, wchar_t)

    namespace string_literals {
        template<details::BasicFixedStringUDLBuffer Buffer>
        consteval auto operator""_slit() {
            return BasicStringLiteral{Buffer.data};
        }
    }// namespace string_literals

#undef PF_STRINGLITERAL_SPECIALIZATION

}// namespace pf

#define PF_STRINGLITERAL_HASH(name)                                                                                                        \
  template<std::size_t N>                                                                                                                  \
  struct hash<pf::name<N>> {                                                                                                               \
    constexpr hash() = default;                                                                                                            \
    constexpr ~hash() = default;                                                                                                           \
    constexpr hash(const hash &) = default;                                                                                                \
    constexpr hash(hash &&) noexcept {}                                                                                                    \
    constexpr hash &operator=(const hash &) = default;                                                                                     \
    constexpr hash &operator=(hash &&) = default;                                                                                          \
                                                                                                                                           \
    [[nodiscard]] constexpr std::uint64_t operator()(const pf::name<N> &str) const noexcept {                                              \
      using string_view_type = typename pf::name<N>::string_view_type;                                                                     \
      return std::hash<string_view_type>{}(static_cast<string_view_type>(str));                                                            \
    }                                                                                                                                      \
  }

namespace std {
    PF_STRINGLITERAL_HASH(StringLiteral);
    PF_STRINGLITERAL_HASH(U8StringLiteral);
    PF_STRINGLITERAL_HASH(U16StringLiteral);
    PF_STRINGLITERAL_HASH(U32StringLiteral);
    PF_STRINGLITERAL_HASH(WStringLiteral);
}// namespace std

#undef PF_STRINGLITERAL_HASH
