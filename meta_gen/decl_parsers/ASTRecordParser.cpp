//
// Created by xflajs00 on 19.03.2023.
//

#include "ASTRecordParser.h"
#include "../AttributeParser.h"

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
        return Access::Public;
    }

    ASTRecordParser::ASTRecordParser(std::shared_ptr<IdGenerator> idGen) : ASTDeclParser(idGen) {}

    std::optional<TypeInfoVariant> ASTRecordParser::parse(clang::ASTContext &astContext, clang::Decl *decl) {
        assert(clang::dyn_cast<clang::CXXRecordDecl>(decl) != nullptr);
        const auto recordDecl = clang::cast<clang::CXXRecordDecl>(decl);

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

        for (const clang::FieldDecl *field: recordDecl->fields()) {
            VariableInfo variableInfo;
            variableInfo.name = field->getNameAsString();
            variableInfo.fullName = field->getQualifiedNameAsString();
            variableInfo.id = getIdGenerator().generateId(variableInfo.fullName);
            variableInfo.typeId = getIdGenerator().generateId(field->getType().getAsString());
            // TODO: variableInfo.attributes = attributeParser.parseFieldAttributes(astContext, *field);
            variableInfo.access = clangAccesConv(field->getAccess());
            variableInfo.isMutable = field->isMutable();

            result.memberVariables.push_back(variableInfo);
        }
        // static variables
        for (const auto innerDecls: recordDecl->decls()) {
            if (auto var = clang::dyn_cast<clang::VarDecl>(innerDecls)) {
                if (var->isStaticDataMember()) {
                    VariableInfo variableInfo;
                    variableInfo.name = var->getNameAsString();
                    variableInfo.fullName = var->getQualifiedNameAsString();
                    variableInfo.id = getIdGenerator().generateId(variableInfo.fullName);
                    variableInfo.typeId = getIdGenerator().generateId(var->getType().getAsString());
                    // TODO: variableInfo.attributes = attributeParser.parseFieldAttributes(astContext, *field);
                    variableInfo.access = clangAccesConv(var->getAccess());

                    result.staticVariables.push_back(variableInfo);
                }
            }
        }

        // TODO: generate ID from argument names as well - mangle
        for (const clang::CXXMethodDecl *method: recordDecl->methods()) {
            if (clang::dyn_cast<clang::CXXConstructorDecl>(method) != nullptr) { continue; }
            if (clang::dyn_cast<clang::CXXDestructorDecl>(method) != nullptr) { continue; }
            FunctionInfo functionInfo;
            functionInfo.name = method->getNameAsString();
            functionInfo.fullName = method->getQualifiedNameAsString();
            functionInfo.id = getIdGenerator().generateId(functionInfo.fullName);
            for (const clang::ParmVarDecl *param: method->parameters()) {
                FunctionArgument argument;
                argument.name = param->getNameAsString();
                argument.fullName = param->getQualifiedNameAsString();
                // TODO: mangle the arg name with the mangled function name
                argument.id = getIdGenerator().generateId(argument.fullName);
                argument.typeId = getIdGenerator().generateId(param->getType().getAsString());
                // TODO: argument.attributes
                functionInfo.arguments.push_back(argument);
            }
            // TODO: functionInfo.attributes = attributeParser.parseMethodAttributes(astContext, *method);
            functionInfo.returnTypeId = getIdGenerator().generateId(method->getReturnType().getAsString());
            functionInfo.access = clangAccesConv(method->getAccess());
            functionInfo.isConstexpr = method->isConstexpr();
            functionInfo.isConsteval = method->isConsteval();
            functionInfo.isConst = method->isConst();
            functionInfo.isVirtual = method->isVirtual();
            functionInfo.isPureVirtual = method->isPure();
            if (method->isStatic()) {
                result.staticFunctions.push_back(functionInfo);
            } else {
                result.memberFunctions.push_back(functionInfo);
            }
        }

        // TODO: generate ID from argument names as well - mangle
        for (const clang::CXXConstructorDecl *ctor: recordDecl->ctors()) {
            ConstructorInfo constructorInfo;
            constructorInfo.id = getIdGenerator().generateId(ctor->getQualifiedNameAsString());
            for (const clang::ParmVarDecl *param: ctor->parameters()) {
                FunctionArgument argument;
                argument.name = param->getNameAsString();
                argument.fullName = param->getQualifiedNameAsString();
                argument.id = getIdGenerator().generateId(argument.fullName);
                argument.typeId = getIdGenerator().generateId(param->getType().getAsString());
                // TODO: argument.attributes
                constructorInfo.arguments.push_back(argument);
            }
            constructorInfo.isConstexpr = ctor->isConstexpr();
            constructorInfo.isConsteval = ctor->isConsteval();
            constructorInfo.isExplicit = ctor->isExplicit();
            constructorInfo.access = clangAccesConv(ctor->getAccess());
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


        for (const clang::CXXBaseSpecifier &base: recordDecl->bases()) {
            BaseClassInfo baseClassInfo;
            // TODO: mangle the name for ID with the derived class's name
            baseClassInfo.id = getIdGenerator().generateId(base.getType().getAsString());
            // TODO: baseClassInfo.attributes
            baseClassInfo.isVirtual = base.isVirtual();
            baseClassInfo.access = clangAccesConv(base.getAccessSpecifier());
            result.baseClasses.push_back(baseClassInfo);
        }

        // recordDecl->friends()?

        return result;
    }

}// namespace pf::meta_gen