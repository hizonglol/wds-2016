#include "oknozzakladkami.h"

OknoZZakladkami::OknoZZakladkami(QWidget *parent) : QTabWidget(parent)
{
    Mapa *wMapa = new Mapa(this);
    this -> insertTab(0,wMapa, tr("Mapa"));
    //wMapa -> setGeometry(0,0,50,50);
    wMapa -> show();
    Miasto *wMiasto = new Miasto("35.685,139.7513889");
    wMiasto -> tydzien_podsum();
}
