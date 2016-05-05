#include "oknozzakladkami.h"

OknoZZakladkami::OknoZZakladkami(QWidget *parent) : QTabWidget(parent)
{
    _wMapa = new Mapa();
    this -> insertTab(0,_wMapa, tr("Mapa"));
    _wMapa -> show();
    _wZakMias = new ZakladkaMiasta();
    this -> insertTab(0,_wZakMias, tr("Tokio"));
}
