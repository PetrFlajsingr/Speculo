//
// Created by xflajs00 on 19.03.2023.
//

#include "../AttributeParser.h"
#include "ASTEnumParser.h"

#include <spdlog/spdlog.h>

namespace pf::meta_gen {
    ASTEnumParser::ASTEnumParser(std::shared_ptr<IdGenerator> idGen) : ASTDeclParser{std::move(idGen)} {
        spdlog::info("Creating ASTEnumDeclParser");
    }

    std::optional<TypeInfoVariant> ASTEnumParser::parse(clang::ASTContext &astContext, clang::Decl *decl) {
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
        result.fullName = enumDecl->getQualifiedNameAsString();
        result.name = enumDecl->getNameAsString();

        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        auto printingPolicy = clang::PrintingPolicy{langOpts};


        result.sourceLocation.line = sourceManager.getPresumedLineNumber(enumDecl->getSourceRange().getBegin());
        result.sourceLocation.column = sourceManager.getPresumedColumnNumber(enumDecl->getSourceRange().getBegin());
        result.sourceLocation.filename = sourceManager.getFilename(enumDecl->getSourceRange().getBegin());

        result.underlyingType = enumDecl->getIntegerType().getAsString(printingPolicy);

        for (const auto &enumerator: enumDecl->enumerators()) {
            std::variant<bool, std::uint64_t, std::int64_t> value;
            if (enumDecl->getIntegerType()->isBooleanType()) {
                value = enumerator->getInitVal().getBoolValue();
                spdlog::info("ASTEnumDeclParser: detected bool as underlying type");
            } else if (enumDecl->getIntegerType()->isSignedIntegerType()) {
                value = enumerator->getInitVal().getSExtValue();
                spdlog::info("ASTEnumDeclParser: detected signed int as underlying type");
            } else if (enumDecl->getIntegerType()->isUnsignedIntegerType()) {
                value = enumerator->getInitVal().getExtValue();
                spdlog::info("ASTEnumDeclParser: detected unsigned int as underlying type");
            }
            const auto line = sourceManager.getPresumedLineNumber(enumerator->getSourceRange().getBegin());
            const auto column = sourceManager.getPresumedColumnNumber(enumerator->getSourceRange().getBegin());
            result.values.emplace(enumerator->getNameAsString(),
                                  EnumTypeInfo::ValueInfo{pf::meta::details::ID::Invalid(), "", value, {},
                                                          {line, column}});
        }

        {
            AttributeParser attributeParser{};
            auto enumAttributes = attributeParser.parseEnumAttributes(astContext, *enumDecl);
            result.attributes = std::move(enumAttributes.attributes);

            for (auto [name, attributes]: enumAttributes.valueAttributes) {
                result.values[name].attributes = std::move(attributes);
            }
        }

        const auto typeId = getIdGenerator().generateId(result.fullName);
        result.id = typeId;

        for (auto &[name, info]: result.values) {
            info.fullName = fmt::format("{}::{}", result.fullName, name);
            const auto valueId = getIdGenerator().generateId(info.fullName);
            info.id = valueId;
        }

        return result;
    }
}// namespace pf::meta_gen