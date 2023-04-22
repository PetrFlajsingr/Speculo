cmake_minimum_required(VERSION 3.25)
project(pf_meta_gen)

if (MSVC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 19.29.30129 AND CMAKE_VERSION VERSION_GREATER 3.20.3)
    set(CMAKE_CXX_STANDARD 23)
else ()
    set(CMAKE_CXX_STANDARD 20)
endif ()


if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    list(APPEND flags "/std:c++latest" "/W4" "/wd4201" "/wd4996" "/wd5030" "/wd4530" "/wd5030")
    list(APPEND test_flags "/std:c++latest" "/wd4201" "/wd4996" "/wd5030" "/wd4530" "/wd5030")
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

add_subdirectory(third_party/cppcoro)

add_executable(pf_meta_gen main.cpp meta_gen/AttributeParser.cpp meta_gen/AstActions.cpp meta_gen/ASTParser.cpp
        meta_gen/MetaInfoWriter.cpp meta_gen/decl_parsers/ASTDeclParser.cpp meta_gen/decl_parsers/ASTDeclParser.h
        meta_gen/decl_parsers/ASTEnumDeclParser.cpp meta_gen/decl_parsers/ASTEnumParser.h
        meta_gen/decl_parsers/ASTRecordParser.cpp meta_gen/decl_parsers/ASTRecordParser.h
        meta_gen/decl_parsers/factory.cpp meta_gen/decl_parsers/factory.h
        meta_gen/CodeGenWriter.cpp)
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

target_link_libraries(meta_test PRIVATE fmt::fmt-header-only spdlog::spdlog tl::expected)
target_include_directories(meta_test PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_options(meta_test PRIVATE ${test_flags})

macro(check_fnc_arg_provided ARG_NAME)
    if (${ARG_NAME} IN_LIST _args_KEYWORDS_MISSING_VALUES OR NOT DEFINED _args_${ARG_NAME})
        message(FATAL_ERROR "Missing ${ARG_NAME}")
    endif ()
endmacro()

function(pf_meta_create_config)
    set(options)
    set(oneValueArgs TARGET)
    set(multiValueArgs FLAGS HEADERS)
    cmake_parse_arguments(_args "${options}" "${oneValueArgs}"
            "${multiValueArgs}" ${ARGN})

    #check_fnc_arg_provided("TARGET")
    #check_fnc_arg_provided("HEADERS")
    #check_fnc_arg_provided("FLAGS")

    get_target_property(INCLUDES ${_args_TARGET} INCLUDE_DIRECTORIES)

    foreach(include ${INCLUDES})
        list(APPEND INCLUDE_ARGS "${include}")
    endforeach()

    get_target_property(SOURCE_DIR ${_args_TARGET} SOURCE_DIR)
    get_target_property(BINARY_DIR ${_args_TARGET} BINARY_DIR)

    find_package(Python3 REQUIRED COMPONENTS Interpreter)
    execute_process(COMMAND ${Python3_EXECUTABLE}
            ${CMAKE_SOURCE_DIR}/scripts/pf_meta_config_create.py
            -p ${_args_TARGET}
            -r ${SOURCE_DIR}
            -o ${BINARY_DIR}
            -f ${_args_FLAGS}
            -I ${INCLUDE_ARGS}
            -H ${_args_HEADERS}
            )
endfunction()
function(pf_meta_run_gen)
    set(options FORMAT)
    set(oneValueArgs TARGET)
    set(multiValueArgs)
    cmake_parse_arguments(_args "${options}" "${oneValueArgs}"
            "${multiValueArgs}" ${ARGN})

    #check_fnc_arg_provided("TARGET")
    #check_fnc_arg_provided("HEADERS")
    #check_fnc_arg_provided("FLAGS")
    get_target_property(BINARY_DIR ${_args_TARGET} BINARY_DIR)
    add_custom_target(${_args_TARGET}_generate_meta COMMAND
            ${PF_META_GEN_DIR}/pf_meta_gen.exe --config "${BINARY_DIR}/pf_meta_${_args_TARGET}_config.json" --ignore-includes $<$<BOOL:${_args_FORMAT}>:--format-output>)

    add_dependencies(meta_test meta_test_generate_meta)
endfunction()

function(pf_meta_register)
    set(options FORMAT)
    set(oneValueArgs TARGET)
    set(multiValueArgs FLAGS HEADERS)
    cmake_parse_arguments(_args "${options}" "${oneValueArgs}"
            "${multiValueArgs}" ${ARGN})

    pf_meta_create_config(
            TARGET ${_args_TARGET}
            FLAGS ${_args_FLAGS}
            HEADERS ${_args_HEADERS}
    )

    pf_meta_run_gen(TARGET ${_args_TARGET} $<$<BOOL:${_args_FORMAT}>:FORMAT>)
endfunction()

# we need clang flags so can't do this get_target_property(CXXFLAGS pf_meta_gen COMPILE_OPTIONS)
list(APPEND CXXFLAGS "std=c++20")
message(STATUS ${CXXFLAGS})

pf_meta_register(
        TARGET meta_test
        FLAGS ${CXXFLAGS}
        HEADERS src/test.h src/test2.hpp
        FORMAT
)



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
