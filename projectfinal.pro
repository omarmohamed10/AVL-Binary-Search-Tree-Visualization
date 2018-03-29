

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projectfinal
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += main.cpp\
        mainwindow.cpp \
    BST.cpp

HEADERS  += mainwindow.h \
    BST.h

FORMS    += mainwindow.ui
