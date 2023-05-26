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

        /* const auto tokens = std::move(parent->getTokenCollector()).consume();
        for (const auto &t : tokens.expandedTokens()) {
            if (!parent->getCompilerInstance().getSourceManager().isInMainFile(t.location())) { continue; }
            std::cout << std::string{t.text(parent->getCompilerInstance().getSourceManager())} << " ";
        }
        std::cout.flush();*/

        ASTParser astParser{config, idGenerator,
                            std::make_shared<AttributeParser>(context, std::move(parent->getTokenCollector()).consume())};
        const auto infos = astParser.parse(context);
        spdlog::info("Writing meta info to {}", config->outputMetaHeader.string());
        metaWriter.write(fmt::format(MetaFilePrologue, "file_include"_a = config->inputIncludePath));
        for (const auto &info: infos) { metaWriter.write(info); }
        metaWriter.write(MetaFileEpilogue);

        spdlog::info("Writing generated code to {} and {}", config->outputCodegenHeader.string(), config->outputCodegenSource.string());

        codeGenWriter.start(std::filesystem::relative(config->outputCodegenHeader, config->projectRootDir).string());
        codeGenWriter.generate(infos);
        codeGenWriter.end();
    }


}// namespace pf::meta_gen