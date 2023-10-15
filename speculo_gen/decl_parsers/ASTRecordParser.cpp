//
// Created by xflajs00 on 19.03.2023.
//

#include "ASTRecordParser.hpp"
#include "../clang_utils.hpp"
#include "../wrap/clang_ast_qualtypenames.hpp"
#include "../wrap/clang_ast_recordlayout.hpp"
#include "../wrap/clang_sema_sema.hpp"
#include "ASTEnumParser.hpp"
#include "details/FundamentalTypeInfos.hpp"
#include "details/IncompleteTypeInfos.hpp"
#include <spdlog/spdlog.h>
#include <ranges>

namespace speculo::gen {

    ASTRecordParser::ASTRecordParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser,
                                     std::shared_ptr<ParsedTypesCache> cache)
        : ASTDeclParser{std::move(idGen), std::move(attribParser), std::move(cache)}, enumParser{idGenerator, attributeParser, typesCache} {
    }

    // TODO: divide this up into separate functions
    std::optional<TypeInfoVariant> ASTRecordParser::parse(clang::ASTContext &astContext, clang::Decl *decl) {
        assert(clang::dyn_cast<clang::CXXRecordDecl>(decl) != nullptr);
        const auto recordDecl = clang::cast<clang::CXXRecordDecl>(decl)->getCanonicalDecl();

        if (ShouldSkipRecordDecl(recordDecl)) { return std::nullopt; }

        spdlog::trace("ASTRecordParser: parsing {}", getProperQualifiedName(recordDecl, astContext));

        const auto isTemplateSpecialization = recordDecl->getTemplateSpecializationKind() != clang::TSK_Undeclared;
        if (isTemplateSpecialization) {
            spdlog::trace("ASTRecordParser: {} is a template specialization", getProperQualifiedName(recordDecl, astContext));
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

        RecordTypeInfo result{};

        collectBasicRecordInfo(result, astContext, definition);

        collectMemberVariablesInfo(result, astContext, definition);

        collectStaticVariablesInfo(result, astContext, definition);

        collectMethodsInfo(result, astContext, definition);

        collectConstructorsInfo(result, astContext, definition);

        collectDestructorInfo(result, astContext, definition);

        collectBaseInfos(result, astContext, definition);

        CheckForGeneratedMacro(result);
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

    bool ASTRecordParser::ShouldSkipRecordDecl(const clang::CXXRecordDecl *recordDecl) {
        if (recordDecl->isInvalidDecl()) { return true; }

        // TODO: verify how this works
        // not supporting templates for now
        if (recordDecl->isTemplateDecl()) {
            spdlog::debug("Skipping template record {}", recordDecl->getQualifiedNameAsString());
            return true;
        }
        if (recordDecl->getTemplateSpecializationKind() != clang::TemplateSpecializationKind::TSK_Undeclared) {
            spdlog::debug("Skipping template specialization record {}", recordDecl->getQualifiedNameAsString());
            return true;
        }

        if (recordDecl->isLambda()) {
            spdlog::trace("Skipping lambda record {}", recordDecl->getQualifiedNameAsString());
            return true;
        }

        if (recordDecl->isAnonymousStructOrUnion()) {
            spdlog::trace("ASTRecordParser: skipping, anonymous struct or union");
            return true;
        }
        return false;
    }

    bool ASTRecordParser::ShouldSkipMethod(const clang::CXXMethodDecl *methodDecl, const clang::CXXRecordDecl *recordDecl) {
        if (methodDecl->isDeleted() || methodDecl->isInvalidDecl()) { return true; }
        if (methodDecl->isCopyAssignmentOperator() && methodDecl->isImplicit()) {
            // Class has user declared move ctor or assign.
            if (recordDecl->hasUserDeclaredMoveAssignment() || recordDecl->hasUserDeclaredMoveConstructor()) { return true; }
            // Class has non-static const member.
            // Class has non-static reference member.
            if (std::ranges::any_of(recordDecl->fields(), [](const auto &field) {
                    return field->getType().isConstQualified() || field->getType()->isReferenceType();
                })) {
                return true;
            }
            // TODO:
            // Class has non-copyable data member or base class.
        }
        if (methodDecl->isMoveAssignmentOperator() && methodDecl->isImplicit()) {
            // Class has a data member that is const.
            // Class has a data member that is a reference.
            if (std::ranges::any_of(recordDecl->fields(), [](const auto &field) {
                    return field->getType().isConstQualified() || field->getType()->isReferenceType();
                })) {
                return true;
            }
            // TODO:
            // Class has a base class which can't be move assigned.
        }
        return false;
    }

    void ASTRecordParser::collectBasicRecordInfo(RecordTypeInfo &info, clang::ASTContext &astContext,
                                                 const clang::CXXRecordDecl *recordDecl) {
        info.fullName = getProperQualifiedName(recordDecl, astContext);
        info.name = getProperName(recordDecl, astContext);

        populateIDs(info, *idGenerator);

        const auto isNestedType = recordDecl->getAccess() != clang::AccessSpecifier::AS_none;
        if (isNestedType) { info.access = clangAccesConv(recordDecl->getAccess()); }

        info.size = astContext.getASTRecordLayout(recordDecl).getSize().getQuantity();
        info.alignment = astContext.getASTRecordLayout(recordDecl).getAlignment().getQuantity();

        info.originalCode = getSourceText(astContext, *recordDecl);

        info.sourceLocation = getSourceLocationInfo(astContext, *recordDecl);

        info.attributes = attributeParser->parseRecordAttributes(astContext, *recordDecl);

        info.isClass = recordDecl->isClass();
        info.isStruct = recordDecl->isStruct();
        info.isUnion = recordDecl->isUnion();
        info.isPolymorphic = recordDecl->isPolymorphic();
        info.isAbstract = recordDecl->isAbstract();
        info.isFinal = recordDecl->isEffectivelyFinal();
        info.isLiteral = recordDecl->isLiteral();
        info.isPOD = recordDecl->isPOD();
        info.isStandardLayout = recordDecl->isStandardLayout();
        info.isTriviallyCopyable = recordDecl->isTriviallyCopyable();
        info.isTrivial = recordDecl->isTrivial();
        info.isEmpty = recordDecl->isEmpty();
        info.isAggregate = recordDecl->isAggregate();
    }

    void ASTRecordParser::collectBaseInfos(RecordTypeInfo &info, clang::ASTContext &astContext, const clang::CXXRecordDecl *recordDecl) {
        for (const clang::CXXBaseSpecifier &base: recordDecl->bases()) {
            BaseClassInfo baseClassInfo{};
            const auto baseRecordDecl = base.getType()->getAsCXXRecordDecl();
            if (baseRecordDecl == nullptr) {
                spdlog::error("Base class not recognized as a record");
                continue;
            }
            baseClassInfo.fullName = getProperQualifiedName(baseRecordDecl, astContext);
            baseClassInfo.name = getProperName(baseRecordDecl, astContext);
            const auto mangledName = MangleBaseClass(info.fullName, baseClassInfo.fullName);
            baseClassInfo.id = idGenerator->generateId(mangledName);
            baseClassInfo.isVirtual = base.isVirtual();
            baseClassInfo.access = clangAccesConv(base.getAccessSpecifier());
            baseClassInfo.sourceLocation = getSourceLocationInfo(astContext, base);
            const auto &layout = astContext.getASTRecordLayout(recordDecl);
            baseClassInfo.byteOffset =
                    (baseClassInfo.isVirtual ? layout.getVBaseClassOffset(baseRecordDecl) : layout.getBaseClassOffset(baseRecordDecl))
                            .getQuantity();
            baseClassInfo.size = astContext.getASTRecordLayout(baseRecordDecl).getSize().getQuantity();


            if (auto fullTypeName = getFullTypeName(astContext, baseRecordDecl); fullTypeName.has_value()) {
                baseClassInfo.typeInfo = typesCache->getOrAdd(*fullTypeName, [&](TypeInfoVariant &result) {
                    if (auto parseResult = parse(astContext, baseRecordDecl); parseResult.has_value()) {
                        result = std::move(*parseResult);
                    } else {
                        spdlog::debug("Unexpected code path triggered in ASTRecordParser {0:x}", 0x8CB9274E);
                        result = getIncompleteTypeInfo(*fullTypeName, *idGenerator);
                    }
                });
            }

            info.baseClasses.emplace_back(std::move(baseClassInfo));
        }
    }

    void ASTRecordParser::collectDestructorInfo(RecordTypeInfo &info, clang::ASTContext &astContext,
                                                const clang::CXXRecordDecl *recordDecl) {

        if (const clang::CXXDestructorDecl *destructor = recordDecl->getDestructor(); destructor != nullptr) {
            info.destructor.fullName = destructor->getQualifiedNameAsString();
            info.destructor.id = idGenerator->generateId(info.destructor.fullName);
            info.destructor.access = clangAccesConv(destructor->getAccess());
            info.destructor.sourceLocation = getSourceLocationInfo(astContext, *destructor);
            info.destructor.attributes = std::move(attributeParser->parseDestructorAttributes(astContext, *destructor).attributes);
            info.destructor.isConstexpr = destructor->isConstexpr();
            info.destructor.isConsteval = destructor->isConsteval();
            info.destructor.isVirtual = destructor->isVirtual();
            info.destructor.isPureVirtual = destructor->isPure();
            const auto methodDecl = clang::dyn_cast<clang::CXXMethodDecl>(destructor);
            info.destructor.isFinal = methodDecl->hasAttr<clang::FinalAttr>();
            info.destructor.isInline = destructor->hasInlineBody();
            info.destructor.isInlineSpecified = destructor->isInlineSpecified();
            info.destructor.isNothrow = destructor->hasAttr<clang::NoThrowAttr>();
        } else if (recordDecl->hasSimpleDestructor()) {
            info.destructor.fullName = fmt::format("{}::~{}", info.fullName, info.name);
            info.destructor.id = idGenerator->generateId(info.destructor.fullName);
            info.destructor.access = Access::Public;
            info.destructor.sourceLocation.emplace(0, 0, "<generated>");
            info.destructor.attributes = {};
            info.destructor.isConstexpr = recordDecl->hasConstexprDestructor();
            info.destructor.isConsteval = false;
            info.destructor.isVirtual = false;
            info.destructor.isPureVirtual = false;
            info.destructor.isFinal = false;
            info.destructor.isInline = false;
            info.destructor.isNothrow = true;
        }
    }

    void ASTRecordParser::collectConstructorsInfo(RecordTypeInfo &info, clang::ASTContext &astContext,
                                                  const clang::CXXRecordDecl *recordDecl) {
        for (const clang::CXXConstructorDecl *ctor: recordDecl->ctors()) {
            if (ctor->isDeleted()) { continue; }

            // TODO: template specializations should actually be stored
            if (ctor->getTemplateSpecializationKind() != clang::TemplateSpecializationKind::TSK_Undeclared) {
                spdlog::trace("ASTRecordParser: {} is a template specialization", getProperQualifiedName(ctor, astContext));
                // FIXME: don't skip explicit specializations if (method->getTemplateSpecializationKind() != clang::TSK_ExplicitSpecialization) {
                // spdlog::trace("ASTRecordParser: skipping a non explicit template specialization");
                continue;
                //}
            }

            if (ShouldSkipConstructor(recordDecl, ctor)) { continue; }

            ConstructorInfo constructorInfo;
            constructorInfo.fullName = ctor->getQualifiedNameAsString();

            auto att = attributeParser->parseConstructorAttributes(astContext, *ctor);
            for (const clang::ParmVarDecl *param: ctor->parameters()) {
                FunctionArgument argument;
                argument.name = param->getNameAsString();
                argument.fullName = param->getQualifiedNameAsString();
                argument.type = CreateTypeUsage(param->getType(), astContext, *typesCache, *idGenerator, enumParser, *this);
                argument.sourceLocation = getSourceLocationInfo(astContext, *param);
                argument.attributes = std::move(att.argumentAttributes[argument.name]);
                constructorInfo.arguments.push_back(argument);
            }
            constructorInfo.isConstexpr = ctor->isConstexpr() && info.isLiteral;
            constructorInfo.isConsteval = ctor->isConsteval() && info.isLiteral;
            constructorInfo.isExplicit = ctor->isExplicit();
            constructorInfo.access = clangAccesConv(ctor->getAccess());
            constructorInfo.sourceLocation = getSourceLocationInfo(astContext, *ctor);
            constructorInfo.isCopy = ctor->isCopyConstructor();
            constructorInfo.isMove = ctor->isMoveConstructor();
            constructorInfo.attributes = std::move(att.attributes);
            constructorInfo.isInline = ctor->hasInlineBody();
            constructorInfo.isInlineSpecified = ctor->isInlineSpecified();
            constructorInfo.isNothrow = ctor->hasAttr<clang::NoThrowAttr>();

            const auto mangledName = MangleFunction(
                    constructorInfo.fullName, constructorInfo.arguments | std::views::transform([](const FunctionArgument &arg) {
                                                  return std::pair(std::string_view{arg.fullName}, std::string_view{arg.type.fullName});
                                              }),
                    false);
            // mangling names for argument IDs
            for (auto &argument: constructorInfo.arguments) {
                argument.id = idGenerator->generateId(fmt::format("{}_{}_{}", mangledName, argument.fullName, argument.type.fullName));
            }
            constructorInfo.id = idGenerator->generateId(mangledName);

            info.constructors.push_back(constructorInfo);
        }
    }

    void ASTRecordParser::collectMethodsInfo(RecordTypeInfo &info, clang::ASTContext &astContext, const clang::CXXRecordDecl *recordDecl) {
        // TODO: this does not enumerate templated, investigate
        // TODO: inherited (but not overriden) functions?
        for (const clang::CXXMethodDecl *method: recordDecl->methods()) {
            // skipping ctors and dtors here
            if (clang::dyn_cast<clang::CXXConstructorDecl>(method) != nullptr) { continue; }
            if (clang::dyn_cast<clang::CXXDestructorDecl>(method) != nullptr) { continue; }

            // TODO: template specializations should actually be stored
            if (method->getTemplateSpecializationKind() != clang::TemplateSpecializationKind::TSK_Undeclared) {
                spdlog::trace("ASTRecordParser: {} is a template specialization", getProperQualifiedName(recordDecl, astContext));
                // FIXME: don't skip explicit specializations if (method->getTemplateSpecializationKind() != clang::TSK_ExplicitSpecialization) {
                // spdlog::trace("ASTRecordParser: skipping a non explicit template specialization");
                continue;
                //}
            }

            FunctionInfo functionInfo;
            functionInfo.name = getProperName(method, astContext);
            functionInfo.fullName = getProperQualifiedName(method, astContext);
            functionInfo.isInline = method->hasInlineBody();
            functionInfo.isInlineSpecified = method->isInlineSpecified();

            if (ShouldSkipMethod(method, recordDecl)) { continue; }

            auto att = attributeParser->parseFunctionAttributes(astContext, *method);
            for (const clang::ParmVarDecl *param: method->parameters()) {
                FunctionArgument argument;
                argument.name = param->getNameAsString();
                argument.fullName = param->getQualifiedNameAsString();
                argument.type = CreateTypeUsage(param->getType(), astContext, *typesCache, *idGenerator, enumParser, *this);
                argument.sourceLocation = getSourceLocationInfo(astContext, *param);
                argument.attributes = std::move(att.argumentAttributes[argument.name]);
                functionInfo.arguments.push_back(argument);
            }
            functionInfo.attributes = std::move(att.attributes);
            functionInfo.returnType = CreateTypeUsage(method->getReturnType(), astContext, *typesCache, *idGenerator, enumParser, *this);
            functionInfo.access = clangAccesConv(method->getAccess());
            functionInfo.isConstexpr = method->isConstexpr();
            functionInfo.isConsteval = method->isConsteval();
            functionInfo.isConst = method->isConst();
            functionInfo.isVirtual = method->isVirtual();
            functionInfo.isPureVirtual = method->isPure();
            functionInfo.isNothrow = method->hasAttr<clang::NoThrowAttr>();
            functionInfo.sourceLocation = getSourceLocationInfo(astContext, *method);

            const auto mangledName = MangleFunction(
                    functionInfo.fullName, functionInfo.arguments | std::views::transform([](const FunctionArgument &arg) {
                                               return std::pair(std::string_view{arg.fullName}, std::string_view{arg.type.fullName});
                                           }),
                    functionInfo.isConst);
            // mangling names for argument IDs
            for (auto &argument: functionInfo.arguments) {
                argument.id = idGenerator->generateId(fmt::format("{}_{}_{}", mangledName, argument.fullName, argument.type.fullName));
            }

            functionInfo.id = idGenerator->generateId(mangledName);

            if (method->isStatic()) {
                info.staticFunctions.push_back(functionInfo);
            } else {
                functionInfo.isFinal = method->hasAttr<clang::FinalAttr>();
                info.memberFunctions.push_back(functionInfo);
            }
        }
        // FIXME: can't really get ptrs to generated operators
    }

    void ASTRecordParser::collectStaticVariablesInfo(RecordTypeInfo &info, clang::ASTContext &astContext,
                                                     const clang::CXXRecordDecl *recordDecl) {
        // TODO: inherited?
        for (const auto innerDecls: recordDecl->decls()) {
            if (auto var = clang::dyn_cast<clang::VarDecl>(innerDecls)) {
                if (var->isStaticDataMember()) {
                    VariableInfo variableInfo;
                    variableInfo.name = var->getNameAsString();
                    variableInfo.fullName = var->getQualifiedNameAsString();
                    variableInfo.id = idGenerator->generateId(variableInfo.fullName);
                    variableInfo.type = CreateTypeUsage(var->getType(), astContext, *typesCache, *idGenerator, enumParser, *this);
                    variableInfo.attributes = attributeParser->parseFieldAttributes(astContext, *var);
                    variableInfo.access = clangAccesConv(var->getAccess());
                    variableInfo.sourceLocation = getSourceLocationInfo(astContext, *var);
                    variableInfo.isConstexpr = var->isConstexpr();
                    variableInfo.isInline = var->isInlineSpecified();
                    variableInfo.isInlineSpecified = var->isInlineSpecified();
                    info.staticVariables.push_back(variableInfo);
                }
            }
        }
    }

    void ASTRecordParser::collectMemberVariablesInfo(RecordTypeInfo &info, clang::ASTContext &astContext,
                                                     const clang::CXXRecordDecl *recordDecl) {
        // TODO: inherited?
        std::size_t previousFieldOffset = 0;
        for (const clang::FieldDecl *field: recordDecl->fields()) {
            VariableInfo variableInfo;
            variableInfo.name = field->getNameAsString();
            variableInfo.fullName = field->getQualifiedNameAsString();
            // FIXME: this is a hack, gotta handle this better
            // ignoring SPECULO_GENERATED expansion mistakenly parsed as an int member
            if (variableInfo.name.starts_with("SPECULO_GENERATED_")) { continue; }
            variableInfo.id = idGenerator->generateId(variableInfo.fullName);
            variableInfo.type = CreateTypeUsage(field->getType(), astContext, *typesCache, *idGenerator, enumParser, *this);
            variableInfo.attributes = attributeParser->parseFieldAttributes(astContext, *field);
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

            info.memberVariables.emplace_back(std::move(variableInfo));

            previousFieldOffset = astContext.getFieldOffset(field);
        }
    }

    void ASTRecordParser::CheckForGeneratedMacro(RecordTypeInfo &info) {
        const auto codeWithoutCommentsAndStrings = removeCommentsAndStrings(info.originalCode, true);
        const auto speculoGeneratedMacroFound = codeWithoutCommentsAndStrings.find(metaGenMacro) != std::string::npos;

        if (!speculoGeneratedMacroFound) {
            const auto isNotPublic = [](const auto &v) { return v.access != Access::Public; };
            if (std::ranges::any_of(info.constructors, isNotPublic) || std::ranges::any_of(info.staticFunctions, isNotPublic) ||
                std::ranges::any_of(info.memberFunctions, isNotPublic) || std::ranges::any_of(info.staticVariables, isNotPublic) ||
                std::ranges::any_of(info.memberVariables, isNotPublic) || isNotPublic(info.destructor)) {
                spdlog::warn("Class {} does not contain 'SPECULO_GENERATED()', but it contains private or protected constructors, "
                             "destructor, variables or functions - the macro is required to access these",
                             info.fullName);
                spdlog::warn("Reflection data for {} will only allow access to public members", info.fullName);
            }
        }
        info.hasSpeculoGeneratedMacro = speculoGeneratedMacroFound;
    }

    std::shared_ptr<TypeInfoVariant> ASTRecordParser::CreateFundamentalTypeInfo(const clang::QualType &type, const std::string &typeName,
                                                                                IdGenerator &idGenerator, ParsedTypesCache &typesCache,
                                                                                clang::ASTContext &astContext) {
        return typesCache.getOrAdd(typeName, [&](TypeInfoVariant &result) { result = getFundamentalTypeInfo(typeName, idGenerator); });
    }

    std::shared_ptr<TypeInfoVariant> ASTRecordParser::CreateIncompleteTypeInfo(const clang::QualType &type, const std::string &typeName,
                                                                               IdGenerator &idGenerator, ParsedTypesCache &typesCache,
                                                                               clang::ASTContext &astContext) {
        return typesCache.getOrAdd(typeName, [&](TypeInfoVariant &result) {
            result = getIncompleteTypeInfo(getProperQualifiedName(type, astContext), idGenerator);
        });
    }

    std::shared_ptr<TypeInfoVariant> ASTRecordParser::CreateEnumTypeInfo(const clang::QualType &type, const std::string &typeName,
                                                                         IdGenerator &idGenerator, ParsedTypesCache &typesCache,
                                                                         clang::ASTContext &astContext, ASTEnumParser &enumParser) {
        return typesCache.getOrAdd(typeName, [&](TypeInfoVariant &result) {
            if (const auto enumType = llvm::dyn_cast<clang::EnumType>(type)) {
                const auto enumDecl = enumType->getDecl();
                if (auto parseResult = enumParser.parse(astContext, enumDecl); parseResult.has_value()) {
                    result = std::move(*parseResult);
                } else {
                    // this shouldn't happen
                    spdlog::debug("Unexpected code path triggered in ASTRecordParser {0:x}", 0xDA6A94AC);
                    result = getIncompleteTypeInfo(getProperQualifiedName(type, astContext), idGenerator);
                }
            } else {
                // this shouldn't happen
                spdlog::debug("Unexpected code path triggered in ASTRecordParser {0:x}", 0x979B1762);
                result = getIncompleteTypeInfo(getProperQualifiedName(type, astContext), idGenerator);
            }
        });
    }

    std::shared_ptr<TypeInfoVariant> ASTRecordParser::CreateRecordTypeInfo(const clang::QualType &type, const std::string &typeName,
                                                                           IdGenerator &idGenerator, ParsedTypesCache &typesCache,
                                                                           clang::ASTContext &astContext, ASTRecordParser &recordParser) {
        return typesCache.getOrAdd(typeName, [&](TypeInfoVariant &result) {
            if (const auto recDecl = type->getAsCXXRecordDecl()) {
                if (auto parseResult = recordParser.parse(astContext, recDecl); parseResult.has_value()) {
                    result = std::move(*parseResult);
                } else {
                    // this shouldn't happen - TODO: currently happens with templated types
                    spdlog::debug("Unexpected code path triggered in ASTRecordParser {0:x}", 0x6D7DE8E7);
                    result = getIncompleteTypeInfo(getProperQualifiedName(type, astContext), idGenerator);
                }
            } else {
                // this shouldn't happen
                spdlog::debug("Unexpected code path triggered in ASTRecordParser {0:x}", 0x2742E4E7);
                result = getIncompleteTypeInfo(getProperQualifiedName(type, astContext), idGenerator);
            }
        });
    }

    TypeUsage ASTRecordParser::CreateTypeUsage(const clang::QualType &type, clang::ASTContext &astContext, ParsedTypesCache &typesCache,
                                               IdGenerator &idGenerator, ASTEnumParser &enumParser, ASTRecordParser &recordParser) {
        TypeUsage result;
        result.fullName = getProperQualifiedName(type.getCanonicalType(), astContext);
        result.form = getTypeForm(type);
        const auto strippedType = stripQualifiersAndPtrRefAliases(type);
        const auto strippedName = getProperQualifiedName(strippedType, astContext);
        // Fundamental types
        if (strippedType->isFundamentalType()) {
            result.type = CreateFundamentalTypeInfo(strippedType, strippedName, idGenerator, typesCache, astContext);
        } else if (strippedType->isIncompleteType()) {
            result.type = CreateIncompleteTypeInfo(strippedType, strippedName, idGenerator, typesCache, astContext);
        } else if (strippedType->isEnumeralType()) {
            result.type = CreateEnumTypeInfo(strippedType, strippedName, idGenerator, typesCache, astContext, enumParser);
        } else if (strippedType->isRecordType()) {
            result.type = CreateRecordTypeInfo(strippedType, strippedName, idGenerator, typesCache, astContext, recordParser);
        } else {
            // this shouldn't happen
            spdlog::debug("Unexpected code path triggered in ASTRecordParser {0:x}", 0x05CDE92E);
            result.type = CreateIncompleteTypeInfo(strippedType, strippedName, idGenerator, typesCache, astContext);
        }
        return result;
    }

    std::optional<std::string> ASTRecordParser::getFullTypeName(clang::ASTContext &astContext, clang::Decl *decl) {
        assert(clang::dyn_cast<clang::CXXRecordDecl>(decl) != nullptr);
        const auto recordDecl = clang::cast<clang::CXXRecordDecl>(decl);

        if (ShouldSkipRecordDecl(recordDecl)) { return std::nullopt; }

        spdlog::trace("ASTRecordParser: getting name of {}", getProperQualifiedName(recordDecl, astContext));

        const auto isTemplateSpecialization = recordDecl->getTemplateSpecializationKind() != clang::TSK_Undeclared;
        if (isTemplateSpecialization) {
            spdlog::trace("ASTRecordParser: {} is a template specialization", getProperQualifiedName(recordDecl, astContext));
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

        return getProperQualifiedName(definition, astContext);
    }

}// namespace speculo::gen