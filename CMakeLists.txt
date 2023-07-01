cmake_minimum_required(VERSION 3.25)
project(speculo VERSION 0.1.0)

include(CMakePackageConfigHelpers)

option(SPECULO_ENABLE_TEST_EXE "Enable test exe target" OFF)

set(CMAKE_CXX_STANDARD 20)

# Set SPECULO_GEN_EXE_PATH to current binary output if not provided
# global variables
# allows for using the project as subdirectory
if (NOT DEFINED SPECULO_GEN_EXE_PATH)
    if (WIN32)
        set(SPECULO_GEN_EXE_PATH ${CMAKE_CURRENT_BINARY_DIR}/speculo_gen.exe CACHE INTERNAL "SPECULO_GEN_EXE_PATH")
    else()
        set(SPECULO_GEN_EXE_PATH ${CMAKE_CURRENT_BINARY_DIR}/speculo_gen CACHE INTERNAL "SPECULO_GEN_EXE_PATH")
    endif ()
endif ()

if (NOT DEFINED SPECULO_GEN_SCRIPTS_PATH)
    set(SPECULO_GEN_SCRIPTS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts CACHE INTERNAL "SPECULO_GEN_SCRIPTS_PATH")
endif ()

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    list(APPEND flags "/W4" "/wd4201" "/wd4996" "/wd5030" "/wd4530" "/wd5030")
    list(APPEND test_flags "/wd4201" "/wd4996" "/wd5030" "/wd4530" "/wd5030" "/wd5222")
else ()
    list(APPEND flags "-fconcepts" "-fconcepts-diagnostics-depth=10" "-Werror=return-type" "-fcoroutines"
            "-Wall" "-Wextra" "-Werror" "-Wpedantic" "-Wno-unknown-pragmas" "-Wno-unused-function" "-fno-rtti"
            "-Wpointer-arith" "-Wno-cast-qual" "-Wno-type-limits" "-fno-strict-aliasing" "-Wno-format-security"
            "-Wshadow" "-Wno-attributes"
            "-fuse-ld=mold")
    list(APPEND test_flags "-fconcepts" "-fconcepts-diagnostics-depth=10" "-Wno-attributes")
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

add_library(speculo INTERFACE)
add_library(speculo::speculo ALIAS speculo)
target_include_directories(speculo INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

add_executable(speculo_gen main.cpp
        speculo_gen/AttributeParser.cpp
        speculo_gen/AstActions.cpp
        speculo_gen/ASTParser.cpp
        speculo_gen/MetaInfoWriter.cpp
        speculo_gen/decl_parsers/ASTDeclParser.cpp
        speculo_gen/decl_parsers/ASTEnumDeclParser.cpp
        speculo_gen/decl_parsers/ASTRecordParser.cpp
        speculo_gen/decl_parsers/factory.cpp
        speculo_gen/codegen/MetaSupportCodeGenerator.cpp
        speculo_gen/codegen/PluginManager.cpp
        speculo_gen/IncludeCollector.cpp
        speculo_gen/clang_utils.cpp
)
target_include_directories(speculo_gen PRIVATE ${FLAT_INCLUDE_DIRS})
add_executable(speculo_generate_fundamental_types main_generate_fundamental_types.cpp)

separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})

target_compile_definitions(speculo_gen PRIVATE ${LLVM_DEFINITIONS_LIST} WIN32_LEAN_AND_MEAN VC_EXTRALEAN)
target_include_directories(speculo_gen PRIVATE ${LLVM_INCLUDE_DIRS})
target_compile_definitions(speculo_generate_fundamental_types PRIVATE ${LLVM_DEFINITIONS_LIST} WIN32_LEAN_AND_MEAN VC_EXTRALEAN)
target_include_directories(speculo_generate_fundamental_types PRIVATE ${LLVM_INCLUDE_DIRS})

set(LLVM_RUNTIME_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/${CMAKE_CFG_INTDIR}/bin)
set(LLVM_LIBRARY_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/${CMAKE_CFG_INTDIR}/lib)
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(HandleLLVMOptions)
include(AddLLVM)


