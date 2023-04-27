/**
 * @file CodeGenWriter.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <llvm/Support/raw_ostream.h>

#include "info_structs.hpp"
#include <fmt/format.h>
#include <pf_common/concepts/ranges.h>

namespace pf::meta_gen {

    // TODO: custom generators
    class CodeGenWriter {
    public:
        explicit CodeGenWriter(std::shared_ptr<llvm::raw_ostream> os) : ostream{std::move(os)} {}

        void start(std::string_view fileName);
        void end();

        void generate(RangeOf<TypeInfoVariant> auto &&typeInfos) {
            std::ranges::for_each(std::forward<decltype(typeInfos)>(typeInfos), [this](auto &&typeInfo) { generate(typeInfo); });
        }

        void generate(const TypeInfoVariant &typeInfo);

    private:
        void write(std::string_view str);

        std::shared_ptr<llvm::raw_ostream> ostream;

        std::string fileUUIDstr;
    };

}// namespace pf::meta_gen
