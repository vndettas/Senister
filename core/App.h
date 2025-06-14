//
// Created by vovab on 07.06.2025.
//

#ifndef VEDITOR_APP_H
#define VEDITOR_APP_H

#include "UI/CodeUI.h"


class App {

public:

    App();


private:

    std::unique_ptr<CodeUI> window;

    std::shared_ptr<TextEngine> text_engine;

    std::shared_ptr<PieceOfTable> text_data_structure;

};


#endif //VEDITOR_APP_H
