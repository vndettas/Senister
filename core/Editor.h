//
// Created by vovab on 12.03.2025.
//

#ifndef VEDITOR_EDITOR_H
#define VEDITOR_EDITOR_H

#include <string>
#include <QString>
#include <QPaintEvent>
#include <QWidget>
#include <QTextLayout>
#include <QPainter>
#include "PieceOfTable.h"
#include <QDebug>
#include <Qpen>
#include <iostream>
#include "ScrollBar.h"
#include <QGridLayout>
#include "LineNumerator.h"
#include "HELPER/CONSTANTS.h"




class Editor : public QWidget {

   Q_OBJECT

public:


     Editor(QWidget *parent =nullptr, const Qt::WindowFlags &f = Qt::Widget);

    ~Editor();


private :

    LineNumerator numerator;

    void paintEvent(QPaintEvent *event) override;


};


#endif //VEDITOR_EDITOR_H
