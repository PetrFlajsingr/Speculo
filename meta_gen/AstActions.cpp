//
// Created by xflajs00 on 18.03.2023.
//

#include "AstActions.h"
#include "ASTParser.h"
#include "src_templates/MetaFilePrologueEpilogue.h"

namespace pf::meta_gen {

    void ASTConsumer::HandleTranslationUnit(clang::ASTContext &context) {
        const auto infos = astParser.parse(context);
        writer.write(MetaFilePrologue);
        for (const auto &info: infos) { writer.write(info); }
        writer.write(MetaFileEpilogue);
    }


}// namespace pf::meta_gen