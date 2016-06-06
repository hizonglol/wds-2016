#ifndef WYSZUKIWARKAMIASTA_H
#define WYSZUKIWARKAMIASTA_H
/*! \file */

#include <QObject>
#include <QString>
#include <QGeoServiceProvider>
#include <QPlaceSearchReply>
#include <QPlaceManager>
#include <QPlaceSearchRequest>
#include <QVector>
#include <QVariant>
#include <QMap>
#include <QGeoCircle>
#include <QGeoCoordinate>
#include <QPlaceResult>
#include <QDebug>

#include "danapogodowa.h"

/*!
 * \brief Wyszukiwarka miasta
 *
 * Wyszukuje koordynaty miejsc o podanej nazwie.
 * Pobiera maksymalnie 4 rekordy.
 */
class WyszukiwarkaMiasta : public QObject {
    Q_OBJECT
public:
    /*!
     * \brief Konstruktor
     * \param Nazwa wyszukiwanego miasta
     *
     * Wysyla zadanie do serwisu Here i pobiera od niego odpowiedz
     * w postaci propozycji miejsc pasujacych do wyszukiwanego hasla
     */
    WyszukiwarkaMiasta(QString nazwa = "Tokio");

    /*!
     * \brief Destruktor
     *
     * Usuwa QGeoServiceProvider
     */
    ~WyszukiwarkaMiasta();

public slots:
    /*!
     * \brief Metoda obslugi odpowiedzi
     *
     * Obsluguje odpowiedz z serwisu internetowego.
     * Wyszukane miejsca wypisuje w QDebug.
     */
    void handleSearchReply();

signals:

    /*!
     * \brief Sygnal pobranych danych
     *
     * Sygnalizuje pobranie danych zezwalajace
     * na otrzymanie dostepu do tych danych
     */
    void danePobrane();

private:
    /*!
     * \brief Dostawca informacji
     */
    QGeoServiceProvider* _wProvider;

    /*!
     * \brief Menadzer polaczenia z dostawca
     */
    QPlaceManager* _wManager;

    /*!
     * \brief Odpowiedz od dostawcy informacji
     */
    QPlaceSearchReply* _wReply;

public:

    /*!
     * \brief Wyniki wyszukiwania
     */
    QVector< QVector <QString> > _vWynikiWyszukiwania;
};

#endif // WYSZUKIWARKAMIASTA_H
