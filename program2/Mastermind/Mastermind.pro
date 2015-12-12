#-------------------------------------------------
#
# Project created by QtCreator 2015-12-06T12:59:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mastermind
TEMPLATE = app
CONFIG += c++11


SOURCES  += main.cpp\
            core/mastermind.cpp \
            core/datacontroler.cpp \
            gui/mainwindow.cpp \
            gui/roundwidget.cpp \
            gui/gamedialog.cpp \
            gui/helpwindow.cpp

HEADERS  += gui/mainwindow.h \
            gui/roundwidget.h \
            gui/gamedialog.h \
            gui/helpwindow.h \
            core/mastermind.h \
            core/datacontroler.h

FORMS    += gui/mainwindow.ui
