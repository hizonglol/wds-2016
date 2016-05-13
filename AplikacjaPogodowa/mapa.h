#ifndef MAPA_H
#define MAPA_H
/*! \file */

#include <QObject>
#include <QLabel>
#include <QDebug>
#include <QGridLayout>
#include <QResizeEvent>

/*!
 * \brief Widzet z mapa
 *
 * Wyswietla na sobie mape Japonii.
 */
class Mapa : public QWidget
{
    Q_OBJECT
public:
    /*!
     * \brief Konstruktor klasy Mapa
     * \param wskaznik na rodzica
     *
     * Laduje mape oraz ustawia ja jako tlo.
     */
    explicit Mapa(QWidget *parent = nullptr);

    /*!
     * \brief resizeEvent
     * \param event zmiany rozmiaru okna
     */
    virtual void resizeEvent(QResizeEvent *event);

signals:

public slots:

private:
    /*!
     * \brief Zarzadca geometria
     *
     * Odpowiada za realizacje resizeEvent.
     */
    QGridLayout *_wWyglad;

    /*!
     * \brief Plik z mapa
     *
     * Przechowuje plik z mapa.
     */
    QPixmap _PlikMapy;

    /*!
     * \brief Wskaznik na tlo widzetu
     */
    QLabel *_wMapa;
};

#endif // MAPA_H
