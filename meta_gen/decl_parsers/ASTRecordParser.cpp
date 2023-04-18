//
// Created by xflajs00 on 19.03.2023.
//

#include "ASTRecordParser.h"
#include "../AttributeParser.h"
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

    ASTRecordParser::ASTRecordParser(std::shared_ptr<IdGenerator> idGen) : ASTDeclParser(idGen) {}

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

        AttributeParser attributeParser{};

        // Skip if found decl is not definition
        const auto definition = recordDecl->getDefinition();
        if (definition != decl) {
            spdlog::info("ASTRecordParser: skipping, not a definition");
            return std::nullopt;
        }
        if (recordDecl->isAnonymousStructOrUnion()) {
            spdlog::info("ASTRecordParser: skipping, anonymous struct or union");
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

        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        auto printingPolicy = clang::PrintingPolicy{langOpts};

        result.sourceLocation.line = sourceManager.getPresumedLineNumber(recordDecl->getSourceRange().getBegin());
        result.sourceLocation.column = sourceManager.getPresumedColumnNumber(recordDecl->getSourceRange().getBegin());
        result.sourceLocation.filename = sourceManager.getFilename(recordDecl->getSourceRange().getBegin());

        result.attributes = attributeParser.parseRecordAttributes(astContext, *recordDecl);

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
            variableInfo.attributes = attributeParser.parseFieldAttributes(astContext, *field);
            variableInfo.access = clangAccesConv(field->getAccess());
            variableInfo.isMutable = field->isMutable();
            variableInfo.sourceLocation.line = sourceManager.getPresumedLineNumber(field->getSourceRange().getBegin());
            variableInfo.sourceLocation.column = sourceManager.getPresumedColumnNumber(field->getSourceRange().getBegin());
            variableInfo.sourceLocation.filename = sourceManager.getFilename(field->getSourceRange().getBegin());

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
                    variableInfo.attributes = attributeParser.parseFieldAttributes(astContext, *var);
                    variableInfo.access = clangAccesConv(var->getAccess());

                    variableInfo.sourceLocation.line = sourceManager.getPresumedLineNumber(var->getSourceRange().getBegin());
                    variableInfo.sourceLocation.column = sourceManager.getPresumedColumnNumber(var->getSourceRange().getBegin());
                    variableInfo.sourceLocation.filename = sourceManager.getFilename(var->getSourceRange().getBegin());

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
                argument.attributes = attributeParser.parseArgumentAttributes(astContext, *param);
                functionInfo.arguments.push_back(argument);
            }
            functionInfo.attributes = attributeParser.parseFunctionAttributes(astContext, *method);
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
                result.memberFunctions.push_back(functionInfo);
            }
        }
        // default copy/move operators
        {
            if (recordDecl->hasSimpleCopyAssignment() && !recordDecl->hasUserDeclaredCopyAssignment()) {
                FunctionInfo functionInfo;
                functionInfo.name = "operator=";
                functionInfo.fullName = fmt::format("{}::{}", result.fullName, functionInfo.name);

                FunctionArgument argument;
                argument.name = "";
                argument.fullName = "";
                argument.typeName = fmt::format("const {}&", result.fullName);
                argument.typeId = getIdGenerator().generateId(argument.typeName);
                argument.sourceLocation.line = 0;
                argument.sourceLocation.column = 0;
                argument.sourceLocation.filename = "<generated>";
                argument.attributes = {};
                functionInfo.arguments.push_back(argument);

                functionInfo.attributes = {};
                functionInfo.returnTypeName = fmt::format("{}&", result.fullName);
                functionInfo.returnTypeId = getIdGenerator().generateId(functionInfo.returnTypeName);
                functionInfo.access = Access::Public;
                functionInfo.isConstexpr = true;// FIXME: this is wrong
                functionInfo.isConsteval = false;
                functionInfo.isConst = false;
                functionInfo.isVirtual = false;
                functionInfo.isPureVirtual = false;
                functionInfo.sourceLocation.line = 0;
                functionInfo.sourceLocation.column = 0;
                functionInfo.sourceLocation.filename = "<generated>";

                const auto mangledName = mangleFunction(
                        functionInfo.fullName, functionInfo.arguments | std::views::transform([](const FunctionArgument &arg) {
                                                   return std::pair(std::string_view{arg.fullName}, std::string_view{arg.typeName});
                                               }));
                // mangling names for argument IDs
                for (auto &arg: functionInfo.arguments) {
                    arg.id = getIdGenerator().generateId(fmt::format("{}_{}_{}", mangledName, arg.fullName, arg.typeName));
                }

                functionInfo.id = getIdGenerator().generateId(mangledName);

                result.memberFunctions.push_back(functionInfo);
            }
            if (recordDecl->hasSimpleMoveAssignment() && !recordDecl->hasUserDeclaredMoveAssignment()) {
                FunctionInfo functionInfo;
                functionInfo.name = "operator=";
                functionInfo.fullName = fmt::format("{}::{}", result.fullName, functionInfo.name);

                FunctionArgument argument;
                argument.name = "";
                argument.fullName = "";
                argument.typeName = fmt::format("{}&&", result.fullName);
                argument.typeId = getIdGenerator().generateId(argument.typeName);
                argument.sourceLocation.line = 0;
                argument.sourceLocation.column = 0;
                argument.sourceLocation.filename = "<generated>";
                argument.attributes = {};
                functionInfo.arguments.push_back(argument);

                functionInfo.attributes = {};
                functionInfo.returnTypeName = fmt::format("{}&", result.fullName);
                functionInfo.returnTypeId = getIdGenerator().generateId(functionInfo.returnTypeName);
                functionInfo.access = Access::Public;
                functionInfo.isConstexpr = true;// FIXME: this is wrong
                functionInfo.isConsteval = false;
                functionInfo.isConst = false;
                functionInfo.isVirtual = false;
                functionInfo.isPureVirtual = false;
                functionInfo.sourceLocation.line = 0;
                functionInfo.sourceLocation.column = 0;
                functionInfo.sourceLocation.filename = "<generated>";

                const auto mangledName = mangleFunction(
                        functionInfo.fullName, functionInfo.arguments | std::views::transform([](const FunctionArgument &arg) {
                                                   return std::pair(std::string_view{arg.fullName}, std::string_view{arg.typeName});
                                               }));
                // mangling names for argument IDs
                for (auto &arg: functionInfo.arguments) {
                    arg.id = getIdGenerator().generateId(fmt::format("{}_{}_{}", mangledName, arg.fullName, arg.typeName));
                }

                functionInfo.id = getIdGenerator().generateId(mangledName);

                result.memberFunctions.push_back(functionInfo);
            }
        }

        for (const clang::CXXConstructorDecl *ctor: recordDecl->ctors()) {
            ConstructorInfo constructorInfo;
            constructorInfo.fullName = ctor->getQualifiedNameAsString();
            constructorInfo.id = getIdGenerator().generateId(constructorInfo.fullName);
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
                argument.attributes = attributeParser.parseArgumentAttributes(astContext, *param);
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
            constructorInfo.attributes = attributeParser.parseConstructorAttributes(astContext, *ctor);

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
        // default ctors
        {
            if (recordDecl->hasDefaultConstructor() && !recordDecl->hasUserProvidedDefaultConstructor()) {
                ConstructorInfo constructorInfo;
                constructorInfo.fullName = fmt::format("{}::{}", result.fullName, result.name);
                constructorInfo.id = getIdGenerator().generateId(constructorInfo.fullName);
                constructorInfo.isConstexpr = recordDecl->defaultedDestructorIsConstexpr();
                constructorInfo.isConsteval = false;
                constructorInfo.isExplicit = false;
                constructorInfo.access = Access::Public;
                constructorInfo.sourceLocation.line = 0;
                constructorInfo.sourceLocation.column = 0;
                constructorInfo.sourceLocation.filename = "<generated>";
                constructorInfo.isCopy = false;
                constructorInfo.isMove = false;
                result.destructor.attributes = {};

                const auto mangledName = mangleFunction(
                        constructorInfo.fullName, constructorInfo.arguments | std::views::transform([](const FunctionArgument &arg) {
                                                      return std::pair(std::string_view{arg.fullName}, std::string_view{arg.typeName});
                                                  }));
                constructorInfo.id = getIdGenerator().generateId(mangledName);

                result.constructors.push_back(constructorInfo);
            }
            if (recordDecl->hasSimpleCopyConstructor() && !recordDecl->hasUserDeclaredCopyConstructor()) {
                ConstructorInfo constructorInfo;
                constructorInfo.fullName = fmt::format("{}::{}", result.fullName, result.name);
                constructorInfo.id = getIdGenerator().generateId(constructorInfo.fullName);
                constructorInfo.isConstexpr = recordDecl->defaultedDestructorIsConstexpr();
                constructorInfo.isConsteval = false;
                constructorInfo.isExplicit = false;
                constructorInfo.access = Access::Public;
                constructorInfo.sourceLocation.line = 0;
                constructorInfo.sourceLocation.column = 0;
                constructorInfo.sourceLocation.filename = "<generated>";
                constructorInfo.isCopy = true;
                constructorInfo.isMove = false;
                result.destructor.attributes = {};

                FunctionArgument argument;
                argument.name = "";
                argument.fullName = "";
                argument.typeName = fmt::format("const {}&", result.fullName);
                argument.typeId = getIdGenerator().generateId(argument.typeName);
                argument.sourceLocation.line = 0;
                argument.sourceLocation.column = 0;
                argument.sourceLocation.filename = "<generated>";
                argument.attributes = {};
                constructorInfo.arguments.push_back(argument);

                const auto mangledName = mangleFunction(
                        constructorInfo.fullName, constructorInfo.arguments | std::views::transform([](const FunctionArgument &arg) {
                                                      return std::pair(std::string_view{arg.fullName}, std::string_view{arg.typeName});
                                                  }));
                // mangling names for argument IDs
                for (auto &argument: constructorInfo.arguments) {
                    argument.id = getIdGenerator().generateId(fmt::format("{}_{}_{}", mangledName, argument.fullName, argument.typeName));
                }
                constructorInfo.id = getIdGenerator().generateId(mangledName);

                result.constructors.push_back(constructorInfo);
            }
            if (recordDecl->hasSimpleMoveConstructor() && !recordDecl->hasUserDeclaredMoveConstructor()) {
                ConstructorInfo constructorInfo;
                constructorInfo.fullName = fmt::format("{}::{}", result.fullName, result.name);
                constructorInfo.id = getIdGenerator().generateId(constructorInfo.fullName);
                constructorInfo.isConstexpr = recordDecl->defaultedDestructorIsConstexpr();
                constructorInfo.isConsteval = false;
                constructorInfo.isExplicit = false;
                constructorInfo.access = Access::Public;
                constructorInfo.sourceLocation.line = 0;
                constructorInfo.sourceLocation.column = 0;
                constructorInfo.sourceLocation.filename = "<generated>";
                constructorInfo.isCopy = false;
                constructorInfo.isMove = true;
                result.destructor.attributes = {};

                FunctionArgument argument;
                argument.name = "";
                argument.fullName = "";
                argument.typeName = fmt::format("{}&&", result.fullName);
                argument.typeId = getIdGenerator().generateId(argument.typeName);
                argument.sourceLocation.line = 0;
                argument.sourceLocation.column = 0;
                argument.sourceLocation.filename = "<generated>";
                argument.attributes = {};
                constructorInfo.arguments.push_back(argument);

                const auto mangledName = mangleFunction(
                        constructorInfo.fullName, constructorInfo.arguments | std::views::transform([](const FunctionArgument &arg) {
                                                      return std::pair(std::string_view{arg.fullName}, std::string_view{arg.typeName});
                                                  }));
                // mangling names for argument IDs
                for (auto &argument: constructorInfo.arguments) {
                    argument.id = getIdGenerator().generateId(fmt::format("{}_{}_{}", mangledName, argument.fullName, argument.typeName));
                }
                constructorInfo.id = getIdGenerator().generateId(mangledName);

                result.constructors.push_back(constructorInfo);
            }
        }
        if (const clang::CXXDestructorDecl *destructor = recordDecl->getDestructor(); destructor != nullptr) {
            result.destructor.fullName = destructor->getQualifiedNameAsString();
            result.destructor.id = getIdGenerator().generateId(result.destructor.fullName);
            result.destructor.access = clangAccesConv(destructor->getAccess());
            result.destructor.sourceLocation.line = sourceManager.getPresumedLineNumber(destructor->getSourceRange().getBegin());
            result.destructor.sourceLocation.column = sourceManager.getPresumedColumnNumber(destructor->getSourceRange().getBegin());
            result.destructor.sourceLocation.filename = sourceManager.getFilename(destructor->getSourceRange().getBegin());
            result.destructor.attributes = attributeParser.parseDestructorAttributes(astContext, *destructor);
            result.destructor.isConstexpr = destructor->isConstexpr();
            result.destructor.isConsteval = destructor->isConsteval();
            result.destructor.isVirtual = destructor->isVirtual();
            result.destructor.isPureVirtual = destructor->isPure();
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


        return result;
    }

}// namespace pf::meta_gen