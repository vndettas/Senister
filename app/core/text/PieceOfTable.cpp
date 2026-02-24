#include "PieceOfTable.h"
#include <QDebug>
#include "Piece.h"
#include "TextEngine.h"
#include <cstddef>
#include <cstdint>
#include <vector>

PieceOfTable::PieceOfTable(const std::filesystem::path filepath) : read_buffer{QString::fromStdString((read_To_Const_Buffer(filepath)))}, add_buffer{}
{

 //later reserve more but now vector reallocation should be tested
  piece_table.reserve(1);
  size_t size = read_buffer.size() - 1;
  piece_table.emplace_back(Piece{0, size, buffer::read_only_buffer});


}

PieceOfTable::PieceOfTable(const QString &_string) : read_buffer{_string}, add_buffer{}
{


 piece_table.reserve(1);
 size_t size = read_buffer.size() - 1;
 piece_table.emplace_back(Piece{0, size, buffer::read_only_buffer});


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

std::vector<Piece>
PieceOfTable::get_Piece_Vector() const
{

    return piece_table;

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
PieceOfTable::print_Logs()
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

    if(pos > this->get_Text_Length()) return {};

int global_length = 0;
int pos2 = pos;
 for(const Piece piece : piece_table){
   if(pos >= global_length && pos < global_length +  piece.length){
       pos2 = pos - global_length + piece.offset;
      return  piece.buffer_type == buffer::add_buffer ? add_buffer.at(pos2) : read_buffer.at(pos2);
   }
   global_length += piece.length;
 }
 qDebug() << "Index at " << pos << " was not found"; 
 return {};

}

QString
PieceOfTable::get_Line(size_t offset, size_t length) const
{


  size_t remaining_length = length;
  size_t global_offset = offset;
  QString line = "";
  for(const Piece piece: piece_table) {
    if(offset >= global_offset && offset <= global_offset + piece.length) {
        size_t local_offset = offset+piece.offset;
        size_t length_from_piece = remaining_length > piece.length ? piece.length : remaining_length;
        line += piece.buffer_type == buffer::add_buffer ? add_buffer.mid(local_offset, length_from_piece) : read_buffer.mid(local_offset, remaining_length);
        remaining_length -= length_from_piece;
        global_offset += piece.length;
     } else {
         return line;
     }
   }
   return line;


}

void
PieceOfTable::erase(size_t offset){


  uint32_t piece_table_global_offset = 0;
  for(size_t itr = 0; itr <= piece_table.size(); ++itr){
    Piece& piece = piece_table[itr];
    qDebug() << "looking for offset " << offset << " current offset pos: " << piece_table_global_offset; 
    if(offset >= piece_table_global_offset && offset <= piece_table_global_offset + piece.length){
       if(offset == piece_table_global_offset) {
        qDebug() << "Delete first char in piece";
       piece.shrink_Front();
        break;
        } else if(offset == piece_table_global_offset + piece.length) {
         qDebug() << "Delete last char in piece";
          piece.shrink_Back();
          break;
        } else {
        qDebug() << "Deletion inside piece executed";
          auto iterator = piece_table.begin() + itr;
          piece_table.insert(iterator+1, Piece(piece.offset + offset, piece.length - offset, piece.buffer_type == buffer::add_buffer ? buffer::add_buffer : buffer::read_only_buffer));
          piece_table[itr].set_Length(piece_table[itr + 1].offset - 1);
          break;
        }
      }
        piece_table_global_offset += piece.length;
    }


}
