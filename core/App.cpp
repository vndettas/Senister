//
// Created by vovab on 07.06.2025.
//

#include "App.h"

App::App()
{
    std::shared_ptr<FileManager> file_manager = std::make_shared<FileManager>();
    std::shared_ptr<File> first_file = std::make_shared<File>("..\\test\\test.cpp");
    std::shared_ptr<File> second_file = std::make_shared<File>("..\\test\\test.cpp");
    file_manager->add_File(first_file);
    file_manager->add_File(second_file);
    window = std::make_unique<CodeUI>(file_manager);
    std::cout << "Window created";
    window->show();
}
