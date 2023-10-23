module;


#include <memory>
#include <optional>
#include <string>
#include <clang/AST/ASTContext.h>
#include <clang/AST/Decl.h>

export module speculo.gen:ast_decl_parser;
import :id_generator;
import :attribute_parser;
import :types_cache;
import :structs;

namespace speculo::gen {

    class ASTDeclParser {
    public:
        ASTDeclParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser,
                      std::shared_ptr<TypesCache> cache);

        virtual ~ASTDeclParser() = 0;

        [[nodiscard]] virtual std::optional<std::string> getFullTypeName(clang::ASTContext &astContext, clang::Decl *decl) = 0;
        [[nodiscard]] virtual std::optional<TypeInfoVariant> parse(clang::ASTContext &astContext, clang::Decl *decl) = 0;

    protected:
        std::shared_ptr<IdGenerator> idGenerator;
        std::shared_ptr<AttributeParser> attributeParser;
        std::shared_ptr<TypesCache> typesCache;
    };

}// namespace speculo::gen
