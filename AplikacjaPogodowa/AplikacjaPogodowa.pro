#-------------------------------------------------
#
# Project created by QtCreator 2016-04-24T19:47:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network xml location

TARGET = AplikacjaPogodowa
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    miasto.cpp \
    mapa.cpp \
    oknozzakladkami.cpp \
    zakladkamiasta.cpp \
    wyszukiwarkamiasta.cpp

HEADERS  += mainwindow.h \
    miasto.h \
    mapa.h \
    oknozzakladkami.h \
    zakladkamiasta.h \
    wyszukiwarkamiasta.h

FORMS    += mainwindow.ui

DISTFILES +=
