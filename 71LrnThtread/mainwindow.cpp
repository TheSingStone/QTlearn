#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QTimer>
#include "workthread.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    widget->setLayout(layout);
    QLCDNumber *lcdNumber = new QLCDNumber(this);
    layout->addWidget(lcdNumber);
    QPushButton *button = new QPushButton(tr("Start"), this);
    layout->addWidget(button);
    setCentralWidget(widget);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=]() {
        static int sec = 0;
        lcdNumber->display(QString::number(sec++));
    });

    WorkThread *thread = new WorkThread(this);
//    connect(button, &QPushButton::clicked, [=]() {
//        timer->start(1);
//        for (int i = 0; i < 2000000000; i++);
//        timer->stop();
//    });
    connect(thread,&WorkThread::done,timer,&QTimer::stop);
    connect(thread,&WorkThread::finished,thread,&WorkThread::deleteLater);
    connect(button,&QPushButton::clicked,[=](){
        timer->start(1);
        thread->start();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
