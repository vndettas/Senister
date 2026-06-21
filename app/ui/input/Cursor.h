#pragma once
#include <QPropertyAnimation>
#include <QObject>
#include <cstdint>
#include <utility>

enum class CursorState{
  Insert_Mode,
  Visual_Mode,
  Normal_Mode
};



class Cursor : public QObject{

  Q_OBJECT

  Q_PROPERTY(float cursor_opacity READ get_Cursor_Opacity WRITE set_Cursor_Opacity)


public:

//    Cursor                                                                              (QObject* parent = nullptr): QObject(parent) {}
    
    Cursor                                                                              ();

    void                                                                                set_Current_Line(uint32_t _current_line_index);

    void                                                                                set_Current_Symbol_Index(uint32_t _current_symbol_index);
    
    float                                                                               get_Cursor_Opacity();

    void                                                                                set_Cursor_Opacity(float opacity);
    
    void                                                                                set_Prefferable_Symbol_Index(uint32_t _prefferable_symbol_index);

    void                                                                                set_Cursor_Mode(CursorState state);

    CursorState                                                                         get_Cursor_Mode();

    void                                                                                move_Right();

    void                                                                                move_Up(uint32_t line_size);

    void                                                                                move_Down(uint32_t line_size);

    void                                                                                move_Left();

    std::pair<int, int>                                                                 get_Cursor_Position();

    uint32_t                                                                            get_Current_Symbol_Index(uint32_t row_size);

    uint32_t                                                                            get_Current_Line_Index();

private:

    uint32_t                                            current_line_index = 0;

    CursorState                                         cursor_state = CursorState::Normal_Mode;

    uint32_t                                            preferrable_symbol_index = 0;
    
    float                                               cursor_opacity = 0.0f;

    QPropertyAnimation*                                 cursor_fading;

    uint32_t                                            current_symbol_index = 0;

};
