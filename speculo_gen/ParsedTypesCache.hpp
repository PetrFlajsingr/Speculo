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
#include "spdlog/spdlog.h"

namespace speculo::gen {

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
        const std::shared_ptr<TypeInfoVariant> &add(const std::string &typeName, std::shared_ptr<TypeInfoVariant> typeInfo) {
            if (typesCache.find(typeName) != typesCache.end()) {
                spdlog::error("Adding already existing type to ParsedTypesCache '{}'", typeName);
            }
            return typesCache.emplace(typeName, std::move(typeInfo)).first->second;
        }

        template<typename Creator>
            requires requires(Creator creator, TypeInfoVariant &result) {
                { creator(result) };
            }
        [[nodiscard]] std::shared_ptr<TypeInfoVariant> getOrAdd(const std::string &fullName, Creator creator) {
            if (auto getResult = get(fullName); getResult.has_value()) { return *getResult; }
            auto newInfo = std::make_shared<TypeInfoVariant>();
            add(fullName, newInfo);
            creator(*newInfo);
            return newInfo;
        }

    private:
        std::unordered_map<std::string, std::shared_ptr<TypeInfoVariant>> typesCache;
    };

}// namespace speculo::gen