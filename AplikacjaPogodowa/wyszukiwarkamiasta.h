#ifndef WYSZUKIWARKAMIASTA_H
#define WYSZUKIWARKAMIASTA_H

#include <QString>
#include <QGeoServiceProvider>
#include <QPlaceManager>
#include <QPlaceSearchRequest>
#include <QGeoCircle>
#include <QGeoCoordinate>
#include <QPlaceSearchReply>
#include <QPlaceResult>
#include <QDebug>

class WyszukiwarkaMiasta : public QObject
{
public:
    WyszukiwarkaMiasta(QString nazwa = "Tokio");

    void handleSearchReply();

private:
    QGeoServiceProvider *_wProvider;
    QPlaceManager *_wManager;
    QPlaceSearchReply *_wReply;


};

#endif // WYSZUKIWARKAMIASTA_H
