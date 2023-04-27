#include "meta/Info.hpp"
#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include "meta_gen/AttributeParser.hpp"
#include "meta_gen/IdGenerator.hpp"
#include "meta_gen/clang_tooling_compilationdatabase_wrap.hpp"
#include "meta_gen/info_structs.hpp"

#include "format.hpp"
#include "meta_gen/AstActions.hpp"
#include <clang/Tooling/CommonOptionsParser.h>

#include <fstream>
#include <nlohmann/json.hpp>
#include <tl/expected.hpp>

#include "FileLock.hpp"
#include "meta_gen/Config.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <cppcoro/static_thread_pool.hpp>
#include <cppcoro/sync_wait.hpp>
#include <cppcoro/task.hpp>
#include <cppcoro/when_all.hpp>

static llvm::cl::OptionCategory PfMetaGenCategory("pf_meta_gen options");

static llvm::cl::opt<std::string> ConfigArg(llvm::cl::Required, "config", llvm::cl::desc("Specify input config"),
                                            llvm::cl::value_desc("filename"));
static llvm::cl::opt<bool> IgnoreIncludes("ignore-includes", llvm::cl::desc("Ignore includes while parsing the file"),
                                          llvm::cl::value_desc("bool"), llvm::cl::init(true));
static llvm::cl::opt<bool> FormatOutput("format-output", llvm::cl::desc("Reformat outputs"), llvm::cl::value_desc("bool"),
                                        llvm::cl::init(false));
static llvm::cl::opt<bool> ForceRegen("force", llvm::cl::desc("Force regeneration"), llvm::cl::value_desc("bool"), llvm::cl::init(false));


namespace nlohmann {
    template<typename Clock, typename Duration>
    struct adl_serializer<std::chrono::time_point<Clock, Duration>> {
        static void to_json(json &j, const std::chrono::time_point<Clock, Duration> &tp) {
            j["since_epoch"] = std::chrono::duration_cast<std::chrono::microseconds>(tp.time_since_epoch()).count();
            j["unit"] = "microseconds";
        }
        static void from_json(const json &j, std::chrono::time_point<Clock, Duration> &p) {
            const auto time_since_epoch = static_cast<unsigned long long>(j["since_epoch"]);
            p = std::chrono::time_point<Clock, Duration>{std::chrono::microseconds{time_since_epoch}};
        }
    };
}// namespace nlohmann

[[nodiscard]] std::unordered_map<std::string, std::chrono::time_point<std::chrono::file_clock>> loadTimestampDatabase() {
    const auto databasePath = std::filesystem::current_path() / "pf_meta_database.json";
    if (!std::filesystem::exists(databasePath)) {
        spdlog::info("Database file not found at '{}'", databasePath.string());
        return {};
    }

    pf::meta_gen::FileLock lock{databasePath};
    pf::meta_gen::FileLockGuard guard{lock};
    auto istream = std::ifstream{databasePath};
    if (!istream.is_open()) {
        spdlog::error("Can't open file '{}': {}", databasePath.string(), strerror(errno));
        return {};
    }
    auto data = nlohmann::json::parse(istream);
    istream.close();
    std::unordered_map<std::string, std::chrono::time_point<std::chrono::file_clock>> result{};
    for (const auto &rec: data.items()) { result[std::string{rec.key()}] = std::chrono::time_point<std::chrono::file_clock>{rec.value()}; }
    return result;
}
// only pass those parsed by this process
void updateTimestampDatabase(const std::unordered_map<std::string, std::chrono::time_point<std::chrono::file_clock>> &newStamps) {
    const auto databasePath = std::filesystem::current_path() / "pf_meta_database.json";
    pf::meta_gen::FileLock lock{databasePath};
    pf::meta_gen::FileLockGuard guard{lock};
    auto istream = std::ifstream{databasePath};
    nlohmann::json data;
    if (istream.is_open()) { data = nlohmann::json::parse(istream); }
    istream.close();

    for (const auto &[key, stamp]: newStamps) { data[key] = stamp; }
    auto ostream = std::ofstream{databasePath};
    if (!ostream.is_open()) {
        spdlog::error("Can't open file for write '{}': {}", databasePath.string(), strerror(errno));
        return;
    }
    ostream << data.dump(4);
}


