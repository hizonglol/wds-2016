#ifndef WYKRES2_H
#define WYKRES2_H
/*! \file */

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

#include "miasto.h"
#include "qcustomplot.h"

/*!
 * \brief Wykres tygodniowy
 *
 * Wyswietla wykres przedstawiajacy zmiany tempteratury
 * w ciagu tygodnia oraz wyswietla tekstowa prognoze pogody
 */
class Wykres2 : public QFrame {
    Q_OBJECT
public:
    /*!
     * \brief Konstruktor
     * \param Wskaznik na rodzica
     *
     * Tworzy zarzadce geometrii
     */
    explicit Wykres2(QWidget* parent = nullptr);

    /*!
     * \brief Destruktor
     *
     * Usuwa obiekty z zarzadcy geometrii oraz kasuje
     * przechowywane obiekty
     */
    ~Wykres2();

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

signals:

public slots:

private:

    /*!
     * \brief Zarzadca geometrii
     */
    QVBoxLayout* _wWyglad;

    /*!
     * \brief Tytul widzetu
     */
    QLabel* _wTytul;

    /*!
     * \brief Wykres z danymi tygodniowymi
     */
    QCustomPlot* _wZachTydz;
};

#endif // WYKRES2_H
