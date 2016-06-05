#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    _wUi(new Ui::MainWindow)
{
    _wUi->setupUi(this);
    _wOknoZZ = new OknoZZakladkami(this);
    _wBelkaStatusowa = new QStatusBar();
    setStatusBar(_wBelkaStatusowa);
    setCentralWidget(_wOknoZZ);
    _wIkona = new QIcon;
    _wIkona -> addFile(":/new/general_icons/general_icons/termometr.png");
    this -> setWindowIcon(*(_wIkona));
    this -> setWindowTitle("Weather app");
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
    question.setWindowTitle("Attention");
    question.setText("Are you sure you want to quit the application?");
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
