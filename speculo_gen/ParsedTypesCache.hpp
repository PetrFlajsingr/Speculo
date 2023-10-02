/**
 * @file ParsedTypesCache.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "Visitor.hpp"
#include "info_structs.hpp"
#include <spdlog/spdlog.h>

namespace speculo::gen {

    /// Internal type cache to avoid parsing AST multiple times.
    class ParsedTypesCache {
    public:
        [[nodiscard]] std::optional<std::shared_ptr<TypeInfoVariant>> get(const std::string &fullName) {
            if (const auto iter = typesCache.find(fullName); iter != typesCache.end()) { return iter->second; }
            return std::nullopt;
        }

        template<OneOf<EnumTypeInfo, RecordTypeInfo, IncompleteTypeInfo, FundamentalTypeInfo> T>
        [[nodiscard]] std::optional<std::reference_wrapper<T>> get(const std::string &fullName) {
            if (const auto iter = typesCache.find(fullName); iter != typesCache.end()) {
                if (!std::holds_alternative<T>(*iter->second)) { return std::nullopt; }
                return std::ref(std::get<T>(*iter->second));
            }
            return std::nullopt;
        }

        std::shared_ptr<TypeInfoVariant> add(std::shared_ptr<TypeInfoVariant> typeInfo) {
            const auto typeName = std::visit(Visitor{[&](const auto &info) { return info.fullName; }}, *typeInfo);
            return add(typeName, std::move(typeInfo));
        }
        std::shared_ptr<TypeInfoVariant> add(const TypeInfoVariant &typeInfo) {
            const auto typeName = std::visit(Visitor{[&](const auto &info) { return info.fullName; }}, typeInfo);
            return add(typeName, std::make_shared<TypeInfoVariant>(typeInfo));
        }
        /// @attention This function is just for type infos which are not yet parsed, but are added to the cache
        /// uninitialized - to be filled later by the caller. That's why type name is required instead
        /// of being extracted from type info structure.
        const std::shared_ptr<TypeInfoVariant> &add(const std::string &typeName, std::shared_ptr<TypeInfoVariant> typeInfo) {
            if (typesCache.find(typeName) != typesCache.end()) {
                spdlog::error("Adding already existing type to ParsedTypesCache '{}'", typeName);
            }
            return typesCache.emplace(typeName, std::move(typeInfo)).first->second;
        }

        /// Returns type info from cache if stored, otherwise calls <code>initializer</code> to create it and returns the created object.
        template<typename Initializer>
            requires requires(Initializer initializer, TypeInfoVariant &result) {
                { initializer(result) };
            }
        [[nodiscard]] std::shared_ptr<TypeInfoVariant> getOrAdd(const std::string &fullName, Initializer initializer) {
            if (auto getResult = get(fullName); getResult.has_value()) { return *getResult; }
            auto newInfo = std::make_shared<TypeInfoVariant>();
            add(fullName, newInfo);
            initializer(*newInfo);
            return newInfo;
        }

    private:
        std::unordered_map<std::string, std::shared_ptr<TypeInfoVariant>> typesCache;
    };

}// namespace speculo::gen