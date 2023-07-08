//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

namespace speculo::gen::templates {

    constexpr auto MetaFilePrologue = R"fmt(
#pragma once

#include "{relative_include_path}"
#include <speculo/details/array.hpp>
#include <speculo/details/RangeOf.hpp>
#include <type_traits>
#include <speculo/details/StaticInfo.hpp>
#include <speculo/details/StaticInfo_Wrappers.hpp>
#include <speculo/ID.hpp>
#include <speculo/Attribute.hpp>
#include <speculo/Info.hpp>

namespace speculo::details {{
)fmt";
    constexpr auto MetaFileEpilogue = R"fmt(
}
)fmt";

}// namespace speculo::gen::templates
