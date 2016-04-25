#ifndef KANWA_H
#define KANWA_H

#include "oknozzakladkami.h"
#include "mapa.h"
#include <QWidget>
#include <QPushButton>
#include <QResizeEvent>


class Kanwa : public QWidget
{
    Q_OBJECT
public:
    explicit Kanwa(QWidget *parent = nullptr);
    virtual void resizeEvent(QResizeEvent *event);
signals:

public slots:

private:
    OknoZZakladkami *_wOkZak;
    QPushButton *_wPrzyciskZamknij;
    Mapa *_wMapa;
};

#endif // KANWA_H
