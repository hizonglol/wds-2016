#ifndef ZAKLADKAMIASTA_H
#define ZAKLADKAMIASTA_H
/*! \file */

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QVector>
#include <QComboBox>

#include "wyszukiwarkamiasta.h"
#include "miasto.h"
#include "qcustomplot.h"

/*!
 * \brief Widzet Zakladka Miasta
 *
 * Wyswietla opis pogody, temperature, wilgotnosc oraz dwa wykresy
 * z temperatura na dwa nastepne dni oraz z temperatura na nastepny
 * tydzien.
 */
class ZakladkaMiasta : public QWidget
{
    Q_OBJECT
public:
    /*!
     * \brief Konstruktor klasy Zakladka Miasta
     * \param Nazwa miasta
     * \param Wskaznik na rodzica
     *
     * Tworzy i inicjalizuje wszystkie polozone na sobie widzety.
     * Pobiera informacje pogodowe z obiektu Miasto.
     * Domyslnie pobiera informacje na temat miasta Tokio.
     */
    ZakladkaMiasta(QString nazwa = "Tokio", QWidget *parent = nullptr);

signals:

public slots:

private:

    /*!
     * \brief Wyszukiwarka koordynatow miasta
     */
    WyszukiwarkaMiasta *_wWyszukiwarka;

    /*!
     * \brief Klasa przechowujaca dane pogodowe
     */
    Miasto *_wMiasto;

    /*!
     * \brief Zarzadca geometria
     */
    QGridLayout *_wWyglad;

    /*!
     * \brief Menu wyszukiwania i wyboru miasta
     */
    QComboBox *_menuZapytan;

    /*!
     * \brief Ikona zachmurzenia
     */
    QLabel *_wIkZach;

    /*!
     * \brief Wartosc temperatury
     */
    QLCDNumber *_wTemper;

    /*!
     * \brief Wartosc prawdopodobienstwa opadow
     */
    QLCDNumber *_wPrawdop;

    /*!
     * \brief Tekstowy opis pogody
     */
    QLabel *_wTekOpis;

    /*!
     * \brief Wykres z temperatura na dwa dni
     */
    QCustomPlot *_wZachDzien;

    /*!
     * \brief Wykres z temperatura na tydzien
     */
    QCustomPlot *_wZachTydz;
};

#endif // ZAKLADKAMIASTA_H
