#include "InputEngine.h"
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

    cursor->move_Right();
    update_ui();

}


void
InputEngine::move_Cursor_Down()
{
    qDebug() << code_ui->Text_Engine()->get_Lines_Count();

    if(cursor->get_Cursor_Position().first < code_ui->Text_Engine()->get_Lines_Count()){
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

    cursor->move_Left();
    update_ui();

}

void
InputEngine::set_Strategy(std::unique_ptr<InputStrategy> strategy)
{

current_strategy = std::move(strategy);

}


void
InputEngine::open_File_Index(uint32_t index)
{

    code_ui->set_Current_File_Index(index);

}
