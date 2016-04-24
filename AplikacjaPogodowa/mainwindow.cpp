#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Kanwa *wOknoKw = new Kanwa(this);
    setStatusBar(new QStatusBar());
    setCentralWidget(wOknoKw);
}

MainWindow::~MainWindow()
{
    delete ui;
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
