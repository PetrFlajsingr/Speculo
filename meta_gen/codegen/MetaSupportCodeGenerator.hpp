/**
 * @file CodeGenWriter.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include "../info_structs.hpp"
#include <fmt/format.h>
#include <meta/details/RangeOf.hpp>

#include "CodeGenerator.hpp"

namespace pf::meta_gen {

    /// Generator to support meta functionality.
    /// Generates friend declarations.
    class MetaSupportCodeGenerator : public CodeGenerator {
    public:
        MetaSupportCodeGenerator() = default;

        [[nodiscard]] GenerationResult start() override;
        [[nodiscard]] GenerationResult end() override;
        [[nodiscard]] RecordGenerationResult generate(RecordTypeInfo &typeInfo) override;
        [[nodiscard]] GenerationResult generate(const EnumTypeInfo &typeInfo) override;

        [[nodiscard]] uint64_t getPriority() const override;
    };

}// namespace pf::meta_gen
