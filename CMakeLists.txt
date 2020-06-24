##
## Valentin DIARD, 2020
##
## License:     MIT License
##
## File:        CMakeLists.txt
## Description: Compilation config with CMake tools.
##

cmake_minimum_required(VERSION 3.16)
project(Tetra-Engine)

set(CMAKE_CXX_STANDARD 20)

#
 # Automated Tests Compilation
#

# Note: Don't include main files into tests compilation

add_executable(Tetra-Engine-Testing
        tests/tools/report_hock.cpp
        tests/testing/basics_tests.cpp)
target_link_libraries(Tetra-Engine-Testing -lcriterion)

#
 # Executable Compilation
#

add_executable(Tetra-Engine
        src/private/core/main.cpp)
