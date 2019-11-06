#-------------------------------------------------
#
# Project created by QtCreator 2019-11-05T19:15:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testAdd
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    component.cpp \
    control.cpp

HEADERS  += mainwindow.h \
    component.h \
    control.h

FORMS    += mainwindow.ui \
    component.ui \
    control.ui
