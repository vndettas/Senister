#include "InputEngine.h"
#include "NormalMode.h"

InputEngine::InputEngine(Cursor* _cursor, CodeUI* _code_ui){
    code_ui = _code_ui;
    current_strategy = std::make_unique<NormalMode>(this);
    cursor = _cursor;
}
void InputEngine::handle_Key(QKeyEvent *event){
current_strategy->handle_Key(event);
}

void InputEngine::update_ui(){
    code_ui->update();
}

void InputEngine::move_Cursor_Right(){
    cursor->move_Right();
    update_ui();

}

void InputEngine::set_Strategy(std::unique_ptr<InputStrategy> strategy){
current_strategy = std::move(strategy);
}