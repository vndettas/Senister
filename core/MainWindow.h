//
// Created by vovab on 12.03.2025.
//

#ifndef VEDITOR_MAINWINDOW_H
#define VEDITOR_MAINWINDOW_H


#include <QMainWindow>
#include "CodeEditor.h"
#include <QVBoxLayout>
#include <iostream>
#include "MainWindow.h"
#include "PieceOfTable.h"
#include "Qdir"


   const int windw_width = 1020;

   const int window_height = 660;

class MainWindow : public QMainWindow
      {
    QObject qObject;

      public:
          MainWindow(QWidget* parent = nullptr);

          ~MainWindow();


private:
          CodeEditor *editor;




};


#endif //VEDITOR_MAINWINDOW_H
