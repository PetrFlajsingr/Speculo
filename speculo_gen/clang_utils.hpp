//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

#include "info_structs.hpp"
#include "wrap/clang_tooling.hpp"


namespace speculo::gen {

    [[nodiscard]] Access clangAccesConv(clang::AccessSpecifier src);

    [[nodiscard]] SourceLocationInfo getSourceLocationInfo(clang::ASTContext &astContext, const clang::Decl &decl);
    [[nodiscard]] std::string getSourceText(clang::ASTContext &astContext, const clang::Decl &decl);

    /// Create qualified name properly, including template arguments.
    [[nodiscard]] std::string getProperQualifiedName(const clang::CXXRecordDecl *decl, const clang::ASTContext &astContext,
                                                            const clang::PrintingPolicy &printingPolicy);
    [[nodiscard]] std::string getProperName(const clang::CXXRecordDecl *decl, const clang::ASTContext &astContext,
                                                   const clang::PrintingPolicy &printingPolicy);
    /// Create qualified named properly, including template arguments
    [[nodiscard]] std::string getProperQualifiedName(const clang::CXXMethodDecl *decl, const clang::ASTContext &astContext,
                                                            const clang::PrintingPolicy &printingPolicy);
    [[nodiscard]] std::string getProperName(const clang::CXXMethodDecl *decl, const clang::ASTContext &astContext,
                                                   const clang::PrintingPolicy &printingPolicy);
    /// Create qualified named properly, including template arguments
    [[nodiscard]] std::string getProperQualifiedName(const clang::CXXConstructorDecl *decl, const clang::ASTContext &astContext,
                                                            const clang::PrintingPolicy &printingPolicy);
    [[nodiscard]] std::string getProperName(const clang::CXXConstructorDecl *decl, const clang::ASTContext &astContext,
                                                   const clang::PrintingPolicy &printingPolicy);

    [[nodiscard]] std::string getProperQualifiedName(const clang::QualType &type, const clang::ASTContext &astContext);

}// namespace speculo::gen
