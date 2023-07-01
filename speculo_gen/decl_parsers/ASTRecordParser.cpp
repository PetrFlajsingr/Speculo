//
// Created by xflajs00 on 19.03.2023.
//

#include "ASTRecordParser.hpp"
#include "../clang_utils.hpp"
#include "../wrap/clang_ast_qualtypenames.hpp"
#include "../wrap/clang_ast_recordlayout.hpp"
#include "../wrap/clang_sema_sema.hpp"
#include <spdlog/spdlog.h>

namespace speculo::gen {

    ASTRecordParser::ASTRecordParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser,
                                     ParsedTypesCache &cache)
        : ASTDeclParser{std::move(idGen), std::move(attribParser), cache} {}

    // TODO: divide this up into separate functions
    std::optional<TypeInfoVariant> ASTRecordParser::parse(clang::ASTContext &astContext, clang::Decl *decl) {
        assert(clang::dyn_cast<clang::CXXRecordDecl>(decl) != nullptr);
        const auto recordDecl = clang::cast<clang::CXXRecordDecl>(decl);

        if (recordDecl->isInvalidDecl()) { return std::nullopt; }

        // TODO: verify how this works
        // not supporting templates for now
        if (recordDecl->isTemplateDecl()) {
            spdlog::warn("Skipping template record {}", recordDecl->getQualifiedNameAsString());
            return std::nullopt;
        }
        if (recordDecl->getTemplateSpecializationKind() != clang::TemplateSpecializationKind::TSK_Undeclared) {
            spdlog::warn("Skipping template specialization record {}", recordDecl->getQualifiedNameAsString());
            return std::nullopt;
        }

        if (recordDecl->isLambda()) {
            spdlog::trace("Skipping lambda record {}", recordDecl->getQualifiedNameAsString());
            return std::nullopt;
        }

        spdlog::trace("ASTRecordParser: parsing {}", getProperQualifiedName(recordDecl, astContext, astContext.getPrintingPolicy()));

        const auto isTemplateSpecialization = recordDecl->getTemplateSpecializationKind() != clang::TSK_Undeclared;
        if (isTemplateSpecialization) {
            spdlog::trace("ASTRecordParser: {} is a template specialization",
                          getProperQualifiedName(recordDecl, astContext, astContext.getPrintingPolicy()));
            if (recordDecl->getTemplateSpecializationKind() != clang::TSK_ExplicitSpecialization) {
                spdlog::trace("ASTRecordParser: skipping a non explicit template specialization");
                return std::nullopt;
            }
        }

        // Skip if found decl is not definition
        const auto definition = recordDecl->getDefinition();
        if (definition != decl) {
            spdlog::trace("ASTRecordParser: skipping, not a definition");
            return std::nullopt;
        }
        if (recordDecl->isAnonymousStructOrUnion()) {
            spdlog::trace("ASTRecordParser: skipping, anonymous struct or union");
            return std::nullopt;
        }

        auto result = std::make_shared<RecordTypeInfo>();

        result->fullName = getProperQualifiedName(recordDecl, astContext, astContext.getPrintingPolicy());
        result->name = getProperName(recordDecl, astContext, astContext.getPrintingPolicy());

        populateIDs(*result, getIdGenerator());

        const auto isNestedType = recordDecl->getAccess() != clang::AccessSpecifier::AS_none;
        if (isNestedType) { result->access = clangAccesConv(recordDecl->getAccess()); }

        result->size = astContext.getASTRecordLayout(recordDecl).getSize().getQuantity();
        result->alignment = astContext.getASTRecordLayout(recordDecl).getAlignment().getQuantity();

        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        auto printingPolicy = clang::PrintingPolicy{langOpts};

        result->originalCode = getSourceText(astContext, *recordDecl);

        // check that there is a semicolon at the end of the macro so we don't miss any functions or ctors
        constexpr std::string_view metaGenMacro = "SPECULO_GENERATED()";
        bool pfMetaGeneratedMacroFound = false;
        if (auto pos = result->originalCode.find(metaGenMacro); pos != std::string::npos) {
            pos += metaGenMacro.size();
            pfMetaGeneratedMacroFound = true;
        }

        result->sourceLocation = getSourceLocationInfo(astContext, *recordDecl);

        result->attributes = getAttributeParser().parseRecordAttributes(astContext, *recordDecl);

        result->isClass = recordDecl->isClass();
        result->isStruct = recordDecl->isStruct();
        result->isUnion = recordDecl->isUnion();
        result->isPolymorphic = recordDecl->isPolymorphic();
        result->isAbstract = recordDecl->isAbstract();
        result->isFinal = recordDecl->isEffectivelyFinal();
        result->isLiteral = recordDecl->isLiteral();
        result->isPOD = recordDecl->isPOD();
        result->isStandardLayout = recordDecl->isStandardLayout();
        result->isTriviallyCopyable = recordDecl->isTriviallyCopyable();
        result->isTrivial = recordDecl->isTrivial();
        result->isEmpty = recordDecl->isEmpty();
        result->isAggregate = recordDecl->isAggregate();

        // TODO: inherited?
        std::size_t previousFieldOffset = 0;
        for (const clang::FieldDecl *field: recordDecl->fields()) {
            VariableInfo variableInfo;
            variableInfo.name = field->getNameAsString();
            variableInfo.fullName = field->getQualifiedNameAsString();
            // FIXME: this is a hack, gotta handle this better
            // ignoring SPECULO_GENERATED expansion mistakenly parsed as an int member
            if (variableInfo.name.starts_with("SPECULO_GENERATED_")) { continue; }
            variableInfo.id = getIdGenerator().generateId(variableInfo.fullName);
            if (const auto typeRecordDecl = field->getType()->getAsCXXRecordDecl(); typeRecordDecl != nullptr) {
                variableInfo.typeName = getProperQualifiedName(typeRecordDecl, astContext, astContext.getPrintingPolicy());
            } else {
                variableInfo.typeName = getProperQualifiedName(field->getType(), astContext);
            }
            variableInfo.typeId = getIdGenerator().generateId(variableInfo.typeName);
            variableInfo.attributes = getAttributeParser().parseFieldAttributes(astContext, *field);
            variableInfo.access = clangAccesConv(field->getAccess());
            variableInfo.isMutable = field->isMutable();
            variableInfo.sourceLocation = getSourceLocationInfo(astContext, *field);
            variableInfo.isBitfield = field->isBitField();
            variableInfo.bitfieldSize = 0;
            if (variableInfo.isBitfield) {
                variableInfo.bitfieldSize = field->getBitWidthValue(astContext);
                variableInfo.bitfieldOffset = astContext.getFieldOffset(field) - previousFieldOffset;
            }
            variableInfo.byteOffset = astContext.getFieldOffset(field) / 8;
            variableInfo.size = astContext.getTypeSizeInChars(field->getType()).getQuantity();

            result->memberVariables.push_back(variableInfo);

            previousFieldOffset = astContext.getFieldOffset(field);
        }
        // TODO: inherited?
        // static variables
        for (const auto innerDecls: recordDecl->decls()) {
            if (auto var = clang::dyn_cast<clang::VarDecl>(innerDecls)) {
                if (var->isStaticDataMember()) {
                    VariableInfo variableInfo;
                    variableInfo.name = var->getNameAsString();
                    variableInfo.fullName = var->getQualifiedNameAsString();
                    variableInfo.id = getIdGenerator().generateId(variableInfo.fullName);
                    if (const auto typeRecordDecl = var->getType()->getAsCXXRecordDecl(); typeRecordDecl != nullptr) {
                        variableInfo.typeName = getProperQualifiedName(typeRecordDecl, astContext, astContext.getPrintingPolicy());
                    } else {
                        variableInfo.typeName = getProperQualifiedName(var->getType(), astContext);
                    }
                    variableInfo.typeId = getIdGenerator().generateId(variableInfo.typeName);
                    variableInfo.attributes = getAttributeParser().parseFieldAttributes(astContext, *var);
                    variableInfo.access = clangAccesConv(var->getAccess());

                    variableInfo.sourceLocation = getSourceLocationInfo(astContext, *var);

                    variableInfo.isConstexpr = var->isConstexpr();
                    variableInfo.isInline = var->isInlineSpecified();
                    variableInfo.isInlineSpecified = var->isInlineSpecified();
                    result->staticVariables.push_back(variableInfo);
                }
            }
        }

        const auto mangleFunction = [](std::string_view fullName,
                                       speculo::RangeOf<std::pair<std::string_view, std::string_view>> auto &&argumentTypesAndNames,
                                       bool isConst) {
            std::string mangledName{fullName};
            for (const auto &[type, name]: argumentTypesAndNames) {
                mangledName.append(fmt::format("_{}_{}_{}", isConst ? "const" : "", type, name));
            }
            return mangledName;
        };

        // TODO: this does not enumerate templated, investigate
        // TODO: inherited (but not overriden) functions?
        for (const clang::CXXMethodDecl *method: recordDecl->methods()) {
            // skipping ctors and dtors here
            if (clang::dyn_cast<clang::CXXConstructorDecl>(method) != nullptr) { continue; }
            if (clang::dyn_cast<clang::CXXDestructorDecl>(method) != nullptr) { continue; }

            // TODO: template specializations should actually be stored
            if (method->getTemplateSpecializationKind() != clang::TemplateSpecializationKind::TSK_Undeclared) {
                spdlog::trace("ASTRecordParser: {} is a template specialization",
                              getProperQualifiedName(recordDecl, astContext, astContext.getPrintingPolicy()));
                // FIXME: don't skip explicit specializations if (method->getTemplateSpecializationKind() != clang::TSK_ExplicitSpecialization) {
                // spdlog::trace("ASTRecordParser: skipping a non explicit template specialization");
                continue;
                //}
            }

            FunctionInfo functionInfo;
            functionInfo.name = getProperName(method, astContext, printingPolicy);
            functionInfo.fullName = getProperQualifiedName(method, astContext, printingPolicy);
            functionInfo.isInline = method->hasInlineBody();
            functionInfo.isInlineSpecified = method->isInlineSpecified();

            if (method->isDeleted() || method->isInvalidDecl()) { continue; }
            if (method->isCopyAssignmentOperator() && method->isImplicit()) {
                // Class has user declared move ctor or assign.
                if (recordDecl->hasUserDeclaredMoveAssignment() || recordDecl->hasUserDeclaredMoveConstructor()) { continue; }
                // Class has non static const member.
                // Class has non static reference member.
                if (std::ranges::any_of(recordDecl->fields(), [](const auto &field) {
                        return field->getType().isConstQualified() || field->getType()->isReferenceType();
                    })) {
                    continue;
                }
                // TODO:
                // Class has non-copyable data member or base class.
            }
            if (method->isMoveAssignmentOperator() && method->isImplicit()) {
                // Class has a data member that is const.
                // Class has a data member that is a reference.
                if (std::ranges::any_of(recordDecl->fields(), [](const auto &field) {
                        return field->getType().isConstQualified() || field->getType()->isReferenceType();
                    })) {
                    continue;
                }
                // TODO:
                // Class has a base class which can't be move assigned.
            }
            auto att = getAttributeParser().parseFunctionAttributes(astContext, *method);
            for (const clang::ParmVarDecl *param: method->parameters()) {
                FunctionArgument argument;
                argument.name = param->getNameAsString();
                argument.fullName = param->getQualifiedNameAsString();
                if (const auto paramTypeRecordDecl = method->getReturnType()->getAsCXXRecordDecl(); paramTypeRecordDecl != nullptr) {
                    argument.typeName = getProperQualifiedName(paramTypeRecordDecl, astContext, astContext.getPrintingPolicy());
                } else {
                    argument.typeName = getProperQualifiedName(param->getType(), astContext);
                }
                argument.typeId = getIdGenerator().generateId(argument.typeName);
                argument.sourceLocation = getSourceLocationInfo(astContext, *param);
                argument.attributes = std::move(att.argumentAttributes[argument.name]);
                functionInfo.arguments.push_back(argument);
            }
            functionInfo.attributes = std::move(att.attributes);
            if (const auto returnTypeRecordDecl = method->getReturnType()->getAsCXXRecordDecl(); returnTypeRecordDecl != nullptr) {
                functionInfo.returnTypeName = getProperQualifiedName(returnTypeRecordDecl, astContext, astContext.getPrintingPolicy());
            } else {
                functionInfo.returnTypeName = getProperQualifiedName(method->getReturnType(), astContext);
            }
            functionInfo.returnTypeId = getIdGenerator().generateId(functionInfo.returnTypeName);
            functionInfo.access = clangAccesConv(method->getAccess());
            functionInfo.isConstexpr = method->isConstexpr();
            functionInfo.isConsteval = method->isConsteval();
            functionInfo.isConst = method->isConst();
            functionInfo.isVirtual = method->isVirtual();
            functionInfo.isPureVirtual = method->isPure();
            functionInfo.isNothrow = method->hasAttr<clang::NoThrowAttr>();
            functionInfo.sourceLocation = getSourceLocationInfo(astContext, *method)

            const auto mangledName = mangleFunction(functionInfo.fullName,
                                                    functionInfo.arguments | std::views::transform([](const FunctionArgument &arg) {
                                                        return std::pair(std::string_view{arg.fullName}, std::string_view{arg.typeName});
                                                    }),
                                                    functionInfo.isConst);
            // mangling names for argument IDs
            for (auto &argument: functionInfo.arguments) {
                argument.id = getIdGenerator().generateId(fmt::format("{}_{}_{}", mangledName, argument.fullName, argument.typeName));
            }

            functionInfo.id = getIdGenerator().generateId(mangledName);

            if (method->isStatic()) {
                result->staticFunctions.push_back(functionInfo);
            } else {
                functionInfo.isFinal = method->hasAttr<clang::FinalAttr>();
                result->memberFunctions.push_back(functionInfo);
            }
        }
        // FIXME: can't really get ptrs to generated operators

        for (const clang::CXXConstructorDecl *ctor: recordDecl->ctors()) {
            if (ctor->isDeleted()) { continue; }

            // TODO: template specializations should actually be stored
            if (ctor->getTemplateSpecializationKind() != clang::TemplateSpecializationKind::TSK_Undeclared) {
                spdlog::trace("ASTRecordParser: {} is a template specialization",
                              getProperQualifiedName(ctor, astContext, astContext.getPrintingPolicy()));
                // FIXME: don't skip explicit specializations if (method->getTemplateSpecializationKind() != clang::TSK_ExplicitSpecialization) {
                // spdlog::trace("ASTRecordParser: skipping a non explicit template specialization");
                continue;
                //}
            }

            if (ShouldSkipConstructor(recordDecl, ctor)) { continue; }

            ConstructorInfo constructorInfo;
            constructorInfo.fullName = ctor->getQualifiedNameAsString();
            constructorInfo.id = getIdGenerator().generateId(constructorInfo.fullName);

            auto att = getAttributeParser().parseConstructorAttributes(astContext, *ctor);
            for (const clang::ParmVarDecl *param: ctor->parameters()) {
                FunctionArgument argument;
                argument.name = param->getNameAsString();
                argument.fullName = param->getQualifiedNameAsString();

                if (const auto paramTypeRecordDecl = param->getType()->getAsCXXRecordDecl(); paramTypeRecordDecl != nullptr) {
                    argument.typeName = getProperQualifiedName(paramTypeRecordDecl, astContext, astContext.getPrintingPolicy());
                } else {
                    argument.typeName = getProperQualifiedName(param->getType(), astContext);
                }
                argument.typeId = getIdGenerator().generateId(argument.typeName);
                argument.sourceLocation = getSourceLocationInfo(astContext, *param);
                argument.attributes = std::move(att.argumentAttributes[argument.name]);
                constructorInfo.arguments.push_back(argument);
            }
            constructorInfo.isConstexpr = ctor->isConstexpr() && result->isLiteral;
            constructorInfo.isConsteval = ctor->isConsteval() && result->isLiteral;
            constructorInfo.isExplicit = ctor->isExplicit();
            constructorInfo.access = clangAccesConv(ctor->getAccess());
            constructorInfo.sourceLocation = getSourceLocationInfo(astContext, *ctor);
            constructorInfo.isCopy = ctor->isCopyConstructor();
            constructorInfo.isMove = ctor->isMoveConstructor();
            constructorInfo.attributes = std::move(att.attributes);
            constructorInfo.isInline = ctor->hasInlineBody();
            constructorInfo.isInlineSpecified = ctor->isInlineSpecified();
            constructorInfo.isNothrow = ctor->hasAttr<clang::NoThrowAttr>();

            const auto mangledName = mangleFunction(constructorInfo.fullName,
                                                    constructorInfo.arguments | std::views::transform([](const FunctionArgument &arg) {
                                                        return std::pair(std::string_view{arg.fullName}, std::string_view{arg.typeName});
                                                    }),
                                                    false);
            // mangling names for argument IDs
            for (auto &argument: constructorInfo.arguments) {
                argument.id = getIdGenerator().generateId(fmt::format("{}_{}_{}", mangledName, argument.fullName, argument.typeName));
            }
            constructorInfo.id = getIdGenerator().generateId(mangledName);

            result->constructors.push_back(constructorInfo);
        }
        if (const clang::CXXDestructorDecl *destructor = recordDecl->getDestructor(); destructor != nullptr) {
            result->destructor.fullName = destructor->getQualifiedNameAsString();
            result->destructor.id = getIdGenerator().generateId(result->destructor.fullName);
            result->destructor.access = clangAccesConv(destructor->getAccess());
            result->destructor.sourceLocation = getSourceLocationInfo(astContext, *destructor);
            result->destructor.attributes = std::move(getAttributeParser().parseDestructorAttributes(astContext, *destructor).attributes);
            result->destructor.isConstexpr = destructor->isConstexpr();
            result->destructor.isConsteval = destructor->isConsteval();
            result->destructor.isVirtual = destructor->isVirtual();
            result->destructor.isPureVirtual = destructor->isPure();
            const auto methodDecl = clang::dyn_cast<clang::CXXMethodDecl>(destructor);
            result->destructor.isFinal = methodDecl->hasAttr<clang::FinalAttr>();
            result->destructor.isInline = destructor->hasInlineBody();
            result->destructor.isInlineSpecified = destructor->isInlineSpecified();
            result->destructor.isNothrow = destructor->hasAttr<clang::NoThrowAttr>();
        } else if (recordDecl->hasSimpleDestructor()) {
            result->destructor.fullName = fmt::format("{}::~{}", result->fullName, result->name);
            result->destructor.id = getIdGenerator().generateId(result->destructor.fullName);
            result->destructor.access = Access::Public;
            result->destructor.sourceLocation.emplace(0, 0,  "<generated>");
            result->destructor.attributes = {};
            result->destructor.isConstexpr = recordDecl->hasConstexprDestructor();
            result->destructor.isConsteval = false;
            result->destructor.isVirtual = false;
            result->destructor.isPureVirtual = false;
            result->destructor.isFinal = false;
            result->destructor.isInline = false;
            result->destructor.isNothrow = true;
        }

        const auto mangleBaseClass = [](std::string_view derivedFullName, std::string baseFullName) {
            return fmt::format("{}__{}", derivedFullName, baseFullName);
        };

        for (const clang::CXXBaseSpecifier &base: recordDecl->bases()) {
            BaseClassInfo baseClassInfo{};
            const auto baseRecordDecl = base.getType()->getAsCXXRecordDecl();
            if (baseRecordDecl == nullptr) {
                spdlog::error("Base class not recognized as a record");
                continue;
            }
            baseClassInfo.fullName = getProperQualifiedName(baseRecordDecl, astContext, astContext.getPrintingPolicy());
            baseClassInfo.name = getProperName(baseRecordDecl, astContext, astContext.getPrintingPolicy());
            const auto mangledName = mangleBaseClass(result->fullName, baseClassInfo.fullName);
            baseClassInfo.id = getIdGenerator().generateId(mangledName);
            baseClassInfo.isVirtual = base.isVirtual();
            baseClassInfo.access = clangAccesConv(base.getAccessSpecifier());
            baseClassInfo.sourceLocation = getSourceLocationInfo(astContext, base);
            const auto &layout = astContext.getASTRecordLayout(recordDecl);
            baseClassInfo.byteOffset =
                    (baseClassInfo.isVirtual ? layout.getVBaseClassOffset(baseRecordDecl) : layout.getBaseClassOffset(baseRecordDecl))
                            .getQuantity();
            baseClassInfo.size = astContext.getASTRecordLayout(baseRecordDecl).getSize().getQuantity();

            if (auto cachedBaseInfo = getTypesCache().getRecord(baseClassInfo.fullName); cachedBaseInfo != nullptr) {
                baseClassInfo.typeInfo = cachedBaseInfo;
            } else {
                auto baseTypeInfo = parse(astContext, baseRecordDecl);
                if (!baseTypeInfo.has_value()) {
                    spdlog::warn("Error during base class parsing '{}'", baseClassInfo.fullName);
                } else {
                    auto baseInfo = std::move(std::get<std::shared_ptr<RecordTypeInfo>>(*baseTypeInfo));
                    getTypesCache().addRecord(baseInfo);
                    baseClassInfo.typeInfo = std::move(baseInfo);
                }
            }

            result->baseClasses.emplace_back(std::move(baseClassInfo));
        }

        if (!pfMetaGeneratedMacroFound) {
            if (std::ranges::any_of(result->constructors, [](const auto &ctor) { return ctor.access != Access::Public; }) ||
                std::ranges::any_of(result->staticFunctions, [](const auto &ctor) { return ctor.access != Access::Public; }) ||
                std::ranges::any_of(result->memberFunctions, [](const auto &ctor) { return ctor.access != Access::Public; }) ||
                std::ranges::any_of(result->staticVariables, [](const auto &ctor) { return ctor.access != Access::Public; }) ||
                std::ranges::any_of(result->memberVariables, [](const auto &ctor) { return ctor.access != Access::Public; }) ||
                result->destructor.access != Access::Public) {
                spdlog::warn("Class {} does not contain 'SPECULO_GENERATED()', but it contains private or protected constructors, "
                             "destructor, variables or functions - the macro is required to access these",
                             result->fullName);
                spdlog::warn("Reflection data for {} will only allow access to public members", result->fullName);
            }
        }
        result->hasPfMetaGeneratedMacro = pfMetaGeneratedMacroFound;
        return result;
    }

    bool ASTRecordParser::ShouldSkipConstructor(const clang::CXXRecordDecl *recordDecl, const clang::CXXConstructorDecl *ctor) {
        const auto isCopyOrMoveImplicitConstructor = (ctor->isCopyConstructor() || ctor->isMoveConstructor()) && ctor->isImplicit();
        if (!isCopyOrMoveImplicitConstructor) { return false; }

        if (ctor->isCopyConstructor()) {
            // Class has user declared move ctor or assign.
            if (recordDecl->hasUserDeclaredMoveAssignment() || recordDecl->hasUserDeclaredMoveConstructor()) { return true; }
            // TODO:
            // Class has non-copyable data member or base class. Base class with inaccessible destructor
        }
        if (ctor->isMoveConstructor()) {
            // TODO:
            // Class has a base class which can't be move assigned.
        }
        // Class has non-static const member.
        // Class has non-static reference member.
        if (std::ranges::any_of(recordDecl->fields(), [](const auto &field) {
                return field->getType().isConstQualified() || field->getType()->isReferenceType();
            })) {
            return true;
        }
        return false;
    }

}// namespace speculo::gen