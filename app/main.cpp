// SPDX-License-Identifier: MIT
// /file  : main.cpp
// Last modified: 2025-08-12 17:40
//

#include <QApplication>
#include "App.h"


int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  App window;
  return app.exec();

}
