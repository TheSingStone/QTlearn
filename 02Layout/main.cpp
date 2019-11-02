#include "mainwindow.h"
#include <QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget window;
    window.setWindowTitle("Enter your age");

    QSpinBox *spinbox = new QSpinBox(&window);
    QSlider *slider = new QSlider(Qt::Horizontal,&window);
    spinbox->setRange(0,130);
    slider->setRange(0,130);

    QObject::connect(slider,&QSlider::valueChanged,
                     spinbox,&QSpinBox::setValue);
    void (QSpinBox:: *spinboxSignal)(int) = &QSpinBox::valueChanged;
    QObject::connect(spinbox,spinboxSignal,slider,&QSlider::setValue);
    spinbox->setValue(35);

    QHBoxLayout *layout = new QHBoxLayout;
    layout -> addWidget(spinbox);
    layout -> addWidget(slider);
    window.setLayout(layout);
    window.show();

    return a.exec();
}
