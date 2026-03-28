#pragma once
#include <QObject>
#include "InputStrategy.h"
#include <memory>
#include <QKeyEvent>
#include "Cursor.h"
#include <QDebug>
#include "../widgets/CodeUI.h"
#include "../../core/profile/ProfileEngine.h"
#include <QString>
#include "SoundEngine.h"

class Cursor;
class InputStrategy;
class NormalMode;
class InsertMode;
class CodeUI;

class InputEngine {

public:

    InputEngine                                                          (Cursor* cursor, CodeUI* code_ui, SoundEngine* engine);

    ~InputEngine();

    void                                                                 switch_To_Normal_Mode();

    void                                                                 insert_Char(QString character);

    void                                                                 switch_To_Insert_Mode();
    
    void                                                                 set_Strategy(InputStrategy* strategy);

    void                                                                 handle_Key(QKeyEvent *event);

    void                                                                 set_Current_File(std::shared_ptr<File> file);

    void                                                                 open_File_Index(uint32_t index);

    void                                                                 move_Cursor_Right();

    void                                                                 move_Cursor_Left();

    void                                                                 move_Cursor_Up();

    void                                                                 move_Cursor_Down();

    void                                                                 delete_Char_Cursor();

    void                                                                 update_ui();

    void                                                                 save_File();

private:

    InputStrategy*                                           current_strategy;

    std::unique_ptr<NormalMode>                              normal_mode;

    SoundEngine*                                             sound_engine;

    std::unique_ptr<InsertMode>                              insert_mode;

    CodeUI*                                                  code_ui = nullptr;

    Cursor*                                                  cursor = nullptr;
};
