cmake_minimum_required(VERSION 3.25)
project(pf_meta_gen VERSION 0.1.0)

include(CMakePackageConfigHelpers)

option(PF_META_ENABLE_TEST_EXE "Enable test exe target" OFF)

if (MSVC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 19.29.30129 AND CMAKE_VERSION VERSION_GREATER 3.20.3)
    set(CMAKE_CXX_STANDARD 23)
else ()
    set(CMAKE_CXX_STANDARD 20)
endif ()

# Set PF_META_GEN_PATH to current binary output if not provided
# global variables
# allows for using the project as subdirectory
if (NOT DEFINED PF_META_GEN_PATH)
    # FIXME: windows exe only for now
    set(PF_META_GEN_PATH ${CMAKE_CURRENT_BINARY_DIR}/pf_meta_gen.exe CACHE INTERNAL "PF_META_GEN_PATH")
endif ()

if (NOT DEFINED PF_META_GEN_SCRIPTS_PATH)
    set(PF_META_GEN_SCRIPTS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts CACHE INTERNAL "PF_META_GEN_SCRIPTS_PATH")
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

add_library(pf_meta INTERFACE)
add_library(pf_meta::pf_meta ALIAS pf_meta)
target_include_directories(pf_meta INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(TARGETS pf_meta
        EXPORT pf_meta_Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

write_basic_package_version_file("pf_metaConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion)

configure_package_config_file(
        "${PROJECT_SOURCE_DIR}/cmake/pf_metaConfig.cmake.in"
        "${PROJECT_BINARY_DIR}/pf_metaConfig.cmake"
        INSTALL_DESTINATION
        ${CMAKE_INSTALL_DATAROOTDIR}/pf_meta/cmake)

install(EXPORT pf_meta_Targets
        FILE pf_metaTargets.cmake
        NAMESPACE pf_meta::
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pf_meta/cmake)

install(FILES "${PROJECT_BINARY_DIR}/pf_metaConfig.cmake"
        "${PROJECT_BINARY_DIR}/pf_metaConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pf_meta/cmake)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/meta DESTINATION include)

set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")

include(CPack)

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

separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})

target_compile_definitions(pf_meta_gen PRIVATE ${LLVM_DEFINITIONS_LIST})
target_include_directories(pf_meta_gen PRIVATE ${LLVM_INCLUDE_DIRS})
target_compile_definitions(pf_meta_generate_fundamental_types PRIVATE ${LLVM_DEFINITIONS_LIST})
target_include_directories(pf_meta_generate_fundamental_types PRIVATE ${LLVM_INCLUDE_DIRS})

set(LLVM_RUNTIME_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/${CMAKE_CFG_INTDIR}/bin)
set(LLVM_LIBRARY_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/${CMAKE_CFG_INTDIR}/lib)
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(HandleLLVMOptions)
include(AddLLVM)


target_include_directories(pf_meta_gen PRIVATE ${CLANG_INCLUDE_DIRS})
target_link_libraries(pf_meta_gen PRIVATE clangAST clangFrontend clangTooling clangToolingSyntax fmt::fmt-header-only spdlog::spdlog tl::expected nlohmann_json::nlohmann_json)
target_link_libraries(pf_meta_gen PRIVATE stduuid pf_meta::pf_meta)
# FIXME: only on win
target_link_libraries(pf_meta_gen PRIVATE synchronization.lib)
target_compile_options(pf_meta_gen PRIVATE ${flags})


target_include_directories(pf_meta_generate_fundamental_types PRIVATE ${CLANG_INCLUDE_DIRS})
target_include_directories(pf_meta_generate_fundamental_types PRIVATE meta_gen/include)
target_link_libraries(pf_meta_generate_fundamental_types PRIVATE clangAST clangFrontend clangTooling clangToolingSyntax fmt::fmt-header-only spdlog::spdlog tl::expected)
target_link_libraries(pf_meta_generate_fundamental_types PRIVATE stduuid pf_meta::pf_meta)
target_compile_options(pf_meta_generate_fundamental_types PRIVATE ${flags})


install(TARGETS pf_meta_gen pf_meta_generate_fundamental_types
        CONFIGURATIONS Debug
        RUNTIME DESTINATION Debug/bin)
install(TARGETS pf_meta_gen pf_meta_generate_fundamental_types
        CONFIGURATIONS Release
        RUNTIME DESTINATION Release/bin)




if (${PF_META_ENABLE_TEST_EXE})
    include(cmake/pf_meta.cmake)
    list(APPEND CXXFLAGS "-std=c++20")
    message(STATUS ${CXXFLAGS})

    add_executable(meta_test main_test.cpp)

    target_link_libraries(meta_test PRIVATE fmt::fmt-header-only spdlog::spdlog tl::expected pf_meta::pf_meta)
    target_include_directories(meta_test PRIVATE ${CMAKE_SOURCE_DIR})
    target_compile_options(meta_test PRIVATE ${test_flags})
    add_dependencies(meta_test pf_meta_gen)

    pf_meta_register(
            TARGET meta_test
            FLAGS ${CXXFLAGS}
            HEADERS src/test.h src/test2.hpp
            FORMAT
            FORCE_REGEN
    )
    add_dependencies(meta_test_generate_meta pf_meta_gen)
endif ()