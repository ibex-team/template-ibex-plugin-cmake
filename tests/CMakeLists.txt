set (TESTS_LIST TestPlugin01)

foreach (test ${TESTS_LIST})
  # /!\ The test and the target building the executable have the same name
  add_executable (${test} ${test}.cpp ${test}.h)
  target_link_libraries (${test} ibex-myplugin)
  add_dependencies (check ${test})
  add_test (${test} ${test})
endforeach ()

# If the tests need the CppUnit library, one can use the following command to
# look for it
#   find_package (CppUnit)
# The script FindCppUnit.cmake is installed by Ibex and the CMAKE_MODULE_PATH
# is set accordingly by ibex_init_common.
# Once the command is executed, the variable CPPUNIT_FOUND can be use to test if
# the library was found or not, and the imported target CppUnit::CppUnit can be
# use in target_link_libraries to link against it.
