//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

#include <pf_common/macros.h>

#include "clang_tooling_wrap.hpp"

#include "info_structs.hpp"
#include <flat/flat_map.hpp>
#include <pf_common/concepts/ranges.h>

namespace pf::meta_gen {

    class AttributeParser {
    public:
        /**
         * Caches file's tokens.
         */
        explicit AttributeParser(clang::ASTContext &astContext);

        struct EnumAttributes {
            std::vector<Attribute> attributes;
            fc::vector_map<std::string, std::vector<Attribute>> valueAttributes;
        };
        struct FunctionLikeAttributes {
            std::vector<Attribute> attributes;
            fc::vector_map<std::string, std::vector<Attribute>> argumentAttributes;
        };

        [[nodiscard]] EnumAttributes parseEnumAttributes(clang::ASTContext &astContext, const clang::EnumDecl &decl) const;

        [[nodiscard]] std::vector<Attribute> parseRecordAttributes(clang::ASTContext &astContext, const clang::CXXRecordDecl &decl) const;

        [[nodiscard]] std::vector<Attribute> parseFieldAttributes(clang::ASTContext &astContext, const clang::FieldDecl &decl) const;

        [[nodiscard]] std::vector<Attribute> parseFieldAttributes(clang::ASTContext &astContext, const clang::VarDecl &decl) const;

        [[nodiscard]] FunctionLikeAttributes parseFunctionAttributes(clang::ASTContext &astContext, const clang::CXXMethodDecl &decl) const;

        [[nodiscard]] FunctionLikeAttributes parseConstructorAttributes(clang::ASTContext &astContext,
                                                                        const clang::CXXConstructorDecl &decl) const;

        [[nodiscard]] FunctionLikeAttributes parseDestructorAttributes(clang::ASTContext &astContext,
                                                                       const clang::CXXDestructorDecl &decl) const;

    private:
        struct EnumTypeAttributeParseResult {
            std::vector<Attribute> attributes;
            clang::SourceLocation end;
        };

        std::vector<clang::Token> tokens;
        using TokensIter = typename decltype(tokens)::iterator;

        struct TokensRange {
            TokensIter begin_;
            TokensIter end_;

            [[nodiscard]] TokensIter begin() const { return begin_; }

            [[nodiscard]] TokensIter end() const { return end_; }
        };

        TokensRange allTokensRange;

        [[nodiscard]] std::vector<Attribute> parseVariableAttributes(clang::ASTContext &astContext, clang::SourceRange srcRange) const;

        [[nodiscard]] FunctionLikeAttributes
        parseFunctionLikeAttributes(clang::ASTContext &astContext, clang::SourceRange srcRange,
                                    const fc::vector_map<std::string, clang::SourceRange> &argumentSrcRanges) const;

        [[nodiscard]] EnumTypeAttributeParseResult parseEnumTypeAttributes(clang::ASTContext &astContext,
                                                                           clang::SourceRange srcRange) const;

        [[nodiscard]] fc::vector_map<std::string, std::vector<Attribute>> parseEnumValueAttributes(clang::ASTContext &astContext,
                                                                                                   clang::SourceRange srcRange) const;

        [[nodiscard]] static std::optional<TokensIter> findAttributesStart([[maybe_unused]] clang::ASTContext &astContext,
                                                                           const TokensRange &tokensRange);

        [[nodiscard]] static std::optional<TokensIter> findAttributesEnd(clang::ASTContext &astContext, const TokensRange &tokensRange);

        [[nodiscard]] static std::vector<Attribute> parseAttributes(clang::ASTContext &astContext, const TokensRange &tokensRange);

        [[nodiscard]] static clang::SourceLocation advanceByTokens(clang::ASTContext &astContext, const clang::SourceLocation &loc,
                                                                   std::size_t count);

        [[nodiscard]] static std::optional<clang::Token> getToken(clang::ASTContext &astContext, const clang::SourceLocation &loc);

        [[nodiscard]] std::optional<TokensRange> sourceRangeToTokensRange(const clang::SourceRange &srcRange) const;

        [[nodiscard]] static bool contains(TokensRange range, pf::RangeOf<clang::tok::TokenKind> auto &&kinds) {
            return std::ranges::any_of(
                    range, [&](const auto &token) { return std::ranges::find(kinds, token.getKind()) != std::ranges::end(kinds); });
        }

        [[nodiscard]] TokensIter findNearestToken(const clang::SourceLocation &sourceLocation) const {
            if (tokens.empty()) { return allTokensRange.end(); }
            for (auto iter = allTokensRange.begin(); iter != allTokensRange.end() - 1; ++iter) {
                if (iter->getLocation() == sourceLocation) { return iter; }
                if (std::ranges::next(iter)->getLocation() > sourceLocation) { return iter; }
            }
            return allTokensRange.end() - 1;
        }
    };


}// namespace pf::meta_gen
