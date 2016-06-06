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

signals:

public slots:

private:
    /*!
     * \brief Wskaznik na mape
     */
    Mapa* _wMapa;

    /*!
     * \brief Wskaznik na zakladke miasta
     */
    ZakladkaMiasta* _wZakMias;

};

#endif // OKNOZZAKLADKAMI_H
