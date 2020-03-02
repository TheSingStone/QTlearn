#ifndef WORKTHREAD_H
#define WORKTHREAD_H
#include <QThread>


class WorkThread : public QThread
{
    Q_OBJECT
public:
    WorkThread(QObject *parent = 0)
        :QThread(parent)
    {

    }
protected:
    void run()
    {
        for(int i = 0; i < 1000000000;i++);
        emit done();
    }
signals:
    void done();
};

#endif // WORKTHREAD_H
