/**
 * @file StringReplace.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <string>

namespace pf::meta_gen {
    void replaceAllOccurrences(std::string &str, const std::string &search, const std::string &replace) {
        size_t pos = 0;
        while ((pos = str.find(search, pos)) != std::string::npos) {
            str.replace(pos, search.length(), replace);
            pos += replace.length();
        }
    }
}// namespace pf::meta_gen