//
// Created by vovab on 12.03.2025.
//

#ifndef VEDITOR_CODEUI_H
#define VEDITOR_CODEUI_H

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


class TextEngine;
class LineNumerator;
class FileManager;
class File;


class Cursor{
public:

    uint32_t get_Current_Line() {return current_line_index; }

    uint32_t get_Current_Symbol_Index() { return current_symbol_index; }

private:

    void setCurrentLine(uint32_t _current_line_index){ current_line_index = _current_line_index; }

    void setCurrentSymbolIndex(uint32_t _current_symbol_index) { current_symbol_index = _current_symbol_index; }

    uint32_t current_line_index = 3;

    uint32_t current_symbol_index = 4;

};

class CodeUI : public QWidget {

   Q_OBJECT

public:

    CodeUI(std::shared_ptr<FileManager> file_manager, QWidget *parent =nullptr,
           const Qt::WindowFlags& f = Qt::Widget);

    uint32_t get_Cursor_Current_Line() { return cursor->get_Current_Line(); }

    uint32_t get_Cursor_Current_Symbol_Index() { return cursor->get_Current_Symbol_Index(); }

    void set_Current_File(std::shared_ptr<File> file) { current_file = file; }

    ~CodeUI(){};

signals:

  void Keypressed(QKeyEvent* event);


private :

    QTimer* timer = nullptr;

    std::shared_ptr<FileManager> file_manager;

    std::shared_ptr<File> current_file;

    TextEngine* text_engine;

    PieceOfTable* text_data_structure;

    std::unique_ptr<Cursor> cursor;

    LineNumerator* line_numerator = nullptr;

    void on_Scroll_Tick();

    void paintEvent(QPaintEvent *event) override;

    void draw_Background(QPainter *painter);

    float scroll_offset_y = 0;

    float scroll_velocity = 0;

    const uint32_t line_spacing = fontMetrics().lineSpacing();

    const uint32_t line_height = fontMetrics().height();

    const uint32_t visible_line_count = (Constants::CODE_VIEWPORT_HEIGHT / line_height) + 1;

public:
    const uint32_t getLineSpacing() const;

private:
    void wheelEvent(QWheelEvent *event) override;

protected:
    void resizeEvent(QResizeEvent *event) override;


};


#endif //VEDITOR_CODEUI_H
