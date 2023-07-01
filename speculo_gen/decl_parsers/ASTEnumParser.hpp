//
// Created by xflajs00 on 19.03.2023.
//

#pragma once

#include "ASTDeclParser.hpp"

namespace speculo::gen {

    class ASTEnumParser final : public ASTDeclParser {
    public:
        ASTEnumParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser, ParsedTypesCache &cache);

        ~ASTEnumParser() override = default;

        std::optional<TypeInfoVariant> parse(clang::ASTContext &astContext, clang::Decl *decl) override;

    private:
        enum class EnumValueCategory { Bool, Signed, Unsigned };

        [[nodiscard]] static std::unordered_map<std::string, EnumTypeInfo::ValueInfo>
        ParseEnumerators(const clang::EnumDecl::enumerator_range &src, EnumValueCategory valueCategory,
                         clang::SourceManager &sourceManager);
        void fillValueInfos(std::unordered_map<std::string, EnumTypeInfo::ValueInfo> &valueInfos, const EnumTypeInfo &type);
        [[nodiscard]] std::shared_ptr<EnumTypeInfo> createEnumTypeInfo(clang::ASTContext &astContext, clang::EnumDecl *enumDecl);
        void fillAttributes(EnumTypeInfo &info, clang::ASTContext &astContext, clang::EnumDecl *enumDecl);

        [[nodiscard]] std::shared_ptr<FundamentalTypeInfo> getUnderlyingType(const std::string &underlyingTypeName);

        [[nodiscard]] static EnumValueCategory GetEnumValueCategory(const clang::EnumDecl *decl);
    };

}// namespace speculo::gen