/// @file IncludeCollector.hpp
/// @brief
/// @author PetrFlajsingr

#pragma once

#include "SourceConfig.hpp"

namespace pf::meta_gen {

        class IncludeCollector {
        public:
            IncludeCollector(SourceConfig &c);

            [[nodiscard]] std::vector<std::filesystem::path> collectIncludes(bool skipSTDHeaders);
        private:
            const SourceConfig *config;
        };

}// namespace pf
