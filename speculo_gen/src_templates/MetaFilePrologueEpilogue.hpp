//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

namespace speculo::gen::templates {

    constexpr auto MetaFilePrologue = R"fmt(
#pragma once

#include "{relative_include_path}"
import speculo;
#include <cstdint>
#include <cstddef>
#include <string_view>
#include <span>
#include <array>

namespace speculo::details {{
)fmt";
    constexpr auto MetaFileEpilogue = R"fmt(
}
)fmt";

}// namespace speculo::gen::templates
