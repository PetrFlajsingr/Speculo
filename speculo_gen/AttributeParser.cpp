//
// Created by xflajs00 on 17.03.2023.
//

#include "AttributeParser.hpp"

#include <iostream>
#include <spdlog/spdlog.h>

#include "clang_utils.hpp"
#include "wrap/clang_ast_recursiveASTVisitor.hpp"
#include "wrap/clang_lex_PreprocessorOptions.hpp"
#include <flat/flat_map.hpp>

#include "algorithms/contains.hpp"
#include <speculo/details/array.hpp>
// FIXME: deduplicate code
namespace speculo::gen {

    AttributeParser::AttributeParser(clang::ASTContext &astContext, clang::syntax::TokenBuffer &&tokBuff)
        : sourceManager{astContext.getSourceManager()}, tokenBuffer{std::move(tokBuff)} {
        tokens.reserve(1000);
        for (const auto &token: tokenBuffer.expandedTokens()) {
            if (!astContext.getSourceManager().isInMainFile(token.location())) { continue; }
            tokens.push_back(token);
        }

        allTokensRange = TokensRange{tokens.begin(), tokens.end()};
    }

    AttributeParser::EnumAttributes AttributeParser::parseEnumAttributes(clang::ASTContext &astContext, const clang::EnumDecl &decl) const {
        EnumAttributes result{};

        auto srcRange = decl.getSourceRange();

        auto enumTypeAttributes = parseEnumTypeAttributes(astContext, srcRange);
        result.attributes = std::move(enumTypeAttributes.attributes);

        srcRange.setBegin(enumTypeAttributes.end);
        result.valueAttributes = parseEnumValueAttributes(astContext, srcRange);

        return result;
    }

    std::vector<Attribute> AttributeParser::parseRecordAttributes(clang::ASTContext &astContext, const clang::CXXRecordDecl &decl) const {
        std::vector<Attribute> result{};

        auto tokensRange = sourceRangeToTokensRange(decl.getSourceRange());
        if (!tokensRange.has_value()) { return {}; }

        // skipping `class` or `struct`
        if ((tokensRange->begin()->kind() == clang::tok::raw_identifier || tokensRange->begin()->kind() == clang::tok::identifier) &&
            contains(speculo::make_array<std::string_view>("struct", "class"),
                     std::string_view{tokensRange->begin()->text(sourceManager)})) {
            ++tokensRange->begin_;
        }

        bool foundAttributes;
        do {
            foundAttributes = false;
            if (const auto start = FindAttributesStart(astContext, *tokensRange); start.has_value()) {
                if (Contains(TokensRange{tokensRange->begin(), *start},
                             speculo::make_array<clang::tok::TokenKind>(clang::tok::raw_identifier, clang::tok::identifier))) {
                    // found class name, thus we're out of class type's attributes
                    break;
                }
                if (const auto end = FindAttributesEnd(astContext, TokensRange{*start, tokensRange->end()}); end.has_value()) {
                    std::ranges::copy(ParseAttributes(astContext, TokensRange{*start, *end}), std::back_inserter(result));
                    tokensRange = TokensRange{*end, tokensRange->end()};
                    foundAttributes = true;
                }
            }
        } while (foundAttributes);

        return MinimizeAttributes(result);
    }

    std::vector<Attribute> AttributeParser::parseFieldAttributes(clang::ASTContext &astContext, const clang::FieldDecl &decl) const {
        return parseVariableAttributes(astContext, decl.getSourceRange());
    }

    std::vector<Attribute> AttributeParser::parseFieldAttributes(clang::ASTContext &astContext, const clang::VarDecl &decl) const {
        return parseVariableAttributes(astContext, decl.getSourceRange());
    }

    AttributeParser::FunctionLikeAttributes AttributeParser::parseFunctionAttributes(clang::ASTContext &astContext,
                                                                                     const clang::CXXMethodDecl &decl) const {
        fc::vector_map<std::string, clang::SourceRange> argSourceRanges;
        argSourceRanges.container.reserve(decl.parameters().size());
        std::ranges::transform(decl.parameters(), std::back_inserter(argSourceRanges.container), [](const auto &param) {
            return std::pair<std::string, clang::SourceRange>{param->getNameAsString(), param->getSourceRange()};
        });
        return parseFunctionLikeAttributes(astContext, decl.getSourceRange(), argSourceRanges);
    }

