//
// Created by xflajs00 on 15.03.2023.
//

#ifndef PF_META_REFLECT_H
#define PF_META_REFLECT_H

#include "Info.hpp"
#include "details/ID.hpp"
#include "details/ReflectInfoProviders.hpp"
#include "details/SpliceResultProviders.hpp"
#include "details/StaticInfo.hpp"


#define PF_REFLECT(X) ::pf::meta::details::provideReflectInfo<X>().Result

#define PF_SPLICE(I) ::pf::meta::details::SpliceResultProvider<I>::Result

#endif//PF_META_REFLECT_H
