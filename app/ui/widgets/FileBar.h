#pragma once

#include "../../core/files/FileManager.h"
#include "../../core/files/File.h"
#include "../../HELPER/CONSTANTS.h"
#include <QWidget>
#include <QWheelEvent>
#include <QPainter>
#include <QFontMetrics>
#include <QString>
#include <QColor>
#include "../../core/profile/ProfileEngine.h"

class File;
class FileManager;

class FileBar : public QWidget {

    Q_OBJECT

public:

    FileBar                                                             (QWidget *parent, FileManager* file_manager, ProfileEngine* _profile_engine, const Qt::WindowFlags& f = Qt::Widget);

private:

    void                                                                draw_Lines(QPainter *painter);

    void                                                                draw_Files(QPainter *painter);

    FileManager*                                                        file_manager;
  
    ProfileEngine*                                                      profile_engine;

    uint32_t                                                            x_scroll_offset = 0;

protected:

    void                                                                paintEvent(QPaintEvent *event) override;

    void                                                                wheelEvent(QWheelEvent *event) override;

};
