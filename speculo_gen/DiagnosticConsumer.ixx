module;

#include "wrap/clang_basic_diagnostic.hpp"
#include <spdlog/spdlog.h>
#include <clang/Basic/SourceManager.h>

export module speculo.gen:diagnostic_consumer;

namespace speculo::gen {

    class SpdlogDiagnosticConsumer : public clang::DiagnosticConsumer {
    public:
        void HandleDiagnostic(clang::DiagnosticsEngine::Level diagLevel, const clang::Diagnostic &info) override {
            if (isErrorOrWarning(diagLevel)) {
                const auto diagnosticData = formatDiagnostic(info);
                const auto [fileName, line] = getFileInfo(info);
                spdlog::error("[{}:{}] {}", fileName, line, diagnosticData);
            }
        }

    private:
        [[nodiscard]] static bool isErrorOrWarning(clang::DiagnosticsEngine::Level diagLevel) {
            return (diagLevel == clang::DiagnosticsEngine::Error || diagLevel == clang::DiagnosticsEngine::Warning);
        }
        [[nodiscard]] static std::string formatDiagnostic(const clang::Diagnostic &info) {
            clang::SmallVector<char, 200> data;
            info.FormatDiagnostic(data);
            return std::string{data.begin(), data.end()};
        }

        [[nodiscard]] static std::pair<std::string, std::uint32_t> getFileInfo(const clang::Diagnostic &info) {
            std::string fileName{};
            const auto line = info.getSourceManager().getSpellingLineNumber(info.getLocation());
            if (const auto file = info.getSourceManager().getFileEntryForID(info.getSourceManager().getFileID(info.getLocation()));
                file != nullptr) {
                fileName = file->getName().str();
            }
            return {fileName, line};
        }
    };

}// namespace speculo::gen