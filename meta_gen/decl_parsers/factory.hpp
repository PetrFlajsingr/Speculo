//
// Created by xflajs00 on 19.03.2023.
//

#ifndef PF_META_GEN_FACTORY_H
#define PF_META_GEN_FACTORY_H

#include "ASTDeclParser.hpp"

namespace pf::meta_gen {

    [[nodiscard]] std::unique_ptr<ASTDeclParser> createDeclParser(clang::ASTContext &astContext, clang::Decl *decl,
                                                                  const std::shared_ptr<IdGenerator> &idGen,
                                                                  std::shared_ptr<AttributeParser> attributeParser);

}

#endif//PF_META_GEN_FACTORY_H
