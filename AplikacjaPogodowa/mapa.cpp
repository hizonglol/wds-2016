#include "mapa.h"

Mapa::Mapa(QWidget* parent) : QWidget(parent)
{
    _wMapa = new QLabel(this);

    if(_PlikMapy.load(":/new/mapy/Japan_Fukuoka.png"))
        _wRysownik = new QPainter();
    else
        qDebug() << "Nie można zaladowac pliku z mapa...";

    _vMiasta.reserve(9);
    _vKoordynaty.resize(9);
    _vNazwy.resize(9);

    _vKoordynaty[0] = "43.066667, 141.35";  //sapporo
    _vKoordynaty[1] = "38.266667, 140.866667";  //sendai
    _vKoordynaty[2] = "35.6895, 139.69171";  //tokio
    _vKoordynaty[3] = "35.183333, 136.9";  //nagoya
    _vKoordynaty[4] = "34.693889, 135.502222";  //osaka
    _vKoordynaty[5] = "34.385278, 132.455278";  //hiroshima
    _vKoordynaty[6] = "33.833333, 132.766667";  //matsuyama
    _vKoordynaty[7] = "33.583333, 130.4";  //fukuoka
    _vKoordynaty[8] = "26.212222, 127.679167";  //naha
    _vNazwy[0] = "Sapporo ";
    _vNazwy[1] = "Sendai ";
    _vNazwy[2] = "Tokio ";
    _vNazwy[3] = "Nagoya ";
    _vNazwy[4] = "Osaka ";
    _vNazwy[5] = "Hiroshima ";
    _vNazwy[6] = "Matsuyama ";
    _vNazwy[7] = "Fukuoka ";
    _vNazwy[8] = "Naha ";

    for (int i = 0; i<9; ++i) {

        Miasto* miasto = new Miasto(_vKoordynaty[i]);
        miasto -> Inicjalizuj();
        _vMiasta.push_back(miasto);
        _vNazwy[i].append(QString::number(_vMiasta[i] -> TerazDane("temperature").toDouble()) + 'F');
    }
}

/*
Mapa::~Mapa(){

    delete _wRysownik;
    delete _wMapa;

    for(int i=0; i<9; ++i){
        delete _vMiasta[i];
    }

}
*/


void Mapa::resizeEvent(QResizeEvent* event)
{
    _x=event->size().width();
    _y=event->size().height();

}


void Mapa::paintEvent(QPaintEvent* event)
{
    _wRysownik -> begin(this);
    QFont czcionka;
    czcionka = _wRysownik->font();

    int font_size;
    font_size = (int)((((float)_x+(float)_y)/2)/55 + 40/11);

    czcionka.setPointSize(font_size); // Zmiana rozmiaru czcionki
    _wRysownik->setFont(czcionka);

    QPen dlugopis(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    _wRysownik->setPen(dlugopis);

    _wRysownik->drawPixmap(0, 0, _x, _y, _PlikMapy);

    //sapporo
    _xt = 0.68*_x;
    _yt = 0.22*_y;
    _wRysownik->drawText(_xt, _yt, _vNazwy[0]);

    //sendai
    _xt = 0.67*_x;
    _yt = 0.47*_y;
    _wRysownik->drawText(_xt, _yt, _vNazwy[1]);

    //tokio
    _xt = 0.63*_x;
    _yt = 0.58*_y;
    _wRysownik->drawText(_xt, _yt, _vNazwy[2]);

    //nagoya
    _xt = 0.50*_x;
    _yt = 0.62*_y;
    _wRysownik->drawText(_xt, _yt, _vNazwy[3]);

    //osaka
    _xt = 0.43*_x;
    _yt = 0.66*_y;
    _wRysownik->drawText(_xt, _yt, _vNazwy[4]);

    //hiroshima
    _xt = 0.22*_x;
    _yt = 0.65*_y;
    _wRysownik->drawText(_xt, _yt, _vNazwy[5]);

    //matsuyama
    _xt = 0.31*_x;
    _yt = 0.70*_y;
    _wRysownik->drawText(_xt, _yt, _vNazwy[6]);

    //fukuoka
    _xt = 0.12*_x;
    _yt = 0.70*_y;
    _wRysownik->drawText(_xt, _yt, _vNazwy[7]);

    //okinawa
    _xt = 0.83*_x;
    _yt = 0.90*_y;
    _wRysownik->drawText(_xt, _yt, _vNazwy[8]);

    _wRysownik->end();
}
