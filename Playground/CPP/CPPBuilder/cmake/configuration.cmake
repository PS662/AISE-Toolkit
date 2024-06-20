# configuration.cmake

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
# Define options for enabling or disabling components of the project
option(WITH_Builder1 "Build the Builder1 component" OFF)
option(WITH_Builder2 "Build the Builder2 component" OFF)
option(WITH_Algorithms "Build the Algorithms component" OFF)
option(WITH_EXAMPLES "Build with examples" OFF)
option(WITH_TESTS "Enable building of tests." OFF)
option(WITH_DOCS "Enable Documentation generation." OFF)

# Add preprocessor definitions based on the options
if (WITH_Builder1)
  add_definitions(-DWITH_Builder1)
endif()

if (WITH_Builder2)
  add_definitions(-DWITH_Builder2)
endif()

if (WITH_Algorithms)
  add_definitions(-DWITH_Algorithms)
endif()

if (WITH_TESTS)
  add_definitions(-DENABLE_TESTS)
endif()

if (WITH_DOCS)
  add_definitions(-DENABLE_DOCS)
endif()

# Handling custom installation and build paths
set(CPPBuilder_INSTALL_PATH "" CACHE PATH "Custom installation path.")
if(CPPBuilder_INSTALL_PATH)
  set(CMAKE_INSTALL_PREFIX ${CPPBuilder_INSTALL_PATH})
endif()