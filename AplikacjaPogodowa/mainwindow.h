#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "oknozzakladkami.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void resizeEvent(QResizeEvent *event);
    virtual void closeEvent(QCloseEvent *event);
    bool CzyMoznaZamknac();

private:
    Ui::MainWindow *ui;
    OknoZZakladkami *_wOknoZZ;
};

#endif // MAINWINDOW_H
