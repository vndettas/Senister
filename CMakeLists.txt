cmake_minimum_required(VERSION 3.27)
project(Veditor)



find_program(CCACHE_PROGRAM ccache)
#ccache used for faster recompile, it is not obligatory and the project will compile without it but i highly reccomend to install it since its very useful
if(CCACHE_PROGRAM)
 message(STATUS "ccache: ${CCACHE_PROGRAM}")
 set(CMAKE_C_COMPILER_LAUNCHER ccache)
 set(CMAKE_CXX_COMPILER_LAUNCHER ccache)
endif()


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

#Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
        )
        
FetchContent_MakeAvailable(googletest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        


add_executable(Veditor
core/main.cpp
core/UI/FileBar.cpp
core/UI/CodeUI.cpp
core/Text/PieceOfTable.cpp
core/Text/TextEngine.cpp
core/App.cpp
core/UI/LineNumerator.cpp
core/UI/Cursor.cpp
core/Input/InputEngine.cpp
core/Input/NormalMode.cpp
core/Files/File.cpp
core/Input/Shortcut.cpp
core/Files/FileManager.cpp
)


target_compile_definitions(Veditor
PRIVATE
$<$<CONFIG:Release>:QT_NO_DEBUG_OUTPUT>
)

target_link_libraries(Veditor Qt6::Core Qt6::Gui Qt6::Widgets)


#------------Test-----------------
enable_testing()
add_executable(
       PieceTableTest test/PieceTableTest.cc)

target_link_libraries( PieceTableTest GTest::gtest_main ) 
include(GoogleTest)
gtest_discover_tests(PieceTableTest)