cmake_minimum_required(VERSION 3.10)
project(Builder2)
# git rm --cached -r .
# git reset --hard
# Set the output directory for libraries
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Generate the shared library from sources
# Name the library after the project, which is 'Builder2'
add_library(Builder2 SHARED src/sample3.cpp src/sample4.cpp)
target_include_directories(Builder2 PUBLIC include)

# Add executables for examples
add_executable(example_sample3 examples/example_sample3.cpp)
target_link_libraries(example_sample3 Builder2)

add_executable(example_sample4 examples/example_sample4.cpp)
target_link_libraries(example_sample4 Builder2)

# Setup tests
add_executable(sample3_tests tests/sample3_tests.cpp)
target_link_libraries(sample3_tests Builder2 gtest_main)
add_test(NAME sample3_tests COMMAND sample3_tests)