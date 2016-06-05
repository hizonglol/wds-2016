#include "zakladkamiasta.h"


ZakladkaMiasta::ZakladkaMiasta(QWidget* parent) : QWidget(parent)
{
    _wWyglad = new QVBoxLayout(this);
    _vwDanePogodowe.resize(11);

    for(int i=0; i<11; ++i)
        _vwDanePogodowe[i] = new DanaPogodowa(this);

    _wTytulZapytania = new QLabel(this);
    _wTytulZapytania -> setText("Please type the place of your interests below");
    _wWyglad -> addWidget(_wTytulZapytania);
    ComboBox();
    this -> setLayout(_wWyglad);
    this -> show();
}


ZakladkaMiasta::~ZakladkaMiasta()
{
    if(_wWyszukiwarka != nullptr) delete _wWyszukiwarka;

    if(_wMiasto != nullptr) delete _wMiasto;

    if(_wTytulZapytania != nullptr) {
        _wWyglad -> removeWidget(_wTytulZapytania);
        delete _wTytulZapytania;
    }

    _wWyglad -> removeWidget(_wMenuZapytan);
    delete _wMenuZapytan;

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

    delete _wWyglad;
}


void ZakladkaMiasta::ComboBox()
{
    if (_wMenuZapytan == nullptr) {
        _wMenuZapytan = new QComboBox(this);
        _wWyglad -> addWidget(_wMenuZapytan);
    }

    _wMenuZapytan -> setEditable(true);
    connect(_wMenuZapytan->lineEdit(), SIGNAL(editingFinished()), this, SLOT(czyPobraneKoordynaty()));
}

void ZakladkaMiasta::czyPobraneKoordynaty()
{
    disconnect(_wMenuZapytan->lineEdit(), SIGNAL(editingFinished()), this, SLOT(czyPobraneKoordynaty()));
    QString nazwa_miasta = _wMenuZapytan->currentText();
    _wWyszukiwarka = new WyszukiwarkaMiasta(nazwa_miasta);
    _wMenuZapytan -> setEditable(false);
    connect(_wWyszukiwarka, SIGNAL(danePobrane()), this, SLOT(wpiszWyniki()));
}

void ZakladkaMiasta::wpiszWyniki()
{
    disconnect(_wWyszukiwarka, SIGNAL(danePobrane()), this, SLOT(wpiszWyniki()));
    _wMenuZapytan->removeItem(0);

    if(_wWyszukiwarka->_vWynikiWyszukiwania.size() == 0) {
        delete _wWyszukiwarka;
        _wMenuZapytan -> setEnabled(true);
        ComboBox();
        return;
    }

    for(int i = 0; i < _wWyszukiwarka->_vWynikiWyszukiwania.size(); ++i)
        _wMenuZapytan->addItem(_wWyszukiwarka->_vWynikiWyszukiwania[i][0]);

    connect(_wMenuZapytan, SIGNAL(activated(int)), this, SLOT(uzyjKlikniete(int)));
}

bool ZakladkaMiasta::CzyChceszToMiasto()
{
    QMessageBox question;
    question.setWindowTitle("Attention");
    question.setText("Are you sure you want to choose this city?");
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
    if(CzyChceszToMiasto()) {
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

    for (int i=0; i<11; ++i)
        _vwDanePogodowe[i] = new DanaPogodowa(this);

    _wIkonkaPogodowa = new IkonkaPogodowa(this);
    _wIkonkaPogodowa -> Inicjalizuj(_wMiasto);
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
    _wWykresPierwszy = new Wykres1(this);
    _wWykresPierwszy -> DodajTytulIWykres(_wMiasto -> DwaDniPodsum().toString(), _wMiasto);
    _wRzadDrugiLayout -> addWidget(_wWykresPierwszy);
    _wRzadDrugi->setLayout(_wRzadDrugiLayout);
    _wWyglad -> addWidget(_wRzadDrugi);
}

void ZakladkaMiasta::TrzeciRzad()
{
    _wRzadTrzeci = new QGroupBox(tr("Temperature for the next 7 days"));
    _wRzadTrzeciLayout = new QHBoxLayout(_wRzadTrzeci);
    _wWykresDrugi = new Wykres2(this);
    _wWykresDrugi -> DodajTytulIWykres(_wMiasto -> TydzienPodsum().toString(), _wMiasto);
    _wRzadTrzeciLayout -> addWidget(_wWykresDrugi);
    _wRzadTrzeci->setLayout(_wRzadTrzeciLayout);
    _wWyglad -> addWidget(_wRzadTrzeci);
}
