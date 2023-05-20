cmake_minimum_required(VERSION 3.25)
project(pf_meta_gen)

include(cmake/pf_meta.cmake)

if (MSVC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 19.29.30129 AND CMAKE_VERSION VERSION_GREATER 3.20.3)
    set(CMAKE_CXX_STANDARD 23)
else ()
    set(CMAKE_CXX_STANDARD 20)
endif ()


if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    list(APPEND flags "/std:c++latest" "/W4" "/wd4201" "/wd4996" "/wd5030" "/wd4530" "/wd5030")
    list(APPEND test_flags "/std:c++latest" "/wd4201" "/wd4996" "/wd5030" "/wd4530" "/wd5030" "/wd5222")
else ()
    list(APPEND flags "-fconcepts" "-fconcepts-diagnostics-depth=10" "-Werror=return-type" "-fcoroutines"
            "-Wall" "-Wextra" "-Werror" "-Wpedantic" "-Wno-unknown-pragmas" "-Wno-unused-function"
            "-Wpointer-arith" "-Wno-cast-qual" "-Wno-type-limits" "-fno-strict-aliasing" "-Wno-format-security" "-Wshadow")
    list(APPEND test_flags "-fconcepts" "-fconcepts-diagnostics-depth=10")
endif ()

if (CMAKE_BUILD_TYPE MATCHES Debug)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        list(APPEND flags "/WX")
    endif ()
endif()

find_package(LLVM CONFIG REQUIRED)
find_package(Clang CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(tl-expected CONFIG REQUIRED)
find_package(stduuid CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_path(FLAT_INCLUDE_DIRS "flat/extra/small_map.hpp")

add_subdirectory(third_party/cppcoro)

add_executable(pf_meta_gen main.cpp
        meta_gen/AttributeParser.cpp
        meta_gen/AstActions.cpp
        meta_gen/ASTParser.cpp
        meta_gen/MetaInfoWriter.cpp
        meta_gen/decl_parsers/ASTDeclParser.cpp
        meta_gen/decl_parsers/ASTEnumDeclParser.cpp
        meta_gen/decl_parsers/ASTRecordParser.cpp
        meta_gen/decl_parsers/factory.cpp
        meta_gen/CodeGenWriter.cpp)
target_include_directories(pf_meta_gen PRIVATE ${FLAT_INCLUDE_DIRS})
add_executable(pf_meta_generate_fundamental_types main_generate_fundamental_types.cpp)
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
target_link_libraries(pf_meta_gen PRIVATE clangAST clangFrontend clangTooling fmt::fmt-header-only spdlog::spdlog tl::expected nlohmann_json::nlohmann_json)
target_link_libraries(pf_meta_gen PRIVATE stduuid cppcoro)
# FIXME: only on win
target_link_libraries(pf_meta_gen PRIVATE synchronization.lib)
target_compile_options(pf_meta_gen PRIVATE ${flags})


target_include_directories(pf_meta_generate_fundamental_types PRIVATE ${CLANG_INCLUDE_DIRS})
target_include_directories(pf_meta_generate_fundamental_types PRIVATE meta_gen/include)
target_link_libraries(pf_meta_generate_fundamental_types PRIVATE clangAST clangFrontend clangTooling fmt::fmt-header-only spdlog::spdlog tl::expected)
target_link_libraries(pf_meta_generate_fundamental_types PRIVATE stduuid)
target_compile_options(pf_meta_generate_fundamental_types PRIVATE ${flags})

target_link_libraries(meta_test PRIVATE fmt::fmt-header-only spdlog::spdlog tl::expected)
target_include_directories(meta_test PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_options(meta_test PRIVATE ${test_flags})
add_dependencies(meta_test pf_meta_gen)


# we need clang flags so can't do this get_target_property(CXXFLAGS pf_meta_gen COMPILE_OPTIONS)
list(APPEND CXXFLAGS "-std=c++20")
message(STATUS ${CXXFLAGS})

pf_meta_register(
        TARGET meta_test
        FLAGS ${CXXFLAGS}
        HEADERS src/test.h src/test2.hpp
        FORMAT
)
add_dependencies(meta_test_generate_meta pf_meta_gen)


#find_package(Python3 REQUIRED COMPONENTS Interpreter)
#execute_process(COMMAND ${Python3_EXECUTABLE}
#        ${CMAKE_SOURCE_DIR}/scripts/pf_meta_config_create.py
#        -p meta_test
#        -r ${CMAKE_SOURCE_DIR}
#        -o ${CMAKE_BINARY_DIR}
#        -f ${CXXFLAGS}
#        -I ${INCLUDE_ARGS}
#        -H ${HEADERS_FOR_META}
#        )
