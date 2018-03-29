#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <iostream>
#include <QGraphicsView>
#include <QTextStream>
#include <QProcess>

#include "BST.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
