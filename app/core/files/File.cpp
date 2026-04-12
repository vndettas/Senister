#include "File.h"

File::File(const std::filesystem::path file_path)
{

  text_data_structure = std::make_unique<PieceOfTable>(file_path);
  text_engine = std::make_unique<TextEngine>(text_data_structure.get());
  name = file_path.filename().string();
  cursor = std::make_unique<Cursor>();


}

float
File::get_scroll_offset()
{

  return scroll_offset_y;


}

float
File::get_scroll_velocity()
{

  return scroll_velocity;


}

void
File::set_scroll_offset(float offset)
{

  scroll_offset_y = offset;


}

void
File::set_scroll_velocity(float velocity)
{

  scroll_velocity = velocity;


}

size_t
File::file_Name_Length() const
{

  return name.length();


}

Cursor*
File::get_Cursor()
{

  assert(cursor);
  return cursor.get();


}

std::string
File::file_Name() const
{

  return name;


}

PieceOfTable*
File::text_Data_Structure() const
{

  return text_data_structure.get();


}

TextEngine*
File::text_Engine() const
{

 return text_engine.get();


}
