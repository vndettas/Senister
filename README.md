# **Project Description**

Lightweight, custom IDE.
Written in C++ using the Qt 6 framework and a custom Piece Table text data structure.

# **Tested On**
**v 0.1.1**

Windows — MinGW (11.0, g++), Qt 6.8.2, CMake 3.27.8

Linux (Ubuntu) — g++ 13.3.0, Qt 6 (installed via package manager), CMake 3.28.3

# **Building the Project**

**Windows**

If you installed Qt manually (e.g. via the Qt Installer), you must specify the path to the Qt CMake configuration in CMakeLists.txt.

```cmake
set(CMAKE_PREFIX_PATH "D:/Qt/6.8.2/mingw_64/lib/cmake") # ← CHANGE THIS LINE
find_package(Qt6 REQUIRED COMPONENTS Gui Core Widgets)
```
Make sure that the Qt version matches your compiler (e.g. MinGW build of Qt for MinGW).

**Linux**

If you installed Qt using a package manager (e.g. apt), no changes are usually required.

Install Qt6 using apt :

```bash
sudo apt install qt6-base-dev qt6-tools-dev qt6-tools-dev-tools
```
