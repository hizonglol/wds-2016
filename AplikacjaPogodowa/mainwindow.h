#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "kanwa.h"
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

    virtual void closeEvent( QCloseEvent *event);
    bool CzyMoznaZamknac();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
