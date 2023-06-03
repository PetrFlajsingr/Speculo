/**
 * @file CodeGenWriter.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <llvm/Support/raw_ostream.h>

#include "../info_structs.hpp"
#include <fmt/format.h>
#include <meta/details/RangeOf.hpp>

#include "CodeGenerator.hpp"

namespace pf::meta_gen {

    class MetaSupportCodeGenerator : public CodeGenerator {
    public:
        MetaSupportCodeGenerator() = default;

        [[nodiscard]] GenerationResult start() override;
        [[nodiscard]] GenerationResult end() override;
        [[nodiscard]] RecordGenerationResult generate(const RecordTypeInfo &typeInfo) override;
        [[nodiscard]] GenerationResult generate(const EnumTypeInfo &typeInfo) override;

        [[nodiscard]] uint64_t getPriority() const override;
    };

}// namespace pf::meta_gen
