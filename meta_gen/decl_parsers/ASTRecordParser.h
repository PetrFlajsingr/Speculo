//
// Created by xflajs00 on 19.03.2023.
//

#pragma once

#include "ASTDeclParser.h"

namespace pf::meta_gen {
    class ASTRecordParser final : public ASTDeclParser {
    public:
        explicit ASTRecordParser(std::shared_ptr<IdGenerator> idGen);

        ~ASTRecordParser() override = default;

        std::optional<TypeInfoVariant> parse(clang::ASTContext &astContext, clang::Decl *decl) override;
    };

}// namespace pf
