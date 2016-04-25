#ifndef MIASTO_H
#define MIASTO_H

#include <QObject>
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>
#include <QDomDocument>
//#include <QDebug>

class miasto : public QObject
{
    Q_OBJECT
public:
    explicit miasto(QObject *parent = nullptr);
    miasto(QObject *parent = nullptr, QString nazwa = nullptr);

signals:

public slots:

private:
    QString _Nazwa;
    QNetworkAccessManager _Manager;
    QNetworkReply *_wReply;
    QEventLoop _Loop;
    QNetworkRequest _Request;
    QString _Adres = "https://api.forecast.io/forecast/e0d597789a2dbf7ffbd658e2832b71df/";
    QDomElement _XmlDokument;
};

#endif // MIASTO_H
