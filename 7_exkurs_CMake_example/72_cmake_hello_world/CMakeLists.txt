# Set the minimum required version of CMake
cmake_minimum_required(VERSION 4.0)

# Set the project name and version and specify C++ as the language
project(HelloWorldExample VERSION 1.0.0 LANGUAGES CXX)

# Set the C++ standard to C++17, enforce it, and disable compiler-specific extensions --> should always be used
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add an executable target named 'hello_world' using all .cpp files in the current directory
add_executable(hello_world 
    app/main.cpp
)

# Create a custom library target named 'hello_world_lib' 
add_library(hello_world_lib SHARED
    src/printHelloWorld.cpp
)

# Specify the include directories for the library target
target_include_directories(hello_world_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

# Link the library to the executable target
target_link_libraries(hello_world PRIVATE hello_world_lib)
