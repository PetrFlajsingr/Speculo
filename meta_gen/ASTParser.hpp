//
// Created by xflajs00 on 18.03.2023.
//

#pragma once

#include <variant>
#include <vector>

#include "Config.hpp"
#include "IdGenerator.hpp"
#include "clang_tooling_wrap.hpp"
#include "info_structs.hpp"

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
