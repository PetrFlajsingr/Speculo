//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include <meta/details/ID.hpp>

namespace pf::meta_gen {
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
        std::size_t size;
        std::size_t alignment;

        bool isNestedType;
        Access nestedAccess;// only relevant if isNestedType == true

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
        // TODO: std::variant<std::shared_ptr<struct RecordTypeInfo>, std::shared_ptr<struct TypeInfo>> typeInfo;
    };

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
        bool isInline;
        bool isInlineSpecified;
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
        bool isInline;
        bool isInlineSpecified;
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
        bool isInline;
        bool isInlineSpecified;
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
        bool isInline;             // only for statics
        bool isInlineSpecified;    // only for statics
        bool isBitfield;           // only for members
        std::size_t bitfieldSize;  // only for members
        std::size_t bitfieldOffset;// only for members
        std::size_t byteOffset;    // only for members
        std::size_t size;          // only for members
        // TODO: std::variant<std::shared_ptr<struct RecordTypeInfo>, std::shared_ptr<struct TypeInfo *>> typeInfo;
    };

    struct BaseClassInfo {
        meta::details::ID id;
        std::string name;
        std::string fullName;
        bool isVirtual;
        Access access;
        SourceLocationInfo sourceLocation;
        std::size_t byteOffset;
        std::size_t size;
        std::shared_ptr<struct RecordTypeInfo> typeInfo;
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

        bool hasPfMetaGeneratedMacro;
    };

    using TypeInfoVariant = std::variant<std::shared_ptr<EnumTypeInfo>, std::shared_ptr<RecordTypeInfo>>;

}// namespace pf::meta_gen
