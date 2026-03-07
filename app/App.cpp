#include "App.h"

App::App()
{

    std::shared_ptr<FileManager> file_manager = std::make_shared<FileManager>();
    std::shared_ptr<File> third_file = std::make_shared<File>("/home/vendetta/github/Senister/test/test.cpp");
    std::shared_ptr<File> first_file = std::make_shared<File>("/home/vendetta/github/Senister/test/test.cpp");
    file_manager->add_File(third_file);
    std::shared_ptr<File> second_file = std::make_shared<File>("/home/vendetta/github/Senister/test/test.cpp");
    file_manager->add_File(second_file);
    std::shared_ptr<File> fourth_file = std::make_shared<File>("/home/vendetta/github/Senister/test/test.cpp");
    file_manager->add_File(fourth_file);
    file_manager->add_File(first_file);
    file_manager->add_File(first_file);
    file_manager->add_File(first_file);
    file_manager->add_File(first_file);
    file_manager->add_File(first_file);
    file_manager->add_File(first_file);
    window = std::make_unique<CodeUI>(file_manager);

    window->show();

}
