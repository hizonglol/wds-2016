#include "zakladkamiasta.h"


ZakladkaMiasta::ZakladkaMiasta(QString nazwa, QWidget* parent) : QWidget(parent)
{


    _wWyglad = new QVBoxLayout(this);


    combo_box();

    this -> setLayout(_wWyglad);
    this -> show();
}


void ZakladkaMiasta::combo_box()
{

    _wMenuZapytan = new QComboBox(this);
    _wMenuZapytan -> setEditable(true);

    connect(_wMenuZapytan->lineEdit(), SIGNAL(editingFinished()), this, SLOT(czy_pobrane_koordynaty()));

    _wWyglad -> addWidget(_wMenuZapytan);
}

void ZakladkaMiasta::czy_pobrane_koordynaty()
{
    QString nazwa_miasta = _wMenuZapytan->currentText();
    _wWyszukiwarka = new WyszukiwarkaMiasta(nazwa_miasta);
    _wMenuZapytan -> setEditable(false);

    connect(_wWyszukiwarka, SIGNAL(dane_pobrane()), this, SLOT(wpisz_wyniki()));
}

void ZakladkaMiasta::wpisz_wyniki()
{

    _wMenuZapytan->removeItem(0);
    //QObject::disconnect(sender, signal, receiver, member);

    for(int i = 0; i < _wWyszukiwarka->_WynikiWyszukiwania.size(); ++i)

        _wMenuZapytan->addItem(_wWyszukiwarka->_WynikiWyszukiwania[i][0]);


    connect(_wMenuZapytan, SIGNAL(activated(int)), this, SLOT(uzyj_klikniete(int)));

}

bool ZakladkaMiasta::CzyChceszToMiasto()
{
    return QMessageBox::question(this, tr("Pytanie"),
                                 tr("Czy wybierasz to miasto?"),
                                 QMessageBox::Yes | QMessageBox::No,
                                 QMessageBox::No)
           == QMessageBox::Yes;
}


void ZakladkaMiasta::uzyj_klikniete(int indeks)
{
    if(CzyChceszToMiasto()) {

        qDebug() << _wWyszukiwarka->_WynikiWyszukiwania[indeks][1];

        QRegularExpression re("(\\d+)° (\\d+)'");

        /*
        QString przeszukiwany_string = "4.768 miles/s glupoty";
        QRegularExpression re1("(\\d+).(\\d+) miles/s");
        QRegularExpressionMatch match = re1.match(przeszukiwany_string);
        QString odpowiedz1 = match.captured(1);
        QString odpowiedz2 = match.captured(2);
        QString odpowiedz = odpowiedz1 + '.' + odpowiedz2;
        double wynik = odpowiedz.toDouble();
        qDebug() << wynik;
        */

        QRegularExpressionMatchIterator i = re.globalMatch(_wWyszukiwarka->_WynikiWyszukiwania[indeks][1]);
        QRegularExpressionMatch match1 = i.next();
        QString word1 = match1.captured(1);
        QString word2 = match1.captured(2);
        QRegularExpressionMatch match2 = i.next();
        QString word3 = match2.captured(1);
        QString word4 = match2.captured(2);
        QString koordynaty = word1 + '.' + word2 + ", " + word3 + '.' + word4;
        qDebug() << koordynaty;

        _wMenuZapytan -> setEnabled(false);
        _wMiasto = new Miasto(koordynaty);

        while(!_wMiasto->czy_pobrane) ;

        wyswietl_reszte_widzetow();
    }
}

void ZakladkaMiasta::wyswietl_reszte_widzetow(){

    qDebug() << "sygnal nadszedl";


    pierwszy_rzad();
    drugi_rzad();
    trzeci_rzad();
}


void ZakladkaMiasta::pierwszy_rzad()
{
    QGroupBox* _wRzadPierwszy = new QGroupBox(tr("Dzisiejsze dane pogodowe"));
    QHBoxLayout* _wRzad = new QHBoxLayout(_wRzadPierwszy);

    QPixmap _PlikIkony;
    QString _Zasob;
    qDebug() << _wMiasto -> teraz_dane("icon").toString();
    _Zasob = ":/new/weather_icons/weather_icons/" + _wMiasto -> teraz_dane("icon").toString() + ".png";
    _PlikIkony.load(_Zasob);

    QLabel* _wIkZach = new QLabel(this);
    QLCDNumber* _wTemper = new QLCDNumber(this);
    QLCDNumber* _wPrawdop = new QLCDNumber(this);

    _wIkZach -> setPixmap(_PlikIkony);
    _wTemper -> display(_wMiasto -> teraz_dane("temperature").toDouble());
    _wPrawdop -> display(_wMiasto -> teraz_dane("precipProbability").toDouble());


    QGroupBox* _wIkonkaPogodowa = new QGroupBox(_wMiasto -> teraz_dane("summary").toString());
    QHBoxLayout* _wWygladIkonki = new QHBoxLayout(_wIkonkaPogodowa);
    _wWygladIkonki -> addWidget(_wIkZach);
    _wIkonkaPogodowa->setLayout(_wWygladIkonki);

    _wRzad -> addWidget(_wIkonkaPogodowa);
    _wRzad -> addWidget(_wTemper);
    _wRzad -> addWidget(_wPrawdop);
    _wRzadPierwszy->setLayout(_wRzad);
    _wWyglad -> addWidget(_wRzadPierwszy);

}


