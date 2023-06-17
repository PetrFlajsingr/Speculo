//
// Created by xflajs00 on 18.03.2023.
//

#include "ASTParser.hpp"
#include "AttributeParser.hpp"
#include "IdGenerator.hpp"

#include "decl_parsers/factory.hpp"
#include "wrap/clang_frontend_compilerinstance.hpp"

namespace pf::meta_gen {

    ASTParser::ASTParser(const SourceConfig *c, std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser)
        : config{c}, idGenerator{std::move(idGen)}, attributeParser{std::move(attribParser)} {}

    std::vector<TypeInfoVariant> ASTParser::parse(clang::ASTContext &astContext) {
        auto tuCtx = astContext.getTranslationUnitDecl();
        return walk(astContext, *tuCtx);
    }

    std::vector<TypeInfoVariant> ASTParser::walk(clang::ASTContext &astContext, const clang::DeclContext &context) {
        std::vector<TypeInfoVariant> result{};
        for (auto it = context.decls_begin(); it != context.decls_end(); ++it) {
            clang::Decl *decl = *it;
            //if (decl->isInvalidDecl()) { continue; }
            auto &sourceManager = astContext.getSourceManager();
            if (config->ignoreIncludes && !sourceManager.isInMainFile(decl->getLocation())) { continue; }

            if (auto parser = createDeclParser(astContext, decl, idGenerator, attributeParser, typesCache); parser != nullptr) {
                if (auto parseResult = parser->parse(astContext, decl); parseResult.has_value()) {
                    typesCache.add(*parseResult);
                    result.emplace_back(std::move(*parseResult));
                }
            }

            // going inside scope
            const auto declContext = clang::dyn_cast<clang::DeclContext>(decl);
            if (declContext) {
                auto subResult = walk(astContext, *declContext);
                std::ranges::move(subResult, std::back_inserter(result));
            }
        }
        return result;
    }
}// namespace pf::meta_gen