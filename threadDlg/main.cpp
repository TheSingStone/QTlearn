#include <QApplication>
#include "CThreadDlg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CThreadDlg w;
    w.show();
    return a.exec();
}
