#include "zakladkamiasta.h"


ZakladkaMiasta::ZakladkaMiasta(QString nazwa, QWidget* parent) : QWidget(parent)
{
    _wWyglad = new QVBoxLayout(this);

    _vwDanePogodowe.resize(12); //DOCELOWO 12
    for(int i=0; i<12; ++i)
        _vwDanePogodowe[i] = new DanaPogodowa(this);

    ComboBox();

    this -> setLayout(_wWyglad);
    this -> show();
}

/*
ZakladkaMiasta::~ZakladkaMiasta(){
    qDebug() << "1 ";
    delete _wWyszukiwarka;
    qDebug() << "2 ";
    delete _wMiasto;
    qDebug() << "3 ";
    delete _wWyglad;
    qDebug() << "4 ";
    delete _wMenuZapytan;
    qDebug() << "5 ";
    delete _wRzadPierwszy;
    qDebug() << "6 ";
    delete _wRzadPierwszyLayout;
    qDebug() << "7 ";
    delete _wIkonkaPogodowa;
    qDebug() << "8 ";
    delete _wWygladIkonki;
    qDebug() << "9 ";

    for(int i=0; i<12; ++i){
        delete _vwDanePogodowe[i];
    }

    qDebug() << "10 ";
    delete _wRzadDrugi;
    qDebug() << "11 ";
    delete _wRzadDrugiLayout;
    qDebug() << "12 ";
    delete _wZachDzien;
    qDebug() << "13 ";
    delete _wRzadTrzeci;
    qDebug() << "14 ";
    delete _wRzadTrzeciLayout;
    qDebug() << "15 ";
    delete _wZachTydz;
    qDebug() << "16 ";
}
*/

void ZakladkaMiasta::ComboBox()
{

    _wMenuZapytan = new QComboBox(this);
    _wMenuZapytan -> setEditable(true);

    connect(_wMenuZapytan->lineEdit(), SIGNAL(editingFinished()), this, SLOT(czyPobraneKoordynaty()));

    _wWyglad -> addWidget(_wMenuZapytan);
}

void ZakladkaMiasta::czyPobraneKoordynaty()
{
    QString nazwa_miasta = _wMenuZapytan->currentText();
    _wWyszukiwarka = new WyszukiwarkaMiasta(nazwa_miasta);
    _wMenuZapytan -> setEditable(false);

    connect(_wWyszukiwarka, SIGNAL(danePobrane()), this, SLOT(wpiszWyniki()));
}

void ZakladkaMiasta::wpiszWyniki()
{

    _wMenuZapytan->removeItem(0);

    for(int i = 0; i < _wWyszukiwarka->_WynikiWyszukiwania.size(); ++i)

        _wMenuZapytan->addItem(_wWyszukiwarka->_WynikiWyszukiwania[i][0]);


    connect(_wMenuZapytan, SIGNAL(activated(int)), this, SLOT(uzyjKlikniete(int)));

}

bool ZakladkaMiasta::CzyChceszToMiasto()
{
    return QMessageBox::question(this, tr("Attention"),
                                 tr("Are you sure you want to choose this city?"),
                                 QMessageBox::Yes | QMessageBox::No,
                                 QMessageBox::No)
           == QMessageBox::Yes;
}

void ZakladkaMiasta::uzyjKlikniete(int indeks)
{
    if(CzyChceszToMiasto()) {

        QRegularExpression re("(\\d+)° (\\d+)'");
        QRegularExpressionMatchIterator i = re.globalMatch(_wWyszukiwarka->_WynikiWyszukiwania[indeks][1]);
        QRegularExpressionMatch match1 = i.next();
        QString word1 = match1.captured(1);
        QString word2 = match1.captured(2);
        QRegularExpressionMatch match2 = i.next();
        QString word3 = match2.captured(1);
        QString word4 = match2.captured(2);
        QString koordynaty = word1 + '.' + word2 + ", " + word3 + '.' + word4;

        _wMenuZapytan -> setEnabled(false);
        _wMiasto = new Miasto(koordynaty);
        connect(_wMiasto, SIGNAL(danePobrane()), this, SLOT(wyswietlReszteWidzetow()));
        _wMiasto -> Inicjalizuj();
    }
}

