#include "File.h"

// File::File(std::shared_ptr<PieceOfTable> _piece_of_table, std::shared_ptr<TextEngine> _text_engine)
// {
//   text_data_structure = std::move(_piece_of_table);
//   text_engine = std::move(_text_engine);
// }
File::File(const std::filesystem::path file_path)
{
  text_data_structure = std::make_unique<PieceOfTable>(file_path);
  text_engine = std::make_unique<TextEngine>(text_data_structure.get());
  name = file_path.filename().string();
}