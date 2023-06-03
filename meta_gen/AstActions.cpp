//
// Created by xflajs00 on 18.03.2023.
//

#include "AstActions.hpp"
#include "ASTParser.hpp"
#include "src_templates/MetaFilePrologueEpilogue.hpp"
#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include <fstream>
#include <iostream>

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

            auto metaCodeGen = MetaSupportCodeGenerator{};
            metaCodeGen.initialize(outStreamCpp, outStreamHpp, hppFileUUIDstr, cppFileUUIDstr);
            metaCodeGen.start();
            std::ranges::for_each(infos, [&](const auto &i) { metaCodeGen.handle(i); });
            metaCodeGen.end();
        }
    }


}// namespace pf::meta_gen