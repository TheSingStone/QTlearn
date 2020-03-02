#include "mainwindow.h"
#include <QMouseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedSize(500,300);

}

MainWindow::~MainWindow()
{

}
 void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        qDebug()<<"MouseWvent"<<event->x()<<""<<
                  event->y()<<""<<event->globalX()<<""
               <<event->globalY()<<endl;
}
}

