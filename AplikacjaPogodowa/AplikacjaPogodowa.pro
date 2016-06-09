#-------------------------------------------------
#
# Project created by QtCreator 2016-04-24T19:47:50
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += /Ox /GA /GL /GS /Gw /Qpar /Qpar-report:2 /favor:AMD64

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network xml location printsupport

TARGET = AplikacjaPogodowa
TEMPLATE = app


SOURCES += main.cpp\
    miasto.cpp \
    mapa.cpp \
    oknozzakladkami.cpp \
    zakladkamiasta.cpp \
    wyszukiwarkamiasta.cpp \
    qcustomplot.cpp \
    danapogodowa.cpp \
    mainwindow.cpp \
    wykres1.cpp \
    wykres2.cpp \
    ikonkapogodowa.cpp

HEADERS  += \
    miasto.h \
    mapa.h \
    oknozzakladkami.h \
    zakladkamiasta.h \
    wyszukiwarkamiasta.h \
    qcustomplot.h \
    danapogodowa.h \
    mainwindow.h \
    wykres1.h \
    wykres2.h \
    ikonkapogodowa.h

FORMS    += \
    mainwindow.ui

DISTFILES +=

TRANSLATIONS += \
    languages/AplikacjaPogodowa_pl.ts \
    languages/AplikacjaPogodowa_de.ts \
    languages/AplikacjaPogodowa_en.ts

RESOURCES += \
    japan.qrc \
    weather_icons.qrc \
    general_icons.qrc \
    translations.qrc