    AttributeParser::FunctionLikeAttributes AttributeParser::parseConstructorAttributes(clang::ASTContext &astContext,
                                                                                        const clang::CXXConstructorDecl &decl) const {
        fc::vector_map<std::string, clang::SourceRange> argSourceRanges;
        argSourceRanges.container.reserve(decl.parameters().size());
        std::ranges::transform(decl.parameters(), std::back_inserter(argSourceRanges.container), [](const auto &param) {
            return std::pair<std::string, clang::SourceRange>{param->getNameAsString(), param->getSourceRange()};
        });
        return parseFunctionLikeAttributes(astContext, decl.getSourceRange(), argSourceRanges);
    }

    AttributeParser::FunctionLikeAttributes AttributeParser::parseDestructorAttributes(clang::ASTContext &astContext,
                                                                                       const clang::CXXDestructorDecl &decl) const {
        return parseFunctionLikeAttributes(astContext, decl.getSourceRange(), {});
    }

    AttributeParser::EnumTypeAttributeParseResult AttributeParser::parseEnumTypeAttributes(clang::ASTContext &astContext,
                                                                                           clang::SourceRange srcRange) const {
        EnumTypeAttributeParseResult result;

        auto tokenRange = sourceRangeToTokensRange(srcRange);
        if (!tokenRange.has_value()) { return {}; }
        tokenRange = TokensRange{tokenRange->begin(), tokenRange->end()};
        // skipping `enum`
        if ((tokenRange->begin()->kind() == clang::tok::raw_identifier || tokenRange->begin()->kind() == clang::tok::identifier) &&
            tokenRange->begin()->text(sourceManager) == "enum") {
            ++tokenRange->begin_;
        }
        // skipping `class` or `struct`
        if ((tokenRange->begin()->kind() == clang::tok::raw_identifier || tokenRange->begin()->kind() == clang::tok::identifier) &&
            contains(speculo::make_array<std::string_view>("struct", "class"),
                     std::string_view{tokenRange->begin()->text(sourceManager)})) {
            ++tokenRange->begin_;
        }

        bool foundAttributes;
        do {
            foundAttributes = false;
            if (const auto start = FindAttributesStart(astContext, *tokenRange); start.has_value()) {
                if (Contains(TokensRange{tokenRange->begin(), *start},
                             speculo::make_array<clang::tok::TokenKind>(clang::tok::raw_identifier, clang::tok::identifier))) {
                    // found enum name, thus we're out of enum type's attributes
                    break;
                }
                if (const auto end = FindAttributesEnd(astContext, TokensRange{*start, tokenRange->end()}); end.has_value()) {
                    std::ranges::copy(ParseAttributes(astContext, TokensRange{*start, *end}), std::back_inserter(result.attributes));
                    tokenRange = TokensRange{*end, tokenRange->end()};
                    foundAttributes = true;
                }
            }
        } while (foundAttributes);
        result.end = srcRange.getBegin();
        result.attributes = MinimizeAttributes(result.attributes);
        return result;
    }

    fc::vector_map<std::string, std::vector<Attribute>> AttributeParser::parseEnumValueAttributes(clang::ASTContext &astContext,
                                                                                                  clang::SourceRange srcRange) const {
        fc::vector_map<std::string, std::vector<Attribute>> result;

        auto tokensRange = sourceRangeToTokensRange(srcRange);
        if (!tokensRange.has_value()) { return result; }

        // advance to l_brace
        {
            auto iter = tokensRange->begin();
            bool foundRSquare = false;
            bool foundLSquare = false;
            bool inAttrs = false;
            std::size_t attributeDepth{};
            while (inAttrs || iter->kind() != clang::tok::l_brace) {
                ++iter;
                if (iter->kind() == clang::tok::r_square) {
                    if (foundRSquare) {
                        --attributeDepth;
                        if (attributeDepth == 0) { inAttrs = false; }
                        foundRSquare = false;
                    } else {
                        foundRSquare = true;
                    }
                } else {
                    foundRSquare = false;
                }
                if (iter->kind() == clang::tok::l_square) {
                    if (foundLSquare) {
                        ++attributeDepth;
                        inAttrs = true;
                        foundLSquare = false;
                    } else {
                        foundLSquare = true;
                    }
                } else {
                    foundLSquare = false;
                }
            }
            // FIXME: this catches stuff inside attributes as well
            if (iter >= tokensRange->end()) { return result; }
            tokensRange = TokensRange{iter, tokensRange->end()};
        }

        for (;;) {
            bool foundValue = true;
            auto iter = tokensRange->begin();
            while (iter->kind() != clang::tok::raw_identifier && iter->kind() != clang::tok::identifier) {
                ++iter;
                if (iter >= tokensRange->end() || iter->kind() == clang::tok::eof) {
                    foundValue = false;
                    break;
                }
            }
            if (!foundValue) { break; }
            tokensRange = TokensRange{iter, tokensRange->end()};

            const auto spelling = iter->text(sourceManager);
            std::pair<std::string, std::vector<Attribute>> valueAttributes{spelling, std::vector<Attribute>{}};

            bool foundAttributes;
            do {
                foundAttributes = false;
                if (const auto start = FindAttributesStart(astContext, *tokensRange); start.has_value()) {
                    if (Contains(TokensRange{tokensRange->begin(), *start},
                                 speculo::make_array<clang::tok::TokenKind>(clang::tok::comma, clang::tok::r_brace))) {
                        // found value divider, these attributes belong to a different value
                        break;
                    }
                    if (const auto end = FindAttributesEnd(astContext, TokensRange{*start, tokensRange->end()}); end.has_value()) {
                        std::ranges::copy(ParseAttributes(astContext, TokensRange{*start, *end}),
                                          std::back_inserter(valueAttributes.second));
                        tokensRange = TokensRange{*end, tokensRange->end()};
                        foundAttributes = true;
                    }
                }
            } while (foundAttributes);
            // skipping current identifier or comma
            ++tokensRange->begin_;
            result.emplace(std::move(valueAttributes));
        }
        std::ranges::for_each(result.container, [](auto &element) { element.second = MinimizeAttributes(element.second); });
        return result;
    }

