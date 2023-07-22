/// @file FileDB_structs.hpp
/// @brief
/// @author PetrFlajsingr

#pragma once

#include <chrono>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <string_view>
#include <filesystem>

namespace speculo::gen {

    struct FileTimestamps {
        std::chrono::time_point<std::chrono::file_clock> lastChange;
        std::unordered_map<std::string, std::chrono::time_point<std::chrono::file_clock>> includeChanges;
    };


    struct ProjectDatabase {
        std::unordered_map<std::string, FileTimestamps> fileTimestamps;
        std::vector<std::string> compilerFlags;
    };

    [[nodiscard]] ProjectDatabase loadProjectDatabase(std::string_view projectName) {
        const auto databasePath = std::filesystem::current_path() / fmt::format("speculo_{}_database.json", projectName);
        if (!std::filesystem::exists(databasePath)) {
            spdlog::info("Database file not found at '{}'", databasePath.string());
            return {};
        }

        auto istream = std::ifstream{databasePath};
        if (!istream.is_open()) {
            spdlog::error("Can't open file '{}': {}", databasePath.string(), strerror(errno));
            return {};
        }
        auto data = nlohmann::json::parse(istream);
        istream.close();
        ProjectDatabase result{};
        for (const auto &rec: data["files"]) { result.fileTimestamps[rec["file"]] = static_cast<FileTimestamps>(rec["timestamps"]); }
        for (const auto &flag: data["compiler_flags"]) { result.compilerFlags.push_back(flag); }
        return result;
    }

    // only pass those parsed by this process
    void updateProjectDatabase(const ProjectDatabase &db, std::string_view projectName) {
        const auto databasePath = std::filesystem::current_path() / fmt::format("speculo_{}_database.json", projectName);
        auto istream = std::ifstream{databasePath};
        nlohmann::json data;
        if (istream.is_open()) { data = nlohmann::json::parse(istream); }
        istream.close();

        auto &filesData = data["files"];
        filesData.clear();
        for (const auto &[file, stamps]: db.fileTimestamps) {
            nlohmann::json fileData{{"file", file}, {"timestamps", stamps}};
            filesData.push_back(fileData);
        }
        auto &flagsData = data["compiler_flags"];
        flagsData.clear();
        for (const auto &flag: db.compilerFlags) { flagsData.push_back(flag); }
        auto ostream = std::ofstream{databasePath};
        if (!ostream.is_open()) {
            spdlog::error("Can't open file for write '{}': {}", databasePath.string(), strerror(errno));
            return;
        }
        ostream << data.dump(4);
    }

}