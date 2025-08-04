#include "App.h"

App::App()
{
    std::shared_ptr<FileManager> file_manager = std::make_shared<FileManager>();
    std::shared_ptr<File> first_file = std::make_shared<File>("C:\\Users\\Work\\Documents\\GitHub\\Veditor\\test\\test.cpp");
    std::shared_ptr<File> third_file = std::make_shared<File>("C:\\Users\\Work\\Documents\\GitHub\\Veditor\\test\\test2.cpp");
    file_manager->add_File(first_file);
    file_manager->add_File(third_file);
    window = std::make_unique<CodeUI>(file_manager);
    window->show();
}
