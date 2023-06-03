//
// Created by xflajs00 on 18.03.2023.
//

#pragma once

#include <memory>

#include "ASTParser.hpp"
#include "IdGenerator.hpp"
#include "MetaInfoWriter.hpp"
#include "codegen/MetaSupportCodeGenerator.hpp"
#include "SourceConfig.hpp"
#include "clang_tooling_wrap.hpp"
#include "info_structs.hpp"

#include <clang/Frontend/CompilerInstance.h>
#include <clang/Tooling/Syntax/Tokens.h>

namespace pf::meta_gen {
    class ASTConsumer : public clang::ASTConsumer {
    public:
        ASTConsumer(const SourceConfig *c, std::shared_ptr<IdGenerator> idGen, class ASTAction *p)
            : config{c}, idGenerator{idGen}, parent{p} {}

        void HandleTranslationUnit(clang::ASTContext &context) override;

    private:
        const SourceConfig *config;
        std::shared_ptr<IdGenerator> idGenerator;
        class ASTAction *parent;
    };


    class ASTAction : public clang::ASTFrontendAction {
    public:
        explicit ASTAction(const SourceConfig *c, std::shared_ptr<IdGenerator> idGen) : config{c}, idGenerator(std::move(idGen)) {}

        std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &Compiler, llvm::StringRef InFile) override {
            return std::make_unique<ASTConsumer>(config, idGenerator, this);
        };

        bool BeginSourceFileAction(clang::CompilerInstance &Compiler) override {
            tokenCollector = std::make_unique<clang::syntax::TokenCollector>(Compiler.getPreprocessor());
            Compiler.getLangOpts().CommentOpts.ParseAllComments = true;
            return true;
        }

        [[nodiscard]] clang::syntax::TokenCollector &getTokenCollector() { return *tokenCollector; }
        [[nodiscard]] const clang::syntax::TokenCollector &getTokenCollector() const { return *tokenCollector; }

    protected:
        void ExecuteAction() override { ASTFrontendAction::ExecuteAction(); }


    private:
        const SourceConfig *config;
        std::shared_ptr<IdGenerator> idGenerator;
        std::unique_ptr<clang::syntax::TokenCollector> tokenCollector{};
    };

    class ActionFactory : public clang::tooling::FrontendActionFactory {
    public:
        explicit ActionFactory(const SourceConfig &c, std::shared_ptr<IdGenerator> idGen) : config{&c}, idGenerator(std::move(idGen)) {}

        std::unique_ptr<clang::FrontendAction> create() override { return std::make_unique<ASTAction>(config, idGenerator); }

    private:
        const SourceConfig *config;
        std::shared_ptr<IdGenerator> idGenerator;
    };
}// namespace pf::meta_gen
