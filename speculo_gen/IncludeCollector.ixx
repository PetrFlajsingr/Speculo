module;

#include <vector>
#include <filesystem>

export module speculo.gen:include_collector;
import :source_config;

export namespace speculo::gen {

    class IncludeCollector {
    public:
        IncludeCollector(SourceConfig &c);

        [[nodiscard]] std::vector<std::filesystem::path> collectIncludes(bool skipSTDHeaders);

    private:
        const SourceConfig *config;
    };

}// namespace speculo::gen
