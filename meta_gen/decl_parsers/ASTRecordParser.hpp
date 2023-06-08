//
// Created by xflajs00 on 19.03.2023.
//

#pragma once

#include "ASTDeclParser.hpp"

namespace pf::meta_gen {
    class ASTRecordParser final : public ASTDeclParser {
    public:
        ASTRecordParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser, ParsedTypesCache &cache);

        ~ASTRecordParser() override = default;

        std::optional<TypeInfoVariant> parse(clang::ASTContext &astContext, clang::Decl *decl) override;

    private:
        /**
         * Create qualified name properly, including template arguments.
         */
        [[nodiscard]] static std::string GetProperQualifiedName(const clang::CXXRecordDecl *decl, const clang::PrintingPolicy &printingPolicy);
        [[nodiscard]] static std::string GetProperName(const clang::CXXRecordDecl *decl, const clang::PrintingPolicy &printingPolicy);
        /// Create qualified named properly, including template arguments
        [[nodiscard]] static std::string GetProperQualifiedName(const clang::CXXMethodDecl *decl, const clang::PrintingPolicy &printingPolicy);
        [[nodiscard]] static std::string GetProperName(const clang::CXXMethodDecl *decl, const clang::PrintingPolicy &printingPolicy);
        /// Create qualified named properly, including template arguments
        [[nodiscard]] static std::string GetProperQualifiedName(const clang::CXXConstructorDecl *decl, const clang::PrintingPolicy &printingPolicy);
        [[nodiscard]] static std::string GetProperName(const clang::CXXConstructorDecl *decl, const clang::PrintingPolicy &printingPolicy);
    };

}// namespace pf::meta_gen
