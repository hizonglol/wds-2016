#ifndef MAPA_H
#define MAPA_H
/*! \file */

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QVector>
#include <QString>
#include <QResizeEvent>
#include <QPaintEvent>
#include <QFont>
#include <QDebug>

#include "miasto.h"

/*!
 * \brief Wyswietla mape Japonii
 *
 * Wyswietla na sobie mape Japonii oraz rysuje nazwy wraz z aktualna
 * temperatura najwiekszego miasta wszystkich prefektur
 */
class Mapa : public QWidget {
    Q_OBJECT
public:
    /*!
     * \brief Konstruktor
     * \param Wskaznik na rodzica
     *
     * Laduje mape, ustawia ja jako tlo, laduje koordynaty najwiekszych
     * miast prefektur oraz zapisuje nazwy tychże miast. Dodatkowo
     * tworzy liste z obiektami Miasto i ja inicjalizuje.
     * Nastepnie przepisuje te dane do wektora QString przygotowujac
     * je w ten sposob dla QPainter.
     */
    explicit Mapa(QWidget* parent = nullptr);

    /*!
     * \brief Destruktor
     *
     * Kasuje wszystkie obiekty w klasie Mapa.
     */
    ~Mapa();

    /*!
     * \brief resizeEvent
     * \param[in] event - zdarzenie zmiany rozmiaru okna
     *
     * Zapisuje nowe rozmiary okna w zmiennych _x, _y
     */
    virtual void resizeEvent(QResizeEvent* event);

    /*!
     * \brief paintEvent
     * \param[in] event - zdarzenie odrysowania
     *
     * Odrysowuje nazwy miast w razie zdarzenia zmiany rozmiaru okna
     */
    virtual void paintEvent(QPaintEvent* event);

signals:

public slots:

private:
    /*!
     * \brief Rysownik
     */
    QPainter* _wRysownik;

    /*!
     * \brief Plik z mapa
     */
    QPixmap _PlikMapy;

    /*!
     * \brief Wskaznik na tlo widzetu
     */
    QLabel* _wMapa;

    /*!
     * \brief Wektor obiektow miast
     *
     * Przechowuje obiekty Miasto odpowiadajace
     * koordynatom
     */
    QVector< Miasto* > _vwMiasta;

    /*!
     * \brief Koordynaty miast
     *
     * Przechowuje stringi z koordynatami miast
     * potrzebnymi do wyswietlenia na mapie
     */
    QVector< QString > _vKoordynaty;

    /*!
     * \brief Wektor nazw z temperaturami
     *
     * Przechowuje stringi z nazwami miast oraz
     * temperatura odpowiadajaca danemu miastu
     */
    QVector< QString > _vNazwy;

    /*!
     * \brief Szerokosc okna po resizeEvent
     */
    int _x;
    /*!
     * \brief Wysokosc okna po resizeEvent
     */
    int _y;
    /*!
     * \brief Tymczasowa pozycja x dla QPainter
     */
    int _xt;

    /*!
     * \brief Tymczasowa pozycja y dla QPainter
     */
    int _yt;
};

#endif // MAPA_H
