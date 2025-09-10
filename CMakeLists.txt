cmake_minimum_required(VERSION 3.27)
project(Senister)



find_program(CCACHE_PROGRAM ccache)
#ccache used for faster recompile, it is not obligatory and the project will compile without it but i highly reccomend to install it since its very useful
if(CCACHE_PROGRAM)
    message(STATUS "ccache: ${CCACHE_PROGRAM}")
    set(CMAKE_C_COMPILER_LAUNCHER ccache)
    set(CMAKE_CXX_COMPILER_LAUNCHER ccache)
endif()


#building in debug unless specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

find_package(Qt6 6.9.2 REQUIRED COMPONENTS Gui Core Widgets)

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


#target_compile_definitions( Senister
#PRIVATE
#$<$<CONFIG:Release>:QT_NO_DEBUG_OUTPUT>
#)

add_subdirectory(app/core)
add_subdirectory(app/ui)


#------------Test-----------------
enable_testing()
add_executable(
       PieceTableTest test/PieceTableTest.cc app/core/text/PieceOfTable.cpp)

target_link_libraries( PieceTableTest Qt6::Core GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(PieceTableTest)
