#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*! \file */

#include "oknozzakladkami.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>

/*!
 *  \brief Glowne okno
 *
 *  Modeluje glowne okno programu. To na nim polozony jest widzet
 *  z zakladkami.
 */
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /*!
     * \brief Konstruktor klasy GlowneOkno
     * \param wskaznik na rodzica
     *
     * Zajmuje sie tworzeniem i inicjalizacja okna z zakladkami
     * oraz status baru.
     */
    explicit MainWindow(QWidget* parent = nullptr);

    //! Destruktor klasy GlowneOkno
    //~MainWindow();

    /*!
     * \brief resizeEvent
     * \param event zmiany rozmiaru okna
     */
    virtual void resizeEvent(QResizeEvent* event);

    /*!
     * \brief closeEvent
     * \param event zmiany rozmiaru okna
     */
    virtual void closeEvent(QCloseEvent* event);

    /*!
     * \brief CzyMoznaZamknac
     * \return Czy male okno zostalo zamkniete
     *
     * Otwiera male okienko, w ktorym uzytkownik ma potwierdzic
     * chec zamkniecia programu.
     */
    bool CzyMoznaZamknac();

private:
    /*!
     * \brief ui
     */
    Ui::MainWindow* _wUi;

    /*!
     * \brief Okno z zakladkami
     *
     * Ten wskaznik pokazuje na widzet z zakladkami.
     */
    OknoZZakladkami* _wOknoZZ;

    QStatusBar* _wBelkaStatusowa;
};

#endif // MAINWINDOW_H
