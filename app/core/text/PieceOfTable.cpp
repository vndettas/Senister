//
// SPDX-License-Identifier: MIT
// /file  : PieceOfTable.cpp
// Last modified: 2025-08-19 11:58
//

#include "PieceOfTable.h"
#include "Piece.h"
#include "TextEngine.h"
#include <cstddef>

PieceOfTable::PieceOfTable(const std::filesystem::path filepath) : read_buffer{QString::fromStdString((read_To_Const_Buffer(filepath)))}, add_buffer{}
{

 //later reserve more but now vector reallocation should be tested
  piece_table.reserve(1);
  piece_table.emplace_back(Piece{0, read_buffer.size(), buffer::read_only_buffer});


}

PieceOfTable::PieceOfTable(const QString &_string) : read_buffer{_string}, add_buffer{}
{


 piece_table.reserve(1);
 piece_table.emplace_back(Piece{0, read_buffer.size(), buffer::read_only_buffer});


}

std::string
PieceOfTable::read_To_Const_Buffer(const std::filesystem::path filepath)
{


  std::ifstream istream(filepath);
  if(!istream){
    throw std::runtime_error("Failed to open file");
  }
  std::string str_buffer((std::istreambuf_iterator<char>(istream)), std::istreambuf_iterator<char>());
  return str_buffer;


}


QString
&PieceOfTable::get_Add_Buffer() const
{

  return (QString &) add_buffer;

}

QString*
PieceOfTable::get_Read_Buffer() const
{

  return const_cast<QString *>(&read_buffer);

}

const std::vector<Piece>*
PieceOfTable::get_Piece_Table() const
{
  return &piece_table;

}

uint32_t
PieceOfTable::get_Text_Length()
{


  uint32_t length = 0;
 for(const Piece& piece : piece_table){
   length += piece.length;
 }
  return length;


}

void
PieceOfTable::print_Logs_Piece_Table()
{


  size_t itr = 0;
  for( const Piece piece : piece_table){
    std::cout << "piece : " << itr << "\n";
    std::cout << "type: : " << piece.buffer_type << '\n';
    std::cout << "offset : " << piece.offset << " ";
    std::cout << "length : " << piece.length;
    std::cout << "\n";
    itr++;
  }
  std::cout << "---\n";


}

QChar
PieceOfTable::get_Char_At(size_t pos)
{

 for(const Piece piece : piece_table){
   if(pos >= piece.offset && pos <= piece.offset +  piece.length){
     if(piece.buffer_type == buffer::add_buffer){
       return add_buffer.at(pos - piece.offset);
     } else if(piece.buffer_type == buffer::read_only_buffer){
       return read_buffer.at(pos - piece.offset);
     }
   }
 }
 return {};


}

QString
PieceOfTable::get_Line(size_t offset, size_t length) const
{


  size_t remaining_length = length;
  size_t new_offset = offset;
  QString line = "";
  for(const Piece piece: piece_table) {
    if(new_offset >= piece.offset && new_offset < piece.offset + piece.length) {
        size_t length_from_piece = remaining_length > piece.length ? piece.length : remaining_length;
        line += piece.buffer_type == buffer::add_buffer ? add_buffer.mid(new_offset - piece.offset, length_from_piece) : read_buffer.mid(new_offset - piece.offset, remaining_length);
        remaining_length -= length_from_piece;
        new_offset += length_from_piece;
      if(remaining_length == 0) return line;
     }
   }
   return line;


}

void
PieceOfTable::erase(size_t offset){


  for(size_t itr = 0; itr <= piece_table.size(); ++itr){
    Piece& piece = piece_table[itr];
    if(offset >= piece.offset && offset <= piece.offset + piece.length){
       if(offset == piece.offset) {
        piece.shrink_Front();
        } else if(offset == piece.offset + piece.length) {
          piece.shrink_Back();
        } else {
          auto iterator = piece_table.begin() + itr;
          piece_table.insert(iterator+1, Piece(piece.offset + offset, piece.length - offset, piece.buffer_type == buffer::add_buffer ? buffer::add_buffer : buffer::read_only_buffer));
          piece.set_Length(piece.offset + offset);
          print_Logs_Piece_Table();
          break;
        }
      }
    }


}
