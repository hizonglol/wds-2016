#ifndef MIASTO_H
#define MIASTO_H

#include <QObject>
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
//#include <QSslConfiguration>
#include <QJsonObject>
#include <QJsonArray>

class Miasto : public QObject
{
    Q_OBJECT
public:
    Miasto();
    Miasto(QString nazwa = nullptr);
    QJsonValue teraz_dane(QString klucz);
    QJsonValue dwa_dni_podsum();
    QJsonValue godzin_dane(int godzina, QString klucz);
    QJsonValue tydzien_podsum();
    QJsonValue dzien_dane(int dzien, QString klucz);

signals:

public slots:

private:
    QString *_wKoordynaty;
    QString _AdrSerwInt = "https://api.forecast.io/forecast/e0d597789a2dbf7ffbd658e2832b71df/";
    //QSslCertificate _Cert;
    QNetworkRequest *_wZadanie;
    QNetworkAccessManager _Menadzer;
    QNetworkReply *_wOdpowiedz;
    QString *_wStrOdpowiedz;
    QEventLoop _Petla;
    QJsonDocument *_wJsonOdpowiedz;
    QJsonObject *_wJsonObj;
};

#endif // MIASTO_H
