//
// Created by xflajs00 on 17.03.2023.
//

#include "AttributeParser.h"

#include <pf_common/algorithms.h>
#include <pf_common/array.h>

#include <spdlog/spdlog.h>

#include "clang_utils.h"

// FIXME: deduplicate code
namespace pf::meta_gen {

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

        auto srcRange = decl.getSourceRange();

        bool foundAttributes;
        do {
            foundAttributes = false;
            if (const auto start = findAttributesStart(astContext, srcRange); start.has_value()) {
                if (contains(astContext, clang::SourceRange{srcRange.getBegin(), *start},
                             pf::make_array<clang::tok::TokenKind>(clang::tok::TokenKind::raw_identifier))) {
                    // found class name, thus we're out of class type's attributes
                    break;
                }
                if (const auto end = findAttributesEnd(astContext, clang::SourceRange{*start, srcRange.getEnd()}); end.has_value()) {
                    std::ranges::copy(parseAttributes(astContext, clang::SourceRange{*start, *end}), std::back_inserter(result));
                    srcRange.setBegin(*end);
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

    std::vector<Attribute> AttributeParser::parseFunctionAttributes(clang::ASTContext &astContext, const clang::CXXMethodDecl &decl) const {
        return parseFunctionLikeAttributes(astContext, decl.getSourceRange());
    }
    std::vector<Attribute> AttributeParser::parseArgumentAttributes(clang::ASTContext &astContext, const clang::ParmVarDecl &decl) const {
        std::vector<Attribute> result{};

        auto srcRange = decl.getSourceRange();
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

        // move as far to the left as possible to collect all attributes
        {
            constexpr auto stopTokens = make_array<clang::tok::TokenKind>(clang::tok::TokenKind::l_paren, clang::tok::TokenKind::comma);
            auto begin = srcRange.getBegin().getLocWithOffset(-1);
            clang::Token token{};
            clang::Lexer::getRawToken(begin, token, sourceManager, langOpts);
            bool foundRSquare = false;
            bool foundLSquare = false;
            bool inAttrs = false;
            while (inAttrs || !pf::contains(stopTokens, token.getKind())) {
                begin = begin.getLocWithOffset(-1);
                clang::Lexer::getRawToken(begin, token, sourceManager, langOpts);
                if (token.getKind() == clang::tok::TokenKind::r_square) {
                    if (foundRSquare) {
                        inAttrs = true;
                        foundRSquare = false;
                    } else {
                        foundRSquare = true;
                    }
                } else {
                    foundRSquare = false;
                }
                if (token.getKind() == clang::tok::TokenKind::l_square) {
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
            srcRange.setBegin(begin);
        }

        bool foundAttributes;
        do {
            foundAttributes = false;
            if (const auto start = findAttributesStart(astContext, srcRange); start.has_value()) {
                if (const auto end = findAttributesEnd(astContext, clang::SourceRange{*start, srcRange.getEnd()}); end.has_value()) {
                    std::ranges::copy(parseAttributes(astContext, clang::SourceRange{*start, *end}), std::back_inserter(result));
                    srcRange.setBegin(*end);
                    foundAttributes = true;
                }
            }
        } while (foundAttributes);

        return result;
    }
    std::vector<Attribute> AttributeParser::parseConstructorAttributes(clang::ASTContext &astContext,
                                                                       const clang::CXXConstructorDecl &decl) const {
        return parseFunctionLikeAttributes(astContext, decl.getSourceRange());
    }

    std::vector<Attribute> AttributeParser::parseDestructorAttributes(clang::ASTContext &astContext,
                                                                      const clang::CXXDestructorDecl &decl) const {
        return parseFunctionLikeAttributes(astContext, decl.getSourceRange());
    }

    AttributeParser::EnumTypeAttributeParseResult AttributeParser::parseEnumTypeAttributes(clang::ASTContext &astContext,
                                                                                           clang::SourceRange srcRange) const {
        EnumTypeAttributeParseResult result;

        // skipping first raw_identifier, which is just `enum`/`enum class`
        srcRange.setBegin(advanceByTokens(astContext, srcRange.getBegin(), 1));

        bool foundAttributes;
        do {
            foundAttributes = false;
            if (const auto start = findAttributesStart(astContext, srcRange); start.has_value()) {
                if (contains(astContext, clang::SourceRange{srcRange.getBegin(), *start},
                             pf::make_array<clang::tok::TokenKind>(clang::tok::TokenKind::raw_identifier))) {
                    // found enum name, thus we're out of enum type's attributes
                    break;
                }
                if (const auto end = findAttributesEnd(astContext, clang::SourceRange{*start, srcRange.getEnd()}); end.has_value()) {
                    std::ranges::copy(parseAttributes(astContext, clang::SourceRange{*start, *end}), std::back_inserter(result.attributes));
                    srcRange.setBegin(*end);
                    foundAttributes = true;
                }
            }
        } while (foundAttributes);
        result.end = srcRange.getBegin();
        return result;
    }

    std::unordered_map<std::string, std::vector<Attribute>> AttributeParser::parseEnumValueAttributes(clang::ASTContext &astContext,
                                                                                                      clang::SourceRange srcRange) const {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

        std::unordered_map<std::string, std::vector<Attribute>> result;

        // advance to l_brace
        {
            auto token = clang::Lexer::findNextToken(srcRange.getBegin(), sourceManager, langOpts);
            while (token->getKind() != clang::tok::TokenKind::l_brace) {
                token = clang::Lexer::findNextToken(token->getLocation(), sourceManager, langOpts);
            }
            const auto newBegin = token->getLocation();
            if (newBegin > srcRange.getEnd()) { return result; }
            srcRange.setBegin(newBegin);
        }

        while (true) {
            bool foundValue = true;
            auto token = clang::Lexer::findNextToken(srcRange.getBegin(), sourceManager, langOpts);
            while (token->getKind() != clang::tok::TokenKind::raw_identifier) {
                token = clang::Lexer::findNextToken(token->getLocation(), sourceManager, langOpts);
                if (!token.has_value() || token->getKind() == clang::tok::TokenKind::eof || token->getLocation() > srcRange.getEnd()) {
                    foundValue = false;
                    break;
                }
            }
            if (!foundValue) { break; }
            srcRange.setBegin(token->getLocation());

            const auto spelling = clang::Lexer::getSpelling(*token, sourceManager, langOpts);
            std::pair<std::string, std::vector<Attribute>> valueAttributes{spelling, {}};

            bool foundAttributes;
            do {
                foundAttributes = false;
                if (const auto start = findAttributesStart(astContext, srcRange); start.has_value()) {
                    if (contains(astContext, clang::SourceRange{srcRange.getBegin(), *start},
                                 pf::make_array<clang::tok::TokenKind>(clang::tok::TokenKind::comma, clang::tok::TokenKind::r_brace))) {
                        // found value divider, these attributes belong to a different value
                        break;
                    }
                    if (const auto end = findAttributesEnd(astContext, clang::SourceRange{*start, srcRange.getEnd()}); end.has_value()) {
                        std::ranges::copy(parseAttributes(astContext, clang::SourceRange{*start, *end}),
                                          std::back_inserter(valueAttributes.second));
                        srcRange.setBegin(*end);
                        foundAttributes = true;
                    }
                }
            } while (foundAttributes);
            result.emplace(std::move(valueAttributes));
        }

        return result;
    }

    std::optional<clang::SourceLocation> AttributeParser::findAttributesStart(clang::ASTContext &astContext,
                                                                              const clang::SourceRange &srcRange) const {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

        clang::SourceLocation result;

        auto token = clang::Lexer::findNextToken(srcRange.getBegin(), sourceManager, langOpts);
        bool foundLSquare = false;
        for (auto i = token->getLocation(); i != srcRange.getEnd();) {
            if (!token.has_value()) { return std::nullopt; }
            if (token->getKind() == clang::tok::TokenKind::eof) { return std::nullopt; }
            if (foundLSquare && token->getKind() == clang::tok::TokenKind::l_square) {
                return result;
            } else {
                foundLSquare = token->getKind() == clang::tok::TokenKind::l_square;
            }
            if (foundLSquare) { result = token->getLocation(); }

            token = clang::Lexer::findNextToken(i, sourceManager, langOpts);
            i = token->getLocation();
        }
        return std::nullopt;
    }

    std::optional<clang::SourceLocation> AttributeParser::findAttributesEnd(clang::ASTContext &astContext,
                                                                            const clang::SourceRange &srcRange) const {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

        auto token = clang::Lexer::findNextToken(srcRange.getBegin(), sourceManager, langOpts);

        bool foundRSquare = false;
        std::size_t parensNestingCnt{};
        for (auto i = token->getLocation(); i != srcRange.getEnd();) {
            if (!token.has_value()) { return std::nullopt; }
            if (token->getKind() == clang::tok::TokenKind::l_paren) {
                ++parensNestingCnt;
            } else if (token->getKind() == clang::tok::TokenKind::r_paren) {
                --parensNestingCnt;
            }
            if (parensNestingCnt == 0) {
                if (foundRSquare && token->getKind() == clang::tok::TokenKind::r_square) {
                    return token->getLocation();
                } else {
                    foundRSquare = token->getKind() == clang::tok::TokenKind::r_square;
                }
            } else {
                foundRSquare = false;
            }

            token = clang::Lexer::findNextToken(i, sourceManager, langOpts);
            i = token->getLocation();
        }
        return std::nullopt;
    }

    std::vector<Attribute> AttributeParser::parseAttributes(clang::ASTContext &astContext, const clang::SourceRange &srcRange) const {
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
        for (auto i = srcRange.getBegin(); i != srcRange.getEnd();) {
            auto token = clang::Lexer::findNextToken(i, sourceManager, langOpts);
            if (!token.has_value()) { break; }
            switch (state) {
                case State::Start: {
                    if (token->getKind() == clang::tok::TokenKind::raw_identifier) {
                        const auto spelling = clang::Lexer::getSpelling(*token, sourceManager, langOpts);
                        if (spelling == "using") {
                            state = State::Using;
                        } else {
                            state = State::Name;
                            attributeName = spelling;
                        }
                    }
                } break;
                case State::None: {
                    if (token->getKind() == clang::tok::TokenKind::raw_identifier) {
                        state = State::Name;
                        attributeName = clang::Lexer::getSpelling(*token, sourceManager, langOpts);
                    }
                } break;
                case State::Using: {
                    attributeNamespace = clang::Lexer::getSpelling(*token, sourceManager, langOpts);
                    state = State::UsingEnd;
                } break;
                case State::UsingEnd: {
                    state = State::None;
                } break;
                case State::Name: {
                    if (token->getKind() == clang::tok::TokenKind::coloncolon ||
                        token->getKind() == clang::tok::TokenKind::raw_identifier) {
                        attributeName += clang::Lexer::getSpelling(*token, sourceManager, langOpts);
                        state = State::Name;
                    } else if (token->getKind() == clang::tok::TokenKind::l_paren) {
                        state = State::Arguments;
                    } else {
                        if (!attributeNamespace.empty()) {
                            result.emplace_back(attributeNamespace, attributeName, attributeParams);
                        } else {
                            if (const auto iter = std::ranges::adjacent_find(attributeName, [](auto v1, auto v2) { return v1 == ':' && v2 == ':'; }); iter != attributeName.end()) {
                                const auto index = std::ranges::distance(attributeName.begin(), iter);
                                attributeNamespace = attributeName.substr(0, index);
                                attributeName = attributeName.substr(index + 2);
                            }
                            result.emplace_back(attributeNamespace, attributeName, attributeParams);
                        }
                        attributeParams.clear();
                        attributeName.clear();
                        state = State::None;
                    }
                } break;
                case State::Arguments: {
                    if (token->getKind() == clang::tok::TokenKind::l_paren) {
                        nestedParensCnt = 1;
                        attributeParam.append(clang::Lexer::getSpelling(*token, sourceManager, langOpts));
                        state = State::NestedParens;
                    } else if (token->getKind() == clang::tok::TokenKind::r_paren) {
                        if (!attributeParam.empty()) { attributeParams.emplace_back(attributeParam); }
                        if (!attributeNamespace.empty()) {
                            result.emplace_back(attributeNamespace, attributeName, attributeParams);
                        } else {
                            if (const auto iter = std::ranges::adjacent_find(attributeName, [](auto v1, auto v2) { return v1 == ':' && v2 == ':'; }); iter != attributeName.end()) {
                                const auto index = std::ranges::distance(attributeName.begin(), iter);
                                attributeNamespace = attributeName.substr(0, index);
                                attributeName = attributeName.substr(index + 2);
                            }
                            result.emplace_back(attributeNamespace, attributeName, attributeParams);
                        }
                        attributeParams.clear();
                        attributeParam.clear();
                        attributeName.clear();
                        state = State::None;
                    } else if (token->getKind() == clang::tok::TokenKind::comma) {
                        if (!attributeParam.empty()) { attributeParams.emplace_back(attributeParam); }
                        attributeParam.clear();
                        state = State::Arguments;
                    } else {
                        attributeParam.append(clang::Lexer::getSpelling(*token, sourceManager, langOpts));
                        state = State::Arguments;
                    }
                } break;
                case State::NestedParens: {
                    if (token->getKind() == clang::tok::TokenKind::l_paren) {
                        ++nestedParensCnt;
                        attributeParam.append(clang::Lexer::getSpelling(*token, sourceManager, langOpts));
                        state = State::NestedParens;
                    } else if (token->getKind() == clang::tok::TokenKind::r_paren) {
                        attributeParam.append(clang::Lexer::getSpelling(*token, sourceManager, langOpts));
                        --nestedParensCnt;
                        if (nestedParensCnt == 0) {
                            state = State::Arguments;
                        } else {
                            state = State::NestedParens;
                        }
                    } else if (token->getKind() == clang::tok::TokenKind::comma) {
                        if (!attributeParam.empty()) { attributeParams.emplace_back(attributeParam); }
                        attributeParam.clear();
                        state = State::Arguments;
                    } else {
                        attributeParam.append(clang::Lexer::getSpelling(*token, sourceManager, langOpts));
                        state = State::NestedParens;
                    }
                } break;
            }
            i = token->getLocation();
        }
        return result;
    }

    clang::SourceLocation AttributeParser::advanceByTokens(clang::ASTContext &astContext, const clang::SourceLocation &loc,
                                                           std::size_t count) const {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        auto token = clang::Lexer::findNextToken(loc, sourceManager, langOpts);
        for (std::size_t i = 0; i < count - 1; ++i) { token = clang::Lexer::findNextToken(token->getLocation(), sourceManager, langOpts); }
        return token->getLocation();
    }

    std::optional<clang::Token> AttributeParser::getToken(clang::ASTContext &astContext, const clang::SourceLocation &loc) const {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        return clang::Lexer::findNextToken(loc, sourceManager, langOpts);
    }

    std::vector<Attribute> AttributeParser::parseVariableAttributes(clang::ASTContext &astContext, clang::SourceRange srcRange) const {
        std::vector<Attribute> result{};

        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

        // move as far to the left as possible to collect all attributes
        {
            constexpr auto stopTokens = make_array<clang::tok::TokenKind>(clang::tok::TokenKind::l_brace, clang::tok::TokenKind::r_brace,
                                                                          clang::tok::TokenKind::colon, clang::tok::TokenKind::semi);
            auto begin = srcRange.getBegin().getLocWithOffset(-1);
            clang::Token token{};
            clang::Lexer::getRawToken(begin, token, sourceManager, langOpts);
            bool foundRSquare = false;
            bool foundLSquare = false;
            bool inAttrs = false;
            while (inAttrs || !pf::contains(stopTokens, token.getKind())) {
                begin = begin.getLocWithOffset(-1);
                clang::Lexer::getRawToken(begin, token, sourceManager, langOpts);
                if (token.getKind() == clang::tok::TokenKind::r_square) {
                    if (foundRSquare) {
                        inAttrs = true;
                        foundRSquare = false;
                    } else {
                        foundRSquare = true;
                    }
                } else {
                    foundRSquare = false;
                }
                if (token.getKind() == clang::tok::TokenKind::l_square) {
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
            srcRange.setBegin(begin);
        }
        // move as far to the right as possible to collect trailing attributes
        {
            constexpr auto stopTokens = make_array<clang::tok::TokenKind>(clang::tok::TokenKind::l_brace, clang::tok::TokenKind::r_brace,
                                                                          clang::tok::TokenKind::colon, clang::tok::TokenKind::semi);
            auto end = srcRange.getEnd();
            auto token = clang::Lexer::findNextToken(end, sourceManager, langOpts);
            bool foundRSquare = false;
            bool foundLSquare = false;
            bool inAttrs = false;
            while (inAttrs || !pf::contains(stopTokens, token->getKind())) {
                token = clang::Lexer::findNextToken(end, sourceManager, langOpts);
                if (!token.has_value()) { break; }
                if (token->getKind() == clang::tok::TokenKind::r_square) {
                    if (foundRSquare) {
                        inAttrs = false;
                        foundRSquare = false;
                    } else {
                        foundRSquare = true;
                    }
                } else {
                    foundRSquare = false;
                }
                if (token->getKind() == clang::tok::TokenKind::l_square) {
                    if (foundLSquare) {
                        inAttrs = true;
                        foundLSquare = false;
                    } else {
                        foundLSquare = true;
                    }
                } else {
                    foundLSquare = false;
                }
                end = token->getLocation();
            }
            srcRange.setEnd(end);
        }


        bool foundAttributes;
        do {
            foundAttributes = false;
            if (const auto start = findAttributesStart(astContext, srcRange); start.has_value()) {
                if (const auto end = findAttributesEnd(astContext, clang::SourceRange{*start, srcRange.getEnd()}); end.has_value()) {
                    std::ranges::copy(parseAttributes(astContext, clang::SourceRange{*start, *end}), std::back_inserter(result));
                    srcRange.setBegin(*end);
                    foundAttributes = true;
                }
            }
        } while (foundAttributes);


        return result;
    }
    std::vector<Attribute> AttributeParser::parseFunctionLikeAttributes(clang::ASTContext &astContext, clang::SourceRange srcRange) const {
        std::vector<Attribute> result{};
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

        // move as far to the left as possible to collect all attributes
        {
            constexpr auto stopTokens = make_array<clang::tok::TokenKind>(clang::tok::TokenKind::l_brace, clang::tok::TokenKind::r_brace,
                                                                          clang::tok::TokenKind::colon, clang::tok::TokenKind::semi);
            auto begin = srcRange.getBegin().getLocWithOffset(-1);
            clang::Token token{};
            clang::Lexer::getRawToken(begin, token, sourceManager, langOpts);
            bool foundRSquare = false;
            bool foundLSquare = false;
            bool inAttrs = false;
            while (inAttrs || !pf::contains(stopTokens, token.getKind())) {
                begin = begin.getLocWithOffset(-1);
                clang::Lexer::getRawToken(begin, token, sourceManager, langOpts);
                if (token.getKind() == clang::tok::TokenKind::r_square) {
                    if (foundRSquare) {
                        inAttrs = true;
                        foundRSquare = false;
                    } else {
                        foundRSquare = true;
                    }
                } else {
                    foundRSquare = false;
                }
                if (token.getKind() == clang::tok::TokenKind::l_square) {
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
            srcRange.setBegin(begin);
        }
        // move as far to the right as possible to collect trailing attributes
        {
            constexpr auto stopTokens = make_array<clang::tok::TokenKind>(clang::tok::TokenKind::l_brace, clang::tok::TokenKind::r_brace,
                                                                          clang::tok::TokenKind::colon, clang::tok::TokenKind::semi);
            auto end = srcRange.getBegin();
            auto token = clang::Lexer::findNextToken(end, sourceManager, langOpts);
            bool foundRSquare = false;
            bool foundLSquare = false;
            bool inAttrs = false;
            while (inAttrs || !pf::contains(stopTokens, token->getKind())) {
                token = clang::Lexer::findNextToken(end, sourceManager, langOpts);
                if (!token.has_value()) { break; }
                if (token->getKind() == clang::tok::TokenKind::r_square) {
                    if (foundRSquare) {
                        inAttrs = false;
                        foundRSquare = false;
                    } else {
                        foundRSquare = true;
                    }
                } else {
                    foundRSquare = false;
                }
                if (token->getKind() == clang::tok::TokenKind::l_square) {
                    if (foundLSquare) {
                        inAttrs = true;
                        foundLSquare = false;
                    } else {
                        foundLSquare = true;
                    }
                } else {
                    foundLSquare = false;
                }
                end = token->getLocation();
            }
            srcRange.setEnd(end);
        }
        clang::SourceRange argumentsRange{};
        // find arguments source range
        {
            auto token = clang::Lexer::findNextToken(srcRange.getBegin(), sourceManager, langOpts);
            bool foundRSquare = false;
            bool foundLSquare = false;
            bool inAttrs = false;
            std::size_t parenDepth{};
            for (auto iter = srcRange.getBegin();;) {
                token = clang::Lexer::findNextToken(iter, sourceManager, langOpts);
                if (!token.has_value()) { break; }
                if (token->getKind() == clang::tok::TokenKind::r_square) {
                    if (foundRSquare) {
                        inAttrs = false;
                        foundRSquare = false;
                    } else {
                        foundRSquare = true;
                    }
                } else {
                    foundRSquare = false;
                }
                if (token->getKind() == clang::tok::TokenKind::l_square) {
                    if (foundLSquare) {
                        inAttrs = true;
                        foundLSquare = false;
                    } else {
                        foundLSquare = true;
                    }
                } else {
                    foundLSquare = false;
                }
                if (!inAttrs) {
                    if (token->getKind() == clang::tok::TokenKind::l_paren) {
                        if (parenDepth == 0) { argumentsRange.setBegin(token->getLocation()); }
                        ++parenDepth;
                    } else if (token->getKind() == clang::tok::TokenKind::r_paren) {
                        --parenDepth;
                        if (parenDepth == 0) {
                            argumentsRange.setEnd(token->getLocation());
                            break;
                        }
                    }
                }
                iter = token->getLocation();
            }
        }

        bool foundAttributes;
        do {
            foundAttributes = false;
            if (const auto start = findAttributesStart(astContext, srcRange); start.has_value()) {
                if (const auto end = findAttributesEnd(astContext, clang::SourceRange{*start, srcRange.getEnd()}); end.has_value()) {
                    std::ranges::copy(parseAttributes(astContext, clang::SourceRange{*start, *end}), std::back_inserter(result));
                    srcRange.setBegin(*end);
                    foundAttributes = true;
                }
            }
        } while (foundAttributes);

        return result;
    }


}// namespace pf::meta_gen