target_include_directories(speculo_gen PRIVATE ${CLANG_INCLUDE_DIRS})
target_link_libraries(speculo_gen PRIVATE clangAST clangFrontend clangTooling clangToolingSyntax fmt::fmt-header-only spdlog::spdlog_header_only tl::expected nlohmann_json::nlohmann_json)
target_link_libraries(speculo_gen PRIVATE stduuid speculo::speculo)
if (WIN32)
target_link_libraries(speculo_gen PRIVATE synchronization.lib)
endif()
target_compile_options(speculo_gen PRIVATE ${flags})


target_include_directories(speculo_generate_fundamental_types PRIVATE ${CLANG_INCLUDE_DIRS})
target_include_directories(speculo_generate_fundamental_types PRIVATE speculo_gen/include)
target_link_libraries(speculo_generate_fundamental_types PRIVATE clangAST clangFrontend clangTooling clangToolingSyntax fmt::fmt-header-only spdlog::spdlog_header_only tl::expected)
target_link_libraries(speculo_generate_fundamental_types PRIVATE stduuid speculo::speculo)
target_compile_options(speculo_generate_fundamental_types PRIVATE ${flags})



install(TARGETS speculo
        EXPORT speculo_Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

write_basic_package_version_file("speculoConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(SPECULO_GEN_EXE_PATH_INSTALL ${CMAKE_INSTALL_PREFIX}/Debug/bin)
else ()
    set(SPECULO_GEN_EXE_PATH_INSTALL ${CMAKE_INSTALL_PREFIX}/Release/bin)
endif ()

if (WIN32)
    set(SPECULO_GEN_EXE_PATH_INSTALL ${SPECULO_GEN_EXE_PATH_INSTALL}/speculo_gen.exe)
else ()
    set(SPECULO_GEN_EXE_PATH_INSTALL ${SPECULO_GEN_EXE_PATH_INSTALL}/speculo_gen)
endif ()

configure_package_config_file(
        "${PROJECT_SOURCE_DIR}/cmake/speculoConfig.cmake.in"
        "${PROJECT_BINARY_DIR}/speculoConfig.cmake"
        INSTALL_DESTINATION
        ${CMAKE_INSTALL_DATAROOTDIR}/speculo/cmake)

install(EXPORT speculo_Targets
        FILE speculoTargets.cmake
        NAMESPACE speculo::
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/speculo/cmake)

install(FILES "${PROJECT_BINARY_DIR}/speculoConfig.cmake"
        "${PROJECT_BINARY_DIR}/speculoConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/speculo/cmake)


install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/speculo DESTINATION include)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/scripts DESTINATION .)
install(FILES ${PROJECT_SOURCE_DIR}/cmake/speculo.cmake DESTINATION cmake)

set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")

include(CPack)


install(TARGETS speculo_gen speculo_generate_fundamental_types
        CONFIGURATIONS Debug
        RUNTIME DESTINATION Debug/bin)
install(TARGETS speculo_gen speculo_generate_fundamental_types
        CONFIGURATIONS Release
        RUNTIME DESTINATION Release/bin)




if (${SPECULO_ENABLE_TEST_EXE})
    include(cmake/speculo.cmake)
    list(APPEND CXXFLAGS "-std=c++20")
    message(STATUS ${CXXFLAGS})

    add_executable(meta_test main_test.cpp)

    target_link_libraries(meta_test PRIVATE fmt::fmt-header-only spdlog::spdlog_header_only tl::expected speculo::speculo)
    target_include_directories(meta_test PRIVATE ${CMAKE_SOURCE_DIR})
    target_compile_options(meta_test PRIVATE ${test_flags})
    add_dependencies(meta_test speculo_gen)

    speculo_register(
            TARGET meta_test
            FLAGS ${CXXFLAGS}
            HEADERS src/test.h src/test2.hpp
            FORMAT
            #FORCE_REGEN
    )
endif ()