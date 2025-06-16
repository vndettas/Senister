cmake_minimum_required(VERSION 3.27)
project(Veditor)

set(CMAKE_PREFIX_PATH "D:/Qt/6.8.2/mingw_64/lib/cmake")
find_package(Qt6 REQUIRED COMPONENTS Gui Core Widgets)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)

add_executable(Veditor
        core/main.cpp
        core/UI/CodeUI.cpp
        core/UI/CodeUI.h
        core/Text/PieceOfTable.cpp
        core/Text/PieceOfTable.h
        core/HELPER/CONSTANTS.h
        core/HELPER/CONSTANTS.h
        core/Text/TextEngine.cpp
        core/Text/TextEngine.h
        core/App.cpp
        core/App.h
        core/App.h
)

target_compile_definitions(Veditor
        PRIVATE
        $<$<CONFIG:Release>:QT_NO_DEBUG_OUTPUT>
)


target_link_libraries(Veditor Qt6::Core Qt6::Gui Qt6::Widgets)


