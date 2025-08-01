#include "NormalMode.h"

NormalMode::NormalMode(InputEngine *engine) : InputStrategy(engine){
    init_Keys();
}

void NormalMode::handle_Key(QKeyEvent *event){
    for( auto pox : key_bindings){
        if(pox.first.get_Key() == event->key()){
            pox.second();
        }
    }
}


void NormalMode::init_Keys() {
        Bind(Qt::Key_L, engine->move_Cursor_Right());
        Bind(Qt::Key_H, engine->move_Cursor_Left());
        Bind(Qt::Key_J, engine->move_Cursor_Down());
        Bind(Qt::Key_K, engine->move_Cursor_Up());
}