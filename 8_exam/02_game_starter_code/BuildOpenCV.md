# Instructions to build OpenCV for the game project

## Download the OpenCV source code

Download the OpenCV source code from the official OpenCV GitHub repository or website. 
Alternatively, you can use the following command to clone the repository:

```bash
git clone https://github.com/opencv/opencv.git
```

## Build OpenCV
Navigate to the OpenCV directory and create a build directory:

```bash
cd opencv
mkdir build
cd build
``` 

## Configure the build with CMake
Run CMake to configure the build.You can specify the build type option as needed. 
If you do not have the testing libraries installed, you can disable the tests and examples to speed up the build process.
If you are using MinGW, you can specify the generator as "MinGW Makefiles".

Afterwards, use --build to compile the OpenCV library. Using the `-j N` option can speed up the build process by allowing parallel compilation, where `N` is the number of CPU cores you want to use.

```bash
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=OFF -G "MinGW Makefiles" ..
cmake --build . -j 32
```

To be able to use the OpenCV library in the game project, you need to add the build path `opencv\build\bin` to the PATH variable

## Testing the program
After the build is complete, use the same procedure to build the Game starter project.
Make sure, that the `haarcascade_frontalface_default.xml` file is copied to the same directory as the executable of the game project. You can find this file in the opencv folder.