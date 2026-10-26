cmake_minimum_required(VERSION 3.24)
project(C++_Journey)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Download raylib automatically from GitHub
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        master # Pulls latest version dynamically
)

# Optimize the download by skipping raylib's bundled examples
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

# 2. Add your source files
add_executable(${PROJECT_NAME} src/main.cpp)

# 3. Link raylib 
# CMake automatically maps all headers and OS-specific graphics pipelines!
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
