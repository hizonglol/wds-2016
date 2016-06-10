#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    _wUi(new Ui::MainWindow)
{
    _wUi->setupUi(this);
    _wOknoZZ = new OknoZZakladkami(this);
    Q_CHECK_PTR(_wOknoZZ);
    _wBelkaStatusowa = new QStatusBar();
    Q_CHECK_PTR(_wBelkaStatusowa);
    setStatusBar(_wBelkaStatusowa);
    setCentralWidget(_wOknoZZ);
    _wIkona = new QIcon;
    Q_CHECK_PTR(_wIkona);
    _wIkona -> addFile(":/new/general_icons/general_icons/termometr.png");
    this -> setWindowIcon(*(_wIkona));
    this -> setWindowTitle("Weather app");
    this -> StworzMenuJezykowe();
}


MainWindow::~MainWindow()
{
    delete _wUi;
    delete _wOknoZZ;
    delete _wBelkaStatusowa;
    delete _wIkona;
}



void MainWindow::resizeEvent(QResizeEvent* event)
{
    _wOknoZZ -> setGeometry(0,0,event->size().width(),
                            event->size().height());
}


bool MainWindow::CzyMoznaZamknac()
{
    QMessageBox question;
    question.setWindowTitle(tr("Attention"));
    question.setText(tr("Are you sure you want to quit the application?"));
    question.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    question.setDefaultButton(QMessageBox::No);
    question.setIconPixmap(QPixmap(":/new/general_icons/general_icons/angry-rain.png"));
    QIcon Ikona;
    Ikona.addFile(":/new/general_icons/general_icons/sniezynka.png");
    question.setWindowIcon(Ikona);

    if(question.exec() == QMessageBox::Yes)
        return true; else

        return false;
}

void MainWindow::closeEvent( QCloseEvent* event)
{
    if(CzyMoznaZamknac()) event -> accept();
    else event -> ignore();
}


void MainWindow::StworzMenuJezykowe(void)
{
    QActionGroup* GrupaJezykowa = new QActionGroup(_wUi -> menuLanguages);
    GrupaJezykowa->setExclusive(true);
    connect(GrupaJezykowa, SIGNAL (triggered(QAction*)), this, SLOT (jezykZmieniony(QAction*)));
    // format systems language
    QString domyslneLocale = QLocale::system().name(); // e.g. "pl_PL"
    domyslneLocale.truncate(domyslneLocale.lastIndexOf('_')); // e.g. "pl"
    QString LocaleAplikacji = "en";
    _SciezkaDoZasobowJezykowych.append(":/new/translations/languages");
    QDir sciezka(_SciezkaDoZasobowJezykowych);
    QStringList NazwyPlikow = sciezka.entryList(QStringList("AplikacjaPogodowa_*.qm"));

    for (int i = 0; i < NazwyPlikow.size(); ++i) {
        // get locale extracted by filename
        QString locale;
        locale = NazwyPlikow[i]; // "TranslationExample_de.qm"
        locale.truncate(locale.lastIndexOf('.')); // "TranslationExample_de"
        locale.remove(0, locale.indexOf('_') + 1); // "de"
        QString Jezyk = QLocale::languageToString(QLocale(locale).language());
        QIcon ico(QString("%1/%2.png").arg(_SciezkaDoZasobowJezykowych).arg(locale));
        QAction* action = new QAction(ico, Jezyk, this);
        action->setCheckable(true);
        action->setData(locale);
        _wUi -> menuLanguages->addAction(action);
        GrupaJezykowa->addAction(action);

        if(LocaleAplikacji != domyslneLocale)
            ZaladujJezyk(domyslneLocale);

// set default translators and language checked
        if (domyslneLocale == locale)
            action->setChecked(true);
    }
}


void MainWindow::jezykZmieniony(QAction* action)
{
    if(0 != action) {
        // load the language dependant on the action content
        ZaladujJezyk(action->data().toString());
    }
}

void ZmienTlumacza(QTranslator& tlumacz, const QString& nazwa_pliku)
{
    // remove the old translator
    qApp->removeTranslator(&tlumacz);

    // load the new translator
    if(tlumacz.load(nazwa_pliku))
        qApp->installTranslator(&tlumacz);
}

void MainWindow::ZaladujJezyk(const QString& r_jezyka)
{
    if(_AktualnyJezyk != r_jezyka) {
        _AktualnyJezyk = r_jezyka;
        QLocale locale = QLocale(_AktualnyJezyk);
        QLocale::setDefault(locale);
        QString languageName = QLocale::languageToString(locale.language());
        ZmienTlumacza(_Tlumacz, QString(":/new/translations/languages/AplikacjaPogodowa_%1.qm").arg(r_jezyka));
        ZmienTlumacza(_TlumaczQt, QString(":/new/translations/languages/qt_%1.qm").arg(r_jezyka));
        _wBelkaStatusowa->showMessage(tr("Current Language changed to %1").arg(languageName));
    }
}

void MainWindow::changeEvent(QEvent* event)
{
    if(0 != event) {
        switch(event->type()) {
        // this event is send if a translator is loaded
        case QEvent::LanguageChange:
            _wUi -> retranslateUi(this);
            break;

        // this event is send, if the system, language changes
        case QEvent::LocaleChange: {
            QString locale = QLocale::system().name();
            locale.truncate(locale.lastIndexOf('_'));
            ZaladujJezyk(locale);
        }
        break;
        }
    }

    QMainWindow::changeEvent(event);
}
