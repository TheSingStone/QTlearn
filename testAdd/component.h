#ifndef COMPONENT_H
#define COMPONENT_H

#include <QWidget>

namespace Ui {
class component;
}

class component : public QWidget
{
    Q_OBJECT

public:
    explicit component(QWidget *parent = 0);
    ~component();

private:
    Ui::component *ui;
};

#endif // COMPONENT_H
