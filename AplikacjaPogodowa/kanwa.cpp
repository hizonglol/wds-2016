#include "kanwa.h"

Kanwa::Kanwa(QWidget *parent) : QWidget(parent)
{
    _wOkZak = new OknoZZakladkami(this);
    _wOkZak -> setGeometry(10,10,250,150);
    _wOkZak -> addTab(_wOkZak, tr("Mapa"));
    _wMapa = new Mapa(_wOkZak -> getLastTab());
    _wOkZak -> getLastTab() -> _Layout.addWidget(_wMapa,0,0);
    _wOkZak -> addTab(_wOkZak, tr("Miasto"));
}

void Kanwa::resizeEvent(QResizeEvent *event)
{
    _wOkZak -> setGeometry(0,0,event->size().width(),
                           event->size().height());

}
