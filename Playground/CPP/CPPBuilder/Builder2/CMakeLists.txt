cmake_minimum_required(VERSION 3.10)
project(Builder2)

# Set the output directory for libraries and executables within the project
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/builder2/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/builder2/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/builder2/bin)

# Generate the shared library from sources
# Name the library after the project, which is 'Builder2'
add_library(Builder2 SHARED src/sample3.cpp src/sample4.cpp)
target_include_directories(Builder2 PUBLIC include)

if(WITH_EXAMPLES)
    # Add executables for examples
    add_executable(example_sample3 examples/example_sample3.cpp)
    target_link_libraries(example_sample3 Builder2)

    add_executable(example_sample4 examples/example_sample4.cpp)
    target_link_libraries(example_sample4 Builder2)

    install(TARGETS example_sample3 example_sample4
            RUNTIME DESTINATION bin)
endif()

# Installation rules for Builder2
install(TARGETS Builder2
        LIBRARY DESTINATION lib  # For shared libraries
        ARCHIVE DESTINATION lib) # For static libraries

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION include/Builder2)

if(WITH_TESTS)
    # Setup tests
    add_executable(sample3_tests tests/sample3_tests.cpp)
    target_link_libraries(sample3_tests Builder2 gtest_main)
    add_test(NAME sample3_tests COMMAND sample3_tests)
    
    add_executable(sample4_tests tests/sample4_tests.cpp)
    target_link_libraries(sample4_tests Builder2 gtest_main)
    add_test(NAME sample4_tests COMMAND sample4_tests)
    
    install(TARGETS sample3_tests sample4_tests 
            RUNTIME DESTINATION bin/tests)
endif()
