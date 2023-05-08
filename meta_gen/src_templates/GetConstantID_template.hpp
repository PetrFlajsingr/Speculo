//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

namespace pf::meta_gen {

    constexpr auto GetConstantIDTemplate = R"fmt(
/****************************** {full_name} START ******************************/
template<>
[[nodiscard]] consteval ID getConstantId<{constant}>() {{
return {value_id};
}}
/****************************** {full_name} END ******************************/
)fmt";

}
