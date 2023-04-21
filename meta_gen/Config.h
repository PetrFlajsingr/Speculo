/**
 * @file Config.h
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <string>
#include <filesystem>

namespace pf::meta_gen {

    struct Config {
        std::filesystem::path inputSource;
        std::filesystem::path outputMetaHeader;
        std::filesystem::path outputCodegenHeader;
        std::filesystem::path outputCodegenSource;
        std::filesystem::path projectRootDir;
        bool ignoreIncludes;
        bool formatOutput;
        std::vector<std::string> compilerFlags;

        std::string inputIncludePath;
    };

}