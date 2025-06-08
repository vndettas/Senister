//
// Created by vovab on 12.03.2025.
//

#ifndef VEDITOR_CODEUI_H
#define VEDITOR_CODEUI_H

#include <string>
#include "../Text/TextEngine.h"
#include "../Text/PieceOfTable.h"
#include <QString>
#include <QPaintEvent>
#include <QWidget>
#include <QTextLayout>
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include <Qpen>
#include <iostream>
#include <memory>
#include <QGridLayout>
#include "LineNumerator.h"
#include "../HELPER/CONSTANTS.h"
class TextEngine;



class CodeUI : public QWidget {

   Q_OBJECT

public:

    float scroll_offset_y = 0;

    float scroll_velocity = 0;

    QTimer* timer;

protected:
    void wheelEvent(QWheelEvent *event) override;

public:


    CodeUI(std::shared_ptr<TextEngine>, std::shared_ptr<PieceOfTable>, QWidget *parent =nullptr,
           const Qt::WindowFlags& f = Qt::Widget);

    ~CodeUI();


private :

    void onScrollTick();

    std::shared_ptr<TextEngine> text_engine;

    std::shared_ptr<PieceOfTable> text_data_structure;

    void paintEvent(QPaintEvent *event) override;


};


#endif //VEDITOR_CODEUI_H
