macro(speculo_check_fnc_arg_provided ARG_NAME)
    if (${ARG_NAME} IN_LIST _args_KEYWORDS_MISSING_VALUES OR NOT DEFINED _args_${ARG_NAME})
        message(FATAL_ERROR "Missing ${ARG_NAME}")
    endif ()
endmacro()

# Create a configuration json for meta generation in BINARY_DIR
#
# Arguments:
#   TARGET - name of the target to generate for
#   FLAGS - clang compiler flags
#   HEADERS - files to generate for
#   DEFINES - macros
function(speculo_create_config)
    set(options)
    set(oneValueArgs TARGET)
    set(multiValueArgs FLAGS HEADERS DEFINES)
    cmake_parse_arguments(_args "${options}" "${oneValueArgs}"
            "${multiValueArgs}" ${ARGN})

    #speculo_check_fnc_arg_provided("TARGET")
    #speculo_check_fnc_arg_provided("HEADERS")
    #speculo_check_fnc_arg_provided("FLAGS")

    get_target_property(SOURCE_DIR ${_args_TARGET} SOURCE_DIR)
    get_target_property(BINARY_DIR ${_args_TARGET} BINARY_DIR)

    find_package(Python3 REQUIRED COMPONENTS Interpreter)
    add_custom_target(speculo_generate_${_args_TARGET}_config
            ALL
            COMMAND ${Python3_EXECUTABLE}
            ${SPECULO_GEN_SCRIPTS_PATH}/speculo_config_create.py
            -p ${_args_TARGET}
            -r ${SOURCE_DIR}
            -o ${BINARY_DIR}
            -I ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES}
            -I "$<JOIN:$<TARGET_PROPERTY:${_args_TARGET},INCLUDE_DIRECTORIES>,$<SEMICOLON>>"
            -H ${_args_HEADERS}
            -D "$<JOIN:$<TARGET_PROPERTY:${_args_TARGET},COMPILE_DEFINITIONS>,$<SEMICOLON>>"
            -f ${_args_FLAGS}
            COMMAND_EXPAND_LISTS
    )
endfunction()

# Run meta generation as a pre-compilation step
#
# Arguments:
#   FORMAT - format output
#   FORCE_REGEN - force regeneration even if the files have not changed
#   TARGET - target to generate for
function(speculo_run_gen)
    set(options FORMAT FORCE_REGEN)
    set(oneValueArgs TARGET)
    set(multiValueArgs HEADERS)
    cmake_parse_arguments(_args "${options}" "${oneValueArgs}"
            "${multiValueArgs}" ${ARGN})

    if (_args_FORMAT)
        set(formatArg --format-output)
    endif()
    if (_args_FORCE_REGEN)
        set(forceArg --force)
    endif()

    #speculo_check_fnc_arg_provided("TARGET")
    #speculo_check_fnc_arg_provided("HEADERS")
    #speculo_check_fnc_arg_provided("FLAGS")

    get_filename_component(SPECULO_GEN_EXE_DIR ${SPECULO_GEN_EXE_PATH} DIRECTORY)
    # create a target for invoking codegen tool
    get_target_property(BINARY_DIR ${_args_TARGET} BINARY_DIR)
    add_custom_target(${_args_TARGET}_generate_meta COMMAND
            ${SPECULO_GEN_EXE_PATH} --config "${BINARY_DIR}/speculo_${_args_TARGET}_config.json"
            --ignore-includes ${formatArg} ${forceArg}
            WORKING_DIRECTORY ${SPECULO_GEN_EXE_DIR}
    )
    # tool invocation needs to wait for config creation
    add_dependencies(${_args_TARGET}_generate_meta speculo_generate_${_args_TARGET}_config)

    get_target_property(TARGET_SOURCE_DIR ${_args_TARGET} SOURCE_DIR)

    # get list of all generated cpp files
    foreach (HEADER ${_args_HEADERS})
        get_filename_component(HEADER_FILENAME ${HEADER} NAME_WLE)
        get_filename_component(HEADER_DIR ${HEADER} DIRECTORY)
        set(GENERATED_SOURCE ${TARGET_SOURCE_DIR}/${HEADER_DIR}/generated/${HEADER_FILENAME}.cpp)
        # the file needs to be created if it does not exist
        if (NOT EXISTS ${GENERATED_SOURCE})
            file(MAKE_DIRECTORY ${TARGET_SOURCE_DIR}/${HEADER_DIR}/generated)
            file(TOUCH ${GENERATED_SOURCE})
        endif ()
        list(APPEND GENERATED_SOURCES ${GENERATED_SOURCE})
    endforeach ()
    # create a static library with generated source files
    list(LENGTH GENERATED_SOURCES GEN_SOURCES_COUNT)
    if (NOT ${GEN_SOURCES_COUNT} EQUAL 0)
        add_library(speculo_${_args_TARGET}_generated_sources STATIC ${GENERATED_SOURCES})
        target_include_directories(speculo_${_args_TARGET}_generated_sources PRIVATE $<TARGET_PROPERTY:${_args_TARGET},INCLUDE_DIRECTORIES>)
        target_compile_options(speculo_${_args_TARGET}_generated_sources PRIVATE ${flags})
        # generated source files need to wait for being generated
        add_dependencies(speculo_${_args_TARGET}_generated_sources ${_args_TARGET}_generate_meta)

        add_dependencies(${_args_TARGET} speculo_${_args_TARGET}_generated_sources)
        get_target_property(TARGET_TYPE ${_args_TARGET} TYPE)
        if (TARGET_TYPE STREQUAL "INTERFACE_LIBRARY")
            target_link_libraries(${_args_TARGET} INTERFACE speculo_${_args_TARGET}_generated_sources)
        else()
            target_link_libraries(${_args_TARGET} PRIVATE speculo_${_args_TARGET}_generated_sources)
        endif()
    endif ()
endfunction()

# Register target for meta generation
#
# Arguments:
#   FORMAT - format output
#   FORCE_REGEN - force regeneration even if the files have not changed
#   TARGET - target to generate for
#   FLAGS - clang compiler flags
#   HEADER - files to generate for
#   DEFINES - macros
function(speculo_register)
    set(options FORMAT FORCE_REGEN)
    set(oneValueArgs TARGET)
    set(multiValueArgs FLAGS HEADERS DEFINES)
    cmake_parse_arguments(_args "${options}" "${oneValueArgs}"
            "${multiValueArgs}" ${ARGN})

    speculo_create_config(
            TARGET ${_args_TARGET}
            FLAGS ${_args_FLAGS}
            HEADERS ${_args_HEADERS}
            DEFINES ${_args_DEFINES}
    )
    if (_args_FORMAT)
        set(formatArg --format-output)
    endif()
    if (_args_FORCE_REGEN)
        set(forceArg --force)
    endif()

    speculo_run_gen(
            TARGET ${_args_TARGET}
            ${formatArg}
            ${forceArg}
            HEADERS ${_args_HEADERS})
endfunction()