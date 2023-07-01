//
// Created by xflajs00 on 17.03.2023.
//

#pragma once

namespace speculo::gen::templates {

    constexpr auto GetTypeID = R"fmt(
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
template<>
[[nodiscard]] consteval ID getTypeId<volatile {type}>() {{
    return {volatile_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<volatile const {type}>() {{
    return {volatile_const_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<volatile {type} &>() {{
    return {volatile_lref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<volatile {type} &&>() {{
    return {volatile_rref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<volatile const {type} &>() {{
    return {volatile_const_lref_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<volatile {type} *>() {{
    return {volatile_ptr_type_id};
}}
template<>
[[nodiscard]] consteval ID getTypeId<volatile const {type} *>() {{
    return {volatile_const_ptr_type_id};
}}
)fmt";

}
