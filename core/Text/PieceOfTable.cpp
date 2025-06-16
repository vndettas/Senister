//
// Created by vovab on 13.03.2025.
//

#include "PieceOfTable.h"
#include <QDebug>

std::string PieceOfTable::read_To_Const_Buffer(const std::filesystem::path filepath)
{
  std::ifstream istream(filepath);
  if(!istream){
    std::cout << "opening failed";
  }
  std::string str_buffer((std::istreambuf_iterator<char>(istream)), std::istreambuf_iterator<char>());
  return str_buffer;
}

//reads whole file to const buffer
PieceOfTable::PieceOfTable(const std::filesystem::path filepath) : read_buffer(QString::fromStdString((read_To_Const_Buffer(filepath)))), add_buffer((get_Read_Buffer()->data())) {
  piece_table.emplace_back(Piece(0, add_buffer.size(), buffer::add_buffer));
}

QString &PieceOfTable::get_Add_Buffer() const
{
  return (QString &) add_buffer;
}


QString* PieceOfTable::get_Read_Buffer() const
{
  return const_cast<QString *>(&read_buffer);

}

const std::vector<Piece>* PieceOfTable::get_Piece_Table() const
{
  return &piece_table;
}

Piece::Piece(size_t offset, size_t length, buffer bufferType) : offset(offset), length(length),
                                                                              buffer_type(bufferType) {}

QString &PieceOfTable::get_Text_Range(size_t offset, size_t length)
{
  QString requested_text;
  requested_text.reserve(length);
  size_t current_offset=0;
  for(auto piece: piece_table) {
    if(current_offset + piece.length < offset)
      // size_t local_offset =
      return requested_text;
  }

}

size_t PieceOfTable::get_Text_Length()
{
  size_t length = 0;
 for(const Piece& piece : piece_table){
   length += piece.length;
 }
  return length;
}

QChar PieceOfTable::get_Char_At(size_t pos)
{
 for(const Piece& piece : piece_table){
   if(pos >= piece.offset && pos <= piece.length){
     if(piece.buffer_type == buffer::add_buffer){
       return add_buffer.at(pos);
     } else if(piece.buffer_type == buffer::read_only_buffer){
       return read_buffer.at(pos);
     }
   }
 }
}

QString PieceOfTable::get_Line(size_t offset, size_t length)
{
  for(const Piece &piece: piece_table) {
    if(offset >= piece.offset && offset <= piece.length) {
      if(piece.buffer_type == buffer::add_buffer) {
        return add_buffer.mid(offset, length);
      } else if(piece.buffer_type == buffer::read_only_buffer) {
        return read_buffer.mid(offset, length);
      }
    }
  }
}
