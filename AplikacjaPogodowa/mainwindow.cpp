#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _wOknoZZ = new OknoZZakladkami(this);
    setStatusBar(new QStatusBar());
    setCentralWidget(_wOknoZZ);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    _wOknoZZ -> setGeometry(0,0,event->size().width(),
                           event->size().height());

}

bool MainWindow::CzyMoznaZamknac()
{
    return QMessageBox::question(this, tr("Ostrzezenie"),
                                 tr("Czy na pewno chcesz wyjsc?"),
                                 QMessageBox::Yes | QMessageBox::No,
                                 QMessageBox::No)
            == QMessageBox::Yes;

}

void MainWindow::closeEvent( QCloseEvent *event)
{
    if(CzyMoznaZamknac()) event -> accept();
    else event -> ignore();
}
