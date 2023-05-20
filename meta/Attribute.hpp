//
// Created by xflajs00 on 15.03.2023.
//

#ifndef PF_META_ATTRIBUTE_H
#define PF_META_ATTRIBUTE_H

#include <span>
#include <string_view>

namespace pf::meta {

    struct Attribute {
        constexpr Attribute(std::string_view ns, std::string_view n, std::span<const std::string_view> args)
            : nnamespace{ns}, name{n}, arguments{args} {}

        std::string_view nnamespace;
        std::string_view name;
        std::span<const std::string_view> arguments;
    };

}// namespace pf::meta

#endif//PF_META_ATTRIBUTE_H
