/**
 * @file test2.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include "test_h.hpp"
#include <meta/macros.hpp>

#include "generated/test2.hpp"

namespace test {
    class HashName {
        PF_META_GENERATED();

    public:
        explicit HashName(std::string_view str) {}
        HashName(const HashName &other) = default;
        HashName &operator=(const HashName &other) = default;
        HashName(HashName &&other) = default;
        HashName &operator=(HashName &&other) = default;

        [[nodiscard]] std::string_view getName() const { return {}; }
        [[nodiscard]] int getHash() const { return hash; }

        [[nodiscard]] bool operator==(const HashName &other) const { return hash == other.hash; }

    private:
        int hash;
    };
      struct C {
        constexpr C(int) {}
    };
    using namespace test2;
    struct SimpleStruct : public test2::DifferentFileBase {
        PF_META_GENERATED();

         unsigned int b1 : 1;
    unsigned int b2 : 2;
    unsigned int b3 : 3;
    unsigned int b4 : 4;
    unsigned int b5 : 5;

    struct NestedPublic {
        PF_META_GENERATED();
        int a;
    };

private:
    struct NestedPrivate {
        PF_META_GENERATED();
        int a;
    };
    void footadlo() {}
    };
}// namespace test
PF_META_GENERATED_HEADER();