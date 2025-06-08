//
// Created by vovab on 07.06.2025.
//

#include "TextEngine.h"

const QString TextEngine::getLine(size_t index) {
  qDebug() << index;
  if(index < line_index_offset.size()) {
    qDebug() << line_index_offset[index + 1] - line_index_offset[index];
    return text_data_structure->getLine(line_index_offset[index],
                                        line_index_offset[index + 1] - line_index_offset[index]);
  }
  return "";
}

void TextEngine::setTextDataStructure(const std::shared_ptr<PieceOfTable> &textDataStructure) {
  text_data_structure=textDataStructure;
  calculateIndexes();
}

void TextEngine::calculateIndexes() {
  const size_t buffer_size = text_data_structure->getTextLength();


  for(int i = 0; i < buffer_size; ++i){
    if(text_data_structure->getCharAt(i) == '\n')
      line_index_offset.push_back(i);
  }
}
