//
// Created by xflajs00 on 18.03.2023.
//

#include "AstActions.hpp"
#include "ASTParser.hpp"
#include "StringReplace.hpp"
#include "codegen/PluginManager.hpp"
#include "src_templates/MetaFilePrologueEpilogue.hpp"
#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include <fstream>

namespace pf::meta_gen {

    void ASTConsumer::HandleTranslationUnit(clang::ASTContext &context) {
        using namespace fmt::literals;

        ASTParser astParser{config, idGenerator,
                            std::make_shared<AttributeParser>(context, std::move(parent->getTokenCollector()).consume())};
        const auto infos = astParser.parse(context);

        {
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
            metaWriter.write(fmt::format(MetaFilePrologue,
                                         "relative_include_path"_a = fmt::format("../{}", config->inputProjectPath.filename().string())));
            for (const auto &info: infos) { metaWriter.write(info); }
            metaWriter.write(MetaFileEpilogue);
        }

        {

            std::ofstream outStreamHpp;
            outStreamHpp.exceptions(std::ofstream::failbit | std::ofstream::badbit);

            try {
                outStreamHpp.open(config->outputCodegenHeader);
            } catch (const std::system_error &e) {
                spdlog::error("Failed to open output file: {}", e.code().message());
                return;
            }
            std::ofstream outStreamCpp;
            outStreamCpp.exceptions(std::ofstream::failbit | std::ofstream::badbit);

            try {
                outStreamCpp.open(config->outputCodegenSource);
            } catch (const std::system_error &e) {
                spdlog::error("Failed to open output file: {}", e.code().message());
                return;
            }

            std::error_code errorCode;
            auto codeGenOutStream = std::make_shared<llvm::raw_fd_ostream>(config->outputCodegenHeader.string(), errorCode,
                                                                           llvm::sys::fs::OpenFlags::OF_Text);
            if (errorCode) {
                spdlog::error("Failed to open output file: {}", errorCode.message());
                return;
            }
            PluginManager pluginManager{std::filesystem::current_path() / "plugins"};

            spdlog::trace("Writing generated code to {} and {}", config->outputCodegenHeader.string(),
                          config->outputCodegenSource.string());

            // TODO: use absolute paths
            uuids::uuid_name_generator uuidGenerator{uuids::uuid::from_string("471F3823-2574-4bfd-b411-99ed177d3e43").value()};
            const auto hppFileUUID = uuidGenerator(std::filesystem::relative(config->outputCodegenHeader, config->projectRootDir).string());
            auto hppFileUUIDstr = to_string(hppFileUUID);
            std::ranges::replace(hppFileUUIDstr, '-', '_');
            const auto cppFileUUID = uuidGenerator(std::filesystem::relative(config->outputCodegenSource, config->projectRootDir).string());
            auto cppFileUUIDstr = to_string(cppFileUUID);
            std::ranges::replace(cppFileUUIDstr, '-', '_');


            outStreamHpp << fmt::format(R"(
#undef PF_META_GENERATED_FILE_ID
#define PF_META_GENERATED_FILE_ID {}
)",
                                        hppFileUUIDstr);

            constexpr auto generatedMacroNameTemplate = R"(PF_META_GENERATED_{line}_{file_id})";

            // macro name, macro body
            std::unordered_map<const RecordTypeInfo *, std::pair<std::string, std::string>> generatedMacros;
            // prepare generated macro map
            std::ranges::for_each(infos, [&](const auto &info) {
                std::visit(Visitor{[&](const std::shared_ptr<RecordTypeInfo> &info) {
                                       if (!info->hasPfMetaGeneratedMacro) { return; }
                                       std::size_t generatedMacroLineOffset{};
                                       if (const auto pos = info->originalCode.find("PF_META_GENERATED()"); pos != std::string::npos) {
                                           for (auto i = 0; i < pos; ++i) {
                                               if (info->originalCode[i] == '\n') { ++generatedMacroLineOffset; }
                                           }
                                       }
                                       generatedMacroLineOffset += info->sourceLocation.line;
                                       generatedMacros.emplace(info.get(), std::pair<std::string, std::string>{
                                                                                   fmt::format(generatedMacroNameTemplate,
                                                                                               "line"_a = generatedMacroLineOffset,
                                                                                               "file_id"_a = hppFileUUIDstr),
                                                                                   ""});
                                   },
                                   [&](const auto &) {}},
                           info);
            });

            std::string headerMacroBody{};

            auto metaCodeGen = MetaSupportCodeGenerator{};

            std::vector<CodeGenerator *> codeGenerators{&metaCodeGen};
            std::ranges::copy(pluginManager.getCodeGenerators(), std::back_inserter(codeGenerators));
            std::ranges::sort(codeGenerators, {}, &CodeGenerator::getPriority);

            outStreamCpp << fmt::format(R"(#include "{}"

)",
                                        config->outputCodegenHeader.filename().string());

