//
// Created by vovab on 07.06.2025.
//

#ifndef VEDITOR_TEXTENGINE_H
#define VEDITOR_TEXTENGINE_H


#include <QString>
#include "../UI/CodeUI.h"
#include "../Text/PieceOfTable.h"
class PieceOfTable;

class TextEngine {
public:

    const QString getLine(size_t index);


private:

    std::shared_ptr<PieceOfTable> text_data_structure;

public:

    std::vector<int> line_index_offset;

    void calculateIndexes();


    void setTextDataStructure(const std::shared_ptr<PieceOfTable> &textDataStructure);

};


#endif //VEDITOR_TEXTENGINE_H
