## General


- Senister does not use using namespace (especially std)
- Prefer uint32_t over int and size_t for containers
- Use initializer list whenever possible to avoid double initialization
- Mark constructors which can possibly do narrowing conversion explicit 


## Variables 


Senister uses snake_case for variable
```
std::shared_ptr<FileManager>                   file_manager;
```


PascalCase for class name
```
class NormalMode : public InputStrategy {
```


And hybrid style for function name (upper_Snake_Case)
```
[[nodiscard]] QChar                                                 get_Char_At(size_t pos);
```


## Header file (.h)


- Senister uses #pragma once directive in header files
- Classes and structs first define public: members and then private:
- Default brace convention in class definition


```
class Cursor {
```


- Use 4 space before defining the function return type
- Put function name and arguments visually on the right side for better readability
- Variable are defined in same way but their names are closer to visually distinguish them from functions


```
    void                                                                                set_Current_Line(uint32_t _current_line_index);

    void                                                                                set_Current_Symbol_Index(uint32_t _current_symbol_index);
    
    void                                                                                set_Prefferable_Symbol_Index(uint32_t _prefferable_symbol_index);

    void                                                                                move_Right();

    void                                                                                move_Up(uint32_t line_size);

    void                                                                                move_Down(uint32_t line_size);

    void                                                                                move_Left();

    std::pair<int, int>                                                                 get_Cursor_Position();

    uint32_t                                                                            get_Current_Symbol_Index(uint32_t row_size);

    uint32_t                                                                            get_Current_Line_Index();

private:

    uint32_t                                            current_line_index = 0;

    uint32_t                                            preferrable_symbol_index = 0;

    uint32_t                                            current_symbol_index = 0;

```


## Implementation file (.cpp)


- Return type is one line above 
- Senister uses 2 spaces in functions body implementation
- One empty line on the start and 2 before last brace
- Braces are on separate lines
```
TextEngine*
CodeUI::Text_Engine()
{

  return text_engine;


}
```


- One Empty line between functions
```
void
InputEngine::update_ui()
{

  assert(code_ui);
  code_ui->update();


}

void
InputEngine::insert_Char(QString character)
{
  
  code_ui->Text_Engine()->insert_Char(character, cursor->get_Cursor_Position());
  update_ui();


}
```


- Default brace convention for control flow
```
if (new_line_size > 0 && current_col >= new_line_size) {
    cursor->set_Current_Symbol_Index(new_line_size - 1);
    
    cursor->set_Preferable_Symbol_Index(new_line_size - 1); 
  } else if (new_line_size == 0) {
    cursor->set_Current_Symbol_Index(0);
    cursor->set_Preferable_Symbol_Index(0);
}
```
