//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

namespace pf::meta_gen {

    constexpr auto MetaFilePrologue = R"fmt(
#pragma once

#include <{file_include}>
#include <meta/details/array.hpp>
#include <meta/details/RangeOf.hpp>
#include <type_traits>
#include <meta/details/StaticInfo.hpp>
#include <meta/details/StaticInfo_Wrappers.hpp>
#include <meta/details/ID.hpp>
#include <meta/Attribute.hpp>
#include <meta/Info.hpp>

namespace pf::meta::details {{
)fmt";
    constexpr auto MetaFileEpilogue = R"fmt(
}
)fmt";

}// namespace pf::meta_gen
