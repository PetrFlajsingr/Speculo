//
// Created by xflajs00 on 17.03.2023.
//

#include "AttributeParser.h"

#include <pf_common/array.h>

#include "clang_utils.h"

namespace pf::meta_gen {

    AttributeParser::EnumAttributes
    AttributeParser::parseEnumAttributes(clang::ASTContext &astContext, const clang::EnumDecl &decl) const {
        EnumAttributes result{};

        auto srcRange = decl.getSourceRange();

        auto enumTypeAttributes = parseEnumTypeAttributes(astContext, srcRange);
        result.attributes = std::move(enumTypeAttributes.attributes);

        srcRange.setBegin(enumTypeAttributes.end);
        result.valueAttributes = parseEnumValueAttributes(astContext, srcRange);

        return result;
    }

    AttributeParser::EnumTypeAttributeParseResult
    AttributeParser::parseEnumTypeAttributes(clang::ASTContext &astContext, clang::SourceRange srcRange) const {
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
                if (const auto end = findAttributesEnd(astContext, clang::SourceRange{*start,
                                                                                      srcRange.getEnd()}); end.has_value()) {
                    std::ranges::copy(parseAttributes(astContext, clang::SourceRange{*start, *end}),
                                      std::back_inserter(result.attributes));
                    srcRange.setBegin(*end);
                    foundAttributes = true;
                }
            }
        } while (foundAttributes);
        result.end = srcRange.getBegin();
        return result;
    }

    std::unordered_map<std::string, std::vector<Attribute>>
    AttributeParser::parseEnumValueAttributes(clang::ASTContext &astContext, clang::SourceRange srcRange) const {
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
                if (!token.has_value() || token->getKind() == clang::tok::TokenKind::eof ||
                    token->getLocation() > srcRange.getEnd()) {
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
                                 pf::make_array<clang::tok::TokenKind>(clang::tok::TokenKind::comma,
                                                                       clang::tok::TokenKind::r_brace))) {
                        // found value divider, these attributes belong to a different value
                        break;
                    }
                    if (const auto end = findAttributesEnd(astContext, clang::SourceRange{*start,
                                                                                          srcRange.getEnd()}); end.has_value()) {
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

    std::optional<clang::SourceLocation>
    AttributeParser::findAttributesStart(clang::ASTContext &astContext, const clang::SourceRange &srcRange) const {
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

    std::optional<clang::SourceLocation>
    AttributeParser::findAttributesEnd(clang::ASTContext &astContext, const clang::SourceRange &srcRange) const {
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

    std::vector<Attribute>
    AttributeParser::parseAttributes(clang::ASTContext &astContext, const clang::SourceRange &srcRange) const {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

        enum class State {
            Start, None, Using, UsingEnd, Name, Arguments, NestedParens
        };
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
                }
                    break;
                case State::None: {
                    if (token->getKind() == clang::tok::TokenKind::raw_identifier) {
                        state = State::Name;
                        attributeName = clang::Lexer::getSpelling(*token, sourceManager, langOpts);
                    }
                }
                    break;
                case State::Using: {
                    attributeNamespace = clang::Lexer::getSpelling(*token, sourceManager, langOpts);
                    state = State::UsingEnd;
                }
                    break;
                case State::UsingEnd: {
                    state = State::None;
                }
                    break;
                case State::Name: {
                    if (token->getKind() == clang::tok::TokenKind::coloncolon ||
                        token->getKind() == clang::tok::TokenKind::raw_identifier) {
                        attributeName += clang::Lexer::getSpelling(*token, sourceManager, langOpts);
                        state = State::Name;
                    } else if (token->getKind() == clang::tok::TokenKind::l_paren) {
                        state = State::Arguments;
                    } else {
                        if (!attributeNamespace.empty()) {
                            result.emplace_back(attributeNamespace + "::" + attributeName, attributeParams);
                        } else {
                            result.emplace_back(attributeName, attributeParams);
                        }
                        attributeParams.clear();
                        attributeName.clear();
                        state = State::None;
                    }
                }
                    break;
                case State::Arguments: {
                    if (token->getKind() == clang::tok::TokenKind::l_paren) {
                        nestedParensCnt = 1;
                        attributeParam.append(clang::Lexer::getSpelling(*token, sourceManager, langOpts));
                        state = State::NestedParens;
                    } else if (token->getKind() == clang::tok::TokenKind::r_paren) {
                        if (!attributeParam.empty()) { attributeParams.emplace_back(attributeParam); }
                        if (!attributeNamespace.empty()) {
                            result.emplace_back(attributeNamespace + "::" + attributeName, attributeParams);
                        } else {
                            result.emplace_back(attributeName, attributeParams);
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
                }
                    break;
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
                }
                    break;
            }


            // std::cout << clang::tok::getTokenName(token->getKind()) << "\t";
            // std::cout << clang::Lexer::getSpelling(*token, sourceManager, langOpts) << std::endl;

            i = token->getLocation();
        }
        // std::cout << std::endl;
        return result;
    }

    clang::SourceLocation
    AttributeParser::advanceByTokens(clang::ASTContext &astContext, const clang::SourceLocation &loc,
                                     std::size_t count) const {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        auto token = clang::Lexer::findNextToken(loc, sourceManager, langOpts);
        for (std::size_t i = 0; i < count - 1; ++i) {
            token = clang::Lexer::findNextToken(token->getLocation(), sourceManager, langOpts);
        }
        return token->getLocation();
    }

    std::optional<clang::Token>
    AttributeParser::getToken(clang::ASTContext &astContext, const clang::SourceLocation &loc) const {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        return clang::Lexer::findNextToken(loc, sourceManager, langOpts);
    }

} // pf::meta_gen