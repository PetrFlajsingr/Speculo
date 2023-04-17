//
// Created by xflajs00 on 17.03.2023.
//

#ifndef PF_META_GEN_CLANG_TOOLING_COMPILATIONDATABASE_WRAP_H
#define PF_META_GEN_CLANG_TOOLING_COMPILATIONDATABASE_WRAP_H

#include <pf_common/macros.h>

#if PF_GCC == 1
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#endif

#include <clang/Tooling/CompilationDatabase.h>

#if PF_GCC == 1
#pragma GCC diagnostic pop
#endif

#endif//PF_META_GEN_CLANG_TOOLING_COMPILATIONDATABASE_WRAP_H
