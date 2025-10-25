#pragma once

#include "../../core/files/FileManager.h"
#include "../../core/files/File.h"
#include "../../HELPER/CONSTANTS.h"
#include <QWidget>
#include <QPainter>
#include <QFontMetrics>
#include <QString>
#include <QColor>

class File;
class FileManager;

class FileBar : public QWidget {

    Q_OBJECT

public:

    FileBar                                                             (QWidget *parent, FileManager* file_manager, const Qt::WindowFlags& f = Qt::Widget);

private:


    void                                                                draw_Lines(QPainter *painter);

    void                                                                draw_Rectangles(QPainter *painter);

    void                                                                draw_Files(QPainter *painter);

    FileManager*                                                        file_manager = nullptr;

protected:

    void                                                                paintEvent(QPaintEvent *event) override;


};
