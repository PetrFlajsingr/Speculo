//
// Created by xflajs00 on 19.03.2023.
//

#include "ASTEnumDeclParser.h"
#include "../AttributeParser.h"

#include <spdlog/spdlog.h>

namespace pf::meta_gen {
    ASTEnumDeclParser::ASTEnumDeclParser(std::shared_ptr<IdGenerator> idGen) : ASTDeclParser{std::move(idGen)} {
        spdlog::info("Creating ASTEnumDeclParser");
    }

    std::optional<TypeInfoVariant> ASTEnumDeclParser::parse(clang::ASTContext &astContext, clang::Decl *decl) {
        assert(clang::dyn_cast<clang::EnumDecl>(decl) != nullptr);

        const auto enumDecl = clang::cast<clang::EnumDecl>(decl);

        spdlog::info("ASTEnumDeclParser: parsing {}", enumDecl->getQualifiedNameAsString());

        // Skip if found decl is not definition
        const auto definition = enumDecl->getDefinition();
        if (definition != decl) {
            spdlog::info("ASTEnumDeclParser: skipping, not a definition");
            return std::nullopt;
        }

        EnumTypeInfo result{};
        result.fullName = definition->getQualifiedNameAsString();
        result.name = definition->getNameAsString();

        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        auto printingPolicy = clang::PrintingPolicy{langOpts};


        result.sourceLocation.line = sourceManager.getPresumedLineNumber(definition->getSourceRange().getBegin());
        result.sourceLocation.column = sourceManager.getPresumedColumnNumber(definition->getSourceRange().getBegin());
        result.sourceLocation.filename = sourceManager.getFilename(definition->getSourceRange().getBegin());

        result.underlyingType = definition->getIntegerType().getAsString(printingPolicy);

        for (const auto &enumerator: definition->enumerators()) {
            std::variant<bool, std::uint64_t, std::int64_t> value;
            if (definition->getIntegerType()->isBooleanType()) {
                value = enumerator->getInitVal().getBoolValue();
                spdlog::info("ASTEnumDeclParser: detected bool as underlying type");
            } else if (definition->getIntegerType()->isSignedIntegerType()) {
                value = enumerator->getInitVal().getSExtValue();
                spdlog::info("ASTEnumDeclParser: detected signed int as underlying type");
            } else if (definition->getIntegerType()->isUnsignedIntegerType()) {
                value = enumerator->getInitVal().getExtValue();
                spdlog::info("ASTEnumDeclParser: detected unsigned int as underlying type");
            }
            const auto line = sourceManager.getPresumedLineNumber(enumerator->getSourceRange().getBegin());
            const auto column = sourceManager.getPresumedColumnNumber(enumerator->getSourceRange().getBegin());
            result.values.emplace(enumerator->getNameAsString(),
                                  EnumTypeInfo::ValueInfo{pf::meta::details::ID::Invalid(), "", value, {}, {line, column}});
        }

        {
            AttributeParser attributeParser{};
            auto enumAttributes = attributeParser.parseEnumAttributes(astContext, *enumDecl);
            result.attributes = std::move(enumAttributes.attributes);

            for (auto [name, attributes]: enumAttributes.valueAttributes) { result.values[name].attributes = std::move(attributes); }
        }

        const auto typeId = getIdGenerator().generateTypeId(result.fullName);
        result.id = typeId;

        for (auto &[name, info]: result.values) {
            info.fullName = fmt::format("{}::{}", result.fullName, name);
            const auto valueId = getIdGenerator().generateTypeId(info.fullName);
            info.id = valueId;
        }

        return result;
    }
}// namespace pf::meta_gen