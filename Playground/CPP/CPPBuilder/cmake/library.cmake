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
    
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    # Include Google Test's headers for easier access in test projects
    include_directories(${googletest_SOURCE_DIR}/include)
endfunction()