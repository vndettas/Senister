// 
// SPDX-License-Identifier: MIT
// /file  : App.cpp
// Last modified: 2025-08-19 11:54
// 

#include "App.h"

App::App()
{
    std::shared_ptr<FileManager> file_manager = std::make_shared<FileManager>();
    std::shared_ptr<File> first_file = std::make_shared<File>("C:\\Users\\Work\\Documents\\GitHub\\Veditor\\test\\test.cpp");
    std::shared_ptr<File> third_file = std::make_shared<File>("C:\\Users\\Work\\Documents\\GitHub\\Veditor\\test\\test2.cpp");
    std::shared_ptr<File> fourth_file = std::make_shared<File>("C:\\Users\\Work\\Documents\\GitHub\\Veditor\\test\\test2copy.cpp");
    std::shared_ptr<File> fifth_file = std::make_shared<File>("C:\\Users\\Work\\Documents\\GitHub\\Veditor\\test\\testcopy.cpp");
    file_manager->add_File(first_file);
    file_manager->add_File(third_file);
    file_manager->add_File(fourth_file);
    file_manager->add_File(fifth_file);
    window = std::make_unique<CodeUI>(file_manager);
    
    window->show();
}
