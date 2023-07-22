/**
 * @file Config.h
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <filesystem>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace speculo::gen {

    enum class RunType { Codegen, Metagen };

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


    [[nodiscard]] std::optional<speculo::gen::ProjectConfig> createConfigs(const std::filesystem::path &configPath, bool ignoreIncludes,
                                                                           bool formatOutput) {
        std::ifstream configFile{configPath};
        if (!configFile.is_open()) {
            spdlog::error("Can't open file '{}'", configPath.string());
            return std::nullopt;
        }
        speculo::gen::ProjectConfig result{};
        auto data = nlohmann::json::parse(configFile);

        result.name = data["project"];
        for (const auto &input: data["header_paths"]) {
            auto inputFile = std::filesystem::path{std::string{input}};
            const auto inputProjectPath = inputFile;
            const auto fileName = inputFile.filename();

            const auto projectRoot = std::filesystem::path{std::string{data["project_root"]}};
            inputFile = projectRoot / inputFile;

            auto metaFolder = inputFile;
            metaFolder.remove_filename();
            metaFolder = projectRoot / metaFolder / "meta";
            auto generatedFolder = inputFile;
            generatedFolder.remove_filename();
            generatedFolder = projectRoot / generatedFolder / "generated";

            auto metaHeader = metaFolder / fileName;
            metaHeader.replace_extension();
            metaHeader.concat(".hpp");
            auto generatedHeader = generatedFolder / fileName;
            generatedHeader.replace_extension();
            generatedHeader.concat(".hpp");
            auto generatedSource = generatedFolder / fileName;
            generatedSource.replace_extension();
            generatedSource.concat(".cpp");

            if (!std::filesystem::exists(metaFolder)) { std::filesystem::create_directory(metaFolder); }
            if (!std::filesystem::exists(generatedFolder)) { std::filesystem::create_directory(generatedFolder); }

            std::vector<std::string> flags{"-xc++", "-Wno-unknown-attributes", "-Wno-pragma-once-outside-header"};
            for (const auto &flag: data["compiler_flags"]) { flags.push_back(flag); }
            for (const auto &define: data["defines"]) { flags.push_back(fmt::format("-D {}", std::string{define})); }
            for (const auto &includePath: data["include_paths"]) { flags.push_back(fmt::format("-I{}", std::string{includePath})); }
            // FIXME: remove once clang claims consteval support
            flags.emplace_back("-D __cpp_consteval=201811L");
            result.sourceConfigs.push_back({.inputSource = inputFile,
                                            .outputMetaHeader = metaHeader,
                                            .outputCodegenHeader = generatedHeader,
                                            .outputCodegenSource = generatedSource,
                                            .projectRootDir = projectRoot,
                                            .ignoreIncludes = ignoreIncludes,
                                            .formatOutput = formatOutput,
                                            .compilerFlags = std::move(flags),
                                            .inputProjectPath = inputProjectPath});
        }
        return result;
    }


}// namespace speculo::gen