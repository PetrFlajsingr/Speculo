module;

#include <array>
#include <cassert>
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>
#include <fmt/format.h>

export module speculo.gen:structs;
import speculo;

export namespace speculo::gen {
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

    using TypeInfoVariant = std::variant<struct EnumTypeInfo, struct RecordTypeInfo, struct IncompleteTypeInfo, struct FundamentalTypeInfo>;

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
        ID id;
        ID constId;
        ID lrefId;
        ID rrefId;
        ID constLrefId;
        ID ptrId;
        ID constPtrId;
        ID volatileId;
        ID volatileConstId;
        ID volatileLrefId;
        ID volatileRrefId;
        ID volatileConstLrefId;
        ID volatilePtrId;
        ID volatileConstPtrId;

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
        std::shared_ptr<TypeInfoVariant> type;
        TypeForm form;
        // TODO: verify this is set properly everywhere
        std::string fullName;

        /// Get ID of the used type. May return nullopt when the type is not of supported form.
        [[nodiscard]] std::optional<ID> getID() const;
    };

    struct EnumTypeInfo : TypeInfo {
        struct ValueInfo {
            ID id;
            std::string fullName;
            std::variant<bool, std::uint64_t, std::int64_t> value;
            std::vector<Attribute> attributes;
            SourceLocationInfo sourceLocation;
        };

        std::vector<Attribute> attributes;
        std::unordered_map<std::string, ValueInfo> values;
        bool isScoped;
        std::shared_ptr<TypeInfoVariant> underlyingType;// basically guaranteed to be FundamentalTypeInfo, but check to be safe
    };

    struct FunctionArgument {
        ID id;
        std::string name;
        std::string fullName;

        std::vector<Attribute> attributes;
        SourceLocationInfo sourceLocation;

        TypeUsage type;
    };

    struct ConstructorInfo {
        ID id;
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
        ID id;
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
        ID id;
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
        ID id;
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
        ID id;
        std::string name;
        std::string fullName;
        bool isVirtual;
        Access access;
        SourceLocationInfo sourceLocation;
        std::size_t byteOffset;
        std::size_t size;
        std::shared_ptr<TypeInfoVariant>
                typeInfo;// may be nullptr when the type can't be parsed for some reason, basically guaranteed to be RecordTypeInfo if not nullptr, better check tho
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

        bool hasSpeculoGeneratedMacro;
    };


    inline std::optional<ID> TypeUsage::getID() const {
        switch (form) {
            case TypeForm::Normal:
                return std::visit([](const auto &t) { return t.id; }, *type);
            case TypeForm::Const:
                return std::visit([](const auto &t) { return t.constId; }, *type);
            case TypeForm::LRef:
                return std::visit([](const auto &t) { return t.lrefId; }, *type);
            case TypeForm::ConstLRef:
                return std::visit([](const auto &t) { return t.constLrefId; }, *type);
            case TypeForm::RRef:
                return std::visit([](const auto &t) { return t.rrefId; }, *type);
            case TypeForm::Ptr:
                return std::visit([](const auto &t) { return t.ptrId; }, *type);
            case TypeForm::ConstPtr:
                return std::visit([](const auto &t) { return t.constPtrId; }, *type);
            case TypeForm::Other:
                return std::nullopt;
            default:
                assert(false && "Invalid value");
                return std::nullopt;
        }
        return std::nullopt;
    }

    [[nodiscard]] inline std::string idToString(speculo::ID id) {
        return fmt::format("ID{{0x{:x}u, 0x{:x}u}}", id.id[0], id.id[1]);
    }
}// namespace speculo::gen