void ZakladkaMiasta::wyswietlReszteWidzetow()
{

    PierwszyRzad();
    DrugiRzad();
    TrzeciRzad();
}

void ZakladkaMiasta::PierwszyRzad()
{
    _wRzadPierwszy = new QGroupBox(tr("Today's weather"));
    _wRzadPierwszyLayout = new QGridLayout(_wRzadPierwszy);

    for (int i=0; i<12; ++i)
        _vwDanePogodowe[i] = new DanaPogodowa(this);

    QPixmap _PlikIkony;
    QString _Zasob;
    _Zasob = ":/new/weather_icons/weather_icons/" + _wMiasto -> TerazDane("icon").toString() + ".png";
    _PlikIkony.load(_Zasob);
    QLabel* _wIkZach = new QLabel(this);
    _wIkZach -> setPixmap(_PlikIkony);
    _wIkonkaPogodowa = new QGroupBox(_wMiasto -> TerazDane("summary").toString());
    _wWygladIkonki = new QHBoxLayout(_wIkonkaPogodowa);
    _wWygladIkonki -> addWidget(_wIkZach);
    _wWygladIkonki -> setAlignment(Qt::AlignHCenter);
    //_wIkonkaPogodowa -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
    _wIkonkaPogodowa -> setLayout(_wWygladIkonki);
    _wRzadPierwszyLayout -> addWidget(_wIkonkaPogodowa,0,0,2,2);

    _vwDanePogodowe[0] -> DodajTytulIWartosc("Temperature (°F)", _wMiasto -> TerazDane("temperature").toDouble());
    _wRzadPierwszyLayout -> addWidget(_vwDanePogodowe[0],0,2,2,2);

    _vwDanePogodowe[1] -> DodajTytulIWartosc("Rain precipitation (m)", _wMiasto -> TerazDane("precipIntensity").toDouble());
    _vwDanePogodowe[2] -> DodajTytulIWartosc("Precipitation probability (%)", (_wMiasto -> TerazDane("precipProbability").toDouble())*100);
    _vwDanePogodowe[3] -> DodajTytulIWartosc("Apparent temperature (°F)", _wMiasto -> TerazDane("apparentTemperature").toDouble());
    _vwDanePogodowe[4] -> DodajTytulIWartosc("Dew point (°F)", _wMiasto -> TerazDane("dewPoint").toDouble());
    _vwDanePogodowe[5] -> DodajTytulIWartosc("Humidity (%)", (_wMiasto -> TerazDane("humidity").toDouble())*100);
    _vwDanePogodowe[6] -> DodajTytulIWartosc("Wind speed (mph)", _wMiasto -> TerazDane("windSpeed").toDouble());
    _vwDanePogodowe[7] -> DodajTytulIWartosc("Wind bearing (degrees)", _wMiasto -> TerazDane("windBearing").toDouble());
    _vwDanePogodowe[8] -> DodajTytulIWartosc("Cloud cover (%)", (_wMiasto -> TerazDane("cloudCover").toDouble())*100);
    _vwDanePogodowe[9] -> DodajTytulIWartosc("Pressure (mbar)", _wMiasto -> TerazDane("pressure").toDouble());
    _vwDanePogodowe[10] -> DodajTytulIWartosc("Ozone (µg m^-3)", _wMiasto -> TerazDane("ozone").toDouble());

    for(int i = 1; i<6; ++i)
        _wRzadPierwszyLayout -> addWidget(_vwDanePogodowe[i], 0, i+5,1,1);

    for(int i = 6; i<11; ++i)
        _wRzadPierwszyLayout -> addWidget(_vwDanePogodowe[i], 1, i,1,1);

    _wRzadPierwszy -> setLayout(_wRzadPierwszyLayout);
    _wWyglad -> addWidget(_wRzadPierwszy);


}


