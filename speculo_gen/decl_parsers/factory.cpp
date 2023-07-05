//
// Created by xflajs00 on 19.03.2023.
//

#include "factory.hpp"
#include "../wrap/clang_ast_declcxx.hpp"

#include "ASTEnumParser.hpp"
#include "ASTRecordParser.hpp"

#include <spdlog/spdlog.h>

namespace speculo::gen {

    std::unique_ptr<ASTDeclParser> createDeclParser(clang::ASTContext &astContext, clang::Decl *decl, std::shared_ptr<IdGenerator> idGen,
                                                    std::shared_ptr<AttributeParser> attributeParser,
                                                    std::shared_ptr<ParsedTypesCache> cache) {
        //if (decl->isInvalidDecl()) { spdlog::trace("createDeclParser: invalid decl of kind {} encountered", decl->getDeclKindName()); }
        if (const auto enumDecl = clang::dyn_cast<clang::EnumDecl>(decl); enumDecl != nullptr) {
            return std::make_unique<ASTEnumParser>(std::move(idGen), std::move(attributeParser), std::move(cache));
        }
        if (const auto recordDecl = clang::dyn_cast<clang::CXXRecordDecl>(decl); recordDecl != nullptr) {
            return std::make_unique<ASTRecordParser>(std::move(idGen), std::move(attributeParser), std::move(cache));
        }
        //spdlog::trace("createDeclParser: unsupported decl of kind {}", decl->getDeclKindName());
        return nullptr;
    }

}// namespace speculo::gen