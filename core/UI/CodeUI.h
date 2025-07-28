#pragma once

#include <string>
#include "../Text/TextEngine.h"
#include "../Text/PieceOfTable.h"
#include <QString>
#include <QPaintEvent>
#include <QWidget>
#include <QTextLayout>
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include <Qpen>
#include <iostream>
#include <memory>
#include <QGridLayout>
#include "../HELPER/CONSTANTS.h"
#include "LineNumerator.h"
#include "../Files/FileManager.h"
#include "../Files/File.h"
#include "../UI/FileBar.h"

class TextEngine;
class LineNumerator;
class FileManager;
class File;
class FileBar;


class Cursor{
public:

    uint32_t get_Current_Line() {return current_line_index; }

    uint32_t get_Current_Symbol_Index() { return current_symbol_index; }

private:

    void setCurrentLine(uint32_t _current_line_index){ current_line_index = _current_line_index; }

    void setCurrentSymbolIndex(uint32_t _current_symbol_index) { current_symbol_index = _current_symbol_index; }

    uint32_t current_line_index = 7;

    uint32_t current_symbol_index = 4;

};

class CodeUI : public QWidget {

   Q_OBJECT

public:
   
   CodeUI(std::shared_ptr<FileManager> file_manager, QWidget *parent =nullptr,
    const Qt::WindowFlags& f = Qt::Widget);
    
    const uint32_t getLineSpacing() const;

    uint32_t get_Cursor_Current_Line() { return cursor->get_Current_Line(); }

    uint32_t get_Cursor_Current_Symbol_Index() { return cursor->get_Current_Symbol_Index(); }
    
    void set_Current_File(std::shared_ptr<File> file) { current_file = file; }
    
    ~CodeUI(){};

signals:

  void key_Pressed(QKeyEvent* event);


private :

    std::shared_ptr<FileManager> file_manager;

    std::shared_ptr<File> current_file;

    TextEngine* text_engine;

    PieceOfTable* text_data_structure;

    std::unique_ptr<Cursor> cursor;
    
    QTimer* timer = nullptr;

    LineNumerator* line_numerator = nullptr;

    FileBar* file_bar = nullptr;

    void on_Scroll_Tick();

    void paintEvent(QPaintEvent *event) override;

    void draw_Rectangles(QPainter *painter);

    void draw_Lines(QPainter *painter);

    float scroll_offset_y = 0;

    float scroll_velocity = 0;

    const uint32_t line_spacing = fontMetrics().lineSpacing();

    const uint32_t line_height = fontMetrics().height();

    const uint32_t visible_line_count = (Constants::CODE_VIEWPORT_HEIGHT / line_height) + 1;
    
protected:
    void resizeEvent(QResizeEvent *event) override;
    
    void wheelEvent(QWheelEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

};

