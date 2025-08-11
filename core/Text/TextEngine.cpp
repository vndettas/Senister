#include "../Text/TextEngine.h"

[[nodiscard]] std::optional<QString> TextEngine::get_Line(size_t index) {
  if(index < line_index_offset.size()) {
    return text_data_structure->get_Line(line_index_offset[index], line_index_offset[index + 1] - line_index_offset[index]);
  } else {
    return {};
  }
}

void TextEngine::set_Data_Structre(PieceOfTable* text_data_structure) {
  this->text_data_structure = text_data_structure;
  calculate_Indexes();
}

void TextEngine::calculate_Indexes() {
    const size_t buffer_size = text_data_structure->get_Text_Length();

    line_index_offset.reserve(buffer_size);
    line_index_offset.push_back(0);

  for(size_t i = 0; i < buffer_size; ++i){
     if(text_data_structure->get_Char_At(i) == '\n'){
      line_index_offset.push_back(i);
    }
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

size_t TextEngine::get_Lines_Count(){
  return line_index_offset.size();
}

void TextEngine::delete_Char_Cursor(std::pair<int, int> cursor_pos){
  uint32_t offset = line_index_offset[cursor_pos.first] + cursor_pos.second;
  text_data_structure->delete_Char(offset);
}