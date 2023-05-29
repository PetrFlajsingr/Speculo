//
// Created by xflajs00 on 15.03.2023.
//

#pragma once

namespace pf::meta::details {

    template<auto...>
    constexpr bool AlwaysFalseV = false;
    template<typename...>
    constexpr bool AlwaysFalseT = false;

}// namespace pf::meta::details
