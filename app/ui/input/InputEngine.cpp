#include "InputEngine.h"
#include <iostream>
#include "NormalMode.h"

InputEngine::InputEngine(Cursor* _cursor, CodeUI* _code_ui)
{


    code_ui = _code_ui;
    current_strategy = std::make_unique<NormalMode>(this);
    cursor = _cursor;


}

void
InputEngine::handle_Key(QKeyEvent *event)
{

    current_strategy->handle_Key(event);

}

void
InputEngine::delete_Char_Cursor()
{

    code_ui->Text_Engine()->delete_Char_Cursor(code_ui->get_Cursor()->get_Cursor_Position());
    update_ui();

}

void
InputEngine::update_ui()
{

    assert(code_ui);
    code_ui->update();

}

void
InputEngine::move_Cursor_Right()
{

  std::pair<int, int> cursor_pos = cursor->get_Cursor_Position();
  //qDebug() << "cursor row:" << cursor_pos.first;
  //qDebug() << "cursor symbol index: " << cursor_pos.second;
  //qDebug() << "line size: "<< code_ui->Text_Engine()->get_Line_Size(cursor_pos.first);
  //Last symbol in last row case
  if((cursor_pos.first == code_ui->Text_Engine()->get_Lines_Count() - 1) && cursor_pos.second + 1 == code_ui->Text_Engine()->get_Line_Size(cursor_pos.first)){

  }
  //Any index in row except last one
  else if(code_ui->Text_Engine()->get_Prev_Line_Start_Pos(cursor_pos.first) + cursor_pos.second + 2 < code_ui->Text_Engine()->get_Next_Line_End_Pos(cursor->get_Cursor_Position().first))  {

    cursor->move_Right();
    update_ui();

    //Last index in row case
  } else {
    cursor->move_Down();
    cursor->setCurrentSymbolIndex(0);
    update_ui();
  }

}


void
InputEngine::move_Cursor_Down()
{

    if(cursor->get_Cursor_Position().first + 1 < code_ui->Text_Engine()->get_Lines_Count()){
    cursor->move_Down();
  }
    update_ui();

}

void
InputEngine::move_Cursor_Up()
{

    cursor->move_Up();
    update_ui();

}

void
InputEngine::move_Cursor_Left()
{

  std::pair<int,int> cursor_pos = cursor->get_Cursor_Position();
  //First symbol in whole text case
  if(cursor_pos.second == 0 && cursor_pos.first == 0){
  //First index in any row except first one
  } else if(cursor_pos.second == 0){
    cursor->move_Up();
    //cursor->setCurrentSymbolIndex((code_ui->Text_Engine()->get_Next_Line_End_Pos(cursor->get_Cursor_Position().first) - 1) - 1);
    cursor->setCurrentSymbolIndex(code_ui->Text_Engine()->get_Line_Size(cursor_pos.first - 1) - 2);
    update_ui();
    //Any index except first one 
  } else if(cursor_pos.second != 0){
    cursor->move_Left();
    update_ui();

  }

} 

void InputEngine::set_Strategy(std::unique_ptr<InputStrategy> strategy) {
current_strategy = std::move(strategy);

}


void
InputEngine::open_File_Index(uint32_t index)
{

    code_ui->set_Current_File_Index(index);

}
