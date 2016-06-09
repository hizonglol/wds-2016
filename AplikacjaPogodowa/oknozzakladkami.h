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
 * Przechowuje widzet z mapa oraz widzet z informacjami o miescie.
 */
class OknoZZakladkami : public QTabWidget {
    Q_OBJECT
public:
    /*!
     * \brief Konstruktor
     * \param Wskaznik na rodzica
     *
     * Inicjalizuje dwa widzety: mape oraz zakladke miasta
     * i umieszcza je w kolejnych zakladkach nadajacac im
     * odpowiednie nazwy
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
     *
     * Zmienia tlumaczenia widzetu na wybrane nowe tlumaczenia
     */
    void changeEvent(QEvent* event);

signals:

public slots:

    /*!
     * \brief Czy poprawne klikniecie w zakladke
     *
     * Sprawdza czy zostala kliknieta zakladka z plusem.
     * Jesli tak to dodaje zakladki z miastem o ile ich ilosc
     * nie przekracza 5. Blokuje sie po przekroczeniu ilosci
     * 5 miast
     */
    void czyKlikniete(int);

    /*!
     * \brief Czy mozna zamknac dana zakladke
     *
     * Sprawdza czy mozna zamknac dana zakladke. Nastepnie
     * kasuje odpowiadajacy jej obiekt. Jesli w ten sposob
     * ilosc zakladek z miastami spadnie ponizej 5 to
     * blokuje przycisk +
     */
    void czyMoznaZamknac(int);

private:
    /*!
     * \brief Wskaznik na mape
     */
    Mapa* _wMapa;

    /*!
     * \brief Wskaznik na ostatnia zakladke z +
     */
    QWidget* _wPrzycisk;

    /*!
     * \brief Wektor zakladek z miastami
     */
    QVector<ZakladkaMiasta* > _wvZakMias;

};

#endif // OKNOZZAKLADKAMI_H
