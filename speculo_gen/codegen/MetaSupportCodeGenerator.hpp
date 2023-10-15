/**
 * @file CodeGenWriter.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

import speculo;

#include <cstddef>

#include "../info_structs.hpp"
#include <fmt/format.h>

#include "CodeGenerator.hpp"

namespace speculo::gen {

    /// Generator to support meta functionality.
    /// Generates friend declarations.
    class MetaSupportCodeGenerator : public CodeGenerator {
    public:
        MetaSupportCodeGenerator() = default;

        [[nodiscard]] RecordGenerationResult generate(RecordTypeInfo &typeInfo) override;
        [[nodiscard]] GenerationResult generate(const EnumTypeInfo &typeInfo) override;
        [[nodiscard]] FilePrologueEpilogue getPrologueEpilogue() override;

        [[nodiscard]] std::uint64_t getPriority() const override;
    };

}// namespace speculo::gen
