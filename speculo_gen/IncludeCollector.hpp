/// @file IncludeCollector.hpp
/// @brief
/// @author PetrFlajsingr

#pragma once

#include "SourceConfig.hpp"

namespace speculo::gen {

    class IncludeCollector {
    public:
        IncludeCollector(SourceConfig &c);

        [[nodiscard]] std::vector<std::filesystem::path> collectIncludes(bool skipSTDHeaders);

    private:
        const SourceConfig *config;
    };

}// namespace speculo::gen
