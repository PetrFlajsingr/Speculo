//
// Created by xflajs00 on 19.03.2023.
//

#pragma once

#include "ASTDeclParser.hpp"
#include "ASTEnumParser.hpp"
#include "fmt/format.h"

namespace speculo::gen {
    class ASTRecordParser final : public ASTDeclParser {
    public:
        constexpr static std::string_view metaGenMacro = "SPECULO_GENERATED()";

        ASTRecordParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser,
                        std::shared_ptr<ParsedTypesCache> cache);

        ~ASTRecordParser() override = default;

        [[nodiscard]] std::optional<std::string> getFullTypeName(clang::ASTContext &astContext, clang::Decl *decl) override;
        [[nodiscard]] std::optional<TypeInfoVariant> parse(clang::ASTContext &astContext, clang::Decl *decl) override;

    private:
        [[nodiscard]] static bool ShouldSkipConstructor(const clang::CXXRecordDecl *recordDecl, const clang::CXXConstructorDecl *ctor);
        [[nodiscard]] static bool ShouldSkipRecordDecl(const clang::CXXRecordDecl *recordDecl);
        [[nodiscard]] static bool ShouldSkipMethod(const clang::CXXMethodDecl *methodDecl, const clang::CXXRecordDecl *recordDecl);

        [[nodiscard]] static std::string
        MangleFunction(std::string_view fullName,
                       speculo::RangeOf<std::pair<std::string_view, std::string_view>> auto &&argumentTypesAndNames, bool isConst) {
            std::string mangledName{fullName};
            for (const auto &[type, name]: argumentTypesAndNames) {
                mangledName.append(fmt::format("_{}_{}_{}", isConst ? "const" : "", type, name));
            }
            return mangledName;
        }
        [[nodiscard]] static std::string MangleBaseClass(std::string_view derivedFullName, std::string baseFullName) {
            return fmt::format("{}__{}", derivedFullName, baseFullName);
        }

        void collectBasicRecordInfo(RecordTypeInfo &info, clang::ASTContext &astContext, const clang::CXXRecordDecl *recordDecl);
        void collectBaseInfos(RecordTypeInfo &info, clang::ASTContext &astContext, const clang::CXXRecordDecl *recordDecl);
        void collectDestructorInfo(RecordTypeInfo &info, clang::ASTContext &astContext, const clang::CXXRecordDecl *recordDecl);
        void collectConstructorsInfo(RecordTypeInfo &info, clang::ASTContext &astContext, const clang::CXXRecordDecl *recordDecl);
        void collectMethodsInfo(RecordTypeInfo &info, clang::ASTContext &astContext, const clang::CXXRecordDecl *recordDecl);
        void collectStaticVariablesInfo(RecordTypeInfo &info, clang::ASTContext &astContext, const clang::CXXRecordDecl *recordDecl);
        void collectMemberVariablesInfo(RecordTypeInfo &info, clang::ASTContext &astContext, const clang::CXXRecordDecl *recordDecl);

        // TODO: these should be elsewhere
        [[nodiscard]] static std::shared_ptr<TypeInfoVariant>
        CreateFundamentalTypeInfo(const clang::QualType &type, const std::string &typeName, IdGenerator &idGenerator,
                                  ParsedTypesCache &typesCache, clang::ASTContext &astContext);
        ;
        [[nodiscard]] static std::shared_ptr<TypeInfoVariant>
        CreateIncompleteTypeInfo(const clang::QualType &type, const std::string &typeName, IdGenerator &idGenerator,
                                 ParsedTypesCache &typesCache, clang::ASTContext &astContext);
        [[nodiscard]] static std::shared_ptr<TypeInfoVariant> CreateEnumTypeInfo(const clang::QualType &type, const std::string &typeName,
                                                                                 IdGenerator &idGenerator, ParsedTypesCache &typesCache,
                                                                                 clang::ASTContext &astContext, ASTEnumParser &enumParser);
        [[nodiscard]] static std::shared_ptr<TypeInfoVariant> CreateRecordTypeInfo(const clang::QualType &type, const std::string &typeName,
                                                                                   IdGenerator &idGenerator, ParsedTypesCache &typesCache,
                                                                                   clang::ASTContext &astContext,
                                                                                   ASTRecordParser &recordParser);
        [[nodiscard]] static TypeUsage CreateTypeUsage(const clang::QualType &type, clang::ASTContext &astContext,
                                                       ParsedTypesCache &typesCache, IdGenerator &idGenerator, ASTEnumParser &enumParser,
                                                       ASTRecordParser &recordParser);

        static void CheckForGeneratedMacro(RecordTypeInfo &info);

        ASTEnumParser enumParser;
    };

}// namespace speculo::gen
