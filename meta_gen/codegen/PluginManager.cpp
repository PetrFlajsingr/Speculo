
#include "PluginManager.hpp"
#include <spdlog/spdlog.h>

namespace pf::meta_gen {


    PluginManager::PluginManager(const std::filesystem::path &pluginFolder) {
#ifdef _WIN32
        constexpr auto DLL_EXTENSION = ".dll";
#else
        constexpr auto DLL_EXTENSION = ".so";
#endif
        spdlog::trace("Loading plugins");

        if (!std::filesystem::exists(pluginFolder) || !std::filesystem::is_directory(pluginFolder)) {
            spdlog::trace("Plugin folder is not present");
            return;
        }
        for (const auto &entry: std::filesystem::directory_iterator{pluginFolder}) {
            if (entry.path().has_extension() && entry.path().extension() == DLL_EXTENSION) {
#ifdef _WIN32
                const auto handle = LoadLibrary(entry.path().c_str());
#else
                const auto handle = dlopen(entry.path().c_str(), RTLD_LAZY);
#endif
                if (handle == nullptr) {
                    spdlog::warn("Could not load plugin '{}'", entry.path().string());
                    continue;
                }
#ifdef _WIN32
                const auto createFunc = (CreateFunction) GetProcAddress(handle, "create");
                const auto destroyFunc = (DestroyFunction) GetProcAddress(handle, "destroy");
#else
                const auto createFunc = (CreateFunction) dlsym(handle, "create");
                const auto destroyFunc = (DestroyFunction) dlsym(handle, "destroy");
#endif
                if (createFunc == nullptr || destroyFunc == nullptr) {
                    spdlog::warn("Plugin does not provide required interface '{}'", entry.path().string());
                    continue;
                }
                spdlog::trace("Loaded plugin '{}'", entry.path().filename().string());
                dllHandles.emplace_back(handle, createFunc, destroyFunc, createFunc());
            }
        }
        spdlog::info("Found and loaded {} plugins", dllHandles.size());
    }

    PluginManager::~PluginManager() {
        for (const auto &[dllHandle, _1, destroy, codeGenerator]: dllHandles) {
            destroy(codeGenerator);
#ifdef _WIN32
            FreeLibrary(dllHandle);
#else
            dlclose(dllHandle);
#endif
        }
    }


}// namespace pf::meta_gen