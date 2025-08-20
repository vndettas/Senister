// 
// SPDX-License-Identifier: MIT
// /file  : File.cpp
// Last modified: 2025-08-20 17:53
// 

#include "File.h"

File::File(const std::filesystem::path file_path) {
  text_data_structure = std::make_unique<PieceOfTable>(file_path);
  text_engine = std::make_unique<TextEngine>(text_data_structure.get());
  name = file_path.filename().string();
}