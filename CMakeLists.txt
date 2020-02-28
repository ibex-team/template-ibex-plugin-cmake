cmake_minimum_required (VERSION 3.0.2)

project (IBEX_MYPLUGIN VERSION 0.42 LANGUAGES CXX)
set (IBEX_MYPLUGIN_DESCRIPTION "Short description of the plugin")

find_package (IBEX 2.8.6 REQUIRED)
message (STATUS "Found Ibex version ${IBEX_VERSION}")
ibex_init_common () # Ibex should have installed this function

################################################################################
# Compile sources
################################################################################
add_subdirectory (src)

################################################################################
# Tests
################################################################################
add_make_target_for_ctest (check)
