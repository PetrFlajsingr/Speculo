//
// Created by xflajs00 on 08.03.2023.
//

#ifndef PF_META_INFO_H
#define PF_META_INFO_H

#include "details/ID.hpp"

namespace pf::meta {

    struct Info {
        constexpr Info() : implId{0x0u, 0x0u} {}
        constexpr explicit(false) Info(details::ID id) : implId{id} {}

        details::ID implId;
    };

}// namespace pf::meta

#endif//PF_META_INFO_H
