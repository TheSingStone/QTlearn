#ifndef CONTROL_H
#define CONTROL_H

#include <QWidget>

namespace Ui {
class control;
}

class control : public QWidget
{
    Q_OBJECT

public:
    explicit control(QWidget *parent = 0);
    ~control();

private:
    Ui::control *ui;
};

#endif // CONTROL_H
