#include "oknozzakladkami.h"

OknoZZakladkami::OknoZZakladkami(QWidget* parent) : QTabWidget(parent)
{
    _wMapa = new Mapa();
    this -> insertTab(0,_wMapa, tr("Map of Japan"));
    _wMapa -> show();
    _wZakMias = new ZakladkaMiasta(this);
    this -> insertTab(1,_wZakMias, tr("City"));
}


OknoZZakladkami::~OknoZZakladkami()
{
    delete _wMapa;
    delete _wZakMias;
}
