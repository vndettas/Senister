#pragma once
#include <QFont>
#include <QWidget>
#include <QInternal>
#include <QTextLayout>
#include <QPainter>
#include <memory>
#include "CodeUI.h"
#include "../../core/profile/ProfileEngine.h"

class CodeUI;
class TextEngine;

class LineNumerator : public QWidget {

    Q_OBJECT

public:

    LineNumerator()=delete;

    LineNumerator                                                           (QWidget *parent, TextEngine* engine, ProfileEngine* profile_engine, const Qt::WindowFlags &f = Qt::Widget);

    void                                                                    set_Current_Text_Engine(TextEngine* text_engine);

    void                                                                    setup_Font();

private:

    TextEngine*                     text_engine;

    ProfileEngine*                  profile_engine;

    CodeUI*                         parent_widget_ui = nullptr;

    uint32_t                        line_spacing = 0;

    QFont                           numerator_font;

    QFont                           numerator_highlighter_font;

    uint32_t                        line_height;

    uint32_t                        visible_line_count;

protected:

    void                                                                      paintEvent(QPaintEvent *event);

};
