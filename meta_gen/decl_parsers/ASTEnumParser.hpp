//
// Created by xflajs00 on 19.03.2023.
//

#pragma once

#include "ASTDeclParser.hpp"

namespace pf::meta_gen {

    class ASTEnumParser final : public ASTDeclParser {
    public:
        ASTEnumParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser, ParsedTypesCache &cache);

        ~ASTEnumParser() override = default;

        std::optional<TypeInfoVariant> parse(clang::ASTContext &astContext, clang::Decl *decl) override;
    };

}// namespace pf::meta_gen