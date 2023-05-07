macro(pf_meta_check_fnc_arg_provided ARG_NAME)
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
function(pf_meta_create_config)
    set(options)
    set(oneValueArgs TARGET)
    set(multiValueArgs FLAGS HEADERS)
    cmake_parse_arguments(_args "${options}" "${oneValueArgs}"
            "${multiValueArgs}" ${ARGN})

    #pf_meta_check_fnc_arg_provided("TARGET")
    #pf_meta_check_fnc_arg_provided("HEADERS")
    #pf_meta_check_fnc_arg_provided("FLAGS")

    get_target_property(INCLUDES ${_args_TARGET} INCLUDE_DIRECTORIES)

    foreach (include ${INCLUDES})
        list(APPEND INCLUDE_ARGS "${include}")
    endforeach ()

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

# Run meta generation as a pre-compilation step
#
# Arguments:
#   FORMAT - format output
#   FORCE_REGEN - force regeneration even if the files have not changed
#   TARGET - target to generate for
function(pf_meta_run_gen)
    set(options FORMAT FORCE_REGEN)
    set(oneValueArgs TARGET)
    set(multiValueArgs)
    cmake_parse_arguments(_args "${options}" "${oneValueArgs}"
            "${multiValueArgs}" ${ARGN})

    if (DEFINED _args_FORMAT)
        set(formatArg --format-output)
    endif()
    if (DEFINED _args_FORCE_REGEN)
        set(forceArg --force)
    endif()

    #pf_meta_check_fnc_arg_provided("TARGET")
    #pf_meta_check_fnc_arg_provided("HEADERS")
    #pf_meta_check_fnc_arg_provided("FLAGS")
    get_target_property(BINARY_DIR ${_args_TARGET} BINARY_DIR)
    add_custom_target(${_args_TARGET}_generate_meta COMMAND
            ${PF_META_GEN_DIR}/pf_meta_gen.exe --config "${BINARY_DIR}/pf_meta_${_args_TARGET}_config.json"
            --ignore-includes ${formatArg} ${forceArg})

    add_dependencies(meta_test meta_test_generate_meta)
endfunction()

# Register target for meta generation
#
# Arguments:
#   FORMAT - format output
#   FORCE_REGEN - force regeneration even if the files have not changed
#   TARGET - target to generate for
#   FLAGS - clang compiler flags
#   HEADER - files to generate for
function(pf_meta_register)
    set(options FORMAT FORCE_REGEN)
    set(oneValueArgs TARGET)
    set(multiValueArgs FLAGS HEADERS)
    cmake_parse_arguments(_args "${options}" "${oneValueArgs}"
            "${multiValueArgs}" ${ARGN})

    pf_meta_create_config(
            TARGET ${_args_TARGET}
            FLAGS ${_args_FLAGS}
            HEADERS ${_args_HEADERS}
    )

    pf_meta_run_gen(TARGET ${_args_TARGET} $<$<BOOL:${_args_FORMAT}>:FORMAT> $<$<BOOL:${_args_FORCE_REGEN}>:FORCE_REGEN>)
endfunction()