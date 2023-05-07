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

namespace pf::meta_gen {

    class ASTConsumer : public clang::ASTConsumer {
    public:
        explicit ASTConsumer(const SourceConfig *c, std::shared_ptr<llvm::raw_fd_ostream> metaOstream,
                             std::shared_ptr<llvm::raw_fd_ostream> codeGenOstream, std::shared_ptr<IdGenerator> idGen)
            : config{c}, astParser{c, idGen}, metaWriter{std::move(metaOstream), idGen}, codeGenWriter{std::move(codeGenOstream)} {}

        void HandleTranslationUnit(clang::ASTContext &context) override;

    private:
        const SourceConfig *config;
        ASTParser astParser;
        MetaInfoWriter metaWriter;
        CodeGenWriter codeGenWriter;
    };


    class ASTAction : public clang::ASTFrontendAction {
    public:
        explicit ASTAction(const SourceConfig *c, std::shared_ptr<llvm::raw_fd_ostream> metaOstream,
                           std::shared_ptr<llvm::raw_fd_ostream> codeGenOstream, std::shared_ptr<IdGenerator> idGen)
            : config{c}, idGenerator(std::move(idGen)), metaOutStream{std::move(metaOstream)}, codeGenOutStream{std::move(codeGenOstream)} {
        }

        std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &Compiler, llvm::StringRef InFile) override {
            return std::make_unique<ASTConsumer>(config, metaOutStream, codeGenOutStream, idGenerator);
        };

        bool BeginSourceFileAction(clang::CompilerInstance &Compiler) override {
            Compiler.getLangOpts().CommentOpts.ParseAllComments = true;
            return true;
        }

    private:
        const SourceConfig *config;
        std::shared_ptr<IdGenerator> idGenerator;
        std::shared_ptr<llvm::raw_fd_ostream> metaOutStream;
        std::shared_ptr<llvm::raw_fd_ostream> codeGenOutStream;
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
