/**
 * @file test2.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include "test_h.hpp"
#include <speculo/macros.hpp>

#include <cstddef>

#include "generated/test2.hpp"


namespace test {
   class HashName {
        SPECULO_GENERATED()

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
        SPECULO_GENERATED()
        constexpr C(int) {}
    };
    using namespace test2;
    struct SimpleStruct : public test2::DifferentFileBase {
        SPECULO_GENERATED()

        unsigned int b1 : 1;
        unsigned int b2 : 2;
        unsigned int b3 : 3;
        unsigned int b4 : 4;
        unsigned int b5 : 5;

        struct NestedPublic {
            SPECULO_GENERATED()
            int a;
        };

    private:
        struct NestedPrivate {
            SPECULO_GENERATED()
            int a;
        };
        void footadlo() {}
    };



    enum class [[using nihil: arithmetic, bit_flags]] Flags : unsigned int {
        V1 = 0x01,
        V2 = 0x02,
        V3 = 0x04,
        A [[nihil::flag_combination]] = V1 | V2 | V3,
        V12 [[nihil::flag_combination]] = V1 | V2 // allowed even when not single bit due to the attribute, checked
    };


}// namespace test
SPECULO_GENERATED_HEADER()