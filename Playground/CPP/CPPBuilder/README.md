
# CPPBuilderProject

## Overview
**CPPBuilderProject** is a modular C++ project designed to demonstrate a flexible approach using multiple builders. Each builder corresponds to a specific component or library, which can be built independently and contributes to the overall functionality of the project.

## Project Structure
```
CPPBuilderProject/
│
├── Builder1/       # Sources, headers, and tests for Builder1
│   ├── src/        # Source files
│   ├── include/    # Header files
│   └── tests/      # Test files
│
├── Builder2/       # Sources, headers, and tests for Builder2
│   ├── src/        # Source files
│   ├── include/    # Header files
│   └── tests/      # Test files
│
├── cmake/          # CMake scripts and configuration files
├── doc/            # Documentation resources and Doxyfile configurations
└── CMakeLists.txt  # Root CMake configuration file
```

## Getting Started

### Prerequisites
Ensure the following tools are installed on your system:
- **CMake** (version 3.10 or newer)
- **C++ Compiler** (supporting at least C++11, e.g., GCC, Clang, MSVC)
- **Doxygen** (for generating documentation)
- **Google Test** (integrated via CMake for unit testing)

### Building the Project
To build the project, follow these steps:

1. **Clone the repository and navigate to the project directory:**
    ```bash
    git clone https://github.com/PS662/AISE-Toolkit
    cd AISE-Toolkit/Playground/CPP/CPPBuilder
    ```

2. **Generate the build system:**
    ```bash
    cmake -S . -B build/
    ```

3. **Build the project:**
    ```bash
    cmake --build build/
    ```

### Running Tests
To execute all unit tests, use the following commands:
```bash
cd build/
ctest
```

### Generating Documentation
To generate the project documentation using Doxygen:

1. **Navigate to the build directory:**
    ```bash
    cd build/
    ```

2. **Run the documentation build target:**
    ```bash
    cmake --build . --target doc_doxygen
    ```

Documentation will be available in the `docs/` directory within the build folder.
