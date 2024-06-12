cmake_minimum_required(VERSION 3.10)
project(CPPBuilderProject)

# Include the configuration
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(library)
include(configuration)

# Google Test support, conditional on WITH_TESTS flag
if(WITH_TESTS)
    enable_testing()
    add_google_test_support()
endif()

# Conditional inclusion of components
if (WITH_Builder1)
    add_subdirectory(Builder1)
endif()

if (WITH_Builder2)
    add_subdirectory(Builder2)
endif()

if (WITH_Algorithms)
    add_subdirectory(Algorithms)
endif()

# Documentation with Doxygen, conditional on WITH_DOCS
if(WITH_DOCS)
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
      set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in)
      set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

      configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
      add_custom_target(doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
        
      install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc/
              DESTINATION share/doc/cppbuilderproject)
    endif()
endif()