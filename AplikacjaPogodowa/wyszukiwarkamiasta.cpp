#include "wyszukiwarkamiasta.h"

WyszukiwarkaMiasta::WyszukiwarkaMiasta(QString nazwa)
{
    QMap<QString,QVariant> params;
    params["here.app_id"] = "j3rgq0ooNvXwenPixMoa";
    params["here.token"] = "ySWyxIUi9CDi5Tfk1jov9A";
    _wProvider = new QGeoServiceProvider("here", params);
    _wManager = _wProvider -> placeManager();
    Q_CHECK_PTR(_wManager);
    QPlaceSearchRequest Request;
    Request.setSearchTerm(nazwa);
    Request.setSearchArea(QGeoCircle(QGeoCoordinate(35, 139)));
    Request.setLimit(4);
    _wReply = _wManager->search(Request);
    connect(_wReply, SIGNAL(finished()), this, SLOT(handleSearchReply()));
}


WyszukiwarkaMiasta::~WyszukiwarkaMiasta()
{
    delete _wProvider;
}


void WyszukiwarkaMiasta::handleSearchReply()
{
    if (_wReply->error() == QPlaceReply::NoError) {
        foreach (const QPlaceSearchResult& result, _wReply->results()) {
            if (result.type() == QPlaceSearchResult::PlaceResult) {
                QVector <QString> temp_miasto;
                QPlaceResult placeResult = result;
                temp_miasto.push_back(placeResult.place().name());
                temp_miasto.push_back(placeResult.place().location().coordinate().toString());
                temp_miasto.push_back(placeResult.place().categories().at(0).name());
                _vWynikiWyszukiwania.push_back(temp_miasto);
            }
        }

        emit danePobrane();
    }
    else
        qDebug() << "Blad wyszukiwania nazwy miasta...";
}
