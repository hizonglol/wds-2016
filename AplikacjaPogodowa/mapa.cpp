#include "mapa.h"

Mapa::Mapa(QWidget *parent) : QWidget(parent)
{
    _wWyglad = new QGridLayout(this);
    _wMapa = new QLabel(this);

    if(_PlikMapy.load("Japan_Fukuoka.png"))
    {
        _wMapa->setPixmap(_PlikMapy.scaled(250, 250));
        //qDebug() << "Picture loaded";
        _wWyglad -> addWidget(_wMapa, 0, 0);
    }
    else
        qDebug() << "Cannot load picture...";
}


void Mapa::resizeEvent(QResizeEvent *event)
{
    _wMapa -> setPixmap(_PlikMapy.scaled((event->size().width()-20), (event->size().height()-40)));

}
