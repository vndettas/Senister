add_executable(senister_ui
input/Cursor.cpp
input/InputEngine.cpp
input/NormalMode.cpp
input/Shortcut.cpp
widgets/CodeUI.cpp
widgets/FileBar.cpp
widgets/LineNumerator.cpp
../App.cpp
../main.cpp
)

target_include_directories( senister_ui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(senister_ui
        PRIVATE senister_core
        PRIVATE Qt6::Gui Qt6::Widgets
)
