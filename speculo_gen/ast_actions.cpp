module;

#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <clang/AST/ASTContext.h>
#include <filesystem>
#include <variant>

module speculo.gen;
import :algorithms;
import :ast_actions;
import :ast_parser;
import :meta_info_writer;
import :src_templates;
import :clang_utils;

namespace speculo::gen {

    void ASTConsumer::HandleTranslationUnit(clang::ASTContext &context) {
        using namespace fmt::literals;

        ASTParser astParser{config, idGenerator,
                            std::make_shared<AttributeParser>(context,
                                                              std::move(parent->getTokenCollector()).consume())};
        auto infos = astParser.parse(context);

        if (config->runType == RunType::Codegen) {
            auto outputsOpt = openOutputs();
            if (!outputsOpt.has_value()) { return; }
            auto outputs = std::move(*outputsOpt);

            PluginManager pluginManager{std::filesystem::current_path() / "plugins"};

            spdlog::trace("Writing generated code to {} and {}", config->outputCodegenHeader.string(),
                          config->outputCodegenSource.string());


            outputs.hpp << fmt::format("\n#undef SPECULO_GENERATED_FILE_ID\n#define SPECULO_GENERATED_FILE_ID {}\n",
                                       outputs.hppUUID);

            auto generatedMacros = initGeneratedMacros(infos, outputs.hppUUID);

            std::string headerMacroBody{};

            const auto codeGenerators = createCodeGenerators(pluginManager);

            outputs.cpp << fmt::format("#include \"{}\"\n", config->outputCodegenHeader.filename().string());

            for (auto &codeGenerator: codeGenerators) {
                auto additional = runCodeGenerator(*codeGenerator, outputs, infos);
                headerMacroBody.append(additional.headerMacro);
                for (const auto &[rec, contents]: additional.recordMacro) {
                    if (const auto iter = generatedMacros.find(rec); iter != generatedMacros.end()) {
                        iter->second.contents.append(contents);
                    }
                }
                infos.reserve(infos.size() + additional.types.size());
                std::ranges::move(additional.types, std::back_inserter(infos));
                outputs.hpp << additional.hppCode;
                outputs.cpp << additional.cppCode;
            }


            outputs.hpp
                    << fmt::format("\n#define SPECULO_GENERATED_HEADER_{} {}\n\n", outputs.hppUUID, headerMacroBody);

            // write SPECULO_GENERATED macro definitions
            std::ranges::for_each(generatedMacros, [&](const auto &m) {
                const auto &[macroName, macroBody] = m.second;
                const auto macro = fmt::format(R"(#define {} {})", macroName, macroBody);
                outputs.hpp << macro << "\n\n";
            });
        } else if (config->runType == RunType::Metagen) {
            writeMetaInfo(infos);
        } else {
            assert(false);
        }
    }

    void ASTConsumer::writeMetaInfo(const std::vector<TypeInfoVariant> &infos) {
        using namespace fmt::literals;
        spdlog::trace("Writing meta info to {}", config->outputMetaHeader.string());

        std::ofstream outStream;
        outStream.exceptions(std::ofstream::failbit | std::ofstream::badbit);

        try {
            outStream.open(config->outputMetaHeader);
        } catch (const std::system_error &e) {
            spdlog::error("Failed to open output file: {}", e.code().message());
            return;
        }

        auto metaWriter = MetaInfoWriter{outStream, idGenerator};
        metaWriter.write(fmt::format(templates::MetaFilePrologue,
                                     "relative_include_path"_a = fmt::format("../{}",
                                                                             config->inputProjectPath.filename().string())));
        for (const auto &info: infos) { metaWriter.write(info); }
        metaWriter.write(templates::MetaFileEpilogue);
    }

    std::optional<ASTConsumer::OutStreams> ASTConsumer::openOutputs() {
        std::ofstream outStreamHpp;
        outStreamHpp.exceptions(std::ofstream::failbit | std::ofstream::badbit);

        try {
            outStreamHpp.open(config->outputCodegenHeader);
        } catch (const std::system_error &e) {
            spdlog::error("Failed to open output file: {}", e.code().message());
            return std::nullopt;
        }
        std::ofstream outStreamCpp;
        outStreamCpp.exceptions(std::ofstream::failbit | std::ofstream::badbit);

        try {
            outStreamCpp.open(config->outputCodegenSource);
        } catch (const std::system_error &e) {
            spdlog::error("Failed to open output file: {}", e.code().message());
            return std::nullopt;
        }

        // TODO: use absolute paths
        uuids::uuid_name_generator uuidGenerator{uuids::uuid::from_string(FileUUIDSeed).value()};
        const auto hppFileUUID = uuidGenerator(
                std::filesystem::relative(config->outputCodegenHeader, config->projectRootDir).string());
        auto hppFileUUIDstr = to_string(hppFileUUID);
        std::ranges::replace(hppFileUUIDstr, '-', '_');
        const auto cppFileUUID = uuidGenerator(
                std::filesystem::relative(config->outputCodegenSource, config->projectRootDir).string());
        auto cppFileUUIDstr = to_string(cppFileUUID);
        std::ranges::replace(cppFileUUIDstr, '-', '_');

        return OutStreams{std::move(outStreamHpp), std::move(hppFileUUIDstr), std::move(outStreamCpp),
                          std::move(cppFileUUIDstr)};
    }

