/// @file SpdlogDiagnosticConsmuer.hpp
/// @brief
/// @author PetrFlajsingr

#pragma once

#include "clang/Basic/Diagnostic.h"
#include <spdlog/spdlog.h>

namespace pf::meta_gen {

    class SpdlogDiagnosticConsumer : public clang::DiagnosticConsumer {
    public:
        void HandleDiagnostic(clang::DiagnosticsEngine::Level diagLevel, const clang::Diagnostic &info) override {
            if (diagLevel == clang::DiagnosticsEngine::Error || diagLevel == clang::DiagnosticsEngine::Warning) {
                clang::SmallVector<char, 200> data;
                info.FormatDiagnostic(data);
                const auto file =
                        info.getSourceManager().getFileEntryForID(info.getSourceManager().getFileID(info.getLocation()))->getName().str();
                const auto line = info.getSourceManager().getSpellingLineNumber(info.getLocation());
                spdlog::error("[{}:{}] {}", file, line, std::string_view{data.begin(), data.end()});
            }
        }
    };

}// namespace pf::meta_gen