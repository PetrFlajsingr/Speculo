//
// Created by xflajs00 on 19.03.2023.
//

#ifndef PF_META_GEN_DECL_PARSER_FACTORY_H
#define PF_META_GEN_DECL_PARSER_FACTORY_H

#include "ASTDeclParser.h"

namespace pf::meta_gen {

    [[nodiscard]] std::unique_ptr<ASTDeclParser> createDeclParser(clang::Decl *decl, std::shared_ptr<IdGenerator> idGen);

}

#endif//PF_META_GEN_DECL_PARSER_FACTORY_H
