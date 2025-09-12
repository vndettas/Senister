//
// SPDX-License-Identifier: MIT
// /file  : NormalMode.h
// Last modified: 2025-08-12 17:40
//

#pragma once
#include "InputStrategy.h"

class NormalMode : public InputStrategy {

public:

    NormalMode                                                                  (InputEngine *engine);

    void                                                                        move_Cursor_Right();

    void                                                                        move_Cursor_Left();

    void                                                                        handle_Key(QKeyEvent *key) override;

private:

    void                                                                        init_Keys() override;


};
