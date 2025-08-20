// 
// SPDX-License-Identifier: MIT
// /file  : File.h
// Last modified: 2025-08-20 17:52
// 

#pragma once
#include <memory>
#include "../Text/PieceOfTable.h"
#include "../Text/TextEngine.h"

class TextEngine;

class File {
public:

    File(){};

    File(const std::filesystem::path path);
    
    //Getters

    std::string File_Name() {return name; };

    size_t FIle_Name_Length() {return name.length(); };
    
    PieceOfTable* Text_Data_Structure() { return text_data_structure.get(); };

    TextEngine* Text_Engine() { return text_engine.get(); };

private:

    std::string name;

    std::unique_ptr<PieceOfTable> text_data_structure;

    std::unique_ptr<TextEngine> text_engine;


};
