//
// Created by xflajs00 on 19.03.2023.
//

#include "ASTRecordParser.hpp"
#include "../AttributeParser.hpp"
#include <clang/Sema/Sema.h>
#include <pf_common/concepts/ranges.h>
#include <spdlog/spdlog.h>

namespace pf::meta_gen {
    // TODO: move
    [[nodiscard]] Access clangAccesConv(clang::AccessSpecifier src) {
        switch (src) {
            using enum Access;
            case clang::AS_public:
                return Public;
            case clang::AS_protected:
                return Protected;
            case clang::AS_private:
                return Private;
            case clang::AS_none:
                // FIXME: what to do here?
                return Public;
        }
        assert(false && "Can't happen");
        return Access::Public;
    }

    ASTRecordParser::ASTRecordParser(std::shared_ptr<IdGenerator> idGen, std::shared_ptr<AttributeParser> attribParser)
        : ASTDeclParser{std::move(idGen), std::move(attribParser)} {}

    // TODO: divide this up into separate functions
    std::optional<TypeInfoVariant> ASTRecordParser::parse(clang::ASTContext &astContext, clang::Decl *decl) {
        assert(clang::dyn_cast<clang::CXXRecordDecl>(decl) != nullptr);
        const auto recordDecl = clang::cast<clang::CXXRecordDecl>(decl);

        // TODO: verify how this works
        // not supporting templates for now
        if (recordDecl->isTemplateDecl()) {
            spdlog::warn("Skipping template record {}", recordDecl->getQualifiedNameAsString());
            return std::nullopt;
        }

        spdlog::info("ASTRecordParser: parsing {}", recordDecl->getQualifiedNameAsString());

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

        RecordTypeInfo result{};

        result.fullName = recordDecl->getQualifiedNameAsString();
        result.name = recordDecl->getNameAsString();
        result.id = getIdGenerator().generateId(result.fullName);
        result.constId = getIdGenerator().generateId("const " + result.fullName);
        result.lrefId = getIdGenerator().generateId(result.fullName + "&");
        result.rrefId = getIdGenerator().generateId(result.fullName + "&&");
        result.constLrefId = getIdGenerator().generateId("const " + result.fullName + "&");
        result.ptrId = getIdGenerator().generateId(result.fullName + "*");
        result.constPtrId = getIdGenerator().generateId("const" + result.fullName + "*");
        result.isNestedType = recordDecl->getAccess() != clang::AccessSpecifier::AS_none;
        if (result.isNestedType) { result.nestedAccess = clangAccesConv(recordDecl->getAccess()); }

        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        auto printingPolicy = clang::PrintingPolicy{langOpts};

        result.originalCode =
                clang::Lexer::getSourceText(clang::CharSourceRange::getTokenRange(recordDecl->getSourceRange()), sourceManager, langOpts)
                        .str();

        // check that there is a semicolon at the end of the macro so we don't miss any functions or ctors
        constexpr std::string_view metaGenMacro = "PF_META_GENERATED()";
        bool pfMetaGeneratedMacroFound = false;
        if (auto pos = result.originalCode.find(metaGenMacro); pos != std::string::npos) {
            pos += metaGenMacro.size();
            if (result.originalCode[pos] != ';') {
                spdlog::error("Class {} contains 'PF_META_GENERATED()', but it's missing a semicolon at the end, preventing proper "
                              "parsing, please provide it 'PF_META_GENERATED();'",
                              result.fullName);
                spdlog::error("Skipping parsing of {} due to the above provided reason", result.fullName);
                return std::nullopt;
            }
            pfMetaGeneratedMacroFound = true;
        }

        result.sourceLocation.line = sourceManager.getPresumedLineNumber(recordDecl->getSourceRange().getBegin());
        result.sourceLocation.column = sourceManager.getPresumedColumnNumber(recordDecl->getSourceRange().getBegin());
        result.sourceLocation.filename = sourceManager.getFilename(recordDecl->getSourceRange().getBegin());

        result.attributes = getAttributeParser().parseRecordAttributes(astContext, *recordDecl);

        result.isClass = recordDecl->isClass();
        result.isStruct = recordDecl->isStruct();
        result.isUnion = recordDecl->isUnion();
        result.isPolymorphic = recordDecl->isPolymorphic();
        result.isAbstract = recordDecl->isAbstract();
        result.isFinal = recordDecl->isEffectivelyFinal();

        // TODO: inherited?
        for (const clang::FieldDecl *field: recordDecl->fields()) {
            VariableInfo variableInfo;
            variableInfo.name = field->getNameAsString();
            variableInfo.fullName = field->getQualifiedNameAsString();
            variableInfo.id = getIdGenerator().generateId(variableInfo.fullName);
            if (const auto typeRecordDecl = field->getType()->getAsCXXRecordDecl(); typeRecordDecl != nullptr) {
                variableInfo.typeName = typeRecordDecl->getQualifiedNameAsString();
            } else {
                variableInfo.typeName = field->getType().getAsString(printingPolicy);
            }
            variableInfo.typeId = getIdGenerator().generateId(variableInfo.typeName);
            variableInfo.attributes = getAttributeParser().parseFieldAttributes(astContext, *field);
            variableInfo.access = clangAccesConv(field->getAccess());
            variableInfo.isMutable = field->isMutable();
            variableInfo.sourceLocation.line = sourceManager.getPresumedLineNumber(field->getSourceRange().getBegin());
            variableInfo.sourceLocation.column = sourceManager.getPresumedColumnNumber(field->getSourceRange().getBegin());
            variableInfo.sourceLocation.filename = sourceManager.getFilename(field->getSourceRange().getBegin());
            variableInfo.isBitfield = field->isBitField();
            variableInfo.bitfieldSize = 0;
            if (variableInfo.isBitfield) { variableInfo.bitfieldSize = field->getBitWidthValue(astContext); }

            result.memberVariables.push_back(variableInfo);
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
                        variableInfo.typeName = typeRecordDecl->getQualifiedNameAsString();
                    } else {
                        variableInfo.typeName = var->getType().getAsString(printingPolicy);
                    }
                    variableInfo.typeId = getIdGenerator().generateId(variableInfo.typeName);
                    variableInfo.attributes = getAttributeParser().parseFieldAttributes(astContext, *var);
                    variableInfo.access = clangAccesConv(var->getAccess());

                    variableInfo.sourceLocation.line = sourceManager.getPresumedLineNumber(var->getSourceRange().getBegin());
                    variableInfo.sourceLocation.column = sourceManager.getPresumedColumnNumber(var->getSourceRange().getBegin());
                    variableInfo.sourceLocation.filename = sourceManager.getFilename(var->getSourceRange().getBegin());

                    variableInfo.isConstexpr = var->isConstexpr();
                    variableInfo.isInline = var->isInlineSpecified();
                    variableInfo.isInlineSpecified = var->isInlineSpecified();
                    result.staticVariables.push_back(variableInfo);
                }
            }
        }

        const auto mangleFunction = [](std::string_view fullName,
                                       RangeOf<std::pair<std::string_view, std::string_view>> auto &&argumentTypesAndNames) {
            std::string result{fullName};
            for (const auto &[type, name]: argumentTypesAndNames) { result.append(fmt::format("_{}_{}", type, name)); }
            return result;
        };

        // TODO: this does not enumerate templated, investigate
        // TODO: inherited (but not overriden) functions?
        for (const clang::CXXMethodDecl *method: recordDecl->methods()) {
            // skipping ctors and dtors here
            if (clang::dyn_cast<clang::CXXConstructorDecl>(method) != nullptr) { continue; }
            if (clang::dyn_cast<clang::CXXDestructorDecl>(method) != nullptr) { continue; }

            FunctionInfo functionInfo;
            functionInfo.name = method->getNameAsString();
            functionInfo.fullName = method->getQualifiedNameAsString();
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
                    argument.typeName = paramTypeRecordDecl->getQualifiedNameAsString();
                } else {
                    argument.typeName = param->getType().getAsString(printingPolicy);
                }
                argument.typeId = getIdGenerator().generateId(argument.typeName);
                argument.sourceLocation.line = sourceManager.getPresumedLineNumber(param->getSourceRange().getBegin());
                argument.sourceLocation.column = sourceManager.getPresumedColumnNumber(param->getSourceRange().getBegin());
                argument.sourceLocation.filename = sourceManager.getFilename(param->getSourceRange().getBegin());
                argument.attributes = std::move(att.argumentAttributes[argument.name]);
                functionInfo.arguments.push_back(argument);
            }
            functionInfo.attributes = std::move(att.attributes);
            if (const auto returnTypeRecordDecl = method->getReturnType()->getAsCXXRecordDecl(); returnTypeRecordDecl != nullptr) {
                functionInfo.returnTypeName = returnTypeRecordDecl->getQualifiedNameAsString();
            } else {
                functionInfo.returnTypeName = method->getReturnType().getAsString(printingPolicy);
            }
            functionInfo.returnTypeId = getIdGenerator().generateId(functionInfo.returnTypeName);
            functionInfo.access = clangAccesConv(method->getAccess());
            functionInfo.isConstexpr = method->isConstexpr();
            functionInfo.isConsteval = method->isConsteval();
            functionInfo.isConst = method->isConst();
            functionInfo.isVirtual = method->isVirtual();
            functionInfo.isPureVirtual = method->isPure();
            functionInfo.sourceLocation.line = sourceManager.getPresumedLineNumber(method->getSourceRange().getBegin());
            functionInfo.sourceLocation.column = sourceManager.getPresumedColumnNumber(method->getSourceRange().getBegin());
            functionInfo.sourceLocation.filename = sourceManager.getFilename(method->getSourceRange().getBegin());

            const auto mangledName = mangleFunction(functionInfo.fullName,
                                                    functionInfo.arguments | std::views::transform([](const FunctionArgument &arg) {
                                                        return std::pair(std::string_view{arg.fullName}, std::string_view{arg.typeName});
                                                    }));
            // mangling names for argument IDs
            for (auto &argument: functionInfo.arguments) {
                argument.id = getIdGenerator().generateId(fmt::format("{}_{}_{}", mangledName, argument.fullName, argument.typeName));
            }

            functionInfo.id = getIdGenerator().generateId(mangledName);

            if (method->isStatic()) {
                result.staticFunctions.push_back(functionInfo);
            } else {
                functionInfo.isFinal = method->hasAttr<clang::FinalAttr>();
                result.memberFunctions.push_back(functionInfo);
            }
        }
        // FIXME: can't really get ptrs to generated operators

        for (const clang::CXXConstructorDecl *ctor: recordDecl->ctors()) {
            if (ctor->isDeleted()) { continue; }
            if (ctor->isCopyConstructor() && ctor->isImplicit()) {
                // Class has user declared move ctor or assign.
                if (recordDecl->hasUserDeclaredMoveAssignment() || recordDecl->hasUserDeclaredMoveConstructor()) { continue; }
                // Class has non-static const member.
                // Class has non-static reference member.
                if (std::ranges::any_of(recordDecl->fields(), [](const auto &field) {
                        return field->getType().isConstQualified() || field->getType()->isReferenceType();
                    })) {
                    continue;
                }
                // TODO:
                // Class has non-copyable data member or base class. Base class with inaccessible destructor
            }
            if (ctor->isMoveConstructor() && ctor->isImplicit()) {
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

            ConstructorInfo constructorInfo;
            constructorInfo.fullName = ctor->getQualifiedNameAsString();
            constructorInfo.id = getIdGenerator().generateId(constructorInfo.fullName);

            auto att = getAttributeParser().parseConstructorAttributes(astContext, *ctor);
            for (const clang::ParmVarDecl *param: ctor->parameters()) {
                FunctionArgument argument;
                argument.name = param->getNameAsString();
                argument.fullName = param->getQualifiedNameAsString();

                if (const auto paramTypeRecordDecl = param->getType()->getAsCXXRecordDecl(); paramTypeRecordDecl != nullptr) {
                    argument.typeName = paramTypeRecordDecl->getQualifiedNameAsString();
                } else {
                    argument.typeName = param->getType().getAsString(printingPolicy);
                }
                argument.typeId = getIdGenerator().generateId(argument.typeName);
                argument.sourceLocation.line = sourceManager.getPresumedLineNumber(param->getSourceRange().getBegin());
                argument.sourceLocation.column = sourceManager.getPresumedColumnNumber(param->getSourceRange().getBegin());
                argument.sourceLocation.filename = sourceManager.getFilename(param->getSourceRange().getBegin());
                argument.attributes = std::move(att.argumentAttributes[argument.name]);
                constructorInfo.arguments.push_back(argument);
            }
            constructorInfo.isConstexpr = ctor->isConstexpr();
            constructorInfo.isConsteval = ctor->isConsteval();
            constructorInfo.isExplicit = ctor->isExplicit();
            constructorInfo.access = clangAccesConv(ctor->getAccess());
            constructorInfo.sourceLocation.line = sourceManager.getPresumedLineNumber(ctor->getSourceRange().getBegin());
            constructorInfo.sourceLocation.column = sourceManager.getPresumedColumnNumber(ctor->getSourceRange().getBegin());
            constructorInfo.sourceLocation.filename = sourceManager.getFilename(ctor->getSourceRange().getBegin());
            constructorInfo.isCopy = ctor->isCopyConstructor();
            constructorInfo.isMove = ctor->isMoveConstructor();
            constructorInfo.attributes = std::move(att.attributes);
            constructorInfo.isInline = ctor->hasInlineBody();
            constructorInfo.isInlineSpecified = ctor->isInlineSpecified();

            const auto mangledName = mangleFunction(constructorInfo.fullName,
                                                    constructorInfo.arguments | std::views::transform([](const FunctionArgument &arg) {
                                                        return std::pair(std::string_view{arg.fullName}, std::string_view{arg.typeName});
                                                    }));
            // mangling names for argument IDs
            for (auto &argument: constructorInfo.arguments) {
                argument.id = getIdGenerator().generateId(fmt::format("{}_{}_{}", mangledName, argument.fullName, argument.typeName));
            }
            constructorInfo.id = getIdGenerator().generateId(mangledName);

            result.constructors.push_back(constructorInfo);
        }
        if (const clang::CXXDestructorDecl *destructor = recordDecl->getDestructor(); destructor != nullptr) {
            result.destructor.fullName = destructor->getQualifiedNameAsString();
            result.destructor.id = getIdGenerator().generateId(result.destructor.fullName);
            result.destructor.access = clangAccesConv(destructor->getAccess());
            result.destructor.sourceLocation.line = sourceManager.getPresumedLineNumber(destructor->getSourceRange().getBegin());
            result.destructor.sourceLocation.column = sourceManager.getPresumedColumnNumber(destructor->getSourceRange().getBegin());
            result.destructor.sourceLocation.filename = sourceManager.getFilename(destructor->getSourceRange().getBegin());
            result.destructor.attributes = std::move(getAttributeParser().parseDestructorAttributes(astContext, *destructor).attributes);
            result.destructor.isConstexpr = destructor->isConstexpr();
            result.destructor.isConsteval = destructor->isConsteval();
            result.destructor.isVirtual = destructor->isVirtual();
            result.destructor.isPureVirtual = destructor->isPure();
            const auto methodDecl = clang::dyn_cast<clang::CXXMethodDecl>(destructor);
            result.destructor.isFinal = methodDecl->hasAttr<clang::FinalAttr>();
            result.destructor.isInline = destructor->hasInlineBody();
            result.destructor.isInlineSpecified = destructor->isInlineSpecified();
        } else if (recordDecl->hasSimpleDestructor()) {
            result.destructor.fullName = fmt::format("{}::~{}", result.fullName, result.name);
            result.destructor.id = getIdGenerator().generateId(result.destructor.fullName);
            result.destructor.access = Access::Public;
            result.destructor.sourceLocation.line = 0;
            result.destructor.sourceLocation.column = 0;
            result.destructor.sourceLocation.filename = "<generated>";
            result.destructor.attributes = {};
            result.destructor.isConstexpr = recordDecl->hasConstexprDestructor();
            result.destructor.isConsteval = false;
            result.destructor.isVirtual = false;
            result.destructor.isPureVirtual = false;
            result.destructor.isFinal = false;
            result.destructor.isInline = false;
        }

        const auto mangleBaseClass = [](std::string_view derivedFullName, std::string baseFullName) {
            return fmt::format("{}__{}", derivedFullName, baseFullName);
        };

        for (const clang::CXXBaseSpecifier &base: recordDecl->bases()) {
            BaseClassInfo baseClassInfo;
            if (const auto baseRecordDecl = base.getType()->getAsCXXRecordDecl(); baseRecordDecl != nullptr) {
                baseClassInfo.fullName = baseRecordDecl->getQualifiedNameAsString();
                baseClassInfo.name = baseRecordDecl->getNameAsString();
            } else {
                baseClassInfo.fullName = base.getType().getAsString(printingPolicy);
                baseClassInfo.name = base.getType().getAsString();
            }
            const auto mangledName = mangleBaseClass(result.fullName, baseClassInfo.fullName);
            baseClassInfo.id = getIdGenerator().generateId(mangledName);
            baseClassInfo.isVirtual = base.isVirtual();
            baseClassInfo.access = clangAccesConv(base.getAccessSpecifier());
            baseClassInfo.sourceLocation.line = sourceManager.getPresumedLineNumber(base.getSourceRange().getBegin());
            baseClassInfo.sourceLocation.column = sourceManager.getPresumedColumnNumber(base.getSourceRange().getBegin());
            baseClassInfo.sourceLocation.filename = sourceManager.getFilename(base.getSourceRange().getBegin());
            result.baseClasses.push_back(baseClassInfo);
        }

        if (!pfMetaGeneratedMacroFound) {
            if (std::ranges::any_of(result.constructors, [](const auto &ctor) { return ctor.access != Access::Public; }) ||
                std::ranges::any_of(result.staticFunctions, [](const auto &ctor) { return ctor.access != Access::Public; }) ||
                std::ranges::any_of(result.memberFunctions, [](const auto &ctor) { return ctor.access != Access::Public; }) ||
                std::ranges::any_of(result.staticVariables, [](const auto &ctor) { return ctor.access != Access::Public; }) ||
                std::ranges::any_of(result.memberVariables, [](const auto &ctor) { return ctor.access != Access::Public; }) ||
                result.destructor.access != Access::Public) {
                spdlog::error("Class {} does not contain 'PF_META_GENERATED()', but it contains private or protected constructors, "
                              "destructor, variables or functions - the macro is required to access these",
                              result.fullName);
                spdlog::error("Skipping parsing of {} due to the above provided reason", result.fullName);
                return std::nullopt;
            }
        }

        return result;
    }

}// namespace pf::meta_gen