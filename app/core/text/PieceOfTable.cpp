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
  piece_table.reserve(20);
  path = filepath;
  size_t size = read_buffer.size() - 1;
  piece_table.emplace_back(Piece{0, size, buffer::read_only_buffer});


}

PieceOfTable::PieceOfTable(const QString &_string) : read_buffer{_string}, add_buffer{}
{

 piece_table.reserve(20);
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


void
PieceOfTable::save_File(){

  QFile file(path);

  if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
  QTextStream out(&file);

  for(const Piece& piece : piece_table){

    if(piece.buffer_type == buffer::add_buffer){

      out << add_buffer.mid(piece.offset, piece.length);

    } else {

      out << read_buffer.mid(piece.offset, piece.length);

    }
   }
  }

  file.close();

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

  uint32_t global_length = 0;
  uint32_t pos2 = pos;
  for(const Piece piece : piece_table){
    if(pos >= global_length && pos < global_length +  piece.length){
       pos2 = pos - global_length + piece.offset;
      return  piece.buffer_type == buffer::add_buffer ? add_buffer.at(pos2) : read_buffer.at(pos2);
   }
    global_length += piece.length;
 }
 return {};

}


QString PieceOfTable::get_Line(size_t offset, size_t length) const 
{
    if (length == 0) return "";

    QString line = "";
    uint32_t current_piece_global_start = 0;
    uint32_t chars_needed = length;
    uint32_t current_read_offset = offset;

    for (const Piece& piece : piece_table) {
        uint32_t current_piece_global_end = current_piece_global_start + piece.length;

        if (current_read_offset >= current_piece_global_start && current_read_offset < current_piece_global_end) {
            
            uint32_t rel_start = current_read_offset - current_piece_global_start;
            
            uint32_t chars_available = piece.length - rel_start;
            uint32_t chars_to_take = std::min(chars_needed, chars_available);
            
            uint32_t buffer_index = piece.offset + rel_start;
            
            if (piece.buffer_type == buffer::add_buffer) {
                line += add_buffer.mid(buffer_index, chars_to_take);
            } else {
                line += read_buffer.mid(buffer_index, chars_to_take); 
            }
            
            chars_needed -= chars_to_take;
            current_read_offset += chars_to_take; 
            
            if (chars_needed == 0) {
                break; 
            }
        }
        
        current_piece_global_start += piece.length;
    }
    
    return line;
}



void
PieceOfTable::erase(size_t offset)
{

  uint32_t piece_table_global_offset = 0;

for(size_t itr = 0; itr < piece_table.size(); ++itr){
    Piece& piece = piece_table[itr];

if(offset >= piece_table_global_offset && offset < piece_table_global_offset + piece.length){
    uint32_t position_in_piece = offset - piece_table_global_offset;

    //First in piece 
    //So just shrink piece from front
    if(position_in_piece == 0){

      piece.shrink_Front();

    //Last in piece
    //Shrink piece from back
    } else if(position_in_piece == piece.length - 1){

      piece.shrink_Back();
    
    } else {

    //end of first piece
    uint32_t right_offset = piece.offset + position_in_piece + 1; 
    //length of right piece
    //old length  - offset in piece - 1
    uint32_t right_length = piece.length - position_in_piece - 1;
    

    //update left piece length
    //now its equal to length before deleted symbol
    piece.set_Length(position_in_piece);

    auto right_iterator = piece_table.begin() + itr + 1;

    piece_table.insert(right_iterator, Piece(right_offset, right_length, piece.buffer_type));
      
    
    }

    if(piece_table[itr].length == 0) piece_table.erase(piece_table.begin() + itr); 

    break;

    }

    piece_table_global_offset += piece.length;

  }
  
}


