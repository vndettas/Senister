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

    [[nodiscard]] std::optional<QString> get_Line(size_t index);


    void calculate_Indexes();

    explicit TextEngine(const std::shared_ptr<PieceOfTable> &textDataStructure);

    void set_Data_Structre(const std::shared_ptr<PieceOfTable>& text_data_structure);



private:

    std::shared_ptr<PieceOfTable> text_data_structure;


    std::vector<int> line_index_offset;


};


#endif //VEDITOR_TEXTENGINE_H
