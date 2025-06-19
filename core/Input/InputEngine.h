//
// Created by vovab on 19.06.2025.
//

#ifndef VEDITOR_INPUTENGINE_H
#define VEDITOR_INPUTENGINE_H
#include <QObject>
#include "VimStrategy.h"

class InputEngine : QObject{

    Q_OBJECT

public:

public slots:

    void onKeyPressed(QEvent* event);

private:



};


#endif //VEDITOR_INPUTENGINE_H
