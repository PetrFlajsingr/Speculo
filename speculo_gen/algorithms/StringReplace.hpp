/**
 * @file StringReplace.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <string>

namespace speculo::gen {
    template<typename CharT, typename CharTraits>
    void replaceAllOccurrences(std::basic_string<CharT, CharTraits> &str,
                               speculo::OneOf<std::basic_string_view<CharT, CharTraits>, const CharT *> auto search,
                               speculo::OneOf<std::basic_string_view<CharT, CharTraits>, const CharT *> auto replace) {
        for (auto pos = 0ull; (pos = str.find(search, pos)) != std::string::npos; pos += replace.length()) {
            str.replace(pos, search.length(), replace);
        }
    }
}// namespace speculo::gen