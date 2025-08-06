#include "Cursor.h"

uint32_t Cursor::get_Current_Line_Index(){
    return current_line_index;
}

uint32_t Cursor::get_Current_Symbol_Index(){
    return current_symbol_index;
}

void Cursor::setCurrentLine(uint32_t _current_line_index){ 
    current_line_index = _current_line_index;
}
   
void Cursor::setCurrentSymbolIndex(uint32_t _current_symbol_index){
     current_symbol_index = _current_symbol_index;
}

std::pair<int, int> Cursor::get_Cursor_Position(){
    return std::pair<int, int>(current_line_index, current_symbol_index);
}