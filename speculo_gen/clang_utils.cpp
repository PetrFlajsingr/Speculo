
#include "clang_utils.hpp"
#include "fmt/format.h"
#include "clang/AST/DeclTemplate.h"
#include <cassert>
#include <clang/AST/QualTypeNames.h>

namespace speculo::gen {

    Access clangAccesConv(clang::AccessSpecifier src) {
        switch (src) {
            using enum Access;
            case clang::AS_public:
                return Public;
            case clang::AS_protected:
                return Protected;
            case clang::AS_private:
                return Private;
            case clang::AS_none:
                return Public;
        }
        assert(false && "Can't happen");
        return Access::Public;
    }

    SourceLocationInfo getSourceLocationInfo(clang::ASTContext &astContext, const clang::Decl &decl) {
        return {astContext.getSourceManager().getPresumedLineNumber(decl.getSourceRange().getBegin()),
                astContext.getSourceManager().getPresumedColumnNumber(decl.getSourceRange().getBegin()),
                astContext.getSourceManager().getFilename(decl.getSourceRange().getBegin()).str()};
    }

    SourceLocationInfo gen::getSourceLocationInfo(clang::ASTContext &astContext, const clang::CXXBaseSpecifier &base) {
        return {astContext.getSourceManager().getPresumedLineNumber(base.getSourceRange().getBegin()),
                astContext.getSourceManager().getPresumedColumnNumber(base.getSourceRange().getBegin()),
                astContext.getSourceManager().getFilename(base.getSourceRange().getBegin()).str()};
    }

    std::string getSourceText(clang::ASTContext &astContext, const clang::Decl &decl) {
        return clang::Lexer::getSourceText(clang::CharSourceRange::getTokenRange(decl.getSourceRange()), astContext.getSourceManager(),
                                           astContext.getLangOpts())
                .str();
    }

    std::string getProperQualifiedName(const clang::CXXRecordDecl *decl, const clang::ASTContext &astContext) {
        std::string qualName = decl->getQualifiedNameAsString();
        if (auto specDecl = clang::dyn_cast<clang::ClassTemplateSpecializationDecl>(decl); specDecl != nullptr) {
            std::string argList{};
            for (const auto &templArg: specDecl->getTemplateArgs().asArray()) {
                if (templArg.getKind() == clang::TemplateArgument::ArgKind::Type) {
                    const auto argType =
                            clang::TypeName::getFullyQualifiedName(templArg.getAsType(), astContext, astContext.getPrintingPolicy());
                    argList.append(argType).append(",");
                }
            }
            if (!argList.empty()) { argList = argList.substr(0, argList.length() - 1); }
            qualName.append(fmt::format("<{}>", argList));
        }
        return qualName;
    }

    std::string getProperName(const clang::CXXRecordDecl *decl, const clang::ASTContext &astContext) {
        std::string qualName = decl->getNameAsString();
        if (auto specDecl = clang::dyn_cast<clang::ClassTemplateSpecializationDecl>(decl); specDecl != nullptr) {
            std::string argList{};
            for (const auto &templArg: specDecl->getTemplateArgs().asArray()) {
                if (templArg.getKind() == clang::TemplateArgument::ArgKind::Type) {
                    const auto argType =
                            clang::TypeName::getFullyQualifiedName(templArg.getAsType(), astContext, astContext.getPrintingPolicy());
                    argList.append(argType).append(",");
                }
            }
            if (!argList.empty()) { argList = argList.substr(0, argList.length() - 1); }
            qualName.append(fmt::format("<{}>", argList));
        }
        return qualName;
    }
    std::string getProperQualifiedName(const clang::CXXMethodDecl *decl, const clang::ASTContext &astContext) {
        std::string result = decl->getQualifiedNameAsString();
        std::string argList{};
        if (const auto args = decl->getTemplateSpecializationArgs(); args != nullptr) {
            for (const auto &templArg: args->asArray()) {
                if (templArg.getKind() == clang::TemplateArgument::ArgKind::Type) {
                    const auto argType =
                            clang::TypeName::getFullyQualifiedName(templArg.getAsType(), astContext, astContext.getPrintingPolicy());
                    argList.append(argType).append(",");
                }
                // TODO: value args support
            }
            if (!argList.empty()) {
                argList = argList.substr(0, argList.length() - 1);
                result.append(fmt::format("<{}>", argList));
            }
        }
        return result;
    }
    std::string getProperName(const clang::CXXMethodDecl *decl, const clang::ASTContext &astContext) {
        std::string result = decl->getNameAsString();
        std::string argList{};
        if (const auto args = decl->getTemplateSpecializationArgs(); args != nullptr) {
            for (const auto &templArg: args->asArray()) {
                switch (templArg.getKind()) {
                    case clang::TemplateArgument::Type: {
                        const auto argType =
                                clang::TypeName::getFullyQualifiedName(templArg.getAsType(), astContext, astContext.getPrintingPolicy());
                        argList.append(argType).append(",");
                    } break;
                    default:
                        break;
                }
                // TODO: value args support
            }
            if (!argList.empty()) {
                argList = argList.substr(0, argList.length() - 1);
                result.append(fmt::format("<{}>", argList));
            }
        }

        return result;
    }

