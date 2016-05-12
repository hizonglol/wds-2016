#include "wyszukiwarkamiasta.h"

WyszukiwarkaMiasta::WyszukiwarkaMiasta(QString nazwa){

    _wProvider = new QGeoServiceProvider("here");
    _wManager = _wProvider -> placeManager();
    QPlaceSearchRequest Request;
    Request.setSearchTerm("Tokio");
    Request.setSearchArea(QGeoCircle(QGeoCoordinate(35, 139)));
    //Request.setLimit(4);

    //_wReply = _wManager->search(Request);

    //connect(_wReply, SIGNAL(finished()), this, SLOT(handleSearchReply()));
}

void WyszukiwarkaMiasta::handleSearchReply() {
    if (_wReply->error() == QPlaceReply::NoError) {
        foreach (const QPlaceSearchResult &result, _wReply->results()) {
            if (result.type() == QPlaceSearchResult::PlaceResult) {
                QPlaceResult placeResult = result;
                qDebug() << "Name: " << placeResult.place().name();
                qDebug() << "Coordinate " << placeResult.place().location().coordinate().toString();
                qDebug() << "Distance: " << placeResult.distance();
            }
        }
    }
    _wReply->deleteLater();  //discard reply
    _wReply = 0;
}
