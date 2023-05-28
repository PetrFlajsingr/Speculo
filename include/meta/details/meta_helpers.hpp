//
// Created by xflajs00 on 15.03.2023.
//

#ifndef PF_META_DETAILS_META_HELPERS_H
#define PF_META_DETAILS_META_HELPERS_H

namespace pf::meta::details {

    template<auto...>
    constexpr bool AlwaysFalseV = false;
    template<typename...>
    constexpr bool AlwaysFalseT = false;

}// namespace pf::meta::details

#endif//PF_META_DETAILS_META_HELPERS_H
