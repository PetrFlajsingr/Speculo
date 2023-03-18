//
// Created by xflajs00 on 18.03.2023.
//

#pragma once

#include <vector>
#include <variant>

#include "info_structs.h"
#include "ParsingSettings.h"
#include "clang_tooling_wrap.h"

namespace pf::meta_gen {
    using TypeInfoVariant = std::variant<EnumTypeInfo>;

    class ASTDeclParser {
        public:
            ASTDeclParser() = default;
            virtual ~ASTDeclParser() = 0;

            [[nodiscard]] virtual std::optional<TypeInfoVariant> parse(clang::ASTContext &astContext, clang::Decl *decl) = 0;
    };

    class ASTEnumDeclParser final : public ASTDeclParser {
        public:
            ASTEnumDeclParser();
            ~ASTEnumDeclParser() override = default;

            std::optional<TypeInfoVariant> parse(clang::ASTContext &astContext, clang::Decl *decl) override;
    };

    [[nodiscard]] std::unique_ptr<ASTDeclParser> createDeclParser(clang::Decl *decl);

    class ASTParser {
    public:
        explicit ASTParser(ParsingSettings parsingSettings);
        [[nodiscard]] std::vector<TypeInfoVariant> parse(clang::ASTContext &astContext);

    private:
        [[nodiscard]] std::vector<TypeInfoVariant> walk(clang::ASTContext &astContext, const clang::DeclContext &context);

        ParsingSettings settings;
    };

}// namespace pf::meta_gen
