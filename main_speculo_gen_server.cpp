
#include <coroutine>
#include <iostream>
#include <cstdint>
#include <filesystem>
#include <string>
#include <cstddef>
#include <thread>
#include <fmt/format.h>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

#include "format.hpp"
#include "speculo_gen/wrap/clang_tooling_commonoptionsparser.hpp"

#include <asio/co_spawn.hpp>
#include <asio/detached.hpp>
#include <asio/thread_pool.hpp>
#include <asio/io_context.hpp>
#include <asio/ip/tcp.hpp>
#include <asio/signal_set.hpp>
#include <asio/write.hpp>

#include "speculo_gen/server/json.hpp"

#include <efsw/efsw.hpp>
#include <concepts>
#include "speculo_gen/server/Safe.hpp"
#include "speculo_gen/ProjectDatabase.hpp"
#include "speculo_gen/SourceConfig.hpp"
#include <flat/flat_map.hpp>
#include <utility>

#if defined(ASIO_ENABLE_HANDLER_TRACKING)
# define use_awaitable \
  asio::use_awaitable_t(__FILE__, __LINE__, __PRETTY_FUNCTION__)
#else
using asio::use_awaitable;
#endif

static llvm::cl::opt<std::string> IPArg(llvm::cl::Optional, "ip", llvm::cl::desc("IP for server to run on"),
                                        llvm::cl::value_desc("ip_address"), llvm::cl::init("127.0.0.1"));
static llvm::cl::opt<std::uint16_t> PortArg(llvm::cl::Optional, "port", llvm::cl::desc("Port for server to run on"),
                                            llvm::cl::value_desc("port"), llvm::cl::init(41584));

namespace speculo::gen {

    struct ProjectInfo {
        /// Name of the project.
        std::string name;
        /// Path to root of the project.
        std::filesystem::path root;
        /// Paths to input files, relative to root.
        std::vector<std::filesystem::path> inputFiles;
        bool ignoreIncludes;
        bool formatOutput;
        std::vector<std::string> compilerFlags;

        ProjectDatabase database;
    };

    template<typename Key, typename Value, std::size_t N>
    class StorageThingy {
    public:

        ~StorageThingy() {
            for (const auto &[_, index] : indexMap) {
                data()[index].~Value();
            }
        }

        [[nodiscard]] std::optional<std::reference_wrapper<Value>> get(const Key &key) {
            if (const auto iter = indexMap.find(key); iter != indexMap.end()) {
                return data()[iter->second];
            }
            return std::nullopt;
        }
        [[nodiscard]] std::optional<std::reference_wrapper<const Value>> get(const Key &key)const {
            if (const auto iter = indexMap.find(key); iter != indexMap.end()) {
                return data()[iter->second];
            }
            return std::nullopt;
        }

        [[nodiscard]] Value& operator[](const Key &key) {
            if (const auto iter = indexMap.find(key); iter != indexMap.end()) {
                return data()[iter->second];
            }
            return insert(key, Value{});
        }

        Value &insert(const Key &key, const Value &value) {
            if (auto opt = get(key); opt.has_value()) {
                opt->get() = value;
                return *opt;
            } else {
                assert(!availableIndices.empty());
                const auto index = availableIndices.back();
                availableIndices.pop_back();
                indexMap[key] = index;
                return *new (&data()[index]) Value{value};
            }
        }

        void erase(const Key &key) {
            if (const auto iter = indexMap.find(key); iter != indexMap.end()) {
                availableIndices.push_back(iter->second);
                data()[iter->second]->~Value();
                indexMap.erase(iter);
            }
        }
    private:
        [[nodiscard]] Value *data() {
            return std::launder<Value>(reinterpret_cast<Value*>(storage));
        }

        fc::vector_map<Key, std::size_t> indexMap;
        std::vector<std::size_t> availableIndices;
        alignas(Value) std::byte storage[sizeof(Value) * N];
    };

    class ProjectWatchServer {
    public:
        explicit ProjectWatchServer(asio::ip::tcp::endpoint tcpEndpoint) : endpoint{std::move(tcpEndpoint)} {
        }

        // blocks thread
        void start() {
            try {
                asio::thread_pool io_context{};

                asio::signal_set signals(io_context, SIGINT, SIGTERM);
                signals.async_wait([&](auto, auto) { io_context.stop(); });

                asio::co_spawn(io_context, listener(), asio::detached);

                io_context.join();
            }
            catch (std::exception &e) {
                spdlog::error("Exception: {}\n", e.what());
            }
        }

    private:
        Safe<StorageThingy<std::string, Safe<ProjectInfo>, 50>> projectInfos;

        asio::awaitable<void> listener() {
            try {
                auto executor = co_await asio::this_coro::executor;
                asio::ip::tcp::acceptor acceptor(executor, endpoint);
                acceptor.set_option(asio::ip::tcp::acceptor::reuse_address(true));
                for (;;) {
                    auto socket = co_await acceptor.async_accept(use_awaitable);
                    asio::co_spawn(executor, handleClient(std::move(socket)), asio::detached);
                }
            }
            catch (std::exception &e) {
                spdlog::error("Exception: {}\n", e.what());
            }
        }


