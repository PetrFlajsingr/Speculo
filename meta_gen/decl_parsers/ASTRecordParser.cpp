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
            using
            enum Access;
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

        auto &sourceManager = astContext.getSourceManager();
        auto &langOpts = astContext.getLangOpts();
        auto printingPolicy = clang::PrintingPolicy{langOpts};

        result.sourceLocation.line = sourceManager.getPresumedLineNumber(recordDecl->getSourceRange().getBegin());
        result.sourceLocation.column = sourceManager.getPresumedColumnNumber(recordDecl->getSourceRange().getBegin());
        result.sourceLocation.filename = sourceManager.getFilename(recordDecl->getSourceRange().getBegin());

        //TODO: result.attributes = AttributeParser{}.parseRecordAttributes(astContext, *recordDecl);

        result.isUnion = recordDecl->isUnion();
        result.isPolymorphic = recordDecl->isPolymorphic();
        result.isAbstract = recordDecl->isAbstract();
        result.isFinal = recordDecl->isEffectivelyFinal();

        // TODO: inherited
        for (const clang::FieldDecl *field: recordDecl->fields()) {
            VariableInfo variableInfo;
            variableInfo.name = field->getNameAsString();
            variableInfo.fullName = field->getQualifiedNameAsString();
            variableInfo.id = getIdGenerator().generateId(variableInfo.fullName);
            if (const auto typeRecordDecl = field->getType()->getAsCXXRecordDecl();
                    typeRecordDecl !=
                    nullptr) {
                variableInfo.typeName = typeRecordDecl->getQualifiedNameAsString();
            } else {
                variableInfo.typeName = field->getType().getAsString(printingPolicy);
            }
            variableInfo.typeId = getIdGenerator().generateId(variableInfo.typeName);
            // TODO: variableInfo.attributes = attributeParser.parseFieldAttributes(astContext, *field);
            variableInfo.access = clangAccesConv(field->getAccess());
            variableInfo.isMutable = field->isMutable();

            result.memberVariables.push_back(variableInfo);
        }
        // TODO: inherited
        // static variables
        for (const auto innerDecls: recordDecl->decls()) {
            if (auto var = clang::dyn_cast<clang::VarDecl>(innerDecls)) {
                if (var->isStaticDataMember()) {
                    VariableInfo variableInfo;
                    variableInfo.name = var->getNameAsString();
                    variableInfo.fullName = var->getQualifiedNameAsString();
                    variableInfo.id = getIdGenerator().generateId(variableInfo.fullName);
                    if (const auto typeRecordDecl = var->getType()->getAsCXXRecordDecl();
                            typeRecordDecl !=
                            nullptr) {
                        variableInfo.typeName = typeRecordDecl->getQualifiedNameAsString();
                    } else {
                        variableInfo.typeName = var->getType().getAsString(printingPolicy);
                    }
                    variableInfo.typeId = getIdGenerator().generateId(variableInfo.typeName);
                    // TODO: variableInfo.attributes = attributeParser.parseFieldAttributes(astContext, *field);
                    variableInfo.access = clangAccesConv(var->getAccess());

                    result.staticVariables.push_back(variableInfo);
                }
            }
        }

        const auto mangleFunction = [](std::string_view fullName,
                                       RangeOf<std::pair<std::string_view, std::string_view>> auto &&argumentTypesAndNames) {
            std::string result{fullName};
            for (const auto &[type, name]: argumentTypesAndNames) {
                result.append(fmt::format("_{}_{}", type, name));
            }
            return result;
        };

        // TODO: inherited (but not overriden) functions
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
                // TODO: mangle the arg name with the mangled function name
                argument.id = getIdGenerator().generateId(argument.fullName);
                if (const auto paramTypeRecordDecl = method->getReturnType()->getAsCXXRecordDecl();
                        paramTypeRecordDecl !=
                        nullptr) {
                    argument.typeName = paramTypeRecordDecl->getQualifiedNameAsString();
                } else {
                    argument.typeName = param->getType().getAsString(printingPolicy);
                }
                argument.typeId = getIdGenerator().generateId(argument.typeName);
                // TODO: argument.attributes
                functionInfo.arguments.push_back(argument);
            }
            // TODO: functionInfo.attributes = attributeParser.parseMethodAttributes(astContext, *method);
            if (const auto returnTypeRecordDecl = method->getReturnType()->getAsCXXRecordDecl();
                    returnTypeRecordDecl !=
                    nullptr) {
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

            const auto mangledName = mangleFunction(functionInfo.fullName,
                                                    functionInfo.arguments |
                                                    std::views::transform([](const FunctionArgument &arg) {
                                                        return std::pair(std::string_view{arg.fullName},
                                                                         std::string_view{arg.typeName});
                                                    }));
            functionInfo.id = getIdGenerator().generateId(mangledName);

            if (method->isStatic()) {
                result.staticFunctions.push_back(functionInfo);
            } else {
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
                argument.id = getIdGenerator().generateId(argument.fullName);

                if (const auto paramTypeRecordDecl = param->getType()->getAsCXXRecordDecl();  paramTypeRecordDecl !=
                                                                                              nullptr) {
                    argument.typeName = paramTypeRecordDecl->getQualifiedNameAsString();
                } else {
                    argument.typeName = param->getType().getAsString(printingPolicy);
                }
                argument.typeId = getIdGenerator().generateId(argument.typeName);
                // TODO: argument.attributes
                constructorInfo.arguments.push_back(argument);
            }
            constructorInfo.isConstexpr = ctor->isConstexpr();
            constructorInfo.isConsteval = ctor->isConsteval();
            constructorInfo.isExplicit = ctor->isExplicit();
            constructorInfo.access = clangAccesConv(ctor->getAccess());

            const auto mangledName = mangleFunction(constructorInfo.fullName,
                                                    constructorInfo.arguments |
                                                    std::views::transform([](const FunctionArgument &arg) {
                                                        return std::pair(std::string_view{arg.fullName},
                                                                         std::string_view{arg.typeName});
                                                    }));
            constructorInfo.id = getIdGenerator().generateId(mangledName);

            result.constructors.push_back(constructorInfo);
        }
        const clang::CXXDestructorDecl *destructor = recordDecl->getDestructor();
        result.destructor.id = getIdGenerator().generateId(destructor->getQualifiedNameAsString());
        result.destructor.access = clangAccesConv(destructor->getAccess());
        // TODO: result.destructor.attributes
        result.destructor.isConstexpr = destructor->isConstexpr();
        result.destructor.isConsteval = destructor->isConsteval();
        result.destructor.isVirtual = destructor->isVirtual();
        result.destructor.isPureVirtual = destructor->isPure();

        const auto mangleBaseClass = [](std::string_view derivedFullName,
                                        std::string baseFullName) {
            return fmt::format("{}__{}", derivedFullName, baseFullName);
        };

        for (const clang::CXXBaseSpecifier &base: recordDecl->bases()) {
            BaseClassInfo baseClassInfo;
            if (const auto baseRecordDecl = base.getType()->getAsCXXRecordDecl();  baseRecordDecl != nullptr) {
                baseClassInfo.fullName = baseRecordDecl->getQualifiedNameAsString();
            } else {
                baseClassInfo.fullName = base.getType().getAsString(printingPolicy);
            }
            const auto mangledName = mangleBaseClass(result.fullName, baseClassInfo.fullName);
            baseClassInfo.id = getIdGenerator().generateId(baseClassInfo.fullName);
            // TODO: baseClassInfo.attributes
            baseClassInfo.isVirtual = base.isVirtual();
            baseClassInfo.access = clangAccesConv(base.getAccessSpecifier());
            result.baseClasses.push_back(baseClassInfo);
        }

        // recordDecl->friends()?

        return result;
    }

}// namespace pf::meta_gen