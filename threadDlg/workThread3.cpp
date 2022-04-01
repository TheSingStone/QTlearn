#include "workThread3.h"
#include <QDebug>

workThread3::workThread3()
{

}
workThread3::~workThread3()
{
}
void workThread3::run()
{
    while(true){
        for (int n = 0; n < 10; n++)
            qDebug() << 3 << 3 << 3 << 3 << 3 << 3 << 3 << 3;
    }

}
