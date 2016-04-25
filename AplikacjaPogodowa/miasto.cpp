#include "miasto.h"

miasto::miasto(QObject *parent) : QObject(parent)
{
    _Nazwa = "37.8267,-122.423";
    _Adres.append(_Nazwa);
    _Request.setUrl(_Adres);
    //QObject::connect(_Manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(fileIsReady(QNetworkReply*)) );
    _wReply = _Manager.get(_Request);
    QObject::connect(_wReply, SIGNAL(finished()), &_Loop, SLOT(quit()));
    _Loop.exec();
    //qDebug(_wReply->readAll());
    _temp_XML.write(_wReply->readAll());
}


miasto::miasto(QObject *parent, QString nazwa) : QObject(parent)
{
    _Nazwa = nazwa;
    _Adres.append(_Nazwa);
    _Request.setUrl(_Adres);
    _wReply = _Manager.get(_Request);
    QObject::connect(_wReply, SIGNAL(finished()), &_Loop, SLOT(quit()));
    _Loop.exec();
    //qDebug(_wReply->readAll());
}
