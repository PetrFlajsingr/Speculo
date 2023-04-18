
#include "CodeGenWriter.hpp"

namespace pf::meta_gen {

    void CodeGenWriter::generate(const meta_gen::TypeInfoVariant &typeInfo) {

    }

    void CodeGenWriter::write(std::string_view str) { *ostream << str; }

}// namespace pf::meta_gen