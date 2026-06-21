#include "Cursor.h"
#include <QDebug>

Cursor::Cursor()
{

  cursor_fading = new QPropertyAnimation(this, "cursor_opacity");
  cursor_fading->setDuration(1300);
  cursor_fading->setKeyValueAt(0.0, 0.0f);
  cursor_fading->setKeyValueAt(0.5, 1.5f);
  cursor_fading->setKeyValueAt(1.5, 0.0f);
  cursor_fading->setEasingCurve(QEasingCurve::InOutQuad);
  cursor_fading->setLoopCount(-1);
  cursor_fading->start();


}

uint32_t
Cursor::get_Current_Line_Index()
{

  return current_line_index;


}

void
Cursor::set_Cursor_Mode(CursorState state)
{

  cursor_state = state;


}

CursorState
Cursor::get_Cursor_Mode()
{

  return cursor_state;


}

uint32_t
Cursor::get_Current_Symbol_Index(uint32_t row_size)
{

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

float
Cursor::get_Cursor_Opacity()
{

  return cursor_opacity;


}

void
Cursor::set_Cursor_Opacity(float opacity)
{

  cursor_opacity = opacity;


}
