#!/bin/bash

# Check if the correct number of arguments was passed
if [ "$#" -lt 2 ]; then
    echo "Usage: $0 ProjectName SampleName1 [SampleName2 ...]"
    exit 1
fi

# Extract the project name and remove it from the list of arguments
project_name=$1
shift

# Create the main project directory
mkdir -p ${project_name}/{src,examples,include,tests}
echo "Created directory structure for ${project_name}"

# Create the CMakeLists.txt file
touch ${project_name}/CMakeLists.txt
echo "CMakeLists.txt created"

# Iterate over remaining arguments to create sample components
for sample_name in "$@"; do
    # Create source files
    touch ${project_name}/src/${sample_name}.cpp
    echo "Source file ${sample_name}.cpp created"

    # Create header files
    touch ${project_name}/include/${sample_name}.h
    echo "Header file ${sample_name}.h created"

    # Create example files
    touch ${project_name}/examples/${sample_name}_example.cpp
    echo "Example file ${sample_name}_example.cpp created"

    # Create test files
    touch ${project_name}/tests/${sample_name}_tests.cpp
    echo "Test file ${sample_name}_tests.cpp created"
done

echo "Builder components have been successfully created."
