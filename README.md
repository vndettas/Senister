Lightweight, cross-platform custom IDE built for personal use.
Written in C++ using the Qt 6 framework and a custom Piece Table text data structure.

✅ Tested On
Windows — MinGW, Qt 6.8.2, CMake
Linux (Ubuntu) — GCC 13.3.0, Qt 6 (from package manager), CMake

Building the Project
Windows
If you installed Qt manually (e.g. via the Qt Installer), you must specify the path to the Qt CMake configuration in CmakeLists.txt:

Make sure the Qt version matches your compiler (e.g. MinGW build of Qt for MinGW).

Linux
If you installed Qt using a package manager (like apt), no additional configuration is usually required:

bash
Copy
Edit
sudo apt install qt6-base-dev qt6-tools-dev qt6-tools-dev-tools
cmake ..
CMake will automatically find Qt through system paths.
