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
 * \brief Wyswietla wykres tygodniowy
 *
 * Wyswietla wykres przedstawiajacy zmiany tempteratury
 * w ciagu tygodnia oraz wyswietla tekstowa prognoze pogody
 */
class Wykres2 : public QFrame {
    Q_OBJECT
public:
    /*!
     * \brief Konstruktor
     * \param[in] parent - wskaznik na rodzica
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
     * \param[in] tytul - tytul widzetu
     * \param[in] miasto - wskaznik na miasto
     *
     * Tworzy wykres oraz go inicjalizuje odpowiednimi danymi pogodowymi.
     * Dodaje wykres do zarzadcy geometrii. Inicjalizuje tytul i dodaje
     * go do zarzadcy geometrii
     */
    void DodajTytulIWykres(const QString& tytul, Miasto* miasto);

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

private:

    /*!
     * \brief Zarzadca geometrii
     *
     * Na nim polozny jest tytul widzetu oraz wykres z danymi
     */
    QVBoxLayout* _wWyglad;

    /*!
     * \brief Tytul widzetu
     *
     * Tytul widzetu wyswietlany w prawym gornym
     * rogu widzetu. Przedstawia opis pogody dla danego
     * okresu czasu.
     */
    QLabel* _wTytul;

    /*!
     * \brief Wykres z danymi tygodniowymi
     *
     * Przedstawia wykres z zakresem temperatur dla
     * nastepnych siedmiu dni
     */
    QCustomPlot* _wZachTydz = nullptr;
};

#endif // WYKRES2_H
