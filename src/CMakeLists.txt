################################################################################
# First example: compiling a library that depends on libibex
################################################################################
# source files of libibex-plugin
list (APPEND SRC ${CMAKE_CURRENT_SOURCE_DIR}/ibex_Plugin.cpp
                 ${CMAKE_CURRENT_SOURCE_DIR}/ibex_Plugin.h
                 # Add more source files here.
                 # For most plugins, the rest can be left as is.
                 )

# Create the target for libibex-plugin
add_library (ibex-plugin ${SRC})
# Using ${IBEX_*} variables (set by CMake using pkg-config) to compile the
# library
target_compile_options (ibex-plugin PUBLIC ${IBEX_CFLAGS})
target_include_directories (ibex-plugin PUBLIC ${IBEX_INCLUDE_DIRS})
target_include_directories (ibex-plugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries (ibex-plugin PUBLIC ${IBEX_LDFLAGS})

# installation of libibex-plugin files
foreach (srcfile ${SRC})
  if (srcfile MATCHES "\\.h$" OR srcfile MATCHES "\\.hpp$")
    list (APPEND HDR ${srcfile})
  endif ()
endforeach()
install (TARGETS ibex-plugin DESTINATION ${CMAKE_INSTALL_LIBDIR})
install (FILES ${HDR} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ibex-plugin)

################################################################################
# More examples in the bin subdirectory
################################################################################
add_subdirectory (bin)
