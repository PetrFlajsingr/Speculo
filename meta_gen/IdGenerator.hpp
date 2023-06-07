//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

#include <meta/Info.hpp>
#include <random>

#include <stduuid/uuid.h>

namespace pf::meta_gen {

    class IdGenerator {
    public:
        IdGenerator() = default;

        [[nodiscard]] pf::meta::ID generateId(const std::string &name) {
            const auto uuid = uuidNameGenerator(name);
            meta::ID result{};
            std::memcpy(result.id.data(), uuid.as_bytes().data(), uuid.as_bytes().size_bytes());
            return result;
        }

        [[nodiscard]] std::uint64_t generateRandomInt() { return dis(gen); }

    private:
        uuids::uuid_name_generator uuidNameGenerator{uuids::uuid::from_string("47183823-2574-4bfd-b411-99ed177d3e43").value()};

        std::random_device rd{};
        std::seed_seq ss{rd(), rd(), rd()};
        std::mt19937_64 gen{ss};
        std::uniform_int_distribution<std::uint64_t> dis;
    };

}// namespace pf::meta_gen
