#pragma once

#include "InputStrategy.h"

class NormalMode : public InputStrategy {

public:

    NormalMode(InputEngine *engine);

    void move_Cursor_Right();

    void handle_Key(QKeyEvent *key) override;

private:

    void init_Keys() override;


};