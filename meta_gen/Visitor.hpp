/**
 * @file Visitor.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

namespace pf::meta_gen {

    template<typename... Ts>
    struct Visitor : Ts... {
        using Ts::operator()...;
    };
    template<typename... Ts>
    Visitor(Ts...) -> Visitor<Ts...>;

}// namespace pf::meta_gen