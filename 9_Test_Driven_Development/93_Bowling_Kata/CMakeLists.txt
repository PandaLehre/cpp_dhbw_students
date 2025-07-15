cmake_minimum_required(VERSION 3.8)

set(This bowling_kata)

project(${This})

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

set(Headers
    src/game.hpp
)

set(Sources
    src/game.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
add_subdirectory(test)

# add_executable(${This}_app src/main.cpp)
