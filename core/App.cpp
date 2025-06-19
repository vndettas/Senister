//
// Created by vovab on 07.06.2025.
//

#include "App.h"

App::App()
{
    std::shared_ptr<PieceOfTable> text_data_structure = std::make_shared<PieceOfTable>("..\\test\\test.cpp");
    std::shared_ptr<TextEngine> text_engine = std::make_shared<TextEngine>(text_data_structure);
    file_Manager = std::make_shared<FileManager>();
    file_Manager->add_File(File(text_data_structure, text_engine));
    window = std::make_unique<CodeUI>(file_Manager);
    window->show();
}
