#ifndef WYKRES1_H
#define WYKRES1_H
/*! \file */

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

#include "miasto.h"
#include "qcustomplot.h"

/*!
 * \brief Wykres dwudniowy
 *
 * Wyswietla wykres przedstawiajacy zmiany tempteratury
 * w ciagu najblizszych dwu dni oraz wyswietla
 * tekstowa prognoze pogody
 */
class Wykres1 : public QFrame {
    Q_OBJECT

public:
    /*!
     * \brief Konstruktor
     * \param Wskaznik na rodzica
     *
     * Tworzy zarzadce geometrii
     */
    explicit Wykres1(QWidget* parent = nullptr);

    /*!
     * \brief Destruktor
     *
     * Usuwa obiekty z zarzadcy geometrii oraz kasuje
     * przechowywane obiekty
     */
    ~Wykres1();

    /*!
     * \brief Metoda inicjalizujaca
     * \param Tytul widzetu
     * \param Wskaznik na miasto
     *
     * Tworzy wykres oraz go inicjalizuje odpowiednimi danymi pogodowymi.
     * Dodaje wykres do zarzadcy geometrii. Inicjalizuje tytul i dodaje
     * go do zarzadcy geometrii
     */
    void DodajTytulIWykres(QString tytul, Miasto* miasto);

protected:
    /*!
     * \brief Event zmian
     *
     * Zmienia tlumaczenia widzetu na wybrane nowe tlumaczenia
     */
    void changeEvent(QEvent* event);

private:

    /*!
     * \brief Zarzadca geometrii
     */
    QVBoxLayout* _wWyglad = nullptr;

    /*!
     * \brief Tytul widzetu
     */
    QLabel* _wTytul;

    /*!
     * \brief Wykres z danymi dwudniowymi
     */
    QCustomPlot* _wZachDzien = nullptr;

};

#endif // WYKRES1_H
