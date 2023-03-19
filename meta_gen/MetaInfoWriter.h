//
// Created by xflajs00 on 19.03.2023.
//

#pragma once

#include <llvm/Support/raw_ostream.h>

#include "IdGenerator.h"
#include "info_structs.h"
#include <pf_common/concepts/ranges.h>


namespace pf::meta_gen {

    class MetaInfoWriter {
    public:
        MetaInfoWriter(std::shared_ptr<llvm::raw_ostream> os, std::shared_ptr<IdGenerator> idGen);

        void write(std::string_view str);

        void write(RangeOf<TypeInfoVariant> auto &&typeInfos) {
            std::ranges::for_each(std::forward<decltype(typeInfos)>(typeInfos), [this](auto &&typeInfo) { write(typeInfo); });
        }
        void write(const TypeInfoVariant &typeInfo);

    private:
        void writeEnumInfo(const EnumTypeInfo &enumInfo);

        [[nodiscard]] static std::string StringifyAttributes(const std::vector<Attribute> &attrs, const std::vector<std::string> &argArrayNames);

        [[nodiscard]] static std::string CreateAttributeArgArray(std::string_view name, const Attribute &attr);

        std::shared_ptr<IdGenerator> idGenerator;
        std::shared_ptr<llvm::raw_ostream> ostream;
    };


}// namespace pf::meta_gen
