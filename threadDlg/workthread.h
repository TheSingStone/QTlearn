#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QThread>

class workthread : public QThread
{
public:
    workthread();
    ~workthread();
protected:
    void run();
};

#endif // WORKTHREAD_H
