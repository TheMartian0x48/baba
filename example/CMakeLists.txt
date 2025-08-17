# Create executable
add_executable(example example.c)

# Link with baba library
target_link_libraries(example baba)

# Include headers
target_include_directories(example PRIVATE ../include)

