/**
 * @file CodeGenerator.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include "../info_structs.hpp"
#include <iostream>

namespace pf::meta_gen {

    class CodeGenerator {
    public:
        CodeGenerator() = default;
        virtual ~CodeGenerator() = default;

        void initialize(std::ostream &cppOstream, std::ostream &hppOstream, std::string uuidHeader, std::string uuidCpp) {
            cppOut = &cppOstream;
            hppOut = &hppOstream;
            headerUUID = std::move(uuidHeader);
            cppUUID = std::move(uuidCpp);
        }

        virtual void start() = 0;

        virtual void handle(const TypeInfoVariant &typeInfo) = 0;

        virtual void end() = 0;


        [[nodiscard]] virtual std::uint64_t getPriority() const = 0;

        [[nodiscard]] std::string_view getHeaderUuid() const { return headerUUID; }
        [[nodiscard]] std::string_view getCppUuid() const { return cppUUID; }

    protected:
        void writeToHpp(std::string_view data) { (*hppOut) << data; }
        void writeToCpp(std::string_view data) { (*cppOut) << data; }


    private:
        std::ostream *cppOut{};
        std::ostream *hppOut{};
        std::string headerUUID;
        std::string cppUUID;
    };

}// namespace pf::meta_gen