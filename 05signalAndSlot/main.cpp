#include <QApplication>
#include <QDebug>
#include "newspaper.h"
#include "reader.h"
/*
 * 程序运行完不能直接结束，疑似地址泄漏的问题
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDate myDate (1980,12,21);
    Newspaper newspaper("Newspaper A",myDate);
    Reader reader;
    QObject::connect(&newspaper, &Newspaper::newPaper,
                     &reader,    &Reader::receiveNewspaper);
    newspaper.send(); 
    int result = a.exec();
    qDebug()<<&newspaper<<endl;
    return result;
}
