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

    File(std::shared_ptr<PieceOfTable>, std::shared_ptr<TextEngine>);

private:

    std::shared_ptr<PieceOfTable> text_data_structure;

    std::shared_ptr<TextEngine> text_engine;


};


#endif //VEDITOR_FILE_H
