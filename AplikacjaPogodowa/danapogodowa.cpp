#include "danapogodowa.h"

DanaPogodowa::DanaPogodowa(QWidget* parent) : QFrame(parent)
{
    _wWyglad = new QVBoxLayout(this);
}


DanaPogodowa::~DanaPogodowa()
{
    _wWyglad -> removeWidget(_wTytul);
    _wWyglad -> removeWidget(_wLCD);
    delete _wTytul;
    delete _wLCD;
    delete _wWyglad;
}


void DanaPogodowa::DodajTytulIWartosc(QString title, double number)
{
    _wTytul = new QLabel(this);
    _wLCD = new QLCDNumber(this);
    _wTytul -> setText(title);
    _wTytul -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    _wWyglad -> addWidget(_wTytul);
    _wWyglad -> setAlignment(_wTytul, Qt::AlignHCenter);
    _wLCD -> display(number);
    _wLCD -> setFrameShape(QFrame::NoFrame);
    _wWyglad -> addWidget(_wLCD);
    this -> setFrameStyle(QFrame::Box);
}
