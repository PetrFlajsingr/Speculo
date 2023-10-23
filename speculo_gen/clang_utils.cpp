module;

#include <fmt/format.h>
#include <clang/AST/DeclTemplate.h>
#include <boost/regex.hpp>
#include <cassert>
#include <clang/AST/QualTypeNames.h>
#include <clang/Lex/Lexer.h>
#include <clang/Basic/SourceManager.h>

module speculo.gen;
import :structs;
import :clang_utils;

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

    SourceLocationInfo getSourceLocationInfo(clang::ASTContext &astContext, const clang::CXXBaseSpecifier &base) {
        return {astContext.getSourceManager().getPresumedLineNumber(base.getSourceRange().getBegin()),
                astContext.getSourceManager().getPresumedColumnNumber(base.getSourceRange().getBegin()),
                astContext.getSourceManager().getFilename(base.getSourceRange().getBegin()).str()};
    }

    std::string getSourceText(clang::ASTContext &astContext, const clang::Decl &decl) {
        clang::SourceLocation b(decl.getBeginLoc()), _e(decl.getEndLoc());
        const auto &sourceManager = astContext.getSourceManager();
        clang::SourceLocation e(clang::Lexer::getLocForEndOfToken(_e, 0, sourceManager, astContext.getLangOpts()));
        return std::string(sourceManager.getCharacterData(b), sourceManager.getCharacterData(e) - sourceManager.getCharacterData(b));
    }

    std::string removeCommentsAndStrings(std::string_view source, bool keepRemovedNewLines) {
        static const boost::regex re(R"regex(
        (?(DEFINE)
          (?<prefix> (?:u8?|U|L) )
          (?<escape> \\ (?:
            ['"?\\abfnrtv]         # simple escape
            | [0-7]{1,3}           # octal escape
            | x [0-9a-fA-F]{1,2}   # hex escape
            | u [0-9a-fA-F]{4}     # universal character name
            | U [0-9a-fA-F]{8}     # universal character name
          ))
        )

        # singleline comment
        // .*

        # multiline comment
        | /\* (?s: .*? ) \*/

        # standard string
        | (?&prefix)? " (?> (?&escape) | [^"\\\r\n]+ )* "

        # raw string
        | (?&prefix)? R " (?<delimiter>[^ ()\\\t\x0B\r\n]*) \( (?s:.*?) \) \k<delimiter> "
    )regex",
                                     boost::regex::perl | boost::regex::no_mod_s | boost::regex::mod_x | boost::regex::optimize);

        std::string result;
        auto start = source.begin();
        auto end = source.end();
        boost::match_results<std::string_view::const_iterator> what;
        auto flags = boost::match_default;

        while (boost::regex_search(start, end, what, re, flags)) {
            result.append(start, what[0].first);

            if (keepRemovedNewLines) {
                const auto newline_count = std::count(what[0].first, what[0].second, '\n');
                result.append(std::string(newline_count, '\n'));
            }
            start = what[0].second;

            flags |= boost::match_prev_avail;
            flags |= boost::match_not_bob;
        }
        result.append(start, end);

        return result;
    }

    std::string getProperQualifiedName(const clang::CXXRecordDecl *decl, const clang::ASTContext &astContext) {
        std::string qualName = decl->getQualifiedNameAsString();
        if (auto specDecl = clang::dyn_cast<clang::ClassTemplateSpecializationDecl>(decl); specDecl != nullptr) {
            std::string argList{};
            for (const auto &templArg: specDecl->getTemplateArgs().asArray()) {
                if (templArg.getKind() == clang::TemplateArgument::ArgKind::Type) {
                    const auto argType = clang::TypeName::getFullyQualifiedName(templArg.getAsType().getCanonicalType(), astContext,
                                                                                astContext.getPrintingPolicy());
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
                    const auto argType = clang::TypeName::getFullyQualifiedName(templArg.getAsType().getCanonicalType(), astContext,
                                                                                astContext.getPrintingPolicy());
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
                    const auto argType = clang::TypeName::getFullyQualifiedName(templArg.getAsType().getCanonicalType(), astContext,
                                                                                astContext.getPrintingPolicy());
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
                        const auto argType = clang::TypeName::getFullyQualifiedName(templArg.getAsType().getCanonicalType(), astContext,
                                                                                    astContext.getPrintingPolicy());
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
                    const auto argType = clang::TypeName::getFullyQualifiedName(templArg.getAsType().getCanonicalType(), astContext,
                                                                                astContext.getPrintingPolicy());
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
                        const auto argType = clang::TypeName::getFullyQualifiedName(templArg.getAsType().getCanonicalType(), astContext,
                                                                                    astContext.getPrintingPolicy());
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
        auto pp = astContext.getPrintingPolicy();
        pp.FullyQualifiedName = 1;
        pp.SuppressScope = 0;
        pp.PrintCanonicalTypes = 1;
        return clang::TypeName::getFullyQualifiedName(type.getCanonicalType(), astContext, pp);
        // return clang::TypeName::getFullyQualifiedName(type.getCanonicalType(), astContext, astContext.getPrintingPolicy());
    }

    clang::QualType stripQualifiersAndPtrRefAliases(const clang::QualType &type) { return type->getCanonicalTypeUnqualified(); }

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

    std::optional<std::string> getTopLevelMacroName(const clang::ASTContext &astContext, clang::SourceLocation sourceLoc) {
        const auto &sourceManager = astContext.getSourceManager();
        if (!sourceManager.isMacroBodyExpansion(sourceLoc)) { return std::nullopt; }

        while (sourceManager.isMacroBodyExpansion(sourceLoc) || sourceManager.isMacroArgExpansion(sourceLoc)) {
            sourceLoc = sourceManager.getImmediateMacroCallerLoc(sourceLoc);
        }

        const auto spellingLoc = sourceManager.getSpellingLoc(sourceLoc);

        clang::Token t;
        clang::Lexer::getRawToken(spellingLoc, t, sourceManager, astContext.getLangOpts());
        return clang::Lexer::getSpelling(t, sourceManager, astContext.getLangOpts());
    }
}// namespace speculo::gen