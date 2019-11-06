#include "component.h"
#include "ui_component.h"

component::component(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::component)
{
    ui->setupUi(this);
}

component::~component()
{
    delete ui;
}
