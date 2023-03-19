//
// Created by xflajs00 on 18.03.2023.
//

#include "ASTParser.h"
#include "AttributeParser.h"
#include "IdGenerator.h"

#include "decl_parsers/decl_parser_factory.h"

namespace pf::meta_gen {

    ASTParser::ASTParser(ParsingSettings parsingSettings, std::shared_ptr<IdGenerator> idGen)
        : settings{parsingSettings}, idGenerator{std::move(idGen)} {}

    std::vector<std::variant<EnumTypeInfo>> ASTParser::parse(clang::ASTContext &astContext) {
        auto tuCtx = astContext.getTranslationUnitDecl();
        return walk(astContext, *tuCtx);
    }

    std::vector<std::variant<EnumTypeInfo>> ASTParser::walk(clang::ASTContext &astContext, const clang::DeclContext &context) {
        std::vector<std::variant<EnumTypeInfo>> result{};
        for (auto it = context.decls_begin(); it != context.decls_end(); ++it) {
            clang::Decl *decl = *it;
            if (decl->isInvalidDecl()) { continue; }
            auto &sourceManager = astContext.getSourceManager();
            if (settings.ignoreIncludes && !sourceManager.isInMainFile(decl->getLocation())) { continue; }

            if (auto parser = createDeclParser(decl, idGenerator); parser != nullptr) {
                if (auto parseResult = parser->parse(astContext, decl); parseResult.has_value()) {
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