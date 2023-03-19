//
// Created by xflajs00 on 19.03.2023.
//

#pragma once

#include "../IdGenerator.h"
#include "../clang_tooling_wrap.h"
#include "../info_structs.h"

#include <memory>
#include <optional>

namespace pf::meta_gen {

    class ASTDeclParser {
    public:
        explicit ASTDeclParser(std::shared_ptr<IdGenerator> idGen);
        virtual ~ASTDeclParser() = 0;

        [[nodiscard]] virtual std::optional<TypeInfoVariant> parse(clang::ASTContext &astContext, clang::Decl *decl) = 0;

    protected:
        [[nodiscard]] IdGenerator &getIdGenerator() { return *idGenerator; }

    private:
        std::shared_ptr<IdGenerator> idGenerator;
    };

}// namespace pf::meta_gen
