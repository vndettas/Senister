//
// SPDX-License-Identifier: MIT
// /file  : Shortcut.cpp
// Last modified: 2025-08-12 17:40
//

#include "Shortcut.h"

Shortcut::Shortcut(Qt::Key _key, Qt::KeyboardModifier _modifier)
{

    key = _key;
    modifier = _modifier;

}
Qt::Key
Shortcut::get_Key()
{

    return key;

}

Qt::KeyboardModifier
Shortcut::get_Modifier()
{

    return modifier;

}
