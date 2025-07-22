#pragma once
#include "UI/CodeUI.h"
#include "Files/FileManager.h"


class App {

public:

    App();


private:

    std::unique_ptr<CodeUI> window;

    std::shared_ptr<FileManager> file_Manager;

};
