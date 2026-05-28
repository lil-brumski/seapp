# Welcome to the github repository for Seapp!


---
## Table of Contents
* [What is Seapp?](#what-is-seapp)
* [Who are the target audience?](#who-are-the-target-audience)
* [Libraries Used](#libraries-used)
* [Prerequisites](#prerequisites)
* [How to build application](#how-to-build-application)
* [Documentation](#documentation)
* [Project Licence](#project-licence)
* [Contributors](#contributors)

---
## What is Seapp?
Seapp is a C++ application written for Computer Vision using the [OpenCV](https://opencv.org/) C++ library, undergraduate mathematics & numerical computations, and ROS2 integration (in the future). Feel free to fork and contribute to this project!

---
## Who are the target audience?
Engineering students, but anyone interested in Linear Algebra or Computer Vision can also use.

---
## Libraries Used
  - [Eigen3](https://gitlab.com/libeigen/eigen) - Mozilla Public License Version 2.0 (MPL2)
  - [Argparse](https://github.com/p-ranav/argparse) - MIT License
  - [OpenCV](https://github.com/opencv/opencv) - Apache 2.0 License
  
---
## Prerequisites
  - A C++ 23 Compiler ([MINGW](https://www.mingw-w64.org/getting-started/msys2/), GCC, [Clang](https://github.com/llvm/llvm-project/releases), [MSVC](https://visualstudio.microsoft.com/downloads/), etc)
  - CMake
  - Ninja

On Debian/Ubuntu-based Linux distros
```bash
$ sudo apt install gcc g++ cmake ninja-build
```

---
## How to build application

```bash
$ git clone --depth=1 --recurse-submodules https://github.com/lil-brumski/seapp.git
```

OR

```bash
$ git clone https://github.com/lil-brumski/seapp.git
$ cd seapp
$ git submodule update --init --recursive
```

##
Create a sub-folder in that seapp/ folder
- On Linux/macOS Systems:
```bash
$ mkdir build
$ cd build
```

##

There are options for building:
- `-DWITH_OPENCV=ON` - Build with OpenCV support. You must have already installed or compiled opencv for this to work.
- `-DWITH_SYSTEM_EIGEN=ON` - Build with the Eigen library installed on the system. If option is set to off it will download Eigen3 from Gitlab first before compiling it alongside your project.

Compiling from the build folder
```bash
$ cmake -DWITH_OPENCV=OFF -DWITH_SYSTEM_EIGEN=OFF -DCMAKE_BUILD_TYPE=Release ..
$ cmake --build . --config Release -j$(nproc)
```

Within the build folder and children folders, look for the `seapp` or `seapp.exe` executable and run:
```bash
$ ./seapp --version
$ ./seapp --help
$ ./seapp --imatrix 1 1 1   3 3 4   2 1 3 --b-vectors 6 20 13
```
 ---

## Documentation
- Coming soon...
---

## Project Licence
- This project uses the [MIT](License) License.
---

## Contributors
  - [lil-brumski](https://github.com/lil-brumski) - Computer Engineering student at RSU, Nigeria.