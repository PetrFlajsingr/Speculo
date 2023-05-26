//
// Created by xflajs00 on 18.03.2023.
//

#ifndef PF_META_GEN_ASTACTIONS_H
#define PF_META_GEN_ASTACTIONS_H

#include <memory>

#include "ASTParser.hpp"
#include "CodeGenWriter.hpp"
#include "IdGenerator.hpp"
#include "MetaInfoWriter.hpp"
#include "SourceConfig.hpp"
#include "clang_tooling_wrap.hpp"
#include "info_structs.hpp"

#include <clang/Frontend/CompilerInstance.h>
#include <clang/Tooling/Syntax/Tokens.h>

namespace pf::meta_gen {
    class ASTConsumer : public clang::ASTConsumer {
    public:
        ASTConsumer(const SourceConfig *c, std::shared_ptr<llvm::raw_fd_ostream> metaOstream,
                    std::shared_ptr<llvm::raw_fd_ostream> codeGenOstream, std::shared_ptr<IdGenerator> idGen, class ASTAction *p)
            : config{c}, metaWriter{std::move(metaOstream), idGen}, idGenerator{idGen}, codeGenWriter{std::move(codeGenOstream)},
              parent{p} {}

        void HandleTranslationUnit(clang::ASTContext &context) override;

    private:
        const SourceConfig *config;
        MetaInfoWriter metaWriter;
        CodeGenWriter codeGenWriter;
        std::shared_ptr<IdGenerator> idGenerator;
        class ASTAction *parent;
    };


    class ASTAction : public clang::ASTFrontendAction {
    public:
        explicit ASTAction(const SourceConfig *c, std::shared_ptr<llvm::raw_fd_ostream> metaOstream,
                           std::shared_ptr<llvm::raw_fd_ostream> codeGenOstream, std::shared_ptr<IdGenerator> idGen)
            : config{c}, idGenerator(std::move(idGen)), metaOutStream{std::move(metaOstream)}, codeGenOutStream{std::move(codeGenOstream)} {
        }

        std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &Compiler, llvm::StringRef InFile) override {
            return std::make_unique<ASTConsumer>(config, metaOutStream, codeGenOutStream, idGenerator, this);
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
        std::shared_ptr<llvm::raw_fd_ostream> metaOutStream;
        std::shared_ptr<llvm::raw_fd_ostream> codeGenOutStream;
        std::unique_ptr<clang::syntax::TokenCollector> tokenCollector{};
    };

    class ActionFactory : public clang::tooling::FrontendActionFactory {
    public:
        explicit ActionFactory(const SourceConfig &c, std::shared_ptr<llvm::raw_fd_ostream> metaOstream,
                               std::shared_ptr<llvm::raw_fd_ostream> codeGenOstream, std::shared_ptr<IdGenerator> idGen)
            : config{&c}, idGenerator(std::move(idGen)), metaOutStream{std::move(metaOstream)},
              codeGenOutStream{std::move(codeGenOstream)} {}

        std::unique_ptr<clang::FrontendAction> create() override {
            return std::make_unique<ASTAction>(config, metaOutStream, codeGenOutStream, idGenerator);
        }

    private:
        const SourceConfig *config;
        std::shared_ptr<IdGenerator> idGenerator;
        std::shared_ptr<llvm::raw_fd_ostream> metaOutStream;
        std::shared_ptr<llvm::raw_fd_ostream> codeGenOutStream;
    };
}// namespace pf::meta_gen

#endif//PF_META_GEN_ASTACTIONS_H
