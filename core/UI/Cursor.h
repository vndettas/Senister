#pragma once
#include <cstdint>
#include <utility>

class Cursor{
public:

    uint32_t get_Current_Line_Index(); 

    uint32_t get_Current_Symbol_Index();

    std::pair<int, int> get_Cursor_Position();

    void setCurrentLine(uint32_t _current_line_index);
    
    void setCurrentSymbolIndex(uint32_t _current_symbol_index);
    
    // --Movement--
    void move_Right();

    void move_Left();

    void move_Up();

    void move_Down();

private:    

    uint32_t current_line_index = 1;

    uint32_t current_symbol_index = 3;

};