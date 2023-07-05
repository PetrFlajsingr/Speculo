//
// Created by xflajs00 on 19.03.2023.
//

#pragma once

#include "ASTDeclParser.hpp"

namespace speculo::gen {

    class ASTEnumParser final : public ASTDeclParser {
    public:
        ASTEnumParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser,
                      std::shared_ptr<ParsedTypesCache> cache);

        ~ASTEnumParser() override = default;

        [[nodiscard]] std::optional<std::string> getFullTypeName(clang::ASTContext &astContext, clang::Decl *decl) override;
        [[nodiscard]] std::optional<TypeInfoVariant> parse(clang::ASTContext &astContext, clang::Decl *decl) override;

    private:
        enum class EnumValueCategory { Bool, Signed, Unsigned };

        [[nodiscard]] static std::unordered_map<std::string, EnumTypeInfo::ValueInfo>
        ParseEnumerators(const clang::EnumDecl::enumerator_range &src, EnumValueCategory valueCategory,
                         clang::SourceManager &sourceManager);
        void fillValueInfos(EnumTypeInfo &type);
        [[nodiscard]] EnumTypeInfo createEnumTypeInfo(clang::ASTContext &astContext, clang::EnumDecl *enumDecl);
        void fillAttributes(EnumTypeInfo &info, clang::ASTContext &astContext, clang::EnumDecl *enumDecl);


        [[nodiscard]] static EnumValueCategory GetEnumValueCategory(const clang::EnumDecl *decl);
    };

}// namespace speculo::gen