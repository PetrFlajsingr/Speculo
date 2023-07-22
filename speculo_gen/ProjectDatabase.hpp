/// @file FileDB_structs.hpp
/// @brief
/// @author PetrFlajsingr

#pragma once

#include <chrono>
#include <filesystem>
#include <fstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace speculo::gen {

    struct FileTimestamps {
        std::chrono::time_point<std::chrono::file_clock> lastChange;
        std::unordered_map<std::string, std::chrono::time_point<std::chrono::file_clock>> includeChanges;
    };


    struct ProjectDatabase {
        std::unordered_map<std::string, FileTimestamps> fileTimestamps;
        std::vector<std::string> compilerFlags;
    };

    [[nodiscard]] ProjectDatabase loadProjectDatabase(std::string_view projectName);

    // only pass those parsed by this process
    void updateProjectDatabase(const ProjectDatabase &db, std::string_view projectName);

}// namespace speculo::gen