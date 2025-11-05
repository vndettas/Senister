#include <QApplication>
#include "App.h"


int main(int argc, char** argv)
{ 
  QApplication app(argc, argv);
  App window;
  return app.exec();

}
