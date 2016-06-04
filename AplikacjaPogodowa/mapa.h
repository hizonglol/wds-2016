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
 * Wyswietla na sobie mape Japonii.
 */
class Mapa : public QWidget {
    Q_OBJECT
public:
    /*!
     * \brief Konstruktor klasy Mapa
     * \param wskaznik na rodzica
     *
     * Laduje mape oraz ustawia ja jako tlo.
     */
    explicit Mapa(QWidget* parent = nullptr);

    //~Mapa();

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
     *
     * Odpowiada za rysowanie.
     */
    QPainter* _wRysownik;

    /*!
     * \brief Plik z mapa
     *
     * Przechowuje plik z mapa.
     */
    QPixmap _PlikMapy;

    /*!
     * \brief Wskaznik na tlo widzetu
     */
    QLabel* _wMapa;

    /*!
     * \brief Wektor obiektow miast
     */
    QVector< Miasto* > _vMiasta;

    /*!
     * \brief Koordynaty miast
     */
    QVector< QString > _vKoordynaty;

    /*!
     * \brief Wektor nazw z temperaturami
     */
    QVector< QString > _vNazwy;


    int _x, _y;

    int _xt, _yt;
};

#endif // MAPA_H
