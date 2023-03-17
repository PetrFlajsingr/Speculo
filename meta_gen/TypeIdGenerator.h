//
// Created by xflajs00 on 17.03.2023.
//

#ifndef PF_META_TYPEIDGENERATOR_H
#define PF_META_TYPEIDGENERATOR_H

#include <random>
#include "../meta/Info.h"

namespace pf::meta_gen {

    class TypeIdGenerator {
    public:
        TypeIdGenerator() {
            std::random_device rd{};
            std::seed_seq ss{rd(), rd(), rd()};
            gen = std::mt19937_64{ss};
        }

        [[nodiscard]] pf::meta::details::ID generateTypeId() {
            const auto w1 = dis(gen);
            const auto w2 = dis(gen);
            return pf::meta::details::ID{w1, w2};
        }

        [[nodiscard]] std::uint64_t generateRandomInt() { return dis(gen); }

    private:
        std::mt19937_64 gen;
        std::uniform_int_distribution<std::uint64_t> dis;
    };

}

#endif //PF_META_TYPEIDGENERATOR_H
