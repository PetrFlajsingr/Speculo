//
// Created by xflajs00 on 19.03.2023.
//

#include "ASTRecordParser.h"
#include "../AttributeParser.h"

#include <spdlog/spdlog.h>

namespace pf::meta_gen {

    ASTRecordParser::ASTRecordParser(std::shared_ptr<IdGenerator> idGen) : ASTDeclParser(idGen) {}

    std::optional<TypeInfoVariant> ASTRecordParser::parse(clang::ASTContext &astContext, clang::Decl *decl) {
        assert(clang::dyn_cast<clang::CXXRecordDecl>(decl) != nullptr);
        const auto recordDecl = clang::cast<clang::CXXRecordDecl>(decl);

        spdlog::info("ASTRecordParser: parsing {}", recordDecl->getQualifiedNameAsString());

        // Skip if found decl is not definition
        const auto definition = recordDecl->getDefinition();
        if (definition != decl) {
            spdlog::info("ASTRecordParser: skipping, not a definition");
            return std::nullopt;
        }
        if (recordDecl->isAnonymousStructOrUnion()) {
            spdlog::info("ASTRecordParser: skipping, anonymous struct or union");
            return std::nullopt;
        }

        RecordTypeInfo result{};

        result.fullName = recordDecl->getQualifiedNameAsString();
        result.name = recordDecl->getNameAsString();

        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        auto printingPolicy = clang::PrintingPolicy{langOpts};

        result.sourceLocation.line = sourceManager.getPresumedLineNumber(recordDecl->getSourceRange().getBegin());
        result.sourceLocation.column = sourceManager.getPresumedColumnNumber(recordDecl->getSourceRange().getBegin());
        result.sourceLocation.filename = sourceManager.getFilename(recordDecl->getSourceRange().getBegin());

        //TODO: result.attributes = AttributeParser{}.parseRecordAttributes(astContext, *recordDecl);

        result.isUnion = recordDecl->isUnion();

        // recordDecl->fields()
        // recordDecl->methods()
        // recordDecl->ctors()
        // recordDecl->friends()?
        // recordDecl->bases()
        // recordDecl->vbases()

        return result;
    }

}// namespace pf::meta_gen