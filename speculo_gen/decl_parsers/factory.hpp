//
// Created by xflajs00 on 19.03.2023.
//

#pragma once

#include "ASTDeclParser.hpp"

namespace speculo::gen {

    [[nodiscard]] std::unique_ptr<ASTDeclParser> createDeclParser(clang::ASTContext &astContext, clang::Decl *decl,
                                                                  std::shared_ptr<IdGenerator> idGen,
                                                                  std::shared_ptr<AttributeParser> attributeParser,
                                                                  std::shared_ptr<ParsedTypesCache> cache);

}
