cmake_minimum_required(VERSION 3.25)
project(pf_meta)

set(CMAKE_CXX_STANDARD 23)

find_package(LLVM CONFIG REQUIRED)
find_package(Clang CONFIG REQUIRED)
find_package(pf_common CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(magic_enum CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(tl-expected CONFIG REQUIRED)

add_executable(libclang_test main.cpp)
add_executable(meta_test main_test.cpp)

function(dump_cmake_variables)
    get_cmake_property(_variableNames VARIABLES)
    list(SORT _variableNames)
    foreach (_variableName ${_variableNames})
        if (ARGV0)
            unset(MATCHED)
            string(REGEX MATCH ${ARGV0} MATCHED ${_variableName})
            if (NOT MATCHED)
                continue()
            endif ()
        endif ()
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach ()
endfunction()

separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
include_directories(${LLVM_INCLUDE_DIRS})

set(LLVM_RUNTIME_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/${CMAKE_CFG_INTDIR}/bin)
set(LLVM_LIBRARY_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/${CMAKE_CFG_INTDIR}/lib)
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(HandleLLVMOptions)
include(AddLLVM)


target_include_directories(libclang_test PRIVATE ${CLANG_INCLUDE_DIRS})
target_link_libraries(libclang_test PRIVATE clangAST clangFrontend clangTooling pf_common::pf_common magic_enum::magic_enum fmt::fmt-header-only spdlog::spdlog tl::expected)

target_link_libraries(meta_test PRIVATE pf_common::pf_common magic_enum::magic_enum fmt::fmt-header-only spdlog::spdlog tl::expected)