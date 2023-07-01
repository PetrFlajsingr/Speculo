//
// Created by xflajs00 on 15.03.2023.
//

#pragma once

namespace speculo::details {

    template<auto...>
    constexpr bool AlwaysFalseV = false;
    template<typename...>
    constexpr bool AlwaysFalseT = false;

}// namespace speculo::details
