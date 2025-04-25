#include <iostream>
#include <QApplication>
#include <QPushButton>
#include "MainWindow.h"

#ifdef NDEBUG
#define QT_NO_DEBUG_OUTPUT
#endif


int main(int argc, char** argv) {
  QApplication app(argc, argv);
  MainWindow window;
  window.show();
  return app.exec();
}
