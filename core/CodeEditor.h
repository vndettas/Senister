//
// Created by vovab on 12.03.2025.
//

#ifndef VEDITOR_CODEEDITOR_H
#define VEDITOR_CODEEDITOR_H

#include <string>
#include <QPaintEvent>
#include <QWidget>
#include <QTextLayout>
#include <QPainter>
#include "PieceOfTable.h"
#include <QDebug>
#include <iostream>

class CodeEditor : public QWidget {

   Q_OBJECT

public:


     CodeEditor(QWidget *parent =nullptr, const Qt::WindowFlags &f = Qt::Widget);

    ~CodeEditor();



private :


    void paintEvent(QPaintEvent *event) override;






};


#endif //VEDITOR_CODEEDITOR_H
