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
    _wWyglad = new QGridLayout();

    _wIkZach = new QLabel();
    _wTemper = new QLCDNumber();
    _wPrawdop = new QLCDNumber();
    _wTekOpis = new QLabel();


    //rzad pierwszy
    _wWyglad -> addWidget(_wIkZach, 0, 0);
    _wWyglad -> addWidget(_wTemper, 0, 1);
    _wWyglad -> addWidget(_wPrawdop, 0, 2);
    _wWyglad -> addWidget(_wTekOpis, 0, 3, 4);

    //rzad drugi
    //_wWyglad -> addWidget(zachmurzenie, 1, 0);

    //rzad trzeci
    //_wWyglad -> addWidget(zachmurzenie, 2, 0);

    this -> setLayout(_wWyglad);
    this->show();
}
