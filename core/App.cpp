//
// Created by vovab on 07.06.2025.
//

#include "App.h"

App::App() {
  text_engine = std::make_shared<TextEngine>();
  text_data_structure = std::make_shared<PieceOfTable>("..\\test\\test.cpp");
  window = std::make_unique<CodeUI>(text_engine, text_data_structure);
  text_engine->setTextDataStructure(text_data_structure);
  window->show();

}
