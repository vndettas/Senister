//
// Created by vovab on 07.06.2025.
//

#ifndef VEDITOR_APP_H
#define VEDITOR_APP_H

#include "UI/CodeUI.h"
#include "Files/FileManager.h"


class App {

public:

    App();


private:

    std::unique_ptr<CodeUI> window;

    std::shared_ptr<FileManager> file_Manager;

};


#endif //VEDITOR_APP_H
