//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

namespace pf::meta_gen {

    constexpr auto GetTypeIDTemplate = R"fmt(
/****************************** {full_name} START ******************************/
template<>
[[nodiscard]] consteval ID getTypeId<{type}>() {{
    return {type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<const {type}>() {{
    return {const_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<{type} &>() {{
    return {lref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<{type} &&>() {{
    return {rref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<const {type} &>() {{
    return {const_lref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<{type} *>() {{
    return {ptr_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<const {type} *>() {{
    return {const_ptr_type_id};
}}
/****************************** {full_name} END ******************************/
)fmt";

}

