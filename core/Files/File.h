// 
// SPDX-License-Identifier: MIT
// /file  : File.h
// Last modified: 2025-08-26 13:01
// 

#pragma once
#include <memory>
#include "../Text/PieceOfTable.h"
#include "../Text/TextEngine.h"

class TextEngine;

class File {
public:

    File                                                (const std::filesystem::path path);             

    size_t                                              file_Name_Length();
    
    std::string                                         file_Name();
    
    PieceOfTable*                                       text_Data_Structure();

    TextEngine*                                         text_Engine();

private:

    std::string                         name;

    std::unique_ptr<PieceOfTable>       text_data_structure;

    std::unique_ptr<TextEngine>         text_engine;


};
