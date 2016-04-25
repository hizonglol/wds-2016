#include "oknozzakladkami.h"

OknoZZakladkami::OknoZZakladkami(QWidget *parent) : QTabWidget(parent)
{

}

void OknoZZakladkami::addTab(QTabWidget *tabWidget, QString title)
{
    Zakladka *wZakladka = new Zakladka();
    tabWidget -> addTab(wZakladka, title);
    _vwZakladki.push_back(wZakladka);
}

Zakladka* OknoZZakladkami::getLastTab()
{
    return _vwZakladki.last();
}
