//
// Created by vovab on 19.06.2025.
//

#ifndef VEDITOR_FILE_H
#define VEDITOR_FILE_H

#include <memory>
#include "../Text/PieceOfTable.h"
#include "../Text/TextEngine.h"

class TextEngine;

class File {
public:

    File(){};

    File(const std::filesystem::path path);
    
    const std::string name

    PieceOfTable* get_Text_Data_Structure() { return text_data_structure.get(); };

    TextEngine* get_Text_Engine() { return text_engine.get(); };

private:

    std::unique_ptr<PieceOfTable> text_data_structure;

    std::unique_ptr<TextEngine> text_engine;


};


#endif //VEDITOR_FILE_H