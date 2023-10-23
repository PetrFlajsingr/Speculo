
import speculo;
import speculo.gen;


#include <fmt/core.h>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/spdlog.h>
#include <filesystem>
#include <future>

#include "speculo_gen/wrap/clang_tooling_compilationdatabase.hpp"
#include "speculo_gen/wrap/clang_tooling.hpp"

#include "format.hpp"
#include "speculo_gen/wrap/clang_tooling_commonoptionsparser.hpp"

#include <tl/expected.hpp>

#include "spdlog/sinks/stdout_color_sinks.h"
#include "speculo_gen/wrap/clang_lex_PreprocessorOptions.hpp"


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


[[nodiscard]] bool IsPauseFilePresent() {
    const auto pauseFilePath = std::filesystem::current_path() / "pause_speculo";
    return std::filesystem::exists(pauseFilePath);
}

int main(int argc, const char **argv) {
    if (IsPauseFilePresent()) {
        spdlog::trace("Speculo paused");
        return 0;
    }
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

    auto configsOpt = speculo::gen::createConfigs(std::filesystem::path{std::string{ConfigArg}}, IgnoreIncludes, FormatOutput);
    if (!configsOpt.has_value()) { return 0; }
    const auto configs = std::move(*configsOpt);

    auto timestampDB = speculo::gen::loadProjectDatabase(configs.name);


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
            [&timestampDB, compilerFlagsChanged](speculo::gen::SourceConfig config) -> tl::expected<ParseResult, ParseFailure> {
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

                const auto currentIncludes = speculo::gen::IncludeCollector{config}.collectIncludes(true);
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

                    spdlog::trace("File '{}' was not changed", config.inputSource.string());
                    return ParseResult{config.inputSource, config.outputMetaHeader, iter->second.lastChange, includeStamps};
                }
            }
        }
        spdlog::trace("Parsing file '{}'", config.inputSource.string());

        if (!includeStampsCollected) {
            const auto currentIncludes = speculo::gen::IncludeCollector{config}.collectIncludes(true);
            for (const auto &path: currentIncludes) { includeStamps[path.string()] = std::filesystem::last_write_time(path); }
        }

        auto idGenerator = std::make_shared<speculo::gen::IdGenerator>();

        std::vector<std::string> sources{config.inputSource.string()};


        // Codegen run
        {
            auto compilerFlags = config.compilerFlags;
            compilerFlags.emplace_back("-D SPECULO_CODE_GENERATOR_RUNNING");
            clang::tooling::FixedCompilationDatabase fixedCompilationDatabase{".", compilerFlags};

            clang::tooling::ClangTool tool{fixedCompilationDatabase, sources};
            config.runType = speculo::gen::RunType::Codegen;
            speculo::gen::ActionFactory factory{config, idGenerator};
            if (const auto ret = tool.run(&factory); ret != 0) { spdlog::error("ClangTool run failed with code {}", ret); }
        }
        // Metagen run
        {
            auto compilerFlags = config.compilerFlags;
            compilerFlags.emplace_back("-D SPECULO_META_GENERATOR_RUNNING");
            clang::tooling::FixedCompilationDatabase fixedCompilationDatabase{".", compilerFlags};

            clang::tooling::ClangTool tool{fixedCompilationDatabase, sources};
            config.runType = speculo::gen::RunType::Metagen;
            speculo::gen::ActionFactory factory{config, idGenerator};
            if (const auto ret = tool.run(&factory); ret != 0) { spdlog::error("ClangTool run failed with code {}", ret); }
        }

        if (FormatOutput) { ::format(std::string{config.outputMetaHeader.string()}); }
        return ParseResult{config.inputSource, config.outputMetaHeader, std::chrono::file_clock::now(), includeStamps};
    };

    std::unordered_map<std::string, speculo::gen::FileTimestamps> newTimestamps;

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
        speculo::gen::ThreadPool threadPool{threadCount};

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
