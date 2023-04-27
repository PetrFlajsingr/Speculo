//
// Created by xflajs00 on 17.03.2023.
//

#ifndef PF_META_CLANG_UTILS_H
#define PF_META_CLANG_UTILS_H

#include "clang_tooling_wrap.hpp"

#include <pf_common/concepts/ranges.h>

namespace pf::meta_gen {

    [[nodiscard]] bool contains(clang::ASTContext &astContext, const clang::SourceRange &range,
                                pf::RangeOf<clang::tok::TokenKind> auto &&kinds) {
        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();

        auto token = clang::Lexer::findNextToken(range.getBegin(), sourceManager, langOpts);
        for (auto i = token->getLocation(); i != range.getEnd();) {
            if (!token.has_value()) { return false; }
            if (std::ranges::any_of(kinds, [tokKind = token->getKind()](auto k) { return k == tokKind; })) { return true; }
            token = clang::Lexer::findNextToken(i, sourceManager, langOpts);
            i = token->getLocation();
        }
        return false;
    }

}// namespace pf::meta_gen

#endif//PF_META_CLANG_UTILS_H
