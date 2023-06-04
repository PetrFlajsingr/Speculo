//
// Created by xflajs00 on 19.03.2023.
//

#include "factory.hpp"
#include <clang/AST/DeclCXX.h>

#include "ASTEnumParser.hpp"
#include "ASTRecordParser.hpp"

#include <spdlog/spdlog.h>

namespace pf::meta_gen {

    std::unique_ptr<ASTDeclParser> createDeclParser(clang::ASTContext &astContext, clang::Decl *decl,
                                                    const std::shared_ptr<IdGenerator> &idGen,
                                                    std::shared_ptr<AttributeParser> attributeParser, ParsedTypesCache &cache) {
        if (decl->isInvalidDecl()) { spdlog::trace("createDeclParser: invalid decl of kind {} encountered", decl->getDeclKindName()); }
        if (const auto enumDecl = clang::dyn_cast<clang::EnumDecl>(decl); enumDecl != nullptr) {
            return std::make_unique<ASTEnumParser>(idGen, std::move(attributeParser), cache);
        } else if (const auto recordDecl = clang::dyn_cast<clang::CXXRecordDecl>(decl); recordDecl != nullptr) {
            return std::make_unique<ASTRecordParser>(idGen, std::move(attributeParser), cache);
        } else {
            spdlog::trace("createDeclParser: unsupported decl of kind {}", decl->getDeclKindName());
            return nullptr;
        }
    }

}// namespace pf::meta_gen