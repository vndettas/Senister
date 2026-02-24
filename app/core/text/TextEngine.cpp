//
// SPDX-License-Identifier: MIT
// /file  : TextEngine.cpp
// Last modified: 2025-08-12 17:40
//

#include "../text/TextEngine.h"
#include <iostream>
#include <QDebug>

TextEngine::TextEngine(PieceOfTable* textDataStructure) : text_data_structure(textDataStructure)
{

  calculate_Indexes();

}


[[nodiscard]] std::optional<QString>
TextEngine::get_Line(size_t index)
{


  size_t line_index = index;
  if(index < line_index_offset.size()){
    size_t start = line_index_offset[line_index];
    size_t end;


    if(line_index + 1 < line_index_offset.size()){
      end = line_index_offset[line_index + 1];
    } else {
      end = text_data_structure->get_Text_Length();
    }

    return text_data_structure->get_Line(start, end - start);
  } else {
    return {};
  } 
}

void
TextEngine::set_Data_Structre(PieceOfTable* text_data_structure)
{

  this->text_data_structure = text_data_structure;
  calculate_Indexes();

}

void
TextEngine::calculate_Indexes()
{


    const size_t buffer_size = text_data_structure->get_Text_Length();
    line_index_offset.clear();
    line_index_offset.push_back(0);
  for(size_t i = 0; i < buffer_size; ++i && (i + 1) < buffer_size){
     if(text_data_structure->get_Char_At(i) == '\n' ){
      line_index_offset.push_back(i + 1);
      
    }
  }


}

uint32_t
TextEngine::getFirstVisibleLine() const
{

  return first_visible_line;

}

void
TextEngine::setFirstVisibleLine(uint32_t firstVisibleLine)
{

  first_visible_line=firstVisibleLine;

}

size_t
TextEngine::get_Lines_Count()
{

  return line_index_offset.size();

}

void
TextEngine::delete_Char_Cursor(std::pair<int, int> cursor_pos)
{

  uint32_t offset = line_index_offset[cursor_pos.first] + cursor_pos.second;
  text_data_structure->erase(offset);
  calculate_Indexes();

}
