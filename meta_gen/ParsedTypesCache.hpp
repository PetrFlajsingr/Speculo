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

namespace pf::meta_gen {

    class ParsedTypesCache {
    public:
        [[nodiscard]] std::shared_ptr<RecordTypeInfo> getRecord(const std::string &fullName) {
            if (const auto iter = recordTypes.find(fullName); iter != recordTypes.end()) { return iter->second; }
            return nullptr;
        }
        [[nodiscard]] std::shared_ptr<TypeInfo> getOther(const std::string &fullName) {
            if (const auto iter = otherTypes.find(fullName); iter != otherTypes.end()) { return iter->second; }
            return nullptr;
        }

        void addRecord(const std::shared_ptr<RecordTypeInfo> &record) { recordTypes.emplace(record->fullName, record); }
        void addOther(const std::shared_ptr<TypeInfo> &typeInfo) { otherTypes.emplace(typeInfo->fullName, typeInfo); }
        void add(TypeInfoVariant typeInfo) {
            std::visit(Visitor{[&](const std::shared_ptr<EnumTypeInfo> &enumInfo) { addOther(enumInfo); },
                               [&](const std::shared_ptr<RecordTypeInfo> &enumInfo) { addRecord(enumInfo); }},
                       typeInfo);
        }

    private:
        std::unordered_map<std::string, std::shared_ptr<RecordTypeInfo>> recordTypes;
        std::unordered_map<std::string, std::shared_ptr<TypeInfo>> otherTypes;
    };

}// namespace pf::meta_gen