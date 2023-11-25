/// @file messages.hpp
/// @brief 
/// @author PetrFlajsingr

#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <filesystem>
#include <vector>
#include <limits>

// TODO: change to module
namespace speculo::gen {
    enum class MessageType : std::uint32_t {
        Success = 0u, // success response
        RegisterProject = 1u, // register project/replace old one with new info
        RequestParsing = 2u, // request parsing for a certain project
        UnregisterProject = 3u, // remove project registration
        Echo = 4u, // echo request/response
        List = 5u, // send back string with project info

        Error = 1000u,
        Invalid = std::numeric_limits<std::uint32_t>::max()
    };

    enum class Error {
        RequestInvalid = 1,
        RequestNotJson = 2,
        RequestIncomplete = 3
    };


    [[nodiscard]] constexpr std::string_view GetErrorMessage(Error error) {
        switch (error) {
            using
            enum Error;
            case RequestInvalid:
                return "Invalid request provided by client";
            case RequestNotJson:
                return "Invalid message format provided by client - not JSON";
            case RequestIncomplete:
                return "Message is missing required items"; // TODO: specify missing items
        }
        if (std::is_constant_evaluated()) {
            throw "Invalid enum value provided";
        } else {
            assert(false && "Not implemented");
            return {};
        }
    }

    [[nodiscard]] bool IsMessageValid(const nlohmann::json &msg, MessageType msgType) {
        switch (msgType) {
            using
            enum MessageType;
            case Echo: {
                if (const auto iter = msg.find("message"); iter != msg.end()) {
                    return msg["message"].is_string();
                }
                return false;
            }
            default:
                assert(false && "Not implemented");
        }
        return false;
    }


    struct RegisterProjectMessage {
        std::string project;
        std::filesystem::path projectRoot;
        std::vector<std::filesystem::path> includePaths;
        std::vector<std::string> compilerFlags;
        std::vector<std::string> defines;
        std::vector<std::filesystem::path> headerPaths;
    };

    struct UnregisterProjectMessage {
        std::string project;
    };
    struct RequestParsingMessage {
        std::string project;
        std::vector<std::filesystem::path> headerPaths;
    };

}