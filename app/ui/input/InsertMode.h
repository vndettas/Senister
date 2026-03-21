#pragma once
#include <iostream>
#include "InputStrategy.h"


class InputEngine;


class InsertMode : public InputStrategy {

public:

    InsertMode                                                                  (InputEngine *engine);
    
    void                                                                        handle_Key(QKeyEvent *key) override;

private:

    void                                                                        init_Keys() override;


};

