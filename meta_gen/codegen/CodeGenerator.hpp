/**
 * @file CodeGenerator.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include "../info_structs.hpp"
#include <iostream>


namespace pf::meta_gen {

    struct GenerationResult {
        std::string hppCode;
        std::string cppCode;
    };

    struct RecordGenerationResult {
        std::string typeBodyCode;
        std::string hppCode;
        std::string cppCode;
    };

    class CodeGenerator {
    public:
        CodeGenerator() = default;
        virtual ~CodeGenerator() = default;

        void initialize(std::string uuidHeader, std::string uuidCpp) {
            headerUUID = std::move(uuidHeader);
            cppUUID = std::move(uuidCpp);
        }

        [[nodiscard]] virtual GenerationResult start() = 0;

        [[nodiscard]] virtual RecordGenerationResult generate(const RecordTypeInfo &typeInfo) = 0;
        [[nodiscard]] virtual GenerationResult generate(const EnumTypeInfo &typeInfo) = 0;

        [[nodiscard]] virtual GenerationResult end() = 0;


        [[nodiscard]] virtual std::uint64_t getPriority() const = 0;

        [[nodiscard]] std::string_view getHeaderUuid() const { return headerUUID; }
        [[nodiscard]] std::string_view getCppUuid() const { return cppUUID; }


    private:
        std::string headerUUID;
        std::string cppUUID;
    };

}// namespace pf::meta_gen