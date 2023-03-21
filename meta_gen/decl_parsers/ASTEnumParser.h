//
// Created by xflajs00 on 19.03.2023.
//

#pragma once

#include "ASTDeclParser.h"

namespace pf::meta_gen {

    class ASTEnumParser final : public ASTDeclParser {
    public:
        explicit ASTEnumParser(std::shared_ptr<IdGenerator> idGen);

        ~ASTEnumParser() override = default;

        std::optional<TypeInfoVariant> parse(clang::ASTContext &astContext, clang::Decl *decl) override;
    };

}