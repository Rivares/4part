#-------------------------------------------------
#
# Project created by QtCreator 2013-03-30T21:19:51
#
#-------------------------------------------------

QT       += core gui

#-----It's OpenMP library! It's helping paralellize program->>>--------
QMAKE_CXXFLAGS += -fopenmp
LIBS += -fopenmp
#----<<<-Configured MinGW for to use OpenMP library--------------------

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Graphs
TEMPLATE = app

-std=c++11

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
