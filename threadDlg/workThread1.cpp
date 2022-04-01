#include "workThread1.h"
#include <QDebug>

workThread1::workThread1()
{

}

workThread1::~workThread1()
{
}

void workThread1::run()
{
    while(true){
        for (int n = 0; n < 10; n++)
            qDebug() << 1 << 1 << 1 << 1 << 1 << 1 << 1 << 1;
    }

}
