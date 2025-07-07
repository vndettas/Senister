//
// Created by vovab on 19.06.2025.
//

#ifndef VEDITOR_FILE_H
#define VEDITOR_FILE_H

#include <memory>
#include "../Text/PieceOfTable.h"
#include "../Text/TextEngine.h"

class File {
public:

    File(){};

    File(std::shared_ptr<PieceOfTable>, std::shared_ptr<TextEngine>);

    File(const std::filesystem::path path);
    

    std::shared_ptr<PieceOfTable> get_Text_Data_Structure() { return text_data_structure; };

    std::shared_ptr<TextEngine> get_Text_Engine() { return text_engine; };

private:

    std::shared_ptr<PieceOfTable> text_data_structure;

    std::shared_ptr<TextEngine> text_engine;


};


#endif //VEDITOR_FILE_H