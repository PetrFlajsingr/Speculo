//
// Created by xflajs00 on 15.03.2023.
//

#ifndef PF_META_REFLECT_H
#define PF_META_REFLECT_H

#include "Info.h"
#include "details/ID.h"
#include "details/StaticInfo.h"

#define PF_REFLECT_TYPE(X)                                                                                                                 \
    ::pf::meta::Info { ::pf::meta::details::getTypeId<X>() }

#define PF_REFLECT_VALUE(V)                                                                                                                \
    ::pf::meta::Info { ::pf::meta::details::getConstantId<V>() }

#define PF_SPLICE_TYPE(I) ::pf::meta::details::StaticInfo<I.implId>::Type

#define PF_SPLICE_VALUE(I)                                                                                                                 \
    []<::pf::meta::Info i>() consteval {                                                                                                   \
        using impl = ::pf::meta::details::StaticInfo<i.implId>;                                                                        \
        return impl::Value;                                                                                                                \
    }.template operator()<I>()


#endif //PF_META_REFLECT_H
