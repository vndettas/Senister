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
        Bind(Qt::Key_L, move_Cursor_Right());
}

void NormalMode::move_Cursor_Right(){
    engine->move_Cursor_Right();
}