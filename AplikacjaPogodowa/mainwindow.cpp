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
}

/*
MainWindow::~MainWindow()
{
    delete _wUi;
    delete _wOknoZZ;
    delete _wBelkaStatusowa;
}
*/


void MainWindow::resizeEvent(QResizeEvent* event)
{
    _wOknoZZ -> setGeometry(0,0,event->size().width(),
                            event->size().height());
}


bool MainWindow::CzyMoznaZamknac()
{
    return QMessageBox::question(this, tr("Attention"),
                                 tr("Are you sure you want to quit the application?"),
                                 QMessageBox::Yes | QMessageBox::No,
                                 QMessageBox::No)
           == QMessageBox::Yes;

}

void MainWindow::closeEvent( QCloseEvent* event)
{
    if(CzyMoznaZamknac()) event -> accept();
    else event -> ignore();
}
