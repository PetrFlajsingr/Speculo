//
// Created by xflajs00 on 17.03.2023.
//

#ifndef PF_META_TYPEIDGENERATOR_H
#define PF_META_TYPEIDGENERATOR_H

#include <random>
#include "../meta/Info.h"

#include <stduuid/uuid.h>

namespace pf::meta_gen {

    class TypeIdGenerator {
    public:
        TypeIdGenerator() {

            std::random_device rd{};
            std::seed_seq ss{rd(), rd(), rd()};
            gen = std::mt19937_64{ss};
        }

        [[nodiscard]] pf::meta::details::ID generateTypeId(const std::string &fullTypeName) {
            const auto uuid = uuidNameGenerator(fullTypeName);
            pf::meta::details::ID result{};
            std::memcpy(result.id.data(), uuid.as_bytes().data(), uuid.as_bytes().size_bytes());
            return result;
        }

        [[nodiscard]] std::uint64_t generateRandomInt() { return dis(gen); }

    private:
        uuids::uuid_name_generator uuidNameGenerator{
                uuids::uuid::from_string("47183823-2574-4bfd-b411-99ed177d3e43").value()};

        std::mt19937_64 gen;
        std::uniform_int_distribution<std::uint64_t> dis;
    };

}

#endif //PF_META_TYPEIDGENERATOR_H
