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


class CodeUI : public QWidget {

   Q_OBJECT

public:

    CodeUI(std::shared_ptr<TextEngine>, std::shared_ptr<PieceOfTable>, QWidget *parent =nullptr,
           const Qt::WindowFlags& f = Qt::Widget);

    ~CodeUI(){};


private :

    float scroll_offset_y = 0;

    float scroll_velocity = 0;

    const uint32_t line_spacing = fontMetrics().lineSpacing();

    const uint32_t line_height = fontMetrics().height();

    const uint32_t visible_line_count = (Constants::CODE_VIEWPORT_HEIGHT / line_height) + 1;

    QTimer* timer = nullptr;

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
