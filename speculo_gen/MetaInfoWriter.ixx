module;

#include <algorithm>
#include <ostream>
#include <string_view>
#include <vector>

export module speculo.gen:meta_info_writer;
import :id_generator;
import speculo;

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
