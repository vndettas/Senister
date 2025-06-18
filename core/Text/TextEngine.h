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



    inline size_t get_Lines_Count(){
      return line_index_offset.size();
    }

    int getFirstVisibleLine() const;

    void setFirstVisibleLine(int firstVisibleLine);


private:

    std::shared_ptr<PieceOfTable> text_data_structure;

    int first_visible_line = 0;


    std::vector<int> line_index_offset;


};


#endif //VEDITOR_TEXTENGINE_H
