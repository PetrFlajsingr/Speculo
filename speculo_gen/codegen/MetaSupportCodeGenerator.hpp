/**
 * @file CodeGenWriter.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include "../info_structs.hpp"
#include <fmt/format.h>
#include <speculo/details/RangeOf.hpp>

#include "CodeGenerator.hpp"

namespace speculo::gen {

    /// Generator to support meta functionality.
    /// Generates friend declarations.
    class MetaSupportCodeGenerator : public CodeGenerator {
    public:
        MetaSupportCodeGenerator() = default;

        [[nodiscard]] RecordGenerationResult generate(RecordTypeInfo &typeInfo) override;
        [[nodiscard]] GenerationResult generate(const EnumTypeInfo &typeInfo) override;
        FilePrologueEpilogue getPrologueEpilogue() override;

        [[nodiscard]] uint64_t getPriority() const override;
    };

}// namespace speculo::gen
