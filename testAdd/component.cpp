#include "component.h"
#include "ui_component.h"

component::component(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::component)
{
    ui->setupUi(this);
    ui->pushButton->setVisible(true);
}

component::~component()
{
    delete ui;
}
