/**
 * @file Config.h
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace speculo::gen {

    enum class RunType {
        Codegen, Metagen
    };

    struct SourceConfig {
        std::filesystem::path inputSource;
        std::filesystem::path outputMetaHeader;
        std::filesystem::path outputCodegenHeader;
        std::filesystem::path outputCodegenSource;
        std::filesystem::path projectRootDir;
        bool ignoreIncludes;
        bool formatOutput;
        std::vector<std::string> compilerFlags;

        std::filesystem::path inputProjectPath;

        RunType runType;
    };

    struct ProjectConfig {
        std::string name;
        std::vector<SourceConfig> sourceConfigs;
    };
}// namespace speculo::gen