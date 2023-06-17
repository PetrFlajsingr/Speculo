//
// Created by xflajs00 on 19.03.2023.
//

#include "../AttributeParser.hpp"
#include "ASTEnumParser.hpp"

#include "../wrap/clang_ast_qualtypenames.hpp"
#include <spdlog/spdlog.h>

namespace pf::meta_gen {
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

        auto result = std::make_shared<EnumTypeInfo>();
        result->fullName = enumDecl->getQualifiedNameAsString();
        result->name = enumDecl->getNameAsString();

        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        auto printingPolicy = clang::PrintingPolicy{langOpts};

        result->originalCode =
                clang::Lexer::getSourceText(clang::CharSourceRange::getTokenRange(enumDecl->getSourceRange()), sourceManager, langOpts)
                        .str();


        result->sourceLocation.line = sourceManager.getPresumedLineNumber(enumDecl->getSourceRange().getBegin());
        result->sourceLocation.column = sourceManager.getPresumedColumnNumber(enumDecl->getSourceRange().getBegin());
        result->sourceLocation.filename = sourceManager.getFilename(enumDecl->getSourceRange().getBegin());

        result->underlyingType = clang::TypeName::getFullyQualifiedName(enumDecl->getIntegerType(), astContext, printingPolicy);
        result->size = astContext.getTypeSizeInChars(enumDecl->getIntegerType()).getQuantity();
        result->alignment = astContext.getTypeAlignInChars(enumDecl->getIntegerType()).getQuantity();
        result->isScoped = enumDecl->isScoped();

        for (const auto &enumerator: enumDecl->enumerators()) {
            std::variant<bool, std::uint64_t, std::int64_t> value;
            if (enumDecl->getIntegerType()->isBooleanType()) {
                value = enumerator->getInitVal().getBoolValue();
                spdlog::trace("ASTEnumDeclParser: detected bool as underlying type");
            } else if (enumDecl->getIntegerType()->isSignedIntegerType()) {
                value = enumerator->getInitVal().getSExtValue();
                spdlog::trace("ASTEnumDeclParser: detected signed int as underlying type");
            } else if (enumDecl->getIntegerType()->isUnsignedIntegerType()) {
                value = enumerator->getInitVal().getExtValue();
                spdlog::trace("ASTEnumDeclParser: detected unsigned int as underlying type");
            }
            const auto line = sourceManager.getPresumedLineNumber(enumerator->getSourceRange().getBegin());
            const auto column = sourceManager.getPresumedColumnNumber(enumerator->getSourceRange().getBegin());
            result->values.emplace(enumerator->getNameAsString(),
                                   EnumTypeInfo::ValueInfo{pf::meta::ID{}, "", value, {}, {line, column}});
        }

        {
            auto enumAttributes = getAttributeParser().parseEnumAttributes(astContext, *enumDecl);
            result->attributes = std::move(enumAttributes.attributes);

            for (auto [name, attributes]: enumAttributes.valueAttributes) { result->values[name].attributes = std::move(attributes); }
        }

        result->id = getIdGenerator().generateId(result->fullName);
        result->constId = getIdGenerator().generateId("const " + result->fullName);
        result->lrefId = getIdGenerator().generateId(result->fullName + " &");
        result->rrefId = getIdGenerator().generateId(result->fullName + " &&");
        result->constLrefId = getIdGenerator().generateId("const " + result->fullName + " &");
        result->ptrId = getIdGenerator().generateId(result->fullName + " *");
        result->constPtrId = getIdGenerator().generateId("const" + result->fullName + " *");
        result->volatileId = getIdGenerator().generateId("volatile " + result->fullName);
        result->volatileConstId = getIdGenerator().generateId("volatile const " + result->fullName);
        result->volatileLrefId = getIdGenerator().generateId("volatile " + result->fullName + " &");
        result->volatileRrefId = getIdGenerator().generateId("volatile " + result->fullName + " &&");
        result->volatileConstLrefId = getIdGenerator().generateId("volatile const " + result->fullName + " &");
        result->volatilePtrId = getIdGenerator().generateId("volatile " + result->fullName + " *");
        result->volatileConstPtrId = getIdGenerator().generateId("volatile const" + result->fullName + " *");

        for (auto &[name, info]: result->values) {
            info.fullName = fmt::format("{}::{}", result->fullName, name);
            const auto valueId = getIdGenerator().generateId(info.fullName);
            info.id = valueId;
            info.sourceLocation.filename = result->sourceLocation.filename;
        }

        return result;
    }
}// namespace pf::meta_gen