    std::optional<AttributeParser::TokensIter> AttributeParser::FindAttributesStart([[maybe_unused]] clang::ASTContext &astContext,
                                                                                    const TokensRange &tokensRange) {
        auto iter = tokensRange.begin();
        if (iter == tokensRange.end()) { return std::nullopt; }
        bool foundLSquare = false;
        for (; iter != tokensRange.end(); ++iter) {
            if (iter->kind() == clang::tok::eof) { return std::nullopt; }
            if (foundLSquare && iter->kind() == clang::tok::l_square) {
                return iter;
            } else {
                foundLSquare = iter->kind() == clang::tok::l_square;
            }
        }
        return std::nullopt;
    }

    std::optional<AttributeParser::TokensIter> AttributeParser::FindAttributesEnd([[maybe_unused]] clang::ASTContext &astContext,
                                                                                  const TokensRange &tokensRange) {
        auto iter = tokensRange.begin();
        if (iter == tokensRange.end()) { return std::nullopt; }

        bool foundRSquare = false;
        std::size_t parensNestingCnt{};
        for (; iter != tokensRange.end(); ++iter) {
            if (iter->kind() == clang::tok::l_paren) {
                ++parensNestingCnt;
            } else if (iter->kind() == clang::tok::r_paren) {
                --parensNestingCnt;
            }
            if (parensNestingCnt == 0) {
                if (foundRSquare && iter->kind() == clang::tok::r_square) {
                    return iter;
                } else {
                    foundRSquare = iter->kind() == clang::tok::r_square;
                }
            } else {
                foundRSquare = false;
            }
        }
        return std::nullopt;
    }

