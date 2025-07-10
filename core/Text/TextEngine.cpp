//
// Created by vovab on 07.06.2025.
//

#include "TextEngine.h"

[[nodiscard]] std::optional<QString> TextEngine::get_Line(size_t index)
  {
  if(index < line_index_offset.size()) {
    return text_data_structure->get_Line(line_index_offset[index], line_index_offset[index + 1] - line_index_offset[index]);
  } else {
    return {};
  }
}

void TextEngine::set_Data_Structre(PieceOfTable* text_data_structure)
  {
  this->text_data_structure = text_data_structure;
  calculate_Indexes();
}

void TextEngine::calculate_Indexes()
  {
    const size_t buffer_size = this->text_data_structure->get_Text_Length();

    line_index_offset.reserve(buffer_size);

  for(size_t i = 0; i < buffer_size; ++i){
     if(text_data_structure->get_Char_At(i) == '\n')
      line_index_offset.push_back(i);
  }
}

TextEngine::TextEngine(PieceOfTable* textDataStructure) : text_data_structure(textDataStructure) {
  calculate_Indexes();
}

uint32_t TextEngine::getFirstVisibleLine() const {
  return first_visible_line;
}

void TextEngine::setFirstVisibleLine(uint32_t firstVisibleLine) {
  first_visible_line=firstVisibleLine;
}
