#ifndef READER
#define READER
#include <QDebug>
class Reader : public QObject
{
    Q_OBJECT
public:
    Reader() {}

    void receiveNewspaper(const QString & name) const
    {
        qDebug() << "Receives Newspaper: " << name;
    }
//    void receiveNewspaper(const QString & name, const QDate & date)
//    {
//        qDebug() << "Receives Newspaper: " << name;
//        qDebug() << date;
//    }
};
#endif // READER

