#ifndef ZAKLADKAMIASTA_H
#define ZAKLADKAMIASTA_H
/*! \file */

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QVector>
#include <QComboBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include <QDebug>

#include "wyszukiwarkamiasta.h"
#include "miasto.h"
#include "ikonkapogodowa.h"
#include "qcustomplot.h"
#include "wykres1.h"
#include "wykres2.h"

/*!
 * \brief Widzet Zakladka Miasta
 *
 * Wyswietla ikone pogody, dane pogodowe, opisy tekstowe oraz dwa wykresy
 * z temperatura na dwa nastepne dni oraz z temperatura na nastepny
 * tydzien.
 */
class ZakladkaMiasta : public QWidget {
    Q_OBJECT
public:
    /*!
     * \brief Konstruktor
     * \param Wskaznik na rodzica
     *
     * Tworzy i inicjalizuje tytul zapytania oraz ComboBox. Tworzy
     * wektor danych pogodowych. Tworzy zarzadce geometrii
     * i go inicjalizuje
     */
    ZakladkaMiasta(QWidget* parent = nullptr);

    /*!
     * \brief Destruktor
     *
     * Usuwa obiekty z zarzadcy geometrii oraz kasuje
     * przechowywane obiekty jesli jeszcze nie zostaly skasowane
     */
    ~ZakladkaMiasta();

signals:

public slots:
    /*!
     * \brief Slot odbierajacy sygnal skonczeniu wpisywania wyszukiwanej nazwy
     *
     * Tworzy zapytanie za pomoca klasy WyszukiwarkaMiasta, blokuje
     * edycje ComboBox oraz laczy sygnal danePobrane() z wyszukiwarki
     * ze slotem wpiszWyniki tej klasy
     */
    void czyPobraneKoordynaty();

    /*!
     * \brief Slot wpisujacy otrzymane wyniki do ComboBox
     *
     * Wpisuje otrzymane wyniki do ComboBox. W razie otrzymania
     * zero wynikow wraca do slotu czyPobraneKoordynaty().
     * Jesli pobranych wynikow jest wiecej niz zero to laczy sygnal
     * danego klikniecia ze slotem uzyjKlikniete
     */
    void wpiszWyniki();

    /*!
     * \brief Slot przetwarzajacy odpowiedzi z wyszukiwarki
     * \param Indeks wybranego miasta
     *
     * Przetwarza odpowiedz z WyszukiwarkaMiasta w sposob
     * zrozumialy dla Miasto. Laczy sygnal pobranych danych
     * ze slotem wyswietlReszteWidzetow().
     */
    void uzyjKlikniete(int indeks);

    /*!
     * \brief Slot wyswietlajacy reszte widzetow
     *
     * Wyswietla reszte widzetow jesli zostaly juz pobrane dane
     * potrzebne do ich utworzenia i zainicjowania
     */
    void wyswietlReszteWidzetow();

private:

    /*!
     * \brief Metoda tworzaca combo box
     *
     * Pozwala na utworzenie zapytania o koordynaty miasta
     */
    void ComboBox();

    /*!
     * \brief Metoda inicjalizujaca pierwszy rzad
     *
     * Inicjalizuje pierwszy rzad zakladki o miescie.
     */
    void PierwszyRzad();

    /*!
     * \brief Metoda inicjalizujaca drugi rzad
     *
     * Inicjalizuje drugi rzad zakladki o miescie.
     */
    void DrugiRzad();

    /*!
     * \brief Metoda inicjalizujaca trzeci rzad
     *
     * Inicjalizuje trzeci rzad zakladki o miescie.
     */
    void TrzeciRzad();

    /*!
     * \brief Okienko z zapytaniem
     * \param Indeks wybieranego miasta
     * \return True jesli wybrane tak, false w innym wypadku
     *
     * Tworzy okienko z zapytaniem czy uzytkownik na pewno
     * zdecydowal sie na wybranie tego miasta z listy
     */
    bool CzyChceszToMiasto(int indeks);

    /*!
     * \brief Wyszukiwarka koordynatow miasta
     */
    WyszukiwarkaMiasta* _wWyszukiwarka = nullptr;

    /*!
     * \brief Klasa przechowujaca dane pogodowe
     */
    Miasto* _wMiasto = nullptr;

    /*!
     * \brief Zarzadca geometria
     */
    QVBoxLayout* _wWyglad;

    /*!
     * \brief Podpowiedz nad menu wyszukiwania
     */
    QLabel* _wTytulZapytania = nullptr;

    /*!
     * \brief Menu wyszukiwania i wyboru miasta
     */
    QComboBox* _wMenuZapytan = nullptr;

    /*!
     * \brief Rzad pierwszy z danymi do wyswietlenia
     */
    QGroupBox* _wRzadPierwszy;

    /*!
     * \brief Zarzadca geometrii rzedu pierwszego
     */
    QGridLayout* _wRzadPierwszyLayout = nullptr;

    /*!
     * \brief Ikonka pogodowa dla rzedu pierwszego
     */
    IkonkaPogodowa* _wIkonkaPogodowa = nullptr;

    /*!
     * \brief Wektor widzetow z danymi pogodowymi
     */
    QVector<DanaPogodowa* > _vwDanePogodowe;

    /*!
     * \brief Rzad drugi z danymi do wyswietlenia
     */
    QGroupBox* _wRzadDrugi;

    /*!
     * \brief Zarzadca geometrii rzedu drugiego
     */
    QHBoxLayout* _wRzadDrugiLayout = nullptr;

    /*!
     * \brief Pierwszy wykres w zakladce
     *
     * Polozony w drugim rzedzie z danymi do wyswietlenia
     */
    Wykres1* _wWykresPierwszy;

    /*!
     * \brief Rzad trzeci z danymi do wyswietlenia
     */
    QGroupBox* _wRzadTrzeci;

    /*!
     * \brief Zarzadca geometrii rzedu trzeciego
     */
    QHBoxLayout* _wRzadTrzeciLayout = nullptr;

    /*!
     * \brief Drugi wykres w zakladce
     *
     * Polozony w trzecim rzedzie z danymi do wyswietlenia
     */
    Wykres2* _wWykresDrugi;

};

#endif // ZAKLADKAMIASTA_H
