//
// Created by xflajs00 on 15.03.2023.
//

#ifndef PF_META_ATTRIBUTE_H
#define PF_META_ATTRIBUTE_H

#include <string_view>
#include <span>

namespace pf::meta {

    struct Attribute {
        constexpr Attribute(std::string_view n, std::span<const std::string_view> args)
                : name{n}, arguments{args} {}

        std::string_view name;
        std::span<const std::string_view> arguments;
    };

}

#endif //PF_META_ATTRIBUTE_H