void ZakladkaMiasta::drugi_rzad()
{
    QGroupBox* _wRzadDrugi = new QGroupBox(tr("Temperatura na nastepne 48 godzin"));
    QHBoxLayout* _wRzad = new QHBoxLayout(_wRzadDrugi);

    QCustomPlot* _wZachDzien = new QCustomPlot(this);
    _wZachDzien -> addGraph();
    _wZachDzien -> addGraph();
    double ymin = 200;
    double ymax = -200;
    _wZachDzien -> xAxis -> setLabel(tr("godzina"));
    _wZachDzien -> xAxis -> setRange(0, 48);
    _wZachDzien -> yAxis -> setLabel(tr("temperatura"));
    _wZachDzien -> graph(0) -> setLineStyle(QCPGraph::lsStepCenter);

    QVector<double> x2_0(49), y2_0(49);
    QVector<double> x2_1(49), y2_1(49);
    for(int i = 0; i < 49; ++i) {
        x2_0[i] = x2_1[i] = i;
        y2_0[i] = _wMiasto -> godzin_dane(i, "temperature").toDouble();
        if(ymax < y2_0[i]) ymax = y2_0[i];
        if(ymin > y2_0[i]) ymin = y2_0[i];
        y2_1[i] = _wMiasto -> godzin_dane(i, "humidity").toDouble();
    }
    ymin = ymin - 1;
    ymax = ymax + 1;
    _wZachDzien -> yAxis -> setRange((int)ymin, (int)ymax);

    _wZachDzien -> graph(0) -> setPen(QPen(QColor(255, 100, 100)));
    _wZachDzien -> graph(0) -> setData(x2_0, y2_0);
    //_wZachDzien -> graph(0) -> setPen(QPen(QColor(100, 255, 100)));
    //_wZachDzien -> graph(1) -> setData(x2_1, y2_1);

    _wRzad -> addWidget(_wZachDzien);
    _wRzadDrugi->setLayout(_wRzad);
    _wWyglad -> addWidget(_wRzadDrugi);
}


void ZakladkaMiasta::trzeci_rzad()
{
    QGroupBox* _wRzadTrzeci = new QGroupBox(tr("Temperatura na nastepne 7 dni"));
    QHBoxLayout* _wRzad = new QHBoxLayout(_wRzadTrzeci);

    QCustomPlot* _wZachTydz = new QCustomPlot(this);
    _wZachTydz -> addGraph();
    _wZachTydz -> addGraph();
    double ymin = 200;
    double ymax = -200;
    _wZachTydz -> xAxis -> setLabel(tr("dzien"));
    _wZachTydz -> xAxis -> setRange(0, 7);
    _wZachTydz -> yAxis -> setLabel(tr("temperatura"));
    _wZachTydz -> graph(0) -> setLineStyle(QCPGraph::lsStepLeft);

    QVector<double> x3_0(8), y3_0(8);
    QVector<double> x3_1(8), y3_1(8);
    for(int i = 0; i < 8; ++i) {
        x3_0[i] = x3_1[i] = i;
        y3_0[i] = _wMiasto -> dzien_dane(i, "temperatureMax").toDouble();
        if(ymax < y3_0[i]) ymax = y3_0[i];
        if(ymin > y3_0[i]) ymin = y3_0[i];
        y3_1[i] = _wMiasto -> dzien_dane(i, "humidity").toDouble();
    }
    ymin = ymin - 1;
    ymax = ymax + 1;
    _wZachTydz -> yAxis -> setRange((int)ymin, (int)ymax);

    _wZachTydz -> graph(0) -> setPen(QPen(QColor(255, 100, 100)));
    _wZachTydz -> graph(0) -> setData(x3_0, y3_0);
    //_wZachTydz -> graph(0) -> setPen(QPen(QColor(100, 255, 100)));
    //_wZachTydz -> graph(1) -> setData(x3_1, y3_1);


    _wRzad -> addWidget(_wZachTydz);
    _wRzadTrzeci->setLayout(_wRzad);
    _wWyglad -> addWidget(_wRzadTrzeci);
}
