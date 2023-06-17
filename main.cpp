#include "meta/Info.hpp"
#include <fmt/core.h>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/spdlog.h>

#include "meta_gen/AttributeParser.hpp"
#include "meta_gen/IdGenerator.hpp"
#include "meta_gen/IncludeCollector.hpp"
#include "meta_gen/wrap/clang_tooling_compilationdatabase.hpp"
#include "meta_gen/info_structs.hpp"

#include "format.hpp"
#include "meta_gen/AstActions.hpp"
#include "meta_gen/wrap/clang_tooling_commonoptionsparser.hpp"

#include <fstream>
#include <nlohmann/json.hpp>
#include <tl/expected.hpp>

#include "meta_gen/SourceConfig.hpp"
#include "meta_gen/ThreadPool.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "meta_gen/wrap/clang_lex_PreprocessorOptions.hpp"


static llvm::cl::opt<std::string> ConfigArg(llvm::cl::Required, "config", llvm::cl::desc("Specify input config"),
                                            llvm::cl::value_desc("filename"));
static llvm::cl::opt<bool> IgnoreIncludes("ignore-includes", llvm::cl::desc("Ignore includes while parsing the file"),
                                          llvm::cl::value_desc("bool"), llvm::cl::init(true));
static llvm::cl::opt<bool> FormatOutput("format-output", llvm::cl::desc("Reformat outputs"), llvm::cl::value_desc("bool"),
                                        llvm::cl::init(false));
static llvm::cl::opt<bool> ForceRegen("force", llvm::cl::desc("Force regeneration"), llvm::cl::value_desc("bool"), llvm::cl::init(false));
static llvm::cl::opt<bool> VerboseLogging("verbose", llvm::cl::desc("Verbose logging"), llvm::cl::value_desc("bool"),
                                          llvm::cl::init(false));
static llvm::cl::opt<bool> RunSequential("sequential", llvm::cl::desc("Run everything on main thread sequentially"),
                                         llvm::cl::value_desc("bool"), llvm::cl::init(false));


template<typename Clock, typename Duration>
struct nlohmann::adl_serializer<std::chrono::time_point<Clock, Duration>> {
    static void to_json(json &j, const std::chrono::time_point<Clock, Duration> &tp) {
        j["since_epoch"] = std::chrono::duration_cast<std::chrono::microseconds>(tp.time_since_epoch()).count();
        j["unit"] = "microseconds";
    }
    static void from_json(const json &j, std::chrono::time_point<Clock, Duration> &p) {
        const auto time_since_epoch = static_cast<unsigned long long>(j["since_epoch"]);
        p = std::chrono::time_point<Clock, Duration>{std::chrono::microseconds{time_since_epoch}};
    }
};

struct FileTimestamps {
    std::chrono::time_point<std::chrono::file_clock> lastChange;
    std::unordered_map<std::string, std::chrono::time_point<std::chrono::file_clock>> includeChanges;
};


template<>
struct nlohmann::adl_serializer<FileTimestamps> {
    static void to_json(json &j, const FileTimestamps &tp) {
        j["timestamp"] = tp.lastChange;
        auto includes = json::array();
        std::ranges::for_each(tp.includeChanges, [&](const auto &r) {
            const auto &includePath = r.first;
            const auto &includeStamp = r.second;
            auto &newR = includes.emplace_back();
            newR["path"] = includePath;
            newR["timestamp"] = includeStamp;
        });
        j["includes"] = std::move(includes);
    }
    static void from_json(const json &j, FileTimestamps &p) {
        p.lastChange = j["timestamp"];
        json::array_t includes = j["includes"];
        std::ranges::for_each(includes, [&](const auto &include) { p.includeChanges[include["path"]] = include["timestamp"]; });
    }
};

struct ProjectDatabase {
    std::unordered_map<std::string, FileTimestamps> fileTimestamps;
    std::vector<std::string> compilerFlags;
};

