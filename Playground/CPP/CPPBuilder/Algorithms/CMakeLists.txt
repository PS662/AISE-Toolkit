cmake_minimum_required(VERSION 3.10)
project(Algorithms)

# Set the output directory for libraries and executables within the project
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/algorithms/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/algorithms/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/algorithms/bin)

# Generate the shared library from sources
# Name the library after the project, which is 'Algorithms'
add_library(Algorithms SHARED src/dfs.cpp)
target_include_directories(Algorithms PUBLIC include)

if(WITH_EXAMPLES)
    # Add executables for examples
    add_executable(example_dfs examples/example_dfs.cpp)
    target_link_libraries(example_dfs Algorithms)
    install(TARGETS example_dfs
            RUNTIME DESTINATION bin)
endif()

# Installation rules for Algorithms
install(TARGETS Algorithms
        LIBRARY DESTINATION lib  # For shared libraries
        ARCHIVE DESTINATION lib) # For static libraries

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION include/Algorithms)

if (WITH_TESTS)
    # Setup tests
    add_executable(dfs_tests tests/dfs_tests.cpp)
    target_link_libraries(dfs_tests Algorithms gtest_main)
    add_test(NAME dfs_tests COMMAND dfs_tests)
    install(TARGETS dfs_tests 
            RUNTIME DESTINATION bin/tests)
endif()