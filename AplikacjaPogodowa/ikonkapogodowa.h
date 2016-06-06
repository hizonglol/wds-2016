#ifndef IKONKAPOGODOWA_H
#define IKONKAPOGODOWA_H

#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QString>
#include <QDebug>

#include "miasto.h"

/*!
 * \brief Ikona pogodowa
 *
 * Modeluje jeden kwadratowy widget wyswietlajacy
 * ikonke aktualnej pogody wraz z tytulem w swoim
 * obramowaniu.
 */
class IkonkaPogodowa : public QGroupBox {
    Q_OBJECT
public:
    /*!
     * \brief Konstruktor
     * \param Wskaznik na rodzica
     *
     * Wpisuje wskaznik na rodzica oraz tworzy zarzadce
     * geometrii
     */
    explicit IkonkaPogodowa(QWidget* parent = nullptr);

    /*!
     * \brief Destruktor
     *
     * Usuwa tytul oraz widzet z wartoscia z zarzadcy
     * geometrii oraz kasuje wszystkie obiekty
     * w klasie IkonaPogodowa
     */
    ~IkonkaPogodowa();

    /*!
     * \brief Metoda inicjalizujaca
     * \param Wskaznik na klase Miasto z informacjami
     *
     * Inicjalizuje pola wskazujace na obiekty, wpisuje
     * obiekty do zarzadcy geometrii oraz odpowiednio
     * go konfiguruje.
     */
    void Inicjalizuj(Miasto* miasto);

signals:

public slots:

private:

    /*!
     * \brief Zarzadca geometrii
     */
    QHBoxLayout* _wWygladIkonki;

    /*!
     * \brief Tytul okna
     */
    QLabel* _wLabelIkonki = nullptr;

    /*!
     * \brief Mapa zasobu z ikona
     */
    QPixmap _PlikIkony;

    /*!
     * \brief Zasob z ikona do wyswietlenia
     */
    QString _Zasob;
};

#endif // IKONKAPOGODOWA_H
