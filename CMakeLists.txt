cmake_minimum_required (VERSION 3.5.1)

project (IBEX_MYPLUGIN VERSION 0.42 LANGUAGES CXX)
set (IBEX_MYPLUGIN_DESCRIPTION "Short description of the plugin")

find_package (IBEX 2.8.9 REQUIRED)
message (STATUS "Found Ibex version ${IBEX_VERSION}")
ibex_init_common () # Ibex should have installed this function

# The following lines test if the found version of Ibex was compiled with a
# linear programming library. If you need to perform this test, uncomment the
# next lines.
#ibex_check_have_lp_lib (HAVE_LP_LIB)
#if (NOT HAVE_LP_LIB)
#  message (FATAL_ERROR "A Linear Programming library is needed for this plugin")
#endif ()

################################################################################
# Compile sources
################################################################################
add_subdirectory (src)

################################################################################
# Tests
################################################################################
# The following command assumes that the tests are in a tests/ subdirectory. So
# the tests/ subdirectory must exist and must contain a CMakeLists.txt file.
# If this is not the case, comment the next line.
add_make_target_for_ctest (check)
