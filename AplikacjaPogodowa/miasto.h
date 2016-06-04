#ifndef MIASTO_H
#define MIASTO_H
/*! \file */

#include <QObject>
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

/*!
 * \brief Objekt Miasto
 *
 * Pobiera z internetu, przechowuje oraz udostepnia metody przekazujace
 * informacje o sobie jako o miescie
 */
class Miasto : public QObject {
    Q_OBJECT
public:
    /*!
     * \brief Konstruktor klasy Miasto
     * \param Koordynaty wyszukiwanego miasta
     *
     * Wysyla zadanie do strony internetowej i pobiera odpowiedz w postaci
     * informacji pogodowych na temat miejsca o zadanych koordynatach.
     * Domyslnie informacje pobiera dla Tokio.
     */
    Miasto(QString koordynaty = "35.6895, 139.69171");

    //~Miasto();

    void Inicjalizuj();

    /*!
     * \brief Metoda dostepu do danych teraz.
     * \param Klucz jaki bedzie poszukiwany.
     * \return Zwraca obiekt przechowujacy dane i informacje o typie danej.
     */
    QJsonValue TerazDane(QString klucz);

    /*!
     * \brief Metoda dostepu do dwudniowego podsumowania.
     * \return Zwraca obiekt przechowujacy dane i informacje o typie danej.
     */
    QJsonValue DwaDniPodsum();

    /*!
     * \brief Metoda dostepu do dwudniowych danych.
     * \param Numer godziny dla jakiej bedzie wyszukiwanie.
     * \param Klucz jaki bedzie poszukiwany.
     * \return Zwraca obiekt przechowujacy dane i informacje o typie danej.
     */
    QJsonValue GodzinoweDane(int godzina, QString klucz);

    /*!
     * \brief Metoda dostepu do tygodniowego podsumowania.
     * \return Zwraca obiekt przechowujacy dane i informacje o typie danej.
     */
    QJsonValue TydzienPodsum();

    /*!
     * \brief Metoda dostepu do tygodniowych danych.
     * \param Numer dnia dla jakiego bedzie wyszukiwanie.
     * \param Klucz jaki bedzie poszukiwany.
     * \return Zwraca obiekt przechowujacy dane i informacje o typie danej.
     */
    QJsonValue TygodnioweDane(int dzien, QString klucz);

signals:

    void danePobrane();

public slots:

private:
    /*!
     * \brief Koordynaty miasta
     */
    QString* _wKoordynaty;

    /*!
     * \brief Adres internetowy serwisu pogodowego
     */
    QString _AdrSerwInt = "https://api.forecast.io/forecast/e0d597789a2dbf7ffbd658e2832b71df/";

    /*!
     * \brief Zadanie wysylane do serwisu internetowego.
     */
    QNetworkRequest* _wZadanie;

    /*!
     * \brief Menadzer polaczenia z serwisem internetowym.
     */
    QNetworkAccessManager _Menadzer;

    /*!
     * \brief Odpowiedz z serwisu internetowego.
     */
    QNetworkReply* _wOdpowiedz;

    /*!
     * \brief Odpowiedz z serwisu internetowego.
     *
     * Odpowiedz przekonwertowana do QString.
     */
    QString* _wStrOdpowiedz;

    /*!
     * \brief Petla obslugi pobierania odpowiedzi.
     */
    QEventLoop _Petla;

    /*!
     * \brief Odpowiedz z serwisu internetowego.
     *
     * Odpowiedz przekonwertowana z QString do QJsonDocument.
     */
    QJsonDocument* _wJsonOdpowiedz;

    /*!
     * \brief Odpowiedz serwisu internetowego.
     *
     * Odpowiedz przekowertowana z QJsonDocument do QJsonObject.
     */
    QJsonObject* _wJsonObj;
};

#endif // MIASTO_H
