//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

namespace pf::meta_gen {

    constexpr auto GetConstantIDTemplate = R"fmt(
template<>
[[nodiscard]] consteval ID getConstantId<{constant}>() {{
return {value_id};
}}
)fmt";

}
