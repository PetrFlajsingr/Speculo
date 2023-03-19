//
// Created by xflajs00 on 19.03.2023.
//

#pragma once

#include "ASTDeclParser.h"

namespace pf::meta_gen {

    class ASTEnumDeclParser final : public ASTDeclParser {
    public:
        explicit ASTEnumDeclParser(std::shared_ptr<IdGenerator> idGen);
        ~ASTEnumDeclParser() override = default;

        std::optional<TypeInfoVariant> parse(clang::ASTContext &astContext, clang::Decl *decl) override;
    };

}