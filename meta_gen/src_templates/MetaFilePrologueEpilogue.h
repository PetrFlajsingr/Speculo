//
// Created by xflajs00 on 17.03.2023.
//

#ifndef PF_META_GEN_METAFILEPROLOGUEEPILOGUE_H
#define PF_META_GEN_METAFILEPROLOGUEEPILOGUE_H

namespace pf::meta_gen {

    constexpr auto MetaFilePrologue = R"fmt(
#pragma once

#include <{file_include}>
#include <meta/details/array.h>
#include <meta/details/RangeOf.h>
#include <type_traits>
#include <meta/details/StaticInfo.h>
#include <meta/details/StaticInfo_Wrappers.h>
#include <meta/details/ID.h>
#include <meta/Attribute.h>
#include <meta/Info.h>

namespace pf::meta::details {{
)fmt";
    constexpr auto MetaFileEpilogue = R"fmt(
}
)fmt";

}// namespace pf::meta_gen

#endif//PF_META_GEN_METAFILEPROLOGUEEPILOGUE_H
