#include "mapa.h"

Mapa::Mapa(QWidget *parent) : QWidget(parent)
{
    _wMapa = new QLabel(this);

    if(_PlikMapy.load(":/new/mapy/Japan_Fukuoka.png"))
    {
        _wRysownik = new QPainter(this);
        //qDebug() << "Picture loaded";
    }
    else
        qDebug() << "Cannot load picture...";

    _vMiasta.reserve(9);

    Miasto *miasto = new Miasto("43.066667, 141.35"); //sapporo
    _vMiasta.push_back(miasto);
    miasto = new Miasto("38.266667, 140.866667"); //sendai
    _vMiasta.push_back(miasto);
    miasto = new Miasto(); //tokio
    _vMiasta.push_back(miasto);
    miasto = new Miasto("35.183333, 136.9"); //nagoya
    _vMiasta.push_back(miasto);
    miasto = new Miasto("34.693889, 135.502222"); //osaka
    _vMiasta.push_back(miasto);
    miasto = new Miasto("34.385278, 132.455278"); //hiroshima
    _vMiasta.push_back(miasto);
    miasto = new Miasto("33.833333, 132.766667"); //matsuyama
    _vMiasta.push_back(miasto);
    miasto = new Miasto("33.583333, 130.4"); //fukuoka
    _vMiasta.push_back(miasto);
    miasto = new Miasto("26.212222, 127.679167"); //naha
    _vMiasta.push_back(miasto);

    _vNazwy.reserve(9);

    QString tekst = "Sapporo " + QString::number(_vMiasta[0] -> teraz_dane("temperature").toDouble()) + 'F';
    _vNazwy.push_back(tekst);
    tekst = "Sendai " + QString::number(_vMiasta[1] -> teraz_dane("temperature").toDouble()) + 'F';
    _vNazwy.push_back(tekst);
    tekst = "Tokio " + QString::number(_vMiasta[2] -> teraz_dane("temperature").toDouble()) + 'F';
    _vNazwy.push_back(tekst);
    tekst = "Nagoya " + QString::number(_vMiasta[3] -> teraz_dane("temperature").toDouble()) + 'F';
    _vNazwy.push_back(tekst);
    tekst = "Osaka " + QString::number(_vMiasta[4] -> teraz_dane("temperature").toDouble()) + 'F';
    _vNazwy.push_back(tekst);
    tekst = "Hiroshima " + QString::number(_vMiasta[5] -> teraz_dane("temperature").toDouble()) + 'F';
    _vNazwy.push_back(tekst);
    tekst = "Matsuyama " + QString::number(_vMiasta[6] -> teraz_dane("temperature").toDouble()) + 'F';
    _vNazwy.push_back(tekst);
    tekst = "Fukuoka " + QString::number(_vMiasta[7] -> teraz_dane("temperature").toDouble()) + 'F';
    _vNazwy.push_back(tekst);
    tekst = "Naha " + QString::number(_vMiasta[8] -> teraz_dane("temperature").toDouble()) + 'F';
    _vNazwy.push_back(tekst);
}


void Mapa::resizeEvent(QResizeEvent *event)
{
    x=event->size().width();
    y=event->size().height();

}


void Mapa::paintEvent(QPaintEvent *event)
{
    _wRysownik -> begin(this);
    QFont czcionka;
    czcionka = _wRysownik->font();

    int font_size;
    font_size = (int)((((float)x+(float)y)/2)/55 + 40/11);

    czcionka.setPointSize(font_size); // Zmiana rozmiaru czcionki
    _wRysownik->setFont(czcionka);

    QPen dlugopis(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    _wRysownik->setPen(dlugopis);

    _wRysownik->drawPixmap(0, 0, x, y, _PlikMapy);

    //sapporo
    xt = 0.68*x;
    yt = 0.22*y;
    _wRysownik->drawText(xt, yt, _vNazwy[0]);

    //sendai
    xt = 0.67*x;
    yt = 0.47*y;
    _wRysownik->drawText(xt, yt, _vNazwy[1]);

    //tokio
    xt = 0.63*x;
    yt = 0.58*y;
    _wRysownik->drawText(xt, yt, _vNazwy[2]);

    //nagoya
    xt = 0.50*x;
    yt = 0.62*y;
    _wRysownik->drawText(xt, yt, _vNazwy[3]);

    //osaka
    xt = 0.43*x;
    yt = 0.66*y;
    _wRysownik->drawText(xt, yt, _vNazwy[4]);

    //hiroshima
    xt = 0.22*x;
    yt = 0.65*y;
    _wRysownik->drawText(xt, yt, _vNazwy[5]);

    //matsuyama
    xt = 0.31*x;
    yt = 0.70*y;
    _wRysownik->drawText(xt, yt, _vNazwy[6]);

    //fukuoka
    xt = 0.12*x;
    yt = 0.70*y;
    _wRysownik->drawText(xt, yt, _vNazwy[7]);

    //okinawa
    xt = 0.83*x;
    yt = 0.90*y;
    _wRysownik->drawText(xt, yt, _vNazwy[8]);

    _wRysownik->end();
}

