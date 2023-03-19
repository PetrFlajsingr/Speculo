//
// Created by xflajs00 on 19.03.2023.
//

#include "ASTRecordParser.h"

namespace pf::meta_gen {

    ASTRecordParser::ASTRecordParser(std::shared_ptr<IdGenerator> idGen) : ASTDeclParser(idGen) {}

    std::optional<TypeInfoVariant> ASTRecordParser::parse(clang::ASTContext &astContext, clang::Decl *decl) {
        assert(clang::dyn_cast<clang::RecordDecl>(decl) != nullptr);
        return std::nullopt;
    }

}// namespace pf