#-------------------------------------------------
#
# Project created by QtCreator 2015-12-06T12:59:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mastermind
TEMPLATE = app


SOURCES += main.cpp\
           gui/mainwindow.cpp \
           gui/roundwidget.cpp

HEADERS  += gui/mainwindow.h \
            gui/roundwidget.h

FORMS    += gui/mainwindow.ui
