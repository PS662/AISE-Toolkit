cmake_minimum_required(VERSION 3.10)
project(BaseBuilders)

# Set the output directory for libraries and executables within the project
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/base_builders/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/base_builders/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/base_builders/bin)


# Generate the shared library from sources
add_library(BaseBuilders SHARED src/algorithms.cpp src/graph.cpp src/matrix.cpp)
target_include_directories(BaseBuilders PUBLIC include)

find_package(IntelDPCPP)
if (IntelDPCPP_FOUND)
    add_definitions(-DSYCL)
    target_link_libraries(BaseBuilders PUBLIC SYCL::SYCL)
endif()

# Conditional build for examples
if(WITH_EXAMPLES)
    add_executable(example_base_object examples/example_base_object.cpp)
    target_link_libraries(example_base_object BaseBuilders)  # Link to BaseBuilders for demonstration
    install(TARGETS example_base_object
            RUNTIME DESTINATION bin)

    add_executable(example_algorithms examples/example_algorithms.cpp)
    target_link_libraries(example_algorithms BaseBuilders)
    install(TARGETS example_algorithms
            RUNTIME DESTINATION bin)

    add_executable(example_graph examples/example_graph.cpp)
    target_link_libraries(example_graph BaseBuilders)
    install(TARGETS example_graph
            RUNTIME DESTINATION bin)

    add_executable(example_matrix examples/example_matrix.cpp)
    target_link_libraries(example_matrix BaseBuilders)
    install(TARGETS example_matrix
            RUNTIME DESTINATION bin)
endif()

# Installation rules for BaseBuilders
install(TARGETS BaseBuilders
        LIBRARY DESTINATION lib  # For shared libraries
        ARCHIVE DESTINATION lib) # For static libraries

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION include/BaseBuilders)

# Conditional build for tests
if (WITH_TESTS)
    # Setup tests
    add_executable(algorithms_test tests/algorithms_test.cpp)
    target_link_libraries(algorithms_test BaseBuilders gtest_main)
    add_test(NAME algorithms_test COMMAND algorithms_test)
    install(TARGETS algorithms_test
            RUNTIME DESTINATION bin/tests)
    
    add_executable(base_object_test tests/base_object_test.cpp)
    target_link_libraries(base_object_test BaseBuilders gtest_main)
    add_test(NAME base_object_test COMMAND base_object_test)
    install(TARGETS base_object_test
            RUNTIME DESTINATION bin/tests)

    add_executable(graph_test tests/graph_test.cpp)
    target_link_libraries(graph_test BaseBuilders gtest_main)
    add_test(NAME graph_test COMMAND graph_test)
    install(TARGETS graph_test
            RUNTIME DESTINATION bin/tests)

    add_executable(matrix_test tests/matrix_test.cpp)
    target_link_libraries(matrix_test BaseBuilders gtest_main)
    add_test(NAME matrix_test COMMAND matrix_test)
    install(TARGETS matrix_test
            RUNTIME DESTINATION bin/tests)
endif()