        asio::awaitable<void> handleMessage(asio::ip::tcp::socket &socket, MessageType messageType, const nlohmann::json &jsonMsg) {
            std::string responseStr;
            switch (messageType) {
                using
                enum speculo::gen::MessageType;
                case RegisterProject: {
                    spdlog::info("Register project request");

                    const auto registerMsg = jsonMsg.get<RegisterProjectMessage>();
                    auto &newProjectInfo = (*projectInfos.get())[registerMsg.project];
                    auto newProjectInfoAccess = *newProjectInfo;
                    assert(false && "Not implemented");
                    responseStr = nlohmann::to_string(CreateSuccessMessage("Message received"));
                }
                    break;
                case RequestParsing: {
                    spdlog::info("Request parsing request");
                    responseStr = nlohmann::to_string(CreateSuccessMessage("Message received"));
                }
                    break;
                case UnregisterProject: {
                    spdlog::info("Unregister project request");
                    responseStr = nlohmann::to_string(CreateSuccessMessage("Message received"));
                }
                    break;
                case Echo: {
                    spdlog::info("Echo request");
                    responseStr = nlohmann::to_string(CreateEchoMessage(jsonMsg["message"]));
                }
                    break;
                case Invalid: {
                    spdlog::info("Invalid client request");
                    responseStr = nlohmann::to_string(CreateErrorMessage(Error::RequestInvalid));
                }
                    break;
                default:
                    assert(false && "Unexpected code path triggered");
            }
            co_await asio::async_write(socket, asio::buffer(responseStr.data(), responseStr.size()),
                                       use_awaitable);
        }


        asio::awaitable<void> handleClient(asio::ip::tcp::socket socket) {
            using namespace speculo::gen;
            try {
                char buffer[65536];
                const auto n = co_await socket.async_read_some(asio::buffer(buffer), use_awaitable);
                const auto bufferView = std::string_view{buffer, n};
                spdlog::trace("Received message '{}'", bufferView);

                const auto jsonMsg = nlohmann::json::parse(bufferView, nullptr, false);
                if (jsonMsg.is_discarded()) {
                    spdlog::info("Invalid client request format");
                    // TODO: document this
                    const auto response = CreateErrorMessage(Error::RequestNotJson);
                    const auto responseStr = nlohmann::to_string(response);
                    co_await asio::async_write(socket, asio::buffer(responseStr.data(), responseStr.size()),
                                               use_awaitable);
                    co_return;
                }
                const auto messageType = speculo::gen::GetMessageType(jsonMsg);
                if (!IsMessageValid(jsonMsg, messageType)) {
                    spdlog::info("Missing items in client request");
                    // TODO: document this
                    const auto response = CreateErrorMessage(Error::RequestIncomplete);
                    const auto responseStr = nlohmann::to_string(response);
                    co_await asio::async_write(socket, asio::buffer(responseStr.data(), responseStr.size()),
                                               use_awaitable);
                    co_return;
                }
                co_await handleMessage(socket, messageType, jsonMsg);
            }
            catch (std::exception &e) {
                std::cout << fmt::format("echo Exception: {}\n", e.what());
            }
        }

        asio::ip::tcp::endpoint endpoint;
    };
}



class UpdateListener : public efsw::FileWatchListener {
public:
    void handleFileAction(efsw::WatchID watchid, const std::string &dir,
                          const std::string &filename, efsw::Action action,
                          std::string oldFilename) override {
        switch (action) {
            case efsw::Actions::Add:
                spdlog::info("DIR ({}) FILE ({}) has event Added", dir, filename);
                break;
            case efsw::Actions::Delete:
                spdlog::info("DIR ({}) FILE ({}) has event Delete", dir, filename);
                break;
            case efsw::Actions::Modified:
                spdlog::info("DIR ({}) FILE ({}) has event Modified", dir, filename);
                break;
            case efsw::Actions::Moved:
                spdlog::info("DIR ({}) FILE ({}) has event Moved from ({})", dir, filename, oldFilename);
                break;
            default:
                assert(false && "Wat");
        }
    }
};

void testFileWatcher() {
    static efsw::FileWatcher fileWatcher{};
    static UpdateListener listener{};
    [[maybe_unused]] const auto watchID_dir = fileWatcher.addWatch("C:\\Users\\xflajs00\\Desktop\\test", &listener,
                                                                   true);
    [[maybe_unused]] const auto watchID_file = fileWatcher.addWatch(
            "C:\\Users\\xflajs00\\Desktop\\test\\dsfgsdfgdsfgsdfgdfg.rdc", &listener, true);

    fileWatcher.watch();
}


[[nodiscard]] asio::ip::address_v4 ParseArgAddress() {
    llvm::SmallVector<std::uint8_t, 4> bytes;
    std::string part;
    std::istringstream ipStream{static_cast<std::string>(IPArg)};

    while (std::getline(ipStream, part, '.')) {
        const auto byte = std::stoi(part);
        if (byte < 0 || byte > 255) {
            throw std::range_error("IP address part is out of range of a byte");
        }
        bytes.push_back(static_cast<std::uint8_t>(byte));
    }

    if (bytes.size() != 4) {
        throw std::length_error("IP address doesn't consist of exactly 4 parts");
    }

    return asio::ip::address_v4{{bytes[0], bytes[1], bytes[2], bytes[3]}};
}

int main(int argc, const char **argv) {
    llvm::cl::ParseCommandLineOptions(argc, argv, "Test");

    speculo::gen::ProjectWatchServer server{{{ParseArgAddress()}, static_cast<std::uint16_t>(PortArg)}};

    server.start();

    return 0;
}