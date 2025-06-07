#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QFont>
#include "Editor.h"
#ifdef NDEBUG
#define QT_NO_DEBUG_OUTPUT
#endif


int main(int argc, char** argv) {
  QApplication app(argc, argv);
  Editor window;
  window.show();
  return app.exec();
}
