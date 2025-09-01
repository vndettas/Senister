// 
// SPDX-License-Identifier: MIT
// /file  : InputStrategy.h
// Last modified: 2025-09-01 22:25
// 

#pragma once

#include <QKeyEvent>
#include "Shortcut.h"
#include <functional>
#include "../Input/InputEngine.h"

using function = std::function<void()>;
#define Bind(Shortcut, function) key_bindings[{Shortcut}] = [this](){ function; };

class InputEngine;

class InputStrategy {

public:

    InputStrategy                                                           (InputEngine *_engine) : engine(_engine){};

    virtual void                                                            handle_Key(QKeyEvent *key) = 0;

private:

    virtual void                                                            init_Keys() = 0;

protected:

    InputEngine*                                        engine = nullptr;

    std::map<Shortcut, function>                        key_bindings;

};