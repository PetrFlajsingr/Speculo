//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include <speculo/ID.hpp>
#include <speculo/details/OneOf.hpp>

namespace speculo::gen {
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

    using TypeInfoVariant = std::variant<std::shared_ptr<struct EnumTypeInfo>, std::shared_ptr<struct RecordTypeInfo>,
                                         std::shared_ptr<struct IncompleteTypeInfo>, std::shared_ptr<struct FundamentalTypeInfo>>;

    struct Attribute {
        std::string nnamespace;
        std::string name;
        std::vector<std::string> arguments;
    };

    struct SourceLocationInfo {
        std::uint32_t line;
        std::uint32_t column;
        std::string filename;
    };

    struct TypeInfo {
        speculo::ID id;
        speculo::ID constId;
        speculo::ID lrefId;
        speculo::ID rrefId;
        speculo::ID constLrefId;
        speculo::ID ptrId;
        speculo::ID constPtrId;
        speculo::ID volatileId;
        speculo::ID volatileConstId;
        speculo::ID volatileLrefId;
        speculo::ID volatileRrefId;
        speculo::ID volatileConstLrefId;
        speculo::ID volatilePtrId;
        speculo::ID volatileConstPtrId;

        std::string fullName;
        std::string name;

        std::optional<SourceLocationInfo> sourceLocation;

        std::size_t size;
        std::size_t alignment;

        /// Set only for nested types.
        std::optional<Access> access;

        std::string originalCode;
    };

    /// Incomplete type, to be used mainly for functions arguments, return types and such.
    struct IncompleteTypeInfo : TypeInfo {};

    struct FundamentalTypeInfo : TypeInfo {};

    enum class TypeForm {
        Normal,   // T
        Const,    // const T
        LRef,     // T &
        ConstLRef,// const T &
        RRef,     // T &&
        Ptr,      // T *
        ConstPtr, // const T *
        Other     // anything else
    };
    struct TypeUsage {
        TypeInfoVariant type;
        TypeForm form;
        std::string fullName;
    };

    struct EnumTypeInfo : TypeInfo {
        struct ValueInfo {
            speculo::ID id;
            std::string fullName;
            std::variant<bool, std::uint64_t, std::int64_t> value;
            std::vector<Attribute> attributes;
            SourceLocationInfo sourceLocation;
        };

        std::vector<Attribute> attributes;
        std::unordered_map<std::string, ValueInfo> values;
        bool isScoped;
        TypeUsage underlyingType;
    };

    struct FunctionArgument {
        speculo::ID id;
        std::string name;
        std::string fullName;

        std::vector<Attribute> attributes;
        SourceLocationInfo sourceLocation;

        TypeUsage type;
    };

    struct ConstructorInfo {
        speculo::ID id;
        std::string fullName;
        std::vector<FunctionArgument> arguments;
        std::vector<Attribute> attributes;
        bool isConstexpr;
        bool isConsteval;
        bool isExplicit;
        Access access;
        std::optional<SourceLocationInfo> sourceLocation;
        bool isCopy;
        bool isMove;
        bool isInline;
        bool isInlineSpecified;
        bool isNothrow;
    };

    struct DestructorInfo {
        speculo::ID id;
        std::string fullName;
        Access access;
        std::vector<Attribute> attributes;
        std::optional<SourceLocationInfo> sourceLocation;
        bool isConstexpr;
        bool isConsteval;
        bool isVirtual;
        bool isPureVirtual;
        bool isFinal;
        bool isInline;
        bool isInlineSpecified;
        bool isNothrow;
    };

    struct FunctionInfo {
        speculo::ID id;
        std::string name;
        std::string fullName;
        std::vector<FunctionArgument> arguments;
        std::vector<Attribute> attributes;

        TypeUsage returnType;

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
        bool isNothrow;
    };

    struct VariableInfo {
        speculo::ID id;
        std::string name;
        std::string fullName;

        TypeUsage type;

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
    };

    struct BaseClassInfo {
        speculo::ID id;
        std::string name;
        std::string fullName;
        bool isVirtual;
        Access access;
        SourceLocationInfo sourceLocation;
        std::size_t byteOffset;
        std::size_t size;
        std::shared_ptr<struct RecordTypeInfo> typeInfo;// may be nullptr when the type can't be parsed for some reason
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
        bool isLiteral;
        bool isPOD;
        bool isStandardLayout;
        bool isTriviallyCopyable;
        bool isTrivial;
        bool isEmpty;
        bool isAggregate;

        bool hasPfMetaGeneratedMacro;
    };

}// namespace speculo::gen
