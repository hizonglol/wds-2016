#include "oknozzakladkami.h"

OknoZZakladkami::OknoZZakladkami(QWidget *parent) : QTabWidget(parent)
{
    _wMapa = new Mapa();
    this -> insertTab(0,_wMapa, tr("Mapa"));
    _wMapa -> show();
    _wZakMias = new ZakladkaMiasta("35.685,139.7513889", this);
    this -> insertTab(1,_wZakMias, tr("Tokio"));
}
