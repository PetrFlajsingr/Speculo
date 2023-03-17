//
// Created by xflajs00 on 17.03.2023.
//

#ifndef PF_META_GEN_GETCONSTANTID_TEMPLATE_H
#define PF_META_GEN_GETCONSTANTID_TEMPLATE_H

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

#endif //PF_META_GEN_GETCONSTANTID_TEMPLATE_H
