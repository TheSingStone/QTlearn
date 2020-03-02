#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButton button("Quit");
    QObject::connect(&button, &QPushButton::clicked, [](bool) {
        qDebug() << "You clicked me!";
    });
    button.show();

    return a.exec();
}
