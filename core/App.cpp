//
// Created by vovab on 07.06.2025.
//

#include "App.h"

App::App()
{
    file_manager = std::make_shared<FileManager>();
    File first_file = File("..\\test\\test.cpp");
    file_Manager->add_File(first_file);
    window = std::make_unique<CodeUI>(file_Manager);
    window->show();
}
