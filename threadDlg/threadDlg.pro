#-------------------------------------------------
#
# Project created by QtCreator 2021-04-14T20:39:21
#
#-------------------------------------------------

QT       += core
QT       += widgets

QT       -= gui

TARGET = threadDlg
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    workthread.cpp \
    CThreadDlg.cpp \
    workThread1.cpp \
    workThread2.cpp \
    workThread3.cpp

FORMS += \
    CThreadDlg.ui

HEADERS += \
    workthread.h \
    CThreadDlg.h \
    workThread1.h \
    workThread2.h \
    workThread3.h
