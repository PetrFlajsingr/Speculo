//
// Created by xflajs00 on 19.03.2023.
//

#include "factory.h"
#include <clang/AST/DeclCXX.h>

#include "ASTEnumParser.h"
#include "ASTRecordParser.h"

#include <spdlog/spdlog.h>

namespace pf::meta_gen {

    std::unique_ptr<ASTDeclParser> createDeclParser(clang::ASTContext &astContext, clang::Decl *decl, const std::shared_ptr<IdGenerator> &idGen) {
        if (decl->isInvalidDecl()) {
            spdlog::warn("createDeclParser: invalid decl of kind {} encountered", decl->getDeclKindName());
        }
        if (const auto enumDecl = clang::dyn_cast<clang::EnumDecl>(decl); enumDecl != nullptr) {
            return std::make_unique<ASTEnumParser>(idGen);
        } else if (const auto recordDecl = clang::dyn_cast<clang::CXXRecordDecl>(decl);
                   recordDecl != nullptr) {
            return std::make_unique<ASTRecordParser>(idGen);
        } else {
            spdlog::warn("createDeclParser: unsupported decl of kind {}", decl->getDeclKindName());
            return nullptr;
        }
    }

}// namespace pf::meta_gen