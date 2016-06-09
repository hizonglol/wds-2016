#include "zakladkamiasta.h"


ZakladkaMiasta::ZakladkaMiasta(QWidget* parent) : QWidget(parent)
{
    _wWyglad = new QVBoxLayout(this);
    Q_CHECK_PTR(_wWyglad);
    _vwDanePogodowe.resize(11);
    _wTytulZapytania = new QLabel(this);
    Q_CHECK_PTR(_wTytulZapytania);
    _wTytulZapytania -> setText("Please type the place of your interests below");
    _wWyglad -> addWidget(_wTytulZapytania);
    _wWyglad -> setAlignment(_wTytulZapytania, Qt::AlignBottom);
    ComboBox();
    this -> setLayout(_wWyglad);
    this -> show();
}


ZakladkaMiasta::~ZakladkaMiasta()
{
    if(_wWyszukiwarka != nullptr) {
        delete _wWyszukiwarka;
        _wWyszukiwarka = nullptr;
    }

    if(_wMiasto != nullptr) {
        delete _wMiasto;
        _wMiasto = nullptr;
    }

    if(_wTytulZapytania != nullptr) {
        _wWyglad -> removeWidget(_wTytulZapytania);
        delete _wTytulZapytania;
        _wTytulZapytania = nullptr;
    }

    if(_wWyglad != nullptr) {
        _wWyglad -> removeWidget(_wMenuZapytan);
        delete _wMenuZapytan;
        _wMenuZapytan = nullptr;
    }

    if(_wRzadPierwszyLayout != nullptr) {
        _wWyglad -> removeWidget(_wRzadPierwszy);
        _wRzadPierwszyLayout -> removeWidget(_wIkonkaPogodowa);
        delete _wIkonkaPogodowa;

        for(int i=0; i<11; ++i) {
            _wRzadPierwszyLayout -> removeWidget(_vwDanePogodowe[i]);
            delete _vwDanePogodowe[i];
        }

        delete _wRzadPierwszy -> layout();
        delete _wRzadPierwszy;

        while(!_vwDanePogodowe.empty()) _vwDanePogodowe.pop_back();
    }

    if(_wRzadDrugiLayout != nullptr) {
        _wWyglad -> removeWidget(_wRzadDrugi);
        _wRzadDrugiLayout -> removeWidget(_wWykresPierwszy);
        delete _wWykresPierwszy;
        delete _wRzadDrugi -> layout();
        delete _wRzadDrugi;
    }

    if(_wRzadTrzeciLayout != nullptr) {
        _wWyglad -> removeWidget(_wRzadTrzeci);
        _wRzadTrzeciLayout -> removeWidget(_wWykresDrugi);
        delete _wWykresDrugi;
        delete _wRzadTrzeci -> layout();
        delete _wRzadTrzeci;
    }

    if(_wWyglad != nullptr) {
        delete _wWyglad;
        _wWyglad = nullptr;
    }
}


void ZakladkaMiasta::ComboBox()
{
    if (_wMenuZapytan == nullptr) {
        _wMenuZapytan = new QComboBox(this);
        Q_CHECK_PTR(_wMenuZapytan);
        _wWyglad -> addWidget(_wMenuZapytan);
        _wWyglad -> setAlignment(_wMenuZapytan, Qt::AlignTop);
    }

    _wMenuZapytan -> setEditable(true);
    connect(_wMenuZapytan->lineEdit(), SIGNAL(editingFinished()), this, SLOT(czyPobraneKoordynaty()));
}

void ZakladkaMiasta::czyPobraneKoordynaty()
{
    disconnect(_wMenuZapytan->lineEdit(), SIGNAL(editingFinished()), this, SLOT(czyPobraneKoordynaty()));
    QString nazwa_miasta = _wMenuZapytan->currentText();
    _wWyszukiwarka = new WyszukiwarkaMiasta(nazwa_miasta);
    Q_CHECK_PTR(_wWyszukiwarka);
    _wMenuZapytan -> setEditable(false);
    connect(_wWyszukiwarka, SIGNAL(danePobrane()), this, SLOT(wpiszWyniki()));
}

