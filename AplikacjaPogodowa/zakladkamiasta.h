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
 * \brief Wyswietla zakladke z danymi pogodowymi miasta
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
     * \param[in] parent = wskaznik na rodzica
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

protected:
    /*!
     * \brief Event zmian
     * \param[in] event - zdarzenie zmiany jezyka aplikacji
     *
     * Zmienia tlumaczenia widzetu na wybrane nowe tlumaczenia
     */
    void changeEvent(QEvent* event);

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
     * \param[in] indeks - indeks wybranego miasta
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
     * potrzebne do ich utworzenia i zainicjowania.
     * Te widzety to grupa rzedu pierwszego, grupa rzedu
     * drugiego i grupa rzedu trzeciego.
     */
    void wyswietlReszteWidzetow();

private:

    /*!
     * \brief Metoda tworzaca combo box
     *
     * Tworzy ComboBox i laczy go z wyszukiwarka miasta.
     * Jesli miasto sie znajdzie to wyswietla wyniki w liscie.
     * Gdy miasto zostanie wybrane z listy to tworzy obiekt
     * Miasto na podstawie wybranego wyniku.
     */
    void ComboBox();

    /*!
     * \brief Metoda inicjalizujaca pierwszy rzad
     *
     * Inicjalizuje pierwszy rzad zakladki o miescie.
     * Tworzy grupe oraz zarzadce geometrii.
     * Tworzy ikonke pogodowa oraz widzety pogodowe dla
     * pobranych danych pogodowych i kladzie na utworzonej
     * grupie.
     */
    void PierwszyRzad();

    /*!
     * \brief Metoda inicjalizujaca drugi rzad
     *
     * Inicjalizuje drugi rzad zakladki o miescie.
     * Tworzy grupe, zarzadce geometrii oraz wykres
     * z danymi pobranymi z internetu.
     * Tworzy wykres z danymi pogodowymi dla dwoch dni.
     */
    void DrugiRzad();

    /*!
     * \brief Metoda inicjalizujaca trzeci rzad
     *
     * Inicjalizuje trzeci rzad zakladki o miescie.
     * Tworzy grupe, zarzadce geometrii oraz wykres
     * z danymi pobranymi z internetu.
     * Tworzy wykres z danymi pogodowymi dla tygodnia.
     */
    void TrzeciRzad();

    /*!
     * \brief Okienko z zapytaniem
     * \param[in] indeks - indeks wybieranego miasta
     * \return true - jesli wybrane klikniete miasto
     * \return false - jesli odrzucone wybrane miasto
     *
     * Tworzy okienko z zapytaniem czy uzytkownik na pewno
     * zdecydowal sie na wybranie tego miasta z listy.
     */
    bool CzyChceszToMiasto(int indeks);

    /*!
     * \brief Wyszukiwarka koordynatow miasta
     *
     * Wyszukiwarka miast. Przeszukuje serwis internetowy
     * Here Maps w celu dopasowania do hasla miejsc.
     * Pobiera dla tych miejsc koordynaty.
     */
    WyszukiwarkaMiasta* _wWyszukiwarka = nullptr;

    /*!
     * \brief Klasa przechowujaca dane pogodowe
     *
     * Klasa przechowujaca dane pogodowe dla aktualnego zapytania
     */
    Miasto* _wMiasto = nullptr;

    /*!
     * \brief Zarzadca geometria
     *
     * Zarzadca geometrii dla calej zakladki. To na tym zarzadcy
     * polozone sa wszystkie trzy grupy z widzetami oraz
     * ComboBox
     */
    QVBoxLayout* _wWyglad;

    /*!
     * \brief Podpowiedz nad menu wyszukiwania
     *
     * Podpowiedz dla uzytkownika nad ComboBox informujaca
     * o tym co aktualnie uzytkownik moze zrobic
     */
    QLabel* _wTytulZapytania = nullptr;

    /*!
     * \brief Menu wyszukiwania i wyboru miasta
     *
     * Menu do ktorego mozna wpisac wyszukiwane miasto.
     * Po otrzymaniu danych wypisuje je w liscie.
     * Jesli dane nie nadeszly to mozna wpisac jeszcze raz.
     * Jesli dane nadeszly to sie blokuje.
     */
    QComboBox* _wMenuZapytan = nullptr;

    /*!
     * \brief Rzad pierwszy z danymi do wyswietlenia
     *
     * Grupa przechowujaca ikone pogodowa oraz widzety pogodowe
     * z danymi do wyswietlenia
     */
    QGroupBox* _wRzadPierwszy;

    /*!
     * \brief Zarzadca geometrii rzedu pierwszego
     *
     * Zarzadca geometrii dla pierwszego rzedu z danymi pogodowymi
     */
    QGridLayout* _wRzadPierwszyLayout = nullptr;

    /*!
     * \brief Ikonka pogodowa dla rzedu pierwszego
     *
     * Ikona zachmurzenia wyswietlana w pierwszym rzedzie danych
     * pogodowych. Ikona odpowiada aktualnej pogodzie.
     */
    IkonkaPogodowa* _wIkonkaPogodowa = nullptr;

    /*!
     * \brief Wektor widzetow z danymi pogodowymi
     *
     * Przechowuje widzety wyswietlajace dany parametr pogodowy
     * i tytul opisujacy ten parametr pogodowy
     */
    QVector<DanaPogodowa* > _vwDanePogodowe;

    /*!
     * \brief Rzad drugi z danymi do wyswietlenia
     *
     * Grupa przechowujaca wykres ze zmianami temperatury dla dwoch dni
     */
    QGroupBox* _wRzadDrugi;

    /*!
     * \brief Zarzadca geometrii rzedu drugiego
     *
     * Zarzadca geometrii dla grupy z wykresem dwudniowym
     */
    QHBoxLayout* _wRzadDrugiLayout = nullptr;

    /*!
     * \brief Pierwszy wykres w zakladce
     *
     * Wykres przedstawiajacy zmiany temperatury na przestrzeni
     * dwoch dni
     */
    Wykres1* _wWykresPierwszy;

    /*!
     * \brief Rzad trzeci z danymi do wyswietlenia
     *
     * Grupa przechowujaca wykres ze zmianami temperatury dla tygodnia
     */
    QGroupBox* _wRzadTrzeci;

    /*!
     * \brief Zarzadca geometrii rzedu trzeciego
     *
     * Zarzadca geometrii dla grupy z wykresem tygodniowym
     */
    QHBoxLayout* _wRzadTrzeciLayout = nullptr;

    /*!
     * \brief Drugi wykres w zakladce
     *
     * Wykres przedstawiajacy zmiany temperatury na przestrzeni
     * tygodnia.
     */
    Wykres2* _wWykresDrugi;

};

#endif // ZAKLADKAMIASTA_H
