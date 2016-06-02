#ifndef ZAKLADKAMIASTA_H
#define ZAKLADKAMIASTA_H
/*! \file */

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QVector>
#include <QGroupBox>
#include <QComboBox>
#include <QPixmap>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>

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

    void czy_pobrane_koordynaty();

    void wpisz_wyniki();

    void uzyj_klikniete(int indeks);

    void wyswietl_reszte_widzetow();

private:

    /*!
     * \brief Metoda tworzaca combo box
     *
     * Pozwala na utworzenie zapytania o koordynaty miasta
     */
    void combo_box();

    /*!
     * \brief Metoda inicjalizujaca pierwszy rzad
     *
     * Inicjalizuje pierwszy rzad zakladki o miescie.
     */
    void pierwszy_rzad();

    /*!
     * \brief Metoda inicjalizujaca drugi rzad
     *
     * Inicjalizuje drugi rzad zakladki o miescie.
     */
    void drugi_rzad();

    /*!
     * \brief Metoda inicjalizujaca trzeci rzad
     *
     * Inicjalizuje trzeci rzad zakladki o miescie.
     */
    void trzeci_rzad();

    bool CzyChceszToMiasto();

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
    QVBoxLayout *_wWyglad;

    /*!
     * \brief Menu wyszukiwania i wyboru miasta
     */
    QComboBox *_wMenuZapytan;

};

#endif // ZAKLADKAMIASTA_H
