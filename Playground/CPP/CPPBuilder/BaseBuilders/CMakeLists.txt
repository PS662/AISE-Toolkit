cmake_minimum_required(VERSION 3.10)
project(Algorithms)

# Set the output directory for libraries and executables within the project
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/algorithms/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/algorithms/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/algorithms/bin)

# Generate the shared library from sources
add_library(Algorithms SHARED src/algorithms.cpp src/graph.cpp)
target_include_directories(Algorithms PUBLIC include)

# Conditional build for examples
if(WITH_EXAMPLES)
    add_executable(example_algorithms examples/example_algorithms.cpp)
    target_link_libraries(example_algorithms Algorithms)
    install(TARGETS example_algorithms
            RUNTIME DESTINATION bin)
    
    add_executable(example_base_object examples/example_base_object.cpp)
    target_link_libraries(example_base_object Algorithms)  # Link to Algorithms for demonstration
    install(TARGETS example_base_object
            RUNTIME DESTINATION bin)
endif()

# Installation rules for Algorithms
install(TARGETS Algorithms
        LIBRARY DESTINATION lib  # For shared libraries
        ARCHIVE DESTINATION lib) # For static libraries

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION include/Algorithms)

# Conditional build for tests
if (WITH_TESTS)
    # Setup tests
    add_executable(algorithms_test tests/algorithms_test.cpp)
    target_link_libraries(algorithms_test Algorithms gtest_main)
    add_test(NAME algorithms_test COMMAND algorithms_test)
    install(TARGETS algorithms_test
            RUNTIME DESTINATION bin/tests)
    
    add_executable(base_object_test tests/base_object_test.cpp)
    target_link_libraries(base_object_test Algorithms gtest_main)
    add_test(NAME base_object_test COMMAND base_object_test)
    install(TARGETS base_object_test
            RUNTIME DESTINATION bin/tests)
endif()