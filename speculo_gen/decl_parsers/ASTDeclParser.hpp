//
// Created by xflajs00 on 19.03.2023.
//

#pragma once

#include "../AttributeParser.hpp"
#include "../IdGenerator.hpp"
#include "../ParsedTypesCache.hpp"
#include "../info_structs.hpp"
#include "../wrap/clang_tooling.hpp"

#include <memory>
#include <optional>

namespace speculo::gen {

    class ASTDeclParser {
    public:
        ASTDeclParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser,
                      std::shared_ptr<ParsedTypesCache> cache);

        virtual ~ASTDeclParser() = 0;

        [[nodiscard]] virtual std::optional<TypeInfoVariant> parse(clang::ASTContext &astContext, clang::Decl *decl) = 0;

    protected:
        std::shared_ptr<IdGenerator> idGenerator;
        std::shared_ptr<AttributeParser> attributeParser;
        std::shared_ptr<ParsedTypesCache> typesCache;
    };

}// namespace speculo::gen
