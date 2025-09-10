// 
// SPDX-License-Identifier: MIT
// /file  : Shortcut.h
// Last modified: 2025-08-12 17:40
// 

#pragma once
#include <QKeyEvent>

struct Shortcut {
    
public:

Shortcut(Qt::Key _key, Qt::KeyboardModifier _modifier = Qt::NoModifier);

friend bool operator<(const Shortcut& first,  const Shortcut& second){ return static_cast<int>(first.key) < static_cast<int>(second.key); };


inline Qt::Key get_Key() const { return key; };

 Qt::KeyboardModifier get_Modifier() const {return modifier; };

private:

    Qt::Key key;

    Qt::KeyboardModifier modifier = Qt::NoModifier;

};