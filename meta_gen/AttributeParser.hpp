//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

#include "wrap/clang_tooling.hpp"

#include "info_structs.hpp"
#include "wrap/clang_frontend_compilerinstance.hpp"
#include "wrap/clang_tooling_syntax_tokens.hpp"
#include <flat/flat_map.hpp>

#include <meta/details/RangeOf.hpp>

namespace pf::meta_gen {

    class AttributeParser {
    public:
        /**
         * Caches file's tokens.
         */
        AttributeParser(clang::ASTContext &astContext, clang::syntax::TokenBuffer &&tokBuff);

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
        clang::SourceManager &sourceManager;

        struct EnumTypeAttributeParseResult {
            std::vector<Attribute> attributes;
            clang::SourceLocation end;
        };

        clang::syntax::TokenBuffer tokenBuffer;
        // TODO: main file tokens only
        std::vector<clang::syntax::Token> tokens;
        using TokensIter = typename decltype(tokens)::iterator;

        struct TokensRange {
            TokensIter begin_;
            TokensIter end_;
            TokensRange() : begin_{}, end_{} {}
            TokensRange(TokensIter b, TokensIter e) : begin_{b}, end_{e} { assert(begin_ <= end_); }

            [[nodiscard]] TokensIter begin() const {
                assert(begin_ <= end_);
                return begin_;
            }

            [[nodiscard]] TokensIter end() const {
                assert(begin_ <= end_);
                return end_;
            }
        };

        TokensRange allTokensRange;

        [[nodiscard]] std::vector<Attribute> parseVariableAttributes(clang::ASTContext &astContext, clang::SourceRange srcRange) const;

        [[nodiscard]] static std::vector<Attribute> MinimizeAttributes(const std::vector<Attribute> &attrs);

        [[nodiscard]] FunctionLikeAttributes
        parseFunctionLikeAttributes(clang::ASTContext &astContext, clang::SourceRange srcRange,
                                    const fc::vector_map<std::string, clang::SourceRange> &argumentSrcRanges) const;

        [[nodiscard]] EnumTypeAttributeParseResult parseEnumTypeAttributes(clang::ASTContext &astContext,
                                                                           clang::SourceRange srcRange) const;

        [[nodiscard]] fc::vector_map<std::string, std::vector<Attribute>> parseEnumValueAttributes(clang::ASTContext &astContext,
                                                                                                   clang::SourceRange srcRange) const;

        [[nodiscard]] static std::optional<TokensIter> FindAttributesStart([[maybe_unused]] clang::ASTContext &astContext,
                                                                           const TokensRange &tokensRange);

        [[nodiscard]] static std::optional<TokensIter> FindAttributesEnd(clang::ASTContext &astContext, const TokensRange &tokensRange);

        [[nodiscard]] static std::vector<Attribute> ParseAttributes(clang::ASTContext &astContext, const TokensRange &tokensRange);


        [[nodiscard]] std::optional<TokensRange> sourceRangeToTokensRange(const clang::SourceRange &srcRange) const;

        [[nodiscard]] static bool Contains(TokensRange range, meta::details::RangeOf<clang::tok::TokenKind> auto &&kinds) {
            return std::ranges::any_of(
                    range, [&](const auto &token) { return std::ranges::find(kinds, token.kind()) != std::ranges::end(kinds); });
        }

        [[nodiscard]] TokensIter findNearestToken(const clang::SourceLocation &sourceLocation) const {
            if (tokens.empty()) { return allTokensRange.end(); }

            auto nearest = allTokensRange.begin();
            auto nearestDiff = std::numeric_limits<std::uint64_t>::max();
            for (auto iter = allTokensRange.begin(); iter != allTokensRange.end() - 1; ++iter) {
                if (iter->location() == sourceLocation) { return iter; }

                const auto diff = iter->location().getRawEncoding() - sourceLocation.getRawEncoding();
                if (diff < nearestDiff) {
                    nearestDiff = diff;
                    nearest = iter;
                }
            }
            return nearest;
        }
    };


}// namespace pf::meta_gen
