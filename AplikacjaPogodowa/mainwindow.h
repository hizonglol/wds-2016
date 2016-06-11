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
 * \brief Wyswietla glowne okno programu
 *
 * Modeluje glowne okno programu, na ktorym polozone
 * jest okno z zakladkami.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /*!
     * \brief Konstruktor
     * \param[in] parent - wskaznik na rodzica
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
     * \param[in] event - zdarzenie zmiany rozmiaru okna
     *
     * Zmienia geometrie okna.
     */
    virtual void resizeEvent(QResizeEvent* event);

    /*!
     * \brief closeEvent
     * \param[in] event - zdarzenie zamkniecia okna
     *
     * Pokazuje okienko z pytaniem do uzytkownika
     * czy na pewno chce zamknac aplikacje
     */
    virtual void closeEvent(QCloseEvent* event);

    /*!
     * \brief Metoda pytajaca o zamkniecie okna
     * \return true - jesli uzytkownik zgodzil sie na zamkniecie aplikacji
     * \return false - jesli uzytkownik nie zgodzil sie na zamkniecie aplikacji
     *
     * Otwiera male okienko pytajace sie uzytkownika o to
     * czy chce zamknac aplikacje.
     */
    bool CzyMoznaZamknac();

protected:

    /*!
     * \brief Event zmian
     * \param[in] event - zdarzenie zmiany jezyka aplikacji
     *
     * Zmienia tlumaczenia widzetu na wybrane nowe tlumaczenia
     */
    void changeEvent(QEvent* event);

protected slots:

    /*!
     * \brief Slot wywolujacy ladowanie jezyka
     * \param[in] action - akcje
     *
     * Uruchamia metode ZaladujJezyk()
     */
    void jezykZmieniony(QAction* action);

private:

    /*!
     * \brief ZaladujJezyk
     * \param[in] r_jezyka - kod jezyka
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
     *
     * Wskaznik na widzet okna z zakladkami
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
     *
     * Tlumacz obiektow aplikacji
     */
    QTranslator _Tlumacz;

    /*!
     * \brief Tlumacz Qt
     *
     * Tlumacz odpowiadajcy za tlumaczenie
     * w obiektach wbudowanych Qt
     */
    QTranslator _TlumaczQt;

    /*!
     * \brief Skrot aktualnego jezyka aplikacji
     *
     * Przechowuje string z kodem aktualnego jezyka aplikacji
     */
    QString _AktualnyJezyk;

    /*!
     * \brief Sciezka do zasobow jezykowych
     */
    QString _SciezkaDoZasobowJezykowych;
};

#endif // MAINWINDOW_H
