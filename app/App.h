#pragma once
#include "ui/widgets/CodeUI.h"
#include "core/files/FileManager.h"
#include "ui/input/SoundEngine.h"
#include "core/profile/ProfileEngine.h"


class App {

public:

    App                                                     ();


private:

    std::unique_ptr<CodeUI>                        window;

    std::unique_ptr<FileManager>                   file_manager;

    std::unique_ptr<SoundEngine>                   sound_engine;

    std::unique_ptr<ProfileEngine>                 profile_manager;

};
