#include "mapa.h"

Mapa::Mapa(QWidget *parent) : QWidget(parent)
{
    QLabel *_wMapa = new QLabel;
    _PlikMapy.load("Japan_Fukuoka.png");
    if(!_PlikMapy.isNull())
    {
        _wMapa->setPixmap(_PlikMapy);
    }
    else
        qDebug() << "Cannot find picture...";
}
