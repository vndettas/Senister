add_library(senister_core STATIC
text/PieceOfTable.cpp
text/TextEngine.cpp
files/File.cpp
files/FileManager.cpp
)

target_include_directories(senister_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(senister_core PUBLIC Qt6::Core)
