//
// Created by vovab on 03.05.2025.
//

#ifndef VEDITOR_SCROLLBAR_H
#define VEDITOR_SCROLLBAR_H

#include <QScrollBar>
#include "HELPER/CONSTANTS.h"


class ScrollBar : QWidget{

Q_OBJECT

public:
    explicit ScrollBar(QWidget *parent) : QWidget(parent) {
    }

private:
    void paintEvent(QPaintEvent *event);
};


#endif //VEDITOR_SCROLLBAR_H
