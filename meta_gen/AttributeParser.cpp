//
// Created by xflajs00 on 17.03.2023.
//

#include "AttributeParser.hpp"

#include <pf_common/algorithms.h>
#include <pf_common/array.h>

#include <spdlog/spdlog.h>

#include "clang_utils.hpp"

// FIXME: deduplicate code
namespace pf::meta_gen {

    AttributeParser::AttributeParser(clang::ASTContext &astContext) {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        const auto fileId = sourceManager.getMainFileID();
        const auto *fileEntry = sourceManager.getFileEntryForID(fileId);
        if (fileEntry == nullptr) { return; }
        const auto fileBeginLoc = sourceManager.getLocForStartOfFile(fileId);
        auto token = clang::Lexer::findNextToken(fileBeginLoc, sourceManager, langOpts);
        if (!token.has_value()) { return; }
        tokens.emplace_back(*token);
        for (;;) {
            if (token = clang::Lexer::findNextToken(token->getLocation(), sourceManager, langOpts); token.has_value()) {
                if (token->getKind() == clang::tok::TokenKind::eof) { break; }
                tokens.emplace_back(*token);
            } else {
                break;
            }
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

        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

        auto tokensRange = sourceRangeToTokensRange(decl.getSourceRange());
        if (!tokensRange.has_value()) { return {}; }

        // skipping `class` or `struct`
        if (tokensRange->begin()->getKind() == clang::tok::TokenKind::raw_identifier &&
            pf::contains(pf::make_array<std::string_view>("struct", "class"),
                         clang::Lexer::getSpelling(*tokensRange->begin(), sourceManager, langOpts))) {
            ++tokensRange->begin_;
        }

        bool foundAttributes;
        do {
            foundAttributes = false;
            if (const auto start = findAttributesStart(astContext, *tokensRange); start.has_value()) {
                if (contains(TokensRange{tokensRange->begin(), *start},
                             pf::make_array<clang::tok::TokenKind>(clang::tok::TokenKind::raw_identifier))) {
                    // found class name, thus we're out of class type's attributes
                    break;
                }
                if (const auto end = findAttributesEnd(astContext, TokensRange{*start, tokensRange->end()}); end.has_value()) {
                    std::ranges::copy(parseAttributes(astContext, TokensRange{*start, *end}), std::back_inserter(result));
                    tokensRange = TokensRange{*end, tokensRange->end()};
                    foundAttributes = true;
                }
            }
        } while (foundAttributes);

        return result;
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

        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

        auto tokenRange = sourceRangeToTokensRange(srcRange);
        if (!tokenRange.has_value()) { return {}; }
        tokenRange = TokensRange{tokenRange->begin(), tokenRange->end()};
        // skipping `enum`
        if (tokenRange->begin()->getKind() == clang::tok::TokenKind::raw_identifier &&
            clang::Lexer::getSpelling(*tokenRange->begin(), sourceManager, langOpts) == "enum") {
            ++tokenRange->begin_;
        }
        // skipping `class` or `struct`
        if (tokenRange->begin()->getKind() == clang::tok::TokenKind::raw_identifier &&
            pf::contains(pf::make_array<std::string_view>("struct", "class"),
                         clang::Lexer::getSpelling(*tokenRange->begin(), sourceManager, langOpts))) {
            ++tokenRange->begin_;
        }

        bool foundAttributes;
        do {
            foundAttributes = false;
            if (const auto start = findAttributesStart(astContext, *tokenRange); start.has_value()) {
                if (contains(TokensRange{tokenRange->begin(), *start},
                             pf::make_array<clang::tok::TokenKind>(clang::tok::TokenKind::raw_identifier))) {
                    // found enum name, thus we're out of enum type's attributes
                    break;
                }
                if (const auto end = findAttributesEnd(astContext, TokensRange{*start, tokenRange->end()}); end.has_value()) {
                    std::ranges::copy(parseAttributes(astContext, TokensRange{*start, *end}), std::back_inserter(result.attributes));
                    tokenRange = TokensRange{*end, tokenRange->end()};
                    foundAttributes = true;
                }
            }
        } while (foundAttributes);
        result.end = srcRange.getBegin();
        return result;
    }

    fc::vector_map<std::string, std::vector<Attribute>> AttributeParser::parseEnumValueAttributes(clang::ASTContext &astContext,
                                                                                                  clang::SourceRange srcRange) const {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

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
            while (inAttrs || iter->getKind() != clang::tok::TokenKind::l_brace) {
                ++iter;
                if (iter->getKind() == clang::tok::TokenKind::r_square) {
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
                if (iter->getKind() == clang::tok::TokenKind::l_square) {
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
            while (iter->getKind() != clang::tok::TokenKind::raw_identifier) {
                ++iter;
                if (iter >= tokensRange->end() || iter->getKind() == clang::tok::TokenKind::eof) {
                    foundValue = false;
                    break;
                }
            }
            if (!foundValue) { break; }
            tokensRange = TokensRange{iter, tokensRange->end()};

            const auto spelling = clang::Lexer::getSpelling(*iter, sourceManager, langOpts);
            std::pair<std::string, std::vector<Attribute>> valueAttributes{spelling, {}};

            bool foundAttributes;
            do {
                foundAttributes = false;
                if (const auto start = findAttributesStart(astContext, *tokensRange); start.has_value()) {
                    if (contains(TokensRange{tokensRange->begin(), *start},
                                 pf::make_array<clang::tok::TokenKind>(clang::tok::TokenKind::comma, clang::tok::TokenKind::r_brace))) {
                        // found value divider, these attributes belong to a different value
                        break;
                    }
                    if (const auto end = findAttributesEnd(astContext, TokensRange{*start, tokensRange->end()}); end.has_value()) {
                        std::ranges::copy(parseAttributes(astContext, TokensRange{*start, *end}),
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

        return result;
    }

    std::optional<AttributeParser::TokensIter> AttributeParser::findAttributesStart([[maybe_unused]] clang::ASTContext &astContext,
                                                                                    const TokensRange &tokensRange) {
        auto iter = tokensRange.begin();
        if (iter == tokensRange.end()) { return std::nullopt; }
        bool foundLSquare = false;
        for (; iter != tokensRange.end(); ++iter) {
            if (iter->getKind() == clang::tok::TokenKind::eof) { return std::nullopt; }
            if (foundLSquare && iter->getKind() == clang::tok::TokenKind::l_square) {
                return iter;
            } else {
                foundLSquare = iter->getKind() == clang::tok::TokenKind::l_square;
            }
        }
        return std::nullopt;
    }

    std::optional<AttributeParser::TokensIter> AttributeParser::findAttributesEnd([[maybe_unused]] clang::ASTContext &astContext,
                                                                                  const TokensRange &tokensRange) {
        auto iter = tokensRange.begin();
        if (iter == tokensRange.end()) { return std::nullopt; }

        bool foundRSquare = false;
        std::size_t parensNestingCnt{};
        for (; iter != tokensRange.end(); ++iter) {
            if (iter->getKind() == clang::tok::TokenKind::l_paren) {
                ++parensNestingCnt;
            } else if (iter->getKind() == clang::tok::TokenKind::r_paren) {
                --parensNestingCnt;
            }
            if (parensNestingCnt == 0) {
                if (foundRSquare && iter->getKind() == clang::tok::TokenKind::r_square) {
                    return iter;
                } else {
                    foundRSquare = iter->getKind() == clang::tok::TokenKind::r_square;
                }
            } else {
                foundRSquare = false;
            }
        }
        return std::nullopt;
    }

    std::vector<Attribute> AttributeParser::parseAttributes(clang::ASTContext &astContext, const TokensRange &tokensRange) {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

        enum class State { Start, None, Using, UsingEnd, Name, Arguments, NestedParens };
        State state = State::Start;

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
                    if (token.getKind() == clang::tok::TokenKind::raw_identifier) {
                        const auto spelling = clang::Lexer::getSpelling(token, sourceManager, langOpts);
                        if (spelling == "using") {
                            state = State::Using;
                        } else {
                            state = State::Name;
                            attributeName = spelling;
                        }
                    }
                } break;
                case State::None: {
                    if (token.getKind() == clang::tok::TokenKind::raw_identifier) {
                        state = State::Name;
                        attributeName = clang::Lexer::getSpelling(token, sourceManager, langOpts);
                    }
                } break;
                case State::Using: {
                    attributeNamespace = clang::Lexer::getSpelling(token, sourceManager, langOpts);
                    state = State::UsingEnd;
                } break;
                case State::UsingEnd: {
                    state = State::None;
                } break;
                case State::Name: {
                    if (token.getKind() == clang::tok::TokenKind::coloncolon || token.getKind() == clang::tok::TokenKind::raw_identifier) {
                        attributeName += clang::Lexer::getSpelling(token, sourceManager, langOpts);
                        state = State::Name;
                    } else if (token.getKind() == clang::tok::TokenKind::l_paren) {
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
                    if (token.getKind() == clang::tok::TokenKind::l_paren) {
                        nestedParensCnt = 1;
                        attributeParam.append(clang::Lexer::getSpelling(token, sourceManager, langOpts));
                        state = State::NestedParens;
                    } else if (token.getKind() == clang::tok::TokenKind::r_paren) {
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
                    } else if (token.getKind() == clang::tok::TokenKind::comma) {
                        if (!attributeParam.empty()) { attributeParams.emplace_back(attributeParam); }
                        attributeParam.clear();
                        state = State::Arguments;
                    } else {
                        attributeParam.append(clang::Lexer::getSpelling(token, sourceManager, langOpts));
                        state = State::Arguments;
                    }
                } break;
                case State::NestedParens: {
                    if (token.getKind() == clang::tok::TokenKind::l_paren) {
                        ++nestedParensCnt;
                        attributeParam.append(clang::Lexer::getSpelling(token, sourceManager, langOpts));
                        state = State::NestedParens;
                    } else if (token.getKind() == clang::tok::TokenKind::r_paren) {
                        attributeParam.append(clang::Lexer::getSpelling(token, sourceManager, langOpts));
                        --nestedParensCnt;
                        if (nestedParensCnt == 0) {
                            state = State::Arguments;
                        } else {
                            state = State::NestedParens;
                        }
                    } else if (token.getKind() == clang::tok::TokenKind::comma) {
                        if (!attributeParam.empty()) { attributeParams.emplace_back(attributeParam); }
                        attributeParam.clear();
                        state = State::Arguments;
                    } else {
                        attributeParam.append(clang::Lexer::getSpelling(token, sourceManager, langOpts));
                        state = State::NestedParens;
                    }
                } break;
            }
        }
        return result;
    }

    clang::SourceLocation AttributeParser::advanceByTokens(clang::ASTContext &astContext, const clang::SourceLocation &loc,
                                                           std::size_t count) {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        auto token = clang::Lexer::findNextToken(loc, sourceManager, langOpts);
        for (std::size_t i = 0; i < count - 1; ++i) { token = clang::Lexer::findNextToken(token->getLocation(), sourceManager, langOpts); }
        return token->getLocation();
    }

    std::optional<clang::Token> AttributeParser::getToken(clang::ASTContext &astContext, const clang::SourceLocation &loc) {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        return clang::Lexer::findNextToken(loc, sourceManager, langOpts);
    }

    std::vector<Attribute> AttributeParser::parseVariableAttributes(clang::ASTContext &astContext, clang::SourceRange srcRange) const {
        std::vector<Attribute> result{};

        TokensIter tokensBegin;
        // move as far to the left as possible to collect all attributes
        {
            constexpr auto stopTokens = make_array<clang::tok::TokenKind>(clang::tok::TokenKind::l_brace, clang::tok::TokenKind::r_brace,
                                                                          clang::tok::TokenKind::colon, clang::tok::TokenKind::semi);
            auto beginLocation = srcRange.getBegin().getLocWithOffset(-1);

            auto iter = findNearestToken(beginLocation);
            if (iter == allTokensRange.end()) { return {}; }

            bool foundRSquare = false;
            bool foundLSquare = false;
            bool inAttrs = false;
            while (inAttrs || !pf::contains(stopTokens, iter->getKind())) {
                if (iter == allTokensRange.begin()) { break; }
                iter = std::ranges::prev(iter);
                if (iter->getKind() == clang::tok::TokenKind::r_square) {
                    if (foundRSquare) {
                        inAttrs = true;
                        foundRSquare = false;
                    } else {
                        foundRSquare = true;
                    }
                } else {
                    foundRSquare = false;
                }
                if (iter->getKind() == clang::tok::TokenKind::l_square) {
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
            constexpr auto stopTokens = make_array<clang::tok::TokenKind>(clang::tok::TokenKind::l_brace, clang::tok::TokenKind::r_brace,
                                                                          clang::tok::TokenKind::colon, clang::tok::TokenKind::semi);
            auto endLocation = srcRange.getEnd();

            auto iter = findNearestToken(endLocation);
            if (iter == allTokensRange.end()) { return {}; }
            bool foundRSquare = false;
            bool foundLSquare = false;
            bool inAttrs = false;
            while (inAttrs || !pf::contains(stopTokens, iter->getKind())) {
                ++iter;
                if (iter == allTokensRange.end()) { break; }
                if (iter->getKind() == clang::tok::TokenKind::r_square) {
                    if (foundRSquare) {
                        inAttrs = false;
                        foundRSquare = false;
                    } else {
                        foundRSquare = true;
                    }
                } else {
                    foundRSquare = false;
                }
                if (iter->getKind() == clang::tok::TokenKind::l_square) {
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
            if (const auto start = findAttributesStart(astContext, tokensRange); start.has_value()) {
                if (const auto end = findAttributesEnd(astContext, TokensRange{*start, tokensRange.end()}); end.has_value()) {
                    std::ranges::copy(parseAttributes(astContext, TokensRange{*start, *end}), std::back_inserter(result));
                    tokensRange = TokensRange{*end, tokensRange.end()};
                    foundAttributes = true;
                }
            }
        } while (foundAttributes);


        return result;
    }

    AttributeParser::FunctionLikeAttributes
    AttributeParser::parseFunctionLikeAttributes(clang::ASTContext &astContext, clang::SourceRange srcRange,
                                                 const fc::vector_map<std::string, clang::SourceRange> &argumentSrcRanges) const {
        FunctionLikeAttributes result{};

        TokensIter tokensBegin;
        // move as far to the left as possible to collect all attributes
        {
            constexpr auto stopTokens = make_array<clang::tok::TokenKind>(clang::tok::TokenKind::l_brace, clang::tok::TokenKind::r_brace,
                                                                          clang::tok::TokenKind::colon, clang::tok::TokenKind::semi);
            auto beginLocation = srcRange.getBegin();

            auto iter = findNearestToken(beginLocation);
            if (iter == allTokensRange.end()) { return {}; }

            bool foundRSquare = false;
            bool foundLSquare = false;
            bool inAttrs = false;
            while (inAttrs || !pf::contains(stopTokens, iter->getKind())) {
                if (iter == allTokensRange.begin()) { break; }
                iter = std::ranges::prev(iter);
                if (iter->getKind() == clang::tok::TokenKind::r_square) {
                    if (foundRSquare) {
                        inAttrs = true;
                        foundRSquare = false;
                    } else {
                        foundRSquare = true;
                    }
                } else {
                    foundRSquare = false;
                }
                if (iter->getKind() == clang::tok::TokenKind::l_square) {
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
            constexpr auto stopTokens = make_array<clang::tok::TokenKind>(clang::tok::TokenKind::l_brace, clang::tok::TokenKind::r_brace,
                                                                          clang::tok::TokenKind::colon, clang::tok::TokenKind::semi);
            auto iter = findNearestToken(srcRange.getEnd());
            if (iter == allTokensRange.end()) { return {}; }

            bool foundRSquare = false;
            bool foundLSquare = false;
            bool inAttrs = false;
            while (inAttrs || !pf::contains(stopTokens, iter->getKind())) {
                ++iter;
                if (iter == allTokensRange.end()) { break; }
                if (iter->getKind() == clang::tok::TokenKind::r_square) {
                    if (foundRSquare) {
                        inAttrs = false;
                        foundRSquare = false;
                    } else {
                        foundRSquare = true;
                    }
                } else {
                    foundRSquare = false;
                }
                if (iter->getKind() == clang::tok::TokenKind::l_square) {
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
            if (const auto start = findAttributesStart(astContext, tokensRange); start.has_value()) {
                {
                    const auto skippedRange = TokensRange{tokensRange.begin(), *start};
                    // if { is found we're entering function body
                    if (std::ranges::any_of(skippedRange,
                                            [](const auto &token) { return token.getKind() == clang::tok::TokenKind::l_brace; })) {
                        break;
                    }

                    const auto wasInArguments = inArguments;
                    if (!inArguments) {
                        // find (
                        inArguments = std::ranges::any_of(
                                skippedRange, [](const auto &token) { return token.getKind() == clang::tok::TokenKind::l_paren; });
                    } else {
                        // find )
                        inArguments = std::ranges::all_of(
                                skippedRange, [](const auto &token) { return token.getKind() != clang::tok::TokenKind::r_paren; });
                    }
                    // only search for , when we're in args and entered them in one of the previous loops
                    if (inArguments && wasInArguments == inArguments) {
                        // move by the count of commas in the skipped range
                        argIndex += std::ranges::count(skippedRange, clang::tok::TokenKind::comma, &clang::Token::getKind);
                    }
                }
                if (const auto end = findAttributesEnd(astContext, TokensRange{*start, tokensRange.end()}); end.has_value()) {
                    tokensRange = TokensRange{*end, tokensRange.end()};
                    foundAttributes = true;
                    if (inArguments) {
                        std::ranges::copy(parseAttributes(astContext, TokensRange{*start, *end}),
                                          std::back_inserter(result.argumentAttributes[argumentSrcRanges.container[argIndex].first]));
                    } else {
                        std::ranges::copy(parseAttributes(astContext, TokensRange{*start, *end}), std::back_inserter(result.attributes));
                    }
                }
            }
        } while (foundAttributes);

        return result;
    }

    std::optional<AttributeParser::TokensRange> AttributeParser::sourceRangeToTokensRange(const clang::SourceRange &srcRange) const {
        auto begin = findNearestToken(srcRange.getBegin());
        if (begin == allTokensRange.end()) { return std::nullopt; }
        auto end = findNearestToken(srcRange.getEnd());
        if (end == allTokensRange.end()) { return std::nullopt; }
        return TokensRange{begin, end};
    }


}// namespace pf::meta_gen