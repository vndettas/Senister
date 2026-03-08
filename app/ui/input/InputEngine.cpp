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
  if((cursor_pos.first == code_ui->Text_Engine()->get_Lines_Count() - 1) && cursor_pos.second + 1 == code_ui->Text_Engine()->get_Line_Size(cursor_pos.first)){

  }
  //Any index in row except last one
  else if(code_ui->Text_Engine()->get_Prev_Line_Start_Pos(cursor_pos.first) + cursor_pos.second + 2 < code_ui->Text_Engine()->get_Next_Line_End_Pos(cursor->get_Cursor_Position().first))  {

    cursor->move_Right();
    update_ui();

    //Last index in row case
  } else {
    move_Cursor_Down();
    cursor->set_Current_Symbol_Index(0);
    cursor->set_Prefferable_Symbol_Index(0);
    update_ui();
  }

}


void
InputEngine::move_Cursor_Down()
{

    if(cursor->get_Cursor_Position().first + 1 < code_ui->Text_Engine()->get_Lines_Count()){
    cursor->move_Down(code_ui->Text_Engine()->get_Line_Size(cursor->get_Cursor_Position().first + 1));
  }
    update_ui();

}

void
InputEngine::set_Current_File(std::shared_ptr<File> file)
{

  cursor = file->get_Cursor();
}

void
InputEngine::move_Cursor_Up()
{
    uint32_t current_line = cursor->get_Cursor_Position().first;

  if(current_line > 0){            
    uint32_t target_line_size = code_ui->Text_Engine()->get_Line_Size(cursor->get_Cursor_Position().first - 1); 
    cursor->move_Up(target_line_size);
    update_ui();

  }
}

void
InputEngine::move_Cursor_Left()
{

  std::pair<int,int> cursor_pos = cursor->get_Cursor_Position();
  //First symbol in whole text case
  if(cursor_pos.second == 0 && cursor_pos.first == 0){
  //First index in any row except first one
  } else if(cursor_pos.second == 0){
    //cursor->setCurrentSymbolIndex((code_ui->Text_Engine()->get_Next_Line_End_Pos(cursor->get_Cursor_Position().first) - 1) - 1);
    move_Cursor_Up();
    cursor->set_Current_Symbol_Index(code_ui->Text_Engine()->get_Line_Size(cursor_pos.first - 1) - 1);
    cursor->set_Prefferable_Symbol_Index(code_ui->Text_Engine()->get_Line_Size(cursor_pos.first - 1) - 1);
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

void
InputEngine::save_File()
{
  code_ui->Text_Engine()->save_File();

}

