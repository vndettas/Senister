#pragma once

#include "../../core/text/TextEngine.h"
#include "../../core/text/PieceOfTable.h"
#include "../HELPER/CONSTANTS.h"
#include "../../core/files/FileManager.h"
#include "../../core/files/File.h"
#include "../input/InputEngine.h"
#include "LineNumerator.h"
#include "FileBar.h"
#include <string>
#include <QString>
#include <QPaintEvent>
#include <QWidget>
#include <QTextLayout>
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include <QPen>
#include <iostream>
#include <memory>
#include <QGridLayout>
#include <QLayout>


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

    CodeUI()=delete;

    CodeUI                                                                   (std::shared_ptr<FileManager> file_manager, QWidget *parent =nullptr,
                                                                                const Qt::WindowFlags& f = Qt::Widget);

    void                                                                     set_Current_File_Index(uint32_t index);

    void                                                                     set_Current_File(std::shared_ptr<File> file);

    const uint32_t                                                           getLineSpacing() const;

    TextEngine*                                                              Text_Engine();

    Cursor*                                                                  get_Cursor();

    void                                                                     on_Scroll_Tick();

    void                                                                     draw_Cursor(QPainter *painter, QTextLayout *text_layout, QFont *text_font);

    void                                                                     paintEvent(QPaintEvent *event) override;

    void                                                                     draw_Rectangles(QPainter *painter);

    void                                                                     draw_Lines(QPainter *painter);

    ~CodeUI(){};

signals:

  void                                                                      key_Pressed(QKeyEvent* event);



private :

    std::shared_ptr<FileManager>                                file_manager;

    std::shared_ptr<File>                                       current_file;

    TextEngine*                                                 text_engine;

    PieceOfTable*                                               text_data_structure;

    std::unique_ptr<InputEngine>                                input_engine;

    std::unique_ptr<Cursor>                                     cursor;

    QTimer*                                                     timer = nullptr;

    LineNumerator*                                              line_numerator = nullptr;

    FileBar*                                                    file_bar = nullptr;

    float                                                       scroll_offset_y = 0;

    float                                                       scroll_velocity = 0;

    const uint32_t                                              line_spacing = fontMetrics().lineSpacing();

    const uint32_t                                              line_height = fontMetrics().height();

    uint32_t                                                    visible_line_count;

protected:
    void                                                                            resizeEvent(QResizeEvent *event) override;

    void                                                                            wheelEvent(QWheelEvent *event) override;

    void                                                                            keyPressEvent(QKeyEvent *event) override;

};
