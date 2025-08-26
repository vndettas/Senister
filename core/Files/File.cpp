// 
// SPDX-License-Identifier: MIT
// /file  : File.cpp
// Last modified: 2025-08-26 13:01
// 

#include "File.h"

File::File(const std::filesystem::path file_path) {
  text_data_structure = std::make_unique<PieceOfTable>(file_path);
  text_engine = std::make_unique<TextEngine>(text_data_structure.get());
  name = file_path.filename().string();
}

size_t
File::file_Name_Length()
{

  return name.length();

}

std::string
File::file_Name()
{

  return name;

}

PieceOfTable*
File::text_Data_Structure()
{

  return text_data_structure.get();

}

TextEngine*
File::text_Engine()
{

 return text_engine.get(); 

}