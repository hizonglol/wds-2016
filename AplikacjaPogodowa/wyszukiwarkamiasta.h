#ifndef WYSZUKIWARKAMIASTA_H
#define WYSZUKIWARKAMIASTA_H
/*! \file */

#include <QString>
#include <QGeoServiceProvider>
#include <QPlaceManager>
#include <QPlaceSearchRequest>
#include <QGeoCircle>
#include <QGeoCoordinate>
#include <QPlaceSearchReply>
#include <QPlaceResult>
#include <QDebug>

/*!
 * \brief Objekt wyszukiwarki miasta
 *
 * Wyszukuje koordynaty miejsc o podanej nazwie.
 * Pobiera maksymalnie 4 rekordy.
 */
class WyszukiwarkaMiasta : public QObject
{
public:
    /*!
     * \brief Konstruktor wyszukiwarki miasta
     * \param Nazwa wyszukiwanego miasta
     *
     * Wysyla zadanie do serwisu Here i pobiera od niego odpowiedz
     * w postaci propozycji miejsc pasujacych do wyszukiwanego hasla.
     */
    WyszukiwarkaMiasta(QString nazwa = "Tokio");

    /*!
     * \brief Metoda obslugi odpowiedzi
     *
     * Obsluguje odpowiedz z serwisu internetowego.
     * Wyszukane miejsca wypisuje w QDebug.
     */
    void handleSearchReply();

private:
    /*!
     * \brief Dostawca informacji
     */
    QGeoServiceProvider *_wProvider;

    /*!
     * \brief Menadzer polaczenia z dostawca
     */
    QPlaceManager *_wManager;

    /*!
     * \brief Odpowiedz od dostawcy informacji
     */
    QPlaceSearchReply *_wReply;


};

#endif // WYSZUKIWARKAMIASTA_H
