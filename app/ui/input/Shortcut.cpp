#include "Shortcut.h"

Shortcut::Shortcut(Qt::Key _key, Qt::KeyboardModifier _modifier)
{

    key = _key;
    modifier = _modifier;

}
Qt::Key
Shortcut::get_Key() const
{

    return key;

}

Qt::KeyboardModifier
Shortcut::get_Modifier() const
{

    return modifier;

}
