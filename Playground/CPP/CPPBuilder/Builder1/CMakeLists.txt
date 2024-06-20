cmake_minimum_required(VERSION 3.10)
project(Builder1)

# Set the output directory for libraries and executables within the project
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/builder1/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/builder1/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/builder1/bin)

# Generate the shared library from sources
# Name the library after the project, which is 'Builder1'
add_library(Builder1 SHARED src/sample1.cpp src/sample2.cpp)
target_include_directories(Builder1 PUBLIC include)

if(WITH_EXAMPLES)
    # Add executables for examples
    add_executable(example_sample1 examples/example_sample1.cpp)
    target_link_libraries(example_sample1 Builder1)

    add_executable(example_sample2 examples/example_sample2.cpp)
    target_link_libraries(example_sample2 Builder1)

    install(TARGETS example_sample1 example_sample2
            RUNTIME DESTINATION bin)
endif()

# Installation rules for Builder1
install(TARGETS Builder1
        LIBRARY DESTINATION lib  # For shared libraries
        ARCHIVE DESTINATION lib) # For static libraries

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION include/Builder1)

if(WITH_TESTS)
    # Setup tests
    add_executable(sample1_tests tests/sample1_tests.cpp)
    target_link_libraries(sample1_tests Builder1 gtest_main)
    add_test(NAME sample1_tests COMMAND sample1_tests)

    # Test for sample2
    add_executable(sample2_tests tests/sample2_tests.cpp)
    target_link_libraries(sample2_tests Builder1 gtest_main)
    add_test(NAME sample2_tests COMMAND sample2_tests)

    install(TARGETS sample1_tests sample2_tests 
            RUNTIME DESTINATION bin/tests)
endif()