//
// Created by vovab on 07.06.2025.
//

#ifndef VEDITOR_APP_H
#define VEDITOR_APP_H

#include "UI/CodeUI.h"


class App {

public:

    App();

    std::unique_ptr<CodeUI> window;

    std::shared_ptr<TextEngine> text_engine;

    std::shared_ptr<PieceOfTable> text_data_structure;

private:

};


#endif //VEDITOR_APP_H
