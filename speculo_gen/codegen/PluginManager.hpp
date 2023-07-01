/**
 * @file PluginManager.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include "CodeGenerator.hpp"
#include <filesystem>
#include <ranges>
#include <speculo/details/RangeOf.hpp>

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

namespace speculo::gen {

    class PluginManager {
    public:
        explicit PluginManager(const std::filesystem::path &pluginFolder);
        ~PluginManager();

        [[nodiscard]] RangeOf<CodeGenerator *> auto getCodeGenerators() const {
            return dllHandles | std::views::transform([](const auto &d) { return d.codeGenerator; });
        }

    private:
#ifdef _WIN32
        using DLLHandle = HINSTANCE;
#else
        using DLLHandle = void *;
#endif

        using CreateFunction = CodeGenerator *(*) ();
        using DestroyFunction = void (*)(CodeGenerator *);

        [[nodiscard]] static DLLHandle LoadSharedLibrary(const std::filesystem::path &path);
        static void FreeSharedLibrary(DLLHandle handle);
        [[nodiscard]] std::pair<CreateFunction, DestroyFunction> GetPluginFunctions(DLLHandle handle);

        void loadAllPluginsFromFolder(const std::filesystem::path &folder);
        [[nodiscard]] static bool IsPluginFile(const std::filesystem::path &path);

        struct DLLData {
            DLLHandle dllHandle;
            CreateFunction createFunction;
            DestroyFunction destroyFunction;
            CodeGenerator *codeGenerator;
        };

        std::vector<DLLData> dllHandles;
    };

}// namespace speculo::gen
