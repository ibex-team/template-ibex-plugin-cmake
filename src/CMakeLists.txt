################################################################################
# First example: compiling a library that depends on libibex
################################################################################
# source files of libibex-myplugin
list (APPEND SRC ${CMAKE_CURRENT_SOURCE_DIR}/ibex_Plugin.cpp
                 ${CMAKE_CURRENT_SOURCE_DIR}/ibex_Plugin.h
                 # Add more source files here.
                 # For most plugins, the rest can be left as is.
                 )

# Create the target for libibex-myplugin
add_library (ibex-myplugin ${SRC})
target_include_directories (ibex-myplugin PUBLIC
                            "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                            "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
target_link_libraries (ibex-myplugin PUBLIC Ibex::ibex)

# installation of libibex-myplugin files
ibex_list_filter_header (HDR ${SRC}) # Ibex should have installed this function
install (TARGETS ibex-myplugin EXPORT MyPluginExport
                               DESTINATION ${CMAKE_INSTALL_LIBDIR})
install (FILES ${HDR} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ibex-myplugin)

################################################################################
# More examples in the bin subdirectory
################################################################################
add_subdirectory (bin)
