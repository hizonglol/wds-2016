#include "kanwa.h"

Kanwa::Kanwa(QWidget *parent) : QWidget(parent)
{
    _wOkZak = new OknoZZakladkami(this);
    _wOkZak -> setGeometry(10,10,250,150);
    _wOkZak -> addTab(_wOkZak, tr("Mapa"));
    _wOkZak -> addTab(_wOkZak, tr("Miasto"));
}

void Kanwa::resizeEvent(QResizeEvent *event)
{
    _wOkZak -> setGeometry(5,5,event->size().width()-10,
                           event->size().height()-50);

}
