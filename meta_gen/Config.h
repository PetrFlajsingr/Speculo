/**
 * @file Config.h
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <string>

namespace pf::meta_gen {

    struct Config {
        std::string inputSource;
        std::string outputMetaHeader;
        std::string outputCodegenHeader;
        std::string outputCodegenSource;
        bool ignoreIncludes;
        bool formatOutput;
        std::vector<std::string> compilerFlags;

        std::string inputIncludePath;
    };

}