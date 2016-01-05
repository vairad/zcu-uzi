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

DEFINES += CLI

SOURCES  += main.cpp\
            core/mastermind.cpp \
            core/datacontroler.cpp \
            gui/mainwindow.cpp \
            gui/roundwidget.cpp \
            gui/gamedialog.cpp \
            gui/helpwindow.cpp \
            core/usermind.cpp \
    cli/cmdinterface.cpp \
    core/solutionfactory.cpp \
    core/entropysolver.cpp

HEADERS  += gui/mainwindow.h \
            gui/roundwidget.h \
            gui/gamedialog.h \
            gui/helpwindow.h \
            core/mastermind.h \
            core/datacontroler.h \
            core/imind.h \
            core/usermind.h \
            core/exception.h \
    cli/cmdinterface.h \
    core/solutionfactory.h \
    core/entropysolver.h \
    core/isolver.h

FORMS    += gui/mainwindow.ui
