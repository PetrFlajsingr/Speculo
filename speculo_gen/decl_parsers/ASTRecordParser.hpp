//
// Created by xflajs00 on 19.03.2023.
//

#pragma once

#include "ASTDeclParser.hpp"

namespace speculo::gen {
    class ASTRecordParser final : public ASTDeclParser {
    public:
        ASTRecordParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser, ParsedTypesCache &cache);

        ~ASTRecordParser() override = default;

        std::optional<TypeInfoVariant> parse(clang::ASTContext &astContext, clang::Decl *decl) override;

    private:


        [[nodiscard]] static bool ShouldSkipConstructor(const clang::CXXRecordDecl *recordDecl, const clang::CXXConstructorDecl *ctor);
    };

}// namespace speculo::gen
