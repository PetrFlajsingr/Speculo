//
// Created by xflajs00 on 18.03.2023.
//

#ifndef PF_META_GEN_ASTACTIONS_H
#define PF_META_GEN_ASTACTIONS_H

#include <memory>

#include "clang_tooling_wrap.h"
#include "info_structs.h"

namespace pf::meta_gen {

    class ASTConsumer : public clang::ASTConsumer {
    public:
        explicit ASTConsumer(std::shared_ptr<llvm::raw_fd_ostream> oStream) : outStream{std::move(oStream)} {}

        void HandleTranslationUnit(clang::ASTContext &context) override;

    private:
        // TODO: move
        void outputEnumInfo(const EnumTypeInfo &info);

        std::shared_ptr<llvm::raw_fd_ostream> outStream;
    };


    class ASTAction : public clang::ASTFrontendAction {
    public:
        explicit ASTAction(std::shared_ptr<llvm::raw_fd_ostream> oStream) : outStream{std::move(oStream)} {}

        std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &Compiler, llvm::StringRef InFile) override {
            return std::make_unique<ASTConsumer>(outStream);
        };

    private:
        std::shared_ptr<llvm::raw_fd_ostream> outStream;
    };

    class ActionFactory : public clang::tooling::FrontendActionFactory {
    public:
        explicit ActionFactory(std::shared_ptr<llvm::raw_fd_ostream> oStream) : outStream{std::move(oStream)} {}

        std::unique_ptr<clang::FrontendAction> create() override { return std::make_unique<ASTAction>(outStream); }

    private:
        std::shared_ptr<llvm::raw_fd_ostream> outStream;
    };
}// namespace pf::meta_gen

#endif//PF_META_GEN_ASTACTIONS_H
