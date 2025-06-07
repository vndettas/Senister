//
// Created by vovab on 03.05.2025.
//

#ifndef VEDITOR_LINENUMERATOR_H
#define VEDITOR_LINENUMERATOR_H

#include <QWidget>
#include <QPainter>
#include "HELPER/CONSTANTS.h"


class LineNumerator : public  QWidget {

Q_OBJECT

public:
    LineNumerator(QWidget *parent) : QWidget(parent) {
    }

    ~LineNumerator() override {

    }

    void paintEvent(QPaintEvent *event);

};


#endif //VEDITOR_LINENUMERATOR_H
