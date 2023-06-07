//
// Created by xflajs00 on 15.03.2023.
//

#pragma once

#include <meta/ID.hpp>
#include <meta/Info.hpp>
#include <meta/details/ReflectInfoProviders.hpp>
#include <meta/details/SpliceResultProviders.hpp>
#include <meta/details/StaticInfo.hpp>

#define PF_REFLECT(X) ::pf::meta::details::provideReflectInfo<X>().Result

#define PF_SPLICE(I) ::pf::meta::details::SpliceResultProvider<I>::Result
