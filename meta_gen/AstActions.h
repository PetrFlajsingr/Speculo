//
// Created by xflajs00 on 18.03.2023.
//

#ifndef PF_META_GEN_ASTACTIONS_H
#define PF_META_GEN_ASTACTIONS_H

#include <memory>

#include "ASTParser.h"
#include "IdGenerator.h"
#include "MetaInfoWriter.h"
#include "ParsingSettings.h"
#include "clang_tooling_wrap.h"
#include "info_structs.h"

namespace pf::meta_gen {

    class ASTConsumer : public clang::ASTConsumer {
    public:
        // TODO: get settings in here
        explicit ASTConsumer(std::shared_ptr<llvm::raw_fd_ostream> oStream, std::shared_ptr<IdGenerator> idGen)
                : astParser{ParsingSettings{true}, idGen}, writer{std::move(oStream), idGen} {}

        void HandleTranslationUnit(clang::ASTContext &context) override;

    private:
        ASTParser astParser;
        MetaInfoWriter writer;
    };


    class ASTAction : public clang::ASTFrontendAction {
    public:
        explicit ASTAction(std::shared_ptr<llvm::raw_fd_ostream> oStream, std::shared_ptr<IdGenerator> idGen)
                : idGenerator(std::move(idGen)), outStream{std::move(oStream)} {}

        std::unique_ptr<clang::ASTConsumer>
        CreateASTConsumer(clang::CompilerInstance &Compiler, llvm::StringRef InFile) override {
            return std::make_unique<ASTConsumer>(outStream, idGenerator);
        };

    private:
        std::shared_ptr<IdGenerator> idGenerator;
        std::shared_ptr<llvm::raw_fd_ostream> outStream;
    };

    class ActionFactory : public clang::tooling::FrontendActionFactory {
    public:
        explicit ActionFactory(std::shared_ptr<llvm::raw_fd_ostream> oStream, std::shared_ptr<IdGenerator> idGen)
                : idGenerator(std::move(idGen)), outStream{std::move(oStream)} {}

        std::unique_ptr<clang::FrontendAction> create() override {
            return std::make_unique<ASTAction>(outStream, idGenerator);
        }

    private:
        std::shared_ptr<IdGenerator> idGenerator;
        std::shared_ptr<llvm::raw_fd_ostream> outStream;
    };
}// namespace pf::meta_gen

#endif//PF_META_GEN_ASTACTIONS_H
