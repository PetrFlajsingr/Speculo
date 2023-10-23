module;

#include <fstream>
#include <memory>

#include "wrap/clang_frontend_compilerinstance.hpp"
#include "wrap/clang_tooling_syntax_tokens.hpp"
#include "wrap/clang_tooling.hpp"

export module speculo.gen:ast_actions;
import :codegen;
import :id_generator;
import :source_config;
import :structs;
import :plugin_manager;
import :meta_code_generator;


namespace speculo::gen {
    class ASTConsumer : public clang::ASTConsumer {
    public:
        ASTConsumer(const SourceConfig *c, std::shared_ptr<IdGenerator> idGen, class ASTAction *p)
                : config{c}, idGenerator{idGen}, parent{p} {}

        void HandleTranslationUnit(clang::ASTContext &context) override;

    private:
        void writeMetaInfo(const std::vector<TypeInfoVariant> &infos);

        struct RecordGenMacro {
            std::string name;
            std::string contents;
        };

        [[nodiscard]] std::unordered_map<const RecordTypeInfo *, RecordGenMacro>
        initGeneratedMacros(const std::vector<TypeInfoVariant> &infos, std::string_view hppUUID);

        struct OutStreams {
            std::ofstream hpp;
            std::string hppUUID;
            std::ofstream cpp;
            std::string cppUUID;
        };

        [[nodiscard]] std::optional<OutStreams> openOutputs();

        [[nodiscard]] std::vector<CodeGenerator *> createCodeGenerators(PluginManager &pluginManager);

        struct AdditionalCodeGenCode {
            std::string headerMacro;
            std::unordered_map<const RecordTypeInfo *, std::string> recordMacro;
            std::vector<TypeInfoVariant> types;
            std::string hppCode;
            std::string cppCode;
        };

        [[nodiscard]] AdditionalCodeGenCode runCodeGenerator(CodeGenerator &generator, OutStreams &outputs,
                                                             std::vector<TypeInfoVariant> &infos);

        const SourceConfig *config;
        std::shared_ptr<IdGenerator> idGenerator;

        class ASTAction *parent;

        MetaSupportCodeGenerator metaSupportCodeGenerator;

        constexpr static auto FileUUIDSeed = "471F3823-2574-4bfd-b411-99ed177d3e43";
    };


    class ASTAction : public clang::ASTFrontendAction {
    public:
        explicit ASTAction(const SourceConfig *c, std::shared_ptr<IdGenerator> idGen) : config{c},
                                                                                        idGenerator(std::move(idGen)) {}

        std::unique_ptr<clang::ASTConsumer>
        CreateASTConsumer(clang::CompilerInstance &Compiler, llvm::StringRef InFile) override {
            // Compiler.getDiagnostics().setClient(new SpdlogDiagnosticConsumer{});
            return std::make_unique<ASTConsumer>(config, idGenerator, this);
        };

        bool BeginSourceFileAction(clang::CompilerInstance &Compiler) override {
            tokenCollector = std::make_unique<clang::syntax::TokenCollector>(Compiler.getPreprocessor());
            Compiler.getLangOpts().CommentOpts.ParseAllComments = true;
            return true;
        }

        [[nodiscard]] clang::syntax::TokenCollector &getTokenCollector() { return *tokenCollector; }

        [[nodiscard]] const clang::syntax::TokenCollector &getTokenCollector() const { return *tokenCollector; }

    protected:
        void ExecuteAction() override { ASTFrontendAction::ExecuteAction(); }


    private:
        const SourceConfig *config;
        std::shared_ptr<IdGenerator> idGenerator;
        std::unique_ptr<clang::syntax::TokenCollector> tokenCollector{};
    };

    export class ActionFactory : public clang::tooling::FrontendActionFactory {
    public:
        explicit ActionFactory(const SourceConfig &c, std::shared_ptr<IdGenerator> idGen) : config{&c}, idGenerator(
                std::move(idGen)) {}

        std::unique_ptr<clang::FrontendAction> create() override {
            return std::make_unique<ASTAction>(config, idGenerator);
        }

    private:
        const SourceConfig *config;
        std::shared_ptr<IdGenerator> idGenerator;
    };


}// namespace speculo::gen
