//
// Created by xflajs00 on 18.03.2023.
//

#pragma once

#include <variant>
#include <vector>

#include "Config.h"
#include "IdGenerator.h"
#include "clang_tooling_wrap.h"
#include "info_structs.h"

namespace pf::meta_gen {

    class ASTParser {
    public:
        ASTParser(const Config *c, std::shared_ptr<IdGenerator> idGen);

        [[nodiscard]] std::vector<TypeInfoVariant> parse(clang::ASTContext &astContext);

    private:
        [[nodiscard]] std::vector<TypeInfoVariant> walk(clang::ASTContext &astContext, const clang::DeclContext &context);

        const Config *config;
        std::shared_ptr<IdGenerator> idGenerator;
    };

}// namespace pf::meta_gen
