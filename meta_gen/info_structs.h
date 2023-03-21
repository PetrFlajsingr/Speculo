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
        meta::details::ID id;
        std::string fullName;
        std::string name;
        struct {
            unsigned int line;
            unsigned int column;
            std::string filename;
        } sourceLocation;
    };

    struct EnumTypeInfo : TypeInfo {
        struct ValueInfo {
            meta::details::ID id;
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

    struct FunctionArgument {
        meta::details::ID id;
        meta::details::ID typeId;
        std::string name;
        std::string fullName;
        std::vector<Attribute> attributes;
    };

    enum class Access {
        Private, Protected, Public
    };

    struct ConstructorInfo {
        meta::details::ID id;
        std::vector<FunctionArgument> arguments;
        std::vector<Attribute> attributes;
        bool isConstexpr;
        bool isConsteval;
        bool isExplicit;
        Access access;
        // TODO: add more
    };

    struct DestructorInfo {
        meta::details::ID id;
        Access access;
        std::vector<Attribute> attributes;
        bool isConstexpr;
        bool isConsteval;
        bool isVirtual;
        bool isPureVirtual;
    };

    // TODO: operators separately?
    struct FunctionInfo {
        meta::details::ID id;
        std::string name;
        std::string fullName;
        std::vector<FunctionArgument> arguments;
        std::vector<Attribute> attributes;
        meta::details::ID returnTypeId;
        Access access;
        bool isConstexpr;
        bool isConsteval;
        bool isConst;
        bool isVirtual;
        bool isPureVirtual;
    };

    struct VariableInfo {
        meta::details::ID id;
        std::string name;
        std::string fullName;
        meta::details::ID typeId;
        std::vector<Attribute> attributes;
        Access access;
        bool isMutable;
    };

    struct BaseClassInfo {
        meta::details::ID id;
        // TODO: attributes?
        bool isVirtual;
        Access access;
    };

    struct RecordTypeInfo : TypeInfo {
        bool isUnion;
        std::vector<Attribute> attributes;

        std::vector<BaseClassInfo> baseClasses;
        std::vector<ConstructorInfo> constructors;
        DestructorInfo destructor;
        std::vector<FunctionInfo> memberFunctions;
        std::vector<VariableInfo> memberVariables;
        std::vector<FunctionInfo> staticFunctions;
        std::vector<VariableInfo> staticVariables;

        bool isPolymorphic;
        bool isAbstract;
        bool isFinal;
    };

    using TypeInfoVariant = std::variant<EnumTypeInfo, RecordTypeInfo>;

}// namespace pf::meta_gen

#endif//PF_META_INFO_STRUCTS_H