    std::string getProperQualifiedName(const clang::CXXConstructorDecl *decl, const clang::ASTContext &astContext) {
        std::string result = decl->getQualifiedNameAsString();
        std::string argList{};
        if (const auto args = decl->getTemplateSpecializationArgs(); args != nullptr) {
            for (const auto &templArg: args->asArray()) {
                if (templArg.getKind() == clang::TemplateArgument::ArgKind::Type) {
                    const auto argType =
                            clang::TypeName::getFullyQualifiedName(templArg.getAsType(), astContext, astContext.getPrintingPolicy());
                    argList.append(argType).append(",");
                }
                // TODO: value args support
            }
            if (!argList.empty()) {
                argList = argList.substr(0, argList.length() - 1);
                result.append(fmt::format("<{}>", argList));
            }
        }
        return result;
    }
    std::string getProperName(const clang::CXXConstructorDecl *decl, const clang::ASTContext &astContext) {
        std::string result = decl->getNameAsString();
        std::string argList{};
        if (const auto args = decl->getTemplateSpecializationArgs(); args != nullptr) {
            for (const auto &templArg: args->asArray()) {
                switch (templArg.getKind()) {
                    case clang::TemplateArgument::Type: {
                        const auto argType =
                                clang::TypeName::getFullyQualifiedName(templArg.getAsType(), astContext, astContext.getPrintingPolicy());
                        argList.append(argType).append(",");
                    } break;
                    default:
                        break;
                }
                // TODO: value args support
            }
            if (!argList.empty()) {
                argList = argList.substr(0, argList.length() - 1);
                result.append(fmt::format("<{}>", argList));
            }
        }
        return result;
    }

    std::string getProperQualifiedName(const clang::QualType &type, const clang::ASTContext &astContext) {
        return clang::TypeName::getFullyQualifiedName(type, astContext, astContext.getPrintingPolicy());
    }

    clang::QualType stripQualifiersAndPtrRef(const clang::QualType &type) {
        clang::QualType result = type;
        while (result->isPointerType() || result->isReferenceType()) {
            if (result->isPointerType()) {
                result = result->getPointeeType();
            } else if (result->isReferenceType()) {
                result = result.getNonReferenceType();
            }
        }

        return result.getUnqualifiedType();
    }

    // FIXME: this is really basic
    TypeForm getTypeForm(const clang::QualType &type) {
        using enum TypeForm;
        if (!type->isPointerType() && !type->isReferenceType() && !type.isVolatileQualified()) {
            if (type.isConstQualified()) { return Const; }
            return Normal;
        }
        if (type->isPointerType()) {
            const auto unptrType = type->getPointeeType();
            if (!unptrType->isPointerType() && !unptrType->isReferenceType() && !unptrType.isVolatileQualified()) {
                if (unptrType.isConstQualified()) { return ConstPtr; }
                return Ptr;
            }
            return Other;
        }
        if (type->isReferenceType()) {
            const auto unrefType = type.getNonReferenceType();
            if (!unrefType->isPointerType() && !unrefType.isVolatileQualified()) {
                if (unrefType.isConstQualified()) { return ConstLRef; }
                if (type->isLValueReferenceType()) {
                    return LRef;
                } else {
                    return RRef;
                }
            }
            return Other;
        }
        return Other;
    }
}// namespace speculo::gen