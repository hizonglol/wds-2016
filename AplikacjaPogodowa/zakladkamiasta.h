#ifndef ZAKLADKAMIASTA_H
#define ZAKLADKAMIASTA_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QVector>
#include <QComboBox>

#include "wyszukiwarkamiasta.h"
#include "miasto.h"
#include "qcustomplot.h"

class ZakladkaMiasta : public QWidget
{
    Q_OBJECT
public:
    explicit ZakladkaMiasta(QWidget *parent = 0);
    ZakladkaMiasta(QString nazwa, QWidget *parent = 0);

signals:

public slots:

private:
    //wyszukiwarka miasta
    WyszukiwarkaMiasta *_wWyszukiwarka;
    //dane
    Miasto *_wMiasto;
    //grid
    QGridLayout *_wWyglad;
    //Combobox
    QComboBox *_menuZapytan;
    //pierwszy rzad grida
    QLabel *_wIkZach;
    QLCDNumber *_wTemper;
    QLCDNumber *_wPrawdop;
    QLabel *_wTekOpis;
    //drugi rzad grida
    QCustomPlot *_wZachDzien;
    //trzeci rzad grida
    QCustomPlot *_wZachTydz;
};

#endif // ZAKLADKAMIASTA_H
