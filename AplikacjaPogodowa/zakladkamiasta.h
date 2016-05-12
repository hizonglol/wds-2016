#ifndef ZAKLADKAMIASTA_H
#define ZAKLADKAMIASTA_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLCDNumber>

#include "miasto.h"

class ZakladkaMiasta : public QWidget
{
    Q_OBJECT
public:
    explicit ZakladkaMiasta(QWidget *parent = 0);
    ZakladkaMiasta(QString nazwa, QWidget *parent = 0);

signals:

public slots:

private:
    //dane
    Miasto *_wMiasto;
    //grid
    QGridLayout *_wWyglad;
    //pierwszy rzad grida
    QLabel *_wIkZach;
    QLCDNumber *_wTemper;
    QLCDNumber *_wPrawdop;
    QLabel *_wTekOpis;
    //drugi rzad grida
    //Q3DBars *_wZachDzien;
    //trzeci rzad grida
    //Q3DBars *_wZachTydz;
};

#endif // ZAKLADKAMIASTA_H
