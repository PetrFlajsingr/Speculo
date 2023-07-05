
#include "PluginManager.hpp"
#include <spdlog/spdlog.h>

namespace speculo::gen {

    constexpr auto DLL_EXTENSION =
#ifdef _WIN32
            ".dll";
#else
            ".so";
#endif

    PluginManager::PluginManager(const std::filesystem::path &pluginFolder) {
        spdlog::trace("Loading plugins");
        loadAllPluginsFromFolder(pluginFolder);
        spdlog::info("Found and loaded {} plugins", dllHandles.size());
    }

    PluginManager::~PluginManager() {
        for (const auto &[dllHandle, _1, destroy, codeGenerator]: dllHandles) {
            destroy(codeGenerator);
            FreeSharedLibrary(dllHandle);
        }
    }

    PluginManager::DLLHandle PluginManager::LoadSharedLibrary(const std::filesystem::path &path) {
#ifdef _WIN32
        return LoadLibrary(path.c_str());
#else
        return dlopen(path.c_str(), RTLD_LAZY);
#endif
    }

    void PluginManager::FreeSharedLibrary(PluginManager::DLLHandle handle) {
#ifdef _WIN32
        FreeLibrary(handle);
#else
        dlclose(handle);
#endif
    }

    std::pair<PluginManager::CreateFunction, PluginManager::DestroyFunction>
    PluginManager::GetPluginFunctions(PluginManager::DLLHandle handle) {
#ifdef _WIN32
        const auto createFunc = (CreateFunction) GetProcAddress(handle, "create");
        const auto destroyFunc = (DestroyFunction) GetProcAddress(handle, "destroy");
#else
        const auto createFunc = (CreateFunction) dlsym(handle, "create");
        const auto destroyFunc = (DestroyFunction) dlsym(handle, "destroy");
#endif
        return std::pair{createFunc, destroyFunc};
    }

    void PluginManager::loadAllPluginsFromFolder(const std::filesystem::path &folder) {
        if (!std::filesystem::exists(folder) || !std::filesystem::is_directory(folder)) {
            spdlog::trace("Plugin folder is not present");
            return;
        }

        for (const auto &entry: std::filesystem::directory_iterator{folder}) {
            if (!IsPluginFile(entry.path())) { continue; }

            const auto handle = LoadSharedLibrary(entry.path());
            if (handle == nullptr) {
                spdlog::warn("Could not load plugin '{}'", entry.path().string());
                continue;
            }
            const auto [createFunc, destroyFunc] = GetPluginFunctions(handle);
            if (createFunc == nullptr || destroyFunc == nullptr) {
                spdlog::warn("Plugin does not provide required interface '{}'", entry.path().string());
                continue;
            }
            spdlog::trace("Loaded plugin '{}'", entry.path().filename().string());
            dllHandles.emplace_back(handle, createFunc, destroyFunc, createFunc());
        }
    }

    bool PluginManager::IsPluginFile(const std::filesystem::path &path) {
        return path.has_extension() && path.extension() == DLL_EXTENSION;
    }


}// namespace speculo::gen