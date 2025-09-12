//
// SPDX-License-Identifier: MIT
// /file  : App.h
// Last modified: 2025-08-12 17:40
//

#pragma once
#include "ui/widgets/CodeUI.h"
#include "core/files/FileManager.h"


class App {

public:

    App                                                     ();


private:

    std::unique_ptr<CodeUI>                        window;

    std::shared_ptr<FileManager>                   file_Manager;

};
