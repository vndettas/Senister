#include "NormalMode.h"

NormalMode::NormalMode(InputEngine *engine) : InputStrategy(engine)
{

  init_Keys();


}

void
NormalMode::handle_Key(QKeyEvent *event)
{

  for(std::pair<Shortcut, function> action : key_bindings){
      if(action.first.get_Key() == event->key() && action.first.get_Modifier() == event->modifiers()){
          action.second();
      }
   }


}

void
NormalMode::init_Keys()
{


   Bind(Qt::Key_L, engine->move_Cursor_Right());
   Bind(Qt::Key_H, engine->move_Cursor_Left());
   Bind(Qt::Key_J, engine->move_Cursor_Down());
   Bind(Qt::Key_K, engine->move_Cursor_Up());
   Bind(Shortcut(Qt::Key_1, Qt::ControlModifier), engine->open_File_Index(0));
   Bind(Shortcut(Qt::Key_2, Qt::ControlModifier), engine->open_File_Index(1));
   Bind(Shortcut(Qt::Key_3, Qt::ControlModifier), engine->open_File_Index(2));
   Bind(Shortcut(Qt::Key_X), engine->delete_Char_Cursor());
   Bind(Shortcut(Qt::Key_S, Qt::ControlModifier), engine->save_File());
   Bind(Shortcut(Qt::Key_I), engine->switch_To_Insert_Mode());


}
