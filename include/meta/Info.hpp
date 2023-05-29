//
// Created by xflajs00 on 08.03.2023.
//

#pragma once

#include <meta/details/ID.hpp>

namespace pf::meta {

    struct Info {
        constexpr Info() : implId{0x0u, 0x0u} {}
        constexpr explicit(false) Info(details::ID id) : implId{id} {}

        details::ID implId;
    };

}// namespace pf::meta
