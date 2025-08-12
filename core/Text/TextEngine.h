// 
// SPDX-License-Identifier: MIT
// /file  : TextEngine.h
// Last modified: 2025-08-12 17:40
// 

#pragma once
#include "../UI/CodeUI.h"
#include "../Text/PieceOfTable.h"
#include <utility>


class Cursor;
class QString;
class PieceOfTable;

class TextEngine {
public:

    explicit TextEngine(PieceOfTable* textDataStructure);

    [[nodiscard]] std::optional<QString> get_Line(size_t index);

    void calculate_Indexes();

    void set_Data_Structre(PieceOfTable* text_data_structure);

    void delete_Char_Cursor(std::pair<int, int> cursor_pos);

    size_t get_Lines_Count();

    [[nodiscard]] uint32_t getFirstVisibleLine() const;

    void setFirstVisibleLine(uint32_t firstVisibleLine);


private:

    PieceOfTable* text_data_structure;
    
    uint32_t first_visible_line = 0;

    std::vector<int> line_index_offset;


};

