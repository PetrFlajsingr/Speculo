/// @file json.hpp
/// @brief
/// @author PetrFlajsingr

#pragma once

#include "messages.hpp"
#include <nlohmann/json.hpp>
#include <ranges>

// TODO: change to module

namespace speculo::gen {
    template<std::ranges::range R, typename Proj = std::identity>
    [[nodiscard]] nlohmann::json::array_t ToJsonArray(R &&r, Proj proj = {}) {
        nlohmann::json::array_t result;
        std::ranges::transform(r, std::back_inserter(result), proj);
        return result;
    }

    // Projection only from string
    template<typename T, typename Proj = std::identity>
    [[nodiscard]] std::vector<T> FromJsonArray(const nlohmann::json::array_t &arr, Proj proj = {}) {
        std::vector<T> result;
        result.reserve(arr.size());
        if constexpr (std::same_as<Proj, std::identity>) {
            std::ranges::transform(arr, std::back_inserter(result), &nlohmann::json::get<T>);
        } else {
            std::ranges::transform(arr, std::back_inserter(result), [&](const auto &j) {
                return proj(j.get<std::string>());
            });
        }
        return result;
    }
}


template<>
struct nlohmann::adl_serializer<speculo::gen::MessageType> {
    static void to_json(json &j, speculo::gen::MessageType msg) {
        switch (msg) {
            using
            enum speculo::gen::MessageType;
            case RegisterProject:
                j = "register_project";
                break;
            case RequestParsing:
                j = "request_parsing";
                break;
            case UnregisterProject:
                j = "unregister_project";
                break;
            case Echo:
                j = "echo";
                break;
            case List:
                j = "list";
                break;
            case Error:
                j = "error";
                break;
            default:
                j = "invalid";
                break;
        }
    }

    static void from_json(const json &j, speculo::gen::MessageType &p) {
        const auto str = j.get<std::string>();
        using
        enum speculo::gen::MessageType;
        if (str == "register_project") {
            p = RegisterProject;
        } else if (str == "request_parsing") {
            p = RequestParsing;
        } else if (str == "unregister_project") {
            p = UnregisterProject;
        } else if (str == "echo") {
            p = Echo;
        } else if (str == "list") {
            p = List;
        } else if (str == "error") {
            p = Error;
        }else {
            p = Invalid;
        }
    }
};


template<>
struct nlohmann::adl_serializer<speculo::gen::RegisterProjectMessage> {
    static void to_json(json &j, speculo::gen::RegisterProjectMessage msg) {
        j["project"] = msg.project;
        j["project_root"] = msg.projectRoot;
        j["include_paths"] = speculo::gen::ToJsonArray(msg.includePaths, [](const auto &p) { return p.string(); });
        j["compiler_flags"] = speculo::gen::ToJsonArray(msg.compilerFlags);
        j["defines"] = speculo::gen::ToJsonArray(msg.defines);
        j["header_paths"] = speculo::gen::ToJsonArray(msg.headerPaths, [](const auto &p) { return p.string(); });
    }

    static void from_json(const json &j, speculo::gen::RegisterProjectMessage &p) {
        p.project = j["project"];
        p.projectRoot = std::filesystem::path{j["project_root"].get<std::string>()};
        p.includePaths = speculo::gen::FromJsonArray<std::filesystem::path>(j["include_paths"],
                                                                            [](const auto &s) {
                                                                                return std::filesystem::path{s};
                                                                            });
        p.compilerFlags = speculo::gen::FromJsonArray<std::string>(j["compiler_flags"]);
        p.defines = speculo::gen::FromJsonArray<std::string>(j["defines"]);
        p.headerPaths = speculo::gen::FromJsonArray<std::filesystem::path>(j["header_paths"],
                                                                           [](const auto &s) {
                                                                               return std::filesystem::path{s};
                                                                           });
    }
};

template<>
struct nlohmann::adl_serializer<speculo::gen::UnregisterProjectMessage> {
    static void to_json(json &j, speculo::gen::UnregisterProjectMessage msg) {
        j["project"] = msg.project;
    }

    static void from_json(const json &j, speculo::gen::UnregisterProjectMessage &p) {
        p.project = j["project"];
    }
};

template<>
struct nlohmann::adl_serializer<speculo::gen::RequestParsingMessage> {
    static void to_json(json &j, speculo::gen::RequestParsingMessage msg) {
        j["project"] = msg.project;
    }

    static void from_json(const json &j, speculo::gen::RequestParsingMessage &p) {
        p.project = j["project"];
    }
};

namespace speculo::gen {
    [[nodiscard]] inline MessageType GetMessageType(const nlohmann::json &msg) {
        if (const auto typeIter = msg.find("type");
                typeIter != msg.end()) {
            return typeIter->get<MessageType>();
        }
        return MessageType::Invalid;
    }


    [[nodiscard]] nlohmann::json CreateSuccessMessage(std::string_view msg) {
        return {
                {"type",    MessageType::Success},
                {"message", msg}
        };
    }

    [[nodiscard]] nlohmann::json CreateEchoMessage(std::string_view response) {
        return {
                {"type",    MessageType::Echo},
                {"message", response}
        };
    }

    [[nodiscard]] nlohmann::json CreateErrorMessage(Error error) {
        return {
                {"type",    MessageType::Error},
                {"code",    static_cast<int>(error)},
                {"message", GetErrorMessage(error)}
        };
    }
}