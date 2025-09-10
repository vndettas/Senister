#pragma once
#include <QWidget>
#include <QInternal>
#include <QTextLayout>
#include <QPainter>
#include <memory>
#include "CodeUI.h"

class CodeUI;
class TextEngine;

class LineNumerator : public QWidget {

    Q_OBJECT

public:
    LineNumerator(QWidget *parent, TextEngine* engine, const Qt::WindowFlags &f = Qt::Widget);

    void set_Current_Text_Engine(TextEngine* text_engine);

private:

    TextEngine* text_engine = nullptr;

    CodeUI* parent_widget_ui = nullptr;

    uint32_t line_spacing = 0;

    const uint32_t line_height = fontMetrics().height();

    const uint32_t visible_line_count = (Constants::CODE_VIEWPORT_HEIGHT / line_height) + 1;

protected:

    void paintEvent(QPaintEvent *event);
};
