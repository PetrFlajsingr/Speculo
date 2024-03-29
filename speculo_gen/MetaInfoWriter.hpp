//
// Created by xflajs00 on 19.03.2023.
//

#pragma once

#include "IdGenerator.hpp"
#include "info_structs.hpp"
#include <algorithm>
#include <speculo/details/RangeOf.hpp>


namespace speculo::gen {

    class MetaInfoWriter {
    public:
        MetaInfoWriter(std::ostream &os, std::shared_ptr<IdGenerator> idGen);

        void write(std::string_view str);

        void write(speculo::RangeOf<TypeInfoVariant> auto &&typeInfos) {
            std::ranges::for_each(typeInfos, [this](auto &&typeInfo) { write(typeInfo); });
        }

        void write(const TypeInfoVariant &typeInfo);

    private:
        void writeEnumInfo(const EnumTypeInfo &enumInfo);
        void writeRecordInfo(const RecordTypeInfo &recordInfo);

        void writeEnumInfoSourceLocation(const EnumTypeInfo &enumInfo);


        [[nodiscard]] static std::string StringifyAttributes(const std::vector<Attribute> &attrs,
                                                             const std::vector<std::string> &argArrayNames);

        [[nodiscard]] static std::string CreateAttributeArgArray(std::string_view name, const Attribute &attr);

        [[nodiscard]] static bool ContainsNoSTIAttribute(const std::vector<Attribute> &attrs) {
            return std::ranges::any_of(attrs, [](const auto &attr) { return attr.nnamespace == "speculo" && attr.name == "no_sti"; });
        }

        std::shared_ptr<IdGenerator> idGenerator;
        std::ostream &ostream;
    };


}// namespace speculo::gen
