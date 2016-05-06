#include "zakladkamiasta.h"

ZakladkaMiasta::ZakladkaMiasta(QWidget *parent) : QWidget(parent)
{
    _wMiasto = new Miasto();
    _wWyglad = new QGridLayout();

    this -> setLayout(_wWyglad);
    this->show();
}

ZakladkaMiasta::ZakladkaMiasta(QString nazwa, QWidget *parent) : QWidget(parent)
{
    _wMiasto = new Miasto(nazwa);
    _wWyglad = new QGridLayout(this);

    _wIkZach = new QLabel();
    _wTemper = new QLCDNumber();
    _wPrawdop = new QLCDNumber();
    _wTekOpis = new QLabel();
    //_wZachDzien = new Q3DBars();
    //_wZachTydz = new Q3DBars();

    _wIkZach -> setText(_wMiasto -> teraz_dane("icon").toString());
    _wTemper -> display(_wMiasto -> teraz_dane("temperature").toDouble());
    _wPrawdop -> display(_wMiasto -> teraz_dane("precipProbability").toDouble());
    _wTekOpis -> setText(_wMiasto -> teraz_dane("summary").toString());

    //rzad pierwszy
    _wWyglad -> addWidget(_wIkZach, 0, 0);
    _wWyglad -> addWidget(_wTemper, 0, 1);
    _wWyglad -> addWidget(_wPrawdop, 0, 2);
    _wWyglad -> addWidget(_wTekOpis, 0, 3, 4, 2);

    //rzad drugi
    //_wWyglad -> addWidget(_wZachDzien, 1, 0);

    //rzad trzeci
    //_wWyglad -> addWidget(_wZachTydz, 2, 0);

    this -> setLayout(_wWyglad);
    this -> show();
}
