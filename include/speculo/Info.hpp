//
// Created by xflajs00 on 08.03.2023.
//

#pragma once

#include <speculo/ID.hpp>

namespace speculo {

    struct Info {
        constexpr Info() : id{0x0u, 0x0u} {}
        constexpr explicit(false) Info(ID i) : id{i} {}

        ID id;
    };

}// namespace speculo
