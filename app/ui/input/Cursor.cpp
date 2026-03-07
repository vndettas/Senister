#include "Cursor.h"
#include <QDebug>

uint32_t
Cursor::get_Current_Line_Index()
{

    return current_line_index;

}

uint32_t
Cursor::get_Current_Symbol_Index(uint32_t row_size)
{

    qDebug() << "row_size: " << row_size;
    qDebug() << "pref: " << preferrable_symbol_index;
    qDebug() << "curr:" << current_symbol_index;
    return current_symbol_index;
}

void
Cursor::set_Current_Line(uint32_t _current_line_index)
{

    current_line_index = _current_line_index;

}

void
Cursor::set_Current_Symbol_Index(uint32_t _current_symbol_index)
{

     current_symbol_index = _current_symbol_index;

}

void
Cursor::set_Prefferable_Symbol_Index(uint32_t _prefferable_symbol_index)
{

  preferrable_symbol_index = _prefferable_symbol_index;
}

std::pair<int, int>
Cursor::get_Cursor_Position()
{

    qDebug() << "line: " << current_line_index << " symbol: " << current_symbol_index;
    return std::pair<int, int>(current_line_index , current_symbol_index);

}

void
Cursor::move_Right()
{

    current_symbol_index++;
    preferrable_symbol_index++;

}

void
Cursor::move_Left()
{

    current_symbol_index--;
    preferrable_symbol_index--;

}

void
Cursor::move_Up(uint32_t line_size)
{

    if(current_line_index > 0){

    current_line_index -= 1;
  
  if(preferrable_symbol_index > line_size){
    current_symbol_index = line_size - 1;
  } else {
  current_symbol_index = preferrable_symbol_index;

  }
}

}

void
Cursor::move_Down(uint32_t line_size)
{

    current_line_index += 1;
  if(preferrable_symbol_index > line_size){
    current_symbol_index = line_size - 1;
  } else {
  current_symbol_index = preferrable_symbol_index;

}

}


