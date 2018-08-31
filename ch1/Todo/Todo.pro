#-------------------------------------------------
#
# Project created by QtCreator 2018-08-31T21:43:05
#
#-------------------------------------------------

CONFIG += c++11

QT       += core gui

QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Todo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    task.cpp

HEADERS  += mainwindow.h \
    task.h

FORMS    += mainwindow.ui \
    task.ui
