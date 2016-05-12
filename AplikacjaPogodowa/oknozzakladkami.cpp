#include "oknozzakladkami.h"

OknoZZakladkami::OknoZZakladkami(QWidget *parent) : QTabWidget(parent)
{
    _wMapa = new Mapa();
    this -> insertTab(0,_wMapa, tr("Mapa"));
    _wMapa -> show();
    _wZakMias = new ZakladkaMiasta("35.685,139.7513889", this);
    this -> insertTab(1,_wZakMias, tr("Tokio"));
}

/*
void OknoZZakladkami::resizeEvent(QResizeEvent *event)
{
    this -> setGeometry(0,0,event->size().width(),
                            event->size().height());

}
*/
