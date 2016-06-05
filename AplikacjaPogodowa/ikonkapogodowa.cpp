#include "ikonkapogodowa.h"

IkonkaPogodowa::IkonkaPogodowa(QWidget* parent) : QGroupBox(parent)
{
    _wWygladIkonki = new QHBoxLayout(this);
}

IkonkaPogodowa::~IkonkaPogodowa()
{
    if(_wLabelIkonki != nullptr) {
        _wWygladIkonki -> removeWidget(_wLabelIkonki);
        delete _wLabelIkonki;
    }

    delete _wWygladIkonki;
}


void IkonkaPogodowa::Inicjalizuj(Miasto* miasto)
{
    _Zasob = ":/new/weather_icons/weather_icons/" + miasto -> TerazDane("icon").toString() + ".png";
    _PlikIkony.load(_Zasob);
    _wLabelIkonki = new QLabel(this);
    _wLabelIkonki -> setPixmap(_PlikIkony);
    this -> setTitle(miasto -> TerazDane("summary").toString());
    _wWygladIkonki -> addWidget(_wLabelIkonki);
    _wWygladIkonki -> setAlignment(Qt::AlignHCenter);
    this -> setLayout(_wWygladIkonki);
}