    std::vector<Attribute> AttributeParser::ParseAttributes(clang::ASTContext &astContext, const TokensRange &tokensRange) {
        enum class State { Start, None, Using, UsingEnd, Name, Arguments, NestedParens };
        State state = State::Start;

        auto &sourceManager = astContext.getSourceManager();

        std::vector<Attribute> result;

        std::string attributeNamespace;
        std::string attributeName;
        std::vector<std::string> attributeParams;
        std::string attributeParam;
        std::size_t nestedParensCnt{};
        for (auto iter = tokensRange.begin(); iter != tokensRange.end(); ++iter) {
            const auto &token = *iter;
            switch (state) {
                case State::Start: {
                    if (token.kind() == clang::tok::raw_identifier || token.kind() == clang::tok::identifier) {
                        const auto spelling = token.text(sourceManager);
                        if (spelling == "using") {
                            state = State::Using;
                        } else {
                            state = State::Name;
                            attributeName = spelling;
                        }
                    }
                } break;
                case State::None: {
                    if (token.kind() == clang::tok::raw_identifier || token.kind() == clang::tok::identifier) {
                        state = State::Name;
                        attributeName = token.text(sourceManager);
                    }
                } break;
                case State::Using: {
                    attributeNamespace = token.text(sourceManager);
                    state = State::UsingEnd;
                } break;
                case State::UsingEnd: {
                    state = State::None;
                } break;
                case State::Name: {
                    if (token.kind() == clang::tok::coloncolon || token.kind() == clang::tok::raw_identifier ||
                        token.kind() == clang::tok::identifier) {
                        attributeName += token.text(sourceManager);
                        state = State::Name;
                    } else if (token.kind() == clang::tok::l_paren) {
                        state = State::Arguments;
                    } else {
                        if (!attributeNamespace.empty()) {
                            result.emplace_back(attributeNamespace, attributeName, attributeParams);
                        } else {
                            if (const auto nameIter =
                                        std::ranges::adjacent_find(attributeName, [](auto v1, auto v2) { return v1 == ':' && v2 == ':'; });
                                nameIter != attributeName.end()) {
                                const auto index = std::ranges::distance(attributeName.begin(), nameIter);
                                attributeNamespace = attributeName.substr(0, index);
                                attributeName = attributeName.substr(index + 2);
                            }
                            result.emplace_back(attributeNamespace, attributeName, attributeParams);
                            attributeNamespace.clear();
                        }
                        attributeParams.clear();
                        attributeName.clear();
                        state = State::None;
                    }
                } break;
                case State::Arguments: {
                    if (token.kind() == clang::tok::l_paren) {
                        nestedParensCnt = 1;
                        attributeParam.append(token.text(sourceManager));
                        state = State::NestedParens;
                    } else if (token.kind() == clang::tok::r_paren) {
                        if (!attributeParam.empty()) { attributeParams.emplace_back(attributeParam); }
                        if (!attributeNamespace.empty()) {
                            result.emplace_back(attributeNamespace, attributeName, attributeParams);
                        } else {
                            if (const auto nameIter =
                                        std::ranges::adjacent_find(attributeName, [](auto v1, auto v2) { return v1 == ':' && v2 == ':'; });
                                nameIter != attributeName.end()) {
                                const auto index = std::ranges::distance(attributeName.begin(), nameIter);
                                attributeNamespace = attributeName.substr(0, index);
                                attributeName = attributeName.substr(index + 2);
                            }
                            result.emplace_back(attributeNamespace, attributeName, attributeParams);
                            attributeNamespace.clear();
                        }
                        attributeParams.clear();
                        attributeParam.clear();
                        attributeName.clear();
                        state = State::None;
                    } else if (token.kind() == clang::tok::comma) {
                        if (!attributeParam.empty()) { attributeParams.emplace_back(attributeParam); }
                        attributeParam.clear();
                        state = State::Arguments;
                    } else {
                        attributeParam.append(token.text(sourceManager));
                        state = State::Arguments;
                    }
                } break;
                case State::NestedParens: {
                    if (token.kind() == clang::tok::l_paren) {
                        ++nestedParensCnt;
                        attributeParam.append(token.text(sourceManager));
                        state = State::NestedParens;
                    } else if (token.kind() == clang::tok::r_paren) {
                        attributeParam.append(token.text(sourceManager));
                        --nestedParensCnt;
                        if (nestedParensCnt == 0) {
                            state = State::Arguments;
                        } else {
                            state = State::NestedParens;
                        }
                    } else if (token.kind() == clang::tok::comma) {
                        if (!attributeParam.empty()) { attributeParams.emplace_back(attributeParam); }
                        attributeParam.clear();
                        state = State::Arguments;
                    } else {
                        attributeParam.append(token.text(sourceManager));
                        state = State::NestedParens;
                    }
                } break;
            }
        }
        return result;
    }

