#pragma once
#include <cstdint>
#include <utility>

class Cursor {
public:

    void                                                                                set_Current_Line(uint32_t _current_line_index);

    void                                                                                set_Current_Symbol_Index(uint32_t _current_symbol_index);
    
    void                                                                                set_Prefferable_Symbol_Index(uint32_t _prefferable_symbol_index);

    void                                                                                move_Right();

    void                                                                                move_Up(uint32_t line_size);

    void                                                                                move_Down(uint32_t line_size);

    void                                                                                move_Left();

    std::pair<int, int>                                                                 get_Cursor_Position();

    uint32_t                                                                            get_Current_Symbol_Index(uint32_t row_size);

    uint32_t                                                                            get_Current_Line_Index();

private:

    uint32_t                                            current_line_index = 0;

    uint32_t                                            preferrable_symbol_index = 0;

    uint32_t                                            current_symbol_index = 0;

};
