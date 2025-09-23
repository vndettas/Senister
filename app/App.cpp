//
// SPDX-License-Identifier: MIT
// /file  : App.cpp
// Last modified: 2025-08-19 11:54
//

#include "App.h"

App::App()
{

    std::shared_ptr<FileManager> file_manager = std::make_shared<FileManager>();
    std::shared_ptr<File> third_file = std::make_shared<File>("/home/vendetta/github/Senister/test/test.cpp");
    file_manager->add_File(third_file);
    window = std::make_unique<CodeUI>(file_manager);

    window->show();

}