    std::vector<Attribute> AttributeParser::parseVariableAttributes(clang::ASTContext &astContext, clang::SourceRange srcRange) const {
        std::vector<Attribute> result{};

        TokensIter tokensBegin;
        // move as far to the left as possible to collect all attributes
        {
            constexpr auto stopTokens = speculo::make_array<clang::tok::TokenKind>(clang::tok::l_brace, clang::tok::r_brace,
                                                                                         clang::tok::colon, clang::tok::semi);
            auto beginLocation = srcRange.getBegin().getLocWithOffset(-1);

            auto iter = findNearestToken(beginLocation);
            if (iter == allTokensRange.end()) { return {}; }

            bool foundRSquare = false;
            bool foundLSquare = false;
            bool inAttrs = false;
            while (inAttrs || !contains(stopTokens, iter->kind())) {
                if (iter == allTokensRange.begin()) { break; }
                iter = std::ranges::prev(iter);
                if (iter->kind() == clang::tok::r_square) {
                    if (foundRSquare) {
                        inAttrs = true;
                        foundRSquare = false;
                    } else {
                        foundRSquare = true;
                    }
                } else {
                    foundRSquare = false;
                }
                if (iter->kind() == clang::tok::l_square) {
                    if (foundLSquare) {
                        inAttrs = false;
                        foundLSquare = false;
                    } else {
                        foundLSquare = true;
                    }
                } else {
                    foundLSquare = false;
                }
            }
            tokensBegin = iter;
        }

        TokensIter tokensEnd{};
        // move as far to the right as possible to collect trailing attributes
        {
            constexpr auto stopTokens = speculo::make_array<clang::tok::TokenKind>(clang::tok::l_brace, clang::tok::r_brace,
                                                                                         clang::tok::colon, clang::tok::semi);
            auto endLocation = srcRange.getEnd();

            auto iter = findNearestToken(endLocation);
            if (iter == allTokensRange.end()) { return {}; }
            bool foundRSquare = false;
            bool foundLSquare = false;
            bool inAttrs = false;
            while (inAttrs || !contains(stopTokens, iter->kind())) {
                ++iter;
                if (iter == allTokensRange.end()) { break; }
                if (iter->kind() == clang::tok::r_square) {
                    if (foundRSquare) {
                        inAttrs = false;
                        foundRSquare = false;
                    } else {
                        foundRSquare = true;
                    }
                } else {
                    foundRSquare = false;
                }
                if (iter->kind() == clang::tok::l_square) {
                    if (foundLSquare) {
                        inAttrs = true;
                        foundLSquare = false;
                    } else {
                        foundLSquare = true;
                    }
                } else {
                    foundLSquare = false;
                }
            }
            tokensEnd = iter;
        }

        auto tokensRange = TokensRange{tokensBegin, tokensEnd};
        bool foundAttributes;
        do {
            foundAttributes = false;
            if (const auto start = FindAttributesStart(astContext, tokensRange); start.has_value()) {
                if (const auto end = FindAttributesEnd(astContext, TokensRange{*start, tokensRange.end()}); end.has_value()) {
                    std::ranges::copy(ParseAttributes(astContext, TokensRange{*start, *end}), std::back_inserter(result));
                    tokensRange = TokensRange{*end, tokensRange.end()};
                    foundAttributes = true;
                }
            }
        } while (foundAttributes);


        return MinimizeAttributes(result);
    }

