# Motivation for CMake

To Compile the program of this folder, multiple steps need to be conducted. First, the cpp files are individually compiled to .o files, then the linker combines them. This can be done using an extension like C/C++ Runner.

```Cmd
g++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference -g3 -O0 -c c:\C\DHBW_Code\2025\cpp_dhbw\02_lecture\7_exkurs_CMake_example\71_cmake_hello_world_starter_code\main.cpp -o .\build\Debug\main.o

g++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference -g3 -O0  -c c:\C\DHBW_Code\2025\cpp_dhbw\02_lecture\7_exkurs_CMake_example\71_cmake_hello_world_starter_code\printHelloWorld.cpp -o .\build\Debug\printHelloWorld.o

g++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference -g3 -O0   .\build\Debug\main.o .\build\Debug\printHelloWorld.o -o .\build\Debug\outDebug.exe
```

Manual commands are complex and time consuming, the small extensions are not able to handle more complex use-cases:

- Complex folder structures, like:
    ```
    project_root/
    ├── app/
    │   └── main.cpp
    ├── src/
    │   └── printHelloWorld.cpp
    ├── include/
    │   └── printHelloWorld.h
    ```
- Creating a library (e.g. static or shared library)
- Creating projects with multiple targets (e.g. executables, libraries, tests)
- Handling dependencies from external libraries (e.g. Boost, OpenCV, etc.)
- Cross-platform compatibility (Windows, Linux, macOS)
- Integration of unit testing frameworks
