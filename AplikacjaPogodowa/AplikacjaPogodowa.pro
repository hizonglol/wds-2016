#-------------------------------------------------
#
# Project created by QtCreator 2016-04-24T19:47:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network xml

TARGET = AplikacjaPogodowa
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    kanwa.cpp \
    oknozzakladkami.cpp \
    miasto.cpp \
    mapa.cpp \
    zakladka.cpp

HEADERS  += mainwindow.h \
    kanwa.h \
    oknozzakladkami.h \
    miasto.h \
    mapa.h \
    zakladka.h

FORMS    += mainwindow.ui
