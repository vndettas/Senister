#include <QApplication>
#include "App.h"

#ifdef NDEBUG
#define QT_NO_DEBUG_OUTPUT
#endif


int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  App window;
  return app.exec();
}
