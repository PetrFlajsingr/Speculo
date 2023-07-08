/// @file FundamentalTypeInfos.hpp
/// @brief
/// @author PetrFlajsingr

#pragma once

#include <speculo/details/OneOf.hpp>

#include "../../IdGenerator.hpp"
#include "../../info_structs.hpp"

namespace speculo::gen {
    // TODO: move
    template<typename T>
    concept FundamentalType =
            speculo::OneOf<T, bool, char, signed char, unsigned char, char8_t, char16_t, char32_t, short, unsigned short, int, unsigned int,
                           long, unsigned long, long long, unsigned long long, float, double, long double, void, std::nullptr_t>;

    template<FundamentalType T>
    [[nodiscard]] FundamentalTypeInfo getFundamentalTypeInfo(IdGenerator &idGenerator);

    inline FundamentalTypeInfo getFundamentalTypeInfo(std::string_view fullTypeName, IdGenerator &idGenerator) {
        if (fullTypeName == "bool") {
            return getFundamentalTypeInfo<bool>(idGenerator);
        } else if (fullTypeName == "char") {
            return getFundamentalTypeInfo<char>(idGenerator);
        } else if (fullTypeName == "signed char") {
            return getFundamentalTypeInfo<signed char>(idGenerator);
        } else if (fullTypeName == "unsigned char") {
            return getFundamentalTypeInfo<unsigned char>(idGenerator);
        } else if (fullTypeName == "char8_t") {
            return getFundamentalTypeInfo<char8_t>(idGenerator);
        } else if (fullTypeName == "char16_t") {
            return getFundamentalTypeInfo<char16_t>(idGenerator);
        } else if (fullTypeName == "char32_t") {
            return getFundamentalTypeInfo<char32_t>(idGenerator);
        } else if (fullTypeName == "short") {
            return getFundamentalTypeInfo<short>(idGenerator);
        } else if (fullTypeName == "unsigned short") {
            return getFundamentalTypeInfo<unsigned short>(idGenerator);
        } else if (fullTypeName == "int") {
            return getFundamentalTypeInfo<int>(idGenerator);
        } else if (fullTypeName == "unsigned int") {
            return getFundamentalTypeInfo<unsigned int>(idGenerator);
        } else if (fullTypeName == "long") {
            return getFundamentalTypeInfo<long>(idGenerator);
        } else if (fullTypeName == "unsigned long") {
            return getFundamentalTypeInfo<unsigned long>(idGenerator);
        } else if (fullTypeName == "long long") {
            return getFundamentalTypeInfo<long long>(idGenerator);
        } else if (fullTypeName == "unsigned long long") {
            return getFundamentalTypeInfo<unsigned long long>(idGenerator);
        } else if (fullTypeName == "float") {
            return getFundamentalTypeInfo<float>(idGenerator);
        } else if (fullTypeName == "double") {
            return getFundamentalTypeInfo<double>(idGenerator);
        } else if (fullTypeName == "long double") {
            return getFundamentalTypeInfo<long double>(idGenerator);
        } else if (fullTypeName == "void") {
            return getFundamentalTypeInfo<void>(idGenerator);
        } else if (fullTypeName == "std::nullptr_t") {
            return getFundamentalTypeInfo<std::nullptr_t>(idGenerator);
        } else {
            assert(false && "Invalid fundamental type name provided");
            return {};
        }
    }


    template<FundamentalType T>
    FundamentalTypeInfo getFundamentalTypeInfo(IdGenerator &idGenerator) {
        FundamentalTypeInfo result;
        if constexpr (std::same_as<T, bool>) {
            result.fullName = result.name = "bool";
        } else if constexpr (std::same_as<T, char>) {
            result.fullName = result.name = "char";
        } else if constexpr (std::same_as<T, signed char>) {
            result.fullName = result.name = "signed char";
        } else if constexpr (std::same_as<T, unsigned char>) {
            result.fullName = result.name = "unsigned char";
        } else if constexpr (std::same_as<T, char8_t>) {
            result.fullName = result.name = "char8_t";
        } else if constexpr (std::same_as<T, char16_t>) {
            result.fullName = result.name = "char16_t";
        } else if constexpr (std::same_as<T, char32_t>) {
            result.fullName = result.name = "char32_t";
        } else if constexpr (std::same_as<T, short>) {
            result.fullName = result.name = "short";
        } else if constexpr (std::same_as<T, unsigned short>) {
            result.fullName = result.name = "unsigned short";
        } else if constexpr (std::same_as<T, int>) {
            result.fullName = result.name = "int";
        } else if constexpr (std::same_as<T, unsigned int>) {
            result.fullName = result.name = "unsigned int";
        } else if constexpr (std::same_as<T, long>) {
            result.fullName = result.name = "long";
        } else if constexpr (std::same_as<T, unsigned long>) {
            result.fullName = result.name = "unsigned long";
        } else if constexpr (std::same_as<T, long long>) {
            result.fullName = result.name = "long long";
        } else if constexpr (std::same_as<T, unsigned long long>) {
            result.fullName = result.name = "unsigned long long";
        } else if constexpr (std::same_as<T, float>) {
            result.fullName = result.name = "float";
        } else if constexpr (std::same_as<T, double>) {
            result.fullName = result.name = "double";
        } else if constexpr (std::same_as<T, long double>) {
            result.fullName = result.name = "long double";
        } else if constexpr (std::same_as<T, void>) {
            result.fullName = result.name = "void";
        } else if constexpr (std::same_as<T, std::nullptr_t>) {
            result.name = "nullptr_t";
            result.fullName = "std::nullptr_t";
        }
        if constexpr (!std::same_as<T, void>) {
            result.size = sizeof(T);
            result.alignment = alignof(T);
        } else {
            // FIXME?
            result.size = 0;
            result.alignment = 0;
        }
        populateIDs(result, idGenerator);
        return result;
    }
}// namespace speculo::gen