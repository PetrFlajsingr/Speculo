//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

#include <pf_common/macros.h>

#include "clang_tooling_wrap.h"

#include "info_structs.h"

namespace pf::meta_gen {

    class AttributeParser {
    public:
        struct EnumAttributes {
            std::vector <Attribute> attributes;
            std::unordered_map <std::string, std::vector<Attribute>> valueAttributes;
        };

        [[nodiscard]] EnumAttributes
        parseEnumAttributes(clang::ASTContext &astContext, const clang::EnumDecl &decl) const;

    private:
        struct EnumTypeAttributeParseResult {
            std::vector <Attribute> attributes;
            clang::SourceLocation end;
        };

        [[nodiscard]] EnumTypeAttributeParseResult
        parseEnumTypeAttributes(clang::ASTContext &astContext, clang::SourceRange srcRange) const;

        [[nodiscard]] std::unordered_map <std::string, std::vector<Attribute>>
        parseEnumValueAttributes(clang::ASTContext &astContext,
                                 clang::SourceRange srcRange) const;

        [[nodiscard]] std::optional <clang::SourceLocation> findAttributesStart(clang::ASTContext &astContext,
                                                                                const clang::SourceRange &srcRange) const;

        [[nodiscard]] std::optional <clang::SourceLocation> findAttributesEnd(clang::ASTContext &astContext,
                                                                              const clang::SourceRange &srcRange) const;

        [[nodiscard]] std::vector <Attribute>
        parseAttributes(clang::ASTContext &astContext, const clang::SourceRange &srcRange) const;

        [[nodiscard]] clang::SourceLocation
        advanceByTokens(clang::ASTContext &astContext, const clang::SourceLocation &loc,
                        std::size_t count) const;

        [[nodiscard]] std::optional <clang::Token>
        getToken(clang::ASTContext &astContext, const clang::SourceLocation &loc) const;
    };




} // pf::meta_gen