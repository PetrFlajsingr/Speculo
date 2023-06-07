
#include "IncludeCollector.hpp"
#include "fmt/format.h"

#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Tooling/CompilationDatabase.h>
#include <clang/Tooling/Tooling.h>

namespace pf::meta_gen {
    class IgnoreDiagnosticConsumer : public clang::DiagnosticConsumer {
    public:
        void HandleDiagnostic(clang::DiagnosticsEngine::Level, const clang::Diagnostic &) override {}
    };

    class IncludeSearchCallback : public clang::PPCallbacks {
    public:
        IncludeSearchCallback(const std::vector<std::filesystem::path> &ignoredPaths, std::vector<std::filesystem::path> &o)
            : ignoredPaths{ignoredPaths}, output{o} {}

        void InclusionDirective(clang::SourceLocation HashLoc, const clang::Token &IncludeTok, clang::StringRef FileName, bool IsAngled,
                                clang::CharSourceRange FilenameRange, clang::OptionalFileEntryRef File, clang::StringRef SearchPath,
                                clang::StringRef RelativePath, const clang::Module *Imported,
                                clang::SrcMgr::CharacteristicKind FileType) override {
            // TODO: ignore generated/<filename>.hpp as well
            // if empty it was probably not found - might be STD header
            if (SearchPath.empty()) { return; }
            auto path = std::filesystem::path(SearchPath.str()) / FileName.str();
            if (std::ranges::find(ignoredPaths, path) != ignoredPaths.end()) { return; }
            // if the file does not exist it is irrelevant
            if (!std::filesystem::exists(path)) { return; }
            output.emplace_back(path);
        }

    private:
        const std::vector<std::filesystem::path> &ignoredPaths;
        std::vector<std::filesystem::path> &output;
    };

    class IncludeSearchAction : public clang::PreprocessOnlyAction {
    public:
        IncludeSearchAction(const std::vector<std::filesystem::path> &ignoredPaths, std::vector<std::filesystem::path> &o)
            : ignoredSubstr{ignoredPaths}, output{o} {}

    public:
        void ExecuteAction() override {
            clang::CompilerInstance &compilerInstance = getCompilerInstance();
            clang::Preprocessor &preprocessor = compilerInstance.getPreprocessor();
            compilerInstance.getDiagnostics().setClient(new IgnoreDiagnosticConsumer{});

            preprocessor.addPPCallbacks(std::make_unique<IncludeSearchCallback>(ignoredSubstr, output));
            PreprocessOnlyAction::ExecuteAction();
        }

    private:
        const std::vector<std::filesystem::path> &ignoredSubstr;
        std::vector<std::filesystem::path> &output;
    };

    class IncludeSearchActionFactory : public clang::tooling::FrontendActionFactory {
    public:
        explicit IncludeSearchActionFactory(const std::vector<std::filesystem::path> &ignoredPaths) : ignoredPaths(ignoredPaths) {}
        std::unique_ptr<clang::FrontendAction> create() override { return std::make_unique<IncludeSearchAction>(ignoredPaths, output); }

        std::vector<std::filesystem::path> ignoredPaths;
        std::vector<std::filesystem::path> output;
    };


    IncludeCollector::IncludeCollector(SourceConfig &c) : config{&c} {}

    std::vector<std::filesystem::path> IncludeCollector::collectIncludes(bool skipSTDHeaders) {
        auto includeSearchFlags = config->compilerFlags;
        if (skipSTDHeaders) {
            includeSearchFlags.emplace_back("-nostdinc");
            includeSearchFlags.emplace_back("-nostdlib");
            includeSearchFlags.emplace_back("-nostdlib++");
            includeSearchFlags.emplace_back("-nodefaultlibs");
        }
        clang::tooling::FixedCompilationDatabase fixedCompilationDatabase{".", includeSearchFlags};
        std::vector<std::string> sources{config->inputSource.string()};

        clang::tooling::ClangTool tool(fixedCompilationDatabase, sources);

        IncludeSearchActionFactory actionFactory{{config->outputCodegenHeader}};
        tool.run(&actionFactory);

        std::ranges::sort(actionFactory.output);
        const auto [rmBeg, rmEnd] = std::ranges::unique(actionFactory.output);
        actionFactory.output.erase(rmBeg, rmEnd);
        return actionFactory.output;
    }
}// namespace pf::meta_gen