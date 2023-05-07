//
// Created by xflajs00 on 17.03.2023.
//

#ifndef PF_META_INFO_STRUCTS_H
#define PF_META_INFO_STRUCTS_H

#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include "../meta/details/ID.hpp"

namespace pf::meta_gen {

    struct Attribute {
        std::string nnamespace;
        std::string name;
        std::vector<std::string> arguments;
    };

    struct SourceLocationInfo {
        unsigned int line;
        unsigned int column;
        std::string filename;
    };

    struct TypeInfo {
        meta::details::ID id;
        meta::details::ID constId;
        meta::details::ID lrefId;
        meta::details::ID rrefId;
        meta::details::ID constLrefId;
        meta::details::ID ptrId;
        meta::details::ID constPtrId;
        std::string fullName;
        std::string name;
        SourceLocationInfo sourceLocation;

        std::string originalCode;
    };

    struct EnumTypeInfo : TypeInfo {
        struct ValueInfo {
            meta::details::ID id;
            std::string fullName;
            std::variant<bool, std::uint64_t, std::int64_t> value;
            std::vector<Attribute> attributes;
            SourceLocationInfo sourceLocation;
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
        std::string typeName;
        std::vector<Attribute> attributes;
        SourceLocationInfo sourceLocation;
    };

    enum class Access { Private, Protected, Public };

    [[nodiscard]] constexpr std::string_view AccessToString(Access access) {
        switch (access) {
            case Access::Private: {
                return "Private";
            }
            case Access::Protected: {
                return "Protected";
            }
            case Access::Public: {
                return "Public";
            }
        }
        return "";
        // std::unreachable
    }

    struct ConstructorInfo {
        meta::details::ID id;
        std::string fullName;
        std::vector<FunctionArgument> arguments;
        std::vector<Attribute> attributes;
        bool isConstexpr;
        bool isConsteval;
        bool isExplicit;
        Access access;
        SourceLocationInfo sourceLocation;
        bool isCopy;
        bool isMove;
    };

    struct DestructorInfo {
        meta::details::ID id;
        std::string fullName;
        Access access;
        std::vector<Attribute> attributes;
        SourceLocationInfo sourceLocation;
        bool isConstexpr;
        bool isConsteval;
        bool isVirtual;
        bool isPureVirtual;
        bool isFinal;
    };

    // TODO: operators separately?
    struct FunctionInfo {
        meta::details::ID id;
        std::string name;
        std::string fullName;
        std::vector<FunctionArgument> arguments;
        std::vector<Attribute> attributes;
        meta::details::ID returnTypeId;
        std::string returnTypeName;
        Access access;
        bool isConstexpr;
        bool isConsteval;
        bool isConst;
        bool isVirtual;
        bool isPureVirtual;
        bool isFinal;
        SourceLocationInfo sourceLocation;
    };

    struct VariableInfo {
        meta::details::ID id;
        std::string name;
        std::string fullName;
        meta::details::ID typeId;
        std::string typeName;
        std::vector<Attribute> attributes;
        Access access;
        bool isMutable;  // only for members
        bool isConstexpr;// only for statics
        SourceLocationInfo sourceLocation;
    };

    struct BaseClassInfo {
        meta::details::ID id;
        std::string name;
        std::string fullName;
        bool isVirtual;
        Access access;
        SourceLocationInfo sourceLocation;
    };

    struct RecordTypeInfo : TypeInfo {
        bool isUnion;
        bool isClass;
        bool isStruct;
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
