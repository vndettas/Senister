//
// Created by vovab on 19.06.2025.
//

#include "File.h"

File::File(std::shared_ptr<PieceOfTable> _piece_of_table, std::shared_ptr<TextEngine> _text_engine) {
  text_data_structure = std::move(_piece_of_table);
  text_engine = std::move(_text_engine);
}
