//
// Created by xflajs00 on 18.03.2023.
//

#pragma once

#include <variant>
#include <vector>

#include "IdGenerator.h"
#include "ParsingSettings.h"
#include "clang_tooling_wrap.h"
#include "info_structs.h"

namespace pf::meta_gen {

    class ASTParser {
    public:
        ASTParser(ParsingSettings parsingSettings,
                  std::shared_ptr<IdGenerator> idGen);

        [[nodiscard]] std::vector<TypeInfoVariant> parse(clang::ASTContext &astContext);

    private:
        [[nodiscard]] std::vector<TypeInfoVariant>
        walk(clang::ASTContext &astContext, const clang::DeclContext &context);

        std::shared_ptr<IdGenerator> idGenerator;
        ParsingSettings settings;
    };

}// namespace pf::meta_gen
