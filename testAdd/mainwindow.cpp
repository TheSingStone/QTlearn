#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "component.h"
#include "control.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpacerItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::init()
{
    QVBoxLayout *pLyt = new QVBoxLayout;
    component *pCmpt = new component;
    control *pCttl = new control;
    pLyt->addWidget(pCmpt);
    pLyt->addWidget(new component);
    pLyt->addWidget(pCttl);
    pLyt->setMargin(6);
    pLyt->setMargin(6);
    pLyt->addSpacerItem(new QSpacerItem(20,5,QSizePolicy::Minimum,QSizePolicy::Expanding));
    ui->mainScrl->setLayout(pLyt);
}
