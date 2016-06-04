#ifndef OKNOZZAKLADKAMI_H
#define OKNOZZAKLADKAMI_H
/*! \file */

#include "mapa.h"
#include "zakladkamiasta.h"
#include <QTabWidget>
#include <QPushButton>
#include <QResizeEvent>

/*!
 * \brief Widzet okna z Zakladkami
 *
 * Przechowuje widzet z mapa oraz widzet z informacjami o miescie.
 */
class OknoZZakladkami : public QTabWidget {
    Q_OBJECT
public:
    /*!
     * \brief Konstruktor Okna z Zakladkami
     * \param Wskaznik na rodzica
     *
     * Inicjalizuje dwa widzety: mape oraz zakladke miasta
     * i umieszcza je w kolejnych zakladkach.
     */
    explicit OknoZZakladkami(QWidget* parent = nullptr);

    //~OknoZZakladkami();

signals:

public slots:

private:
    /*!
     * \brief Wskaznik na widzet mapy
     */
    Mapa* _wMapa;

    /*!
     * \brief Wskaznik na zakladke miasta
     */
    ZakladkaMiasta* _wZakMias;

    /*!
     * \brief Wskaznik na przycisk zamkniecia
     */
    QPushButton* _wPrzyciskZamknij;

};

#endif // OKNOZZAKLADKAMI_H
