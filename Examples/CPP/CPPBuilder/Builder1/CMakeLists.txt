cmake_minimum_required(VERSION 3.10)
project(Builder1)

# Set the output directory for libraries
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Generate the shared library from sources
# Name the library after the project, which is 'Builder1'
add_library(Builder1 SHARED src/sample1.cpp src/sample2.cpp)
target_include_directories(Builder1 PUBLIC include)

# Add executables for examples
add_executable(example_sample1 examples/example_sample1.cpp)
target_link_libraries(example_sample1 Builder1)

add_executable(example_sample2 examples/example_sample2.cpp)
target_link_libraries(example_sample2 Builder1)

# Setup tests
add_executable(sample1_tests tests/sample1_tests.cpp)
target_link_libraries(sample1_tests Builder1 gtest_main)
add_test(NAME sample1_tests COMMAND sample1_tests)
