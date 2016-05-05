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
    Miasto *_wMiasto;
    QGridLayout *_wWyglad;

    QLabel *_wIkZach;
    QLCDNumber *_wTemper;
    QLCDNumber *_wPrawdop;
    QLabel *_wTekOpis;
};

#endif // ZAKLADKAMIASTA_H
