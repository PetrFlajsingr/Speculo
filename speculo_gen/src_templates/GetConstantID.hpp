//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

namespace speculo::gen::templates {

    constexpr auto GetConstantID = R"fmt(
template<>
[[nodiscard]] consteval ID getConstantId<{constant}>() {{
return {value_id};
}}
)fmt";

}
