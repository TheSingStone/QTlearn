#ifndef THREADDLG_H
#define THREADDLG_H


#include <QDialog>
#include "workthread.h"
#include "workThread1.h"
#include "workThread2.h"
#include "workThread3.h"
#include <QMessageBox>

#define MAXSIZE 4

namespace Ui {
class CThreadDlg;
}

class CThreadDlg : public QDialog
{
    Q_OBJECT

public:
    CThreadDlg(QWidget *parent = Q_NULLPTR);
public slots:
    void BtnStartClicked();
    void BtnStopClicked();

private:
    Ui::CThreadDlg *ui;
    workthread *workThread[MAXSIZE];
};

#endif // THREADDLG_H
