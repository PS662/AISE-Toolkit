# config.cmake

# Option to treat warnings as errors - can be turned on/off via CMake command line or GUI
option(TREAT_WARNINGS_AS_ERRORS "Treat compiler warnings as errors." ON)

# Compiler-specific configurations
if(CMAKE_COMPILER_IS_GNUCXX)
    # Add flags for GCC
    add_compile_options(-Wall)  # Enable all warnings
    
    if(TREAT_WARNINGS_AS_ERRORS)
        add_compile_options(-Werror)  # Treat all warnings as errors
    endif()

    # Specific warning suppressions
    add_compile_options(-Wno-maybe-uninitialized)
elseif(MSVC)
    # Add flags for MSVC
    add_compile_options(/W3)  # Set warning level to 3

    if(TREAT_WARNINGS_AS_ERRORS)
        add_compile_options(/WX)  # Treat warnings as errors
    endif()

    # Disable specific warnings in MSVC
    add_definitions(/D_CRT_SECURE_NO_WARNINGS)
endif()

# Define preprocessor macros globally
add_definitions(-DMY_GLOBAL_DEFINITION)
