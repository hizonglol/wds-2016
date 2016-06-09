#ifndef DANAPOGODOWA_H
#define DANAPOGODOWA_H
/*! \file */

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QDebug>

/*!
 * \brief Dana pogodowa
 *
 * Modeluje jeden kwadratowy element z tytulem
 * oraz liczba reprezentujaca dany parametr pogodowy
 */
class DanaPogodowa : public QFrame {
    Q_OBJECT
public:

    /*!
     * \brief Konstruktor
     * \param Wskaznik na rodzica
     *
     * Wpisuje wskaznik na rodzica oraz tworzy zarzadce
     * geometrii
     */
    explicit DanaPogodowa(QWidget* parent = nullptr);

    /*!
     * \brief Destruktor
     *
     * Usuwa tytul oraz widzet z wartoscia z zarzadcy
     * geometrii oraz kasuje wszystkie obiekty
     * w klasie DanaPogodowa
     */
    ~DanaPogodowa();

    /*!
     * \brief Metoda inicjalizujaca
     * \param Tytul okna
     * \param Numer do wyswietlenia
     *
     * Inicjalizuje pola wskazujace na obiekty, wpisuje
     * obiekty do zarzadcy geometrii oraz odpowiednio
     * go konfiguruje.
     */
    void DodajTytulIWartosc(QString title, double number);

    /*!
     * \brief Metoda zmieniajaca tytul widzetu
     * \param Tytul okna
     */
    void ZmienTytul(QString title);

signals:

public slots:

private:

    /*!
     * \brief Zarzadca geometrii
     */
    QVBoxLayout* _wWyglad;

    /*!
     * \brief Tytul okna
     */
    QLabel* _wTytul = nullptr;

    /*!
     * \brief Wartosc do wyswietlenia
     */
    QLCDNumber* _wLCD = nullptr;
};

#endif // DANAPOGODOWA_H
