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


  QString &getTextRange(size_t start, size_t length)
  {

  }

QString* PieceOfTable::getReadBuffer() const {
  return const_cast<QString *>(&read_buffer);

}

const std::vector<Piece>* PieceOfTable::getPieceTable() const {
  return &piece_table;
}
