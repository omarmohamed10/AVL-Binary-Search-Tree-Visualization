#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsView>
#include <QTextStream>
#include <QProcess>
#include <QTextEdit>
#include <QMessageBox>

#include "BST.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view = new QGraphicsView(&scene) ;
    view->setRenderHints(QPainter::SmoothPixmapTransform);
    obj = new BST();
    obj->init(&scene , view) ;
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Insert_clicked()
{
    obj->insert(ui->lineEdit->text().toInt());
    obj->show();
}

void MainWindow::on_Delete_clicked()
{
    obj->deleteNode(ui->lineEdit_2->text().toInt());
       obj->show();
}

void MainWindow::on_Find_clicked()
{
    bool temp = obj->findElem(ui->lineEdit_3->text().toInt()) ;
       if (temp == true)
       {
           QMessageBox::information(this,tr("AVL"),tr("Found"));
       }
       else
       {
           QMessageBox::information(this,tr("AVL"),tr(" not Found"));
       }
}
