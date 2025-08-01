#pragma once
#include <QObject>
#include "InputStrategy.h"
#include <memory>
#include <QKeyEvent>
#include "../UI/CodeUI.h"

class Cursor;
class InputStrategy;
class NormalMode;
class CodeUI;


class InputEngine{

public:

    InputEngine(Cursor* cursor, CodeUI* code_ui);

    void set_Strategy(std::unique_ptr<InputStrategy> strategy);

    void handle_Key(QKeyEvent *event);

    void move_Cursor_Right();

    void update_ui();

private:

    std::unique_ptr<InputStrategy> current_strategy;

    CodeUI* code_ui = nullptr;
 
    Cursor* cursor = nullptr;
};

