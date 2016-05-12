#include "mapa.h"

Mapa::Mapa(QWidget *parent) : QLabel(parent)
{
    //QLabel *_wMapa = new QLabel(this);
    if(_PlikMapy.load("Japan_Fukuoka.png"))
    {
        //_wMapa->setPixmap(_PlikMapy);
        setPixmap(_PlikMapy);
        qDebug() << "Picture loaded";
    }
    else
        qDebug() << "Cannot load picture...";
}
