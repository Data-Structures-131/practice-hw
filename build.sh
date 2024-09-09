#!/bin/bash

# Create build directory if it doesn't exist
if [ ! -d "build" ]; then
    mkdir build
fi

# Change to build directory
cd build

# Run CMake and Build the Project
cmake ..
make

# Run the program and redirect output to output.txt
./main > ../output.txt
