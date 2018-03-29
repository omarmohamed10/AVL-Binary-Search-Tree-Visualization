#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <iostream>
#include <QGraphicsView>
#include <QTextStream>
#include <QProcess>

#include "BST.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_Insert_clicked();

    void on_Delete_clicked();

    void on_Find_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    QGraphicsView *view;
    BST*obj;
};
#endif // MAINWINDOW_H
