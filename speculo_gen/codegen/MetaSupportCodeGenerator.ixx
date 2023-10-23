module;

#include <cstddef>

#include <fmt/format.h>

export module speculo.gen:meta_code_generator;
import speculo;
import :codegen;
import :structs;

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
