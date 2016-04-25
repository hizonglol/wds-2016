#ifndef MAPA_H
#define MAPA_H

#include <QObject>
#include <QLabel>
#include <QDebug>

class Mapa : public QWidget
{
    Q_OBJECT
public:
    explicit Mapa(QWidget *parent = 0);

signals:

public slots:

private:
    QPixmap _PlikMapy;
    QLabel *_wMapa;
};

#endif // MAPA_H
