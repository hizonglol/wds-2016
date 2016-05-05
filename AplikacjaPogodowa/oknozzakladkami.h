#ifndef OKNOZZAKLADKAMI_H
#define OKNOZZAKLADKAMI_H

#include "mapa.h"
#include "zakladkamiasta.h"
#include <QTabWidget>
#include <QPushButton>
#include <QResizeEvent>


class OknoZZakladkami : public QTabWidget
{
    Q_OBJECT
public:
    explicit OknoZZakladkami(QWidget *parent = nullptr);
signals:

public slots:

private:
    Mapa *_wMapa;
    ZakladkaMiasta *_wZakMias;
    QPushButton *_wPrzyciskZamknij;
};

#endif // OKNOZZAKLADKAMI_H
