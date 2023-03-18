cmake_minimum_required(VERSION 3.25)
project(pf_meta_gen)

if (MSVC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 19.29.30129 AND CMAKE_VERSION VERSION_GREATER 3.20.3)
    set(CMAKE_CXX_STANDARD 23)
else ()
    set(CMAKE_CXX_STANDARD 20)
endif ()


if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    list(APPEND flags "/std:c++latest" "/W4" "/wd4201" "/wd4996" "/wd5030" "/wd4530")
else ()
    list(APPEND flags "-fconcepts" "-fconcepts-diagnostics-depth=10" "-Werror=return-type" "-fcoroutines"
            "-Wall" "-Wextra" "-Werror" "-Wpedantic" "-Wno-unknown-pragmas" "-Wno-unused-function"
            "-Wpointer-arith" "-Wno-cast-qual" "-Wno-type-limits" "-fno-strict-aliasing" "-Wno-format-security" "-Wshadow")
endif ()
if (CMAKE_BUILD_TYPE MATCHES Debug)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        list(APPEND flags "/WX")
    endif ()
endif()

find_package(LLVM CONFIG REQUIRED)
find_package(Clang CONFIG REQUIRED)
find_package(pf_common CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(magic_enum CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(tl-expected CONFIG REQUIRED)
add_executable(pf_meta_gen main.cpp meta_gen/AttributeParser.cpp)
find_package(stduuid CONFIG REQUIRED)

add_executable(meta_test main_test.cpp)


separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
include_directories(${LLVM_INCLUDE_DIRS})

set(LLVM_RUNTIME_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/${CMAKE_CFG_INTDIR}/bin)
set(LLVM_LIBRARY_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/${CMAKE_CFG_INTDIR}/lib)
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(HandleLLVMOptions)
include(AddLLVM)


target_include_directories(pf_meta_gen PRIVATE ${CLANG_INCLUDE_DIRS})
target_include_directories(pf_meta_gen PRIVATE meta_gen/include)
target_link_libraries(pf_meta_gen PRIVATE clangAST clangFrontend clangTooling pf_common::pf_common magic_enum::magic_enum fmt::fmt-header-only spdlog::spdlog tl::expected)
target_link_libraries(pf_meta_gen PRIVATE stduuid)
target_compile_options(pf_meta_gen PRIVATE ${flags})

target_link_libraries(meta_test PRIVATE pf_common::pf_common magic_enum::magic_enum fmt::fmt-header-only spdlog::spdlog tl::expected)
target_compile_options(meta_test PRIVATE ${flags})