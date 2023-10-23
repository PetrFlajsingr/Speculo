module;

#include <memory>

module speculo.gen;
import :ast_decl_parser;


namespace speculo::gen {

    ASTDeclParser::ASTDeclParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser,
                                 std::shared_ptr<TypesCache> cache)
        : idGenerator{std::move(idGen)}, attributeParser{std::move(attribParser)}, typesCache{std::move(cache)} {}

    ASTDeclParser::~ASTDeclParser() = default;

}// namespace speculo::gen