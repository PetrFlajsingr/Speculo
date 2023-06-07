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
    using namespace test2;
    struct SimpleStruct : public test2::DifferentFileBase {
        PF_META_GENERATED();

        SimpleStruct(DifferentFileBase ) {}

        void foo(DifferentFileBase &) {}

        /* unsigned int b1 : 1;
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
    void footadlo() {}*/
    };
}
PF_META_GENERATED_HEADER();