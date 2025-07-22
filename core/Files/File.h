#pragma once

#include <memory>
#include "../Text/PieceOfTable.h"
#include "../Text/TextEngine.h"

class TextEngine;

class File {
public:

    File(){};

    File(const std::filesystem::path path);
    
    std::string get_File_Name() {return name; };

    size_t get_File_Name_Length() {return name.length(); };
    
    PieceOfTable* get_Text_Data_Structure() { return text_data_structure.get(); };

    TextEngine* get_Text_Engine() { return text_engine.get(); };

private:

    std::string name;

    std::unique_ptr<PieceOfTable> text_data_structure;

    std::unique_ptr<TextEngine> text_engine;


};
