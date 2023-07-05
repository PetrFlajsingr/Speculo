//
// Created by xflajs00 on 15.03.2023.
//

#pragma once

#include <speculo/ID.hpp>
#include <speculo/Info.hpp>
#include <speculo/details/ReflectInfoProviders.hpp>
#include <speculo/details/SpliceResultProviders.hpp>
#include <speculo/details/StaticInfo.hpp>

#define SPECULO_REFLECT(X) ::speculo::details::provideReflectInfo<X>().Result

#define SPECULO_SPLICE(I) ::speculo::details::SpliceResultProvider<I>::Result
