# library.cmake
function(setup_library TARGET_NAME)
  target_include_directories(${TARGET_NAME} PUBLIC include)
  set_target_properties(${TARGET_NAME} PROPERTIES
                        VERSION ${PROJECT_VERSION}
                        SOVERSION ${PROJECT_VERSION_MAJOR})
endfunction()

function(add_google_test_support)
    # Set separate build directory for Google Test
    set(GOOGLE_TEST_BUILD_DIR "${CMAKE_BINARY_DIR}/googletest")

    # Ensure GTest is not installed
    set(INSTALL_GTEST OFF CACHE BOOL "Disable installation of Google Test" FORCE)
    set(GTEST_NO_INSTALL ON CACHE BOOL "Disable installation of Google Test" FORCE)

    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.10.0.zip
        SOURCE_DIR ${GOOGLE_TEST_BUILD_DIR}/src
        BINARY_DIR ${GOOGLE_TEST_BUILD_DIR}/build
    )
    
    FetchContent_MakeAvailable(googletest)

    # Include Google Test's headers for easier access in test projects
    include_directories(${GOOGLE_TEST_BUILD_DIR}/src/googletest/include)
    include_directories(${GOOGLE_TEST_BUILD_DIR}/src/googlemock/include)
endfunction()