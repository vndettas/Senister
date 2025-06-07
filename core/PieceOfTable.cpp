//
// Created by vovab on 13.03.2025.
//

#include "PieceOfTable.h"


//reads file to read-only buffer
std::string PieceOfTable::readToBuffer(const std::string &filepath) {
  std::ifstream istream(filepath);
  if(!istream){
    std::cout << "opening failed";
  }
  std::string str_buffer((std::istreambuf_iterator<char>(istream)), std::istreambuf_iterator<char>());
  return str_buffer;
}

//initilise read-only buffer and copies it to add buffer
PieceOfTable::PieceOfTable(const std::string& filepath) : read_buffer(QString::fromStdString((readToBuffer(filepath))))
, add_buffer((getReadBuffer()->data()))  {
  piece_table.emplace_back(Piece(0, add_buffer.size(), buffer::add_buffer));

}

QString &PieceOfTable::getAddBuffer() const {
  return (QString &) add_buffer;
}


QString* PieceOfTable::getReadBuffer() const {
  return const_cast<QString *>(&read_buffer);

}

const std::vector<PieceOfTable::Piece>* PieceOfTable::getPieceTable() const {
  return &piece_table;
}

PieceOfTable::Piece::Piece(size_t offset, size_t length, buffer bufferType) : offset(offset), length(length),
                                                                              buffer_type(bufferType) {}

QString &PieceOfTable::getTextRange(size_t offset, size_t length) {
  QString requested_text;
  requested_text.reserve(length);
  size_t current_offset=0;
  for(auto piece: piece_table) {
    if(current_offset + piece.length < offset)
      // size_t local_offset =
      return requested_text;
  }

}