[[nodiscard]] ProjectDatabase loadProjectDatabase(std::string_view projectName) {
    const auto databasePath = std::filesystem::current_path() / fmt::format("pf_meta_{}_database.json", projectName);
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
    const auto databasePath = std::filesystem::current_path() / fmt::format("pf_meta_{}_database.json", projectName);
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


[[nodiscard]] std::optional<pf::meta_gen::ProjectConfig> createConfigs(const std::filesystem::path &configPath) {
    std::ifstream configFile{configPath};
    if (!configFile.is_open()) {
        spdlog::error("Can't open file '{}'", configPath.string());
        return std::nullopt;
    }
    pf::meta_gen::ProjectConfig result{};
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
        // TODO: move elsewhere
        flags.emplace_back("-D PF_META_GENERATOR_RUNNING");
        // FIXME: remove once clang claims consteval support
        flags.emplace_back("-D __cpp_consteval=201811L");
        result.sourceConfigs.push_back({.inputSource = inputFile,
                                        .outputMetaHeader = metaHeader,
                                        .outputCodegenHeader = generatedHeader,
                                        .outputCodegenSource = generatedSource,
                                        .projectRootDir = projectRoot,
                                        .ignoreIncludes = IgnoreIncludes,
                                        .formatOutput = FormatOutput,
                                        .compilerFlags = std::move(flags),
                                        .inputProjectPath = inputProjectPath});
    }
    return result;
}


