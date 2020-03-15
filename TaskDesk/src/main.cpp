#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.loadText();
    w.exportPic();
//    w.show();

    return 0;
    return a.exec();
}
