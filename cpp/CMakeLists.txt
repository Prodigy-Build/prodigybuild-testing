cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

project(numericCpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

file(GLOB sourcefiles lib/*.hpp)
include_directories(include)

# Set the directory of the Catch include files
set(CATCH_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

# Create an interface library called "Catch" and set its include directories
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

# Set the source files for the tests
set(TEST_SOURCES ${PROJECT_SOURCE_DIR}/tests/testmain.cpp)

# Create an executable called "tests" and link the source and test files
add_executable(tests ${sourcefiles} ${TEST_SOURCES})

# Link the Catch library to the tests executable
target_link_libraries(tests Catch)

# Set the target properties for the tests executable
set_target_properties(tests
        PROPERTIES
        COMPILE_FLAGS "-ftest-coverage -fprofile-arcs"
        LINK_FLAGS    "-lgcov --coverage"
        )