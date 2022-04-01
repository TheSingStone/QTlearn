#include "workthread.h"
#include <QDebug>

workthread::workthread()
{

}

workthread::~workthread()
{
}
void workthread::run()
{
    while(true){
        for (int n = 0; n < 10; n++)
            qDebug() << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;
    }

}
