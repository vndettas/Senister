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


class TextEngine;
class LineNumerator;

class Cursor{
public:

    size_t get_Current_Line() {return current_line_index; }

    size_t get_Current_Symbol_Index() { return current_symbol_index; }


private:

    void setCurrentLine(size_t _current_line_index){ current_line_index = _current_line_index; }

    void setCurrentSymbolIndex(size_t _current_symbol_index) { current_symbol_index = _current_symbol_index; }

    size_t current_line_index = 7;

    size_t current_symbol_index = 3;



};


class CodeUI : public QWidget {

   Q_OBJECT

public:

    CodeUI(std::shared_ptr<TextEngine>, std::shared_ptr<PieceOfTable>, QWidget *parent =nullptr,
           const Qt::WindowFlags& f = Qt::Widget);

    size_t get_Cursor_Current_Line() { return cursor->get_Current_Line(); }

    size_t get_Cursor_Current_Symbol_Index() { return cursor->get_Current_Symbol_Index(); }

    ~CodeUI(){};


private :

    float scroll_offset_y = 0;

    float scroll_velocity = 0;

    const uint32_t line_spacing = fontMetrics().lineSpacing();

    const uint32_t line_height = fontMetrics().height();

    const uint32_t visible_line_count = (Constants::CODE_VIEWPORT_HEIGHT / line_height) + 1;

    QTimer* timer = nullptr;

    std::unique_ptr<Cursor> cursor;

    LineNumerator* line_numerator = nullptr;

    std::shared_ptr<TextEngine> text_engine;

    std::shared_ptr<PieceOfTable> text_data_structure;

    void on_Scroll_Tick();

    void paintEvent(QPaintEvent *event) override;

    void draw_Background(QPainter *painter);

public:
    const uint32_t getLineSpacing() const;

private:
    void wheelEvent(QWheelEvent *event) override;

protected:
    void resizeEvent(QResizeEvent *event) override;


};


#endif //VEDITOR_CODEUI_H
