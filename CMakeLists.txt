cmake_minimum_required(VERSION 3.10)
project(ContainerAdapters)

set(CMAKE_CXX_STANDARD 17)

# Add executable
add_executable(main sample_usage-main.cpp Student.cpp)
