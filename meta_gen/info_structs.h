//
// Created by xflajs00 on 17.03.2023.
//

#ifndef PF_META_INFO_STRUCTS_H
#define PF_META_INFO_STRUCTS_H

#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include "../meta/details/ID.h"

namespace pf::meta_gen {

    struct Attribute {
        std::string name;
        std::vector<std::string> arguments;
    };

    struct TypeInfo {
        pf::meta::details::ID id;
        std::string fullName;
        std::string name;
        struct {
            unsigned int line;
            unsigned int column;
            std::string filename;
        } sourceLocation;
    };

    struct EnumTypeInfo : public TypeInfo {
        struct ValueInfo {
            pf::meta::details::ID id;
            std::string fullName;
            std::variant<bool, std::uint64_t, std::int64_t> value;
            std::vector<Attribute> attributes;
            struct {
                unsigned int line;
                unsigned int column;
            } sourceLocation;
        };

        std::vector<Attribute> attributes;
        std::unordered_map<std::string, ValueInfo> values;
        std::string underlyingType;
    };

    using TypeInfoVariant = std::variant<EnumTypeInfo>;

}// namespace pf::meta_gen

#endif//PF_META_INFO_STRUCTS_H
