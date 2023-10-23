module;

#include "../wrap/clang_ast_qualtypenames.hpp"
#include <spdlog/spdlog.h>

module speculo.gen;
import :ast_enum_parser;
import :id_generator;
import :attribute_parser;
import :types_cache;
import :structs;
import :clang_utils;
import :type_info_factory;

namespace speculo::gen {
    ASTEnumParser::ASTEnumParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser,
                                 std::shared_ptr<TypesCache> cache)
        : ASTDeclParser{std::move(idGen), std::move(attribParser), std::move(cache)} {
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

        auto result = createEnumTypeInfo(astContext, definition);

        result.values = ParseEnumerators(definition->enumerators(), GetEnumValueCategory(definition), astContext.getSourceManager());

        fillAttributes(result, astContext, definition);

        populateIDs(result, *idGenerator);

        fillValueInfos(result);

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
                    value = enumerator->getInitVal().getZExtValue();
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

    void ASTEnumParser::fillValueInfos(EnumTypeInfo &type) {
        for (auto &[name, info]: type.values) {
            info.fullName = fmt::format("{}::{}", type.fullName, name);
            const auto valueId = idGenerator->generateId(info.fullName);
            info.id = valueId;
            info.sourceLocation.filename = type.sourceLocation->filename;
        }
    }


    EnumTypeInfo ASTEnumParser::createEnumTypeInfo(clang::ASTContext &astContext, clang::EnumDecl *enumDecl) {
        EnumTypeInfo result{};
        result.fullName = enumDecl->getQualifiedNameAsString();
        result.name = enumDecl->getNameAsString();

        result.originalCode = getSourceText(astContext, *enumDecl);

        result.sourceLocation.emplace(getSourceLocationInfo(astContext, *enumDecl));

        const auto underlyingTypeName = getProperQualifiedName(stripQualifiersAndPtrRefAliases(enumDecl->getIntegerType()), astContext);

        result.underlyingType = typesCache->getOrAdd(
                underlyingTypeName, [&](TypeInfoVariant &result) { result = getFundamentalTypeInfo(underlyingTypeName, *idGenerator); });

        result.size = astContext.getTypeSizeInChars(enumDecl->getIntegerType()).getQuantity();
        result.alignment = astContext.getTypeAlignInChars(enumDecl->getIntegerType()).getQuantity();
        result.isScoped = enumDecl->isScoped();
        return result;
    }

    void ASTEnumParser::fillAttributes(EnumTypeInfo &info, clang::ASTContext &astContext, clang::EnumDecl *enumDecl) {
        auto enumAttributes = attributeParser->parseEnumAttributes(astContext, *enumDecl);
        info.attributes = std::move(enumAttributes.attributes);

        for (auto [name, attributes]: enumAttributes.valueAttributes) {
            // FIXME: this lookup check should be unnecessary, but it is here due to a bug in AttributeParser::parseEnumValueAttributes
            if (const auto iter = info.values.find(name); iter != info.values.end()) { iter->second.attributes = std::move(attributes); }
        }
    }

    std::optional<std::string> ASTEnumParser::getFullTypeName(clang::ASTContext &astContext, clang::Decl *decl) {
        assert(clang::dyn_cast<clang::EnumDecl>(decl) != nullptr);

        const auto enumDecl = clang::cast<clang::EnumDecl>(decl);

        spdlog::trace("ASTEnumDeclParser: getting name of {}", enumDecl->getQualifiedNameAsString());

        // Skip if found decl is not definition
        const auto definition = enumDecl->getDefinition();
        if (definition != decl) {
            spdlog::trace("ASTEnumDeclParser: skipping, not a definition");
            return std::nullopt;
        }

        return definition->getQualifiedNameAsString();
    }


}// namespace speculo::gen