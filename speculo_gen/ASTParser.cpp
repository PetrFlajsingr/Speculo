//
// Created by xflajs00 on 18.03.2023.
//

#include "ASTParser.hpp"
#include "AttributeParser.hpp"
#include "IdGenerator.hpp"

#include "decl_parsers/details/IncompleteTypeInfos.hpp"
#include "decl_parsers/factory.hpp"
#include "spdlog/spdlog.h"
#include "wrap/clang_frontend_compilerinstance.hpp"

namespace speculo::gen {

    ASTParser::ASTParser(const SourceConfig *c, std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser)
        : config{c}, idGenerator{std::move(idGen)}, attributeParser{std::move(attribParser)},
          typesCache{std::make_shared<ParsedTypesCache>()} {}

    std::vector<TypeInfoVariant> ASTParser::parse(clang::ASTContext &astContext) {
        auto tuCtx = astContext.getTranslationUnitDecl();
        return walk(astContext, *tuCtx);
    }

    std::vector<TypeInfoVariant> ASTParser::walk(clang::ASTContext &astContext, const clang::DeclContext &context) {
        std::vector<TypeInfoVariant> result{};
        for (const auto decl: context.decls()) {
            //if (decl->isInvalidDecl()) { continue; }
            auto &sourceManager = astContext.getSourceManager();
            if (config->ignoreIncludes && !sourceManager.isInMainFile(decl->getLocation())) { continue; }

            if (auto parser = createDeclParser(astContext, decl, idGenerator, attributeParser, typesCache); parser != nullptr) {
                if (auto fullTypeName = parser->getFullTypeName(astContext, decl); fullTypeName.has_value()) {
                    auto cacheType = std::make_shared<TypeInfoVariant>();
                    typesCache->add(*fullTypeName, cacheType);

                    if (auto parseResult = parser->parse(astContext, decl); parseResult.has_value()) {
                        *cacheType = std::move(*parseResult);
                    } else {
                        spdlog::debug("Unexpected code path triggered in ASTParser {0:x}", 0x9EFB2820);
                        *cacheType = getIncompleteTypeInfo(*fullTypeName, *idGenerator);
                    }
                    result.emplace_back(*cacheType);
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
}// namespace speculo::gen