void ZakladkaMiasta::wpiszWyniki()
{
    disconnect(_wWyszukiwarka, SIGNAL(danePobrane()), this, SLOT(wpiszWyniki()));
    _wMenuZapytan->removeItem(0);

    if(_wWyszukiwarka->_vWynikiWyszukiwania.size() == 0) {
        delete _wWyszukiwarka;
        _wWyszukiwarka = nullptr;
        _wMenuZapytan -> setEnabled(true);
        ComboBox();
        return;
    }

    for(int i = 0; i < _wWyszukiwarka->_vWynikiWyszukiwania.size(); ++i)
        _wMenuZapytan->addItem(_wWyszukiwarka->_vWynikiWyszukiwania[i][0]);

    connect(_wMenuZapytan, SIGNAL(activated(int)), this, SLOT(uzyjKlikniete(int)));
}

bool ZakladkaMiasta::CzyChceszToMiasto(int indeks)
{
    QMessageBox question;
    question.setWindowTitle(tr("Attention"));
    QString tekst_zapytania;
    tekst_zapytania = tr("Are you sure you want to choose this city:");
    tekst_zapytania.append(' ');
    tekst_zapytania.append(_wWyszukiwarka->_vWynikiWyszukiwania[indeks][0]);
    tekst_zapytania.append('?');
    question.setText(tekst_zapytania);
    question.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    question.setDefaultButton(QMessageBox::No);
    question.setIconPixmap(QPixmap(":/new/general_icons/general_icons/confuzed-rain.png"));
    QIcon Ikona;
    Ikona.addFile(":/new/general_icons/general_icons/sniezynka.png");
    question.setWindowIcon(Ikona);

    if(question.exec() == QMessageBox::Yes)
        return true; else

        return false;
}

void ZakladkaMiasta::uzyjKlikniete(int indeks)
{
    if(_wWyszukiwarka->_vWynikiWyszukiwania.size() != 1)
        if(!CzyChceszToMiasto(indeks)) return;

    _wWyglad -> removeWidget(_wTytulZapytania);
    delete _wTytulZapytania;
    _wTytulZapytania = nullptr;
    QRegularExpression re("(\\d+)° (\\d+)'");
    QRegularExpressionMatchIterator i = re.globalMatch(_wWyszukiwarka->_vWynikiWyszukiwania[indeks][1]);
    QRegularExpressionMatch match1 = i.next();
    QString word1 = match1.captured(1);
    QString word2 = match1.captured(2);
    QRegularExpressionMatch match2 = i.next();
    QString word3 = match2.captured(1);
    QString word4 = match2.captured(2);
    QString koordynaty = word1 + '.' + word2 + ", " + word3 + '.' + word4;
    _wMenuZapytan -> setEnabled(false);
    _wMenuZapytan -> setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    _wWyglad -> setAlignment(_wMenuZapytan, Qt::AlignAbsolute | Qt::AlignLeft);
    _wMiasto = new Miasto(koordynaty);
    Q_CHECK_PTR(_wMiasto);
    connect(_wMiasto, SIGNAL(danePobrane()), this, SLOT(wyswietlReszteWidzetow()));
    _wMiasto -> Inicjalizuj();
}

void ZakladkaMiasta::wyswietlReszteWidzetow()
{
    PierwszyRzad();
    DrugiRzad();
    TrzeciRzad();
}

