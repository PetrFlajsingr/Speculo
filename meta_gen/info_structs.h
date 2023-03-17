//
// Created by xflajs00 on 17.03.2023.
//

#ifndef PF_META_INFO_STRUCTS_H
#define PF_META_INFO_STRUCTS_H

#include <vector>
#include <string>
#include <variant>
#include <unordered_map>

namespace pf::meta_gen {

    struct Attribute {
        std::string name;
        std::vector<std::string> arguments;
    };

    struct TypeInfo {
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

    struct Variable {
        std::string fullName;
        std::string name;
        std::string type;
    };

    struct MemberVariable : Variable {
    };

    struct Function {
        std::string fullName;
        std::string name;
        std::string type;
        std::vector<std::pair<std::string, std::string>> args;
        std::vector<std::string> returnType;
    };

    struct MemberFunction : Function {
        bool isConst;
    };

    struct Constructor {
        bool isExplicit;
        std::vector<std::pair<std::string, std::string>> args;
    };

    struct RecordTypeInfo : public TypeInfo {
        enum class Type {
            Struct, Class, Union
        };
        Type type;

        std::vector<Constructor> constructors;
        // destructor
        std::vector<MemberFunction> memberFunctions;
        std::vector<Function> staticFunctions;
        std::vector<Variable> staticVariables;
        std::vector<MemberVariable> memberVariables;
        std::vector<std::string> nestedTypes;
    };


}

#endif //PF_META_INFO_STRUCTS_H
