#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    ui->setupUi(this);
    setWindowTitle(tr("主窗口"));
    openAction = new QAction(QIcon(":/res/images/Candybar.ico"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction,&QAction::triggered,this,&MainWindow::openFile);
    saveAction = new QAction(QIcon(":/res/images/GameRanger.ico"), tr("&Save..."), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save a new file"));
    connect(saveAction,&QAction::triggered,this,&MainWindow::saveFile);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(saveAction);


    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);

    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
    statusBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open Files"),
                                                ",",
                                                tr("Text Files(*.txt)"));
    if(!path.isEmpty()){
        QFile file(path);
        if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
            QMessageBox::warning(this,tr("Read File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }else{
        QMessageBox::warning(this,tr("path"),
                             tr("You did not select any file"));
    }
}
void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this,
                                                    tr("Open File"),
                                                    ".",
                                                    tr("Text Files(*.txt)"));
        if(!path.isEmpty()) {
            QFile file(path);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QMessageBox::warning(this, tr("Write File"),
                                           tr("Cannot open file:\n%1").arg(path));
                return;
            }
            QTextStream out(&file);
            out << textEdit->toPlainText();
            file.close();
        } else {
            QMessageBox::warning(this, tr("Path"),
                                 tr("You did not select any file."));
        }

}