int main(int argc, const char **argv) {
    llvm::cl::ParseCommandLineOptions(argc, argv, "Test");

    spdlog::default_logger()->sinks().clear();
    spdlog::default_logger()->set_level(spdlog::level::trace);
    {
        auto &stdoutSink = spdlog::default_logger()->sinks().emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        if (static_cast<bool>(VerboseLogging)) {
            stdoutSink->set_level(spdlog::level::trace);
        } else {
#ifdef NDEBUG
            stdoutSink->set_level(spdlog::level::info);
#else
            stdoutSink->set_level(spdlog::level::debug);
#endif
        }
        spdlog::default_logger()
                ->sinks()
                .emplace_back(std::make_shared<spdlog::sinks::daily_file_sink_mt>(
                        (std::filesystem::current_path() / "logs/daily.log").string(), 0, 0))
                ->set_level(spdlog::level::trace);
    }

    auto configsOpt = createConfigs(std::filesystem::path{std::string{ConfigArg}});
    if (!configsOpt.has_value()) { return 0; }
    const auto configs = std::move(*configsOpt);

    auto timestampDB = loadProjectDatabase(configs.name);


    struct ParseResult {
        std::filesystem::path inPath;
        std::filesystem::path outPath;
        std::chrono::time_point<std::chrono::file_clock> stamp;
        std::unordered_map<std::string, std::chrono::time_point<std::chrono::file_clock>> includeStamps;
    };
    struct ParseFailure {
        std::filesystem::path inPath;
        std::filesystem::path outPath;
    };

    auto compilerFlagsChanged = false;
    if (!configs.sourceConfigs.empty()) { compilerFlagsChanged = configs.sourceConfigs.front().compilerFlags != timestampDB.compilerFlags; }

    const auto generateMetaForSource =
            [&timestampDB, compilerFlagsChanged](pf::meta_gen::SourceConfig config) -> tl::expected<ParseResult, ParseFailure> {
        if (!std::filesystem::exists(config.inputSource)) {
            spdlog::error("Provided file does not exist: '{}'", config.inputSource.string());
            return tl::make_unexpected(ParseFailure{config.inputSource, config.outputMetaHeader});
        }

        const auto lastWriteTime = std::filesystem::last_write_time(config.inputSource);
        auto includeStampsCollected = false;
        std::unordered_map<std::string, std::chrono::time_point<std::chrono::file_clock>> includeStamps;
        // if regeneration is forced or if compiler flags changed we need to regenerate
        if (!static_cast<bool>(ForceRegen) && !compilerFlagsChanged) {
            if (const auto iter = timestampDB.fileTimestamps.find(config.inputSource.string()); iter != timestampDB.fileTimestamps.end()) {
                const auto wasFileChanged = lastWriteTime > iter->second.lastChange;

                const auto currentIncludes = pf::meta_gen::IncludeCollector{config}.collectIncludes(true);
                bool anyIncludeChanged = std::ranges::any_of(currentIncludes, [&](const auto &path) {
                    return iter->second.includeChanges.find(path.string()) == iter->second.includeChanges.end();
                });

                for (const auto &path: currentIncludes) {
                    const auto currentLast = std::filesystem::last_write_time(path);
                    if (const auto i = iter->second.includeChanges.find(path.string()); i != iter->second.includeChanges.end()) {
                        anyIncludeChanged = anyIncludeChanged || (i->second < currentLast);
                    }
                    includeStamps[path.string()] = std::chrono::file_clock::now();
                }
                includeStampsCollected = true;

                if (!wasFileChanged && !anyIncludeChanged) {

                    spdlog::info("File '{}' was not changed", config.inputSource.string());
                    return ParseResult{config.inputSource, config.outputMetaHeader, iter->second.lastChange, includeStamps};
                }
            }
        }
        spdlog::info("Parsing file '{}'", config.inputSource.string());

        if (!includeStampsCollected) {
            const auto currentIncludes = pf::meta_gen::IncludeCollector{config}.collectIncludes(true);
            for (const auto &path: currentIncludes) { includeStamps[path.string()] = std::filesystem::last_write_time(path); }
        }

        std::vector<std::string> sources{config.inputSource.string()};

        clang::tooling::FixedCompilationDatabase fixedCompilationDatabase{".", config.compilerFlags};

        clang::tooling::ClangTool tool{fixedCompilationDatabase, sources};

        auto idGenerator = std::make_shared<pf::meta_gen::IdGenerator>();
        pf::meta_gen::ActionFactory factory{config, std::move(idGenerator)};
        if (const auto ret = tool.run(&factory); ret != 0) { spdlog::error("ClangTool run failed with code {}", ret); }

        if (FormatOutput) { ::format(std::string{config.outputMetaHeader.string()}); }
        return ParseResult{config.inputSource, config.outputMetaHeader, std::chrono::file_clock::now(), includeStamps};
    };

    std::unordered_map<std::string, FileTimestamps> newTimestamps;

    if (static_cast<bool>(RunSequential)) {
        std::vector<tl::expected<ParseResult, ParseFailure>> results;
        std::ranges::for_each(configs.sourceConfigs, [&](const auto &config) { results.emplace_back(generateMetaForSource(config)); });

        std::ranges::for_each(results, [&](auto &v) {
            if (!v.has_value()) {
                spdlog::error("File '{}' failed", v.error().inPath.string());
            } else {
                newTimestamps[v->inPath.string()].lastChange = v->stamp;
                newTimestamps[v->inPath.string()].includeChanges = v->includeStamps;
            }
        });

    } else {
        const auto threadCount = std::thread::hardware_concurrency();
        pf::meta_gen::ThreadPool threadPool{threadCount};

        std::vector<std::future<tl::expected<ParseResult, ParseFailure>>> results;
        std::ranges::for_each(configs.sourceConfigs, [&](const auto &config) {
            results.emplace_back(threadPool.enqueue([=] { return generateMetaForSource(config); }));
        });

        threadPool.finishAndStop();

        std::ranges::for_each(results, [&](auto &r) {
            const auto v = r.get();
            if (!v.has_value()) {
                spdlog::error("File '{}' failed", v.error().inPath.string());
            } else {
                newTimestamps[v->inPath.string()].lastChange = v->stamp;
                newTimestamps[v->inPath.string()].includeChanges = v->includeStamps;
            }
        });
    }

    timestampDB.fileTimestamps = std::move(newTimestamps);
    if (!configs.sourceConfigs.empty()) { timestampDB.compilerFlags = configs.sourceConfigs.front().compilerFlags; }

    updateProjectDatabase(timestampDB, configs.name);

    return 0;
}
