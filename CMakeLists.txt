# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(C++Playground VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Optionally, set a variable for sources for clarity
set(SOURCES
    src/main.cpp
    src/trie.cpp
)

# Add include directories
include_directories(include)

# Add an executable based on the source files
add_executable(C++Playground ${SOURCES})

# Link against libraries (if any)
# target_link_libraries(MyProject PUBLIC SomeLibrary)

# If using any third-party libraries stored in 'libs', add them
# add_subdirectory(libs/SomeLibrary)

# Enable testing and add tests
# enable_testing()
# add_subdirectory(tests)

# Install rules (optional)
install(TARGETS C++Playground DESTINATION bin)
install(FILES include/trie.h DESTINATION include)

# CPack packaging (optional, requires including CPack module)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