    std::unordered_map<const RecordTypeInfo *, ASTConsumer::RecordGenMacro>
    ASTConsumer::initGeneratedMacros(const std::vector<TypeInfoVariant> &infos, std::string_view hppUUID) {
        using namespace fmt::literals;

        constexpr auto generatedMacroNameTemplate = R"(SPECULO_GENERATED_{line}_{file_id})";
        // macro name, macro body
        std::unordered_map<const RecordTypeInfo *, RecordGenMacro> generatedMacros;
        // prepare generated macro map
        std::ranges::for_each(infos, [&](const auto &info) {
            std::visit(Visitor{[&](const RecordTypeInfo &recordInfo) {
                           if (!recordInfo.hasSpeculoGeneratedMacro) { return; }
                           std::size_t generatedMacroLineOffset{};
                           const auto codeWithoutCommentsAndStrings = removeCommentsAndStrings(recordInfo.originalCode, true);
                           if (const auto pos = codeWithoutCommentsAndStrings.find("SPECULO_GENERATED()");
                                   pos != std::string::npos) {
                               for (auto i = 0ull; i < pos; ++i) {
                                   if (codeWithoutCommentsAndStrings[i] == '\n') { ++generatedMacroLineOffset; }
                               }
                           }
                           assert(recordInfo.sourceLocation.has_value());
                           generatedMacroLineOffset += recordInfo.sourceLocation->line;
                           generatedMacros.emplace(&recordInfo, RecordGenMacro{fmt::format(generatedMacroNameTemplate,
                                                                                           "line"_a = generatedMacroLineOffset,
                                                                                           "file_id"_a = hppUUID),
                                                                               ""});
                       },
                               [&](const auto &) {}},
                       info);
        });
        return generatedMacros;
    }

    std::vector<CodeGenerator *> ASTConsumer::createCodeGenerators(PluginManager &pluginManager) {
        std::vector<CodeGenerator *> codeGenerators{&metaSupportCodeGenerator};
        std::ranges::copy(pluginManager.getCodeGenerators(), std::back_inserter(codeGenerators));
        std::ranges::sort(codeGenerators, {}, &CodeGenerator::getPriority);
        return codeGenerators;
    }

    ASTConsumer::AdditionalCodeGenCode ASTConsumer::runCodeGenerator(CodeGenerator &generator, OutStreams &outputs,
                                                                     std::vector<TypeInfoVariant> &infos) {
        AdditionalCodeGenCode result;

        generator.initialize(outputs.hppUUID, outputs.cppUUID,
                             fmt::format("../{}", config->inputProjectPath.filename().string()),
                             spdlog::default_logger());

        std::ranges::for_each(infos, [&](auto &info) {
            std::visit(Visitor{[&](RecordTypeInfo &recordInfo) {
                           auto genCode = generator.generate(recordInfo);
                           // add \ to new lines, because it's generated into a macro body
                           replaceAllOccurrences(genCode.typeBodyCode, "\n", "\\\n");
                           result.recordMacro.emplace(&recordInfo, genCode.typeBodyCode);

                           result.hppCode.append(genCode.hppCode);
                           result.cppCode.append(genCode.cppCode);
                           // add \ to new lines, because it's generated into a macro body
                           replaceAllOccurrences(genCode.headerBodyCode, "\n", "\\\n");
                           result.headerMacro.append(genCode.headerBodyCode);

                           result.types.reserve(result.types.size() + genCode.generatedTypes.size());
                           std::ranges::move(result.types, std::back_inserter(genCode.generatedTypes));
                       },
                               [&](const EnumTypeInfo &enumInfo) {
                                   auto genCode = generator.generate(enumInfo);
                                   result.hppCode.append(genCode.hppCode);
                                   result.cppCode.append(genCode.cppCode);
                                   // add \ to new lines, because it's generated into a macro body
                                   replaceAllOccurrences(genCode.headerBodyCode, "\n", "\\\n");
                                   result.headerMacro.append(genCode.headerBodyCode);

                                   result.types.reserve(result.types.size() + genCode.generatedTypes.size());
                                   std::ranges::move(result.types, std::back_inserter(genCode.generatedTypes));
                               },
                               // no action for incomplete types
                               [](const IncompleteTypeInfo &) {},
                               // no action for fundamental types
                               [](const FundamentalTypeInfo &) {}},
                       info);
        });

        auto prolEpiData = generator.getPrologueEpilogue();
        result.hppCode = prolEpiData.hppPrologue + result.hppCode + prolEpiData.hppEpilogue;
        result.cppCode = prolEpiData.cppPrologue + result.cppCode + prolEpiData.cppEpilogue;
        // add \ to new lines, because it's generated into a macro body
        replaceAllOccurrences(prolEpiData.headerBodyPrologue, "\n", "\\\n");
        replaceAllOccurrences(prolEpiData.headerBodyEpilogue, "\n", "\\\n");
        result.headerMacro = prolEpiData.headerBodyPrologue + result.headerMacro + prolEpiData.headerBodyEpilogue;
        return result;
    }


}// namespace speculo::gen