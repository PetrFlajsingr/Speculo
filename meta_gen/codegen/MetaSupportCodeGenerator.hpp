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

        void start() override;
        void end() override;
        void handle(const TypeInfoVariant &typeInfo) override;

        [[nodiscard]] uint64_t getPriority() const override;

    };

}// namespace pf::meta_gen
