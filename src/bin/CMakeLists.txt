################################################################################
# First example: compiling a binary that depends on libibex-plugin
################################################################################
# source files of bin1
list (APPEND SRC1 ${CMAKE_CURRENT_SOURCE_DIR}/bin1.cpp
                  # Add more source files here.
                  # For most plugins, the rest can be left as is.
                  )

# Create the target for bin1
add_executable (bin1 ${SRC1})
target_link_libraries (bin1 PUBLIC ibex-plugin)

# install the binary
install (TARGETS bin1 DESTINATION ${CMAKE_INSTALL_BINDIR})

################################################################################
# Second example: compiling a binary that depends only on libibex
################################################################################
# source files of bin2
list (APPEND SRC2 ${CMAKE_CURRENT_SOURCE_DIR}/bin2.cpp
                  # Add more source files here.
                  # For most plugins, the rest can be left as is.
                  )

# Create the target for bin2
add_executable (bin2 ${SRC2})
# Using ${IBEX_*} variables (set by CMake using pkg-config) to compile the
# library
target_compile_options (bin2 PUBLIC ${IBEX_CFLAGS})
target_include_directories (bin2 PUBLIC ${IBEX_INCLUDE_DIRS})
target_link_libraries (bin2 PUBLIC ${IBEX_LDFLAGS})

# install the binary
install (TARGETS bin2 DESTINATION ${CMAKE_INSTALL_BINDIR})

