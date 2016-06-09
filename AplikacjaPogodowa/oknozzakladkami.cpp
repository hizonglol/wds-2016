#include "oknozzakladkami.h"

OknoZZakladkami::OknoZZakladkami(QWidget* parent) : QTabWidget(parent)
{
    _wMapa = new Mapa();
    Q_CHECK_PTR(_wMapa);
    this -> insertTab(0,_wMapa, "Map of Japan");
    _wMapa -> show();
    ZakladkaMiasta* ZakMias = new ZakladkaMiasta(this);
    Q_CHECK_PTR(ZakMias);
    _wvZakMias.push_back(ZakMias);
    this -> insertTab(1,ZakMias, "City");
    _wPrzycisk = new QWidget(this);
    this -> addTab(_wPrzycisk, "+");
    this -> setTabsClosable(true);
    this->tabBar()->tabButton(0, QTabBar::RightSide)->resize(0, 0);
    this->tabBar()->tabButton(2, QTabBar::RightSide)->resize(0, 0);
    connect(this, SIGNAL(tabBarClicked(int)), this, SLOT(czyKlikniete(int)));
    connect(this, SIGNAL(tabCloseRequested(int)), this, SLOT(czyMoznaZamknac(int)));
}


OknoZZakladkami::~OknoZZakladkami()
{
    delete _wMapa;

    while(!_wvZakMias.empty()) {
        delete _wvZakMias[0];
        _wvZakMias.pop_front();
    }
}


void OknoZZakladkami::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::LanguageChange) {
        this->setTabText(0, tr("Map of Japan"));

        for(int i = 1; i<this->count()-1; ++i)
            this->setTabText(i, tr("City"));
    }
    else
        QWidget::changeEvent(event);
}


void OknoZZakladkami::czyKlikniete(int index)
{
    if(index > 5 || index < 0) return;

    if(this->count()-1 == index) {
        ZakladkaMiasta* Zakladka = new ZakladkaMiasta(this);
        _wvZakMias.push_back(Zakladka);
        this -> insertTab(this->count()-1, Zakladka, "City");
    }

    if(this->count()-1 > 5)
        this->setTabEnabled(this->count()-1, false);
}


void OknoZZakladkami::czyMoznaZamknac(int index)
{
    if(index < 1 || this->count()-2 < index) return;

    this->removeTab(index);
    delete _wvZakMias[index-1];
    _wvZakMias.remove(index-1);

    if(this->count()-1 <= 5) this->setTabEnabled(this->count()-1, true);
}