void ZakladkaMiasta::DrugiRzad()
{
    _wRzadDrugi = new QGroupBox(tr("Temperature for the next 48 hours"));
    _wRzadDrugiLayout = new QHBoxLayout(_wRzadDrugi);

    _wZachDzien = new QCustomPlot(this);
    _wZachDzien -> addGraph();
    _wZachDzien -> addGraph();
    double ymin = 200;
    double ymax = -200;
    _wZachDzien -> xAxis -> setLabel(tr("Hour"));
    _wZachDzien -> xAxis -> setRange(0, 48);
    _wZachDzien -> yAxis -> setLabel(tr("Temperature in F"));
    _wZachDzien -> graph(0) -> setLineStyle(QCPGraph::lsStepCenter);

    QVector<double> x2_0(49), y2_0(49);
    QVector<double> x2_1(49), y2_1(49);
    for(int i = 0; i < 49; ++i) {
        x2_0[i] = x2_1[i] = i;
        y2_0[i] = _wMiasto -> GodzinoweDane(i, "temperature").toDouble();
        if(ymax < y2_0[i]) ymax = y2_0[i];
        if(ymin > y2_0[i]) ymin = y2_0[i];
        y2_1[i] = _wMiasto -> GodzinoweDane(i, "humidity").toDouble();
    }
    ymin = ymin - 1;
    ymax = ymax + 1;
    _wZachDzien -> yAxis -> setRange((int)ymin, (int)ymax);

    _wZachDzien -> graph(0) -> setPen(QPen(QColor(255, 100, 100)));
    _wZachDzien -> graph(0) -> setData(x2_0, y2_0);
    //_wZachDzien -> graph(0) -> setPen(QPen(QColor(100, 255, 100)));
    //_wZachDzien -> graph(1) -> setData(x2_1, y2_1);

    _wRzadDrugiLayout -> addWidget(_wZachDzien);
    _wRzadDrugi->setLayout(_wRzadDrugiLayout);
    _wWyglad -> addWidget(_wRzadDrugi);
}

void ZakladkaMiasta::TrzeciRzad()
{
    _wRzadTrzeci = new QGroupBox(tr("Temperature for the next 7 days"));
    _wRzadTrzeciLayout = new QHBoxLayout(_wRzadTrzeci);

    _wZachTydz = new QCustomPlot(this);
    _wZachTydz -> addGraph();
    _wZachTydz -> addGraph();
    double ymin = 200;
    double ymax = -200;
    _wZachTydz -> xAxis -> setLabel(tr("Day"));
    _wZachTydz -> xAxis -> setRange(0, 7);
    _wZachTydz -> yAxis -> setLabel(tr("Temperature in F"));
    _wZachTydz -> graph(0) -> setLineStyle(QCPGraph::lsStepLeft);

    QVector<double> x3_0(8), y3_0(8);
    QVector<double> x3_1(8), y3_1(8);
    for(int i = 0; i < 8; ++i) {
        x3_0[i] = x3_1[i] = i;
        y3_0[i] = _wMiasto -> TygodnioweDane(i, "temperatureMax").toDouble();
        if(ymax < y3_0[i]) ymax = y3_0[i];
        if(ymin > y3_0[i]) ymin = y3_0[i];
        y3_1[i] = _wMiasto -> TygodnioweDane(i, "humidity").toDouble();
    }
    ymin = ymin - 1;
    ymax = ymax + 1;
    _wZachTydz -> yAxis -> setRange((int)ymin, (int)ymax);

    _wZachTydz -> graph(0) -> setPen(QPen(QColor(255, 100, 100)));
    _wZachTydz -> graph(0) -> setData(x3_0, y3_0);
    //_wZachTydz -> graph(0) -> setPen(QPen(QColor(100, 255, 100)));
    //_wZachTydz -> graph(1) -> setData(x3_1, y3_1);


    _wRzadTrzeciLayout -> addWidget(_wZachTydz);
    _wRzadTrzeci->setLayout(_wRzadTrzeciLayout);
    _wWyglad -> addWidget(_wRzadTrzeci);
}
