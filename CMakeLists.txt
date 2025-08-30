cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(baba C)

# Include directories
include_directories(include)

# Collect source files
file(GLOB_RECURSE BABA_SOURCES
    "include/baba/**/*.c"
)

# Create static library
add_library(baba STATIC ${BABA_SOURCES})


# Add example subdirectory
add_subdirectory(example)

