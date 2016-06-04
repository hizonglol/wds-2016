#ifndef DANAPOGODOWA_H
#define DANAPOGODOWA_H
/*! \file */

#include <QFrame>
#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QLCDNumber>

class DanaPogodowa : public QFrame {
    Q_OBJECT
public:
    explicit DanaPogodowa(QWidget* parent = nullptr);

    //~DanaPogodowa();

    void DodajTytulIWartosc(QString title, double number);

signals:

public slots:

private:
    QFrame* _wRamka;

    QVBoxLayout* _wWyglad;

    QLabel* _wTytul;

    QLCDNumber* _wLCD;
};

#endif // DANAPOGODOWA_H
