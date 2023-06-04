//
// Created by xflajs00 on 19.03.2023.
//

#pragma once

#include "../AttributeParser.hpp"
#include "../IdGenerator.hpp"
#include "../ParsedTypesCache.hpp"
#include "../clang_tooling_wrap.hpp"
#include "../info_structs.hpp"

#include <memory>
#include <optional>

namespace pf::meta_gen {

    class ASTDeclParser {
    public:
        ASTDeclParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser, ParsedTypesCache &cache);

        virtual ~ASTDeclParser() = 0;

        [[nodiscard]] virtual std::optional<TypeInfoVariant> parse(clang::ASTContext &astContext, clang::Decl *decl) = 0;

    protected:
        [[nodiscard]] IdGenerator &getIdGenerator() { return *idGenerator; }
        [[nodiscard]] AttributeParser &getAttributeParser() { return *attributeParser; }
        [[nodiscard]] ParsedTypesCache &getTypesCache() { return typesCache; }

    private:
        std::shared_ptr<IdGenerator> idGenerator;
        std::shared_ptr<AttributeParser> attributeParser;
        ParsedTypesCache &typesCache;
    };

}// namespace pf::meta_gen
