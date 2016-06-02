#ifndef WYSZUKIWARKAMIASTA_H
#define WYSZUKIWARKAMIASTA_H
/*! \file */

#include <QObject>
#include <QString>
#include <QVariant>
#include <QGeoServiceProvider>
#include <QPlaceManager>
#include <QPlaceSearchRequest>
#include <QGeoCircle>
#include <QGeoCoordinate>
#include <QPlaceSearchReply>
#include <QPlaceResult>
#include <QDebug>
#include <QMap>
#include <QList>

/*!
 * \brief Objekt wyszukiwarki miasta
 *
 * Wyszukuje koordynaty miejsc o podanej nazwie.
 * Pobiera maksymalnie 4 rekordy.
 */
class WyszukiwarkaMiasta : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief Konstruktor wyszukiwarki miasta
     * \param Nazwa wyszukiwanego miasta
     *
     * Wysyla zadanie do serwisu Here i pobiera od niego odpowiedz
     * w postaci propozycji miejsc pasujacych do wyszukiwanego hasla.
     */
    WyszukiwarkaMiasta(QString nazwa = "Tokio");

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

    void dane_pobrane();

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

public:

    /*!
     * \brief Wyniki wyszukiwania
     */
    QVector< QVector <QString> > _WynikiWyszukiwania;
};

#endif // WYSZUKIWARKAMIASTA_H
