/**
 * @file PluginManager.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include "CodeGenerator.hpp"
#include <filesystem>
#include <meta/details/RangeOf.hpp>
#include <ranges>

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

namespace pf::meta_gen {

    class PluginManager {
    public:
        explicit PluginManager(const std::filesystem::path &pluginFolder);
        ~PluginManager();

        [[nodiscard]] meta::details::RangeOf<CodeGenerator *> auto getCodeGenerators() const {
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

        struct DLLData {
            DLLHandle dllHandle;
            CreateFunction createFunction;
            DestroyFunction destroyFunction;
            CodeGenerator *codeGenerator;
        };

        std::vector<DLLData> dllHandles;
    };

}// namespace pf::meta_gen
