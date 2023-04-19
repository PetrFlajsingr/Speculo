//
// Created by xflajs00 on 18.03.2023.
//

#include "AstActions.h"
#include "ASTParser.h"
#include "src_templates/MetaFilePrologueEpilogue.h"
#include <fmt/format.h>
#include <spdlog/spdlog.h>

namespace pf::meta_gen {

    void ASTConsumer::HandleTranslationUnit(clang::ASTContext &context) {
        using namespace fmt::literals;
        const auto infos = astParser.parse(context);
        spdlog::info("Writing meta info to {}", config->outputMetaHeader);
        metaWriter.write(fmt::format(MetaFilePrologue, "file_include"_a = config->inputIncludePath));
        for (const auto &info: infos) { metaWriter.write(info); }
        metaWriter.write(MetaFileEpilogue);

        spdlog::info("Writing generated code to {} and {}", config->outputCodegenHeader, config->outputCodegenSource);
        codeGenWriter.generate(infos);
    }


}// namespace pf::meta_gen