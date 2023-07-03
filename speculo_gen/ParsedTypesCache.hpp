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

namespace speculo::gen {

    class ParsedTypesCache {
    public:
        [[nodiscard]] std::optional<TypeInfoVariant> get(const std::string &fullName) {
            if (const auto iter = typesCache.find(fullName); iter != typesCache.end()) { return iter->second; }
            return std::nullopt;
        }

        template<OneOf<EnumTypeInfo, RecordTypeInfo, IncompleteTypeInfo, FundamentalTypeInfo> T>
        [[nodiscard]] std::optional<std::shared_ptr<T>> get(const std::string &fullName) {
            if (const auto iter = typesCache.find(fullName); iter != typesCache.end()) {
                if (!std::holds_alternative<std::shared_ptr<T>>(iter->second)) { return std::nullopt; }
                return std::get<std::shared_ptr<T>>(iter->second);
            }
            return std::nullopt;
        }

        void add(TypeInfoVariant typeInfo) {
            std::visit(Visitor{[&](const auto &info) { addToCache(info); }}, typeInfo);
        }

        template<std::invocable Getter>
            requires requires(Getter getter) {
                { getter() } -> std::same_as<TypeInfoVariant>;
            }
        [[nodiscard]] TypeInfoVariant getOrAdd(const std::string &fullName, Getter getter) {
            if (auto getResult = get(fullName); getResult.has_value()) { return *getResult; }
            TypeInfoVariant newInfo = getter();
            add(newInfo);
            return newInfo;
        }
        template<OneOf<EnumTypeInfo, RecordTypeInfo, IncompleteTypeInfo, FundamentalTypeInfo> T, std::invocable Getter>
            requires requires(Getter getter) {
                { getter() } -> std::same_as<std::shared_ptr<T>>;
            }
        [[nodiscard]] std::shared_ptr<T> getOrAdd(const std::string &fullName, Getter getter) {
            if (auto getResult = get<T>(fullName); getResult.has_value()) { return *getResult; }
            auto newInfo = getter();
            add(newInfo);
            return newInfo;
        }

    private:
        void addToCache(const auto &info) { typesCache.try_emplace(info->fullName, info); }

        std::unordered_map<std::string, TypeInfoVariant> typesCache;
    };

}// namespace speculo::gen