            std::ranges::for_each(codeGenerators, [&](auto codeGenerator) {
                codeGenerator->initialize(hppFileUUIDstr, cppFileUUIDstr,
                                          fmt::format("../{}", config->inputProjectPath.filename().string()), spdlog::default_logger());

                auto startData = codeGenerator->start();
                outStreamHpp << startData.hppCode;
                outStreamCpp << startData.cppCode;
                // add \ to new lines, because it's generated into a macro body
                replaceAllOccurrences(startData.headerBodyCode, "\n", "\\\n");
                headerMacroBody.append(startData.headerBodyCode);

                std::ranges::for_each(infos, [&](const auto &info) {
                    std::visit(Visitor{[&](const std::shared_ptr<RecordTypeInfo> &info) {
                                           auto genCode = codeGenerator->generate(*info);
                                           if (const auto iter = generatedMacros.find(info.get()); iter != generatedMacros.end()) {
                                               // add \ to new lines, because it's generated into a macro body
                                               replaceAllOccurrences(genCode.typeBodyCode, "\n", "\\\n");
                                               iter->second.second.append(genCode.typeBodyCode);
                                           }
                                           outStreamHpp << genCode.hppCode;
                                           outStreamCpp << genCode.cppCode;
                                           // add \ to new lines, because it's generated into a macro body
                                           replaceAllOccurrences(genCode.headerBodyCode, "\n", "\\\n");
                                           headerMacroBody.append(genCode.headerBodyCode);
                                       },
                                       [&](const std::shared_ptr<EnumTypeInfo> &info) {
                                           auto genCode = codeGenerator->generate(*info);
                                           outStreamHpp << genCode.hppCode;
                                           outStreamCpp << genCode.cppCode;
                                           // add \ to new lines, because it's generated into a macro body
                                           replaceAllOccurrences(genCode.headerBodyCode, "\n", "\\\n");
                                           headerMacroBody.append(genCode.headerBodyCode);
                                       }},
                               info);
                });

                auto endData = codeGenerator->end();
                outStreamHpp << endData.hppCode;
                outStreamCpp << endData.cppCode;
                // add \ to new lines, because it's generated into a macro body
                replaceAllOccurrences(endData.headerBodyCode, "\n", "\\\n");
                headerMacroBody.append(endData.headerBodyCode);
            });

            outStreamHpp << fmt::format(R"(#undef PF_META_GENERATED_HEADER
#define PF_META_GENERATED_HEADER() {}

)",
                                        headerMacroBody);

            // write PF_META_GENERATED macro definitions
            std::ranges::for_each(generatedMacros, [&](const auto &m) {
                const auto &macroName = m.second.first;
                const auto &macroBody = m.second.second;
                const auto macro = fmt::format(R"(#define {} {})", macroName, macroBody);
                outStreamHpp << macro << "\n\n";
            });
        }
    }


}// namespace pf::meta_gen