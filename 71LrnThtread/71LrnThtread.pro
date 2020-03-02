#-------------------------------------------------
#
# Project created by QtCreator 2019-11-14T11:21:47
#
#-------------------------------------------------

QT       += core gui
#QMAKE_CXXFLAGS += -std=c++0x
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 71LrnThtread
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    workthread.h

FORMS    += mainwindow.ui
