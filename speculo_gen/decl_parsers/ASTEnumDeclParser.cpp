//
// Created by xflajs00 on 19.03.2023.
//

#include "../AttributeParser.hpp"
#include "ASTEnumParser.hpp"

#include "../clang_utils.hpp"
#include "../wrap/clang_ast_qualtypenames.hpp"
#include <spdlog/spdlog.h>

#include "details/FundamentalTypeInfos.hpp"

namespace speculo::gen {
    ASTEnumParser::ASTEnumParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser, ParsedTypesCache &cache)
        : ASTDeclParser{std::move(idGen), std::move(attribParser), cache} {
        spdlog::trace("Creating ASTEnumDeclParser");
    }

    std::optional<TypeInfoVariant> ASTEnumParser::parse(clang::ASTContext &astContext, clang::Decl *decl) {
        assert(clang::dyn_cast<clang::EnumDecl>(decl) != nullptr);

        const auto enumDecl = clang::cast<clang::EnumDecl>(decl);

        spdlog::trace("ASTEnumDeclParser: parsing {}", enumDecl->getQualifiedNameAsString());

        // Skip if found decl is not definition
        const auto definition = enumDecl->getDefinition();
        if (definition != decl) {
            spdlog::trace("ASTEnumDeclParser: skipping, not a definition");
            return std::nullopt;
        }

        auto result = createEnumTypeInfo(astContext, enumDecl);

        result->values = ParseEnumerators(enumDecl->enumerators(), GetEnumValueCategory(enumDecl), astContext.getSourceManager());

        fillAttributes(*result, astContext, enumDecl);

        populateIDs(*result, getIdGenerator());

        fillValueInfos(result->values, *result);

        return result;
    }

    std::unordered_map<std::string, EnumTypeInfo::ValueInfo> ASTEnumParser::ParseEnumerators(const clang::EnumDecl::enumerator_range &src,
                                                                                             EnumValueCategory valueCategory,
                                                                                             clang::SourceManager &sourceManager) {
        auto result = std::unordered_map<std::string, EnumTypeInfo::ValueInfo>{};
        for (const auto &enumerator: src) {
            std::variant<bool, std::uint64_t, std::int64_t> value;
            switch (valueCategory) {
                using enum EnumValueCategory;
                case Bool: {
                    value = enumerator->getInitVal().getBoolValue();
                    spdlog::trace("ASTEnumDeclParser: detected bool as underlying type");
                } break;
                case Signed: {
                    value = enumerator->getInitVal().getSExtValue();
                    spdlog::trace("ASTEnumDeclParser: detected signed int as underlying type");
                } break;
                case Unsigned: {
                    value = enumerator->getInitVal().getExtValue();
                    spdlog::trace("ASTEnumDeclParser: detected unsigned int as underlying type");
                } break;
            }
            const auto line = sourceManager.getPresumedLineNumber(enumerator->getSourceRange().getBegin());
            const auto column = sourceManager.getPresumedColumnNumber(enumerator->getSourceRange().getBegin());
            result.emplace(enumerator->getNameAsString(), EnumTypeInfo::ValueInfo{speculo::ID{}, "", value, {}, {line, column}});
        }
        return result;
    }

    ASTEnumParser::EnumValueCategory ASTEnumParser::GetEnumValueCategory(const clang::EnumDecl *decl) {
        using enum EnumValueCategory;
        const auto integerType = decl->getIntegerType();
        if (integerType->isBooleanType()) { return Bool; }
        if (integerType->isSignedIntegerType()) { return Signed; }
        if (integerType->isUnsignedIntegerType()) { return Unsigned; }
        spdlog::error("Unexpected internal type of enum");
        return {};
    }

    void ASTEnumParser::fillValueInfos(std::unordered_map<std::string, EnumTypeInfo::ValueInfo> &valueInfos, const EnumTypeInfo &type) {
        for (auto &[name, info]: valueInfos) {
            info.fullName = fmt::format("{}::{}", type.fullName, name);
            const auto valueId = getIdGenerator().generateId(info.fullName);
            info.id = valueId;
            info.sourceLocation.filename = type.sourceLocation->filename;
        }
    }


    std::shared_ptr<EnumTypeInfo> ASTEnumParser::createEnumTypeInfo(clang::ASTContext &astContext, clang::EnumDecl *enumDecl) {
        auto result = std::make_shared<EnumTypeInfo>();
        result->fullName = enumDecl->getQualifiedNameAsString();
        result->name = enumDecl->getNameAsString();

        result->originalCode = getSourceText(astContext, *enumDecl);

        result->sourceLocation.emplace(getSourceLocationInfo(astContext, *enumDecl));

        const auto underlyingTypeName = getProperQualifiedName(enumDecl->getIntegerType(), astContext);

        result->underlyingType = {getUnderlyingType(underlyingTypeName), TypeForm::Normal, underlyingTypeName};
        result->size = astContext.getTypeSizeInChars(enumDecl->getIntegerType()).getQuantity();
        result->alignment = astContext.getTypeAlignInChars(enumDecl->getIntegerType()).getQuantity();
        result->isScoped = enumDecl->isScoped();
        return result;
    }

    void ASTEnumParser::fillAttributes(EnumTypeInfo &info, clang::ASTContext &astContext, clang::EnumDecl *enumDecl) {
        auto enumAttributes = getAttributeParser().parseEnumAttributes(astContext, *enumDecl);
        info.attributes = std::move(enumAttributes.attributes);

        for (auto [name, attributes]: enumAttributes.valueAttributes) { info.values[name].attributes = std::move(attributes); }
    }

    std::shared_ptr<FundamentalTypeInfo> ASTEnumParser::getUnderlyingType(const std::string &underlyingTypeName) {
        std::shared_ptr<FundamentalTypeInfo> underlyingType;
        if (auto type = getTypesCache().get<FundamentalTypeInfo>(underlyingTypeName); type.has_value()) {
            underlyingType = std::move(*type);
        } else {
            underlyingType = std::make_shared<FundamentalTypeInfo>(getFundamentalTypeInfo(underlyingTypeName));
            getTypesCache().add(underlyingType);
        }
        return underlyingType;
    }
}// namespace speculo::gen