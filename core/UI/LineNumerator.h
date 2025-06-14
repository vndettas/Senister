//
// Created by vovab on 03.05.2025.
//

#ifndef VEDITOR_LINENUMERATOR_H
#define VEDITOR_LINENUMERATOR_H

#include <QWidget>
#include <QPainter>
#include "../HELPER/CONSTANTS.h"
#include "CodeUI.h"


class LineNumerator : public  QWidget {

Q_OBJECT

public:
    LineNumerator(QWidget *parent) : QWidget(parent) {};


    ~LineNumerator() {};


    void paintEvent(QPaintEvent *event);

private:

};


#endif //VEDITOR_LINENUMERATOR_H
