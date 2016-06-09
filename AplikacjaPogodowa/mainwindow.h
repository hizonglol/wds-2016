#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*! \file */

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QIcon>
#include <QStatusBar>
#include <QDebug>

#include "oknozzakladkami.h"

namespace Ui {
class MainWindow;
}

/*!
 * \brief Glowne okno
 *
 * Modeluje glowne okno programu, na ktorym polozone
 * jest okno z zakladkami.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /*!
     * \brief Konstruktor
     * \param Wskaznik na rodzica
     *
     * Tworzy i inicjalizuje okna z zakladkami
     * oraz tworzy status bar.
     */
    explicit MainWindow(QWidget* parent = nullptr);

    /*!
     * \brief Destruktor
     *
     * Kasuje wszystkie obiekty w klasie MainWindow
     */
    ~MainWindow();

    /*!
     * \brief resizeEvent
     * \param Event zmiany rozmiaru okna
     */
    virtual void resizeEvent(QResizeEvent* event);

    /*!
     * \brief closeEvent
     * \param Event zamkniecia okna
     */
    virtual void closeEvent(QCloseEvent* event);

    /*!
     * \brief Metoda pytajaca o zamkniecie okna
     * \return Czy male okno zostalo zamkniete
     *
     * Otwiera male okienko, za pomoca ktorego
     * zadaje pytanie uzytkownikowi potwierdzajace
     * chec zamkniecia okna.
     */
    bool CzyMoznaZamknac();

protected:

    /*!
     * \brief Event zmian
     *
     * Zmienia tlumaczenia widzetu na wybrane nowe tlumaczenia
     */
    void changeEvent(QEvent* event);

protected slots:

    /*!
     * \brief Slot wywolujacy ladowanie jezyka
     * \param action
     *
     * Uruchamia metode ZaladujJezyk()
     */
    void jezykZmieniony(QAction* action);

private:

    /*!
     * \brief ZaladujJezyk
     * \param skrot jezyka
     *
     * Zmienia locale oraz laduje tlumacza odpowiadajacemu danemu skrotowi
     */
    void ZaladujJezyk(const QString& r_jezyka);

    /*!
     * \brief Metoda tworzaca menu jezykowe
     *
     * Laduje tlumaczenia z zasobow aplikacji, tworzy wybor jezykow do tlumaczenia
     */
    void StworzMenuJezykowe(void);

    /*!
     * \brief UI klasy MainWindow
     */
    Ui::MainWindow* _wUi;

    /*!
     * \brief Okno z zakladkami
     */
    OknoZZakladkami* _wOknoZZ;

    /*!
     * \brief Belka statusowa
     */
    QStatusBar* _wBelkaStatusowa;

    /*!
     * \brief Ikona aplikacji
     */
    QIcon* _wIkona;

    /*!
     * \brief Tlumacz aplikacji
     */
    QTranslator _Tlumacz;

    /*!
     * \brief Skrot aktualnego jezyka aplikacji
     */
    QString _AktualnyJezyk;

    /*!
     * \brief Sciezka do zasobow jezykowych
     */
    QString _SciezkaDoZasobowJezykowych;
};

#endif // MAINWINDOW_H
