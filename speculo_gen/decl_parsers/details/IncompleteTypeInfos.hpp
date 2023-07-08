/// @file IncompleteTypeInfos.hpp
/// @brief
/// @author PetrFlajsingr

#pragma once

#include "../../IdGenerator.hpp"
#include "../../info_structs.hpp"

namespace speculo::gen {
    inline IncompleteTypeInfo getIncompleteTypeInfo(std::string_view typeName, IdGenerator &idGenerator) {
        IncompleteTypeInfo result;
        result.fullName = typeName;
        result.name = result.fullName;
        result.size = 0ull;
        result.alignment = 0ull;
        populateIDs(result, idGenerator);
        return result;
    }
}// namespace speculo::gen