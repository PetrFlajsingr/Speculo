//
// Created by xflajs00 on 19.03.2023.
//

#include "decl_parser_factory.h"

#include "ASTEnumDeclParser.h"
#include "ASTRecordParser.h"

#include <spdlog/spdlog.h>

namespace pf::meta_gen {

    std::unique_ptr<ASTDeclParser> createDeclParser(clang::Decl *decl, std::shared_ptr<IdGenerator> idGen) {
        if (const auto enumDecl = clang::dyn_cast<clang::EnumDecl>(decl); enumDecl != nullptr && !enumDecl->isInvalidDecl()) {
            return std::make_unique<ASTEnumDeclParser>(idGen);
        } else {
            spdlog::warn("createDeclParser: unsupported decl type");
            return nullptr;
        }
    }

}// namespace pf::meta_gen