    AttributeParser::FunctionLikeAttributes
    AttributeParser::parseFunctionLikeAttributes(clang::ASTContext &astContext, clang::SourceRange srcRange,
                                                 const fc::vector_map<std::string, clang::SourceRange> &argumentSrcRanges) const {
        FunctionLikeAttributes result{};

        TokensIter tokensBegin;
        // move as far to the left as possible to collect all attributes
        {
            constexpr auto stopTokens = speculo::make_array<clang::tok::TokenKind>(clang::tok::l_brace, clang::tok::r_brace,
                                                                                         clang::tok::colon, clang::tok::semi);
            auto beginLocation = srcRange.getBegin();

            auto iter = findNearestToken(beginLocation);
            if (iter == allTokensRange.end()) { return {}; }

            bool foundRSquare = false;
            bool foundLSquare = false;
            bool inAttrs = false;
            while (inAttrs || !contains(stopTokens, iter->kind())) {
                if (iter == allTokensRange.begin()) { break; }
                iter = std::ranges::prev(iter);
                if (iter->kind() == clang::tok::r_square) {
                    if (foundRSquare) {
                        inAttrs = true;
                        foundRSquare = false;
                    } else {
                        foundRSquare = true;
                    }
                } else {
                    foundRSquare = false;
                }
                if (iter->kind() == clang::tok::l_square) {
                    if (foundLSquare) {
                        inAttrs = false;
                        foundLSquare = false;
                    } else {
                        foundLSquare = true;
                    }
                } else {
                    foundLSquare = false;
                }
            }
            tokensBegin = iter;
        }
        TokensIter tokensEnd;
        // move as far to the right as possible to collect trailing attributes
        {
            constexpr auto stopTokens = speculo::make_array<clang::tok::TokenKind>(clang::tok::l_brace, clang::tok::r_brace,
                                                                                         clang::tok::colon, clang::tok::semi);
            auto iter = findNearestToken(srcRange.getEnd());
            if (iter == allTokensRange.end()) { return {}; }

            bool foundRSquare = false;
            bool foundLSquare = false;
            bool inAttrs = false;
            while (inAttrs || !contains(stopTokens, iter->kind())) {
                ++iter;
                if (iter == allTokensRange.end()) { break; }
                if (iter->kind() == clang::tok::r_square) {
                    if (foundRSquare) {
                        inAttrs = false;
                        foundRSquare = false;
                    } else {
                        foundRSquare = true;
                    }
                } else {
                    foundRSquare = false;
                }
                if (iter->kind() == clang::tok::l_square) {
                    if (foundLSquare) {
                        inAttrs = true;
                        foundLSquare = false;
                    } else {
                        foundLSquare = true;
                    }
                } else {
                    foundLSquare = false;
                }
            }
            tokensEnd = iter;
        }
        auto tokensRange = TokensRange{tokensBegin, tokensEnd};

        bool inArguments = false;
        std::size_t argIndex{};

        bool foundAttributes;
        do {
            foundAttributes = false;
            if (const auto start = FindAttributesStart(astContext, tokensRange); start.has_value()) {
                {
                    const auto skippedRange = TokensRange{tokensRange.begin(), *start};
                    // if { is found we're entering function body
                    if (std::ranges::any_of(skippedRange, [](const auto &token) { return token.kind() == clang::tok::l_brace; })) { break; }

                    const auto wasInArguments = inArguments;
                    if (!inArguments) {
                        // find (
                        inArguments =
                                std::ranges::any_of(skippedRange, [](const auto &token) { return token.kind() == clang::tok::l_paren; });
                    } else {
                        // find )
                        inArguments =
                                std::ranges::all_of(skippedRange, [](const auto &token) { return token.kind() != clang::tok::r_paren; });
                    }
                    // only search for , when we're in args and entered them in one of the previous loops
                    if (inArguments && wasInArguments == inArguments) {
                        // move by the count of commas in the skipped range
                        argIndex += std::ranges::count(skippedRange, clang::tok::comma, &clang::syntax::Token::kind);
                    }
                }
                if (const auto end = FindAttributesEnd(astContext, TokensRange{*start, tokensRange.end()}); end.has_value()) {
                    tokensRange = TokensRange{*end, tokensRange.end()};
                    foundAttributes = true;
                    if (inArguments) {
                        std::ranges::copy(ParseAttributes(astContext, TokensRange{*start, *end}),
                                          std::back_inserter(result.argumentAttributes[argumentSrcRanges.container[argIndex].first]));
                    } else {
                        std::ranges::copy(ParseAttributes(astContext, TokensRange{*start, *end}), std::back_inserter(result.attributes));
                    }
                }
            }
        } while (foundAttributes);

        result.attributes = MinimizeAttributes(result.attributes);
        std::ranges::for_each(result.argumentAttributes.container, [](auto &el) { el.second = MinimizeAttributes(el.second); });
        return result;
    }

    std::optional<AttributeParser::TokensRange> AttributeParser::sourceRangeToTokensRange(const clang::SourceRange &srcRange) const {
        auto begin = findNearestToken(srcRange.getBegin());
        if (begin == allTokensRange.end()) { return std::nullopt; }
        auto end = findNearestToken(srcRange.getEnd());
        if (end == allTokensRange.end()) { return std::nullopt; }
        return TokensRange{begin, end};
    }

    std::vector<Attribute> AttributeParser::MinimizeAttributes(const std::vector<Attribute> &attrs) {
        fc::vector_map<std::string, std::vector<const Attribute *>> duplicates;
        std::ranges::for_each(attrs, [&](auto &attr) {
            const auto fullName = fmt::format("{}::{}", attr.nnamespace, attr.name);
            duplicates[fullName].emplace_back(&attr);
        });
        std::vector<Attribute> result{};
        result.reserve(duplicates.size());
        std::ranges::transform(duplicates, std::back_inserter(result), [&](const auto &v) {
            const auto &attributes = v.second;
            auto minAttr = *attributes.front();
            std::ranges::for_each(attributes.begin() + 1, attributes.end(),
                                  [&](const auto attr) { std::ranges::move(attr->arguments, std::back_inserter(minAttr.arguments)); });
            std::ranges::sort(minAttr.arguments);
            const auto uniqueRes = std::ranges::unique(minAttr.arguments);
            minAttr.arguments.erase(uniqueRes.begin(), uniqueRes.end());

            return minAttr;
        });
        return result;
    }


}// namespace speculo::gen