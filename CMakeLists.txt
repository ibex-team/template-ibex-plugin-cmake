cmake_minimum_required (VERSION 3.0.2)

project (IBEX_PLUGIN VERSION 0.42 LANGUAGES CXX)
set (IBEX_PLUGIN_DESCRIPTION "Short description of the plugin")

################################################################################
# Options for install directory
################################################################################
set (CMAKE_INSTALL_INCLUDEDIR "include" CACHE PATH "C++ header files (include)")
set (CMAKE_INSTALL_LIBDIR "lib" CACHE PATH "object code libraries (lib)")
set (CMAKE_INSTALL_BINDIR "bin" CACHE PATH "user executables (bin)")

################################################################################
# Check that the compiler supports c++11
################################################################################
include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
  message(FATAL_ERROR "Ibex needs a compiler with C++11 support")
endif()

if (WIN32)
  # We need this for strdup under Windows (see issue #287)
  add_definitions(-U__STRICT_ANSI__)
endif ()

################################################################################
# Looking for Ibex
################################################################################
#find_package (IBEX 2.8.3 REQUIRED)
include (FindPkgConfig)
pkg_search_module (IBEX REQUIRED ibex)
message (STATUS "Found Ibex version ${IBEX_VERSION}")

################################################################################
# Compile sources
################################################################################
add_subdirectory (src)

################################################################################
# Tests
################################################################################
include(CTest)
if (BUILD_TESTING)
  add_custom_target (check
                      COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure $(ARGS)
                      DEPENDS ibex-plugin COMMENT "Running the tests")
  add_subdirectory (tests EXCLUDE_FROM_ALL)
endif ()
