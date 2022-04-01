#include "CThreadDlg.h"
#include "ui_CThreadDlg.h"

CThreadDlg::CThreadDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CThreadDlg)
{
    ui->setupUi(this);
    connect(ui->btnStart, SIGNAL(clicked()), this, SLOT(BtnStartClicked()));
    connect(ui->btnStop, SIGNAL(clicked()), this, SLOT(BtnStopClicked()));
    connect(ui->btnQuit, SIGNAL(clicked()), this, SLOT(close()));
}

void CThreadDlg::BtnStartClicked()
{
    workThread[0] = new workthread();
    workThread[1] = new workThread1();
    workThread[2] = new workThread2();
    workThread[3] = new workThread3();
    for (int i = 0; i < MAXSIZE; i++){
        workThread[i]->start();
    }
    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);
}
void CThreadDlg::BtnStopClicked()
{
    for (int i = 0; i < MAXSIZE; i++){
        workThread[i]->terminate();
        workThread[i]->wait();
    }
    ui->btnStart->setEnabled(true);
    ui->btnStop->setEnabled(false);
}
