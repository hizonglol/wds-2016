#include "miasto.h"


Miasto::Miasto(QString koordynaty)
{
    _wKoordynaty = new QString(koordynaty);
    _AdrSerwInt.append(_wKoordynaty);
    _wZadanie = new QNetworkRequest;
    _wZadanie->setUrl(_AdrSerwInt);
}


Miasto::~Miasto()
{
    delete _wJsonObj;
    delete _Menadzer;
}


void Miasto::Inicjalizuj()
{
    _Menadzer = new QNetworkAccessManager(this);
    _wOdpowiedz = _Menadzer->get(*_wZadanie);
    QObject::connect(_wOdpowiedz, SIGNAL(finished()), &_Petla, SLOT(quit()));
    _Petla.exec();

    if (_wOdpowiedz->error() == QNetworkReply::NoError) {
        _wStrOdpowiedz = new QString(_wOdpowiedz->readAll());
        _wJsonOdpowiedz = new QJsonDocument;
        (*_wJsonOdpowiedz) = QJsonDocument::fromJson(_wStrOdpowiedz->toUtf8());
        _wJsonObj = new QJsonObject(_wJsonOdpowiedz->object());
        emit danePobrane();
        delete _wJsonOdpowiedz;
        delete _wStrOdpowiedz;
    }
    else
        qDebug() << "Blad przy pobieraniu danych z internetu...\n" <<_wOdpowiedz->errorString();

    delete _wKoordynaty;
    delete _wZadanie;
    delete _wOdpowiedz;
}


QJsonValue Miasto::TerazDane(QString klucz)
{
    QJsonObject dane = (*_wJsonObj)["currently"].toObject();
    //qDebug() << dane[klucz] << '\n';
    return dane[klucz];
}


QJsonValue Miasto::DwaDniPodsum()
{
    QJsonObject dane = (*_wJsonObj)["hourly"].toObject();
    //qDebug() << dane["summary"] << '\n';
    return dane["summary"];
}


QJsonValue Miasto::GodzinoweDane(int godzina, QString klucz)
{
    if(godzina<0 || godzina>48) {
        qDebug() << "Nieprawidlowa godzina...\n" <<_wOdpowiedz->errorString();
        return -1;
    }
    else {
        QJsonObject dane_godzinowe = (*_wJsonObj)["hourly"].toObject();
        QJsonArray godzina_danych = dane_godzinowe["data"].toArray();
        QJsonObject dane = godzina_danych[godzina].toObject();
        //qDebug() << dane[klucz] << '\n';
        return dane[klucz];
    }
}


QJsonValue Miasto::TydzienPodsum()
{
    QJsonObject dane = (*_wJsonObj)["daily"].toObject();
    //qDebug() << dane["summary"] << '\n';
    return dane["summary"];
}


QJsonValue Miasto::TygodnioweDane(int dzien, QString klucz)
{
    if(dzien<0 || dzien>7) {
        qDebug() << "Nieprawidlowy dzien...\n" <<_wOdpowiedz->errorString();
        return -1;
    }
    else {
        QJsonObject dane_dniowe = (*_wJsonObj)["daily"].toObject();
        QJsonArray dzien_danych = dane_dniowe["data"].toArray();
        QJsonObject dane = dzien_danych[dzien].toObject();
        //qDebug() << dane[klucz] << '\n';
        return dane[klucz];
    }
}
