#pragma once
#include <vector>
#include <optional>
#include "PieceOfTable.h"
#include <utility>
#include <cstdint>


class Cursor;
class QString;
class PieceOfTable;

class TextEngine {
public:

    TextEngine()=delete;

    explicit TextEngine                                                             (PieceOfTable* textDataStructure);

    void                                                                            setFirstVisibleLine(uint32_t firstVisibleLine);

    void                                                                            calculate_Indexes();

    void                                                                            set_Data_Structre(PieceOfTable* text_data_structure);

    void                                                                            delete_Char_Cursor(std::pair<int, int> cursor_pos);

    size_t                                                                          get_Lines_Count();

    [[nodiscard]] uint32_t                                                          getFirstVisibleLine() const;

    [[nodiscard]] std::optional<QString>                                            get_Line(size_t index);


private:

    PieceOfTable*                                           text_data_structure;

    uint32_t                                                first_visible_line = 1;

    std::vector<int>                                        line_index_offset;


};
