## Tasks to Compile the Program Using CMake (Command Line)

1. **Create a build directory**  
    ```cmd
    mkdir build
    cd build
    ```

2. **Generate build files with CMake**  
    ```cmd
    cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
    ```

3. **Build the project**
    ```cmd
    cmake --build .
    ```

4. **Run the executable**  
    ```cmd
    hello_world.exe
    ```