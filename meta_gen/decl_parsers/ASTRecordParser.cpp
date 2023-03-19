//
// Created by xflajs00 on 19.03.2023.
//

#include "ASTRecordParser.h"

#include <spdlog/spdlog.h>

namespace pf::meta_gen {

    ASTRecordParser::ASTRecordParser(std::shared_ptr<IdGenerator> idGen) : ASTDeclParser(idGen) {}

    std::optional<TypeInfoVariant> ASTRecordParser::parse(clang::ASTContext &astContext, clang::Decl *decl) {
        assert(clang::dyn_cast<clang::RecordDecl>(decl) != nullptr);
        const auto recordDecl = clang::cast<clang::RecordDecl>(decl);

        spdlog::info("ASTRecordParser: parsing {}", recordDecl->getQualifiedNameAsString());

        // Skip if found decl is not definition
        const auto definition = recordDecl->getDefinition();
        if (definition != decl) {
            spdlog::info("ASTRecordParser: skipping, not a definition");
            return std::nullopt;
        }

        RecordTypeInfo result{};
    }

}// namespace pf