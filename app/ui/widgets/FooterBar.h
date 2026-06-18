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

class FooterBar : public QWidget {

    Q_OBJECT

public:

    FooterBar                                                            (QWidget *parent, const Qt::WindowFlags& f = Qt::Widget);

public slots:

private:

protected:

    void                                                                paintEvent(QPaintEvent *event) override;


};
