module;

#include <chrono>
#include <nlohmann/json.hpp>


export module speculo.gen:json_serializers;
import :project_database;

export template<typename Clock, typename Duration>
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

export template<>
struct nlohmann::adl_serializer<speculo::gen::FileTimestamps> {
    static void to_json(json &j, const speculo::gen::FileTimestamps &tp) {
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
    static void from_json(const json &j, speculo::gen::FileTimestamps &p) {
        p.lastChange = j["timestamp"];
        json::array_t includes = j["includes"];
        std::ranges::for_each(includes, [&](const auto &include) { p.includeChanges[include["path"]] = include["timestamp"]; });
    }
};