[[nodiscard]] std::optional<std::vector<pf::meta_gen::Config>> createConfigs(const std::filesystem::path &configPath) {
    std::ifstream configFile{configPath};
    if (!configFile.is_open()) {
        spdlog::error("Can't open file '{}'", configPath.string());
        return std::nullopt;
    }
    auto data = nlohmann::json::parse(configFile);

    std::vector<pf::meta_gen::Config> result{};
    for (const auto &input: data["header_paths"]) {
        // TODO: multiple input files
        auto inputFile = std::filesystem::path{std::string{input}};
        const auto inputFileIncludePath = inputFile;
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

        std::vector<std::string> flags{"-xc++", "-Wno-unknown-attributes"};
        for (const auto &flag: data["compiler_flags"]) {
            flags.push_back(flag);
            if (!flags.back().starts_with('-')) { flags.back() = fmt::format("-{}", flags.back()); }
        }
        for (const auto &includePath: data["include_paths"]) { flags.push_back(fmt::format("-I{}", std::string{includePath})); }
        result.push_back({.inputSource = inputFile,
                          .outputMetaHeader = metaHeader,
                          .outputCodegenHeader = generatedHeader,
                          .outputCodegenSource = generatedSource,
                          .projectRootDir = projectRoot,
                          .ignoreIncludes = IgnoreIncludes,
                          .formatOutput = FormatOutput,
                          .compilerFlags = std::move(flags),
                          .inputIncludePath = inputFileIncludePath.string()});
    }
    return result;
}


int main(int argc, const char **argv) {
    spdlog::set_level(spdlog::level::debug);
    spdlog::default_logger()->sinks().clear();
    spdlog::default_logger()->sinks().emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    llvm::cl::ParseCommandLineOptions(argc, argv, "Test");

    auto configsOpt = createConfigs(std::filesystem::path{std::string{ConfigArg}});
    if (!configsOpt.has_value()) { return 0; }
    const auto configs = std::move(*configsOpt);

    const auto timestampDB = loadTimestampDatabase();

    cppcoro::static_thread_pool threadPool;

    struct ParseResult {
        std::filesystem::path inPath;
        std::filesystem::path outPath;
        std::chrono::time_point<std::chrono::file_clock> stamp;
    };
    struct ParseFailure {
        std::filesystem::path inPath;
        std::filesystem::path outPath;
    };

    const auto generateMetaForSource =
            [&timestampDB, &threadPool](pf::meta_gen::Config config) -> cppcoro::task<tl::expected<ParseResult, ParseFailure>> {
        co_await threadPool.schedule();

        const auto lastWriteTime = std::filesystem::last_write_time(config.inputSource);
        if (!static_cast<bool>(ForceRegen)) {
            if (const auto iter = timestampDB.find(config.inputSource.string()); iter != timestampDB.end()) {
                if (lastWriteTime < iter->second) {
                    spdlog::info("File '{}' was not changed", config.inputSource.string());
                    co_return ParseResult{config.inputSource, config.outputMetaHeader, iter->second};
                }
            }
        }

        std::vector<std::string> sources{config.inputSource.string()};

        clang::tooling::FixedCompilationDatabase fixedCompilationDatabase{".", config.compilerFlags};

        clang::tooling::ClangTool tool{fixedCompilationDatabase, sources};


        std::error_code errorCode;
        auto metaOutStream =
                std::make_shared<llvm::raw_fd_ostream>(config.outputMetaHeader.string(), errorCode, llvm::sys::fs::OpenFlags::OF_Text);
        if (errorCode) {
            spdlog::error("Failed to open output file: {}", errorCode.message());
            co_return tl::make_unexpected(ParseFailure{config.inputSource, config.outputMetaHeader});
        }
        auto codeGenOutStream =
                std::make_shared<llvm::raw_fd_ostream>(config.outputCodegenHeader.string(), errorCode, llvm::sys::fs::OpenFlags::OF_Text);
        if (errorCode) {
            spdlog::error("Failed to open output file: {}", errorCode.message());
            co_return tl::make_unexpected(ParseFailure{config.inputSource, config.outputMetaHeader});
        }
        auto idGenerator = std::make_shared<pf::meta_gen::IdGenerator>();
        pf::meta_gen::ActionFactory factory{config, metaOutStream, codeGenOutStream, idGenerator};
        if (const auto ret = tool.run(&factory); ret != 0) { spdlog::error("ClangTool run failed with code {}", ret); }

        metaOutStream->close();
        codeGenOutStream->close();

        if (FormatOutput) { format(std::string{config.outputMetaHeader.string()}); }
        co_return ParseResult{config.inputSource, config.outputMetaHeader, std::chrono::file_clock::now()};
    };

    std::vector<cppcoro::task<tl::expected<ParseResult, ParseFailure>>> tasks;
    std::ranges::for_each(configs, [&](const pf::meta_gen::Config &config) { tasks.emplace_back(generateMetaForSource(config)); });

    std::unordered_map<std::string, std::chrono::time_point<std::chrono::file_clock>> newTimestamps;
    const auto results = cppcoro::sync_wait(cppcoro::when_all(std::move(tasks)));
    std::ranges::for_each(results, [&](const auto &v) {
        if (!v.has_value()) {
            spdlog::error("File '{}' failed", v.error().inPath.string());
        } else {
            newTimestamps[v->inPath.string()] = v->stamp;
        }
    });
    updateTimestampDatabase(newTimestamps);


    return 0;
}
