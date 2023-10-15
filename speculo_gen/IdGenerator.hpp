//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

import speculo;

#include <random>
#include <stduuid/uuid.h>

#include "info_structs.hpp"

namespace speculo::gen {

    class IdGenerator {
    public:
        IdGenerator() = default;

        [[nodiscard]] speculo::ID generateId(const std::string &name) {
            const auto uuid = uuidNameGenerator(name);
            speculo::ID result{};
            std::memcpy(result.id.data(), uuid.as_bytes().data(), uuid.as_bytes().size_bytes());
            return result;
        }

        [[nodiscard]] std::uint64_t generateRandomInt() { return dis(gen); }

    private:
        constexpr static auto IdUUIDSeed = "47183823-2574-4bfd-b411-99ed177d3e43";
        uuids::uuid_name_generator uuidNameGenerator{uuids::uuid::from_string(IdUUIDSeed).value()};

        std::random_device rd{};
        std::seed_seq ss{rd(), rd(), rd()};
        std::mt19937_64 gen{ss};
        std::uniform_int_distribution<std::uint64_t> dis;
    };

    inline void populateIDs(TypeInfo &info, IdGenerator &generator) {
        info.id = generator.generateId(info.fullName);
        info.constId = generator.generateId("const " + info.fullName);
        info.lrefId = generator.generateId(info.fullName + " &");
        info.rrefId = generator.generateId(info.fullName + " &&");
        info.constLrefId = generator.generateId("const " + info.fullName + " &");
        info.ptrId = generator.generateId(info.fullName + " *");
        info.constPtrId = generator.generateId("const" + info.fullName + " *");
        info.volatileId = generator.generateId("volatile " + info.fullName);
        info.volatileConstId = generator.generateId("volatile const " + info.fullName);
        info.volatileLrefId = generator.generateId("volatile " + info.fullName + " &");
        info.volatileRrefId = generator.generateId("volatile " + info.fullName + " &&");
        info.volatileConstLrefId = generator.generateId("volatile const " + info.fullName + " &");
        info.volatilePtrId = generator.generateId("volatile " + info.fullName + " *");
        info.volatileConstPtrId = generator.generateId("volatile const" + info.fullName + " *");
    }

}// namespace speculo::gen
