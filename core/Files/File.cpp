//
// Created by vovab on 19.06.2025.
//

#include "File.h"

File::File(std::shared_ptr<PieceOfTable> _piece_of_table, std::shared_ptr<TextEngine> _text_engine)
{
  text_data_structure = std::move(_piece_of_table);
  text_engine = std::move(_text_engine);
}
File(const std::filesystem::path file_path)
{
  text_data_structure = std::make_shared<PieceOfTable>(file_path);
  text_engine = std::make_shared<TextEngine>(text_data_structure);
}