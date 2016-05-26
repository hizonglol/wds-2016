#include "wyszukiwarkamiasta.h"

WyszukiwarkaMiasta::WyszukiwarkaMiasta(QString nazwa){

    QMap<QString,QVariant> params;
    params["here.app_id"] = "j3rgq0ooNvXwenPixMoa";
    params["here.token"] = "ySWyxIUi9CDi5Tfk1jov9A";

    _wProvider = new QGeoServiceProvider("here", params);
    _wManager = _wProvider -> placeManager();
    Q_CHECK_PTR(_wManager);
    QPlaceSearchRequest Request;
    Request.setSearchTerm("Tokio");
    Request.setSearchArea(QGeoCircle(QGeoCoordinate(35, 139)));
    Request.setLimit(4);

    _wReply = _wManager->search(Request);

    connect(_wReply, SIGNAL(finished()), this, SLOT(handleSearchReply()));
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
    _wReply = nullptr;
}
