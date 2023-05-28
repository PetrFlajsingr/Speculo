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
#   DEFINES - macros
function(pf_meta_create_config)
    set(options)
    set(oneValueArgs TARGET)
    set(multiValueArgs FLAGS HEADERS DEFINES)
    cmake_parse_arguments(_args "${options}" "${oneValueArgs}"
            "${multiValueArgs}" ${ARGN})

    #pf_meta_check_fnc_arg_provided("TARGET")
    #pf_meta_check_fnc_arg_provided("HEADERS")
    #pf_meta_check_fnc_arg_provided("FLAGS")

    get_target_property(COMPILE_DEFINITIONS ${_args_TARGET} COMPILE_DEFINITIONS)
    set(SKIP_COMPILE_DEFINITIONS FALSE)
    list(LENGTH COMPILE_DEFINITIONS LENGTH_RESULT)
    if (LENGTH_RESULT EQUAL 1)
        if(${COMPILE_DEFINITIONS} STREQUAL COMPILE_DEFINITIONS-NOTFOUND)
            set(SKIP_COMPILE_DEFINITIONS TRUE)
        endif()
    endif()
    if (NOT SKIP_COMPILE_DEFINITIONS)
        foreach (def ${COMPILE_DEFINITIONS})
            list(APPEND DEFINITIONS ${def})
        endforeach()
    endif()

    foreach (def ${_args_DEFINITIONS})
        list(APPEND DEFINITIONS ${def})
    endforeach()

    get_directory_property(GLOBAL_DEFINITIONS COMPILE_DEFINITIONS)
    set(SKIP_GLOBAL_DEFINITIONS FALSE)
    list(LENGTH GLOBAL_DEFINITIONS LENGTH_RESULT)
    if (LENGTH_RESULT EQUAL 1)
        if(${GLOBAL_DEFINITIONS} STREQUAL GLOBAL_DEFINITIONS-NOTFOUND)
            set(SKIP_GLOBAL_DEFINITIONS TRUE)
        endif()
    endif()
    if (NOT SKIP_GLOBAL_DEFINITIONS)
        foreach (def ${GLOBAL_DEFINITIONS})
            list(APPEND DEFINITIONS ${def})
        endforeach()
    endif()

    get_target_property(INCLUDES ${_args_TARGET} INCLUDE_DIRECTORIES)
    set(SKIP_INCLUDES FALSE)
    list(LENGTH INCLUDES LENGTH_RESULT)
    if (LENGTH_RESULT EQUAL 1)
        if(${INCLUDES} STREQUAL INCLUDES-NOTFOUND)
            set(SKIP_INCLUDES TRUE)
        endif()
    endif()

    if (NOT ${SKIP_INCLUDES})
        foreach (include ${INCLUDES})
            list(APPEND INCLUDE_ARGS "${include}")
        endforeach ()
    endif ()

    get_target_property(DEPENDENCIES ${_args_TARGET} LINK_LIBRARIES)
    list(LENGTH DEPENDENCIES LENGTH_RESULT)
    set(DEPENDENCIES_INVALID FALSE)
    if (LENGTH_RESULT EQUAL 1)
        if(${DEPENDENCIES} STREQUAL DEPENDENCIES-NOTFOUND)
            set(DEPENDENCIES_INVALID TRUE)
        endif()
    endif()

    if (NOT ${DEPENDENCIES_INVALID})
        foreach (dependency ${DEPENDENCIES})
            get_target_property(DEPENDENCY_INCLUDES ${dependency} INCLUDE_DIRECTORIES)
            list(LENGTH DEPENDENCY_INCLUDES LENGTH_RESULT)
            if (LENGTH_RESULT EQUAL 1)
                if(${DEPENDENCY_INCLUDES} STREQUAL DEPENDENCY_INCLUDES-NOTFOUND)
                    continue()
                endif()
            endif()

            foreach (include ${DEPENDENCY_INCLUDES})
                list(APPEND INCLUDE_ARGS "${include}")
            endforeach ()
        endforeach ()

        foreach (dependency ${DEPENDENCIES})
            get_target_property(DEPENDENCY_INCLUDES ${dependency} INTERFACE_INCLUDE_DIRECTORIES)
            list(LENGTH DEPENDENCY_INCLUDES LENGTH_RESULT)
            if (LENGTH_RESULT EQUAL 1)
                if(${DEPENDENCY_INCLUDES} STREQUAL DEPENDENCY_INCLUDES-NOTFOUND)
                    continue()
                endif()
            endif()

            foreach (include ${DEPENDENCY_INCLUDES})
                list(APPEND INCLUDE_ARGS "${include}")
            endforeach ()
        endforeach ()
    endif()

    get_target_property(SOURCE_DIR ${_args_TARGET} SOURCE_DIR)
    get_target_property(BINARY_DIR ${_args_TARGET} BINARY_DIR)

    find_package(Python3 REQUIRED COMPONENTS Interpreter)
    execute_process(COMMAND ${Python3_EXECUTABLE}
            ${PF_META_GEN_SCRIPTS_PATH}/pf_meta_config_create.py
            -p ${_args_TARGET}
            -r ${SOURCE_DIR}
            -o ${BINARY_DIR}
            -I ${INCLUDE_ARGS}
            -H ${_args_HEADERS}
            -D ${DEFINITIONS}
            -f ${_args_FLAGS}
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

    if (_args_FORMAT)
        set(formatArg --format-output)
    endif()
    if (_args_FORCE_REGEN)
        set(forceArg --force)
    endif()

    #pf_meta_check_fnc_arg_provided("TARGET")
    #pf_meta_check_fnc_arg_provided("HEADERS")
    #pf_meta_check_fnc_arg_provided("FLAGS")
    get_target_property(BINARY_DIR ${_args_TARGET} BINARY_DIR)
    add_custom_target(${_args_TARGET}_generate_meta COMMAND
            ${PF_META_GEN_PATH} --config "${BINARY_DIR}/pf_meta_${_args_TARGET}_config.json"
            --ignore-includes ${formatArg} ${forceArg})

    add_dependencies(${_args_TARGET} ${_args_TARGET}_generate_meta)
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
function(pf_meta_register)
    set(options FORMAT FORCE_REGEN)
    set(oneValueArgs TARGET)
    set(multiValueArgs FLAGS HEADERS DEFINES)
    cmake_parse_arguments(_args "${options}" "${oneValueArgs}"
            "${multiValueArgs}" ${ARGN})

    target_link_libraries(${_args_TARGET} PUBLIC pf_meta::pf_meta)

    pf_meta_create_config(
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

    pf_meta_run_gen(TARGET ${_args_TARGET} ${formatArg} ${forceArg})
endfunction()