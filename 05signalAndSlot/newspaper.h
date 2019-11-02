#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include <QObject>
#include <QDate>

class Newspaper : public QObject
{
    Q_OBJECT
public:
    Newspaper(const QString & name, const QDate & date) :
        m_name(name),m_date(date)
    {
    }

    void send()
    {
        emit newPaper(m_name);
    }

signals:
    void newPaper(const QString & name) const;
//    void newPaper(const QString &, const QDate &);

private:
    QString m_name;
    QDate m_date;
};

#endif // NEWSPAPER_H
