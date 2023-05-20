//
// Created by xflajs00 on 19.03.2023.
//

#include "ASTDeclParser.hpp"

namespace pf::meta_gen {

    ASTDeclParser::ASTDeclParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser)
        : idGenerator{std::move(idGen)}, attributeParser{std::move(attribParser)} {}

    ASTDeclParser::~ASTDeclParser() = default;

}// namespace pf::meta_gen