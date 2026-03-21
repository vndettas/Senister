#include "InsertMode.h"
InsertMode::InsertMode(InputEngine *engine) : InputStrategy(engine)
{

    init_Keys();

}

void
InsertMode::handle_Key(QKeyEvent *event)
{

  QString character = event->text();

  //Method is print checks whether it is printable key e.g. A B C 
  //If it isnt printable it means its probably esc backspace etc
  if(character[0].isPrint()){
   engine->insert_Char(character); 
   engine->move_Cursor_Right();
  }
  for(std::pair<Shortcut, function> action : key_bindings){
        if(action.first.get_Key() == event->key() && action.first.get_Modifier() == event->modifiers()){
            action.second();
        }
    }


}

void
InsertMode::init_Keys()
{

    Bind(Qt::Key_Escape, engine->switch_To_Normal_Mode());

}
