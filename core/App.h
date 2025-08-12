// 
// SPDX-License-Identifier: MIT
// /file  : App.h
// Last modified: 2025-08-12 17:40
// 

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
