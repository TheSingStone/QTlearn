#include "workThread2.h"
#include <QDebug>

workThread2::workThread2()
{

}
workThread2::~workThread2()
{
}
void workThread2::run()
{
    while(true){
        for (int n = 0; n < 10; n++)
            qDebug() << 2 << 2 << 2 << 2 << 2 << 2 << 2 << 2;
    }

}
