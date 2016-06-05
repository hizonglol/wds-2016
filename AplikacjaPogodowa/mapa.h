#ifndef MAPA_H
#define MAPA_H
/*! \file */

#include <QObject>
#include <QLabel>
#include <QDebug>
#include <QGridLayout>
#include <QResizeEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QFont>

#include "miasto.h"

/*!
 * \brief Widzet z mapa
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
     * \param event zmiany rozmiaru okna
     */
    virtual void resizeEvent(QResizeEvent* event);

    /*!
     * \brief paintEvent
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
     */
    QVector< Miasto* > _vwMiasta;

    /*!
     * \brief Koordynaty miast
     */
    QVector< QString > _vKoordynaty;

    /*!
     * \brief Wektor nazw z temperaturami
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
