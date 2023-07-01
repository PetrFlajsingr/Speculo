//
// Created by xflajs00 on 19.03.2023.
//

#include "ASTDeclParser.hpp"

namespace speculo::gen {

    ASTDeclParser::ASTDeclParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser, ParsedTypesCache &cache)
        : idGenerator{std::move(idGen)}, attributeParser{std::move(attribParser)}, typesCache{cache} {}

    ASTDeclParser::~ASTDeclParser() = default;

}// namespace speculo::gen