module;

#include <variant>
#include <vector>
#include <memory>
#include <clang/AST/ASTContext.h>

export module speculo.gen:ast_parser;
import :types_cache;
import :id_generator;
import :attribute_parser;
import :source_config;
import :structs;
import :types_cache;

namespace speculo::gen {

    class ASTParser {
    public:
        ASTParser(const SourceConfig *c, std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser);

        [[nodiscard]] std::vector<TypeInfoVariant> parse(clang::ASTContext &astContext);

    private:
        [[nodiscard]] std::vector<TypeInfoVariant> walk(clang::ASTContext &astContext, const clang::DeclContext &context);

        const SourceConfig *config;
        std::shared_ptr<IdGenerator> idGenerator;
        std::shared_ptr<AttributeParser> attributeParser;
        std::shared_ptr<TypesCache> typesCache;
    };

}// namespace speculo::gen
