/**
 * @file CodeGenerator.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include "../info_structs.hpp"
#include <iostream>
#include <spdlog/spdlog.h>


namespace speculo::gen {

    struct GenerationResult {
        /// Code inserted into generated/<filename>.hpp
        std::string hppCode;
        /// Code inserted into generated/<filename>.cpp
        std::string cppCode;
        /// Code inserted into PF_META_GENERATED_HEADER() for current header file
        std::string headerBodyCode;
        /// Generated types - have to be contained in hppCode (or in typeBodyCode)
        std::vector<TypeInfoVariant> generatedTypes;
    };

    struct RecordGenerationResult : GenerationResult {
        /// Code inserted into PF_META_GENERATED() for this record
        std::string typeBodyCode;
    };

    class CodeGenerator {
    public:
        CodeGenerator() = default;
        virtual ~CodeGenerator() = default;

        void initialize(std::string uuidHeader, std::string uuidCpp, std::string originalHeaderRelativePath,
                        std::shared_ptr<spdlog::logger> log) {
            headerUUID = std::move(uuidHeader);
            cppUUID = std::move(uuidCpp);
            relativePathToOriginal = std::move(originalHeaderRelativePath);
            logger = std::move(log);
        }
        /// Called once before the first type.
        [[nodiscard]] virtual GenerationResult start() = 0;
        /// Called for each record type.
        /// @param typeInfo reference to the type, can be modified to add info for newly generated functions or variables.
        [[nodiscard]] virtual RecordGenerationResult generate(RecordTypeInfo &typeInfo) = 0;

        [[nodiscard]] virtual GenerationResult generate(const EnumTypeInfo &typeInfo) = 0;

        [[nodiscard]] virtual GenerationResult end() = 0;


        [[nodiscard]] virtual std::uint64_t getPriority() const = 0;

        [[nodiscard]] std::string_view getHeaderUuid() const { return headerUUID; }

        [[nodiscard]] std::string_view getCppUuid() const { return cppUUID; }

        [[nodiscard]] std::string_view getRelativePathToOriginal() const { return relativePathToOriginal; }

        [[nodiscard]] spdlog::logger &getLogger() const { return *logger; }


    private:
        std::string headerUUID;
        std::string cppUUID;
        std::string relativePathToOriginal;
        std::shared_ptr<spdlog::logger> logger;
    };

}// namespace speculo::gen