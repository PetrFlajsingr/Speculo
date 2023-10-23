module;

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <spdlog/spdlog.h>

export module speculo.gen:codegen;
import :structs;

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

       void merge(const GenerationResult &other) {
           hppCode.append("\n").append(other.hppCode);
           cppCode.append("\n").append(other.cppCode);
           headerBodyCode.append("\n").append(other.headerBodyCode);
           generatedTypes.reserve(generatedTypes.size() + other.generatedTypes.size());
           std::ranges::copy(other.generatedTypes, std::back_inserter(generatedTypes));
       }
   };

   struct RecordGenerationResult : GenerationResult {
       /// Code inserted into PF_META_GENERATED() for this record
       std::string typeBodyCode;

       void merge(const RecordGenerationResult &other) {
           typeBodyCode.append("\n").append(other.typeBodyCode);
           GenerationResult::merge(other);
       }
   };

   struct FilePrologueEpilogue {
       std::string cppPrologue;
       std::string hppPrologue;
       std::string cppEpilogue;
       std::string hppEpilogue;
       std::string headerBodyPrologue;
       std::string headerBodyEpilogue;
   };

   /// Order of execution: generate gets called for all types -> getPrologueEpilogue at the end
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
       /// Called for each record type.
       /// @param typeInfo reference to the type, can be modified to add info for newly generated functions or variables.
       [[nodiscard]] virtual RecordGenerationResult generate(RecordTypeInfo &typeInfo) = 0;

       [[nodiscard]] virtual GenerationResult generate(const EnumTypeInfo &typeInfo) = 0;
       /// Prologue should be used for includes and such
       [[nodiscard]] virtual FilePrologueEpilogue getPrologueEpilogue() = 0;


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