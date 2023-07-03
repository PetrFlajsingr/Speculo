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
        std::basic_string_view<CharT, CharTraits> replaceS{replace};
        std::basic_string_view<CharT, CharTraits> searchS{search};
        for (auto pos = 0ull; (pos = str.find(searchS, pos)) != std::string::npos; pos += replaceS.length()) {
            str.replace(pos, searchS.length(), replaceS);
        }
    }
}// namespace speculo::gen