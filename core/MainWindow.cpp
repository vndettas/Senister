//
// Created by vovab on 12.03.2025.
//

#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
  window()->setFixedSize(windw_width, window_height);
  PieceOfTable *temp = new PieceOfTable("C:/Users/vovab/Documents/GitHub/Veditor/test/test.cpp");
  CodeEditor *editor = new CodeEditor(window());
  setCentralWidget(editor);

}


MainWindow::~MainWindow() {};