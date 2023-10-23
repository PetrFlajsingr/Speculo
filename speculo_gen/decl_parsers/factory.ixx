module;

#include <memory>
#include <clang/AST/ASTContext.h>

export module speculo.gen:decl_parser_factory;
import :ast_decl_parser;
import :id_generator;
import :attribute_parser;
import :types_cache;

namespace speculo::gen {

    [[nodiscard]] std::unique_ptr<ASTDeclParser> createDeclParser(clang::ASTContext &astContext, clang::Decl *decl,
                                                                  std::shared_ptr<IdGenerator> idGen,
                                                                  std::shared_ptr<AttributeParser> attributeParser,
                                                                  std::shared_ptr<TypesCache> cache);

}
