/**
 * @file test2.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include "generated/test2.hpp"

struct SimpleStruct {
    PF_META_GENERATED();

    unsigned int b1 : 1;
    unsigned int b2 : 2;
    unsigned int b3 : 3;
    unsigned int b4 : 4;
    unsigned int b5 : 5;

    struct NestedPublic {
        int a;
    };

private:
    struct NestedPrivate {
        int a;
    };
    void footadlo() {}
};

PF_META_GENERATED_HEADER();