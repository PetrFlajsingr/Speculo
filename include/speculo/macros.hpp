/**
 * @file macros.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#define SPECULO_COMBINE_MACRO4_INNER(x, y, z, w) x##y##z##w
#define SPECULO_COMBINE_MACRO4(x, y, z, w) SPECULO_COMBINE_MACRO4_INNER(x, y, z, w)


#ifdef SPECULO_GENERATOR_RUNNING
#define SPECULO_GENERATED()
#define SPECULO_GENERATED_HEADER()
#else
#define SPECULO_GENERATED() SPECULO_COMBINE_MACRO4(SPECULO_GENERATED_, __LINE__, _, SPECULO_GENERATED_FILE_ID)
#endif
