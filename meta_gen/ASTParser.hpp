//
// Created by xflajs00 on 18.03.2023.
//

#pragma once

#include <variant>
#include <vector>

#include "AttributeParser.hpp"
#include "IdGenerator.hpp"
#include "ParsedTypesCache.hpp"
#include "SourceConfig.hpp"
#include "wrap/clang_tooling.hpp"
#include "info_structs.hpp"

namespace pf::meta_gen {

    class ASTParser {
    public:
        ASTParser(const SourceConfig *c, std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser);

        [[nodiscard]] std::vector<TypeInfoVariant> parse(clang::ASTContext &astContext);

    private:
        [[nodiscard]] std::vector<TypeInfoVariant> walk(clang::ASTContext &astContext, const clang::DeclContext &context);

        const SourceConfig *config;
        std::shared_ptr<IdGenerator> idGenerator;
        std::shared_ptr<AttributeParser> attributeParser;

        ParsedTypesCache typesCache;
    };

}// namespace pf::meta_gen