void ZakladkaMiasta::PierwszyRzad()
{
    _wRzadPierwszy = new QGroupBox("Today's weather");
    Q_CHECK_PTR(_wRzadPierwszy);
    _wRzadPierwszyLayout = new QGridLayout(_wRzadPierwszy);
    Q_CHECK_PTR(_wRzadPierwszyLayout);

    for (int i=0; i<11; ++i) {
        _vwDanePogodowe[i] = new DanaPogodowa(this);
        Q_CHECK_PTR(_vwDanePogodowe[i]);
    }

    _wIkonkaPogodowa = new IkonkaPogodowa(this);
    Q_CHECK_PTR(_wIkonkaPogodowa);
    _wIkonkaPogodowa -> Inicjalizuj(_wMiasto);
    _wRzadPierwszyLayout -> addWidget(_wIkonkaPogodowa,0,0,2,2);
    _vwDanePogodowe[0] -> DodajTytulIWartosc("Temperature (°F)", _wMiasto -> TerazDane("temperature").toDouble());
    _wRzadPierwszyLayout -> addWidget(_vwDanePogodowe[0],0,2,2,2);
    _vwDanePogodowe[1] -> DodajTytulIWartosc("Forecasted rain (m)", _wMiasto -> TerazDane("precipIntensity").toDouble());
    _vwDanePogodowe[2] -> DodajTytulIWartosc("Rain precipitation (%)", (_wMiasto -> TerazDane("precipProbability").toDouble())*100);
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
    _wRzadDrugi = new QGroupBox("Temperature for the next 48 hours");
    Q_CHECK_PTR(_wRzadDrugi);
    _wRzadDrugiLayout = new QHBoxLayout(_wRzadDrugi);
    Q_CHECK_PTR(_wRzadDrugiLayout);
    _wWykresPierwszy = new Wykres1(this);
    Q_CHECK_PTR(_wWykresPierwszy);
    _wWykresPierwszy -> DodajTytulIWykres(_wMiasto -> DwaDniPodsum().toString(), _wMiasto);
    _wRzadDrugiLayout -> addWidget(_wWykresPierwszy);
    _wRzadDrugi->setLayout(_wRzadDrugiLayout);
    _wWyglad -> addWidget(_wRzadDrugi);
}

void ZakladkaMiasta::TrzeciRzad()
{
    _wRzadTrzeci = new QGroupBox("Temperature for the next 7 days");
    Q_CHECK_PTR(_wRzadTrzeci);
    _wRzadTrzeciLayout = new QHBoxLayout(_wRzadTrzeci);
    Q_CHECK_PTR(_wRzadTrzeciLayout);
    _wWykresDrugi = new Wykres2(this);
    Q_CHECK_PTR(_wWykresDrugi);
    _wWykresDrugi -> DodajTytulIWykres(_wMiasto -> TydzienPodsum().toString(), _wMiasto);
    _wRzadTrzeciLayout -> addWidget(_wWykresDrugi);
    _wRzadTrzeci->setLayout(_wRzadTrzeciLayout);
    _wWyglad -> addWidget(_wRzadTrzeci);
}


void ZakladkaMiasta::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::LanguageChange) {
        if(_wTytulZapytania != nullptr) _wTytulZapytania->setText(tr("Please type the place of your interests below"));

        if(_wRzadPierwszyLayout != nullptr) {
            _wRzadPierwszy -> setTitle(tr("Today's weather"));
            _vwDanePogodowe[0] -> ZmienTytul(tr("Temperature (°F)"));
            _vwDanePogodowe[1] -> ZmienTytul(tr("Forecasted rain (m)"));
            _vwDanePogodowe[2] -> ZmienTytul(tr("Rain precipitation (%)"));
            _vwDanePogodowe[3] -> ZmienTytul(tr("Apparent temperature (°F)"));
            _vwDanePogodowe[4] -> ZmienTytul(tr("Dew point (°F)"));
            _vwDanePogodowe[5] -> ZmienTytul(tr("Humidity (%)"));
            _vwDanePogodowe[6] -> ZmienTytul(tr("Wind speed (mph)"));
            _vwDanePogodowe[7] -> ZmienTytul(tr("Wind bearing (degrees)"));
            _vwDanePogodowe[8] -> ZmienTytul(tr("Cloud cover (%)"));
            _vwDanePogodowe[9] -> ZmienTytul(tr("Pressure (mbar)"));
            _vwDanePogodowe[10] -> ZmienTytul(tr("Ozone (µg m^-3)"));
        }

        if(_wRzadDrugiLayout != nullptr)
            _wRzadDrugi -> setTitle(tr("Temperature for the next 48 hours"));

        if(_wRzadTrzeciLayout != nullptr)
            _wRzadTrzeci -> setTitle(tr("Temperature for the next 7 days"));
    }
    else
        QWidget::changeEvent(event);
}
