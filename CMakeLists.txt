cmake_minimum_required(VERSION 3.27)
project(Veditor)


set(CMAKE_C_COMPILER_LAUNCHER ccache)
set(CMAKE_CXX_COMPILER_LAUNCHER ccache)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Example (Linux):  /home/user/Qt/6.6.2/gcc_64/lib/cmake
# Example (Windows): D:/Qt/6.8.2/mingw_64/lib/cmake
#Qt path configuration
set(CMAKE_PREFIX_PATH "D:/Qt/6.8.2/mingw_64/lib/cmake") # ← CHANGE THIS LINE
find_package(Qt6 REQUIRED COMPONENTS Gui Core Widgets)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)


add_executable(Veditor
        core/main.cpp
        core/UI/CodeUI.cpp
        core/Text/PieceOfTable.cpp
        core/Text/TextEngine.cpp
        core/App.cpp
        core/UI/LineNumerator.cpp
        core/Input/InputEngine.cpp
        core/Input/VimStrategy.cpp
        core/Files/File.cpp
        core/Files/FileManager.cpp
)


target_compile_definitions(Veditor
        PRIVATE
        $<$<CONFIG:Release>:QT_NO_DEBUG_OUTPUT>
)


target_link_libraries(Veditor Qt6::Core Qt6::Gui Qt6::Widgets)


