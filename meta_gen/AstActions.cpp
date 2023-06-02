//
// Created by xflajs00 on 18.03.2023.
//

#include "AstActions.hpp"
#include "ASTParser.hpp"
#include "src_templates/MetaFilePrologueEpilogue.hpp"
#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include <iostream>

namespace pf::meta_gen {

    void ASTConsumer::HandleTranslationUnit(clang::ASTContext &context) {
        using namespace fmt::literals;

        ASTParser astParser{config, idGenerator,
                            std::make_shared<AttributeParser>(context, std::move(parent->getTokenCollector()).consume())};
        const auto infos = astParser.parse(context);

        {
            spdlog::trace("Writing meta info to {}", config->outputMetaHeader.string());
            std::error_code errorCode;
            auto metaOutStream =
                    std::make_shared<llvm::raw_fd_ostream>(config->outputMetaHeader.string(), errorCode, llvm::sys::fs::OpenFlags::OF_Text);
            if (errorCode) {
                spdlog::error("Failed to open output file: {}", errorCode.message());
                return;
            }
            auto metaWriter = MetaInfoWriter{metaOutStream, idGenerator};
            metaWriter.write(fmt::format(MetaFilePrologue,
                                         "relative_include_path"_a = fmt::format("../{}", config->inputProjectPath.filename().string())));
            for (const auto &info: infos) { metaWriter.write(info); }
            metaWriter.write(MetaFileEpilogue);
        }

        {
            std::error_code errorCode;
            auto codeGenOutStream = std::make_shared<llvm::raw_fd_ostream>(config->outputCodegenHeader.string(), errorCode,
                                                                           llvm::sys::fs::OpenFlags::OF_Text);
            if (errorCode) {
                spdlog::error("Failed to open output file: {}", errorCode.message());
                return;
            }
            spdlog::trace("Writing generated code to {} and {}", config->outputCodegenHeader.string(),
                          config->outputCodegenSource.string());
            auto codeGenWriter = CodeGenWriter{codeGenOutStream};
            codeGenWriter.start(std::filesystem::relative(config->outputCodegenHeader, config->projectRootDir).string());
            codeGenWriter.generate(infos);
            codeGenWriter.end();
        }
    }


}// namespace pf::meta_gen