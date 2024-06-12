# library.cmake
function(setup_library TARGET_NAME)
  target_include_directories(${TARGET_NAME} PUBLIC include)
  set_target_properties(${TARGET_NAME} PROPERTIES
                        VERSION ${PROJECT_VERSION}
                        SOVERSION ${PROJECT_VERSION_MAJOR})
endfunction()

include(FetchContent)

function(add_google_test_support)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.10.0.zip
    )

    # Set separate output directories for Google Test
    set(GOOGLE_TEST_BUILD_DIR "${CMAKE_BINARY_DIR}/googletest")

    # Build Google Test in a separate directory
    FetchContent_MakeAvailable(googletest)

    # Include Google Test's headers for easier access in test projects
    include_directories(${googletest_SOURCE_DIR}/include)
    # Disable installation for Google Test
    set(GTEST_NO_INSTALL ON CACHE INTERNAL "" FORCE)

    # Add definitions for GTest main to avoid multiple inclusion issues
    add_definitions(-DGTEST_HAS_PTHREAD=0)
endfunction()