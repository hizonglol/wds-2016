#ifndef OKNOZZAKLADKAMI_H
#define OKNOZZAKLADKAMI_H
/*! \file */

#include <QTabWidget>
#include <QResizeEvent>
#include <QDebug>

#include "mapa.h"
#include "zakladkamiasta.h"

/*!
 * \brief Okna z Zakladkami
 *
 * Przechowuje widzet z mapa oraz widzet z informacjami o miastach.
 * Posiada przycisk do dodawania nowych zakladek z miastami.
 * Miasta maja przycisk to usuwania sie.
 */
class OknoZZakladkami : public QTabWidget {
    Q_OBJECT
public:
    /*!
     * \brief Konstruktor
     * \param[in] parent - wskaznik na rodzica
     *
     * Inicjalizuje dwa widzety: mape oraz zakladke miasta
     * i umieszcza je w kolejnych zakladkach nadajacac im
     * odpowiednie nazwy. Nastepnie tworzy przyciski do zamykania
     * zakladek oraz dodaje przycisk do tworzenia nowych zakladek.
     */
    explicit OknoZZakladkami(QWidget* parent = nullptr);

    /*!
     *\brief Destruktor
     *
     * Kasuje przechowywane obiekty
     */
    ~OknoZZakladkami();

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
     * \brief Czy poprawne klikniecie w zakladke
     * \param[in] index - indeks kliknietego okna
     *
     * Sprawdza czy zostala kliknieta zakladka z plusem.
     * Jesli tak to dodaje zakladki z miastem o ile ich ilosc
     * nie przekracza 5. Blokuje sie po przekroczeniu ilosci
     * 5 miast
     * Zakladki dodawane sa przed przyciskiem dodawania
     * nowych zakladek oraz do wektora wskaznikow do
     * obiektow odpowiadajcych tym zakladkom
     */
    void czyKlikniete(int index);

    /*!
     * \brief Czy mozna zamknac dana zakladke
     * \param[in] index - indeks zamykanego okna
     *
     * Sprawdza czy mozna zamknac dana zakladke. Nastepnie
     * kasuje odpowiadajacy jej obiekt. Jesli w ten sposob
     * ilosc zakladek z miastami spadnie ponizej 5 to
     * blokuje przycisk +
     * Kasowany obiekt jest usuwany z listy zakladek
     * oraz usuwany z wektora zakladek po uzyciu delete
     */
    void czyMoznaZamknac(int index);

private:
    /*!
     * \brief Wskaznik na mape
     *
     * Wskaznik na zakladke z mapa. Mapa jest ustawiana jako
     * pierwsza zakladka. Dla tej zakladki jest zmniejszany
     * do zera przycisk do zamykania.
     */
    Mapa* _wMapa;

    /*!
     * \brief Wskaznik na ostatnia zakladke z +
     *
     * Wskaznik na zakladke dodajaca nowe zakladki.
     * Dla tej zakladki jest zmniejszany do zera
     * przycisk do zamykania
     */
    QWidget* _wPrzycisk;

    /*!
     * \brief Wektor zakladek z miastami
     *
     * Wektor przechowuje zakladki z miastami.
     * Kolejnosc obiektow w wektorze odpowiada kolejnosci
     * zakladek na pasku zakladek.
     */
    QVector<ZakladkaMiasta* > _wvZakMias;

};

#endif // OKNOZZAKLADKAMI_H
