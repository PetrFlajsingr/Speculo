//
// Created by xflajs00 on 19.03.2023.
//

#include "ASTDeclParser.h"

namespace pf::meta_gen {

    ASTDeclParser::ASTDeclParser(std::shared_ptr<IdGenerator> idGen) : idGenerator{std::move(idGen)} {}

    ASTDeclParser::~ASTDeclParser() = default;

}// namespace pf::meta_gen