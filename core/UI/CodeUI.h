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
#include <QLayout>
#include "../Input/InputEngine.h"


class InputEngine;
class Cursor;
class TextEngine;
class LineNumerator;
class FileManager;
class File;
class FileBar;


class CodeUI : public QWidget {

   Q_OBJECT

public:
   
   CodeUI(std::shared_ptr<FileManager> file_manager, QWidget *parent =nullptr,
    const Qt::WindowFlags& f = Qt::Widget);
    
    const uint32_t getLineSpacing() const;

    void set_Current_File(std::shared_ptr<File> file); 
    
    void set_Current_File_Index(uint32_t index);
    
    TextEngine* Text_Engine();

    Cursor* get_Cursor();

    ~CodeUI(){};

signals:

  void key_Pressed(QKeyEvent* event);
  


private :

    std::shared_ptr<FileManager> file_manager;

    std::shared_ptr<File> current_file;

    //Todo: make it unq ptr
    
    TextEngine* text_engine = nullptr;

    PieceOfTable* text_data_structure = nullptr;

    std::unique_ptr<InputEngine> input_engine;

    std::unique_ptr<Cursor> cursor;

    //Todo: make it unq ptr

    QTimer* timer = nullptr;

    LineNumerator* line_numerator = nullptr;

    FileBar* file_bar = nullptr;

    void on_Scroll_Tick();

    void draw_Cursor(QPainter *painter, QTextLayout *text_layout, QFont *text_font);

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

