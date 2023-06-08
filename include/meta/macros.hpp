/**
 * @file macros.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#define PF_META_COMBINE_MACRO4_INNER(x, y, z, w) x##y##z##w
#define PF_META_COMBINE_MACRO4(x, y, z, w) PF_META_COMBINE_MACRO4_INNER(x, y, z, w)


#ifdef PF_META_GENERATOR_RUNNING
#define PF_META_GENERATED()
#define PF_META_GENERATED_HEADER()
#else
#define PF_META_GENERATED() PF_META_COMBINE_MACRO4(PF_META_GENERATED_, __LINE__, _, PF_META_GENERATED_FILE_ID);
#endif
