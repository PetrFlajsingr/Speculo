//
// Created by xflajs00 on 18.03.2023.
//

#pragma once

#include <variant>
#include <vector>

#include "IdGenerator.hpp"
#include "SourceConfig.hpp"
#include "clang_tooling_wrap.hpp"
#include "info_structs.hpp"

namespace pf::meta_gen {

    class ASTParser {
    public:
        ASTParser(const SourceConfig *c, std::shared_ptr<IdGenerator> idGen);

        [[nodiscard]] std::vector<TypeInfoVariant> parse(clang::ASTContext &astContext);

    private:
        [[nodiscard]] std::vector<TypeInfoVariant> walk(clang::ASTContext &astContext, const clang::DeclContext &context);

        const SourceConfig *config;
        std::shared_ptr<IdGenerator> idGenerator;
    };

}// namespace pf::meta_gen