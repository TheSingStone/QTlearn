#include "mainwindow.h"
#include <QWidget>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QMessageBox>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Main"));

    openAction = new QAction(QIcon(":/new/images/doc"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

    statusBar();//??

}

MainWindow::~MainWindow()
{

}

void MainWindow::open()
{
    QMessageBox::information(this,tr("Information"),tr("open"));
}
